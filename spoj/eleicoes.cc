#include <cstdio>
#include <map>

int main() {
	int n;
	scanf("%d", &n);
	std::map<int, int> votos;
	int max_votos = 0, max_candidato;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		votos[x]++;
		if (votos[x] > max_votos) {
			max_candidato = x;
			max_votos = votos[x];
		}
	}
	
	printf("%d", max_candidato);

	return 0;
}
