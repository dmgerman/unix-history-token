begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_bridgevar.h,v 1.4 2003/07/08 07:13:50 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1999, 2000 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jason L. Wright  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * OpenBSD: if_bridge.h,v 1.14 2001/03/22 03:48:29 jason Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Data structure and control definitions for bridge interfaces.  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_comment
comment|/*  * Commands used in the SIOCSDRVSPEC ioctl.  Note the lookup of the  * bridge interface itself is keyed off the ifdrv structure.  */
end_comment

begin_define
define|#
directive|define
name|BRDGADD
value|0
end_define

begin_comment
comment|/* add bridge member (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGDEL
value|1
end_define

begin_comment
comment|/* delete bridge member (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGGIFFLGS
value|2
end_define

begin_comment
comment|/* get member if flags (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGSIFFLGS
value|3
end_define

begin_comment
comment|/* set member if flags (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGSCACHE
value|4
end_define

begin_comment
comment|/* set cache size (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGCACHE
value|5
end_define

begin_comment
comment|/* get cache size (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGIFS
value|6
end_define

begin_comment
comment|/* get member list (ifbifconf) */
end_comment

begin_define
define|#
directive|define
name|BRDGRTS
value|7
end_define

begin_comment
comment|/* get address list (ifbaconf) */
end_comment

begin_define
define|#
directive|define
name|BRDGSADDR
value|8
end_define

begin_comment
comment|/* set static address (ifbareq) */
end_comment

begin_define
define|#
directive|define
name|BRDGSTO
value|9
end_define

begin_comment
comment|/* set cache timeout (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGTO
value|10
end_define

begin_comment
comment|/* get cache timeout (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGDADDR
value|11
end_define

begin_comment
comment|/* delete address (ifbareq) */
end_comment

begin_define
define|#
directive|define
name|BRDGFLUSH
value|12
end_define

begin_comment
comment|/* flush address cache (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGGPRI
value|13
end_define

begin_comment
comment|/* get priority (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGSPRI
value|14
end_define

begin_comment
comment|/* set priority (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGHT
value|15
end_define

begin_comment
comment|/* get hello time (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGSHT
value|16
end_define

begin_comment
comment|/* set hello time (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGFD
value|17
end_define

begin_comment
comment|/* get forward delay (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGSFD
value|18
end_define

begin_comment
comment|/* set forward delay (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGMA
value|19
end_define

begin_comment
comment|/* get max age (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGSMA
value|20
end_define

begin_comment
comment|/* set max age (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGSIFPRIO
value|21
end_define

begin_comment
comment|/* set if priority (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGSIFCOST
value|22
end_define

begin_comment
comment|/* set if path cost (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGADDS
value|23
end_define

begin_comment
comment|/* add bridge span member (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGDELS
value|24
end_define

begin_comment
comment|/* delete bridge span member (ifbreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGPARAM
value|25
end_define

begin_comment
comment|/* get bridge STP params (ifbropreq) */
end_comment

begin_define
define|#
directive|define
name|BRDGGRTE
value|26
end_define

begin_comment
comment|/* get cache drops (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGGIFSSTP
value|27
end_define

begin_comment
comment|/* get member STP params list 					 * (ifbpstpconf) */
end_comment

begin_define
define|#
directive|define
name|BRDGSPROTO
value|28
end_define

begin_comment
comment|/* set protocol (ifbrparam) */
end_comment

begin_define
define|#
directive|define
name|BRDGSTXHC
value|29
end_define

begin_comment
comment|/* set tx hold count (ifbrparam) */
end_comment

begin_comment
comment|/*  * Generic bridge control request.  */
end_comment

begin_struct
struct|struct
name|ifbreq
block|{
name|char
name|ifbr_ifsname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* member if name */
name|uint32_t
name|ifbr_ifsflags
decl_stmt|;
comment|/* member if flags */
name|uint32_t
name|ifbr_stpflags
decl_stmt|;
comment|/* member if STP flags */
name|uint32_t
name|ifbr_path_cost
decl_stmt|;
comment|/* member if STP cost */
name|uint8_t
name|ifbr_portno
decl_stmt|;
comment|/* member if port number */
name|uint8_t
name|ifbr_priority
decl_stmt|;
comment|/* member if STP priority */
name|uint8_t
name|ifbr_proto
decl_stmt|;
comment|/* member if STP protocol */
name|uint8_t
name|ifbr_role
decl_stmt|;
comment|/* member if STP role */
name|uint8_t
name|ifbr_state
decl_stmt|;
comment|/* member if STP state */
block|}
struct|;
end_struct

