begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: cfe_api_int.h,v 1.2 2003/02/07 17:38:48 cgd Exp $ */
end_comment

begin_comment
comment|/* from: SiByte Id: cfe_api_int.h,v 1.21 2002/07/09 23:29:11 cgd Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright 2000, 2001, 2002  * Broadcom Corporation. All rights reserved.  *  * This software is furnished under license and may be used and copied only  * in accordance with the following terms and conditions.  Subject to these  * conditions, you may download, copy, install, use, modify and distribute  * modified or unmodified copies of this software in source and/or binary  * form. No title or ownership is transferred hereby.  *  * 1) Any source code used, modified or distributed must reproduce and  *    retain this copyright notice and list of conditions as they appear in  *    the source file.  *  * 2) No right is granted to use any trade name, trademark, or logo of  *    Broadcom Corporation.  The "Broadcom Corporation" name may not be  *    used to endorse or promote products derived from this software  *    without the prior written permission of Broadcom Corporation.  *  * 3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR IMPLIED  *    WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED WARRANTIES OF  *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR  *    NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM BE LIABLE  *    FOR ANY DAMAGES WHATSOEVER, AND IN PARTICULAR, BROADCOM SHALL NOT BE  *    LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  *    OR OTHERWISE), EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *********************************************************************     *     *  Broadcom Common Firmware Environment (CFE)     *     *  Device function prototypes		File: cfe_api_int.h     *     *  This header defines all internal types and macros for the     *  library.  This is stuff that's not exported to an app     *  using the library.     *     *  Authors:  Mitch Lichtenberg, Chris Demetriou     *     ********************************************************************* */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CFE_API_INT_H
end_ifndef

begin_define
define|#
directive|define
name|CFE_API_INT_H
end_define

begin_comment
comment|/*  *********************************************************************     *  Constants     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|CFE_CMD_FW_GETINFO
value|0
end_define

begin_define
define|#
directive|define
name|CFE_CMD_FW_RESTART
value|1
end_define

begin_define
define|#
directive|define
name|CFE_CMD_FW_BOOT
value|2
end_define

begin_define
define|#
directive|define
name|CFE_CMD_FW_CPUCTL
value|3
end_define

begin_define
define|#
directive|define
name|CFE_CMD_FW_GETTIME
value|4
end_define

begin_define
define|#
directive|define
name|CFE_CMD_FW_MEMENUM
value|5
end_define

begin_define
define|#
directive|define
name|CFE_CMD_FW_FLUSHCACHE
value|6
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_GETHANDLE
value|9
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_ENUM
value|10
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_OPEN
value|11
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_INPSTAT
value|12
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_READ
value|13
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_WRITE
value|14
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_IOCTL
value|15
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_CLOSE
value|16
end_define

begin_define
define|#
directive|define
name|CFE_CMD_DEV_GETINFO
value|17
end_define

begin_define
define|#
directive|define
name|CFE_CMD_ENV_ENUM
value|20
end_define

begin_define
define|#
directive|define
name|CFE_CMD_ENV_GET
value|22
end_define

begin_define
define|#
directive|define
name|CFE_CMD_ENV_SET
value|23
end_define

begin_define
define|#
directive|define
name|CFE_CMD_ENV_DEL
value|24
end_define

begin_define
define|#
directive|define
name|CFE_CMD_MAX
value|32
end_define

begin_define
define|#
directive|define
name|CFE_CMD_VENDOR_USE
value|0x8000
end_define

begin_comment
comment|/* codes above this are for customer use */
end_comment

begin_comment
comment|/*  *********************************************************************     *  Structures     ********************************************************************* */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cfe_xuint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|cfe_xint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|cfe_xptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_buffer_s
block|{
name|cfe_xuint_t
name|buf_offset
decl_stmt|;
comment|/* offset on device (bytes) */
name|cfe_xptr_t
name|buf_ptr
decl_stmt|;
comment|/* pointer to a buffer */
name|cfe_xuint_t
name|buf_length
decl_stmt|;
comment|/* length of this buffer */
name|cfe_xuint_t
name|buf_retlen
decl_stmt|;
comment|/* returned length (for read ops) */
name|cfe_xuint_t
name|buf_ioctlcmd
decl_stmt|;
comment|/* IOCTL command (used only for IOCTLs) */
block|}
name|xiocb_buffer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|buf_devflags
value|buf_ioctlcmd
end_define

