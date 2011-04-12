package com.mac.tc;

public class BinaryCode {

	public static void main (  String[] args ) {
		BinaryCode bc = new BinaryCode();
		bc.run (  "22111" );
		bc.run("12221112222221112221111111112221111");
		bc.run("123210120");
	}
	
	public final void run ( String encoded ) {
		System.out.println( "test:"+encoded );
		String[] result = this.decode(encoded);
		for ( String r: result ) {
			System.out.println( r );
		}
	}
	
	
	public final String[] decode ( String encoded ) {
		String[] result = new String[2];
		result[0] = trydecode ( 0, encoded );
		result[1] = trydecode ( 1, encoded );
		return result;
	}
	
	public final static int[] strToBits ( String str ) {
		int[] result = new int[str.length()];
		for ( int i = 0; i<str.length(); i++ ) {
			result[i] = Integer.parseInt( String.valueOf( str.charAt(i) ) );
		}
		return result;
	}
	
	public String trydecode ( int seed, String encoded ) {
		int[] result = strToBits ( encoded );
		int previous, current;
		previous = 0;
		current = result[0];
		result[0] = seed;
		for ( int i=0; i < result.length-1; i++ ) {
			//calculate
			int enc = result[i+1];
			result[i+1] = current - result[i] - previous;
			previous = result[i];
			current = enc;
			
			//validate
			if ( result[i] < 0 || result [i] > 1 ) { return "NONE"+i; } 
		}
		//checksum
		int j = result.length - 1;
		if ( current - result[j] - result[j-1] != 0 ) { return "NONEFIM"; } 
		
		//assembly
		StringBuilder sb = new StringBuilder();
		for ( int i=0; i < result.length; i++ ) {
			sb.append( result[i] );
		}
		return  sb.toString();
	}
}
