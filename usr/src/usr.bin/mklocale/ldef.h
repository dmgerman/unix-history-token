begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * %sccs.include.redist.c%  *  *	@(#)ldef.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This should look a LOT like a _RuneEntry  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rune_list
block|{
name|rune_t
name|min
decl_stmt|;
name|rune_t
name|max
decl_stmt|;
name|rune_t
name|map
decl_stmt|;
name|u_long
modifier|*
name|types
decl_stmt|;
name|struct
name|rune_list
modifier|*
name|next
decl_stmt|;
block|}
name|rune_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rune_map
block|{
name|u_long
name|map
index|[
name|_CACHED_RUNES
index|]
decl_stmt|;
name|rune_list
modifier|*
name|root
decl_stmt|;
block|}
name|rune_map
typedef|;
end_typedef

end_unit

