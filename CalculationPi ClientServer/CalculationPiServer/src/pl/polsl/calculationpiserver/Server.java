/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpiserver;

import java.io.Closeable;
import java.io.IOException;
import java.net.ServerSocket;

/**
 * Class responsible for serverSocket support
 * 
 * @author BW
 * @version 1.0
 */
public class Server implements Closeable{
    /**
     * Server socket representation
     */
    private final ServerSocket SERVERSOCKET;

    /**
     * Default constructor creating the new server socket
     * 
     * @param port port number associated with the server socket
     * @throws IOException when server socket creation error
     */
    Server(int port) throws IOException {
        
        SERVERSOCKET = new ServerSocket(port);
    }
    
    /**
     * Method responsible for closing the server socket
     * 
     * @throws IOException when there will be problems in the connection
     */
    @Override
    public void close() throws IOException {
        if(SERVERSOCKET!=null)
            SERVERSOCKET.close();
    }
    
    /**
     * Getter for 'SERVERSOCKET' field
     * 
     * @return current server socket
     */
    public ServerSocket getServerSocket(){
        return SERVERSOCKET;
    }
}
