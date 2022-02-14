package com.example.apichallenge;

import java.util.List;

public class PokemonModel {
    private String name;
    private int id;
    private String imageURL;
    private int height, weight;
    private String type1, type2;
    private int hp, attack, defense, sAttack, sDefense, speed;
    private List<String> moves;

    public PokemonModel() { }

    @Override
    public String toString() {
        return "PokemonModel{" + "name='" + name + '\'' + ", id=" + id + ", imageURL='" + imageURL + '\'' + ", height=" + height + ", weight=" + weight +
                ", type1='" + type1 + '\'' + ", type2='" + type2 + '\'' + ", hp=" + hp + ", attack=" + attack + ", defense=" + defense +
                ", sAttack=" + sAttack + ", sDefense=" + sDefense + ", speed=" + speed + '}';
    }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }
    public String getImageURL() { return imageURL; }
    public void setImageURL(String imageURL) { this.imageURL = imageURL; }
    public int getHeight() { return height; }
    public void setHeight(int height) { this.height = height; }
    public int getWeight() { return weight; }
    public void setWeight(int weight) { this.weight = weight; }
    public String getType1() { return type1; }
    public void setType1(String type1) { this.type1 = type1; }
    public String getType2() { return type2; }
    public void setType2(String type2) { this.type2 = type2; }
    public int getHp() { return hp; }
    public void setHp(int hp) { this.hp = hp; }
    public int getAttack() { return attack; }
    public void setAttack(int attack) { this.attack = attack; }
    public int getDefense() { return defense; }
    public void setDefense(int defense) { this.defense = defense; }
    public int getsAttack() { return sAttack; }
    public void setsAttack(int sAttack) { this.sAttack = sAttack; }
    public int getsDefense() { return sDefense; }
    public void setsDefense(int sDefense) { this.sDefense = sDefense; }
    public int getSpeed() { return speed; }
    public void setSpeed(int speed) { this.speed = speed; }
    public List<String> getMoves() { return moves; }
    public void setMoves(List<String> moves) { this.moves = moves; }
}
