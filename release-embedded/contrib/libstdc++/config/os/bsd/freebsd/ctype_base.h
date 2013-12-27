begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2003 Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
comment|// Information as gleaned from /usr/include/ctype.h on FreeBSD 3.4,
end_comment

begin_comment
comment|// 4.0 and all versions of the CVS managed file at:
end_comment

begin_comment
comment|// :pserver:anoncvs@anoncvs.freebsd.org:/home/ncvs/src/include/ctype.h
end_comment

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|/// @brief  Base class for ctype.
end_comment

begin_decl_stmt
name|class
name|ctype_base
block|{
name|public
label|:
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
name|long
name|mask
typedef|;
ifdef|#
directive|ifdef
name|_CTYPE_S
comment|// FreeBSD 4.0 uses this style of define.
specifier|static
specifier|const
name|mask
name|upper
init|=
name|_CTYPE_U
decl_stmt|;
specifier|static
specifier|const
name|mask
name|lower
init|=
name|_CTYPE_L
decl_stmt|;
specifier|static
specifier|const
name|mask
name|alpha
init|=
name|_CTYPE_A
decl_stmt|;
specifier|static
specifier|const
name|mask
name|digit
init|=
name|_CTYPE_D
decl_stmt|;
specifier|static
specifier|const
name|mask
name|xdigit
init|=
name|_CTYPE_X
decl_stmt|;
specifier|static
specifier|const
name|mask
name|space
init|=
name|_CTYPE_S
decl_stmt|;
specifier|static
specifier|const
name|mask
name|print
init|=
name|_CTYPE_R
decl_stmt|;
specifier|static
specifier|const
name|mask
name|graph
init|=
name|_CTYPE_A
operator||
name|_CTYPE_D
operator||
name|_CTYPE_P
decl_stmt|;
specifier|static
specifier|const
name|mask
name|cntrl
init|=
name|_CTYPE_C
decl_stmt|;
specifier|static
specifier|const
name|mask
name|punct
init|=
name|_CTYPE_P
decl_stmt|;
specifier|static
specifier|const
name|mask
name|alnum
init|=
name|_CTYPE_A
operator||
name|_CTYPE_D
decl_stmt|;
else|#
directive|else
comment|// Older versions, including Free BSD 3.4, use this style of define.
specifier|static
specifier|const
name|mask
name|upper
init|=
name|_U
decl_stmt|;
specifier|static
specifier|const
name|mask
name|lower
init|=
name|_L
decl_stmt|;
specifier|static
specifier|const
name|mask
name|alpha
init|=
name|_A
decl_stmt|;
specifier|static
specifier|const
name|mask
name|digit
init|=
name|_D
decl_stmt|;
specifier|static
specifier|const
name|mask
name|xdigit
init|=
name|_X
decl_stmt|;
specifier|static
specifier|const
name|mask
name|space
init|=
name|_S
decl_stmt|;
specifier|static
specifier|const
name|mask
name|print
init|=
name|_R
decl_stmt|;
specifier|static
specifier|const
name|mask
name|graph
init|=
name|_A
operator||
name|_D
operator||
name|_P
decl_stmt|;
specifier|static
specifier|const
name|mask
name|cntrl
init|=
name|_C
decl_stmt|;
specifier|static
specifier|const
name|mask
name|punct
init|=
name|_P
decl_stmt|;
specifier|static
specifier|const
name|mask
name|alnum
init|=
name|_A
operator||
name|_D
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

end_unit

