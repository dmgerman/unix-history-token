begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)clist.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Raw structures for the character list routines.  */
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
name|char
name|c_info
index|[
name|CBSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|cblock
modifier|*
name|cfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nclist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cblock
modifier|*
name|cfreelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cfreecount
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

