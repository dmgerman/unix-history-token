begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * strerror.c --- ANSI C compatible system error routine  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1986, 1988, 1989, 1991 the Free Software Foundation, Inc.  * From gawk.  *   * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  *  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

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
name|mesg
index|[
literal|30
index|]
decl_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
operator|||
name|n
operator|>=
name|sys_nerr
condition|)
block|{
name|sprintf
argument_list|(
name|mesg
argument_list|,
literal|"Unknown error (%d)"
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|mesg
return|;
block|}
else|else
return|return
name|sys_errlist
index|[
name|n
index|]
return|;
block|}
end_function

end_unit

