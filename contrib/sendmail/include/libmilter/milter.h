begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2002 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: milter.h,v 8.37 2002/03/22 19:32:48 ca Exp $  */
end_comment

begin_comment
comment|/* **  MILTER.H -- Global definitions for mail filter. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBMILTER_MILTER_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBMILTER_MILTER_H
value|1
end_define

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_include
include|#
directive|include
file|"libmilter/mfapi.h"
end_include

begin_comment
comment|/* socket and thread portability */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|pthread_t
name|sthread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|socket_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_MACROS_ENTRIES
value|4
end_define

begin_comment
comment|/* max size of macro pointer array */
end_comment

begin_comment
comment|/* **  context for milter **  implementation hint: **  macros are stored in mac_buf[] as sequence of: **  macro_name \0 macro_value **  (just as read from the MTA) **  mac_ptr is a list of pointers into mac_buf to the beginning of each **  entry, i.e., macro_name, macro_value, ... */
end_comment

begin_struct
struct|struct
name|smfi_str
block|{
name|sthread_t
name|ctx_id
decl_stmt|;
comment|/* thread id */
name|socket_t
name|ctx_sd
decl_stmt|;
comment|/* socket descriptor */
name|int
name|ctx_dbg
decl_stmt|;
comment|/* debug level */
name|time_t
name|ctx_timeout
decl_stmt|;
comment|/* timeout */
name|int
name|ctx_state
decl_stmt|;
comment|/* state */
name|smfiDesc_ptr
name|ctx_smfi
decl_stmt|;
comment|/* filter description */
name|unsigned
name|long
name|ctx_pflags
decl_stmt|;
comment|/* protocol flags */
name|char
modifier|*
modifier|*
name|ctx_mac_ptr
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_mac_buf
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_reply
decl_stmt|;
comment|/* reply code */
name|void
modifier|*
name|ctx_privdata
decl_stmt|;
comment|/* private data */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBMILTER_MILTER_H */
end_comment

end_unit

