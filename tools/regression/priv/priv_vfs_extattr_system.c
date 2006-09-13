begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 nCircle Network Security, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson for the TrustedBSD  * Project under contract to nCircle Network Security, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR, NCIRCLE NETWORK SECURITY,  * INC., OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Test that privilege is required to write to the system extended attribute  * namespace.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/extattr.h>
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
name|EA_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|EA_NAME
value|"test"
end_define

begin_define
define|#
directive|define
name|EA_DATA
value|"test"
end_define

begin_define
define|#
directive|define
name|EA_SIZE
value|strlen(EA_DATA)
end_define

begin_function
name|void
name|priv_vfs_extattr_system
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|fpath
index|[
literal|1024
index|]
decl_stmt|;
name|int
name|error
decl_stmt|;
name|assert_root
argument_list|()
expr_stmt|;
comment|/* 	 * Set file perms so that discretionary access control would grant 	 * write rights on non-system EAs on the file. 	 */
name|setup_file
argument_list|(
name|fpath
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0666
argument_list|)
expr_stmt|;
comment|/* 	 * Try with privilege. 	 */
if|if
condition|(
name|extattr_set_file
argument_list|(
name|fpath
argument_list|,
name|EA_NAMESPACE
argument_list|,
name|EA_NAME
argument_list|,
name|EA_DATA
argument_list|,
name|EA_SIZE
argument_list|)
operator|<
literal|0
condition|)
block|{
name|warn
argument_list|(
literal|"extattr_set_file(SYSTEM, %s, %s, %d) as root"
argument_list|,
name|EA_NAME
argument_list|,
name|EA_DATA
argument_list|,
name|EA_SIZE
argument_list|)
expr_stmt|;
goto|goto
name|out
goto|;
block|}
name|set_euid
argument_list|(
name|UID_OTHER
argument_list|)
expr_stmt|;
comment|/* 	 * Try without privilege. 	 */
name|error
operator|=
name|extattr_set_file
argument_list|(
name|fpath
argument_list|,
name|EA_NAMESPACE
argument_list|,
name|EA_NAME
argument_list|,
name|EA_DATA
argument_list|,
name|EA_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
block|{
name|warn
argument_list|(
literal|"extattr_set_file(SYSTEM, %s, %s, %d) succeeded as !root"
argument_list|,
name|EA_NAME
argument_list|,
name|EA_DATA
argument_list|,
name|EA_SIZE
argument_list|)
expr_stmt|;
goto|goto
name|out
goto|;
block|}
if|if
condition|(
name|errno
operator|!=
name|EPERM
condition|)
block|{
name|warn
argument_list|(
literal|"extattr_set_file(SYSTEM, %s, %s, %d) wrong errno %d "
literal|"as !root"
argument_list|,
name|EA_NAME
argument_list|,
name|EA_DATA
argument_list|,
name|EA_SIZE
argument_list|,
name|errno
argument_list|)
expr_stmt|;
goto|goto
name|out
goto|;
block|}
name|out
label|:
name|seteuid
argument_list|(
name|UID_ROOT
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|fpath
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

