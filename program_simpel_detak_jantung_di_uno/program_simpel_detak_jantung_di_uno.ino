// Inisialisasi variabel
float alpha = 0.3; //kofisien alfa low pass filter
double current_output, previous_output; //variabel low pass filter
int current_input, after_filter; //variabel low pass filter
int threshold = 520; //threshold pendeteksi detak jantung

int time_per_bit[20]; //variabel temp value analog
int hasil_filter; //variabel output filter moving average
float BPM; //variable Bir Rate / Minute
int panjang_filter = 20; //koefisien panjang filter Moving Average

unsigned long previous_millis = 0;
const long interval = 3000; //delay pengiriman ke ESP32 3000ms

int last_state; //variable pendeteksi detak jantung
int state;
long time_now, time_span, last_time;


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200); //kecepatan bit rate / second

}

void loop() {

  //pembacaan analog pada keluaran sensor dan low pass filter untuk memperhalus pembacaan sinyal
  current_input = analogRead(A0);
  current_output  = alpha * current_input + (1 - alpha) * previous_output;
  previous_output = current_output;
// koding pendeteksi detak jantung
  if (current_output >= threshold) {
    digitalWrite(13, HIGH);
    state = 1;
  } else {
    digitalWrite(13, LOW);
    state = 0;
  }
  // koding menghitung rentang waktu detak jantung
  if (last_state == 0 && state == 1) {
    time_now = millis();
    time_span = time_now - last_time;
    last_time = time_now;
  }
  last_state = state;

  // kalkulasi untuk mendapatkan BPM dengan filter moving average
  if (time_span >= 600 && time_span <= 1100)
    hasil_filter = movAvg(time_span);
  BPM = (1000.0 / hasil_filter) * 60; //konversi periode ke frekuensi / menit
  if (BPM >= 150) {
    BPM = 0;
  }
  unsigned long currentMillis = millis();

  // koding penjeda pengiriman nilai BPM ke ESP32
  if (currentMillis - previous_millis >= interval) {
    previous_millis = currentMillis;
    Serial.print(BPM, 0);
    Serial.println();
  }
  delay(5);


}


//fungsi filter moving average
//fungsinya untuk memperbagus data yang osilasi
int movAvg(int in) {
  double sum = 0;
  for (int i = panjang_filter - 1; i >= 1; i--) {
    time_per_bit[i] = time_per_bit[i - 1];
    sum += time_per_bit[i];
  }
  time_per_bit[0] = in;
  sum += in;
  return (sum / panjang_filter);
}
