package pl.polsl.calculationpiandroid;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import pl.polsl.calculationpiandroid.model.InvalidArgumentException;
import pl.polsl.calculationpiandroid.model.Model;
import pl.polsl.calculationpiandroid.model.MonteCarloMethods;

public class ResultWindow extends AppCompatActivity {

    private int numberOfPoints;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result_window);

        this.numberOfPoints = getIntent().getIntExtra("numberOfPoints",1);
        TextView resultText = (TextView) findViewById(R.id.resultText);
        resultText.setText("Calculated value for "+Integer.toString(this.numberOfPoints)+" points is:");

        TextView resultField = (TextView) findViewById(R.id.resultField);
        Model model = new MonteCarloMethods();
        try {
            resultField.setText(Double.toString(model.calculatePi(this.numberOfPoints)));
        } catch (InvalidArgumentException e) {

        }


        Button button = (Button) findViewById(R.id.BackButton);
        button.setOnClickListener (new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {

                backStep(view);
            }
        });
    }

    public void backStep(View view){
        Intent i = new Intent(this, MainMenu.class);
        i.putExtra("numberOfPoints", numberOfPoints);
        startActivity(i);
    }

}
