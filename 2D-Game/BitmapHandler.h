#pragma once
#include "Headers.h"

/**@brief
	* Klasa zajmuj¹ca siê obs³ug¹ bitmap
	*/
class BitmapHandler
{
public:
	/**@brief
	* Metoda tworz¹ca bitmapê
	* 
	* @param width
	*	D³ugoœæ bitmapy
	* 
	* @param height
	*	Wysokoœæ bitmapy
	* 
	* @param color
	*	Kolor bitmapy
	*/
	sf::Image create(unsigned int width, unsigned int height, const sf::Color color = sf::Color(0, 0, 0));

	/**@brief
	* Metoda usuwaj¹ca bitmapê
	*
	* @param bitmap
	*	Bitmapa
	*/
	void remove(sf::Image* bitmap);

	/**@brief
	* Metoda ³aduj¹ca bitmapê z pliku
	*
	* @param bitmap
	*	Zmienna do której ma byæ zapisana bitmapa
	* 
	* @param filename
	*	Nazwa pliku, w którym znajduje sie bitmapa
	*/
	bool loadFromFile(sf::Image *bitmap, std::string filename);

	/**@brief
	* Metoda zapisujaca bitmapê do pliku
	*
	* @param bitmap
	*	Bitmapa do zapisania
	*
	* @param filename
	*	Nazwa pliku, do którego ma byæ zapisana bitmapa
	*/
	bool saveToFile(sf::Image bitmap, std::string filename);

	/**@brief
	* Metoda kopiuj¹ca bitmapê
	*
	* @param src
	*	Bitmapa Ÿródlowa
	*
	* @param dst
	*	Bitmapa docelowa
	*/
	void copy(sf::Image* src, sf::Image *dst);

	/**@brief
	* Metoda kopiuj¹ca fragment bitmapy
	*
	* @param src
	*	Bitmapa Ÿródlowa
	*
	* @param dst
	*	Bitmapa docelowa
	* 
	* @param rect
	*	Prostok¹t, jaki ma byæ skopiowany z bitmapy Ÿród³owej do bitmapy docelowej
	*/
	void copy(sf::Image* src, sf::Image* dst, sf::IntRect rect);

	/**@brief
	* Metoda przerzucaj¹ca bitmapê w poziomie
	*
	* @param bitmap
	*	Bitmapa
	*/
	void flipHorizontally(sf::Image* bitmap);

	/**@brief
	* Metoda przerzucaj¹ca bitmapê w pionie
	*
	* @param bitmap
	*	Bitmapa
	*/
	void flipVertically(sf::Image* bitmap);
};