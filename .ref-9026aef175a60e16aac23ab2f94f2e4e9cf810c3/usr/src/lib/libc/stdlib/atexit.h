begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)atexit.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* must be at least 32 to guarantee ANSI conformance */
end_comment

begin_define
define|#
directive|define
name|ATEXIT_SIZE
value|32
end_define

begin_struct
struct|struct
name|atexit
block|{
name|struct
name|atexit
modifier|*
name|next
decl_stmt|;
comment|/* next in list */
name|int
name|ind
decl_stmt|;
comment|/* next index in this table */
name|void
function_decl|(
modifier|*
name|fns
index|[
name|ATEXIT_SIZE
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* the table itself */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|atexit
modifier|*
name|__atexit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to head of LIFO stack */
end_comment

end_unit

