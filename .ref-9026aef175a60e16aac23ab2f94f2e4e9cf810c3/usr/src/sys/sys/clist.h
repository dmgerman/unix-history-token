begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)clist.h	8.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|cblock
block|{
name|struct
name|cblock
modifier|*
name|c_next
decl_stmt|;
comment|/* next cblock in queue */
name|char
name|c_quote
index|[
name|CBQSIZE
index|]
decl_stmt|;
comment|/* quoted characters */
name|char
name|c_info
index|[
name|CBSIZE
index|]
decl_stmt|;
comment|/* characters */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|cblock
modifier|*
name|cfree
decl_stmt|,
modifier|*
name|cfreelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfreecount
decl_stmt|,
name|nclist
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

