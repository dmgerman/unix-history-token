begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Common state locking definitions.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
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
define|\
value|mtx_init(&(_ic)->ic_comlock, _name, "802.11 com lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK_DESTROY
parameter_list|(
name|_ic
parameter_list|)
value|mtx_destroy(&(_ic)->ic_comlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_lock(&(_ic)->ic_comlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_UNLOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_unlock(&(_ic)->ic_comlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK_ASSERT
parameter_list|(
name|_ic
parameter_list|)
define|\
value|mtx_assert(&(_ic)->ic_comlock, MA_OWNED)
end_define

begin_comment
comment|/*  * Beacon locking definitions.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
name|ieee80211_beacon_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_BEACON_LOCK_INIT
parameter_list|(
name|_ic
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_ic)->ic_beaconlock, _name, "802.11 beacon lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IEEE80211_BEACON_LOCK_DESTROY
parameter_list|(
name|_ic
parameter_list|)
value|mtx_destroy(&(_ic)->ic_beaconlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_BEACON_LOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_lock(&(_ic)->ic_beaconlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_BEACON_UNLOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_unlock(&(_ic)->ic_beaconlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_BEACON_LOCK_ASSERT
parameter_list|(
name|_ic
parameter_list|)
define|\
value|mtx_assert(&(_ic)->ic_beaconlock, MA_OWNED)
end_define

begin_comment
comment|/*  * Node locking definitions.  * NB: MTX_DUPOK is because we don't generate per-interface strings.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
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
define|\
value|mtx_init(&(_nt)->nt_nodelock, _name, "802.11 node table", \ 		MTX_DEF | MTX_DUPOK)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK_DESTROY
parameter_list|(
name|_nt
parameter_list|)
value|mtx_destroy(&(_nt)->nt_nodelock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK
parameter_list|(
name|_nt
parameter_list|)
value|mtx_lock(&(_nt)->nt_nodelock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_IS_LOCKED
parameter_list|(
name|_nt
parameter_list|)
value|mtx_owned(&(_nt)->nt_nodelock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_UNLOCK
parameter_list|(
name|_nt
parameter_list|)
value|mtx_unlock(&(_nt)->nt_nodelock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_LOCK_ASSERT
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_assert(&(_nt)->nt_nodelock, MA_OWNED)
end_define

begin_comment
comment|/*  * Node table scangen locking definitions.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
name|ieee80211_scan_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_SCAN_LOCK_INIT
parameter_list|(
name|_nt
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_nt)->nt_scanlock, _name, "802.11 node scangen", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SCAN_LOCK_DESTROY
parameter_list|(
name|_nt
parameter_list|)
value|mtx_destroy(&(_nt)->nt_scanlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SCAN_LOCK
parameter_list|(
name|_nt
parameter_list|)
value|mtx_lock(&(_nt)->nt_scanlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SCAN_UNLOCK
parameter_list|(
name|_nt
parameter_list|)
value|mtx_unlock(&(_nt)->nt_scanlock)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SCAN_LOCK_ASSERT
parameter_list|(
name|_nt
parameter_list|)
define|\
value|mtx_assert(&(_nt)->nt_scanlock, MA_OWNED)
end_define

begin_comment
comment|/*  * Per-node power-save queue definitions.   */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_INIT
parameter_list|(
name|_ni
parameter_list|,
name|_name
parameter_list|)
value|do {		\ 	mtx_init(&(_ni)->ni_savedq.ifq_mtx, _name, "802.11 ps queue", MTX_DEF);\ 	(_ni)->ni_savedq.ifq_maxlen = IEEE80211_PS_MAX_QUEUE;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_DESTROY
parameter_list|(
name|_ni
parameter_list|)
define|\
value|mtx_destroy(&(_ni)->ni_savedq.ifq_mtx)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_QLEN
parameter_list|(
name|_ni
parameter_list|)
define|\
value|_IF_QLEN(&(_ni)->ni_savedq)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_LOCK
parameter_list|(
name|_ni
parameter_list|)
value|do {	\ 	IF_LOCK(&(_ni)->ni_savedq);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_UNLOCK
parameter_list|(
name|_ni
parameter_list|)
value|do {	\ 	IF_UNLOCK(&(_ni)->ni_savedq);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_DEQUEUE
parameter_list|(
name|_ni
parameter_list|,
name|_m
parameter_list|,
name|_qlen
parameter_list|)
value|do {	\ 	IEEE80211_NODE_SAVEQ_LOCK(_ni);				\ 	_IF_DEQUEUE(&(_ni)->ni_savedq, _m);			\ 	(_qlen) = IEEE80211_NODE_SAVEQ_QLEN(_ni);		\ 	IEEE80211_NODE_SAVEQ_UNLOCK(_ni);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_SAVEQ_DRAIN
parameter_list|(
name|_ni
parameter_list|,
name|_qlen
parameter_list|)
value|do {		\ 	IEEE80211_NODE_SAVEQ_LOCK(_ni);				\ 	(_qlen) = IEEE80211_NODE_SAVEQ_QLEN(_ni);		\ 	_IF_DRAIN(&(_ni)->ni_savedq);				\ 	IEEE80211_NODE_SAVEQ_UNLOCK(_ni);			\ } while (0)
end_define

begin_comment
comment|/* XXX could be optimized */
end_comment

begin_define
define|#
directive|define
name|_IEEE80211_NODE_SAVEQ_DEQUEUE_HEAD
parameter_list|(
name|_ni
parameter_list|,
name|_m
parameter_list|)
value|do {	\ 	_IF_DEQUEUE(&(_ni)->ni_savedq, m);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IEEE80211_NODE_SAVEQ_ENQUEUE
parameter_list|(
name|_ni
parameter_list|,
name|_m
parameter_list|,
name|_qlen
parameter_list|,
name|_age
parameter_list|)
value|do {\ 	(_m)->m_nextpkt = NULL;					\ 	if ((_ni)->ni_savedq.ifq_tail != NULL) { 		\ 		_age -= M_AGE_GET((_ni)->ni_savedq.ifq_tail);	\ 		(_ni)->ni_savedq.ifq_tail->m_nextpkt = (_m);	\ 	} else { 						\ 		(_ni)->ni_savedq.ifq_head = (_m); 		\ 	}							\ 	M_AGE_SET(_m, _age);					\ 	(_ni)->ni_savedq.ifq_tail = (_m); 			\ 	(_qlen) = ++(_ni)->ni_savedq.ifq_len; 			\ } while (0)
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
name|M_LINK0
value|M_PROTO1
end_define

begin_comment
comment|/* WEP requested */
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
value|0x20000
end_define

begin_comment
comment|/* fast frame */
end_comment

begin_define
define|#
directive|define
name|M_TXCB
value|0x40000
end_define

begin_comment
comment|/* do tx complete callback */
end_comment

begin_define
define|#
directive|define
name|M_80211_TX
value|(0x60000|M_PROTO1|M_WME_AC_MASK|M_PROTO4|M_PROTO5)
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
comment|/* A-MPDU processing done */
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

begin_define
define|#
directive|define
name|M_80211_RX
value|(M_AMPDU|M_WEP)
end_define

begin_comment
comment|/*  * Encode WME access control bits in the PROTO flags.  * This is safe since it's passed directly in to the  * driver and there's no chance someone else will clobber  * them on us.  */
end_comment

begin_define
define|#
directive|define
name|M_WME_AC_MASK
value|(M_PROTO2|M_PROTO3)
end_define

begin_comment
comment|/* XXX 5 is wrong if M_PROTO* are redefined */
end_comment

begin_define
define|#
directive|define
name|M_WME_AC_SHIFT
value|5
end_define

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
value|((m)->m_flags = ((m)->m_flags&~ M_WME_AC_MASK) | \ 		((ac)<< M_WME_AC_SHIFT))
end_define

begin_define
define|#
directive|define
name|M_WME_GETAC
parameter_list|(
name|m
parameter_list|)
value|(((m)->m_flags>> M_WME_AC_SHIFT)& 0x3)
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
name|ieee80211_load_module
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
value|static int								\ name##_modevent(module_t mod, int type, void *unused)			\ {									\ 	switch (type) {							\ 	case MOD_LOAD:							\ 		ieee80211_crypto_register(&name);			\ 		return 0;						\ 	case MOD_UNLOAD:						\ 	case MOD_QUIESCE:						\ 		if (nrefs) {						\ 			printf("wlan_##name: still in use (%u dynamic refs)\n",\ 				nrefs);					\ 			return EBUSY;					\ 		}							\ 		if (type == MOD_UNLOAD)					\ 			ieee80211_crypto_unregister(&name);		\ 		return 0;						\ 	}								\ 	return EINVAL;							\ }									\ static moduledata_t name##_mod = {					\ 	"wlan_" #name,							\ 	name##_modevent,						\ 	0								\ };									\ DECLARE_MODULE(wlan_##name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_FIRST);\ MODULE_VERSION(wlan_##name, version);					\ MODULE_DEPEND(wlan_##name, wlan, 1, 1, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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

