begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mbuf.h	8.5 (Berkeley) 2/19/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Mbufs are of a single size, MSIZE (machine/param.h), which  * includes overhead.  An mbuf may add a single "mbuf cluster" of size  * MCLBYTES (also in machine/param.h), which has no additional overhead  * and is used instead of the internal data area; this is done when  * at least MINCLSIZE of data must be stored.  */
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

begin_comment
comment|/*  * Maximum number of allocatable counters for external buffers. This  * ensures enough VM address space for the allocation of counters  * in the extreme case where all possible external buffers are allocated.  *  * Note: When new types of external storage are allocated, EXT_COUNTERS  * 	 must be tuned accordingly. Practically, this isn't a big deal  *	 as each counter is only a word long, so we can fit  *	 (PAGE_SIZE / length of word) counters in a single page.  *  * XXX: Must increase this if using any of if_ti, if_wb, if_sk drivers,  *	or any other drivers which may manage their own buffers and  *	eventually attach them to mbufs.   */
end_comment

begin_define
define|#
directive|define
name|EXT_COUNTERS
value|(nmbclusters + nsfbufs)
end_define

begin_comment
comment|/*  * Macros for type conversion  * mtod(m, t) -	convert mbuf pointer to data pointer of correct type  * dtom(x) -	convert data pointer within mbuf to mbuf pointer (XXX)  */
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
comment|/* header at beginning of each mbuf: */
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
comment|/* record/packet header in first mbuf of chain; valid if M_PKTHDR set */
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
comment|/* description of external storage mapped into mbuf, valid if M_EXT set */
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
argument_list|(
argument|*ext_free
argument_list|)
comment|/* free routine if not the usual */
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|ext_args
decl_stmt|;
comment|/* optional argument pointer */
name|u_int
name|ext_size
decl_stmt|;
comment|/* size of buffer, for ext_free */
name|union
name|mext_refcnt
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
comment|/* mbuf flags */
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
comment|/* mbuf pkthdr flags, also in m_flags */
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
comment|/* external buffer types: identify ext_buf type */
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
comment|/* flags copied when copying m_pkthdr */
end_comment

begin_define
define|#
directive|define
name|M_COPYFLAGS
value|(M_PKTHDR|M_EOR|M_PROTO1|M_PROTO1|M_PROTO2|M_PROTO3 | \ 			    M_PROTO4|M_PROTO5|M_BCAST|M_MCAST|M_FRAG|M_RDONLY)
end_define

begin_comment
comment|/* flags indicating hw checksum support and sw checksum requirements */
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
comment|/* mbuf types */
end_comment

begin_define
define|#
directive|define
name|MT_FREE
value|0
end_define

begin_comment
comment|/* should be on free list */
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
comment|/*  * mbuf statistics  */
end_comment

begin_struct
struct|struct
name|mbstat
block|{
name|u_long
name|m_mbufs
decl_stmt|;
comment|/* # mbufs obtained from page pool */
name|u_long
name|m_clusters
decl_stmt|;
comment|/* # clusters obtained from page pool */
name|u_long
name|m_clfree
decl_stmt|;
comment|/* # clusters on freelist (cache) */
name|u_long
name|m_refcnt
decl_stmt|;
comment|/* # ref counters obtained from page pool */
name|u_long
name|m_refree
decl_stmt|;
comment|/* # ref counters on freelist (cache) */
name|u_long
name|m_spare
decl_stmt|;
comment|/* spare field */
name|u_long
name|m_drops
decl_stmt|;
comment|/* times failed to find space */
name|u_long
name|m_wait
decl_stmt|;
comment|/* times waited for space */
name|u_long
name|m_drain
decl_stmt|;
comment|/* times drained protocols for space */
name|u_long
name|m_mcfail
decl_stmt|;
comment|/* times m_copym failed */
name|u_long
name|m_mpfail
decl_stmt|;
comment|/* times m_pullup failed */
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
block|}
struct|;
end_struct

begin_comment
comment|/* flags to m_get/MGET */
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
name|M_WAIT
value|0
end_define

begin_comment
comment|/*  * Normal mbuf clusters are normally treated as character arrays  * after allocation, but use the first word of the buffer as a free list  * pointer while on the free list.  */
end_comment

