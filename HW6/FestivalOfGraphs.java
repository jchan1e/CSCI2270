  
import java.util.Set;
import java.util.HashSet;
import java.util.TreeSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import java.util.Deque;
import java.util.ArrayDeque;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;

class FestivalOfGraphs
{
	private Graph g;
	
	public void init(String graphFile) 
	{
		System.out.println(graphFile);
		// open the file
		BufferedReader br = null;
		
		try
		{
			// open the file called "graph.txt"
			br = new BufferedReader(new FileReader(graphFile));
		
			// read the first line
			String line = br.readLine();	
			
			// convert the first line (a string) to an integer (numberOfVertices)
			Integer n = Integer.parseInt(line);
			
			g = new Graph(n);
		
			for (int fromVertex = 0; fromVertex < n; ++fromVertex)
			{
				line = br.readLine();
				if (line.length() > 0)
				{
					int pos = 0;
					while (line.indexOf("{", pos) > -1)
					{
						String sub = line.substring(line.indexOf("{", pos) + 1, line.indexOf("}", pos + 1));
						Integer toVertex = Integer.parseInt(sub.substring(0, sub.indexOf(",")));
						Integer weightOfEdge = Integer.parseInt(sub.substring(sub.indexOf(",") + 1, sub.length()));
						pos = line.indexOf("}", pos + 1);
						if (!g.hasEdge(fromVertex, toVertex))
							g.addEdge(fromVertex, toVertex, weightOfEdge);
					}	
				}	
			}
		}
		catch (FileNotFoundException ex) {
			// handle FileNotFoundException
			System.out.println("No such file as " + graphFile + " in your directory");
		}
		catch (IOException ex) {
			// handle IOException
			System.out.println("Ran into problems processing " + graphFile);
		}
		finally {
			if (br != null) {
				try {
					br.close();
				}
				catch (IOException ex) {
					// handle IOException
					System.out.println("Ran into unrecoverable problems processing " + graphFile);
				}
			}
		}
		
	}
	
	public List<Integer> DepthFirstList(Integer v)
	{
		List<Integer> vertices = new ArrayList<Integer>();
		Deque<Integer> toExplore = new ArrayDeque<Integer>();
		List<Integer> visited = new ArrayList<Integer>();

		toExplore.addFirst(v);

		while (toExplore.peekFirst() != null)
		{
			Integer n = toExplore.removeFirst();
			if (!visited.contains(n))
			{
				vertices.add(n);
				visited.add(n);
			}
			Set<Integer> neighbors = g.getAdjList(n).keySet();
			for(Integer i : neighbors)
			{
				if (!visited.contains(i))
				{
					toExplore.addFirst(i);
				}
			}
		}

		return vertices;
	}
	
	public List<Integer> BreadthFirstList(Integer v) 
	{
		List<Integer> vertices = new ArrayList<Integer>();
		Deque<Integer> toExplore = new ArrayDeque<Integer>();
		List<Integer> visited = new ArrayList<Integer>();

		toExplore.addFirst(v);

		while (toExplore.peekFirst() != null)
		{
			Integer n = toExplore.removeLast();
			if (!visited.contains(n))
			{
				vertices.add(n);
				visited.add(n);
			}
			Set<Integer> neighbors = g.getAdjList(n).keySet();
			for(Integer i : neighbors)
			{
				if (!visited.contains(i))
				{
					toExplore.addFirst(i);
				}
			}
		}

		return vertices;
	}

	
	public Graph DepthFirstSpanningTree(Integer v) 
	{
		Graph t = new Graph(g.getNumVertices()); 
		Deque<Integer> stackie = new ArrayDeque<Integer>();
		List<Integer> visited = new ArrayList<Integer>();

		stackie.addFirst(v);
		visited.add(v);
		Integer n = v;
		Set<Integer> neighbors;
		//Set<Integer> neighborsClone;

		while (stackie.peekFirst() != null)
		{
			neighbors = new TreeSet<Integer>(g.getAdjList(n).keySet());
			Set<Integer>  neighborsClone = new TreeSet<Integer>(neighbors); //Copy neighbors
			for (Integer i : neighborsClone) //Iterate over the copy
			{
				if (visited.contains(i))
					neighbors.remove(i);
			}
			//System.out.println(n + " " + neighbors + " " + neighborsClone);
			if (neighbors.isEmpty())
			{
				stackie.removeFirst();
				visited.add(n);
				if (stackie.peekFirst() != null)
					n = stackie.peekFirst();
			}
			else
			{
				Integer i = (Integer)neighbors.toArray()[0];
				t.addEdge(g.findEdge(n, i));
				visited.add(n);
				visited.add(i);
				n = i;
				stackie.addFirst(n);
				
			}
		}

		return t;
	}
	
	
	public Graph BreadthFirstSpanningTree(Integer v) 
	{
		Graph t = new Graph(g.getNumVertices()); 
		Deque<Integer> stackie = new ArrayDeque<Integer>();
		List<Integer> visited = new ArrayList<Integer>();

		stackie.offer(v);
		visited.add(v);
		Integer n;
		Set<Integer> neighbors;
		//Set<Integer> neighborsClone;

		while (stackie.peekLast() != null)
		{
			n = stackie.poll();
			neighbors = new TreeSet<Integer>(g.getAdjList(n).keySet());
			Set<Integer> neighborsClone = new TreeSet<Integer>(neighbors); //Copy neighbors
			for (Integer i : neighborsClone) //Iterate over the copy
			{
				if (visited.contains(i))
					neighbors.remove(i);
			}
			//System.out.println(n + " " + neighbors + " " + neighborsClone);
			for(Integer i : neighbors)
			{
				t.addEdge(g.findEdge(n, i));
				stackie.offer(i);
				visited.add(i);
			}

		}
		//g.printAdjacencyMatrix();
		return t;
	}

	List<String> DijkstrasShortestPath(Integer t)
	{
		List<Integer> initialized = new ArrayList<Integer>();
		List<Integer> pathWeights = new ArrayList<Integer>();
		List<String> prettyWeights = new ArrayList<String>();
		
		Set<Integer> vertexSet = new HashSet<Integer>();
		
		return prettyWeights;
	}
	
	public Graph PrimsAlgorithm(Integer v) 
	{
		Graph t = new Graph(g.getNumVertices());
	/*	Deque<Integer> stackie = new ArrayDeque<Integer>();
		List<Integer> visited = new ArrayList<Integer>();

		stackie.offer(v);
		visited.add(v);
		Integer n;
		Set<Integer> neighbors;
		//Set<Integer> neighborsClone;

		while (stackie.peekLast() != null)
		{
			n = stackie.poll();
			Set<Integer> newNeighbors = new TreeSet<Integer>(g.getAdjList(n).keySet());
			for (Integer i : newNeighbors) //Iterate over the copy
			{
				if (visited.contains(i))
					newNeighbors.remove(i);
				else
					neighbors.add(i);
			}
			System.out.println(n + " " + neighbors + " " + newNeighbors);


			for(Integer j : visited)
			{
				for(Integer i : g.getAdjList(j).keySet())
				{
					if (!visited.contains(i))
					{
						if (g.getEdgeWeight(j,i) < least)
							least = i;
					}
				}
			}

			t.addEdge(g.findEdge(n, i));
			stackie.offer(i);
			visited.add(i);

		}	*/
		//g.printAdjacencyMatrix();
		return t;
	}
	
	
}

