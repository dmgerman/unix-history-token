begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1992-1994,2001 by Joerg Wunsch, Dresden  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  * from: ioctl_fd.h,v 1.11  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IOCTL_FD_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IOCTL_FD_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|FD_FORMAT_VERSION
value|110
end_define

begin_comment
comment|/* used to validate before formatting */
end_comment

begin_define
define|#
directive|define
name|FD_MAX_NSEC
value|36
end_define

begin_comment
comment|/* highest known number of spt - allow for */
end_comment

begin_comment
comment|/* 2.88 MB drives */
end_comment

begin_struct
struct|struct
name|fd_formb
block|{
name|int
name|format_version
decl_stmt|;
comment|/* == FD_FORMAT_VERSION */
name|int
name|cyl
decl_stmt|,
name|head
decl_stmt|;
name|int
name|transfer_rate
decl_stmt|;
comment|/* fdreg.h: FDC_???KBPS */
union|union
block|{
struct|struct
name|fd_form_data
block|{
comment|/* 			 * DO NOT CHANGE THE LAYOUT OF THIS STRUCTS 			 * it is hardware-dependent since it exactly 			 * matches the byte sequence to write to FDC 			 * during its `format track' operation 			 */
name|u_char
name|secshift
decl_stmt|;
comment|/* 0 -> 128, ...; usually 2 -> 512 */
name|u_char
name|nsecs
decl_stmt|;
comment|/* must be<= FD_MAX_NSEC */
name|u_char
name|gaplen
decl_stmt|;
comment|/* GAP 3 length; usually 84 */
name|u_char
name|fillbyte
decl_stmt|;
comment|/* usually 0xf6 */
struct|struct
name|fd_idfield_data
block|{
comment|/* 				 * data to write into id fields; 				 * for obscure formats, they mustn't match 				 * the real values (but mostly do) 				 */
name|u_char
name|cylno
decl_stmt|;
comment|/* 0 thru 79 (or 39) */
name|u_char
name|headno
decl_stmt|;
comment|/* 0, or 1 */
name|u_char
name|secno
decl_stmt|;
comment|/* starting at 1! */
name|u_char
name|secsize
decl_stmt|;
comment|/* usually 2 */
block|}
name|idfields
index|[
name|FD_MAX_NSEC
index|]
struct|;
comment|/* 0<= idx< nsecs used */
block|}
name|structured
struct|;
name|u_char
name|raw
index|[
literal|1
index|]
decl_stmt|;
comment|/* to have continuous indexed access */
block|}
name|format_info
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* make life easier */
end_comment

begin_define
define|#
directive|define
name|fd_formb_secshift
value|format_info.structured.secshift
end_define

begin_define
define|#
directive|define
name|fd_formb_nsecs
value|format_info.structured.nsecs
end_define

begin_define
define|#
directive|define
name|fd_formb_gaplen
value|format_info.structured.gaplen
end_define

begin_define
define|#
directive|define
name|fd_formb_fillbyte
value|format_info.structured.fillbyte
end_define

begin_comment
comment|/* these data must be filled in for(i = 0; i< fd_formb_nsecs; i++) */
end_comment

begin_define
define|#
directive|define
name|fd_formb_cylno
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].cylno
end_define

begin_define
define|#
directive|define
name|fd_formb_headno
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].headno
end_define

begin_define
define|#
directive|define
name|fd_formb_secno
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].secno
end_define

begin_define
define|#
directive|define
name|fd_formb_secsize
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].secsize
end_define

begin_struct
struct|struct
name|fd_type
block|{
name|int
name|sectrac
decl_stmt|;
comment|/* sectors per track         */
name|int
name|secsize
decl_stmt|;
comment|/* size code for sectors     */
name|int
name|datalen
decl_stmt|;
comment|/* data len when secsize = 0 */
name|int
name|gap
decl_stmt|;
comment|/* gap len between sectors   */
name|int
name|tracks
decl_stmt|;
comment|/* total num of tracks       */
name|int
name|size
decl_stmt|;
comment|/* size of disk in sectors   */
name|int
name|steptrac
decl_stmt|;
comment|/* steps per cylinder        */
name|int
name|trans
decl_stmt|;
comment|/* transfer speed code       */
name|int
name|heads
decl_stmt|;
comment|/* number of heads	     */
name|int
name|f_gap
decl_stmt|;
comment|/* format gap len            */
name|int
name|f_inter
decl_stmt|;
comment|/* format interleave factor  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdc_status
block|{
name|u_int
name|status
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FD_FORM
value|_IOW('F', 61, struct fd_formb)
end_define

begin_comment
comment|/* format a track */
end_comment

begin_define
define|#
directive|define
name|FD_GTYPE
value|_IOR('F', 62, struct fd_type)
end_define

begin_comment
comment|/* get drive type */
end_comment

begin_define
define|#
directive|define
name|FD_STYPE
value|_IOW('F', 63, struct fd_type)
end_define

begin_comment
comment|/* set drive type */
end_comment

begin_define
define|#
directive|define
name|FD_GOPTS
value|_IOR('F', 64, int)
end_define

begin_comment
comment|/* drive options, see below */
end_comment

begin_define
define|#
directive|define
name|FD_SOPTS
value|_IOW('F', 65, int)
end_define

begin_define
define|#
directive|define
name|FD_DEBUG
value|_IOW('F', 66, int)
end_define

begin_comment
comment|/*  * Obtain NE765 status registers.  Only successful if there is  * a valid status stored in fdc->status[].  */
end_comment

begin_define
define|#
directive|define
name|FD_GSTAT
value|_IOR('F', 68, struct fdc_status)
end_define

begin_comment
comment|/* Options for FD_GOPTS/FD_SOPTS, cleared on device close */
end_comment

begin_define
define|#
directive|define
name|FDOPT_NORETRY
value|0x0001
end_define

begin_comment
comment|/* no retries on failure */
end_comment

begin_define
define|#
directive|define
name|FDOPT_NOERRLOG
value|0x002
end_define

begin_comment
comment|/* no "hard error" kernel log messages */
end_comment

begin_comment
comment|/*  * The following definitions duplicate those in sys/i386/isa/fdreg.h  * They are here since their values are to be used in the above  * structure when formatting a floppy. For very obvious reasons, both  * definitions must match ;-)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FDC_500KBPS
end_ifndef

begin_define
define|#
directive|define
name|FDC_500KBPS
value|0x00
end_define

begin_comment
comment|/* 500KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_300KBPS
value|0x01
end_define

begin_comment
comment|/* 300KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_250KBPS
value|0x02
end_define

begin_comment
comment|/* 250KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_125KBPS
value|0x03
end_define

begin_comment
comment|/* 125KBPS FM drive transfer rate */
end_comment

begin_comment
comment|/* for some controllers 1MPBS instead */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FDC_500KBPS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IOCTL_FD_H_ */
end_comment

end_unit

