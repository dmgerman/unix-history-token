begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent definitions for FreeBSD/i386.    Copyright 1997, 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_FBSD_H
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD/ELF uses stabs-in-ELF with the DWARF register numbering    scheme by default, so we must redefine STAB_REG_TO_REGNUM.  This    messes up the floating-point registers for a.out, but there is not    much we can do about that.  */
end_comment

begin_undef
undef|#
directive|undef
name|STAB_REG_TO_REGNUM
end_undef

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|reg
parameter_list|)
value|i386_dwarf_reg_to_regnum ((reg))
end_define

begin_comment
comment|/* FreeBSD uses the old gcc convention for struct returns.  */
end_comment

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
value|generic_use_struct_convention (1, type)
end_define

begin_escape
end_escape

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
value|0
end_define

begin_comment
comment|/* Array index of saved PC.  */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  Store the address that    longjmp will jump to in *ADDR, and return non-zero if successful.  */
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

begin_escape
end_escape

begin_comment
comment|/* Shared library support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4_SHARED_LIBS
end_ifndef

begin_comment
comment|/* Return non-zero if we are in a shared library trampoline code stub.  */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
define|\
value|(name&& !strcmp(name, "_DYNAMIC"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SVR4_SHARED_LIBS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_FBSD_H */
end_comment

end_unit

