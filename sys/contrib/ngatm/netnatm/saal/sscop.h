begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/saal/sscop.h,v 1.4 2004/07/08 08:22:16 brandt Exp $  *  * External interface to sscop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_SAAL_SSCOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_SAAL_SSCOP_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/saal/sscopdef.h>
end_include

begin_comment
comment|/*  * Define how a buffer looks like.  */
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

begin_define
define|#
directive|define
name|SSCOP_MBUF_T
value|mbuf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSCOP_MBUF_T
value|uni_msg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|SSCOP_MBUF_T
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sscop
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Vector for user functions  */
end_comment

begin_struct
struct|struct
name|sscop_funcs
block|{
comment|/* management signal from SSCOP */
name|void
function_decl|(
modifier|*
name|send_manage
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|sscop_maasig
parameter_list|,
name|struct
name|SSCOP_MBUF_T
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
comment|/* AAL signal from SSCOP */
name|void
function_decl|(
modifier|*
name|send_upper
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|sscop_aasig
parameter_list|,
name|struct
name|SSCOP_MBUF_T
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
comment|/* send a PDU to the wire */
name|void
function_decl|(
modifier|*
name|send_lower
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|SSCOP_MBUF_T
modifier|*
parameter_list|)
function_decl|;
comment|/* print a message */
name|void
function_decl|(
modifier|*
name|verbose
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
block|)
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* start a timer */
end_comment

begin_function_decl
name|void
modifier|*
function_decl|(
modifier|*
name|start_timer
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stop a timer */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|stop_timer
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|/* Function defined by the SSCOP code */
end_comment

begin_comment
comment|/* create a new SSCOP instance and initialize to default values */
end_comment

begin_function_decl
name|struct
name|sscop
modifier|*
name|sscop_create
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|sscop_funcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy an SSCOP instance */
end_comment

begin_function_decl
name|void
name|sscop_destroy
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get the current parameters of an SSCOP */
end_comment

begin_function_decl
name|void
name|sscop_getparam
parameter_list|(
specifier|const
name|struct
name|sscop
modifier|*
parameter_list|,
name|struct
name|sscop_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set new parameters in an SSCOP */
end_comment

begin_function_decl
name|int
name|sscop_setparam
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|struct
name|sscop_param
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* deliver an signal to the SSCOP */
end_comment

begin_function_decl
name|int
name|sscop_aasig
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|enum
name|sscop_aasig
parameter_list|,
name|struct
name|SSCOP_MBUF_T
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* deliver an management signal to the SSCOP */
end_comment

begin_function_decl
name|int
name|sscop_maasig
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|enum
name|sscop_maasig
parameter_list|,
name|struct
name|SSCOP_MBUF_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SSCOP input function */
end_comment

begin_function_decl
name|void
name|sscop_input
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|struct
name|SSCOP_MBUF_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Move the window by a given number of messages. Return the new window */
end_comment

begin_function_decl
name|u_int
name|sscop_window
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* declare the lower layer busy or not busy */
end_comment

begin_function_decl
name|u_int
name|sscop_setbusy
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* retrieve the state */
end_comment

begin_function_decl
name|enum
name|sscop_state
name|sscop_getstate
parameter_list|(
specifier|const
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* map signals to strings */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|sscop_msigname
parameter_list|(
name|enum
name|sscop_maasig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|sscop_signame
parameter_list|(
name|enum
name|sscop_aasig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|sscop_statename
parameter_list|(
name|enum
name|sscop_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set/get debugging state */
end_comment

begin_function_decl
name|void
name|sscop_setdebug
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|sscop_getdebug
parameter_list|(
specifier|const
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reset the instance */
end_comment

begin_function_decl
name|void
name|sscop_reset
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

