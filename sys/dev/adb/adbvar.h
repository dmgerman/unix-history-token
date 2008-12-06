begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_ADBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_ADBVAR_H_
end_define

begin_include
include|#
directive|include
file|"adb.h"
end_include

begin_enum
enum|enum
block|{
name|ADB_COMMAND_BUS_RESET
init|=
literal|0
block|}
enum|;
end_enum

begin_struct
struct|struct
name|adb_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|device_t
name|parent
decl_stmt|;
name|struct
name|intr_config_hook
name|enum_hook
decl_stmt|;
specifier|volatile
name|int
name|sync_packet
decl_stmt|;
specifier|volatile
name|int
name|packet_reply
decl_stmt|;
name|uint16_t
name|autopoll_mask
decl_stmt|;
name|uint8_t
name|syncreg
index|[
literal|8
index|]
decl_stmt|;
name|device_t
name|children
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|adb_devinfo
name|devinfo
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_ADBVAR_H_ */
end_comment

end_unit

