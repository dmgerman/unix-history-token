begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB for a UltraSparc running GNU/Linux.     Copyright 2001, 2002 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_SPARC_LIN64_H
end_ifndef

begin_define
define|#
directive|define
name|TM_SPARC_LIN64_H
end_define

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|0
end_define

begin_include
include|#
directive|include
file|"sparc/tm-sp64.h"
end_include

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|16
end_define

begin_comment
comment|/* See asm-sparc64/sigcontext.h */
end_comment

begin_comment
comment|/* We always want full V9 + Ultra VIS stuff... */
end_comment

begin_undef
undef|#
directive|undef
name|TM_PRINT_INSN_MACH
end_undef

begin_define
define|#
directive|define
name|TM_PRINT_INSN_MACH
value|bfd_mach_sparc_v9a
end_define

begin_define
define|#
directive|define
name|GDB_PTRACE_REGS64
end_define

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_endif
endif|#
directive|endif
endif|TM_SPARC_LIN64_H
end_endif

end_unit

