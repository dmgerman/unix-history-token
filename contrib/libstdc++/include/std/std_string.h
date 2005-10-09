begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Components for manipulating sequences of characters -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 21  Strings library
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file string  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_STRING
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_STRING
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<bits/stringfwd.h>
end_include

begin_include
include|#
directive|include
file|<bits/char_traits.h>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// For allocator.
end_comment

begin_include
include|#
directive|include
file|<bits/type_traits.h>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_comment
comment|// For operators>>,<<, and getline decls.
end_comment

begin_include
include|#
directive|include
file|<bits/stl_iterator.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_function.h>
end_include

begin_comment
comment|// For less
end_comment

begin_include
include|#
directive|include
file|<bits/basic_string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_EXPORT_TEMPLATE
end_ifndef

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_comment
comment|// for find_if
end_comment

begin_include
include|#
directive|include
file|<bits/basic_string.tcc>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GLIBCXX_STRING */
end_comment

end_unit

