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

begin_comment
comment|/*  * Mbufs are of a single size, MSIZE (sys/param.h), which includes overhead.  * An mbuf may add a single "mbuf cluster" of size MCLBYTES (also in  * sys/param.h), which has no additional overhead and is used instead of the  * internal data area; this is done when at least MINCLSIZE of data must be  * stored.  Additionally, it is possible to allocate a separate buffer  * externally and attach it to the mbuf in a way similar to that of mbuf  * clusters.  */
end_comment

begin_define
define|#
directive|define
name|MLEN
value|(MSIZE - sizeof(struct m_hdr))
end_define

begin_comment
comment|/* normal data len */
end_comment

begin_define
define|#
directive|define
name|MHLEN
value|(MLEN - sizeof(struct pkthdr))
end_define

begin_comment
comment|/* data len w/pkthdr */
end_comment

begin_define
define|#
directive|define
name|MINCLSIZE
value|(MHLEN + 1)
end_define

begin_comment
comment|/* smallest amount to put in cluster */
end_comment

begin_define
define|#
directive|define
name|M_MAXCOMPRESS
value|(MHLEN / 2)
end_define

begin_comment
comment|/* max amount to copy for compression */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*-  * Macros for type conversion:  * mtod(m, t)	-- Convert mbuf pointer to data pointer of correct type.  * dtom(x)	-- Convert data pointer within mbuf to mbuf pointer (XXX).  */
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
name|dtom
parameter_list|(
name|x
parameter_list|)
value|((struct mbuf *)((intptr_t)(x)& ~(MSIZE-1)))
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LP64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_HDR_PAD
value|6
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_HDR_PAD
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Header present at the beginning of every mbuf.  */
end_comment

begin_struct
struct|struct
name|m_hdr
block|{
name|struct
name|mbuf
modifier|*
name|mh_next
decl_stmt|;
comment|/* next buffer in chain */
name|struct
name|mbuf
modifier|*
name|mh_nextpkt
decl_stmt|;
comment|/* next chain in queue/record */
name|caddr_t
name|mh_data
decl_stmt|;
comment|/* location of data */
name|int
name|mh_len
decl_stmt|;
comment|/* amount of data in this mbuf */
name|int
name|mh_flags
decl_stmt|;
comment|/* flags; see below */
name|short
name|mh_type
decl_stmt|;
comment|/* type of data in this mbuf */
name|uint8_t
name|pad
index|[
name|M_HDR_PAD
index|]
decl_stmt|;
comment|/* word align                  */
block|}
struct|;
end_struct

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
comment|/*  * Record/packet header in first mbuf of chain; valid only if M_PKTHDR is set.  */
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
comment|/* variables for ip and tcp reassembly */
name|void
modifier|*
name|header
decl_stmt|;
comment|/* pointer to packet header */
name|int
name|len
decl_stmt|;
comment|/* total packet length */
comment|/* variables for hardware checksum */
name|int
name|csum_flags
decl_stmt|;
comment|/* flags regarding checksum */
name|int
name|csum_data
decl_stmt|;
comment|/* data field used by csum routines */
name|u_int16_t
name|tso_segsz
decl_stmt|;
comment|/* TSO segment size */
name|u_int16_t
name|ether_vtag
decl_stmt|;
comment|/* Ethernet 802.1p+q vlan tag */
name|SLIST_HEAD
argument_list|(
argument|packet_tags
argument_list|,
argument|m_tag
argument_list|)
name|tags
expr_stmt|;
comment|/* list of packet tags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of external storage mapped into mbuf; valid only if M_EXT is  * set.  */
end_comment

begin_struct
struct|struct
name|m_ext
block|{
name|caddr_t
name|ext_buf
decl_stmt|;
comment|/* start of buffer */
name|void
function_decl|(
modifier|*
name|ext_free
function_decl|)
comment|/* free routine if not the usual */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ext_args
decl_stmt|;
comment|/* optional argument pointer */
name|u_int
name|ext_size
decl_stmt|;
comment|/* size of buffer, for ext_free */
specifier|volatile
name|u_int
modifier|*
name|ref_cnt
decl_stmt|;
comment|/* pointer to ref count info */
name|int
name|ext_type
decl_stmt|;
comment|/* type of external storage */
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
name|struct
name|m_hdr
name|m_hdr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|pkthdr
name|MH_pkthdr
decl_stmt|;
comment|/* M_PKTHDR set */
union|union
block|{
name|struct
name|m_ext
name|MH_ext
decl_stmt|;
comment|/* M_EXT set */
name|char
name|MH_databuf
index|[
name|MHLEN
index|]
decl_stmt|;
block|}
name|MH_dat
union|;
block|}
name|MH
struct|;
name|char
name|M_databuf
index|[
name|MLEN
index|]
decl_stmt|;
comment|/* !M_PKTHDR, !M_EXT */
block|}
name|M_dat
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|m_next
value|m_hdr.mh_next
end_define

