begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)langpats.c	1.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In-line assembly code expander for  * the kernel.  This code is stolen from  * pc2 and the old asm.sed script.  */
end_comment

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
value|139
end_define

begin_comment
comment|/*  * Pattern table.  */
end_comment

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
block|{
literal|"$0,_spl0\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0,$18\n"
block|}
block|,
block|{
literal|"$0,_spl1\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$1,$18\n"
block|}
block|,
block|{
literal|"$0,_splsoftclock\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x8,$18\n"
block|}
block|,
block|{
literal|"$0,_splnet\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0xc,$18\n"
block|}
block|,
block|{
literal|"$0,_splimp\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x16,$18\n"
block|}
block|,
block|{
literal|"$0,_spl4\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x14,$18\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|"r[0-9]*,_spl4\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x14,$18\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|"$0,_splbio"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|"r[0-9]*,_splbio"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|"$0,_spltty"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|"r[0-9]*,_spltty\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|"$0,_spl5\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|"r[0-9]*,_spl5\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x15,$18\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|"$0,_splclock\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x18,$18\n"
block|}
block|,
block|{
literal|"$0,_spl6\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x18,$18\n"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
literal|"r[0-9]*,_spl6\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x18,$18\n"
block|}
block|,
endif|#
directive|endif
block|{
literal|"$0,_spl7\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	$0x1f,$18\n"
block|}
block|,
block|{
literal|"$1,_splx\n"
block|,
literal|"	mfpr	$18,r0\n\ 	mtpr	(sp)+,$18\n"
block|}
block|,
block|{
literal|"$1,_mfpr\n"
block|,
literal|"	mfpr	(sp)+,r0\n"
block|}
block|,
block|{
literal|"$2,_mtpr\n"
block|,
literal|"	mtpr	4(sp),(sp)\n\ 	addl2	$8,sp\n"
block|}
block|,
block|{
literal|"$0,_setsoftclock\n"
block|,
literal|"	mtpr	$0x8,$0x14\n"
block|}
block|,
block|{
literal|"$1,_resume\n"
block|,
literal|"	ashl	$9,(sp)+,r0 \n\ 	movpsl	-(sp) \n\ 	jsb	_Resume\n"
block|}
block|,
block|{
literal|"$3,_bcopy\n"
block|,
literal|"	movc3	8(sp),*(sp),*4(sp)\n\ 	addl2	$12,sp\n"
block|}
block|,
block|{
literal|"$3,_ovbcopy\n"
block|,
literal|"	movc3	8(sp),*(sp),*4(sp)\n\ 	addl2	$12,sp\n"
block|}
block|,
block|{
literal|"$2,_bzero\n"
block|,
literal|"	movc5	$0,(r0),$0,4(sp),*(sp)\n\ 	addl2	$8,sp\n"
block|}
block|,
block|{
literal|"$3,_bcmp\n"
block|,
literal|"	popr	$0x7\n\ 	cmpc3	r2,(r0),(r1)\n"
block|}
block|,
block|{
literal|"$3,_strncmp\n"
block|,
literal|"	cmpc3	8(sp),*(sp),*4(sp)\n\ 	addl2	$12,sp\n"
block|}
block|,
block|{
literal|"$2,_blkclr\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,(sp)\n\ 	movc5	$0,(r3),$0,r0,(r3)\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	(sp),r0\n\ 	jgtr	1b\n\ 	movl	(sp)+,r0\n\ 	movc5	$0,(r3),$0,r0,(r3)\n"
block|}
block|,
block|{
literal|"$1,_strlen\n"
block|,
literal|"	movl	(sp),r1\n\ 1:\n\ 	locc	$0,$65535,(r1)\n\ 	jeql	1b\n\ 	subl3	(sp)+,r1,r0\n"
block|}
block|,
block|{
literal|"$4,_scanc\n"
block|,
literal|"	popr	$0xf\n\ 	scanc	r0,(r1),(r2),r3\n"
block|}
block|,
block|{
literal|"$3,_copyin\n"
block|,
literal|"	jsb	_Copyin\n\ 	addl2	$12,sp\n"
block|}
block|,
block|{
literal|"$3,_copyout\n"
block|,
literal|"	jsb	_Copyout\n\ 	addl2	$12,sp\n"
block|}
block|,
block|{
literal|"$1,_fubyte\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	jsb	_Fubyte\n"
block|}
block|,
block|{
literal|"$1,_fuibyte\n"
block|,
literal|"	movl (sp)+,r0\n\ 	jsb	_Fubyte\n"
block|}
block|,
block|{
literal|"$1,_fuword\n"
block|,
literal|"	movl (sp)+,r0\n\ 	jsb	_Fuword\n"
block|}
block|,
block|{
literal|"$1,_fuiword\n"
block|,
literal|"	movl (sp)+,r0\n\ 	jsb	_Fuword\n"
block|}
block|,
block|{
literal|"$2,_subyte\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Subyte\n"
block|}
block|,
block|{
literal|"$2,_suibyte\n"
block|,
literal|"	movl (sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Subyte\n"
block|}
block|,
block|{
literal|"$2,_suword\n"
block|,
literal|"	movl (sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Suword\n"
block|}
block|,
block|{
literal|"$2,_suiword\n"
block|,
literal|"	movl (sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	jsb	_Suword\n"
block|}
block|,
block|{
literal|"$1,_setrq\n"
block|,
literal|"	movl	(sp)+,r0 \n\ 	jsb	_Setrq\n"
block|}
block|,
block|{
literal|"$1,_remrq\n"
block|,
literal|"	movl	(sp)+,r0 \n\ 	jsb	_Remrq\n"
block|}
block|,
block|{
literal|"$0,_swtch\n"
block|,
literal|"	movpsl	-(sp)\n\ 	jsb	_Swtch\n"
block|}
block|,
block|{
literal|"$1,_setjmp\n"
block|,
literal|"	movl	(sp)+,r0 \n\ 	jsb	_Setjmp\n"
block|}
block|,
block|{
literal|"$1,_longjmp\n"
block|,
literal|"	movl	(sp)+,r0 \n\ 	jsb	_Longjmp\n"
block|}
block|,
block|{
literal|"$1,_ffs\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	ffs	$0,$32,r1,r0 \n\ 	bneq	1f \n\ 	mnegl	$1,r0 \n\ 1: \n\ 	incl	r0\n"
block|}
block|,
block|{
literal|"$1,_htons\n"
block|,
literal|"	rotl	$8,(sp),r0\n\ 	movb	1(sp),r0\n\ 	movzwl	r0,r0\n\ 	addl2	$4,sp\n"
block|}
block|,
block|{
literal|"$1,_ntohs\n"
block|,
literal|"	rotl	$8,(sp),r0\n\ 	movb	1(sp),r0\n\ 	movzwl	r0,r0\n\ 	addl2	$4,sp\n"
block|}
block|,
block|{
literal|"$1,_htonl\n"
block|,
literal|"	rotl	$-8,(sp),r0\n\ 	insv	r0,$16,$8,r0\n\ 	movb	3(sp),r0\n\ 	addl2	$4,sp\n"
block|}
block|,
block|{
literal|"$1,_ntohl\n"
block|,
literal|"	rotl	$-8,(sp),r0\n\ 	insv	r0,$16,$8,r0\n\ 	movb	3(sp),r0\n\ 	addl2	$4,sp\n"
block|}
block|,
block|{
literal|"$2,__insque\n"
block|,
literal|"	insque	*(sp)+,*(sp)+\n"
block|}
block|,
block|{
literal|"$1,__remque\n"
block|,
literal|"	remque	*(sp)+,r0\n"
block|}
block|,
block|{
literal|"$2,__queue\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	insque	r1,*4(r0)\n"
block|}
block|,
block|{
literal|"$1,__dequeue\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	remque	*(r0),r0\n"
block|}
block|, }
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
value|{\     hash = 0; rehash = 1; ccp = cp; \     do	{ \     	hash *= (int)*ccp++; \     } while (*ccp&& *ccp != '\n'); \     hash>>= 7; hash %= HSHSIZ; hp =&htbl[hash]; size = ccp - cp + 1; \ }
end_define

begin_define
define|#
directive|define
name|REHASH
parameter_list|(
name|hp
parameter_list|)
value|{\     hp += rehash; rehash += 2; \     if (hp>=&htbl[HSHSIZ]) \     	hp -= HSHSIZ; \ }
end_define

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|struct
name|pats
modifier|*
name|pp
decl_stmt|,
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
comment|/* 	 * Set up the hash table. 	 */
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
argument_list|(
name|ptab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ptab
index|[
literal|0
index|]
argument_list|)
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
comment|/* 	 * Check each line and replace as appropriate. 	 */
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
define|#
directive|define
name|CALLS
value|"calls\t"
if|if
condition|(
name|strncmp
argument_list|(
name|cp
argument_list|,
name|CALLS
argument_list|,
sizeof|sizeof
argument_list|(
name|CALLS
argument_list|)
operator|-
literal|1
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
sizeof|sizeof
argument_list|(
name|CALLS
argument_list|)
operator|-
literal|1
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
name|strncmp
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

