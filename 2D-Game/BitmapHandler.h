#pragma once
#include "Headers.h"

/**@brief
	* Klasa zajmuj�ca si� obs�ug� bitmap
	*/
class BitmapHandler
{
public:
	/**@brief
	* Metoda tworz�ca bitmap�
	* 
	* @param width
	*	D�ugo�� bitmapy
	* 
	* @param height
	*	Wysoko�� bitmapy
	* 
	* @param color
	*	Kolor bitmapy
	*/
	sf::Image create(unsigned int width, unsigned int height, const sf::Color color = sf::Color(0, 0, 0));

	/**@brief
	* Metoda usuwaj�ca bitmap�
	*
	* @param bitmap
	*	Bitmapa
	*/
	void remove(sf::Image* bitmap);

	/**@brief
	* Metoda �aduj�ca bitmap� z pliku
	*
	* @param bitmap
	*	Zmienna do kt�rej ma by� zapisana bitmapa
	* 
	* @param filename
	*	Nazwa pliku, w kt�rym znajduje sie bitmapa
	*/
	bool loadFromFile(sf::Image *bitmap, std::string filename);

	/**@brief
	* Metoda zapisujaca bitmap� do pliku
	*
	* @param bitmap
	*	Bitmapa do zapisania
	*
	* @param filename
	*	Nazwa pliku, do kt�rego ma by� zapisana bitmapa
	*/
	bool saveToFile(sf::Image bitmap, std::string filename);

	/**@brief
	* Metoda kopiuj�ca bitmap�
	*
	* @param src
	*	Bitmapa �r�dlowa
	*
	* @param dst
	*	Bitmapa docelowa
	*/
	void copy(sf::Image* src, sf::Image *dst);

	/**@brief
	* Metoda kopiuj�ca fragment bitmapy
	*
	* @param src
	*	Bitmapa �r�dlowa
	*
	* @param dst
	*	Bitmapa docelowa
	* 
	* @param rect
	*	Prostok�t, jaki ma by� skopiowany z bitmapy �r�d�owej do bitmapy docelowej
	*/
	void copy(sf::Image* src, sf::Image* dst, sf::IntRect rect);

	/**@brief
	* Metoda przerzucaj�ca bitmap� w poziomie
	*
	* @param bitmap
	*	Bitmapa
	*/
	void flipHorizontally(sf::Image* bitmap);

	/**@brief
	* Metoda przerzucaj�ca bitmap� w pionie
	*
	* @param bitmap
	*	Bitmapa
	*/
	void flipVertically(sf::Image* bitmap);
};