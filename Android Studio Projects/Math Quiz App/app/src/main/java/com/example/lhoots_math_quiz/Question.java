package com.example.lhoots_math_quiz;

//Import Libraries
import java.util.Random;

//Declare Question class
public class Question {
    //Declare variables
    private int firstNumber, secondNumber, answer, answerPosition, upperLimit;
    private int [] answerArray;
    private String questionPhrase;

    //Question function
    public Question(int upperLimit) {
        this.upperLimit = upperLimit; //Sets the upper limit
        Random randomNumberMaker = new Random(); //Creates a Random object
        this.firstNumber = randomNumberMaker.nextInt(upperLimit); //Sets the first number to the next random int
        this.secondNumber = randomNumberMaker.nextInt(upperLimit); //Sets the second number to the next random int
        this.answer = this.firstNumber + this.secondNumber; //Adds them together to get the answer
        this.questionPhrase = firstNumber + " + " + secondNumber + " = "; //Sets the question to 1st + 2nd =
        this.answerPosition = randomNumberMaker.nextInt(4); //Picks a random number for the answer position

        this.answerArray = new int[] {0, 1, 2, 3}; //Creates an answer Array
        this.answerArray[0] = answer + 1; //Sets one answer to + 1
        this.answerArray[1] = answer + 10; //Sets one answer to + 10
        this.answerArray[2] = answer - 5; //Sets one answer to - 5
        this.answerArray[3] = answer - 2; //Sets one answer to - 2
        this.answerArray = shuffleArray(this.answerArray); //Shuffles the array
        answerArray[answerPosition] = answer; //Finds teh answer
    }

    //ShuffleArray function
    private int[] shuffleArray(int[] array) {
        int index, temp; //Declare variables
        Random randomNumberGenerator = new Random(); //Creates Random object
        for(int i = array.length - 1; i> 0; i--) { //Loops through the array
            index = randomNumberGenerator.nextInt(i + 1); //Sets the index to a random number
            temp = array[index]; //Sets a temp variable to the index
            array[index] = array[i]; //Sets the array location
            array[i] = temp; //Updates the index
        }
        return array; //Returns the array
    }

    //Getters and Setters
    public int getFirstNumber() {
        return firstNumber;
    }
    public void setFirstNumber(int firstNumber) {
        this.firstNumber = firstNumber;
    }
    public int getSecondNumber() {
        return secondNumber;
    }
    public void setSecondNumber(int secondNumber) {
        this.secondNumber = secondNumber;
    }
    public int getAnswer() {
        return answer;
    }
    public void setAnswer(int answer) {
        this.answer = answer;
    }
    public int getAnswerPosition() {
        return answerPosition;
    }
    public void setAnswerPosition(int answerPosition) {
        this.answerPosition = answerPosition;
    }
    public int getUpperLimit() {
        return upperLimit;
    }
    public void setUpperLimit(int upperLimit) {
        this.upperLimit = upperLimit;
    }
    public int[] getAnswerArray() {
        return answerArray;
    }
    public void setAnswerArray(int[] answerArray) {
        this.answerArray = answerArray;
    }
    public String getQuestionPhrase() {
        return questionPhrase;
    }
    public void setQuestionPhrase(String questionPhrase) {
        this.questionPhrase = questionPhrase;
    }
}