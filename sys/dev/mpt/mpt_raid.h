begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Definitions for the integrated RAID features LSI MPT Fusion adapters.  *  * Copyright (c) 2005, WHEEL Sp. z o.o.  * Copyright (c) 2004, 2005 Justin T. Gibbs  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the names of the above listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Some Breakage and Bug Fixing added later.  * Copyright (c) 2006, by Matthew Jacob  * All Rights Reserved  *  * Support from LSI-Logic has also gone a great deal toward making this a  * workable subsystem and is gratefully acknowledged.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPT_RAID_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPT_RAID_H_
end_define

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|MPT_RAID_MWCE_ON
block|,
name|MPT_RAID_MWCE_OFF
block|,
name|MPT_RAID_MWCE_REBUILD_ONLY
block|,
name|MPT_RAID_MWCE_NC
block|}
name|mpt_raid_mwce_t
typedef|;
end_typedef

begin_function_decl
name|cam_status
name|mpt_map_physdisk
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|union
name|ccb
modifier|*
parameter_list|,
name|target_id_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_is_raid_member
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|target_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_is_raid_volume
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|target_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|cam_status mpt_raid_quiesce_disk(struct mpt_softc *, struct mpt_raid_disk *, request_t *);
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|mpt_raid_free_mem
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|mpt_raid_wakeup
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
block|{
name|mpt
operator|->
name|raid_wakeup
operator|++
expr_stmt|;
name|wakeup
argument_list|(
operator|&
name|mpt
operator|->
name|raid_volumes
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|MPT_RAID_SYNC_REPORT_INTERVAL
value|(15 * 60 * hz)
end_define

begin_define
define|#
directive|define
name|MPT_RAID_RESYNC_RATE_MAX
value|(255)
end_define

begin_define
define|#
directive|define
name|MPT_RAID_RESYNC_RATE_MIN
value|(1)
end_define

begin_define
define|#
directive|define
name|MPT_RAID_RESYNC_RATE_NC
value|(0)
end_define

begin_define
define|#
directive|define
name|MPT_RAID_RESYNC_RATE_DEFAULT
value|MPT_RAID_RESYNC_RATE_NC
end_define

begin_define
define|#
directive|define
name|MPT_RAID_QUEUE_DEPTH_DEFAULT
value|(128)
end_define

begin_define
define|#
directive|define
name|MPT_RAID_MWCE_DEFAULT
value|MPT_RAID_MWCE_NC
end_define

begin_define
define|#
directive|define
name|RAID_VOL_FOREACH
parameter_list|(
name|mpt
parameter_list|,
name|mpt_vol
parameter_list|)
define|\
value|for (mpt_vol = (mpt)->raid_volumes;				\ 	     mpt_vol != (mpt)->raid_volumes + (mpt)->raid_max_volumes;	\ 	     mpt_vol++)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_MPT_RAID_H_ */
end_comment

end_unit

