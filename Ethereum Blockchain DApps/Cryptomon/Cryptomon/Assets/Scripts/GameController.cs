using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public class GameController : MonoBehaviour
{
    public GameObject[] cardPrefabs; public GameObject[] cards; public Cryptomon[] cList;
    public GameObject Menu; public Text userAddress1; public Text userAddress2;
    public GameObject UI; public GameObject GameOverUI; public Text winner;
    public int turn;

    // Start is called before the first frame update
    void Start() {
        GameOverUI.SetActive(false);
        string line;
        StreamReader reader = new StreamReader("Assets/Scripts/deploy.txt");
        while((line = reader.ReadLine()) != null) {
            if (line == "Citromon:") {
                line = reader.ReadLine();
                cardPrefabs[0].GetComponent<Cryptomon>().owner = line;
            }
            else if (line == "Artzimon:") {
                line = reader.ReadLine();
                cardPrefabs[1].GetComponent<Cryptomon>().owner = line;
            }
            else if (line == "Sluitermon:") {
                line = reader.ReadLine();
                cardPrefabs[2].GetComponent<Cryptomon>().owner = line;
            }
            else if (line == "Justomon:") {
                line = reader.ReadLine();
                cardPrefabs[3].GetComponent<Cryptomon>().owner = line;
            }
        }
    }

    void Update() {
        if (userAddress1.text == "" || userAddress2.text == "") {
            Menu.transform.Find("Button").gameObject.GetComponent<Button>().interactable = false;
        } else { Menu.transform.Find("Button").gameObject.GetComponent<Button>().interactable = true; }
    }

    private void setTurn(int turn) {
        for (int i = 0; i < cards.Length; i++) {
            cards[i].transform.Find("Move 1").gameObject.GetComponent<Button>().interactable = false;
            cards[i].transform.Find("Move 2").gameObject.GetComponent<Button>().interactable = false;
        }
        cards[turn].transform.Find("Move 1").gameObject.GetComponent<Button>().interactable = true;
        cards[turn].transform.Find("Move 2").gameObject.GetComponent<Button>().interactable = true;
    }

    public void move1() {
        cards[turn].transform.Find("Move 1").gameObject.GetComponent<Button>().interactable = false;
        cards[turn].transform.Find("Move 2").gameObject.GetComponent<Button>().interactable = false;    
        StartCoroutine(handleMove1()); 
    }

    private IEnumerator handleMove1() {
        int r = Random.Range(0, 100) + 1;
        for (int i = 0; i < cards[turn].GetComponent<Cryptomon>().moves[0].damage; i++) {
            if (r <= cList[turn].moves[0].missRate) break;
            if (turn == 0) cards[1].GetComponent<Cryptomon>().hp--;
            else cards[0].GetComponent<Cryptomon>().hp--;
            yield return new WaitForSeconds(0.025f);
            cards[1].transform.Find("HP Text").gameObject.GetComponent<Text>().text = cards[1].GetComponent<Cryptomon>().hp.ToString();
            cards[0].transform.Find("HP Text").gameObject.GetComponent<Text>().text = cards[0].GetComponent<Cryptomon>().hp.ToString();
            if (!areAllAlive()) {
                gameOver();
                yield break;
            }
        }
        if (turn == 0) turn = 1;
        else turn = 0;
        setTurn(turn);
    }

    public void move2() {
        cards[turn].transform.Find("Move 1").gameObject.GetComponent<Button>().interactable = false;
        cards[turn].transform.Find("Move 2").gameObject.GetComponent<Button>().interactable = false;    
        StartCoroutine(handleMove2()); 
    }

    private IEnumerator handleMove2() {
        int r = Random.Range(0, 100) + 1;
        for (int i = 0; i < cards[turn].GetComponent<Cryptomon>().moves[1].damage; i++) {
            if (r >= cList[turn].moves[1].missRate) break;
            if (turn == 0) cards[1].GetComponent<Cryptomon>().hp--;
            else cards[0].GetComponent<Cryptomon>().hp--;
            yield return new WaitForSeconds(0.025f);
            cards[1].transform.Find("HP Text").gameObject.GetComponent<Text>().text = cards[1].GetComponent<Cryptomon>().hp.ToString();
            cards[0].transform.Find("HP Text").gameObject.GetComponent<Text>().text = cards[0].GetComponent<Cryptomon>().hp.ToString();
            if (!areAllAlive()) {
                gameOver();
                yield break;
            }
        }
        if (turn == 0) turn = 1;
        else turn = 0;
        setTurn(turn);
    }

    private void gameOver() {
        for (int i = 0; i < cards.Length; i++) {
            cards[i].transform.Find("Move 1").gameObject.GetComponent<Button>().interactable = false;
            cards[i].transform.Find("Move 2").gameObject.GetComponent<Button>().interactable = false;
            cards[i].SetActive(false);
        }
        GameOverUI.SetActive(true);
        if (!(cards[0].GetComponent<Cryptomon>().hp <= 0)) winner.text = $"{cards[0].GetComponent<Cryptomon>().owner}\nWins";
        else winner.text = $"{cards[1].GetComponent<Cryptomon>().owner}\nWins";
    }

    private bool areAllAlive() {
        for (int i = 0; i < cList.Length; i++) if (cList[i].hp <= 0) return false;
        return true;
    }

    public void startButton() {

        for (int i = 0; i < cardPrefabs.Length; i++) {
            if (cardPrefabs[i].GetComponent<Cryptomon>().owner == userAddress1.text) {
                GameObject c1 = Instantiate(cardPrefabs[i], new Vector3(UI.transform.position.x - 6f, UI.transform.position.y, 0f), Quaternion.identity);
                c1.transform.parent = UI.transform;
                c1.transform.localScale = new Vector3(1f, 1f, 1f); 
            }
            if (cardPrefabs[i].GetComponent<Cryptomon>().owner == userAddress2.text) {
                GameObject c2 = Instantiate(cardPrefabs[i], new Vector3(UI.transform.position.x + 6f, UI.transform.position.y, 0f), Quaternion.identity);
                c2.transform.parent = UI.transform;
                c2.transform.localScale = new Vector3(1f, 1f, 1f); 
            }
        }

        // Sets Card Values in game
        cards = GameObject.FindGameObjectsWithTag("Card");
        for (int i = 0; i < cards.Length; i++) {
            cList[i] = cards[i].GetComponent<Cryptomon>();
            cards[i].transform.Find("HP Text").gameObject.GetComponent<Text>().text = cList[i].hp.ToString();
            cards[i].transform.Find("Name Text").gameObject.GetComponent<Text>().text = cList[i].cryptomonName;
            cards[i].transform.Find("SPD Value Text").gameObject.GetComponent<Text>().text = cList[i].speed.ToString();
            cards[i].transform.Find("Move 1").gameObject.transform.Find("Text").GetComponent<Text>().text = cList[i].moves[0].moveName;
            cards[i].transform.Find("Move 2").gameObject.transform.Find("Text").GetComponent<Text>().text = cList[i].moves[1].moveName;
            cards[i].transform.Find("Move 1").gameObject.transform.Find("Move 1 Miss Rate Text").GetComponent<Text>().text = cList[i].moves[0].missRate.ToString();
            cards[i].transform.Find("Move 2").gameObject.transform.Find("Move 2 Miss Rate Text").GetComponent<Text>().text = cList[i].moves[1].missRate.ToString();
            cards[i].transform.Find("Move 1").gameObject.transform.Find("Move 1 Damage Text").GetComponent<Text>().text = cList[i].moves[0].damage.ToString();
            cards[i].transform.Find("Move 2").gameObject.transform.Find("Move 2 Damage Text").GetComponent<Text>().text = cList[i].moves[1].damage.ToString();
            cards[i].transform.Find("Move 1").GetComponent<Button>().onClick.AddListener(move1);
            cards[i].transform.Find("Move 2").GetComponent<Button>().onClick.AddListener(move2);
        }
        if (cList[0].speed < cList[1].speed) turn = 1;
        else if (cList[0].speed > cList[1].speed) turn = 0;
        else turn = Random.Range(0, cList.Length);
        setTurn(turn);
        Menu.SetActive(false);
    }
}