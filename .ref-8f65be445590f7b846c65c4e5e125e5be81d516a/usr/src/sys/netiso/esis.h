begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  *	$Header: esis.h,v 4.7 88/09/15 11:24:18 hagens Exp $  *	$Source: /usr/argo/sys/netiso/RCS/esis.h,v $  *	@(#)esis.h	7.3 (Berkeley) %G% *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_comment
comment|/*  * Definitions for byte order,  * according to byte significance from low address to high.  */
end_comment

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* mc68000, tahoe, most others */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|BYTE_ORDER
end_endif

begin_define
define|#
directive|define
name|SNPAC_AGE
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|ESIS_CONFIG
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|ESIS_HT
value|(ESIS_CONFIG * 2)
end_define

begin_comment
comment|/*  *	Fixed part of an ESIS header  */
end_comment

begin_struct
struct|struct
name|esis_fixed
block|{
name|u_char
name|esis_proto_id
decl_stmt|;
comment|/* network layer protocol identifier */
name|u_char
name|esis_hdr_len
decl_stmt|;
comment|/* length indicator (octets) */
name|u_char
name|esis_vers
decl_stmt|;
comment|/* version/protocol identifier extension */
name|u_char
name|esis_res1
decl_stmt|;
comment|/* reserved */
name|u_char
name|esis_type
decl_stmt|;
comment|/* type code */
comment|/* technically, type should be&='d 0x1f */
define|#
directive|define
name|ESIS_ESH
value|0x02
comment|/* End System Hello */
define|#
directive|define
name|ESIS_ISH
value|0x04
comment|/* Intermediate System Hello */
define|#
directive|define
name|ESIS_RD
value|0x06
comment|/* Redirect */
name|u_char
name|esis_ht_msb
decl_stmt|;
comment|/* holding time (seconds) high byte */
name|u_char
name|esis_ht_lsb
decl_stmt|;
comment|/* holding time (seconds) low byte */
name|u_char
name|esis_cksum_msb
decl_stmt|;
comment|/* checksum high byte */
name|u_char
name|esis_cksum_lsb
decl_stmt|;
comment|/* checksum low byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for ESIS datagram options  */
end_comment

begin_define
define|#
directive|define
name|ESISOVAL_NETMASK
value|0xe1
end_define

begin_comment
comment|/* address mask option, RD PDU only */
end_comment

begin_define
define|#
directive|define
name|ESISOVAL_SNPAMASK
value|0xe2
end_define

begin_comment
comment|/* snpa mask option, RD PDU only */
end_comment

begin_define
define|#
directive|define
name|ESISOVAL_ESCT
value|0xc6
end_define

begin_comment
comment|/* end system conf. timer, ISH PDU only */
end_comment

begin_define
define|#
directive|define
name|ESIS_CKSUM_OFF
value|0x07
end_define

begin_define
define|#
directive|define
name|ESIS_CKSUM_REQUIRED
parameter_list|(
name|pdu
parameter_list|)
define|\
value|((pdu->esis_cksum_msb != 0) || (pdu->esis_cksum_lsb != 0))
end_define

begin_define
define|#
directive|define
name|ESIS_VERSION
value|1
end_define

begin_struct
struct|struct
name|esis_stat
block|{
name|u_short
name|es_nomem
decl_stmt|;
comment|/* insufficient memory to send hello */
name|u_short
name|es_badcsum
decl_stmt|;
comment|/* incorrect checksum */
name|u_short
name|es_badvers
decl_stmt|;
comment|/* incorrect version number */
name|u_short
name|es_badtype
decl_stmt|;
comment|/* unknown pdu type field */
name|u_short
name|es_toosmall
decl_stmt|;
comment|/* packet too small */
name|u_short
name|es_eshsent
decl_stmt|;
comment|/* ESH sent */
name|u_short
name|es_eshrcvd
decl_stmt|;
comment|/* ESH rcvd */
name|u_short
name|es_ishsent
decl_stmt|;
comment|/* ISH sent */
name|u_short
name|es_ishrcvd
decl_stmt|;
comment|/* ISH rcvd */
name|u_short
name|es_rdsent
decl_stmt|;
comment|/* RD sent */
name|u_short
name|es_rdrcvd
decl_stmt|;
comment|/* RD rcvd */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|esis_stat
name|esis_stat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

