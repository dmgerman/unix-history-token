begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)machpats.c	7.3 (Berkeley) %G%"
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
comment|/*  * Pattern table for special VAX instructions.  */
end_comment

begin_decl_stmt
name|struct
name|pats
name|machine_ptab
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|vax
block|{
literal|3
block|,
literal|"_blkcpy\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,(sp)\n\ 	movc3	r0,(r1),(r3)\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	(sp),r0\n\ 	jgtr	1b\n\ 	movl	(sp)+,r0\n\ 	movc3	r0,(r1),(r3)\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_bcopy\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r5\n\ 	movc3	r5,(r1),(r3)\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_ovbcopy\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	movc3	r5,(r3),(r4)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_blkclr\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,(sp)\n\ 	movc5	$0,(r3),$0,r0,(r3)\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	(sp),r0\n\ 	jgtr	1b\n\ 	movl	(sp)+,r0\n\ 	movc5	$0,(r3),$0,r0,(r3)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_bzero\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r5\n\ 	movc5	$0,(r3),$0,r5,(r3)\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_insque\n"
block|,
literal|"	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	insque	(r4),(r5)\n"
block|}
block|,
block|{
literal|1
block|,
literal|"_remque\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	remque	(r5),r0\n"
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
literal|0
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_decl_stmt
name|struct
name|pats
name|vax_ptab
index|[]
init|=
block|{
block|{
literal|3
block|,
literal|"_blkcmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	jbr	2f\n\ 1:\n\ 	subl2	r0,(sp)\n\ 	cmpc3	r0,(r1),(r3)\n\ 	bneq	3f\n\ 2:\n\ 	movzwl	$65535,r0\n\ 	cmpl	(sp),r0\n\ 	jgtr	1b\n\ 	movl	(sp)+,r0\n\ 	cmpc3	r0,(r1),(r3)\n\ 3:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_bcmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r5\n\ 	cmpc3	r5,(r1),(r3)\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_llocc\n"
block|,
literal|"	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	movl	(sp)+,r1\n\ 1:\n\ 	movzwl	$65535,r0\n\ 	cmpl	r5,r0\n\ 	jleq	1f\n\ 	subl2	r0,r5\n\ 	locc	r4,r0,(r1)\n\ 	jeql	1b\n\ 	addl2	r5,r0\n\ 	jbr	2f\n\ 1:\n\ 	locc	r4,r5,(r1)\n\ 2:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_locc\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	locc	r3,r4,(r5)\n"
block|}
block|,
block|{
literal|4
block|,
literal|"_scanc\n"
block|,
literal|"	movl	(sp)+,r2\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	scanc	r2,(r3),(r4),r5\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_skpc\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r4\n\ 	movl	(sp)+,r5\n\ 	skpc	r3,r4,(r5)\n"
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

begin_decl_stmt
name|struct
name|pats
name|vaxsubset_ptab
index|[]
init|=
block|{
block|{
literal|3
block|,
literal|"_blkcmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r0\n\ 2:\n\ 	cmpb	(r1)+,(r3)+\n\ 	jneq	3f\n\ 	sobgtr	r0,2b\n\ 3:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_bcmp\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r3\n\ 	movl	(sp)+,r0\n\ 	tstl	r0\n\ 	jeql	1f\n\ 2:\n\ 	cmpb	(r1)+,(r3)+\n\ 	jneq	1f\n\ 	sobgtr	r0,2b\n\ 1:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_llocc\n"
block|,
literal|"	movl	(sp)+,r4\n\ 	movl	(sp)+,r0\n\ 	tstl	r0\n\ 	jeql	1f\n\ 	movl	(sp)+,r1\n\ 2:\n\ 	cmpb	r4,(r1)+\n\ 	jeql	1f\n\ 	sobgtr	r0,2b\n\ 1:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_locc\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r0\n\ 	tstl	r0\n\ 	jeql	1f\n\ 	movl	(sp)+,r5\n\ 2:\n\ 	cmpb	r3,(r5)+\n\ 	jeql	1f\n\ 	sobgtr	r0,2b\n\ 1:\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_skpc\n"
block|,
literal|"	movl	(sp)+,r3\n\ 	movl	(sp)+,r0\n\ 	tstl	r0\n\ 	jeql	1f\n\ 	movl	(sp)+,r5\n\ 2:\n\ 	cmpb	r3,(r5)+\n\ 	jneq	1f\n\ 	sobgtr	r0,2b\n\ 1:\n"
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