begin_comment
comment|/* BRDGGIFFLAGS, BRDGSIFFLAGS */
end_comment

begin_define
define|#
directive|define
name|IFBIF_LEARNING
value|0x0001
end_define

begin_comment
comment|/* if can learn */
end_comment

begin_define
define|#
directive|define
name|IFBIF_DISCOVER
value|0x0002
end_define

begin_comment
comment|/* if sends packets w/ unknown dest. */
end_comment

begin_define
define|#
directive|define
name|IFBIF_STP
value|0x0004
end_define

begin_comment
comment|/* if participates in spanning tree */
end_comment

begin_define
define|#
directive|define
name|IFBIF_SPAN
value|0x0008
end_define

begin_comment
comment|/* if is a span port */
end_comment

begin_define
define|#
directive|define
name|IFBIF_STICKY
value|0x0010
end_define

begin_comment
comment|/* if learned addresses stick */
end_comment

begin_define
define|#
directive|define
name|IFBIF_BSTP_EDGE
value|0x0020
end_define

begin_comment
comment|/* member stp edge port */
end_comment

begin_define
define|#
directive|define
name|IFBIF_BSTP_AUTOEDGE
value|0x0040
end_define

begin_comment
comment|/* member stp autoedge enabled */
end_comment

begin_define
define|#
directive|define
name|IFBIF_BSTP_P2P
value|0x0080
end_define

begin_comment
comment|/* member stp p2p */
end_comment

begin_define
define|#
directive|define
name|IFBIF_BSTP_AUTOP2P
value|0x0100
end_define

begin_comment
comment|/* member stp autop2p enabled */
end_comment

begin_define
define|#
directive|define
name|IFBIF_BSTP_ADMEDGE
value|0x0200
end_define

begin_comment
comment|/* member stp admin edge enabled */
end_comment

begin_define
define|#
directive|define
name|IFBIF_BSTP_ADMCOST
value|0x0400
end_define

begin_comment
comment|/* member stp admin path cost */
end_comment

begin_define
define|#
directive|define
name|IFBIFBITS
value|"\020\001LEARNING\002DISCOVER\003STP\004SPAN" \ 			"\005STICKY\006EDGE\007AUTOEDGE\010P2P\011AUTOP2P"
end_define

begin_define
define|#
directive|define
name|IFBIFMASK
value|~(IFBIF_BSTP_EDGE|IFBIF_BSTP_AUTOEDGE|IFBIF_BSTP_P2P| \ 			IFBIF_BSTP_AUTOP2P|IFBIF_BSTP_ADMEDGE| \ 			IFBIF_BSTP_ADMCOST)
end_define

begin_comment
comment|/* not saved */
end_comment

begin_comment
comment|/* BRDGFLUSH */
end_comment

begin_define
define|#
directive|define
name|IFBF_FLUSHDYN
value|0x00
end_define

begin_comment
comment|/* flush learned addresses only */
end_comment

begin_define
define|#
directive|define
name|IFBF_FLUSHALL
value|0x01
end_define

begin_comment
comment|/* flush all addresses */
end_comment

begin_comment
comment|/*  * Interface list structure.  */
end_comment

