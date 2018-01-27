#include <cstdio>

bool found[100];
int g[100][100];
int gi[100];

void visit(int x) {
  if (found[x]) {
    return;
  }
  found[x] = true;
  for (int i = 0; i < gi[x]; i++) {
    visit(g[x][i]);
  }
}

int main() {
  int test = 1;
  while (true) {
    int e, l;
    scanf("%d%d", &e, &l);
    if (e == 0 && l == 0) {
      return 0;
    }
    for (int i = 0; i < e; ++i) {
      gi[i] = 0;
      found[i] = false;
    }
    printf("Teste %d\n", test++);
    for (int i = 0; i < l; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x;
      --y;
      g[x][gi[x]++] = y;
      g[y][gi[y]++] = x;
    }
    visit(0);
    bool missing = false;
    for (int i = 0; i < e; ++i) {
      if (!found[i]) {
        missing = true;
      }
    }
    printf("%s\n\n", missing ? "falha" : "normal");
  }
  return 0;
}
