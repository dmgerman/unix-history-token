begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mbuf.h	8.5 (Berkeley) 2/19/95  * $Id: mbuf.h,v 1.24 1997/10/10 18:15:46 phk Exp $  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|M_WAITOK
end_ifndef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mbufs are of a single size, MSIZE (machine/machparam.h), which  * includes overhead.  An mbuf may add a single "mbuf cluster" of size  * MCLBYTES (also in machine/machparam.h), which has no additional overhead  * and is used instead of the internal data area; this is done when  * at least MINCLSIZE of data must be stored.  */
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
value|(MHLEN + MLEN)
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
comment|/*  * Macros for type conversion  * mtod(m,t) -	convert mbuf pointer to data pointer of correct type  * dtom(x) -	convert data pointer within mbuf to mbuf pointer (XXX)  * mtocl(x) -	convert pointer within cluster to cluster index #  * cltom(x) -	convert cluster # to ptr to beginning of cluster  */
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
value|((struct mbuf *)((long)(x)& ~(MSIZE-1)))
end_define

begin_define
define|#
directive|define
name|mtocl
parameter_list|(
name|x
parameter_list|)
value|(((u_long)(x) - (u_long)mbutl)>> MCLSHIFT)
end_define

begin_define
define|#
directive|define
name|cltom
parameter_list|(
name|x
parameter_list|)
value|((caddr_t)((u_long)mbutl + ((u_long)(x)<< MCLSHIFT)))
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
name|u_int
operator|)
argument_list|)
expr_stmt|;
name|u_int
name|ext_size
decl_stmt|;
comment|/* size of buffer, for ext_free */
name|void
argument_list|(
argument|*ext_ref
argument_list|)
comment|/* add a reference to the ext object */
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
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
name|M_PROTO1
value|0x0008
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

begin_comment
comment|/* flags copied when copying m_pkthdr */
end_comment

begin_define
define|#
directive|define
name|M_COPYFLAGS
value|(M_PKTHDR|M_EOR|M_PROTO1|M_BCAST|M_MCAST)
end_define

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

begin_comment
comment|/*efine	MT_SOCKET	3*/
end_comment

begin_comment
comment|/* socket structure */
end_comment

begin_comment
comment|/*efine	MT_PCB		4*/
end_comment

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

begin_comment
comment|/*efine	MT_HTABLE	6*/
end_comment

begin_comment
comment|/* IMP host tables */
end_comment

begin_comment
comment|/*efine	MT_ATABLE	7*/
end_comment

begin_comment
comment|/* address resolution tables */
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
name|MT_SOOPTS
value|10
end_define

begin_comment
comment|/* socket options */
end_comment

begin_define
define|#
directive|define
name|MT_FTABLE
value|11
end_define

begin_comment
comment|/* fragment reassembly header */
end_comment

begin_comment
comment|/*efine	MT_RIGHTS	12*/
end_comment

begin_comment
comment|/* access rights */
end_comment

begin_comment
comment|/*efine	MT_IFADDR	13*/
end_comment

begin_comment
comment|/* interface address */
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

begin_comment
comment|/* flags to m_get/MGET */
end_comment

begin_define
define|#
directive|define
name|M_DONTWAIT
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|M_WAIT
value|M_WAITOK
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
comment|/*  * mbuf utility macros:  *  *	MBUFLOCK(code)  * prevents a section of code from from being interrupted by network  * drivers.  */
end_comment

begin_define
define|#
directive|define
name|MBUFLOCK
parameter_list|(
name|code
parameter_list|)
define|\
value|{ int ms = splimp(); \ 	  { code } \ 	  splx(ms); \ 	}
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
value|{ \ 	  int _ms = splimp(); \ 	  if (mmbfree == 0) \ 		(void)m_mballoc(1, (how)); \ 	  if (((m) = mmbfree) != 0) { \ 		mmbfree = (m)->m_next; \ 		mbstat.m_mtypes[MT_FREE]--; \ 		(m)->m_type = (type); \ 		mbstat.m_mtypes[type]++; \ 		(m)->m_next = (struct mbuf *)NULL; \ 		(m)->m_nextpkt = (struct mbuf *)NULL; \ 		(m)->m_data = (m)->m_dat; \ 		(m)->m_flags = 0; \ 		splx(_ms); \ 	} else { \ 		splx(_ms); \ 		(m) = m_retry((how), (type)); \ 	} \ }
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
value|{ \ 	  int _ms = splimp(); \ 	  if (mmbfree == 0) \ 		(void)m_mballoc(1, (how)); \ 	  if (((m) = mmbfree) != 0) { \ 		mmbfree = (m)->m_next; \ 		mbstat.m_mtypes[MT_FREE]--; \ 		(m)->m_type = (type); \ 		mbstat.m_mtypes[type]++; \ 		(m)->m_next = (struct mbuf *)NULL; \ 		(m)->m_nextpkt = (struct mbuf *)NULL; \ 		(m)->m_data = (m)->m_pktdat; \ 		(m)->m_flags = M_PKTHDR; \ 		splx(_ms); \ 	} else { \ 		splx(_ms); \ 		(m) = m_retryhdr((how), (type)); \ 	} \ }
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
define|\
value|MBUFLOCK( \ 	  if (mclfree == 0) \ 		(void)m_clalloc(1, (how)); \ 	  if (((p) = (caddr_t)mclfree) != 0) { \ 		++mclrefcnt[mtocl(p)]; \ 		mbstat.m_clfree--; \ 		mclfree = ((union mcluster *)(p))->mcl_next; \ 	  } \ 	)
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
define|\
value|{ MCLALLOC((m)->m_ext.ext_buf, (how)); \ 	  if ((m)->m_ext.ext_buf != NULL) { \ 		(m)->m_data = (m)->m_ext.ext_buf; \ 		(m)->m_flags |= M_EXT; \ 		(m)->m_ext.ext_free = NULL;  \ 		(m)->m_ext.ext_ref = NULL;  \ 		(m)->m_ext.ext_size = MCLBYTES;  \ 	  } \ 	}
end_define