begin_define
define|#
directive|define
name|m_len
value|m_hdr.mh_len
end_define

begin_define
define|#
directive|define
name|m_data
value|m_hdr.mh_data
end_define

begin_define
define|#
directive|define
name|m_type
value|m_hdr.mh_type
end_define

begin_define
define|#
directive|define
name|m_flags
value|m_hdr.mh_flags
end_define

begin_define
define|#
directive|define
name|m_nextpkt
value|m_hdr.mh_nextpkt
end_define

begin_define
define|#
directive|define
name|m_act
value|m_nextpkt
end_define

begin_define
define|#
directive|define
name|m_pkthdr
value|M_dat.MH.MH_pkthdr
end_define

begin_define
define|#
directive|define
name|m_ext
value|M_dat.MH.MH_dat.MH_ext
end_define

begin_define
define|#
directive|define
name|m_pktdat
value|M_dat.MH.MH_dat.MH_databuf
end_define

begin_define
define|#
directive|define
name|m_dat
value|M_dat.M_databuf
end_define

begin_comment
comment|/*  * mbuf flags.  */
end_comment

begin_define
define|#
directive|define
name|M_EXT
value|0x0001
end_define

begin_comment
comment|/* has associated external storage */
end_comment

begin_define
define|#
directive|define
name|M_PKTHDR
value|0x0002
end_define

begin_comment
comment|/* start of record */
end_comment

begin_define
define|#
directive|define
name|M_EOR
value|0x0004
end_define

begin_comment
comment|/* end of record */
end_comment

begin_define
define|#
directive|define
name|M_RDONLY
value|0x0008
end_define

begin_comment
comment|/* associated data is marked read-only */
end_comment

begin_define
define|#
directive|define
name|M_PROTO1
value|0x0010
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO2
value|0x0020
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO3
value|0x0040
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO4
value|0x0080
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO5
value|0x0100
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_NOTIFICATION
value|0x2000
end_define

begin_comment
comment|/* SCTP notification */
end_comment

begin_define
define|#
directive|define
name|M_SKIP_FIREWALL
value|0x4000
end_define

begin_comment
comment|/* skip firewall processing */
end_comment

begin_define
define|#
directive|define
name|M_FREELIST
value|0x8000
end_define

begin_comment
comment|/* mbuf is on the free list */
end_comment

begin_comment
comment|/*  * mbuf pkthdr flags (also stored in m_flags).  */
end_comment

begin_define
define|#
directive|define
name|M_BCAST
value|0x0200
end_define

begin_comment
comment|/* send/received as link-level broadcast */
end_comment

begin_define
define|#
directive|define
name|M_MCAST
value|0x0400
end_define

begin_comment
comment|/* send/received as link-level multicast */
end_comment

begin_define
define|#
directive|define
name|M_FRAG
value|0x0800
end_define

begin_comment
comment|/* packet is a fragment of a larger packet */
end_comment

begin_define
define|#
directive|define
name|M_FIRSTFRAG
value|0x1000
end_define

begin_comment
comment|/* packet is first fragment */
end_comment

begin_define
define|#
directive|define
name|M_LASTFRAG
value|0x2000
end_define

begin_comment
comment|/* packet is last fragment */
end_comment

begin_define
define|#
directive|define
name|M_VLANTAG
value|0x10000
end_define

begin_comment
comment|/* ether_vtag is valid */
end_comment

begin_define
define|#
directive|define
name|M_PROMISC
value|0x20000
end_define

begin_comment
comment|/* packet was not for us */
end_comment

begin_comment
comment|/*  * External buffer types: identify ext_buf type.  */
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
comment|/* sendfile(2)'s sf_bufs */
end_comment

