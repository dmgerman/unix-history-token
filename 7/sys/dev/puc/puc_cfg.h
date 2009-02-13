begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PUC_CFG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PUC_CFG_H
end_define

begin_define
define|#
directive|define
name|DEFAULT_RCLK
value|1843200
end_define

begin_define
define|#
directive|define
name|PUC_PORT_NONSTANDARD
value|0
end_define

begin_define
define|#
directive|define
name|PUC_PORT_1P
value|1
end_define

begin_comment
comment|/* 1 parallel port */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_1S
value|2
end_define

begin_comment
comment|/* 1 serial port */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_1S1P
value|3
end_define

begin_comment
comment|/* 1 serial + 1 parallel ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_1S2P
value|4
end_define

begin_comment
comment|/* 1 serial + 2 parallel ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_2P
value|5
end_define

begin_comment
comment|/* 2 parallel ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_2S
value|6
end_define

begin_comment
comment|/* 2 serial ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_2S1P
value|7
end_define

begin_comment
comment|/* 2 serial + 1 parallel ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_3S
value|8
end_define

begin_comment
comment|/* 3 serial ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_4S
value|9
end_define

begin_comment
comment|/* 4 serial ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_4S1P
value|10
end_define

begin_comment
comment|/* 4 serial + 1 parallel ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_6S
value|11
end_define

begin_comment
comment|/* 6 serial ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_8S
value|12
end_define

begin_comment
comment|/* 8 serial ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_12S
value|13
end_define

begin_comment
comment|/* 12 serial ports */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_16S
value|14
end_define

begin_comment
comment|/* 16 serial ports */
end_comment

begin_comment
comment|/* Interrupt Latch Register (ILR) types */
end_comment

begin_define
define|#
directive|define
name|PUC_ILR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PUC_ILR_DIGI
value|1
end_define

begin_define
define|#
directive|define
name|PUC_ILR_QUATECH
value|2
end_define

begin_comment
comment|/* Configuration queries. */
end_comment

begin_enum
enum|enum
name|puc_cfg_cmd
block|{
name|PUC_CFG_GET_CLOCK
block|,
name|PUC_CFG_GET_DESC
block|,
name|PUC_CFG_GET_ILR
block|,
name|PUC_CFG_GET_LEN
block|,
name|PUC_CFG_GET_NPORTS
block|,
name|PUC_CFG_GET_OFS
block|,
name|PUC_CFG_GET_RID
block|,
name|PUC_CFG_GET_TYPE
block|,
name|PUC_CFG_SETUP
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|puc_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|puc_config_f
parameter_list|(
name|struct
name|puc_softc
modifier|*
parameter_list|,
name|enum
name|puc_cfg_cmd
parameter_list|,
name|int
parameter_list|,
name|intptr_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|puc_cfg
block|{
name|uint16_t
name|vendor
decl_stmt|;
name|uint16_t
name|device
decl_stmt|;
name|uint16_t
name|subvendor
decl_stmt|;
name|uint16_t
name|subdevice
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|int
name|clock
decl_stmt|;
name|int8_t
name|ports
decl_stmt|;
name|int8_t
name|rid
decl_stmt|;
comment|/* Rid of first port */
name|int8_t
name|d_rid
decl_stmt|;
comment|/* Delta rid of next ports */
name|int8_t
name|d_ofs
decl_stmt|;
comment|/* Delta offset of next ports */
name|puc_config_f
modifier|*
name|config_function
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|puc_config_f
name|puc_config
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PUC_CFG_H_ */
end_comment

end_unit