begin_define
define|#
directive|define
name|MCLFREE
parameter_list|(
name|p
parameter_list|)
define|\
value|MBUFLOCK ( \ 	  if (--mclrefcnt[mtocl(p)] == 0) { \ 		((union mcluster *)(p))->mcl_next = mclfree; \ 		mclfree = (union mcluster *)(p); \ 		mbstat.m_clfree++; \ 	  } \ 	)
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
define|\
value|MBUFLOCK(  \ 	  mbstat.m_mtypes[(m)->m_type]--; \ 	  if ((m)->m_flags& M_EXT) { \ 		if ((m)->m_ext.ext_free) \ 			(*((m)->m_ext.ext_free))((m)->m_ext.ext_buf, \ 			    (m)->m_ext.ext_size); \ 		else { \ 			char *p = (m)->m_ext.ext_buf; \ 			if (--mclrefcnt[mtocl(p)] == 0) { \ 				((union mcluster *)(p))->mcl_next = mclfree; \ 				mclfree = (union mcluster *)(p); \ 				mbstat.m_clfree++; \ 			} \ 		} \ 	  } \ 	  (n) = (m)->m_next; \ 	  (m)->m_type = MT_FREE; \ 	  mbstat.m_mtypes[MT_FREE]++; \ 	  (m)->m_next = mmbfree; \ 	  mmbfree = (m); \ 	)
end_define

begin_comment
comment|/*  * Copy mbuf pkthdr from from to to.  * from must have M_PKTHDR set, and to must be empty.  */
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
value|{ \ 	(to)->m_pkthdr = (from)->m_pkthdr; \ 	(to)->m_flags = (from)->m_flags& M_COPYFLAGS; \ 	(to)->m_data = (to)->m_pktdat; \ }
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
define|\
value|{ (m)->m_data += (MLEN - (len))&~ (sizeof(long) - 1); }
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
define|\
value|{ (m)->m_data += (MHLEN - (len))&~ (sizeof(long) - 1); }
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
value|((m)->m_flags& M_EXT ?
comment|/* (m)->m_data - (m)->m_ext.ext_buf */
value|0 : \ 	    (m)->m_flags& M_PKTHDR ? (m)->m_data - (m)->m_pktdat : \ 	    (m)->m_data - (m)->m_dat)
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
value|((m)->m_flags& M_EXT ? (m)->m_ext.ext_buf + (m)->m_ext.ext_size - \ 	    ((m)->m_data + (m)->m_len) : \&(m)->m_dat[MLEN] - ((m)->m_data + (m)->m_len))
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
value|{ \ 	if (M_LEADINGSPACE(m)>= (plen)) { \ 		(m)->m_data -= (plen); \ 		(m)->m_len += (plen); \ 	} else \ 		(m) = m_prepend((m), (plen), (how)); \ 	if ((m)&& (m)->m_flags& M_PKTHDR) \ 		(m)->m_pkthdr.len += (plen); \ }
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
value|{ \ 	MBUFLOCK(mbstat.m_mtypes[(m)->m_type]--; mbstat.m_mtypes[t]++;) \ 	(m)->m_type = t;\ }
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
comment|/*  * Mbuf statistics.  */
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
name|u_short
name|m_mtypes
index|[
literal|256
index|]
decl_stmt|;
comment|/* type specific mbuf allocations */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
name|struct
name|mbstat
name|mbstat
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
name|struct
name|mbuf
modifier|*
name|mmbfree
decl_stmt|;
end_decl_stmt

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
name|m_retry
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
name|m_retryhdr
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

begin_comment
comment|/* !_SYS_MBUF_H_ */
end_comment

end_unit

