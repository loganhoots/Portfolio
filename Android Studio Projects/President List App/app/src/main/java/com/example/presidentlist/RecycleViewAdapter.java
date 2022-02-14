package com.example.presidentlist;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.constraintlayout.solver.state.State;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;
import com.bumptech.glide.Glide;
import java.util.List;

public class RecycleViewAdapter extends RecyclerView.Adapter<RecycleViewAdapter.MyViewHolder> {

    List<President> presidentList;
    Context context;

    public RecycleViewAdapter(List<President> presidentList, Context context) {
        this.presidentList = presidentList;
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
        holder.tv_president_name.setText(presidentList.get(position).getName());
        holder.tv_president_election_date.setText(String.valueOf(presidentList.get(position).getDateOfElection()));
        Glide.with(context).load(presidentList.get(position).getImageURL()).into(holder.iv_president_pic);
        holder.parentLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(context, AddEditOne.class);
                intent.putExtra("id", presidentList.get(position).getId());
                context.startActivity(intent);
            }
        });
    }

    @Override
    public int getItemCount() { return presidentList.size(); }

    public class MyViewHolder extends RecyclerView.ViewHolder {
        ImageView iv_president_pic;
        TextView tv_president_name;
        TextView tv_president_election_date;
        ConstraintLayout parentLayout;

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            iv_president_pic = itemView.findViewById(R.id.iv_presidentPicture);
            tv_president_election_date = itemView.findViewById(R.id.tv_dateElection);
            tv_president_name = itemView.findViewById(R.id.tv_presidentName);
            parentLayout = itemView.findViewById(R.id.oneLinePresidentLayout);
        }
    }
}
