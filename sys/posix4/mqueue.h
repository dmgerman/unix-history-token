begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_MQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MQUEUE_H_
end_define

begin_comment
comment|/* mqueue.h: POSIX 1003.1b Message Queues */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/_posix.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_P1003_1B_INCLUDE_MAYBES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|sigevent
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|mqd_t
typedef|;
end_typedef

begin_comment
comment|/* message queue descriptors */
end_comment

begin_struct
struct|struct
name|mq_attr
block|{
name|long
name|mq_flags
decl_stmt|;
comment|/* message queue flags */
name|long
name|mq_maxmsg
decl_stmt|;
comment|/* maximum number of messages */
name|long
name|mq_msgsize
decl_stmt|;
comment|/* maximum message size */
name|long
name|mq_curmsgs
decl_stmt|;
comment|/* number of messages currently queued */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|mqd_t
name|mq_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
name|oflag
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_close
parameter_list|(
name|mqd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_unlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_send
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|mq_receive
parameter_list|(
name|mqd_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_notify
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|struct
name|sigevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_setattr
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|struct
name|mq_attr
modifier|*
parameter_list|,
name|struct
name|mq_attr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_getattr
parameter_list|(
name|mqd_t
parameter_list|,
name|struct
name|mq_attr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MQUEUE_H_ */
end_comment

end_unit

