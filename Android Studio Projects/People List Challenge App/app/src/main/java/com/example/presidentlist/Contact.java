package com.example.presidentlist;

import android.widget.ImageView;

import java.util.Comparator;

public class Contact {
    private int id;
    private String name;
    private String phoneNumber;
    private String address;
    private String email;
    private String imageURL;
    private String image;

    public Contact(int id, String name, String phoneNumber, String address, String email, String imageURL, String image) {
        this.id = id;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.address = address;
        this.email = email;
        this.imageURL = imageURL;
        this.image = image;
    }

    public static Comparator<Contact> PresidentNameAZComparator = new Comparator<Contact>() {
        @Override
        public int compare(Contact p1, Contact p2) {
            return p1.getName().compareTo(p2.getName());
        }
    };

    public static Comparator<Contact> PresidentNameZAComparator = new Comparator<Contact>() {
        @Override
        public int compare(Contact p1, Contact p2) {
            return p2.getName().compareTo(p1.getName());
        }
    };

    @Override
    public String toString() {
        return "Contact{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", phoneNumber=" + phoneNumber +
                ", address=" + address + '\'' +
                ", email=" + email + '\'' +
                ", URL=" + imageURL + '\'' +
                ", imageURL=" + image + '\'' +
                '}';
    }

    public int getId() { return id; }
    public void setId(int id) { this.id = id; }
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public String getPhoneNumber() { return phoneNumber; }
    public void setPhoneNumber(String phoneNumber) { this.phoneNumber = phoneNumber; }
    public String getAddress() { return address; }
    public void setAddress(String address) { this.address = address; }
    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }
    public String getImageURL() { return imageURL; }
    public void setImageURL(String imageURL) { this.imageURL = imageURL; }
    public String getImage() { return image; }
    public void setImage(String image) { this.image = image; }
}
