begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  *  *	@(#)gcrt0.h	5.1 (Berkeley) 4/12/91  */
end_comment

begin_comment
comment|/* @(#)gcrt0.h	1.1 (Tahoe) 3/21/85 */
end_comment

begin_struct
struct|struct
name|phdr
block|{
name|char
modifier|*
name|lpc
decl_stmt|;
name|char
modifier|*
name|hpc
decl_stmt|;
name|int
name|ncnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tostruct
block|{
name|char
modifier|*
name|selfpc
decl_stmt|;
name|long
name|count
decl_stmt|;
name|unsigned
name|short
name|link
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	a raw arc,      *	    with pointers to the calling site and the called site      *	    and a count.      */
end_comment

begin_struct
struct|struct
name|rawarc
block|{
name|unsigned
name|long
name|raw_frompc
decl_stmt|;
name|unsigned
name|long
name|raw_selfpc
decl_stmt|;
name|long
name|raw_count
decl_stmt|;
block|}
struct|;
end_struct

end_unit

