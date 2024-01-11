//
// Created by Iulia on 12/7/2023.
//
#include "../headers/game.h"
#include "../headers/pawn.h"
#include "../headers/knight.h"
#include "../headers/bishop.h"
#include "../headers/queen.h"
#include "../headers/rook.h"
#include "../headers/king.h"
#include "../headers/exceptions.h"
#include "../headers/PieceFactory.h"


bool isPieceDragging = false;
bool gameOver = false;

Game::Game() : window(sf::VideoMode(596, 596), "Chess Game") {
    board = new Board(600, 600 / 8);
    Textures::loadAllTextures();
    addPiecesToVector();
}

/**
Game::Game(const Game &other)
{
    board = new Board(*other.board);
    pieces.clear();
    for (const auto& piece : other.pieces)
        pieces.push_back(std::unique_ptr<Piece>(piece->clone()));
}
*/

Game& Game::operator=(const Game& other)
{
    if (this != &other)
    {
        board = new Board(*other.board);
        pieces.clear();
        for (const auto& piece : other.pieces) {
            pieces.push_back(std::unique_ptr<Piece>(piece->clone()));
        }
    }
    return *this;

}

Game::~Game()
{
    /**
    delete board;
    for (const Piece *piece: pieces) {
        delete piece;
    }*/
    std::cout << "Chess ended!";
}

