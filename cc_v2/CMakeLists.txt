# CMakeList.txt: projekt CMake dla elementu cc_v2, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (cc_v2 "cc_v2.cpp" "cc_v2.h" "board.h" "piece.h" "board.cpp" "piece.cpp" "move.h" "pawn.h" "pawn.cpp" "knight.h" "knight.cpp" "king.h" "king.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
