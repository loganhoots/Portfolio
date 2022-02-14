package com.example.presidentlist;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;
import com.bumptech.glide.Glide;
import java.util.List;

public class RecycleViewAdapter extends RecyclerView.Adapter<RecycleViewAdapter.MyViewHolder> {

    List<Contact> contactList;
    Context context;

    public RecycleViewAdapter(List<Contact> contactList, Context context) {
        this.contactList = contactList;
        this.context = context;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.one_line_president, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        holder.tv_contact_name.setText(contactList.get(position).getName());
        holder.tv_contact_phone.setText(String.valueOf(contactList.get(position).getPhoneNumber()));
        Glide.with(context).load(contactList.get(position).getImage()).into(holder.iv_president_pic);
        holder.parentLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(context, AddEditOne.class);
                intent.putExtra("id", contactList.get(position).getId());
                context.startActivity(intent);
            }
        });
    }

    @Override
    public int getItemCount() { return contactList.size(); }

    public class MyViewHolder extends RecyclerView.ViewHolder {
        ImageView iv_president_pic;
        TextView tv_contact_name;
        TextView tv_contact_phone;
        ConstraintLayout parentLayout;

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            iv_president_pic = itemView.findViewById(R.id.iv_contactPic);
            tv_contact_phone = itemView.findViewById(R.id.tv_contactNumber);
            tv_contact_name = itemView.findViewById(R.id.tv_contactName);
            parentLayout = itemView.findViewById(R.id.oneLinePresidentLayout);
        }
    }
}
