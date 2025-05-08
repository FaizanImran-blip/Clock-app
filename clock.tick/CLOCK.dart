import 'dart:io';
import 'dart:async';

class Cloc {
  List<int> c = [0];
  int m;
  int s;
  late Timer _timer;
  late int h;
  late int w;
  late int d;

  Cloc({this.m = 1, this.s = 59}) {
    h = 20;
    w = 33;
    d = 0;
  }
  void show() {
    DateTime now = DateTime.now();
    print("Current Date-Time: $now");
  }

  void dis() {
    print("=========================::2D-Cloc::=============================");
    for (int i = 0; i < h; i++) {
      stdout.write("||");
      stdout.write("\t\t\t\t\t\t\t\t||\n");
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
    int i = -1;
    int e = 0;
    _timer = Timer.periodic(Duration(seconds: 0), (Timer t) {
      i++;
      dis();
      print("Cloc => Hours: [$d] minute :[$e]: seconds: [${c[0]}] neno-Seconds: [$i]");
      clr();
      if (i == 59) {
        i = -1;
        c[0] = c[0] + 1;
      }

      if (c[0] == 60) {
        c[0] = 0;
        e++;
      }
      if (e == 60) {
        d++;
      }

      if (e == 12) {
        print("Cloc reached 12 hours. Stopping.");
        _timer.cancel();
      }
    });
  }
}

void main() {
  Cloc c = Cloc();
  print("Press Enter to start ticking...");
  stdin.readLineSync();
  int ch = 1;
  c.start();
  print("1 :- Check exact date and time :-");
  print("2 :- Start the Cloc -:");
  ch = int.parse(stdin.readLineSync()!);
  switch (ch) {
    case 1:
      c.show();
      break;
    case 2:
      c.start();
      break;
    default:
      print("invalid::selection::");
  }
}
