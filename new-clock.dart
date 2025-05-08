import 'dart:io';
import 'dart:async';

class Cloc {
  late Timer _timer;
  final int h = 20;
  final int w = 29;

  void show() {
    DateTime now = DateTime.now();
    print("Current Date-Time: $now");
  }

  void dis(int hours, int minutes, int seconds) {
    print("=========================::2D-Cloc::=====================");
    for (int i = 0; i < h; i++) {
      if (i == h ~/ 2 - 1) {
        stdout.write("||" + "\t" * 3 + "Hours   : ${hours.toString().padLeft(2, '0')}" + "\t" * 3 + "||\n");
      } else if (i == h ~/ 2) {
        stdout.write("||" + "\t" * 3 + "Minutes : ${minutes.toString().padLeft(2, '0')}" + "\t" * 3 + "||\n");
      } else if (i == h ~/ 2 + 1) {
        stdout.write("||" + "\t" * 3 + "Seconds : ${seconds.toString().padLeft(2, '0')}" + "\t" * 3 + "||\n");
      } else {
        stdout.write("||" + "\t" * 7 + "||\n");
      }
    }
    for (int i = 0; i < w; i++) {
      stdout.write("==");
    }
    print("");
  }

  void clr() {
    print("\x1B[2J\x1B[0;0H");
  }

  void start() {
    _timer = Timer.periodic(Duration(seconds: 1), (Timer t) {
      DateTime now = DateTime.now();
      clr();
      dis(now.hour, now.minute, now.second);
    });
  }
}

void main() {
  Cloc c = Cloc();
  print("Press Enter to continue...");
  stdin.readLineSync();

  print("1 :- Check exact date and time");
  print("2 :- Start the Cloc");
  int ch = int.parse(stdin.readLineSync()!);

  switch (ch) {
    case 1:
      c.show();
      break;
    case 2:
      c.start();
      break;
    default:
      print("Invalid selection");
  }
}
