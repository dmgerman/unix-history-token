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
literal|"@(#)langpats.c	1.2 (Berkeley) %G%"
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
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
block|{
literal|"0,_spl0\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0,$18\n"
block|}
block|,
block|{
literal|"0,_spl1\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$1,$18\n"
block|}
block|,
block|{
literal|"0,_splsoftclock\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x8,$18\n"
block|}
block|,
block|{
literal|"0,_splnet\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0xc,$18\n"
block|}
block|,
block|{
literal|"0,_splimp\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x16,$18\n"
block|}
block|,
block|{
literal|"0,_spl4\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x14,$18\n"
block|}
block|,
block|{
literal|"0,_splbio\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
block|{
literal|"0,_spltty\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
block|{
literal|"0,_spl5\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
block|{
literal|"0,_splclock\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x18,$18\n"
block|}
block|,
block|{
literal|"0,_spl6\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x18,$18\n"
block|}
block|,
block|{
literal|"0,_splhigh\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x1f,$18\n"
block|}
block|,
block|{
literal|"0,_spl7\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x1f,$18\n"
block|}
block|,
block|{
literal|"1,_splx\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	$18,r0\n\ 	mtpr	r1,$18\n"
block|}
block|,
block|{
literal|"1,_mfpr\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	mfpr	r5,r0\n"
block|}
block|,
block|{
literal|"2,_mtpr\n"
block|,
literal|"	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	mtpr	r5,r4\n"
block|}
block|,
block|{
literal|"0,_setsoftclock\n"
block|,
literal|"	mtpr	$0x8,$0x14\n"
block|}
block|,
block|{
literal|"1,_resume\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	ashl	$9,r5,r0\n\ 	movpsl	-(sp)\n\ 	jsb	_Resume\n"
block|}
block|,
block|{
literal|"3,_copyin\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r5\n\ 	jsb	_Copyin\n"
block|}
block|,
block|{
literal|"3,_copyout\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r5\n\ 	jsb	_Copyout\n"
block|}
block|,
block|{
literal|"1,_fubyte\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Fubyte\n"
block|}
block|,
block|{
literal|"1,_fuibyte\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Fubyte\n"
block|}
block|,
block|{
literal|"1,_fuword\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Fuword\n"
block|}
block|,
block|{
literal|"1,_fuiword\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Fuword\n"
block|}
block|,
block|{
literal|"2,_subyte\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Subyte\n"
block|}
block|,
block|{
literal|"2,_suibyte\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Subyte\n"
block|}
block|,
block|{
literal|"2,_suword\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Suword\n"
block|}
block|,
block|{
literal|"2,_suiword\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Suword\n"
block|}
block|,
block|{
literal|"1,_setrq\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Setrq\n"
block|}
block|,
block|{
literal|"1,_remrq\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Remrq\n"
block|}
block|,
block|{
literal|"0,_swtch\n"
block|,
literal|"	movpsl	-(sp)\n\ 	jsb	_Swtch\n"
block|}
block|,
block|{
literal|"1,_setjmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	clrl	r0\n\ 	movl	fp,(r1)+\n\ 	moval	1(pc),(r1)\n"
block|}
block|,
block|{
literal|"1,_longjmp\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Longjmp\n"
block|}
block|,
block|{
literal|"1,_ffs\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	ffs	$0,$32,r1,r0\n\ 	bneq	1f\n\ 	mnegl	$1,r0\n\ 1:\n\ 	incl	r0\n"
block|}
block|,
block|{
literal|"1,_htons\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	rotl	$8,r5,r0\n\ 	rotl	$-8,r5,r1\n\ 	movb	r1,r0\n\ 	movzwl	r0,r0\n"
block|}
block|,
block|{
literal|"1,_ntohs\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	rotl	$8,r5,r0\n\ 	rotl	$-8,r5,r1\n\ 	movb	r1,r0\n\ 	movzwl	r0,r0\n"
block|}
block|,
block|{
literal|"1,_htonl\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	rotl	$-8,r5,r0\n\ 	insv	r0,$16,$8,r0\n\ 	rotl	$8,r5,r1\n\ 	movb	r1,r0\n"
block|}
block|,
block|{
literal|"1,_ntohl\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	rotl	$-8,r5,r0\n\ 	insv	r0,$16,$8,r0\n\ 	rotl	$8,r5,r1\n\ 	movb	r1,r0\n"
block|}
block|,
block|{
literal|"2,__insque\n"
block|,
literal|"	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	insque	(r4),(r5)\n"
block|}
block|,
block|{
literal|"1,__remque\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	remque	(r5),r0\n"
block|}
block|,
block|{
literal|"2,__queue\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	insque	(r1),*4(r0)\n"
block|}
block|,
block|{
literal|"1,__dequeue\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	remque	*(r0),r0\n"
block|}
block|,
block|{
literal|"2,_imin\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5\n\ 	cmpl	r0,r5\n\ 	bleq	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_imax\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5\n\ 	cmpl	r0,r5\n\ 	bgeq	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_min\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5\n\ 	cmpl	r0,r5\n\ 	blequ	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_max\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5\n\ 	cmpl	r0,r5\n\ 	bgequ	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
block|{
literal|"4,_spl0\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0,$8\n"
block|}
block|,
block|{
literal|"4,_spl1\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x11,$8\n"
block|}
block|,
block|{
literal|"4,_spl3\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x13,$8\n"
block|}
block|,
block|{
literal|"4,_spl7\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x17,$8\n"
block|}
block|,
block|{
literal|"4,_spl8\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|"4,_splimp\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|"4,_splsoftclock\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x8,$8\n"
block|}
block|,
block|{
literal|"4,_splnet\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0xc,$8\n"
block|}
block|,
block|{
literal|"4,_splbio\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|"4,_spltty\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|"4,_splclock\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|"4,_splhigh\n"
block|,
literal|"	mfpr	$8,r0\n\ 	mtpr	$0x18,$8\n"
block|}
block|,
block|{
literal|"8,_splx\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	$8,r0\n\ 	mtpr	r1,$8\n"
block|}
block|,
block|{
literal|"8,_mfpr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mfpr	r1,r0\n"
block|}
block|,
block|{
literal|"12,_mtpr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	mtpr	r0,r1\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|"8,_uncache\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	mtpr	r1,$0x1c\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|"4,_setsoftclock\n"
block|,
literal|"	mtpr	$0x8,$0x10\n"
block|}
block|,
block|{
literal|"8,_fuibyte\n"
block|,
literal|"	callf	$8,_fubyte\n"
block|}
block|,
block|{
literal|"8,_fuiword\n"
block|,
literal|"	callf	$8,_fuword\n"
block|}
block|,
block|{
literal|"12,_suibyte\n"
block|,
literal|"	callf	$12,_subyte\n"
block|}
block|,
block|{
literal|"12,_suiword\n"
block|,
literal|"	callf	$12,_suword\n"
block|}
block|,
block|{
literal|"8,_setjmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	clrl	r0\n\ 	movab	(fp),(r1)\n\ 	addl2	$4,r1\n\ 	movab	1(pc),(r1)\n"
block|}
block|,
block|{
literal|"8,_ffs\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	ffs	r1,r0\n\ 	bgeq	1f\n\ 	mnegl	$1,r0\n\ 1:\n\ 	incl	r0\n"
block|}
block|,
block|{
literal|"12,__insque\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	insque	(r0),(r1)\n"
block|}
block|,
block|{
literal|"8,__remque\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	remque	(r1)\n"
block|}
block|,
block|{
literal|"12,_imin\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bleq	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"12,_imax\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bgeq	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"12,_min\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	blequ	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"12,_max\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	bgequ	1f\n\ 	movl	r1,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"12,__movow\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	movow	r0,(r1)\n"
block|}
block|,
block|{
literal|"12,__movob\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r0\n\ 	movob	r0,(r1)\n"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|mc68000
argument_list|)
comment|/* someday... */
endif|#
directive|endif
block|{
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