begin_comment
comment|/* returned device info flags */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xiocb_inpstat_s
block|{
name|cfe_xuint_t
name|inp_status
decl_stmt|;
comment|/* 1 means input available */
block|}
name|xiocb_inpstat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_envbuf_s
block|{
name|cfe_xint_t
name|enum_idx
decl_stmt|;
comment|/* 0-based enumeration index */
name|cfe_xptr_t
name|name_ptr
decl_stmt|;
comment|/* name string buffer */
name|cfe_xint_t
name|name_length
decl_stmt|;
comment|/* size of name buffer */
name|cfe_xptr_t
name|val_ptr
decl_stmt|;
comment|/* value string buffer */
name|cfe_xint_t
name|val_length
decl_stmt|;
comment|/* size of value string buffer */
block|}
name|xiocb_envbuf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_cpuctl_s
block|{
name|cfe_xuint_t
name|cpu_number
decl_stmt|;
comment|/* cpu number to control */
name|cfe_xuint_t
name|cpu_command
decl_stmt|;
comment|/* command to issue to CPU */
name|cfe_xuint_t
name|start_addr
decl_stmt|;
comment|/* CPU start address */
name|cfe_xuint_t
name|gp_val
decl_stmt|;
comment|/* starting GP value */
name|cfe_xuint_t
name|sp_val
decl_stmt|;
comment|/* starting SP value */
name|cfe_xuint_t
name|a1_val
decl_stmt|;
comment|/* starting A1 value */
block|}
name|xiocb_cpuctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_time_s
block|{
name|cfe_xint_t
name|ticks
decl_stmt|;
comment|/* current time in ticks */
block|}
name|xiocb_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_exitstat_s
block|{
name|cfe_xint_t
name|status
decl_stmt|;
block|}
name|xiocb_exitstat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_meminfo_s
block|{
name|cfe_xint_t
name|mi_idx
decl_stmt|;
comment|/* 0-based enumeration index */
name|cfe_xint_t
name|mi_type
decl_stmt|;
comment|/* type of memory block */
name|cfe_xuint_t
name|mi_addr
decl_stmt|;
comment|/* physical start address */
name|cfe_xuint_t
name|mi_size
decl_stmt|;
comment|/* block size */
block|}
name|xiocb_meminfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xiocb_fwinfo_s
block|{
name|cfe_xint_t
name|fwi_version
decl_stmt|;
comment|/* major, minor, eco version */
name|cfe_xint_t
name|fwi_totalmem
decl_stmt|;
comment|/* total installed mem */
name|cfe_xint_t
name|fwi_flags
decl_stmt|;
comment|/* various flags */
name|cfe_xint_t
name|fwi_boardid
decl_stmt|;
comment|/* board ID */
name|cfe_xint_t
name|fwi_bootarea_va
decl_stmt|;
comment|/* VA of boot area */
name|cfe_xint_t
name|fwi_bootarea_pa
decl_stmt|;
comment|/* PA of boot area */
name|cfe_xint_t
name|fwi_bootarea_size
decl_stmt|;
comment|/* size of boot area */
name|cfe_xint_t
name|fwi_reserved1
decl_stmt|;
name|cfe_xint_t
name|fwi_reserved2
decl_stmt|;
name|cfe_xint_t
name|fwi_reserved3
decl_stmt|;
block|}
name|xiocb_fwinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cfe_xiocb_s
block|{
name|cfe_xuint_t
name|xiocb_fcode
decl_stmt|;
comment|/* IOCB function code */
name|cfe_xint_t
name|xiocb_status
decl_stmt|;
comment|/* return status */
name|cfe_xint_t
name|xiocb_handle
decl_stmt|;
comment|/* file/device handle */
name|cfe_xuint_t
name|xiocb_flags
decl_stmt|;
comment|/* flags for this IOCB */
name|cfe_xuint_t
name|xiocb_psize
decl_stmt|;
comment|/* size of parameter list */
union|union
block|{
name|xiocb_buffer_t
name|xiocb_buffer
decl_stmt|;
comment|/* buffer parameters */
name|xiocb_inpstat_t
name|xiocb_inpstat
decl_stmt|;
comment|/* input status parameters */
name|xiocb_envbuf_t
name|xiocb_envbuf
decl_stmt|;
comment|/* environment function parameters */
name|xiocb_cpuctl_t
name|xiocb_cpuctl
decl_stmt|;
comment|/* CPU control parameters */
name|xiocb_time_t
name|xiocb_time
decl_stmt|;
comment|/* timer parameters */
name|xiocb_meminfo_t
name|xiocb_meminfo
decl_stmt|;
comment|/* memory arena info parameters */
name|xiocb_fwinfo_t
name|xiocb_fwinfo
decl_stmt|;
comment|/* firmware information */
name|xiocb_exitstat_t
name|xiocb_exitstat
decl_stmt|;
comment|/* Exit Status */
block|}
name|plist
union|;
block|}
name|cfe_xiocb_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CFE_API_INT_H */
end_comment

end_unit

