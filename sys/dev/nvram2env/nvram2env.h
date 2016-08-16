begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Aleksandr Rybalko.  * Copyright (c) 2016 Michael Zhilin.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NVRAM2ENV_NVRAM2ENV_H_
end_ifndef

begin_define
define|#
directive|define
name|NVRAM2ENV_NVRAM2ENV_H_
end_define

begin_define
define|#
directive|define
name|nvram2env_read_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_bt, (sc)->sc_bh,(reg))
end_define

begin_define
define|#
directive|define
name|nvram2env_read_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_bt, (sc)->sc_bh,(reg))
end_define

begin_define
define|#
directive|define
name|nvram2env_read_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_bt, (sc)->sc_bh,(reg))
end_define

begin_define
define|#
directive|define
name|nvram2env_write_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_bt, (sc)->sc_bh,	\ 			 (reg), (val))
end_define

begin_define
define|#
directive|define
name|nvram2env_write_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_bt, (sc)->sc_bh,	\ 			 (reg), (val))
end_define

begin_define
define|#
directive|define
name|nvram2env_write_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_bt, (sc)->sc_bh,	\ 			 (reg), (val))
end_define

begin_struct
struct|struct
name|nvram2env_softc
block|{
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_addr_t
name|addr
decl_stmt|;
name|int
name|need_swap
decl_stmt|;
name|uint32_t
name|sig
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|NVRAM_FLAGS_NOCHECK
value|0x0001
comment|/* Do not check(CRC or somthing else)*/
define|#
directive|define
name|NVRAM_FLAGS_GENERIC
value|0x0002
comment|/* Format Generic, skip 4b and read */
define|#
directive|define
name|NVRAM_FLAGS_BROADCOM
value|0x0004
comment|/* Format Broadcom, use struct nvram */
define|#
directive|define
name|NVRAM_FLAGS_UBOOT
value|0x0008
comment|/* Format Generic, skip 4b of CRC and read */
name|uint32_t
name|maxsize
decl_stmt|;
name|uint32_t
name|crc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NVRAM_MAX_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|CFE_NVRAM_SIGNATURE
value|0x48534c46
end_define

begin_struct
struct|struct
name|nvram
block|{
name|u_int32_t
name|sig
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
name|u_int32_t
name|unknown1
decl_stmt|;
name|u_int32_t
name|unknown2
decl_stmt|;
name|u_int32_t
name|unknown3
decl_stmt|;
name|char
name|data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|nvram2env_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvram2env_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|nvram2env_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|driver_t
name|nvram2env_driver
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_NVRAM2ENV_NVRAM2ENV_H_ */
end_comment

end_unit

