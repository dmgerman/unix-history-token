begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  * Copyright (c) 1997-2006 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * ioctl definitions for Qlogic FC/SCSI HBA driver  */
end_comment

begin_define
define|#
directive|define
name|ISP_IOC
value|(021)
end_define

begin_comment
comment|/* 'Ctrl-Q' */
end_comment

begin_comment
comment|/*  * This ioctl sets/retrieves the debugging level for this hba instance.  * Note that this is not a simple integer level- see ispvar.h for definitions.  *  * The arguments is a pointer to an integer with the new debugging level.  * The old value is written into this argument.  */
end_comment

begin_define
define|#
directive|define
name|ISP_SDBLEV
value|_IOWR(ISP_IOC, 1, int)
end_define

begin_comment
comment|/*  * This ioctl resets the HBA. Use with caution.  */
end_comment

begin_define
define|#
directive|define
name|ISP_RESETHBA
value|_IO(ISP_IOC, 2)
end_define

begin_comment
comment|/*  * This ioctl performs a fibre channel rescan.  */
end_comment

begin_define
define|#
directive|define
name|ISP_RESCAN
value|_IO(ISP_IOC, 3)
end_define

begin_comment
comment|/*  * This ioctl performs a reset and then will set the adapter to the  * role that was passed in (the old role will be returned). It almost  * goes w/o saying: use with caution.  */
end_comment

begin_define
define|#
directive|define
name|ISP_SETROLE
value|_IOWR(ISP_IOC, 4, int)
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_TARGET
value|0x1
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_INITIATOR
value|0x2
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_BOTH
value|(ISP_ROLE_TARGET|ISP_ROLE_INITIATOR)
end_define

begin_comment
comment|/*  * Get the current adapter role  */
end_comment

begin_define
define|#
directive|define
name|ISP_GETROLE
value|_IOR(ISP_IOC, 5, int)
end_define

begin_comment
comment|/*  * Get/Clear Stats  */
end_comment

begin_define
define|#
directive|define
name|ISP_STATS_VERSION
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|isp_stat_version
decl_stmt|;
name|uint8_t
name|isp_type
decl_stmt|;
comment|/* (ro) reflects chip type */
name|uint8_t
name|isp_revision
decl_stmt|;
comment|/* (ro) reflects chip version */
name|uint8_t
name|unused1
decl_stmt|;
name|uint32_t
name|unused2
decl_stmt|;
comment|/* 	 * Statistics Counters 	 */
define|#
directive|define
name|ISP_NSTATS
value|16
define|#
directive|define
name|ISP_INTCNT
value|0
define|#
directive|define
name|ISP_INTBOGUS
value|1
define|#
directive|define
name|ISP_INTMBOXC
value|2
define|#
directive|define
name|ISP_INGOASYNC
value|3
define|#
directive|define
name|ISP_RSLTCCMPLT
value|4
define|#
directive|define
name|ISP_FPHCCMCPLT
value|5
define|#
directive|define
name|ISP_RSCCHIWAT
value|6
define|#
directive|define
name|ISP_FPCCHIWAT
value|7
name|uint64_t
name|isp_stats
index|[
name|ISP_NSTATS
index|]
decl_stmt|;
block|}
name|isp_stats_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP_GET_STATS
value|_IOR(ISP_IOC, 6, isp_stats_t)
end_define

begin_define
define|#
directive|define
name|ISP_CLR_STATS
value|_IO(ISP_IOC, 7)
end_define

begin_comment
comment|/*  * Initiate a LIP  */
end_comment

begin_define
define|#
directive|define
name|ISP_FC_LIP
value|_IO(ISP_IOC, 8)
end_define

begin_comment
comment|/*  * Return the Port Database structure for the named device, or ENODEV if none.  * Caller fills in virtual loopid (0..255), aka 'target'. The driver returns  * ENODEV (if nothing valid there) or the actual loopid (for local loop devices  * only), 24 bit Port ID and Node and Port WWNs.  */
end_comment

