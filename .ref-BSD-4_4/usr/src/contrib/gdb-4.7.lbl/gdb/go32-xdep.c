begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host-dependent code for dos running GO32 for GDB, the GNU debugger.    Copyright 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
specifier|static
name|void
name|uerror
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fatal: %s!\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|fork
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call fork()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|vfork
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call vfork()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|wait
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call wait()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|execlp
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call execlp()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|kill_inferior
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call kill_inferior()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|re_comp
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call re_comp()"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|re_exec
argument_list|()
end_macro

begin_block
block|{
name|uerror
argument_list|(
literal|"attempt to call re_exec()"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

