begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running under NetBSD.    Copyright 1994, 1996, 2000, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_NBSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_NBSD_H
end_define

begin_define
define|#
directive|define
name|HAVE_I387_REGS
end_define

begin_define
define|#
directive|define
name|HAVE_SSE_REGS
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_include
include|#
directive|include
file|"config/tm-nbsd.h"
end_include

begin_decl_stmt
specifier|extern
name|use_struct_convention_fn
name|i386nbsd_use_struct_convention
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
define|\
value|i386nbsd_use_struct_convention(gcc_p, type)
end_define

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|sizeof(int)
end_define

begin_comment
comment|/* jmp_buf[_JBLEN] is array of ints */
end_comment

begin_define
define|#
directive|define
name|JB_PC
value|0
end_define

begin_comment
comment|/* Setjmp()'s return PC saved here */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the stack.    We expect the first arg to be a pointer to the jmp_buf structure from which    we extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_longjmp_target
parameter_list|(
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|ADDR
parameter_list|)
value|get_longjmp_target(ADDR)
end_define

begin_escape
end_escape

begin_comment
comment|/* Support for signal handlers.  */
end_comment

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|i386bsd_in_sigtramp (pc, name)
end_define

begin_function_decl
specifier|extern
name|int
name|i386bsd_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These defines allow the recognition of sigtramps as a function name<sigtramp>.     FIXME: kettenis/2001-07-13: These should be added to the target    vector and turned into functions when we go "multi-arch".  */
end_comment

begin_define
define|#
directive|define
name|SIGTRAMP_START
parameter_list|(
name|pc
parameter_list|)
value|i386bsd_sigtramp_start
end_define

begin_define
define|#
directive|define
name|SIGTRAMP_END
parameter_list|(
name|pc
parameter_list|)
value|i386bsd_sigtramp_end
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386bsd_sigtramp_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386bsd_sigtramp_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Override FRAME_SAVED_PC to enable the recognition of signal handlers.  */
end_comment

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
name|frame
parameter_list|)
value|i386bsd_frame_saved_pc (frame)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386bsd_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_NBSD_H */
end_comment

end_unit

