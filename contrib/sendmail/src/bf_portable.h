begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: bf_portable.h,v 8.6 1999/11/04 19:31:25 ca Exp $  *  * Contributed by Exactis.com, Inc.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BF_PORTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|BF_PORTABLE_H
value|1
end_define

begin_comment
comment|/* **  This implementation will behave differently from the Torek-based code in **  the following major ways: **   - The buffer size argument to bfopen() will be sent in, sent back, **     queried, lost, found, subjected to public inquiry, lost again, and **     finally buried in soft peat and recycled as firelighters. **   - Errors in creating the file (but not necessarily writing to it) will **     always be detected and reported synchronously with the bfopen() */
end_comment

begin_comment
comment|/* Linked structure for storing information about each buffered file */
end_comment

begin_struct
struct|struct
name|bf
block|{
name|FILE
modifier|*
name|bf_key
decl_stmt|;
comment|/* Unused except as a key for lookup */
name|bool
name|bf_committed
decl_stmt|;
comment|/* buffered file is on disk */
name|char
modifier|*
name|bf_filename
decl_stmt|;
comment|/* Name of disk file */
name|int
name|bf_refcount
decl_stmt|;
comment|/* Reference count */
name|struct
name|bf
modifier|*
name|bf_cdr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **  Access routines for looking up bf structures ** **	maybe replace with a faster data structure later */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bfinsert
name|__P
argument_list|(
operator|(
expr|struct
name|bf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bf
modifier|*
name|bflookup
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bf
modifier|*
name|bfdelete
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BF_PORTABLE_H */
end_comment

end_unit

