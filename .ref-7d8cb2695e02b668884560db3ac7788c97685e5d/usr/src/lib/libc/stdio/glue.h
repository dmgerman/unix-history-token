begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  *  *	@(#)glue.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The first few FILEs are statically allocated; others are dynamically  * allocated and linked in via this glue structure.  */
end_comment

begin_struct
struct|struct
name|glue
block|{
name|struct
name|glue
modifier|*
name|next
decl_stmt|;
name|int
name|niobs
decl_stmt|;
name|FILE
modifier|*
name|iobs
decl_stmt|;
block|}
name|__sglue
struct|;
end_struct

end_unit

