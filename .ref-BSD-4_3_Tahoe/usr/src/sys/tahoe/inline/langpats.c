begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)langpats.c	1.5 (Berkeley) 11/25/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"inline.h"
end_include

begin_comment
comment|/*  * Pattern table for kernel specific routines.  * These patterns are based on the old asm.sed script.  */
end_comment

begin_decl_stmt
name|struct
name|pats
name|language_ptab
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"_spl0\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl1\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x11,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl3\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x13,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl4\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x14,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl5\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x15,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl7\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x17,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spl8\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splimp\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splsoftclock\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x8,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splnet\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0xc,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splbio\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_spltty\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splclock\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_splhigh\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_splx\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	$8,r0\n\ 	mtpr	r1,$8\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_mfpr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	r1,r0\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_mtpr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	mtpr	r0,r1\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|1
block|,
literal|"_uncache\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mtpr	r1,$0x1c\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|,
literal|"_setsoftclock\n"
block|,
literal|"	mtpr	$0x8,$0x10\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_fuibyte\n"
block|,
literal|"	callf	$8,_fubyte\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_fuiword\n"
block|,
literal|"	callf	$8,_fuword\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_suibyte\n"
block|,
literal|"	callf	$12,_subyte\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_suiword\n"
block|,
literal|"	callf	$12,_suword\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_setjmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	clrl	r0\n\ 	movab	(fp),(r1)\n\ 	addl2	$4,r1\n\ 	movab	1(pc),(r1)\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_ffs\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	ffs	r1,r0\n\ 	bgeq	1f\n\ 	mnegl	$1,r0\n\ 1:\n\ 	incl	r0\n"
block|}
block|,
block|{
literal|2
block|,
literal|"__insque\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	insque	(r0),(r1)\n"
block|}
block|,
block|{
literal|1
block|,
literal|"__remque\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	remque	(r1)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_imin\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bleq	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_imax\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bgeq	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_min\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	blequ	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_max\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bgequ	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"__movow\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	movow	r0,(r1)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"__movob\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	movob	r0,(r1)\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_movpsl\n"
block|,
literal|"	movpsl	r0\n"
block|}
block|,
block|{
literal|0
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

