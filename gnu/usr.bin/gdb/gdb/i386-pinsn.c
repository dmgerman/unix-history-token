begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Print i386 instructions for GDB, the GNU debugger.    Copyright 1986, 1987, 1989, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"dis-asm.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Print the instruction at address MEMADDR in debugged memory,    on STREAM.  Returns length of the instruction, in bytes.  */
end_comment

begin_function
name|int
name|print_insn
parameter_list|(
name|memaddr
parameter_list|,
name|stream
parameter_list|)
name|CORE_ADDR
name|memaddr
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
block|{
name|disassemble_info
name|info
decl_stmt|;
name|GDB_INIT_DISASSEMBLE_INFO
argument_list|(
name|info
argument_list|,
name|stream
argument_list|)
expr_stmt|;
return|return
name|print_insn_i386
argument_list|(
name|memaddr
argument_list|,
operator|&
name|info
argument_list|)
return|;
block|}
end_function

end_unit

