begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running NetWare.    Copyright 1993, 1994 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386NW_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386NW_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* Stop backtracing when we wander into main.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|fp
parameter_list|,
name|fi
parameter_list|)
value|alternate_frame_chain_valid (fp, fi)
end_define

begin_comment
comment|/* Offsets (in target ints) into jmp_buf.  Not defined in any system header    file, so we have to step through setjmp/longjmp with a debugger and figure    them out.  */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_comment
comment|/* jmp_buf[] is array of ints */
end_comment

begin_define
define|#
directive|define
name|JB_PC
value|6
end_define

begin_comment
comment|/* Setjmp()'s return PC saved here */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the stack.    We expect the first arg to be a pointer to the jmp_buf structure from which    we extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_longjmp_target
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|ADDR
parameter_list|)
value|get_longjmp_target(ADDR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386NW_H */
end_comment

end_unit

