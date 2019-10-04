import 'dart:io';

void main(List<String> args) async {
  print("Jalan");
  HttpServer server = await HttpServer.bind('localhost', 5600);
  server.transform(WebSocketTransformer()).listen(onWebSocketData);
}

void onWebSocketData(WebSocket client) {
  print("Waiting client");
  client.listen((data) {
    client.add('Echo: $data');
    print(data);
  });
}
