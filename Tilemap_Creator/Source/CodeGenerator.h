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

#pragma once

#include "Tilemap.h"
#include "RoomLink.h"
#include "Version.h"

class CodeGenerator
{
public:
    virtual void generateRooms(QTextStream& out, const std::vector<Tilemap::TileArea>& tilemapArea) const = 0;
    virtual void generateRoomLinks(QTextStream& out, const RoomLink::RoomLinkMap& roomLinkMap) const = 0;
    virtual ~CodeGenerator() = default;
};
