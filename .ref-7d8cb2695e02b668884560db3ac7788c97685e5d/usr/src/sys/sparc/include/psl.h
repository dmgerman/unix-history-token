begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)psl.h	7.3 (Berkeley) %G%  *  * from: $Header: psl.h,v 1.12 92/11/26 02:04:42 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PSR_IMPL
end_ifndef

begin_comment
comment|/*  * SPARC Process Status Register (in psl.h for hysterical raisins).  *  * The picture in the Sun manuals looks like this:  *	                                     1 1  *	 31   28 27   24 23   20 19       14 3 2 11    8 7 6 5 4       0  *	+-------+-------+-------+-----------+-+-+-------+-+-+-+---------+  *	|  impl |  ver  |  icc  |  reserved |E|E|  pil  |S|P|E|   CWP   |  *	|       |       |n z v c|           |C|F|       | |S|T|         |  *	+-------+-------+-------+-----------+-+-+-------+-+-+-+---------+  */
end_comment

begin_define
define|#
directive|define
name|PSR_IMPL
value|0xf0000000
end_define

begin_comment
comment|/* implementation */
end_comment

begin_define
define|#
directive|define
name|PSR_VER
value|0x0f000000
end_define

begin_comment
comment|/* version */
end_comment

begin_define
define|#
directive|define
name|PSR_ICC
value|0x00f00000
end_define

begin_comment
comment|/* integer condition codes */
end_comment

begin_define
define|#
directive|define
name|PSR_N
value|0x00800000
end_define

begin_comment
comment|/* negative */
end_comment

begin_define
define|#
directive|define
name|PSR_Z
value|0x00400000
end_define

begin_comment
comment|/* zero */
end_comment

begin_define
define|#
directive|define
name|PSR_O
value|0x00200000
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|PSR_C
value|0x00100000
end_define

begin_comment
comment|/* carry */
end_comment

begin_define
define|#
directive|define
name|PSR_EC
value|0x00002000
end_define

begin_comment
comment|/* coprocessor enable */
end_comment

begin_define
define|#
directive|define
name|PSR_EF
value|0x00001000
end_define

begin_comment
comment|/* FP enable */
end_comment

begin_define
define|#
directive|define
name|PSR_PIL
value|0x00000f00
end_define

begin_comment
comment|/* interrupt level */
end_comment

begin_define
define|#
directive|define
name|PSR_S
value|0x00000080
end_define

begin_comment
comment|/* supervisor (kernel) mode */
end_comment

begin_define
define|#
directive|define
name|PSR_PS
value|0x00000040
end_define

begin_comment
comment|/* previous supervisor mode (traps) */
end_comment

begin_define
define|#
directive|define
name|PSR_ET
value|0x00000020
end_define

begin_comment
comment|/* trap enable */
end_comment

begin_define
define|#
directive|define
name|PSR_CWP
value|0x0000001f
end_define

begin_comment
comment|/* current window pointer */
end_comment

begin_define
define|#
directive|define
name|PSR_BITS
value|"\20\16EC\15EF\10S\7PS\6ET"
end_define

