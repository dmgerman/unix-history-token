begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1988, 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mbuf.h	8.5 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MBUF_H_
end_define

begin_comment
comment|/* XXX: These includes suck. Sorry! */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/sdt.h>
end_include

begin_define
define|#
directive|define
name|MBUF_PROBE1
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|)
define|\
value|SDT_PROBE1(sdt, , , probe, arg0)
end_define

begin_define
define|#
directive|define
name|MBUF_PROBE2
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|SDT_PROBE2(sdt, , , probe, arg0, arg1)
end_define

begin_define
define|#
directive|define
name|MBUF_PROBE3
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|SDT_PROBE3(sdt, , , probe, arg0, arg1, arg2)
end_define

begin_define
define|#
directive|define
name|MBUF_PROBE4
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|SDT_PROBE4(sdt, , , probe, arg0, arg1, arg2, arg3)
end_define

begin_define
define|#
directive|define
name|MBUF_PROBE5
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|SDT_PROBE5(sdt, , , probe, arg0, arg1, arg2, arg3, arg4)
end_define

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__gethdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__get
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__getcl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__clget
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__cljget
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__cljset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__free
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sdt
argument_list|, , ,
name|m__freem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Mbufs are of a single size, MSIZE (sys/param.h), which includes overhead.  * An mbuf may add a single "mbuf cluster" of size MCLBYTES (also in  * sys/param.h), which has no additional overhead and is used instead of the  * internal data area; this is done when at least MINCLSIZE of data must be  * stored.  Additionally, it is possible to allocate a separate buffer  * externally and attach it to the mbuf in a way similar to that of mbuf  * clusters.  *  * NB: These calculation do not take actual compiler-induced alignment and  * padding inside the complete struct mbuf into account.  Appropriate  * attention is required when changing members of struct mbuf.  *  * MLEN is data length in a normal mbuf.  * MHLEN is data length in an mbuf with pktheader.  * MINCLSIZE is a smallest amount of data that should be put into cluster.  *  * Compile-time assertions in uipc_mbuf.c test these values to ensure that  * they are sensible.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|MHSIZE
value|offsetof(struct mbuf, m_dat)
end_define

begin_define
define|#
directive|define
name|MPKTHSIZE
value|offsetof(struct mbuf, m_pktdat)
end_define

begin_define
define|#
directive|define
name|MLEN
value|((int)(MSIZE - MHSIZE))
end_define

begin_define
define|#
directive|define
name|MHLEN
value|((int)(MSIZE - MPKTHSIZE))
end_define

begin_define
define|#
directive|define
name|MINCLSIZE
value|(MHLEN + 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*-  * Macro for type conversion: convert mbuf pointer to data pointer of correct  * type:  *  * mtod(m, t)	-- Convert mbuf pointer to data pointer of correct type.  * mtodo(m, o) -- Same as above but with offset 'o' into data.  */
end_comment

begin_define
define|#
directive|define
name|mtod
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|((t)((m)->m_data))
end_define

begin_define
define|#
directive|define
name|mtodo
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|)
value|((void *)(((m)->m_data) + (o)))
end_define

begin_comment
comment|/*  * Argument structure passed to UMA routines during mbuf and packet  * allocations.  */
end_comment

