begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * if_pppvar.h - private structures and declarations for PPP.  *  * Copyright (c) 1994 The Australian National University.  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation is hereby granted, provided that the above copyright  * notice appears in all copies.  This software is provided without any  * warranty, express or implied. The Australian National University  * makes no representations about the suitability of this software for  * any purpose.  *  * IN NO EVENT SHALL THE AUSTRALIAN NATIONAL UNIVERSITY BE LIABLE TO ANY  * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF  * THE AUSTRALIAN NATIONAL UNIVERSITY HAVE BEEN ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * THE AUSTRALIAN NATIONAL UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE AUSTRALIAN NATIONAL UNIVERSITY HAS NO  * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS,  * OR MODIFICATIONS.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: if_pppvar.h,v 1.11 1997/10/17 21:50:32 roberto Exp $  */
end_comment

begin_comment
comment|/*  * Supported network protocols.  These values are used for  * indexing sc_npmode.  */
end_comment

begin_define
define|#
directive|define
name|NP_IP
value|0
end_define

begin_comment
comment|/* Internet Protocol */
end_comment

begin_define
define|#
directive|define
name|NUM_NP
value|1
end_define

begin_comment
comment|/* Number of NPs. */
end_comment

begin_comment
comment|/*  * Structure describing each ppp unit.  */
end_comment

begin_struct
struct|struct
name|ppp_softc
block|{
name|struct
name|ifnet
name|sc_if
decl_stmt|;
comment|/* network-visible interface */
comment|/*hi*/
name|u_int
name|sc_flags
decl_stmt|;
comment|/* control/status bits; see if_ppp.h */
name|struct
name|callout_handle
name|sc_ch
decl_stmt|;
comment|/* Used for scheduling timeouts */
name|void
modifier|*
name|sc_devp
decl_stmt|;
comment|/* pointer to device-dep structure */
name|void
argument_list|(
argument|*sc_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* start output proc */
name|void
argument_list|(
argument|*sc_ctlp
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* rcvd control pkt */
name|void
argument_list|(
argument|*sc_relinq
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* relinquish ifunit */
name|void
argument_list|(
argument|*sc_setmtu
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* set mtu */
name|short
name|sc_mru
decl_stmt|;
comment|/* max receive unit */
name|pid_t
name|sc_xfer
decl_stmt|;
comment|/* used in transferring unit */
comment|/*hi*/
name|struct
name|ifqueue
name|sc_rawq
decl_stmt|;
comment|/* received packets */
comment|/*net*/
name|struct
name|ifqueue
name|sc_inq
decl_stmt|;
comment|/* queue of input packets for daemon */
comment|/*net*/
name|struct
name|ifqueue
name|sc_fastq
decl_stmt|;
comment|/* interactive output packet q */
name|struct
name|mbuf
modifier|*
name|sc_npqueue
decl_stmt|;
comment|/* output packets not to be sent yet */
name|struct
name|mbuf
modifier|*
modifier|*
name|sc_npqtail
decl_stmt|;
comment|/* ptr to last next ptr in npqueue */
name|struct
name|pppstat
name|sc_stats
decl_stmt|;
comment|/* count of bytes/pkts sent/rcvd */
name|enum
name|NPmode
name|sc_npmode
index|[
name|NUM_NP
index|]
decl_stmt|;
comment|/* what to do with each NP */
name|struct
name|compressor
modifier|*
name|sc_xcomp
decl_stmt|;
comment|/* transmit compressor */
name|void
modifier|*
name|sc_xc_state
decl_stmt|;
comment|/* transmit compressor state */
name|struct
name|compressor
modifier|*
name|sc_rcomp
decl_stmt|;
comment|/* receive decompressor */
name|void
modifier|*
name|sc_rc_state
decl_stmt|;
comment|/* receive decompressor state */
name|time_t
name|sc_last_sent
decl_stmt|;
comment|/* time (secs) last NP pkt sent */
name|time_t
name|sc_last_recv
decl_stmt|;
comment|/* time (secs) last NP pkt rcvd */
ifdef|#
directive|ifdef
name|PPP_FILTER
name|struct
name|bpf_program
name|sc_pass_filt
decl_stmt|;
comment|/* filter for packets to pass */
name|struct
name|bpf_program
name|sc_active_filt
decl_stmt|;
comment|/* filter for "non-idle" packets */
endif|#
directive|endif
comment|/* PPP_FILTER */
ifdef|#
directive|ifdef
name|VJC
name|struct
name|slcompress
modifier|*
name|sc_comp
decl_stmt|;
comment|/* vjc control buffer */
endif|#
directive|endif
comment|/* Device-dependent part for async lines. */
name|ext_accm
name|sc_asyncmap
decl_stmt|;
comment|/* async control character map */
name|u_long
name|sc_rasyncmap
decl_stmt|;
comment|/* receive async control char map */
name|struct
name|mbuf
modifier|*
name|sc_outm
decl_stmt|;
comment|/* mbuf chain currently being output */
name|struct
name|mbuf
modifier|*
name|sc_m
decl_stmt|;
comment|/* pointer to input mbuf chain */
name|struct
name|mbuf
modifier|*
name|sc_mc
decl_stmt|;
comment|/* pointer to current input mbuf */
name|char
modifier|*
name|sc_mp
decl_stmt|;
comment|/* ptr to next char in input mbuf */
name|short
name|sc_ilen
decl_stmt|;
comment|/* length of input packet so far */
name|u_short
name|sc_fcs
decl_stmt|;
comment|/* FCS so far (input) */
name|u_short
name|sc_outfcs
decl_stmt|;
comment|/* FCS so far for output packet */
name|u_char
name|sc_rawin
index|[
literal|16
index|]
decl_stmt|;
comment|/* chars as received */
name|int
name|sc_rawin_count
decl_stmt|;
comment|/* # in sc_rawin */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ppp_softc
name|ppp_softc
index|[
name|NPPP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ppp_softc
modifier|*
name|pppalloc
name|__P
argument_list|(
operator|(
name|pid_t
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pppdealloc
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pppioctl
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
name|sc
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|data
operator|,
name|int
name|flag
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pppoutput
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|mbuf
operator|*
name|m0
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
expr|struct
name|rtentry
operator|*
name|rtp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ppp_restart
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ppppktin
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
name|sc
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
name|int
name|lost
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|ppp_dequeue
name|__P
argument_list|(
operator|(
expr|struct
name|ppp_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

