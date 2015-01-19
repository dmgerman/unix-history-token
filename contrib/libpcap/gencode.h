begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*  * ATM support:  *  * Copyright (c) 1997 Yen Yen Lim and North Dakota State University  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Yen Yen Lim and  *      North Dakota State University  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___ATTRIBUTE__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___ATTRIBUTE__ */
end_comment

begin_comment
comment|/* Address qualifiers. */
end_comment

begin_define
define|#
directive|define
name|Q_HOST
value|1
end_define

begin_define
define|#
directive|define
name|Q_NET
value|2
end_define

begin_define
define|#
directive|define
name|Q_PORT
value|3
end_define

begin_define
define|#
directive|define
name|Q_GATEWAY
value|4
end_define

begin_define
define|#
directive|define
name|Q_PROTO
value|5
end_define

begin_define
define|#
directive|define
name|Q_PROTOCHAIN
value|6
end_define

begin_define
define|#
directive|define
name|Q_PORTRANGE
value|7
end_define

begin_comment
comment|/* Protocol qualifiers. */
end_comment

begin_define
define|#
directive|define
name|Q_LINK
value|1
end_define

begin_define
define|#
directive|define
name|Q_IP
value|2
end_define

begin_define
define|#
directive|define
name|Q_ARP
value|3
end_define

begin_define
define|#
directive|define
name|Q_RARP
value|4
end_define

begin_define
define|#
directive|define
name|Q_SCTP
value|5
end_define

begin_define
define|#
directive|define
name|Q_TCP
value|6
end_define

begin_define
define|#
directive|define
name|Q_UDP
value|7
end_define

begin_define
define|#
directive|define
name|Q_ICMP
value|8
end_define

begin_define
define|#
directive|define
name|Q_IGMP
value|9
end_define

begin_define
define|#
directive|define
name|Q_IGRP
value|10
end_define

begin_define
define|#
directive|define
name|Q_ATALK
value|11
end_define

begin_define
define|#
directive|define
name|Q_DECNET
value|12
end_define

begin_define
define|#
directive|define
name|Q_LAT
value|13
end_define

begin_define
define|#
directive|define
name|Q_SCA
value|14
end_define

begin_define
define|#
directive|define
name|Q_MOPRC
value|15
end_define

begin_define
define|#
directive|define
name|Q_MOPDL
value|16
end_define

begin_define
define|#
directive|define
name|Q_IPV6
value|17
end_define

begin_define
define|#
directive|define
name|Q_ICMPV6
value|18
end_define

begin_define
define|#
directive|define
name|Q_AH
value|19
end_define

begin_define
define|#
directive|define
name|Q_ESP
value|20
end_define

begin_define
define|#
directive|define
name|Q_PIM
value|21
end_define

begin_define
define|#
directive|define
name|Q_VRRP
value|22
end_define

begin_define
define|#
directive|define
name|Q_AARP
value|23
end_define

begin_define
define|#
directive|define
name|Q_ISO
value|24
end_define

begin_define
define|#
directive|define
name|Q_ESIS
value|25
end_define

begin_define
define|#
directive|define
name|Q_ISIS
value|26
end_define

begin_define
define|#
directive|define
name|Q_CLNP
value|27
end_define

begin_define
define|#
directive|define
name|Q_STP
value|28
end_define

begin_define
define|#
directive|define
name|Q_IPX
value|29
end_define

begin_define
define|#
directive|define
name|Q_NETBEUI
value|30
end_define

begin_comment
comment|/* IS-IS Levels */
end_comment

begin_define
define|#
directive|define
name|Q_ISIS_L1
value|31
end_define

begin_define
define|#
directive|define
name|Q_ISIS_L2
value|32
end_define

begin_comment
comment|/* PDU types */
end_comment

begin_define
define|#
directive|define
name|Q_ISIS_IIH
value|33
end_define

begin_define
define|#
directive|define
name|Q_ISIS_LAN_IIH
value|34
end_define

begin_define
define|#
directive|define
name|Q_ISIS_PTP_IIH
value|35
end_define

begin_define
define|#
directive|define
name|Q_ISIS_SNP
value|36
end_define

begin_define
define|#
directive|define
name|Q_ISIS_CSNP
value|37
end_define

begin_define
define|#
directive|define
name|Q_ISIS_PSNP
value|38
end_define

