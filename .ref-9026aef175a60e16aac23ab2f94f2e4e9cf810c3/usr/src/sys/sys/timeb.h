begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)timeb.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* The ftime(2) system call structure -- deprecated. */
end_comment

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
comment|/* seconds since the Epoch */
name|unsigned
name|short
name|millitm
decl_stmt|;
comment|/* + milliseconds since the Epoch */
name|short
name|timezone
decl_stmt|;
comment|/* minutes west of CUT */
name|short
name|dstflag
decl_stmt|;
comment|/* DST == non-zero */
block|}
struct|;
end_struct

end_unit

