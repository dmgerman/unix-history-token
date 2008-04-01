begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYNCH_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYNCH_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|_ASM
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/int_types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ASM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_ASM
comment|/*  * Thread and LWP mutexes have the same type  * definitions.  *  * NOTE:  *  * POSIX requires that<pthread.h> define the structures pthread_mutex_t  * and pthread_cond_t.  Although these structures are identical to mutex_t  * (lwp_mutex_t) and cond_t (lwp_cond_t), defined here, a typedef of these  * types would require including<synch.h> in<pthread.h>, pulling in  * non-posix symbols/constants, violating POSIX namespace restrictions.  Hence,  * pthread_mutex_t/pthread_cond_t have been redefined (in<sys/types.h>).  * Any modifications done to mutex_t/lwp_mutex_t or cond_t/lwp_cond_t must  * also be done to pthread_mutex_t/pthread_cond_t.  */
typedef|typedef
struct|struct
name|_lwp_mutex
block|{
struct|struct
block|{
name|uint16_t
name|flag1
decl_stmt|;
name|uint8_t
name|flag2
decl_stmt|;
name|uint8_t
name|ceiling
decl_stmt|;
union|union
block|{
name|uint16_t
name|bcptype
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|count_type1
decl_stmt|;
name|uint8_t
name|count_type2
decl_stmt|;
block|}
name|mtype_rcount
struct|;
block|}
name|mbcp_type_un
union|;
name|uint16_t
name|magic
decl_stmt|;
block|}
name|flags
struct|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|pad
index|[
literal|8
index|]
decl_stmt|;
block|}
name|lock64
struct|;
struct|struct
block|{
name|uint32_t
name|ownerpid
decl_stmt|;
name|uint32_t
name|lockword
decl_stmt|;
block|}
name|lock32
struct|;
name|upad64_t
name|owner64
decl_stmt|;
block|}
name|lock
union|;
name|upad64_t
name|data
decl_stmt|;
block|}
name|lwp_mutex_t
typedef|;
comment|/*  * Thread and LWP condition variables have the same  * type definition.  * NOTE:  * The layout of the following structure should be kept in sync with the  * layout of pthread_cond_t in sys/types.h. See NOTE above for lwp_mutex_t.  */
typedef|typedef
struct|struct
name|_lwp_cond
block|{
struct|struct
block|{
name|uint8_t
name|flag
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|magic
decl_stmt|;
block|}
name|flags
struct|;
name|upad64_t
name|data
decl_stmt|;
block|}
name|lwp_cond_t
typedef|;
comment|/*  * LWP semaphores  */
typedef|typedef
struct|struct
name|_lwp_sema
block|{
name|uint32_t
name|count
decl_stmt|;
comment|/* semaphore count */
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|magic
decl_stmt|;
name|uint8_t
name|flags
index|[
literal|8
index|]
decl_stmt|;
comment|/* last byte reserved for waiters */
name|upad64_t
name|data
decl_stmt|;
comment|/* optional data */
block|}
name|lwp_sema_t
typedef|;
comment|/*  * Thread and LWP rwlocks have the same type definition.  * NOTE: The layout of this structure should be kept in sync with the layout  * of the correponding structure of pthread_rwlock_t in sys/types.h.  * Also, because we have to deal with C++, there is an identical structure  * for rwlock_t in head/sync.h that we cannot change.  */
typedef|typedef
struct|struct
name|_lwp_rwlock
block|{
name|int32_t
name|readers
decl_stmt|;
comment|/* -1 == writer else # of readers */
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|magic
decl_stmt|;
name|lwp_mutex_t
name|mutex
decl_stmt|;
comment|/* used to indicate ownership */
name|lwp_cond_t
name|readercv
decl_stmt|;
comment|/* unused */
name|lwp_cond_t
name|writercv
decl_stmt|;
comment|/* unused */
block|}
name|lwp_rwlock_t
typedef|;
endif|#
directive|endif
comment|/* _ASM */
comment|/*  * Definitions of synchronization types.  */
define|#
directive|define
name|USYNC_THREAD
value|0x00
comment|/* private to a process */
define|#
directive|define
name|USYNC_PROCESS
value|0x01
comment|/* shared by processes */
comment|/* Keep the following 3 fields in sync with pthread.h */
define|#
directive|define
name|LOCK_NORMAL
value|0x00
comment|/* same as USYNC_THREAD */
define|#
directive|define
name|LOCK_ERRORCHECK
value|0x02
comment|/* error check lock */
define|#
directive|define
name|LOCK_RECURSIVE
value|0x04
comment|/* recursive lock */
define|#
directive|define
name|USYNC_PROCESS_ROBUST
value|0x08
comment|/* shared by processes robustly */
comment|/* Keep the following 5 fields in sync with pthread.h */
define|#
directive|define
name|LOCK_PRIO_NONE
value|0x00
define|#
directive|define
name|LOCK_PRIO_INHERIT
value|0x10
define|#
directive|define
name|LOCK_PRIO_PROTECT
value|0x20
define|#
directive|define
name|LOCK_STALL_NP
value|0x00
define|#
directive|define
name|LOCK_ROBUST_NP
value|0x40
comment|/*  * lwp_mutex_t flags  */
define|#
directive|define
name|LOCK_OWNERDEAD
value|0x1
define|#
directive|define
name|LOCK_NOTRECOVERABLE
value|0x2
define|#
directive|define
name|LOCK_INITED
value|0x4
define|#
directive|define
name|LOCK_UNMAPPED
value|0x8
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SYNCH_H */
end_comment

end_unit