begin_define
define|#
directive|define
name|Q_ISIS_LSP
value|39
end_define

begin_define
define|#
directive|define
name|Q_RADIO
value|40
end_define

begin_define
define|#
directive|define
name|Q_CARP
value|41
end_define

begin_comment
comment|/* Directional qualifiers. */
end_comment

begin_define
define|#
directive|define
name|Q_SRC
value|1
end_define

begin_define
define|#
directive|define
name|Q_DST
value|2
end_define

begin_define
define|#
directive|define
name|Q_OR
value|3
end_define

begin_define
define|#
directive|define
name|Q_AND
value|4
end_define

begin_define
define|#
directive|define
name|Q_ADDR1
value|5
end_define

begin_define
define|#
directive|define
name|Q_ADDR2
value|6
end_define

begin_define
define|#
directive|define
name|Q_ADDR3
value|7
end_define

begin_define
define|#
directive|define
name|Q_ADDR4
value|8
end_define

begin_define
define|#
directive|define
name|Q_RA
value|9
end_define

begin_define
define|#
directive|define
name|Q_TA
value|10
end_define

begin_define
define|#
directive|define
name|Q_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|Q_UNDEF
value|255
end_define

begin_comment
comment|/* ATM types */
end_comment

begin_define
define|#
directive|define
name|A_METAC
value|22
end_define

begin_comment
comment|/* Meta signalling Circuit */
end_comment

begin_define
define|#
directive|define
name|A_BCC
value|23
end_define

begin_comment
comment|/* Broadcast Circuit */
end_comment

begin_define
define|#
directive|define
name|A_OAMF4SC
value|24
end_define

begin_comment
comment|/* Segment OAM F4 Circuit */
end_comment

begin_define
define|#
directive|define
name|A_OAMF4EC
value|25
end_define

begin_comment
comment|/* End-to-End OAM F4 Circuit */
end_comment

begin_define
define|#
directive|define
name|A_SC
value|26
end_define

begin_comment
comment|/* Signalling Circuit*/
end_comment

begin_define
define|#
directive|define
name|A_ILMIC
value|27
end_define

begin_comment
comment|/* ILMI Circuit */
end_comment

begin_define
define|#
directive|define
name|A_OAM
value|28
end_define

begin_comment
comment|/* OAM cells : F4 only */
end_comment

begin_define
define|#
directive|define
name|A_OAMF4
value|29
end_define

begin_comment
comment|/* OAM F4 cells: Segment + End-to-end */
end_comment

begin_define
define|#
directive|define
name|A_LANE
value|30
end_define

begin_comment
comment|/* LANE traffic */
end_comment

begin_define
define|#
directive|define
name|A_LLC
value|31
end_define

begin_comment
comment|/* LLC-encapsulated traffic */
end_comment

begin_comment
comment|/* Based on Q.2931 signalling protocol */
end_comment

begin_define
define|#
directive|define
name|A_SETUP
value|41
end_define

begin_comment
comment|/* Setup message */
end_comment

begin_define
define|#
directive|define
name|A_CALLPROCEED
value|42
end_define

begin_comment
comment|/* Call proceeding message */
end_comment

begin_define
define|#
directive|define
name|A_CONNECT
value|43
end_define

begin_comment
comment|/* Connect message */
end_comment

begin_define
define|#
directive|define
name|A_CONNECTACK
value|44
end_define

begin_comment
comment|/* Connect Ack message */
end_comment

begin_define
define|#
directive|define
name|A_RELEASE
value|45
end_define

begin_comment
comment|/* Release message */
end_comment

begin_define
define|#
directive|define
name|A_RELEASE_DONE
value|46
end_define

begin_comment
comment|/* Release message */
end_comment

begin_comment
comment|/* ATM field types */
end_comment

begin_define
define|#
directive|define
name|A_VPI
value|51
end_define

begin_define
define|#
directive|define
name|A_VCI
value|52
end_define

begin_define
define|#
directive|define
name|A_PROTOTYPE
value|53
end_define

begin_define
define|#
directive|define
name|A_MSGTYPE
value|54
end_define

begin_define
define|#
directive|define
name|A_CALLREFTYPE
value|55
end_define

begin_define
define|#
directive|define
name|A_CONNECTMSG
value|70
end_define

