begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 nCircle Network Security, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson for the TrustedBSD  * Project under contract to nCircle Network Security, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR, NCIRCLE NETWORK SECURITY,  * INC., OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Test that sysctls can only be written with privilege by trying first with,  * then without privilege.  Do this by first reading, then setting the  * hostname as a no-op.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"main.h"
end_include

begin_define
define|#
directive|define
name|KERN_HOSTNAME_STRING
value|"kern.hostname"
end_define

begin_function
name|void
name|priv_sysctl_write
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|int
name|error
decl_stmt|;
name|assert_root
argument_list|()
expr_stmt|;
comment|/* 	 * First query the current value. 	 */
name|len
operator|=
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|error
operator|=
name|sysctlbyname
argument_list|(
name|KERN_HOSTNAME_STRING
argument_list|,
name|buffer
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"sysctlbyname(\"%s\") query"
argument_list|,
name|KERN_HOSTNAME_STRING
argument_list|)
expr_stmt|;
comment|/* 	 * Now try to set with privilege. 	 */
name|error
operator|=
name|sysctlbyname
argument_list|(
name|KERN_HOSTNAME_STRING
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|buffer
argument_list|,
name|strlen
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"sysctlbyname(\"%s\") set as root"
argument_list|,
name|KERN_HOSTNAME_STRING
argument_list|)
expr_stmt|;
comment|/* 	 * Now without privilege. 	 */
name|set_euid
argument_list|(
name|UID_OTHER
argument_list|)
expr_stmt|;
name|error
operator|=
name|sysctlbyname
argument_list|(
name|KERN_HOSTNAME_STRING
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|buffer
argument_list|,
name|strlen
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
name|errx
argument_list|(
operator|-
literal|1
argument_list|,
literal|"sysctlbyname(\"%s\") succeeded as !root"
argument_list|,
name|KERN_HOSTNAME_STRING
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
name|EPERM
condition|)
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"sysctlbyname(\"%s\") wrong errno %d"
argument_list|,
name|KERN_HOSTNAME_STRING
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

