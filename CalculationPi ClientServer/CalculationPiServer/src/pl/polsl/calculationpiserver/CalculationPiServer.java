package pl.polsl.calculationpiserver;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Properties;
import pl.polsl.calculationpiserver.model.MonteCarloMethods;

/**
 * Main class of the server application realizing calculating the Pi value.
 * 
 * @author BW
 * @version 1.0
 */
public class CalculationPiServer {

    /**
     * Main method of server application.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        Properties defaultProperties = new Properties();
        try( FileInputStream in = new FileInputStream(".properties")){
            defaultProperties.load(in);
        }
        catch(IOException e){}
        
        try (Server server = new Server(Integer.parseInt(defaultProperties.getProperty("port")))) {
            System.out.println("Server started");
            while (true) {
                Socket socket = server.getServerSocket().accept();
                try {
                    SingleService singleService = new SingleService(socket);
                    MonteCarloMethods model = new MonteCarloMethods();
                    singleService.realize(model);
                } 
                catch (IOException e) {
                    System.err.println(e.getMessage());
                }
            }
        } catch (NumberFormatException e){
          System.err.println("Incorrect port value in the .properties file");  
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
        
    }
    
}