begin_struct
struct|struct
name|isp_fc_device
block|{
name|uint32_t
name|loopid
decl_stmt|;
comment|/* 0..255 */
name|uint32_t
label|:
literal|6
operator|,
name|role
operator|:
literal|2
operator|,
name|portid
operator|:
literal|24
expr_stmt|;
comment|/* 24 bit Port ID */
name|uint64_t
name|node_wwn
decl_stmt|;
name|uint64_t
name|port_wwn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_FC_GETDINFO
value|_IOWR(ISP_IOC, 9, struct isp_fc_device)
end_define

begin_comment
comment|/*  * Get F/W crash dump  */
end_comment

begin_define
define|#
directive|define
name|ISP_GET_FW_CRASH_DUMP
value|_IO(ISP_IOC, 10)
end_define

begin_define
define|#
directive|define
name|ISP_FORCE_CRASH_DUMP
value|_IO(ISP_IOC, 11)
end_define

begin_comment
comment|/*  * Get information about this Host Adapter, including current connection  * topology and capabilities.  */
end_comment

begin_struct
struct|struct
name|isp_hba_device
block|{
name|uint32_t
label|:
literal|8
operator|,
operator|:
literal|4
operator|,
name|fc_speed
operator|:
literal|4
operator|,
comment|/* Gbps */
operator|:
literal|2
operator|,
name|fc_class2
operator|:
literal|1
operator|,
name|fc_ip_supported
operator|:
literal|1
operator|,
name|fc_scsi_supported
operator|:
literal|1
operator|,
name|fc_topology
operator|:
literal|3
operator|,
name|fc_loopid
operator|:
literal|8
expr_stmt|;
name|uint8_t
name|fc_fw_major
decl_stmt|;
name|uint8_t
name|fc_fw_minor
decl_stmt|;
name|uint8_t
name|fc_fw_micro
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint64_t
name|nvram_node_wwn
decl_stmt|;
name|uint64_t
name|nvram_port_wwn
decl_stmt|;
name|uint64_t
name|active_node_wwn
decl_stmt|;
name|uint64_t
name|active_port_wwn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_TOPO_UNKNOWN
value|0
end_define

begin_comment
comment|/* connection topology unknown */
end_comment

begin_define
define|#
directive|define
name|ISP_TOPO_FCAL
value|1
end_define

begin_comment
comment|/* private or PL_DA */
end_comment

begin_define
define|#
directive|define
name|ISP_TOPO_LPORT
value|2
end_define

begin_comment
comment|/* public loop */
end_comment

begin_define
define|#
directive|define
name|ISP_TOPO_NPORT
value|3
end_define

begin_comment
comment|/* N-port */
end_comment

begin_define
define|#
directive|define
name|ISP_TOPO_FPORT
value|4
end_define

begin_comment
comment|/* F-port */
end_comment

begin_define
define|#
directive|define
name|ISP_FC_GETHINFO
value|_IOR(ISP_IOC, 12, struct isp_hba_device)
end_define

begin_comment
comment|/*  * Set some internal parameters. This doesn't take effect until  * the chip is reset.  *  * Each parameter is generalized to be a name string with an integer value.  *  * Known parameters are:  *  *	Name				Value Range  *	  *	"framelength"			512,1024,2048  *	"exec_throttle"			16..255  *	"fullduplex"			0,1  *	"loopid"			0..125  */
end_comment

begin_struct
struct|struct
name|isp_fc_param
block|{
name|char
name|param_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* null terminated */
name|uint32_t
name|parameter
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_GET_FC_PARAM
value|_IOWR(ISP_IOC, 98, struct isp_fc_param)
end_define

begin_define
define|#
directive|define
name|ISP_SET_FC_PARAM
value|_IOWR(ISP_IOC, 99, struct isp_fc_param)
end_define

begin_comment
comment|/*  * Various Reset Goodies  */
end_comment

begin_struct
struct|struct
name|isp_fc_tsk_mgmt
block|{
name|uint32_t
name|loopid
decl_stmt|;
comment|/* 0..255 */
name|uint32_t
name|lun
decl_stmt|;
enum|enum
block|{
name|IPT_CLEAR_ACA
block|,
name|IPT_TARGET_RESET
block|,
name|IPT_LUN_RESET
block|,
name|IPT_CLEAR_TASK_SET
block|,
name|IPT_ABORT_TASK_SET
block|}
name|action
enum|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_TSK_MGMT
value|_IOWR(ISP_IOC, 97, struct isp_fc_tsk_mgmt)
end_define

end_unit

