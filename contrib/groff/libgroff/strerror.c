begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|INT_DIGITS
value|19
end_define

begin_comment
comment|/* enough for 64 bit integer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_NERR
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_ERRLIST
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
literal|"Error "
argument_list|)
operator|+
literal|1
operator|+
name|INT_DIGITS
index|]
decl_stmt|;
if|if
condition|(
name|n
operator|>=
literal|0
operator|&&
name|n
operator|<
name|sys_nerr
operator|&&
name|sys_errlist
index|[
name|n
index|]
operator|!=
literal|0
condition|)
return|return
name|sys_errlist
index|[
name|n
index|]
return|;
else|else
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"Error %d"
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
block|}
end_function

end_unit

