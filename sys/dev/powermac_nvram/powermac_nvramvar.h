begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_POWERMAC_POWERMAC_NVRAMVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_POWERMAC_POWERMAC_NVRAMVAR_H_
end_define

begin_define
define|#
directive|define
name|NVRAM_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|CORE99_SIGNATURE
value|0x5a
end_define

begin_define
define|#
directive|define
name|SM_FLASH_CMD_ERASE_CONFIRM
value|0xd0
end_define

begin_define
define|#
directive|define
name|SM_FLASH_CMD_ERASE_SETUP
value|0x20
end_define

begin_define
define|#
directive|define
name|SM_FLASH_CMD_RESET
value|0xff
end_define

begin_define
define|#
directive|define
name|SM_FLASH_CMD_WRITE_SETUP
value|0x40
end_define

begin_define
define|#
directive|define
name|SM_FLASH_CMD_CLEAR_STATUS
value|0x50
end_define

begin_define
define|#
directive|define
name|SM_FLASH_CMD_READ_STATUS
value|0x70
end_define

begin_define
define|#
directive|define
name|SM_FLASH_STATUS_DONE
value|0x80
end_define

begin_define
define|#
directive|define
name|SM_FLASH_STATUS_ERR
value|0x38
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|powermac_nvram_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|phandle_t
name|sc_node
decl_stmt|;
name|vm_offset_t
name|sc_bank
decl_stmt|;
name|vm_offset_t
name|sc_bank0
decl_stmt|;
name|vm_offset_t
name|sc_bank1
decl_stmt|;
name|uint8_t
name|sc_data
index|[
name|NVRAM_SIZE
index|]
decl_stmt|;
name|struct
name|cdev
modifier|*
name|sc_cdev
decl_stmt|;
name|int
name|sc_type
decl_stmt|;
define|#
directive|define
name|FLASH_TYPE_SM
value|0
define|#
directive|define
name|FLASH_TYPE_AMD
value|1
name|int
name|sc_isopen
decl_stmt|;
name|int
name|sc_rpos
decl_stmt|;
name|int
name|sc_wpos
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|chrp_header
block|{
name|uint8_t
name|signature
decl_stmt|;
name|uint8_t
name|chrp_checksum
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|char
name|name
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|core99_header
block|{
name|struct
name|chrp_header
name|chrp_header
decl_stmt|;
name|uint32_t
name|adler_checksum
decl_stmt|;
name|uint32_t
name|generation
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|2
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
comment|/* _POWERPC_POWERMAC_POWERMAC_NVRAMVAR_H_ */
end_comment

end_unit

