begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mbuf.h 4.7 81/11/29 */
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
name|NMBCLUSTERS
value|256
end_define

begin_comment
comment|/*  * Macros for type conversion  *  * CONSTANTS HERE ARE A CROCK  */
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
value|((struct mbuf *)((int)mbutl + ((x)<< CLSHIFT)))
end_define

begin_define
define|#
directive|define
name|mtocl
parameter_list|(
name|x
parameter_list|)
value|(((int)x - (int)mbutl)>> CLSHIFT)
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
name|MCLGET
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
define|\
value|{ int ms = splimp(); \ 	  if ((m)=mclfree) \ 	      { ++mclrefcnt[mtocl(m)]; nmclfree--; mclfree = (m)->m_next; } \ 	  splx(ms); }
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
value|{ int ms = splimp(); \ 	  if ((m)->m_off> MSIZE) { \ 		(n) = (struct mbuf *)(mtod(m, int)&~0x3ff); \ 		if (--mclrefcnt[mtocl(n)] == 0) \ 		    { (n)->m_next = mclfree; mclfree = (n); nmclfree++; } \ 	  } \ 	  (n) = (m)->m_next; (m)->m_next = mfree; \ 	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); mbstat.m_bufs++; \ 	  splx(ms); }
end_define

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
name|int
name|nmclfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mclrefcnt
index|[
name|NMBCLUSTERS
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

