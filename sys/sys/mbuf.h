begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mbuf.h	8.5 (Berkeley) 2/19/95  * $FreeBSD$  */
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
comment|/*  * Mbufs are of a single size, MSIZE (machine/param.h), which  * includes overhead.  An mbuf may add a single "mbuf cluster" of size  * MCLBYTES (also in machine/param.h), which has no additional overhead  * and is used instead of the internal data area; this is done when  * at least MINCLSIZE of data must be stored.  Additionally, it is possible  * to allocate a separate buffer externally and attach it to the mbuf in  * a way similar to that of mbuf clusters.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
name|short
name|mh_type
decl_stmt|;
comment|/* type of data in this mbuf */
name|short
name|mh_flags
decl_stmt|;
comment|/* flags; see below */
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
name|int
name|len
decl_stmt|;
comment|/* total packet length */
comment|/* variables for ip and tcp reassembly */
name|void
modifier|*
name|header
decl_stmt|;
comment|/* pointer to packet header */
comment|/* variables for hardware checksum */
name|int
name|csum_flags
decl_stmt|;
comment|/* flags regarding checksum */
name|int
name|csum_data
decl_stmt|;
comment|/* data field used by csum routines */
name|struct
name|mbuf
modifier|*
name|aux
decl_stmt|;
comment|/* extra data buffer; ipsec/others */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of external storage mapped into mbuf; valid only if M_EXT is set.  */
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
name|caddr_t
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
comment|/*  * The core of the mbuf object along with some shortcut defines for  * practical purposes.  */
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

begin_comment
comment|/*  * Flags copied when copying m_pkthdr.  */
end_comment

begin_define
define|#
directive|define
name|M_COPYFLAGS
value|(M_PKTHDR|M_EOR|M_PROTO1|M_PROTO1|M_PROTO2|M_PROTO3 | \ 			    M_PROTO4|M_PROTO5|M_BCAST|M_MCAST|M_FRAG|M_RDONLY)
end_define

begin_comment
comment|/*  * Flags indicating hw checksum support and sw checksum requirements.  */
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
value|2
end_define

begin_comment
comment|/* packet header */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MT_SOCKET
value|3
end_define

begin_comment
comment|/* socket structure */
end_comment

begin_define
define|#
directive|define
name|MT_PCB
value|4
end_define

begin_comment
comment|/* protocol control block */
end_comment

begin_define
define|#
directive|define
name|MT_RTABLE
value|5
end_define

begin_comment
comment|/* routing tables */
end_comment

begin_define
define|#
directive|define
name|MT_HTABLE
value|6
end_define

begin_comment
comment|/* IMP host tables */
end_comment

begin_define
define|#
directive|define
name|MT_ATABLE
value|7
end_define

begin_comment
comment|/* address resolution tables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MT_SONAME
value|8
end_define

begin_comment
comment|/* socket name */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MT_SOOPTS
value|10
end_define

begin_comment
comment|/* socket options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MT_FTABLE
value|11
end_define

begin_comment
comment|/* fragment reassembly header */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MT_RIGHTS
value|12
end_define

begin_comment
comment|/* access rights */
end_comment

begin_define
define|#
directive|define
name|MT_IFADDR
value|13
end_define

begin_comment
comment|/* interface address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Mbuf and cluster allocation statistics PCPU structure.  */
end_comment

