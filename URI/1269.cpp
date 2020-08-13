#include <bits/stdc++.h>
#define MAX_E 1010
#define MAX_T (1010 + MAX_E)

using namespace std;

vector<int> taskGraph[MAX_T];

unordered_set<int> tasksByEmployee[MAX_E];

int taskEffort[MAX_T];

int maxTaskEffort[MAX_T];

int level[MAX_T];

unordered_map<int, unordered_set<int>> dependencies;

int visited[MAX_T];

void dfs(int u) {
	visited[u] = 1;
	int effort = 0;
	for (int v : taskGraph[u]) {
		dependencies[u].insert(v);
		
		if (!visited[v]) {
			dfs(v);
		}

		dependencies[u].insert(dependencies[v].begin(), dependencies[v].end());

		effort += maxTaskEffort[v];
	}
	maxTaskEffort[u] = effort + taskEffort[u];
}

int main() {
	int T, E, numberEmployees, basicEffort, tasksNumber, anotherTask, employee;

	while(scanf("%d %d", &T, &E) == 2 && (T || E)) {
		
		memset (taskEffort, 0, sizeof taskEffort);
		memset (maxTaskEffort, 0, sizeof maxTaskEffort);
		memset (level, -1, sizeof level);
		memset (visited, 0, sizeof visited);
		
		
		for (int taskId = 1; taskId <= T; taskId++) {
		
			scanf("%d %d %d", &taskEffort[taskId], &tasksNumber, &numberEmployees);
						
			for (int dTaskIdx = 0; dTaskIdx < tasksNumber; dTaskIdx++) {
				scanf("%d", &anotherTask);
				taskGraph[taskId].push_back(anotherTask);
			}

			for (int dWorkerIdx = 0; dWorkerIdx < numberEmployees; dWorkerIdx++) {
				scanf("%d", &employee);
				tasksByEmployee[employee].insert(taskId);
			}
		}

		for (int tId = 1; tId <= T; tId++) {
			if (!visited[tId]) {
				dfs (tId);
			}
		}
		
		unordered_set<int> resultSet;
		
		printf("*****\n");		
		for (int e = 1; e <= E; e++) {
			int salary = 0;
			
			for (auto t1 : tasksByEmployee[e]) {
				resultSet.insert(dependencies[t1].begin(), dependencies[t1].end());			
			}
			
			for (auto t1 : tasksByEmployee[e]) {
				if (resultSet.find(t1) == resultSet.end()) {
					salary += maxTaskEffort[t1];
				}
			}
			
			printf("%d %d\n", e, salary);
			resultSet.clear();
		}
				
		for (auto &neighbourList : taskGraph) {
			neighbourList.clear();
		}
		
		for (auto &employeeTasks : tasksByEmployee) {
			employeeTasks.clear();
		}
		dependencies.clear();
	}

	return 0;
}


