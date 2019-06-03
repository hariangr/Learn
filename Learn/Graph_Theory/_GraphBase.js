function setup() {
  createCanvas(400, 400);
	
	this._edges = [];
	
	this._nodes = [
		new Node(30,80, color(255,0,0)), // Red 0
		new Node(75, 30, color(0,255,0)), // Green 1
		new Node(100, 250, color(0,0,255)), // Blue2
		new Node(360, 300, color(255,255,0)), // Yellow3
		new Node(90, 90, color(255,0,255)), // Pink4
		new Node(200, 140, color(0,255,255)), // Cyan5
		new Node(360, 200, color(255,255,255)), // White6
	];
	
	connect(this._nodes[2], this._nodes[3]);
	connect(this._nodes[4], this._nodes[0]);
	connect(this._nodes[4], this._nodes[1]);
	connect(this._nodes[4], this._nodes[5]);
	connect(this._nodes[5], this._nodes[6]);
	connect(this._nodes[6], this._nodes[3]);
}

function connect(from, to) {
	this._edges.push(
		new Edge(from, to)
	);
}

function draw() {
  background(0);
	
	noStroke();
	this._nodes.forEach((item, index) => {
		fill(item.fillColor);
		ellipse(item.x, item.y, 10, 10);
	});
	
	this._edges.forEach((item, index) => {
		const from = item.from;
		const to = item.to;
		
		stroke(color(0,255,0));		
		line(from.x, from.y, to.x, to.y);
	});
}

class Node {
	constructor(x,y, fillColor) {
		this.x = x;
		this.y = y;
		
		if(!fillColor) {
			this.fillColor = 255;
		} else {
			this.fillColor = fillColor;
		}
	}
}

class Edge {
	constructor(from, to) {
		this.from = from;
		this.to = to;
	}
}