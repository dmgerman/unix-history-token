begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Cardbus CIS definitions  */
end_comment

begin_function_decl
name|int
name|cardbus_do_cis
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
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
comment|/* CIS TUPLES */
end_comment

begin_define
define|#
directive|define
name|CISTPL_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|CISTPL_LONG_LINK_CB
value|0x02
end_define

begin_define
define|#
directive|define
name|CISTPL_INDIRECT
value|0x03
end_define

begin_define
define|#
directive|define
name|CISTPL_CONFIG_CB
value|0x04
end_define

begin_define
define|#
directive|define
name|CISTPL_CFTABLE_ENTRY_CB
value|0x05
end_define

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_MFC
value|0x06
end_define

begin_define
define|#
directive|define
name|CISTPL_BAR
value|0x07
end_define

begin_define
define|#
directive|define
name|CISTPL_PWR_MGMNT
value|0x08
end_define

begin_define
define|#
directive|define
name|CISTPL_EXTDEVICE
value|0x09
end_define

begin_define
define|#
directive|define
name|CISTPL_CHECKSUM
value|0x10
end_define

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_A
value|0x11
end_define

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_C
value|0x12
end_define

begin_define
define|#
directive|define
name|CISTPL_LINKTARGET
value|0x13
end_define

begin_define
define|#
directive|define
name|CISTPL_NO_LINK
value|0x14
end_define

begin_define
define|#
directive|define
name|CISTPL_VERS_1
value|0x15
end_define

begin_define
define|#
directive|define
name|CISTPL_ALTSTR
value|0x16
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_A
value|0x17
end_define

begin_define
define|#
directive|define
name|CISTPL_JEDEC_C
value|0x18
end_define

begin_define
define|#
directive|define
name|CISTPL_JEDEC_A
value|0x19
end_define

begin_define
define|#
directive|define
name|CISTPL_CONFIG
value|0x1A
end_define

begin_define
define|#
directive|define
name|CISTPL_CFTABLE_ENTRY
value|0x1B
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_OC
value|0x1C
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_OA
value|0x1D
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_GEO
value|0x1E
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_GEO_A
value|0x1F
end_define

begin_define
define|#
directive|define
name|CISTPL_MANFID
value|0x20
end_define

begin_define
define|#
directive|define
name|CISTPL_FUNCID
value|0x21
end_define

begin_define
define|#
directive|define
name|CISTPL_FUNCE
value|0x22
end_define

begin_define
define|#
directive|define
name|CISTPL_SWIL
value|0x23
end_define

begin_define
define|#
directive|define
name|CISTPL_VERS_2
value|0x40
end_define

begin_define
define|#
directive|define
name|CISTPL_FORMAT
value|0x41
end_define

begin_define
define|#
directive|define
name|CISTPL_GEOMETRY
value|0x42
end_define

begin_define
define|#
directive|define
name|CISTPL_BYTEORDER
value|0x43
end_define

begin_define
define|#
directive|define
name|CISTPL_DATE
value|0x44
end_define

begin_define
define|#
directive|define
name|CISTPL_BATTERY
value|0x45
end_define

begin_define
define|#
directive|define
name|CISTPL_ORG
value|0x46
end_define

begin_define
define|#
directive|define
name|CISTPL_END
value|0xFF
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
value|0x08
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
value|2
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

end_unit

