begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technologies, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: lomac.c,v 1.3 2001/11/26 21:04:04 bfeldman Exp $  */
end_comment

begin_comment
comment|/*  * This file encapsulates ls's use of LOMAC's ioctl interface.  ls uses  * this interface to determine the LOMAC attributes of files.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/lomacio.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"lomac.h"
end_include

begin_define
define|#
directive|define
name|LOMAC_DEVICE
value|"/dev/lomac"
end_define

begin_decl_stmt
specifier|static
name|int
name|devlomac
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for LOMAC_DEVICE */
end_comment

begin_comment
comment|/* lomac_start()  *  * in:     nothing  * out:    nothing  * return: nothing  *  * Makes `devlomac' a fd to LOMAC_DEVICE  */
end_comment

begin_function
specifier|static
name|void
name|lomac_start
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|(
name|devlomac
operator|=
name|open
argument_list|(
name|LOMAC_DEVICE
argument_list|,
name|O_RDWR
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"cannot open %s"
argument_list|,
name|LOMAC_DEVICE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* lomac_stop()  *  * in:     nothing  * out:    nothing  * return: nothing  *  * Closes `devlomac', the fd to LOMAC_DEVICE.  */
end_comment

begin_function
name|void
name|lomac_stop
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|devlomac
operator|!=
operator|-
literal|1
operator|&&
name|close
argument_list|(
name|devlomac
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"cannot close %s"
argument_list|,
name|LOMAC_DEVICE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* get_lattr()  *  * in:     pid - pid of process whose level we want to know  * out:    nothing  * return: level of proces `pid'  *  * This function uses LOMAC's ioctl interface to determine the LOMAC  * attributes of the process with pid `pid'.  *  * This function presently reports only levels.  When LOMAC's ioctl  * interface is expanded to report levels and flags, this function  * will also need expansion.  */
end_comment

begin_function
name|int
name|get_lattr
parameter_list|(
name|int
name|pid
parameter_list|)
block|{
if|if
condition|(
name|devlomac
operator|==
operator|-
literal|1
condition|)
name|lomac_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|devlomac
argument_list|,
name|LIOGETPLEVEL
argument_list|,
operator|&
name|pid
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
name|pid
operator|)
return|;
block|}
end_function

end_unit

