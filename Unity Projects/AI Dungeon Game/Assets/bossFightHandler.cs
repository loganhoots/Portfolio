using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Linq;
using UnityEngine.SceneManagement;

public class bossFightHandler : MonoBehaviour
{
    public SpriteRenderer gh1, gh2, gh3, gh4, gh5, gh6, ph1, ph2, ph3, ph4, skeletonR;
    public Sprite fh, eh, dead;
    public Text attack_box;
    public Button short_sword, long_sword, crossbow, long_bow;
    private int SS_dam = 1, LS_dam = 2, CB_dam = 1, LB_dam = 2, p_dam, p_choice;
    private int temp;
    private float SS_ac = 0.8f, LS_ac = 0.6f, CB_ac = 0.4f, LB_ac = 0.2f, p_ac;
    private float[] g_ac = new float[4] { 0.8f, 0.6f, 0.4f, 0.2f };
    private int[] g_dam = new int[4] { 1, 2, 1, 2 };
    private List<int> p_choices = new List<int>();
    private string[] weapons = new string[4] { "Short Sword", "Long Sword", "Crossbow", "Long Bow" };
    private bool turn = true, player_win = false;
    private int p_health = 4, g_health = 6;
    public Animator skele_ani, player;

    // Start is called before the first frame update
    void Start() {
        p_health = PlayerPrefs.GetInt("health", 4);
        mod(p_health);
        active_buttons();
        attack_box.text = "Fight!";
        short_sword.onClick.AddListener(attack_ss);
        long_sword.onClick.AddListener(attack_ls);
        crossbow.onClick.AddListener(attack_cb);
        long_bow.onClick.AddListener(attack_lb);

        if (p_health != 4)
        {
            for (int i = 0; i < (4 - p_health); i++)
            {
                switch (i)
                {
                    case 0:
                        ph1.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    case 1:
                        ph2.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    case 2:
                        ph3.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    case 3:
                        ph4.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    // Update is called once per frame
    void Update() {
    }

    IEnumerator attack() {
        for (int i = 0; i < p_choices.Count; i++) {
            if (p_choice == p_choices[i]) {
                turn = false;
                break;
            }
            else { turn = true; }
        }
        if (Random.Range(0.0f, 1.0f) >= p_ac && turn) {
            if (p_dam == 2) { player.SetBool("Big Attack", true); }
            else { player.SetBool("Small Attack", true); }
            skele_ani.SetBool("Attacked", true);
            attack_box.text = "Hit! " + p_dam + " damage";
            for (int i = 0; i < p_dam; i++) {
                switch (g_health) {
                    case 6:
                        gh1.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 5:
                        gh2.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 4:
                        gh3.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 3:
                        gh4.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 2:
                        gh5.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 1:
                        gh6.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    default:
                        break;
                }
            }
            p_choices.Add(p_choice);
        }
        else {
            if (turn) { attack_box.text = "Miss!"; }
            else {
                if (p_dam == 2) { player.SetBool("Big Attack", true); }
                else { player.SetBool("Small Attack", true); }
                attack_box.text = "Skeleton Blocked!";
                skele_ani.SetBool("Block", true);
            }  
        }
        yield return new WaitForSecondsRealtime(1);
        player.SetBool("Big Attack", false);
        player.SetBool("Small Attack", false);
        skele_ani.SetBool("Block", false);
        skele_ani.SetBool("Attacked", false);
        yield return new WaitForSecondsRealtime(2);
        if (g_health < 1) {
            PlayerPrefs.DeleteAll();
            skele_ani.SetBool("Death", true);
            attack_box.text = "You win!";
            player_win = true;
            yield return new WaitForSecondsRealtime(1);
            skeletonR.sprite = dead;
            skele_ani.enabled = false;
            skele_ani.SetBool("Death", false);
            yield return new WaitForSecondsRealtime(4);
            SceneManager.LoadScene(0);
            yield return new WaitForSecondsRealtime(1);
        }
        mod(g_health);
        temp = Random.Range(0, 4);
        if (Random.Range(0.0f, 1.0f) >= g_ac[temp]) {
            if (g_dam[temp] == 2) {
                skele_ani.SetBool("Big Attack", true);
            }
            else if (g_dam[temp] == 1) {
                skele_ani.SetBool("Small Attack", true);
            }
            attack_box.text = "Skeleton Hit! " + g_dam[temp] + " damage | Using the " + weapons[temp];
            for (int i = 0; i < g_dam[temp]; i++) {
                switch (p_health) {
                    case 4:
                        ph1.sprite = eh;
                        p_health--;
                        Debug.Log(p_health);
                        break;
                    case 3:
                        ph2.sprite = eh;
                        p_health--;
                        Debug.Log(p_health);
                        break;
                    case 2:
                        ph3.sprite = eh;
                        p_health--;
                        Debug.Log(p_health);
                        break;
                    case 1:
                        ph4.sprite = eh;
                        p_health--;
                        Debug.Log(p_health);
                        break;
                    default:
                        break;
                }
            }
            yield return new WaitForSecondsRealtime(1);
            skele_ani.SetBool("Big Attack", false); 
            skele_ani.SetBool("Small Attack", false);
        }
        else {
            attack_box.text = "Skeleton Miss!";
        }
        yield return new WaitForSecondsRealtime(2);
        if (p_health < 1) {
            PlayerPrefs.DeleteAll();
            attack_box.text = "You Lose!";
            player_win = false;
            yield return new WaitForSecondsRealtime(5);
            SceneManager.LoadScene(0);
            yield return new WaitForSecondsRealtime(1);
        }
        active_buttons();
        mod(p_health);
        attack_box.text = "Fight!";
    }

    void active_buttons() {
        short_sword.gameObject.SetActive(true);
        long_sword.gameObject.SetActive(true);
        crossbow.gameObject.SetActive(true);
        long_bow.gameObject.SetActive(true);
    }
    void deactive_buttons() {
        short_sword.gameObject.SetActive(false);
        long_sword.gameObject.SetActive(false);
        crossbow.gameObject.SetActive(false);
        long_bow.gameObject.SetActive(false);
    }

    void attack_ss() {
        p_choice = 0;
        deactive_buttons();
        p_ac = SS_ac;
        p_dam = SS_dam;
        StartCoroutine(attack());
    }
    void attack_ls() {
        p_choice = 1;
        deactive_buttons();
        p_ac = LS_ac;
        p_dam = LS_dam;
        StartCoroutine(attack());
    }
    void attack_cb() {
        p_choice = 2;
        deactive_buttons();
        p_ac = CB_ac;
        p_dam = CB_dam;
        StartCoroutine(attack());
    }
    void attack_lb() {
        p_choice = 3;
        deactive_buttons();
        p_ac = LB_ac;
        p_dam = LB_dam;
        StartCoroutine(attack());
    }

    void mod(int health) {
        switch (health) {
            case 6:
                SS_ac = 0.6f;
                LS_ac = 0.6f;
                CB_ac = 0.2f;
                LB_ac = 0.2f;
                break;
            case 5:
                SS_ac = 0.6f;
                LS_ac = 0.6f;
                CB_ac = 0.4f;
                LB_ac = 0.2f;
                break;
            case 4:
                SS_ac = 0.8f;
                LS_ac = 0.6f;
                CB_ac = 0.4f;
                LB_ac = 0.2f;
                break;
            case 3:
                SS_ac = 0.8f;
                LS_ac = 0.6f;
                CB_ac = 0.2f;
                LB_ac = 0.4f;
                break;
            case 2:
                SS_ac = 0.4f;
                LS_ac = 0.2f;
                CB_ac = 0.6f;
                LB_ac = 0.8f;
                break;
            case 1:
                SS_ac = 0.2f;
                LS_ac = 0.4f;
                CB_ac = 0.6f;
                LB_ac = 0.8f;
                break;
            default:
                break;
        }
    }

    public void hover_LS() { attack_box.text = "Long Sword: " + LS_dam + " damage | " + (1f - LS_ac) + " accuracy"; }
    public void hover_SS() { attack_box.text = "Short Sword: " + SS_dam + " damage | " + (1f - SS_ac) + " accuracy"; }
    public void hover_CB() { attack_box.text = "Crossbow: " + CB_dam + " damage | " + (1f - CB_ac) + " accuracy"; }
    public void hover_LB() { attack_box.text = "Long Bow: " + LB_dam + " damage | " + (1f - LB_ac) + " accuracy"; }
    public void exit() { attack_box.text = "Fight!"; }
}