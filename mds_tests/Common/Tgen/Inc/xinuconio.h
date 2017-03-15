/******************************************************************************
* Copyright (C) janvier 2001 Bibloth�que de fonctions mettant en oeuvre les   *
* bases de donn�es terminfo : xinuconio.h                                     *
*                                                                             *
* Auteur : Alain Riffart, ariffart@club-internet.fr                           *
*                                                                             *
* Ce programme est libre, vous pouvez le redistribuer et/ou le modifier selon *
* les termes de la Licence Publique G�n�rale GNU publi�e par la Free Software *
* Foundation (version 2 ou bien toute autre version ult�rieure choisie par    *
* vous).                                                                      *
*                                                                             *
* Ce programme est distribu� car potentiellement utile, mais SANS AUCUNE      *
* GARANTIE, ni explicite ni implicite, y compris les garanties de             *
* commercialisation ou d'adaptation dans un but sp�cifique. Reportez-vous �   *
* la Licence Publique G�n�rale GNU pour plus de d�tails.                      *
*                                                                             *
* Vous devez avoir re�u une copie de la Licence Publique G�n�rale GNU en m�me *
* temps que ce programme ; si ce n'est pas le cas, �crivez � la Free Software *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307,        *
* �tats-Unis.                                                                 *
******************************************************************************/

#include <ncurses.h>

/* Par d�faut les donn�es de la base terminfo sont cherch�es dans un fichier
   pour un terminal linux. Les modifications sont simples � apporter si vous
   voulez vous r�f�rer � la base de donn�es d'un autre terminal *************/

# define termi setupterm("linux",fileno(stdin),NULL)


/*********** Directives de compilation utiles � la fonction clrscr ***********/

# define efecran tigetstr("clear")

/*********** Directives de compilation utiles � la fonction clreol ***********/

# define efli tigetstr("el")

/*********** Directives de compilation utiles � la fonction delline **********/

# define delli tigetstr("dl1")

/*********** Directives de compilation utiles � la fonction insline **********/

# define insli tigetstr("il1")

/*********** Directives de compilation utiles � la fonction highvideo ********/

# define hivi tigetstr("bold")

/*********** Directives de compilation utiles � la fonction lowvideo ********/ 

# define lovi tigetstr("dim")

/***** Directives de compilation utiles � la fonction clreol normalvideo *****/

# define novi tigetstr("sgr0")

/******* Directives de compilation utiles � la fonction _setcursortype *******/

/* Trois directives pour produire trois s�quences d'�chappement qui  permettent
   de g�rer l'apparence du curseur :
   efcur -> curseur invisible
   gdcur -> curseur pav�
   curseur -> curseur un trait ***********************************************/

# define efcur tigetstr("civis")   
# define gdcur tigetstr("cvvis")
# define curseur tigetstr("cnorm")

/* Trois constantes qui serviront de param�tres � la fonction _setcursortype */

# define _NOCURSOR 0      // Curseur invisible
# define _NORMALCURSOR 1  // Curseur en surbrillance ou pav� szlon syst�mes
# define _SOLIDCURSOR 2   // Curseur normal r�duit � un trait

/********** Directives de compilation utiles � la fonction gotoxy ************/

# define posxy tigetstr("cup")

/********* Directives de compilation utiles � la fonction textcolor **********/

# define coult tigetstr("setaf")

/********** Directives de compilation utiles � la fonction gotoxy ************/

# define coulf tigetstr("setab")

/***** Les identificateurs de couleurs valables pour le fond et la forme *****/

# define noir 0
# define rouge 1
# define vert 2
# define jaune 3
# define bleu 4
# define magenta 5
# define cyan 6
# define blanc 7



/********** Directives de compilation utiles � la fonction textattr **********/

/* Les neufs param�tres n�cessaires � la fonction textattr
  - surbri pour surbrillance
  - ssli pour soulignement
  - invi pour inversion vid�o
  - cligno pour clignotement
  - bint pour basse intensit�
  - gras pour affichage en carat�res gras
  - invis pour affichage invisible
  - prote pour affichage prot�g�
  - altcar pour activation d�sactivation de la touche alternate 
  - defmod pour la r�initialisation des modes d'affichage par d�faut *********/

# define surbri 256
# define ssli 128
# define invi 64
# define cligno 32
# define bint 16
# define gras 8
# define invis 4
# define prote 2
# define altcar 1
# define defmode 0

/***************  R�cup�ration de la  valeur de la capacit� sgr **************/

# define modaf tigetstr("sgr")

/******************************** Les prototypes *****************************/

void clrscr (void);
void clreol (void);
void delline (void);
void insline (void);
void highvideo (void);
void lowvideo (void);
void normalvideo (void);
void _setcursortype (int _type);
void gotoxy (int x, int y);
void textcolor (int _color);
void textbackground (int _color);
void textattr (int _mode);
int _lignes(void);
int _colonnes();
