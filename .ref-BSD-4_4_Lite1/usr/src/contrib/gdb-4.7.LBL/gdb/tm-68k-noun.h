begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine parameters for an embedded m68k, for GDB, the GNU debugger.    This is for object file formats that don't have underlines on symbols.    Copyright 1986, 1987, 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_68881
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

begin_comment
comment|/* Longjmp info comes from the Sun-3 machine description.  Might as well    guess... */
end_comment

begin_comment
comment|/* Offsets (in target ints) into jmp_buf.  Not defined by Sun, but at least    documented in a comment in<machine/setjmp.h>! */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|JB_ONSSTACK
value|0
end_define

begin_define
define|#
directive|define
name|JB_SIGMASK
value|1
end_define

begin_define
define|#
directive|define
name|JB_SP
value|2
end_define

begin_define
define|#
directive|define
name|JB_PC
value|3
end_define

begin_define
define|#
directive|define
name|JB_PSL
value|4
end_define

begin_define
define|#
directive|define
name|JB_D2
value|5
end_define

begin_define
define|#
directive|define
name|JB_D3
value|6
end_define

begin_define
define|#
directive|define
name|JB_D4
value|7
end_define

begin_define
define|#
directive|define
name|JB_D5
value|8
end_define

begin_define
define|#
directive|define
name|JB_D6
value|9
end_define

begin_define
define|#
directive|define
name|JB_D7
value|10
end_define

begin_define
define|#
directive|define
name|JB_A2
value|11
end_define

begin_define
define|#
directive|define
name|JB_A3
value|12
end_define

begin_define
define|#
directive|define
name|JB_A4
value|13
end_define

begin_define
define|#
directive|define
name|JB_A5
value|14
end_define

begin_define
define|#
directive|define
name|JB_A6
value|15
end_define

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the stack.    We expect the first arg to be a pointer to the jmp_buf structure from which    we extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
end_comment

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|ADDR
parameter_list|)
value|get_longjmp_target(ADDR)
end_define

begin_comment
comment|/* Where is the PC after a call?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|m68k_saved_pc_after_call
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|SAVED_PC_AFTER_CALL
end_undef

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
define|\
value|m68k_saved_pc_after_call(frame)
end_define

end_unit

