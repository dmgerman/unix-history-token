begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)machpats.c	1.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"inline.h"
end_include

begin_comment
comment|/*  * Pattern table for special instructions.  */
end_comment

begin_decl_stmt
name|struct
name|pats
name|machine_ptab
index|[]
init|=
block|{
block|{
literal|3
block|,
literal|"_blkcpy\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movblk\n"
block|}
block|,
block|{
literal|3
block|,
literal|"_bcopy\n"
block|,
literal|"	movl	(sp)+,r0\n\ 	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movblk\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_bzero\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movab	1f,r0\n\ 	movs3\n\ 	.data\n\ 1:	.byte	0\n\ 	.text\n"
block|}
block|,
block|{
literal|2
block|,
literal|"_blkclr\n"
block|,
literal|"	movl	(sp)+,r1\n\ 	movl	(sp)+,r2\n\ 	movab	1f,r0\n\ 	movs3\n\ 	.data\n\ 1:	.byte	0\n\ 	.text\n"
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

