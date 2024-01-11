#pragma once

#include "piece.h"

/**
 * @brief Fabrică de piese bazată pe șabloane.
 * Prin utilizarea șabloanelor, poți crea o fabrică de piese care poate produce instanțe ale oricărui tip de piesă,
 * astfel încât să poți crea un obiect de tip Pawn, Rook, Knight, etc., utilizând aceeași interfață PieceFactory.
 * Funcția template primește un obiect de tip Piece și afișează informații despre poziția și culoarea piesei.
 */


template <typename T>
class PieceFactory {
public:
    /**
     * @brief Creează o instanță a piesei specificate.
     * @param texture Textura piesei.
     * @param position Poziția inițială a piesei pe tablă.
     * @param width Lățimea piesei.
     * @param height Înălțimea piesei.
     * @param color Culoarea piesei.
     * @return Un obiect unic reprezentând piesa creată.
     */
    static std::unique_ptr<Piece> createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);
};

template <typename T>
std::unique_ptr<Piece> PieceFactory<T>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<T>(texture, position, width, height, color);
}

/**
 * @brief Afișează informații despre piesă.
 * Funcția template primește o referință la obiectul piesei și afișează informații despre poziția și culoarea piesei.
 * @param piece Referință la obiectul piesei.
 */

template <typename T>
void printPieceInfo(const T& piece) {
    std::cout << "Piece information: " << piece << std::endl;
}