/*
 * Sketch based interface using Perlin noise to initialize a vector field
 * 
 * GOALS: (will only implement the ones I have time for although I'm stoked on everything)
 * On-Mouse-Drag user can create a hermite spline curve which will have an influence on the particles' movement
 * On-Click the particles will create a sphere propagation using Gaussian impulse
 *
 */
 
 /****************************** PLAN ***********************************************/
 /*
 1) use the build in 'noise()' function that generates a random value based on Perlin noise. Use this to generate the x, y components of a vector field.
 
 
 */
 /****************************** END ************************************************/
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
   curve(clickedX, clickedY, dragX, dragY, 300, 300, 400, 400);
      
 }
 
 void mousePressed() {
   clickedX = mouseX;
   clickedY = mouseY;
 }
 
 void mouseDragged() {
   dragX = mouseX;
   dragY = mouseY;
 }
