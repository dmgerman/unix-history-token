begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)mbuf.h	7.10 (Berkeley) 2/8/88  */
end_comment

begin_comment
comment|/*  * Constants related to memory allocator.  */
end_comment

begin_define
define|#
directive|define
name|MSIZE
value|128
end_define

begin_comment
comment|/* size of an mbuf */
end_comment

begin_if
if|#
directive|if
name|CLBYTES
operator|>
literal|1024
end_if

begin_define
define|#
directive|define
name|MCLBYTES
value|1024
end_define

begin_define
define|#
directive|define
name|MCLSHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MCLOFSET
value|(MCLBYTES - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCLBYTES
value|CLBYTES
end_define

begin_define
define|#
directive|define
name|MCLSHIFT
value|CLSHIFT
end_define

begin_define
define|#
directive|define
name|MCLOFSET
value|CLOFSET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MMINOFF
value|12
end_define

begin_comment
comment|/* mbuf header length */
end_comment

begin_define
define|#
directive|define
name|MTAIL
value|4
end_define

begin_define
define|#
directive|define
name|MMAXOFF
value|(MSIZE-MTAIL)
end_define

begin_comment
comment|/* offset where data ends */
end_comment

begin_define
define|#
directive|define
name|MLEN
value|(MSIZE-MMINOFF-MTAIL)
end_define

begin_comment
comment|/* mbuf data length */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|512
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NMBPCL
value|(CLBYTES/MSIZE)
end_define

begin_comment
comment|/* # mbufs per cluster */
end_comment

begin_comment
comment|/*  * Macros for type conversion  */
end_comment

begin_comment
comment|/* network cluster number to virtual address, and back */
end_comment

begin_define
define|#
directive|define
name|cltom
parameter_list|(
name|x
parameter_list|)
value|((struct mbuf *)((int)mbutl + ((x)<< MCLSHIFT)))
end_define

begin_define
define|#
directive|define
name|mtocl
parameter_list|(
name|x
parameter_list|)
value|(((int)x - (int)mbutl)>> MCLSHIFT)
end_define

begin_comment
comment|/* address in mbuf to mbuf head */
end_comment

begin_define
define|#
directive|define
name|dtom
parameter_list|(
name|x
parameter_list|)
value|((struct mbuf *)((int)x& ~(MSIZE-1)))
end_define

begin_comment
comment|/* mbuf head, to typed data */
end_comment

begin_define
define|#
directive|define
name|mtod
parameter_list|(
name|x
parameter_list|,
name|t
parameter_list|)
value|((t)((int)(x) + (x)->m_off))
end_define

begin_struct
struct|struct
name|mbuf
block|{
name|struct
name|mbuf
modifier|*
name|m_next
decl_stmt|;
comment|/* next buffer in chain */
name|u_long
name|m_off
decl_stmt|;
comment|/* offset of data */
name|short
name|m_len
decl_stmt|;
comment|/* amount of data in this mbuf */
name|short
name|m_type
decl_stmt|;
comment|/* mbuf type (0 == free) */
name|u_char
name|m_dat
index|[
name|MLEN
index|]
decl_stmt|;
comment|/* data storage */
name|struct
name|mbuf
modifier|*
name|m_act
decl_stmt|;
comment|/* link in higher-level mbuf list */
block|}
struct|;
end_struct

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

begin_comment
comment|/* flags to m_get */
end_comment

begin_define
define|#
directive|define
name|M_DONTWAIT
value|0
end_define

begin_define
define|#
directive|define
name|M_WAIT
value|1
end_define

begin_comment
comment|/* flags to m_pgalloc */
end_comment

begin_define
define|#
directive|define
name|MPG_MBUFS
value|0
end_define

begin_comment
comment|/* put new mbufs on free list */
end_comment

begin_define
define|#
directive|define
name|MPG_CLUSTERS
value|1
end_define

begin_comment
comment|/* put new clusters on free list */
end_comment

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
comment|/*  * m_pullup will pull up additional length if convenient;  * should be enough to hold headers of second-level and higher protocols.   */
end_comment

begin_define
define|#
directive|define
name|MPULL_EXTRA
value|32
end_define

begin_define
define|#
directive|define
name|MGET
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|,
name|t
parameter_list|)
define|\
value|{ int ms = splimp(); \ 	  if ((m)=mfree) \ 		{ if ((m)->m_type != MT_FREE) panic("mget"); (m)->m_type = t; \ 		  mbstat.m_mtypes[MT_FREE]--; mbstat.m_mtypes[t]++; \ 		  mfree = (m)->m_next; (m)->m_next = 0; \ 		  (m)->m_off = MMINOFF; } \ 	  else \ 		(m) = m_more(i, t); \ 	  splx(ms); }
end_define

