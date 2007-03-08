begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * LSI MPT Host Adapter FreeBSD Wrapper Definitions (CAM version)  *  * Copyright (c) 2000, 2001 by Greg Ansley, Adam Prewett  *  * Partially derived from Matty Jacobs ISP driver.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2006 by Matthew Jacob  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the names of the above listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Support from Chris Ellsworth in order to make SAS adapters work  * is gratefully acknowledged.  *  * Support from LSI-Logic has also gone a great deal toward making this a  * workable subsystem and is gratefully acknowledged.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2004, Avid Technology, Inc. and its contributors.  * Copyright (c) 2005, WHEEL Sp. z o.o.  * Copyright (c) 2004, 2005 Justin T. Gibbs  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the names of the above listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPT_CAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPT_CAM_H_
end_define

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_define
define|#
directive|define
name|ccb_mpt_ptr
value|sim_priv.entries[0].ptr
end_define

begin_define
define|#
directive|define
name|ccb_req_ptr
value|sim_priv.entries[1].ptr
end_define

begin_comment
comment|/************************** CCB Manipulation Routines *************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_freeze_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_set_ccb_status
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|cam_status
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|mpt_freeze_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
block|{
if|if
condition|(
operator|(
name|ccb
operator|->
name|ccb_h
operator|.
name|status
operator|&
name|CAM_DEV_QFRZN
operator|)
operator|==
literal|0
condition|)
block|{
name|ccb
operator|->
name|ccb_h
operator|.
name|status
operator||=
name|CAM_DEV_QFRZN
expr_stmt|;
name|xpt_freeze_devq
argument_list|(
name|ccb
operator|->
name|ccb_h
operator|.
name|path
argument_list|,
comment|/*count*/
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mpt_set_ccb_status
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|cam_status
name|status
parameter_list|)
block|{
name|ccb
operator|->
name|ccb_h
operator|.
name|status
operator|&=
operator|~
name|CAM_STATUS_MASK
expr_stmt|;
name|ccb
operator|->
name|ccb_h
operator|.
name|status
operator||=
name|status
expr_stmt|;
block|}
end_function

begin_comment
comment|/****************************** Timeout Recovery ******************************/
end_comment

begin_comment
comment|/*  * The longest timeout specified for a Task Managent command.  */
end_comment

begin_define
define|#
directive|define
name|MPT_TMF_MAX_TIMEOUT
value|(20000)
end_define

begin_function
specifier|static
name|__inline
name|void
name|mpt_wakeup_recovery_thread
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
block|{
name|wakeup
argument_list|(
name|mpt
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_MPT_CAM_H_ */
end_comment

end_unit

