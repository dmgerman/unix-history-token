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
literal|"@(#)libcpats.c	1.2	(Berkeley)	8/18/84"
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
literal|"1,_fgetc\n"
block|,
literal|"	movl	(sp)+,r2\n\ 	sobgeq	(r2),1f\n\ 	pushl	r2\n\ 	calls	$1,__filbuf\n\ 	jbr	2f\n\ 1:\n\ 	movzbl	*4(r2),r0\n\ 	incl	4(r2)\n\ 2:\n"
block|}
block|,
block|{
literal|"2,_fputc\n"
block|,
literal|"	movl	(sp)+,r2$\n\ 	movl	(sp)+,r3\n\ 	sobgeq	(r3),1f\n\ 	pushl	r3\n\ 	pushl	r2\n\ 	calls	$2,__flsbuf\n\ 	jbr	2f\n\ 1:\n\ 	movb	r2,*4(r3)\n\ 	incl	4(r3)\n\ 2:\n"
block|}
block|,
block|{
literal|"1,_strlen\n"
block|,
literal|"	movl	(sp)+,r5\n\ 	movl	r5,r1\n\ 1:\n\ 	locc	$0,$65535,(r1)\n\ 	jeql	1b\n\ 	subl3	r5,r1,r0\n"
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

