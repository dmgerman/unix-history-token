begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_l1l2.h - i4b layer 1 / layer 2 interactions  *	---------------------------------------------------  *  *	$Id: i4b_l1l2.h,v 1.11 2000/06/02 16:14:35 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Fri Jun  2 14:35:03 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_L1L2_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_L1L2_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/i4b_trace.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i4b/i4b_trace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|i4b_l1l2_func
name|i4b_l1l2_func
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|i4b_l1l2_func
block|{
comment|/* Layer 1 --> Layer 2 */
comment|/* =================== */
name|int
function_decl|(
modifier|*
name|PH_DATA_IND
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|PH_ACTIVATE_IND
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|PH_DEACTIVATE_IND
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
define|#
directive|define
name|PH_Data_Ind
parameter_list|(
name|unit
parameter_list|,
name|data
parameter_list|)
define|\
value|((*i4b_l1l2_func.PH_DATA_IND)(unit, data))
define|#
directive|define
name|PH_Act_Ind
parameter_list|(
name|unit
parameter_list|)
define|\
value|((*i4b_l1l2_func.PH_ACTIVATE_IND)(unit))
define|#
directive|define
name|PH_Deact_Ind
parameter_list|(
name|unit
parameter_list|)
define|\
value|((*i4b_l1l2_func.PH_DEACTIVATE_IND)(unit))
comment|/* Layer 2 --> Layer 1 */
comment|/* =================== */
name|int
function_decl|(
modifier|*
name|PH_DATA_REQ
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|PH_ACTIVATE_REQ
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
define|#
directive|define
name|PH_Data_Req
parameter_list|(
name|unit
parameter_list|,
name|data
parameter_list|,
name|freeflag
parameter_list|)
define|\
value|((*i4b_l1l2_func.PH_DATA_REQ)(unit, data, freeflag))
define|#
directive|define
name|PH_Act_Req
parameter_list|(
name|unit
parameter_list|)
define|\
value|((*i4b_l1l2_func.PH_ACTIVATE_REQ)(unit))
comment|/* Layer 1 --> upstream, ISDN trace data */
comment|/* ===================================== */
name|int
function_decl|(
modifier|*
name|MPH_TRACE_IND
function_decl|)
parameter_list|(
name|i4b_trace_hdr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|MPH_Trace_Ind
parameter_list|(
name|header
parameter_list|,
name|length
parameter_list|,
name|pointer
parameter_list|)
define|\
value|((*i4b_l1l2_func.MPH_TRACE_IND)(header, length, pointer))
comment|/* L1/L2 management command and status information */
comment|/* =============================================== */
name|int
function_decl|(
modifier|*
name|MPH_STATUS_IND
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|MPH_COMMAND_REQ
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|MPH_Status_Ind
parameter_list|(
name|unit
parameter_list|,
name|status
parameter_list|,
name|parm
parameter_list|)
define|\
value|((*i4b_l1l2_func.MPH_STATUS_IND)(unit, status, parm))
define|#
directive|define
name|MPH_Command_Req
parameter_list|(
name|unit
parameter_list|,
name|command
parameter_list|,
name|parm
parameter_list|)
define|\
value|((*i4b_l1l2_func.MPH_COMMAND_REQ)(unit, command, parm))
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_L1L2_H_ */
end_comment

end_unit