begin_struct
struct|struct
name|mb_args
block|{
name|int
name|flags
decl_stmt|;
comment|/* Flags for mbuf being allocated */
name|short
name|type
decl_stmt|;
comment|/* Type of mbuf being allocated */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Packet tag structure (see below for details).  */
end_comment

begin_struct
struct|struct
name|m_tag
block|{
name|SLIST_ENTRY
argument_list|(
argument|m_tag
argument_list|)
name|m_tag_link
expr_stmt|;
comment|/* List of packet tags */
name|u_int16_t
name|m_tag_id
decl_stmt|;
comment|/* Tag ID */
name|u_int16_t
name|m_tag_len
decl_stmt|;
comment|/* Length of data */
name|u_int32_t
name|m_tag_cookie
decl_stmt|;
comment|/* ABI/Module ID */
name|void
function_decl|(
modifier|*
name|m_tag_free
function_decl|)
parameter_list|(
name|struct
name|m_tag
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Record/packet header in first mbuf of chain; valid only if M_PKTHDR is set.  * Size ILP32: 48  *	 LP64: 56  * Compile-time assertions in uipc_mbuf.c test these values to ensure that  * they are correct.  */
end_comment

begin_struct
struct|struct
name|pkthdr
block|{
name|struct
name|ifnet
modifier|*
name|rcvif
decl_stmt|;
comment|/* rcv interface */
name|SLIST_HEAD
argument_list|(
argument|packet_tags
argument_list|,
argument|m_tag
argument_list|)
name|tags
expr_stmt|;
comment|/* list of packet tags */
name|int32_t
name|len
decl_stmt|;
comment|/* total packet length */
comment|/* Layer crossing persistent information. */
name|uint32_t
name|flowid
decl_stmt|;
comment|/* packet's 4-tuple system */
name|uint64_t
name|csum_flags
decl_stmt|;
comment|/* checksum and offload features */
name|uint16_t
name|fibnum
decl_stmt|;
comment|/* this packet should use this fib */
name|uint8_t
name|cosqos
decl_stmt|;
comment|/* class/quality of service */
name|uint8_t
name|rsstype
decl_stmt|;
comment|/* hash type */
name|uint8_t
name|l2hlen
decl_stmt|;
comment|/* layer 2 header length */
name|uint8_t
name|l3hlen
decl_stmt|;
comment|/* layer 3 header length */
name|uint8_t
name|l4hlen
decl_stmt|;
comment|/* layer 4 header length */
name|uint8_t
name|l5hlen
decl_stmt|;
comment|/* layer 5 header length */
union|union
block|{
name|uint8_t
name|eight
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|sixteen
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|thirtytwo
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|sixtyfour
index|[
literal|1
index|]
decl_stmt|;
name|uintptr_t
name|unintptr
index|[
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
name|PH_per
union|;
comment|/* Layer specific non-persistent local storage for reassembly, etc. */
union|union
block|{
name|uint8_t
name|eight
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|sixteen
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|thirtytwo
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|sixtyfour
index|[
literal|1
index|]
decl_stmt|;
name|uintptr_t
name|unintptr
index|[
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
name|PH_loc
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ether_vtag
value|PH_per.sixteen[0]
end_define

begin_define
define|#
directive|define
name|PH_vt
value|PH_per
end_define

begin_define
define|#
directive|define
name|vt_nrecs
value|sixteen[0]
end_define

begin_define
define|#
directive|define
name|tso_segsz
value|PH_per.sixteen[1]
end_define

begin_define
define|#
directive|define
name|csum_phsum
value|PH_per.sixteen[2]
end_define

begin_define
define|#
directive|define
name|csum_data
value|PH_per.thirtytwo[1]
end_define

begin_comment
comment|/*  * Description of external storage mapped into mbuf; valid only if M_EXT is  * set.  * Size ILP32: 28  *	 LP64: 48  * Compile-time assertions in uipc_mbuf.c test these values to ensure that  * they are correct.  */
end_comment

begin_struct
struct|struct
name|m_ext
block|{
union|union
block|{
specifier|volatile
name|u_int
name|ext_count
decl_stmt|;
comment|/* value of ref count info */
specifier|volatile
name|u_int
modifier|*
name|ext_cnt
decl_stmt|;
comment|/* pointer to ref count info */
block|}
union|;
name|caddr_t
name|ext_buf
decl_stmt|;
comment|/* start of buffer */
name|uint32_t
name|ext_size
decl_stmt|;
comment|/* size of buffer, for ext_free */
name|uint32_t
name|ext_type
range|:
literal|8
decl_stmt|,
comment|/* type of external storage */
name|ext_flags
range|:
literal|24
decl_stmt|;
comment|/* external storage mbuf flags */
name|void
function_decl|(
modifier|*
name|ext_free
function_decl|)
comment|/* free routine if not the usual */
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ext_arg1
decl_stmt|;
comment|/* optional argument pointer */
name|void
modifier|*
name|ext_arg2
decl_stmt|;
comment|/* optional argument pointer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The core of the mbuf object along with some shortcut defines for practical  * purposes.  */
end_comment

begin_struct
struct|struct
name|mbuf
block|{
comment|/* 	 * Header present at the beginning of every mbuf. 	 * Size ILP32: 24 	 *      LP64: 32 	 * Compile-time assertions in uipc_mbuf.c test these values to ensure 	 * that they are correct. 	 */
union|union
block|{
comment|/* next buffer in chain */
name|struct
name|mbuf
modifier|*
name|m_next
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|mbuf
argument_list|)
name|m_slist
expr_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|mbuf
argument_list|)
name|m_stailq
expr_stmt|;
block|}
union|;
union|union
block|{
comment|/* next chain in queue/record */
name|struct
name|mbuf
modifier|*
name|m_nextpkt
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|mbuf
argument_list|)
name|m_slistpkt
expr_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|mbuf
argument_list|)
name|m_stailqpkt
expr_stmt|;
block|}
union|;
name|caddr_t
name|m_data
decl_stmt|;
comment|/* location of data */
name|int32_t
name|m_len
decl_stmt|;
comment|/* amount of data in this mbuf */
name|uint32_t
name|m_type
range|:
literal|8
decl_stmt|,
comment|/* type of data in this mbuf */
name|m_flags
range|:
literal|24
decl_stmt|;
comment|/* flags; see below */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
name|uint32_t
name|m_pad
decl_stmt|;
comment|/* pad for 64bit alignment */
endif|#
directive|endif
comment|/* 	 * A set of optional headers (packet header, external storage header) 	 * and internal data storage.  Historically, these arrays were sized 	 * to MHLEN (space left after a packet header) and MLEN (space left 	 * after only a regular mbuf header); they are now variable size in 	 * order to support future work on variable-size mbufs. 	 */
union|union
block|{
struct|struct
block|{
name|struct
name|pkthdr
name|m_pkthdr
decl_stmt|;
comment|/* M_PKTHDR set */
union|union
block|{
name|struct
name|m_ext
name|m_ext
decl_stmt|;
comment|/* M_EXT set */
name|char
name|m_pktdat
index|[
literal|0
index|]
decl_stmt|;
block|}
union|;
block|}
struct|;
name|char
name|m_dat
index|[
literal|0
index|]
decl_stmt|;
comment|/* !M_PKTHDR, !M_EXT */
block|}
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * mbuf flags of global significance and layer crossing.  * Those of only protocol/layer specific significance are to be mapped  * to M_PROTO[1-12] and cleared at layer handoff boundaries.  * NB: Limited to the lower 24 bits.  */
end_comment

begin_define
define|#
directive|define
name|M_EXT
value|0x00000001
end_define

begin_comment
comment|/* has associated external storage */
end_comment

begin_define
define|#
directive|define
name|M_PKTHDR
value|0x00000002
end_define

begin_comment
comment|/* start of record */
end_comment

begin_define
define|#
directive|define
name|M_EOR
value|0x00000004
end_define

begin_comment
comment|/* end of record */
end_comment

begin_define
define|#
directive|define
name|M_RDONLY
value|0x00000008
end_define

begin_comment
comment|/* associated data is marked read-only */
end_comment

begin_define
define|#
directive|define
name|M_BCAST
value|0x00000010
end_define

begin_comment
comment|/* send/received as link-level broadcast */
end_comment

begin_define
define|#
directive|define
name|M_MCAST
value|0x00000020
end_define

begin_comment
comment|/* send/received as link-level multicast */
end_comment

begin_define
define|#
directive|define
name|M_PROMISC
value|0x00000040
end_define

begin_comment
comment|/* packet was not for us */
end_comment

begin_define
define|#
directive|define
name|M_VLANTAG
value|0x00000080
end_define

begin_comment
comment|/* ether_vtag is valid */
end_comment

begin_define
define|#
directive|define
name|M_UNUSED_8
value|0x00000100
end_define

begin_comment
comment|/* --available-- */
end_comment

begin_define
define|#
directive|define
name|M_NOFREE
value|0x00000200
end_define

begin_comment
comment|/* do not free mbuf, embedded in cluster */
end_comment

begin_define
define|#
directive|define
name|M_PROTO1
value|0x00001000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO2
value|0x00002000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO3
value|0x00004000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO4
value|0x00008000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO5
value|0x00010000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO6
value|0x00020000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO7
value|0x00040000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO8
value|0x00080000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO9
value|0x00100000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO10
value|0x00200000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO11
value|0x00400000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO12
value|0x00800000
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|MB_DTOR_SKIP
value|0x1
end_define

begin_comment
comment|/* don't pollute the cache by touching a freed mbuf */
end_comment

begin_comment
comment|/*  * Flags to purge when crossing layers.  */
end_comment

begin_define
define|#
directive|define
name|M_PROTOFLAGS
define|\
value|(M_PROTO1|M_PROTO2|M_PROTO3|M_PROTO4|M_PROTO5|M_PROTO6|M_PROTO7|M_PROTO8|\      M_PROTO9|M_PROTO10|M_PROTO11|M_PROTO12)
end_define

begin_comment
comment|/*  * Flags preserved when copying m_pkthdr.  */
end_comment

begin_define
define|#
directive|define
name|M_COPYFLAGS
define|\
value|(M_PKTHDR|M_EOR|M_RDONLY|M_BCAST|M_MCAST|M_PROMISC|M_VLANTAG| \      M_PROTOFLAGS)
end_define

begin_comment
comment|/*  * Mbuf flag description for use with printf(9) %b identifier.  */
end_comment

begin_define
define|#
directive|define
name|M_FLAG_BITS
define|\
value|"\20\1M_EXT\2M_PKTHDR\3M_EOR\4M_RDONLY\5M_BCAST\6M_MCAST" \     "\7M_PROMISC\10M_VLANTAG"
end_define

begin_define
define|#
directive|define
name|M_FLAG_PROTOBITS
define|\
value|"\15M_PROTO1\16M_PROTO2\17M_PROTO3\20M_PROTO4\21M_PROTO5" \     "\22M_PROTO6\23M_PROTO7\24M_PROTO8\25M_PROTO9\26M_PROTO10" \     "\27M_PROTO11\30M_PROTO12"
end_define

begin_define
define|#
directive|define
name|M_FLAG_PRINTF
value|(M_FLAG_BITS M_FLAG_PROTOBITS)
end_define

begin_comment
comment|/*  * Network interface cards are able to hash protocol fields (such as IPv4  * addresses and TCP port numbers) classify packets into flows.  These flows  * can then be used to maintain ordering while delivering packets to the OS  * via parallel input queues, as well as to provide a stateless affinity  * model.  NIC drivers can pass up the hash via m->m_pkthdr.flowid, and set  * m_flag fields to indicate how the hash should be interpreted by the  * network stack.  *  * Most NICs support RSS, which provides ordering and explicit affinity, and  * use the hash m_flag bits to indicate what header fields were covered by  * the hash.  M_HASHTYPE_OPAQUE and M_HASHTYPE_OPAQUE_HASH can be set by non-  * RSS cards or configurations that provide an opaque flow identifier, allowing  * for ordering and distribution without explicit affinity.  Additionally,  * M_HASHTYPE_OPAQUE_HASH indicates that the flow identifier has hash  * properties.  */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_HASHPROP
value|0x80
end_define

begin_comment
comment|/* has hash properties */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_HASH
parameter_list|(
name|t
parameter_list|)
value|(M_HASHTYPE_HASHPROP | (t))
end_define

begin_comment
comment|/* Microsoft RSS standard hash types */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_IPV4
value|M_HASHTYPE_HASH(1)
end_define

begin_comment
comment|/* IPv4 2-tuple */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_TCP_IPV4
value|M_HASHTYPE_HASH(2)
end_define

begin_comment
comment|/* TCPv4 4-tuple */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_IPV6
value|M_HASHTYPE_HASH(3)
end_define

begin_comment
comment|/* IPv6 2-tuple */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_TCP_IPV6
value|M_HASHTYPE_HASH(4)
end_define

begin_comment
comment|/* TCPv6 4-tuple */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_IPV6_EX
value|M_HASHTYPE_HASH(5)
end_define

begin_comment
comment|/* IPv6 2-tuple + 							    * ext hdrs */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_TCP_IPV6_EX
value|M_HASHTYPE_HASH(6)
end_define

begin_comment
comment|/* TCPv6 4-tuple + 							    * ext hdrs */
end_comment

begin_comment
comment|/* Non-standard RSS hash types */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_UDP_IPV4
value|M_HASHTYPE_HASH(7)
end_define

begin_comment
comment|/* IPv4 UDP 4-tuple*/
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_UDP_IPV4_EX
value|M_HASHTYPE_HASH(8)
end_define

begin_comment
comment|/* IPv4 UDP 4-tuple + 							    * ext hdrs */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_UDP_IPV6
value|M_HASHTYPE_HASH(9)
end_define

begin_comment
comment|/* IPv6 UDP 4-tuple*/
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_RSS_UDP_IPV6_EX
value|M_HASHTYPE_HASH(10)
end_define

begin_comment
comment|/* IPv6 UDP 4-tuple + 							    * ext hdrs */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_OPAQUE
value|63
end_define

begin_comment
comment|/* ordering, not affinity */
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_OPAQUE_HASH
value|M_HASHTYPE_HASH(M_HASHTYPE_OPAQUE)
end_define

begin_comment
comment|/* ordering+hash, not affinity*/
end_comment

begin_define
define|#
directive|define
name|M_HASHTYPE_CLEAR
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.rsstype = 0)
end_define

begin_define
define|#
directive|define
name|M_HASHTYPE_GET
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.rsstype)
end_define

begin_define
define|#
directive|define
name|M_HASHTYPE_SET
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|)
value|((m)->m_pkthdr.rsstype = (v))
end_define

begin_define
define|#
directive|define
name|M_HASHTYPE_TEST
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|)
value|(M_HASHTYPE_GET(m) == (v))
end_define

begin_define
define|#
directive|define
name|M_HASHTYPE_ISHASH
parameter_list|(
name|m
parameter_list|)
value|(M_HASHTYPE_GET(m)& M_HASHTYPE_HASHPROP)
end_define

begin_comment
comment|/*  * COS/QOS class and quality of service tags.  * It uses DSCP code points as base.  */
end_comment

begin_define
define|#
directive|define
name|QOS_DSCP_CS0
value|0x00
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_DEF
value|QOS_DSCP_CS0
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS1
value|0x20
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF11
value|0x28
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF12
value|0x30
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF13
value|0x38
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS2
value|0x40
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF21
value|0x48
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF22
value|0x50
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF23
value|0x58
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS3
value|0x60
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF31
value|0x68
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF32
value|0x70
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF33
value|0x78
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS4
value|0x80
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF41
value|0x88
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF42
value|0x90
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_AF43
value|0x98
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS5
value|0xa0
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_EF
value|0xb8
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS6
value|0xc0
end_define

begin_define
define|#
directive|define
name|QOS_DSCP_CS7
value|0xe0
end_define

begin_comment
comment|/*  * External mbuf storage buffer types.  */
end_comment

begin_define
define|#
directive|define
name|EXT_CLUSTER
value|1
end_define

begin_comment
comment|/* mbuf cluster */
end_comment

begin_define
define|#
directive|define
name|EXT_SFBUF
value|2
end_define

begin_comment
comment|/* sendfile(2)'s sf_buf */
end_comment

begin_define
define|#
directive|define
name|EXT_JUMBOP
value|3
end_define

begin_comment
comment|/* jumbo cluster page sized */
end_comment

begin_define
define|#
directive|define
name|EXT_JUMBO9
value|4
end_define

begin_comment
comment|/* jumbo cluster 9216 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_JUMBO16
value|5
end_define

begin_comment
comment|/* jumbo cluster 16184 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_PACKET
value|6
end_define

begin_comment
comment|/* mbuf+cluster from packet zone */
end_comment

begin_define
define|#
directive|define
name|EXT_MBUF
value|7
end_define

begin_comment
comment|/* external mbuf reference (M_IOVEC) */
end_comment

begin_define
define|#
directive|define
name|EXT_SFBUF_NOCACHE
value|8
end_define

begin_comment
comment|/* sendfile(2)'s sf_buf not to be cached */
end_comment

begin_define
define|#
directive|define
name|EXT_VENDOR1
value|224
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_VENDOR2
value|225
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_VENDOR3
value|226
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_VENDOR4
value|227
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_EXP1
value|244
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_EXP2
value|245
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_EXP3
value|246
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_EXP4
value|247
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_NET_DRV
value|252
end_define

begin_comment
comment|/* custom ext_buf provided by net driver(s) */
end_comment

begin_define
define|#
directive|define
name|EXT_MOD_TYPE
value|253
end_define

begin_comment
comment|/* custom module's ext_buf type */
end_comment

begin_define
define|#
directive|define
name|EXT_DISPOSABLE
value|254
end_define

begin_comment
comment|/* can throw this buffer away w/page flipping */
end_comment

begin_define
define|#
directive|define
name|EXT_EXTREF
value|255
end_define

begin_comment
comment|/* has externally maintained ext_cnt ptr */
end_comment

begin_comment
comment|/*  * Flags for external mbuf buffer types.  * NB: limited to the lower 24 bits.  */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_EMBREF
value|0x000001
end_define

begin_comment
comment|/* embedded ext_count */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_EXTREF
value|0x000002
end_define

begin_comment
comment|/* external ext_cnt, notyet */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_NOFREE
value|0x000010
end_define

begin_comment
comment|/* don't free mbuf to pool, notyet */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_VENDOR1
value|0x010000
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_VENDOR2
value|0x020000
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_VENDOR3
value|0x040000
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_VENDOR4
value|0x080000
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_EXP1
value|0x100000
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_EXP2
value|0x200000
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_EXP3
value|0x400000
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_EXP4
value|0x800000
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_comment
comment|/*  * EXT flag description for use with printf(9) %b identifier.  */
end_comment

begin_define
define|#
directive|define
name|EXT_FLAG_BITS
define|\
value|"\20\1EXT_FLAG_EMBREF\2EXT_FLAG_EXTREF\5EXT_FLAG_NOFREE" \     "\21EXT_FLAG_VENDOR1\22EXT_FLAG_VENDOR2\23EXT_FLAG_VENDOR3" \     "\24EXT_FLAG_VENDOR4\25EXT_FLAG_EXP1\26EXT_FLAG_EXP2\27EXT_FLAG_EXP3" \     "\30EXT_FLAG_EXP4"
end_define

begin_comment
comment|/*  * External reference/free functions.  */
end_comment

begin_function_decl
name|void
name|sf_ext_free
parameter_list|(
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
name|sf_ext_free_nocache
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flags indicating checksum, segmentation and other offload work to be  * done, or already done, by hardware or lower layers.  It is split into  * separate inbound and outbound flags.  *  * Outbound flags that are set by upper protocol layers requesting lower  * layers, or ideally the hardware, to perform these offloading tasks.  * For outbound packets this field and its flags can be directly tested  * against ifnet if_hwassist.  */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP
value|0x00000001
end_define

begin_comment
comment|/* IP header checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_UDP
value|0x00000002
end_define

begin_comment
comment|/* UDP checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_TCP
value|0x00000004
end_define

begin_comment
comment|/* TCP checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_SCTP
value|0x00000008
end_define

begin_comment
comment|/* SCTP checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_TSO
value|0x00000010
end_define

begin_comment
comment|/* TCP segmentation offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_ISCSI
value|0x00000020
end_define

begin_comment
comment|/* iSCSI checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP6_UDP
value|0x00000200
end_define

begin_comment
comment|/* UDP checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP6_TCP
value|0x00000400
end_define

begin_comment
comment|/* TCP checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP6_SCTP
value|0x00000800
end_define

begin_comment
comment|/* SCTP checksum offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP6_TSO
value|0x00001000
end_define

begin_comment
comment|/* TCP segmentation offload */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP6_ISCSI
value|0x00002000
end_define

begin_comment
comment|/* iSCSI checksum offload */
end_comment

begin_comment
comment|/* Inbound checksum support where the checksum was verified by hardware. */
end_comment

begin_define
define|#
directive|define
name|CSUM_L3_CALC
value|0x01000000
end_define

begin_comment
comment|/* calculated layer 3 csum */
end_comment

begin_define
define|#
directive|define
name|CSUM_L3_VALID
value|0x02000000
end_define

begin_comment
comment|/* checksum is correct */
end_comment

begin_define
define|#
directive|define
name|CSUM_L4_CALC
value|0x04000000
end_define

begin_comment
comment|/* calculated layer 4 csum */
end_comment

begin_define
define|#
directive|define
name|CSUM_L4_VALID
value|0x08000000
end_define

begin_comment
comment|/* checksum is correct */
end_comment

begin_define
define|#
directive|define
name|CSUM_L5_CALC
value|0x10000000
end_define

begin_comment
comment|/* calculated layer 5 csum */
end_comment

begin_define
define|#
directive|define
name|CSUM_L5_VALID
value|0x20000000
end_define

begin_comment
comment|/* checksum is correct */
end_comment

begin_define
define|#
directive|define
name|CSUM_COALESED
value|0x40000000
end_define

begin_comment
comment|/* contains merged segments */
end_comment

begin_comment
comment|/*  * CSUM flag description for use with printf(9) %b identifier.  */
end_comment

begin_define
define|#
directive|define
name|CSUM_BITS
define|\
value|"\20\1CSUM_IP\2CSUM_IP_UDP\3CSUM_IP_TCP\4CSUM_IP_SCTP\5CSUM_IP_TSO" \     "\6CSUM_IP_ISCSI" \     "\12CSUM_IP6_UDP\13CSUM_IP6_TCP\14CSUM_IP6_SCTP\15CSUM_IP6_TSO" \     "\16CSUM_IP6_ISCSI" \     "\31CSUM_L3_CALC\32CSUM_L3_VALID\33CSUM_L4_CALC\34CSUM_L4_VALID" \     "\35CSUM_L5_CALC\36CSUM_L5_VALID\37CSUM_COALESED"
end_define

begin_comment
comment|/* CSUM flags compatibility mappings. */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_CHECKED
value|CSUM_L3_CALC
end_define

begin_define
define|#
directive|define
name|CSUM_IP_VALID
value|CSUM_L3_VALID
end_define

begin_define
define|#
directive|define
name|CSUM_DATA_VALID
value|CSUM_L4_VALID
end_define

begin_define
define|#
directive|define
name|CSUM_PSEUDO_HDR
value|CSUM_L4_CALC
end_define

begin_define
define|#
directive|define
name|CSUM_SCTP_VALID
value|CSUM_L4_VALID
end_define

begin_define
define|#
directive|define
name|CSUM_DELAY_DATA
value|(CSUM_TCP|CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|CSUM_DELAY_IP
value|CSUM_IP
end_define

begin_comment
comment|/* Only v4, no v6 IP hdr csum */
end_comment

begin_define
define|#
directive|define
name|CSUM_DELAY_DATA_IPV6
value|(CSUM_TCP_IPV6|CSUM_UDP_IPV6)
end_define

begin_define
define|#
directive|define
name|CSUM_DATA_VALID_IPV6
value|CSUM_DATA_VALID
end_define

begin_define
define|#
directive|define
name|CSUM_TCP
value|CSUM_IP_TCP
end_define

begin_define
define|#
directive|define
name|CSUM_UDP
value|CSUM_IP_UDP
end_define

begin_define
define|#
directive|define
name|CSUM_SCTP
value|CSUM_IP_SCTP
end_define

begin_define
define|#
directive|define
name|CSUM_TSO
value|(CSUM_IP_TSO|CSUM_IP6_TSO)
end_define

begin_define
define|#
directive|define
name|CSUM_UDP_IPV6
value|CSUM_IP6_UDP
end_define

begin_define
define|#
directive|define
name|CSUM_TCP_IPV6
value|CSUM_IP6_TCP
end_define

begin_define
define|#
directive|define
name|CSUM_SCTP_IPV6
value|CSUM_IP6_SCTP
end_define

begin_comment
comment|/*  * mbuf types describing the content of the mbuf (including external storage).  */
end_comment

begin_define
define|#
directive|define
name|MT_NOTMBUF
value|0
end_define

begin_comment
comment|/* USED INTERNALLY ONLY! Object is not mbuf */
end_comment

begin_define
define|#
directive|define
name|MT_DATA
value|1
end_define

begin_comment
comment|/* dynamic (data) allocation */
end_comment

begin_define
define|#
directive|define
name|MT_HEADER
value|MT_DATA
end_define

begin_comment
comment|/* packet header, use M_PKTHDR instead */
end_comment

begin_define
define|#
directive|define
name|MT_VENDOR1
value|4
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|MT_VENDOR2
value|5
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|MT_VENDOR3
value|6
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|MT_VENDOR4
value|7
end_define

begin_comment
comment|/* for vendor-internal use */
end_comment

begin_define
define|#
directive|define
name|MT_SONAME
value|8
end_define

begin_comment
comment|/* socket name */
end_comment

begin_define
define|#
directive|define
name|MT_EXP1
value|9
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|MT_EXP2
value|10
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|MT_EXP3
value|11
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|MT_EXP4
value|12
end_define

begin_comment
comment|/* for experimental use */
end_comment

begin_define
define|#
directive|define
name|MT_CONTROL
value|14
end_define

begin_comment
comment|/* extra-data protocol message */
end_comment

begin_define
define|#
directive|define
name|MT_OOBDATA
value|15
end_define

begin_comment
comment|/* expedited data  */
end_comment

begin_define
define|#
directive|define
name|MT_NTYPES
value|16
end_define

begin_comment
comment|/* number of mbuf types for mbtypes[] */
end_comment

begin_define
define|#
directive|define
name|MT_NOINIT
value|255
end_define

begin_comment
comment|/* Not a type but a flag to allocate 				   a non-initialized mbuf */
end_comment

begin_comment
comment|/*  * String names of mbuf-related UMA(9) and malloc(9) types.  Exposed to  * !_KERNEL so that monitoring tools can look up the zones with  * libmemstat(3).  */
end_comment

begin_define
define|#
directive|define
name|MBUF_MEM_NAME
value|"mbuf"
end_define

begin_define
define|#
directive|define
name|MBUF_CLUSTER_MEM_NAME
value|"mbuf_cluster"
end_define

begin_define
define|#
directive|define
name|MBUF_PACKET_MEM_NAME
value|"mbuf_packet"
end_define

begin_define
define|#
directive|define
name|MBUF_JUMBOP_MEM_NAME
value|"mbuf_jumbo_page"
end_define

begin_define
define|#
directive|define
name|MBUF_JUMBO9_MEM_NAME
value|"mbuf_jumbo_9k"
end_define

begin_define
define|#
directive|define
name|MBUF_JUMBO16_MEM_NAME
value|"mbuf_jumbo_16k"
end_define

begin_define
define|#
directive|define
name|MBUF_TAG_MEM_NAME
value|"mbuf_tag"
end_define

begin_define
define|#
directive|define
name|MBUF_EXTREFCNT_MEM_NAME
value|"mbuf_ext_refcnt"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

begin_define
define|#
directive|define
name|MBUF_CHECKSLEEP
parameter_list|(
name|how
parameter_list|)
value|do {					\ 	if (how == M_WAITOK)						\ 		WITNESS_WARN(WARN_GIANTOK | WARN_SLEEPOK, NULL,		\ 		    "Sleeping in \"%s\"", __func__);			\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MBUF_CHECKSLEEP
parameter_list|(
name|how
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Network buffer allocation API  *  * The rest of it is defined in kern/kern_mbuf.c  */
end_comment

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_mbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_clust
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_pack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_jumbop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_jumbo9
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_jumbo16
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mb_dupcl
parameter_list|(
name|struct
name|mbuf
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
name|mb_free_ext
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_adj
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_apply
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_append
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|c_caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_cat
parameter_list|(
name|struct
name|mbuf
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
name|m_catpkt
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_clget
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|m_cljget
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|how
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_collapse
parameter_list|(
name|struct
name|mbuf
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
name|m_copyback
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|c_caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_copydata
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_copym
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
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
name|mbuf
modifier|*
name|m_copypacket
parameter_list|(
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
name|m_copy_pkthdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_copyup
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_defrag
parameter_list|(
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
name|m_demote_pkthdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_demote
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_devget
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|u_int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_dup
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_dup_pkthdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
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
name|m_extadd
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|m_fixhdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_fragment
parameter_list|(
name|struct
name|mbuf
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
name|m_freem
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_get2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_getjcl
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_getm2
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_getptr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|m_length
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_mbuftouio
parameter_list|(
name|struct
name|uio
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
name|m_move_pkthdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_pkthdr_init
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_prepend
parameter_list|(
name|struct
name|mbuf
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
name|m_print
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_pulldown
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_pullup
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_sanity
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_split
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_uiotombuf
parameter_list|(
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|,
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
name|mbuf
modifier|*
name|m_unshare
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|m_gettype
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|int
name|type
decl_stmt|;
switch|switch
condition|(
name|size
condition|)
block|{
case|case
name|MSIZE
case|:
name|type
operator|=
name|EXT_MBUF
expr_stmt|;
break|break;
case|case
name|MCLBYTES
case|:
name|type
operator|=
name|EXT_CLUSTER
expr_stmt|;
break|break;
if|#
directive|if
name|MJUMPAGESIZE
operator|!=
name|MCLBYTES
case|case
name|MJUMPAGESIZE
case|:
name|type
operator|=
name|EXT_JUMBOP
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|MJUM9BYTES
case|:
name|type
operator|=
name|EXT_JUMBO9
expr_stmt|;
break|break;
case|case
name|MJUM16BYTES
case|:
name|type
operator|=
name|EXT_JUMBO16
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"%s: invalid cluster size %d"
argument_list|,
name|__func__
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|type
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Associated an external reference counted buffer with an mbuf.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_extaddref
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|u_int
name|size
parameter_list|,
name|u_int
modifier|*
name|ref_cnt
parameter_list|,
name|void
function_decl|(
modifier|*
name|freef
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|ref_cnt
operator|!=
name|NULL
argument_list|,
operator|(
literal|"%s: ref_cnt not provided"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
name|atomic_add_int
argument_list|(
name|ref_cnt
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_flags
operator||=
name|M_EXT
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_buf
operator|=
name|buf
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_cnt
operator|=
name|ref_cnt
expr_stmt|;
name|m
operator|->
name|m_data
operator|=
name|m
operator|->
name|m_ext
operator|.
name|ext_buf
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_size
operator|=
name|size
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_free
operator|=
name|freef
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_arg1
operator|=
name|arg1
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_arg2
operator|=
name|arg2
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_type
operator|=
name|EXT_EXTREF
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_flags
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uma_zone_t
name|m_getzone
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|uma_zone_t
name|zone
decl_stmt|;
switch|switch
condition|(
name|size
condition|)
block|{
case|case
name|MCLBYTES
case|:
name|zone
operator|=
name|zone_clust
expr_stmt|;
break|break;
if|#
directive|if
name|MJUMPAGESIZE
operator|!=
name|MCLBYTES
case|case
name|MJUMPAGESIZE
case|:
name|zone
operator|=
name|zone_jumbop
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|MJUM9BYTES
case|:
name|zone
operator|=
name|zone_jumbo9
expr_stmt|;
break|break;
case|case
name|MJUM16BYTES
case|:
name|zone
operator|=
name|zone_jumbo16
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"%s: invalid cluster size %d"
argument_list|,
name|__func__
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|zone
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize an mbuf with linear storage.  *  * Inline because the consumer text overhead will be roughly the same to  * initialize or call a function with this many parameters and M_PKTHDR  * should go away with constant propagation for !MGETHDR.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|m_init
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|how
parameter_list|,
name|short
name|type
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|m
operator|->
name|m_next
operator|=
name|NULL
expr_stmt|;
name|m
operator|->
name|m_nextpkt
operator|=
name|NULL
expr_stmt|;
name|m
operator|->
name|m_data
operator|=
name|m
operator|->
name|m_dat
expr_stmt|;
name|m
operator|->
name|m_len
operator|=
literal|0
expr_stmt|;
name|m
operator|->
name|m_flags
operator|=
name|flags
expr_stmt|;
name|m
operator|->
name|m_type
operator|=
name|type
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|M_PKTHDR
condition|)
name|error
operator|=
name|m_pkthdr_init
argument_list|(
name|m
argument_list|,
name|how
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
literal|0
expr_stmt|;
name|MBUF_PROBE5
argument_list|(
name|m__init
argument_list|,
name|m
argument_list|,
name|how
argument_list|,
name|type
argument_list|,
name|flags
argument_list|,
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_get
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|; 	struct
name|mb_args
name|args
block|;
name|args
operator|.
name|flags
operator|=
literal|0
block|;
name|args
operator|.
name|type
operator|=
name|type
block|;
name|m
operator|=
name|uma_zalloc_arg
argument_list|(
name|zone_mbuf
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
block|;
name|MBUF_PROBE3
argument_list|(
name|m__get
argument_list|,
name|how
argument_list|,
name|type
argument_list|,
name|m
argument_list|)
block|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_gethdr
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|; 	struct
name|mb_args
name|args
block|;
name|args
operator|.
name|flags
operator|=
name|M_PKTHDR
block|;
name|args
operator|.
name|type
operator|=
name|type
block|;
name|m
operator|=
name|uma_zalloc_arg
argument_list|(
name|zone_mbuf
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
block|;
name|MBUF_PROBE3
argument_list|(
name|m__gethdr
argument_list|,
name|how
argument_list|,
name|type
argument_list|,
name|m
argument_list|)
block|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getcl
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|,
argument|int flags
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|; 	struct
name|mb_args
name|args
block|;
name|args
operator|.
name|flags
operator|=
name|flags
block|;
name|args
operator|.
name|type
operator|=
name|type
block|;
name|m
operator|=
name|uma_zalloc_arg
argument_list|(
name|zone_pack
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
block|;
name|MBUF_PROBE4
argument_list|(
name|m__getcl
argument_list|,
name|how
argument_list|,
name|type
argument_list|,
name|flags
argument_list|,
name|m
argument_list|)
block|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * XXX: m_cljset() is a dangerous API.  One must attach only a new,  * unreferenced cluster to an mbuf(9).  It is not possible to assert  * that, so care can be taken only by users of the API.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_cljset
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|void
modifier|*
name|cl
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|int
name|size
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EXT_CLUSTER
case|:
name|size
operator|=
name|MCLBYTES
expr_stmt|;
break|break;
if|#
directive|if
name|MJUMPAGESIZE
operator|!=
name|MCLBYTES
case|case
name|EXT_JUMBOP
case|:
name|size
operator|=
name|MJUMPAGESIZE
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|EXT_JUMBO9
case|:
name|size
operator|=
name|MJUM9BYTES
expr_stmt|;
break|break;
case|case
name|EXT_JUMBO16
case|:
name|size
operator|=
name|MJUM16BYTES
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"%s: unknown cluster type %d"
argument_list|,
name|__func__
argument_list|,
name|type
argument_list|)
expr_stmt|;
break|break;
block|}
name|m
operator|->
name|m_data
operator|=
name|m
operator|->
name|m_ext
operator|.
name|ext_buf
operator|=
name|cl
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_free
operator|=
name|m
operator|->
name|m_ext
operator|.
name|ext_arg1
operator|=
name|m
operator|->
name|m_ext
operator|.
name|ext_arg2
operator|=
name|NULL
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_size
operator|=
name|size
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_type
operator|=
name|type
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_flags
operator|=
name|EXT_FLAG_EMBREF
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_count
operator|=
literal|1
expr_stmt|;
name|m
operator|->
name|m_flags
operator||=
name|M_EXT
expr_stmt|;
name|MBUF_PROBE3
argument_list|(
name|m__cljset
argument_list|,
name|m
argument_list|,
name|cl
argument_list|,
name|type
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|m_chtype
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|short
name|new_type
parameter_list|)
block|{
name|m
operator|->
name|m_type
operator|=
name|new_type
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|m_clrprotoflags
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
while|while
condition|(
name|m
condition|)
block|{
name|m
operator|->
name|m_flags
operator|&=
operator|~
name|M_PROTOFLAGS
expr_stmt|;
name|m
operator|=
name|m
operator|->
name|m_next
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_last
argument_list|(
argument|struct mbuf *m
argument_list|)
block|{
while|while
condition|(
name|m
operator|->
name|m_next
condition|)
name|m
operator|=
name|m
operator|->
name|m_next
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|m
operator|)
return|;
end_return

begin_function
unit|}  static
specifier|inline
name|u_int
name|m_extrefcnt
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|m
operator|->
name|m_flags
operator|&
name|M_EXT
argument_list|,
operator|(
literal|"%s: M_EXT missing"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|m
operator|->
name|m_ext
operator|.
name|ext_flags
operator|&
name|EXT_FLAG_EMBREF
operator|)
condition|?
name|m
operator|->
name|m_ext
operator|.
name|ext_count
else|:
operator|*
name|m
operator|->
name|m_ext
operator|.
name|ext_cnt
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * mbuf, cluster, and external object allocation macros (for compatibility  * purposes).  */
end_comment

begin_define
define|#
directive|define
name|M_MOVE_PKTHDR
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|)
value|m_move_pkthdr((to), (from))
end_define

begin_define
define|#
directive|define
name|MGET
parameter_list|(
name|m
parameter_list|,
name|how
parameter_list|,
name|type
parameter_list|)
value|((m) = m_get((how), (type)))
end_define

begin_define
define|#
directive|define
name|MGETHDR
parameter_list|(
name|m
parameter_list|,
name|how
parameter_list|,
name|type
parameter_list|)
value|((m) = m_gethdr((how), (type)))
end_define

begin_define
define|#
directive|define
name|MCLGET
parameter_list|(
name|m
parameter_list|,
name|how
parameter_list|)
value|m_clget((m), (how))
end_define

begin_define
define|#
directive|define
name|MEXTADD
parameter_list|(
name|m
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|,
name|free
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|flags
parameter_list|,
name|type
parameter_list|)
define|\
value|m_extadd((m), (caddr_t)(buf), (size), (free), (arg1), (arg2),	\     (flags), (type))
end_define

begin_define
define|#
directive|define
name|m_getm
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|,
name|how
parameter_list|,
name|type
parameter_list|)
define|\
value|m_getm2((m), (len), (how), (type), M_PKTHDR)
end_define

begin_comment
comment|/*  * Evaluate TRUE if it's safe to write to the mbuf m's data region (this can  * be both the local data payload, or an external buffer area, depending on  * whether M_EXT is set).  */
end_comment

begin_define
define|#
directive|define
name|M_WRITABLE
parameter_list|(
name|m
parameter_list|)
value|(!((m)->m_flags& M_RDONLY)&&			\ 			 (!(((m)->m_flags& M_EXT)) ||			\ 			 (m_extrefcnt(m) == 1)))
end_define

begin_comment
comment|/* Check if the supplied mbuf has a packet header, or else panic. */
end_comment

begin_define
define|#
directive|define
name|M_ASSERTPKTHDR
parameter_list|(
name|m
parameter_list|)
define|\
value|KASSERT((m) != NULL&& (m)->m_flags& M_PKTHDR,			\ 	    ("%s: no mbuf packet header!", __func__))
end_define

begin_comment
comment|/*  * Ensure that the supplied mbuf is a valid, non-free mbuf.  *  * XXX: Broken at the moment.  Need some UMA magic to make it work again.  */
end_comment

begin_define
define|#
directive|define
name|M_ASSERTVALID
parameter_list|(
name|m
parameter_list|)
define|\
value|KASSERT((((struct mbuf *)m)->m_flags& 0) == 0,			\ 	    ("%s: attempted use of a free mbuf!", __func__))
end_define

begin_comment
comment|/*  * Return the address of the start of the buffer associated with an mbuf,  * handling external storage, packet-header mbufs, and regular data mbufs.  */
end_comment

begin_define
define|#
directive|define
name|M_START
parameter_list|(
name|m
parameter_list|)
define|\
value|(((m)->m_flags& M_EXT) ? (m)->m_ext.ext_buf :			\ 	 ((m)->m_flags& M_PKTHDR) ?&(m)->m_pktdat[0] :		\&(m)->m_dat[0])
end_define

begin_comment
comment|/*  * Return the size of the buffer associated with an mbuf, handling external  * storage, packet-header mbufs, and regular data mbufs.  */
end_comment

begin_define
define|#
directive|define
name|M_SIZE
parameter_list|(
name|m
parameter_list|)
define|\
value|(((m)->m_flags& M_EXT) ? (m)->m_ext.ext_size :			\ 	 ((m)->m_flags& M_PKTHDR) ? MHLEN :				\ 	 MLEN)
end_define

begin_comment
comment|/*  * Set the m_data pointer of a newly allocated mbuf to place an object of the  * specified size at the end of the mbuf, longword aligned.  *  * NB: Historically, we had M_ALIGN(), MH_ALIGN(), and MEXT_ALIGN() as  * separate macros, each asserting that it was called at the proper moment.  * This required callers to themselves test the storage type and call the  * right one.  Rather than require callers to be aware of those layout  * decisions, we centralize here.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_align
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|len
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|INVARIANTS
specifier|const
name|char
modifier|*
name|msg
init|=
literal|"%s: not a virgin mbuf"
decl_stmt|;
endif|#
directive|endif
name|int
name|adjust
decl_stmt|;
name|KASSERT
argument_list|(
name|m
operator|->
name|m_data
operator|==
name|M_START
argument_list|(
name|m
argument_list|)
argument_list|,
operator|(
name|msg
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
name|adjust
operator|=
name|M_SIZE
argument_list|(
name|m
argument_list|)
operator|-
name|len
expr_stmt|;
name|m
operator|->
name|m_data
operator|+=
name|adjust
operator|&
operator|~
operator|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|M_ALIGN
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|m_align(m, len)
end_define

begin_define
define|#
directive|define
name|MH_ALIGN
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|m_align(m, len)
end_define

begin_define
define|#
directive|define
name|MEXT_ALIGN
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|m_align(m, len)
end_define

begin_comment
comment|/*  * Compute the amount of space available before the current start of data in  * an mbuf.  *  * The M_WRITABLE() is a temporary, conservative safety measure: the burden  * of checking writability of the mbuf data area rests solely with the caller.  *  * NB: In previous versions, M_LEADINGSPACE() would only check M_WRITABLE()  * for mbufs with external storage.  We now allow mbuf-embedded data to be  * read-only as well.  */
end_comment

begin_define
define|#
directive|define
name|M_LEADINGSPACE
parameter_list|(
name|m
parameter_list|)
define|\
value|(M_WRITABLE(m) ? ((m)->m_data - M_START(m)) : 0)
end_define

begin_comment
comment|/*  * Compute the amount of space available after the end of data in an mbuf.  *  * The M_WRITABLE() is a temporary, conservative safety measure: the burden  * of checking writability of the mbuf data area rests solely with the caller.  *  * NB: In previous versions, M_TRAILINGSPACE() would only check M_WRITABLE()  * for mbufs with external storage.  We now allow mbuf-embedded data to be  * read-only as well.  */
end_comment

begin_define
define|#
directive|define
name|M_TRAILINGSPACE
parameter_list|(
name|m
parameter_list|)
define|\
value|(M_WRITABLE(m) ?						\ 	    ((M_START(m) + M_SIZE(m)) - ((m)->m_data + (m)->m_len)) : 0)
end_define

begin_comment
comment|/*  * Arrange to prepend space of size plen to mbuf m.  If a new mbuf must be  * allocated, how specifies whether to wait.  If the allocation fails, the  * original mbuf chain is freed and m is set to NULL.  */
end_comment

begin_define
define|#
directive|define
name|M_PREPEND
parameter_list|(
name|m
parameter_list|,
name|plen
parameter_list|,
name|how
parameter_list|)
value|do {					\ 	struct mbuf **_mmp =&(m);					\ 	struct mbuf *_mm = *_mmp;					\ 	int _mplen = (plen);						\ 	int __mhow = (how);						\ 									\ 	MBUF_CHECKSLEEP(how);						\ 	if (M_LEADINGSPACE(_mm)>= _mplen) {				\ 		_mm->m_data -= _mplen;					\ 		_mm->m_len += _mplen;					\ 	} else								\ 		_mm = m_prepend(_mm, _mplen, __mhow);			\ 	if (_mm != NULL&& _mm->m_flags& M_PKTHDR)			\ 		_mm->m_pkthdr.len += _mplen;				\ 	*_mmp = _mm;							\ } while (0)
end_define

begin_comment
comment|/*  * Change mbuf to new type.  This is a relatively expensive operation and  * should be avoided.  */
end_comment

begin_define
define|#
directive|define
name|MCHTYPE
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|m_chtype((m), (t))
end_define

begin_comment
comment|/* Length to m_copy to copy all. */
end_comment

begin_define
define|#
directive|define
name|M_COPYALL
value|1000000000
end_define

begin_comment
comment|/* Compatibility with 4.3. */
end_comment

begin_define
define|#
directive|define
name|m_copy
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|)
value|m_copym((m), (o), (l), M_NOWAIT)
end_define

begin_decl_stmt
specifier|extern
name|int
name|max_datalen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MHLEN - max_hdr */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_hdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Largest link + protocol header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_linkhdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Largest link-level header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_protohdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Largest protocol header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nmbclusters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of clusters */
end_comment

begin_comment
comment|/*-  * Network packets may have annotations attached by affixing a list of  * "packet tags" to the pkthdr structure.  Packet tags are dynamically  * allocated semi-opaque data structures that have a fixed header  * (struct m_tag) that specifies the size of the memory block and a  *<cookie,type> pair that identifies it.  The cookie is a 32-bit unique  * unsigned value used to identify a module or ABI.  By convention this value  * is chosen as the date+time that the module is created, expressed as the  * number of seconds since the epoch (e.g., using date -u +'%s').  The type  * value is an ABI/module-specific value that identifies a particular  * annotation and is private to the module.  For compatibility with systems  * like OpenBSD that define packet tags w/o an ABI/module cookie, the value  * PACKET_ABI_COMPAT is used to implement m_tag_get and m_tag_find  * compatibility shim functions and several tag types are defined below.  * Users that do not require compatibility should use a private cookie value  * so that packet tag-related definitions can be maintained privately.  *  * Note that the packet tag returned by m_tag_alloc has the default memory  * alignment implemented by malloc.  To reference private data one can use a  * construct like:  *  *	struct m_tag *mtag = m_tag_alloc(...);  *	struct foo *p = (struct foo *)(mtag+1);  *  * if the alignment of struct m_tag is sufficient for referencing members of  * struct foo.  Otherwise it is necessary to embed struct m_tag within the  * private data structure to insure proper alignment; e.g.,  *  *	struct foo {  *		struct m_tag	tag;  *		...  *	};  *	struct foo *p = (struct foo *) m_tag_alloc(...);  *	struct m_tag *mtag =&p->tag;  */
end_comment

begin_comment
comment|/*  * Persistent tags stay with an mbuf until the mbuf is reclaimed.  Otherwise  * tags are expected to ``vanish'' when they pass through a network  * interface.  For most interfaces this happens normally as the tags are  * reclaimed when the mbuf is free'd.  However in some special cases  * reclaiming must be done manually.  An example is packets that pass through  * the loopback interface.  Also, one must be careful to do this when  * ``turning around'' packets (e.g., icmp_reflect).  *  * To mark a tag persistent bit-or this flag in when defining the tag id.  * The tag will then be treated as described above.  */
end_comment

begin_define
define|#
directive|define
name|MTAG_PERSISTENT
value|0x800
end_define

begin_define
define|#
directive|define
name|PACKET_TAG_NONE
value|0
end_define

begin_comment
comment|/* Nadda */
end_comment

begin_comment
comment|/* Packet tags for use with PACKET_ABI_COMPAT. */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_IN_DONE
value|1
end_define

begin_comment
comment|/* IPsec applied, in */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_OUT_DONE
value|2
end_define

begin_comment
comment|/* IPsec applied, out */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_IN_CRYPTO_DONE
value|3
end_define

begin_comment
comment|/* NIC IPsec crypto done */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_OUT_CRYPTO_NEEDED
value|4
end_define

begin_comment
comment|/* NIC IPsec crypto req'ed */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_IN_COULD_DO_CRYPTO
value|5
end_define

begin_comment
comment|/* NIC notifies IPsec */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_PENDING_TDB
value|6
end_define

begin_comment
comment|/* Reminder to do IPsec */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_BRIDGE
value|7
end_define

begin_comment
comment|/* Bridge processing done */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_GIF
value|8
end_define

begin_comment
comment|/* GIF processing done */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_GRE
value|9
end_define

begin_comment
comment|/* GRE processing done */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IN_PACKET_CHECKSUM
value|10
end_define

begin_comment
comment|/* NIC checksumming done */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_ENCAP
value|11
end_define

begin_comment
comment|/* Encap.  processing */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_SOCKET
value|12
end_define

begin_comment
comment|/* IPSEC socket ref */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_HISTORY
value|13
end_define

begin_comment
comment|/* IPSEC history */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPV6_INPUT
value|14
end_define

begin_comment
comment|/* IPV6 input processing */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_DUMMYNET
value|15
end_define

begin_comment
comment|/* dummynet info */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_DIVERT
value|17
end_define

begin_comment
comment|/* divert info */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPFORWARD
value|18
end_define

begin_comment
comment|/* ipforward info */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_MACLABEL
value|(19 | MTAG_PERSISTENT)
end_define

begin_comment
comment|/* MAC label */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_PF
value|(21 | MTAG_PERSISTENT)
end_define

begin_comment
comment|/* PF/ALTQ information */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_RTSOCKFAM
value|25
end_define

begin_comment
comment|/* rtsock sa family */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPOPTIONS
value|27
end_define

begin_comment
comment|/* Saved IP options */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_CARP
value|28
end_define

begin_comment
comment|/* CARP info */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_IPSEC_NAT_T_PORTS
value|29
end_define

begin_comment
comment|/* two uint16_t */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_ND_OUTGOING
value|30
end_define

begin_comment
comment|/* ND outgoing */
end_comment

begin_comment
comment|/* Specific cookies and tags. */
end_comment

begin_comment
comment|/* Packet tag routines. */
end_comment

begin_function_decl
name|struct
name|m_tag
modifier|*
name|m_tag_alloc
parameter_list|(
name|u_int32_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_tag_delete
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|m_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_tag_delete_chain
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|m_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_tag_free_default
parameter_list|(
name|struct
name|m_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|m_tag
modifier|*
name|m_tag_locate
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|m_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|m_tag
modifier|*
name|m_tag_copy
parameter_list|(
name|struct
name|m_tag
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_tag_copy_chain
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
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
name|m_tag_delete_nonpersistent
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize the list of tags associated with an mbuf.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_tag_init
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|SLIST_INIT
argument_list|(
operator|&
name|m
operator|->
name|m_pkthdr
operator|.
name|tags
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set up the contents of a tag.  Note that this does not fill in the free  * method; the caller is expected to do that.  *  * XXX probably should be called m_tag_init, but that was already taken.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_tag_setup
parameter_list|(
name|struct
name|m_tag
modifier|*
name|t
parameter_list|,
name|u_int32_t
name|cookie
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|t
operator|->
name|m_tag_id
operator|=
name|type
expr_stmt|;
name|t
operator|->
name|m_tag_len
operator|=
name|len
expr_stmt|;
name|t
operator|->
name|m_tag_cookie
operator|=
name|cookie
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Reclaim resources associated with a tag.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_tag_free
parameter_list|(
name|struct
name|m_tag
modifier|*
name|t
parameter_list|)
block|{
call|(
modifier|*
name|t
operator|->
name|m_tag_free
call|)
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Return the first tag associated with an mbuf.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|m_tag
operator|*
name|m_tag_first
argument_list|(
argument|struct mbuf *m
argument_list|)
block|{
return|return
operator|(
name|SLIST_FIRST
argument_list|(
operator|&
name|m
operator|->
name|m_pkthdr
operator|.
name|tags
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * Return the next tag in the list of tags associated with an mbuf.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|m_tag
operator|*
name|m_tag_next
argument_list|(
argument|struct mbuf *m __unused
argument_list|,
argument|struct m_tag *t
argument_list|)
block|{
return|return
operator|(
name|SLIST_NEXT
argument_list|(
name|t
argument_list|,
name|m_tag_link
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * Prepend a tag to the list of tags associated with an mbuf.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_tag_prepend
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|m_tag
modifier|*
name|t
parameter_list|)
block|{
name|SLIST_INSERT_HEAD
argument_list|(
operator|&
name|m
operator|->
name|m_pkthdr
operator|.
name|tags
argument_list|,
name|t
argument_list|,
name|m_tag_link
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Unlink a tag from the list of tags associated with an mbuf.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|m_tag_unlink
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|m_tag
modifier|*
name|t
parameter_list|)
block|{
name|SLIST_REMOVE
argument_list|(
operator|&
name|m
operator|->
name|m_pkthdr
operator|.
name|tags
argument_list|,
name|t
argument_list|,
name|m_tag
argument_list|,
name|m_tag_link
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* These are for OpenBSD compatibility. */
end_comment

begin_define
define|#
directive|define
name|MTAG_ABI_COMPAT
value|0
end_define

begin_comment
comment|/* compatibility ABI */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|m_tag
operator|*
name|m_tag_get
argument_list|(
argument|int type
argument_list|,
argument|int length
argument_list|,
argument|int wait
argument_list|)
block|{
return|return
operator|(
name|m_tag_alloc
argument_list|(
name|MTAG_ABI_COMPAT
argument_list|,
name|type
argument_list|,
name|length
argument_list|,
name|wait
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|m_tag
operator|*
name|m_tag_find
argument_list|(
argument|struct mbuf *m
argument_list|,
argument|int type
argument_list|,
argument|struct m_tag *start
argument_list|)
block|{
return|return
operator|(
name|SLIST_EMPTY
argument_list|(
operator|&
name|m
operator|->
name|m_pkthdr
operator|.
name|tags
argument_list|)
operator|?
operator|(
expr|struct
name|m_tag
operator|*
operator|)
name|NULL
operator|:
name|m_tag_locate
argument_list|(
name|m
argument_list|,
name|MTAG_ABI_COMPAT
argument_list|,
name|type
argument_list|,
name|start
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_free
argument_list|(
argument|struct mbuf *m
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|n
operator|=
name|m
operator|->
name|m_next
block|;
name|MBUF_PROBE1
argument_list|(
name|m__free
argument_list|,
name|m
argument_list|)
block|;
if|if
condition|(
operator|(
name|m
operator|->
name|m_flags
operator|&
operator|(
name|M_PKTHDR
operator||
name|M_NOFREE
operator|)
operator|)
operator|==
operator|(
name|M_PKTHDR
operator||
name|M_NOFREE
operator|)
condition|)
name|m_tag_delete_chain
argument_list|(
name|m
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|m
operator|->
name|m_flags
operator|&
name|M_EXT
condition|)
name|mb_free_ext
argument_list|(
name|m
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|m
operator|->
name|m_flags
operator|&
name|M_NOFREE
operator|)
operator|==
literal|0
condition|)
name|uma_zfree
argument_list|(
name|zone_mbuf
argument_list|,
name|m
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
operator|(
name|n
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|rt_m_getfib
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|m
operator|->
name|m_flags
operator|&
name|M_PKTHDR
argument_list|,
operator|(
literal|"Attempt to get FIB from non header mbuf."
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|m
operator|->
name|m_pkthdr
operator|.
name|fibnum
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|M_GETFIB
parameter_list|(
name|_m
parameter_list|)
value|rt_m_getfib(_m)
end_define

begin_define
define|#
directive|define
name|M_SETFIB
parameter_list|(
name|_m
parameter_list|,
name|_fib
parameter_list|)
value|do {						\         KASSERT((_m)->m_flags& M_PKTHDR, ("Attempt to set FIB on non header mbuf."));	\ 	((_m)->m_pkthdr.fibnum) = (_fib);				\ } while (0)
end_define

begin_comment
comment|/* flags passed as first argument for "m_ether_tcpip_hash()" */
end_comment

begin_define
define|#
directive|define
name|MBUF_HASHFLAG_L2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MBUF_HASHFLAG_L3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MBUF_HASHFLAG_L4
value|(1<< 4)
end_define

begin_comment
comment|/* mbuf hashing helper routines */
end_comment

begin_function_decl
name|uint32_t
name|m_ether_tcpip_hash_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|m_ether_tcpip_hash
parameter_list|(
specifier|const
name|uint32_t
parameter_list|,
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MBUF_PROFILING
end_ifdef

begin_function_decl
name|void
name|m_profile
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|M_PROFILE
parameter_list|(
name|m
parameter_list|)
value|m_profile(m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_PROFILE
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|mbufq
block|{
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|mbuf
argument_list|)
name|mq_head
expr_stmt|;
name|int
name|mq_len
decl_stmt|;
name|int
name|mq_maxlen
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|mbufq_init
parameter_list|(
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|,
name|int
name|maxlen
parameter_list|)
block|{
name|STAILQ_INIT
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|)
expr_stmt|;
name|mq
operator|->
name|mq_maxlen
operator|=
name|maxlen
expr_stmt|;
name|mq
operator|->
name|mq_len
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|mbufq_flush
parameter_list|(
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|m
operator|=
name|STAILQ_FIRST
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|)
expr_stmt|;
name|STAILQ_INIT
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|)
expr_stmt|;
name|mq
operator|->
name|mq_len
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mbufq_drain
parameter_list|(
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|,
modifier|*
name|n
decl_stmt|;
name|n
operator|=
name|mbufq_flush
argument_list|(
name|mq
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|m
operator|=
name|n
operator|)
operator|!=
name|NULL
condition|)
block|{
name|n
operator|=
name|STAILQ_NEXT
argument_list|(
name|m
argument_list|,
name|m_stailqpkt
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|mbufq_first
parameter_list|(
specifier|const
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
return|return
operator|(
name|STAILQ_FIRST
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|mbufq_last
parameter_list|(
specifier|const
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
return|return
operator|(
name|STAILQ_LAST
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|,
name|mbuf
argument_list|,
name|m_stailqpkt
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|mbufq_full
parameter_list|(
specifier|const
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
return|return
operator|(
name|mq
operator|->
name|mq_len
operator|>=
name|mq
operator|->
name|mq_maxlen
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|mbufq_len
parameter_list|(
specifier|const
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
return|return
operator|(
name|mq
operator|->
name|mq_len
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|mbufq_enqueue
parameter_list|(
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
if|if
condition|(
name|mbufq_full
argument_list|(
name|mq
argument_list|)
condition|)
return|return
operator|(
name|ENOBUFS
operator|)
return|;
name|STAILQ_INSERT_TAIL
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|,
name|m
argument_list|,
name|m_stailqpkt
argument_list|)
expr_stmt|;
name|mq
operator|->
name|mq_len
operator|++
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|mbufq_dequeue
parameter_list|(
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|m
operator|=
name|STAILQ_FIRST
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
block|{
name|STAILQ_REMOVE_HEAD
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|,
name|m_stailqpkt
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_nextpkt
operator|=
name|NULL
expr_stmt|;
name|mq
operator|->
name|mq_len
operator|--
expr_stmt|;
block|}
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mbufq_prepend
parameter_list|(
name|struct
name|mbufq
modifier|*
name|mq
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|STAILQ_INSERT_HEAD
argument_list|(
operator|&
name|mq
operator|->
name|mq_head
argument_list|,
name|m
argument_list|,
name|m_stailqpkt
argument_list|)
expr_stmt|;
name|mq
operator|->
name|mq_len
operator|++
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
comment|/* !_SYS_MBUF_H_ */
end_comment

end_unit

