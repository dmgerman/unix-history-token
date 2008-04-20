begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: ieee80211_amrr.h,v 1.3 2006/06/17 19:34:31 damien Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_AMRR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_AMRR_H_
end_define

begin_comment
comment|/*-  * Naive implementation of the Adaptive Multi Rate Retry algorithm:  *  * "IEEE 802.11 Rate Adaptation: A Practical Approach"  *  Mathieu Lacage, Hossein Manshaei, Thierry Turletti  *  INRIA Sophia - Projet Planete  *  http://www-sop.inria.fr/rapports/sophia/RR-5208.html  */
end_comment

begin_comment
comment|/*  * Rate control settings.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ieee80211_amrr
block|{
name|u_int
name|amrr_min_success_threshold
decl_stmt|;
name|u_int
name|amrr_max_success_threshold
decl_stmt|;
name|int
name|amrr_interval
decl_stmt|;
comment|/* update interval (ticks) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_AMRR_MIN_SUCCESS_THRESHOLD
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_AMRR_MAX_SUCCESS_THRESHOLD
value|15
end_define

begin_comment
comment|/*  * Rate control state for a given node.  */
end_comment

begin_struct
struct|struct
name|ieee80211_amrr_node
block|{
name|struct
name|ieee80211_amrr
modifier|*
name|amn_amrr
decl_stmt|;
comment|/* backpointer */
name|int
name|amn_rix
decl_stmt|;
comment|/* current rate index */
name|int
name|amn_ticks
decl_stmt|;
comment|/* time of last update */
comment|/* statistics */
name|u_int
name|amn_txcnt
decl_stmt|;
name|u_int
name|amn_success
decl_stmt|;
name|u_int
name|amn_success_threshold
decl_stmt|;
name|u_int
name|amn_recovery
decl_stmt|;
name|u_int
name|amn_retrycnt
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_amrr_init
parameter_list|(
name|struct
name|ieee80211_amrr
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_amrr_cleanup
parameter_list|(
name|struct
name|ieee80211_amrr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_amrr_setinterval
parameter_list|(
name|struct
name|ieee80211_amrr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_amrr_node_init
parameter_list|(
name|struct
name|ieee80211_amrr
modifier|*
parameter_list|,
name|struct
name|ieee80211_amrr_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_amrr_choose
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_amrr_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE80211_AMRR_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_AMRR_FAILURE
value|0
end_define

begin_comment
comment|/*  * Update statistics with tx complete status.  Ok is non-zero  * if the packet is known to be ACK'd.  Retries has the number  * retransmissions (i.e. xmit attempts - 1).  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_amrr_tx_complete
parameter_list|(
name|struct
name|ieee80211_amrr_node
modifier|*
name|amn
parameter_list|,
name|int
name|ok
parameter_list|,
name|int
name|retries
parameter_list|)
block|{
name|amn
operator|->
name|amn_txcnt
operator|++
expr_stmt|;
if|if
condition|(
name|ok
condition|)
name|amn
operator|->
name|amn_success
operator|++
expr_stmt|;
name|amn
operator|->
name|amn_retrycnt
operator|+=
name|retries
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set tx count/retry statistics explicitly.  Intended for  * drivers that poll the device for statistics maintained  * in the device.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_amrr_tx_update
parameter_list|(
name|struct
name|ieee80211_amrr_node
modifier|*
name|amn
parameter_list|,
name|int
name|txcnt
parameter_list|,
name|int
name|success
parameter_list|,
name|int
name|retrycnt
parameter_list|)
block|{
name|amn
operator|->
name|amn_txcnt
operator|=
name|txcnt
expr_stmt|;
name|amn
operator|->
name|amn_success
operator|=
name|success
expr_stmt|;
name|amn
operator|->
name|amn_retrycnt
operator|=
name|retrycnt
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_AMRR_H_ */
end_comment

end_unit