begin_struct
struct|struct
name|ifbifconf
block|{
name|uint32_t
name|ifbic_len
decl_stmt|;
comment|/* buffer size */
union|union
block|{
name|caddr_t
name|ifbicu_buf
decl_stmt|;
name|struct
name|ifbreq
modifier|*
name|ifbicu_req
decl_stmt|;
block|}
name|ifbic_ifbicu
union|;
define|#
directive|define
name|ifbic_buf
value|ifbic_ifbicu.ifbicu_buf
define|#
directive|define
name|ifbic_req
value|ifbic_ifbicu.ifbicu_req
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bridge address request.  */
end_comment

begin_struct
struct|struct
name|ifbareq
block|{
name|char
name|ifba_ifsname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* member if name */
name|unsigned
name|long
name|ifba_expire
decl_stmt|;
comment|/* address expire time */
name|uint8_t
name|ifba_flags
decl_stmt|;
comment|/* address flags */
name|uint8_t
name|ifba_dst
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* destination address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFBAF_TYPEMASK
value|0x03
end_define

begin_comment
comment|/* address type mask */
end_comment

begin_define
define|#
directive|define
name|IFBAF_DYNAMIC
value|0x00
end_define

begin_comment
comment|/* dynamically learned address */
end_comment

begin_define
define|#
directive|define
name|IFBAF_STATIC
value|0x01
end_define

begin_comment
comment|/* static address */
end_comment

begin_define
define|#
directive|define
name|IFBAF_STICKY
value|0x02
end_define

begin_comment
comment|/* sticky address */
end_comment

begin_define
define|#
directive|define
name|IFBAFBITS
value|"\020\1STATIC\2STICKY"
end_define

begin_comment
comment|/*  * Address list structure.  */
end_comment

begin_struct
struct|struct
name|ifbaconf
block|{
name|uint32_t
name|ifbac_len
decl_stmt|;
comment|/* buffer size */
union|union
block|{
name|caddr_t
name|ifbacu_buf
decl_stmt|;
name|struct
name|ifbareq
modifier|*
name|ifbacu_req
decl_stmt|;
block|}
name|ifbac_ifbacu
union|;
define|#
directive|define
name|ifbac_buf
value|ifbac_ifbacu.ifbacu_buf
define|#
directive|define
name|ifbac_req
value|ifbac_ifbacu.ifbacu_req
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bridge parameter structure.  */
end_comment

begin_struct
struct|struct
name|ifbrparam
block|{
union|union
block|{
name|uint32_t
name|ifbrpu_int32
decl_stmt|;
name|uint16_t
name|ifbrpu_int16
decl_stmt|;
name|uint8_t
name|ifbrpu_int8
decl_stmt|;
block|}
name|ifbrp_ifbrpu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifbrp_csize
value|ifbrp_ifbrpu.ifbrpu_int32
end_define

begin_comment
comment|/* cache size */
end_comment

begin_define
define|#
directive|define
name|ifbrp_ctime
value|ifbrp_ifbrpu.ifbrpu_int32
end_define

begin_comment
comment|/* cache time (sec) */
end_comment

begin_define
define|#
directive|define
name|ifbrp_prio
value|ifbrp_ifbrpu.ifbrpu_int16
end_define

begin_comment
comment|/* bridge priority */
end_comment

begin_define
define|#
directive|define
name|ifbrp_proto
value|ifbrp_ifbrpu.ifbrpu_int8
end_define

begin_comment
comment|/* bridge protocol */
end_comment

begin_define
define|#
directive|define
name|ifbrp_txhc
value|ifbrp_ifbrpu.ifbrpu_int8
end_define

begin_comment
comment|/* bpdu tx holdcount */
end_comment

begin_define
define|#
directive|define
name|ifbrp_hellotime
value|ifbrp_ifbrpu.ifbrpu_int8
end_define

begin_comment
comment|/* hello time (sec) */
end_comment

begin_define
define|#
directive|define
name|ifbrp_fwddelay
value|ifbrp_ifbrpu.ifbrpu_int8
end_define

begin_comment
comment|/* fwd time (sec) */
end_comment

begin_define
define|#
directive|define
name|ifbrp_maxage
value|ifbrp_ifbrpu.ifbrpu_int8
end_define

begin_comment
comment|/* max age (sec) */
end_comment

begin_define
define|#
directive|define
name|ifbrp_cexceeded
value|ifbrp_ifbrpu.ifbrpu_int32
end_define

begin_comment
comment|/* # of cache dropped 							 * adresses */
end_comment

begin_comment
comment|/*  * Bridge current operational parameters structure.  */
end_comment

begin_struct
struct|struct
name|ifbropreq
block|{
name|uint8_t
name|ifbop_holdcount
decl_stmt|;
name|uint8_t
name|ifbop_maxage
decl_stmt|;
name|uint8_t
name|ifbop_hellotime
decl_stmt|;
name|uint8_t
name|ifbop_fwddelay
decl_stmt|;
name|uint8_t
name|ifbop_protocol
decl_stmt|;
name|uint16_t
name|ifbop_priority
decl_stmt|;
name|uint16_t
name|ifbop_root_port
decl_stmt|;
name|uint32_t
name|ifbop_root_path_cost
decl_stmt|;
name|uint64_t
name|ifbop_bridgeid
decl_stmt|;
name|uint64_t
name|ifbop_designated_root
decl_stmt|;
name|uint64_t
name|ifbop_designated_bridge
decl_stmt|;
name|struct
name|timeval
name|ifbop_last_tc_time
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bridge member operational STP params structure.  */
end_comment

begin_struct
struct|struct
name|ifbpstpreq
block|{
name|uint8_t
name|ifbp_portno
decl_stmt|;
comment|/* bp STP port number */
name|uint32_t
name|ifbp_fwd_trans
decl_stmt|;
comment|/* bp STP fwd transitions */
name|uint32_t
name|ifbp_design_cost
decl_stmt|;
comment|/* bp STP designated cost */
name|uint32_t
name|ifbp_design_port
decl_stmt|;
comment|/* bp STP designated port */
name|uint64_t
name|ifbp_design_bridge
decl_stmt|;
comment|/* bp STP designated bridge */
name|uint64_t
name|ifbp_design_root
decl_stmt|;
comment|/* bp STP designated root */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bridge STP ports list structure.  */
end_comment

begin_struct
struct|struct
name|ifbpstpconf
block|{
name|uint32_t
name|ifbpstp_len
decl_stmt|;
comment|/* buffer size */
union|union
block|{
name|caddr_t
name|ifbpstpu_buf
decl_stmt|;
name|struct
name|ifbpstpreq
modifier|*
name|ifbpstpu_req
decl_stmt|;
block|}
name|ifbpstp_ifbpstpu
union|;
define|#
directive|define
name|ifbpstp_buf
value|ifbpstp_ifbpstpu.ifbpstpu_buf
define|#
directive|define
name|ifbpstp_req
value|ifbpstp_ifbpstpu.ifbpstpu_req
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|BRIDGE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do {			\ 	mtx_init(&(_sc)->sc_mtx, "if_bridge", NULL, MTX_DEF);	\ 	cv_init(&(_sc)->sc_cv, "if_bridge_cv");			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|do {	\ 	mtx_destroy(&(_sc)->sc_mtx);		\ 	cv_destroy(&(_sc)->sc_cv);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BRIDGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BRIDGE_LOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_owned(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BRIDGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BRIDGE_LOCK2REF
parameter_list|(
name|_sc
parameter_list|,
name|_err
parameter_list|)
value|do {	\ 	mtx_assert(&(_sc)->sc_mtx, MA_OWNED);	\ 	if ((_sc)->sc_iflist_xcnt> 0)		\ 		(_err) = EBUSY;			\ 	else					\ 		(_sc)->sc_iflist_ref++;		\ 	mtx_unlock(&(_sc)->sc_mtx);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_UNREF
parameter_list|(
name|_sc
parameter_list|)
value|do {				\ 	mtx_lock(&(_sc)->sc_mtx);					\ 	(_sc)->sc_iflist_ref--;						\ 	if (((_sc)->sc_iflist_xcnt> 0)&& ((_sc)->sc_iflist_ref == 0))	\ 		cv_broadcast(&(_sc)->sc_cv);				\ 	mtx_unlock(&(_sc)->sc_mtx);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_XLOCK
parameter_list|(
name|_sc
parameter_list|)
value|do {		\ 	mtx_assert(&(_sc)->sc_mtx, MA_OWNED);		\ 	(_sc)->sc_iflist_xcnt++;			\ 	while ((_sc)->sc_iflist_ref> 0)		\ 		cv_wait(&(_sc)->sc_cv,&(_sc)->sc_mtx);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_XDROP
parameter_list|(
name|_sc
parameter_list|)
value|do {	\ 	mtx_assert(&(_sc)->sc_mtx, MA_OWNED);	\ 	(_sc)->sc_iflist_xcnt--;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_INPUT
parameter_list|(
name|_ifp
parameter_list|,
name|_m
parameter_list|)
value|do {    	\ 	KASSERT(bridge_input_p != NULL,			\ 	    ("%s: if_bridge not loaded!", __func__));	\ 	_m = (*bridge_input_p)(_ifp, _m);		\ 	if (_m != NULL)					\ 		_ifp = _m->m_pkthdr.rcvif;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|BRIDGE_OUTPUT
parameter_list|(
name|_ifp
parameter_list|,
name|_m
parameter_list|,
name|_err
parameter_list|)
value|do {    		\ 	KASSERT(bridge_output_p != NULL,			\ 	    ("%s: if_bridge not loaded!", __func__));		\ 	_err = (*bridge_output_p)(_ifp, _m, NULL, NULL);	\ } while (0)
end_define

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|bridge_input_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|bridge_output_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|bridge_dn_p
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ifnet
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

end_unit

