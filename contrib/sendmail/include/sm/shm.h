begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003, 2005 Proofpoint, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: shm.h,v 1.12 2013-11-22 20:51:31 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_SHM_H
end_ifndef

begin_define
define|#
directive|define
name|SM_SHM_H
end_define

begin_if
if|#
directive|if
name|SM_CONF_SHM
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/shm.h>
end_include

begin_comment
comment|/* # include "def.h"	*/
end_comment

begin_comment
comment|/* key for shared memory */
end_comment

begin_define
define|#
directive|define
name|SM_SHM_KEY
value|((key_t) 42)
end_define

begin_comment
comment|/* return value for failed shmget() */
end_comment

begin_define
define|#
directive|define
name|SM_SHM_NULL
value|((void *) -1)
end_define

begin_define
define|#
directive|define
name|SM_SHM_NO_ID
value|(-2)
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_shmstart
name|__P
argument_list|(
operator|(
name|key_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_shmstop
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_shmsetowner
name|__P
argument_list|(
operator|(
name|int
operator|,
name|uid_t
operator|,
name|gid_t
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for those braindead systems... (e.g., SunOS 4) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHM_R
end_ifndef

begin_define
define|#
directive|define
name|SHM_R
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHM_R */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHM_W
end_ifndef

begin_define
define|#
directive|define
name|SHM_W
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHM_W */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SHM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_SHM_H */
end_comment

end_unit

