begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: twalk.c,v 1.1 1999/02/22 10:33:16 christos Exp $	*/
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
literal|"$NetBSD: twalk.c,v 1.1 1999/02/22 10:33:16 christos Exp $"
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

begin_function_decl
specifier|static
name|void
name|trecurse
parameter_list|(
specifier|const
name|node_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|VISIT
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Walk the nodes of a tree */
end_comment

begin_decl_stmt
specifier|static
name|void
name|trecurse
argument_list|(
name|root
argument_list|,
name|action
argument_list|,
name|level
argument_list|)
decl|const
name|node_t
modifier|*
name|root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Root of the tree to be walked */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|VISIT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|root
operator|->
name|llink
operator|==
name|NULL
operator|&&
name|root
operator|->
name|rlink
operator|==
name|NULL
condition|)
call|(
modifier|*
name|action
call|)
argument_list|(
name|root
argument_list|,
name|leaf
argument_list|,
name|level
argument_list|)
expr_stmt|;
else|else
block|{
call|(
modifier|*
name|action
call|)
argument_list|(
name|root
argument_list|,
name|preorder
argument_list|,
name|level
argument_list|)
expr_stmt|;
if|if
condition|(
name|root
operator|->
name|llink
operator|!=
name|NULL
condition|)
name|trecurse
argument_list|(
name|root
operator|->
name|llink
argument_list|,
name|action
argument_list|,
name|level
operator|+
literal|1
argument_list|)
expr_stmt|;
call|(
modifier|*
name|action
call|)
argument_list|(
name|root
argument_list|,
name|postorder
argument_list|,
name|level
argument_list|)
expr_stmt|;
if|if
condition|(
name|root
operator|->
name|rlink
operator|!=
name|NULL
condition|)
name|trecurse
argument_list|(
name|root
operator|->
name|rlink
argument_list|,
name|action
argument_list|,
name|level
operator|+
literal|1
argument_list|)
expr_stmt|;
call|(
modifier|*
name|action
call|)
argument_list|(
name|root
argument_list|,
name|endorder
argument_list|,
name|level
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* Walk the nodes of a tree */
end_comment

begin_decl_stmt
name|void
name|twalk
argument_list|(
name|vroot
argument_list|,
name|action
argument_list|)
decl|const
name|void
modifier|*
name|vroot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Root of the tree to be walked */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|VISIT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_block
block|{
if|if
condition|(
name|vroot
operator|!=
name|NULL
operator|&&
name|action
operator|!=
name|NULL
condition|)
name|trecurse
argument_list|(
name|vroot
argument_list|,
name|action
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

