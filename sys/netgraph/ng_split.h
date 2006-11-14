begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  * Copyright (c) 1999-2000, Vitaly V Belekhov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_SPLIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_SPLIT_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_SPLIT_NODE_TYPE
value|"split"
end_define

begin_define
define|#
directive|define
name|NGM_SPLIT_COOKIE
value|949409402
end_define

begin_comment
comment|/* My hook names */
end_comment

begin_define
define|#
directive|define
name|NG_SPLIT_HOOK_MIXED
value|"mixed"
end_define

begin_comment
comment|/* Mixed stream (in/out) */
end_comment

begin_define
define|#
directive|define
name|NG_SPLIT_HOOK_OUT
value|"out"
end_define

begin_comment
comment|/* Output to outhook (sending out) */
end_comment

begin_define
define|#
directive|define
name|NG_SPLIT_HOOK_IN
value|"in"
end_define

begin_comment
comment|/* Input from inhook (recieving) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_SPLIT_H_ */
end_comment

end_unit

