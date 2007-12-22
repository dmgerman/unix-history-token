begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: mld6_var.h,v 1.4 2000/03/25 07:23:54 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_MLD6_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_MLD6_VAR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MLD_RANDOM_DELAY
parameter_list|(
name|X
parameter_list|)
value|(arc4random() % (X) + 1)
end_define

begin_comment
comment|/*  * States for MLD stop-listening processing  */
end_comment

begin_define
define|#
directive|define
name|MLD_OTHERLISTENER
value|0
end_define

begin_define
define|#
directive|define
name|MLD_IREPORTEDLAST
value|1
end_define

begin_define
define|#
directive|define
name|MLD_REPORTPENDING
value|2
end_define

begin_comment
comment|/* implementation specific */
end_comment

begin_function_decl
name|void
name|mld6_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld6_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld6_start_listening
parameter_list|(
name|struct
name|in6_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld6_stop_listening
parameter_list|(
name|struct
name|in6_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld6_fasttimeo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET6_MLD6_VAR_H_ */
end_comment

end_unit

