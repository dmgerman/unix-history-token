begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Standard iostream objects -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 27.3  Standard iostream objects
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file iostream  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_IOSTREAM
end_ifndef

begin_define
define|#
directive|define
name|_CPP_IOSTREAM
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
file|<ostream>
end_include

begin_include
include|#
directive|include
file|<istream>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/**    *  @name Standard Stream Objects    *    *  The&lt;iostream&gt; header declares the eight<em>standard stream    *  objects</em>.  For other declarations, see    *  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#10 and the    *  @link s27_2_iosfwd I/O forward declarations @endlink    *    *  They are required by default to cooperate with the global C library's    *  @c FILE streams, and to be available during program startup and    *  termination.  For more information, see the HOWTO linked to above.   */
comment|//@{
specifier|extern
name|istream
name|cin
decl_stmt|;
comment|///< Linked to standard input
specifier|extern
name|ostream
name|cout
decl_stmt|;
comment|///< Linked to standard output
specifier|extern
name|ostream
name|cerr
decl_stmt|;
comment|///< Linked to standard error (unbuffered)
specifier|extern
name|ostream
name|clog
decl_stmt|;
comment|///< Linked to standard error (buffered)
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
specifier|extern
name|wistream
name|wcin
decl_stmt|;
comment|///< Linked to standard input
specifier|extern
name|wostream
name|wcout
decl_stmt|;
comment|///< Linked to standard output
specifier|extern
name|wostream
name|wcerr
decl_stmt|;
comment|///< Linked to standard error (unbuffered)
specifier|extern
name|wostream
name|wclog
decl_stmt|;
comment|///< Linked to standard error (buffered)
endif|#
directive|endif
comment|//@}
comment|// For construction of filebuffers for cout, cin, cerr, clog et. al.
specifier|static
name|ios_base
operator|::
name|Init
name|__ioinit
expr_stmt|;
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

