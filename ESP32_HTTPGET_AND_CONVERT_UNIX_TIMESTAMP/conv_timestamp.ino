long date2unix(String s_date) {
  long unix_date;
  int splitT = s_date.indexOf("T");
  dayStamp = s_date.substring(0, splitT);
  timeStamp = s_date.substring(splitT + 1, s_date.length() - 1);

  //parsing

  int p_tahun = dayStamp.indexOf('-');
  int p_bulan = dayStamp.indexOf('-', p_tahun + 1);
  String firstValue = dayStamp.substring(0, p_tahun);
  String secondValue = dayStamp.substring(p_tahun + 1, p_bulan);
  String thirdValue = dayStamp.substring(p_bulan + 1);
  int tahun = firstValue.toInt();
  int bulan = secondValue.toInt();
  int tanggal = thirdValue.toInt();

  int p_jam = timeStamp.indexOf(':');
  int p_menit = timeStamp.indexOf(':', p_jam + 1);
  firstValue = timeStamp.substring(0, p_jam);
  secondValue = timeStamp.substring(p_jam + 1, p_menit);
  thirdValue = timeStamp.substring(p_menit + 1);
  int jam = firstValue.toInt();
  int menit = secondValue.toInt();
  int detik = thirdValue.toInt();
  //
  //    Serial.println(tahun);
  //    Serial.println(bulan);
  //    Serial.println(tanggal);
  //
  //    Serial.println(jam);
  //    Serial.println(menit);
  //    Serial.println(detik);

  time_t rawtime;
  struct tm * timeinfo;

  /* get current timeinfo: */
  time ( &rawtime ); //or: rawtime = time(0);
  /* convert to struct: */
  timeinfo = localtime ( &rawtime );

  /* now modify the timeinfo to the given date: */
  timeinfo->tm_year   = tahun - 1900;
  timeinfo->tm_mon    = bulan - 1;    //months since January - [0,11]
  timeinfo->tm_mday   = tanggal;          //day of the month - [1,31]
  timeinfo->tm_hour   = jam;         //hours since midnight - [0,23]
  timeinfo->tm_min    = menit;          //minutes after the hour - [0,59]
  timeinfo->tm_sec    = detik;          //seconds after the minute - [0,59]

  /* call mktime: create unix time stamp from timeinfo struct */
  unix_date = mktime ( timeinfo );
  return unix_date;
}

