begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)clnp.h	8.2 (Berkeley) 4/16/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_CLNP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_CLNP_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/clnp.h,v $ */
end_comment

begin_comment
comment|/* should be config option but cpp breaks with too many #defines */
end_comment

begin_define
define|#
directive|define
name|DECBIT
end_define

begin_comment
comment|/*  *	Return true if the mbuf is a cluster mbuf  */
end_comment

begin_define
define|#
directive|define
name|IS_CLUSTER
parameter_list|(
name|m
parameter_list|)
value|((m)->m_flags& M_EXT)
end_define

begin_comment
comment|/*  *	Move the halfword into the two characters  */
end_comment

begin_define
define|#
directive|define
name|HTOC
parameter_list|(
name|msb
parameter_list|,
name|lsb
parameter_list|,
name|hword
parameter_list|)
define|\
value|(msb) = (u_char)((hword)>> 8);\ 	(lsb) = (u_char)((hword)& 0xff)
end_define

begin_comment
comment|/*  *	Move the two charcters into the halfword  */
end_comment

begin_define
define|#
directive|define
name|CTOH
parameter_list|(
name|msb
parameter_list|,
name|lsb
parameter_list|,
name|hword
parameter_list|)
define|\
value|(hword) = ((msb)<< 8) | (lsb)
end_define

begin_comment
comment|/*  *	Return true if the checksum has been set - ie. the checksum is  *	not zero  */
end_comment

begin_define
define|#
directive|define
name|CKSUM_REQUIRED
parameter_list|(
name|clnp
parameter_list|)
define|\
value|(((clnp)->cnf_cksum_msb != 0) || ((clnp)->cnf_cksum_lsb != 0))
end_define

begin_comment
comment|/*  *	Fixed part of clnp header  */
end_comment

