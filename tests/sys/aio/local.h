begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Chelsio Communications, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AIO_TEST_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIO_TEST_LOCAL_H_
end_define

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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<atf-c.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|sysctl_oid_name
init|=
literal|"vfs.aio.enable_unsafe"
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|is_unsafe_aio_enabled
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|len
decl_stmt|;
name|int
name|unsafe
decl_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|unsafe
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctlbyname
argument_list|(
name|sysctl_oid_name
argument_list|,
operator|&
name|unsafe
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|ENOENT
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|unsafe
operator|==
literal|0
condition|?
literal|0
else|:
literal|1
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ATF_REQUIRE_UNSAFE_AIO
parameter_list|()
value|do {						\ 	switch (is_unsafe_aio_enabled()) {					\ 	case -1:								\ 		atf_libc_error(errno, "Failed to read %s", sysctl_oid_name);	\ 		break;								\ 	case 0:									\ 		atf_tc_skip("Unsafe AIO is disabled");				\ 		break;								\ 	default:								\ 		printf("Unsafe AIO is enabled\n");				\ 		break;								\ 	}									\ } while (0)
end_define

begin_define
define|#
directive|define
name|PLAIN_REQUIRE_UNSAFE_AIO
parameter_list|(
name|_exit_code
parameter_list|)
value|do {				\ 	switch (is_unsafe_aio_enabled()) {					\ 	case -1:								\ 		printf("Failed to read %s", sysctl_oid_name);			\ 		_exit(_exit_code);						\ 		break;								\ 	case 0:									\ 		printf("Unsafe AIO is disabled\n");				\ 		_exit(_exit_code);						\ 		break;								\ 	default:								\ 		printf("Unsafe AIO is enabled\n");				\ 		break;								\ 	}									\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AIO_TEST_LOCAL_H_ */
end_comment

end_unit

