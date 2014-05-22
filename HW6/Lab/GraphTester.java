

public class GraphTester
{
	public static void main(String[] args)
	{
		int n = 6;
		Graph G = new Graph(n);
		fillGraph(G, n);
		System.out.println(n + " pointed star");
		for(int i = 0; i < n; ++i)
			System.out.println(G.getAdjList(i));

		n = 8;
		Graph H = new Graph(n);
		fillGraph(H, n);
		System.out.println(n + " pointed star");
		for(int i = 0; i < n; ++i)
			System.out.println(H.getAdjList(i));

		n = 15;
		Graph J = new Graph(n);
		fillGraph(J, n);
		System.out.println(n + " pointed star");
		for(int i = 0; i < n; ++i)
			System.out.println(J.getAdjList(i));
	}

	public static void fillGraph(Graph g, int n)
	{
		for(int i = 0; i < n; ++i)
			g.addEdge(i, (i+(n-1)/2)%n, 1);
	}
}
