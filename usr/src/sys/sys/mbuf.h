begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mbuf.h 4.1 81/10/29 */
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
name|NMPAGES
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
value|((struct mbuf *)((x<< 10) + (int)netutl))
end_define

begin_define
define|#
directive|define
name|mtopf
parameter_list|(
name|x
parameter_list|)
value|((((int)x& ~0x3ff) - (int)netutl)>> 10)
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
name|NMPAGES
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
name|m_free
argument_list|()
decl_stmt|,
modifier|*
name|m_more
argument_list|()
decl_stmt|;
end_decl_stmt

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
value|{ int ms = spl_imp(); \ 	  if ((m)=mfree) \ 		{ netcb.n_bufs--; mfree = (m)->m_next; (m)->m_next = 0; } \ 	  else \ 		(m) = m_more(i); \ 	  splx(ms); }
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
value|{ int ms = spl_imp(); \ 	  if ((m)=mpfree) \ 	      { ++mprefcnt[mtopf(m)]; nmpfree--; mpfree = (m)->m_next; } \ 	  splx(ms); }
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
value|{ int ms = spl_imp(); \ 	  if ((m)->m_off> MSIZE) { \ 		(n) = (struct mbuf *)(mtod(m, int)&~0x3ff); \ 		if (--mprefcnt[mtopf(n)] == 0) \ 		    { (n)->m_next = mpfree; mpfree = (n); nmpfree++; } \ 	  } \ 	  (n) = (m)->m_next; (m)->m_next = mfree; \ 	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); netcb.n_bufs++; \ 	  splx(ms); }
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|mbuf
name|netutl
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
name|Netmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page tables to map Netutl */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|short
name|n_bufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # free msg buffers */
end_comment

begin_decl_stmt
name|short
name|n_hiwat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # free mbufs allocated */
end_comment

begin_decl_stmt
name|short
name|n_lowat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min. # free mbufs */
end_comment

begin_decl_stmt
name|short
name|n_pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # pages owned by network */
end_comment

end_unit

