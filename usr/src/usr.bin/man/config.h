begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)config.h	8.4 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_tag
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_tag
argument_list|)
name|q
expr_stmt|;
comment|/* Queue of tags. */
name|TAILQ_HEAD
argument_list|(
argument|tqh
argument_list|,
argument|_entry
argument_list|)
name|list
expr_stmt|;
comment|/* Queue of entries. */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* Associated string. */
name|size_t
name|len
decl_stmt|;
comment|/* Length of 's'. */
block|}
name|TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_entry
argument_list|)
name|q
expr_stmt|;
comment|/* Queue of entries. */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* Associated string. */
name|size_t
name|len
decl_stmt|;
comment|/* Length of 's'. */
block|}
name|ENTRY
typedef|;
end_typedef

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|_head
argument_list|,
name|_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_head
name|head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TAG
modifier|*
name|addlist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|config
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|debug
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TAG
modifier|*
name|getlist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

