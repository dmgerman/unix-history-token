begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vmmac.h	7.4 (Berkeley) 11/12/87  */
end_comment

begin_comment
comment|/*  * Virtual memory related conversion macros  */
end_comment

begin_comment
comment|/* Core clicks to number of pages of page tables needed to map that much */
end_comment

begin_define
define|#
directive|define
name|ctopt
parameter_list|(
name|x
parameter_list|)
value|(((x)+NPTEPG-1)/NPTEPG)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/* Virtual page numbers to text|data|stack segment page numbers and back */
end_comment

begin_define
define|#
directive|define
name|vtotp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)(v))
end_define

begin_define
define|#
directive|define
name|vtodp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)((v) - stoc(ctos((p)->p_tsize))))
end_define

begin_define
define|#
directive|define
name|vtosp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)(BTOPUSRSTACK - 1 - (v)))
end_define

begin_define
define|#
directive|define
name|tptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(i))
end_define

begin_define
define|#
directive|define
name|dptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(stoc(ctos((p)->p_tsize)) + (i)))
end_define

begin_define
define|#
directive|define
name|sptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(BTOPUSRSTACK - 1 - (i)))
end_define

begin_comment
comment|/* Tell whether virtual page numbers are in text|data|stack segment */
end_comment

begin_define
define|#
directive|define
name|isassv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)>= BTOPUSRSTACK - (p)->p_ssize)
end_define

begin_define
define|#
directive|define
name|isatsv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)< (p)->p_tsize)
end_define

begin_define
define|#
directive|define
name|isadsv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)>= stoc(ctos((p)->p_tsize))&& \ 	(v)< (p)->p_tsize + (p)->p_dsize)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Virtual page numbers to text|data|stack segment page numbers and back */
end_comment

begin_define
define|#
directive|define
name|vtotp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)(v)-LOWPAGES)
end_define

begin_define
define|#
directive|define
name|vtodp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)((v) - stoc(ctos((p)->p_tsize)) - LOWPAGES))
end_define

begin_define
define|#
directive|define
name|vtosp
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((int)(BTOPUSRSTACK - 1 - (v)))
end_define

begin_define
define|#
directive|define
name|tptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(i) + LOWPAGES)
end_define

begin_define
define|#
directive|define
name|dptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(stoc(ctos((p)->p_tsize)) + (i) + LOWPAGES))
end_define

begin_define
define|#
directive|define
name|sptov
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((unsigned)(BTOPUSRSTACK - 1 - (i)))
end_define

begin_comment
comment|/* Tell whether virtual page numbers are in text|data|stack segment */
end_comment

begin_define
define|#
directive|define
name|isassv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((v)>= BTOPUSRSTACK - (p)->p_ssize)
end_define

begin_define
define|#
directive|define
name|isatsv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(((v) - LOWPAGES)< (p)->p_tsize)
end_define

begin_define
define|#
directive|define
name|isadsv
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(((v) - LOWPAGES)>= stoc(ctos((p)->p_tsize))&& \ 				!isassv(p, v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tell whether pte's are text|data|stack */
end_comment

begin_define
define|#
directive|define
name|isaspte
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte)> sptopte(p, (p)->p_ssize))
end_define

begin_define
define|#
directive|define
name|isatpte
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte)< dptopte(p, 0))
end_define

begin_define
define|#
directive|define
name|isadpte
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|(!isaspte(p, pte)&& !isatpte(p, pte))
end_define

begin_comment
comment|/* Text|data|stack pte's to segment page numbers and back */
end_comment

begin_define
define|#
directive|define
name|ptetotp
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|((pte) - (p)->p_p0br)
end_define

begin_define
define|#
directive|define
name|ptetodp
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|(((pte) - (p)->p_p0br) - (p)->p_tsize)
end_define

begin_define
define|#
directive|define
name|ptetosp
parameter_list|(
name|p
parameter_list|,
name|pte
parameter_list|)
value|(((p)->p_addr - (pte)) - 1)
end_define

begin_define
define|#
directive|define
name|tptopte
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((p)->p_p0br + (i))
end_define

begin_define
define|#
directive|define
name|dptopte
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((p)->p_p0br + ((p)->p_tsize + (i)))
end_define

begin_define
define|#
directive|define
name|sptopte
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|((p)->p_addr - (1 + (i)))
end_define

begin_comment
comment|/* Convert a virtual page number to a pte address. */
end_comment

begin_define
define|#
directive|define
name|vtopte
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(((v)< (p)->p_tsize + (p)->p_dsize) ? ((p)->p_p0br + (v)) : \ 	((p)->p_addr - (BTOPUSRSTACK - (v))))
end_define

begin_comment
comment|/* Bytes to pages without rounding, and back */
end_comment

begin_define
define|#
directive|define
name|btop
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x))>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|ptob
parameter_list|(
name|x
parameter_list|)
value|((caddr_t)((x)<< PGSHIFT))
end_define

begin_comment
comment|/* Turn virtual addresses into kernel map indices */
end_comment

