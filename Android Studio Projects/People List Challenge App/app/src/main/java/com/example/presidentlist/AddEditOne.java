package com.example.presidentlist;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.FileProvider;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Map;

public class AddEditOne extends AppCompatActivity {

    Button btn_ok, btn_cancel, btn_web, btn_email, btn_map, btn_text, btn_call, btn_take, btn_load;
    List<Contact> contactList;
    EditText et_phone, et_presidentName, et_contactAddress, et_email, et_presidentURL;
    ImageView pic;
    MyApplication myApplication = (MyApplication) this.getApplication();
    int id;
    final static int PERMISSION_TO_CALL = 1;
    static final int REQUEST_TAKE_PHOTO = 2;
    static final int SELECT_A_PHOTO = 3;
    String mCurrectPhotoPath, temp = "";
    List<Uri> uriList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_edit_one);

        contactList = myApplication.getContactList();

        btn_ok = findViewById(R.id.btn_ok);
        btn_cancel = findViewById(R.id.btn_cancel);
        btn_web = findViewById(R.id.btn_web);
        btn_email = findViewById(R.id.btn_email);
        btn_map = findViewById(R.id.btn_map);
        btn_text = findViewById(R.id.btn_text);
        btn_call = findViewById(R.id.btn_call);
        btn_take = findViewById(R.id.btn_c_take);
        btn_load = findViewById(R.id.btn_c_choose);
        et_phone = findViewById(R.id.et_contactNumber);
        et_contactAddress = findViewById(R.id.et_address);
        et_presidentName = findViewById(R.id.et_contactName);
        et_email = findViewById(R.id.et_email);
        et_presidentURL = findViewById(R.id.et_pictureURL);
        pic = findViewById(R.id.iv_contact_icon);

        Intent intent = getIntent();
        id = intent.getIntExtra("id", -1);
        Contact contact = null;

        if (id >= 0)  {
            for(Contact p: contactList) {
                if (p.getId() == id) {
                    contact = p;
                }
            }
            et_presidentName.setText(contact.getName());
            et_contactAddress.setText(contact.getAddress());
            et_phone.setText(contact.getPhoneNumber());
            et_email.setText(contact.getEmail());
            et_presidentURL.setText(contact.getImageURL());
            Glide.with(this).load(contact.getImage()).into(pic);
        }
        else {

        }

        btn_ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (temp.equals("")) { temp = contactList.get(id).getImage(); }
                if (id >= 0) {
                    Contact updatedContact = new Contact(id, et_presidentName.getText().toString(), et_phone.getText().toString(),
                            et_contactAddress.getText().toString(), et_email.getText().toString(), et_presidentURL.getText().toString(), temp);
                    contactList.set(id, updatedContact);
                }
                else {
                    int nextID = myApplication.getNextID();
                    Contact newContact = new Contact(nextID, et_presidentName.getText().toString(), et_phone.getText().toString(),
                            et_contactAddress.getText().toString(), et_email.getText().toString(), et_presidentURL.getText().toString(), temp);
                    contactList.add(newContact);
                    myApplication.setNextID(nextID++);
                }
                Intent intent = new Intent(AddEditOne.this, MainActivity.class);
                startActivity(intent);
            }
        });

        btn_cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddEditOne.this, MainActivity.class);
                startActivity(intent);
            }
        });

        btn_web.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openWebPage(et_presidentURL.getText().toString());
            }
        });

        btn_email.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String [] addresses = new String [1];
                addresses[0] = et_email.getText().toString();
                sendEmail(addresses, "Hello from Logan");
            }
        });

        btn_map.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String mapsQuery = "geo:0,0?q=" + et_contactAddress.getText().toString();
                Uri MapUri = Uri.parse(mapsQuery);
                showMap(MapUri);
            }
        });

        btn_text.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                composeMmsMessage(et_phone.getText().toString(), "Hello I would like to talk");
            }
        });

        btn_call.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) { callPhoneNumber(et_phone.getText().toString()); }
        });

        btn_take.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dispatchTakePictureIntent();
            }
        });

        btn_load.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(i, SELECT_A_PHOTO);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        ImageView iv_photo;
        iv_photo = findViewById(R.id.iv_contact_icon);

        uriList = ((MyApplication) this.getApplication()).getUriList();
        if (requestCode == REQUEST_TAKE_PHOTO && resultCode == RESULT_OK) {
            Glide.with(this).load(mCurrectPhotoPath).into(iv_photo);
            temp = mCurrectPhotoPath;
            uriList.add(Uri.fromFile(new File(mCurrectPhotoPath)));
        }
        if (requestCode == SELECT_A_PHOTO && resultCode == RESULT_OK) {
            Uri selectedPhoto = data.getData();
            Glide.with(this).load(selectedPhoto).into(iv_photo);
            temp = selectedPhoto.toString();
            uriList.add(selectedPhoto);
        }
    }

    private void dispatchTakePictureIntent() {
        Intent takePictureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        File photoFile = null;
        try {
            photoFile = createImageFile();
        } catch (IOException ex) {
            Toast.makeText(this, "Something went wrong.", Toast.LENGTH_SHORT).show();
        }
        if (photoFile != null) {
            Uri photoURI = FileProvider.getUriForFile(this, "com.example.challengeprovider", photoFile);
            takePictureIntent.putExtra(MediaStore.EXTRA_OUTPUT, photoURI);
            startActivityForResult(takePictureIntent, REQUEST_TAKE_PHOTO);
        }
    }

    private File createImageFile() throws IOException {
        //Toast.makeText(myApplication, "We got here", Toast.LENGTH_SHORT).show();
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String imageFileName = "JPEG_" + timeStamp + "_";
        File storageDir = getExternalFilesDir(Environment.DIRECTORY_PICTURES);
        File image = File.createTempFile(imageFileName, ".jpg", storageDir);
        mCurrectPhotoPath = image.getAbsolutePath();
        return image;
    }

    public void openWebPage(String url) {
        if (!url.startsWith("http://") || !url.startsWith("https://")) { url = "https://" + url; }
        Uri webpage = Uri.parse(url);
        Intent intent = new Intent(Intent.ACTION_VIEW, webpage);
        startActivity(intent);
    }

    public void sendEmail(String[] addresses, String subject) {
        Intent intent = new Intent(Intent.ACTION_SENDTO);
        intent.setData(Uri.parse("mailto:"));
        intent.putExtra(Intent.EXTRA_EMAIL, addresses);
        intent.putExtra(Intent.EXTRA_SUBJECT, subject);
        startActivity(intent);
    }

    public void showMap(Uri geoLocation) {
        Intent intent = new Intent(Intent.ACTION_VIEW);
        intent.setData(geoLocation);
        startActivity(intent);
    }

    public void composeMmsMessage(String phoneNumber, String message) {
        Intent intent = new Intent(Intent.ACTION_SENDTO);
        intent.setData(Uri.parse("smsto:" + phoneNumber));
        intent.putExtra("sms_body", message);
        startActivity(intent);
    }

    public void callPhoneNumber(String phoneNumber) {
        Intent intent = new Intent(Intent.ACTION_CALL);
        intent.setData(Uri.parse("tel:" + phoneNumber));
        if (ActivityCompat.checkSelfPermission(getApplicationContext(), Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(AddEditOne.this, new String[] { Manifest.permission.CALL_PHONE }, PERMISSION_TO_CALL);
        } else { startActivity(intent); }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults) {
        switch (requestCode) {
            case PERMISSION_TO_CALL: {
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    callPhoneNumber(et_phone.getText().toString());
                } else {
                    Toast.makeText(this, "Cannot make call without permission", Toast.LENGTH_SHORT).show();
                }
                return;
            }
        }
    }
}