package com.flight.connection;

import java.util.ArrayList;
import java.util.PropertyResourceBundle;
import java.util.ResourceBundle;

public class Finder {
	public static void main ( String[] Args ) {
		Finder f = new Finder();
		try {
			
		ResourceBundle rp = PropertyResourceBundle.getBundle("problem1");
		System.out.println( 
			f.find( 
				Integer.parseInt(rp.getString("n")),
				rp.getString("flights").split(";"), 
				Integer.parseInt(rp.getString("time"))
				) 
			);
		} catch ( Exception e) {
			e.printStackTrace();
			System.out.println();
			e.getCause().printStackTrace();
		}
		return;
	}
	private Graph g;
	public int find (
			int n, String[] flights, int time
			) {
		this.setG(Graph.parse(flights));
		this.getG().findroutes(1,n);
		return 0;
	}
	
	public void setG(Graph g) {
		this.g = g;
	}

	public Graph getG() {
		return g;
	}

	public static class Graph {
		protected ArrayList<Edge> edges = 
			new ArrayList<Edge>();
		protected Vertex[] vertex;
		public static Graph parse ( String[] flights ) {
			Graph g = new Graph();
			String flightstr = strconcat ( flights );
			String[] fls = flightstr.split(" ");
			for ( String fl: fls ) {
				if (  fl.length() == 0 ) continue;
				int[] i= new int[5];
				int c=0;
				for ( String t: fl.split(",") ) {
					System.out.println ( t );
					i[c++] = Integer.parseInt(t);
				}
				g.edges.add(new Edge(i[0], i[1], i[2], i[3], i[4]));
			}
			return g;
		}
		private static final String strconcat ( String[] flights ) {
			StringBuilder sb = new StringBuilder ();
			for ( String s: flights ) {
				sb.append(s);
			}
			return sb.toString();
		}		
		public final boolean findroutes ( int from, int to ) {
			return false;
		}
		public static class Vertex {
			protected final int city;
			private static Vertex[] vertices = 
				new Vertex[477];
			public ArrayList<Edge> incoming = 
				new ArrayList<Edge>();
			public Vertex ( int city ) {
				this.city = city;
			}
			public static final Vertex vertex( int city ) {
					if ( vertices[city] != null ) {
						return vertices[city];
					}
				vertices[city]= new Vertex(city);
				return vertices[city];
			}
			public final void addEdgeIncoming ( Edge e ) {
				if ( this.incoming.contains(e)) { return; }
				this.incoming.add( e);
			}
			
			
		}
		public static class Edge {
			protected final Vertex a,b;
			protected final int f,t,p;
			public Edge ( int a, int b, int f, int t, int p ) {
				this.a = Vertex.vertex(a) ;
				this.b = Vertex.vertex(b);
				this.f = f;
				this.t = t;
				this.p = p;
				
				this.b.addEdgeIncoming(this);
				//this.a.addEdgeOutgoing(this);
			}
		}
	}
}