begin_comment
comment|/* returns Q.2931 signalling messages for 				   establishing and destroying switched 				   virtual connection */
end_comment

begin_define
define|#
directive|define
name|A_METACONNECT
value|71
end_define

begin_comment
comment|/* returns Q.2931 signalling messages for 				   establishing and destroying predefined 				   virtual circuits, such as broadcast 				   circuit, oamf4 segment circuit, oamf4 				   end-to-end circuits, ILMI circuits or 				   connection signalling circuit. */
end_comment

begin_comment
comment|/* MTP2 types */
end_comment

begin_define
define|#
directive|define
name|M_FISU
value|22
end_define

begin_comment
comment|/* FISU */
end_comment

begin_define
define|#
directive|define
name|M_LSSU
value|23
end_define

begin_comment
comment|/* LSSU */
end_comment

begin_define
define|#
directive|define
name|M_MSU
value|24
end_define

begin_comment
comment|/* MSU */
end_comment

begin_comment
comment|/* MTP2 HSL types */
end_comment

begin_define
define|#
directive|define
name|MH_FISU
value|25
end_define

begin_comment
comment|/* FISU for HSL */
end_comment

begin_define
define|#
directive|define
name|MH_LSSU
value|26
end_define

begin_comment
comment|/* LSSU */
end_comment

begin_define
define|#
directive|define
name|MH_MSU
value|27
end_define

begin_comment
comment|/* MSU */
end_comment

begin_comment
comment|/* MTP3 field types */
end_comment

begin_define
define|#
directive|define
name|M_SIO
value|1
end_define

begin_define
define|#
directive|define
name|M_OPC
value|2
end_define

begin_define
define|#
directive|define
name|M_DPC
value|3
end_define

begin_define
define|#
directive|define
name|M_SLS
value|4
end_define

begin_comment
comment|/* MTP3 field types in case of MTP2 HSL */
end_comment

begin_define
define|#
directive|define
name|MH_SIO
value|5
end_define

begin_define
define|#
directive|define
name|MH_OPC
value|6
end_define

begin_define
define|#
directive|define
name|MH_DPC
value|7
end_define

begin_define
define|#
directive|define
name|MH_SLS
value|8
end_define

