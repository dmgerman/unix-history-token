begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)atexit.h	5.1 (Berkeley) 5/15/90  */
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

