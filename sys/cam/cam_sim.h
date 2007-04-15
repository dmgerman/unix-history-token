begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Data structures and definitions for SCSI Interface Modules (SIMs).  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_SIM_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_SIM_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The sim driver creates a sim for each controller.  The sim device  * queue is separately created in order to allow resource sharing between  * sims.  For instance, a driver may create one sim for each channel of  * a multi-channel controller and use the same queue for each channel.  * In this way, the queue resources are shared across all the channels  * of the multi-channel controller.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cam_sim
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cam_devq
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sim_action_func
function_decl|)
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sim_poll_func
function_decl|)
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|cam_devq
modifier|*
name|cam_simq_alloc
parameter_list|(
name|u_int32_t
name|max_sim_transactions
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_simq_free
parameter_list|(
name|struct
name|cam_devq
modifier|*
name|devq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cam_sim
modifier|*
name|cam_sim_alloc
parameter_list|(
name|sim_action_func
name|sim_action
parameter_list|,
name|sim_poll_func
name|sim_poll
parameter_list|,
specifier|const
name|char
modifier|*
name|sim_name
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|,
name|u_int32_t
name|unit
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|int
name|max_dev_transactions
parameter_list|,
name|int
name|max_tagged_dev_transactions
parameter_list|,
name|struct
name|cam_devq
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_sim_free
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|int
name|free_devq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Optional sim attributes may be set with these. */
end_comment

begin_function_decl
name|void
name|cam_sim_set_path
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|u_int32_t
name|path_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convenience routines for accessing sim attributes. */
end_comment

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|cam_sim_path
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|cam_sim_name
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
name|cam_sim_softc
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|cam_sim_unit
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|cam_sim_bus
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generically useful offsets into the sim private area */
end_comment

begin_define
define|#
directive|define
name|spriv_ptr0
value|sim_priv.entries[0].ptr
end_define

begin_define
define|#
directive|define
name|spriv_ptr1
value|sim_priv.entries[1].ptr
end_define

begin_define
define|#
directive|define
name|spriv_field0
value|sim_priv.entries[0].field
end_define

begin_define
define|#
directive|define
name|spriv_field1
value|sim_priv.entries[1].field
end_define

begin_comment
comment|/*  * The sim driver should not access anything directly from this  * structure.  */
end_comment

begin_struct
struct|struct
name|cam_sim
block|{
name|sim_action_func
name|sim_action
decl_stmt|;
name|sim_poll_func
name|sim_poll
decl_stmt|;
specifier|const
name|char
modifier|*
name|sim_name
decl_stmt|;
name|void
modifier|*
name|softc
decl_stmt|;
name|struct
name|mtx
modifier|*
name|mtx
decl_stmt|;
name|u_int32_t
name|path_id
decl_stmt|;
comment|/* The Boot device may set this to 0? */
name|u_int32_t
name|unit_number
decl_stmt|;
name|u_int32_t
name|bus_id
decl_stmt|;
name|int
name|max_tagged_dev_openings
decl_stmt|;
name|int
name|max_dev_openings
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|CAM_SIM_REL_TIMEOUT_PENDING
value|0x01
define|#
directive|define
name|CAM_SIM_MPSAFE
value|0x02
name|struct
name|callout
name|callout
decl_stmt|;
name|struct
name|cam_devq
modifier|*
name|devq
decl_stmt|;
comment|/* Device Queue to use for this SIM */
comment|/* "Pool" of inactive ccbs managed by xpt_alloc_ccb and xpt_free_ccb */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|ccb_freeq
expr_stmt|;
comment|/* 	 * Maximum size of ccb pool.  Modified as devices are added/removed 	 * or have their * opening counts changed. 	 */
name|u_int
name|max_ccbs
decl_stmt|;
comment|/* Current count of allocated ccbs */
name|u_int
name|ccb_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CAM_SIM_LOCK
parameter_list|(
name|sim
parameter_list|)
value|mtx_lock((sim)->mtx);
end_define

begin_define
define|#
directive|define
name|CAM_SIM_UNLOCK
parameter_list|(
name|sim
parameter_list|)
value|mtx_unlock((sim)->mtx);
end_define

begin_function
specifier|static
name|__inline
name|u_int32_t
name|cam_sim_path
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
block|{
return|return
operator|(
name|sim
operator|->
name|path_id
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|cam_sim_name
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
block|{
return|return
operator|(
name|sim
operator|->
name|sim_name
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|cam_sim_softc
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
block|{
return|return
operator|(
name|sim
operator|->
name|softc
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|cam_sim_unit
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
block|{
return|return
operator|(
name|sim
operator|->
name|unit_number
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|cam_sim_bus
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|)
block|{
return|return
operator|(
name|sim
operator|->
name|bus_id
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_SIM_H */
end_comment

end_unit

