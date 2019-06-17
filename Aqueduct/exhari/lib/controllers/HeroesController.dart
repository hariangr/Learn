import 'package:exhari/exhari.dart';

class HeroesController extends Controller {
  final List _heroes = [
    {'id': 1, 'name': 'Something'},
    {'id': 2, 'name': 'Hero2'},
    {'id': 3, 'name': '2b'},
  ];

  @override
  FutureOr<RequestOrResponse> handle(Request request) {
    if (request.path.variables.containsKey('id')) {
      final id = request.path.variables['id'];

      print(id);
      final hero = _heroes.firstWhere((test) => test['id'] == id);

      if (hero == null) {
        return Response.notFound();
      }

      return Response.ok(hero);
    }

    return Response.ok(_heroes);
  }
}
