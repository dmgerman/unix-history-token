begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * %sccs.include.redist.c%  *  *	@(#)ftree.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Data structure used by the ftree.c routines to store the file args to be  * handed to fts(). It keeps a reference count of which args generated a  * "selected" member  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ftree
block|{
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* file tree name */
name|int
name|refcnt
decl_stmt|;
comment|/* has tree had a selected file? */
name|struct
name|ftree
modifier|*
name|fow
decl_stmt|;
comment|/* pointer to next entry on list */
block|}
name|FTREE
typedef|;
end_typedef

end_unit

