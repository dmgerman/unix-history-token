begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_stat.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_STAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_STAT_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_stat.h,v $  *  * Here are the data structures in which the global  * statistics(counters) are gathered.  */
end_comment

begin_struct
struct|struct
name|tp_stat
block|{
name|u_long
name|ts_param_ignored
decl_stmt|;
name|u_long
name|ts_unused3
decl_stmt|;
name|u_long
name|ts_bad_csum
decl_stmt|;
name|u_long
name|ts_inv_length
decl_stmt|;
name|u_long
name|ts_inv_pcode
decl_stmt|;
name|u_long
name|ts_inv_dutype
decl_stmt|;
name|u_long
name|ts_negotfailed
decl_stmt|;
name|u_long
name|ts_inv_dref
decl_stmt|;
name|u_long
name|ts_inv_pval
decl_stmt|;
name|u_long
name|ts_inv_sufx
decl_stmt|;
name|u_long
name|ts_inv_aclass
decl_stmt|;
name|u_long
name|ts_xtd_fmt
decl_stmt|;
name|u_long
name|ts_use_txpd
decl_stmt|;
name|u_long
name|ts_csum_off
decl_stmt|;
name|u_long
name|ts_send_drop
decl_stmt|;
name|u_long
name|ts_recv_drop
decl_stmt|;
name|u_long
name|ts_xpd_intheway
decl_stmt|;
comment|/* xpd mark caused data flow to stop */
name|u_long
name|ts_xpdmark_del
decl_stmt|;
comment|/* xpd markers thrown away */
name|u_long
name|ts_dt_ooo
decl_stmt|;
comment|/* dt tpdus received out of order */
name|u_long
name|ts_dt_niw
decl_stmt|;
comment|/* dt tpdus received& not in window */
name|u_long
name|ts_xpd_niw
decl_stmt|;
comment|/* xpd tpdus received& not in window */
name|u_long
name|ts_xpd_dup
decl_stmt|;
name|u_long
name|ts_dt_dup
decl_stmt|;
comment|/* dt tpdus received& are duplicates */
name|u_long
name|ts_zfcdt
decl_stmt|;
comment|/* # times f credit went down to 0 */
name|u_long
name|ts_lcdt_reduced
decl_stmt|;
comment|/* 		# times local cdt reduced on an acknowledgement. 		*/
name|u_long
name|ts_pkt_rcvd
decl_stmt|;
comment|/* from ip */
name|u_long
name|ts_tpdu_rcvd
decl_stmt|;
comment|/* accepted as a TPDU in tp_input */
name|u_long
name|ts_tpdu_sent
decl_stmt|;
name|u_long
name|ts_unused2
decl_stmt|;
name|u_long
name|ts_retrans_cr
decl_stmt|;
name|u_long
name|ts_retrans_cc
decl_stmt|;
name|u_long
name|ts_retrans_dr
decl_stmt|;
name|u_long
name|ts_retrans_dt
decl_stmt|;
name|u_long
name|ts_retrans_xpd
decl_stmt|;
name|u_long
name|ts_conn_gaveup
decl_stmt|;
name|u_long
name|ts_ER_sent
decl_stmt|;
name|u_long
name|ts_DT_sent
decl_stmt|;
name|u_long
name|ts_XPD_sent
decl_stmt|;
name|u_long
name|ts_AK_sent
decl_stmt|;
name|u_long
name|ts_XAK_sent
decl_stmt|;
name|u_long
name|ts_DR_sent
decl_stmt|;
name|u_long
name|ts_DC_sent
decl_stmt|;
name|u_long
name|ts_CR_sent
decl_stmt|;
name|u_long
name|ts_CC_sent
decl_stmt|;
name|u_long
name|ts_ER_rcvd
decl_stmt|;
name|u_long
name|ts_DT_rcvd
decl_stmt|;
name|u_long
name|ts_XPD_rcvd
decl_stmt|;
name|u_long
name|ts_AK_rcvd
decl_stmt|;
name|u_long
name|ts_XAK_rcvd
decl_stmt|;
name|u_long
name|ts_DR_rcvd
decl_stmt|;
name|u_long
name|ts_DC_rcvd
decl_stmt|;
name|u_long
name|ts_CR_rcvd
decl_stmt|;
name|u_long
name|ts_CC_rcvd
decl_stmt|;
name|u_long
name|ts_Eticks
decl_stmt|;
name|u_long
name|ts_Eexpired
decl_stmt|;
name|u_long
name|ts_Eset
decl_stmt|;
name|u_long
name|ts_Ecan_act
decl_stmt|;
name|u_long
name|ts_Cticks
decl_stmt|;
name|u_long
name|ts_Cexpired
decl_stmt|;
name|u_long
name|ts_Cset
decl_stmt|;
name|u_long
name|ts_Ccan_act
decl_stmt|;
name|u_long
name|ts_Ccan_inact
decl_stmt|;
name|u_long
name|ts_Fdelack
decl_stmt|;
name|u_long
name|ts_Fpruned
decl_stmt|;
name|u_long
name|ts_concat_rcvd
decl_stmt|;
name|u_long
name|ts_zdebug
decl_stmt|;
comment|/* zero dref to test timeout on conn estab tp_input.c */
name|u_long
name|ts_ydebug
decl_stmt|;
comment|/* throw away pseudo-random pkts tp_input.c */
name|u_long
name|ts_unused5
decl_stmt|;
name|u_long
name|ts_unused
decl_stmt|;
comment|/* kludged concat to test separation tp_emit.c */
name|u_long
name|ts_vdebug
decl_stmt|;
comment|/* kludge to test input size checking tp_emit.c */
name|u_long
name|ts_unused4
decl_stmt|;
name|u_long
name|ts_ldebug
decl_stmt|;
comment|/* faked a renegging of credit */
name|u_long
name|ts_mb_small
decl_stmt|;
name|u_long
name|ts_mb_cluster
decl_stmt|;
name|u_long
name|ts_mb_len_distr
index|[
literal|17
index|]
decl_stmt|;
name|u_long
name|ts_eot_input
decl_stmt|;
name|u_long
name|ts_eot_user
decl_stmt|;
name|u_long
name|ts_EOT_sent
decl_stmt|;
name|u_long
name|ts_tp0_conn
decl_stmt|;
name|u_long
name|ts_tp4_conn
decl_stmt|;
name|u_long
name|ts_quench
decl_stmt|;
name|u_long
name|ts_rcvdecbit
decl_stmt|;
define|#
directive|define
name|NRTT_CATEGORIES
value|4
comment|/*  The 4 categories are: 	 * 0 --> tp_flags: ~TPF_PEER_ON_SAMENET |  TPF_NL_PDN 	 * 1 --> tp_flags: ~TPF_PEER_ON_SAMENET | ~TPF_NL_PDN 	 * 2 --> tp_flags:  TPF_PEER_ON_SAMENET | ~TPF_NL_PDN 	 * 3 --> tp_flags:  TPF_PEER_ON_SAMENET |  TPF_NL_PDN 	 */
name|int
name|ts_rtt
index|[
name|NRTT_CATEGORIES
index|]
decl_stmt|;
name|int
name|ts_rtv
index|[
name|NRTT_CATEGORIES
index|]
decl_stmt|;
name|u_long
name|ts_ackreason
index|[
name|_ACK_NUM_REASONS_
index|]
decl_stmt|;
comment|/*  ACK_DONT 0 / ACK_STRAT_EACH 0x1 / ACK_STRAT_FULLWIN 0x4 	  	 *	ACK_DUP 0x8 / ACK_EOT 0x10  / ACK_REORDER 0x20 	  	 *	ACK_USRRCV ** 	  	 *	ACK_FCC ** 		 */
block|}
name|tp_stat
struct|;
end_struct

