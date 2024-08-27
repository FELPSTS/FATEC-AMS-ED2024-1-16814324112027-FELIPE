/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 **
 * Atividade B3-1-Cálculo tempo execuçao-Insertion Sort *
 **
 * Para: Prof Veríssimo * * Objetivo: Tempo de execução *
 **
 * Autor: FELIPE TORQUATO * * Data:13/08/2024 *
 * *--------------------------------------------------------------**/

#include <stdio.h>
                                                    
1.  for j ← 2 to length[A]                  // 2t 
2.      do key ← A[j]                       // 1t
3.      ▷ Insert A[j] into the sorted       //0t
4.        sequence A[1 ... j-1].            // 0t
5.      i ← j - 1                           // 2t
6.      while i > 0 and A[i] > key          // 2tn²
7.          do A[i + 1] ← A[i]              // 2tn²
8.          i ← i - 1                       // 2t
9.      A[i + 1] ← key                      // 2t



// 4tn² + 10t - 3t