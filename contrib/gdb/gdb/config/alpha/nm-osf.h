begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native definitions for alpha running OSF/1.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* ptrace register ``addresses'' are absolute.  */
end_comment

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_comment
comment|/* FIXME: Shouldn't the default definition in inferior.h be int* ? */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|int*
end_define

begin_comment
comment|/* ptrace transfers longs, the ptrace man page is lying.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_XFER_TYPE
value|long
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
comment|/* OSF/1 has shared libraries.  */
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
value|((regsetp)->regs)
end_define

end_unit

