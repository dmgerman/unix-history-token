begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $Header: iso.h,v 4.9 88/09/11 18:06:38 hagens Exp $ */
end_comment

begin_comment
comment|/* $Source: /usr/argo/sys/netiso/RCS/iso.h,v $ */
end_comment

begin_comment
comment|/*	@(#)iso.h	7.2 (Berkeley) %G% */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISO__
end_ifndef

begin_define
define|#
directive|define
name|__ISO__
end_define

begin_comment
comment|/*  *	Return true if this is a multicast address  *	This assumes that the bit transmission is lsb first. This   *	assumption is valid for 802.3 but not 802.5. There is a  *	kludge to get around this for 802.5 -- see if_lan.c  *	where subnetwork header is setup.  */
end_comment

begin_define
define|#
directive|define
name|IS_MULTICAST
parameter_list|(
name|snpa
parameter_list|)
define|\
value|((snpa)[0]& 0x01)
end_define

begin_comment
comment|/*  * Protocols  */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP0
value|25
end_define

begin_comment
comment|/* connection oriented transport protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP1
value|26
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP2
value|27
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP3
value|28
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP4
value|29
end_define

begin_comment
comment|/* connection oriented transport protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP
value|ISOPROTO_TP4
end_define

begin_comment
comment|/* tp-4 with negotiation */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_CLTP
value|30
end_define

begin_comment
comment|/* connectionless transport (not yet impl.) */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_CLNP
value|31
end_define

begin_comment
comment|/* connectionless internetworking protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_X25
value|32
end_define

begin_comment
comment|/* cons */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_INACT_NL
value|33
end_define

begin_comment
comment|/* inactive network layer! */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_ESIS
value|34
end_define

begin_comment
comment|/* ES-IS protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_RAW
value|255
end_define

begin_comment
comment|/* raw clnp */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_MAX
value|256
end_define

begin_define
define|#
directive|define
name|ISO_PORT_RESERVED
value|1024
end_define

begin_define
define|#
directive|define
name|ISO_PORT_USERRESERVED
value|5000
end_define

begin_comment
comment|/*  * Port/socket numbers: standard network functions  * NOT PRESENTLY USED  */
end_comment

begin_define
define|#
directive|define
name|ISO_PORT_MAINT
value|501
end_define

begin_define
define|#
directive|define
name|ISO_PORT_ECHO
value|507
end_define

begin_define
define|#
directive|define
name|ISO_PORT_DISCARD
value|509
end_define

begin_define
define|#
directive|define
name|ISO_PORT_SYSTAT
value|511
end_define

begin_define
define|#
directive|define
name|ISO_PORT_NETSTAT
value|515
end_define

begin_comment
comment|/*  * Port/socket numbers: non-standard application functions  */
end_comment

begin_define
define|#
directive|define
name|ISO_PORT_LOGIN
value|513
end_define

begin_comment
comment|/*  * Port/socket numbers: public use  */
end_comment

begin_define
define|#
directive|define
name|ISO_PORT_PUBLIC
value|1024
end_define

begin_comment
comment|/* high bit set --> public */
end_comment

begin_comment
comment|/*  *	Network layer protocol identifiers  */
end_comment

begin_define
define|#
directive|define
name|ISO8473_CLNP
value|0x81
end_define

begin_define
define|#
directive|define
name|ISO9542_ESIS
value|0x82
end_define

begin_define
define|#
directive|define
name|ISO9542X25_ESIS
value|0x8a
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN_CLASSA_NET
end_ifndef

begin_include
include|#
directive|include
file|"../netinet/in.h"
end_include

begin_endif
endif|#
directive|endif
endif|IN_CLASSA_NET
end_endif

begin_comment
comment|/*  *	Type 37 Address  *  *	This address is named for the value of its AFI (37). This format  *	supports an X.121 address. A type 37 address has the following format:  *  *<----- idp -------><- dsp ->  *<- afi -><- idi -><- dsp ->  *  | "37"   | 7 bytes | 9 bytes |  *  *	The idi contains 14 bcd digits of X.121 address.  *	The use of the dsp part is unknown.  *  *	The afi is considered the "network" portion of the address.  *  This means that you can't have multihoming in the x.25 environment.  *  Makes loopback a bear.  */
end_comment