void Game::addPiecesToVector()
{
    unsigned int squareSize = board->getSquareSize();
    auto scale = static_cast<float>(squareSize);
    float halfPieceWidth = pieceWidth / 2.0f;
    float halfPieceHeight = pieceHeight / 2.0f;


     /** FOLOSIRE PieceFactory
    pieces.push_back(PieceFactory<Pawn>::createPiece(Textures::whitePawn, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Rook>::createPiece(Textures::whiteRook, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Knight>::createPiece(Textures::whiteKnight, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Bishop>::createPiece(Textures::whiteBishop, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Queen>::createPiece(Textures::whiteQueen, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<King>::createPiece(Textures::whiteKing, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Bishop>::createPiece(Textures::whiteBishop, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Knight>::createPiece(Textures::whiteKnight, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(PieceFactory<Rook>::createPiece(Textures::whiteRook, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
*/


    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));

    pieces.push_back(std::make_unique<Rook>(Textures::whiteRook, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Knight>(Textures::whiteKnight, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Bishop>(Textures::whiteBishop, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Queen>(Textures::whiteQueen, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<King>(Textures::whiteKing, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Bishop>(Textures::whiteBishop, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Knight>(Textures::whiteKnight, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Rook>(Textures::whiteRook, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));


    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));

    pieces.push_back(std::make_unique<Rook>(Textures::blackRook, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Knight>(Textures::blackKnight, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Bishop>(Textures::blackBishop, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Queen>(Textures::blackQueen, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<King>(Textures::blackKing, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Bishop>(Textures::blackBishop, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Knight>(Textures::blackKnight, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Rook>(Textures::blackRook, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));

    /**
     * FOLOSIRE PieceFactory
     */
    printPieceInfo(*pieces[0]);
    printPieceInfo(*pieces[1]);
    printPieceInfo(*pieces[2]);
    printPieceInfo(*pieces[3]);
    printPieceInfo(*pieces[4]);
    printPieceInfo(*pieces[5]);
    printPieceInfo(*pieces[6]);
    printPieceInfo(*pieces[7]);

}

bool Game::isMouseOverPiece(const Piece& piece, const sf::Vector2f& mousePosition) const
{

    /// Verificăm dacă poziția mouse-ului se află deasupra sprite-ului piesei
    return piece.getPosition().x <= mousePosition.x && mousePosition.x <= piece.getPosition().x + pieceWidth &&
           piece.getPosition().y <= mousePosition.y && mousePosition.y <= piece.getPosition().y + pieceHeight;

}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                handleMousePress(event.mouseButton.x, event.mouseButton.y);
                break;
            case sf::Event::MouseButtonReleased:
                handleMouseRelease();
                break;
            case sf::Event::MouseMoved:
                handleMouseMove(event.mouseMove.x, event.mouseMove.y);
                break;
            default:
                break;
        }
    }

}

void Game::handleMousePress(int mouseX, int mouseY)
{
    sf::Vector2f clickPosition(static_cast<float>(mouseX), static_cast<float>(mouseY));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (const auto& piecePtr : pieces)
        {
            if (isMouseOverPiece(*piecePtr, clickPosition))
            {
                // Piece was clicked, start dragging
                std::cout<<"press"<<"\n";
                piecePtr->setIsSelected(true);
                selectedPiece = piecePtr.get();
                isPieceDragging = true;

                // Set the initial piece position
                initialPiecePos = piecePtr->getPosition();
                break;
            }
        }

    }

}

void Game::handleMouseMove(int mouseX, int mouseY)
{
    sf::Vector2f mousePosition(static_cast<float>(mouseX), static_cast<float>(mouseY));

    /// Verificați dacă o piesă este în mișcare
    if (isPieceDragging && selectedPiece != nullptr) {
        /// Actualizați poziția piesei în funcție de poziția curentă a mouse-ului
        selectedPiece->move(mousePosition);
    }

}
void Game::handleCapture(const sf::Vector2f& dropPosition)
{
    auto capturedPiece = std::find_if(pieces.begin(), pieces.end(), [&](const auto& piecePtr) {
        return piecePtr->getPosition() == dropPosition && piecePtr->getColor() != selectedPiece->getColor();
    });

    if (capturedPiece != pieces.end())
    {
        std::cout << "Piece captured!" << std::endl;

        /// Remove the captured piece from the vector
        pieces.erase(capturedPiece);
        std::cout << "Piece deleted!" << std::endl;

    }
}

void Game::handleMouseRelease()
{
    sf::Text checkMessage;
    /// Verificați dacă butonul stâng al mouse-ului a fost eliberat
    if (isPieceDragging && selectedPiece != nullptr)
    {
        std::cout<<"drop" << "\n";
        /// O piesă a fost eliberată, opriți trăgând și mutați piesa la poziția curentă a mouse-ului
        selectedPiece->setIsSelected(false);
        isPieceDragging = false;

        /// Verificați dacă piesa este mutată pe o casetă validă
        sf::Vector2f dropPosition = calculateSquareCenter(selectedPiece->getPosition());

        if (selectedPiece->isValidMove(initialPiecePos,dropPosition, *board))
        {
            /// Caseta de destinație este validă, actualizați poziția piesei
            selectedPiece->move(dropPosition);
            /// Verifica captura
            handleCapture(dropPosition);
        } else
        {
            /// Caseta de destinație nu este validă, readuceți piesa la poziția inițială
            selectedPiece->move(initialPiecePos);
        }

        /// Resetați poziția inițială pentru a evita mutarea piesei la fiecare eliberare a mouse-ului
        initialPiecePos = selectedPiece->getPosition();

        ///Deselecteaza piesa
        isPieceDragging = false;
        selectedPiece->setIsSelected(false);
        selectedPiece = nullptr;
    }

    for (const auto& piecePtr : pieces)
    {
        if (auto kingPtr = dynamic_cast<King*>(piecePtr.get()))
        {
            /// Verifică pentru fiecare rege dacă este în șah
            if (isKingInCheck(*kingPtr))
            {
                if (kingPtr->getColor() == sf::Color::White)
                        std::cout << "Chess black player!" << std::endl;
                    else if (kingPtr->getColor() == sf::Color::Black)
                                std::cout << "Chess white player!" << std::endl;

            }
            if (isCheckmate(*kingPtr))
            {
                ///Mesaj in consola
                std::cout << "Checkmate\n " << (kingPtr->getColor() == sf::Color::White ? "Black" : "White") << " player wins!" << std::endl;
            }
        }
    }
}

sf::Vector2f Game::calculateSquareCenter(const sf::Vector2f& mousePosition) const
{
    unsigned int squareSize = board->getSquareSize();
    float halfPieceWidth = pieceWidth / 2.0f;
    float halfPieceHeight = pieceHeight / 2.0f;

    /// Calculați coloana și rândul în funcție de poziția mouse-ului și dimensiunile piesei
    int column = static_cast<int>(mousePosition.x / squareSize);
    int row = static_cast<int>(mousePosition.y / squareSize);

    /// Asigurați-vă rândul si coloana sunt în limitele tablei
    column = std::max(0, std::min(7, column));
    row = std::max(0, std::min(7, row));

    /// Calculați centrul casetei, având în vedere dimensiunile piesei
    sf::Vector2f center(static_cast<float>(column * squareSize + squareSize / 2) - halfPieceWidth,
                        static_cast<float>(row * squareSize + squareSize / 2) - halfPieceHeight);

    return center;

}

bool Game::isKingInCheck(const King& king) const {
    for (const auto& piecePtr : pieces) {
        if (piecePtr->getColor() != king.getColor() &&
            piecePtr->isValidMove(piecePtr->getPosition(), king.getPosition(), *board)) {
            return true;
        }
    }
    return false;
}

bool Game::isSquareOccupied(const sf::Vector2f& position) const {
    /// Verificați dacă locația este ocupată de oricare dintre piese
    for (const auto& piecePtr : pieces) {
        if (piecePtr->getPosition() == position) {
            return true; /// Locația este ocupată
        }
    }
    return false; /// Locația este liberă
}

bool Game::isSquareAttacked(const sf::Vector2f& position, sf::Color attackingColor) const {
    /// Verificați dacă locația este atacată de oricare dintre piesele de culoare opusă
    for (const auto& piecePtr : pieces) {
        if (piecePtr->getColor() != attackingColor &&
            piecePtr->isValidMove(piecePtr->getPosition(), position, *board)) {
            return true; /// Locația este atacată
        }
    }
    return false; /// Locația nu este atacată
}

bool Game::isCheckmate(const King& king) const {
    if (!isKingInCheck(king)) {
        return false; /// Regele nu este în șah mat dacă nu este în șah
    }

    const sf::Vector2f kingPos = king.getPosition();
    /// Coordonatele posibile pentru o mutare a regelui
    const std::vector<sf::Vector2f> possibleMoves =
            {
                    {kingPos.x + 1, kingPos.y},
                    {kingPos.x - 1, kingPos.y},
                    {kingPos.x, kingPos.y + 1},
                    {kingPos.x, kingPos.y - 1},
                    {kingPos.x + 1, kingPos.y + 1},
                    {kingPos.x - 1, kingPos.y - 1},
                    {kingPos.x + 1, kingPos.y - 1},
                    {kingPos.x - 1, kingPos.y + 1}
            };

    /// Verificați fiecare mutare posibilă
    for (const auto& move : possibleMoves) {
        /// Verificați dacă locația este liberă sau atacată
        if (!isSquareOccupied(move) && !isSquareAttacked(kingPos, king.getColor()))
        {
            return false; /// Regele poate face cel puțin o mutare legală pentru a ieși din șah
        }
    }

    return true; /// Regele nu poate face nicio mutare legală, deci este șah mat
}


void Game::run() {
    while (window.isOpen() && !gameOver) {
        handleEvents();
        window.clear();
        board->draw(window);
        for (const auto &piecePtr: pieces) {
            piecePtr->draw(window);
        }
        window.display();

        /// Verificați dacă jocul este în șah mat după fiecare iterație
        for (const auto &piecePtr: pieces)
        {
            if (auto kingPtr = dynamic_cast<King *>(piecePtr.get()))
            {
                if (isCheckmate(*kingPtr))
                {
                    /// Jocul este în șah mat
                    gameOver = true;
                    /// Așteptați o scurtă pauză înainte de a închide fereastra
                    sf::sleep(sf::seconds(3.0f));
                }
            }
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Chess Game Information" << std::endl;
    os << *game.board;
    for (const auto& piecePtr : game.pieces) {
        os << *piecePtr;
    }

    return os;
}