begin_define
define|#
directive|define
name|kmxtob
parameter_list|(
name|a
parameter_list|)
value|(usrpt + (a) * NPTEPG)
end_define

begin_define
define|#
directive|define
name|btokmx
parameter_list|(
name|b
parameter_list|)
value|(((b) - usrpt) / NPTEPG)
end_define

begin_comment
comment|/* User area address and pcb bases */
end_comment

begin_define
define|#
directive|define
name|uaddr
parameter_list|(
name|p
parameter_list|)
value|(&((p)->p_p0br[(p)->p_szpt * NPTEPG - UPAGES]))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|pcbb
parameter_list|(
name|p
parameter_list|)
value|((p)->p_addr[0].pg_pfnum)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Average new into old with aging factor time */
end_comment

begin_define
define|#
directive|define
name|ave
parameter_list|(
name|smooth
parameter_list|,
name|cnt
parameter_list|,
name|time
parameter_list|)
define|\
value|smooth = ((time - 1) * (smooth) + (cnt)) / (time)
end_define

begin_comment
comment|/* Abstract machine dependent operations */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
end_if

begin_define
define|#
directive|define
name|setp0br
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p0br = (x), mtpr(P0BR, x))
end_define

begin_define
define|#
directive|define
name|setp0lr
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p0lr = \ 			    (x) | (u.u_pcb.pcb_p0lr& AST_CLR), \ 			 mtpr(P0LR, x))
end_define

begin_define
define|#
directive|define
name|setp1br
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p1br = (x), mtpr(P1BR, x))
end_define

begin_define
define|#
directive|define
name|setp1lr
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p1lr = (x), mtpr(P1LR, x))
end_define

begin_define
define|#
directive|define
name|initp1br
parameter_list|(
name|x
parameter_list|)
value|((x) - P1PAGES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|setp0br
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p0br = (x), mtpr(P0BR, x))
end_define

begin_define
define|#
directive|define
name|setp0lr
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p0lr = (x), mtpr(P0LR, x))
end_define

begin_define
define|#
directive|define
name|setp1br
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p1br = (x), mtpr(P1BR, x))
end_define

begin_define
define|#
directive|define
name|setp1lr
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p1lr = (x), mtpr(P1LR, x))
end_define

begin_define
define|#
directive|define
name|setp2br
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p2br = (x), mtpr(P2BR, x))
end_define

begin_define
define|#
directive|define
name|setp2lr
parameter_list|(
name|x
parameter_list|)
value|(u.u_pcb.pcb_p2lr = (x), mtpr(P2LR, x))
end_define

begin_define
define|#
directive|define
name|initp2br
parameter_list|(
name|x
parameter_list|)
value|((x) - P2PAGES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|outofmem
parameter_list|()
value|wakeup((caddr_t)&proc[2]);
end_define

begin_comment
comment|/*  * Page clustering macros.  *   * dirtycl(pte)			is the page cluster dirty?  * anycl(pte,fld)		does any pte in the cluster has fld set?  * zapcl(pte,fld) = val		set all fields fld in the cluster to val  * distcl(pte)			distribute high bits to cluster; note that  *				distcl copies everything but pg_pfnum,  *				INCLUDING pg_m!!!  *  * In all cases, pte must be the low pte in the cluster, even if  * the segment grows backwards (e.g. the stack).  */
end_comment

begin_define
define|#
directive|define
name|H
parameter_list|(
name|pte
parameter_list|)
value|((struct hpte *)(pte))
end_define

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
value|dirty(pte)
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|((pte)->fld)
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|(pte)->fld
end_define

begin_define
define|#
directive|define
name|distcl
parameter_list|(
name|pte
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
value|(dirty(pte) || dirty((pte)+1))
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|((pte)->fld || (((pte)+1)->fld))
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|(pte)[1].fld = (pte)[0].fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
define|\
value|(dirty(pte) || dirty((pte)+1) || dirty((pte)+2) || dirty((pte)+3))
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
define|\
value|((pte)->fld || (((pte)+1)->fld) || (((pte)+2)->fld) || (((pte)+3)->fld))
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
define|\
value|(pte)[3].fld = (pte)[2].fld = (pte)[1].fld = (pte)[0].fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|distcl
end_ifndef

begin_define
define|#
directive|define
name|distcl
parameter_list|(
name|pte
parameter_list|)
value|zapcl(H(pte),pg_high)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Lock a page frame.  */
end_comment

begin_define
define|#
directive|define
name|MLOCK
parameter_list|(
name|c
parameter_list|)
value|{ \ 	while ((c)->c_lock) { \ 		(c)->c_want = 1; \ 		sleep((caddr_t)(c), PSWP+1); \ 	} \ 	(c)->c_lock = 1; \ }
end_define

begin_comment
comment|/*  * Unlock a page frame.  */
end_comment

begin_define
define|#
directive|define
name|MUNLOCK
parameter_list|(
name|c
parameter_list|)
value|{ \ 	if ((c)->c_want) { \ 		wakeup((caddr_t)(c)); \ 		(c)->c_want = 0; \ 	} \ 	(c)->c_lock = 0; \ }
end_define

end_unit

