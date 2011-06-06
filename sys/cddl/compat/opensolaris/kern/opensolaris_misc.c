begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/jail.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/misc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_decl_stmt
name|char
name|hw_serial
index|[
literal|11
index|]
init|=
literal|"0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|opensolaris_utsname
name|utsname
init|=
block|{
operator|.
name|machine
operator|=
name|MACHINE
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|opensolaris_utsname_init
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|utsname
operator|.
name|sysname
operator|=
name|ostype
expr_stmt|;
name|utsname
operator|.
name|nodename
operator|=
name|prison0
operator|.
name|pr_hostname
expr_stmt|;
name|utsname
operator|.
name|release
operator|=
name|osrelease
expr_stmt|;
name|snprintf
argument_list|(
name|utsname
operator|.
name|version
argument_list|,
sizeof|sizeof
argument_list|(
name|utsname
operator|.
name|version
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
name|osreldate
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|opensolaris_utsname_init
argument_list|,
name|SI_SUB_TUNABLES
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|opensolaris_utsname_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

