begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 by the Board of Trustees  *    of Leland Stanford Junior University.  * Copyright (C) 1998 Digital Equipment Corporation  *  * This file is part of the SimOS distribution.  * See LICENSE file for terms of the license.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIMOS_SCSI_H
end_ifndef

begin_define
define|#
directive|define
name|_SIMOS_SCSI_H
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_ADDR
value|0xfffffcc500000000
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_ADDR_32
value|0xffffffffa5000000
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_MAXDMA_LEN
value|128
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_MAXTARG
value|16
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_MAXLUN
value|16
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_REGS
value|((struct SimOS_SCSI *)SIMOS_SCSI_ADDR)
end_define

begin_define
define|#
directive|define
name|SIMOS_SCSI_REGS_32
value|((struct SimOS_SCSI *)SIMOS_SCSI_ADDR_32)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|SCSIReg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|SimOS_SCSI
block|{
name|SCSIReg
name|startIO
decl_stmt|;
comment|/* write-only */
name|SCSIReg
name|done
index|[
name|SIMOS_SCSI_MAXTARG
index|]
decl_stmt|;
comment|/* read-write (write=ack) */
name|SCSIReg
name|target
decl_stmt|;
comment|/* data fields */
name|SCSIReg
name|lun
decl_stmt|;
name|SCSIReg
name|cmd
index|[
literal|12
index|]
decl_stmt|;
name|SCSIReg
name|length
decl_stmt|;
name|SCSIReg
name|sgLen
decl_stmt|;
struct|struct
block|{
name|SCSIReg
name|pAddr
decl_stmt|;
name|SCSIReg
name|len
decl_stmt|;
block|}
name|sgMap
index|[
name|SIMOS_SCSI_MAXDMA_LEN
index|]
struct|;
block|}
name|SimOS_SCSI
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