begin_union
union|union
name|mcluster
block|{
name|union
name|mcluster
modifier|*
name|mcl_next
decl_stmt|;
name|char
name|mcl_buf
index|[
name|MCLBYTES
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * The m_ext object reference counter structure.  */
end_comment

begin_union
union|union
name|mext_refcnt
block|{
name|union
name|mext_refcnt
modifier|*
name|next_ref
decl_stmt|;
name|u_int
name|refcnt
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * free list header definitions: mbffree_lst, mclfree_lst, mcntfree_lst  */
end_comment

begin_struct
struct|struct
name|mbffree_lst
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mtx
name|m_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mclfree_lst
block|{
name|union
name|mcluster
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mtx
name|m_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcntfree_lst
block|{
name|union
name|mext_refcnt
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mtx
name|m_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Wake up the next instance (if any) of a sleeping allocation - which is  * waiting for a {cluster, mbuf} to be freed.  *  * Must be called with the appropriate mutex held.  */
end_comment

begin_define
define|#
directive|define
name|MBWAKEUP
parameter_list|(
name|m_wid
parameter_list|)
value|do {						\ 	if ((m_wid)) {							\ 		m_wid--;						\ 		wakeup_one(&(m_wid)); 					\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * mbuf external reference count management macros:  *  * MEXT_IS_REF(m): true if (m) is not the only mbuf referencing  *     the external buffer ext_buf  * MEXT_REM_REF(m): remove reference to m_ext object  * MEXT_ADD_REF(m): add reference to m_ext object already  *     referred to by (m)  * MEXT_INIT_REF(m): allocate and initialize an external  *     object reference counter for (m)  */
end_comment

begin_define
define|#
directive|define
name|MEXT_IS_REF
parameter_list|(
name|m
parameter_list|)
value|((m)->m_ext.ref_cnt->refcnt> 1)
end_define

begin_define
define|#
directive|define
name|MEXT_REM_REF
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	KASSERT((m)->m_ext.ref_cnt->refcnt> 0, ("m_ext refcnt< 0"));	\ 	atomic_subtract_int(&((m)->m_ext.ref_cnt->refcnt), 1);		\ } while(0)
end_define

begin_define
define|#
directive|define
name|MEXT_ADD_REF
parameter_list|(
name|m
parameter_list|)
value|atomic_add_int(&((m)->m_ext.ref_cnt->refcnt), 1)
end_define

begin_define
define|#
directive|define
name|_MEXT_ALLOC_CNT
parameter_list|(
name|m_cnt
parameter_list|,
name|how
parameter_list|)
value|do {				\ 	union mext_refcnt *__mcnt;					\ 									\ 	mtx_enter(&mcntfree.m_mtx, MTX_DEF);				\ 	if (mcntfree.m_head == NULL)					\ 		m_alloc_ref(1, (how));					\ 	__mcnt = mcntfree.m_head;					\ 	if (__mcnt != NULL) {						\ 		mcntfree.m_head = __mcnt->next_ref;			\ 		mbstat.m_refree--;					\ 		__mcnt->refcnt = 0;					\ 	}								\ 	mtx_exit(&mcntfree.m_mtx, MTX_DEF);				\ 	(m_cnt) = __mcnt;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_MEXT_DEALLOC_CNT
parameter_list|(
name|m_cnt
parameter_list|)
value|do {					\ 	union mext_refcnt *__mcnt = (m_cnt);				\ 									\ 	mtx_enter(&mcntfree.m_mtx, MTX_DEF);				\ 	__mcnt->next_ref = mcntfree.m_head;				\ 	mcntfree.m_head = __mcnt;					\ 	mbstat.m_refree++;						\ 	mtx_exit(&mcntfree.m_mtx, MTX_DEF);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|MEXT_INIT_REF
parameter_list|(
name|m
parameter_list|,
name|how
parameter_list|)
value|do {					\ 	struct mbuf *__mmm = (m);					\ 									\ 	_MEXT_ALLOC_CNT(__mmm->m_ext.ref_cnt, (how));			\ 	if (__mmm->m_ext.ref_cnt != NULL)				\ 		MEXT_ADD_REF(__mmm);					\ } while (0)
end_define

begin_comment
comment|/*  * mbuf allocation/deallocation macros:  *  *	MGET(struct mbuf *m, int how, int type)  * allocates an mbuf and initializes it to contain internal data.  *  *	MGETHDR(struct mbuf *m, int how, int type)  * allocates an mbuf and initializes it to contain a packet header  * and internal data.  */
end_comment

begin_comment
comment|/*  * Lower-level macros for MGET(HDR)... Not to be used outside the  * subsystem ("non-exportable" macro names are prepended with "_").  */
end_comment

begin_define
define|#
directive|define
name|_MGET_SETUP
parameter_list|(
name|m_set
parameter_list|,
name|m_set_type
parameter_list|)
value|do {				\ 	(m_set)->m_type = (m_set_type);					\ 	(m_set)->m_next = NULL;						\ 	(m_set)->m_nextpkt = NULL;					\ 	(m_set)->m_data = (m_set)->m_dat;				\ 	(m_set)->m_flags = 0;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_MGET
parameter_list|(
name|m_mget
parameter_list|,
name|m_get_how
parameter_list|)
value|do {					\ 	if (mmbfree.m_head == NULL)					\ 		m_mballoc(1, (m_get_how));				\ 	(m_mget) = mmbfree.m_head;					\ 	if ((m_mget) != NULL) {						\ 		mmbfree.m_head = (m_mget)->m_next;			\ 		mbtypes[MT_FREE]--;					\ 	} else {							\ 		if ((m_get_how) == M_WAIT)				\ 			(m_mget) = m_mballoc_wait();			\ 	}								\ } while (0)
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
value|do {						\ 	struct mbuf *_mm;						\ 	int _mhow = (how);						\ 	int _mtype = (type);						\ 									\ 	mtx_enter(&mmbfree.m_mtx, MTX_DEF);				\ 	_MGET(_mm, _mhow);						\ 	if (_mm != NULL) {						\ 		mbtypes[_mtype]++;					\ 		mtx_exit(&mmbfree.m_mtx, MTX_DEF);			\ 		_MGET_SETUP(_mm, _mtype);				\ 	} else								\ 		mtx_exit(&mmbfree.m_mtx, MTX_DEF);			\ 	(m) = _mm;							\ } while (0)
end_define

begin_define
define|#
directive|define
name|_MGETHDR_SETUP
parameter_list|(
name|m_set
parameter_list|,
name|m_set_type
parameter_list|)
value|do {				\ 	(m_set)->m_type = (m_set_type);					\ 	(m_set)->m_next = NULL;						\ 	(m_set)->m_nextpkt = NULL;					\ 	(m_set)->m_data = (m_set)->m_pktdat;				\ 	(m_set)->m_flags = M_PKTHDR;					\ 	(m_set)->m_pkthdr.rcvif = NULL;					\ 	(m_set)->m_pkthdr.csum_flags = 0;				\ 	(m_set)->m_pkthdr.aux = NULL;					\ } while (0)
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
value|do {					\ 	struct mbuf *_mm;						\ 	int _mhow = (how);						\ 	int _mtype = (type);						\ 									\ 	mtx_enter(&mmbfree.m_mtx, MTX_DEF);				\ 	_MGET(_mm, _mhow);						\ 	if (_mm != NULL) {						\ 		mbtypes[_mtype]++;					\ 		mtx_exit(&mmbfree.m_mtx, MTX_DEF);			\ 		_MGETHDR_SETUP(_mm, _mtype);				\ 	} else								\ 		mtx_exit(&mmbfree.m_mtx, MTX_DEF);			\ 	(m) = _mm;							\ } while (0)
end_define

begin_comment
comment|/*  * mbuf external storage macros:  *  *   MCLGET allocates and refers an mcluster to an mbuf  *   MEXTADD sets up pre-allocated external storage and refers to mbuf  *   MEXTFREE removes reference to external object and frees it if  *       necessary  */
end_comment

begin_define
define|#
directive|define
name|_MCLALLOC
parameter_list|(
name|p
parameter_list|,
name|how
parameter_list|)
value|do {						\ 	caddr_t _mp;							\ 	int _mhow = (how);						\ 									\ 	if (mclfree.m_head == NULL)					\ 		m_clalloc(1, _mhow);					\ 	_mp = (caddr_t)mclfree.m_head;					\ 	if (_mp != NULL) {						\ 		mbstat.m_clfree--;					\ 		mclfree.m_head = ((union mcluster *)_mp)->mcl_next;	\ 	} else {							\ 		if (_mhow == M_WAIT)					\ 			_mp = m_clalloc_wait();				\ 	}								\ 	(p) = _mp;							\ } while (0)
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
value|do {						\ 	struct mbuf *_mm = (m);						\ 									\ 	mtx_enter(&mclfree.m_mtx, MTX_DEF);				\ 	_MCLALLOC(_mm->m_ext.ext_buf, (how));				\ 	mtx_exit(&mclfree.m_mtx, MTX_DEF);				\ 	if (_mm->m_ext.ext_buf != NULL) {				\ 		MEXT_INIT_REF(_mm, (how));				\ 		if (_mm->m_ext.ref_cnt == NULL) {			\ 			_MCLFREE(_mm->m_ext.ext_buf);			\ 			_mm->m_ext.ext_buf = NULL;			\ 		} else {						\ 			_mm->m_data = _mm->m_ext.ext_buf;		\ 			_mm->m_flags |= M_EXT;				\ 			_mm->m_ext.ext_free = NULL;			\ 			_mm->m_ext.ext_args = NULL;			\ 			_mm->m_ext.ext_size = MCLBYTES;			\ 			_mm->m_ext.ext_type = EXT_CLUSTER;		\ 		}							\ 	}								\ } while (0)
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
value|do {		\ 	struct mbuf *_mm = (m);						\ 									\ 	MEXT_INIT_REF(_mm, M_WAIT);					\ 	if (_mm->m_ext.ref_cnt != NULL) {				\ 		_mm->m_flags |= (M_EXT | (flags));			\ 		_mm->m_ext.ext_buf = (caddr_t)(buf);			\ 		_mm->m_data = _mm->m_ext.ext_buf;			\ 		_mm->m_ext.ext_size = (size);				\ 		_mm->m_ext.ext_free = (free);				\ 		_mm->m_ext.ext_args = (args);				\ 		_mm->m_ext.ext_type = (type);				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|_MCLFREE
parameter_list|(
name|p
parameter_list|)
value|do {						\ 	union mcluster *_mp = (union mcluster *)(p);			\ 									\ 	mtx_enter(&mclfree.m_mtx, MTX_DEF);				\ 	_mp->mcl_next = mclfree.m_head;					\ 	mclfree.m_head = _mp;						\ 	mbstat.m_clfree++;						\ 	MBWAKEUP(m_clalloc_wid);					\ 	mtx_exit(&mclfree.m_mtx, MTX_DEF); 				\ } while (0)
end_define

begin_comment
comment|/* MEXTFREE:  * If the atomic_cmpset_int() returns 0, then we effectively do nothing  * in terms of "cleaning up" (freeing the ext buf and ref. counter) as  * this means that either there are still references, or another thread  * is taking care of the clean-up.  */
end_comment

begin_define
define|#
directive|define
name|MEXTFREE
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	struct mbuf *_mmm = (m);					\ 									\ 	MEXT_REM_REF(_mmm);						\ 	if (atomic_cmpset_int(&_mmm->m_ext.ref_cnt->refcnt, 0, 1)) {	\ 		if (_mmm->m_ext.ext_type != EXT_CLUSTER) {		\ 			(*(_mmm->m_ext.ext_free))(_mmm->m_ext.ext_buf,	\ 			    _mmm->m_ext.ext_args);			\ 		} else							\ 			_MCLFREE(_mmm->m_ext.ext_buf);			\ 		_MEXT_DEALLOC_CNT(_mmm->m_ext.ref_cnt);			\ 	}								\ 	_mmm->m_flags&= ~M_EXT;					\ } while (0)
end_define

begin_comment
comment|/*  * MFREE(struct mbuf *m, struct mbuf *n)  * Free a single mbuf and associated external storage.  * Place the successor, if any, in n.  */
end_comment

begin_define
define|#
directive|define
name|MFREE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|do {						\ 	struct mbuf *_mm = (m);						\ 									\ 	KASSERT(_mm->m_type != MT_FREE, ("freeing free mbuf"));		\ 	if (_mm->m_flags& M_EXT)					\ 		MEXTFREE(_mm);						\ 	mtx_enter(&mmbfree.m_mtx, MTX_DEF);				\ 	mbtypes[_mm->m_type]--;						\ 	_mm->m_type = MT_FREE;						\ 	mbtypes[MT_FREE]++;						\ 	(n) = _mm->m_next;						\ 	_mm->m_next = mmbfree.m_head;					\ 	mmbfree.m_head = _mm;						\ 	MBWAKEUP(m_mballoc_wid);					\ 	mtx_exit(&mmbfree.m_mtx, MTX_DEF); 				\ } while (0)
end_define

begin_comment
comment|/*  * M_WRITABLE(m)  * Evaluate TRUE if it's safe to write to the mbuf m's data region (this  * can be both the local data payload, or an external buffer area,  * depending on whether M_EXT is set).  */
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
comment|/*  * Copy mbuf pkthdr from "from" to "to".  * from must have M_PKTHDR set, and to must be empty.  * aux pointer will be moved to `to'.  */
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
value|do {					\ 	struct mbuf *_mfrom = (from);					\ 	struct mbuf *_mto = (to);					\ 									\ 	_mto->m_data = _mto->m_pktdat;					\ 	_mto->m_flags = _mfrom->m_flags& M_COPYFLAGS;			\ 	_mto->m_pkthdr = _mfrom->m_pkthdr;				\ 	_mfrom->m_pkthdr.aux = (struct mbuf *)NULL;			\ } while (0)
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
value|((m)->m_flags& M_EXT ?						\
comment|/* (m)->m_data - (m)->m_ext.ext_buf */
value|0 :			\ 	    (m)->m_flags& M_PKTHDR ? (m)->m_data - (m)->m_pktdat :	\ 	    (m)->m_data - (m)->m_dat)
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
comment|/*  * Arrange to prepend space of size plen to mbuf m.  * If a new mbuf must be allocated, how specifies whether to wait.  * If how is M_DONTWAIT and allocation fails, the original mbuf chain  * is freed and m is set to NULL.  */
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
comment|/*  * change mbuf to new type  */
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
value|do {						\ 	struct mbuf *_mm = (m);						\ 	int _mt = (t);							\ 									\ 	atomic_subtract_long(&mbtypes[_mm->m_type], 1);			\ 	atomic_add_long(&mbtypes[_mt], 1);				\ 	_mm->m_type = (_mt);						\ } while (0)
end_define

begin_comment
comment|/* length to m_copy to copy all */
end_comment

begin_define
define|#
directive|define
name|M_COPYALL
value|1000000000
end_define

begin_comment
comment|/* compatibility with 4.3 */
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
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_long
name|m_clalloc_wid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mbuf cluster wait count */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|m_mballoc_wid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mbuf wait count */
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
name|int
name|max_hdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* largest link+protocol header */
end_comment

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
name|struct
name|mbstat
name|mbstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|mbtypes
index|[
name|MT_NTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per-type mbuf allocations */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mbuf_wait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mbuf sleep time */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mbuf
modifier|*
name|mbutl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual address of mclusters */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mclfree_lst
name|mclfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mbffree_lst
name|mmbfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mcntfree_lst
name|mcntfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nmbclusters
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nmbufs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nsfbufs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_adj
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|m_alloc_ref
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_cat
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|m_clalloc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|m_clalloc_wait
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_copyback
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_copydata
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_copym
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_copypacket
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_devget
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|ifnet
operator|*
operator|,
name|void
argument_list|(
operator|*
name|copy
argument_list|)
argument_list|(
name|char
operator|*
argument_list|,
name|caddr_t
argument_list|,
name|u_int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_dup
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_free
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_freem
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_get
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_getclr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_gethdr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|m_mballoc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_mballoc_wait
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_prepend
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_pulldown
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_print
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|mbuf
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_pullup
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_split
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_aux_add
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_aux_find
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|m_aux_delete
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

