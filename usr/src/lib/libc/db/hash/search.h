begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * %sccs.include.redist.c%  *  *	@(#)search.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Backward compatibility to hsearch interface */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|entry
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|FIND
block|,
name|ENTER
block|}
name|ACTION
typedef|;
end_typedef

end_unit

