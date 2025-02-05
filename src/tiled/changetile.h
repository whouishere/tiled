/*
 * changetile.h
 * Copyright 2015-2017, Thorbjørn Lindeijer <bjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "changevalue.h"
#include "undocommands.h"

#include <QVector>

namespace Tiled {

class Tile;

class TilesetDocument;

class ChangeTileType : public ChangeValue<Tile, QString>
{
public:
    /**
     * Creates an undo command that sets the given \a tile's \a type.
     */
    ChangeTileType(TilesetDocument *tilesetDocument,
                   const QList<Tile*> &tiles,
                   const QString &type,
                   QUndoCommand *parent = nullptr);

    int id() const override { return Cmd_ChangeTileType; }

protected:
    QString getValue(const Tile *tile) const override;
    void setValue(Tile *tile, const QString &type) const override;
};

class ChangeTileProbability : public ChangeValue<Tile, qreal>
{
public:
    ChangeTileProbability(TilesetDocument *tilesetDocument,
                          const QList<Tile*> &tiles,
                          qreal probability,
                          QUndoCommand *parent = nullptr);

    ChangeTileProbability(TilesetDocument *tilesetDocument,
                          const QList<Tile*> &tiles,
                          const QVector<qreal> &probabilities,
                          QUndoCommand *parent = nullptr);

    int id() const override { return Cmd_ChangeTileProbability; }

protected:
    qreal getValue(const Tile *tile) const override;
    void setValue(Tile *tile, const qreal &probability) const override;
};

} // namespace Tiled
