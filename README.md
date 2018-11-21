<h1 align="center">
  <img src="https://raw.githubusercontent.com/Richard1984/archivio-fermi-client/81041b2932b032ead156777a6927efe1925b52ca/static/shortcut/safari-pinned-tab.svg?sanitize=true" height="100"><br/>
  <span>Statistica - GPOI</span>
</h1>
<h3 align="center">Oleksandr Soludchyk, Riccardo Sangiorgio, Giacomo Nanni</h3>

# Descrizione

> Il programma consente di calcolare media aritmetica, media aritmetica ponderata, media armonica, media geometrica e varianza relative ai dati inseriti in un file.

1. Prima di eseguire il programma è necessario creare un file e popolarlo seguendo il seguente schema.

```
NUMBER : WEIGHT * FREQUENCY ,
```

###### Esempio
```
4:100*15,
2:100*20,
5:100*30
```

2. Il programma deve essere eseguito specificando come argomento la directory del file contenente i dati.

```shell
$ ./statistica $PROJECT_DIR/data.txt
```

3. È possibile scegliere quindi tra le varie opzioni presenti nel menù.

```
- MENU -
1) STAMPA DATI
2) CALCOLA MEDIA
3) CALCOLA VARIANZA
4) CALCOLA TUTTO
5) RIEPILOGO
6) ESCI
```

4. Nel caso in cui si selezioni la voce numero 2 *(CALCOLA MEDIA)*, sarà possibile scegliere tra le seguenti opzioni.
```
- CALCOLA MEDIA -
1) MEDIA ARITMETICA
2) MEDIA ARMONICA
3) MEDIA ARITMETICA PONDERATA
4) MEDIA GEOMETRICA
5) INDIETRO
```

# Struttura del programma

## Classe Application

### Variabili

```C++
std::vector<value> vec;
long double m_mediaAritmetica = 0;
long double m_mediaAritmeticaPonderata = 0;
long double m_mediaArmonica = 0;
long double m_mediaGeometrica = 0;
long double m_varianzaQ = 0;
long double m_varianza = 0;
long int n = 0;
```

|Tipo          |Nome                         |Valore iniziale   |Descrizione                  |
|--------------|-----------------------------|------------------|-----------------------------|
|vector<value> |vec                          |NULL              |Campione di dati             |
|long double   |m_mediaAritmetica            |0                 |Media artimetica             |
|long double   |m_mediaAritmeticaPonderata   |0                 |Media artimetica ponderata   |
|long double   |m_mediaArmonica              |0                 |Media armonica               |
|long double   |m_mediaGeometrica            |0                 |Media geometrica             |
|long double   |m_varianzaQ                  |0                 |Varianza quadratica          |
|long double   |m_varianza                   |0                 |Varianza                     |
|long int      |n                            |0                 |Totale delle frequenze       |

### Metodi

```C++
int menu();
int sub_menu();
void mediaAritmetica();
void mediaArmonica();
void mediaAritmeticaPonderata();
void mediaGeometrica();
void varianza();
void print();
void riepilogo();
void loadFromFile(std::string& path);
void parse(std::string& line);
void addToVec(std::string& number, std::string& weight, std::string& frequency);
std::string getNumberfromString(std::string& line);
std::string trimByDelim(const char& delim, std::string& line);
```
  
|Tipo          |Nome                         |Attributi         |Descrizione                            |
|--------------|-----------------------------|------------------|---------------------------------------|
|int           |menu                         |//                |Stampa il menù                         |
|int           |sub_menu                     |//                |Stampa il sotto-menù                   |
|void          |mediaAritmetica              |//                |Calcola la media aritmetica            |
|void          |mediaArmonica                |//                |Calcola la media armonica              |
|void          |mediaAritmeticaPonderata     |//                |Calcola la media aritmetica ponderata  |
|void          |mediaGeometrica              |//                |Calcola la media geometrica            |
|void          |varianza                     |//                |Calcola la varianza                    |
|void          |print                        |//                |Stampa il contenuto del vettore *vec*  |
|void          |riepilogo   		     |//                |Stampa il riepilogo di tutti i calcoli |
|void          |loadFromFile  		     |string& path 	|Legge i dati dal file   		|
|void  	       |parse   	             |string& line 	|Esegue il parsing dei dati   		|
|void          |addToVec   		     |string& number, string& weight, string& frequency   | Aggiunge i dati al vettore   |
|string   |getNumberfromString   	     |string& line   	|Converte i dati letti da stringa a numero   |
|string   |trimByDelim   		     |char& delim, string& line   |Esegue lo split della stringa di dati letta   |

