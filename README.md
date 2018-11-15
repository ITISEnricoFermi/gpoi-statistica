<h1 align="center">
  <img src="https://raw.githubusercontent.com/Richard1984/archivio-fermi-client/81041b2932b032ead156777a6927efe1925b52ca/static/shortcut/safari-pinned-tab.svg?sanitize=true" height="100"><br/>
  <span>Statistica - GPOI</span>
</h1>
<h3 align="center">Oleksandr Soludchyk, Riccardo Sangiorgio, Giacomo Nanni</h3>

# Descrizione

# Tabella delle variabili

### Classe Application

#### Variabili

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

#### Metodi

```C++
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
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
