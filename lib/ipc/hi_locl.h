begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETPEERUCRED
end_ifdef

begin_include
include|#
directive|include
file|<ucred.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_include
include|#
directive|include
file|<asn1-common.h>
end_include

begin_include
include|#
directive|include
file|<heimbase.h>
end_include

begin_include
include|#
directive|include
file|<base64.h>
end_include

begin_include
include|#
directive|include
file|<heim-ipc.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GCD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_include
include|#
directive|include
file|<servers/bootstrap.h>
end_include

begin_include
include|#
directive|include
file|<dispatch/dispatch.h>
end_include

begin_include
include|#
directive|include
file|<bsm/libbsm.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__APPLE_PRIVATE__
end_ifndef

begin_comment
comment|/* awe, using private interface */
end_comment

begin_typedef
typedef|typedef
name|boolean_t
function_decl|(
modifier|*
name|dispatch_mig_callback_t
function_decl|)
parameter_list|(
name|mach_msg_header_t
modifier|*
name|message
parameter_list|,
name|mach_msg_header_t
modifier|*
name|reply
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|mach_msg_return_t
name|dispatch_mig_server
parameter_list|(
name|dispatch_source_t
name|ds
parameter_list|,
name|size_t
name|maxmsgsz
parameter_list|,
name|dispatch_mig_callback_t
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_function_decl
name|int
name|_heim_ipc_create_cred
parameter_list|(
name|uid_t
parameter_list|,
name|gid_t
parameter_list|,
name|pid_t
parameter_list|,
name|pid_t
parameter_list|,
name|heim_icred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