begin_define
define|#
directive|define
name|EXT_JUMBOP
value|3
end_define

begin_comment
comment|/* jumbo cluster 4096 bytes */
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
name|EXT_NET_DRV
value|100
end_define

begin_comment
comment|/* custom ext_buf provided by net driver(s) */
end_comment

begin_define
define|#
directive|define
name|EXT_MOD_TYPE
value|200
end_define

begin_comment
comment|/* custom module's ext_buf type */
end_comment

begin_define
define|#
directive|define
name|EXT_DISPOSABLE
value|300
end_define

begin_comment
comment|/* can throw this buffer away w/page flipping */
end_comment

begin_define
define|#
directive|define
name|EXT_EXTREF
value|400
end_define

begin_comment
comment|/* has externally maintained ref_cnt ptr */
end_comment

begin_comment
comment|/*  * Flags copied when copying m_pkthdr.  */
end_comment

begin_define
define|#
directive|define
name|M_COPYFLAGS
value|(M_PKTHDR|M_EOR|M_RDONLY|M_PROTO1|M_PROTO1|M_PROTO2|\ 			    M_PROTO3|M_PROTO4|M_PROTO5|M_SKIP_FIREWALL|\ 			    M_BCAST|M_MCAST|M_FRAG|M_FIRSTFRAG|M_LASTFRAG|\ 			    M_VLANTAG|M_PROMISC)
end_define

begin_comment
comment|/*  * Flags to purge when crossing layers.  */
end_comment

begin_define
define|#
directive|define
name|M_PROTOFLAGS
value|(M_PROTO1|M_PROTO2|M_PROTO3|M_PROTO4|M_PROTO5)
end_define

begin_comment
comment|/*  * Flags indicating hw checksum support and sw checksum requirements.  This  * field can be directly tested against if_data.ifi_hwassist.  */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP
value|0x0001
end_define

begin_comment
comment|/* will csum IP */
end_comment

begin_define
define|#
directive|define
name|CSUM_TCP
value|0x0002
end_define

begin_comment
comment|/* will csum TCP */
end_comment

begin_define
define|#
directive|define
name|CSUM_UDP
value|0x0004
end_define

begin_comment
comment|/* will csum UDP */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_FRAGS
value|0x0008
end_define

begin_comment
comment|/* will csum IP fragments */
end_comment

begin_define
define|#
directive|define
name|CSUM_FRAGMENT
value|0x0010
end_define

begin_comment
comment|/* will do IP fragmentation */
end_comment

begin_define
define|#
directive|define
name|CSUM_TSO
value|0x0020
end_define

begin_comment
comment|/* will do TSO */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_CHECKED
value|0x0100
end_define

begin_comment
comment|/* did csum IP */
end_comment

begin_define
define|#
directive|define
name|CSUM_IP_VALID
value|0x0200
end_define

begin_comment
comment|/*   ... the csum is valid */
end_comment

begin_define
define|#
directive|define
name|CSUM_DATA_VALID
value|0x0400
end_define

begin_comment
comment|/* csum_data field is valid */
end_comment

begin_define
define|#
directive|define
name|CSUM_PSEUDO_HDR
value|0x0800
end_define

begin_comment
comment|/* csum_data has pseudo hdr */
end_comment

