begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386, Mach 3.0    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Include common definitions for Mach3 systems */
end_comment

begin_include
include|#
directive|include
file|"nm-m3.h"
end_include

begin_comment
comment|/* Define offsets to access CPROC stack when it does not have  * a kernel thread.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE_CPROC_SP_OFFSET
value|20
end_define

begin_define
define|#
directive|define
name|MACHINE_CPROC_PC_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|MACHINE_CPROC_FP_OFFSET
value|12
end_define

begin_comment
comment|/* Thread flavors used in re-setting the T bit.  * @@ this is also bad for cross debugging.  */
end_comment

begin_define
define|#
directive|define
name|TRACE_FLAVOR
value|i386_THREAD_STATE
end_define

begin_define
define|#
directive|define
name|TRACE_FLAVOR_SIZE
value|i386_THREAD_STATE_COUNT
end_define

begin_define
define|#
directive|define
name|TRACE_SET
parameter_list|(
name|x
parameter_list|,
name|state
parameter_list|)
define|\
value|((struct i386_thread_state *)state)->efl |= 0x100
end_define

begin_define
define|#
directive|define
name|TRACE_CLEAR
parameter_list|(
name|x
parameter_list|,
name|state
parameter_list|)
define|\
value|((((struct i386_thread_state *)state)->efl&= ~0x100), 1)
end_define

begin_comment
comment|/* we can do it */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
value|1
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_comment
comment|/* Sigh. There should be a file for i386 but no sysv stuff in it */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* I want to test this float info code. See comment in tm-i386v.h */
end_comment

begin_undef
undef|#
directive|undef
name|FLOAT_INFO
end_undef

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i386_mach3_float_info (); }
end_define

begin_comment
comment|/* Address of end of stack space.  * for MACH, see<machine/vmparam.h>  * @@@ I don't know what is in the 5 ints...  */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_END_ADDR
end_undef

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0xc0000000-sizeof(int [5]))
end_define

end_unit

