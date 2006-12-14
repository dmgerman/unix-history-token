begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 IronPort Systems  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_comment
comment|/* Assume amd64 wants 32 bit Linux */
end_comment

begin_struct
struct|struct
name|iovec32
block|{
name|u_int32_t
name|iov_base
decl_stmt|;
name|int
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MFIQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|MFIQ_BIO
value|1
end_define

begin_define
define|#
directive|define
name|MFIQ_READY
value|2
end_define

begin_define
define|#
directive|define
name|MFIQ_BUSY
value|3
end_define

begin_define
define|#
directive|define
name|MFIQ_COUNT
value|4
end_define

begin_struct
struct|struct
name|mfi_qstat
block|{
name|uint32_t
name|q_length
decl_stmt|;
name|uint32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|mfi_statrequest
block|{
name|uint32_t
name|ms_item
decl_stmt|;
name|struct
name|mfi_qstat
name|ms_qstat
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|MAX_IOCTL_SGE
value|16
end_define

begin_struct
struct|struct
name|mfi_ioc_packet
block|{
name|uint16_t
name|mfi_adapter_no
decl_stmt|;
name|uint16_t
name|mfi_pad1
decl_stmt|;
name|uint32_t
name|mfi_sgl_off
decl_stmt|;
name|uint32_t
name|mfi_sge_count
decl_stmt|;
name|uint32_t
name|mfi_sense_off
decl_stmt|;
name|uint32_t
name|mfi_sense_len
decl_stmt|;
union|union
block|{
name|uint8_t
name|raw
index|[
literal|128
index|]
decl_stmt|;
name|struct
name|mfi_frame_header
name|hdr
decl_stmt|;
block|}
name|mfi_frame
union|;
name|struct
name|iovec
name|mfi_sgl
index|[
name|MAX_IOCTL_SGE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_ioc_aen
block|{
name|uint16_t
name|aen_adapter_no
decl_stmt|;
name|uint16_t
name|aen_pad1
decl_stmt|;
name|uint32_t
name|aen_seq_num
decl_stmt|;
name|uint32_t
name|aen_class_locale
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_CMD
value|_IOWR('M', 1, struct mfi_ioc_packet)
end_define

begin_define
define|#
directive|define
name|MFI_SET_AEN
value|_IOW('M', 3, struct mfi_ioc_aen)
end_define

begin_define
define|#
directive|define
name|MAX_LINUX_IOCTL_SGE
value|16
end_define

begin_struct
struct|struct
name|mfi_linux_ioc_packet
block|{
name|uint16_t
name|lioc_adapter_no
decl_stmt|;
name|uint16_t
name|lioc_pad1
decl_stmt|;
name|uint32_t
name|lioc_sgl_off
decl_stmt|;
name|uint32_t
name|lioc_sge_count
decl_stmt|;
name|uint32_t
name|lioc_sense_off
decl_stmt|;
name|uint32_t
name|lioc_sense_len
decl_stmt|;
union|union
block|{
name|uint8_t
name|raw
index|[
literal|128
index|]
decl_stmt|;
name|struct
name|mfi_frame_header
name|hdr
decl_stmt|;
block|}
name|lioc_frame
union|;
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
comment|/* Assume amd64 wants 32 bit Linux */
name|struct
name|iovec32
name|lioc_sgl
index|[
name|MAX_LINUX_IOCTL_SGE
index|]
decl_stmt|;
else|#
directive|else
name|struct
name|iovec
name|lioc_sgl
index|[
name|MAX_LINUX_IOCTL_SGE
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFIIO_STATS
value|_IOWR('Q', 101, union mfi_statrequest)
end_define

begin_struct
struct|struct
name|mfi_linux_ioc_aen
block|{
name|uint16_t
name|laen_adapter_no
decl_stmt|;
name|uint16_t
name|laen_pad1
decl_stmt|;
name|uint32_t
name|laen_seq_num
decl_stmt|;
name|uint32_t
name|laen_class_locale
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Create a second set so the FreeBSD native ioctl doesn't  * conflict in FreeBSD ioctl handler.  Translate in mfi_linux.c.  */
end_comment

begin_define
define|#
directive|define
name|MFI_LINUX_CMD
value|0xc1144d01
end_define

begin_define
define|#
directive|define
name|MFI_LINUX_SET_AEN
value|0x400c4d03
end_define

begin_define
define|#
directive|define
name|MFI_LINUX_CMD_2
value|0xc1144d02
end_define

begin_define
define|#
directive|define
name|MFI_LINUX_SET_AEN_2
value|0x400c4d04
end_define

end_unit

