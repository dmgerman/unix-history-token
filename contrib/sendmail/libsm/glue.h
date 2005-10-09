begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  * $Id: glue.h,v 1.6 2001/01/22 23:09:49 ca Exp $  */
end_comment

begin_comment
comment|/* **  The first few FILEs are statically allocated; others are dynamically **  allocated and linked in via this glue structure. */
end_comment

begin_struct
specifier|extern
struct|struct
name|sm_glue
block|{
name|struct
name|sm_glue
modifier|*
name|gl_next
decl_stmt|;
name|int
name|gl_niobs
decl_stmt|;
name|SM_FILE_T
modifier|*
name|gl_iobs
decl_stmt|;
block|}
name|smglue
struct|;
end_struct

end_unit

