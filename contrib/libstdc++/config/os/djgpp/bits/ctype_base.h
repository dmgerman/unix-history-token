begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 22.1  Locales
end_comment

begin_comment
comment|//
end_comment

begin_struct
struct|struct
name|ctype_base
block|{
typedef|typedef
name|unsigned
name|short
name|mask
typedef|;
comment|// Non-standard typedefs.
typedef|typedef
name|unsigned
name|char
modifier|*
name|__to_type
typedef|;
comment|// NB: Offsets into ctype<char>::_M_table force a particular size
comment|// on the mask type. Because of this, we don't use an enum.
specifier|static
specifier|const
name|mask
name|space
init|=
name|__dj_ISSPACE
decl_stmt|;
comment|// Whitespace
specifier|static
specifier|const
name|mask
name|print
init|=
name|__dj_ISPRINT
decl_stmt|;
comment|// Printing
specifier|static
specifier|const
name|mask
name|cntrl
init|=
name|__dj_ISCNTRL
decl_stmt|;
comment|// Control character
specifier|static
specifier|const
name|mask
name|upper
init|=
name|__dj_ISUPPER
decl_stmt|;
comment|// UPPERCASE
specifier|static
specifier|const
name|mask
name|lower
init|=
name|__dj_ISLOWER
decl_stmt|;
comment|// lowercase
specifier|static
specifier|const
name|mask
name|alpha
init|=
name|__dj_ISALPHA
decl_stmt|;
comment|// Alphabetic
specifier|static
specifier|const
name|mask
name|digit
init|=
name|__dj_ISDIGIT
decl_stmt|;
comment|// Numeric
specifier|static
specifier|const
name|mask
name|punct
init|=
name|__dj_ISPUNCT
decl_stmt|;
comment|// Punctuation
specifier|static
specifier|const
name|mask
name|xdigit
init|=
name|__dj_ISXDIGIT
decl_stmt|;
comment|// Hexadecimal numeric
specifier|static
specifier|const
name|mask
name|alnum
init|=
name|__dj_ISALPHA
decl_stmt|;
comment|// Alphanumeric
specifier|static
specifier|const
name|mask
name|graph
init|=
name|__dj_ISGRAPH
decl_stmt|;
comment|// Graphical
block|}
struct|;
end_struct

end_unit

