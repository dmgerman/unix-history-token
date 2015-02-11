begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHIQ_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|VCHIQ_ARM_H
end_define

begin_include
include|#
directive|include
file|"vchiq_core.h"
end_include

begin_enum
enum|enum
name|vc_suspend_status
block|{
name|VC_SUSPEND_FORCE_CANCELED
init|=
operator|-
literal|3
block|,
comment|/* Force suspend canceled, too busy */
name|VC_SUSPEND_REJECTED
init|=
operator|-
literal|2
block|,
comment|/* Videocore rejected suspend request */
name|VC_SUSPEND_FAILED
init|=
operator|-
literal|1
block|,
comment|/* Videocore suspend failed */
name|VC_SUSPEND_IDLE
init|=
literal|0
block|,
comment|/* VC active, no suspend actions */
name|VC_SUSPEND_REQUESTED
block|,
comment|/* User has requested suspend */
name|VC_SUSPEND_IN_PROGRESS
block|,
comment|/* Slot handler has recvd suspend request */
name|VC_SUSPEND_SUSPENDED
comment|/* Videocore suspend succeeded */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|vc_resume_status
block|{
name|VC_RESUME_FAILED
init|=
operator|-
literal|1
block|,
comment|/* Videocore resume failed */
name|VC_RESUME_IDLE
init|=
literal|0
block|,
comment|/* VC suspended, no resume actions */
name|VC_RESUME_REQUESTED
block|,
comment|/* User has requested resume */
name|VC_RESUME_IN_PROGRESS
block|,
comment|/* Slot handler has received resume request */
name|VC_RESUME_RESUMED
comment|/* Videocore resumed successfully (active) */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|USE_TYPE_E
block|{
name|USE_TYPE_SERVICE
block|,
name|USE_TYPE_SERVICE_NO_RESUME
block|,
name|USE_TYPE_VCHIQ
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|vchiq_arm_state_struct
block|{
comment|/* Keepalive-related data */
name|VCHIQ_THREAD_T
name|ka_thread
decl_stmt|;
name|struct
name|completion
name|ka_evt
decl_stmt|;
name|atomic_t
name|ka_use_count
decl_stmt|;
name|atomic_t
name|ka_use_ack_count
decl_stmt|;
name|atomic_t
name|ka_release_count
decl_stmt|;
name|struct
name|completion
name|vc_suspend_complete
decl_stmt|;
name|struct
name|completion
name|vc_resume_complete
decl_stmt|;
name|rwlock_t
name|susp_res_lock
decl_stmt|;
name|enum
name|vc_suspend_status
name|vc_suspend_state
decl_stmt|;
name|enum
name|vc_resume_status
name|vc_resume_state
decl_stmt|;
name|unsigned
name|int
name|wake_address
decl_stmt|;
name|struct
name|timer_list
name|suspend_timer
decl_stmt|;
name|int
name|suspend_timer_timeout
decl_stmt|;
name|int
name|suspend_timer_running
decl_stmt|;
comment|/* Global use count for videocore. 	** This is equal to the sum of the use counts for all services.  When 	** this hits zero the videocore suspend procedure will be initiated. 	*/
name|int
name|videocore_use_count
decl_stmt|;
comment|/* Use count to track requests from videocore peer. 	** This use count is not associated with a service, so needs to be 	** tracked separately with the state. 	*/
name|int
name|peer_use_count
decl_stmt|;
comment|/* Flag to indicate whether resume is blocked.  This happens when the 	** ARM is suspending 	*/
name|struct
name|completion
name|resume_blocker
decl_stmt|;
name|int
name|resume_blocked
decl_stmt|;
name|struct
name|completion
name|blocked_blocker
decl_stmt|;
name|int
name|blocked_count
decl_stmt|;
name|int
name|autosuspend_override
decl_stmt|;
comment|/* Flag to indicate that the first vchiq connect has made it through. 	** This means that both sides should be fully ready, and we should 	** be able to suspend after this point. 	*/
name|int
name|first_connect
decl_stmt|;
name|unsigned
name|long
name|long
name|suspend_start_time
decl_stmt|;
name|unsigned
name|long
name|long
name|sleep_start_time
decl_stmt|;
name|unsigned
name|long
name|long
name|resume_start_time
decl_stmt|;
name|unsigned
name|long
name|long
name|last_wake_time
decl_stmt|;
block|}
name|VCHIQ_ARM_STATE_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|vchiq_arm_log_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vchiq_susp_log_level
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|__init
name|vchiq_platform_init
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__exit
name|vchiq_platform_exit
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATE_T
modifier|*
name|vchiq_get_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_arm_vcsuspend
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_arm_force_suspend
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vchiq_arm_allow_resume
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_arm_vcresume
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_arm_init_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_ARM_STATE_T
modifier|*
name|arm_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vchiq_check_resume
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_check_suspend
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_platform_suspend
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vchiq_platform_videocore_wanted
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vchiq_platform_use_suspend_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_platform_use_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_service_use_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_ARM_STATE_T
modifier|*
name|vchiq_platform_get_arm_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vchiq_videocore_wanted
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_use_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|,
name|enum
name|USE_TYPE_E
name|use_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_release_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_suspend_state
parameter_list|(
name|VCHIQ_ARM_STATE_T
modifier|*
name|arm_state
parameter_list|,
name|enum
name|vc_suspend_status
name|new_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_resume_state
parameter_list|(
name|VCHIQ_ARM_STATE_T
modifier|*
name|arm_state
parameter_list|,
name|enum
name|vc_resume_status
name|new_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_suspend_timer
parameter_list|(
name|VCHIQ_ARM_STATE_T
modifier|*
name|arm_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vchiq_proc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_proc_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|proc_dir_entry
modifier|*
name|vchiq_proc_top
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|proc_dir_entry
modifier|*
name|vchiq_clients_top
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VCHIQ_ARM_H */
end_comment

end_unit

