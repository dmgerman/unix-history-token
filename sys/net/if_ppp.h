begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * if_ppp.h - Point-to-Point Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Modified by Paul Mackerras (paulus@cs.anu.edu.au)  * Added PPP_MRU, sc_outm, sc_fastq, sc_bpf.  *  *	$Id$  *	From: if_ppp.h,v 1.4 1993/08/29 11:22:37 paulus Exp $  */
end_comment

begin_comment
comment|/*  * Standard PPP header.  */
end_comment

begin_struct
struct|struct
name|ppp_header
block|{
name|u_char
name|ph_address
decl_stmt|;
comment|/* Address Field */
name|u_char
name|ph_control
decl_stmt|;
comment|/* Control Field */
name|u_short
name|ph_protocol
decl_stmt|;
comment|/* Protocol Field */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPP_HEADER_LEN
value|4
end_define

begin_comment
comment|/* octets, must == sizeof(struct ppp_header) */
end_comment

begin_define
define|#
directive|define
name|PPP_FCS_LEN
value|2
end_define

begin_comment
comment|/* octets for FCS */
end_comment

begin_define
define|#
directive|define
name|PPP_ALLSTATIONS
value|0xff
end_define

begin_comment
comment|/* All-Stations broadcast address */
end_comment

begin_define
define|#
directive|define
name|PPP_UI
value|0x03
end_define

begin_comment
comment|/* Unnumbered Information */
end_comment

begin_define
define|#
directive|define
name|PPP_FLAG
value|0x7e
end_define

begin_comment
comment|/* Flag Sequence */
end_comment

begin_define
define|#
directive|define
name|PPP_ESCAPE
value|0x7d
end_define

begin_comment
comment|/* Asynchronous Control Escape */
end_comment

begin_define
define|#
directive|define
name|PPP_TRANS
value|0x20
end_define

begin_comment
comment|/* Asynchronous transparency modifier */
end_comment

begin_comment
comment|/*  * Protocol types.  */
end_comment

begin_define
define|#
directive|define
name|PPP_IP
value|0x21
end_define

begin_comment
comment|/* Internet Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_XNS
value|0x25
end_define

begin_comment
comment|/* Xerox NS */
end_comment

begin_define
define|#
directive|define
name|PPP_VJC_COMP
value|0x2d
end_define

begin_comment
comment|/* VJ compressed TCP */
end_comment

begin_define
define|#
directive|define
name|PPP_VJC_UNCOMP
value|0x2f
end_define

begin_comment
comment|/* VJ uncompressed TCP */
end_comment

begin_define
define|#
directive|define
name|PPP_LCP
value|0xc021
end_define

begin_comment
comment|/* Link Control Protocol */
end_comment

begin_comment
comment|/*  * Important FCS values.  */
end_comment

begin_define
define|#
directive|define
name|PPP_INITFCS
value|0xffff
end_define

begin_comment
comment|/* Initial FCS value */
end_comment

begin_define
define|#
directive|define
name|PPP_GOODFCS
value|0xf0b8
end_define

begin_comment
comment|/* Good final FCS value */
end_comment

begin_define
define|#
directive|define
name|PPP_FCS
parameter_list|(
name|fcs
parameter_list|,
name|c
parameter_list|)
value|(((fcs)>> 8) ^ fcstab[((fcs) ^ (c))& 0xff])
end_define

begin_define
define|#
directive|define
name|PPP_MTU
value|1500
end_define

begin_comment
comment|/* Default MTU (size of Info field) */
end_comment

begin_define
define|#
directive|define
name|PPP_MRU
value|1500
end_define

begin_comment
comment|/* Default MRU (max receive unit) */
end_comment

begin_define
define|#
directive|define
name|PPP_MAXMRU
value|65000
end_define

begin_comment
comment|/* Largest MRU we allow */
end_comment

begin_define
define|#
directive|define
name|PPP_HIWAT
value|400
end_define

begin_comment
comment|/* Don't start a new packet if HIWAT on que */
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
name|u_int
name|sc_flags
decl_stmt|;
comment|/* see below */
name|struct
name|tty
modifier|*
name|sc_ttyp
decl_stmt|;
comment|/* pointer to tty structure */
name|struct
name|mbuf
modifier|*
name|sc_outm
decl_stmt|;
comment|/* mbuf chain being output currently */
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
comment|/* pointer to next char in input mbuf */
name|short
name|sc_ilen
decl_stmt|;
comment|/* length of input-packet-so-far */
name|u_short
name|sc_fcs
decl_stmt|;
comment|/* FCS so far (input) */
name|u_short
name|sc_outfcs
decl_stmt|;
comment|/* FCS so far for output packet */
name|short
name|sc_mru
decl_stmt|;
comment|/* max receive unit */
name|u_long
name|sc_asyncmap
decl_stmt|;
comment|/* async control character map */
name|u_long
name|sc_rasyncmap
decl_stmt|;
comment|/* receive async control char map */
name|struct
name|ifqueue
name|sc_inq
decl_stmt|;
comment|/* TTY side input queue */
name|struct
name|ifqueue
name|sc_fastq
decl_stmt|;
comment|/* IP interactive output packet queue */
ifdef|#
directive|ifdef
name|VJC
name|struct
name|slcompress
name|sc_comp
decl_stmt|;
comment|/* vjc control buffer */
endif|#
directive|endif
name|u_int
name|sc_bytessent
decl_stmt|;
name|u_int
name|sc_bytesrcvd
decl_stmt|;
name|caddr_t
name|sc_bpf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_PROT
value|0x00000001
end_define

begin_comment
comment|/* protocol compression (output) */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_AC
value|0x00000002
end_define

begin_comment
comment|/* header compression (output) */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_TCP
value|0x00000004
end_define

begin_comment
comment|/* TCP (VJ) compression (output) */
end_comment

begin_define
define|#
directive|define
name|SC_NO_TCP_CCID
value|0x00000008
end_define

begin_comment
comment|/* disable VJ connection-id comp. */
end_comment

begin_define
define|#
directive|define
name|SC_REJ_COMP_AC
value|0x00000010
end_define

begin_comment
comment|/* reject adrs/ctrl comp. on input */
end_comment

begin_define
define|#
directive|define
name|SC_REJ_COMP_TCP
value|0x00000020
end_define

begin_comment
comment|/* reject TCP (VJ) comp. on input */
end_comment

begin_define
define|#
directive|define
name|SC_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* bits that user can change */
end_comment

begin_comment
comment|/* state bits */
end_comment

begin_define
define|#
directive|define
name|SC_ESCAPED
value|0x00010000
end_define

begin_comment
comment|/* saw a PPP_ESCAPE */
end_comment

begin_define
define|#
directive|define
name|SC_FLUSH
value|0x00020000
end_define

begin_comment
comment|/* flush input until next PPP_FLAG */
end_comment

begin_define
define|#
directive|define
name|t_sc
value|T_LINEP
end_define

begin_comment
comment|/* this stuff doesn't belong here... */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGFLAGS
value|_IOR('t', 90, int)
end_define

begin_comment
comment|/* get configuration flags */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSFLAGS
value|_IOW('t', 89, int)
end_define

begin_comment
comment|/* set configuration flags */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGASYNCMAP
value|_IOR('t', 88, int)
end_define

begin_comment
comment|/* get async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSASYNCMAP
value|_IOW('t', 87, int)
end_define

begin_comment
comment|/* set async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGUNIT
value|_IOR('t', 86, int)
end_define

begin_comment
comment|/* get ppp unit number */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGRASYNCMAP
value|_IOR('t', 85, int)
end_define

begin_comment
comment|/* get receive async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSRASYNCMAP
value|_IOW('t', 84, int)
end_define

begin_comment
comment|/* set receive async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGMRU
value|_IOR('t', 83, int)
end_define

begin_comment
comment|/* get max receive unit */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSMRU
value|_IOW('t', 82, int)
end_define

begin_comment
comment|/* set max receive unit */
end_comment

begin_comment
comment|/* old copies of PPP may have defined this */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ifr_mtu
argument_list|)
end_if

begin_define
define|#
directive|define
name|ifr_mtu
value|ifr_metric
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

