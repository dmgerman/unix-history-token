begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 by Matthew Jacob  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Alternatively, this software may be distributed under the terms of the  * the GNU Public License ("GPL", Library, Version 2).  *  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Matthew Jacob<mjacob@feral.com)  *  */
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
value|_IOWR(ISP_IOC, 0, int)
end_define

begin_comment
comment|/*  * This ioctl resets the HBA. Use with caution.  */
end_comment

begin_define
define|#
directive|define
name|ISP_RESETHBA
value|_IO(ISP_IOC, 1)
end_define

begin_comment
comment|/*  * This ioctl performs a fibre chanel rescan.  */
end_comment

begin_define
define|#
directive|define
name|ISP_FC_RESCAN
value|_IO(ISP_IOC, 2)
end_define

begin_comment
comment|/*  * Initiate a LIP  */
end_comment

begin_define
define|#
directive|define
name|ISP_FC_LIP
value|_IO(ISP_IOC, 3)
end_define

begin_comment
comment|/*  * Return the Port Database structure for the named device, or ENODEV if none.  * Caller fills in virtual loopid (0..255), aka 'target'. The driver returns  * ENODEV (if nothing valid there) or the actual loopid (for local loop devices  * only), 24 bit Port ID and Node and Port WWNs.  */
end_comment

begin_struct
struct|struct
name|isp_fc_device
block|{
name|u_int32_t
name|loopid
decl_stmt|;
comment|/* 0..255 */
name|u_int32_t
name|portid
decl_stmt|;
comment|/* 24 bit Port ID */
name|u_int64_t
name|node_wwn
decl_stmt|;
name|u_int64_t
name|port_wwn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_FC_GETDINFO
value|_IOWR(ISP_IOC, 4, struct isp_fc_device)
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
name|u_int8_t
name|isp_stat_version
decl_stmt|;
name|u_int8_t
name|isp_type
decl_stmt|;
comment|/* (ro) reflects chip type */
name|u_int8_t
name|isp_revision
decl_stmt|;
comment|/* (ro) reflects chip version */
name|u_int8_t
name|unused1
decl_stmt|;
name|u_int32_t
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
name|u_int64_t
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

end_unit

