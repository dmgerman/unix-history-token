begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running gdb on a Sun 4 running sunos 4.    Copyright (C) 1989, Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Include limits to override definitions in defs.h.  */
end_comment

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|"xm-sparc.h"
end_include

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable use of alternate code for Sun's format of core dump file.  */
end_comment

begin_define
define|#
directive|define
name|NEW_SUN_CORE
end_define

begin_comment
comment|/* Do implement the attach and detach commands.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

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
comment|/* It does have a wait structure, and it might help things out . . . */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_define
define|#
directive|define
name|FPU
end_define

begin_comment
comment|/* Large alloca's fail because the attempt to increase the stack limit in    main() fails because shared libraries are allocated just below the initial    stack limit.  The SunOS kernel will not allow the stack to grow into    the area occupied by the shared libraries.  Sun knows about this bug    but has no obvious fix for it.  */
end_comment

begin_comment
comment|/* XXX is this true for BSD */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_define
define|#
directive|define
name|PSIGNAL_IN_SIGNAL_H
end_define

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|char*
end_define

end_unit

