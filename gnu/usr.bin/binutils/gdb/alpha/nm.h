begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native definitions for alpha running FreeBSD.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  We expect that we have just entered    longjmp and haven't yet setup the stack frame, so the args are still in the    argument regs.  A0_REGNUM points at the jmp_buf structure from which we    extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
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

begin_comment
comment|/* Tell gdb that we can attach and detach other processes */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* We define our own fetch/store methods */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|alpha_u_regs_offset
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|alpha_u_regs_offset()
end_define

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|char*
end_define

begin_comment
comment|/* ptrace transfers longs, the ptrace man page is lying.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_XFER_TYPE
value|int
end_define

begin_comment
comment|/* The alpha does not step over a breakpoint, the manpage is lying again.  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_STEP_BREAKPOINT
end_define

begin_comment
comment|/* Linux has shared libraries.  */
end_comment

begin_define
define|#
directive|define
name|GDB_TARGET_HAS_SHARED_LIBS
end_define

begin_comment
comment|/* Support for shared libraries.  */
end_comment

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_define
define|#
directive|define
name|TARGET_ELF64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a lie.  It's actually in stdio.h. */
end_comment

begin_define
define|#
directive|define
name|PSIGNAL_IN_SIGNAL_H
end_define

begin_comment
comment|/* Given a pointer to either a gregset_t or fpregset_t, return a    pointer to the first register.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_REGSET_BASE
parameter_list|(
name|regsetp
parameter_list|)
value|((long *) (regsetp))
end_define

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kernel_writablecore
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ADDITIONAL_OPTIONS
define|\
value|{"kernel", no_argument,&kernel_debugging, 1}, \         {"k", no_argument,&kernel_debugging, 1}, \         {"wcore", no_argument,&kernel_writablecore, 1}, \         {"w", no_argument,&kernel_writablecore, 1},
end_define

begin_define
define|#
directive|define
name|ADDITIONAL_OPTION_HELP
define|\
value|"\   --kernel           Enable kernel debugging.\n\   --wcore            Make core file writable (only works for /dev/mem).\n\                      This option only works while debugging a kernel !!\n\ "
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROMPT
value|kernel_debugging?"(kgdb) ":"(gdb) "
end_define

begin_comment
comment|/* misuse START_PROGRESS to test whether we're running as kgdb */
end_comment

begin_comment
comment|/* START_PROGRESS is called at the top of main */
end_comment

begin_undef
undef|#
directive|undef
name|START_PROGRESS
end_undef

begin_define
define|#
directive|define
name|START_PROGRESS
parameter_list|(
name|STR
parameter_list|,
name|N
parameter_list|)
define|\
value|if (!strcmp(STR, "kgdb")) \      kernel_debugging = 1;
end_define

end_unit

