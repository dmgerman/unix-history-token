begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)remque.c	5.3 (Berkeley) %G%"
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
comment|/*  * remque -- vax remque instruction  *  * NOTE: this implementation is non-atomic!!  */
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
name|remque
argument_list|(
name|e
argument_list|)
specifier|register
expr|struct
name|vaxque
operator|*
name|e
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|e
operator|->
name|vq_prev
operator|->
name|vq_next
operator|=
name|e
operator|->
name|vq_next
expr_stmt|;
name|e
operator|->
name|vq_next
operator|->
name|vq_prev
operator|=
name|e
operator|->
name|vq_prev
expr_stmt|;
block|}
end_block

end_unit

