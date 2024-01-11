#include "../headers/PieceFactory.h"
#include "../headers/Pawn.h"
#include "../headers/Rook.h"
#include "../headers/King.h"
#include "../headers/Queen.h"
#include "../headers/Knight.h"
#include "../headers/Bishop.h"


/// Instantierea pentru Pawn
template <>
std::unique_ptr<Piece> PieceFactory<Pawn>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<Pawn>(texture, position, width, height, color);
}

/// Instantierea pentru Rook
template <>
std::unique_ptr<Piece> PieceFactory<Rook>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<Rook>(texture, position, width, height, color);
}

/// Instantierea pentru King
template <>
std::unique_ptr<Piece> PieceFactory<King>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<Rook>(texture, position, width, height, color);
}

/// Instantierea pentru Queen
template <>
std::unique_ptr<Piece> PieceFactory<Queen>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<Rook>(texture, position, width, height, color);
}

/// Instantierea pentru Bishop
template <>
std::unique_ptr<Piece> PieceFactory<Bishop>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<Rook>(texture, position, width, height, color);
}

/// Instantierea pentru Knight
template <>
std::unique_ptr<Piece> PieceFactory<Knight>::createPiece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) {
    return std::make_unique<Rook>(texture, position, width, height, color);
}