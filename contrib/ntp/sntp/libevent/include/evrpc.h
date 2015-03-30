begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT1_EVRPC_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT1_EVRPC_H_INCLUDED_
end_define

begin_comment
comment|/** @file evrpc.h    An RPC system for Libevent.    The<evrpc.h> header is deprecated in Libevent 2.0 and later; please   use<event2/rpc.h> instead.  Depending on what functionality you   need, you may also want to include more of the other<event2/...>   headers.  */
end_comment

begin_include
include|#
directive|include
file|<event.h>
end_include

begin_include
include|#
directive|include
file|<event2/rpc.h>
end_include

begin_include
include|#
directive|include
file|<event2/rpc_struct.h>
end_include

begin_include
include|#
directive|include
file|<event2/rpc_compat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT1_EVRPC_H_INCLUDED_ */
end_comment

end_unit

