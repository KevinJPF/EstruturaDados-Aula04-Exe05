#include "filachar.h"
#include "pilhachar.h"
#include <stdio.h>
#include <string.h>
int concha(char *c) { // verifica se c é uma concha
  Pilha P = pilha(20);

  for (int i = 0; i < strlen(c); i++) {

    if (vaziap(P) || topo(P) != c[i])
      empilha(c[i], P);
    else
      desempilha(P);
  }

  if (vaziap(P))
    return 1;
  else
    return 0;
}
void filtra(Fila F) { // exibe apenas as cadeias em F que são conchas
  int totalConchas;

  for (int i = 0; i < F->total; i++) {
    if (concha(F->item[i])) {
      printf("\nA cadeia %s e uma concha.\n", F->item[i]);
      totalConchas++;
    }
  }

  printf("\nO total de cadeias que sao conchas e: %d\n", totalConchas);
}
int main(void) {
  Fila F = fila(20);
  enfileira("AAAAAAAABAAABA", F);
  enfileira("BBBBBBBBBBBBBB", F);
  enfileira("ABBABBABBABB", F);
  enfileira("AAABAAABBABAAA", F);
  enfileira("ABAABAAAAAAAAA", F);
  enfileira("AABAAAAAABAAAA", F);
  enfileira("AAAABB", F);
  enfileira("AABBBBAABAAB", F);
  enfileira("ABAAAAAAAAAB", F);
  enfileira("ABABBBABAB", F);
  enfileira("BBBBBBBBBBBBBB", F);
  enfileira("AABAABAAAA", F);
  enfileira("AABAAABBBBBABB", F);
  enfileira("BBBAAAAABA", F);
  enfileira("BBBBBBBBBBBBBB", F);
  enfileira("AAAAAAAAAAAABB", F);
  enfileira("BAAAAABAAAAAAA", F);
  enfileira("BBBBABBBBBBA", F);
  enfileira("BBABABAAAAAABB", F);
  enfileira("ABAABAABAB", F);

  filtra(F); // deve exibir 12 conchas

  destroif(&F);
  return 0;
}