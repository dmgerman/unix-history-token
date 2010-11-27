begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Juli Mallett<jmallett@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for Marvell MV88E61XX  *  * Note that names and definitions were gleaned from Linux and U-Boot patches  * released by Marvell, often by looking at contextual use of the registers  * involved, and may not be representative of the full functionality of those  * registers and are certainly not an exhaustive enumeration of registers.  *  * For an exhaustive enumeration of registers, check out the QD-DSDT package  * included in the Marvell ARM Feroceon Board Support Package for Linux.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_CAVIUM_OCTE_MV88E61XXPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_CAVIUM_OCTE_MV88E61XXPHYREG_H_
end_define

begin_comment
comment|/*  * Port addresses& per-port registers.  */
end_comment

begin_define
define|#
directive|define
name|MV88E61XX_PORT
parameter_list|(
name|x
parameter_list|)
value|(0x10 + (x))
end_define

begin_define
define|#
directive|define
name|MV88E61XX_HOST_PORT
value|(5)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORTS
value|(6)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FORCE_MAC
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_PAUSE_CONTROL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_REVISION
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_CONTROL
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_CONTROL2
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_VLAN_MAP
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_VLAN
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_EGRESS_CONTROL
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_EGRESS_CONTROL2
value|(0x0a)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_PORT_LEARN
value|(0x0b)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_ATU_CONTROL
value|(0x0c)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_PRIORITY_CONTROL
value|(0x0d)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_ETHER_PROTO
value|(0x0f)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_PROVIDER_PROTO
value|(0x1a)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_PRIORITY_MAP
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_PRIORITY_MAP2
value|(0x19)
end_define

begin_comment
comment|/*  * Fields and values in each register.  */
end_comment

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_MEDIA
value|(0x0300)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_MEDIA_10M
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_MEDIA_100M
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_MEDIA_1G
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_DUPLEX
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_LINK
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_STATUS_FC
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_CONTROL_DOUBLE_TAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_MAP_DEST
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_DISCARD_UNTAGGED
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_DISCARD_TAGGED
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_8021Q_MODE
value|(0x0c00)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_8021Q_DISABLED
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_8021Q_FALLBACK
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_8021Q_CHECK
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_PORT_FILTER_8021Q_SECURE
value|(0x0c00)
end_define

begin_comment
comment|/*  * Global address& global registers.  */
end_comment

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL
value|(0x1b)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_STATUS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_CONTROL
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_OP
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_VID
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_DATA_P0P3
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_DATA_P4P5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_ATU_CONTROL
value|(0x0a)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_PRIORITY_MAP
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_MONITOR
value|(0x1a)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_REMOTE_MGMT
value|(0x1c)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_STATS
value|(0x1d)
end_define

begin_comment
comment|/*  * Fields and values in each register.  */
end_comment

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_OP_BUSY
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_OP_OP
value|(0x7000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_OP_OP_FLUSH
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_OP_OP_VTU_LOAD
value|(0x3000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL_VTU_VID_VALID
value|(0x1000)
end_define

begin_comment
comment|/*  * Second global address& second global registers.  */
end_comment

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2
value|(0x1c)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_MANAGE_2X
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_MANAGE_0X
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_TRUNK_MASK
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_TRUNK_MAP
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_RATELIMIT
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_VLAN_CONTROL
value|(0x0b)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_MAC_ADDRESS
value|(0x0d)
end_define

begin_comment
comment|/*  * Fields and values in each register.  */
end_comment

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_DOUBLE_USE
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_LOOP_PREVENT
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_FLOW_MESSAGE
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_FLOOD_BC
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_REMOVE_PTAG
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_AGE_INT
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_FLOW_TAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_ALWAYS_VTU
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_FORCE_FC_PRI
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_FC_PRI
value|(0x0070)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_MGMT_TO_HOST
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MV88E61XX_GLOBAL2_CONTROL2_MGMT_PRI
value|(0x0007)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MIPS_CAVIUM_OCTE_MV88E61XXPHYREG_H_ */
end_comment

end_unit

