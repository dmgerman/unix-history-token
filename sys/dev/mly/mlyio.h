begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/********************************************************************************  * Control structures exchanged through the GAM interface with userland  * management tools.  *  * The member naming here is consistent with the Linux driver, with which this  * interface is basically compatible.   */
end_comment

begin_struct
struct|struct
name|mly_user_command
block|{
name|unsigned
name|char
name|ControllerNumber
decl_stmt|;
name|union
name|mly_command_packet
name|CommandMailbox
decl_stmt|;
name|int
name|DataTransferLength
decl_stmt|;
name|int
name|RequestSenseLength
decl_stmt|;
name|void
modifier|*
name|DataTransferBuffer
decl_stmt|;
name|void
modifier|*
name|RequestSenseBuffer
decl_stmt|;
name|int
name|CommandStatus
decl_stmt|;
comment|/* not in the Linux structure */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLYIO_COMMAND
value|_IOWR('M', 200, struct mly_user_command)
end_define

begin_struct
struct|struct
name|mly_user_health
block|{
name|unsigned
name|char
name|ControllerNumber
decl_stmt|;
name|void
modifier|*
name|HealthStatusBuffer
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLYIO_HEALTH
value|_IOW('M', 201, struct mly_user_health)
end_define

begin_comment
comment|/*  * Command queue statistics  */
end_comment

begin_define
define|#
directive|define
name|MLYQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|MLYQ_CCB
value|1
end_define

begin_define
define|#
directive|define
name|MLYQ_READY
value|2
end_define

begin_define
define|#
directive|define
name|MLYQ_BUSY
value|3
end_define

begin_define
define|#
directive|define
name|MLYQ_COMPLETE
value|4
end_define

begin_define
define|#
directive|define
name|MLYQ_COUNT
value|5
end_define

begin_struct
struct|struct
name|mly_qstat
block|{
name|u_int32_t
name|q_length
decl_stmt|;
name|u_int32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

end_unit

