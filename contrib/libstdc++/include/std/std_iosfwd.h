begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Forwarding declarations -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2001, 2002, 2003
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
comment|// ISO C++ 14882: 27.2  Forward declarations
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file iosfwd  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_IOSFWD
end_ifndef

begin_define
define|#
directive|define
name|_CPP_IOSFWD
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
file|<bits/c++locale.h>
end_include

begin_include
include|#
directive|include
file|<cctype>
end_include

begin_comment
comment|// For isspace, etc.
end_comment

begin_include
include|#
directive|include
file|<bits/stringfwd.h>
end_include

begin_comment
comment|// For string forward declarations.
end_comment

begin_include
include|#
directive|include
file|<bits/fpos.h>
end_include

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_ios
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_streambuf
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_istream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_ostream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_iostream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
operator|,
name|typename
name|_Alloc
operator|=
name|allocator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_stringbuf
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
operator|,
name|typename
name|_Alloc
operator|=
name|allocator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_istringstream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
operator|,
name|typename
name|_Alloc
operator|=
name|allocator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_ostringstream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
operator|,
name|typename
name|_Alloc
operator|=
name|allocator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_stringstream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_filebuf
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_ifstream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_ofstream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_fstream
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|istreambuf_iterator
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|ostreambuf_iterator
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCPP_RESOLVE_LIB_DEFECTS
comment|// Not included.   (??? Apparently no LWG number?)
name|class
name|ios_base
decl_stmt|;
endif|#
directive|endif
comment|/**     *  @defgroup s27_2_iosfwd I/O Forward Declarations    *    *  Nearly all of the I/O classes are parameterized on the type of    *  characters they read and write.  (The major exception is ios_base at    *  the top of the hierarchy.)  This is a change from pre-Standard    *  streams, which were not templates.    *    *  For ease of use and compatibility, all of the basic_* I/O-related    *  classes are given typedef names for both of the builtin character    *  widths (wide and narrow).  The typedefs are the same as the    *  pre-Standard names, for example:    *    *  @code    *     typedef basic_ifstream<char>  ifstream;    *  @endcode    *    *  Because properly forward-declaring these classes can be difficult, you    *  should not do it yourself.  Instead, include the&lt;iosfwd&gt;    *  header, which contains only declarations of all the I/O classes as    *  well as the typedefs.  Trying to forward-declare the typedefs    *  themselves (e.g., "class ostream;") is not valid ISO C++.    *    *  For more specific declarations, see    *  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#10    *    *  @{   */
typedef|typedef
name|basic_ios
operator|<
name|char
operator|>
name|ios
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_streambuf
operator|<
name|char
operator|>
name|streambuf
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_istream
operator|<
name|char
operator|>
name|istream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ostream
operator|<
name|char
operator|>
name|ostream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_iostream
operator|<
name|char
operator|>
name|iostream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_stringbuf
operator|<
name|char
operator|>
name|stringbuf
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_istringstream
operator|<
name|char
operator|>
name|istringstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ostringstream
operator|<
name|char
operator|>
name|ostringstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_stringstream
operator|<
name|char
operator|>
name|stringstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_filebuf
operator|<
name|char
operator|>
name|filebuf
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ifstream
operator|<
name|char
operator|>
name|ifstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ofstream
operator|<
name|char
operator|>
name|ofstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_fstream
operator|<
name|char
operator|>
name|fstream
expr_stmt|;
comment|///< @isiosfwd
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
typedef|typedef
name|basic_ios
operator|<
name|wchar_t
operator|>
name|wios
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_streambuf
operator|<
name|wchar_t
operator|>
name|wstreambuf
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_istream
operator|<
name|wchar_t
operator|>
name|wistream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ostream
operator|<
name|wchar_t
operator|>
name|wostream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_iostream
operator|<
name|wchar_t
operator|>
name|wiostream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_stringbuf
operator|<
name|wchar_t
operator|>
name|wstringbuf
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_istringstream
operator|<
name|wchar_t
operator|>
name|wistringstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ostringstream
operator|<
name|wchar_t
operator|>
name|wostringstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_stringstream
operator|<
name|wchar_t
operator|>
name|wstringstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_filebuf
operator|<
name|wchar_t
operator|>
name|wfilebuf
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ifstream
operator|<
name|wchar_t
operator|>
name|wifstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_ofstream
operator|<
name|wchar_t
operator|>
name|wofstream
expr_stmt|;
comment|///< @isiosfwd
typedef|typedef
name|basic_fstream
operator|<
name|wchar_t
operator|>
name|wfstream
expr_stmt|;
comment|///< @isiosfwd
endif|#
directive|endif
comment|/** @}  */
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

