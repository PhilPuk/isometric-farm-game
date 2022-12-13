#include <SFML/Graphics.hpp>

class Cube
{
public:
    Cube(float size = 100.f)
        : m_size(size)
    {
        // Erstelle die Eckpunkte des W�rfels
        m_vertices.setPrimitiveType(sf::Triangles);
        m_vertices.resize(8);
        m_vertices[0] = sf::Vector2f(-m_size, -m_size);
        m_vertices[1] = sf::Vector2f(m_size, -m_size);
        m_vertices[2] = sf::Vector2f(m_size, m_size);
        m_vertices[3] = sf::Vector2f(-m_size, m_size);
        m_vertices[4] = sf::Vector2f(-m_size, -m_size);
        m_vertices[5] = sf::Vector2f(m_size, m_size);
        m_vertices[6] = sf::Vector2f(-m_size, m_size);
        m_vertices[7] = sf::Vector2f(m_size, -m_size);

    }

    void draw(sf::RenderTarget& target)
    {
        // Zeichne den W�rfel auf das Ziel
        target.draw(m_vertices);
    }

private:
    sf::VertexArray m_vertices; // Die Eckpunkte des W�rfels
    float m_size; // Die Gr��e des W�rfels
};