begin_define
define|#
directive|define
name|PIL_CLOCK
value|10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * GCC pseudo-functions for manipulating PSR (primarily PIL field).  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|getpsr
parameter_list|()
block|{
name|int
name|psr
decl_stmt|;
asm|__asm __volatile("rd %%psr,%0" : "=r" (psr));
return|return
operator|(
name|psr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|setpsr
parameter_list|(
name|int
name|newpsr
parameter_list|)
block|{
asm|__asm __volatile("wr %0,0,%%psr" : : "r" (newpsr));
asm|__asm __volatile("nop");
asm|__asm __volatile("nop");
asm|__asm __volatile("nop");
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|spl0
parameter_list|()
block|{
name|int
name|psr
decl_stmt|,
name|oldipl
decl_stmt|;
comment|/* 	 * wrpsr xors two values: we choose old psr and old ipl here, 	 * which gives us the same value as the old psr but with all 	 * the old PIL bits turned off. 	 */
asm|__asm __volatile("rd %%psr,%0" : "=r" (psr));
name|oldipl
operator|=
name|psr
operator|&
name|PSR_PIL
expr_stmt|;
asm|__asm __volatile("wr %0,%1,%%psr" : : "r" (psr), "r" (oldipl));
comment|/* 	 * Three instructions must execute before we can depend 	 * on the bits to be changed. 	 */
asm|__asm __volatile("nop; nop; nop");
return|return
operator|(
name|oldipl
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * PIL 1 through 14 can use this macro.  * (spl0 and splhigh are special since they put all 0s or all 1s  * into the ipl field.)  */
end_comment

begin_define
define|#
directive|define
name|SPL
parameter_list|(
name|name
parameter_list|,
name|newipl
parameter_list|)
define|\
value|static __inline int name() { \ 	int psr, oldipl; \ 	__asm __volatile("rd %%psr,%0" : "=r" (psr)); \ 	oldipl = psr& PSR_PIL; \ 	psr&= ~oldipl; \ 	__asm __volatile("wr %0,%1,%%psr" : : \ 	    "r" (psr), "n" ((newipl)<< 8)); \ 	__asm __volatile("nop; nop; nop"); \ 	return (oldipl); \ }
end_define

begin_macro
name|SPL
argument_list|(
argument|splsoftint
argument_list|,
literal|1
argument_list|)
end_macro

begin_define
define|#
directive|define
name|splnet
value|splsoftint
end_define

begin_define
define|#
directive|define
name|splsoftclock
value|splsoftint
end_define

begin_comment
comment|/* Memory allocation (must be as high as highest network device) */
end_comment

begin_macro
name|SPL
argument_list|(
argument|splimp
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* tty input runs at software level 6 */
end_comment

begin_define
define|#
directive|define
name|PIL_TTY
value|6
end_define

begin_macro
name|SPL
argument_list|(
argument|spltty
argument_list|,
argument|PIL_TTY
argument_list|)
end_macro

begin_comment
comment|/* audio software interrupts are at software level 4 */
end_comment

begin_define
define|#
directive|define
name|PIL_AUSOFT
value|4
end_define

begin_macro
name|SPL
argument_list|(
argument|splausoft
argument_list|,
argument|PIL_AUSOFT
argument_list|)
end_macro

begin_macro
name|SPL
argument_list|(
argument|splbio
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|SPL
argument_list|(
argument|splclock
argument_list|,
argument|PIL_CLOCK
argument_list|)
end_macro

begin_comment
comment|/* zs hardware interrupts are at level 12 */
end_comment

begin_macro
name|SPL
argument_list|(
argument|splzs
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* audio hardware interrupts are at level 13 */
end_comment

begin_macro
name|SPL
argument_list|(
argument|splaudio
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* second sparc timer interrupts at level 14 */
end_comment

begin_macro
name|SPL
argument_list|(
argument|splstatclock
argument_list|,
literal|14
argument_list|)
end_macro

begin_function
specifier|static
name|__inline
name|int
name|splhigh
parameter_list|()
block|{
name|int
name|psr
decl_stmt|,
name|oldipl
decl_stmt|;
asm|__asm __volatile("rd %%psr,%0" : "=r" (psr));
asm|__asm __volatile("wr %0,0,%%psr" : : "r" (psr | PSR_PIL));
asm|__asm __volatile("and %1,%2,%0; nop; nop" : "=r" (oldipl) : \ 	    "r" (psr), "n" (PSR_PIL));
return|return
operator|(
name|oldipl
operator|)
return|;
block|}
end_function

begin_comment
comment|/* splx does not have a return value */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|splx
parameter_list|(
name|int
name|newipl
parameter_list|)
block|{
name|int
name|psr
decl_stmt|;
asm|__asm __volatile("rd %%psr,%0" : "=r" (psr));
asm|__asm __volatile("wr %0,%1,%%psr" : : \ 	    "r" (psr& ~PSR_PIL), "rn" (newipl));
asm|__asm __volatile("nop; nop; nop");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PSR_IMPL */
end_comment

end_unit

