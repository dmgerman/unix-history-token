begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a mips box under 4.3bsd.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.    Contributed by Per Bothner(bothner@cs.wisc.edu) at U.Wisconsin    and by Alessandro Forin(af@cs.cmu.edu) at CMU  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HOST_BYTE_ORDER
argument_list|)
end_if

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_comment
comment|/* Needed for DECstation core files.  */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|UADDR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DECstation memcpy and memset return void *, not char *.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|memcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MEM_FNS_DECLARED
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|offsetof
argument_list|)
end_if

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((unsigned long)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Only used for core files on DECstations.    First four registers at u.u_ar0 are saved arguments, and    there is no r0 saved.   Float registers are saved    in u_pcb.pcb_fpregs, not relative to u.u_ar0.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|{ \ 	  if (regno< FP0_REGNUM) \ 	    addr = blockend + sizeof(int) * (4 + regno - 1); \ 	  else \ 	    addr = offsetof (struct user, u_pcb.pcb_fpregs[0]) + \ 		   sizeof (int) * (regno - FP0_REGNUM); \ 	}
end_define

begin_comment
comment|/* Kernel is a bit tenacious about sharing text segments, disallowing bpts.  */
end_comment

begin_define
define|#
directive|define
name|ONE_PROCESS_WRITETEXT
end_define

end_unit

