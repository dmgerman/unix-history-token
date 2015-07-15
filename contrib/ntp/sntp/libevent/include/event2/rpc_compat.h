begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_RPC_COMPAT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_RPC_COMPAT_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/rpc_compat.h    Deprecated versions of the functions in rpc.h: provided only for   backwards compatibility.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/** backwards compatible accessors that work only with gcc */
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
undef|#
directive|undef
name|EVTAG_ASSIGN
undef|#
directive|undef
name|EVTAG_GET
undef|#
directive|undef
name|EVTAG_ADD
define|#
directive|define
name|EVTAG_ASSIGN
parameter_list|(
name|msg
parameter_list|,
name|member
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|(*(msg)->base->member##_assign)(msg, ## args)
define|#
directive|define
name|EVTAG_GET
parameter_list|(
name|msg
parameter_list|,
name|member
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|(*(msg)->base->member##_get)(msg, ## args)
define|#
directive|define
name|EVTAG_ADD
parameter_list|(
name|msg
parameter_list|,
name|member
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|(*(msg)->base->member##_add)(msg, ## args)
endif|#
directive|endif
define|#
directive|define
name|EVTAG_LEN
parameter_list|(
name|msg
parameter_list|,
name|member
parameter_list|)
value|((msg)->member##_length)
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT2_EVENT_COMPAT_H_INCLUDED_ */
end_comment

end_unit