begin_define
define|#
directive|define
name|TP_PM_MAX
value|0xa
end_define

begin_comment
comment|/* 10 decimal */
end_comment

begin_define
define|#
directive|define
name|IncStat
parameter_list|(
name|x
parameter_list|)
value|tp_stat.
comment|/**/
value|x
comment|/**/
value|++
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TP_PERF_MEAS
end_ifdef

begin_define
define|#
directive|define
name|PStat
parameter_list|(
name|Tpcb
parameter_list|,
name|X
parameter_list|)
value|(Tpcb)->tp_p_meas->
comment|/**/
value|X
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|IncPStat
parameter_list|(
name|Tpcb
parameter_list|,
name|X
parameter_list|)
value|if((Tpcb)->tp_perf_on) (Tpcb)->tp_p_meas->
comment|/**/
value|X
comment|/**/
value|++
end_define

begin_comment
comment|/* BEWARE OF MACROS like this ^^^ must be sure it's surrounded by {} if  * it's used in an if-else statement.  */
end_comment

begin_comment
comment|/* for perf measurement stuff: maximum window size it can handle */
end_comment

begin_struct
struct|struct
name|tp_pmeas
block|{
comment|/* the first few are distributions as a fn of window size 		 * only keep enough space for normal format plus 1 slot for 		 * extended format, in case any windows larger than 15 are used 		 */
comment|/* 		 * tps_npdusent: for each call to tp_sbsend, we inc the 		 * element representing the number of pdus sent in this call 		 */
name|int
name|tps_win_lim_by_cdt
index|[
name|TP_PM_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|tps_win_lim_by_data
index|[
name|TP_PM_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* 		 * tps_sendtime: Each call to tp_sbsend() is timed.  For 		 * Each window size, we keep the running average of the time 		 * taken by tp_sbsend() for each window size. 		 */
name|int
name|tps_sendtime
index|[
name|TP_PM_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* 		 * n_TMsendack: # times ack sent because timer went off 		 * n_ack_cuz_eot: # times ack sent due to EOTSDU on incoming packet 		 * n_ack_cuz_dup: # times ack sent for receiving a duplicate pkt. 		 * n_ack_cuz_fullwin: # times ack sent for receiving the full window. 		 * n_ack_cuz_doack: # times ack sent for having just reordered data. 		 */
name|int
name|tps_n_TMsendack
decl_stmt|;
name|int
name|tps_n_ack_cuz_eot
decl_stmt|;
name|int
name|tps_n_ack_cuz_fullwin
decl_stmt|;
name|int
name|tps_n_ack_cuz_reorder
decl_stmt|;
name|int
name|tps_n_ack_cuz_dup
decl_stmt|;
name|int
name|tps_n_ack_cuz_strat
decl_stmt|;
comment|/* 		 * when we send an ack: how much less than the "expected" window 		 * did we actually ack.  For example: if we last sent a credit 		 * of 10, and we're acking now for whatever reason, and have 		 * only received 6 since our last credit advertisement, we'll 		 * keep the difference, 4, in this variable. 		 */
name|int
name|tps_ack_early
index|[
name|TP_PM_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* 		 * when we ack, for the # pkts we actually acked w/ this ack, 		 * how much cdt are we advertising? 		 * [ size of window acknowledged ] [ cdt we're giving ] 		 */
name|int
name|tps_cdt_acked
index|[
name|TP_PM_MAX
operator|+
literal|1
index|]
index|[
name|TP_PM_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|tps_AK_sent
decl_stmt|;
name|int
name|tps_XAK_sent
decl_stmt|;
name|int
name|tps_DT_sent
decl_stmt|;
name|int
name|tps_XPD_sent
decl_stmt|;
name|int
name|tps_AK_rcvd
decl_stmt|;
name|int
name|tps_XAK_rcvd
decl_stmt|;
name|int
name|tps_DT_rcvd
decl_stmt|;
name|int
name|tps_XPD_rcvd
decl_stmt|;
name|int
name|Nb_from_sess
decl_stmt|;
name|int
name|Nb_to_sess
decl_stmt|;
name|int
name|Nb_to_ll
decl_stmt|;
name|int
name|Nb_from_ll
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFPERF
parameter_list|(
name|tpcb
parameter_list|)
value|if (tpcb->tp_perf_on&& tpcb->tp_p_meas) {
end_define

begin_define
define|#
directive|define
name|ENDPERF
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|PStat_Junk
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PStat
parameter_list|(
name|tpcb
parameter_list|,
name|x
parameter_list|)
value|PStat_Junk
end_define

begin_define
define|#
directive|define
name|IncPStat
parameter_list|(
name|tpcb
parameter_list|,
name|x
parameter_list|)
end_define

begin_comment
comment|/* no-op */
end_comment

begin_define
define|#
directive|define
name|tpmeas
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|IFPERF
parameter_list|(
name|x
parameter_list|)
value|if (0) {
end_define

begin_define
define|#
directive|define
name|ENDPERF
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP_PERF_MEAS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

