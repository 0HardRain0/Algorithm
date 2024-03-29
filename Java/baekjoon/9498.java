import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int A = Integer.parseInt(st.nextToken());

        if ( A >= 90) {
            System.out.println("A");
        } else if(79 < A){
            System.out.println("B");
        } else if (69 < A) {
            System.out.println("C");
        } else if (59 < A) {
            System.out.println("D");
        } else {
            System.out.println("F");
        }
    }
}