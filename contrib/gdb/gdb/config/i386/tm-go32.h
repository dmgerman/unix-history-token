begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent definitions for Intel x86 running DJGPP.    Copyright 1995, 1996, 1997, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_GO32_H
end_ifndef

begin_define
define|#
directive|define
name|TM_GO32_H
end_define

begin_undef
undef|#
directive|undef
name|HAVE_SSE_REGS
end_undef

begin_comment
comment|/* FIXME! go32-nat.c needs to support XMMi registers */
end_comment

begin_define
define|#
directive|define
name|HAVE_I387_REGS
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address and produces the frame's    chain-pointer.    In the case of the i386, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.    DJGPP doesn't have any special frames for signal handlers, they are    just normal C functions. */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN
end_undef

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(!inside_entry_file ((thisframe)->pc) ? \    read_memory_integer ((thisframe)->frame, 4) :\    0)
end_define

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAMELESS_FUNCTION_INVOCATION
end_undef

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|FI
parameter_list|)
define|\
value|(frameless_look_for_prologue(FI))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386go32_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|FRAME_SAVED_PC
end_undef

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(i386go32_frame_saved_pc ((FRAME)))
end_define

begin_comment
comment|/* Support for longjmp.  */
end_comment

begin_comment
comment|/* Details about jmp_buf.  It's supposed to be an array of integers.  */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_comment
comment|/* Size of elements in jmp_buf.  */
end_comment

begin_define
define|#
directive|define
name|JB_PC
value|8
end_define

begin_comment
comment|/* Array index of saved PC inside jmp_buf.  */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the    stack.  We expect the first arg to be a pointer to the jmp_buf    structure from which we extract the pc (JB_PC) that we will land    at.  The pc is copied into ADDR.  This routine returns true on    success.  */
end_comment

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|addr
parameter_list|)
value|get_longjmp_target (addr)
end_define

begin_function_decl
specifier|extern
name|int
name|get_longjmp_target
parameter_list|(
name|CORE_ADDR
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_GO32_H */
end_comment

end_unit

