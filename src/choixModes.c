/**
 * @file choixModes.c
 * @author Zoé Marquis (zoe_marquis@ens.univ-artois.fr)
 * @author Enzo Nulli (enzo_nulli@ens.univ-artois.fr)
 * @brief Ensemble de fonctions de dialogue par la console pour choisir le mode
 * de jeu.
 * @version 1.0
 * @date 2022-12-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "choixModes.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Supprime ce qu'il y a dans le buffer de stdin.
 */
static void clearBuffer() {
  char c;
  while ((c = getchar()) != '\n' && (c != EOF))
    ;
}

/**
 * @brief Dialogue avec l'utilisateur pour lui permettre de choisir le mode
 * d'interface avec lequel il souhaite jouer.
 *
 * @param interface un caractère représentant le mode souhaité
 */
void choix_interface(char *interface) {
  printf("Choisissez l'interface de jeu. Entrez :\n"
         "'g' pour jouer en mode interface graphique\n"
         "'c' pour jouer en mode console\n"
         "Votre choix : ");
  scanf("%c", interface);
  clearBuffer();
  while (*interface != 'g' && *interface != 'c') {
    printf("Entrée incorrecte. Veuillez réessayer : ");
    scanf("%c", interface);
    clearBuffer();
  }
  assert(*interface == 'c' || *interface == 'g');
}

/**
 * @brief Dialogue avec l'utilisateur pour lui permettre de choisir le mode
 * de jeu avec lequel il souhaite jouer.
 *
 * @param mode un caractère représentant le mode souhaité
 */
void choix_mode(char *mode) {
  printf("Choisissez un mode de jeu. Entrez :\n"
         "'h' pour jouer à deux\n"
         "'a' pour jouer contre une intelligence artificielle\n"
         "'i' pour qu'une intelligence artificielle joue contre vous\n"
         "'s' pour être spectateur d'une partie entre deux intelligences "
         "artificielles\nVotre choix : ");
  scanf("%c", mode);
  clearBuffer();
  while (*mode != 'h' && *mode != 'a' && *mode != 'i' && *mode != 's') {
    printf("Entrée incorrecte. Veuillez recommencer : ");
    scanf("%c", mode);
    clearBuffer();
  }
  assert(*mode == 'h' || *mode == 'a' || *mode == 'i' || *mode == 's');
}

/**
 * @brief Dialogue avec l'utilisateur pour lui permettre de choisir le niveau de
 * l'IA avec lequel il souhaite jouer.
 *
 * @param niveau un caractère représentant le niveau souhaité
 */
void choix_niveau(char *niveau) {
  printf("Choisissez le niveau de l'intelligence artificielle. Entrez :\n"
         "'1' pour le mode facile\n"
         "'2' pour le mode moyen\n"
         "'3' pour le mode difficile\nVotre choix : ");
  scanf("%c", niveau);
  clearBuffer();
  while (*niveau != '1' && *niveau != '2' && *niveau != '3') {
    printf("Entrée incorrecte. Veuillez recommencer : ");
    scanf("%c", niveau);
    clearBuffer();
  }
  assert(*niveau == '1' || *niveau == '2' || *niveau == '3');
}

/**
 * @brief Dialogue avec l'utilisateur pour lui permettre de choisir les niveaux
 * des 2 IA avec lequel il souhaite jouer.
 *
 * @param niveau1 un caractère représentant le niveau de l'IA n°1
 * @param niveau2 un caractère représentant le niveau de l'IA n°2
 */
void choix_niveaux(char *niveau1, char *niveau2) {
  printf("Choisissez le niveau de la première intelligence artificielle. "
         "Entrez :\n"
         "'1' pour le mode facile\n"
         "'2' pour le mode moyen\n"
         "'3' pour le mode difficile\nVotre choix : ");
  scanf("%c", niveau1);
  clearBuffer();
  while (*niveau1 != '1' && *niveau1 != '2' && *niveau1 != '3') {
    printf("Entrée incorrecte. Veuillez recommencer : ");
    scanf("%c", niveau1);
    clearBuffer();
  }

  printf("Choisissez le niveau de la seconde intelligence artificielle. "
         "Entrez :\n"
         "'1' pour le mode facile\n"
         "'2' pour le mode moyen\n"
         "'3' pour le mode difficile\nVotre choix : ");
  scanf("%c", niveau2);
  clearBuffer();
  while (*niveau2 != '1' && *niveau2 != '2' && *niveau2 != '3') {
    printf("Entrée incorrecte. Veuillez recommencer : ");
    scanf("%c", niveau1);
    clearBuffer();
  }
  assert(*niveau1 == '1' || *niveau1 == '2' || *niveau1 == '3');
  assert(*niveau2 == '1' || *niveau2 == '2' || *niveau2 == '3');
}
