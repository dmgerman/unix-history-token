begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// 'struct hash' from SGI -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
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
comment|/*  * Copyright (c) 1996-1998  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_comment
comment|/** @file ext/hash_fun.h  *  This file is a GNU extension to the Standard C++ Library (possibly  *  containing extensions from the HP/SGI STL subset).  You should only  *  include this header if you are using GCC 3 or later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HASH_FUN_H
end_ifndef

begin_define
define|#
directive|define
name|_HASH_FUN_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
name|using
name|std
operator|::
name|size_t
expr_stmt|;
name|template
operator|<
name|class
name|_Key
operator|>
expr|struct
name|hash
block|{ }
expr_stmt|;
specifier|inline
name|size_t
name|__stl_hash_string
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
block|{
name|unsigned
name|long
name|__h
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
operator|*
name|__s
condition|;
operator|++
name|__s
control|)
name|__h
operator|=
literal|5
operator|*
name|__h
operator|+
operator|*
name|__s
expr_stmt|;
return|return
name|size_t
argument_list|(
name|__h
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|char
operator|*
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|__s
operator|)
specifier|const
block|{
return|return
name|__stl_hash_string
argument_list|(
name|__s
argument_list|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
specifier|const
name|char
operator|*
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|__s
operator|)
specifier|const
block|{
return|return
name|__stl_hash_string
argument_list|(
name|__s
argument_list|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|char
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|char
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|unsigned
name|char
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|char
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|signed
name|char
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|char
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|short
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|short
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|unsigned
name|short
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|short
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|int
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|int
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|unsigned
name|int
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|int
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|long
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|long
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|unsigned
name|long
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|long
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

