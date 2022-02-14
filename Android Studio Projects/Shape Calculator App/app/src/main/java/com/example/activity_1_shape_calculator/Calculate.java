package com.example.activity_1_shape_calculator;

//Calculate Class
public class Calculate {
    //Area Function
    public String area(float w, float h, int c) {
        String returnValue = ""; //Declare returnValue variable
        float temp; //Define temp variable

        //Switch case on the shape type
        switch (c) {
            case 1: //Handles the rectangle and rhombus
                temp = w * h; //Area of rectangle and rhombus
                temp = Math.round(temp * 100f) / 100f; //Rounds the number
                returnValue = String.valueOf(temp) + " units^2"; //Sets the return variable to the area
                break;
            case 2: //Handles the triangle
                temp = 0.5f * w * h; //Area of the triangle
                temp = Math.round(temp * 100f) / 100f; //Rounds the number
                returnValue = String.valueOf(temp) + " units^2"; //Sets the return variable to the area
                break;
            default: //Handles invalid selections
                return "Invalid Selection"; //Returns the invalid output
        }
        return returnValue; //Returns the output
    }

    //Perimeter Function
    public String perimeter(float w, float h, int c) {
        String returnValue = ""; //Declare temp variable
        float temp; //Define temp variable

        //Switch case on the shape type
        switch (c) {
            case 1: //Handles rectangle and rhombus
                temp = 2 * w + 2 * h; //Perimeter of rectangle and rhombus
                temp = Math.round(temp * 100f) / 100f; //Rounds the number
                returnValue = String.valueOf(temp) + " units"; //Sets the return variable to the perimeter
                break;
            case 2: //Handles the triangle
                temp = (float)Math.sqrt(w * w + h * h); //Perimeter of triangle
                temp = Math.round(temp * 100f) / 100f; //Rounds the number
                returnValue = String.valueOf(temp) + " units"; //Sets the return variable to the perimeter
                break;
            default: //Handles invalid selection
                return "Invalid Selection"; //Returns the invalid output
        }
        return returnValue; //Returns the output
    }
}
