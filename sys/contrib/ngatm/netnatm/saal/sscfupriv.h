begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/saal/sscfupriv.h,v 1.3 2003/09/19 12:02:03 hbb Exp $  *  * Private SSCF-UNI definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<netgraph/atm/sscfu/ng_sscfu_cust.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"sscfucust.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure for signal queueing.  */
end_comment

begin_struct
struct|struct
name|sscfu_sig
block|{
name|sscfu_sigq_link_t
name|link
decl_stmt|;
comment|/* link to next signal */
name|enum
name|saal_sig
name|sig
decl_stmt|;
comment|/* the signal */
name|struct
name|SSCFU_MBUF_T
modifier|*
name|m
decl_stmt|;
comment|/* associated message */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sscfu
block|{
name|enum
name|sscfu_state
name|state
decl_stmt|;
comment|/* SSCF state */
specifier|const
name|struct
name|sscfu_funcs
modifier|*
name|funcs
decl_stmt|;
comment|/* func vector */
name|void
modifier|*
name|aarg
decl_stmt|;
comment|/* user arg */
name|int
name|inhand
decl_stmt|;
comment|/* need to queue signals */
name|sscfu_sigq_head_t
name|sigs
decl_stmt|;
comment|/* signal queue */
name|u_int
name|debug
decl_stmt|;
comment|/* debugging flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debugging  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SSCFU_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|F
parameter_list|)
value|if ((S)->debug& (M)) (S)->funcs->verbose F
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|F
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

