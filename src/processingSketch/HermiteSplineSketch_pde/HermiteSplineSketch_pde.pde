/*
 * HermiteSplineSketch
 * 
 * On-Click user can create a hermite spline curve by dragging their mouse
 */
 
 // Global vars
 int clickedX, clickedY;
 int dragX, dragY;
 
 void setup() {
    size(800, 600);
 }
 
 
 void draw() {
   // white background
   background(255);
   stroke(0);
      
 }
 
 void mousePressed() {
   clickedX = mouseX;
   clickedY = mouseY;
 }
 
 void mouseDragged() {
   dragX = mouseX;
   dragY = mouseY;
 }
