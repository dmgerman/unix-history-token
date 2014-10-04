begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2002 Katsushi Kobayashi and Hidetoshi Shimokawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the acknowledgement as bellow:  *  *    This product includes software developed by K. Kobayashi and H. Shimokawa  *  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|FW_PHY_PHYSID_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|FW_PHY_PHYSID
value|(63<<2)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ROOT_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|FW_PHY_ROOT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FW_PHY_CPS_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|FW_PHY_CPS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FW_PHY_RHB_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|FW_PHY_RHB
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|FW_PHY_IBR_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|FW_PHY_IBR
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ISBR_REG
value|0x05
end_define

begin_define
define|#
directive|define
name|FW_PHY_ISBR
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FW_PHY_GC_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|FW_PHY_SPD_REG
value|0x02
end_define

begin_define
define|#
directive|define
name|FW_PHY_SPD
value|(3<<6)
end_define

begin_define
define|#
directive|define
name|FW_PHY_REV_REG
value|0x02
end_define

begin_define
define|#
directive|define
name|FW_PHY_REV
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|FW_PHY_NP_REG
value|0x02
end_define

begin_define
define|#
directive|define
name|FW_PHY_NP
value|(15<<0)
end_define

begin_define
define|#
directive|define
name|FW_PHY_P1_REG
value|0x03
end_define

begin_define
define|#
directive|define
name|FW_PHY_P2_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|FW_PHY_P3_REG
value|0x05
end_define

begin_define
define|#
directive|define
name|FW_PHY_P_ASTAT
value|(3<<6)
end_define

begin_define
define|#
directive|define
name|FW_PHY_P_BSTAT
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|FW_PHY_P_CH
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|FW_PHY_P_CON
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FW_PHY_LOOPINT_REG
value|0x06
end_define

begin_define
define|#
directive|define
name|FW_PHY_LOOPINT
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|FW_PHY_CPSINT_REG
value|0x06
end_define

begin_define
define|#
directive|define
name|FW_PHY_CPSNT
value|(1<<6)
end_define

begin_comment
comment|/* #define FW_PHY_CPS_REG			0x06 #define FW_PHY_CPS			(1<<5) */
end_comment

begin_define
define|#
directive|define
name|FW_PHY_IR_REG
value|0x06
end_define

begin_define
define|#
directive|define
name|FW_PHY_IR
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|FW_PHY_C_REG
value|0x06
end_define

begin_define
define|#
directive|define
name|FW_PHY_C
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ESPD_REG
value|0x03
end_define

begin_define
define|#
directive|define
name|FW_PHY_ESPD
value|(7<<5)
end_define

begin_define
define|#
directive|define
name|FW_PHY_EDEL_REG
value|0x03
end_define

begin_define
define|#
directive|define
name|FW_PHY_EDEL
value|15<<0
end_define

end_unit

