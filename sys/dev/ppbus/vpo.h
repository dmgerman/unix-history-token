begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: vpo.h,v 1.1 1997/08/14 13:57:45 msmith Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__VP03_H
end_ifndef

begin_define
define|#
directive|define
name|__VP03_H
end_define

begin_define
define|#
directive|define
name|barrier
parameter_list|()
value|__asm__("": : :"memory")
end_define

begin_define
define|#
directive|define
name|VP0_INITIATOR
value|0x7
end_define

begin_define
define|#
directive|define
name|VP0_SECTOR_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|VP0_BUFFER_SIZE
value|0x12000
end_define

begin_define
define|#
directive|define
name|VP0_SPL
parameter_list|()
value|splbio()
end_define

begin_define
define|#
directive|define
name|VP0_ESELECT_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|VP0_ECMD_TIMEOUT
value|2
end_define

begin_define
define|#
directive|define
name|VP0_ECONNECT
value|3
end_define

begin_define
define|#
directive|define
name|VP0_ESTATUS_TIMEOUT
value|4
end_define

begin_define
define|#
directive|define
name|VP0_EDATA_OVERFLOW
value|5
end_define

begin_define
define|#
directive|define
name|VP0_EDISCONNECT
value|6
end_define

begin_define
define|#
directive|define
name|VP0_EPPDATA_TIMEOUT
value|7
end_define

begin_define
define|#
directive|define
name|VP0_ENOPORT
value|9
end_define

begin_define
define|#
directive|define
name|VP0_EINITFAILED
value|10
end_define

begin_define
define|#
directive|define
name|VP0_EINTR
value|12
end_define

begin_define
define|#
directive|define
name|VP0_EOTHER
value|13
end_define

begin_define
define|#
directive|define
name|VP0_OPENNINGS
value|1
end_define

begin_define
define|#
directive|define
name|n
parameter_list|(
name|flags
parameter_list|)
value|(~(flags)& (flags))
end_define

begin_comment
comment|/*  * VP0 timings.  */
end_comment

begin_define
define|#
directive|define
name|MHZ_16_IO_DURATION
value|62
end_define

begin_define
define|#
directive|define
name|VP0_SPP_WRITE_PULSE
value|253
end_define

begin_define
define|#
directive|define
name|VP0_NIBBLE_READ_PULSE
value|486
end_define

begin_comment
comment|/*  * VP0 connections.  */
end_comment

begin_define
define|#
directive|define
name|H_AUTO
value|n(AUTOFEED)
end_define

begin_define
define|#
directive|define
name|H_nAUTO
value|AUTOFEED
end_define

begin_define
define|#
directive|define
name|H_STROBE
value|n(STROBE)
end_define

begin_define
define|#
directive|define
name|H_nSTROBE
value|STROBE
end_define

begin_define
define|#
directive|define
name|H_BSY
value|n(nBUSY)
end_define

begin_define
define|#
directive|define
name|H_nBSY
value|n_BUSY
end_define

begin_define
define|#
directive|define
name|H_SEL
value|SELECT
end_define

begin_define
define|#
directive|define
name|H_nSEL
value|n(SELECT)
end_define

begin_define
define|#
directive|define
name|H_ERR
value|ERROR
end_define

begin_define
define|#
directive|define
name|H_nERR
value|n(ERROR)
end_define

begin_define
define|#
directive|define
name|H_ACK
value|nACK
end_define

begin_define
define|#
directive|define
name|H_nACK
value|n(nACK)
end_define

begin_define
define|#
directive|define
name|H_FLT
value|nFAULT
end_define

begin_define
define|#
directive|define
name|H_nFLT
value|n(nFAULT)
end_define

begin_define
define|#
directive|define
name|H_SELIN
value|n(SELECTIN)
end_define

begin_define
define|#
directive|define
name|H_nSELIN
value|SELECTIN
end_define

begin_define
define|#
directive|define
name|H_INIT
value|nINIT
end_define

begin_define
define|#
directive|define
name|H_nINIT
value|n(nINIT)
end_define

begin_struct
struct|struct
name|vpo_sense
block|{
name|struct
name|scsi_sense
name|cmd
decl_stmt|;
name|unsigned
name|int
name|stat
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vpo_data
block|{
name|unsigned
name|short
name|vpo_unit
decl_stmt|;
name|int
name|vpo_stat
decl_stmt|;
name|int
name|vpo_count
decl_stmt|;
name|int
name|vpo_error
decl_stmt|;
name|struct
name|ppb_status
name|vpo_status
decl_stmt|;
name|struct
name|vpo_sense
name|vpo_sense
decl_stmt|;
name|unsigned
name|char
name|vpo_buffer
index|[
name|VP0_BUFFER_SIZE
index|]
decl_stmt|;
name|struct
name|ppb_device
name|vpo_dev
decl_stmt|;
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

