begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: tsearch.c,v 1.3 1999/09/16 11:45:37 lukem Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Tree search generalized from Knuth (6.2.2) Algorithm T just like  * the AT&T man page says.  *  * The node_t structure is for internal use only, lint doesn't grok it.  *  * Written by reading the System V Interface Definition, not the code.  *  * Totally public domain.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: tsearch.c,v 1.3 1999/09/16 11:45:37 lukem Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|_SEARCH_PRIVATE
end_define

begin_include
include|#
directive|include
file|<search.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* find or insert datum into search tree */
end_comment

begin_function_decl
name|void
modifier|*
name|tsearch
parameter_list|(
name|vkey
parameter_list|,
name|vrootp
parameter_list|,
name|compar
parameter_list|)
specifier|const
name|void
modifier|*
name|vkey
decl_stmt|;
comment|/* key to be located */
name|void
modifier|*
modifier|*
name|vrootp
decl_stmt|;
comment|/* address of tree root */
function_decl|int
parameter_list|(
function_decl|*compar
end_function_decl

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|node_t
modifier|*
name|q
decl_stmt|;
name|node_t
modifier|*
modifier|*
name|rootp
init|=
operator|(
name|node_t
operator|*
operator|*
operator|)
name|vrootp
decl_stmt|;
if|if
condition|(
name|rootp
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
while|while
condition|(
operator|*
name|rootp
operator|!=
name|NULL
condition|)
block|{
comment|/* Knuth's T1: */
name|int
name|r
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|=
call|(
modifier|*
name|compar
call|)
argument_list|(
name|vkey
argument_list|,
operator|(
operator|*
name|rootp
operator|)
operator|->
name|key
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|/* T2: */
return|return
operator|*
name|rootp
return|;
comment|/* we found it! */
name|rootp
operator|=
operator|(
name|r
operator|<
literal|0
operator|)
condition|?
operator|&
operator|(
operator|*
name|rootp
operator|)
operator|->
name|llink
else|:
comment|/* T3: follow left branch */
operator|&
operator|(
operator|*
name|rootp
operator|)
operator|->
name|rlink
expr_stmt|;
comment|/* T4: follow right branch */
block|}
name|q
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|node_t
argument_list|)
argument_list|)
expr_stmt|;
comment|/* T5: key not found */
if|if
condition|(
name|q
operator|!=
literal|0
condition|)
block|{
comment|/* make new node */
operator|*
name|rootp
operator|=
name|q
expr_stmt|;
comment|/* link new node to old */
comment|/* LINTED const castaway ok */
name|q
operator|->
name|key
operator|=
operator|(
name|void
operator|*
operator|)
name|vkey
expr_stmt|;
comment|/* initialize new node */
name|q
operator|->
name|llink
operator|=
name|q
operator|->
name|rlink
operator|=
name|NULL
expr_stmt|;
block|}
return|return
name|q
return|;
block|}
end_block

end_unit

