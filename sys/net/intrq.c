begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/intrq.h>
end_include

begin_comment
comment|/*  * If the appropriate intrq_present variable is zero, don't use  * the queue (as it'll never get processed).  * When defined, each of the network stacks declares their own  * *intrq_present variable to be non-zero.  */
end_comment

begin_decl_stmt
specifier|const
name|int
name|atintrq1_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|atintrq2_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|atmintrq_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ipintrq_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ip6intrq_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ipxintrq_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|natmintrq_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|nsintrq_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|atintrq1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|atintrq2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|atm_intrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|ip6intrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|ipxintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|natmintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|nsintrq
decl_stmt|;
end_decl_stmt

end_unit

