begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1984 Regents of the University of California */
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
literal|"@(#)langpats.c	2.8 (Berkeley) 2/20/85"
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
ifdef|#
directive|ifdef
name|vax
block|{
literal|"1,_ffs\n"
block|,
literal|"	movl	(sp)+,r1$\n\ 	ffs	$0,$32,r1,r0\n\ 	bneq	1f\n\ 	mnegl	$1,r0\n\ 1:\n\ 	incl	r0\n"
block|}
block|,
block|{
literal|"1,_htons\n"
block|,
literal|"	movl	(sp)+,r5$\n\ 	rotl	$8,r5,r0\n\ 	rotl	$-8,r5,r1\n\ 	movb	r1,r0\n\ 	movzwl	r0,r0\n"
block|}
block|,
block|{
literal|"1,_ntohs\n"
block|,
literal|"	movl	(sp)+,r5$\n\ 	rotl	$8,r5,r0\n\ 	rotl	$-8,r5,r1\n\ 	movb	r1,r0\n\ 	movzwl	r0,r0\n"
block|}
block|,
block|{
literal|"1,_htonl\n"
block|,
literal|"	movl	(sp)+,r5$\n\ 	rotl	$-8,r5,r0\n\ 	insv	r0,$16,$8,r0\n\ 	rotl	$8,r5,r1\n\ 	movb	r1,r0\n"
block|}
block|,
block|{
literal|"1,_ntohl\n"
block|,
literal|"	movl	(sp)+,r5$\n\ 	rotl	$-8,r5,r0\n\ 	insv	r0,$16,$8,r0\n\ 	rotl	$8,r5,r1\n\ 	movb	r1,r0\n"
block|}
block|,
block|{
literal|"2,__insque\n"
block|,
literal|"	movl	(sp)+,r4*\n\ 	movl	(sp)+,r5*\n\ 	insque	(r4),(r5)\n"
block|}
block|,
block|{
literal|"1,__remque\n"
block|,
literal|"	movl	(sp)+,r5*\n\ 	remque	(r5),r0\n"
block|}
block|,
block|{
literal|"2,__queue\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1*\n\ 	insque	(r1),*4(r0)\n"
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
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5$\n\ 	cmpl	r0,r5\n\ 	bleq	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_imax\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5$\n\ 	cmpl	r0,r5\n\ 	bgeq	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_min\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5$\n\ 	cmpl	r0,r5\n\ 	blequ	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_max\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5$\n\ 	cmpl	r0,r5\n\ 	bgequ	1f\n\ 	movl	r5,r0\n\ 1:\n"
block|}
block|,
endif|#
directive|endif
endif|vax
ifdef|#
directive|ifdef
name|mc68000
comment|/* someday... */
endif|#
directive|endif
endif|mc68000
block|{
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

