begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * ioctl interface  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Fetch the driver's interface version.  */
end_comment

begin_define
define|#
directive|define
name|AMR_IO_VERSION_NUMBER
value|0x01
end_define

begin_define
define|#
directive|define
name|AMR_IO_VERSION
value|_IOR('A', 0x200, int)
end_define

begin_comment
comment|/*  * Pass a command from userspace through to the adapter.  *  * Note that in order to be code-compatible with the Linux  * interface where possible, the formatting of the au_cmd field is  * somewhat Interesting.  *  * For normal commands, the layout is (fields from struct amr_mailbox_ioctl):  *  * 0		mb_command  * 1		mb_channel  * 2		mb_param  * 3		mb_pad[0]  * 4		mb_drive  *  * For SCSI passthrough commands, the layout is:  *  * 0		AMR_CMD_PASS	(0x3)  * 1		reserved, 0  * 2		cdb length  * 3		cdb data  * 3+cdb_len	passthrough control byte (timeout, ars, islogical)  * 4+cdb_len	reserved, 0  * 5+cdb_len	channel  * 6+cdb_len	target  */
end_comment

begin_struct
struct|struct
name|amr_user_ioctl
block|{
name|unsigned
name|char
name|au_cmd
index|[
literal|32
index|]
decl_stmt|;
comment|/* command text from userspace */
name|void
modifier|*
name|au_buffer
decl_stmt|;
comment|/* data buffer in userspace */
name|unsigned
name|long
name|au_length
decl_stmt|;
comment|/* data buffer size (0 == no data) */
name|int
name|au_direction
decl_stmt|;
comment|/* data transfer direction */
define|#
directive|define
name|AMR_IO_NODATA
value|0
define|#
directive|define
name|AMR_IO_READ
value|1
define|#
directive|define
name|AMR_IO_WRITE
value|2
name|int
name|au_status
decl_stmt|;
comment|/* command status returned by adapter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AMR_IO_COMMAND
value|_IOWR('A', 0x201, struct amr_user_ioctl)
end_define

end_unit