begin_struct_decl
struct_decl|struct
name|slist
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|stmt
block|{
name|int
name|code
decl_stmt|;
name|struct
name|slist
modifier|*
name|jt
decl_stmt|;
comment|/*only for relative jump in block*/
name|struct
name|slist
modifier|*
name|jf
decl_stmt|;
comment|/*only for relative jump in block*/
name|bpf_int32
name|k
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|slist
block|{
name|struct
name|stmt
name|s
decl_stmt|;
name|struct
name|slist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A bit vector to represent definition sets.  We assume TOT_REGISTERS  * is smaller than 8*sizeof(atomset).  */
end_comment

begin_typedef
typedef|typedef
name|bpf_u_int32
name|atomset
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOMMASK
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|ATOMELEM
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|)
value|(d& ATOMMASK(n))
end_define

begin_comment
comment|/*  * An unbounded set.  */
end_comment

begin_typedef
typedef|typedef
name|bpf_u_int32
modifier|*
name|uset
typedef|;
end_typedef

begin_comment
comment|/*  * Total number of atomic entities, including accumulator (A) and index (X).  * We treat all these guys similarly during flow analysis.  */
end_comment

begin_define
define|#
directive|define
name|N_ATOMS
value|(BPF_MEMWORDS+2)
end_define

begin_struct
struct|struct
name|edge
block|{
name|int
name|id
decl_stmt|;
name|int
name|code
decl_stmt|;
name|uset
name|edom
decl_stmt|;
name|struct
name|block
modifier|*
name|succ
decl_stmt|;
name|struct
name|block
modifier|*
name|pred
decl_stmt|;
name|struct
name|edge
modifier|*
name|next
decl_stmt|;
comment|/* link list of incoming edges for a node */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|block
block|{
name|int
name|id
decl_stmt|;
name|struct
name|slist
modifier|*
name|stmts
decl_stmt|;
comment|/* side effect stmts */
name|struct
name|stmt
name|s
decl_stmt|;
comment|/* branch stmt */
name|int
name|mark
decl_stmt|;
name|u_int
name|longjt
decl_stmt|;
comment|/* jt branch requires long jump */
name|u_int
name|longjf
decl_stmt|;
comment|/* jf branch requires long jump */
name|int
name|level
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|sense
decl_stmt|;
name|struct
name|edge
name|et
decl_stmt|;
name|struct
name|edge
name|ef
decl_stmt|;
name|struct
name|block
modifier|*
name|head
decl_stmt|;
name|struct
name|block
modifier|*
name|link
decl_stmt|;
comment|/* link field used by optimizer */
name|uset
name|dom
decl_stmt|;
name|uset
name|closure
decl_stmt|;
name|struct
name|edge
modifier|*
name|in_edges
decl_stmt|;
name|atomset
name|def
decl_stmt|,
name|kill
decl_stmt|;
name|atomset
name|in_use
decl_stmt|;
name|atomset
name|out_use
decl_stmt|;
name|int
name|oval
decl_stmt|;
name|int
name|val
index|[
name|N_ATOMS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arth
block|{
name|struct
name|block
modifier|*
name|b
decl_stmt|;
comment|/* protocol checks */
name|struct
name|slist
modifier|*
name|s
decl_stmt|;
comment|/* stmt list */
name|int
name|regno
decl_stmt|;
comment|/* virtual register number of result */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|qual
block|{
name|unsigned
name|char
name|addr
decl_stmt|;
name|unsigned
name|char
name|proto
decl_stmt|;
name|unsigned
name|char
name|dir
decl_stmt|;
name|unsigned
name|char
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|arth
modifier|*
name|gen_loadi
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|arth
modifier|*
name|gen_load
parameter_list|(
name|int
parameter_list|,
name|struct
name|arth
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|arth
modifier|*
name|gen_loadlen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|arth
modifier|*
name|gen_neg
parameter_list|(
name|struct
name|arth
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|arth
modifier|*
name|gen_arth
parameter_list|(
name|int
parameter_list|,
name|struct
name|arth
modifier|*
parameter_list|,
name|struct
name|arth
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_and
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|,
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_or
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|,
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_not
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_scode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_ecode
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|struct
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_acode
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|struct
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_mcode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
name|struct
name|block
modifier|*
name|gen_mcode6
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|block
modifier|*
name|gen_ncode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|bpf_u_int32
parameter_list|,
name|struct
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_proto_abbrev
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_relation
parameter_list|(
name|int
parameter_list|,
name|struct
name|arth
modifier|*
parameter_list|,
name|struct
name|arth
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_less
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_greater
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_byteop
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_broadcast
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_multicast
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_inbound
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_llc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_llc_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_llc_s
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_llc_u
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_llc_s_subtype
parameter_list|(
name|bpf_u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_llc_u_subtype
parameter_list|(
name|bpf_u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_vlan
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_mpls
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pppoed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pppoes
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_atmfield_code
parameter_list|(
name|int
name|atmfield
parameter_list|,
name|bpf_int32
name|jvalue
parameter_list|,
name|bpf_u_int32
name|jtype
parameter_list|,
name|int
name|reverse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_atmtype_abbrev
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_atmmulti_abbrev
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_mtp2type_abbrev
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_mtp3field_code
parameter_list|(
name|int
name|mtp3field
parameter_list|,
name|bpf_u_int32
name|jvalue
parameter_list|,
name|bpf_u_int32
name|jtype
parameter_list|,
name|int
name|reverse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_ifname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_rnr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_srnr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_ruleset
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_reason
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_action
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_pf_dir
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_p80211_type
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|gen_p80211_fcdir
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_optimize
parameter_list|(
name|struct
name|block
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_ifdef
unit|))
ifdef|#
directive|ifdef
name|__ATTRIBUTE___FORMAT_OK
end_ifdef

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
comment|/* __ATTRIBUTE___FORMAT_OK */
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|finish_parse
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bpf_insn
modifier|*
name|icode_to_fcode
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lex_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lex_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sappend
parameter_list|(
name|struct
name|slist
modifier|*
parameter_list|,
name|struct
name|slist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|JT
parameter_list|(
name|b
parameter_list|)
value|((b)->et.succ)
end_define

begin_define
define|#
directive|define
name|JF
parameter_list|(
name|b
parameter_list|)
value|((b)->ef.succ)
end_define

begin_decl_stmt
specifier|extern
name|int
name|no_optimize
decl_stmt|;
end_decl_stmt

end_unit

