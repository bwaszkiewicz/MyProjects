package pl.polsl.calculationpiandroid;

import android.content.Intent;
import android.graphics.Color;
import android.net.ParseException;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;



public class MainMenu extends AppCompatActivity {

    private int numberOfPoints;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_menu);

        Button button = (Button) findViewById(R.id.CalcButton);
        button.setOnClickListener (new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {

                nextStep(view);
            }
        });

    }

    public void nextStep(View view){

        TextView numberField = (TextView) findViewById(R.id.NumberField);

        if(numberField.getText().toString().isEmpty()){
            numberField.setHint("You must enter number!");
            numberField.setHintTextColor(Color.RED);
            return;
        }

        try {
            this.numberOfPoints = Integer.parseInt(numberField.getText().toString());
        } catch (ParseException e) {
            numberField.setHint("You must enter number!");
            numberField.setHintTextColor(Color.RED);
            return;
        }

        if(numberOfPoints<1){
            numberField.setText("");
            numberField.setHint("Number must be greater than 0!");
            numberField.setHintTextColor(Color.RED);
            return;
        }

        Intent i = new Intent(this, ResultWindow.class);
        i.putExtra("numberOfPoints", numberOfPoints);
        startActivity(i);
    }

}
