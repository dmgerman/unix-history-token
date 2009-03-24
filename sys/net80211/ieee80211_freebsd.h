begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_FREEBSD_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_comment
comment|/*  * Common state locking definitions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* e.g. "ath0_com_lock" */
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
name|ieee80211_com_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_LOCK_INIT
parameter_list|(
name|_ic
parameter_list|,
name|_name
parameter_list|)
value|do {				\ 	ieee80211_com_lock_t *cl =&(_ic)->ic_comlock;			\ 	snprintf(cl->name, sizeof(cl->name), "%s_com_lock", _name);	\ 	mtx_init(&cl->mtx, cl->name, NULL, MTX_DEF | MTX_RECURSE);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK_OBJ
parameter_list|(
name|_ic
parameter_list|)
value|(&(_ic)->ic_comlock.mtx)
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK_DESTROY
parameter_list|(
name|_ic
parameter_list|)
value|mtx_destroy(IEEE80211_LOCK_OBJ(_ic))
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_lock(IEEE80211_LOCK_OBJ(_ic))
end_define

begin_define
define|#
directive|define
name|IEEE80211_UNLOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_unlock(IEEE80211_LOCK_OBJ(_ic))
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK_ASSERT
parameter_list|(
name|_ic
parameter_list|)
define|\
value|mtx_assert(IEEE80211_LOCK_OBJ(_ic), MA_OWNED)
end_define

begin_comment
comment|/*  * Node locking definitions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* e.g. "ath0_node_lock" */
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
name|ieee80211_node_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK_INIT
parameter_list|(
name|_nt
parameter_list|,
name|_name
parameter_list|)
value|do {			\ 	ieee80211_node_lock_t *nl =&(_nt)->nt_nodelock;		\ 	snprintf(nl->name, sizeof(nl->name), "%s_node_lock", _name);	\ 	mtx_init(&nl->mtx, nl->name, NULL, MTX_DEF | MTX_RECURSE);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK_OBJ
parameter_list|(
name|_nt
parameter_list|)
value|(&(_nt)->nt_nodelock.mtx)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK_DESTROY
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_destroy(IEEE80211_NODE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_lock(IEEE80211_NODE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_IS_LOCKED
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_owned(IEEE80211_NODE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_UNLOCK
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_unlock(IEEE80211_NODE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK_ASSERT
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_assert(IEEE80211_NODE_LOCK_OBJ(_nt), MA_OWNED)
end_define

begin_comment
comment|/*  * Node table iteration locking definitions; this protects the  * scan generation # used to iterate over the station table  * while grabbing+releasing the node lock.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* e.g. "ath0_scan_lock" */
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
name|ieee80211_scan_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_NODE_ITERATE_LOCK_INIT
parameter_list|(
name|_nt
parameter_list|,
name|_name
parameter_list|)
value|do {		\ 	ieee80211_scan_lock_t *sl =&(_nt)->nt_scanlock;		\ 	snprintf(sl->name, sizeof(sl->name), "%s_scan_lock", _name);	\ 	mtx_init(&sl->mtx, sl->name, NULL, MTX_DEF);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_ITERATE_LOCK_OBJ
parameter_list|(
name|_nt
parameter_list|)
value|(&(_nt)->nt_scanlock.mtx)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_ITERATE_LOCK_DESTROY
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_destroy(IEEE80211_NODE_ITERATE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_ITERATE_LOCK
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_lock(IEEE80211_NODE_ITERATE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_ITERATE_UNLOCK
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_unlock(IEEE80211_NODE_ITERATE_LOCK_OBJ(_nt))
end_define

begin_define
define|#
directive|define
name|_AGEQ_ENQUEUE
parameter_list|(
name|_ifq
parameter_list|,
name|_m
parameter_list|,
name|_qlen
parameter_list|,
name|_age
parameter_list|)
value|do {		\ 	(_m)->m_nextpkt = NULL;					\ 	if ((_ifq)->ifq_tail != NULL) { 			\ 		_age -= M_AGE_GET((_ifq)->ifq_head);		\ 		(_ifq)->ifq_tail->m_nextpkt = (_m);		\ 	} else { 						\ 		(_ifq)->ifq_head = (_m); 			\ 	}							\ 	M_AGE_SET(_m, _age);					\ 	(_ifq)->ifq_tail = (_m); 				\ 	(_qlen) = ++(_ifq)->ifq_len; 				\ } while (0)
end_define

begin_comment
comment|/*  * Power-save queue definitions.   */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
name|ieee80211_psq_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_PSQ_INIT
parameter_list|(
name|_psq
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_psq)->psq_lock, _name, "802.11 ps q", MTX_DEF);
end_define

begin_define
define|#
directive|define
name|IEEE80211_PSQ_DESTROY
parameter_list|(
name|_psq
parameter_list|)
value|mtx_destroy(&(_psq)->psq_lock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_PSQ_LOCK
parameter_list|(
name|_psq
parameter_list|)
value|mtx_lock(&(_psq)->psq_lock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_PSQ_UNLOCK
parameter_list|(
name|_psq
parameter_list|)
value|mtx_unlock(&(_psq)->psq_lock)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IF_PREPEND_LIST
end_ifndef

begin_define
define|#
directive|define
name|_IF_PREPEND_LIST
parameter_list|(
name|ifq
parameter_list|,
name|mhead
parameter_list|,
name|mtail
parameter_list|,
name|mcount
parameter_list|)
value|do {	\ 	(mtail)->m_nextpkt = (ifq)->ifq_head;			\ 	if ((ifq)->ifq_tail == NULL)				\ 		(ifq)->ifq_tail = (mtail);			\ 	(ifq)->ifq_head = (mhead);				\ 	(ifq)->ifq_len += (mcount);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_PREPEND_LIST
parameter_list|(
name|ifq
parameter_list|,
name|mhead
parameter_list|,
name|mtail
parameter_list|,
name|mcount
parameter_list|)
value|do {		\ 	IF_LOCK(ifq);						\ 	_IF_PREPEND_LIST(ifq, mhead, mtail, mcount);		\ 	IF_UNLOCK(ifq);						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_PREPEND_LIST */
end_comment

begin_comment
comment|/* XXX temporary */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NODE_WDSQ_INIT
parameter_list|(
name|_ni
parameter_list|,
name|_name
parameter_list|)
value|do {		\ 	mtx_init(&(_ni)->ni_wdsq.ifq_mtx, _name, "802.11 wds queue", MTX_DEF);\ 	(_ni)->ni_wdsq.ifq_maxlen = IEEE80211_PS_MAX_QUEUE;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_WDSQ_DESTROY
parameter_list|(
name|_ni
parameter_list|)
value|do { \ 	mtx_destroy(&(_ni)->ni_wdsq.ifq_mtx); \ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_WDSQ_QLEN
parameter_list|(
name|_ni
parameter_list|)
value|_IF_QLEN(&(_ni)->ni_wdsq)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_WDSQ_LOCK
parameter_list|(
name|_ni
parameter_list|)
value|IF_LOCK(&(_ni)->ni_wdsq)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_WDSQ_UNLOCK
parameter_list|(
name|_ni
parameter_list|)
value|IF_UNLOCK(&(_ni)->ni_wdsq)
end_define

begin_define
define|#
directive|define
name|_IEEE80211_NODE_WDSQ_DEQUEUE_HEAD
parameter_list|(
name|_ni
parameter_list|,
name|_m
parameter_list|)
value|do {		\ 	_IF_DEQUEUE(&(_ni)->ni_wdsq, m);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IEEE80211_NODE_WDSQ_ENQUEUE
parameter_list|(
name|_ni
parameter_list|,
name|_m
parameter_list|,
name|_qlen
parameter_list|,
name|_age
parameter_list|)
value|do {	\ 	_AGEQ_ENQUEUE(&ni->ni_wdsq, _m, _qlen, _age);		\ } while (0)
end_define

begin_comment
comment|/*  * 802.1x MAC ACL database locking definitions.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
name|acl_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACL_LOCK_INIT
parameter_list|(
name|_as
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_as)->as_lock, _name, "802.11 ACL", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ACL_LOCK_DESTROY
parameter_list|(
name|_as
parameter_list|)
value|mtx_destroy(&(_as)->as_lock)
end_define

begin_define
define|#
directive|define
name|ACL_LOCK
parameter_list|(
name|_as
parameter_list|)
value|mtx_lock(&(_as)->as_lock)
end_define

begin_define
define|#
directive|define
name|ACL_UNLOCK
parameter_list|(
name|_as
parameter_list|)
value|mtx_unlock(&(_as)->as_lock)
end_define

begin_define
define|#
directive|define
name|ACL_LOCK_ASSERT
parameter_list|(
name|_as
parameter_list|)
define|\
value|mtx_assert((&(_as)->as_lock), MA_OWNED)
end_define

begin_comment
comment|/*  * Node reference counting definitions.  *  * ieee80211_node_initref	initialize the reference count to 1  * ieee80211_node_incref	add a reference  * ieee80211_node_decref	remove a reference  * ieee80211_node_dectestref	remove a reference and return 1 if this  *				is the last reference, otherwise 0  * ieee80211_node_refcnt	reference count for printing (only)  */
end_comment

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_define
define|#
directive|define
name|ieee80211_node_initref
parameter_list|(
name|_ni
parameter_list|)
define|\
value|do { ((_ni)->ni_refcnt = 1); } while (0)
end_define

begin_define
define|#
directive|define
name|ieee80211_node_incref
parameter_list|(
name|_ni
parameter_list|)
define|\
value|atomic_add_int(&(_ni)->ni_refcnt, 1)
end_define

begin_define
define|#
directive|define
name|ieee80211_node_decref
parameter_list|(
name|_ni
parameter_list|)
define|\
value|atomic_subtract_int(&(_ni)->ni_refcnt, 1)
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211_node
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_node_dectestref
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ieee80211_node_refcnt
parameter_list|(
name|_ni
parameter_list|)
value|(_ni)->ni_refcnt
end_define

begin_struct_decl
struct_decl|struct
name|ifqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_drain_ifq
parameter_list|(
name|struct
name|ifqueue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_flush_ifq
parameter_list|(
name|struct
name|ifqueue
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_vap_destroy
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IFNET_IS_UP_RUNNING
parameter_list|(
name|_ifp
parameter_list|)
define|\
value|(((_ifp)->if_flags& IFF_UP)&& \ 	 ((_ifp)->if_drv_flags& IFF_DRV_RUNNING))
end_define

begin_define
define|#
directive|define
name|msecs_to_ticks
parameter_list|(
name|ms
parameter_list|)
value|(((ms)*hz)/1000)
end_define

begin_define
define|#
directive|define
name|ticks_to_msecs
parameter_list|(
name|t
parameter_list|)
value|(1000*(t) / hz)
end_define

begin_define
define|#
directive|define
name|ticks_to_secs
parameter_list|(
name|t
parameter_list|)
value|((t) / hz)
end_define

begin_define
define|#
directive|define
name|time_after
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(b) - (long)(a)< 0)
end_define

begin_define
define|#
directive|define
name|time_before
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|time_after(b,a)
end_define

begin_define
define|#
directive|define
name|time_after_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(a) - (long)(b)>= 0)
end_define

begin_define
define|#
directive|define
name|time_before_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|time_after_eq(b,a)
end_define

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_getmgtframe
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|frm
parameter_list|,
name|int
name|headroom
parameter_list|,
name|int
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tx path usage */
end_comment

begin_define
define|#
directive|define
name|M_ENCAP
value|M_PROTO1
end_define

begin_comment
comment|/* 802.11 encap done */
end_comment

begin_define
define|#
directive|define
name|M_WDS
value|M_PROTO2
end_define

begin_comment
comment|/* WDS frame */
end_comment

begin_define
define|#
directive|define
name|M_EAPOL
value|M_PROTO3
end_define

begin_comment
comment|/* PAE/EAPOL frame */
end_comment

begin_define
define|#
directive|define
name|M_PWR_SAV
value|M_PROTO4
end_define

begin_comment
comment|/* bypass PS handling */
end_comment

begin_define
define|#
directive|define
name|M_MORE_DATA
value|M_PROTO5
end_define

begin_comment
comment|/* more data frames to follow */
end_comment

begin_define
define|#
directive|define
name|M_FF
value|M_PROTO6
end_define

begin_comment
comment|/* fast frame */
end_comment

begin_define
define|#
directive|define
name|M_TXCB
value|M_PROTO7
end_define

begin_comment
comment|/* do tx complete callback */
end_comment

begin_define
define|#
directive|define
name|M_AMPDU_MPDU
value|M_PROTO8
end_define

begin_comment
comment|/* ok for A-MPDU aggregation */
end_comment

begin_define
define|#
directive|define
name|M_80211_TX
define|\
value|(M_FRAG|M_FIRSTFRAG|M_LASTFRAG|M_ENCAP|M_WDS|M_EAPOL|M_PWR_SAV|\ 	 M_MORE_DATA|M_FF|M_TXCB|M_AMPDU_MPDU)
end_define

begin_comment
comment|/* rx path usage */
end_comment

begin_define
define|#
directive|define
name|M_AMPDU
value|M_PROTO1
end_define

begin_comment
comment|/* A-MPDU subframe */
end_comment

begin_define
define|#
directive|define
name|M_WEP
value|M_PROTO2
end_define

begin_comment
comment|/* WEP done by hardware */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|M_AMPDU_MPDU
value|M_PROTO8
end_define

begin_comment
comment|/* A-MPDU re-order done */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M_80211_RX
value|(M_AMPDU|M_WEP|M_AMPDU_MPDU)
end_define

begin_comment
comment|/*  * Store WME access control bits in the vlan tag.  * This is safe since it's done after the packet is classified  * (where we use any previous tag) and because it's passed  * directly in to the driver and there's no chance someone  * else will clobber them on us.  */
end_comment

begin_define
define|#
directive|define
name|M_WME_SETAC
parameter_list|(
name|m
parameter_list|,
name|ac
parameter_list|)
define|\
value|((m)->m_pkthdr.ether_vtag = (ac))
end_define

begin_define
define|#
directive|define
name|M_WME_GETAC
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.ether_vtag)
end_define

begin_comment
comment|/*  * Mbufs on the power save queue are tagged with an age and  * timed out.  We reuse the hardware checksum field in the  * mbuf packet header to store this data.  */
end_comment

begin_define
define|#
directive|define
name|M_AGE_SET
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|)
value|(m->m_pkthdr.csum_data = v)
end_define

begin_define
define|#
directive|define
name|M_AGE_GET
parameter_list|(
name|m
parameter_list|)
value|(m->m_pkthdr.csum_data)
end_define

begin_define
define|#
directive|define
name|M_AGE_SUB
parameter_list|(
name|m
parameter_list|,
name|adj
parameter_list|)
value|(m->m_pkthdr.csum_data -= adj)
end_define

begin_define
define|#
directive|define
name|MTAG_ABI_NET80211
value|1132948340
end_define

begin_comment
comment|/* net80211 ABI */
end_comment

begin_struct
struct|struct
name|ieee80211_cb
block|{
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NET80211_TAG_CALLBACK
value|0
end_define

begin_comment
comment|/* xmit complete callback */
end_comment

begin_function_decl
name|int
name|ieee80211_add_callback
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_process_callback
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
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
name|get_random_bytes
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_sysctl_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sysctl_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sysctl_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sysctl_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_load_module
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A "policy module" is an adjunct module to net80211 that provides  * functionality that typically includes policy decisions.  This  * modularity enables extensibility and vendor-supplied functionality.  */
end_comment

begin_define
define|#
directive|define
name|_IEEE80211_POLICY_MODULE
parameter_list|(
name|policy
parameter_list|,
name|name
parameter_list|,
name|version
parameter_list|)
define|\
value|typedef void (*policy##_setup)(int);					\ SET_DECLARE(policy##_set, policy##_setup);				\ static int								\ wlan_##name##_modevent(module_t mod, int type, void *unused)		\ {									\ 	policy##_setup * const *iter, f;				\ 	switch (type) {							\ 	case MOD_LOAD:							\ 		SET_FOREACH(iter, policy##_set) {			\ 			f = (void*) *iter;				\ 			f(type);					\ 		}							\ 		return 0;						\ 	case MOD_UNLOAD:						\ 	case MOD_QUIESCE:						\ 		if (nrefs) {						\ 			printf("wlan_##name: still in use (%u dynamic refs)\n",\ 				nrefs);					\ 			return EBUSY;					\ 		}							\ 		if (type == MOD_UNLOAD) {				\ 			SET_FOREACH(iter, policy##_set) {		\ 				f = (void*) *iter;			\ 				f(type);				\ 			}						\ 		}							\ 		return 0;						\ 	}								\ 	return EINVAL;							\ }									\ static moduledata_t name##_mod = {					\ 	"wlan_" #name,							\ 	wlan_##name##_modevent,						\ 	0								\ };									\ DECLARE_MODULE(wlan_##name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_FIRST);\ MODULE_VERSION(wlan_##name, version);					\ MODULE_DEPEND(wlan_##name, wlan, 1, 1, 1)
end_define

begin_comment
comment|/*  * Crypto modules implement cipher support.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_MODULE
parameter_list|(
name|name
parameter_list|,
name|version
parameter_list|)
define|\
value|_IEEE80211_POLICY_MODULE(crypto, name, version);			\ static void								\ name##_modevent(int type)						\ {									\ 	if (type == MOD_LOAD)						\ 		ieee80211_crypto_register(&name);			\ 	else								\ 		ieee80211_crypto_unregister(&name);			\ }									\ TEXT_SET(crypto##_set, name##_modevent)
end_define

begin_comment
comment|/*  * Scanner modules provide scanning policy.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SCANNER_MODULE
parameter_list|(
name|name
parameter_list|,
name|version
parameter_list|)
define|\
value|_IEEE80211_POLICY_MODULE(scanner, name, version)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SCANNER_ALG
parameter_list|(
name|name
parameter_list|,
name|alg
parameter_list|,
name|v
parameter_list|)
define|\
value|static void								\ name##_modevent(int type)						\ {									\ 	if (type == MOD_LOAD)						\ 		ieee80211_scanner_register(alg,&v);			\ 	else								\ 		ieee80211_scanner_unregister(alg,&v);			\ }									\ TEXT_SET(scanner_set, name##_modevent);
end_define

begin_comment
unit|\
comment|/*  * ACL modules implement acl policy.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACL_MODULE
parameter_list|(
name|name
parameter_list|,
name|alg
parameter_list|,
name|version
parameter_list|)
define|\
value|_IEEE80211_POLICY_MODULE(acl, name, version);				\ static void								\ alg##_modevent(int type)						\ {									\ 	if (type == MOD_LOAD)						\ 		ieee80211_aclator_register(&alg);			\ 	else								\ 		ieee80211_aclator_unregister(&alg);			\ }									\ TEXT_SET(acl_set, alg##_modevent);
end_define

begin_comment
unit|\
comment|/*  * Authenticator modules handle 802.1x/WPA authentication.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_AUTH_MODULE
parameter_list|(
name|name
parameter_list|,
name|version
parameter_list|)
define|\
value|_IEEE80211_POLICY_MODULE(auth, name, version)
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_ALG
parameter_list|(
name|name
parameter_list|,
name|alg
parameter_list|,
name|v
parameter_list|)
define|\
value|static void								\ name##_modevent(int type)						\ {									\ 	if (type == MOD_LOAD)						\ 		ieee80211_authenticator_register(alg,&v);		\ 	else								\ 		ieee80211_authenticator_unregister(alg);		\ }									\ TEXT_SET(auth_set, name##_modevent)
end_define

begin_comment
comment|/*  * Rate control modules provide tx rate control support.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RATE_MODULE
parameter_list|(
name|alg
parameter_list|,
name|version
parameter_list|)
define|\
value|_IEEE80211_POLICY_MODULE(rate, alg, version);				\ static void								\ alg##_modevent(int type)						\ {									\
comment|/* XXX nothing to do until the rate control framework arrives */
value|\ }									\ TEXT_SET(rate##_set, alg##_modevent)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct_decl
struct_decl|struct
name|ieee80211req
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|ieee80211_ioctl_getfunc
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211req
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|ieee80211_ioctl_getset
argument_list|,
name|ieee80211_ioctl_getfunc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IEEE80211_IOCTL_GET
parameter_list|(
name|_name
parameter_list|,
name|_get
parameter_list|)
value|TEXT_SET(ieee80211_ioctl_getset, _get)
end_define

begin_typedef
typedef|typedef
name|int
name|ieee80211_ioctl_setfunc
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211req
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|ieee80211_ioctl_setset
argument_list|,
name|ieee80211_ioctl_setfunc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IEEE80211_IOCTL_SET
parameter_list|(
name|_name
parameter_list|,
name|_set
parameter_list|)
value|TEXT_SET(ieee80211_ioctl_setset, _set)
end_define

begin_comment
comment|/* XXX this stuff belongs elsewhere */
end_comment

begin_comment
comment|/*  * Message formats for messages from the net80211 layer to user  * applications via the routing socket.  These messages are appended  * to an if_announcemsghdr structure.  */
end_comment

begin_struct
struct|struct
name|ieee80211_join_event
block|{
name|uint8_t
name|iev_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_leave_event
block|{
name|uint8_t
name|iev_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_replay_event
block|{
name|uint8_t
name|iev_src
index|[
literal|6
index|]
decl_stmt|;
comment|/* src MAC */
name|uint8_t
name|iev_dst
index|[
literal|6
index|]
decl_stmt|;
comment|/* dst MAC */
name|uint8_t
name|iev_cipher
decl_stmt|;
comment|/* cipher type */
name|uint8_t
name|iev_keyix
decl_stmt|;
comment|/* key id/index */
name|uint64_t
name|iev_keyrsc
decl_stmt|;
comment|/* RSC from key */
name|uint64_t
name|iev_rsc
decl_stmt|;
comment|/* RSC from frame */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_michael_event
block|{
name|uint8_t
name|iev_src
index|[
literal|6
index|]
decl_stmt|;
comment|/* src MAC */
name|uint8_t
name|iev_dst
index|[
literal|6
index|]
decl_stmt|;
comment|/* dst MAC */
name|uint8_t
name|iev_cipher
decl_stmt|;
comment|/* cipher type */
name|uint8_t
name|iev_keyix
decl_stmt|;
comment|/* key id/index */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_wds_event
block|{
name|uint8_t
name|iev_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_csa_event
block|{
name|uint32_t
name|iev_flags
decl_stmt|;
comment|/* channel flags */
name|uint16_t
name|iev_freq
decl_stmt|;
comment|/* setting in Mhz */
name|uint8_t
name|iev_ieee
decl_stmt|;
comment|/* IEEE channel number */
name|uint8_t
name|iev_mode
decl_stmt|;
comment|/* CSA mode */
name|uint8_t
name|iev_count
decl_stmt|;
comment|/* CSA count */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_cac_event
block|{
name|uint32_t
name|iev_flags
decl_stmt|;
comment|/* channel flags */
name|uint16_t
name|iev_freq
decl_stmt|;
comment|/* setting in Mhz */
name|uint8_t
name|iev_ieee
decl_stmt|;
comment|/* IEEE channel number */
comment|/* XXX timestamp? */
name|uint8_t
name|iev_type
decl_stmt|;
comment|/* IEEE80211_NOTIFY_CAC_* */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_radar_event
block|{
name|uint32_t
name|iev_flags
decl_stmt|;
comment|/* channel flags */
name|uint16_t
name|iev_freq
decl_stmt|;
comment|/* setting in Mhz */
name|uint8_t
name|iev_ieee
decl_stmt|;
comment|/* IEEE channel number */
comment|/* XXX timestamp? */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_auth_event
block|{
name|uint8_t
name|iev_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_deauth_event
block|{
name|uint8_t
name|iev_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_country_event
block|{
name|uint8_t
name|iev_addr
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|iev_cc
index|[
literal|2
index|]
decl_stmt|;
comment|/* ISO country code */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_radio_event
block|{
name|uint8_t
name|iev_state
decl_stmt|;
comment|/* 1 on, 0 off */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTM_IEEE80211_ASSOC
value|100
end_define

begin_comment
comment|/* station associate (bss mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_REASSOC
value|101
end_define

begin_comment
comment|/* station re-associate (bss mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_DISASSOC
value|102
end_define

begin_comment
comment|/* station disassociate (bss mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_JOIN
value|103
end_define

begin_comment
comment|/* station join (ap mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_LEAVE
value|104
end_define

begin_comment
comment|/* station leave (ap mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_SCAN
value|105
end_define

begin_comment
comment|/* scan complete, results available */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_REPLAY
value|106
end_define

begin_comment
comment|/* sequence counter replay detected */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_MICHAEL
value|107
end_define

begin_comment
comment|/* Michael MIC failure detected */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_REJOIN
value|108
end_define

begin_comment
comment|/* station re-associate (ap mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_WDS
value|109
end_define

begin_comment
comment|/* WDS discovery (ap mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_CSA
value|110
end_define

begin_comment
comment|/* Channel Switch Announcement event */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_RADAR
value|111
end_define

begin_comment
comment|/* radar event */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_CAC
value|112
end_define

begin_comment
comment|/* Channel Availability Check event */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_DEAUTH
value|113
end_define

begin_comment
comment|/* station deauthenticate */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_AUTH
value|114
end_define

begin_comment
comment|/* station authenticate (ap mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_COUNTRY
value|115
end_define

begin_comment
comment|/* discovered country code (sta mode) */
end_comment

begin_define
define|#
directive|define
name|RTM_IEEE80211_RADIO
value|116
end_define

begin_comment
comment|/* RF kill switch state change */
end_comment

begin_comment
comment|/*  * Structure prepended to raw packets sent through the bpf  * interface when set to DLT_IEEE802_11_RADIO.  This allows  * user applications to specify pretty much everything in  * an Atheros tx descriptor.  XXX need to generalize.  *  * XXX cannot be more than 14 bytes as it is copied to a sockaddr's  * XXX sa_data area.  */
end_comment

begin_struct
struct|struct
name|ieee80211_bpf_params
block|{
name|uint8_t
name|ibp_vers
decl_stmt|;
comment|/* version */
define|#
directive|define
name|IEEE80211_BPF_VERSION
value|0
name|uint8_t
name|ibp_len
decl_stmt|;
comment|/* header length in bytes */
name|uint8_t
name|ibp_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_BPF_SHORTPRE
value|0x01
comment|/* tx with short preamble */
define|#
directive|define
name|IEEE80211_BPF_NOACK
value|0x02
comment|/* tx with no ack */
define|#
directive|define
name|IEEE80211_BPF_CRYPTO
value|0x04
comment|/* tx with h/w encryption */
define|#
directive|define
name|IEEE80211_BPF_FCS
value|0x10
comment|/* frame incldues FCS */
define|#
directive|define
name|IEEE80211_BPF_DATAPAD
value|0x20
comment|/* frame includes data padding */
define|#
directive|define
name|IEEE80211_BPF_RTS
value|0x40
comment|/* tx with RTS/CTS */
define|#
directive|define
name|IEEE80211_BPF_CTS
value|0x80
comment|/* tx with CTS only */
name|uint8_t
name|ibp_pri
decl_stmt|;
comment|/* WME/WMM AC+tx antenna */
name|uint8_t
name|ibp_try0
decl_stmt|;
comment|/* series 1 try count */
name|uint8_t
name|ibp_rate0
decl_stmt|;
comment|/* series 1 IEEE tx rate */
name|uint8_t
name|ibp_power
decl_stmt|;
comment|/* tx power (device units) */
name|uint8_t
name|ibp_ctsrate
decl_stmt|;
comment|/* IEEE tx rate for CTS */
name|uint8_t
name|ibp_try1
decl_stmt|;
comment|/* series 2 try count */
name|uint8_t
name|ibp_rate1
decl_stmt|;
comment|/* series 2 IEEE tx rate */
name|uint8_t
name|ibp_try2
decl_stmt|;
comment|/* series 3 try count */
name|uint8_t
name|ibp_rate2
decl_stmt|;
comment|/* series 3 IEEE tx rate */
name|uint8_t
name|ibp_try3
decl_stmt|;
comment|/* series 4 try count */
name|uint8_t
name|ibp_rate3
decl_stmt|;
comment|/* series 4 IEEE tx rate */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_FREEBSD_H_ */
end_comment

end_unit

