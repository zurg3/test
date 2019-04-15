// iTunes
/// Filenames (adds '0' before track number)
var artist = document.getElementsByTagName('span')[32].innerText;
var album_title = document.getElementsByTagName('span')[31].innerText;
var release_year = document.getElementsByTagName('time')[0].innerText;

var tracks = document.getElementsByClassName('table__row__titles');
var tracks_count = document.getElementsByClassName('table__row__titles').length;

console.log(artist + ' - ' + album_title + ' (' + release_year + ')');
if (tracks_count > 0 && tracks_count < 10) {
  for (i = 0; i < tracks_count; i++) {
    var track_num = i + 1;
    console.log(track_num + '. ' + tracks[i].innerText);
  }
}
else if (tracks_count >= 10 && tracks_count < 100) {
  for (i = 0; i < tracks_count; i++) {
    var track_num = i + 1;
    if (track_num > 0 && track_num < 10) {
      console.log('0' + track_num + '. ' + tracks[i].innerText);
    }
    else {
      console.log(track_num + '. ' + tracks[i].innerText);
    }
  }
}
