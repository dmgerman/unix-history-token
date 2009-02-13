begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * System Disk ioctls  */
end_comment

begin_comment
comment|/* system disk status values */
end_comment

begin_define
define|#
directive|define
name|MLX_SYSD_ONLINE
value|0x03
end_define

begin_define
define|#
directive|define
name|MLX_SYSD_CRITICAL
value|0x04
end_define

begin_define
define|#
directive|define
name|MLX_SYSD_OFFLINE
value|0xff
end_define

begin_define
define|#
directive|define
name|MLXD_STATUS
value|_IOR ('M', 100, int)
end_define

begin_define
define|#
directive|define
name|MLXD_CHECKASYNC
value|_IOR ('M', 101, int)
end_define

begin_comment
comment|/* command result returned in argument */
end_comment

begin_comment
comment|/*  * Controller ioctls  */
end_comment

begin_struct
struct|struct
name|mlx_pause
block|{
name|int
name|mp_which
decl_stmt|;
define|#
directive|define
name|MLX_PAUSE_ALL
value|0xff
define|#
directive|define
name|MLX_PAUSE_CANCEL
value|0x00
name|int
name|mp_when
decl_stmt|;
name|int
name|mp_howlong
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx_usercommand
block|{
comment|/* data buffer */
name|size_t
name|mu_datasize
decl_stmt|;
comment|/* size of databuffer */
name|void
modifier|*
name|mu_buf
decl_stmt|;
comment|/* address in userspace of databuffer */
name|int
name|mu_bufptr
decl_stmt|;
comment|/* offset into command mailbox to place databuffer address */
comment|/* command */
name|u_int16_t
name|mu_status
decl_stmt|;
comment|/* command status returned */
name|u_int8_t
name|mu_command
index|[
literal|16
index|]
decl_stmt|;
comment|/* command mailbox contents */
comment|/* wrapper */
name|int
name|mu_error
decl_stmt|;
comment|/* result of submission to driver */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx_rebuild_request
block|{
name|int
name|rr_channel
decl_stmt|;
name|int
name|rr_target
decl_stmt|;
name|int
name|rr_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx_rebuild_status
block|{
name|u_int16_t
name|rs_code
decl_stmt|;
define|#
directive|define
name|MLX_REBUILDSTAT_REBUILDCHECK
value|0x0000
define|#
directive|define
name|MLX_REBUILDSTAT_ADDCAPACITY
value|0x0400
define|#
directive|define
name|MLX_REBUILDSTAT_ADDCAPACITYINIT
value|0x0500
define|#
directive|define
name|MLX_REBUILDSTAT_IDLE
value|0xffff
name|u_int16_t
name|rs_drive
decl_stmt|;
name|int
name|rs_size
decl_stmt|;
name|int
name|rs_remaining
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX_NEXT_CHILD
value|_IOWR('M', 0, int)
end_define

begin_define
define|#
directive|define
name|MLX_RESCAN_DRIVES
value|_IO  ('M', 1)
end_define

begin_define
define|#
directive|define
name|MLX_DETACH_DRIVE
value|_IOW ('M', 2, int)
end_define

begin_define
define|#
directive|define
name|MLX_PAUSE_CHANNEL
value|_IOW ('M', 3, struct mlx_pause)
end_define

begin_define
define|#
directive|define
name|MLX_COMMAND
value|_IOWR('M', 4, struct mlx_usercommand)
end_define

begin_define
define|#
directive|define
name|MLX_REBUILDASYNC
value|_IOWR('M', 5, struct mlx_rebuild_request)
end_define

begin_define
define|#
directive|define
name|MLX_REBUILDSTAT
value|_IOR ('M', 6, struct mlx_rebuild_status)
end_define

begin_define
define|#
directive|define
name|MLX_GET_SYSDRIVE
value|_IOWR('M', 7, int)
end_define

end_unit

