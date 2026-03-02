# Proiect-POO

### Simularea unei rețele de transport public urban

Proiectul modelează și simulează funcționarea unei rețele de transport public urban, utilizând concepte fundamentale de Programare Orientată pe Obiecte.
Clasa de bază, MijlocTransport, descrie caracteristicile generale ale unui vehicul de transport: linia pe care circulă, identificatorul unic, capacitatea, viteza medie și numărul de stații parcurse (inițializat cu zero la începutul cursei). Această clasă este abstractă și definește comportamente comune, precum calcularea timpului estimat de sosire.
Din aceasta derivă trei clase concrete: Autobuz, Tramvai, Metrou. Fiecare tip de vehicul adaugă atribute specifice (număr de uși, tipul șinelor, interval între trenuri etc.) și implementează propriul mod de calcul al timpului de parcurgere, reflectând diferențele reale dintre mijloacele de transport.
Aplicația gestionează o colecție de vehicule care formează rețeaua de transport. Utilizatorul poate încărca date din fișier, adăuga sau elimina vehicule și realiza interogări după diferite criterii (tip, capacitate, viteză, timp estimat). Rezultatele sunt obținute prin utilizarea polimorfismului și a funcțiilor virtuale apelate prin pointeri la clasa de bază.
Proiectul evidențiază utilizarea moștenirii, polimorfismului, funcțiilor virtuale pure, excepțiilor personalizate și a pointerilor inteligenți pentru gestionarea corectă a obiectelor din cadrul rețelei.
