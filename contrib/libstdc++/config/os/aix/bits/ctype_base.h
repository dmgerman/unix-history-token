begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 1999 Free Software Foundation, Inc.
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

begin_comment
comment|// Information as gleaned from /usr/include/ctype.h
end_comment

begin_struct
struct|struct
name|ctype_base
block|{
comment|// Non-standard typedefs.
typedef|typedef
specifier|const
name|int
modifier|*
name|__to_type
typedef|;
comment|// NB: Offsets into ctype<char>::_M_table force a particular size
comment|// on the mask type. Because of this, we don't use an enum.
typedef|typedef
name|unsigned
name|int
name|mask
typedef|;
specifier|static
specifier|const
name|mask
name|upper
init|=
name|_ISUPPER
decl_stmt|;
specifier|static
specifier|const
name|mask
name|lower
init|=
name|_ISLOWER
decl_stmt|;
specifier|static
specifier|const
name|mask
name|alpha
init|=
name|_ISALPHA
decl_stmt|;
specifier|static
specifier|const
name|mask
name|digit
init|=
name|_ISDIGIT
decl_stmt|;
specifier|static
specifier|const
name|mask
name|xdigit
init|=
name|_ISXDIGIT
decl_stmt|;
specifier|static
specifier|const
name|mask
name|space
init|=
name|_ISSPACE
decl_stmt|;
specifier|static
specifier|const
name|mask
name|print
init|=
name|_ISPRINT
decl_stmt|;
specifier|static
specifier|const
name|mask
name|graph
init|=
name|_ISGRAPH
decl_stmt|;
specifier|static
specifier|const
name|mask
name|cntrl
init|=
name|_ISCNTRL
decl_stmt|;
specifier|static
specifier|const
name|mask
name|punct
init|=
name|_ISPUNCT
decl_stmt|;
specifier|static
specifier|const
name|mask
name|alnum
init|=
name|_ISALNUM
decl_stmt|;
block|}
struct|;
end_struct

end_unit