begin_struct
struct|struct
name|clnp_fixed
block|{
name|u_char
name|cnf_proto_id
decl_stmt|;
comment|/* network layer protocol identifier */
name|u_char
name|cnf_hdr_len
decl_stmt|;
comment|/* length indicator (octets) */
name|u_char
name|cnf_vers
decl_stmt|;
comment|/* version/protocol identifier extension */
name|u_char
name|cnf_ttl
decl_stmt|;
comment|/* lifetime (500 milliseconds) */
name|u_char
name|cnf_type
decl_stmt|;
comment|/* type code */
comment|/* Includes err_ok, more_segs, and seg_ok */
name|u_char
name|cnf_seglen_msb
decl_stmt|;
comment|/* pdu segment length (octets) high byte */
name|u_char
name|cnf_seglen_lsb
decl_stmt|;
comment|/* pdu segment length (octets) low byte */
name|u_char
name|cnf_cksum_msb
decl_stmt|;
comment|/* checksum high byte */
name|u_char
name|cnf_cksum_lsb
decl_stmt|;
comment|/* checksum low byte */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CNF_TYPE
value|0x1f
end_define

begin_define
define|#
directive|define
name|CNF_ERR_OK
value|0x20
end_define

begin_define
define|#
directive|define
name|CNF_MORE_SEGS
value|0x40
end_define

begin_define
define|#
directive|define
name|CNF_SEG_OK
value|0x80
end_define

begin_define
define|#
directive|define
name|CLNP_CKSUM_OFF
value|0x07
end_define

begin_comment
comment|/* offset of checksum */
end_comment

begin_define
define|#
directive|define
name|clnl_fixed
value|clnp_fixed
end_define

begin_comment
comment|/*  *	Segmentation part of clnp header  */
end_comment

begin_struct
struct|struct
name|clnp_segment
block|{
name|u_short
name|cng_id
decl_stmt|;
comment|/* data unit identifier */
name|u_short
name|cng_off
decl_stmt|;
comment|/* segment offset */
name|u_short
name|cng_tot_len
decl_stmt|;
comment|/* total length */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Clnp fragment reassembly structures:  *  *	All packets undergoing reassembly are linked together in  *	clnp_fragl structures. Each clnp_fragl structure contains a  *	pointer to the original clnp packet header, as well as a  *	list of packet fragments. Each packet fragment  *	is headed by a clnp_frag structure. This structure contains the  *	offset of the first and last byte of the fragment, as well as  *	a pointer to the data (an mbuf chain) of the fragment.  */
end_comment

begin_comment
comment|/*  *	NOTE:  *		The clnp_frag structure is stored in an mbuf immedately preceeding  *	the fragment data. Since there are words in this struct,  *	it must be word aligned.  *  *	NOTE:  *		All the fragment code assumes that the entire clnp header is  *	contained in the first mbuf.  */
end_comment

begin_struct
struct|struct
name|clnp_frag
block|{
name|u_int
name|cfr_first
decl_stmt|;
comment|/* offset of first byte of this frag */
name|u_int
name|cfr_last
decl_stmt|;
comment|/* offset of last byte of this frag */
name|u_int
name|cfr_bytes
decl_stmt|;
comment|/* bytes to shave to get to data */
name|struct
name|mbuf
modifier|*
name|cfr_data
decl_stmt|;
comment|/* ptr to data for this frag */
name|struct
name|clnp_frag
modifier|*
name|cfr_next
decl_stmt|;
comment|/* next fragment in list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|clnp_fragl
block|{
name|struct
name|iso_addr
name|cfl_src
decl_stmt|;
comment|/* source of the pkt */
name|struct
name|iso_addr
name|cfl_dst
decl_stmt|;
comment|/* destination of the pkt */
name|u_short
name|cfl_id
decl_stmt|;
comment|/* id of the pkt */
name|u_char
name|cfl_ttl
decl_stmt|;
comment|/* current ttl of pkt */
name|u_short
name|cfl_last
decl_stmt|;
comment|/* offset of last byte of packet */
name|struct
name|mbuf
modifier|*
name|cfl_orighdr
decl_stmt|;
comment|/* ptr to original header */
name|struct
name|clnp_frag
modifier|*
name|cfl_frags
decl_stmt|;
comment|/* linked list of fragments for pkt */
name|struct
name|clnp_fragl
modifier|*
name|cfl_next
decl_stmt|;
comment|/* next pkt being reassembled */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	The following structure is used to index into an options section  *	of a clnp datagram. These values can be used without worry that  *	offset or length fields are invalid or too big, etc. That is,  *	the consistancy of the options will be guaranteed before this  *	structure is filled in. Any pointer (field ending in p) is  *	actually the offset from the beginning of the mbuf the option  *	is contained in.  A value of NULL for any pointer  *	means that the option is not present. The length any option  *	does not include the option code or option length fields.  */
end_comment

begin_struct
struct|struct
name|clnp_optidx
block|{
name|u_short
name|cni_securep
decl_stmt|;
comment|/* ptr to beginning of security option */
name|char
name|cni_secure_len
decl_stmt|;
comment|/* length of entire security option */
name|u_short
name|cni_srcrt_s
decl_stmt|;
comment|/* offset of start of src rt option */
name|u_short
name|cni_srcrt_len
decl_stmt|;
comment|/* length of entire src rt option */
name|u_short
name|cni_recrtp
decl_stmt|;
comment|/* ptr to beginning of recrt option */
name|char
name|cni_recrt_len
decl_stmt|;
comment|/* length of entire recrt option */
name|char
name|cni_priorp
decl_stmt|;
comment|/* ptr to priority option */
name|u_short
name|cni_qos_formatp
decl_stmt|;
comment|/* ptr to format of qos option */
name|char
name|cni_qos_len
decl_stmt|;
comment|/* length of entire qos option */
name|u_char
name|cni_er_reason
decl_stmt|;
comment|/* reason from ER pdu option */
comment|/* ESIS options */
name|u_short
name|cni_esct
decl_stmt|;
comment|/* value from ISH ESCT option */
name|u_short
name|cni_netmaskp
decl_stmt|;
comment|/* ptr to beginning of netmask option */
name|char
name|cni_netmask_len
decl_stmt|;
comment|/* length of entire netmask option */
name|u_short
name|cni_snpamaskp
decl_stmt|;
comment|/* ptr to beginning of snpamask option */
name|char
name|cni_snpamask_len
decl_stmt|;
comment|/* length of entire snpamask option */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ER_INVALREAS
value|0xff
end_define

begin_comment
comment|/* code for invalid ER pdu discard reason */
end_comment

begin_comment
comment|/* given an mbuf and addr of option, return offset from data of mbuf */
end_comment

begin_define
define|#
directive|define
name|CLNP_OPTTOOFF
parameter_list|(
name|m
parameter_list|,
name|opt
parameter_list|)
define|\
value|((u_short) (opt - mtod(m, caddr_t)))
end_define

begin_comment
comment|/* given an mbuf and offset of option, return address of option */
end_comment

begin_define
define|#
directive|define
name|CLNP_OFFTOOPT
parameter_list|(
name|m
parameter_list|,
name|off
parameter_list|)
define|\
value|((caddr_t) (mtod(m, caddr_t) + off))
end_define

begin_comment
comment|/*	return true iff src route is valid */
end_comment

begin_define
define|#
directive|define
name|CLNPSRCRT_VALID
parameter_list|(
name|oidx
parameter_list|)
define|\
value|((oidx)&& (oidx->cni_srcrt_s))
end_define

begin_comment
comment|/*	return the offset field of the src rt */
end_comment

begin_define
define|#
directive|define
name|CLNPSRCRT_OFF
parameter_list|(
name|oidx
parameter_list|,
name|options
parameter_list|)
define|\
value|(*((u_char *)(CLNP_OFFTOOPT(options, oidx->cni_srcrt_s) + 1)))
end_define

begin_comment
comment|/*	return the type field of the src rt */
end_comment

begin_define
define|#
directive|define
name|CLNPSRCRT_TYPE
parameter_list|(
name|oidx
parameter_list|,
name|options
parameter_list|)
define|\
value|((u_char)(*(CLNP_OFFTOOPT(options, oidx->cni_srcrt_s))))
end_define

begin_comment
comment|/* return the length of the current address */
end_comment

begin_define
define|#
directive|define
name|CLNPSRCRT_CLEN
parameter_list|(
name|oidx
parameter_list|,
name|options
parameter_list|)
define|\
value|((u_char)(*(CLNP_OFFTOOPT(options, oidx->cni_srcrt_s) + CLNPSRCRT_OFF(oidx, options) - 1)))
end_define

begin_comment
comment|/* return the address of the current address */
end_comment

begin_define
define|#
directive|define
name|CLNPSRCRT_CADDR
parameter_list|(
name|oidx
parameter_list|,
name|options
parameter_list|)
define|\
value|((caddr_t)(CLNP_OFFTOOPT(options, oidx->cni_srcrt_s) + CLNPSRCRT_OFF(oidx, options)))
end_define

begin_comment
comment|/*  *	return true if the src route has run out of routes  *	this is true if the offset of next route is greater than the end of the rt  */
end_comment

begin_define
define|#
directive|define
name|CLNPSRCRT_TERM
parameter_list|(
name|oidx
parameter_list|,
name|options
parameter_list|)
define|\
value|(CLNPSRCRT_OFF(oidx, options)> oidx->cni_srcrt_len)
end_define

begin_comment
comment|/*  *	Options a user can set/get  */
end_comment

begin_define
define|#
directive|define
name|CLNPOPT_FLAGS
value|0x01
end_define

begin_comment
comment|/* flags: seg permitted, no er xmit, etc  */
end_comment

begin_define
define|#
directive|define
name|CLNPOPT_OPTS
value|0x02
end_define

begin_comment
comment|/* datagram options */
end_comment

begin_comment
comment|/*  *	Values for particular datagram options  */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_PAD
value|0xcc
end_define

begin_comment
comment|/* padding */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_SECURE
value|0xc5
end_define

begin_comment
comment|/* security */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_SRCRT
value|0xc8
end_define

begin_comment
comment|/* source routing */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_RECRT
value|0xcb
end_define

begin_comment
comment|/* record route */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_QOS
value|0xc3
end_define

begin_comment
comment|/* quality of service */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_PRIOR
value|0xcd
end_define

begin_comment
comment|/* priority */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_ERREAS
value|0xc1
end_define

begin_comment
comment|/* ER PDU ONLY: reason for discard */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_SRCSPEC
value|0x40
end_define

begin_comment
comment|/* source address specific */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_DSTSPEC
value|0x80
end_define

begin_comment
comment|/* destination address specific */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_GLOBAL
value|0xc0
end_define

begin_comment
comment|/* globally unique */
end_comment

begin_comment
comment|/* Globally Unique QOS */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_SEQUENCING
value|0x10
end_define

begin_comment
comment|/* sequencing preferred */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_CONGESTED
value|0x08
end_define

begin_comment
comment|/* congestion experienced */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_LOWDELAY
value|0x04
end_define

begin_comment
comment|/* low transit delay */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_PARTRT
value|0x00
end_define

begin_comment
comment|/* partial source routing */
end_comment

begin_define
define|#
directive|define
name|CLNPOVAL_COMPRT
value|0x01
end_define

begin_comment
comment|/* complete source routing */
end_comment

begin_comment
comment|/*  *	Clnp flags used in a control block flags field.  *	NOTE: these must be out of the range of bits defined in ../net/raw_cb.h  */
end_comment

begin_define
define|#
directive|define
name|CLNP_NO_SEG
value|0x010
end_define

begin_comment
comment|/* segmentation not permitted */
end_comment

begin_define
define|#
directive|define
name|CLNP_NO_ER
value|0x020
end_define

begin_comment
comment|/* do not generate ERs */
end_comment

begin_define
define|#
directive|define
name|CLNP_SEND_RAW
value|0x080
end_define

begin_comment
comment|/* send pkt as RAW DT rather than TP DT */
end_comment

begin_define
define|#
directive|define
name|CLNP_NO_CKSUM
value|0x100
end_define

begin_comment
comment|/* don't use clnp checksum */
end_comment

begin_define
define|#
directive|define
name|CLNP_ECHO
value|0x200
end_define

begin_comment
comment|/* send echo request */
end_comment

begin_define
define|#
directive|define
name|CLNP_NOCACHE
value|0x400
end_define

begin_comment
comment|/* don't store cache information */
end_comment

begin_define
define|#
directive|define
name|CLNP_ECHOR
value|0x800
end_define

begin_comment
comment|/* send echo reply */
end_comment

begin_comment
comment|/* valid clnp flags */
end_comment

begin_define
define|#
directive|define
name|CLNP_VFLAGS
value|(CLNP_SEND_RAW|CLNP_NO_SEG|CLNP_NO_ER|CLNP_NO_CKSUM\ 	|CLNP_ECHO|CLNP_NOCACHE|CLNP_ECHOR)
end_define

begin_comment
comment|/*  *	Constants used by clnp  */
end_comment

begin_define
define|#
directive|define
name|CLNP_HDR_MIN
value|(sizeof (struct clnp_fixed))
end_define

begin_define
define|#
directive|define
name|CLNP_HDR_MAX
value|(254)
end_define

begin_define
define|#
directive|define
name|CLNP_TTL_UNITS
value|2
end_define

begin_comment
comment|/* 500 milliseconds */
end_comment

begin_define
define|#
directive|define
name|CLNP_TTL
value|15*CLNP_TTL_UNITS
end_define

begin_comment
comment|/* time to live (seconds) */
end_comment

begin_define
define|#
directive|define
name|ISO8473_V1
value|0x01
end_define

begin_comment
comment|/*  *	Clnp packet types  *	In order to test raw clnp and tp/clnp simultaneously, a third type of  *	packet has been defined: CLNP_RAW. This is done so that the input  *	routine can switch to the correct input routine (rclnp_input or  *	tpclnp_input) based on the type field. If clnp had a higher level protocol  *	field, this would not be necessary.  */
end_comment

begin_define
define|#
directive|define
name|CLNP_DT
value|0x1C
end_define

begin_comment
comment|/* normal data */
end_comment

begin_define
define|#
directive|define
name|CLNP_ER
value|0x01
end_define

begin_comment
comment|/* error report */
end_comment

begin_define
define|#
directive|define
name|CLNP_RAW
value|0x1D
end_define

begin_comment
comment|/* debug only */
end_comment

begin_define
define|#
directive|define
name|CLNP_EC
value|0x1E
end_define

begin_comment
comment|/* echo packet */
end_comment

begin_define
define|#
directive|define
name|CLNP_ECR
value|0x1F
end_define

begin_comment
comment|/* echo reply */
end_comment

begin_comment
comment|/*  *	ER pdu error codes  */
end_comment

begin_define
define|#
directive|define
name|GEN_NOREAS
value|0x00
end_define

begin_comment
comment|/* reason not specified */
end_comment

begin_define
define|#
directive|define
name|GEN_PROTOERR
value|0x01
end_define

begin_comment
comment|/* protocol procedure error */
end_comment

begin_define
define|#
directive|define
name|GEN_BADCSUM
value|0x02
end_define

begin_comment
comment|/* incorrect checksum */
end_comment

begin_define
define|#
directive|define
name|GEN_CONGEST
value|0x03
end_define

begin_comment
comment|/* pdu discarded due to congestion */
end_comment

begin_define
define|#
directive|define
name|GEN_HDRSYNTAX
value|0x04
end_define

begin_comment
comment|/* header syntax error */
end_comment

begin_define
define|#
directive|define
name|GEN_SEGNEEDED
value|0x05
end_define

begin_comment
comment|/* segmentation needed, but not permitted */
end_comment

begin_define
define|#
directive|define
name|GEN_INCOMPLETE
value|0x06
end_define

begin_comment
comment|/* incomplete pdu received */
end_comment

begin_define
define|#
directive|define
name|GEN_DUPOPT
value|0x07
end_define

begin_comment
comment|/* duplicate option */
end_comment

begin_comment
comment|/* address errors */
end_comment

begin_define
define|#
directive|define
name|ADDR_DESTUNREACH
value|0x80
end_define

begin_comment
comment|/* destination address unreachable */
end_comment

begin_define
define|#
directive|define
name|ADDR_DESTUNKNOWN
value|0x81
end_define

begin_comment
comment|/* destination address unknown */
end_comment

begin_comment
comment|/* source routing */
end_comment

begin_define
define|#
directive|define
name|SRCRT_UNSPECERR
value|0x90
end_define

begin_comment
comment|/* unspecified src rt error */
end_comment

begin_define
define|#
directive|define
name|SRCRT_SYNTAX
value|0x91
end_define

begin_comment
comment|/* syntax error in src rt field */
end_comment

begin_define
define|#
directive|define
name|SRCRT_UNKNOWNADDR
value|0x92
end_define

begin_comment
comment|/* unknown addr in src rt field */
end_comment

begin_define
define|#
directive|define
name|SRCRT_BADPATH
value|0x93
end_define

begin_comment
comment|/* path not acceptable */
end_comment

begin_comment
comment|/* lifetime */
end_comment

begin_define
define|#
directive|define
name|TTL_EXPTRANSIT
value|0xa0
end_define

begin_comment
comment|/* lifetime expired during transit */
end_comment

begin_define
define|#
directive|define
name|TTL_EXPREASS
value|0xa1
end_define

begin_comment
comment|/* lifetime expired during reassembly */
end_comment

begin_comment
comment|/* pdu discarded */
end_comment

begin_define
define|#
directive|define
name|DISC_UNSUPPOPT
value|0xb0
end_define

begin_comment
comment|/* unsupported option not specified? */
end_comment

begin_define
define|#
directive|define
name|DISC_UNSUPPVERS
value|0xb1
end_define

begin_comment
comment|/* unsupported protocol version */
end_comment

begin_define
define|#
directive|define
name|DISC_UNSUPPSECURE
value|0xb2
end_define

begin_comment
comment|/* unsupported security option */
end_comment

begin_define
define|#
directive|define
name|DISC_UNSUPPSRCRT
value|0xb3
end_define

begin_comment
comment|/* unsupported src rt option */
end_comment

begin_define
define|#
directive|define
name|DISC_UNSUPPRECRT
value|0xb4
end_define

begin_comment
comment|/* unsupported rec rt option */
end_comment

begin_comment
comment|/* reassembly */
end_comment

begin_define
define|#
directive|define
name|REASS_INTERFERE
value|0xc0
end_define

begin_comment
comment|/* reassembly interference */
end_comment

begin_define
define|#
directive|define
name|CLNP_ERRORS
value|22
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|int
name|clnp_er_index
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLNP_ER_CODES
end_ifdef

begin_decl_stmt
name|u_char
name|clnp_er_codes
index|[
name|CLNP_ERRORS
index|]
init|=
block|{
name|GEN_NOREAS
block|,
name|GEN_PROTOERR
block|,
name|GEN_BADCSUM
block|,
name|GEN_CONGEST
block|,
name|GEN_HDRSYNTAX
block|,
name|GEN_SEGNEEDED
block|,
name|GEN_INCOMPLETE
block|,
name|GEN_DUPOPT
block|,
name|ADDR_DESTUNREACH
block|,
name|ADDR_DESTUNKNOWN
block|,
name|SRCRT_UNSPECERR
block|,
name|SRCRT_SYNTAX
block|,
name|SRCRT_UNKNOWNADDR
block|,
name|SRCRT_BADPATH
block|,
name|TTL_EXPTRANSIT
block|,
name|TTL_EXPREASS
block|,
name|DISC_UNSUPPOPT
block|,
name|DISC_UNSUPPVERS
block|,
name|DISC_UNSUPPSECURE
block|,
name|DISC_UNSUPPSRCRT
block|,
name|DISC_UNSUPPRECRT
block|,
name|REASS_INTERFERE
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TROLL
end_ifdef

begin_define
define|#
directive|define
name|TR_DUPEND
value|0x01
end_define

begin_comment
comment|/* duplicate end of fragment */
end_comment

begin_define
define|#
directive|define
name|TR_DUPPKT
value|0x02
end_define

begin_comment
comment|/* duplicate entire packet */
end_comment

begin_define
define|#
directive|define
name|TR_DROPPKT
value|0x04
end_define

begin_comment
comment|/* drop packet on output */
end_comment

begin_define
define|#
directive|define
name|TR_TRIM
value|0x08
end_define

begin_comment
comment|/* trim bytes from packet */
end_comment

begin_define
define|#
directive|define
name|TR_CHANGE
value|0x10
end_define

begin_comment
comment|/* change bytes in packet */
end_comment

begin_define
define|#
directive|define
name|TR_MTU
value|0x20
end_define

begin_comment
comment|/* delta to change device mtu */
end_comment

begin_define
define|#
directive|define
name|TR_CHUCK
value|0x40
end_define

begin_comment
comment|/* drop packet in rclnp_input */
end_comment

begin_define
define|#
directive|define
name|TR_BLAST
value|0x80
end_define

begin_comment
comment|/* force rclnp_output to blast many packet */
end_comment

begin_define
define|#
directive|define
name|TR_RAWLOOP
value|0x100
end_define

begin_comment
comment|/* make if_loop call clnpintr directly */
end_comment

begin_struct
struct|struct
name|troll
block|{
name|int
name|tr_ops
decl_stmt|;
comment|/* operations to perform */
name|float
name|tr_dup_size
decl_stmt|;
comment|/* % to duplicate */
name|float
name|tr_dup_freq
decl_stmt|;
comment|/* frequency to duplicate packets */
name|float
name|tr_drop_freq
decl_stmt|;
comment|/* frequence to drop packets */
name|int
name|tr_mtu_adj
decl_stmt|;
comment|/* delta to adjust if mtu */
name|int
name|tr_blast_cnt
decl_stmt|;
comment|/* # of pkts to blast out */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SN_OUTPUT
parameter_list|(
name|clcp
parameter_list|,
name|m
parameter_list|)
define|\
value|troll_output(clcp->clc_ifp, m, clcp->clc_firsthop, clcp->clc_rt)
end_define

begin_define
define|#
directive|define
name|SN_MTU
parameter_list|(
name|ifp
parameter_list|,
name|rt
parameter_list|)
value|(((rt&& rt->rt_rmx.rmx_mtu) ?\ 	rt->rt_rmx.rmx_mtu : clnp_badmtu(ifp, rt, __LINE__, __FILE__))\ 		- trollctl.tr_mtu_adj)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|float
name|troll_random
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO TROLL */
end_comment

begin_define
define|#
directive|define
name|SN_OUTPUT
parameter_list|(
name|clcp
parameter_list|,
name|m
parameter_list|)
define|\
value|(*clcp->clc_ifp->if_output)(clcp->clc_ifp, m, clcp->clc_firsthop, clcp->clc_rt)
end_define

begin_define
define|#
directive|define
name|SN_MTU
parameter_list|(
name|ifp
parameter_list|,
name|rt
parameter_list|)
value|(((rt&& rt->rt_rmx.rmx_mtu) ?\ 	rt->rt_rmx.rmx_mtu : clnp_badmtu(ifp, rt, __LINE__, __FILE__)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TROLL */
end_comment

begin_comment
comment|/*  *	Macro to remove an address from a clnp header  */
end_comment

begin_define
define|#
directive|define
name|CLNP_EXTRACT_ADDR
parameter_list|(
name|isoa
parameter_list|,
name|hoff
parameter_list|,
name|hend
parameter_list|)
define|\
value|{\ 		isoa.isoa_len = (u_char)*hoff;\ 		if ((((++hoff) + isoa.isoa_len)> hend) ||\ 			(isoa.isoa_len> 20) || (isoa.isoa_len == 0)) {\ 			hoff = (caddr_t)0;\ 		} else {\ 			(void) bcopy(hoff, (caddr_t)isoa.isoa_genaddr, isoa.isoa_len);\ 			hoff += isoa.isoa_len;\ 		}\ 	}
end_define

begin_comment
comment|/*  *	Macro to insert an address into a clnp header  */
end_comment

begin_define
define|#
directive|define
name|CLNP_INSERT_ADDR
parameter_list|(
name|hoff
parameter_list|,
name|isoa
parameter_list|)
define|\
value|*hoff++ = (isoa).isoa_len;\ 	(void) bcopy((caddr_t)((isoa).isoa_genaddr), hoff, (isoa).isoa_len);\ 	hoff += (isoa).isoa_len;
end_define

begin_comment
comment|/*  *	Clnp hdr cache.	Whenever a clnp packet is sent, a copy of the  *	header is made and kept in this cache. In addition to a copy of  *	the cached clnp hdr, the cache contains  *	information necessary to determine whether the new packet  *	to send requires a new header to be built.  */
end_comment

begin_struct
struct|struct
name|clnp_cache
block|{
comment|/* these fields are used to check the validity of the cache */
name|struct
name|iso_addr
name|clc_dst
decl_stmt|;
comment|/* destination of packet */
name|struct
name|mbuf
modifier|*
name|clc_options
decl_stmt|;
comment|/* ptr to options mbuf */
name|int
name|clc_flags
decl_stmt|;
comment|/* flags passed to clnp_output */
comment|/* these fields are state that clnp_output requires to finish the pkt */
name|int
name|clc_segoff
decl_stmt|;
comment|/* offset of seg part of header */
name|struct
name|rtentry
modifier|*
name|clc_rt
decl_stmt|;
comment|/* ptr to rtentry (points into 											the route structure) */
name|struct
name|sockaddr
modifier|*
name|clc_firsthop
decl_stmt|;
comment|/* first hop of packet */
name|struct
name|ifnet
modifier|*
name|clc_ifp
decl_stmt|;
comment|/* ptr to interface structure */
name|struct
name|iso_ifaddr
modifier|*
name|clc_ifa
decl_stmt|;
comment|/* ptr to interface address */
name|struct
name|mbuf
modifier|*
name|clc_hdr
decl_stmt|;
comment|/* cached pkt hdr (finally)! */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|satosiso
end_ifndef

begin_define
define|#
directive|define
name|satosiso
parameter_list|(
name|sa
parameter_list|)
define|\
value|((struct sockaddr_iso *)(sa))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|caddr_t
name|clnp_insert_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|iso_addr
modifier|*
name|clnp_srcaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|clnp_reass
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TROLL
end_ifdef

begin_decl_stmt
name|struct
name|troll
name|trollctl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TROLL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

