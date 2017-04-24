begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993, 1994, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_var.h	8.4 (Berkeley) 5/24/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_VAR_H_
end_define

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_fsm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_comment
comment|/*  * Kernel variables for tcp.  */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_do_rfc1323
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_tcp_do_rfc1323
value|VNET(tcp_do_rfc1323)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* TCP segment queue entry */
end_comment

begin_struct
struct|struct
name|tseg_qent
block|{
name|LIST_ENTRY
argument_list|(
argument|tseg_qent
argument_list|)
name|tqe_q
expr_stmt|;
name|int
name|tqe_len
decl_stmt|;
comment|/* TCP segment data length */
name|struct
name|tcphdr
modifier|*
name|tqe_th
decl_stmt|;
comment|/* a pointer to tcp header */
name|struct
name|mbuf
modifier|*
name|tqe_m
decl_stmt|;
comment|/* mbuf contains packet */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|tsegqe_head
argument_list|,
name|tseg_qent
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sackblk
block|{
name|tcp_seq
name|start
decl_stmt|;
comment|/* start seq no. of sack block */
name|tcp_seq
name|end
decl_stmt|;
comment|/* end seq no. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sackhole
block|{
name|tcp_seq
name|start
decl_stmt|;
comment|/* start seq no. of hole */
name|tcp_seq
name|end
decl_stmt|;
comment|/* end seq no. */
name|tcp_seq
name|rxmit
decl_stmt|;
comment|/* next seq. no in hole to be retransmitted */
name|TAILQ_ENTRY
argument_list|(
argument|sackhole
argument_list|)
name|scblink
expr_stmt|;
comment|/* scoreboard linkage */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sackhint
block|{
name|struct
name|sackhole
modifier|*
name|nexthole
decl_stmt|;
name|int
name|sack_bytes_rexmit
decl_stmt|;
name|tcp_seq
name|last_sack_ack
decl_stmt|;
comment|/* Most recent/largest sacked ack */
name|int
name|ispare
decl_stmt|;
comment|/* explicit pad for 64bit alignment */
name|int
name|sacked_bytes
decl_stmt|;
comment|/* 					 * Total sacked bytes reported by the 					 * receiver via sack option 					 */
name|uint32_t
name|_pad1
index|[
literal|1
index|]
decl_stmt|;
comment|/* TBD */
name|uint64_t
name|_pad
index|[
literal|1
index|]
decl_stmt|;
comment|/* TBD */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcptemp
block|{
name|u_char
name|tt_ipgen
index|[
literal|40
index|]
decl_stmt|;
comment|/* the size must be of max ip header, now IPv6 */
name|struct
name|tcphdr
name|tt_t
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tcp6cb
value|tcpcb
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_comment
comment|/*   * TODO: We yet need to brave plowing in  * to tcp_input() and the pru_usrreq() block.  * Right now these go to the old standards which  * are somewhat ok, but in the long term may  * need to be changed. If we do tackle tcp_input()  * then we need to get rid of the tcp_do_segment()  * function below.  */
end_comment

begin_comment
comment|/* Flags for tcp functions */
end_comment

begin_define
define|#
directive|define
name|TCP_FUNC_BEING_REMOVED
value|0x01
end_define

begin_comment
comment|/* Can no longer be referenced */
end_comment

begin_struct_decl
struct_decl|struct
name|tcpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * If defining the optional tcp_timers, in the  * tfb_tcp_timer_stop call you must use the  * callout_async_drain() function with the  * tcp_timer_discard callback. You should check  * the return of callout_async_drain() and if 0  * increment tt_draincnt. Since the timer sub-system  * does not know your callbacks you must provide a  * stop_all function that loops through and calls  * tcp_timer_stop() with each of your defined timers.  */
end_comment

begin_struct
struct|struct
name|tcp_function_block
block|{
name|char
name|tfb_tcp_block_name
index|[
name|TCP_FUNCTION_NAME_LEN_MAX
index|]
decl_stmt|;
name|int
function_decl|(
modifier|*
name|tfb_tcp_output
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tfb_tcp_do_segment
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|tfb_tcp_ctloutput
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|,
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
comment|/* Optional memory allocation/free routine */
name|void
function_decl|(
modifier|*
name|tfb_tcp_fb_init
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tfb_tcp_fb_fini
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
comment|/* Optional timers, must define all if you define one */
name|int
function_decl|(
modifier|*
name|tfb_tcp_timer_stop_all
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tfb_tcp_timer_activate
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|tfb_tcp_timer_active
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tfb_tcp_timer_stop
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tfb_tcp_rexmit_tmr
function_decl|)
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
specifier|volatile
name|uint32_t
name|tfb_refcnt
decl_stmt|;
name|uint32_t
name|tfb_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcp_function
block|{
name|TAILQ_ENTRY
argument_list|(
argument|tcp_function
argument_list|)
name|tf_next
expr_stmt|;
name|struct
name|tcp_function_block
modifier|*
name|tf_fb
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|tcp_funchead
argument_list|,
name|tcp_function
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Tcp control block, one per tcp; fields:  * Organized for 16 byte cacheline efficiency.  */
end_comment

begin_struct
struct|struct
name|tcpcb
block|{
name|struct
name|tsegqe_head
name|t_segq
decl_stmt|;
comment|/* segment reassembly queue */
name|void
modifier|*
name|t_pspare
index|[
literal|2
index|]
decl_stmt|;
comment|/* new reassembly queue */
name|int
name|t_segqlen
decl_stmt|;
comment|/* segment reassembly queue length */
name|int
name|t_dupacks
decl_stmt|;
comment|/* consecutive dup acks recd */
name|struct
name|tcp_timer
modifier|*
name|t_timers
decl_stmt|;
comment|/* All the TCP timers in one struct */
name|struct
name|inpcb
modifier|*
name|t_inpcb
decl_stmt|;
comment|/* back pointer to internet pcb */
name|int
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|u_int
name|t_flags
decl_stmt|;
name|struct
name|vnet
modifier|*
name|t_vnet
decl_stmt|;
comment|/* back pointer to parent vnet */
name|tcp_seq
name|snd_una
decl_stmt|;
comment|/* sent but unacknowledged */
name|tcp_seq
name|snd_max
decl_stmt|;
comment|/* highest sequence number sent; 					 * used to recognize retransmits 					 */
name|tcp_seq
name|snd_nxt
decl_stmt|;
comment|/* send next */
name|tcp_seq
name|snd_up
decl_stmt|;
comment|/* send urgent pointer */
name|tcp_seq
name|snd_wl1
decl_stmt|;
comment|/* window update seg seq number */
name|tcp_seq
name|snd_wl2
decl_stmt|;
comment|/* window update seg ack number */
name|tcp_seq
name|iss
decl_stmt|;
comment|/* initial send sequence number */
name|tcp_seq
name|irs
decl_stmt|;
comment|/* initial receive sequence number */
name|tcp_seq
name|rcv_nxt
decl_stmt|;
comment|/* receive next */
name|tcp_seq
name|rcv_adv
decl_stmt|;
comment|/* advertised window */
name|u_long
name|rcv_wnd
decl_stmt|;
comment|/* receive window */
name|tcp_seq
name|rcv_up
decl_stmt|;
comment|/* receive urgent pointer */
name|u_long
name|snd_wnd
decl_stmt|;
comment|/* send window */
name|u_long
name|snd_cwnd
decl_stmt|;
comment|/* congestion-controlled window */
name|u_long
name|snd_spare1
decl_stmt|;
comment|/* unused */
name|u_long
name|snd_ssthresh
decl_stmt|;
comment|/* snd_cwnd size threshold for 					 * for slow start exponential to 					 * linear switch 					 */
name|u_long
name|snd_spare2
decl_stmt|;
comment|/* unused */
name|tcp_seq
name|snd_recover
decl_stmt|;
comment|/* for use in NewReno Fast Recovery */
name|u_int
name|t_rcvtime
decl_stmt|;
comment|/* inactivity time */
name|u_int
name|t_starttime
decl_stmt|;
comment|/* time connection was established */
name|u_int
name|t_rtttime
decl_stmt|;
comment|/* RTT measurement start time */
name|tcp_seq
name|t_rtseq
decl_stmt|;
comment|/* sequence number being timed */
name|u_int
name|t_bw_spare1
decl_stmt|;
comment|/* unused */
name|tcp_seq
name|t_bw_spare2
decl_stmt|;
comment|/* unused */
name|int
name|t_rxtcur
decl_stmt|;
comment|/* current retransmit value (ticks) */
name|u_int
name|t_maxseg
decl_stmt|;
comment|/* maximum segment size */
name|u_int
name|t_pmtud_saved_maxseg
decl_stmt|;
comment|/* pre-blackhole MSS */
name|int
name|t_srtt
decl_stmt|;
comment|/* smoothed round-trip time */
name|int
name|t_rttvar
decl_stmt|;
comment|/* variance in round-trip time */
name|int
name|t_rxtshift
decl_stmt|;
comment|/* log(2) of rexmt exp. backoff */
name|u_int
name|t_rttmin
decl_stmt|;
comment|/* minimum rtt allowed */
name|u_int
name|t_rttbest
decl_stmt|;
comment|/* best rtt we've seen */
name|u_long
name|t_rttupdated
decl_stmt|;
comment|/* number of times rtt sampled */
name|u_long
name|max_sndwnd
decl_stmt|;
comment|/* largest window peer has offered */
name|int
name|t_softerror
decl_stmt|;
comment|/* possible error not yet reported */
comment|/* out-of-band data */
name|char
name|t_oobflags
decl_stmt|;
comment|/* have some */
name|char
name|t_iobc
decl_stmt|;
comment|/* input character */
comment|/* RFC 1323 variables */
name|u_char
name|snd_scale
decl_stmt|;
comment|/* window scaling for send window */
name|u_char
name|rcv_scale
decl_stmt|;
comment|/* window scaling for recv window */
name|u_char
name|request_r_scale
decl_stmt|;
comment|/* pending window scaling */
name|u_int32_t
name|ts_recent
decl_stmt|;
comment|/* timestamp echo data */
name|u_int
name|ts_recent_age
decl_stmt|;
comment|/* when last updated */
name|u_int32_t
name|ts_offset
decl_stmt|;
comment|/* our timestamp offset */
name|tcp_seq
name|last_ack_sent
decl_stmt|;
comment|/* experimental */
name|u_long
name|snd_cwnd_prev
decl_stmt|;
comment|/* cwnd prior to retransmit */
name|u_long
name|snd_ssthresh_prev
decl_stmt|;
comment|/* ssthresh prior to retransmit */
name|tcp_seq
name|snd_recover_prev
decl_stmt|;
comment|/* snd_recover prior to retransmit */
name|int
name|t_sndzerowin
decl_stmt|;
comment|/* zero-window updates sent */
name|u_int
name|t_badrxtwin
decl_stmt|;
comment|/* window for retransmit recovery */
name|u_char
name|snd_limited
decl_stmt|;
comment|/* segments limited transmitted */
comment|/* SACK related state */
name|int
name|snd_numholes
decl_stmt|;
comment|/* number of holes seen by sender */
name|TAILQ_HEAD
argument_list|(
argument|sackhole_head
argument_list|,
argument|sackhole
argument_list|)
name|snd_holes
expr_stmt|;
comment|/* SACK scoreboard (sorted) */
name|tcp_seq
name|snd_fack
decl_stmt|;
comment|/* last seq number(+1) sack'd by rcv'r*/
name|int
name|rcv_numsacks
decl_stmt|;
comment|/* # distinct sack blks present */
name|struct
name|sackblk
name|sackblks
index|[
name|MAX_SACK_BLKS
index|]
decl_stmt|;
comment|/* seq nos. of sack blocks */
name|tcp_seq
name|sack_newdata
decl_stmt|;
comment|/* New data xmitted in this recovery 					   episode starts at this seq number */
name|struct
name|sackhint
name|sackhint
decl_stmt|;
comment|/* SACK scoreboard hint */
name|int
name|t_rttlow
decl_stmt|;
comment|/* smallest observerved RTT */
name|u_int32_t
name|rfbuf_ts
decl_stmt|;
comment|/* recv buffer autoscaling timestamp */
name|int
name|rfbuf_cnt
decl_stmt|;
comment|/* recv buffer autoscaling byte count */
name|struct
name|toedev
modifier|*
name|tod
decl_stmt|;
comment|/* toedev handling this connection */
name|int
name|t_sndrexmitpack
decl_stmt|;
comment|/* retransmit packets sent */
name|int
name|t_rcvoopack
decl_stmt|;
comment|/* out-of-order packets received */
name|void
modifier|*
name|t_toe
decl_stmt|;
comment|/* TOE pcb pointer */
name|int
name|t_bytes_acked
decl_stmt|;
comment|/* # bytes acked during current RTT */
name|struct
name|cc_algo
modifier|*
name|cc_algo
decl_stmt|;
comment|/* congestion control algorithm */
name|struct
name|cc_var
modifier|*
name|ccv
decl_stmt|;
comment|/* congestion control specific vars */
name|struct
name|osd
modifier|*
name|osd
decl_stmt|;
comment|/* storage for Khelp module data */
name|u_int
name|t_keepinit
decl_stmt|;
comment|/* time to establish connection */
name|u_int
name|t_keepidle
decl_stmt|;
comment|/* time before keepalive probes begin */
name|u_int
name|t_keepintvl
decl_stmt|;
comment|/* interval between keepalives */
name|u_int
name|t_keepcnt
decl_stmt|;
comment|/* number of keepalives before close */
name|u_int
name|t_tsomax
decl_stmt|;
comment|/* TSO total burst length limit in bytes */
name|u_int
name|t_tsomaxsegcount
decl_stmt|;
comment|/* TSO maximum segment count */
name|u_int
name|t_tsomaxsegsize
decl_stmt|;
comment|/* TSO maximum segment size in bytes */
name|u_int
name|t_flags2
decl_stmt|;
comment|/* More tcpcb flags storage */
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|TCP_RFC7413
argument_list|)
name|uint32_t
name|t_ispare
index|[
literal|6
index|]
decl_stmt|;
comment|/* 5 UTO, 1 TBD */
name|uint64_t
name|t_tfo_cookie
decl_stmt|;
comment|/* TCP Fast Open cookie */
else|#
directive|else
name|uint32_t
name|t_ispare
index|[
literal|8
index|]
decl_stmt|;
comment|/* 5 UTO, 3 TBD */
endif|#
directive|endif
name|struct
name|tcp_function_block
modifier|*
name|t_fb
decl_stmt|;
comment|/* TCP function call block */
name|void
modifier|*
name|t_fb_ptr
decl_stmt|;
comment|/* Pointer to t_fb specific data */
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|TCP_RFC7413
argument_list|)
name|unsigned
name|int
modifier|*
name|t_tfo_pending
decl_stmt|;
comment|/* TCP Fast Open pending counter */
name|void
modifier|*
name|t_pspare2
index|[
literal|1
index|]
decl_stmt|;
comment|/* 1 TCP_SIGNATURE */
else|#
directive|else
name|void
modifier|*
name|t_pspare2
index|[
literal|2
index|]
decl_stmt|;
comment|/* 1 TCP_SIGNATURE, 1 TBD */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|TCPPCAP
argument_list|)
name|struct
name|mbufq
name|t_inpkts
decl_stmt|;
comment|/* List of saved input packets. */
name|struct
name|mbufq
name|t_outpkts
decl_stmt|;
comment|/* List of saved output packets. */
ifdef|#
directive|ifdef
name|_LP64
name|uint64_t
name|_pad
index|[
literal|0
index|]
decl_stmt|;
comment|/* all used! */
else|#
directive|else
name|uint64_t
name|_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* 2 are available */
endif|#
directive|endif
comment|/* _LP64 */
else|#
directive|else
name|uint64_t
name|_pad
index|[
literal|6
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* defined(_KERNEL)&& defined(TCPPCAP) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags and utility macros for the t_flags field.  */
end_comment

begin_define
define|#
directive|define
name|TF_ACKNOW
value|0x000001
end_define

begin_comment
comment|/* ack peer immediately */
end_comment

begin_define
define|#
directive|define
name|TF_DELACK
value|0x000002
end_define

begin_comment
comment|/* ack, but try to delay it */
end_comment

begin_define
define|#
directive|define
name|TF_NODELAY
value|0x000004
end_define

begin_comment
comment|/* don't delay packets to coalesce */
end_comment

begin_define
define|#
directive|define
name|TF_NOOPT
value|0x000008
end_define

begin_comment
comment|/* don't use tcp options */
end_comment

begin_define
define|#
directive|define
name|TF_SENTFIN
value|0x000010
end_define

begin_comment
comment|/* have sent FIN */
end_comment

begin_define
define|#
directive|define
name|TF_REQ_SCALE
value|0x000020
end_define

begin_comment
comment|/* have/will request window scaling */
end_comment

begin_define
define|#
directive|define
name|TF_RCVD_SCALE
value|0x000040
end_define

begin_comment
comment|/* other side has requested scaling */
end_comment

begin_define
define|#
directive|define
name|TF_REQ_TSTMP
value|0x000080
end_define

begin_comment
comment|/* have/will request timestamps */
end_comment

begin_define
define|#
directive|define
name|TF_RCVD_TSTMP
value|0x000100
end_define

begin_comment
comment|/* a timestamp was received in SYN */
end_comment

begin_define
define|#
directive|define
name|TF_SACK_PERMIT
value|0x000200
end_define

begin_comment
comment|/* other side said I could SACK */
end_comment

begin_define
define|#
directive|define
name|TF_NEEDSYN
value|0x000400
end_define

begin_comment
comment|/* send SYN (implicit state) */
end_comment

begin_define
define|#
directive|define
name|TF_NEEDFIN
value|0x000800
end_define

begin_comment
comment|/* send FIN (implicit state) */
end_comment

begin_define
define|#
directive|define
name|TF_NOPUSH
value|0x001000
end_define

begin_comment
comment|/* don't push */
end_comment

begin_define
define|#
directive|define
name|TF_PREVVALID
value|0x002000
end_define

begin_comment
comment|/* saved values for bad rxmit valid */
end_comment

begin_define
define|#
directive|define
name|TF_MORETOCOME
value|0x010000
end_define

begin_comment
comment|/* More data to be appended to sock */
end_comment

begin_define
define|#
directive|define
name|TF_LQ_OVERFLOW
value|0x020000
end_define

begin_comment
comment|/* listen queue overflow */
end_comment

begin_define
define|#
directive|define
name|TF_LASTIDLE
value|0x040000
end_define

begin_comment
comment|/* connection was previously idle */
end_comment

begin_define
define|#
directive|define
name|TF_RXWIN0SENT
value|0x080000
end_define

begin_comment
comment|/* sent a receiver win 0 in response */
end_comment

begin_define
define|#
directive|define
name|TF_FASTRECOVERY
value|0x100000
end_define

begin_comment
comment|/* in NewReno Fast Recovery */
end_comment

begin_define
define|#
directive|define
name|TF_WASFRECOVERY
value|0x200000
end_define

begin_comment
comment|/* was in NewReno Fast Recovery */
end_comment

begin_define
define|#
directive|define
name|TF_SIGNATURE
value|0x400000
end_define

begin_comment
comment|/* require MD5 digests (RFC2385) */
end_comment

begin_define
define|#
directive|define
name|TF_FORCEDATA
value|0x800000
end_define

begin_comment
comment|/* force out a byte */
end_comment

begin_define
define|#
directive|define
name|TF_TSO
value|0x1000000
end_define

begin_comment
comment|/* TSO enabled on this connection */
end_comment

begin_define
define|#
directive|define
name|TF_TOE
value|0x2000000
end_define

begin_comment
comment|/* this connection is offloaded */
end_comment

begin_define
define|#
directive|define
name|TF_ECN_PERMIT
value|0x4000000
end_define

begin_comment
comment|/* connection ECN-ready */
end_comment

begin_define
define|#
directive|define
name|TF_ECN_SND_CWR
value|0x8000000
end_define

begin_comment
comment|/* ECN CWR in queue */
end_comment

begin_define
define|#
directive|define
name|TF_ECN_SND_ECE
value|0x10000000
end_define

begin_comment
comment|/* ECN ECE in queue */
end_comment

begin_define
define|#
directive|define
name|TF_CONGRECOVERY
value|0x20000000
end_define

begin_comment
comment|/* congestion recovery mode */
end_comment

begin_define
define|#
directive|define
name|TF_WASCRECOVERY
value|0x40000000
end_define

begin_comment
comment|/* was in congestion recovery */
end_comment

begin_define
define|#
directive|define
name|TF_FASTOPEN
value|0x80000000
end_define

begin_comment
comment|/* TCP Fast Open indication */
end_comment

begin_define
define|#
directive|define
name|IN_FASTRECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|(t_flags& TF_FASTRECOVERY)
end_define

begin_define
define|#
directive|define
name|ENTER_FASTRECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|t_flags |= TF_FASTRECOVERY
end_define

begin_define
define|#
directive|define
name|EXIT_FASTRECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|t_flags&= ~TF_FASTRECOVERY
end_define

begin_define
define|#
directive|define
name|IN_CONGRECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|(t_flags& TF_CONGRECOVERY)
end_define

begin_define
define|#
directive|define
name|ENTER_CONGRECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|t_flags |= TF_CONGRECOVERY
end_define

begin_define
define|#
directive|define
name|EXIT_CONGRECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|t_flags&= ~TF_CONGRECOVERY
end_define

begin_define
define|#
directive|define
name|IN_RECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|(t_flags& (TF_CONGRECOVERY | TF_FASTRECOVERY))
end_define

begin_define
define|#
directive|define
name|ENTER_RECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|t_flags |= (TF_CONGRECOVERY | TF_FASTRECOVERY)
end_define

begin_define
define|#
directive|define
name|EXIT_RECOVERY
parameter_list|(
name|t_flags
parameter_list|)
value|t_flags&= ~(TF_CONGRECOVERY | TF_FASTRECOVERY)
end_define

begin_define
define|#
directive|define
name|BYTES_THIS_ACK
parameter_list|(
name|tp
parameter_list|,
name|th
parameter_list|)
value|(th->th_ack - tp->snd_una)
end_define

begin_comment
comment|/*  * Flags for the t_oobflags field.  */
end_comment

begin_define
define|#
directive|define
name|TCPOOB_HAVEDATA
value|0x01
end_define

begin_define
define|#
directive|define
name|TCPOOB_HADDATA
value|0x02
end_define

begin_comment
comment|/*  * Flags for PLPMTU handling, t_flags2  */
end_comment

begin_define
define|#
directive|define
name|TF2_PLPMTU_BLACKHOLE
value|0x00000001
end_define

begin_comment
comment|/* Possible PLPMTUD Black Hole. */
end_comment

begin_define
define|#
directive|define
name|TF2_PLPMTU_PMTUD
value|0x00000002
end_define

begin_comment
comment|/* Allowed to attempt PLPMTUD. */
end_comment

begin_define
define|#
directive|define
name|TF2_PLPMTU_MAXSEGSNT
value|0x00000004
end_define

begin_comment
comment|/* Last seg sent was full seg. */
end_comment

begin_comment
comment|/*  * Structure to hold TCP options that are only used during segment  * processing (in tcp_input), but not held in the tcpcb.  * It's basically used to reduce the number of parameters  * to tcp_dooptions and tcp_addoptions.  * The binary order of the to_flags is relevant for packing of the  * options in tcp_addoptions.  */
end_comment

begin_struct
struct|struct
name|tcpopt
block|{
name|u_int32_t
name|to_flags
decl_stmt|;
comment|/* which options are present */
define|#
directive|define
name|TOF_MSS
value|0x0001
comment|/* maximum segment size */
define|#
directive|define
name|TOF_SCALE
value|0x0002
comment|/* window scaling */
define|#
directive|define
name|TOF_SACKPERM
value|0x0004
comment|/* SACK permitted */
define|#
directive|define
name|TOF_TS
value|0x0010
comment|/* timestamp */
define|#
directive|define
name|TOF_SIGNATURE
value|0x0040
comment|/* TCP-MD5 signature option (RFC2385) */
define|#
directive|define
name|TOF_SACK
value|0x0080
comment|/* Peer sent SACK option */
define|#
directive|define
name|TOF_FASTOPEN
value|0x0100
comment|/* TCP Fast Open (TFO) cookie */
define|#
directive|define
name|TOF_MAXOPT
value|0x0200
name|u_int32_t
name|to_tsval
decl_stmt|;
comment|/* new timestamp */
name|u_int32_t
name|to_tsecr
decl_stmt|;
comment|/* reflected timestamp */
name|u_char
modifier|*
name|to_sacks
decl_stmt|;
comment|/* pointer to the first SACK blocks */
name|u_char
modifier|*
name|to_signature
decl_stmt|;
comment|/* pointer to the TCP-MD5 signature */
name|u_char
modifier|*
name|to_tfo_cookie
decl_stmt|;
comment|/* pointer to the TFO cookie */
name|u_int16_t
name|to_mss
decl_stmt|;
comment|/* maximum segment size */
name|u_int8_t
name|to_wscale
decl_stmt|;
comment|/* window scaling */
name|u_int8_t
name|to_nsacks
decl_stmt|;
comment|/* number of SACK blocks */
name|u_int8_t
name|to_tfo_len
decl_stmt|;
comment|/* TFO cookie length */
name|u_int32_t
name|to_spare
decl_stmt|;
comment|/* UTO */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for tcp_dooptions.  */
end_comment

begin_define
define|#
directive|define
name|TO_SYN
value|0x01
end_define

begin_comment
comment|/* parse SYN-only options */
end_comment

begin_struct
struct|struct
name|hc_metrics_lite
block|{
comment|/* must stay in sync with hc_metrics */
name|u_long
name|rmx_mtu
decl_stmt|;
comment|/* MTU for this path */
name|u_long
name|rmx_ssthresh
decl_stmt|;
comment|/* outbound gateway buffer limit */
name|u_long
name|rmx_rtt
decl_stmt|;
comment|/* estimated round trip time */
name|u_long
name|rmx_rttvar
decl_stmt|;
comment|/* estimated rtt variance */
name|u_long
name|rmx_cwnd
decl_stmt|;
comment|/* congestion window */
name|u_long
name|rmx_sendpipe
decl_stmt|;
comment|/* outbound delay-bandwidth product */
name|u_long
name|rmx_recvpipe
decl_stmt|;
comment|/* inbound delay-bandwidth product */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used by tcp_maxmtu() to communicate interface specific features  * and limits at the time of connection setup.  */
end_comment

begin_struct
struct|struct
name|tcp_ifcap
block|{
name|int
name|ifcap
decl_stmt|;
name|u_int
name|tsomax
decl_stmt|;
name|u_int
name|tsomaxsegcount
decl_stmt|;
name|u_int
name|tsomaxsegsize
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_PCB_H_
end_ifndef

begin_struct_decl
struct_decl|struct
name|in_conninfo
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IN_PCB_H_ */
end_comment

begin_struct
struct|struct
name|tcptw
block|{
name|struct
name|inpcb
modifier|*
name|tw_inpcb
decl_stmt|;
comment|/* XXX back pointer to internet pcb */
name|tcp_seq
name|snd_nxt
decl_stmt|;
name|tcp_seq
name|rcv_nxt
decl_stmt|;
name|tcp_seq
name|iss
decl_stmt|;
name|tcp_seq
name|irs
decl_stmt|;
name|u_short
name|last_win
decl_stmt|;
comment|/* cached window value */
name|u_short
name|tw_so_options
decl_stmt|;
comment|/* copy of so_options */
name|struct
name|ucred
modifier|*
name|tw_cred
decl_stmt|;
comment|/* user credentials */
name|u_int32_t
name|t_recent
decl_stmt|;
name|u_int32_t
name|ts_offset
decl_stmt|;
comment|/* our timestamp offset */
name|u_int
name|t_starttime
decl_stmt|;
name|int
name|tw_time
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|tcptw
argument_list|)
name|tw_2msl
expr_stmt|;
name|void
modifier|*
name|tw_pspare
decl_stmt|;
comment|/* TCP_SIGNATURE */
name|u_int
modifier|*
name|tw_spare
decl_stmt|;
comment|/* TCP_SIGNATURE */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|intotcpcb
parameter_list|(
name|ip
parameter_list|)
value|((struct tcpcb *)(ip)->inp_ppcb)
end_define

begin_define
define|#
directive|define
name|intotw
parameter_list|(
name|ip
parameter_list|)
value|((struct tcptw *)(ip)->inp_ppcb)
end_define

begin_define
define|#
directive|define
name|sototcpcb
parameter_list|(
name|so
parameter_list|)
value|(intotcpcb(sotoinpcb(so)))
end_define

begin_comment
comment|/*  * The smoothed round-trip time and estimated variance  * are stored as fixed point numbers scaled by the values below.  * For convenience, these scales are also used in smoothing the average  * (smoothed = (1/scale)sample + ((scale-1)/scale)smoothed).  * With these scales, srtt has 3 bits to the right of the binary point,  * and thus an "ALPHA" of 0.875.  rttvar has 2 bits to the right of the  * binary point, and is smoothed with an ALPHA of 0.75.  */
end_comment

begin_define
define|#
directive|define
name|TCP_RTT_SCALE
value|32
end_define

begin_comment
comment|/* multiplier for srtt; 3 bits frac. */
end_comment

begin_define
define|#
directive|define
name|TCP_RTT_SHIFT
value|5
end_define

begin_comment
comment|/* shift for srtt; 3 bits frac. */
end_comment

begin_define
define|#
directive|define
name|TCP_RTTVAR_SCALE
value|16
end_define

begin_comment
comment|/* multiplier for rttvar; 2 bits */
end_comment

begin_define
define|#
directive|define
name|TCP_RTTVAR_SHIFT
value|4
end_define

begin_comment
comment|/* shift for rttvar; 2 bits */
end_comment

begin_define
define|#
directive|define
name|TCP_DELTA_SHIFT
value|2
end_define

begin_comment
comment|/* see tcp_input.c */
end_comment

begin_comment
comment|/*  * The initial retransmission should happen at rtt + 4 * rttvar.  * Because of the way we do the smoothing, srtt and rttvar  * will each average +1/2 tick of bias.  When we compute  * the retransmit timer, we want 1/2 tick of rounding and  * 1 extra tick because of +-1/2 tick uncertainty in the  * firing of the timer.  The bias will give us exactly the  * 1.5 tick we need.  But, because the bias is  * statistical, we have to test that we don't drop below  * the minimum feasible timer (which is 2 ticks).  * This version of the macro adapted from a paper by Lawrence  * Brakmo and Larry Peterson which outlines a problem caused  * by insufficient precision in the original implementation,  * which results in inappropriately large RTO values for very  * fast networks.  */
end_comment

begin_define
define|#
directive|define
name|TCP_REXMTVAL
parameter_list|(
name|tp
parameter_list|)
define|\
value|max((tp)->t_rttmin, (((tp)->t_srtt>> (TCP_RTT_SHIFT - TCP_DELTA_SHIFT))  \ 	  + (tp)->t_rttvar)>> TCP_DELTA_SHIFT)
end_define

begin_comment
comment|/*  * TCP statistics.  * Many of these should be kept per connection,  * but that's inconvenient at the moment.  */
end_comment

begin_struct
struct|struct
name|tcpstat
block|{
name|uint64_t
name|tcps_connattempt
decl_stmt|;
comment|/* connections initiated */
name|uint64_t
name|tcps_accepts
decl_stmt|;
comment|/* connections accepted */
name|uint64_t
name|tcps_connects
decl_stmt|;
comment|/* connections established */
name|uint64_t
name|tcps_drops
decl_stmt|;
comment|/* connections dropped */
name|uint64_t
name|tcps_conndrops
decl_stmt|;
comment|/* embryonic connections dropped */
name|uint64_t
name|tcps_minmssdrops
decl_stmt|;
comment|/* average minmss too low drops */
name|uint64_t
name|tcps_closed
decl_stmt|;
comment|/* conn. closed (includes drops) */
name|uint64_t
name|tcps_segstimed
decl_stmt|;
comment|/* segs where we tried to get rtt */
name|uint64_t
name|tcps_rttupdated
decl_stmt|;
comment|/* times we succeeded */
name|uint64_t
name|tcps_delack
decl_stmt|;
comment|/* delayed acks sent */
name|uint64_t
name|tcps_timeoutdrop
decl_stmt|;
comment|/* conn. dropped in rxmt timeout */
name|uint64_t
name|tcps_rexmttimeo
decl_stmt|;
comment|/* retransmit timeouts */
name|uint64_t
name|tcps_persisttimeo
decl_stmt|;
comment|/* persist timeouts */
name|uint64_t
name|tcps_keeptimeo
decl_stmt|;
comment|/* keepalive timeouts */
name|uint64_t
name|tcps_keepprobe
decl_stmt|;
comment|/* keepalive probes sent */
name|uint64_t
name|tcps_keepdrops
decl_stmt|;
comment|/* connections dropped in keepalive */
name|uint64_t
name|tcps_sndtotal
decl_stmt|;
comment|/* total packets sent */
name|uint64_t
name|tcps_sndpack
decl_stmt|;
comment|/* data packets sent */
name|uint64_t
name|tcps_sndbyte
decl_stmt|;
comment|/* data bytes sent */
name|uint64_t
name|tcps_sndrexmitpack
decl_stmt|;
comment|/* data packets retransmitted */
name|uint64_t
name|tcps_sndrexmitbyte
decl_stmt|;
comment|/* data bytes retransmitted */
name|uint64_t
name|tcps_sndrexmitbad
decl_stmt|;
comment|/* unnecessary packet retransmissions */
name|uint64_t
name|tcps_sndacks
decl_stmt|;
comment|/* ack-only packets sent */
name|uint64_t
name|tcps_sndprobe
decl_stmt|;
comment|/* window probes sent */
name|uint64_t
name|tcps_sndurg
decl_stmt|;
comment|/* packets sent with URG only */
name|uint64_t
name|tcps_sndwinup
decl_stmt|;
comment|/* window update-only packets sent */
name|uint64_t
name|tcps_sndctrl
decl_stmt|;
comment|/* control (SYN|FIN|RST) packets sent */
name|uint64_t
name|tcps_rcvtotal
decl_stmt|;
comment|/* total packets received */
name|uint64_t
name|tcps_rcvpack
decl_stmt|;
comment|/* packets received in sequence */
name|uint64_t
name|tcps_rcvbyte
decl_stmt|;
comment|/* bytes received in sequence */
name|uint64_t
name|tcps_rcvbadsum
decl_stmt|;
comment|/* packets received with ccksum errs */
name|uint64_t
name|tcps_rcvbadoff
decl_stmt|;
comment|/* packets received with bad offset */
name|uint64_t
name|tcps_rcvreassfull
decl_stmt|;
comment|/* packets dropped for no reass space */
name|uint64_t
name|tcps_rcvshort
decl_stmt|;
comment|/* packets received too short */
name|uint64_t
name|tcps_rcvduppack
decl_stmt|;
comment|/* duplicate-only packets received */
name|uint64_t
name|tcps_rcvdupbyte
decl_stmt|;
comment|/* duplicate-only bytes received */
name|uint64_t
name|tcps_rcvpartduppack
decl_stmt|;
comment|/* packets with some duplicate data */
name|uint64_t
name|tcps_rcvpartdupbyte
decl_stmt|;
comment|/* dup. bytes in part-dup. packets */
name|uint64_t
name|tcps_rcvoopack
decl_stmt|;
comment|/* out-of-order packets received */
name|uint64_t
name|tcps_rcvoobyte
decl_stmt|;
comment|/* out-of-order bytes received */
name|uint64_t
name|tcps_rcvpackafterwin
decl_stmt|;
comment|/* packets with data after window */
name|uint64_t
name|tcps_rcvbyteafterwin
decl_stmt|;
comment|/* bytes rcvd after window */
name|uint64_t
name|tcps_rcvafterclose
decl_stmt|;
comment|/* packets rcvd after "close" */
name|uint64_t
name|tcps_rcvwinprobe
decl_stmt|;
comment|/* rcvd window probe packets */
name|uint64_t
name|tcps_rcvdupack
decl_stmt|;
comment|/* rcvd duplicate acks */
name|uint64_t
name|tcps_rcvacktoomuch
decl_stmt|;
comment|/* rcvd acks for unsent data */
name|uint64_t
name|tcps_rcvackpack
decl_stmt|;
comment|/* rcvd ack packets */
name|uint64_t
name|tcps_rcvackbyte
decl_stmt|;
comment|/* bytes acked by rcvd acks */
name|uint64_t
name|tcps_rcvwinupd
decl_stmt|;
comment|/* rcvd window update packets */
name|uint64_t
name|tcps_pawsdrop
decl_stmt|;
comment|/* segments dropped due to PAWS */
name|uint64_t
name|tcps_predack
decl_stmt|;
comment|/* times hdr predict ok for acks */
name|uint64_t
name|tcps_preddat
decl_stmt|;
comment|/* times hdr predict ok for data pkts */
name|uint64_t
name|tcps_pcbcachemiss
decl_stmt|;
name|uint64_t
name|tcps_cachedrtt
decl_stmt|;
comment|/* times cached RTT in route updated */
name|uint64_t
name|tcps_cachedrttvar
decl_stmt|;
comment|/* times cached rttvar updated */
name|uint64_t
name|tcps_cachedssthresh
decl_stmt|;
comment|/* times cached ssthresh updated */
name|uint64_t
name|tcps_usedrtt
decl_stmt|;
comment|/* times RTT initialized from route */
name|uint64_t
name|tcps_usedrttvar
decl_stmt|;
comment|/* times RTTVAR initialized from rt */
name|uint64_t
name|tcps_usedssthresh
decl_stmt|;
comment|/* times ssthresh initialized from rt*/
name|uint64_t
name|tcps_persistdrop
decl_stmt|;
comment|/* timeout in persist state */
name|uint64_t
name|tcps_badsyn
decl_stmt|;
comment|/* bogus SYN, e.g. premature ACK */
name|uint64_t
name|tcps_mturesent
decl_stmt|;
comment|/* resends due to MTU discovery */
name|uint64_t
name|tcps_listendrop
decl_stmt|;
comment|/* listen queue overflows */
name|uint64_t
name|tcps_badrst
decl_stmt|;
comment|/* ignored RSTs in the window */
name|uint64_t
name|tcps_sc_added
decl_stmt|;
comment|/* entry added to syncache */
name|uint64_t
name|tcps_sc_retransmitted
decl_stmt|;
comment|/* syncache entry was retransmitted */
name|uint64_t
name|tcps_sc_dupsyn
decl_stmt|;
comment|/* duplicate SYN packet */
name|uint64_t
name|tcps_sc_dropped
decl_stmt|;
comment|/* could not reply to packet */
name|uint64_t
name|tcps_sc_completed
decl_stmt|;
comment|/* successful extraction of entry */
name|uint64_t
name|tcps_sc_bucketoverflow
decl_stmt|;
comment|/* syncache per-bucket limit hit */
name|uint64_t
name|tcps_sc_cacheoverflow
decl_stmt|;
comment|/* syncache cache limit hit */
name|uint64_t
name|tcps_sc_reset
decl_stmt|;
comment|/* RST removed entry from syncache */
name|uint64_t
name|tcps_sc_stale
decl_stmt|;
comment|/* timed out or listen socket gone */
name|uint64_t
name|tcps_sc_aborted
decl_stmt|;
comment|/* syncache entry aborted */
name|uint64_t
name|tcps_sc_badack
decl_stmt|;
comment|/* removed due to bad ACK */
name|uint64_t
name|tcps_sc_unreach
decl_stmt|;
comment|/* ICMP unreachable received */
name|uint64_t
name|tcps_sc_zonefail
decl_stmt|;
comment|/* zalloc() failed */
name|uint64_t
name|tcps_sc_sendcookie
decl_stmt|;
comment|/* SYN cookie sent */
name|uint64_t
name|tcps_sc_recvcookie
decl_stmt|;
comment|/* SYN cookie received */
name|uint64_t
name|tcps_hc_added
decl_stmt|;
comment|/* entry added to hostcache */
name|uint64_t
name|tcps_hc_bucketoverflow
decl_stmt|;
comment|/* hostcache per bucket limit hit */
name|uint64_t
name|tcps_finwait2_drops
decl_stmt|;
comment|/* Drop FIN_WAIT_2 connection after time limit */
comment|/* SACK related stats */
name|uint64_t
name|tcps_sack_recovery_episode
decl_stmt|;
comment|/* SACK recovery episodes */
name|uint64_t
name|tcps_sack_rexmits
decl_stmt|;
comment|/* SACK rexmit segments   */
name|uint64_t
name|tcps_sack_rexmit_bytes
decl_stmt|;
comment|/* SACK rexmit bytes      */
name|uint64_t
name|tcps_sack_rcv_blocks
decl_stmt|;
comment|/* SACK blocks (options) received */
name|uint64_t
name|tcps_sack_send_blocks
decl_stmt|;
comment|/* SACK blocks (options) sent     */
name|uint64_t
name|tcps_sack_sboverflow
decl_stmt|;
comment|/* times scoreboard overflowed */
comment|/* ECN related stats */
name|uint64_t
name|tcps_ecn_ce
decl_stmt|;
comment|/* ECN Congestion Experienced */
name|uint64_t
name|tcps_ecn_ect0
decl_stmt|;
comment|/* ECN Capable Transport */
name|uint64_t
name|tcps_ecn_ect1
decl_stmt|;
comment|/* ECN Capable Transport */
name|uint64_t
name|tcps_ecn_shs
decl_stmt|;
comment|/* ECN successful handshakes */
name|uint64_t
name|tcps_ecn_rcwnd
decl_stmt|;
comment|/* # times ECN reduced the cwnd */
comment|/* TCP_SIGNATURE related stats */
name|uint64_t
name|tcps_sig_rcvgoodsig
decl_stmt|;
comment|/* Total matching signature received */
name|uint64_t
name|tcps_sig_rcvbadsig
decl_stmt|;
comment|/* Total bad signature received */
name|uint64_t
name|tcps_sig_err_buildsig
decl_stmt|;
comment|/* Failed to make signature */
name|uint64_t
name|tcps_sig_err_sigopt
decl_stmt|;
comment|/* No signature expected by socket */
name|uint64_t
name|tcps_sig_err_nosigopt
decl_stmt|;
comment|/* No signature provided by segment */
name|uint64_t
name|_pad
index|[
literal|12
index|]
decl_stmt|;
comment|/* 6 UTO, 6 TBD */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tcps_rcvmemdrop
value|tcps_rcvreassfull
end_define

begin_comment
comment|/* compat */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|TI_UNLOCKED
value|1
end_define

begin_define
define|#
directive|define
name|TI_RLOCKED
value|2
end_define

begin_include
include|#
directive|include
file|<sys/counter.h>
end_include

begin_expr_stmt
name|VNET_PCPUSTAT_DECLARE
argument_list|(
expr|struct
name|tcpstat
argument_list|,
name|tcpstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* tcp statistics */
end_comment

begin_comment
comment|/*  * In-kernel consumers can use these accessor macros directly to update  * stats.  */
end_comment

begin_define
define|#
directive|define
name|TCPSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|VNET_PCPUSTAT_ADD(struct tcpstat, tcpstat, name, (val))
end_define

begin_define
define|#
directive|define
name|TCPSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|TCPSTAT_ADD(name, 1)
end_define

begin_comment
comment|/*  * Kernel module consumers must use this accessor macro.  */
end_comment

begin_function_decl
name|void
name|kmod_tcpstat_inc
parameter_list|(
name|int
name|statnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KMOD_TCPSTAT_INC
parameter_list|(
name|name
parameter_list|)
define|\
value|kmod_tcpstat_inc(offsetof(struct tcpstat, name) / sizeof(uint64_t))
end_define

begin_comment
comment|/*  * Running TCP connection count by state.  */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|counter_u64_t
argument_list|,
name|tcps_states
index|[
name|TCP_NSTATES
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_tcps_states
value|VNET(tcps_states)
end_define

begin_define
define|#
directive|define
name|TCPSTATES_INC
parameter_list|(
name|state
parameter_list|)
value|counter_u64_add(V_tcps_states[state], 1)
end_define

begin_define
define|#
directive|define
name|TCPSTATES_DEC
parameter_list|(
name|state
parameter_list|)
value|counter_u64_add(V_tcps_states[state], -1)
end_define

begin_comment
comment|/*  * TCP specific helper hook point identifiers.  */
end_comment

begin_define
define|#
directive|define
name|HHOOK_TCP_EST_IN
value|0
end_define

begin_define
define|#
directive|define
name|HHOOK_TCP_EST_OUT
value|1
end_define

begin_define
define|#
directive|define
name|HHOOK_TCP_LAST
value|HHOOK_TCP_EST_OUT
end_define

begin_struct
struct|struct
name|tcp_hhook_data
block|{
name|struct
name|tcpcb
modifier|*
name|tp
decl_stmt|;
name|struct
name|tcphdr
modifier|*
name|th
decl_stmt|;
name|struct
name|tcpopt
modifier|*
name|to
decl_stmt|;
name|long
name|len
decl_stmt|;
name|int
name|tso
decl_stmt|;
name|tcp_seq
name|curack
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * TCB structure exported to user-land via sysctl(3).  * Evil hack: declare only if in_pcb.h and sys/socketvar.h have been  * included.  Not all of our clients do.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NETINET_IN_PCB_H_
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SYS_SOCKETVAR_H_
argument_list|)
end_if

begin_struct
struct|struct
name|xtcp_timer
block|{
name|int
name|tt_rexmt
decl_stmt|;
comment|/* retransmit timer */
name|int
name|tt_persist
decl_stmt|;
comment|/* retransmit persistence */
name|int
name|tt_keep
decl_stmt|;
comment|/* keepalive */
name|int
name|tt_2msl
decl_stmt|;
comment|/* 2*msl TIME_WAIT timer */
name|int
name|tt_delack
decl_stmt|;
comment|/* delayed ACK timer */
name|int
name|t_rcvtime
decl_stmt|;
comment|/* Time since last packet received */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xtcpcb
block|{
name|size_t
name|xt_len
decl_stmt|;
name|struct
name|inpcb
name|xt_inp
decl_stmt|;
name|struct
name|tcpcb
name|xt_tp
decl_stmt|;
name|struct
name|xsocket
name|xt_socket
decl_stmt|;
name|struct
name|xtcp_timer
name|xt_timer
decl_stmt|;
name|u_quad_t
name|xt_alignment_hack
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Identifiers for TCP sysctl nodes  */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DO_RFC1323
value|1
end_define

begin_comment
comment|/* use RFC-1323 extensions */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_MSSDFLT
value|3
end_define

begin_comment
comment|/* MSS default */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_STATS
value|4
end_define

begin_comment
comment|/* statistics */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_RTTDFLT
value|5
end_define

begin_comment
comment|/* default RTT estimate */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_KEEPIDLE
value|6
end_define

begin_comment
comment|/* keepalive idle timer */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_KEEPINTVL
value|7
end_define

begin_comment
comment|/* interval to send keepalives */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_SENDSPACE
value|8
end_define

begin_comment
comment|/* send buffer space */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_RECVSPACE
value|9
end_define

begin_comment
comment|/* receive buffer space */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_KEEPINIT
value|10
end_define

begin_comment
comment|/* timeout for establishing syn */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_PCBLIST
value|11
end_define

begin_comment
comment|/* list of all outstanding PCBs */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DELACKTIME
value|12
end_define

begin_comment
comment|/* time before sending delayed ACK */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_V6MSSDFLT
value|13
end_define

begin_comment
comment|/* MSS default for IPv6 */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_SACK
value|14
end_define

begin_comment
comment|/* Selective Acknowledgement,rfc 2018 */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DROP
value|15
end_define

begin_comment
comment|/* drop tcp connection */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_STATES
value|16
end_define

begin_comment
comment|/* connection counts by TCP state */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_tcp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_tcp_sack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_TCPLOG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|inpcbhead
argument_list|,
name|tcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* queue of active tcpcb's */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|inpcbinfo
argument_list|,
name|tcbinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_log_in_vain
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_mssdflt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_minmss
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_delack_enabled
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_do_rfc3390
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_initcwnd_segments
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_sendspace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_recvspace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|path_mtu_discovery
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_do_rfc3465
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_abc_l_var
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_tcb
value|VNET(tcb)
end_define

begin_define
define|#
directive|define
name|V_tcbinfo
value|VNET(tcbinfo)
end_define

begin_define
define|#
directive|define
name|V_tcp_mssdflt
value|VNET(tcp_mssdflt)
end_define

begin_define
define|#
directive|define
name|V_tcp_minmss
value|VNET(tcp_minmss)
end_define

begin_define
define|#
directive|define
name|V_tcp_delack_enabled
value|VNET(tcp_delack_enabled)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3390
value|VNET(tcp_do_rfc3390)
end_define

begin_define
define|#
directive|define
name|V_tcp_initcwnd_segments
value|VNET(tcp_initcwnd_segments)
end_define

begin_define
define|#
directive|define
name|V_tcp_sendspace
value|VNET(tcp_sendspace)
end_define

begin_define
define|#
directive|define
name|V_tcp_recvspace
value|VNET(tcp_recvspace)
end_define

begin_define
define|#
directive|define
name|V_path_mtu_discovery
value|VNET(path_mtu_discovery)
end_define

begin_define
define|#
directive|define
name|V_tcp_do_rfc3465
value|VNET(tcp_do_rfc3465)
end_define

begin_define
define|#
directive|define
name|V_tcp_abc_l_var
value|VNET(tcp_abc_l_var)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_do_sack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SACK enabled/disabled */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_sc_rst_sock_fail
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* RST on sock alloc failure */
end_comment

begin_define
define|#
directive|define
name|V_tcp_do_sack
value|VNET(tcp_do_sack)
end_define

begin_define
define|#
directive|define
name|V_tcp_sc_rst_sock_fail
value|VNET(tcp_sc_rst_sock_fail)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_do_ecn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* TCP ECN enabled/disabled */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_ecn_maxretries
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_tcp_do_ecn
value|VNET(tcp_do_ecn)
end_define

begin_define
define|#
directive|define
name|V_tcp_ecn_maxretries
value|VNET(tcp_ecn_maxretries)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|hhook_head
operator|*
argument_list|,
name|tcp_hhh
index|[
name|HHOOK_TCP_LAST
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_tcp_hhh
value|VNET(tcp_hhh)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|tcp_do_rfc6675_pipe
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_tcp_do_rfc6675_pipe
value|VNET(tcp_do_rfc6675_pipe)
end_define

begin_function_decl
name|int
name|tcp_addoptions
parameter_list|(
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_ccalgounload
parameter_list|(
name|struct
name|cc_algo
modifier|*
name|unload_algo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|tcp_close
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_discardcb
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_twstart
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_twclose
parameter_list|(
name|struct
name|tcptw
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|tcp_drop
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_fini
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tcp_log_addrs
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tcp_log_vain
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_reass
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_reass_global_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_reass_flush
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_dooptions
parameter_list|(
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|u_char
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
name|tcp_dropwithreset
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|tcpcb
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
name|tcp_pulloutofband
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|tcphdr
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
name|tcp_xmit_timer
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_newreno_partial_ack
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cc_ack_received
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|struct
name|tcphdr
modifier|*
name|th
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cc_conn_init
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cc_post_recovery
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|struct
name|tcphdr
modifier|*
name|th
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cc_cong_signal
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|struct
name|tcphdr
modifier|*
name|th
parameter_list|,
name|uint32_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hhook_run_tcp_est_in
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|struct
name|tcphdr
modifier|*
name|th
parameter_list|,
name|struct
name|tcpopt
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_autorcvbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_do_segment
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_tcp_functions
parameter_list|(
name|struct
name|tcp_function_block
modifier|*
name|blk
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|deregister_tcp_functions
parameter_list|(
name|struct
name|tcp_function_block
modifier|*
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcp_function_block
modifier|*
name|find_and_ref_tcp_functions
parameter_list|(
name|struct
name|tcp_function_set
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcp_function_block
modifier|*
name|find_and_ref_tcp_fb
parameter_list|(
name|struct
name|tcp_function_block
modifier|*
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_default_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|,
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|tcp_maxmtu
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcp_ifcap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|tcp_maxmtu6
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcp_ifcap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|tcp_maxseg
parameter_list|(
specifier|const
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_mss_update
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|hc_metrics_lite
modifier|*
parameter_list|,
name|struct
name|tcp_ifcap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_mss
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_mssopt
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inpcb
modifier|*
name|tcp_drop_syn_sent
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|tcp_newtcpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_output
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_state_change
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_respond
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|tcp_seq
parameter_list|,
name|tcp_seq
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_tw_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|void
name|tcp_tw_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|tcp_tw_zone_change
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_twcheck
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
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
name|tcp_setpersist
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcptemp
modifier|*
name|tcpip_maketemplate
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcpip_fillheaders
parameter_list|(
name|struct
name|inpcb
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

begin_function_decl
name|void
name|tcp_timer_activate
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_timer_active
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_timer_stop
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_trace
parameter_list|(
name|short
parameter_list|,
name|short
parameter_list|,
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * All tcp_hc_* functions are IPv4 and IPv6 (via in_conninfo)  */
end_comment

begin_function_decl
name|void
name|tcp_hc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|void
name|tcp_hc_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|tcp_hc_get
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|hc_metrics_lite
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|tcp_hc_getmtu
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_hc_updatemtu
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_hc_update
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|hc_metrics_lite
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|tcp_usrreqs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|tcp_seq
name|tcp_new_isn
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_sack_doack
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|tcp_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_update_sack_list
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|tcp_seq
name|rcv_laststart
parameter_list|,
name|tcp_seq
name|rcv_lastend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_clean_sackreport
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_sack_adjust
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sackhole
modifier|*
name|tcp_sack_output
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|int
modifier|*
name|sack_bytes_rexmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_sack_partialack
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_free_sackholes
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_newreno
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_compute_pipe
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|tcp_fields_to_host
parameter_list|(
name|struct
name|tcphdr
modifier|*
name|th
parameter_list|)
block|{
name|th
operator|->
name|th_seq
operator|=
name|ntohl
argument_list|(
name|th
operator|->
name|th_seq
argument_list|)
expr_stmt|;
name|th
operator|->
name|th_ack
operator|=
name|ntohl
argument_list|(
name|th
operator|->
name|th_ack
argument_list|)
expr_stmt|;
name|th
operator|->
name|th_win
operator|=
name|ntohs
argument_list|(
name|th
operator|->
name|th_win
argument_list|)
expr_stmt|;
name|th
operator|->
name|th_urp
operator|=
name|ntohs
argument_list|(
name|th
operator|->
name|th_urp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|tcp_fields_to_net
parameter_list|(
name|struct
name|tcphdr
modifier|*
name|th
parameter_list|)
block|{
name|th
operator|->
name|th_seq
operator|=
name|htonl
argument_list|(
name|th
operator|->
name|th_seq
argument_list|)
expr_stmt|;
name|th
operator|->
name|th_ack
operator|=
name|htonl
argument_list|(
name|th
operator|->
name|th_ack
argument_list|)
expr_stmt|;
name|th
operator|->
name|th_win
operator|=
name|htons
argument_list|(
name|th
operator|->
name|th_win
argument_list|)
expr_stmt|;
name|th
operator|->
name|th_urp
operator|=
name|htons
argument_list|(
name|th
operator|->
name|th_urp
argument_list|)
expr_stmt|;
block|}
end_function

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
comment|/* _NETINET_TCP_VAR_H_ */
end_comment

end_unit

