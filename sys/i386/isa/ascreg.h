begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ascreg.h - port and bit definitions for the GI-1904 interface   *  * Copyright (c) 1995 Gunther Schadow.  All rights reserved.  * Copyright (c) 1995 Luigi Rizzo.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Gunther Schadow.  *	and Luigi Rizzo  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/***    Registers (base=3EB): ************/
end_comment

begin_define
define|#
directive|define
name|ASC_CFG
value|(scu->base)
end_define

begin_comment
comment|/*** ASC_CFG 3EB: configuration register. Write only, mirror in RAM      ***   7   6   5   4   3   2   1   0      ***   -   -  I_5 I_3 I10 D_3  -  D_1      ***/
end_comment

begin_comment
comment|/*** #define ASC_CNF_MASK  0x3D */
end_comment

begin_comment
comment|/*  was 0x5a */
end_comment

begin_define
define|#
directive|define
name|ASC_CNF_DMA1
value|0x01
end_define

begin_comment
comment|/* was (~0x02& ASC_CNF_MASK) */
end_comment

begin_define
define|#
directive|define
name|ASC_CNF_DMA3
value|0x04
end_define

begin_comment
comment|/* was (~0x08& ASC_CNF_MASK) */
end_comment

begin_define
define|#
directive|define
name|ASC_CNF_IRQ3
value|0x10
end_define

begin_comment
comment|/* was (~0x10& ASC_CNF_MASK) */
end_comment

begin_define
define|#
directive|define
name|ASC_CNF_IRQ5
value|0x20
end_define

begin_comment
comment|/* was (~0x40& ASC_CNF_MASK) */
end_comment

begin_define
define|#
directive|define
name|ASC_CNF_IRQ10
value|0x08
end_define

begin_comment
comment|/* was (~0x40& ASC_CNF_MASK) */
end_comment

begin_comment
comment|/*** ASC_STAT 3EC: command/status; rw, mirror in ram      ***    7   6   5   4   3   2   1   0      ***   BSY  -   -   -   -   -   -   -      ***            [<--  Resolution -->] 13h,10h,0eh,0ch,09h, 07h, 04h, 02h      ***/
end_comment

begin_define
define|#
directive|define
name|ASC_STAT
value|(scu->base + 1)
end_define

begin_define
define|#
directive|define
name|ASC_RDY_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|ASC_RES_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|ASC_RES_800
value|0x13
end_define

begin_define
define|#
directive|define
name|ASC_RES_700
value|0x10
end_define

begin_define
define|#
directive|define
name|ASC_RES_600
value|0x0e
end_define

begin_define
define|#
directive|define
name|ASC_RES_500
value|0x0c
end_define

begin_define
define|#
directive|define
name|ASC_RES_400
value|0x09
end_define

begin_comment
comment|/* 0x00 */
end_comment

begin_define
define|#
directive|define
name|ASC_RES_300
value|0x07
end_define

begin_comment
comment|/* 0x04 */
end_comment

begin_define
define|#
directive|define
name|ASC_RES_200
value|0x04
end_define

begin_comment
comment|/* 0x20 */
end_comment

begin_define
define|#
directive|define
name|ASC_RES_100
value|0x02
end_define

begin_comment
comment|/* 0x24 */
end_comment

begin_comment
comment|/*** ASC_CMD 3EC: command/status; rw, mirror in ram      *** W:  7   6   5   4   3   2   1   0      ***     .   -   -   .   .   .   .   .        *** b0: 1: light on& get resolution, 0: light off      *** b1: 0: load scan len (sub_16, with b4=1, b7=1)      *** b2: 1/0 : dma stuff      *** b3: 0/1 : dma stuff      *** b4: 1   : load scan len (sub_16, with b1=0, b7=1)      *** b5: ?          *** b6: ?          *** b7: ?   : set at beginning of sub_16      ***/
end_comment

begin_define
define|#
directive|define
name|ASC_CMD
value|(scu->base + 1)
end_define

begin_define
define|#
directive|define
name|ASC_LIGHT_ON
value|0x01
end_define

begin_define
define|#
directive|define
name|ASC_SET_B2
value|0x04
end_define

begin_define
define|#
directive|define
name|ASC_OPERATE
value|0x91
end_define

begin_comment
comment|/* from linux driver... */
end_comment

begin_define
define|#
directive|define
name|ASC_STANDBY
value|0x05
end_define

begin_comment
comment|/* from linux driver... */
end_comment

begin_comment
comment|/*** ASC_LEN_L, ASC_LEN_H 3ED, 3EE: transfer length, lsb first ***/
end_comment

begin_define
define|#
directive|define
name|ASC_LEN_L
value|((scu->base)+2)
end_define

begin_define
define|#
directive|define
name|ASC_LEN_H
value|((scu->base)+3)
end_define

begin_comment
comment|/*** 3EE ASC_PROBE (must read ASC_PROBE_VALUE) ***/
end_comment

begin_define
define|#
directive|define
name|ASC_PROBE
value|((scu->base)+3)
end_define

begin_define
define|#
directive|define
name|ASC_PROBE_VALUE
value|0xA5
end_define

begin_comment
comment|/*** ASC_BOH 3EF: always write 0 at the moment, read some values ?  ***/
end_comment

begin_define
define|#
directive|define
name|ASC_BOH
value|((scu->base)+4)
end_define

end_unit

