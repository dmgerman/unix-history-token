begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 LSIIT Laboratory.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|DEBUG_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_nmsgs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|log_fp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IF_DEBUG
parameter_list|(
name|l
parameter_list|)
value|if (debug&& debug& (l))
end_define

begin_define
define|#
directive|define
name|LOG_MAX_MSGS
value|20
end_define

begin_comment
comment|/* if> 20/minute then shut up for a while */
end_comment

begin_define
define|#
directive|define
name|LOG_SHUT_UP
value|600
end_define

begin_comment
comment|/* shut up for 10 minutes */
end_comment

begin_comment
comment|/* Debug values definition */
end_comment

begin_comment
comment|/* DVMRP reserved for future use */
end_comment

begin_define
define|#
directive|define
name|DEBUG_DVMRP_PRUNE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_ROUTE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_PEER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_TIMER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_DETAIL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP
value|( DEBUG_DVMRP_PRUNE | DEBUG_DVMRP_ROUTE | \ 				DEBUG_DVMRP_PEER )
end_define

begin_comment
comment|/* MLD related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MLD_PROTO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DEBUG_MLD_TIMER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DEBUG_MLD_MEMBER
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DEBUG_MEMBER
value|DEBUG_MLD_MEMBER
end_define

begin_define
define|#
directive|define
name|DEBUG_MLD
value|( DEBUG_MLD_PROTO | DEBUG_MLD_TIMER | \ 				DEBUG_MLD_MEMBER )
end_define

begin_comment
comment|/* Misc */
end_comment

begin_define
define|#
directive|define
name|DEBUG_TRACE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DEBUG_TIMEOUT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DEBUG_PKT
value|0x00000200
end_define

begin_comment
comment|/* Kernel related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_IF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DEBUG_KERN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DEBUG_MFC
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DEBUG_RSRR
value|0x00002000
end_define

begin_comment
comment|/* PIM related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PIM_HELLO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_REGISTER
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_JOIN_PRUNE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_BOOTSTRAP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_ASSERT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_CAND_RP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_MRT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_TIMER
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_RPF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DEBUG_RPF
value|DEBUG_PIM_RPF
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_DETAIL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM
value|( DEBUG_PIM_HELLO | DEBUG_PIM_REGISTER | \ 				DEBUG_PIM_JOIN_PRUNE | DEBUG_PIM_BOOTSTRAP | \ 				DEBUG_PIM_ASSERT | DEBUG_PIM_CAND_RP | \ 				DEBUG_PIM_MRT | DEBUG_PIM_TIMER | \ 				DEBUG_PIM_RPF )
end_define

begin_define
define|#
directive|define
name|DEBUG_MRT
value|( DEBUG_DVMRP_ROUTE | DEBUG_PIM_MRT )
end_define

begin_define
define|#
directive|define
name|DEBUG_NEIGHBORS
value|( DEBUG_DVMRP_PEER | DEBUG_PIM_HELLO )
end_define

begin_define
define|#
directive|define
name|DEBUG_TIMER
value|( DEBUG_MLD_TIMER | DEBUG_DVMRP_TIMER | \ 				DEBUG_PIM_TIMER )
end_define

begin_define
define|#
directive|define
name|DEBUG_ASSERT
value|( DEBUG_PIM_ASSERT )
end_define

begin_comment
comment|/* CONFIG related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_CONF
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DEBUG_ALL
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|DEBUG_SWITCH
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DEBUG_DEFAULT
value|0xffffffff
end_define

begin_comment
comment|/*  default if "-d" given without value */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YIPS_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|YIPSDEBUG
parameter_list|(
name|lev
parameter_list|,
name|arg
parameter_list|)
value|if ((debug& (lev)) == (lev)) { arg; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YIPSDEBUG
parameter_list|(
name|lev
parameter_list|,
name|arg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(YIPS_DEBUG) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|packet_kind
name|__P
argument_list|(
operator|(
name|u_int
name|proto
operator|,
name|u_int
name|type
operator|,
name|u_int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug_kind
name|__P
argument_list|(
operator|(
name|u_int
name|proto
operator|,
name|u_int
name|type
operator|,
name|u_int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|log
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_level
name|__P
argument_list|(
operator|(
name|u_int
name|proto
operator|,
name|u_int
name|type
operator|,
name|u_int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump
name|__P
argument_list|(
operator|(
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fdump
name|__P
argument_list|(
operator|(
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cdump
name|__P
argument_list|(
operator|(
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_vifs
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_nbrs
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_mldqueriers
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_pim_mrt
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dump_rp_set
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_stat
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

