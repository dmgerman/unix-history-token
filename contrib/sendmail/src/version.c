begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2004 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: version.c,v 8.130 2004/07/30 18:03:07 ca Exp $"
argument_list|)
end_macro

begin_decl_stmt
name|char
name|Version
index|[]
init|=
literal|"8.13.1"
decl_stmt|;
end_decl_stmt

end_unit

