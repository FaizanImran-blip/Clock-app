import 'dart:io';
import 'dart:async';

class Clokk {
  List<int> c = [0];
  int m;
  int s;
  late Timer _timer;
  late int h;
  late int w;
  Clokk({this.m = 1, this.s = 59}) {
    h = 20;
    w = 33;
  }
  void show() {
    DateTime now = DateTime.now();
    print("Current Date-Time: $now");
  }

  void dis() {
    print("=========================::2D-Clokk::=============================");
    for (int i = 0; i < h; i++) {
      stdout.write("||");
      stdout.write("\t\t\t\t\t\t\t\t||\n");
    }
    for (int i = 0; i < w; i++) {
      stdout.write("==");
    }
    print("");
  }


  void start() {
    int i = -1;
    int e = 0;
    _timer = Timer.periodic(Duration(seconds: 1), (Timer t) {
      stdout.write("\x1B[2J\x1B[0;H");
      i++;
      dis();
      print("Clokk => Hours :[$e]: Minuters: [${c[0]}] Seconds: [$i]");
      if (i == 59) {
        i = -1;
        c[0] = c[0] + 1;
      }

      if (c[0] == 60) {
        c[0] = 0;
        e++;
      }

      if (e == 12) {
        print("Clokk reached 12 hours. Stopping.");
        _timer.cancel();
      }
    });
  }
}

void main() {
  Clokk c = Clokk();
  print("Press Enter to start ticking...");
  stdin.readLineSync();
  int ch = 1;
  bool e=true;
  bool a=e;
  while(a==e)
  {
  print("1 :- Check exact date and time :-");
  print("2 :- Start the Clokk -:");
  ch = int.parse(stdin.readLineSync()!);
  switch (ch) {
    case 1:
      c.show();
      break;
    case 2:
      c.start();
      e=false;
      break;
    default:
      print("invalid::selection::");
  }
  }
}