begin_define
define|#
directive|define
name|BIGSOCKADDRS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BIGSOCKADDRS
end_ifdef

begin_define
define|#
directive|define
name|ADDR37_IDI_LEN
value|7
end_define

begin_comment
comment|/* 14 bcd digits == 7 octets */
end_comment

begin_define
define|#
directive|define
name|ADDR37_DSP_LEN
value|9
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ADDR37_IDI_LEN
value|7
end_define

begin_comment
comment|/* 14 bcd digits == 7 octets */
end_comment

begin_define
define|#
directive|define
name|ADDR37_DSP_LEN
value|3
end_define

begin_comment
comment|/* this is a lie to fit in sockaddr */
end_comment

begin_endif
endif|#
directive|endif
endif|BIGSOCKADDRS
end_endif

begin_struct
struct|struct
name|addr_37
block|{
name|u_char
name|a37_idi
index|[
name|ADDR37_IDI_LEN
index|]
decl_stmt|;
comment|/* initial domain identifier */
name|u_char
name|a37_dsp
index|[
name|ADDR37_DSP_LEN
index|]
decl_stmt|;
comment|/* domain specific part */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ovl_37
block|{
comment|/* overlay for type 37 address */
name|u_char
name|o37_afi
decl_stmt|;
comment|/* afi */
name|u_char
name|o37_x121
index|[
name|ADDR37_IDI_LEN
index|]
decl_stmt|;
comment|/* X.121 address */
name|u_char
name|o37_dsp
index|[
name|ADDR37_DSP_LEN
index|]
decl_stmt|;
comment|/* unknown use at this time */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	OSINET address  *  *	This style address is used by the OSINET group  *	An OSINET address has the following (variable-length) format  *  *<----- idp -------><---------------- dsp --------------------------->  *<- afi -><- idi -><---------------- dsp --------------------------->  *  | "47"   | "0004"   |             11 bytes                            |  *  |  afi(1)| osinetid | orgid(2) | subnet id(2) | (4-8) | nsap sel(1) |  *  *	the afi, orgid, and subnet id are considered the "network" portion of  *	the address.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIGSOCKADDRS
end_ifdef

begin_define
define|#
directive|define
name|ADDROSINET_IDI_LEN
value|2
end_define

begin_define
define|#
directive|define
name|ADDROSINET_DSP_LEN
value|11
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ADDROSINET_IDI_LEN
value|2
end_define

begin_define
define|#
directive|define
name|ADDROSINET_DSP_LEN
value|8
end_define

begin_comment
comment|/* this is a lie to fit in sockaddr */
end_comment

begin_endif
endif|#
directive|endif
endif|BIGSOCKADDRS
end_endif

begin_struct
struct|struct
name|addr_osinet
block|{
name|u_char
name|aosi_idi
index|[
name|ADDROSINET_IDI_LEN
index|]
decl_stmt|;
comment|/* initial domain identifier */
name|u_char
name|aosi_dsp
index|[
name|ADDROSINET_DSP_LEN
index|]
decl_stmt|;
comment|/* domain specific part */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OVLOSINET_ID_LEN
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BIGSOCKADDRS
end_ifdef

begin_define
define|#
directive|define
name|OVLOSINET_ORGID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|OVLOSINET_SNETID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|OVLOSINET_SNPA_LEN
value|8
end_define

begin_define
define|#
directive|define
name|OVLOSINET_NSAP_LEN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OVLOSINET_ORGID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|OVLOSINET_SNETID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|OVLOSINET_SNPA_LEN
value|5
end_define

begin_comment
comment|/* this is a lie to fit in sockaddr */
end_comment

begin_define
define|#
directive|define
name|OVLOSINET_NSAP_LEN
value|1
end_define

begin_endif
endif|#
directive|endif
endif|BIGSOCKADDRS
end_endif

begin_struct
struct|struct
name|ovl_osinet
block|{
comment|/* overlay for osinet address */
name|u_char
name|oosi_afi
decl_stmt|;
comment|/* afi */
name|u_char
name|oosi_id
index|[
name|OVLOSINET_ID_LEN
index|]
decl_stmt|;
comment|/* osinet id */
name|u_char
name|oosi_orgid
index|[
name|OVLOSINET_ORGID_LEN
index|]
decl_stmt|;
comment|/* orgid */
name|u_char
name|oosi_snetid
index|[
name|OVLOSINET_SNETID_LEN
index|]
decl_stmt|;
comment|/* subnet id */
name|u_char
name|oosi_snpa
index|[
name|OVLOSINET_SNPA_LEN
index|]
decl_stmt|;
comment|/* snpa */
name|u_char
name|oosi_nsap
index|[
name|OVLOSINET_NSAP_LEN
index|]
decl_stmt|;
comment|/* nsap sel */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	RFC 986 address  *  *	This style address is used when DOD internet addresses are used  *	The format of rfc986 addresses is:  *  *<----- idp -------><---------------- dsp -------------------->  *<- afi -><- idi -><---------------- dsp -------------------->  *  | "47"   | "0006"  |             6 bytes                       |  *  |  afi(1)| idi(2)  | version (1) | inet addr (4) | proto id(1) |  *  *	the afi, idi, and network portion of the inet address are considered   *	the "network" portion of the address.  */
end_comment

begin_define
define|#
directive|define
name|ADDRRFC986_IDI_LEN
value|2
end_define

begin_define
define|#
directive|define
name|ADDRRFC986_DSP_LEN
value|6
end_define

begin_struct
struct|struct
name|addr_rfc986
block|{
name|u_char
name|a986_idi
index|[
name|ADDRRFC986_IDI_LEN
index|]
decl_stmt|;
comment|/* initial domain identifier */
name|u_char
name|a986_dsp
index|[
name|ADDRRFC986_DSP_LEN
index|]
decl_stmt|;
comment|/* domain specific part */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OVLRFC986_INET_LEN
value|4
end_define

begin_struct
struct|struct
name|ovl_rfc986
block|{
name|u_char
name|o986_afi
decl_stmt|;
comment|/* afi */
name|u_char
name|o986_idi
index|[
name|ADDRRFC986_IDI_LEN
index|]
decl_stmt|;
comment|/* idi */
name|u_char
name|o986_vers
decl_stmt|;
comment|/* version */
name|u_char
name|o986_inetaddr
index|[
name|OVLRFC986_INET_LEN
index|]
decl_stmt|;
comment|/* internet address */
name|u_char
name|o986_upid
decl_stmt|;
comment|/* upper protocol id */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RFC986V1
value|0x01
end_define

begin_comment
comment|/* version of 986 addr */
end_comment

begin_define
define|#
directive|define
name|AFI_37
value|0x37
end_define

begin_comment
comment|/* bcd of "37" */
end_comment

begin_define
define|#
directive|define
name|AFI_OSINET
value|0x47
end_define

begin_comment
comment|/* bcd of "47" */
end_comment

begin_define
define|#
directive|define
name|AFI_RFC986
value|0x47
end_define

begin_comment
comment|/* bcd of "47" */
end_comment

begin_define
define|#
directive|define
name|AFI_SNA
value|0x00
end_define

begin_comment
comment|/* SubNetwork Address; invalid really... 								- used by ES-IS */
end_comment

begin_comment
comment|/* the idi for type 37 addresses is very different than the others */
end_comment

begin_define
define|#
directive|define
name|IDI_OSINET
value|0x0004
end_define

begin_comment
comment|/* bcd of "0004" */
end_comment

begin_define
define|#
directive|define
name|IDI_RFC986
value|0x0006
end_define

begin_comment
comment|/* bcd of "0006" */
end_comment

begin_comment
comment|/*  *	This address type is used to store a subnetwork address in a   *	sockaddr_iso. The isoa_len field should contain the length of the  *	subnetwork address plus the length of the afi (ie +1 ).  *  *	This address format is used only by the ES-IS protocol  */
end_comment

begin_define
define|#
directive|define
name|ADDRSNA_IDI_LEN
value|7
end_define

begin_struct
struct|struct
name|addr_sn
block|{
name|char
name|sna_addr
index|[
name|ADDRSNA_IDI_LEN
index|]
decl_stmt|;
comment|/* subnetwork address */
block|}
struct|;
end_struct

begin_comment
comment|/*   *	Type 47 is the biggest address: 11 bytes. The length of iso_addr  *	is 13 bytes.  */
end_comment

begin_struct
struct|struct
name|old_iso_addr
block|{
name|u_char
name|isoa_afi
decl_stmt|;
comment|/* authority and format id */
union|union
block|{
name|struct
name|addr_37
name|addr_37
decl_stmt|;
comment|/* type 37 */
name|struct
name|addr_osinet
name|addr_osinet
decl_stmt|;
comment|/* type osinet */
name|struct
name|addr_rfc986
name|addr_rfc986
decl_stmt|;
comment|/* type rfc986 */
name|struct
name|addr_sn
name|addr_sn
decl_stmt|;
comment|/* subnetwork address */
block|}
name|isoa_u
union|;
name|u_char
name|isoa_len
decl_stmt|;
comment|/* length (in bytes) */
block|}
struct|;
end_struct

begin_comment
comment|/* The following looks like a sockaddr  * in case we decide to use tree routines */
end_comment

begin_struct
struct|struct
name|iso_addr
block|{
name|u_char
name|isoa_len
decl_stmt|;
comment|/* length (in bytes) */
name|char
name|isoa_genaddr
index|[
literal|20
index|]
decl_stmt|;
comment|/* general opaque address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|t37_idi
value|isoa_u.addr_37.a37_idi
end_define

begin_define
define|#
directive|define
name|t37_dsp
value|isoa_u.addr_37.a37_dsp
end_define

begin_define
define|#
directive|define
name|osinet_idi
value|isoa_u.addr_osinet.aosi_idi
end_define

begin_define
define|#
directive|define
name|osinet_dsp
value|isoa_u.addr_osinet.aosi_dsp
end_define

begin_define
define|#
directive|define
name|rfc986_idi
value|isoa_u.addr_rfc986.a986_idi
end_define

begin_define
define|#
directive|define
name|rfc986_dsp
value|isoa_u.addr_rfc986.a986_dsp
end_define

begin_define
define|#
directive|define
name|sna_idi
value|isoa_u.addr_sn.sna_addr
end_define

begin_comment
comment|/*  *	An iso_addr is 18 bytes, a sockaddr_iso is therefore 20 bytes.  *	the struct sockaddr data field has been changed to 22 bytes.  *  * severly changed osinet and t37 addresses from argo code, we don't want  * sockaddrs to grow bigger than the original 16 bytes so we changed the   * t37 and osinet addresses so that they were only 10 bytes long  */
end_comment

begin_struct
struct|struct
name|sockaddr_iso
block|{
name|u_char
name|siso_len
decl_stmt|;
comment|/* length */
name|u_char
name|siso_family
decl_stmt|;
comment|/* family */
name|u_char
name|siso_ssuffixlen
decl_stmt|;
comment|/* session suffix len */
name|u_char
name|siso_tsuffixlen
decl_stmt|;
comment|/* transport suffix len */
comment|/*  u_char				siso_nsaptype;		/* someday?? */
name|struct
name|iso_addr
name|siso_addr
decl_stmt|;
comment|/* network address */
name|u_char
name|siso_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* make multiple of sizeof long */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|siso_data
value|siso_addr.isoa_genaddr
end_define

begin_define
define|#
directive|define
name|siso_nlen
value|siso_addr.isoa_len
end_define

begin_define
define|#
directive|define
name|TSEL
parameter_list|(
name|s
parameter_list|)
value|((caddr_t)((s)->siso_data + (s)->siso_nlen))
end_define

begin_define
define|#
directive|define
name|SAME_ISOADDR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(bcmp((a)->siso_data, (b)->siso_data, (unsigned)(a)->siso_nlen)==0)
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_INET
value|0
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_X121BCD
value|1
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_X121BIN
value|2
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_DCCBCD
value|3
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_DCCBIN
value|4
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_OSINET
value|5
end_define

begin_define
define|#
directive|define
name|NSAPTYPE_RFC986
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|iso_netmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iso_hash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iso_addrmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|iso_ifaddr
modifier|*
name|iso_iaonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|isodomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|isosw
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* user utilities definitions from the iso library */
end_comment

begin_function_decl
name|char
modifier|*
name|iso_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|hostent
modifier|*
name|iso_gethostbyname
argument_list|()
decl_stmt|,
modifier|*
name|iso_gethostbyaddr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_endif
endif|#
directive|endif
endif|__ISO__
end_endif

begin_define
define|#
directive|define
name|_offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|((int)((caddr_t)&((t *)0)->m))
end_define

end_unit

