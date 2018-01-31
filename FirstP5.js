// START 31JAN2018 sekitar jam 9
// first project (Benernya yangpertama di Galih
// yang kedua gagal jadi dihapus)
// FINISH 31JAN2018 10:26PM

var offset = 0;
var rains = [];

function setup(){
  createCanvas(600, 400);
  noStroke();
}

function draw(){
  background(51);

  var _r = sin(offset) * 100;
  fill(255,255,255);
  ellipse(width/2, height/2, _r);
  offset += 0.05;

  for(var i = 0; i < rains.length; i++){
    var rain = rains[i];
    rain.render();
    rain.addV();
    rain.addAcc();

    if(rain.isOffScreen()){
      rains.splice(i, 1);
    }
  }
}

function mousePressed(){
  //console.log("a");  
  x = new Rain(mouseX, mouseY);
  rains.push(x);
}

function Rain(_x, _y){
  this.x = _x;
  this.y = _y;
  this.r = 10;
  this.vel = 1;
  this.acc = .1;

  this.render = function() {
    fill(255, 0, 0);
    ellipse(this.x, this.y, this.r);
  }

  this.addV = function(){
    this.y += this.vel;
  }

  this.addAcc = function(){
    this.vel += this.acc;
  }

  this.isOffScreen = function(){
    //console.log(this.y);
    return (this.y > height)
  }
}
