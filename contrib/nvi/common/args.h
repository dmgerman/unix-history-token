begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)args.h	10.2 (Berkeley) 3/6/96  */
end_comment

begin_comment
comment|/*  * Structure for building "argc/argv" vector of arguments.  *  * !!!  * All arguments are nul terminated as well as having an associated length.  * The argument vector is NOT necessarily NULL terminated.  The proper way  * to check the number of arguments is to use the argc value in the EXCMDARG  * structure or to walk the array until an ARGS structure with a length of 0  * is found.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_args
block|{
name|CHAR_T
modifier|*
name|bp
decl_stmt|;
comment|/* Argument. */
name|size_t
name|blen
decl_stmt|;
comment|/* Buffer length. */
name|size_t
name|len
decl_stmt|;
comment|/* Argument length. */
define|#
directive|define
name|A_ALLOCATED
value|0x01
comment|/* If allocated space. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
name|ARGS
typedef|;
end_typedef

end_unit

