begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2001 Granch, Ltd. All rights reserved.  * Author: Denis I.Timofeev<timofeev@granch.ru>  *  * Redistributon and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * We don't have registered vendor id yet...  */
end_comment

begin_define
define|#
directive|define
name|SBNI_PCI_VENDOR
value|0x55
end_define

begin_define
define|#
directive|define
name|SBNI_PCI_DEVICE
value|0x9f
end_define

begin_define
define|#
directive|define
name|ISA_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|SBNI_PORTS
value|4
end_define

begin_enum
enum|enum
name|sbni_reg
block|{
name|CSR0
init|=
literal|0
block|,
name|CSR1
init|=
literal|1
block|,
name|DAT
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* CSR0 mapping */
end_comment

begin_enum
enum|enum
block|{
name|BU_EMP
init|=
literal|0x02
block|,
name|RC_CHK
init|=
literal|0x04
block|,
name|CT_ZER
init|=
literal|0x08
block|,
name|TR_REQ
init|=
literal|0x10
block|,
name|TR_RDY
init|=
literal|0x20
block|,
name|EN_INT
init|=
literal|0x40
block|,
name|RC_RDY
init|=
literal|0x80
block|}
enum|;
end_enum

begin_comment
comment|/* CSR1 mapping */
end_comment

begin_define
define|#
directive|define
name|PR_RES
value|0x80
end_define

begin_struct
struct|struct
name|sbni_csr1
block|{
name|unsigned
name|rxl
range|:
literal|5
decl_stmt|;
name|unsigned
name|rate
range|:
literal|2
decl_stmt|;
name|unsigned
label|:
literal|1
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FRAME_ACK_MASK
value|(u_int16_t)0x7000
end_define

begin_define
define|#
directive|define
name|FRAME_LEN_MASK
value|(u_int16_t)0x03FF
end_define

begin_define
define|#
directive|define
name|FRAME_FIRST
value|(u_int16_t)0x8000
end_define

begin_define
define|#
directive|define
name|FRAME_RETRY
value|(u_int16_t)0x0800
end_define

begin_define
define|#
directive|define
name|FRAME_SENT_BAD
value|(u_int16_t)0x4000
end_define

begin_define
define|#
directive|define
name|FRAME_SENT_OK
value|(u_int16_t)0x3000
end_define

begin_enum
enum|enum
block|{
name|FL_WAIT_ACK
init|=
literal|1
block|,
name|FL_NEED_RESEND
init|=
literal|2
block|,
name|FL_PREV_OK
init|=
literal|4
block|,
name|FL_SLOW_MODE
init|=
literal|8
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|DEFAULT_IOBASEADDR
init|=
literal|0x210
block|,
name|DEFAULT_INTERRUPTNUMBER
init|=
literal|5
block|,
name|DEFAULT_RATE
init|=
literal|0
block|,
name|DEFAULT_FRAME_LEN
init|=
literal|1012
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DEF_RXL_DELTA
value|-1
end_define

begin_define
define|#
directive|define
name|DEF_RXL
value|0xf
end_define

begin_define
define|#
directive|define
name|SBNI_SIG
value|0x5a
end_define

begin_define
define|#
directive|define
name|SBNI_MIN_LEN
value|(ETHER_MIN_LEN - 4)
end_define

begin_define
define|#
directive|define
name|SBNI_MAX_FRAME
value|1023
end_define

begin_define
define|#
directive|define
name|SBNI_HZ
value|18
end_define

begin_comment
comment|/* ticks to wait for pong or packet */
end_comment

begin_comment
comment|/* sbni watchdog called SBNI_HZ times per sec. */
end_comment

begin_define
define|#
directive|define
name|TR_ERROR_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|CHANGE_LEVEL_START_TICKS
value|4
end_define

end_unit

