begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_rnd.c,v 1.5 2012/03/18 09:46:50 jruoho Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2009 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_rnd.c,v 1.5 2012/03/18 09:46:50 jruoho Exp $"
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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/rnd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump_syscalls.h>
end_include

begin_include
include|#
directive|include
file|"../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|RNDADDDATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|RNDADDDATA
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks ioctl(RNDADDDATA) (PR kern/42020)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Adapted from example provided by Juho Salminen in the noted PR. */
end_comment

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|RNDADDDATA
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|rnddata_t
name|rd
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
name|fd
operator|=
name|rump_sys_open
argument_list|(
literal|"/dev/random"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"cannot open /dev/random"
argument_list|)
expr_stmt|;
name|rd
operator|.
name|entropy
operator|=
literal|1
expr_stmt|;
name|rd
operator|.
name|len
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|rump_sys_ioctl
argument_list|(
name|fd
argument_list|,
name|RNDADDDATA
argument_list|,
operator|&
name|rd
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"RNDADDDATA"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|RNDADDDATA2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|RNDADDDATA2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"checks ioctl(RNDADDDATA) deals with "
literal|"garbage len field"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|RNDADDDATA2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|rnddata_t
name|rd
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
name|fd
operator|=
name|rump_sys_open
argument_list|(
literal|"/dev/random"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"cannot open /dev/random"
argument_list|)
expr_stmt|;
name|rd
operator|.
name|entropy
operator|=
literal|1
expr_stmt|;
name|rd
operator|.
name|len
operator|=
operator|-
literal|1
expr_stmt|;
name|ATF_REQUIRE_ERRNO
argument_list|(
name|EINVAL
argument_list|,
name|rump_sys_ioctl
argument_list|(
name|fd
argument_list|,
name|RNDADDDATA
argument_list|,
operator|&
name|rd
argument_list|)
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|RNDADDDATA
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|RNDADDDATA2
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

