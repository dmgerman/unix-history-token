begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Main loop for the standalone kernel debugger, for GDB, the GNU Debugger.    Copyright 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
name|args
index|[]
init|=
block|{
literal|"kdb"
block|,
literal|"kdb-symbols"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|environment
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_macro
name|start
argument_list|()
end_macro

begin_block
block|{
name|INIT_STACK
argument_list|(
name|kdb_stack_beg
argument_list|,
name|kdb_stack_end
argument_list|)
expr_stmt|;
name|environ
operator|=
name|environment
expr_stmt|;
name|main
argument_list|(
literal|2
argument_list|,
name|args
argument_list|,
name|environment
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

