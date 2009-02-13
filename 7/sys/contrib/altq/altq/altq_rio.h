begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: altq_rio.h,v 1.9 2003/07/10 12:07:49 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998-2003  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_RIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_RIO_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq_classq.h>
end_include

begin_comment
comment|/*  * RIO: RED with IN/OUT bit  * (extended to support more than 2 drop precedence values)  */
end_comment

begin_define
define|#
directive|define
name|RIO_NDROPPREC
value|3
end_define

begin_comment
comment|/* number of drop precedence values */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_struct
struct|struct
name|rio_interface
block|{
name|char
name|rio_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rio_stats
block|{
name|struct
name|rio_interface
name|iface
decl_stmt|;
name|int
name|q_len
index|[
name|RIO_NDROPPREC
index|]
decl_stmt|;
name|struct
name|redstats
name|q_stats
index|[
name|RIO_NDROPPREC
index|]
decl_stmt|;
comment|/* static red parameters */
name|int
name|q_limit
decl_stmt|;
name|int
name|weight
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|struct
name|redparams
name|q_params
index|[
name|RIO_NDROPPREC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rio_conf
block|{
name|struct
name|rio_interface
name|iface
decl_stmt|;
name|struct
name|redparams
name|q_params
index|[
name|RIO_NDROPPREC
index|]
decl_stmt|;
name|int
name|rio_weight
decl_stmt|;
comment|/* weight for EWMA */
name|int
name|rio_limit
decl_stmt|;
comment|/* max queue length */
name|int
name|rio_pkttime
decl_stmt|;
comment|/* average packet time in usec */
name|int
name|rio_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_comment
comment|/* rio flags */
end_comment

begin_define
define|#
directive|define
name|RIOF_ECN4
value|0x01
end_define

begin_comment
comment|/* use packet marking for IPv4 packets */
end_comment

begin_define
define|#
directive|define
name|RIOF_ECN6
value|0x02
end_define

begin_comment
comment|/* use packet marking for IPv6 packets */
end_comment

begin_define
define|#
directive|define
name|RIOF_ECN
value|(RIOF_ECN4 | RIOF_ECN6)
end_define

begin_define
define|#
directive|define
name|RIOF_CLEARDSCP
value|0x200
end_define

begin_comment
comment|/* clear diffserv codepoint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_comment
comment|/*  * IOCTLs for RIO  */
end_comment

begin_define
define|#
directive|define
name|RIO_IF_ATTACH
value|_IOW('Q', 1, struct rio_interface)
end_define

begin_define
define|#
directive|define
name|RIO_IF_DETACH
value|_IOW('Q', 2, struct rio_interface)
end_define

begin_define
define|#
directive|define
name|RIO_ENABLE
value|_IOW('Q', 3, struct rio_interface)
end_define

begin_define
define|#
directive|define
name|RIO_DISABLE
value|_IOW('Q', 4, struct rio_interface)
end_define

begin_define
define|#
directive|define
name|RIO_CONFIG
value|_IOWR('Q', 6, struct rio_conf)
end_define

begin_define
define|#
directive|define
name|RIO_GETSTATS
value|_IOWR('Q', 12, struct rio_stats)
end_define

begin_define
define|#
directive|define
name|RIO_SETDEFAULTS
value|_IOW('Q', 30, struct redparams[RIO_NDROPPREC])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|rio
block|{
comment|/* per drop precedence structure */
struct|struct
name|dropprec_state
block|{
comment|/* red parameters */
name|int
name|inv_pmax
decl_stmt|;
comment|/* inverse of max drop probability */
name|int
name|th_min
decl_stmt|;
comment|/* red min threshold */
name|int
name|th_max
decl_stmt|;
comment|/* red max threshold */
comment|/* variables for internal use */
name|int
name|th_min_s
decl_stmt|;
comment|/* th_min scaled by avgshift */
name|int
name|th_max_s
decl_stmt|;
comment|/* th_max scaled by avgshift */
name|int
name|probd
decl_stmt|;
comment|/* drop probability denominator */
name|int
name|qlen
decl_stmt|;
comment|/* queue length */
name|int
name|avg
decl_stmt|;
comment|/* (scaled) queue length average */
name|int
name|count
decl_stmt|;
comment|/* packet count since the last dropped/ 					   marked packet */
name|int
name|idle
decl_stmt|;
comment|/* queue was empty */
name|int
name|old
decl_stmt|;
comment|/* avg is above th_min */
name|struct
name|timeval
name|last
decl_stmt|;
comment|/* timestamp when queue becomes idle */
block|}
name|rio_precstate
index|[
name|RIO_NDROPPREC
index|]
struct|;
name|int
name|rio_wshift
decl_stmt|;
comment|/* log(red_weight) */
name|int
name|rio_weight
decl_stmt|;
comment|/* weight for EWMA */
name|struct
name|wtab
modifier|*
name|rio_wtab
decl_stmt|;
comment|/* weight table */
name|int
name|rio_pkttime
decl_stmt|;
comment|/* average packet time in micro sec 					   used for idle calibration */
name|int
name|rio_flags
decl_stmt|;
comment|/* rio flags */
name|u_int8_t
name|rio_codepoint
decl_stmt|;
comment|/* codepoint value to tag packets */
name|u_int8_t
name|rio_codepointmask
decl_stmt|;
comment|/* codepoint mask bits */
name|struct
name|redstats
name|q_stats
index|[
name|RIO_NDROPPREC
index|]
decl_stmt|;
comment|/* statistics */
block|}
name|rio_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|rio_queue
block|{
name|struct
name|rio_queue
modifier|*
name|rq_next
decl_stmt|;
comment|/* next red_state in the list */
name|struct
name|ifaltq
modifier|*
name|rq_ifq
decl_stmt|;
comment|/* backpointer to ifaltq */
name|class_queue_t
modifier|*
name|rq_q
decl_stmt|;
name|rio_t
modifier|*
name|rq_rio
decl_stmt|;
block|}
name|rio_queue_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_function_decl
specifier|extern
name|rio_t
modifier|*
name|rio_alloc
parameter_list|(
name|int
parameter_list|,
name|struct
name|redparams
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rio_destroy
parameter_list|(
name|rio_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rio_getstats
parameter_list|(
name|rio_t
modifier|*
parameter_list|,
name|struct
name|redstats
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rio_addq
parameter_list|(
name|rio_t
modifier|*
parameter_list|,
name|class_queue_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|altq_pktattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|rio_getq
parameter_list|(
name|rio_t
modifier|*
parameter_list|,
name|class_queue_t
modifier|*
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
comment|/* _ALTQ_ALTQ_RIO_H_ */
end_comment

end_unit

