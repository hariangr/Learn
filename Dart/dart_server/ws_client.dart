import 'dart:io';

void main(List<String> args) async {
  WebSocket ws = await WebSocket.connect("ws://localhost:5600");
  ws.add("dataaa");

  ws.listen((a) {
    print(a);

    ws.add("${DateTime.now()}");
  });
}
