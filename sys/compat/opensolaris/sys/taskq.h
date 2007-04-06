begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TASKQ_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TASKQ_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)taskq.h	1.5	05/06/08 SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kcondvar.h>
end_include

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
define|#
directive|define
name|TASKQ_NAMELEN
value|31
typedef|typedef
name|struct
name|taskq
name|taskq_t
typedef|;
typedef|typedef
name|uintptr_t
name|taskqid_t
typedef|;
typedef|typedef
name|void
function_decl|(
name|task_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Public flags for taskq_create(): bit range 0-15  */
define|#
directive|define
name|TASKQ_PREPOPULATE
value|0x0001
comment|/* Prepopulate with threads and data */
define|#
directive|define
name|TASKQ_CPR_SAFE
value|0x0002
comment|/* Use CPR safe protocol */
define|#
directive|define
name|TASKQ_DYNAMIC
value|0x0004
comment|/* Use dynamic thread scheduling */
comment|/*  * Flags for taskq_dispatch. TQ_SLEEP/TQ_NOSLEEP should be same as  * KM_SLEEP/KM_NOSLEEP.  */
define|#
directive|define
name|TQ_SLEEP
value|0x00
comment|/* Can block for memory */
define|#
directive|define
name|TQ_NOSLEEP
value|0x01
comment|/* cannot block for memory; may fail */
define|#
directive|define
name|TQ_NOQUEUE
value|0x02
comment|/* Do not enqueue if can't dispatch */
define|#
directive|define
name|TQ_NOALLOC
value|0x04
comment|/* cannot allocate memory; may fail */
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|taskq_t
modifier|*
name|system_taskq
decl_stmt|;
specifier|extern
name|taskq_t
modifier|*
name|taskq_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|pri_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|taskq_t
modifier|*
name|taskq_create_instance
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|pri_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|taskqid_t
name|taskq_dispatch
parameter_list|(
name|taskq_t
modifier|*
parameter_list|,
name|task_func_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|nulltask
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|taskq_destroy
parameter_list|(
name|taskq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|taskq_wait
parameter_list|(
name|taskq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|taskq_suspend
parameter_list|(
name|taskq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|taskq_suspended
parameter_list|(
name|taskq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|taskq_resume
parameter_list|(
name|taskq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|taskq_member
parameter_list|(
name|taskq_t
modifier|*
parameter_list|,
name|kthread_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
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
comment|/* _SYS_TASKQ_H */
end_comment

end_unit

