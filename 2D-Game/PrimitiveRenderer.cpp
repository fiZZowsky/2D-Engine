#include "PrimitiveRenderer.h"


PrimitiveRenderer::PrimitiveRenderer() {}

PrimitiveRenderer::~PrimitiveRenderer() {}

void PrimitiveRenderer::swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

sf::RectangleShape PrimitiveRenderer::drawRectangle(int x, int y, int width, int height,
	sf::Color outlineColor, sf::Color fillColor){


	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setPosition(x, y);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setFillColor(fillColor);
	return rectangle;
}

sf::CircleShape PrimitiveRenderer::drawCircle(int x, int y, int radius,
	sf::Color outlineColor, sf::Color fillColor){

	sf::CircleShape circle(radius);
	circle.setPosition(x, y);
	circle.setOutlineColor(outlineColor);
	circle.setFillColor(fillColor);
	return circle;
}

sf::CircleShape PrimitiveRenderer::drawTriangle(int x, int y, int edgeSize, 
	sf::Color outlineColor, sf::Color fillColor) {

	sf::CircleShape triangle(edgeSize, 3);
	triangle.setPosition(x,y);

	triangle.setFillColor(fillColor);
	triangle.setOutlineColor(outlineColor);
	return triangle;
}

sf::CircleShape PrimitiveRenderer::drawPolygon(int x, int y, int edgeSize, int sidesNumber,
	sf::Color outlineColor, sf::Color fillColor) {

	sf::CircleShape polygon(edgeSize, sidesNumber);
	polygon.setPosition(x, y);
	polygon.setFillColor(fillColor);
	polygon.setOutlineColor(outlineColor);
	return polygon;
}

sf::RectangleShape PrimitiveRenderer::drawPixel(int x, int y, sf::Color color) {
	return drawRectangle(x, y, 1, 1, color, color);
}


sf::RectangleShape PrimitiveRenderer::drawPixel(Point2D *point, sf::Color color) {
	return drawRectangle(point->getX(), point->getY(), 1, 1, color, color);
}


sf::VertexArray PrimitiveRenderer::drawLine(int x1, int y1, int x2, int y2, sf::Color color) {
	sf::VertexArray line(sf::Lines, 2);

	line[0] = sf::Vertex(sf::Vector2f(x1, y1), color);
	line[1] = sf::Vertex(sf::Vector2f(x2, y2), color);

	return line;
}

sf::VertexArray PrimitiveRenderer::drawPolyline(std::vector<Point2D> points, sf::Color color) {

	sf::VertexArray polyline(sf::LineStrip, points.size());

	for (int i = 0; i < points.size(); i++) {
		polyline[i] = sf::Vertex(sf::Vector2f(points[i].getX(), points[i].getY()), color);
	}

	return polyline;
}

sf::VertexArray PrimitiveRenderer::drawPolyline(std::vector<LineSegment> lineSegments, sf::Color color) {
	sf::VertexArray polyline(sf::LineStrip, lineSegments.size() + 1);

	for (int i = 0; i < lineSegments.size(); i++) {
		polyline[i] = sf::Vertex(sf::Vector2f(lineSegments[i].getStartPoint()->getX(), lineSegments[i].getStartPoint()->getY()), color);
	}
	polyline[lineSegments.size()] = sf::Vertex(sf::Vector2f(lineSegments[lineSegments.size() - 1].getEndPoint()->getX(),
		lineSegments[lineSegments.size() - 1].getEndPoint()->getY()), color);

	return polyline;
}



sf::VertexArray PrimitiveRenderer::drawClosedPolyline(std::vector<Point2D> points, sf::Color color) {

	sf::VertexArray polyline(sf::LineStrip, points.size() + 1);

	for (int i = 0; i < points.size(); i++) {
		polyline[i] = sf::Vertex(sf::Vector2f(points[i].getX(), points[i].getY()), color);
	}
	//closing the line
	polyline[points.size()] = sf::Vertex(sf::Vector2f(points[0].getX(), points[0].getY()), color);

	return polyline;

}

sf::VertexArray PrimitiveRenderer::drawClosedPolyline(std::vector<LineSegment> lineSegments, sf::Color color){

	sf::VertexArray polyline(sf::LineStrip, lineSegments.size() + 2);

	for (int i = 0; i < lineSegments.size(); i++) {
		polyline[i] = sf::Vertex(sf::Vector2f(lineSegments[i].getStartPoint()->getX(), lineSegments[i].getStartPoint()->getY()), color);
	}
	polyline[lineSegments.size()] = sf::Vertex(sf::Vector2f(lineSegments[lineSegments.size() - 1].getEndPoint()->getX(),
		lineSegments[lineSegments.size() - 1].getEndPoint()->getY()), color);

	//end point
	polyline[lineSegments.size() + 1] = sf::Vertex(sf::Vector2f(lineSegments[0].getStartPoint()->getX(),
		lineSegments[0].getStartPoint()->getY()), color);

	return polyline;

}


