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
file|<sys/queue.h>
end_include

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
comment|/*  * Macros for type conversion:  * mtod(m, t)	-- Convert mbuf pointer to data pointer of correct type.  * dtom(x)	-- Convert data pointer within mbuf to mbuf pointer (XXX).  * mtocl(x) -	convert pointer within cluster to cluster index #  * cltom(x) -	convert cluster # to ptr to beginning of cluster  */
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

begin_define
define|#
directive|define
name|mtocl
parameter_list|(
name|x
parameter_list|)
value|(((uintptr_t)(x) - (uintptr_t)mbutl)>> MCLSHIFT)
end_define

begin_define
define|#
directive|define
name|cltom
parameter_list|(
name|x
parameter_list|)
value|((caddr_t)((uintptr_t)mbutl + \ 			    ((uintptr_t)(x)<< MCLSHIFT)))
end_define

begin_define
define|#
directive|define
name|mcl_valid
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)>= (uintptr_t)mbutl&&		\ 			 (uintptr_t)(x)< (uintptr_t)mbutltop)
end_define

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
name|u_int
parameter_list|)
function_decl|;
name|u_int
name|ext_size
decl_stmt|;
comment|/* size of buffer, for ext_free */
name|void
function_decl|(
modifier|*
name|ext_ref
function_decl|)
comment|/* add a reference to the ext object */
parameter_list|(
name|caddr_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
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
name|M_PROTO1
value|0x0008
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO2
value|0x0010
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO3
value|0x0020
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO4
value|0x0040
end_define

begin_comment
comment|/* protocol-specific */
end_comment

begin_define
define|#
directive|define
name|M_PROTO5
value|0x0080
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
value|0x0100
end_define

begin_comment
comment|/* send/received as link-level broadcast */
end_comment

begin_define
define|#
directive|define
name|M_MCAST
value|0x0200
end_define

begin_comment
comment|/* send/received as link-level multicast */
end_comment

begin_define
define|#
directive|define
name|M_FRAG
value|0x0400
end_define

begin_comment
comment|/* packet is a fragment of a larger packet */
end_comment

begin_define
define|#
directive|define
name|M_FIRSTFRAG
value|0x0800
end_define

begin_comment
comment|/* packet is first fragment */
end_comment

begin_define
define|#
directive|define
name|M_LASTFRAG
value|0x1000
end_define

begin_comment
comment|/* packet is last fragment */
end_comment

begin_comment
comment|/*  * Flags copied when copying m_pkthdr.  */
end_comment

begin_define
define|#
directive|define
name|M_COPYFLAGS
value|(M_PKTHDR|M_EOR|M_PROTO1|M_PROTO1|M_PROTO2|M_PROTO3 | \ 			    M_PROTO4|M_PROTO5|M_BCAST|M_MCAST|M_FRAG | \ 			    M_FIRSTFRAG|M_LASTFRAG)
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
name|MT_TAG
value|13
end_define

begin_comment
comment|/* volatile metadata associated to pkts */
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

begin_comment
comment|/*  * General mbuf allocator statistics structure.  */
end_comment

begin_struct
struct|struct
name|mbstat
block|{
name|u_long
name|m_mbufs
decl_stmt|;
comment|/* mbufs obtained from page pool */
name|u_long
name|m_clusters
decl_stmt|;
comment|/* clusters obtained from page pool */
name|u_long
name|m_spare
decl_stmt|;
comment|/* spare field */
name|u_long
name|m_clfree
decl_stmt|;
comment|/* free clusters */
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
comment|/*  * Flags specifying how an allocation should be made.  */
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
comment|/* Freelists:  *  * Normal mbuf clusters are normally treated as character arrays  * after allocation, but use the first word of the buffer as a free list  * pointer while on the free list.  */
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
comment|/*  * These are identifying numbers passed to the m_mballoc_wait function,  * allowing us to determine whether the call came from an MGETHDR or  * an MGET.  */
end_comment

begin_define
define|#
directive|define
name|MGETHDR_C
value|1
end_define

begin_define
define|#
directive|define
name|MGET_C
value|2
end_define

begin_comment
comment|/*  * Wake up the next instance (if any) of m_mballoc_wait() which is  * waiting for an mbuf to be freed.  This should be called at splimp().  *  * XXX: If there is another free mbuf, this routine will be called [again]  * from the m_mballoc_wait routine in order to wake another sleep instance.  */
end_comment

begin_define
define|#
directive|define
name|MMBWAKEUP
parameter_list|()
value|do {						\ 	if (m_mballoc_wid) {						\ 		m_mballoc_wid--;					\ 		wakeup_one(&m_mballoc_wid); 				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Same as above, but for mbuf cluster(s).  */
end_comment

begin_define
define|#
directive|define
name|MCLWAKEUP
parameter_list|()
value|do {						\ 	if (m_clalloc_wid) {						\ 		m_clalloc_wid--;					\ 		wakeup_one(&m_clalloc_wid);				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * mbuf utility macros:  *  *	MBUFLOCK(code)  * prevents a section of code from from being interrupted by network  * drivers.  */
end_comment

begin_define
define|#
directive|define
name|MBUFLOCK
parameter_list|(
name|code
parameter_list|)
value|do {						\ 	int _ms = splimp();						\ 									\ 	{ code }							\ 	splx(_ms);							\ } while (0)
end_define

begin_comment
comment|/*  * mbuf allocation/deallocation macros:  *  *	MGET(struct mbuf *m, int how, int type)  * allocates an mbuf and initializes it to contain internal data.  *  *	MGETHDR(struct mbuf *m, int how, int type)  * allocates an mbuf and initializes it to contain a packet header  * and internal data.  */
end_comment

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
value|do {						\ 	struct mbuf *_mm;						\ 	int _mhow = (how);						\ 	int _mtype = (type);						\ 	int _ms = splimp();						\ 									\ 	if (mmbfree == NULL)						\ 		(void)m_mballoc(1, _mhow);				\ 	_mm = mmbfree;							\ 	if (_mm != NULL) {						\ 		mmbfree = _mm->m_next;					\ 		mbtypes[MT_FREE]--;					\ 		_mm->m_type = _mtype;					\ 		mbtypes[_mtype]++;					\ 		_mm->m_next = NULL;					\ 		_mm->m_nextpkt = NULL;					\ 		_mm->m_data = _mm->m_dat;				\ 		_mm->m_flags = 0;					\ 		(m) = _mm;						\ 		splx(_ms);						\ 	} else {							\ 		splx(_ms);						\ 		_mm = m_retry(_mhow, _mtype);				\ 		if (_mm == NULL&& _mhow == M_WAIT)			\ 			(m) = m_mballoc_wait(MGET_C, _mtype);		\ 		else							\ 			(m) = _mm;					\ 	}								\ } while (0)
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
value|do {					\ 	struct mbuf *_mm;						\ 	int _mhow = (how);						\ 	int _mtype = (type);						\ 	int _ms = splimp();						\ 									\ 	if (mmbfree == NULL)						\ 		(void)m_mballoc(1, _mhow);				\ 	_mm = mmbfree;							\ 	if (_mm != NULL) {						\ 		mmbfree = _mm->m_next;					\ 		mbtypes[MT_FREE]--;					\ 		_mm->m_type = _mtype;					\ 		mbtypes[_mtype]++;					\ 		_mm->m_next = NULL;					\ 		_mm->m_nextpkt = NULL;					\ 		_mm->m_data = _mm->m_pktdat;				\ 		_mm->m_flags = M_PKTHDR;				\ 		_mm->m_pkthdr.rcvif = NULL;				\ 		SLIST_INIT(&_mm->m_pkthdr.tags); 			\ 		_mm->m_pkthdr.csum_flags = 0;				\ 		(m) = _mm;						\ 		splx(_ms);						\ 	} else {							\ 		splx(_ms);						\ 		_mm = m_retryhdr(_mhow, _mtype);			\ 		if (_mm == NULL&& _mhow == M_WAIT)			\ 			(m) = m_mballoc_wait(MGETHDR_C, _mtype);	\ 		else							\ 			(m) = _mm;					\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Mbuf cluster macros.  * MCLALLOC(caddr_t p, int how) allocates an mbuf cluster.  * MCLGET adds such clusters to a normal mbuf;  * the flag M_EXT is set upon success.  * MCLFREE releases a reference to a cluster allocated by MCLALLOC,  * freeing the cluster if the reference count has reached 0.  */
end_comment

begin_define
define|#
directive|define
name|MCLALLOC
parameter_list|(
name|p
parameter_list|,
name|how
parameter_list|)
value|do {						\ 	caddr_t _mp;							\ 	int _mhow = (how);						\ 	int _ms = splimp();						\ 									\ 	if (mclfree == NULL)						\ 		(void)m_clalloc(1, _mhow);				\ 	_mp = (caddr_t)mclfree;						\ 	if (_mp != NULL) {						\ 		KASSERT(mcl_valid(_mp),					\ 			("MCLALLOC junk pointer: %x< %x< %x.",	\ 			(uintptr_t)mbutl, (uintptr_t)_mp,		\ 			(uintptr_t)mbutltop));				\ 		KASSERT(mclrefcnt[mtocl(_mp)] == 0,			\ 			("free cluster with refcount %d.",		\ 			mclrefcnt[mtocl(_mp)]));			\ 		mclrefcnt[mtocl(_mp)]++;				\ 		mbstat.m_clfree--;					\ 		mclfree = ((union mcluster *)_mp)->mcl_next;		\ 		(p) = _mp;						\ 		splx(_ms);						\ 	} else {							\ 		splx(_ms);						\ 		if (_mhow == M_WAIT)					\ 			(p) = m_clalloc_wait();				\ 		else							\ 			(p) = NULL;					\ 	}								\ } while (0)
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
value|do {						\ 	struct mbuf *_mm = (m);						\ 									\ 	MCLALLOC(_mm->m_ext.ext_buf, (how));				\ 	if (_mm->m_ext.ext_buf != NULL) {				\ 		_mm->m_data = _mm->m_ext.ext_buf;			\ 		_mm->m_flags |= M_EXT;					\ 		_mm->m_ext.ext_free = NULL;				\ 		_mm->m_ext.ext_ref = NULL;				\ 		_mm->m_ext.ext_size = MCLBYTES;				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MCLFREE1
parameter_list|(
name|p
parameter_list|)
value|do {						\ 	union mcluster *_mp = (union mcluster *)(p);			\ 									\ 	KASSERT(mcl_valid(_mp),						\ 		("MCLFREE1 junk pointer: %x< %x< %x.",		\ 		(uintptr_t)mbutl, (uintptr_t)_mp,			\ 		(uintptr_t)mbutltop));					\ 	KASSERT(mclrefcnt[mtocl(_mp)]> 0,				\ 		("freeing free cluster, refcount: %d.",			\ 		mclrefcnt[mtocl(_mp)]));				\ 	if (--mclrefcnt[mtocl(_mp)] == 0) {				\ 		_mp->mcl_next = mclfree;				\ 		mclfree = _mp;						\ 		mbstat.m_clfree++;					\ 		MCLWAKEUP();						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MCLFREE
parameter_list|(
name|p
parameter_list|)
value|MBUFLOCK(						\ 	MCLFREE1(p);							\ )
end_define

begin_define
define|#
directive|define
name|MEXTFREE1
parameter_list|(
name|m
parameter_list|)
value|do {						\ 		struct mbuf *_mm = (m);					\ 									\ 		if (_mm->m_ext.ext_free != NULL)			\ 			(*_mm->m_ext.ext_free)(_mm->m_ext.ext_buf,	\ 		    	    _mm->m_ext.ext_size);			\ 		else							\ 			MCLFREE1(_mm->m_ext.ext_buf);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|MEXTFREE
parameter_list|(
name|m
parameter_list|)
value|MBUFLOCK(						\ 	MEXTFREE1(m);							\ )
end_define

begin_comment
comment|/*  * NB: M_COPY_PKTHDR is deprecated; use either M_MOVE_PKTHDR  *     or m_dup_pkthdr.  */
end_comment

begin_comment
comment|/*  * Move mbuf pkthdr from "from" to "to".  * from should have M_PKTHDR set, and to must be empty.  * from no longer has a pkthdr after this operation.  */
end_comment

begin_define
define|#
directive|define
name|M_MOVE_PKTHDR
parameter_list|(
name|_to
parameter_list|,
name|_from
parameter_list|)
value|m_move_pkthdr((_to), (_from))
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
comment|/*  * Check if we can write to an mbuf.  */
end_comment

begin_define
define|#
directive|define
name|M_EXT_WRITABLE
parameter_list|(
name|m
parameter_list|)
define|\
value|((m)->m_ext.ext_free == NULL&& mclrefcnt[mtocl((m)->m_ext.ext_buf)] == 1)
end_define

begin_define
define|#
directive|define
name|M_WRITABLE
parameter_list|(
name|m
parameter_list|)
value|(!((m)->m_flags& M_EXT) || \     M_EXT_WRITABLE(m) )
end_define

begin_comment
comment|/*  * Compute the amount of space available  * before the current start of data in an mbuf.  *  * The M_WRITABLE() is a temporary, conservative safety measure: the burden  * of checking writability of the mbuf data area rests solely with the caller.  */
end_comment

begin_define
define|#
directive|define
name|M_LEADINGSPACE
parameter_list|(
name|m
parameter_list|)
define|\
value|((m)->m_flags& M_EXT ?						\ 	    (M_EXT_WRITABLE(m) ? (m)->m_data - (m)->m_ext.ext_buf : 0):	\ 	    (m)->m_flags& M_PKTHDR ? (m)->m_data - (m)->m_pktdat :	\ 	    (m)->m_data - (m)->m_dat)
end_define

begin_comment
comment|/*  * Compute the amount of space available  * after the end of data in an mbuf.  *  * The M_WRITABLE() is a temporary, conservative safety measure: the burden  * of checking writability of the mbuf data area rests solely with the caller.  */
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
comment|/* change mbuf to new type */
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
value|do {						\ 	struct mbuf *_mm = (m);						\ 	int _mt = (t);							\ 	int _ms = splimp();						\ 									\ 	mbtypes[_mm->m_type]--;						\ 	mbtypes[_mt]++;							\ 	splx(_ms);							\ 	_mm->m_type = (_mt);						\ } while (0)
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int
name|m_clalloc_wid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mbuf cluster wait count */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
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
name|mbuf
modifier|*
name|mbutltop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* highest address of mclusters */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mclrefcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cluster reference counts */
end_comment

begin_decl_stmt
specifier|extern
name|union
name|mcluster
modifier|*
name|mclfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mbuf
modifier|*
name|mmbfree
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
name|int
name|m_clalloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|m_clalloc_wait
parameter_list|(
name|void
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
name|m_getcl
parameter_list|(
name|int
name|how
parameter_list|,
name|short
name|type
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|m_getclr
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
name|m_mballoc
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
name|m_mballoc_wait
parameter_list|(
name|int
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
name|m_retry
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
name|m_retryhdr
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

begin_comment
comment|/*  * Packets may have annotations attached by affixing a list  * of "packet tags" to the pkthdr structure.  Packet tags are  * dynamically allocated semi-opaque data structures that have  * a fixed header (struct m_tag) that specifies the size of the  * memory block and a<cookie,type> pair that identifies it.  * The cookie is a 32-bit unique unsigned value used to identify  * a module or ABI.  By convention this value is chose as the  * date+time that the module is created, expressed as the number of  * seconds since the epoch (e.g. using date -u +'%s').  The type value  * is an ABI/module-specific value that identifies a particular annotation  * and is private to the module.  For compatibility with systems  * like openbsd that define packet tags w/o an ABI/module cookie,  * the value PACKET_ABI_COMPAT is used to implement m_tag_get and  * m_tag_find compatibility shim functions and several tag types are  * defined below.  Users that do not require compatibility should use  * a private cookie value so that packet tag-related definitions  * can be maintained privately.  *  * Note that the packet tag returned by m_tag_allocate has the default  * memory alignment implemented by malloc.  To reference private data  * one can use a construct like:  *  *	struct m_tag *mtag = m_tag_allocate(...);  *	struct foo *p = (struct foo *)(mtag+1);  *  * if the alignment of struct m_tag is sufficient for referencing members  * of struct foo.  Otherwise it is necessary to embed struct m_tag within  * the private data structure to insure proper alignment; e.g.  *  *	struct foo {  *		struct m_tag	tag;  *		...  *	};  *	struct foo *p = (struct foo *) m_tag_allocate(...);  *	struct m_tag *mtag =&p->tag;  */
end_comment

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
comment|/* Packet tag for use with PACKET_ABI_COMPAT */
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

begin_comment
comment|/*  * As a temporary and low impact solution to replace the even uglier  * approach used so far in some parts of the network stack (which relies  * on global variables), packet tag-like annotations are stored in MT_TAG  * mbufs (or lookalikes) prepended to the actual mbuf chain.  *  *	m_type	= MT_TAG  *	m_flags = m_tag_id  *	m_next	= next buffer in chain.  *  * BE VERY CAREFUL not to pass these blocks to the mbuf handling routines.  */
end_comment

begin_define
define|#
directive|define
name|_m_tag_id
value|m_hdr.mh_flags
end_define

begin_comment
comment|/* Packet tags used in the FreeBSD network stack */
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
name|PACKET_TAG_IPFW
value|16
end_define

begin_comment
comment|/* ipfw classification */
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

begin_comment
comment|/* Packet tag routines */
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
name|m_tag_free
parameter_list|(
name|struct
name|m_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_tag_prepend
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
name|m_tag_unlink
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
name|m_tag_init
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|m_tag
modifier|*
name|m_tag_first
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|m_tag
modifier|*
name|m_tag_next
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

begin_comment
comment|/* these are for openbsd compatibility */
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

