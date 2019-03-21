package pl.polsl.calculationpiclient.view;

/**
 * Interface of View
 * 
 * @author BW
 * @version 1.0
 */
public interface View {
    /**
     * A method displaying server's response for user
     * 
     * @param message server message to be displayed to the user
     */
    void showServerMessage(String message);
    
    /**
     * A method displaying server warnings
     * 
     * @param message server message to be displayed to the user
     */
    void showErrorFromServer(String message);
}
