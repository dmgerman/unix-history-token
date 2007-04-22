begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp_pcb.h,v 1.21 2005/07/16 01:18:47 suz Exp $	 */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__sctp_pcb_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_pcb_h__
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_os.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_constants.h>
end_include

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctppcbhead
argument_list|,
name|sctp_inpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctpasochead
argument_list|,
name|sctp_tcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctpladdr
argument_list|,
name|sctp_laddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctpvtaghead
argument_list|,
name|sctp_tagblock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctp_vrflist
argument_list|,
name|sctp_vrf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctp_ifnlist
argument_list|,
name|sctp_ifn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctp_ifalist
argument_list|,
name|sctp_ifa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_readhead
argument_list|,
name|sctp_queued_to_read
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_streamhead
argument_list|,
name|sctp_stream_queue_pending
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<netinet/sctp_structs.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_uio.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_auth.h>
end_include

begin_comment
comment|/*  * PCB flags (in sctp_flags bitmask)  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_UDPTYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_TCPTYPE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_BOUNDALL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_ACCEPTING
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_UNBOUND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_CLOSE_IP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAS_CONNECTED
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAS_ABORTED
value|0x00100000
end_define

begin_comment
comment|/* TCP model support */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_CONNECTED
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_IN_TCPPOOL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DONT_WAKE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAKEOUTPUT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAKEINPUT
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_BOUND_V6
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_NEEDS_MAPPED_V4
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_BLOCKING_IO
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_SOCKET_GONE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_SOCKET_ALLGONE
value|0x40000000
end_define

begin_comment
comment|/* flags to copy to new PCB */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_COPY_FLAGS
value|0x0e000004
end_define

begin_comment
comment|/*  * PCB Features (in sctp_features bitmask)  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_EXT_RCVINFO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DONOT_HEARTBEAT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_FRAG_INTERLEAVE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_INTERLEAVE_STRMS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DO_ASCONF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_AUTO_ASCONF
value|0x00000040
end_define

begin_comment
comment|/* socket options */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_NODELAY
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_AUTOCLOSE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVDATAIOEVNT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVASSOCEVNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVPADDREVNT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVPEERERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVSENDFAILEVNT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVSHUTDOWNEVNT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_ADAPTATIONEVNT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_PDAPIEVNT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_AUTHEVNT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_STREAM_RESETEVNT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_NO_FRAGMENT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_EXPLICIT_EOR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SCTP_PCBHASH_ALLADDR
parameter_list|(
name|port
parameter_list|,
name|mask
parameter_list|)
value|(port& mask)
end_define

begin_define
define|#
directive|define
name|SCTP_PCBHASH_ASOC
parameter_list|(
name|tag
parameter_list|,
name|mask
parameter_list|)
value|(tag& mask)
end_define

