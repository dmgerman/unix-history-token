begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for target machine Hewlett-Packard 9000/300, running bsd.    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Configuration file for HP9000/300 series machine running  * University of Utah's 4.3bsd port.  This is NOT for HP-UX.  * Problems to hpbsd-bugs@cs.utah.edu  */
end_comment

begin_define
define|#
directive|define
name|HAVE_68881
end_define

begin_comment
comment|/* Define BPT_VECTOR if it is different than the default.    This is the vector number used by traps to indicate a breakpoint. */
end_comment

begin_define
define|#
directive|define
name|BPT_VECTOR
value|0x2
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_define
define|#
directive|define
name|TARGET_NBPG
value|4096
end_define

begin_define
define|#
directive|define
name|TARGET_UPAGES
value|3
end_define

begin_comment
comment|/* On the HP300, sigtramp is in the u area.  Gak!  User struct is not    mapped to the same virtual address in user/kernel address space    (hence STACK_END_ADDR as opposed to KERNEL_U_ADDR).  This tests    for the whole u area, since we don't necessarily have hp300bsd    include files around.  */
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
define|\
value|((pc)>= STACK_END_ADDR   \&& (pc)< STACK_END_ADDR + TARGET_UPAGES * TARGET_NBPG \    )
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0xfff00000
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

end_unit

