begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)anddi3.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_function
name|long
name|long
name|__anddi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
name|long
name|long
name|u
decl_stmt|,
name|v
decl_stmt|;
block|{
name|long_long
name|w
decl_stmt|;
name|long_long
name|uu
decl_stmt|,
name|vv
decl_stmt|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|vv
operator|.
name|ll
operator|=
name|v
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
name|uu
operator|.
name|s
operator|.
name|high
operator|&
name|vv
operator|.
name|s
operator|.
name|high
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
name|uu
operator|.
name|s
operator|.
name|low
operator|&
name|vv
operator|.
name|s
operator|.
name|low
expr_stmt|;
return|return
name|w
operator|.
name|ll
return|;
block|}
end_function

end_unit

