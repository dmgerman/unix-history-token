begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Michael Gmelin<freebsd@grem.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISL_H_
end_define

begin_comment
comment|/* Command register 1  (bits 7-5) */
end_comment

begin_define
define|#
directive|define
name|REG_CMD1
value|0x00
end_define

begin_define
define|#
directive|define
name|CMD1_MASK_POWER_DOWN
value|0x00
end_define

begin_comment
comment|/* 00000000 */
end_comment

begin_define
define|#
directive|define
name|CMD1_MASK_ALS_ONCE
value|0x01<< 5
end_define

begin_comment
comment|/* 00100000 */
end_comment

begin_define
define|#
directive|define
name|CMD1_MASK_IR_ONCE
value|0x02<< 5
end_define

begin_comment
comment|/* 01000000 */
end_comment

begin_define
define|#
directive|define
name|CMD1_MASK_PROX_ONCE
value|0x03<< 5
end_define

begin_comment
comment|/* 01100000 */
end_comment

begin_comment
comment|/* RESERVED */
end_comment

begin_comment
comment|/* 10000000 */
end_comment

begin_define
define|#
directive|define
name|CMD1_MASK_ALS_CONT
value|0x05<< 5
end_define

begin_comment
comment|/* 10100000 */
end_comment

begin_define
define|#
directive|define
name|CMD1_MASK_IR_CONT
value|0x06<< 5
end_define

begin_comment
comment|/* 11000000 */
end_comment

begin_define
define|#
directive|define
name|CMD1_MASK_PROX_CONT
value|0x07<< 5
end_define

begin_comment
comment|/* 11100000 */
end_comment

begin_comment
comment|/* Command register 2 (bits) */
end_comment

begin_define
define|#
directive|define
name|REG_CMD2
value|0x01
end_define

begin_comment
comment|/* data registers */
end_comment

begin_define
define|#
directive|define
name|REG_DATA1
value|0x02
end_define

begin_define
define|#
directive|define
name|REG_DATA2
value|0x03
end_define

begin_define
define|#
directive|define
name|CMD2_SHIFT_RANGE
value|0x00
end_define

begin_define
define|#
directive|define
name|CMD2_MASK_RANGE
value|(0x03<< CMD2_SHIFT_RANGE)
end_define

begin_define
define|#
directive|define
name|CMD2_SHIFT_RESOLUTION
value|0x02
end_define

begin_define
define|#
directive|define
name|CMD2_MASK_RESOLUTION
value|(0x03<< CMD2_SHIFT_RESOLUTION)
end_define

begin_comment
comment|/* Interrupt registers */
end_comment

begin_define
define|#
directive|define
name|REG_INT_LO_LSB
value|0x04
end_define

begin_define
define|#
directive|define
name|REG_INT_LO_MSB
value|0x05
end_define

begin_define
define|#
directive|define
name|REG_INT_HI_LSB
value|0x06
end_define

begin_define
define|#
directive|define
name|REG_INT_HI_MSB
value|0x07
end_define

begin_comment
comment|/* Test register (should hold 0x00 at all times */
end_comment

begin_define
define|#
directive|define
name|REG_TEST
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

