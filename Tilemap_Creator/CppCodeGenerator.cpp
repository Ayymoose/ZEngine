// Copyright (C) 2022  Ayymooose

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "CppCodeGenerator.h"
#include <QTextStream>

void CppCodeGenerator::generate(QTextStream& out, const std::vector<Tilemap::TileArea>& tileAreas) const
{
    // Header information
    out << "// Autogenerated C++ using " APPLICATION_NAME " " BUILD_VERSION "\n";
    out << "// ALL CHANGES WILL BE UNDONE! DO NOT EDIT!" "\n";

    // Generate room information
    out << "TilemapInformation ti;" "\n";
    out << "ti.rooms = " "\n";
    out << "{" "\n";

    for (auto const& tileArea : tileAreas)
    {
        size_t index = 0;
        out << "\t{\n";
        out << "\t\t{\n";
        for (size_t ty = 0; ty < tileArea.tilesDown; ++ty)
        {
            out << "\t\t\t{";
            for (size_t tx = 0; tx < tileArea.tilesAcross-1; ++tx)
            {
                Q_ASSERT(index < tileArea.tileIndices.size());
                out << tileArea.tileIndices[index++];
                out << ',';
            }
            Q_ASSERT(index < tileArea.tileIndices.size());
            out << tileArea.tileIndices[index++];
            out << "},\n";
        }
        out << "\t\t}\n";
        out << "\t},\n";
    }

    out << "};" "\n";
    out << "ti.roomsAcross = " "\n";
    out << "ti.roomsDown = " "\n";
    out << "ti.tilemap = " "\n";
}

