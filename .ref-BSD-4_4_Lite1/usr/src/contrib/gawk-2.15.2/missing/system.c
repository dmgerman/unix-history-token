begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * system.c --- replacement system() for systems missing one  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1986, 1988, 1989, 1991 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Progamming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with GAWK; see the file COPYING.  If not, write to  * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|system
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|fatal
argument_list|(
literal|"system() not supported on this system"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

