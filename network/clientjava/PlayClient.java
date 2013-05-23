
package client;

import java.io.IOException;
import java.net.UnknownHostException;

public class PlayClient 
{
    public static void main(String[] args) throws UnknownHostException, IOException, InterruptedException
    {
        Client client = new Client("localhost",9999);
        client.Connect();
        client.sendMessage("HOLA");
        client.readMessage();
    }    
}
