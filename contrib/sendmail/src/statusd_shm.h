begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: statusd_shm.h,v 8.4 1999/05/18 08:00:04 gshapiro Exp $  *  * Contributed by Exactis.com, Inc.  *  */
end_comment

begin_comment
comment|/* ** The shared memory part of statusd. ** ** Attach to STATUSD_SHM_KEY and update the counter appropriate ** for your type of service. ** */
end_comment

begin_define
define|#
directive|define
name|STATUSD_MAGIC
value|110946
end_define

begin_define
define|#
directive|define
name|STATUSD_SHM_KEY
value|(key_t)(13)
end_define

begin_define
define|#
directive|define
name|STATUSD_LONGS
value|(2)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|magic
decl_stmt|;
name|unsigned
name|long
name|ul
index|[
name|STATUSD_LONGS
index|]
decl_stmt|;
block|}
name|STATUSD_SHM
typedef|;
end_typedef

begin_comment
comment|/* **  Offsets into ul[]. The appropriate program **  increments these as appropriate. */
end_comment

begin_define
define|#
directive|define
name|STATUSD_COOKIE
value|(0)
end_define

begin_comment
comment|/* reregister cookie */
end_comment

begin_comment
comment|/* sendmail */
end_comment

begin_define
define|#
directive|define
name|STATUSD_SM_NSENDMAIL
value|(1)
end_define

begin_comment
comment|/* how many running */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|shmtick
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

