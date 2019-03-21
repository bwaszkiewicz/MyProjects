package pl.polsl.calculationpiclient.view;

/**
 * View to support the console version of the program
 * 
 * @author BW
 * @version 1.0
 */
public class ClientView implements View {
    
    /**
     * A method displaying server's response for user
     * 
     * @param message server message to be displayed to the user
     */
    @Override
    public void showServerMessage(String message){
        System.out.println(message);
    }
    
    /**
     * A method displaying server warnings
     * 
     * @param message server message to be displayed to the user
     */
    @Override
    public void showErrorFromServer(String message){
        System.err.println(message);
    }
}
