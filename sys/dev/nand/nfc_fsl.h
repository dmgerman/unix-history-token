begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Juniper Networks, Inc.  * Copyright (C) 2009-2012 Semihalf  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NAND_NFC_FSL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NAND_NFC_FSL_H_
end_define

begin_comment
comment|/* LBC BR/OR Registers layout definitions */
end_comment

begin_define
define|#
directive|define
name|BR_V
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BR_V_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BR_MSEL
value|0x000000E0
end_define

begin_define
define|#
directive|define
name|BR_MSEL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BR_DECC_CHECK_MODE
value|0x00000600
end_define

begin_define
define|#
directive|define
name|BR_DECC_CHECK_GEN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|OR_FCM_PAGESIZE
value|0x00000400
end_define

begin_comment
comment|/* Options definitions */
end_comment

begin_define
define|#
directive|define
name|NAND_OPT_ECC_MODE_HW
value|1
end_define

begin_define
define|#
directive|define
name|NAND_OPT_ECC_MODE_SOFT
value|(1<< 1)
end_define

begin_comment
comment|/* FMR - Flash Mode Register */
end_comment

begin_define
define|#
directive|define
name|FMR_CWTO
value|0xF000
end_define

begin_define
define|#
directive|define
name|FMR_CWTO_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|FMR_BOOT
value|0x0800
end_define

begin_define
define|#
directive|define
name|FMR_ECCM
value|0x0100
end_define

begin_define
define|#
directive|define
name|FMR_AL
value|0x0030
end_define

begin_define
define|#
directive|define
name|FMR_AL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|FMR_OP
value|0x0003
end_define

begin_define
define|#
directive|define
name|FMR_OP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FIR_OP_NOP
value|0x0
end_define

begin_comment
comment|/* No operation and end of sequence */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_CA
value|0x1
end_define

begin_comment
comment|/* Issue current column address */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_PA
value|0x2
end_define

begin_comment
comment|/* Issue current block+page address */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_UA
value|0x3
end_define

begin_comment
comment|/* Issue user defined address */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_CM
parameter_list|(
name|x
parameter_list|)
value|(4 + (x))
end_define

begin_comment
comment|/* Issue command from FCR[CMD(x)] */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_WB
value|0x8
end_define

begin_comment
comment|/* Write FBCR bytes from FCM buffer */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_WS
value|0x9
end_define

begin_comment
comment|/* Write 1 or 2 bytes from MDR[AS] */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_RB
value|0xA
end_define

begin_comment
comment|/* Read FBCR bytes to FCM buffer */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_RS
value|0xB
end_define

begin_comment
comment|/* Read 1 or 2 bytes to MDR[AS] */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_CW0
value|0xC
end_define

begin_comment
comment|/* Wait then issue FCR[CMD0] */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_CW1
value|0xD
end_define

begin_comment
comment|/* Wait then issue FCR[CMD1] */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_RBW
value|0xE
end_define

begin_comment
comment|/* Wait then read FBCR bytes */
end_comment

begin_define
define|#
directive|define
name|FIR_OP_RSW
value|0xF
end_define

begin_comment
comment|/* Wait then read 1 or 2 bytes */
end_comment

begin_comment
comment|/* LTESR - Transfer Error Status Register */
end_comment

begin_define
define|#
directive|define
name|LTESR_BM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LTESR_FCT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LTESR_PAR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LTESR_WP
value|0x04000000
end_define

begin_define
define|#
directive|define
name|LTESR_ATMW
value|0x00800000
end_define

begin_define
define|#
directive|define
name|LTESR_ATMR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|LTESR_CS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LTESR_CC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LTESR_NAND_MASK
value|(LTESR_FCT | LTESR_CC | LTESR_CS)
end_define

begin_comment
comment|/* FPAR - Flash Page Address Register */
end_comment

begin_define
define|#
directive|define
name|FPAR_SP_PI
value|0x00007C00
end_define

begin_define
define|#
directive|define
name|FPAR_SP_PI_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|FPAR_SP_MS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FPAR_SP_CI
value|0x000001FF
end_define

begin_define
define|#
directive|define
name|FPAR_SP_CI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPAR_LP_PI
value|0x0003F000
end_define

begin_define
define|#
directive|define
name|FPAR_LP_PI_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|FPAR_LP_MS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FPAR_LP_CI
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|FPAR_LP_CI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FSL_FCM_WAIT_TIMEOUT
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NAND_NFC_FSL_H_ */
end_comment

end_unit

