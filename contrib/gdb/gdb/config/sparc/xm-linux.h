begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running gdb on a Sparc running GNU/Linux.     Copyright 1989, 1993, 1994, 1995, 1996, 1998, 2001, 2002 Free    Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XM_SPARCLINUX_H
end_ifndef

begin_define
define|#
directive|define
name|XM_SPARCLINUX_H
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0x0
end_define

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_comment
comment|/* If you expect to use the mmalloc package to obtain mapped symbol files,    for now you have to specify some parameters that determine how gdb places    the mappings in it's address space.  See the comments in map_to_address()    for details.  This is expected to only be a short term solution.  Yes it    is a kludge.    FIXME:  Make this more automatic. */
end_comment

begin_define
define|#
directive|define
name|MMAP_BASE_ADDRESS
value|0xE0000000
end_define

begin_comment
comment|/* First mapping here */
end_comment

begin_define
define|#
directive|define
name|MMAP_INCREMENT
value|0x01000000
end_define

begin_comment
comment|/* Increment to next mapping */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XM_SPARCLINUX_H */
end_comment

end_unit

