begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_ADB_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_ADB_H_
end_define

begin_include
include|#
directive|include
file|"adb_hb_if.h"
end_include

begin_include
include|#
directive|include
file|"adb_if.h"
end_include

begin_enum
enum|enum
block|{
name|ADB_COMMAND_FLUSH
init|=
literal|0
block|,
name|ADB_COMMAND_LISTEN
init|=
literal|2
block|,
name|ADB_COMMAND_TALK
init|=
literal|3
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|ADB_DEVICE_DONGLE
init|=
literal|0x01
block|,
name|ADB_DEVICE_KEYBOARD
init|=
literal|0x02
block|,
name|ADB_DEVICE_MOUSE
init|=
literal|0x03
block|,
name|ADB_DEVICE_TABLET
init|=
literal|0x04
block|,
name|ADB_DEVICE_MODEM
init|=
literal|0x05
block|,
name|ADB_DEVICE_MISC
init|=
literal|0x07
block|}
enum|;
end_enum

begin_struct
struct|struct
name|adb_devinfo
block|{
name|uint8_t
name|address
decl_stmt|;
name|uint8_t
name|default_address
decl_stmt|;
name|uint8_t
name|handler_id
decl_stmt|;
name|uint16_t
name|register3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Pass packets down through the bus manager */
end_comment

begin_function_decl
name|u_int
name|adb_send_packet
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|command
parameter_list|,
name|u_char
name|reg
parameter_list|,
name|int
name|len
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|adb_set_autopoll
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pass packets up from the interface */
end_comment

begin_function_decl
name|u_int
name|adb_receive_raw_packet
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|status
parameter_list|,
name|u_char
name|command
parameter_list|,
name|int
name|len
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|adb_get_device_type
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|adb_get_device_handler
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|adb_set_device_handler
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint8_t
name|newhandler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|adb_read_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|reg
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|adb_write_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|reg
parameter_list|,
name|size_t
name|len
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bits for implementing ADB host bus adapters */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|adb_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|driver_t
name|adb_driver
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

