begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)insque.c	5.3 (Berkeley) 6/1/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * insque -- vax insque instruction  *  * NOTE: this implementation is non-atomic!!  */
end_comment

begin_struct
struct|struct
name|vaxque
block|{
comment|/* queue format expected by VAX queue instructions */
name|struct
name|vaxque
modifier|*
name|vq_next
decl_stmt|;
name|struct
name|vaxque
modifier|*
name|vq_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|insque
argument_list|(
name|e
argument_list|,
name|prev
argument_list|)
specifier|register
expr|struct
name|vaxque
operator|*
name|e
operator|,
operator|*
name|prev
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|e
operator|->
name|vq_prev
operator|=
name|prev
expr_stmt|;
name|e
operator|->
name|vq_next
operator|=
name|prev
operator|->
name|vq_next
expr_stmt|;
name|prev
operator|->
name|vq_next
operator|->
name|vq_prev
operator|=
name|e
expr_stmt|;
name|prev
operator|->
name|vq_next
operator|=
name|e
expr_stmt|;
block|}
end_block

end_unit

