var canvas;  // create global variable for canvas
var ctx;  // create global variable for context
var color;  // create global variable for color
var currentX;  // create global variable for canvas x position
var currentY;  // create global variable for canvas y posistion

function initialize(form) {
   canvas = document.getElementById("canvas");  // initalize canvas variable with location
   ctx = canvas.getContext("2d");  // initialize canvas variable
   ctx.setTransform(1, 0, 0, 1, 0, 0);  // set standard transform
   ctx.font = "1.5rem Calibri, sans-serif";  // set default font
   color = form.elements["color"].value;  // initialize with color from form
   ctx.lineWidth ="4";  // set default line width
   ctx.textBaseline = "top";  // set text baseline to top
   ctx.fillStyle = color;  // set fill style to color from form
   currentX = 10;  // set starting x to 10
   currentY = 10;  // set starting y to 10

   drawName(form);
   drawDate(form);
   drawTitle(form);
   drawShape(form);
}

function drawName(form) {
   var name = form.elements["name"].value;  // get name from form
   ctx.fillText(name, currentX, currentY);  // draw name
   currentY += 20;  // increase y by 20
}

function drawDate(form) {
   var date = form.elements["date"].value;  // get date from form
   ctx.fillText(date, currentX, currentY);  // draw date
   currentY += 20;  // increase y by 20
}

function drawTitle(form) {
   var title = form.elements["title"].value;  // get title from form
   ctx.fillText(title, currentX, currentY);  // draw title
   currentY += 50;  // increase y by 50
}
function drawShape(form) {
   var shapes = document.getElementsByName('shapes');  // get list of shapes from form
   var quantity = form.elements["quantity"].value;  // get quantity from form
   var selectedShape;  // create variable for selected shape

   for (i = 0; i < shapes.length; i++) {  // for every shape in radio button list
      if (shapes[i].checked) {  // if shape is selected
         selectedShape = shapes[i].id;  // save shape to variable
      }
   }
   
   if (selectedShape == "triangle") {  // if shape is triangle
      for (j = 0; j < quantity; j++) {  // draw "quantity" number of shapes
         drawTriangle();  // draw shape
         currentX += 60;  // increse x by 60
      }
      
   }
   else if (selectedShape == "square") {  // if shape is square
      for (j = 0; j < quantity; j++) {  // draw "quantity" number of shapes
         drawSquare();  // draw shape
         currentX += 60;  // increase x by 60
      }
   }
   else {
      for (j = 0; j < quantity; j++) {  // draw "quantitiy" number of shapes
         drawCircle();  // draw shap
         currentX += 60;  // increase x by 60
      }
   }
}

function drawTriangle() {
   ctx.beginPath();  // begin path
   ctx.moveTo(currentX, currentY);  // starting point
   ctx.lineTo(currentX, currentY + 50);  // move down 50
   ctx.lineTo(currentX + 50, currentY + 50);  // move right 50
   ctx.closePath();  // return to orginal position
   ctx.fillStyle = color;  // fill with color
   ctx.fill(); // fill shape
}

function drawSquare() {
   ctx.beginPath();  // begin path
   ctx.moveTo(currentX, currentY);  // starting point
   ctx.lineTo(currentX, currentY + 50);  // move down 50
   ctx.lineTo(currentX + 50, currentY + 50);  // move right 50
   ctx.lineTo(currentX + 50, currentY);  // move up 50
   ctx.closePath();  // return to start
   ctx.fillStyle = color;  // set fill color
   ctx.fill();  // fill shape
}

function drawCircle() {
   ctx.beginPath();  // begin path
   ctx.arc(currentX + 25, currentY + 25, 25, 0, 2 * Math.PI);  // draw circle with radius of 25
   ctx.fillStyle = color;  // set fill color
   ctx.fill();  // fill shape
}

function preventFormReset(event) {
   event.returnValue = false;  // prevents form from reseting, when you click submit.
 }