begin_struct
struct|struct
name|sctp_vrf
block|{
name|LIST_ENTRY
argument_list|(
argument|sctp_vrf
argument_list|)
name|next_vrf
expr_stmt|;
name|struct
name|sctp_ifalist
modifier|*
name|vrf_addr_hash
decl_stmt|;
name|struct
name|sctp_ifnlist
name|ifnlist
decl_stmt|;
name|uint32_t
name|vrf_id
decl_stmt|;
name|uint32_t
name|total_ifa_count
decl_stmt|;
name|u_long
name|vrf_hashmark
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_ifn
block|{
name|struct
name|sctp_ifalist
name|ifalist
decl_stmt|;
name|struct
name|sctp_vrf
modifier|*
name|vrf
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|sctp_ifn
argument_list|)
name|next_ifn
expr_stmt|;
name|void
modifier|*
name|ifn_p
decl_stmt|;
comment|/* never access without appropriate lock */
name|uint32_t
name|ifn_type
decl_stmt|;
name|uint32_t
name|ifn_index
decl_stmt|;
comment|/* shorthand way to look at ifn for reference */
name|uint32_t
name|refcount
decl_stmt|;
comment|/* number of reference held should be>= 				 * ifa_count */
name|uint32_t
name|ifa_count
decl_stmt|;
comment|/* IFA's we hold (in our list - ifalist) */
name|char
name|ifn_name
index|[
name|SCTP_IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SCTP local IFA flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_VALID
value|0x00000001
end_define

begin_comment
comment|/* its up and active */
end_comment

begin_define
define|#
directive|define
name|SCTP_BEING_DELETED
value|0x00000002
end_define

begin_comment
comment|/* being deleted, when 						 * refcount = 0. Note that it 						 * is pulled from the ifn list 						 * and ifa_p is nulled right 						 * away but it cannot be freed 						 * until the last *net 						 * pointing to it is deleted. */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_DEFER_USE
value|0x00000004
end_define

begin_comment
comment|/* Hold off using this one */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_IFA_UNUSEABLE
value|0x00000008
end_define

begin_struct
struct|struct
name|sctp_ifa
block|{
name|LIST_ENTRY
argument_list|(
argument|sctp_ifa
argument_list|)
name|next_ifa
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|sctp_ifa
argument_list|)
name|next_bucket
expr_stmt|;
name|struct
name|sctp_ifn
modifier|*
name|ifn_p
decl_stmt|;
comment|/* back pointer to parent ifn */
name|void
modifier|*
name|ifa
decl_stmt|;
comment|/* pointer to ifa, needed for flag update for 				 * that we MUST lock appropriate locks. This 				 * is for V6. */
name|union
name|sctp_sockstore
name|address
decl_stmt|;
name|uint32_t
name|refcount
decl_stmt|;
comment|/* number of folks refering to this */
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|localifa_flags
decl_stmt|;
name|uint8_t
name|src_is_loop
decl_stmt|;
name|uint8_t
name|src_is_priv
decl_stmt|;
name|uint8_t
name|src_is_glob
decl_stmt|;
name|uint8_t
name|in_ifa_list
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_laddr
block|{
name|LIST_ENTRY
argument_list|(
argument|sctp_laddr
argument_list|)
name|sctp_nxt_addr
expr_stmt|;
comment|/* next in list */
name|struct
name|sctp_ifa
modifier|*
name|ifa
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
comment|/* Used during asconf and adding if no-zero 				 * src-addr selection will not consider this 				 * address. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_block_entry
block|{
name|int
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_timewait
block|{
name|uint32_t
name|tv_sec_at_expire
decl_stmt|;
comment|/* the seconds from boot to expire */
name|uint32_t
name|v_tag
decl_stmt|;
comment|/* the vtag that can not be reused */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_tagblock
block|{
name|LIST_ENTRY
argument_list|(
argument|sctp_tagblock
argument_list|)
name|sctp_nxt_tagblock
expr_stmt|;
name|struct
name|sctp_timewait
name|vtag_block
index|[
name|SCTP_NUMBER_IN_VTAG_BLOCK
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_epinfo
block|{
name|struct
name|sctpasochead
modifier|*
name|sctp_asochash
decl_stmt|;
name|u_long
name|hashasocmark
decl_stmt|;
name|struct
name|sctppcbhead
modifier|*
name|sctp_ephash
decl_stmt|;
name|u_long
name|hashmark
decl_stmt|;
name|struct
name|sctpasochead
modifier|*
name|sctp_restarthash
decl_stmt|;
name|u_long
name|hashrestartmark
decl_stmt|;
comment|/*- 	 * The TCP model represents a substantial overhead in that we get an 	 * additional hash table to keep explicit connections in. The 	 * listening TCP endpoint will exist in the usual ephash above and 	 * accept only INIT's. It will be incapable of sending off an INIT. 	 * When a dg arrives we must look in the normal ephash. If we find a 	 * TCP endpoint that will tell us to go to the specific endpoint 	 * hash and re-hash to find the right assoc/socket. If we find a UDP 	 * model socket we then must complete the lookup. If this fails, 	 * i.e. no association can be found then we must continue to see if 	 * a sctp_peeloff()'d socket is in the tcpephash (a spun off socket 	 * acts like a TCP model connected socket). 	 */
name|struct
name|sctppcbhead
modifier|*
name|sctp_tcpephash
decl_stmt|;
name|u_long
name|hashtcpmark
decl_stmt|;
name|uint32_t
name|hashtblsize
decl_stmt|;
name|struct
name|sctp_vrflist
modifier|*
name|sctp_vrfhash
decl_stmt|;
name|u_long
name|hashvrfmark
decl_stmt|;
name|struct
name|sctppcbhead
name|listhead
decl_stmt|;
name|struct
name|sctpladdr
name|addr_wq
decl_stmt|;
name|struct
name|sctpiterators
name|iteratorhead
decl_stmt|;
comment|/* ep zone info */
name|sctp_zone_t
name|ipi_zone_ep
decl_stmt|;
name|sctp_zone_t
name|ipi_zone_asoc
decl_stmt|;
name|sctp_zone_t
name|ipi_zone_laddr
decl_stmt|;
name|sctp_zone_t
name|ipi_zone_net
decl_stmt|;
name|sctp_zone_t
name|ipi_zone_chunk
decl_stmt|;
name|sctp_zone_t
name|ipi_zone_readq
decl_stmt|;
name|sctp_zone_t
name|ipi_zone_strmoq
decl_stmt|;
name|struct
name|mtx
name|ipi_ep_mtx
decl_stmt|;
name|struct
name|mtx
name|it_mtx
decl_stmt|;
name|struct
name|mtx
name|ipi_iterator_wq_mtx
decl_stmt|;
name|struct
name|mtx
name|ipi_addr_mtx
decl_stmt|;
name|uint32_t
name|ipi_count_ep
decl_stmt|;
comment|/* assoc/tcb zone info */
name|uint32_t
name|ipi_count_asoc
decl_stmt|;
comment|/* local addrlist zone info */
name|uint32_t
name|ipi_count_laddr
decl_stmt|;
comment|/* remote addrlist zone info */
name|uint32_t
name|ipi_count_raddr
decl_stmt|;
comment|/* chunk structure list for output */
name|uint32_t
name|ipi_count_chunk
decl_stmt|;
comment|/* socket queue zone info */
name|uint32_t
name|ipi_count_readq
decl_stmt|;
comment|/* socket queue zone info */
name|uint32_t
name|ipi_count_strmoq
decl_stmt|;
comment|/* system wide number of free chunks hanging around */
name|uint32_t
name|ipi_free_chunks
decl_stmt|;
name|uint32_t
name|ipi_free_strmoq
decl_stmt|;
name|struct
name|sctpvtaghead
name|vtag_timewait
index|[
name|SCTP_STACK_VTAG_HASH_SIZE
index|]
decl_stmt|;
comment|/* address work queue handling */
if|#
directive|if
name|defined
argument_list|(
name|SCTP_USE_THREAD_BASED_ITERATOR
argument_list|)
name|uint32_t
name|iterator_running
decl_stmt|;
name|SCTP_PROCESS_STRUCT
name|thread_proc
decl_stmt|;
endif|#
directive|endif
name|struct
name|sctp_timer
name|addr_wq_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*-  * Here we have all the relevant information for each SCTP entity created. We  * will need to modify this as approprate. We also need to figure out how to  * access /dev/random.  */
end_comment

begin_struct
struct|struct
name|sctp_pcb
block|{
name|unsigned
name|int
name|time_of_secret_change
decl_stmt|;
comment|/* number of seconds from 						 * timeval.tv_sec */
name|uint32_t
name|secret_key
index|[
name|SCTP_HOW_MANY_SECRETS
index|]
index|[
name|SCTP_NUMBER_OF_SECRETS
index|]
decl_stmt|;
name|unsigned
name|int
name|size_of_a_cookie
decl_stmt|;
name|unsigned
name|int
name|sctp_timeoutticks
index|[
name|SCTP_NUM_TMRS
index|]
decl_stmt|;
name|unsigned
name|int
name|sctp_minrto
decl_stmt|;
name|unsigned
name|int
name|sctp_maxrto
decl_stmt|;
name|unsigned
name|int
name|initial_rto
decl_stmt|;
name|int
name|initial_init_rto_max
decl_stmt|;
name|unsigned
name|int
name|sctp_sack_freq
decl_stmt|;
name|uint32_t
name|sctp_sws_sender
decl_stmt|;
name|uint32_t
name|sctp_sws_receiver
decl_stmt|;
comment|/* authentication related fields */
name|struct
name|sctp_keyhead
name|shared_keys
decl_stmt|;
name|sctp_auth_chklist_t
modifier|*
name|local_auth_chunks
decl_stmt|;
name|sctp_hmaclist_t
modifier|*
name|local_hmacs
decl_stmt|;
name|uint16_t
name|default_keyid
decl_stmt|;
comment|/* various thresholds */
comment|/* Max times I will init at a guy */
name|uint16_t
name|max_init_times
decl_stmt|;
comment|/* Max times I will send before we consider someone dead */
name|uint16_t
name|max_send_times
decl_stmt|;
name|uint16_t
name|def_net_failure
decl_stmt|;
comment|/* number of streams to pre-open on a association */
name|uint16_t
name|pre_open_stream_count
decl_stmt|;
name|uint16_t
name|max_open_streams_intome
decl_stmt|;
comment|/* random number generator */
name|uint32_t
name|random_counter
decl_stmt|;
name|uint8_t
name|random_numbers
index|[
name|SCTP_SIGNATURE_ALOC_SIZE
index|]
decl_stmt|;
name|uint8_t
name|random_store
index|[
name|SCTP_SIGNATURE_ALOC_SIZE
index|]
decl_stmt|;
comment|/* 	 * This timer is kept running per endpoint.  When it fires it will 	 * change the secret key.  The default is once a hour 	 */
name|struct
name|sctp_timer
name|signature_change
decl_stmt|;
name|int
name|def_cookie_life
decl_stmt|;
comment|/* defaults to 0 */
name|int
name|auto_close_time
decl_stmt|;
name|uint32_t
name|initial_sequence_debug
decl_stmt|;
name|uint32_t
name|adaptation_layer_indicator
decl_stmt|;
name|char
name|store_at
decl_stmt|;
name|uint8_t
name|max_burst
decl_stmt|;
name|char
name|current_secret_number
decl_stmt|;
name|char
name|last_secret_number
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_ALIGNMENT
end_ifndef

begin_define
define|#
directive|define
name|SCTP_ALIGNMENT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_ALIGNM1
end_ifndef

begin_define
define|#
directive|define
name|SCTP_ALIGNM1
value|(SCTP_ALIGNMENT-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sctp_lport
value|ip_inp.inp.inp_lport
end_define

begin_struct
struct|struct
name|sctp_inpcb
block|{
comment|/*- 	 * put an inpcb in front of it all, kind of a waste but we need to 	 * for compatability with all the other stuff. 	 */
union|union
block|{
name|struct
name|inpcb
name|inp
decl_stmt|;
name|char
name|align
index|[
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|in6pcb
argument_list|)
operator|+
name|SCTP_ALIGNM1
operator|)
operator|&
operator|~
name|SCTP_ALIGNM1
index|]
decl_stmt|;
block|}
name|ip_inp
union|;
comment|/* Socket buffer lock protects read_queue and of course sb_cc */
name|struct
name|sctp_readhead
name|read_queue
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|sctp_inpcb
argument_list|)
name|sctp_list
expr_stmt|;
comment|/* lists all endpoints */
comment|/* hash of all endpoints for model */
name|LIST_ENTRY
argument_list|(
argument|sctp_inpcb
argument_list|)
name|sctp_hash
expr_stmt|;
comment|/* count of local addresses bound, 0 if bound all */
name|int
name|laddr_count
decl_stmt|;
comment|/* list of addrs in use by the EP, NULL if bound-all */
name|struct
name|sctpladdr
name|sctp_addr_list
decl_stmt|;
comment|/* 	 * used for source address selection rotation when we are subset 	 * bound 	 */
name|struct
name|sctp_laddr
modifier|*
name|next_addr_touse
decl_stmt|;
comment|/* back pointer to our socket */
name|struct
name|socket
modifier|*
name|sctp_socket
decl_stmt|;
name|uint32_t
name|sctp_flags
decl_stmt|;
comment|/* INP state flag set */
name|uint32_t
name|sctp_features
decl_stmt|;
comment|/* Feature flags */
name|struct
name|sctp_pcb
name|sctp_ep
decl_stmt|;
comment|/* SCTP ep data */
comment|/* head of the hash of all associations */
name|struct
name|sctpasochead
modifier|*
name|sctp_tcbhash
decl_stmt|;
name|u_long
name|sctp_hashmark
decl_stmt|;
comment|/* head of the list of all associations */
name|struct
name|sctpasochead
name|sctp_asoc_list
decl_stmt|;
ifdef|#
directive|ifdef
name|SCTP_TRACK_FREED_ASOCS
name|struct
name|sctpasochead
name|sctp_asoc_free_list
decl_stmt|;
endif|#
directive|endif
name|struct
name|sctp_iterator
modifier|*
name|inp_starting_point_for_iterator
decl_stmt|;
name|uint32_t
name|sctp_frag_point
decl_stmt|;
name|uint32_t
name|partial_delivery_point
decl_stmt|;
name|uint32_t
name|sctp_context
decl_stmt|;
name|struct
name|sctp_sndrcvinfo
name|def_send
decl_stmt|;
comment|/*- 	 * These three are here for the sosend_dgram 	 * (pkt, pkt_last and control). 	 * routine. However, I don't think anyone in 	 * the current FreeBSD kernel calls this. So 	 * they are candidates with sctp_sendm for 	 * de-supporting. 	 */
name|struct
name|mbuf
modifier|*
name|pkt
decl_stmt|,
modifier|*
name|pkt_last
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|control
decl_stmt|;
name|struct
name|mtx
name|inp_mtx
decl_stmt|;
name|struct
name|mtx
name|inp_create_mtx
decl_stmt|;
name|struct
name|mtx
name|inp_rdata_mtx
decl_stmt|;
name|int32_t
name|refcount
decl_stmt|;
name|uint32_t
name|def_vrf_id
decl_stmt|;
name|uint32_t
name|total_sends
decl_stmt|;
name|uint32_t
name|total_recvs
decl_stmt|;
name|uint32_t
name|last_abort_code
decl_stmt|;
name|uint32_t
name|total_nospaces
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_tcb
block|{
name|struct
name|socket
modifier|*
name|sctp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|sctp_inpcb
modifier|*
name|sctp_ep
decl_stmt|;
comment|/* back pointer to ep */
name|LIST_ENTRY
argument_list|(
argument|sctp_tcb
argument_list|)
name|sctp_tcbhash
expr_stmt|;
comment|/* next link in hash 							 * table */
name|LIST_ENTRY
argument_list|(
argument|sctp_tcb
argument_list|)
name|sctp_tcblist
expr_stmt|;
comment|/* list of all of the 							 * TCB's */
name|LIST_ENTRY
argument_list|(
argument|sctp_tcb
argument_list|)
name|sctp_tcbrestarhash
expr_stmt|;
comment|/* next link in restart 								 * hash table */
name|LIST_ENTRY
argument_list|(
argument|sctp_tcb
argument_list|)
name|sctp_asocs
expr_stmt|;
comment|/* vtag hash list */
name|struct
name|sctp_block_entry
modifier|*
name|block_entry
decl_stmt|;
comment|/* pointer locked by  socket 						 * send buffer */
name|struct
name|sctp_association
name|asoc
decl_stmt|;
comment|/*- 	 * freed_by_sorcv_sincelast is protected by the sockbuf_lock NOT the 	 * tcb_lock. Its special in this way to help avoid extra mutex calls 	 * in the reading of data. 	 */
name|uint32_t
name|freed_by_sorcv_sincelast
decl_stmt|;
name|uint32_t
name|total_sends
decl_stmt|;
name|uint32_t
name|total_recvs
decl_stmt|;
name|int
name|freed_from_where
decl_stmt|;
name|uint16_t
name|rport
decl_stmt|;
comment|/* remote port in network format */
name|uint16_t
name|resv
decl_stmt|;
name|struct
name|mtx
name|tcb_mtx
decl_stmt|;
name|struct
name|mtx
name|tcb_send_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<netinet/sctp_lock_bsd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|sctp_epinfo
name|sctppcbinfo
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|SCTP6_ARE_ADDR_EQUAL
parameter_list|(
name|struct
name|in6_addr
modifier|*
name|a
parameter_list|,
name|struct
name|in6_addr
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_fill_pcbinfo
parameter_list|(
name|struct
name|sctp_pcbinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_ifn
modifier|*
name|sctp_find_ifn
parameter_list|(
name|struct
name|sctp_vrf
modifier|*
name|vrf
parameter_list|,
name|void
modifier|*
name|ifn
parameter_list|,
name|uint32_t
name|ifn_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_vrf
modifier|*
name|sctp_allocate_vrf
parameter_list|(
name|int
name|vrfid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_vrf
modifier|*
name|sctp_find_vrf
parameter_list|(
name|uint32_t
name|vrfid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_ifa
modifier|*
name|sctp_add_addr_to_vrf
parameter_list|(
name|uint32_t
name|vrfid
parameter_list|,
name|void
modifier|*
name|ifn
parameter_list|,
name|uint32_t
name|ifn_index
parameter_list|,
name|uint32_t
name|ifn_type
parameter_list|,
specifier|const
name|char
modifier|*
name|if_name
parameter_list|,
name|void
modifier|*
name|ifa
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|uint32_t
name|ifa_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_free_ifa
parameter_list|(
name|struct
name|sctp_ifa
modifier|*
name|sctp_ifap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_ifa
modifier|*
name|sctp_del_addr_from_vrf
parameter_list|(
name|uint32_t
name|vrfid
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|uint32_t
name|ifn_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_nets
modifier|*
name|sctp_findnet
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_inpcb
modifier|*
name|sctp_pcb_findep
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_inpcb_bind
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_tcb
modifier|*
name|sctp_findassociation_addr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sctphdr
modifier|*
parameter_list|,
name|struct
name|sctp_chunkhdr
modifier|*
parameter_list|,
name|struct
name|sctp_inpcb
modifier|*
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
modifier|*
parameter_list|,
name|uint32_t
name|vrf_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_tcb
modifier|*
name|sctp_findassociation_addr_sa
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sctp_inpcb
modifier|*
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_move_pcb_and_assoc
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-  * For this call ep_addr, the to is the destination endpoint address of the  * peer (relative to outbound). The from field is only used if the TCP model  * is enabled and helps distingush amongst the subset bound (non-boundall).  * The TCP model MAY change the actual ep field, this is why it is passed.  */
end_comment

begin_function_decl
name|struct
name|sctp_tcb
modifier|*
name|sctp_findassociation_ep_addr
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_tcb
modifier|*
name|sctp_findassociation_ep_asocid
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|sctp_assoc_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_tcb
modifier|*
name|sctp_findassociation_ep_asconf
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sctphdr
modifier|*
parameter_list|,
name|struct
name|sctp_inpcb
modifier|*
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_inpcb_alloc
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_is_address_on_local_host
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|uint32_t
name|vrf_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_inpcb_free
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sctp_tcb
modifier|*
name|sctp_aloc_assoc
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_free_assoc
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_add_vtag_to_timewait
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_add_local_addr_ep
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_ifa
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_insert_laddr
parameter_list|(
name|struct
name|sctpladdr
modifier|*
parameter_list|,
name|struct
name|sctp_ifa
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_remove_laddr
parameter_list|(
name|struct
name|sctp_laddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_del_local_addr_ep
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_ifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_set_initial_cc_param
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_add_remote_addr
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_remove_net
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_del_remote_addr
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_pcb_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_add_local_addr_assoc
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sctp_ifa
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_del_local_addr_assoc
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sctp_ifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_load_addresses_from_init
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sctphdr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_set_primary_addr
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_is_vtag_good
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void sctp_drain(void); */
end_comment

begin_function_decl
name|int
name|sctp_destination_is_reachable
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-  * Null in last arg inpcb indicate run on ALL ep's. Specific inp in last arg  * indicates run on ONLY assoc's of the specified endpoint.  */
end_comment

begin_function_decl
name|int
name|sctp_initiate_iterator
parameter_list|(
name|inp_func
name|inpf
parameter_list|,
name|asoc_func
name|af
parameter_list|,
name|inp_func
name|inpe
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|end_func
name|ef
parameter_list|,
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|uint8_t
name|co_off
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
comment|/* !__sctp_pcb_h__ */
end_comment

end_unit