void PrimitiveRenderer::myDrawLine(sf::RenderWindow* window, int x0, int y0, int x1, int y1, sf::Color color) {
	if (x0 > x1) {
		swap(&x0, &x1);
	}

	float deltaY = abs(y1 - y0);
	float deltaX = abs(x1 - x0);

	float m = deltaY / deltaX;
	float x, y;
	float yi, xi;

	if (m <= 1) {

		for (int i = 0; i < deltaX; i++) {
			yi = m * i + y0;
			x = x0 + i;
			window->draw(drawPixel(x, round(yi), color));
		}
	}
	else {

		swap(&x0, &y0);
		swap(&x1, &y1);


		deltaY = abs(y1 - y0);
		deltaX = abs(x1 - x0);

		m = deltaY / deltaX;

		for (int i = 0; i < deltaX; i++) {
			xi = m * i + x0;
			y = y0 + i;
			window->draw(drawPixel(round(xi), y, color));
		}

	}
}


void PrimitiveRenderer::myDrawCircle(sf::RenderWindow* window, int x, int y, int radius, sf::Color color) {
	
	double angleInRadians;
	Point2D p1, p2;
	int tmpX, tmpY;
	for (int i = 0; i < 180; i++) {
		angleInRadians = (i * M_PI) / 180;

		tmpX = radius * cos(angleInRadians);
		tmpY = radius * sin(angleInRadians);

		p1.setPoint(x + tmpX, y + tmpY);
		p2.setPoint(x + tmpX, y - tmpY);

		window->draw(drawPixel(p1.getX(), p1.getY()));
		window->draw(drawPixel(p2.getX(), p2.getY()));
	}
}

void PrimitiveRenderer::myDrawElipse(sf::RenderWindow* window, int x, int y, int radiusX, int radiusY, sf::Color color) {
	double angleInRadians;
	Point2D p1, p2;
	int tmpX, tmpY;
	for (int i = 0; i < 180; i++) {
		angleInRadians = (i * M_PI) / 180;

		tmpX = radiusX * cos(angleInRadians);
		tmpY = radiusY * sin(angleInRadians);

		p1.setPoint(x + tmpX, y + tmpY);
		p2.setPoint(x + tmpX, y - tmpY);

		window->draw(drawPixel(p1.getX(), p1.getY()));
		window->draw(drawPixel(p2.getX(), p2.getY()));
	}
}

void PrimitiveRenderer::myDrawPolygon(sf::RenderWindow* window, std::vector<Point2D> points, sf::Color color) {

	std::vector<LineSegment> lineSegments;

	//we need at least 3 points to draw polygon
	if (points.size() < 3) {
		return;
	}

	// converting points to line segments
	for (int i = 1; i < points.size(); i++) {
		lineSegments.push_back(LineSegment(&points[i - 1], &points[i]));
	}
	lineSegments.push_back(LineSegment(&points[points.size() - 1], &points[0]));

	myDrawPolygon(window, lineSegments, color);
}

void PrimitiveRenderer::myDrawPolygon(sf::RenderWindow* window, std::vector<LineSegment> lineSegments, sf::Color color) {

	//we need at least 3 linesegments to draw polygon
	if (lineSegments.size() < 3) {
		return;
	}

	// checking if line segments are crossing
	for (int i = 1; i < lineSegments.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (LineSegment::isLineSegmentsCrossing(lineSegments[j], lineSegments[i])) {
				return;
			}
		}
	}

	window->draw(drawPolyline(lineSegments, color));
}

void PrimitiveRenderer::boundryFill(sf::RenderWindow* window, Point2D p, sf::Color fillColor, sf::Color boundryColor) {
	//making window screenshot to be able to get pixel color
	sf::Texture texture;
	sf::Image screenshot;

	texture.create(window->getSize().x, window->getSize().y);
	texture.update(*window);
	screenshot = texture.copyToImage();

	//getting pixel color
	sf::Color pixelColor = screenshot.getPixel(p.getX(), p.getY());

	//if (pixelColor == fillColor) std::cout << "White" << std::endl;
	//else std::cout << "Inny" << std::endl;

	//iteracyjnie
	std::vector<Point2D> pointsToFill;
	pointsToFill.push_back(p);

	while (!pointsToFill.empty()) {
		//pobranie punktu z kolejki i usuniêcie go z niej
		p = pointsToFill[pointsToFill.size() - 1];
		pointsToFill.pop_back();
		
		//ustalenie koloru pixela
		pixelColor = screenshot.getPixel(p.getX(), p.getY());

		//if (pixelColor == sf::Color::Black) std::cout << "Black" << std::endl;

		if (pixelColor== fillColor) continue;
		if (pixelColor == boundryColor) continue;

		//rysowanie pixela na ekranie
		window->draw(drawPixel(&p, fillColor));

		//rysowanie pixela na kopii ekranu
		screenshot.setPixel(p.getX(), p.getY(), fillColor);

		pointsToFill.push_back(Point2D(p.getX(), p.getY() - 1));	//N
		pointsToFill.push_back(Point2D(p.getX(), p.getY() + 1));	//S
		pointsToFill.push_back(Point2D(p.getX() + 1, p.getY()));	//W
		pointsToFill.push_back(Point2D(p.getX() - 1, p.getY()));	//E
	}
}


sf::RectangleShape PrimitiveRenderer::drawSFMLLine(int x, int y, int length, int rotation, sf::Color fillColor) {
	sf::RectangleShape SFMLline(sf::Vector2f(length, 1));
	SFMLline.setPosition(sf::Vector2f(x, y));
	SFMLline.setFillColor(fillColor);
	SFMLline.rotate(rotation);
	return SFMLline;
}