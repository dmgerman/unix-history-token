begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memset    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|PTR
name|DEFUN
argument_list|(
name|memset
argument_list|,
operator|(
name|dest
operator|,
name|val
operator|,
name|len
operator|)
argument_list|,
name|PTR
name|dest
name|AND
specifier|register
name|int
name|val
name|AND
specifier|register
name|size_t
name|len
argument_list|)
block|{
specifier|register
name|unsigned
name|char
modifier|*
name|ptr
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|dest
decl_stmt|;
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
operator|*
name|ptr
operator|++
operator|=
name|val
expr_stmt|;
return|return
name|dest
return|;
block|}
end_decl_stmt

end_unit

