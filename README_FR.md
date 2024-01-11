# cpp polymorph class

J'ai créé le petit projet MultiArray dans un but "éducatif".

Il propose deux versions de la même classe MultiArray.

La version polymorphe est flexible mais limitée. La version variante est limitée mais flexible.

## Explication du projet :

Le postulat de départ est qu'en C++, un tableau multidimensionnel est généralement une structure homogène, c'est-à-dire que tous les éléments du tableau doivent être du même type de données (int, float, char, std::string, std::vector, ...). Cependant, pour un projet, j'avais besoin de stocker dans un tableau un certain nombre de données avec de multiples types afin de pouvoir travailler dessus facilement.

La classe MultiArray est là pour répondre à ce problème. Elle simule le comportement d'un tableau. On peut simuler un tableau multidimensionnel avec des types de données différents en utilisant des structures ou des classes.

## La version Polymorphe :

Dans cette version, la classe MultiArrayPolymorphe utilise une classe interne "Any" qui peut stocker n'importe quel type de données en utilisant des pointeurs polymorphes. Cette classe est compatible avec les versions C++14 à C++17. Elle n'est pas compatible avec la version C++11 car j'utilise "std::unique_ptr," qui n'existait pas et n'est apparu qu'en C++14.

Grâce à la "struct Any" de la classe, elle peut stocker n'importe quel type de données. L'avantage, contrairement à la version "variant," est que je peux ajouter tous les types de données, ou presque. Presque, parce que malheureusement je ne peux pas stocker des <vector> dedans.

Par contre, elle a un avantage majeur par rapport à la version "variant," c'est que je peux ajouter des types de données sans avoir à modifier la source. Je peux donc la compiler dans une bibliothèque sans avoir à la recompiler à chaque ajout de nouveau type de données.

## La version Variant :

Tout comme la version précédente, la classe MultiArrayVariant est capable de gérer quasiement tous les types de données. Pour cela, il suffit d'ajouter les types que doit accepter de traiter le conteneur qu'est la classe dans la ligne :
	using ValueVariant = std::variant<int, float, bool, std::string, std::vector<int>>;
	std::vector<ValueVariant> data;

Par contre, si vous souhaitez ajouter ou supprimer un type pouvant être traité par la classe MultiArrayVariant, vous devez modifier cette ligne et donc compiler de nouveau votre source.



Les deux classes ont des avantages et des inconvénients. Chacun fera son choix selon ses besoins.


## Exécuter des tests unitaires

Pour compiler et exécuter les tests, vous devez exécuter

```sh
$ mkdir build
$ cd build
$ cmake .. 
$ make
$ ./MultiArrayVariant
$ ./MultiArrayPoly