begin_comment
comment|/*  * Mbuf page cluster macros.  * MCLALLOC allocates mbuf page clusters.  * Note that it works only with a count of 1 at the moment.  * MCLGET adds such clusters to a normal mbuf.  * m->m_len is set to MCLBYTES upon success, and to MLEN on failure.  * MCLFREE frees clusters allocated by MCLALLOC.  */
end_comment

begin_define
define|#
directive|define
name|MCLALLOC
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
define|\
value|{ int ms = splimp(); \ 	  if (mclfree == 0) \ 		(void)m_clalloc((i), MPG_CLUSTERS, M_DONTWAIT); \ 	  if ((m)=mclfree) \ 	     {++mclrefcnt[mtocl(m)];mbstat.m_clfree--;mclfree = (m)->m_next;} \ 	  splx(ms); }
end_define

begin_define
define|#
directive|define
name|M_HASCL
parameter_list|(
name|m
parameter_list|)
value|((m)->m_off>= MSIZE)
end_define

begin_define
define|#
directive|define
name|MTOCL
parameter_list|(
name|m
parameter_list|)
value|((struct mbuf *)(mtod((m), int)&~ MCLOFSET))
end_define

begin_define
define|#
directive|define
name|MCLGET
parameter_list|(
name|m
parameter_list|)
define|\
value|{ struct mbuf *p; \ 	  MCLALLOC(p, 1); \ 	  if (p) { \ 		(m)->m_off = (int)p - (int)(m); \ 		(m)->m_len = MCLBYTES; \ 	  } else \ 		(m)->m_len = MLEN; \ 	}
end_define

begin_define
define|#
directive|define
name|MCLFREE
parameter_list|(
name|m
parameter_list|)
value|{ \ 	if (--mclrefcnt[mtocl(m)] == 0) \ 	    { (m)->m_next = mclfree;mclfree = (m);mbstat.m_clfree++;} \ 	}
end_define

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
value|{ int ms = splimp(); \ 	  if ((m)->m_type == MT_FREE) panic("mfree"); \ 	  mbstat.m_mtypes[(m)->m_type]--; mbstat.m_mtypes[MT_FREE]++; \ 	  (m)->m_type = MT_FREE; \ 	  if (M_HASCL(m)) { \ 		(n) = MTOCL(m); \ 		MCLFREE(n); \ 	  } \ 	  (n) = (m)->m_next; (m)->m_next = mfree; \ 	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); \ 	  splx(ms); \ 	  if (m_want) { \ 		  m_want = 0; \ 		  wakeup((caddr_t)&mfree); \ 	  } \ 	}
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
name|mbutl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual address of net free mem */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Mbmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page tables to map Netutl */
end_comment

begin_decl_stmt
name|struct
name|mbstat
name|mbstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nmbclusters
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|mfree
decl_stmt|,
modifier|*
name|mclfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mclrefcnt
index|[
name|NMBCLUSTERS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|m_want
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m_get
argument_list|()
decl_stmt|,
modifier|*
name|m_getclr
argument_list|()
decl_stmt|,
modifier|*
name|m_free
argument_list|()
decl_stmt|,
modifier|*
name|m_more
argument_list|()
decl_stmt|,
modifier|*
name|m_copy
argument_list|()
decl_stmt|,
modifier|*
name|m_pullup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|caddr_t
name|m_clalloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

