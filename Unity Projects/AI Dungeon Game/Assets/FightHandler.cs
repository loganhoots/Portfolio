using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Linq;
using UnityEngine.SceneManagement;

public class FightHandler : MonoBehaviour
{
    public SpriteRenderer gh1, gh2, gh3, gh4, ph1, ph2, ph3, ph4;
    public Sprite fh, eh;
    public Text attack_box;
    public Button short_sword, long_sword, crossbow, long_bow;
    private int SS_dam = 1, LS_dam = 2, CB_dam = 1, LB_dam = 2, p_dam;
    private int weapon, temp_;
    private float SS_ac, LS_ac, CB_ac, LB_ac, p_ac, g_ac, temp;
    private List<int> g_dam = new List<int> { };
    private List<float> g_sword_ac = new List<float> { };
    private List<float> g_bow_ac = new List<float> { };
    private List<float> g_w_ac = new List<float> { };
    private bool turn = false, player_win = false;
    private int p_health = 4, g_health = 4;

    // Start is called before the first frame update
    void Start() {
        p_health = PlayerPrefs.GetInt("health", 4);
        Debug.Log(p_health);
        active_buttons();
        attack_box.text = "Fight!";
        short_sword.onClick.AddListener(attack_ss);
        long_sword.onClick.AddListener(attack_ls);
        crossbow.onClick.AddListener(attack_cb);
        long_bow.onClick.AddListener(attack_lb);
        mod(p_health);

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
        
        if (Random.Range(0.0f, 1.0f) >= p_ac)
        {
            attack_box.text = "Hit! " + p_dam + " damage";
            for (int i = 0; i < p_dam; i++) 
            {
                switch (g_health)
                {
                    case 4:
                        gh1.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 3:
                        gh2.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 2:
                        gh3.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    case 1:
                        gh4.sprite = eh;
                        g_health--;
                        Debug.Log(g_health);
                        break;
                    default:
                        break;
                }
            }
        }
        else 
        {
            attack_box.text = "Miss!";
        }
        if (g_health < 1) 
        {
            attack_box.text = "You win!";
            player_win = true;
            PlayerPrefs.SetInt("health", p_health);
            yield return new WaitForSecondsRealtime(6);
            SceneManager.LoadScene(0);
        }
        yield return new WaitForSecondsRealtime(3);
        mod(g_health);
        g_sword_ac.Add(SS_ac);
        g_sword_ac.Add(LS_ac);
        g_w_ac.Add(g_sword_ac.Min());
        g_bow_ac.Add(CB_ac);
        g_bow_ac.Add(LB_ac);
        g_w_ac.Add(g_bow_ac.Min());
        for (int i = 0; i < g_w_ac.Count; i++) {
            if (g_w_ac[i] == SS_ac)
            {
                g_dam.Add(SS_dam);
            }
            else if (g_w_ac[i] == LS_ac)
            {
                g_dam.Add(LS_dam);
            }
            else if (g_w_ac[i] == CB_ac)
            {
                g_dam.Add(CB_dam);
            }
            else
            {
                g_dam.Add(LB_dam);
            }
        }

        if (Random.Range(0.0f, 1.0f) >= g_w_ac[g_dam.IndexOf(g_dam.Max())]) {
            attack_box.text = "Goblin Hit! " + g_dam.Max() + " damage";
            for (int i = 0; i < g_dam.Max(); i++) 
            {
                switch (p_health)
                {
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
        }
        else
        {
            attack_box.text = "Goblin Miss!";
        }
        if (p_health < 1)
        {
            attack_box.text = "You Lose!";
            player_win = false;
            PlayerPrefs.DeleteAll();
            yield return new WaitForSecondsRealtime(6);
            SceneManager.LoadScene(0);
        }
        yield return new WaitForSecondsRealtime(3);
        active_buttons();
        mod(p_health);
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
        deactive_buttons();
        p_ac = SS_ac;
        p_dam = SS_dam;
        StartCoroutine(attack());
    }

    void attack_ls()
    {
        deactive_buttons();
        p_ac = LS_ac;
        p_dam = LS_dam;
        StartCoroutine(attack());
    }

    void attack_cb()
    {
        deactive_buttons();
        p_ac = CB_ac;
        p_dam = CB_dam;
        StartCoroutine(attack());
    }

    void attack_lb()
    {
        deactive_buttons();
        p_ac = LB_ac;
        p_dam = LB_dam;
        StartCoroutine(attack());
    }

    void mod(int health) {
        switch (health) {
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

    public void hover_LS() {
        attack_box.text = "Long Sword: " + LS_dam + " damage | " + (1 - LS_ac) + " accuracy";
    }
    public void hover_SS() {
        attack_box.text = "Short Sword: " + SS_dam + " damage | " + (1 - SS_ac) + " accuracy";
    }
    public void hover_CB() {
        attack_box.text = "Crossbow: " + CB_dam + " damage | " + (1 - CB_ac) + " accuracy";
    }
    public void hover_LB() {
        attack_box.text = "Long Bow: " + LB_dam + " damage | " + (1 - LB_ac) + " accuracy";
    }
    public void exit() {
        attack_box.text = "Fight!";
    }
}