begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running the GNU Hurd.    Copyright 1992, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386GNU_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386GNU_H
value|1
end_define

begin_comment
comment|/* Include common definitions for GNU systems.    FIXME: This does not belong here since this is supposed to contain    only native-dependent information.  */
end_comment

begin_include
include|#
directive|include
file|"nm-gnu.h"
end_include

begin_comment
comment|/* Thread flavors used in re-setting the T bit.    FIXME: This is native-dependent.  */
end_comment

begin_define
define|#
directive|define
name|THREAD_STATE_FLAVOR
value|i386_REGS_SEGS_STATE
end_define

begin_define
define|#
directive|define
name|THREAD_STATE_SIZE
value|i386_THREAD_STATE_COUNT
end_define

begin_define
define|#
directive|define
name|THREAD_STATE_SET_TRACED
parameter_list|(
name|state
parameter_list|)
define|\
value|((struct i386_thread_state *)state)->efl |= 0x100
end_define

begin_define
define|#
directive|define
name|THREAD_STATE_CLEAR_TRACED
parameter_list|(
name|state
parameter_list|)
define|\
value|((((struct i386_thread_state *)state)->efl&= ~0x100), 1)
end_define

begin_comment
comment|/* We can attach and detach.    FIXME: This is probably native-dependent too.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
value|1
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

begin_comment
comment|/* We use stabs-in-ELF with the DWARF register numbering scheme.  */
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
comment|/* Offset to saved PC in sigcontext.  */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|68
end_define

begin_comment
comment|/* We need this file for the SOLIB_TRAMPOLINE stuff.  */
end_comment

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_I386GNU_H */
end_comment

end_unit

