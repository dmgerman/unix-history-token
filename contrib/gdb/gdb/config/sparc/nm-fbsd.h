begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for FreeBSD/sparc64.    Copyright 2002    Free Software Foundation, Inc.    Contributed by David E. O'Brien<obrien@FreeBSD.org>.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_FBSD_H
end_define

begin_comment
comment|/* Type of the third argument to the `ptrace' system call.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|caddr_t
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* We can attach and detach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_escape
end_escape

begin_comment
comment|/* Shared library support.  */
end_comment

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* Support for shared libraries. */
end_comment

begin_include
include|#
directive|include
file|"elf/common.h"
end_include

begin_comment
comment|/* Additional ELF shared library info. */
end_comment

begin_comment
comment|/* Make things match up with what is expected in sparc-nat.c.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_GETREGS
value|PT_GETREGS
end_define

begin_define
define|#
directive|define
name|PTRACE_SETREGS
value|PT_SETREGS
end_define

begin_define
define|#
directive|define
name|PTRACE_GETFPREGS
value|PT_GETFPREGS
end_define

begin_define
define|#
directive|define
name|PTRACE_SETFPREGS
value|PT_SETFPREGS
end_define

begin_define
define|#
directive|define
name|GDB_GREGSET_T
value|struct reg
end_define

begin_define
define|#
directive|define
name|GDB_FPREGSET_T
value|struct fpreg
end_define

begin_define
define|#
directive|define
name|regs
value|trapframe
end_define

begin_define
define|#
directive|define
name|r_g1
value|tf_global[1]
end_define

begin_define
define|#
directive|define
name|r_ps
value|tf_tstate
end_define

begin_define
define|#
directive|define
name|r_pc
value|tf_tpc
end_define

begin_define
define|#
directive|define
name|r_npc
value|tf_tnpc
end_define

begin_define
define|#
directive|define
name|r_y
value|tf_y
end_define

begin_define
define|#
directive|define
name|FPU_FSR_TYPE
value|unsigned long
end_define

begin_define
define|#
directive|define
name|fp_status
value|fpreg
end_define

begin_comment
comment|/* our reg.h */
end_comment

begin_define
define|#
directive|define
name|fpu
value|fpreg
end_define

begin_comment
comment|/* our reg.h */
end_comment

begin_define
define|#
directive|define
name|fpu_regs
value|fr_regs
end_define

begin_comment
comment|/* one field of fpu_fr on Solaris */
end_comment

begin_define
define|#
directive|define
name|fpu_fr
value|fr_regs
end_define

begin_comment
comment|/* a union w/in struct fpu on Solaris */
end_comment

begin_define
define|#
directive|define
name|fpu_fsr
value|fr_fsr
end_define

begin_define
define|#
directive|define
name|Fpu_fsr
value|fr_fsr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_FBSD_H */
end_comment

end_unit

