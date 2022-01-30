using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

namespace SimpleBarExample {
	public class DemoBarAnimator : MonoBehaviour {
		public int totalXP = 0;
		public int neededXP = 100;
		public int level = 1;
		public float dampening = 5f;
		public float changeSpeed = .5f;
		Material mat;
		float fillTarget = 0f;
		float delta = 0f;
		float newFill;

		void Awake() {
			Renderer rend = GetComponent<Renderer>();
			Image img = GetComponent<Image>();
			if (rend != null) {
				mat = new Material(rend.material);
				rend.material = mat;
			} else if (img != null) {
				mat = new Material(img.material);
				img.material = mat;
			} else {
				Debug.LogWarning("No Renderer or Image attached to " + name);
			}
		}

		void Update() {
			//increase total xp based on spider kills
			if (totalXP >= neededXP) {
				level++;
				neededXP += neededXP;
				totalXP = 0;
			}
			newFill = (float) totalXP / neededXP;
			delta -= fillTarget - newFill;
			fillTarget = newFill;
			delta = Mathf.Lerp(delta, 0, Time.deltaTime * dampening);
			mat.SetFloat("_Delta", delta);
			mat.SetFloat("_Fill", fillTarget);
		}
	}
}
