begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for 53C400 SCSI-controller chip.  *  * Derived from Linux NCR-5380 generic driver sources (by Drew Eckhardt).  *  * Copyright (C) 1994 Serge Vakulenko (vak@cronyx.ru)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE DEVELOPERS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IC_NCR_53C400_H_
end_ifndef

begin_define
define|#
directive|define
name|_IC_NCR_53C400_H_
end_define

begin_define
define|#
directive|define
name|C400_CSR
value|0
end_define

begin_comment
comment|/* rw - Control and Status Reg. */
end_comment

begin_define
define|#
directive|define
name|CSR_5380_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|CSR_TRANSFER_DIRECTION
value|0x40
end_define

begin_define
define|#
directive|define
name|CSR_TRANSFER_READY_INTR
value|0x20
end_define

begin_define
define|#
directive|define
name|CSR_5380_INTR
value|0x10
end_define

begin_define
define|#
directive|define
name|CSR_SHARED_INTR
value|0x08
end_define

begin_define
define|#
directive|define
name|CSR_HOST_BUF_NOT_READY
value|0x04
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|CSR_SCSI_BUF_READY
value|0x02
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|CSR_5380_GATED_IRQ
value|0x01
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|CSR_BITS
value|"\20\1irq\2sbrdy\3hbrdy\4shintr\5intr\6tintr\7tdir\10enable"
end_define

begin_define
define|#
directive|define
name|C400_CCR
value|1
end_define

begin_comment
comment|/* rw - Clock Counter Reg. */
end_comment

begin_define
define|#
directive|define
name|C400_HBR
value|4
end_define

begin_comment
comment|/* rw - Host Buffer Reg. */
end_comment

begin_define
define|#
directive|define
name|C400_5380_REG_OFFSET
value|8
end_define

begin_comment
comment|/* Offset of 5380 registers. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IC_NCR_53C400_H_ */
end_comment

end_unit

