begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)config.h	8.1 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_entry
block|{
name|struct
name|queue_entry
name|list
decl_stmt|;
comment|/* List of items. */
name|struct
name|queue_entry
name|tags
decl_stmt|;
comment|/* List of tags. */
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

begin_decl_stmt
specifier|extern
name|struct
name|queue_entry
name|head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ENTRY
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
name|void
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
name|ENTRY
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

