// 스캐너 써도 됨 근데 스캐너 쪽이 느림

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");


        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int apb = A + B;
        int amb = A * B;
        int arc = A % C;
        int brc = B % C;

        System.out.println(apb % C);
        System.out.println((arc + brc) % C);
        System.out.println(amb % C);
        System.out.println((arc * brc) % C);

    }
}