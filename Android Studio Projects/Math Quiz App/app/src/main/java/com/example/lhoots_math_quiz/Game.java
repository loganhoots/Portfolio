package com.example.lhoots_math_quiz;

//Import Libraries
import java.util.ArrayList;
import java.util.List;

//Declare Game Class
public class Game {
    //Declare Variables
    private List<Question> questions;
    private int numberCorrect, numberIncorrect, totalQuestions, score;
    private Question currentQuestion;

    //Constructor
    public Game() {
        numberCorrect = 0; //Sets the number of correct to 0
        numberIncorrect = 0; //Sets the number of incorrect ot 0
        totalQuestions = 0; //Sets the total questions to 0
        score = 0; //Sets the score to 0
        currentQuestion = new Question(100); //Creates the next question
        questions  = new ArrayList<Question>(); //Stores it in an array
    }

    //Make New Question Function
    public void makeNewQuestion() {
        currentQuestion = new Question(totalQuestions * 2 + 5); //Creates the next question
        totalQuestions++; //Increases the number of questions
        questions.add(currentQuestion); //Adds the current question to the question array
    }

    //Check Answer Function
    public boolean checkAnswer(int submittedAnswer) {
        boolean isCorrect; //Declares variables
        if (currentQuestion.getAnswer() == submittedAnswer) { //Checks the the answer is correct
            numberCorrect++; //Increases the number of correct answers
            isCorrect = true; //Sets the answer to correct
        }
        else { //Assumes the answer is wrong
            numberIncorrect++; //Increases the number of incorrect answers
            isCorrect = false; //Sets the answer to incorrect
        }
        score = numberCorrect * 10 - numberIncorrect * 30; //Updates score
        return isCorrect; //Returns outcome
    }

    //Getters and setters
    public List<Question> getQuestions() {
        return questions;
    }
    public void setQuestions(List<Question> questions) {
        this.questions = questions;
    }
    public int getNumberCorrect() {
        return numberCorrect;
    }
    public void setNumberCorrect(int numberCorrect) {
        this.numberCorrect = numberCorrect;
    }
    public int getNumberIncorrect() {
        return numberIncorrect;
    }
    public void setNumberIncorrect(int numberIncorrect) {
        this.numberIncorrect = numberIncorrect;
    }
    public int getTotalQuestions() {
        return totalQuestions;
    }
    public void setTotalQuestions(int totalQuestions) {
        this.totalQuestions = totalQuestions;
    }
    public int getScore() {
        return score;
    }
    public void setScore(int score) {
        this.score = score;
    }
    public Question getCurrentQuestion() {
        return currentQuestion;
    }
    public void setCurrentQuestion(Question currentQuestion) {
        this.currentQuestion = currentQuestion;
    }
}