using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable]
public class Player
{
    public Image panel;
    public Text text;
    public Button button;
}

[System.Serializable]
public class PlayerColor
{
    public Color panelColor;
    public Color textColor;
}

public class GameController : MonoBehaviour
{
    public Text[] buttonList;
    private string playerSide;
    public GameObject gameOverPanel;
    public Text gameOverText;
    private int moveCount;
    public GameObject restartButton;
    public Player playerX;
    public Player playerO;
    public PlayerColor activePlayerColor;
    public PlayerColor inactivePlayerColor;
    public GameObject startInfo;

    void SetPlayerButtons(bool toggle)
    {
        playerX.button.interactable = toggle;
        playerO.button.interactable = toggle;
    }

    void StartGame()
    {
        SetBoardInteractable(true);
        SetPlayerButtons(false);
        startInfo.SetActive(false);
    }

    public void SetStartingSide(string startingSide)
    {
        playerSide = startingSide;
        if (playerSide == "X")
        {
            SetPlayerColors(playerX, playerO);
        }
        else
        {
            SetPlayerColors(playerO, playerX);
        }
        StartGame();
    }

    void SetPlayerColorsInactive() {
        playerX.panel.color = inactivePlayerColor.panelColor;
        playerX.text.color = inactivePlayerColor.textColor;
        playerO.panel.color = inactivePlayerColor.panelColor;
        playerO.text.color = inactivePlayerColor.textColor;
    }

    public void RestartGame() {
        SetPlayerButtons(true);
        moveCount = 0;
        gameOverPanel.SetActive(false);
        for (int i = 0; i < buttonList.Length; i++) {
            buttonList[i].text = "";
        }
        restartButton.SetActive(false);
        SetPlayerColorsInactive();
        startInfo.SetActive(true);
    }
    
    void SetPlayerColors(Player newPlayer, Player oldPlayer)
    {
        newPlayer.panel.color = activePlayerColor.panelColor;
        newPlayer.text.color = activePlayerColor.textColor;
        oldPlayer.panel.color = inactivePlayerColor.panelColor;
        oldPlayer.text.color = inactivePlayerColor.textColor;
    }

    void SetGameControllerReferenceOnButtons() {
        for (int i = 0; i < buttonList.Length; i++) {
            buttonList[i].GetComponentInParent<GridSpace>().SetGameControllerReference(this);
        }
    }

    void Awake() {
        SetGameControllerReferenceOnButtons();
        gameOverPanel.SetActive(false);
        moveCount = 0;
        restartButton.SetActive(false);
    }

    public string GetPlayerSide() { return playerSide; }

    public void EndTurn() {
        if (buttonList[1].text == playerSide && buttonList[4].text == playerSide && buttonList[6].text == playerSide) { GameOver(playerSide); }
        if (buttonList[2].text == playerSide && buttonList[0].text == playerSide && buttonList[7].text == playerSide) { GameOver(playerSide); }
        if (buttonList[3].text == playerSide && buttonList[5].text == playerSide && buttonList[8].text == playerSide) { GameOver(playerSide); }
        if (buttonList[1].text == playerSide && buttonList[2].text == playerSide && buttonList[3].text == playerSide) { GameOver(playerSide); }
        if (buttonList[4].text == playerSide && buttonList[0].text == playerSide && buttonList[5].text == playerSide) { GameOver(playerSide); }
        if (buttonList[6].text == playerSide && buttonList[7].text == playerSide && buttonList[8].text == playerSide) { GameOver(playerSide); }
        if (buttonList[1].text == playerSide && buttonList[0].text == playerSide && buttonList[8].text == playerSide) { GameOver(playerSide); }
        if (buttonList[3].text == playerSide && buttonList[0].text == playerSide && buttonList[6].text == playerSide) { GameOver(playerSide); }
        ChangeSides();
        moveCount++;
        if (moveCount >= 9) {
            GameOver("draw");
        }
    }

    void SetGameOverText(string value) {
        gameOverPanel.SetActive(true);
        gameOverText.text = value;
    }

    void GameOver(string winningPlayer) {
        if (winningPlayer == "draw") {
            SetGameOverText("It's a draw!");
            SetPlayerColorsInactive();
        }
        else { SetGameOverText(playerSide + " Wins!"); }
        gameOverPanel.SetActive(true);
        SetBoardInteractable(false);
        restartButton.SetActive(true);
    }

    void ChangeSides() {
        playerSide = (playerSide == "X") ? "O" : "X";
        if (playerSide == "X")
        {
            SetPlayerColors(playerX, playerO);
        }
        else
        {
            SetPlayerColors(playerO, playerX);
        }
    }

    void SetBoardInteractable(bool toggle)
    {
        for (int i = 0; i < buttonList.Length; i++)
        {
            buttonList[i].GetComponentInParent<Button>().interactable = toggle;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
