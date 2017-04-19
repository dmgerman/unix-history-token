begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/****************************************************************************  *  * Name:        mfw_hsi.h  *  * Description: Global definitions  *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MFW_HSI_H
end_ifndef

begin_define
define|#
directive|define
name|MFW_HSI_H
end_define

begin_define
define|#
directive|define
name|MFW_TRACE_SIGNATURE
value|0x25071946
end_define

begin_comment
comment|/* The trace in the buffer */
end_comment

begin_define
define|#
directive|define
name|MFW_TRACE_EVENTID_MASK
value|0x00ffff
end_define

begin_define
define|#
directive|define
name|MFW_TRACE_PRM_SIZE_MASK
value|0x0f0000
end_define

begin_define
define|#
directive|define
name|MFW_TRACE_PRM_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MFW_TRACE_ENTRY_SIZE
value|3
end_define

begin_struct
struct|struct
name|mcp_trace
block|{
name|u32
name|signature
decl_stmt|;
comment|/* Help to identify that the trace is valid */
name|u32
name|size
decl_stmt|;
comment|/* the size of the trace buffer in bytes*/
name|u32
name|curr_level
decl_stmt|;
comment|/* 2 - all will be written to the buffer 				 * 1 - debug trace will not be written 				 * 0 - just errors will be written to the buffer 				 */
name|u32
name|modules_mask
index|[
literal|2
index|]
decl_stmt|;
comment|/* a bit per module, 1 means write it, 0 means mask it */
comment|/* Warning: the following pointers are assumed to be 32bits as they are used only in the MFW */
name|u32
name|trace_prod
decl_stmt|;
comment|/* The next trace will be written to this offset */
name|u32
name|trace_oldest
decl_stmt|;
comment|/* The oldest valid trace starts at this offset (usually very close after the current producer) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MFW_HSI_H */
end_comment

end_unit

