begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host-dependent code for GDB, for NYU Ultra3 running Sym1 OS.    Copyright (C) 1988, 1989, 1991, 1992 Free Software Foundation, Inc.    Contributed by David Wood (wood@nyu.edu) at New York University.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

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
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
file|"gdbcore.h"
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

begin_comment
comment|/* Assorted operating system circumventions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYM1
end_ifdef

begin_comment
comment|/* FIXME: Kludge this for now. It really should be system call. */
end_comment

begin_function
name|int
name|getpagesize
parameter_list|()
block|{
return|return
operator|(
literal|8192
operator|)
return|;
block|}
end_function

begin_comment
comment|/* FIXME: Fake out the fcntl() call, which we don't have.  */
end_comment

begin_macro
name|fcntl
argument_list|(
argument|fd
argument_list|,
argument|cmd
argument_list|,
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|,
name|cmd
decl_stmt|,
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|F_GETFL
case|:
return|return
operator|(
name|O_RDONLY
operator|)
return|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Ultra3's fcntl() failing, cmd = %d.\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/*   * 4.2 Signal support, requires linking with libjobs.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|_SigMask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sigbit
parameter_list|(
name|s
parameter_list|)
value|(1L<< ((s)-1))
end_define

begin_macro
name|init_SigMask
argument_list|()
end_macro

begin_block
block|{
comment|/* Taken from the sym1 kernel in machdep.c:startup() */
name|_SigMask
operator|=
name|sigbit
argument_list|(
name|SIGTSTP
argument_list|)
operator||
name|sigbit
argument_list|(
name|SIGTTOU
argument_list|)
operator||
name|sigbit
argument_list|(
name|SIGTTIN
argument_list|)
operator||
name|sigbit
argument_list|(
name|SIGCHLD
argument_list|)
operator||
name|sigbit
argument_list|(
name|SIGTINT
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sigmask
argument_list|(
argument|signo
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signo
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|1
operator|<<
operator|(
name|signo
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_block

begin_macro
name|sigsetmask
argument_list|(
argument|sigmask
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|int
name|sigmask
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|mask
init|=
literal|1
decl_stmt|;
name|int
name|lastmask
init|=
name|_SigMask
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|sigmask
operator|&
name|mask
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|_SigMask
operator|&
name|mask
operator|)
condition|)
block|{
name|sighold
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
name|_SigMask
operator||=
name|mask
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|_SigMask
operator|&
name|mask
condition|)
block|{
name|sigrelse
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
name|_SigMask
operator|&=
operator|~
name|mask
expr_stmt|;
block|}
name|mask
operator|<<=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|lastmask
operator|)
return|;
block|}
end_block

begin_macro
name|sigblock
argument_list|(
argument|sigmask
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|int
name|sigmask
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|mask
init|=
literal|1
decl_stmt|;
name|int
name|lastmask
init|=
name|_SigMask
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|sigmask
operator|&
name|mask
operator|)
operator|&&
operator|!
operator|(
name|_SigMask
operator|&
name|mask
operator|)
condition|)
block|{
name|sighold
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
name|_SigMask
operator||=
name|mask
expr_stmt|;
block|}
name|mask
operator|<<=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|lastmask
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYM1 */
end_comment

begin_comment
comment|/* Initialization code for this module.  */
end_comment

begin_macro
name|_initialize_ultra3
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|SYM1
name|init_SigMask
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

