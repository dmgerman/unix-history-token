begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* main.c: defines main() for cc1, cc1plus, etc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_decl_stmt
name|int
decl|main
name|PARAMS
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We define main() to call toplev_main(), which is defined in toplev.c.    We do this in a separate file in order to allow the language front-end    to define a different main(), if it so desires.  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
return|return
name|toplev_main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function

end_unit

