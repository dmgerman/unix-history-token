begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host-machine dependent parameters for Motorola 88000, for GDB.    Copyright 1986, 1987, 1988, 1989, 1990, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_define
define|#
directive|define
name|USG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|memcpy
value|__builtin_memcpy
end_define

begin_comment
comment|/* gcc doesn't have this, at least not gcc 1.92.  */
end_comment

begin_comment
comment|/* #define memset __builtin_memset */
end_comment

begin_define
define|#
directive|define
name|strcmp
value|__builtin_strcmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX
end_ifdef

begin_define
define|#
directive|define
name|x_foff
value|_x_x._x_offset
end_define

begin_define
define|#
directive|define
name|x_fname
value|_x_name
end_define

begin_define
define|#
directive|define
name|USER
value|ptrace_user
end_define

begin_define
define|#
directive|define
name|_BSD_WAIT_FLAVOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USIZE
end_ifndef

begin_define
define|#
directive|define
name|USIZE
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NBPG
value|NBPC
end_define

begin_define
define|#
directive|define
name|UPAGES
value|USIZE
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_comment
comment|/* Since registers r0 through r31 are stored directly in the struct ptrace_user,    (for m88k BCS)    the ptrace_user offsets are sufficient and KERNEL_U_ADDRESS can be 0 */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0
end_define

end_unit

