begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/saal/sscopdef.h,v 1.4 2004/07/08 08:22:17 brandt Exp $  *  * Definitions of SSCOP constants and parameter blocks. This is seen by  * the outside world.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_SAAL_SSCOPDEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_SAAL_SSCOPDEF_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * AA-interface signals  */
end_comment

begin_enum
enum|enum
name|sscop_aasig
block|{
name|SSCOP_ESTABLISH_request
block|,
comment|/*<- UU, BR */
name|SSCOP_ESTABLISH_indication
block|,
comment|/* -> UU */
name|SSCOP_ESTABLISH_response
block|,
comment|/*<- UU, BR */
name|SSCOP_ESTABLISH_confirm
block|,
comment|/* -> UU */
name|SSCOP_RELEASE_request
block|,
comment|/*<- UU */
name|SSCOP_RELEASE_indication
block|,
comment|/* -> UU, SRC */
name|SSCOP_RELEASE_confirm
block|,
comment|/* -> */
name|SSCOP_DATA_request
block|,
comment|/*<- MU */
name|SSCOP_DATA_indication
block|,
comment|/* -> MU, SN */
name|SSCOP_UDATA_request
block|,
comment|/*<- MU */
name|SSCOP_UDATA_indication
block|,
comment|/* -> MU */
name|SSCOP_RECOVER_indication
block|,
comment|/* -> */
name|SSCOP_RECOVER_response
block|,
comment|/*<- */
name|SSCOP_RESYNC_request
block|,
comment|/*<- UU */
name|SSCOP_RESYNC_indication
block|,
comment|/* -> UU */
name|SSCOP_RESYNC_response
block|,
comment|/*<- */
name|SSCOP_RESYNC_confirm
block|,
comment|/* -> */
name|SSCOP_RETRIEVE_request
block|,
comment|/*<- RN */
name|SSCOP_RETRIEVE_indication
block|,
comment|/* -> MU */
name|SSCOP_RETRIEVE_COMPL_indication
block|,
comment|/* -> */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sscop_maasig
block|{
name|SSCOP_MDATA_request
block|,
comment|/*<- MU */
name|SSCOP_MDATA_indication
block|,
comment|/* -> MU */
name|SSCOP_MERROR_indication
block|,
comment|/* -> CODE, CNT */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Values for retrieval. Numbers in SSCOP are 24bit, so  * we can use the large values  */
end_comment

begin_enum
enum|enum
block|{
name|SSCOP_MAXSEQNO
init|=
literal|0xffffff
block|,
name|SSCOP_RETRIEVE_UNKNOWN
init|=
name|SSCOP_MAXSEQNO
operator|+
literal|1
block|,
name|SSCOP_RETRIEVE_TOTAL
init|=
name|SSCOP_MAXSEQNO
operator|+
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/*  * SSCOP states  */
end_comment

begin_enum
enum|enum
name|sscop_state
block|{
name|SSCOP_IDLE
block|,
comment|/* initial state */
name|SSCOP_OUT_PEND
block|,
comment|/* outgoing connection pending */
name|SSCOP_IN_PEND
block|,
comment|/* incoming connection pending */
name|SSCOP_OUT_DIS_PEND
block|,
comment|/* outgoing disconnect pending */
name|SSCOP_OUT_RESYNC_PEND
block|,
comment|/* outgoing resynchronisation pending */
name|SSCOP_IN_RESYNC_PEND
block|,
comment|/* incoming resynchronisation pending */
name|SSCOP_OUT_REC_PEND
block|,
comment|/* outgoing recovery pending */
name|SSCOP_REC_PEND
block|,
comment|/* recovery response pending */
name|SSCOP_IN_REC_PEND
block|,
comment|/* incoming recovery pending */
name|SSCOP_READY
block|,
comment|/* data transfer ready */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SSCOP_NSTATES
value|10
end_define

begin_struct
struct|struct
name|sscop_param
block|{
name|uint32_t
name|timer_cc
decl_stmt|;
comment|/* timer_cc in msec */
name|uint32_t
name|timer_poll
decl_stmt|;
comment|/* timer_poll im msec */
name|uint32_t
name|timer_keep_alive
decl_stmt|;
comment|/* timer_keep_alive in msec */
name|uint32_t
name|timer_no_response
decl_stmt|;
comment|/*timer_no_response in msec */
name|uint32_t
name|timer_idle
decl_stmt|;
comment|/* timer_idle in msec */
name|uint32_t
name|maxk
decl_stmt|;
comment|/* maximum user data in bytes */
name|uint32_t
name|maxj
decl_stmt|;
comment|/* maximum u-u info in bytes */
name|uint32_t
name|maxcc
decl_stmt|;
comment|/* max. retransmissions for control packets */
name|uint32_t
name|maxpd
decl_stmt|;
comment|/* max. vt(pd) before sending poll */
name|uint32_t
name|maxstat
decl_stmt|;
comment|/* max. number of elements in stat list */
name|uint32_t
name|mr
decl_stmt|;
comment|/* initial window */
name|uint32_t
name|flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|SSCOP_ROBUST
init|=
literal|0x0001
block|,
comment|/* atmf/97-0216 robustness */
name|SSCOP_POLLREX
init|=
literal|0x0002
block|,
comment|/* send POLL after retransmit */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SSCOP_SET_TCC
init|=
literal|0x0001
block|,
name|SSCOP_SET_TPOLL
init|=
literal|0x0002
block|,
name|SSCOP_SET_TKA
init|=
literal|0x0004
block|,
name|SSCOP_SET_TNR
init|=
literal|0x0008
block|,
name|SSCOP_SET_TIDLE
init|=
literal|0x0010
block|,
name|SSCOP_SET_MAXK
init|=
literal|0x0020
block|,
name|SSCOP_SET_MAXJ
init|=
literal|0x0040
block|,
name|SSCOP_SET_MAXCC
init|=
literal|0x0080
block|,
name|SSCOP_SET_MAXPD
init|=
literal|0x0100
block|,
name|SSCOP_SET_MAXSTAT
init|=
literal|0x0200
block|,
name|SSCOP_SET_MR
init|=
literal|0x0400
block|,
name|SSCOP_SET_ROBUST
init|=
literal|0x0800
block|,
name|SSCOP_SET_POLLREX
init|=
literal|0x1000
block|,
name|SSCOP_SET_ALLMASK
init|=
literal|0x1fff
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SSCOP_DBG_USIG
init|=
literal|0x0001
block|,
name|SSCOP_DBG_TIMER
init|=
literal|0x0002
block|,
name|SSCOP_DBG_BUG
init|=
literal|0x0004
block|,
name|SSCOP_DBG_INSIG
init|=
literal|0x0008
block|,
name|SSCOP_DBG_STATE
init|=
literal|0x0010
block|,
name|SSCOP_DBG_PDU
init|=
literal|0x0020
block|,
name|SSCOP_DBG_ERR
init|=
literal|0x0040
block|,
name|SSCOP_DBG_EXEC
init|=
literal|0x0080
block|,
name|SSCOP_DBG_FLOW
init|=
literal|0x0100
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

