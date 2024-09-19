import heapq
class Solution:
    def shortestPath(self, n: int, edges, src: int):
        adj={}
        for i in range(n):
            adj[i]=[]

        for s,d,weight in edges:
            adj[s].append([d,weight])
        
        shortest={}
        minHeap=[[0,src]]

        while minHeap:
            w1,n1=heapq.heappop(minHeap)
            if n1 in shortest:
                continue
            shortest[n1]=w1

            for n2,w2 in adj[n1]:
                if n2 not in shortest:
                    heapq.heappush(minHeap,[w1+w2, n2])
        
        for i  in range(n):
            if i not in shortest:
                shortest[i]=-1

        return shortest
S1=Solution()
print(S1.shortestPath(n=5, edges=[[0,1,10],[0,2,3],[1,3,2],[2,1,4],[2,3,8],[2,4,2],[3,4,5]],src=0))
