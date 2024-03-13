import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	static int calcula(BigInteger n) {
		if(n.compareTo(BigInteger.TEN) == -1) {
			return n.intValue();
		}
		BigInteger total = new BigInteger("0");
		while(n.compareTo(BigInteger.ZERO) == 1) {
			total = total.add(n.mod(BigInteger.TEN));
			n = n.divide(BigInteger.TEN);
		}
		return calcula(total);
	}
	
	public static void main(String[] args) {
		BigInteger N, M;
		String n, m;
		int sn, sm;
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()) {
			n = in.next();
			m = in.next();
			
			if(n.equals("0") && m.equals("0"))
				break;
			
			N = new BigInteger(n);
			M = new BigInteger(m);
			
			sn = calcula(N);
			sm = calcula(M);
						
			if(sn > sm)
				System.out.println("1");
			else if(sn < sm)
				System.out.println("2");
			else
				System.out.println("0");
		}
	
	}

}
