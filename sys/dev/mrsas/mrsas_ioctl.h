begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, LSI Corp. All rights reserved. Author: Marian Choy  * Support: freebsdraid@lsi.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer. 2. Redistributions  * in binary form must reproduce the above copyright notice, this list of  * conditions and the following disclaimer in the documentation and/or other  * materials provided with the distribution. 3. Neither the name of the  *<ORGANIZATION> nor the names of its contributors may be used to endorse or  * promote products derived from this software without specific prior written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing  * official policies,either expressed or implied, of the FreeBSD Project.  *  * Send feedback to:<megaraidfbsd@lsi.com> Mail to: LSI Corporation, 1621  * Barber Lane, Milpitas, CA 95035 ATTN: MegaRaid FreeBSD  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MRSAS_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|MRSAS_IOCTL_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_IOWR
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IOWR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_comment
comment|/* Compilation error FIX */
end_comment

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<=
literal|900000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<compat/freebsd32/freebsd32.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We need to use the same values as the mfi driver until MegaCli adds  * support for this (mrsas) driver: M is for MegaRAID. (This is typically the  * vendor or product initial) 1 arbitrary. (This may be used to segment kinds  * of commands.  (1-9 status, 10-20 policy, etc.) struct mrsas_iocpacket  * (sizeof() this parameter will be used.) These three values are encoded  * into a somewhat unique, 32-bit value.  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_IOC_FIRMWARE_PASS_THROUGH64
value|_IOWR('M', 1, struct mrsas_iocpacket)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_define
define|#
directive|define
name|MRSAS_IOC_FIRMWARE_PASS_THROUGH32
value|_IOWR('M', 1, struct mrsas_iocpacket32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MRSAS_IOC_SCAN_BUS
value|_IO('M',  10)
end_define

begin_define
define|#
directive|define
name|MRSAS_LINUX_CMD32
value|0xc1144d01
end_define

begin_define
define|#
directive|define
name|MAX_IOCTL_SGE
value|16
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_READ
value|0x0010
end_define

begin_define
define|#
directive|define
name|MFI_CMD_LD_SCSI_IO
value|0x03
end_define

begin_define
define|#
directive|define
name|INQUIRY_CMD
value|0x12
end_define

begin_define
define|#
directive|define
name|INQUIRY_CMDLEN
value|6
end_define

begin_define
define|#
directive|define
name|INQUIRY_REPLY_LEN
value|96
end_define

begin_define
define|#
directive|define
name|INQUIRY_VENDOR
value|8
end_define

begin_comment
comment|/* Offset in reply data to 						 * vendor name */
end_comment

begin_define
define|#
directive|define
name|SCSI_SENSE_BUFFERSIZE
value|96
end_define

begin_define
define|#
directive|define
name|MEGAMFI_RAW_FRAME_SIZE
value|128
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|mrsas_iocpacket
block|{
name|u_int16_t
name|host_no
decl_stmt|;
name|u_int16_t
name|__pad1
decl_stmt|;
name|u_int32_t
name|sgl_off
decl_stmt|;
name|u_int32_t
name|sge_count
decl_stmt|;
name|u_int32_t
name|sense_off
decl_stmt|;
name|u_int32_t
name|sense_len
decl_stmt|;
union|union
block|{
name|u_int8_t
name|raw
index|[
name|MEGAMFI_RAW_FRAME_SIZE
index|]
decl_stmt|;
name|struct
name|mrsas_header
name|hdr
decl_stmt|;
block|}
name|frame
union|;
name|struct
name|iovec
name|sgl
index|[
name|MAX_IOCTL_SGE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|mrsas_iocpacket32
block|{
name|u_int16_t
name|host_no
decl_stmt|;
name|u_int16_t
name|__pad1
decl_stmt|;
name|u_int32_t
name|sgl_off
decl_stmt|;
name|u_int32_t
name|sge_count
decl_stmt|;
name|u_int32_t
name|sense_off
decl_stmt|;
name|u_int32_t
name|sense_len
decl_stmt|;
union|union
block|{
name|u_int8_t
name|raw
index|[
name|MEGAMFI_RAW_FRAME_SIZE
index|]
decl_stmt|;
name|struct
name|mrsas_header
name|hdr
decl_stmt|;
block|}
name|frame
union|;
name|struct
name|iovec32
name|sgl
index|[
name|MAX_IOCTL_SGE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_FREEBSD32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MRSAS_IOCTL_H */
end_comment

end_unit

