begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)pc2.c 1.13 6/1/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/*  * The hash table must be at least twice as big as the number  * of patterns, preferably bigger. It must also be a prime number  */
end_comment

begin_define
define|#
directive|define
name|HSHSIZ
value|101
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|CALLTEMPLATE
value|"calls\t$"
end_define

begin_define
define|#
directive|define
name|TEMPLATESIZE
value|7
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_define
define|#
directive|define
name|CALLTEMPLATE
value|"jbsr\t"
end_define

begin_define
define|#
directive|define
name|TEMPLATESIZE
value|5
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_struct
struct|struct
name|pats
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|replace
decl_stmt|;
block|}
name|ptab
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|vax
comment|/*  * C library routines  */
block|{
literal|"1,_fgetc\n"
block|,
literal|"	sobgeq	*(sp),1f\n\ 	calls	$1,__filbuf\n\ 	jbr     2f\n\ 1:\n\ 	addl3	$4,(sp)+,r1\n\ 	movzbl	*(r1),r0\n\ 	incl	(r1)\n\ 2:\n"
block|}
block|,
block|{
literal|"2,_fputc\n"
block|,
literal|"	sobgeq	*4(sp),1f\n\ 	calls	$2,__flsbuf\n\ 	jbr	2f\n\ 1:\n\ 	popr	$0x3\n\ 	movb	r0,*4(r1)\n\ 	incl	4(r1)\n\ 2:\n"
block|}
block|,
comment|/*  * VAX special instructions  */
block|{
literal|"3,_blkcpy\n"
block|,
literal|"	popr	$0xa\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,(sp)\n\ 	movc3	r0,(r1),(r3)\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	(sp),r0\n\ 	jgtr	1b\n\ 	movl	(sp)+,r0\n\ 	movc3	r0,(r1),(r3)\n"
block|}
block|,
block|{
literal|"2,_blkclr\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,(sp)\n\ 	movc5	$0,(r3),$0,r0,(r3)\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	(sp),r0\n\ 	jgtr	1b\n\ 	movl	(sp)+,r0\n\ 	movc5	$0,(r3),$0,r0,(r3)\n"
block|}
block|,
block|{
literal|"3,_LOCC\n"
block|,
literal|"	popr	$0x30\n\ 	movl	(sp)+,r1\n\ 1:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r5,r0\n\ 	jleq	1f\n\ 	subl2	r0,r5\n\ 	locc	r4,r0,(r1)\n\ 	jeql	1b\n\ 	addl2	r5,r0\n\ 	jbr	2f\n\ 1:\n\ 	locc	r4,r5,(r1)\n\ 2:\n"
block|}
block|,
block|{
literal|"2,_ROUND\n"
block|,
literal|"	cvtrdl	(sp)+,r0\n"
block|}
block|,
block|{
literal|"2,_TRUNC\n"
block|,
literal|"	cvtdl	(sp)+,r0\n"
block|}
block|,
comment|/*  * General Pascal library routines  */
block|{
literal|"1,_ACTFILE\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	12(r1),r0\n"
block|}
block|,
block|{
literal|"2,_FCALL\n"
block|,
literal|"	movl	4(sp),r0\n\ 	movc3	4(r0),__disply+8,*(sp)+\n\ 	movl	(sp)+,r0\n\ 	movc3	4(r0),8(r0),__disply+8\n"
block|}
block|,
block|{
literal|"2,_FRTN\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movc3	4(r0),*(sp)+,__disply+8\n"
block|}
block|,
block|{
literal|"3,_FSAV\n"
block|,
literal|"	movl	8(sp),r0\n\ 	movl	(sp)+,(r0)\n\ 	ashl	$3,(sp)+,4(r0)\n\ 	movc3	4(r0),__disply+8,8(r0)\n\ 	movl	(sp)+,r0\n"
block|}
block|,
comment|/*  * Pascal relational comparisons  */
block|{
literal|"3,_RELEQ\n"
block|,
literal|"	popr	$0xb\n\ 	movl	r0,r4\n\ 1:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jleq	3f\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jeql	1b\n\ 2:\n\ 	clrl	r0\n\ 	jbr	4f\n\ 3:\n\ 	cmpc3	r4,(r1),(r3)\n\ 	jneq	2b\n\ 	incl	r0\n\ 4:\n"
block|}
block|,
block|{
literal|"3,_RELNE\n"
block|,
literal|"	popr	$0xb\n\ 	movl	r0,r4\n\ 1:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jleq	3f\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jeql	1b\n\ 2:\n\ 	movl	$1,r0\n\ 	jbr	4f\n\ 3:\n\ 	cmpc3	r4,(r1),(r3)\n\ 	jneq	2b\n\ 4:\n"
block|}
block|,
block|{
literal|"3,_RELSLT\n"
block|,
literal|"	popr	$0xb\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jlss	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
block|{
literal|"3,_RELSLE\n"
block|,
literal|"	popr	$0xb\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jleq	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
block|{
literal|"3,_RELSGT\n"
block|,
literal|"	popr	$0xb\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jgtr	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
block|{
literal|"3,_RELSGE\n"
block|,
literal|"	popr	$0xb\n\ 	movl	r0,r4\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,r4\n\ 	cmpc3	r0,(r1),(r3)\n\ 	jneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r4,r0\n\ 	jgtr	1b\n\ 	cmpc3	r4,(r1),(r3)\n\ 3:\n\ 	jgeq	4f\n\ 	clrl	r0\n\ 	jbr	5f\n\ 4:\n\ 	movl	$1,r0\n\ 5:\n"
block|}
block|,
comment|/*  * Pascal set operations.  */
block|{
literal|"4,_ADDT\n"
block|,
literal|"	popr	$0x17\n\ 	movl	r0,r3\n\ 1:\n\ 	bisl3	(r1)+,(r2)+,(r3)+\n\ 	sobgtr	r4,1b\n"
block|}
block|,
block|{
literal|"4,_SUBT\n"
block|,
literal|"	popr	$0x17\n\ 	movl	r0,r3\n\ 1:\n\ 	bicl3	(r2)+,(r1)+,(r3)+\n\ 	sobgtr	r4,1b\n"
block|}
block|,
block|{
literal|"4,_MULT\n"
block|,
literal|"	popr	$0x17\n\ 	movl	r0,r3\n\ 1:\n\ 	mcoml	(r1)+,r5\n\ 	bicl3	r5,(r2)+,(r3)+\n\ 	sobgtr	r4,1b\n"
block|}
block|,
block|{
literal|"4,_IN\n"
block|,
literal|"	popr	$0x1e\n\ 	clrl	r0\n\ 	subl2	r2,r1\n\ 	cmpl	r1,r3\n\ 	jgtru	1f\n\ 	jbc	r1,(r4),1f\n\ 	incl	r0\n\ 1:\n"
block|}
block|,
comment|/*  * Pascal runtime checks  */
block|{
literal|"1,_ASRT\n"
block|,
literal|"	tstl	(sp)+\n\ 	jneq	1f\n\ 	pushl	$0\n\ 	pushl	$_EASRT\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|"2,_ASRTS\n"
block|,
literal|"	popr	$0x03\n\ 	tstl	r0\n\ 	jneq	1f\n\ 	pushl	r1\n\ 	pushl	$_EASRTS\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|"1,_CHR\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	cmpl	r0,$127\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ECHR\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|"0,_LINO\n"
block|,
literal|"	incl	__stcnt\n\ 	cmpl	__stcnt,__stlim\n\ 	jlss	1f\n\ 	pushl	__stcnt\n\ 	pushl	$_ELINO\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|"1,_NIL\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	cmpl	r0,__maxptr\n\ 	jgtr	1f\n\ 	cmpl	r0,__minptr\n\ 	jgeq	2f\n\ 1:\n\ 	pushl	$0\n\ 	pushl	$_ENIL\n\ 	calls	$2,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|"2,_RANDOM\n"
block|,
literal|"	addl2	$8,sp\n\ 	emul	__seed,$1103515245,$0,r0\n\ 	ediv	$0x7fffffff,r0,r1,r0\n\ 	movl	r0,__seed\n\ 	cvtld	r0,r0\n\ 	divd2	$0d2.147483647e+09,r0\n"
block|}
block|,
block|{
literal|"3,_RANG4\n"
block|,
literal|"	popr	$0x07\n\ 	cmpl	r0,r1\n\ 	jlss	1f\n\ 	cmpl	r0,r2\n\ 	jleq	2f\n\ 1:\n\ 	pushl	r0\n\ 	pushl	$_ERANG\n\ 	calls	$2,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|"2,_RSNG4\n"
block|,
literal|"	popr	$0x03\n\ 	cmpl	r0,r1\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ERANG\n\ 	calls	$2,_ERROR\n\ 1:\n"
block|}
block|,
block|{
literal|"1,_SEED\n"
block|,
literal|"	movl	__seed,r0\n\ 	movl	(sp)+,__seed\n"
block|}
block|,
block|{
literal|"3,_SUBSC\n"
block|,
literal|"	popr	$0x07\n\ 	cmpl	r0,r1\n\ 	jlss	1f\n\ 	cmpl	r0,r2\n\ 	jleq	2f\n\ 1:\n\ 	pushl	r0\n\ 	pushl	$_ESUBSC\n\ 	calls	$2,_ERROR\n\ 2:\n"
block|}
block|,
block|{
literal|"2,_SUBSCZ\n"
block|,
literal|"	popr	$0x03\n\ 	cmpl	r0,r1\n\ 	jlequ	1f\n\ 	pushl	r0\n\ 	pushl	$_ESUBSC\n\ 	calls	$2,_ERROR\n\ 1:\n"
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
literal|"_ACTFILE\n"
block|,
literal|"	movl	sp@,a0\n\ 	movl	a0@(12),d0\n"
block|}
block|,
block|{
literal|"_ADDT\n"
block|,
literal|"	movl	a2,sp@-\n\ 	movl	sp@(8),a2\n\ 	movl	sp@(12),a1\n\ 	movl	sp@(4),a0\n\ 	movl	sp@(16),d1\n\ 	subql	#1,d1\n\ 1:\n\ 	movl	a2@+,d0\n\ 	orl	a1@+,d0\n\ 	movl	d0,a0@+\n\ 	dbra	d1,1b\n\ 	movl	sp@+,a2\n\ 	movl	sp@,d0\n"
block|}
block|,
block|{
literal|"_SUBT\n"
block|,
literal|"	movl	a2,sp@-\n\ 	movl	sp@(8),a2\n\ 	movl	sp@(12),a1\n\ 	movl	sp@(4),a0\n\ 	movl	sp@(16),d1\n\ 	subql	#1,d1\n\ 1:\n\ 	movl	a1@+,d0\n\ 	notl	d0\n\ 	andl	a2@+,d0\n\ 	movl	d0,a0@+\n\ 	dbra	d1,1b\n\ 	movl	sp@+,a2\n\ 	movl	sp@,d0\n"
block|}
block|,
block|{
literal|"_MULT\n"
block|,
literal|"	movl	a2,sp@-\n\ 	movl	sp@(8),a2\n\ 	movl	sp@(12),a1\n\ 	movl	sp@(4),a0\n\ 	movl	sp@(16),d1\n\ 	subql	#1,d1\n\ 1:\n\ 	movl	a2@+,d0\n\ 	andl	a1@+,d0\n\ 	movl	d0,a0@+\n\ 	dbra	d1,1b\n\ 	movl	sp@+,a2\n\ 	movl	sp@,d0\n"
block|}
block|,
block|{
literal|"_IN\n"
block|,
literal|"	movl	sp@,d1\n\ 	subl	sp@(4),d1\n\ 	cmpl	sp@(8),d1\n\ 	jbhi	1f\n\ 	movl	sp@(12),a0\n\ 	movl	d1,d0\n\ 	lsrl	#3,d0\n\ 	btst	d1,a0@(0,d0:l)\n\ 	jbne	1f\n\ 	moveq	#1,d0\n\ 	jbra	2f\n\ 1:\n\ 	moveq	#0,d0\n\ 2:\n"
block|}
block|,
endif|#
directive|endif
endif|mc68000
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|pats
modifier|*
name|htbl
index|[
name|HSHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HASH
parameter_list|(
name|cp
parameter_list|,
name|hp
parameter_list|)
value|{\ 	hash = 0; rehash = 1; ccp = cp; \ 	do	{ \ 		hash *= (int)*ccp++; \ 	} while (*ccp&& *ccp != '\n'); \ 	hash>>= 7; hash %= HSHSIZ; hp =&htbl[hash]; size = ccp - cp + 1; \ 	}
end_define

begin_define
define|#
directive|define
name|REHASH
parameter_list|(
name|hp
parameter_list|)
value|{\ 	hp += rehash; rehash += 2; \ 	if (hp>=&htbl[HSHSIZ]) \ 		hp -= HSHSIZ; \ 	}
end_define

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|struct
name|pats
modifier|*
name|pp
decl_stmt|;
specifier|register
name|struct
name|pats
modifier|*
modifier|*
name|hp
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|ccp
decl_stmt|,
modifier|*
name|lp
decl_stmt|;
specifier|register
name|int
name|hash
decl_stmt|,
name|rehash
decl_stmt|,
name|size
decl_stmt|;
name|char
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|freopen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
name|freopen
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|,
literal|"w"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
comment|/* 	 * set up the hash table 	 */
for|for
control|(
name|pp
operator|=
name|ptab
init|;
name|pp
operator|<
operator|&
name|ptab
index|[
sizeof|sizeof
name|ptab
operator|/
sizeof|sizeof
name|ptab
index|[
literal|0
index|]
index|]
condition|;
name|pp
operator|++
control|)
block|{
name|HASH
argument_list|(
name|pp
operator|->
name|name
argument_list|,
name|hp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|hp
condition|)
name|REHASH
argument_list|(
name|hp
argument_list|)
expr_stmt|;
operator|*
name|hp
operator|=
name|pp
expr_stmt|;
block|}
comment|/* 	 * check each line and replace as appropriate 	 */
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
name|BUFSIZ
argument_list|,
name|stdin
argument_list|)
condition|)
block|{
name|lp
operator|=
name|index
argument_list|(
name|line
argument_list|,
literal|':'
argument_list|)
expr_stmt|;
for|for
control|(
name|cp
operator|=
operator|(
name|lp
operator|!=
name|NULL
operator|)
condition|?
operator|++
name|lp
else|:
name|line
init|;
operator|*
name|cp
operator|==
literal|'\t'
condition|;
control|)
name|cp
operator|++
expr_stmt|;
if|if
condition|(
name|strcmpn
argument_list|(
name|cp
argument_list|,
name|CALLTEMPLATE
argument_list|,
name|TEMPLATESIZE
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fputs
argument_list|(
name|line
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|cp
operator|+=
name|TEMPLATESIZE
expr_stmt|;
name|HASH
argument_list|(
name|cp
argument_list|,
name|hp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|hp
condition|)
block|{
if|if
condition|(
name|strcmpn
argument_list|(
operator|(
operator|*
name|hp
operator|)
operator|->
name|name
argument_list|,
name|cp
argument_list|,
name|size
argument_list|)
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|lp
operator|!=
name|NULL
condition|)
block|{
operator|*
name|lp
operator|++
operator|=
literal|'\n'
expr_stmt|;
operator|*
name|lp
operator|=
literal|'\0'
expr_stmt|;
name|fputs
argument_list|(
name|line
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
name|fputs
argument_list|(
operator|(
operator|*
name|hp
operator|)
operator|->
name|replace
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
goto|goto
name|nextline
goto|;
block|}
name|REHASH
argument_list|(
name|hp
argument_list|)
expr_stmt|;
block|}
name|fputs
argument_list|(
name|line
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|nextline
label|:
empty_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

