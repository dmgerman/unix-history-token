begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Adaptec, Inc.  * Copyright (c) 2010-2012 PMC-Sierra, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PRINT_BUFFER_SIZE
end_ifndef

begin_define
define|#
directive|define
name|PRINT_BUFFER_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_FLAGS_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_KERNEL_PRINT_B
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_FW_PRINT_B
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_FUNCTION_ENTRY_B
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_FUNCTION_EXIT_B
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_ERROR_B
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_INIT_B
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_OS_COMMANDS_B
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_SCAN_B
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_COALESCE_B
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_IOCTL_COMMANDS_B
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_SYNC_COMMANDS_B
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_COMM_B
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_CSMI_COMMANDS_B
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_AIF_B
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HBA_FLAGS_DBG_DEBUG_B
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FW_DEBUG_STR_LENGTH_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|FW_DEBUG_FLAGS_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|FW_DEBUG_BLED_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|FW_DEBUG_FLAGS_NO_HEADERS_B
value|0x01
end_define

begin_struct_decl
struct_decl|struct
name|aac_softc
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|aacraid_get_fw_debug_buffer
parameter_list|(
name|struct
name|aac_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aacraid_fw_printf
parameter_list|(
name|struct
name|aac_softc
modifier|*
parameter_list|,
name|unsigned
name|long
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
specifier|extern
name|void
name|aacraid_fw_print_mem
parameter_list|(
name|struct
name|aac_softc
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aacraid_sync_command
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|command
parameter_list|,
name|u_int32_t
name|arg0
parameter_list|,
name|u_int32_t
name|arg1
parameter_list|,
name|u_int32_t
name|arg2
parameter_list|,
name|u_int32_t
name|arg3
parameter_list|,
name|u_int32_t
modifier|*
name|sp
parameter_list|,
name|u_int32_t
modifier|*
name|r1
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

