/* font.hpp

Copyright (c) 2010 by Felix Lauer and Simon Schneegans

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

# ifndef FONT_HPP_INCLUDED
# define FONT_HPP_INCLUDED

# include <SFML/Graphics.hpp>

/// A namespace for loading font files.

namespace font {
    /// The different fonts included in MARS.
    enum FontType {Ubuntu, FreeSans,
                   COUNT ///< COUNT contains the amount of entries in the enum. Keep it the last!
    };

    /// Returns a const& to the SFML font.
    /// You can specify which font to return with the \a type parameter.
    sf::Font const& getFont(FontType type);
}

# endif // FONT_HPP_INCLUDED

