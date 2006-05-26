begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Definitions for the integrated RAID features LSI MPT Fusion adapters.  *  * Copyright (c) 2005, WHEEL Sp. z o.o.  * Copyright (c) 2004, 2005 Justin T. Gibbs  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the names of the above listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
specifier|const
name|char
modifier|*
name|mpt_vol_type
parameter_list|(
name|struct
name|mpt_raid_volume
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mpt_vol_state
parameter_list|(
name|struct
name|mpt_raid_volume
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mpt_disk_state
parameter_list|(
name|struct
name|mpt_raid_disk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_vol_prt
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|struct
name|mpt_raid_volume
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_disk_prt
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|struct
name|mpt_raid_disk
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_issue_raid_req
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|struct
name|mpt_raid_volume
modifier|*
parameter_list|,
name|struct
name|mpt_raid_disk
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|uint32_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cam_status
name|mpt_raid_quiesce_disk
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|struct
name|mpt_raid_disk
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_refresh_raid_data
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_schedule_raid_refresh
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

