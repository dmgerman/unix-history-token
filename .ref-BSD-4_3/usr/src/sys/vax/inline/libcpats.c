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
literal|"@(#)libcpats.c	7.1 (Berkeley) 6/5/86"
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
comment|/*  * Pattern table for the C library.  */
end_comment

begin_decl_stmt
name|struct
name|pats
name|libc_ptab
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|vax
block|{
literal|1
block|,
literal|"_fgetc\n"
block|,
literal|"	sobgeq	*(sp),1f\n\ 	calls	$1,__filbuf\n\ 	jbr     2f\n\ 1:\n\ 	addl3	$4,(sp)+,r1\n\ 	movzbl	*(r1),r0\n\ 	incl	(r1)\n\ 2:\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_fputc\n"
block|,
literal|"	sobgeq	*4(sp),1f\n\ 	calls	$2,__flsbuf\n\ 	jbr	2f\n\ 1:\n\ 	movq	(sp)+,r0\n\ 	movb	r0,*4(r1)\n\ 	incl	4(r1)\n\ 2:\n"
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

begin_decl_stmt
name|struct
name|pats
name|vaxsubset_libc_ptab
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"_strlen\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	movl	r5,r1\n\ 1:\n\ 	tstb	(r1)+\n\ 	jneq	1b\n\ 	decl	r1\n\ 	subl3	r5,r1,r0\n"
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
name|vax_libc_ptab
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"_strlen\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	movl	r5,r1\n\ 1:\n\ 	locc	$0,$65535,(r1)\n\ 	jeql	1b\n\ 	subl3	r5,r1,r0\n"
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

