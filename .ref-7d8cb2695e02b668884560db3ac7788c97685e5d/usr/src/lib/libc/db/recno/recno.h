begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)recno.h	8.1 (Berkeley) %G%  */
end_comment

begin_enum
enum|enum
name|SRCHOP
block|{
name|SDELETE
block|,
name|SINSERT
block|,
name|SEARCH
block|}
enum|;
end_enum

begin_comment
comment|/* Rec_search operation. */
end_comment

begin_include
include|#
directive|include
file|"../btree/btree.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

