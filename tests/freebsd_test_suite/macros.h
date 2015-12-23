begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 EMC / Isilon Storage Division  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FREEBSD_TEST_MACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FREEBSD_TEST_MACROS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_define
define|#
directive|define
name|ATF_REQUIRE_FEATURE
parameter_list|(
name|_feature_name
parameter_list|)
value|do {				\ 	if (feature_present(_feature_name) == 0) {			\ 		atf_tc_skip("kernel feature (%s) not present",		\ 		    _feature_name);					\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|ATF_REQUIRE_KERNEL_MODULE
parameter_list|(
name|_mod_name
parameter_list|)
value|do {			\ 	if (modfind(_mod_name) == -1) {					\ 		atf_tc_skip("module %s could not be resolved: %s",	\ 		    _mod_name, strerror(errno));			\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|PLAIN_REQUIRE_FEATURE
parameter_list|(
name|_feature_name
parameter_list|,
name|_exit_code
parameter_list|)
value|do {		\ 	if (feature_present(_feature_name) == 0) {			\ 		printf("kernel feature (%s) not present\n",		\ 		    _feature_name);					\ 		_exit(_exit_code);					\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|PLAIN_REQUIRE_KERNEL_MODULE
parameter_list|(
name|_mod_name
parameter_list|,
name|_exit_code
parameter_list|)
value|do {		\ 	if (modfind(_mod_name) == -1) {					\ 		printf("module %s could not be resolved: %s\n",		\ 		    _mod_name, strerror(errno));			\ 		_exit(_exit_code);					\ 	}								\ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

