begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Cardbus CIS definitions  */
end_comment

begin_struct_decl
struct_decl|struct
name|cis_tupleinfo
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|cardbus_do_cis
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAXTUPLESIZE
value|0x400
end_define

begin_comment
comment|/* BAR */
end_comment

begin_define
define|#
directive|define
name|TPL_BAR_REG_ASI_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|TPL_BAR_REG_AS
value|0x10
end_define

begin_define
define|#
directive|define
name|TPL_BAR_REG_PREFETCHABLE_ONLY
value|0x20
end_define

begin_define
define|#
directive|define
name|TPL_BAR_REG_PREFETCHABLE_CACHEABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|TPL_BAR_REG_PREFETCHABLE
value|0x60
end_define

begin_define
define|#
directive|define
name|TPL_BAR_REG_BELOW1MB
value|0x80
end_define

begin_comment
comment|/* CISTPL_FUNC */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_MF
value|0
end_define

begin_comment
comment|/* multi function tuple */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_MEM
value|1
end_define

begin_comment
comment|/* memory */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_SERIAL
value|2
end_define

begin_comment
comment|/* serial, including modem and fax */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_PARALLEL
value|3
end_define

begin_comment
comment|/* parallel, including printer and SCSI */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_DISK
value|4
end_define

begin_comment
comment|/* Disk */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_VIDEO
value|5
end_define

begin_comment
comment|/* Video Adaptor */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_LAN
value|6
end_define

begin_comment
comment|/* LAN Adaptor */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNC_AIMS
value|7
end_define

begin_comment
comment|/* Auto Inclement Mass Strages */
end_comment

begin_comment
comment|/* TPL_FUNC_LAN */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNCE_LAN_TECH
value|1
end_define

begin_comment
comment|/* technology */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNCE_LAN_SPEED
value|2
end_define

begin_comment
comment|/* speed */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNCE_LAN_MEDIA
value|3
end_define

begin_comment
comment|/* which media do you use? */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNCE_LAN_NID
value|4
end_define

begin_comment
comment|/* node id (address) */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNCE_LAN_CONN
value|5
end_define

begin_comment
comment|/* connector type (shape) */
end_comment

begin_comment
comment|/* TPL_FUNC_SERIAL */
end_comment

begin_define
define|#
directive|define
name|TPL_FUNCE_SER_UART
value|0
end_define

begin_comment
comment|/* UART type */
end_comment

end_unit

