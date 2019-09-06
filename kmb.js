function kmb(get_num) {
  if ((7 > get_num.toString().length) && (get_num.toString().length >= 4)) {
    var num_char = 'K';
    var div_num = 1000;
    var fractional_part = (get_num / div_num).toString().split('.')[1][0];

    if (fractional_part != 0) {
      return parseInt((get_num / div_num), 10).toString() + '.' + fractional_part + num_char;
    }
    else if (fractional_part == 0) {
      return parseInt((get_num / div_num), 10).toString() + num_char;
    }
  }
  else if ((10 > get_num.toString().length) && (get_num.toString().length >= 7)) {
    var num_char = 'M';
    var div_num = 1000000;
    var fractional_part = (get_num / div_num).toString().split('.')[1][0];

    if (fractional_part != 0) {
      return parseInt((get_num / div_num), 10).toString() + '.' + fractional_part + num_char;
    }
    else if (fractional_part == 0) {
      return parseInt((get_num / div_num), 10).toString() + num_char;
    }
  }
  else if (get_num.toString().length >= 10) {
    var num_char = 'B';
    var div_num = 1000000000;
    var fractional_part = (get_num / div_num).toString().split('.')[1][0];

    if (fractional_part != 0) {
      return parseInt((get_num / div_num), 10).toString() + '.' + fractional_part + num_char;
    }
    else if (fractional_part == 0) {
      return parseInt((get_num / div_num), 10).toString() + num_char;
    }
  }
  else if (get_num.toString().length < 4) {
    return get_num;
  }
}

var a = parseInt(prompt('Enter the number'), 10);
console.log(a.toString() + ' => ' + kmb(a).toString());
