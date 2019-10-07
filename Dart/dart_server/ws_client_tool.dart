import 'dart:io';
// import 'dart:convert';
import 'dart:async';

void main(List<String> args) async {
  WebSocket ws = await WebSocket.connect("ws://localhost:5700");
  ws.add('{"event": "hai", "payload": "pa"}');

  ws.listen((a) {
    print(a);

    // ws.add("${DateTime.now()}");
    // ws.add('{"event": "ping", "payload": "pa"}');
  });

  int z = 9;
  Timer.periodic(Duration(seconds: 2), (t) {
    var x = "hari inisss $z";
    // ws.add(x);

    ws.add({"event": "ping", "payload": "$z"});
    print(x);
    z++;
  });

  // while (true) {
  //   var _input = stdin.readLineSync();
  //   if(_input == "0") break;

  //   ws.add(_input);
  // }
}
