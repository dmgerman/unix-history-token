begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Version of sigsetmask.c    Copyright 1991, 1992 Free Software Foundation, Inc.    Written by Steve Chamberlain (sac@cygnus.com).    Contributed by Cygnus Support.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Set the current signal mask to the set provided, and return the     previous value */
end_comment

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_SETMASK
end_ifdef

begin_decl_stmt
name|int
name|DEFUN
argument_list|(
name|sigsetmask
argument_list|,
operator|(
name|set
operator|)
argument_list|,
name|int
name|set
argument_list|)
block|{
name|sigset_t
name|new
decl_stmt|;
name|sigset_t
name|old
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|new
argument_list|)
expr_stmt|;
if|if
condition|(
name|set
operator|!=
literal|0
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
comment|/* FIXME, we don't know how to translate old mask to new */
block|}
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|new
argument_list|,
operator|&
name|old
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* FIXME, we always return 1 as old value.  */
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

