begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1979, 1984 Regents of the University of California   * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)langpats.c	5.5 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"inline.h"
end_include

begin_comment
comment|/*  * Pattern table for Pascal library routines.  */
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
comment|/*  * General Pascal library routines  */
block|{
literal|2
block|,
literal|"_ROUND\n"
block|,
literal|"	movd	(sp)+,r0\n\ 	cvtrdl	r0,r0\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_TRUNC\n"
block|,
literal|"	movd	(sp)+,r0\n\ 	cvtdl	r0,r0\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_ACTFILE\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	12(r1),r0\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_FCALL\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	movl	(sp),r0\n\ 	movc3	4(r0),__disply+8,(r5)\n\ 	movl	(sp)+,r0\n\ 	movc3	4(r0),8(r0),__disply+8\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_FRTN\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r5\n\ 	movc3	4(r0),(r5),__disply+8\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_FSAV\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	movl	(sp),r5\n\ 	movl	r3,(r5)\n\ 	ashl	$3,r4,4(r5)\n\ 	movc3	4(r5),__disply+8,8(r5)\n\ 	movl	(sp)+,r0\n"
block|}
block|,
comment|/*  * Pascal relational comparisons  */
block|{
literal|3
block|,
literal|"_RELEQ\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	r0,r4\n\ 1:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jleq	3f\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jeql	1b\n\ 2:\n\ 	clrl	r0\n\ 	jbr	4f\n\ 3:\n\ 	cmpc3	r4,(r1),(r3)\n\ 	jneq	2b\n\ 	incl	r0\n\ 4:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RELNE\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	r0,r4\n\ 1:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jleq	3f\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jeql	1b\n\ 2:\n\ 	movl	$1,r0\n\ 	jbr	4f\n\ 3:\n\ 	cmpc3	r4,(r1),(r3)\n\ 	jneq	2b\n\ 4:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RELSLT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jlss	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RELSLE\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jleq	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RELSGT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jgtr	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RELSGE\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jgeq	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
comment|/*  * Pascal set operations.  */
block|{
literal|4
block|,
literal|"_ADDT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r4\n\ 	movl	r0,r3\n\ 1:\n\ 	bisl3	(r1)+,(r2)+,(r3)+\n\ 	sobgtr	r4,1b\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_SUBT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r4\n\ 	movl	r0,r3\n\ 1:\n\ 	bicl3	(r2)+,(r1)+,(r3)+\n\ 	sobgtr	r4,1b\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_MULT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r4\n\ 	movl	r0,r3\n\ 1:\n\ 	mcoml	(r1)+,r5\n\ 	bicl3	r5,(r2)+,(r3)+\n\ 	sobgtr	r4,1b\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_IN\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	clrl	r0\n\ 	subl2	r2,r1\n\ 	cmpl	r1,r3\n\ 	jgtru	1f\n\ 	jbc	r1,(r4),1f\n\ 	incl	r0\n\ 1:\n"
block|}
block|,
comment|/*  * Pascal runtime checks  */
block|{
literal|1
block|,
literal|"_ASRT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	tstl	r0\n\ 	jneq	1f\n\ 	pushl	$0\n\ 	pushl	$_EASRT\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_ASRTS\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	tstl	r0\n\ 	jneq	1f\n\ 	pushl	r1\n\ 	pushl	$_EASRTS\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_CHR\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	cmpl	r0,$127\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ECHR\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_LINO\n"
block|,
literal|"	incl	__stcnt\n\ 	cmpl	__stcnt,__stlim\n\ 	jlss	1f\n\ 	pushl	__stcnt\n\ 	pushl	$_ELINO\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_NIL\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	cmpl	r0,__maxptr\n\ 	jgtr	1f\n\ 	cmpl	r0,__minptr\n\ 	jgeq	2f\n\ 1:\n\ 	pushl	$0\n\ 	pushl	$_ENIL\n\ 	calls	$2,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_RANDOM\n"
block|,
literal|"	movd	(sp)+,r0\n\ 	emul	__seed,$1103515245,$0,r0\n\ 	ediv	$0x7fffffff,r0,r1,r0\n\ 	movl	r0,__seed\n\ 	cvtld	r0,r0\n\ 	divd2	$0d2.147483647e+09,r0\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RANG4\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	cmpl	r0,r1\n\ 	jlss	1f\n\ 	cmpl	r0,r2\n\ 	jleq	2f\n\ 1:\n\ 	pushl	r0\n\ 	pushl	$_ERANG\n\ 	calls	$2,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_RSNG4\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ERANG\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_SEED\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	__seed,r0\n\ 	movl	r1,__seed\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_SUBSC\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	cmpl	r0,r1\n\ 	jlss	1f\n\ 	cmpl	r0,r2\n\ 	jleq	2f\n\ 1:\n\ 	pushl	r0\n\ 	pushl	$_ESUBSC\n\ 	calls	$2,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_SUBSCZ\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ESUBSC\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
endif|#
directive|endif
endif|vax
ifdef|#
directive|ifdef
name|mc68000
comment|/*  * General Pascal library routines  */
block|{
literal|1
block|,
literal|"_ACTFILE\n"
block|,
literal|"	movl	sp@+,a0\n\ 	movl	a0@(12),d0\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_ADDT\n"
block|,
literal|"	movl	sp@+,a0\n\ 	movl	sp@+,d0\n\ 	movl	sp@+,a1\n\ 	movl	sp@+,d1\n\ 	movl	a0,sp@-\n\ 	movl	a2,sp@-\n\ 	movl	d0,a2\n\ 	subql	#1,d1\n\ 1:\n\ 	movl	a2@+,d0\n\ 	orl	a1@+,d0\n\ 	movl	d0,a0@+\n\ 	dbra	d1,1b\n\ 	movl	sp@+,a2\n\ 	movl	sp@+,d0\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_SUBT\n"
block|,
literal|"	movl	sp@+,a0\n\ 	movl	sp@+,d0\n\ 	movl	sp@+,a1\n\ 	movl	sp@+,d1\n\ 	movl	a0,sp@-\n\ 	movl	a2,sp@-\n\ 	movl	d0,a2\n\ 	subql	#1,d1\n\ 1:\n\ 	movl	a1@+,d0\n\ 	notl	d0\n\ 	andl	a2@+,d0\n\ 	movl	d0,a0@+\n\ 	dbra	d1,1b\n\ 	movl	sp@+,a2\n\ 	movl	sp@+,d0\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_MULT\n"
block|,
literal|"	movl	sp@+,a0\n\ 	movl	sp@+,d0\n\ 	movl	sp@+,a1\n\ 	movl	sp@+,d1\n\ 	movl	a0,sp@-\n\ 	movl	a2,sp@-\n\ 	movl	d0,a2\n\ 	subql	#1,d1\n\ 1:\n\ 	movl	a2@+,d0\n\ 	andl	a1@+,d0\n\ 	movl	d0,a0@+\n\ 	dbra	d1,1b\n\ 	movl	sp@+,a2\n\ 	movl	sp@+,d0\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_IN\n"
block|,
literal|"	movl	sp@+,d0\n\ 	movl	sp@+,a0\n\ 	movl	sp@+,d1\n\ 	movl	sp@+,a1\n\ 	subl	a0,d0\n\ 	cmpl	d1,d0\n\ 	jhi	1f\n\ 	movl	d0,d1\n\ 	lsrl	#3,d1\n\ 	btst	d0,a1@(0,d1:l)\n\ 	jeq	1f\n\ 	moveq	#1,d0\n\ 	jra	2f\n\ 1:\n\ 	moveq	#0,d0\n\ 2:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RANG4\n"
block|,
literal|"	movl	sp@+,d0\n\ 	movl	sp@+,a0\n\ 	movl	sp@+,a1\n\ 	cmpl	a0,d0\n\ 	jlt	1f\n\ 	cmpl	a1,d0\n\ 	jle	2f\n\ 1:\n\ 	pea	_ERANG\n\ 	jbsr	_ERROR\n\ 	addqw	#4,sp\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_RSNG4\n"
block|,
literal|"	movl	sp@+,a0\n\ 	movl	sp@+,a1\n\ 	cmpl	a1,a0\n\ 	jls	1f\n\ 	pea	_ERANG\n\ 	jbsr	_ERROR\n\ 	addqw	#4,sp\n\ 1:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_SUBSC\n"
block|,
literal|"	movl	sp@+,d0\n\ 	movl	sp@+,a0\n\ 	movl	sp@+,a1\n\ 	cmpl	a0,d0\n\ 	jlt	1f\n\ 	cmpl	a1,d0\n\ 	jle	2f\n\ 1:\n\ 	pea	_ESUBSC\n\ 	jbsr	_ERROR\n\ 	addqw	#4,sp\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_SUBSCZ\n"
block|,
literal|"	movl	sp@+,a0\n\ 	movl	sp@+,a1\n\ 	cmpl	a1,a0\n\ 	jls	1f\n\ 	pea	_ESUBSC\n\ 	jbsr	_ERROR\n\ 	addqw	#4,sp\n\ 1:\n"
block|}
block|,
endif|#
directive|endif
endif|mc68000
ifdef|#
directive|ifdef
name|tahoe
block|{
literal|2
block|,
literal|"_TRUNC\n"
block|,
literal|"	ldd	(sp)\n\ 	movab	8(sp),sp\n\ 	cvdl	r0\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_ACTFILE\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	12(r1),r0\n"
block|}
block|,
comment|/*  * Pascal set operations.  */
block|{
literal|4
block|,
literal|"_ADDT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r3\n\ 	clrl	r4\n\ 1:\n\ 	orl3	(r1)[r4],(r2)[r4],(r0)[r4]\n\ 	aoblss	r3,r4,1b\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_SUBT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r3\n\ 	decl	r3\n\ 1:\n\ 	mcoml	(r2)[r3],r4\n\ 	andl3	r4,(r1)[r3],(r0)[r3]\n\ 	decl	r3\n\ 	jgeq	1b\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_MULT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r3\n\ 	clrl	r4\n\ 1:\n\ 	andl3	(r1)[r4],(r2)[r4],(r0)[r4]\n\ 	aoblss	r3,r4,1b\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_IN\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	clrl	r0\n\ 	subl2	r2,r1\n\ 	cmpl	r1,r3\n\ 	jgtru	1f\n\ 	shrl	$3,r1,r2\n\ 	movzbl	(r4)[r2],r3\n\ 	andl2	$7,r1\n\ 	jbc	r1,r3,1f\n\ 	incl	r0\n\ 1:\n"
block|}
block|,
comment|/*  * Pascal runtime checks  */
block|{
literal|1
block|,
literal|"_ASRT\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	tstl	r0\n\ 	jneq	1f\n\ 	pushl	$0\n\ 	pushl	$_EASRT\n\ 	callf	$12,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_ASRTS\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	tstl	r0\n\ 	jneq	1f\n\ 	pushl	r1\n\ 	pushl	$_EASRTS\n\ 	callf	$12,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_CHR\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	cmpl	r0,$127\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ECHR\n\ 	callf	$12,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|0
block|,
literal|"_LINO\n"
block|,
literal|"	incl	__stcnt\n\ 	cmpl	__stcnt,__stlim\n\ 	jlss	1f\n\ 	pushl	__stcnt\n\ 	pushl	$_ELINO\n\ 	callf	$12,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_NIL\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	cmpl	r0,__maxptr\n\ 	jgtr	1f\n\ 	cmpl	r0,__minptr\n\ 	jgeq	2f\n\ 1:\n\ 	pushl	$0\n\ 	pushl	$_ENIL\n\ 	callf	$12,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_RANG4\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	cmpl	r0,r1\n\ 	jlss	1f\n\ 	cmpl	r0,r2\n\ 	jleq	2f\n\ 1:\n\ 	pushl	r0\n\ 	pushl	$_ERANG\n\ 	callf	$12,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_RSNG4\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ERANG\n\ 	callf	$12,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_SEED\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	__seed,r0\n\ 	movl	r1,__seed\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_SUBSC\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	cmpl	r0,r1\n\ 	jlss	1f\n\ 	cmpl	r0,r2\n\ 	jleq	2f\n\ 1:\n\ 	pushl	r0\n\ 	pushl	$_ESUBSC\n\ 	callf	$12,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_SUBSCZ\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	cmpl	r0,r1\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ESUBSC\n\ 	callf	$12,_ERROR\n\ 1:\n"
block|}
block|,
endif|#
directive|endif
endif|tahoe
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

