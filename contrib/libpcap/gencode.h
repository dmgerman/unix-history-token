begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  * @(#) $Header: /tcpdump/master/libpcap/gencode.h,v 1.47 2000/11/04 10:09:55 guy Exp $ (LBL)  */
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
name|Q_TCP
value|5
end_define

begin_define
define|#
directive|define
name|Q_UDP
value|6
end_define

begin_define
define|#
directive|define
name|Q_ICMP
value|7
end_define

begin_define
define|#
directive|define
name|Q_IGMP
value|8
end_define

begin_define
define|#
directive|define
name|Q_IGRP
value|9
end_define

begin_define
define|#
directive|define
name|Q_ATALK
value|10
end_define

begin_define
define|#
directive|define
name|Q_DECNET
value|11
end_define

begin_define
define|#
directive|define
name|Q_LAT
value|12
end_define

begin_define
define|#
directive|define
name|Q_SCA
value|13
end_define

begin_define
define|#
directive|define
name|Q_MOPRC
value|14
end_define

begin_define
define|#
directive|define
name|Q_MOPDL
value|15
end_define

begin_define
define|#
directive|define
name|Q_IPV6
value|16
end_define

begin_define
define|#
directive|define
name|Q_ICMPV6
value|17
end_define

begin_define
define|#
directive|define
name|Q_AH
value|18
end_define

begin_define
define|#
directive|define
name|Q_ESP
value|19
end_define

begin_define
define|#
directive|define
name|Q_PIM
value|20
end_define

begin_define
define|#
directive|define
name|Q_AARP
value|21
end_define

begin_define
define|#
directive|define
name|Q_ISO
value|22
end_define

begin_define
define|#
directive|define
name|Q_ESIS
value|23
end_define

begin_define
define|#
directive|define
name|Q_ISIS
value|24
end_define

begin_define
define|#
directive|define
name|Q_CLNP
value|25
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
name|Q_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|Q_UNDEF
value|255
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
comment|/*   * A bit vector to represent definition sets.  We assume TOT_REGISTERS  * is smaller than 8*sizeof(atomset).  */
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
name|int
name|longjt
decl_stmt|;
comment|/* jt branch requires long jump */
name|int
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
name|gen_vlan
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
if|#
directive|if
name|HAVE___ATTRIBUTE__
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
operator|,
function_decl|format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|int
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

