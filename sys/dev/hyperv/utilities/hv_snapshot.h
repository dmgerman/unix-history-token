begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VSS_H
end_ifndef

begin_define
define|#
directive|define
name|_VSS_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|FS_VSS_DEV_NAME
value|"hv_fsvss_dev"
end_define

begin_define
define|#
directive|define
name|APP_VSS_DEV_NAME
value|"hv_appvss_dev"
end_define

begin_define
define|#
directive|define
name|VSS_DEV
parameter_list|(
name|VSS
parameter_list|)
value|"/dev/"VSS
end_define

begin_define
define|#
directive|define
name|VSS_SUCCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|VSS_FAIL
value|0x00000001
end_define

begin_enum
enum|enum
name|hv_vss_op_t
block|{
name|HV_VSS_NONE
init|=
literal|0
block|,
name|HV_VSS_CHECK
block|,
name|HV_VSS_FREEZE
block|,
name|HV_VSS_THAW
block|,
name|HV_VSS_COUNT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|hv_vss_opt_msg
block|{
name|uint32_t
name|opt
decl_stmt|;
comment|/* operation */
name|uint32_t
name|status
decl_stmt|;
comment|/* 0 for success, 1 for error */
name|uint64_t
name|msgid
decl_stmt|;
comment|/* an ID used to identify the transaction */
name|uint8_t
name|reserved
index|[
literal|48
index|]
decl_stmt|;
comment|/* reserved values are all zeroes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCHVVSSREAD
value|_IOR('v', 2, struct hv_vss_opt_msg)
end_define

begin_define
define|#
directive|define
name|IOCHVVSSWRITE
value|_IOW('v', 3, struct hv_vss_opt_msg)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

