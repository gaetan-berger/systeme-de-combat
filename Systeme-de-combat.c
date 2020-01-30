#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Personnages{
    int ViePersonnages;

    int VieGuerrier;
    int ManaGuerrier;
    int AttaqueGuerrier;
    int DefenseGuerrier;
	int ChoixGuerrier;
	int CibleGuerrier;

    int VieVoleur;
    int ManaVoleur;
    int AttaqueVoleur;
    int DefenseVoleur;
	int ChoixVoleur;
	int CibleVoleur;

    int VieMage;
    int ManaMage;
    int AttaqueMage;
    int DefenseMage;
	int ChoixMage;
	int CibleMage;

    int ViePretre;
    int ManaPretre;
    int AttaquePretre;
    int DefensePretre;
	int ChoixPretre;
	int CiblePretre;
	int SoinPretre;

};

typedef struct Personnages perso;

struct Monstres{
	int SpawnMonstre;
	int ennemi;
	
    int VieZombie;
    int AttaqueZombie;
    int DefenseZombie;
	int ChoixZombie;
	int CibleZombie;

    int VieLapin;
    int AttaqueLapin;
    int DefenseLapin;
	int ChoixLapin;
	int CibleLapin;

};

typedef struct Monstres monstre;



int main(void){

    //Randomizer
    srand(time(NULL));


    perso perso;
    monstre monstre;

    perso.ViePersonnages = 1;

    perso.VieGuerrier = 100;
    perso.VieVoleur = 80;
    perso.VieMage = 60;
    perso.ViePretre = 80;

    perso.ManaMage = 20;
    perso.ManaPretre = 20;


    monstre.VieZombie = 120;
    monstre.VieLapin = 60;
	
	monstre.SpawnMonstre = 0;
	monstre.ennemi = 0;

    //Boucle d'attaque
    while (perso.ViePersonnages != 0){

		if ( monstre.SpawnMonstre == 0 ){
		
			//Apparition des monstres
			monstre.ennemi = rand()%3+1; // entre 1-3
		
			monstre.SpawnMonstre = 1;
		
		}
		
		perso.AttaqueGuerrier = rand()%5+20;
		perso.AttaqueVoleur = rand()%4+18;
		perso.AttaqueMage = rand()%6+6;
		perso.AttaquePretre = rand()%6+8;

		perso.DefenseGuerrier = 10;
		perso.DefenseVoleur = 6;
		perso.DefenseMage = 5;
		perso.DefensePretre = 7;
		
		monstre.AttaqueZombie = rand()%5+15;
		monstre.AttaqueLapin = rand()%2+10;
		
		monstre.DefenseZombie = 7;
		monstre.DefenseLapin = 1;
		
		//Action Lapin
		if ( monstre.ennemi == 1 ){
			
			monstre.ChoixLapin = rand()%2+1;
			
			printf("Le lapin a %d points de vie. \n", monstre.VieLapin );
			
			//Le Lapin attend
			if ( monstre.ChoixLapin == 2 ){
				printf("Le lapin vous observe avec un regard mefiant. \n");
			}
		}
		
		//Action Zombie
		if ( monstre.ennemi == 2 ){
			
			monstre.ChoixZombie = rand()%2+1;
			printf("Le zombie a %d points de vie. \n", monstre.VieZombie );
			
			//Defense Zombie
			if ( monstre.ChoixZombie == 2 ){
				monstre.DefenseZombie = monstre.DefenseZombie + 2;	
				printf("Le zombie se defend. \n");
			}
		}
		
		//Action Zombie + Lapin
		if ( monstre.ennemi == 3 ){
			
			monstre.ChoixLapin = rand()%2+1;
			
			printf("Le lapin a %d points de vie. \n", monstre.VieLapin );
			
			//Le Lapin attend
			if ( monstre.ChoixLapin == 2 ){
				printf("Le lapin vous observe avec un regard mefiant. \n");
			}
			
			monstre.ChoixZombie = rand()%2+1;
			printf("Le zombie a %d points de vie. \n", monstre.VieZombie );
			
			//Defense Zombie
			if ( monstre.ChoixZombie == 2 ){
				monstre.DefenseZombie = monstre.DefenseZombie + 2;	
				printf("Le zombie se defend. \n");
			}
			
		}
		
		printf("Votre guerrier a %d points de vie. \n", perso.VieGuerrier );
		printf("Votre voleur a %d points de vie. \n", perso.VieVoleur );
		printf("Votre mage a %d points de vie. \n", perso.VieMage );
		printf("Votre pretre a %d points de vie. \n", perso.ViePretre );
		
		//Action Guerrier
		printf("Saisissez 1 pour attaquer avec le guerrier \n");
		printf("Saisissez 2 pour vous defendre avec le guerrier \n");
		
		scanf("%d",&perso.ChoixGuerrier);
		
		if ( monstre.ennemi == 1 ){
			
			//Attaque Guerrier
			if ( perso.ChoixGuerrier == 1 ){
				perso.AttaqueGuerrier = perso.AttaqueGuerrier - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaqueGuerrier;
				printf("Le lapin subit %d points de degats. \n", perso.AttaqueGuerrier);
			}
			
			//DefenseGuerrier
			if ( perso.ChoixGuerrier == 2 ){
				perso.DefenseGuerrier = perso.DefenseGuerrier + 4;
				printf("Le guerrier se defend. \n");
			}
			
		}
		
		if ( monstre.ennemi == 2 ){
			
			//Attaque Guerrier
			if ( perso.ChoixGuerrier == 1 ){
				perso.AttaqueGuerrier = perso.AttaqueGuerrier - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaqueGuerrier;
				printf("Le zombie subit %d points de degats. \n", perso.AttaqueGuerrier);
			}
			
			//DefenseGuerrier
			if ( perso.ChoixGuerrier == 2 ){
				perso.DefenseGuerrier = perso.DefenseGuerrier + 4;
				printf("Le guerrier se defend. \n");
			}
			
		}
		
		if ( monstre.ennemi == 3 ){
			
			
			//Attaque Guerrier
			if ( perso.ChoixGuerrier == 1 ){
				printf("Saisissez 1 pour attaquer le lapin, 2 pour le zombie \n");
				scanf("%d",&perso.CibleGuerrier);
			
				if ( perso.CibleGuerrier == 1 );{
				
				perso.AttaqueGuerrier = perso.AttaqueGuerrier - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaqueGuerrier;
				printf("Le lapin subit %d points de degats. \n", perso.AttaqueGuerrier);
				}
				
				if ( perso.CibleGuerrier == 2 ){
				perso.AttaqueGuerrier = perso.AttaqueGuerrier - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaqueGuerrier;
				printf("Le zombie subit %d points de degats. \n", perso.AttaqueGuerrier);
				}	
				
			}
			
			//DefenseGuerrier
			if ( perso.ChoixGuerrier == 2 ){
				perso.DefenseGuerrier = perso.DefenseGuerrier + 4;
				printf("Le guerrier se defend. \n");
			}
			
		}
		
		//Action Voleur
		printf("Saisissez 1 pour attaquer avec le voleur \n");
		printf("Saisissez 2 pour vous defendre avec le voleur \n");
		
		scanf("%d",&perso.ChoixVoleur);
		
		if ( monstre.ennemi == 1 ){
			
			//Attaque Voleur
			if ( perso.ChoixVoleur == 1 ){
				perso.AttaqueVoleur = perso.AttaqueVoleur - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaqueVoleur;
				printf("Le lapin subit %d points de degats. \n", perso.AttaqueVoleur);
			}
			
			//Defense Voleur
			if ( perso.ChoixVoleur == 2 ){
				perso.DefenseVoleur = perso.DefenseVoleur + 2;
				printf("Le voleur se defend. \n");
			}
			
		}
		
		if ( monstre.ennemi == 2 ){
			
			//Attaque Voleur
			if ( perso.ChoixVoleur == 1 ){
				perso.AttaqueVoleur = perso.AttaqueVoleur - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaqueVoleur;
				printf("Le zombie subit %d points de degats. \n", perso.AttaqueVoleur);
			}
			
			//Defense Voleur
			if ( perso.ChoixVoleur == 2 ){
				perso.DefenseVoleur = perso.DefenseVoleur + 2;
				printf("Le voleur se defend. \n");
			}
			
		}
		
		if ( monstre.ennemi == 3 ){
			
			
			//Attaque Voleur
			if ( perso.ChoixVoleur == 1 ){
				printf("Saisissez 1 pour attaquer le lapin, 2 pour le zombie \n");
				scanf("%d",&perso.CibleVoleur);
			
				if ( perso.CibleVoleur == 1 );{
				
				perso.AttaqueVoleur = perso.AttaqueVoleur - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaqueVoleur;
				printf("Le lapin subit %d points de degats. \n", perso.AttaqueVoleur);
				}
				
				if ( perso.CibleVoleur == 2 ){
				perso.AttaqueVoleur = perso.AttaqueVoleur - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaqueVoleur;
				printf("Le zombie subit %d points de degats. \n", perso.AttaqueVoleur);
				}	
				
			}
			
			//Defense Voleur
			if ( perso.ChoixVoleur == 2 ){
				perso.DefenseVoleur = perso.DefenseVoleur + 2;
				printf("Le voleur se defend. \n");
			}
			
		}
		
		//Action Mage
		printf("Saisissez 1 pour attaquer avec le mage \n");
		printf("Saisissez 2 pour vous defendre avec le mage \n");
		printf("Saisissez 3 pour lancer une boule de feu en zone qui coute 5 de mana \n");
		
		scanf("%d",&perso.ChoixMage);
		
		if ( monstre.ennemi == 1 ){
			
			//Attaque Mage
			if ( perso.ChoixMage == 1 ){
				perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaqueMage;
				printf("Le lapin subit %d points de degats. \n", perso.AttaqueMage);
			}
			
			//Defense Mage
			if ( perso.ChoixMage == 2 ){
				perso.DefenseMage = perso.DefenseMage + 2;
				printf("Le mage se defend. \n");
			}
			
			//Boule de feu Mage
			if ( perso.ChoixMage == 3 ){
				if ( perso.ManaMage >= 5 ){
					perso.AttaqueMage = perso.AttaqueMage + 15;
					perso.ManaMage = perso.ManaMage - 5;
					perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseLapin;
					monstre.VieLapin = monstre.VieLapin - perso.AttaqueMage;
					printf("Le lapin subit %d points de degats de la boule de feu \n", perso.AttaqueMage);
				}
				else{
					printf("Vous n'avez pas assez de mana \n");
				}
			}
		}
		
		if ( monstre.ennemi == 2 ){
			
			//Attaque Mage
			if ( perso.ChoixMage == 1 ){
				perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaqueMage;
				printf("Le zombie subit %d points de degats. \n", perso.AttaqueMage);
			}
			
			//Defense Mage
			if ( perso.ChoixMage == 2 ){
				perso.DefenseMage = perso.DefenseMage + 2;
				printf("Le mage se defend. \n");
			}
			
			//Boule de feu Mage
			if ( perso.ChoixMage == 3 ){
				if ( perso.ManaMage >= 5 ){
					perso.AttaqueMage = perso.AttaqueMage + 15;
					perso.ManaMage = perso.ManaMage - 5;
					perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseZombie;
					monstre.VieZombie = monstre.VieZombie - perso.AttaqueMage;
					printf("Le zombie subit %d points de degats de la boule de feu \n", perso.AttaqueMage);
				}
				else{
					printf("Vous n'avez pas assez de mana \n");
				}
			}
		
		}
		
		if ( monstre.ennemi == 3 ){
			
			
			//Attaque Mage
			if ( perso.ChoixMage == 1 ){
				printf("Saisissez 1 pour attaquer le lapin, 2 pour le zombie \n");
				scanf("%d",&perso.CibleMage);
			
				if ( perso.CibleMage == 1 );{
				
				perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaqueMage;
				printf("Le lapin subit %d points de degats. \n", perso.AttaqueMage);
				}
				
				if ( perso.CibleMage == 2 ){
				perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaqueMage;
				printf("Le zombie subit %d points de degats. \n", perso.AttaqueMage);
				}	
				
			}
			
			//Defense Mage
			if ( perso.ChoixMage == 2 ){
				perso.DefenseMage = perso.DefenseMage + 2;
				printf("Le mage se defend. \n");
			}
			
			//Boule de feu Mage
			if ( perso.ChoixMage == 3 ){
				if ( perso.ManaMage >= 5 ){
					perso.AttaqueMage = perso.AttaqueMage + 15;
					perso.ManaMage = perso.ManaMage - 5;
					perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseZombie;
					monstre.VieZombie = monstre.VieZombie - perso.AttaqueMage;
					printf("Le zombie subit %d points de degats de la boule de feu \n", perso.AttaqueMage);
					perso.AttaqueMage = perso.AttaqueMage + monstre.DefenseZombie;
					perso.AttaqueMage = perso.AttaqueMage - monstre.DefenseLapin;
					monstre.VieLapin = monstre.VieLapin - perso.AttaqueMage;
					printf("Le lapin subit %d points de degats de la boule de feu \n", perso.AttaqueMage);
				}
				else{
					printf("Vous n'avez pas assez de mana \n");
				}
			}
			
		}
		
		//Action Pretre
		printf("Saisissez 1 pour attaquer avec le pretre \n");
		printf("Saisissez 2 pour vous defendre avec le pretre \n");
		printf("Saisissez 3 pour lancer un soin qui coute 5 de mana \n");
		
		scanf("%d",&perso.ChoixPretre);
		
		if ( monstre.ennemi == 1 ){
			
			//Attaque Pretre
			if ( perso.ChoixPretre == 1 ){
				perso.AttaquePretre = perso.AttaquePretre - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaquePretre;
				printf("Le lapin subit %d points de degats. \n", perso.AttaquePretre);
			}
			
			//Defense Pretre
			if ( perso.ChoixPretre == 2 ){
				perso.DefensePretre = perso.DefensePretre + 2;
				printf("Le pretre se defend. \n");
			}
			
			//Soin Pretre
			if ( perso.ChoixPretre == 3 ){
				if ( perso.ManaPretre >= 5 ){
					printf("Saisissez 1 pour soigner le guerrier \n");
					printf("Saisissez 2 pour soigner le voleur \n");
					printf("Saisissez 3 pour soigner le mage \n");
					printf("Saisissez 4 pour soigner le pretre \n");
				
					scanf("%d",&perso.CiblePretre);
				
					if ( perso.CiblePretre == 1 ){
						perso.VieGuerrier = perso.VieGuerrier + 15;
					}
					
					if ( perso.CiblePretre == 2 ){
						perso.VieVoleur = perso.VieVoleur + 15;
					}
					
					if ( perso.CiblePretre == 3 ){
						perso.VieMage = perso.VieMage + 15;
					}
					
					if ( perso.CiblePretre == 4 ){
						perso.ViePretre = perso.ViePretre + 15;
					}
				}
				else{
					printf("Vous n'avez pas assez de mana \n");
				}
			}
		}
		
		if ( monstre.ennemi == 2 ){
			
			//Attaque Pretre
			if ( perso.ChoixPretre == 1 ){
				perso.AttaquePretre = perso.AttaquePretre - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaquePretre;
				printf("Le zombie subit %d points de degats. \n", perso.AttaquePretre);
			}
			
			//Defense Pretre
			if ( perso.ChoixPretre == 2 ){
				perso.DefensePretre = perso.DefensePretre + 2;
				printf("Le pretre se defend. \n");
			}
			
			//Soin Pretre
			if ( perso.ChoixPretre == 3 ){
				if ( perso.ManaPretre >= 5 ){
					printf("Saisissez 1 pour soigner le guerrier \n");
					printf("Saisissez 2 pour soigner le voleur \n");
					printf("Saisissez 3 pour soigner le mage \n");
					printf("Saisissez 4 pour soigner le pretre \n");
				
					scanf("%d",&perso.CiblePretre);
				
					if ( perso.CiblePretre == 1 ){
						perso.VieGuerrier = perso.VieGuerrier + 15;
					}
					
					if ( perso.CiblePretre == 2 ){
						perso.VieVoleur = perso.VieVoleur + 15;
					}
					
					if ( perso.CiblePretre == 3 ){
						perso.VieMage = perso.VieMage + 15;
					}
					
					if ( perso.CiblePretre == 4 ){
						perso.ViePretre = perso.ViePretre + 15;
					}
				}
				else{
					printf("Vous n'avez pas assez de mana \n");
				}
			}
		}
		
		if ( monstre.ennemi == 3 ){
			
			//Attaque Pretre
			if ( perso.ChoixPretre == 1 ){
				printf("Saisissez 1 pour attaquer le lapin, 2 pour le zombie \n");
				scanf("%d",&perso.CiblePretre);
			
				if ( perso.CiblePretre == 1 );{
				
				perso.AttaquePretre = perso.AttaquePretre - monstre.DefenseLapin;
				monstre.VieLapin = monstre.VieLapin - perso.AttaquePretre;
				printf("Le lapin subit %d points de degats. \n", perso.AttaquePretre);
				}
				
				if ( perso.CiblePretre == 2 ){
				perso.AttaquePretre = perso.AttaquePretre - monstre.DefenseZombie;
				monstre.VieZombie = monstre.VieZombie - perso.AttaquePretre;
				printf("Le zombie subit %d points de degats. \n", perso.AttaquePretre);
				}	
				
			}
			
			//Defense Pretre
			if ( perso.ChoixPretre == 2 ){
				perso.DefensePretre = perso.DefensePretre + 2;
				printf("Le pretre se defend. \n");
			}
			
			//Soin Pretre
			if ( perso.ChoixPretre == 3 ){
				if ( perso.ManaPretre >= 5 ){
					printf("Saisissez 1 pour soigner le guerrier \n");
					printf("Saisissez 2 pour soigner le voleur \n");
					printf("Saisissez 3 pour soigner le mage \n");
					printf("Saisissez 4 pour soigner le pretre \n");
				
					scanf("%d",&perso.CiblePretre);
				
					if ( perso.CiblePretre == 1 ){
						perso.VieGuerrier = perso.VieGuerrier + 15;
					}
					
					if ( perso.CiblePretre == 2 ){
						perso.VieVoleur = perso.VieVoleur + 15;
					}
					
					if ( perso.CiblePretre == 3 ){
						perso.VieMage = perso.VieMage + 15;
					}
					
					if ( perso.CiblePretre == 4 ){
						perso.ViePretre = perso.ViePretre + 15;
					}
				}
				else{
					printf("Vous n'avez pas assez de mana \n");
				}
			}
		}
		
		//Attaque Lapin
		if ( monstre.ChoixLapin == 1 ){
				
				monstre.CibleLapin = rand()%4+1;
				
			if( monstre.CibleLapin == 1 ){
					monstre.AttaqueLapin = monstre.AttaqueLapin - perso.DefenseGuerrier;
					printf("Votre guerrier subit %d points de degats. \n", monstre.AttaqueLapin);
				}		
				
			if( monstre.CibleLapin == 2 ){
					monstre.AttaqueLapin = monstre.AttaqueLapin - perso.DefenseVoleur;
					printf("Votre voleur subit %d points de degats. \n", monstre.AttaqueLapin);
				}		
				
			if( monstre.CibleLapin == 3 ){
					monstre.AttaqueLapin = monstre.AttaqueLapin - perso.DefenseMage;
					printf("Votre mage subit %d points de degats. \n", monstre.AttaqueLapin);
				}		
				
			if( monstre.CibleLapin == 4 ){
					monstre.AttaqueLapin = monstre.AttaqueLapin - perso.DefensePretre;
					printf("Votre pretre subit %d points de degats. \n", monstre.AttaqueLapin);
				}		
		}
		
		//Attaque Zombie
		if ( monstre.ChoixZombie == 1 ){
				
				monstre.CibleZombie = rand()%4+1;
				
			if( monstre.CibleZombie == 1 ){
					monstre.AttaqueZombie = monstre.AttaqueZombie - perso.DefenseGuerrier;
					printf("Votre guerrier subit %d points de degats. \n", monstre.AttaqueZombie);
				}		
				
			if( monstre.CibleZombie == 2 ){
					monstre.AttaqueZombie = monstre.AttaqueZombie - perso.DefenseVoleur;
					printf("Votre voleur subit %d points de degats. \n", monstre.AttaqueZombie);
				}		
				
			if( monstre.CibleZombie == 3 ){
					monstre.AttaqueZombie = monstre.AttaqueZombie - perso.DefenseMage;
					printf("Votre mage subit %d points de degats. \n", monstre.AttaqueZombie);
				}		
				
			if( monstre.CibleZombie == 4 ){
					monstre.AttaqueZombie = monstre.AttaqueZombie - perso.DefensePretre;
					printf("Votre pretre subit %d points de degats. \n", monstre.AttaqueZombie);
				}		
		}
		
		//Vérification de si les personnages sont morts ou vivants.
		if (perso.VieGuerrier > 0)
		{
			printf("Votre guerrier a %d points de vie. \n", perso.VieGuerrier );
		}
		else{
			printf("Votre guerrier est mort. \n" );
		}

		if (perso.VieVoleur > 0)
		{
			printf("Votre voleur a %d points de vie. \n", perso.VieVoleur );
		}
		else{
			printf("Votre voleur est mort. \n" );
		}

		if (perso.VieMage > 0)
		{
			printf("Votre mage a %d points de vie. \n", perso.VieMage );
		}
		else{
			printf("Votre mage est mort. \n" );
		}

		if (perso.ViePretre > 0)
		{
			printf("Votre pretre a %d points de vie. \n", perso.ViePretre );
		}
		else{
			printf("Votre pretre est mort. \n" );
		}

		//Vérification de si l'équipe est morte ou non
		if (perso.VieGuerrier == 0 && perso.VieVoleur == 0 && perso.VieMage == 0 && perso.ViePretre == 0)
		{
			printf("Toute votre equipe est morte. \n");
			perso.ViePersonnages = 0;
		}
		
		//Vérification de l'état des monstres
		if( monstre.ennemi == 1 ){
			if( monstre.VieLapin <= 0 ){
				monstre.SpawnMonstre = 0;
			}
		}
		
		if( monstre.ennemi == 2 ){
			if( monstre.VieZombie <= 0 ){
				monstre.SpawnMonstre = 0;
			}
		}
		
		if( monstre.ennemi == 3 ){
			if( monstre.VieLapin <= 0 && monstre.VieZombie <= 0 ){
				monstre.SpawnMonstre = 0;
			}
		}
    }
    return 0;
}