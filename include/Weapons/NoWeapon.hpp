/* NoWeapon.hpp

Copyright (c) 2010 - 2011 by Felix Lauer and Simon Schneegans

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>. */

# ifndef NOWEAPON_HPP_INCLUDED
# define NOWEAPON_HPP_INCLUDED

# include "Weapons/Weapon.hpp"

/// Weapon: NoWeapon.

class NoWeapon: public Weapon {
    public:
        /// Ctor which constructs the weapon.
        NoWeapon(Ship* parent):
              Weapon(weapons::wNoWeapon, parent, sf::String("Nothing")) {};

        /// Does nothing.
        void fire() const {}

        /// Does nothing.
        void draw() const {}
};

# endif // NOWEAPON_HPP_INCLUDED


