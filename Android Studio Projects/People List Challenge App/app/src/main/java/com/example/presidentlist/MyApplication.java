package com.example.presidentlist;

import android.app.Application;
import android.net.Uri;
import android.widget.ImageView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MyApplication extends Application {
    private static List<Contact> contactList = new ArrayList<Contact>();
    private static int nextID = 20;
    List<Uri> uriList = new ArrayList<>();

    public MyApplication() {
        fillPresidentList();
        this.uriList = new ArrayList<>();
    }

    private void fillPresidentList() {
        Contact p0 = new Contact(0, "Logan Hoots", "9288300033", "365 E Delano Ave", "lhoots@my.gcu.edu", "www.youtube.com/c/nightowl7187", "");
        Contact p1 = new Contact(1, "Shad Sluiter", "1234567890", "123 Address St", "shad.sluiter@gcu.edu", "www.twitch.tv/nightowl7187", "");
        Contact p2 = new Contact(2, "Mr. 3rd Contact", "0987654321", "456 Address St", "this_is@real.email.com", "www.twitter.com/nightowl7187", "");

        contactList.addAll(Arrays.asList(new Contact[] {p0, p1, p2}));
    }

    public List<Uri> getUriList() { return uriList; }
    public void setUriList(List<Uri> uriList) { this.uriList = uriList; }
    public static List<Contact> getContactList() { return contactList; }
    public static void setContactList(List<Contact> contactList) { MyApplication.contactList = contactList; }
    public static int getNextID() { return nextID; }
    public static void setNextID(int nextID) { MyApplication.nextID = nextID; }
}