begin_struct
struct|struct
name|mbpstat
block|{
name|u_long
name|mb_mbfree
decl_stmt|;
name|u_long
name|mb_mbpgs
decl_stmt|;
name|u_long
name|mb_clfree
decl_stmt|;
name|u_long
name|mb_clpgs
decl_stmt|;
name|long
name|mb_mbtypes
index|[
name|MT_NTYPES
index|]
decl_stmt|;
name|short
name|mb_active
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * General mbuf allocator statistics structure.  * XXX: Modifications of these are not protected by any mutex locks nor by  * any atomic() manipulations.  As a result, we may occasionally lose  * a count or two.  Luckily, not all of these fields are modified at all  * and remain static, and those that are manipulated are only manipulated  * in failure situations, which do not occur (hopefully) very often.  */
end_comment

begin_struct
struct|struct
name|mbstat
block|{
name|u_long
name|m_drops
decl_stmt|;
comment|/* times failed to allocate */
name|u_long
name|m_wait
decl_stmt|;
comment|/* times succesfully returned from wait */
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
comment|/* Number of mbtypes (gives # elems in mbpstat's mb_mbtypes[] array: */
name|short
name|m_numtypes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags specifying how an allocation should be made.  * M_DONTWAIT means "don't block if nothing is available" whereas  * M_TRYWAIT means "block for mbuf_wait ticks at most if nothing is  * available."  */
end_comment

begin_define
define|#
directive|define
name|M_DONTWAIT
value|1
end_define

begin_define
define|#
directive|define
name|M_TRYWAIT
value|0
end_define

begin_define
define|#
directive|define
name|M_WAIT
value|M_TRYWAIT
end_define

begin_comment
comment|/* XXX: Deprecated. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*-  * mbuf external reference count management macros.  *  * MEXT_IS_REF(m): true if (m) is not the only mbuf referencing  *     the external buffer ext_buf.  *  * MEXT_REM_REF(m): remove reference to m_ext object.  *  * MEXT_ADD_REF(m): add reference to m_ext object already  *     referred to by (m).  */
end_comment

begin_define
define|#
directive|define
name|MEXT_IS_REF
parameter_list|(
name|m
parameter_list|)
value|(*((m)->m_ext.ref_cnt)> 1)
end_define

begin_define
define|#
directive|define
name|MEXT_REM_REF
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	KASSERT(*((m)->m_ext.ref_cnt)> 0, ("m_ext refcnt< 0"));	\ 	atomic_subtract_int((m)->m_ext.ref_cnt, 1);			\ } while(0)
end_define

begin_define
define|#
directive|define
name|MEXT_ADD_REF
parameter_list|(
name|m
parameter_list|)
value|atomic_add_int((m)->m_ext.ref_cnt, 1)
end_define

begin_comment
comment|/*  * mbuf, cluster, and external object allocation macros  * (for compatibility purposes).  */
end_comment

begin_define
define|#
directive|define
name|m_getclr
value|m_get_clrd
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
value|(m) = m_get((how), (type))
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
value|(m) = m_gethdr((how), (type))
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

begin_comment
comment|/*  * MEXTFREE(m): disassociate (and possibly free) an external object from (m).  *   * If the atomic_cmpset_int() returns 0, then we effectively do nothing  * in terms of "cleaning up" (freeing the ext buf and ref. counter) as  * this means that either there are still references, or another thread  * is taking care of the clean-up.  */
end_comment

begin_define
define|#
directive|define
name|MEXTFREE
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	struct mbuf *_mb = (m);						\ 									\ 	MEXT_REM_REF(_mb);						\ 	if (atomic_cmpset_int(_mb->m_ext.ref_cnt, 0, 1))		\ 		_mext_free(_mb);					\ 	_mb->m_flags&= ~M_EXT;						\ } while (0)
end_define

begin_comment
comment|/*  * Evaluate TRUE if it's safe to write to the mbuf m's data region (this  * can be both the local data payload, or an external buffer area,  * depending on whether M_EXT is set).  */
end_comment

begin_define
define|#
directive|define
name|M_WRITABLE
parameter_list|(
name|m
parameter_list|)
value|(!((m)->m_flags& M_RDONLY)&& (!((m)->m_flags  \& M_EXT) || !MEXT_IS_REF(m)))
end_define

begin_comment
comment|/*-  * Copy mbuf pkthdr from "from" to "to".  * "from" must have M_PKTHDR set, and "to" must be empty.  * aux pointer will be moved to "to".  */
end_comment

