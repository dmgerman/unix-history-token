begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * strerror.c --- ANSI C compatible system error routine  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1986, 1988, 1989, 1991 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Progamming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with GAWK; see the file COPYING.  If not, write to  * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

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
operator|>
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

