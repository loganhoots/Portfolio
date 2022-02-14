package com.example.activity_1_roman_numeral_converter;

//NumberConverter Class
public class NumberConverter {
    //toRoman Function
    public String toRoman(int number) {
        String returnValue = ""; //Declare the returnValue variable
        if (number <= 0 || number > 10000) { //Checks if the number is <= 0 or > 10000
            return "Sorry. I can't do that."; //Outputs invalid selection
        }

        while (number >= 1000) { //Loops while the number is >= 1000
            returnValue += "M"; //Adds M to the return String
            number -= 1000; //Subtracts 1000 from number
        }
        while (number >= 900) { //Loops while the number is >= 900
            returnValue += "CM"; //Adds CM to the return String
            number -= 900; //Subtracts 900 from number
        }
        while (number >= 500) { //Loops while the number is >= 500
            returnValue += "D"; //Adds D to the return String
            number -= 500; //Subtracts 500 from number
        }
        while (number >= 400) { //Loops while the number is >= 400
            returnValue += "CD"; //Adds CD to the return String
            number -= 400; //Subtracts 400 from number
        }
        while (number >= 100) { //Loops while the number is >= 100
            returnValue += "C"; //Adds C to the return String
            number -= 100; //Subtracts 100 from number
        }
        while (number >= 90) { //Loops while the number is >= 90
            returnValue += "XC"; //Adds XC to the return String
            number -= 90; //Subtracts 90 from number
        }
        while (number >= 50) { //Loops while the number is >= 50
            returnValue += "L"; //Adds L to the return String
            number -= 50; //Subtracts 50 from number
        }
        while (number >= 40) { //Loops while the number is >= 40
            returnValue += "XL"; //Adds XL to the return String
            number -= 40; //Subtracts 40 from number
        }
        while (number >= 10) { //Loops while the number is >= 10
            returnValue += "X"; //Adds X to the return String
            number -= 10; //Subtracts 10 from the number
        }
        while (number >= 9) { //Loops while the number is >= 9
            returnValue += "IX"; //Adds IX to the return String
            number -= 9; //Subtracts 9 from number
        }
        while (number >= 5) { //Loops while the number is >= 5
            returnValue += "V"; //Adds V to the return String
            number -= 5; //Subtracts 5 from number
        }
        while (number >= 4) { //Loops while the number is >= 4
            returnValue += "IV"; //Adds IV to the return String
            number -= 4; //Subtracts 4 from number
        }
        while (number >= 1) { //Loops while the number is >= 1
            returnValue += "I"; //Adds I to the return String
            number -= 1; //Subtracts 1 from number
        }

        //Return the string value of the numeral
        return returnValue;
    }

    //toNumber Function
    public int toNumber(String numeral) {
        int returnValue = 0; //Declare the returnValue
        for (int i = 0; i < numeral.length(); i++) { //Loops through the string
            char c = numeral.charAt(i); //Sets c to the char at index i
            switch (c) { //Switch case based on c
                case 'M': //Handles M
                    returnValue += 1000; //Adds 1000 to number
                    break;
                case 'D': //Handles D
                    returnValue += 500; //Adds 500 to number
                    break;
                case 'C': //Handles C
                    if ((i + 1) >= numeral.length()) { //Checks if the next index is larger than the string length
                        returnValue += 100; //Adds 100 to number
                    }
                    else { //If the next index is in the string
                        char k = numeral.charAt(i + 1); //Set k to the next char in the string
                        if (k == 'M') { //Handles M
                            returnValue += 900; //Adds 900 to number
                            i += 1; //Increases i
                        }
                        else if (k == 'D') { //Handles D
                            returnValue += 400; //Adds 400 to number
                            i += 1; //Increases i
                        }
                        else {
                            returnValue += 100; //Adds 100 to number
                        }
                    }
                    break;
                case 'L': //Handles L
                    returnValue += 50; //Adds 50 to number
                    break;
                case 'X': //Handles X
                    if ((i + 1) >= numeral.length()) { //Checks if the next index is larger than the string length
                        returnValue += 10; //Adds 10 to number
                    }
                    else { //If the next index is in the string
                        char k = numeral.charAt(i + 1); //Set k to the next char in the string
                        if (k == 'C') { //Handles C
                            returnValue += 90; //Adds 90 to number
                            i += 1; //Increases i
                        }
                        else if (k == 'L') { //Handles L
                            returnValue += 40; //Adds 40 to number
                            i += 1; //Increments i
                        }
                        else {
                            returnValue += 10; //Adds 10 to number
                        }
                    }
                    break;
                case 'V': //Handles V
                    returnValue += 5; //Adds 5 to number
                    break;
                case 'I': //Handles I
                    if ((i + 1) >= numeral.length()) { //Checks if the next index is larger than the string length
                        returnValue += 1; //Adds 1 to number
                    }
                    else { //If the next index is in the string
                        char k = numeral.charAt(i + 1); //Set k to the next char in the string
                        if (k == 'X') { //Handles X
                            returnValue += 9; //Adds 9 to number
                            i += 1; //Increments i
                        }
                        else if (k == 'V') { //Handles V
                            returnValue += 4; //Adds 4 to number
                            i += 1; //Increments i
                        }
                        else {
                            returnValue += 1; //Adds 1 to number
                        }
                    }
                    break;
                default: //Handles invalid selection
                    returnValue = -1; //Sets returnValue to -1
                    break;
            }
        }
        //Return an integer of the number
        return returnValue;
    }
}
