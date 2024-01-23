import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        BigInteger result = new BigInteger("0");

        try {
            String[] numberList = br.readLine().split(" ");
            br.close();

            for(String b : numberList){
                result = new BigInteger(b).add(result);
            }

            System.out.println(result);
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}