begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1993, 1997 Free Software Foundation, Inc.    This file is part of the GNU IO Library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this library; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.     As a special exception, if you link this library with files    compiled with a GNU compiler to produce an executable, this does    not cause the resulting executable to be covered by the GNU General    Public License.  This exception does not however invalidate any    other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/* Modified for GNU iostream by Per Bothner 1991, 1992. */
end_comment

begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_undef
undef|#
directive|undef
name|isatty
end_undef

begin_define
define|#
directive|define
name|isatty
parameter_list|(
name|Fd
parameter_list|)
value|__isatty (Fd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Allocate a file buffer, or switch to unbuffered I/O.  * Per the ANSI C standard, ALL tty devices default to line buffered.  *  * As a side effect, we set __SOPT or __SNPT (en/dis-able fseek  * optimisation) right after the _fstat() that finds the buffer size.  */
end_comment

begin_function
name|int
name|_IO_file_doallocate
parameter_list|(
name|fp
parameter_list|)
name|_IO_FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|_IO_size_t
name|size
decl_stmt|;
name|int
name|couldbetty
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|struct
name|stat
name|st
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
comment|/* If _IO_cleanup_registration_needed is non-zero, we should call the      function it points to.  This is to make sure _IO_cleanup gets called      on exit.  We call it from _IO_file_doallocate, since that is likely      to get called by any program that does buffered I/O. */
if|if
condition|(
name|_IO_cleanup_registration_needed
condition|)
call|(
modifier|*
name|_IO_cleanup_registration_needed
call|)
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fp
operator|->
name|_fileno
operator|<
literal|0
operator|||
name|_IO_SYSSTAT
argument_list|(
name|fp
argument_list|,
operator|&
name|st
argument_list|)
operator|<
literal|0
condition|)
block|{
name|couldbetty
operator|=
literal|0
expr_stmt|;
name|size
operator|=
name|_IO_BUFSIZ
expr_stmt|;
if|#
directive|if
literal|0
comment|/* do not try to optimise fseek() */
block|fp->_flags |= __SNPT;
endif|#
directive|endif
block|}
else|else
block|{
name|couldbetty
operator|=
name|S_ISCHR
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
expr_stmt|;
if|#
directive|if
name|_IO_HAVE_ST_BLKSIZE
name|size
operator|=
name|st
operator|.
name|st_blksize
operator|<=
literal|0
condition|?
name|_IO_BUFSIZ
else|:
name|st
operator|.
name|st_blksize
expr_stmt|;
else|#
directive|else
name|size
operator|=
name|_IO_BUFSIZ
expr_stmt|;
endif|#
directive|endif
block|}
name|ALLOC_BUF
argument_list|(
name|p
argument_list|,
name|size
argument_list|,
name|EOF
argument_list|)
expr_stmt|;
name|_IO_setb
argument_list|(
name|fp
argument_list|,
name|p
argument_list|,
name|p
operator|+
name|size
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|couldbetty
operator|&&
name|isatty
argument_list|(
name|fp
operator|->
name|_fileno
argument_list|)
condition|)
name|fp
operator|->
name|_flags
operator||=
name|_IO_LINE_BUF
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

