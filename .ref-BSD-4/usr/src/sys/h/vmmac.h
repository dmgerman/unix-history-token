begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmmac.h	4.1	11/9/80	*/
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
value|((int)((v) - (p)->p_tsize))
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
value|((int)(btop(USRSTACK) - 1 - (v)))
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
value|((unsigned)((p)->p_tsize + (i)))
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
value|((unsigned)(btop(USRSTACK) - 1 - (i)))
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
value|((v)& P1TOP)
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
value|((v)>= (p)->p_tsize&& !isassv(p, v))
end_define

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
value|((pte) - ((p)->p_p0br + (p)->p_tsize))
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
define|\
value|(((p)->p_p0br + (p)->p_szpt*NPTEPG - UPAGES - 1) - (pte))
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
value|((p)->p_p0br + (p)->p_tsize + (i))
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
define|\
value|(((p)->p_p0br + (p)->p_szpt*NPTEPG - UPAGES - 1) - (i))
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

begin_define
define|#
directive|define
name|pcbb
parameter_list|(
name|p
parameter_list|)
value|((p)->p_addr[0].pg_pfnum)
end_define

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

end_unit