#### Media Artimetica

```C++
void Application::mediaAritmetica() {
  system("cls");
  if (m_mediaAritmetica) return;
  long double s = 0;
  size_t k = vec.size();
  for (int i = 0; i < k; i++) {
    long double xi = vec.at(i).number;
    int ni = vec.at(i).frequency;
    s += (xi * ni) / n;
  }

  m_mediaAritmetica = s;

  printf("Media Aritmetica: %.3f\n", m_mediaAritmetica);
}
```

#### Media Aritmetica Ponderata

```C++
void Application::mediaAritmeticaPonderata() {
  system("cls");
  if (m_mediaAritmeticaPonderata) return;

  long double s = 0;
  size_t k = vec.size();
  long long int pesoTot = 0;
  long double numTot = 0;
  
  for (int i = 0; i < k; i++) {
    int wi = vec.at(i).weight;
    int ni = vec.at(i).frequency;
    pesoTot += wi * ni;
  }

  for (int i = 0; i < k; i++) {
    long double xi = vec.at(i).number;
    int ni = vec.at(i).frequency;
    int wi = vec.at(i).weight;
    numTot += wi * ni * xi;
  }

  m_mediaAritmeticaPonderata = numTot / pesoTot;

  printf("Media Aritmetica Ponderata: %.3f\n", m_mediaAritmeticaPonderata);
}
```

#### Media Armonica

```C++
void Application::mediaArmonica() {
  system("cls");
  if (m_mediaArmonica) return;

  long double s = 0;
  size_t k = vec.size();
  
  for (int i = 0; i < k; i++) {
    long double xi = vec.at(i).number;
    int ni = vec.at(i).frequency;
    s += ni / xi;
  }

  m_mediaArmonica = n / s;

  printf("Media Armonica: %.3f\n", m_mediaArmonica);
}
```

#### Media Geometrica

```C++
void Application::mediaGeometrica() {
  system("cls");
  if (m_mediaGeometrica) return;
  if (vec.size() == 0) return;

  size_t k = vec.size();
  long double m = powl(vec.at(0).number, vec.at(0).frequency);
  
  for (int i = 0; i < k - 1; i++) {
    long double xi = vec.at(i + 1).number;
    int ni = vec.at(i + 1).frequency;

    m *= powl(xi, ni);
  }

  m_mediaGeometrica = powl(m, 1 / (long double) n);

  printf("Media Geometrica: %.3f\n", m_mediaGeometrica);
}
```

#### Varianza

```C++
void Application::varianza() {
  system("cls");
  if (m_varianza) return;
  if (!m_mediaAritmetica) mediaAritmetica();

  long double s2 = 0;
  size_t k = vec.size();
  
  for (size_t i = 0; i < k; i++) {
    long double xi = vec.at(i).number;
    int ni = vec.at(i).frequency;
    s2 = ni * pow(xi - m_mediaAritmetica, 2);
  }
  
  m_varianzaQ = s2 / k;
  m_varianza = sqrtl(m_varianzaQ);

  printf("Varianza^(2): %.3f\nVarianza: %.3f\n", m_varianzaQ, m_varianza);
}
```

## Authors

* **Oleksandr Soludchyk** - [Tox1k](https://github.com/Tox1k)
* **Riccardo Sangiorgio** - [Richard1984](https://github.com/Richard1984/)
* **Giacomo Nanni**

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