begin_define
define|#
directive|define
name|M_COPY_PKTHDR
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|)
value|do {					\ 	struct mbuf *_mfrom = (from);					\ 	struct mbuf *_mto = (to);					\ 									\ 	_mto->m_data = _mto->m_pktdat;					\ 	_mto->m_flags = _mfrom->m_flags& M_COPYFLAGS;			\ 	_mto->m_pkthdr = _mfrom->m_pkthdr;				\ 	_mfrom->m_pkthdr.aux = NULL;					\ } while (0)
end_define

begin_comment
comment|/*  * Set the m_data pointer of a newly-allocated mbuf (m_get/MGET) to place  * an object of the specified size at the end of the mbuf, longword aligned.  */
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
value|do {						\ 	(m)->m_data += (MLEN - (len))& ~(sizeof(long) - 1);		\ } while (0)
end_define

begin_comment
comment|/*  * As above, for mbufs allocated with m_gethdr/MGETHDR  * or initialized by M_COPY_PKTHDR.  */
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
value|do {						\ 	(m)->m_data += (MHLEN - (len))& ~(sizeof(long) - 1);		\ } while (0)
end_define

begin_comment
comment|/*  * Compute the amount of space available  * before the current start of data in an mbuf.  */
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
comment|/*  * Compute the amount of space available  * after the end of data in an mbuf.  */
end_comment

begin_define
define|#
directive|define
name|M_TRAILINGSPACE
parameter_list|(
name|m
parameter_list|)
define|\
value|((m)->m_flags& M_EXT ? (m)->m_ext.ext_buf +			\ 	    (m)->m_ext.ext_size - ((m)->m_data + (m)->m_len) :		\&(m)->m_dat[MLEN] - ((m)->m_data + (m)->m_len))
end_define

begin_comment
comment|/*  * Arrange to prepend space of size plen to mbuf m.  * If a new mbuf must be allocated, how specifies whether to wait.  * If the allocation fails, the original mbuf chain is freed and m is  * set to NULL.  */
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
value|do {					\ 	struct mbuf **_mmp =&(m);					\ 	struct mbuf *_mm = *_mmp;					\ 	int _mplen = (plen);						\ 	int __mhow = (how);						\ 									\ 	if (M_LEADINGSPACE(_mm)>= _mplen) {				\ 		_mm->m_data -= _mplen;					\ 		_mm->m_len += _mplen;					\ 	} else								\ 		_mm = m_prepend(_mm, _mplen, __mhow);			\ 	if (_mm != NULL&& _mm->m_flags& M_PKTHDR)			\ 		_mm->m_pkthdr.len += _mplen;				\ 	*_mmp = _mm;							\ } while (0)
end_define

begin_comment
comment|/*  * Change mbuf to new type.  * This is a relatively expensive operation and should be avoided.  */
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
comment|/* Compatibility with 4.3 */
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

begin_comment
comment|/*  * pkthdr.aux type tags.  */
end_comment

begin_struct
struct|struct
name|mauxtag
block|{
name|int
name|af
decl_stmt|;
name|int
name|type
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* largest link + protocol header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_linkhdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* largest link-level header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_protohdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* largest protocol header */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mbpstat
name|mb_statpcpu
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Per-CPU allocation stats. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mbstat
name|mbstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General mbuf stats/infos. */
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

begin_decl_stmt
specifier|extern
name|int
name|nmbcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scale kmem_map for counter space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nmbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of mbufs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nsfbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of sendfile(2) bufs */
end_comment

begin_function_decl
name|void
name|_mext_free
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
name|struct
name|mbuf
modifier|*
name|m_aux_add
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
name|m_aux_add2
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_aux_delete
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
name|m_aux_find
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
name|m_aux_find2
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
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
name|m_chtype
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_clget
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
name|free
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|short
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
name|caddr_t
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
name|copy
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
name|struct
name|mbuf
modifier|*
name|m_free
parameter_list|(
name|struct
name|mbuf
modifier|*
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
name|m_get
parameter_list|(
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
name|m_get_clrd
parameter_list|(
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
name|m_gethdr
parameter_list|(
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
name|m_gethdr_clrd
parameter_list|(
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
name|m_getm
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
name|m
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

