begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel 386 native support.    Copyright (C) 1988, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"language.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/reg.h>
end_include

begin_include
include|#
directive|include
file|"ieee-float.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|ext_format
name|ext_format_i387
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* this table must line up with REGISTER_NAMES in tm-i386v.h */
end_comment

begin_comment
comment|/* symbols like 'EAX' come from<sys/reg.h> */
end_comment

begin_decl_stmt
specifier|static
name|int
name|regmap
index|[]
init|=
block|{
name|EAX
block|,
name|ECX
block|,
name|EDX
block|,
name|EBX
block|,
name|UESP
block|,
name|EBP
block|,
name|ESI
block|,
name|EDI
block|,
name|EIP
block|,
name|EFL
block|,
name|CS
block|,
name|SS
block|,
name|DS
block|,
name|ES
block|,
name|FS
block|,
name|GS
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blockend is the value of u.u_ar0, and points to the  * place where GS is stored  */
end_comment

begin_function
name|int
name|i386_register_u_addr
parameter_list|(
name|blockend
parameter_list|,
name|regnum
parameter_list|)
name|int
name|blockend
decl_stmt|;
name|int
name|regnum
decl_stmt|;
block|{
if|#
directive|if
literal|0
comment|/* this will be needed if fp registers are reinstated */
comment|/* for now, you can look at them with 'info float'    * sys5 wont let you change them with ptrace anyway    */
block|if (regnum>= FP0_REGNUM&& regnum<= FP7_REGNUM)      {       int ubase, fpstate;       struct user u;       ubase = blockend + 4 * (SS + 1) - KSTKSZ;       fpstate = ubase + ((char *)&u.u_fpstate - (char *)&u);       return (fpstate + 0x1c + 10 * (regnum - FP0_REGNUM));     }    else
endif|#
directive|endif
return|return
operator|(
name|blockend
operator|+
literal|4
operator|*
name|regmap
index|[
name|regnum
index|]
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* using FLOAT_INFO as is would be a problem.  FLOAT_INFO is called    via a command xxx and eventually calls ptrace without ever having    traversed the target vector.  This would be terribly impolite    behaviour for a sun4 hosted remote gdb.     A fix might be to move this code into the "info registers" command.    rich@cygnus.com 15 Sept 92. */
end_comment

begin_comment
unit|i386_float_info () {   struct user u;
comment|/* just for address computations */
end_comment

begin_comment
unit|int i;
comment|/* fpstate defined in<sys/user.h> */
end_comment

begin_if
unit|struct fpstate *fpstatep;   char buf[sizeof (struct fpstate) + 2 * sizeof (int)];   unsigned int uaddr;   char fpvalid = 0;   unsigned int rounded_addr;   unsigned int rounded_size;   extern int corechan;   int skip;      uaddr = (char *)&u.u_fpvalid - (char *)&u;   if (target_has_execution)     {       unsigned int data;       unsigned int mask;              rounded_addr = uaddr& -sizeof (int);       data = ptrace (3, inferior_pid, (PTRACE_ARG3_TYPE) rounded_addr, 0);       mask = 0xff<< ((uaddr - rounded_addr) * 8);              fpvalid = ((data& mask) != 0);     }
if|#
directive|if
literal|0
end_if

begin_endif
unit|else      {       if (lseek (corechan, uaddr, 0)< 0) 	perror ("seek on core file");       if (myread (corechan,&fpvalid, 1)< 0)  	perror ("read on core file");            }
endif|#
directive|endif
end_endif

begin_comment
comment|/* no core support yet */
end_comment

begin_if
unit|if (fpvalid == 0)      {       printf ("no floating point status saved\n");       return;     }      uaddr = (char *)&U_FPSTATE(u) - (char *)&u;   if (target_has_execution)     {       int *ip;              rounded_addr = uaddr& -sizeof (int);       rounded_size = (((uaddr + sizeof (struct fpstate)) - uaddr) + 		      sizeof (int) - 1) / sizeof (int);       skip = uaddr - rounded_addr;              ip = (int *)buf;       for (i = 0; i< rounded_size; i++)  	{ 	  *ip++ = ptrace (3, inferior_pid, (PTRACE_ARG3_TYPE) rounded_addr, 0); 	  rounded_addr += sizeof (int); 	}     }
if|#
directive|if
literal|0
end_if

begin_endif
unit|else      {       if (lseek (corechan, uaddr, 0)< 0) 	perror_with_name ("seek on core file");       if (myread (corechan, buf, sizeof (struct fpstate))< 0)  	perror_with_name ("read from core file");       skip = 0;     }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
unit|fpstatep = (struct fpstate *)(buf + skip);   print_387_status (fpstatep->status, (struct env387 *)fpstatep->state); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* never */
end_comment

end_unit

