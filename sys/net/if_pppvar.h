begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * if_pppvar.h - private structures and declarations for PPP.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994 The Australian National University.  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation is hereby granted, provided that the above copyright  * notice appears in all copies.  This software is provided without any  * warranty, express or implied. The Australian National University  * makes no representations about the suitability of this software for  * any purpose.  *  * IN NO EVENT SHALL THE AUSTRALIAN NATIONAL UNIVERSITY BE LIABLE TO ANY  * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF  * THE AUSTRALIAN NATIONAL UNIVERSITY HAVE BEEN ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * THE AUSTRALIAN NATIONAL UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE AUSTRALIAN NATIONAL UNIVERSITY HAS NO  * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS,  * OR MODIFICATIONS.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
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
name|NP_IPV6
value|1
end_define

begin_comment
comment|/* Internet Protocol version 6 */
end_comment

begin_define
define|#
directive|define
name|NUM_NP
value|2
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
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* network-visible interface */
comment|/*hi*/
name|u_int
name|sc_flags
decl_stmt|;
comment|/* control/status bits; see if_ppp.h */
name|struct
name|callout
name|sc_timo_ch
decl_stmt|;
comment|/* Used for scheduling timeouts */
name|void
modifier|*
name|sc_devp
decl_stmt|;
comment|/* pointer to device-dep structure */
name|void
function_decl|(
modifier|*
name|sc_start
function_decl|)
parameter_list|(
name|struct
name|ppp_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* start output proc */
name|void
function_decl|(
modifier|*
name|sc_ctlp
function_decl|)
parameter_list|(
name|struct
name|ppp_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* rcvd control pkt */
name|void
function_decl|(
modifier|*
name|sc_relinq
function_decl|)
parameter_list|(
name|struct
name|ppp_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* relinquish ifunit */
name|void
function_decl|(
modifier|*
name|sc_setmtu
function_decl|)
parameter_list|(
name|struct
name|ppp_softc
modifier|*
parameter_list|)
function_decl|;
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
name|LIST_ENTRY
argument_list|(
argument|ppp_softc
argument_list|)
name|sc_list
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPP2IFP
parameter_list|(
name|sc
parameter_list|)
value|((sc)->sc_ifp)
end_define

begin_function_decl
name|struct
name|ppp_softc
modifier|*
name|pppalloc
parameter_list|(
name|pid_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pppdealloc
parameter_list|(
name|struct
name|ppp_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pppioctl
parameter_list|(
name|struct
name|ppp_softc
modifier|*
name|sc
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pppoutput
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|dst
parameter_list|,
name|struct
name|rtentry
modifier|*
name|rtp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppp_restart
parameter_list|(
name|struct
name|ppp_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppppktin
parameter_list|(
name|struct
name|ppp_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|lost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ppp_dequeue
parameter_list|(
name|struct
name|ppp_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

end_unit

