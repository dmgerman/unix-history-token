begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for Sparc running NetBSD, for GDB.    Copyright 1986, 1987, 1989, 1992, 1994, 1996, 1999, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_NBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_NBSD_H
end_define

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_comment
comment|/* Get generic NetBSD native definitions. */
end_comment

begin_include
include|#
directive|include
file|"config/nm-nbsd.h"
end_include

begin_comment
comment|/* Before storing, we need to read all the registers.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_comment
comment|/* Make things match up with what is expected in sparc-nat.c.  */
end_comment

begin_define
define|#
directive|define
name|regs
value|trapframe
end_define

begin_define
define|#
directive|define
name|fp_status
value|fpstate
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
value|tf_psr
end_define

begin_define
define|#
directive|define
name|r_pc
value|tf_pc
end_define

begin_define
define|#
directive|define
name|r_npc
value|tf_npc
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
name|fpu
value|fpstate
end_define

begin_define
define|#
directive|define
name|fpu_regs
value|fs_regs
end_define

begin_define
define|#
directive|define
name|fpu_fsr
value|fs_fsr
end_define

begin_define
define|#
directive|define
name|fpu_fr
value|fs_regs
end_define

begin_define
define|#
directive|define
name|Fpu_fsr
value|fs_fsr
end_define

begin_define
define|#
directive|define
name|FPU_FSR_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|PTRACE_GETREGS
value|PT_GETREGS
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
name|PTRACE_SETREGS
value|PT_SETREGS
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_NBSD_H */
end_comment

end_unit

