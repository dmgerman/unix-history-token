begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mbuf.h 4.5 81/11/18 */
end_comment

begin_comment
comment|/*  * Constants related to memory allocator.  */
end_comment

begin_define
define|#
directive|define
name|PGSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MSIZE
value|128
end_define

begin_comment
comment|/* size of an mbuf */
end_comment

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

begin_define
define|#
directive|define
name|NMBPAGES
value|256
end_define

begin_comment
comment|/*  * Macros for type conversion  *  * CONSTANTS HERE ARE A CROCK  */
end_comment

begin_comment
comment|/* network page map number to virtual address, and back */
end_comment

begin_define
define|#
directive|define
name|pftom
parameter_list|(
name|x
parameter_list|)
value|((struct mbuf *)((x<< 10) + (int)mbutl))
end_define

begin_define
define|#
directive|define
name|mtopf
parameter_list|(
name|x
parameter_list|)
value|((((int)x& ~0x3ff) - (int)mbutl)>> 10)
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
value|((struct mbuf *)((int)x& ~0x7f))
end_define

begin_define
define|#
directive|define
name|mtoff
parameter_list|(
name|x
parameter_list|)
value|(((int)x& 0x3ff)>> 7)
end_define

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
name|m_cnt
decl_stmt|;
comment|/* reference count */
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

begin_define
define|#
directive|define
name|M_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|MGET
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
define|\
value|{ int ms = splimp(); \ 	  if ((m)=mfree) \ 		{ mbstat.m_bufs--; mfree = (m)->m_next; (m)->m_next = 0; } \ 	  else \ 		(m) = m_more(i); \ 	  splx(ms); }
end_define

begin_define
define|#
directive|define
name|MPGET
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
define|\
value|{ int ms = splimp(); \ 	  if ((m)=mpfree) \ 	      { ++mprefcnt[mtopf(m)]; nmpfree--; mpfree = (m)->m_next; } \ 	  splx(ms); }
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
value|{ int ms = splimp(); \ 	  if ((m)->m_off> MSIZE) { \ 		(n) = (struct mbuf *)(mtod(m, int)&~0x3ff); \ 		if (--mprefcnt[mtopf(n)] == 0) \ 		    { (n)->m_next = mpfree; mpfree = (n); nmpfree++; } \ 	  } \ 	  (n) = (m)->m_next; (m)->m_next = mfree; \ 	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); mbstat.m_bufs++; \ 	  splx(ms); }
end_define

begin_define
define|#
directive|define
name|NMBPG
value|(PGSIZE/MSIZE)
end_define

begin_comment
comment|/* mbufs/page */
end_comment

begin_struct
struct|struct
name|mbstat
block|{
name|short
name|m_bufs
decl_stmt|;
comment|/* # free msg buffers */
name|short
name|m_hiwat
decl_stmt|;
comment|/* # free mbufs allocated */
name|short
name|m_lowat
decl_stmt|;
comment|/* min. # free mbufs */
name|short
name|m_pages
decl_stmt|;
comment|/* # pages owned by network */
name|short
name|m_drops
decl_stmt|;
comment|/* times failed to find space */
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
name|nmbpages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|mfree
decl_stmt|,
modifier|*
name|mpfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nmpfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mprefcnt
index|[
name|NMBPAGES
index|]
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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

