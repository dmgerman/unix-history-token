begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * User-space command  *  * Note that the command's scatter/gather list will be computed by the  * driver, and cannot be filled in by the consumer.  */
end_comment

begin_struct
struct|struct
name|twe_usercommand
block|{
name|TWE_Command
name|tu_command
decl_stmt|;
comment|/* command ready for the controller */
name|void
modifier|*
name|tu_data
decl_stmt|;
comment|/* pointer to data in userspace */
name|size_t
name|tu_size
decl_stmt|;
comment|/* userspace data length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TWEIO_COMMAND
value|_IOWR('T', 100, struct twe_usercommand)
end_define

begin_comment
comment|/*  * Command queue statistics  */
end_comment

begin_define
define|#
directive|define
name|TWEQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|TWEQ_BIO
value|1
end_define

begin_define
define|#
directive|define
name|TWEQ_READY
value|2
end_define

begin_define
define|#
directive|define
name|TWEQ_BUSY
value|3
end_define

begin_define
define|#
directive|define
name|TWEQ_COMPLETE
value|4
end_define

begin_define
define|#
directive|define
name|TWEQ_COUNT
value|5
end_define

begin_comment
comment|/* total number of queues */
end_comment

begin_struct
struct|struct
name|twe_qstat
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

begin_comment
comment|/*  * Statistics request  */
end_comment

begin_union
union|union
name|twe_statrequest
block|{
name|u_int32_t
name|ts_item
decl_stmt|;
name|struct
name|twe_qstat
name|ts_qstat
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|TWEIO_STATS
value|_IOWR('T', 101, union twe_statrequest)
end_define

begin_comment
comment|/*  * AEN listen  */
end_comment

begin_define
define|#
directive|define
name|TWEIO_AEN_POLL
value|_IOR('T', 102, int)
end_define

begin_define
define|#
directive|define
name|TWEIO_AEN_WAIT
value|_IOR('T', 103, int)
end_define

begin_comment
comment|/*  * Controller parameter access  */
end_comment

begin_struct
struct|struct
name|twe_paramcommand
block|{
name|u_int16_t
name|tp_table_id
decl_stmt|;
name|u_int8_t
name|tp_param_id
decl_stmt|;
name|void
modifier|*
name|tp_data
decl_stmt|;
name|u_int8_t
name|tp_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TWEIO_SET_PARAM
value|_IOW ('T', 104, struct twe_paramcommand)
end_define

begin_define
define|#
directive|define
name|TWEIO_GET_PARAM
value|_IOW ('T', 105, struct twe_paramcommand)
end_define

begin_comment
comment|/*  * Request a controller soft-reset  */
end_comment

begin_define
define|#
directive|define
name|TWEIO_RESET
value|_IO  ('T', 106)
end_define

end_unit

