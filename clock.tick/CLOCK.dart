import 'dart:io';
import 'dart:async';

class Clock {
  List<int> c = [0];
  int m;
  int s;
  late Timer _timer;

  Clock({this.m = 1, this.s = 59});
  void show() {
    DateTime now = DateTime.now();
    print("Current Date-Time: $now");
  }

  void start() {
    int i = -1;
    int e = 0;
    _timer = Timer.periodic(Duration(seconds: 1), (Timer t) {
      i++;
      print("Clock => Hour:[$e]: Minute: [${c[0]}] Second: [$i]");

      if (i == 59) {
        i = -1;
        c[0] = c[0] + 1;
      }

      if (c[0] == 60) {
        c[0] = 0;
        e++;
      }

      if (e == 12) {
        print("Clock reached 12 hours. Stopping.");
        _timer.cancel();
      }
    });
  }
}

void main() {
  Clock c = Clock();

  print("Press Enter to start ticking...");
  stdin.readLineSync();
  int ch = 1;
  c.start();
  print("1 - Check exact date and time:");
  ch = int.parse(stdin.readLineSync()!);
  c.start();
  switch (ch) {
    case 1:
      c.show();
      break;
    default:
      print("invalid::selection::");
  }
}