begin_define
define|#
directive|define
name|CSUM_DELAY_DATA
value|(CSUM_TCP | CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|CSUM_DELAY_IP
value|(CSUM_IP)
end_define

begin_comment
comment|/* XXX add ipv6 here too? */
end_comment

begin_comment
comment|/*  * mbuf types.  */
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
name|MT_SONAME
value|8
end_define

begin_comment
comment|/* socket name */
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
comment|/*  * General mbuf allocator statistics structure.  *  * Many of these statistics are no longer used; we instead track many  * allocator statistics through UMA's built in statistics mechanism.  */
end_comment

begin_struct
struct|struct
name|mbstat
block|{
name|u_long
name|m_mbufs
decl_stmt|;
comment|/* XXX */
name|u_long
name|m_mclusts
decl_stmt|;
comment|/* XXX */
name|u_long
name|m_drain
decl_stmt|;
comment|/* times drained protocols for space */
name|u_long
name|m_mcfail
decl_stmt|;
comment|/* XXX: times m_copym failed */
name|u_long
name|m_mpfail
decl_stmt|;
comment|/* XXX: times m_pullup failed */
name|u_long
name|m_msize
decl_stmt|;
comment|/* length of an mbuf */
name|u_long
name|m_mclbytes
decl_stmt|;
comment|/* length of an mbuf cluster */
name|u_long
name|m_minclsize
decl_stmt|;
comment|/* min length of data to allocate a cluster */
name|u_long
name|m_mlen
decl_stmt|;
comment|/* length of data in an mbuf */
name|u_long
name|m_mhlen
decl_stmt|;
comment|/* length of data in a header mbuf */
comment|/* Number of mbtypes (gives # elems in mbtypes[] array: */
name|short
name|m_numtypes
decl_stmt|;
comment|/* XXX: Sendfile stats should eventually move to their own struct */
name|u_long
name|sf_iocnt
decl_stmt|;
comment|/* times sendfile had to do disk I/O */
name|u_long
name|sf_allocfail
decl_stmt|;
comment|/* times sfbuf allocation failed */
name|u_long
name|sf_allocwait
decl_stmt|;
comment|/* times sfbuf allocation had to wait */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags specifying how an allocation should be made.  *  * The flag to use is as follows:  * - M_DONTWAIT or M_NOWAIT from an interrupt handler to not block allocation.  * - M_WAIT or M_WAITOK or M_TRYWAIT from wherever it is safe to block.  *  * M_DONTWAIT/M_NOWAIT means that we will not block the thread explicitly and  * if we cannot allocate immediately we may return NULL, whereas  * M_WAIT/M_WAITOK/M_TRYWAIT means that if we cannot allocate resources we  * will block until they are available, and thus never return NULL.  *  * XXX Eventually just phase this out to use M_WAITOK/M_NOWAIT.  */
end_comment

begin_define
define|#
directive|define
name|MBTOM
parameter_list|(
name|how
parameter_list|)
value|(how)
end_define

begin_define
define|#
directive|define
name|M_DONTWAIT
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|M_TRYWAIT
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|M_WAIT
value|M_WAITOK
end_define

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
value|"mbuf_jumbo_pagesize"
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

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|zone_ext_refcnt
decl_stmt|;
end_decl_stmt

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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getjcl
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|,
argument|int flags
argument_list|,
argument|int size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getclr
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_free
argument_list|(
expr|struct
name|mbuf
operator|*
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|__inline
name|void
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
specifier|static
name|__inline
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

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_last
argument_list|(
expr|struct
name|mbuf
operator|*
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

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
literal|"%s: m_getjcl: invalid cluster size"
argument_list|,
name|__func__
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
name|MSIZE
case|:
name|zone
operator|=
name|zone_mbuf
expr_stmt|;
break|break;
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
literal|"%s: m_getjcl: invalid cluster type"
argument_list|,
name|__func__
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
return|return
operator|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
operator|(
name|uma_zalloc_arg
argument_list|(
name|zone_mbuf
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * XXX This should be deprecated, very little use.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getclr
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
if|if
condition|(
name|m
operator|!=
name|NULL
condition|)
name|bzero
argument_list|(
name|m
operator|->
name|m_data
argument_list|,
name|MLEN
argument_list|)
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
name|__inline
name|struct
name|mbuf
modifier|*
name|m_gethdr
parameter_list|(
name|int
name|how
parameter_list|,
name|short
name|type
parameter_list|)
block|{
name|struct
name|mb_args
name|args
decl_stmt|;
name|args
operator|.
name|flags
operator|=
name|M_PKTHDR
expr_stmt|;
name|args
operator|.
name|type
operator|=
name|type
expr_stmt|;
return|return
operator|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
operator|(
name|uma_zalloc_arg
argument_list|(
name|zone_mbuf
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
operator|)
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
name|m_getcl
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|,
argument|int flags
argument_list|)
block|{ 	struct
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
return|return
operator|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
operator|(
name|uma_zalloc_arg
argument_list|(
name|zone_pack
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * m_getjcl() returns an mbuf with a cluster of the specified size attached.  * For size it takes MCLBYTES, MJUMPAGESIZE, MJUM9BYTES, MJUM16BYTES.  *  * XXX: This is rather large, should be real function maybe.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getjcl
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|,
argument|int flags
argument_list|,
argument|int size
argument_list|)
block|{ 	struct
name|mb_args
name|args
block|; 	struct
name|mbuf
operator|*
name|m
block|,
operator|*
name|n
block|;
name|uma_zone_t
name|zone
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
name|zone_mbuf
argument_list|,
operator|&
name|args
argument_list|,
name|how
argument_list|)
block|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|zone
operator|=
name|m_getzone
argument_list|(
name|size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|n
operator|=
name|uma_zalloc_arg
argument_list|(
name|zone
argument_list|,
name|m
argument_list|,
name|how
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|n
operator|==
name|NULL
condition|)
block|{
name|uma_zfree
argument_list|(
name|zone_mbuf
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_if

begin_return
return|return
operator|(
name|m
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|struct
name|mbuf
modifier|*
name|m_free
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|n
init|=
name|m
operator|->
name|m_next
decl_stmt|;
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
else|else
name|uma_zfree
argument_list|(
name|zone_mbuf
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
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
block|{
if|if
condition|(
name|m
operator|->
name|m_flags
operator|&
name|M_EXT
condition|)
name|printf
argument_list|(
literal|"%s: %p mbuf already has cluster\n"
argument_list|,
name|__func__
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_ext
operator|.
name|ext_buf
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
name|uma_zalloc_arg
argument_list|(
name|zone_clust
argument_list|,
name|m
argument_list|,
name|how
argument_list|)
expr_stmt|;
comment|/* 	 * On a cluster allocation failure, drain the packet zone and retry, 	 * we might be able to loosen a few clusters up on the drain. 	 */
if|if
condition|(
operator|(
name|how
operator|&
name|M_NOWAIT
operator|)
operator|&&
operator|(
name|m
operator|->
name|m_ext
operator|.
name|ext_buf
operator|==
name|NULL
operator|)
condition|)
block|{
name|zone_drain
argument_list|(
name|zone_pack
argument_list|)
expr_stmt|;
name|uma_zalloc_arg
argument_list|(
name|zone_clust
argument_list|,
name|m
argument_list|,
name|how
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * m_cljget() is different from m_clget() as it can allocate clusters without  * attaching them to an mbuf.  In that case the return value is the pointer  * to the cluster of the requested size.  If an mbuf was specified, it gets  * the cluster attached to it and the return value can be safely ignored.  * For size it takes MCLBYTES, MJUMPAGESIZE, MJUM9BYTES, MJUM16BYTES.  */
end_comment

begin_function
specifier|static
name|__inline
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
block|{
name|uma_zone_t
name|zone
decl_stmt|;
if|if
condition|(
name|m
operator|&&
name|m
operator|->
name|m_flags
operator|&
name|M_EXT
condition|)
name|printf
argument_list|(
literal|"%s: %p mbuf already has cluster\n"
argument_list|,
name|__func__
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|!=
name|NULL
condition|)
name|m
operator|->
name|m_ext
operator|.
name|ext_buf
operator|=
name|NULL
expr_stmt|;
name|zone
operator|=
name|m_getzone
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|uma_zalloc_arg
argument_list|(
name|zone
argument_list|,
name|m
argument_list|,
name|how
argument_list|)
operator|)
return|;
block|}
end_function

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
name|uma_zone_t
name|zone
decl_stmt|;
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
name|EXT_JUMBOP
case|:
name|size
operator|=
name|MJUMPAGESIZE
expr_stmt|;
name|zone
operator|=
name|zone_jumbop
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
name|zone
operator|=
name|zone_jumbo9
expr_stmt|;
break|break;
case|case
name|EXT_JUMBO16
case|:
name|size
operator|=
name|MJUM16BYTES
expr_stmt|;
name|zone
operator|=
name|zone_jumbo16
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"unknown cluster type"
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
name|ext_args
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
name|ref_cnt
operator|=
name|uma_find_refcnt
argument_list|(
name|zone
argument_list|,
name|cl
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_flags
operator||=
name|M_EXT
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

begin_comment
unit|}
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
name|args
parameter_list|,
name|flags
parameter_list|,
name|type
parameter_list|)
define|\
value|m_extadd((m), (caddr_t)(buf), (size), (free), (args), (flags), (type))
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
value|(!((m)->m_flags& M_RDONLY)&&			\ 			 (!(((m)->m_flags& M_EXT)) ||			\ 			 (*((m)->m_ext.ref_cnt) == 1)) )
end_define

begin_comment
unit|\
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
value|KASSERT(m != NULL&& m->m_flags& M_PKTHDR,			\ 	    ("%s: no mbuf packet header!", __func__))
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
comment|/*  * Set the m_data pointer of a newly-allocated mbuf (m_get/MGET) to place an  * object of the specified size at the end of the mbuf, longword aligned.  */
end_comment

begin_define
define|#
directive|define
name|M_ALIGN
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|do {						\ 	KASSERT(!((m)->m_flags& (M_PKTHDR|M_EXT)),			\ 		("%s: M_ALIGN not normal mbuf", __func__));		\ 	KASSERT((m)->m_data == (m)->m_dat,				\ 		("%s: M_ALIGN not a virgin mbuf", __func__));		\ 	(m)->m_data += (MLEN - (len))& ~(sizeof(long) - 1);		\ } while (0)
end_define

begin_comment
comment|/*  * As above, for mbufs allocated with m_gethdr/MGETHDR or initialized by  * M_DUP/MOVE_PKTHDR.  */
end_comment

begin_define
define|#
directive|define
name|MH_ALIGN
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|do {						\ 	KASSERT((m)->m_flags& M_PKTHDR&& !((m)->m_flags& M_EXT),	\ 		("%s: MH_ALIGN not PKTHDR mbuf", __func__));		\ 	KASSERT((m)->m_data == (m)->m_pktdat,				\ 		("%s: MH_ALIGN not a virgin mbuf", __func__));		\ 	(m)->m_data += (MHLEN - (len))& ~(sizeof(long) - 1);		\ } while (0)
end_define

begin_comment
comment|/*  * Compute the amount of space available before the current start of data in  * an mbuf.  *  * The M_WRITABLE() is a temporary, conservative safety measure: the burden  * of checking writability of the mbuf data area rests solely with the caller.  */
end_comment

begin_define
define|#
directive|define
name|M_LEADINGSPACE
parameter_list|(
name|m
parameter_list|)
define|\
value|((m)->m_flags& M_EXT ?						\ 	    (M_WRITABLE(m) ? (m)->m_data - (m)->m_ext.ext_buf : 0):	\ 	    (m)->m_flags& M_PKTHDR ? (m)->m_data - (m)->m_pktdat :	\ 	    (m)->m_data - (m)->m_dat)
end_define

begin_comment
comment|/*  * Compute the amount of space available after the end of data in an mbuf.  *  * The M_WRITABLE() is a temporary, conservative safety measure: the burden  * of checking writability of the mbuf data area rests solely with the caller.  */
end_comment

begin_define
define|#
directive|define
name|M_TRAILINGSPACE
parameter_list|(
name|m
parameter_list|)
define|\
value|((m)->m_flags& M_EXT ?						\ 	    (M_WRITABLE(m) ? (m)->m_ext.ext_buf + (m)->m_ext.ext_size	\ 		- ((m)->m_data + (m)->m_len) : 0) :			\&(m)->m_dat[MLEN] - ((m)->m_data + (m)->m_len))
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
value|m_copym((m), (o), (l), M_DONTWAIT)
end_define

begin_decl_stmt
unit|extern
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
name|struct
name|mbstat
name|mbstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General mbuf stats/infos */
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

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

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
name|void
name|m_align
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
name|m_copymdata
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
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
name|n
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|dstoff
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
name|m_demote
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
name|struct
name|mbuf
modifier|*
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
name|how
parameter_list|)
function_decl|;
end_function_decl

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
name|PACKET_TAG_PF_ROUTED
value|21
end_define

begin_comment
comment|/* PF routed, avoid loops */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_PF_FRAGCACHE
value|22
end_define

begin_comment
comment|/* PF fragment cached */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_PF_QID
value|23
end_define

begin_comment
comment|/* PF ALTQ queue id */
end_comment

begin_define
define|#
directive|define
name|PACKET_TAG_PF_TAG
value|24
end_define

begin_comment
comment|/* PF tagged */
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
name|PACKET_TAG_PF_TRANSLATE_LOCALHOST
value|26
end_define

begin_comment
comment|/* PF translate localhost */
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
argument|struct mbuf *m
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

