begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// OBSOLETE /* Target machine description for MIPS running SVR4, for GDB.
end_comment

begin_comment
comment|// OBSOLETE    Copyright 1994, 1995, 1998, 1999, 2000 Free Software Foundation, Inc.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This file is part of GDB.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This program is free software; you can redistribute it and/or modify
end_comment

begin_comment
comment|// OBSOLETE    it under the terms of the GNU General Public License as published by
end_comment

begin_comment
comment|// OBSOLETE    the Free Software Foundation; either version 2 of the License, or
end_comment

begin_comment
comment|// OBSOLETE    (at your option) any later version.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This program is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// OBSOLETE    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// OBSOLETE    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// OBSOLETE    GNU General Public License for more details.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// OBSOLETE    along with this program; if not, write to the Free Software
end_comment

begin_comment
comment|// OBSOLETE    Foundation, Inc., 59 Temple Place - Suite 330,
end_comment

begin_comment
comment|// OBSOLETE    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #include "mips/tm-mips.h"
end_comment

begin_comment
comment|// OBSOLETE #include "config/tm-sysv4.h"
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* The signal handler trampoline is called _sigtramp.  */
end_comment

begin_comment
comment|// OBSOLETE #undef IN_SIGTRAMP
end_comment

begin_comment
comment|// OBSOLETE #define IN_SIGTRAMP(pc, name) ((name)&& DEPRECATED_STREQ ("_sigtramp", name))
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* On entry to the signal handler trampoline, an ucontext is already
end_comment

begin_comment
comment|// OBSOLETE    pushed on the stack. We can get at the saved registers via the
end_comment

begin_comment
comment|// OBSOLETE    mcontext which is contained within the ucontext.  */
end_comment

begin_comment
comment|// OBSOLETE #define SIGFRAME_BASE	0
end_comment

begin_comment
comment|// OBSOLETE #define SIGFRAME_REGSAVE_OFF	(SIGFRAME_BASE + 40)
end_comment

begin_comment
comment|// OBSOLETE #define SIGFRAME_PC_OFF		(SIGFRAME_BASE + 40 + 35 * 4)
end_comment

begin_comment
comment|// OBSOLETE #define SIGFRAME_FPREGSAVE_OFF	(SIGFRAME_BASE + 40 + 36 * 4)
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Convert a DWARF register number to a gdb REGNUM.  */
end_comment

begin_comment
comment|// OBSOLETE #define DWARF_REG_TO_REGNUM(num) ((num)< 32 ? (num) : (num)+FP0_REGNUM-32)
end_comment

end_unit

