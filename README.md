# Système de Gestion Départementale - FST Tanger

Une application de bureau développée en C++ avec Qt Framework pour la gestion des étudiants, professeurs et soutenances du département Génie Informatique de la Faculté des Sciences et Techniques de Tanger.

## 🎯 Fonctionnalités

### Module Cycle d'Ingénieur
- **Gestion des étudiants** : Ajout, suppression et consultation des étudiants
- **Gestion des professeurs** : Administration du corps enseignant
- **Tableau de bord** : Statistiques et vue d'ensemble
- **Emplois du temps** : Visualisation des plannings S1, S3, S5
- **Gestion des salles** : Administration des espaces
- **Authentification** : Système de connexion sécurisé

### Module Master/Licence
- **Gestion multi-niveaux** : Support Licence et Master
- **Gestion des soutenances** : Planification et suivi
- **Filtrage avancé** : Par filière (AI, IT) et niveau
- **Statistiques détaillées** : Compteurs et derniers ajouts
- **Interface enrichie** : Alertes et confirmations

## 🛠️ Technologies

- **Langage** : C++17
- **Framework** : Qt 6.x (Core, GUI, Widgets, SQL)
- **Base de données** : PostgreSQL
- **Architecture** : MVC avec interfaces graphiques

## 📋 Prérequis

- Qt 6.x ou supérieur
- PostgreSQL
- Compilateur C++17
- Qt Creator (recommandé)

## 🚀 Installation

1. **Cloner le projet**
   ```bash
   git clone <repository-url>
   cd interface-graphique-en-C-via-Qt-framework
   ```

2. **Configuration de la base de données**
   - Créer une base PostgreSQL nommée `DepartementGI`
   - Configurer les paramètres dans `database.h`

3. **Compilation**
   ```bash
   # Pour le module Cycle
   cd Cycle
   qmake gestion_departement.pro
   make
   
   # Pour le module Master/Licence
   cd ../Master_Licence
   qmake gestion_departement.pro
   make
   ```

## 📁 Structure du Projet

```
├── Cycle/                    # Module Cycle d'Ingénieur
│   ├── assets/              # Ressources graphiques
│   ├── *.cpp, *.h, *.ui     # Code source et interfaces
│   └── gestion_departement.pro
├── Master_Licence/          # Module Master/Licence
│   ├── assets/              # Ressources graphiques
│   ├── *.cpp, *.h, *.ui     # Code source et interfaces
│   └── gestion_departement.pro
└── README.md
```

## 🎨 Interface

L'application dispose d'une interface moderne avec :
- Icônes personnalisées pour chaque fonctionnalité
- Thème cohérent aux couleurs de FST Tanger
- Navigation intuitive entre les modules
- Tableaux de données interactifs

## 🔧 Configuration Base de Données

Modifier les paramètres dans `database.h` :
```cpp
db.setHostName("localhost");
db.setDatabaseName("DepartementGI");
db.setUserName("your_username");
db.setPassword("your_password");
db.setPort(5432);
```

## 📊 Modules Principaux

| Module | Description | Fichiers Clés |
|--------|-------------|---------------|
| **Authentification** | Système de login | `loginpage.*` |
| **Dashboard** | Tableau de bord | `welcomewindow.*` |
| **Étudiants** | CRUD étudiants | `addstudentpage.*`, `deletestudentpage.*` |
| **Professeurs** | Gestion professeurs | `addprof.*` |
| **Soutenances** | Planification | `addsoutenance.*` |

## 🤝 Contribution

Pour contribuer au projet :
1. Fork le repository
2. Créer une branche feature
3. Commiter les changements
4. Pousser vers la branche
5. Ouvrir une Pull Request

## 📝 Licence

Projet académique - FST Tanger

---
*Développé pour le Département Génie Informatique - Faculté des Sciences et Techniques de Tanger*
