begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, 2005, 2008 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sem.h,v 1.10 2008/05/30 16:26:39 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_SEM_H
end_ifndef

begin_define
define|#
directive|define
name|SM_SEM_H
value|1
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_comment
comment|/* key for semaphores */
end_comment

begin_define
define|#
directive|define
name|SM_SEM_KEY
value|(41L)
end_define

begin_define
define|#
directive|define
name|SM_SEM_NO_ID
value|(-1)
end_define

begin_define
define|#
directive|define
name|SM_NO_SEM
parameter_list|(
name|id
parameter_list|)
value|((id)< 0)
end_define

begin_if
if|#
directive|if
name|SM_CONF_SEM
operator|>
literal|0
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
file|<sys/sem.h>
end_include

begin_if
if|#
directive|if
name|SM_CONF_SEM
operator|==
literal|2
end_if

begin_union
union|union
name|semun
block|{
name|int
name|val
decl_stmt|;
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
name|ushort
modifier|*
name|array
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SEM == 2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEM_A
end_ifndef

begin_define
define|#
directive|define
name|SEM_A
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SEM_A */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEM_R
end_ifndef

begin_define
define|#
directive|define
name|SEM_R
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SEM_R */
end_comment

begin_define
define|#
directive|define
name|SM_NSEM
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|sm_sem_start
name|__P
argument_list|(
operator|(
name|key_t
operator|,
name|int
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
name|sm_sem_stop
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_sem_acq
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_sem_rel
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_sem_get
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

begin_decl_stmt
specifier|extern
name|int
name|sm_semsetowner
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_SEM> 0 */
end_comment

begin_define
define|#
directive|define
name|sm_sem_start
parameter_list|(
name|key
parameter_list|,
name|nsem
parameter_list|,
name|semflg
parameter_list|,
name|owner
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sm_sem_stop
parameter_list|(
name|semid
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sm_sem_acq
parameter_list|(
name|semid
parameter_list|,
name|semnum
parameter_list|,
name|timeout
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sm_sem_rel
parameter_list|(
name|semid
parameter_list|,
name|semnum
parameter_list|,
name|timeout
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sm_sem_get
parameter_list|(
name|semid
parameter_list|,
name|semnum
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SEM> 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_SEM_H */
end_comment

end_unit

