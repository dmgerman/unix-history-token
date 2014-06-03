begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002, 2003 Proofpoint, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: bdb.h,v 1.5 2013-11-22 20:51:31 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_BDB_H
end_ifndef

begin_define
define|#
directive|define
name|SM_BDB_H
end_define

begin_if
if|#
directive|if
name|NEWDB
end_if

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DB_VERSION_MAJOR
end_ifndef

begin_define
define|#
directive|define
name|DB_VERSION_MAJOR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! DB_VERSION_MAJOR */
end_comment

begin_if
if|#
directive|if
name|DB_VERSION_MAJOR
operator|>=
literal|4
operator|&&
name|DB_VERSION_MINOR
operator|>=
literal|1
end_if

begin_define
define|#
directive|define
name|DBTXN
value|NULL ,
end_define

begin_comment
comment|/* **  Always turn on DB_FCNTL_LOCKING for DB 4.1.x since its **  "workaround" for accepting an empty (locked) file depends on **  this flag. Notice: this requires 4.1.24 + patch (which should be **  part of 4.1.25). */
end_comment

begin_define
define|#
directive|define
name|SM_DB_FLAG_ADD
parameter_list|(
name|flag
parameter_list|)
value|(flag) |= DB_FCNTL_LOCKING
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DB_VERSION_MAJOR>= 4&& DB_VERSION_MINOR>= 1 */
end_comment

begin_define
define|#
directive|define
name|DBTXN
end_define

begin_if
if|#
directive|if
operator|!
name|HASFLOCK
operator|&&
name|defined
argument_list|(
name|DB_FCNTL_LOCKING
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_DB_FLAG_ADD
parameter_list|(
name|flag
parameter_list|)
value|(flag) |= DB_FCNTL_LOCKING
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HASFLOCK&& defined(DB_FCNTL_LOCKING) */
end_comment

begin_define
define|#
directive|define
name|SM_DB_FLAG_ADD
parameter_list|(
name|flag
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HASFLOCK&& defined(DB_FCNTL_LOCKING) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DB_VERSION_MAJOR>= 4&& DB_VERSION_MINOR>= 1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEWDB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_BDB_H */
end_comment

end_unit

