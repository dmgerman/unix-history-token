begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  * $Id: fvwrite.h,v 1.7 2001/03/02 00:18:19 ca Exp $  */
end_comment

begin_comment
comment|/* I/O descriptors for sm_fvwrite() */
end_comment

begin_struct
struct|struct
name|sm_iov
block|{
name|void
modifier|*
name|iov_base
decl_stmt|;
name|size_t
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm_uio
block|{
name|struct
name|sm_iov
modifier|*
name|uio_iov
decl_stmt|;
name|int
name|uio_iovcnt
decl_stmt|;
name|int
name|uio_resid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|sm_fvwrite
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
expr|struct
name|sm_uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

