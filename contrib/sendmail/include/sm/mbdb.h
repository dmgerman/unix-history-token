begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: mbdb.h,v 1.4 2001/03/08 03:23:08 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_MBDB_H
end_ifndef

begin_define
define|#
directive|define
name|SM_MBDB_H
end_define

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<sm/types.h>
end_include

begin_include
include|#
directive|include
file|<sm/limits.h>
end_include

begin_comment
comment|/* **  This is an abstract interface for looking up local mail recipients. */
end_comment

begin_define
define|#
directive|define
name|MBDB_MAXNAME
value|256
end_define

begin_define
define|#
directive|define
name|SM_NO_UID
value|((uid_t)(-1))
end_define

begin_define
define|#
directive|define
name|SM_NO_GID
value|((gid_t)(-1))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uid_t
name|mbdb_uid
decl_stmt|;
name|gid_t
name|mbdb_gid
decl_stmt|;
name|char
name|mbdb_name
index|[
name|MBDB_MAXNAME
index|]
decl_stmt|;
name|char
name|mbdb_fullname
index|[
name|MBDB_MAXNAME
index|]
decl_stmt|;
name|char
name|mbdb_homedir
index|[
name|PATH_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|mbdb_shell
index|[
name|PATH_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|SM_MBDB_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|sm_mbdb_initialize
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_mbdb_terminate
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_mbdb_lookup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|SM_MBDB_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_mbdb_frompw
name|__P
argument_list|(
operator|(
name|SM_MBDB_T
operator|*
operator|,
expr|struct
name|passwd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_pwfullname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_MBDB_H */
end_comment

end_unit

