begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gscreg.h - port and bit definitions for the Genius GS-4500 interface  *  *  * Copyright (c) 1995 Gunther Schadow.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Gunther Schadow.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * status register (r)  */
end_comment

begin_comment
comment|/* the DMA/IRQ jumper configuration */
end_comment

begin_define
define|#
directive|define
name|GSC_CNF_MASK
value|0x5a
end_define

begin_define
define|#
directive|define
name|GSC_CNF_DMA1
value|(~0x02& GSC_CNF_MASK)
end_define

begin_define
define|#
directive|define
name|GSC_CNF_DMA3
value|(~0x08& GSC_CNF_MASK)
end_define

begin_define
define|#
directive|define
name|GSC_CNF_IRQ3
value|(~0x10& GSC_CNF_MASK)
end_define

begin_define
define|#
directive|define
name|GSC_CNF_IRQ5
value|(~0x40& GSC_CNF_MASK)
end_define

begin_comment
comment|/* the resolution switch setting */
end_comment

begin_define
define|#
directive|define
name|GSC_RES_MASK
value|0x24
end_define

begin_define
define|#
directive|define
name|GSC_RES_400
value|0x00
end_define

begin_define
define|#
directive|define
name|GSC_RES_300
value|0x04
end_define

begin_define
define|#
directive|define
name|GSC_RES_200
value|0x20
end_define

begin_define
define|#
directive|define
name|GSC_RES_100
value|0x24
end_define

begin_comment
comment|/* other flags */
end_comment

begin_define
define|#
directive|define
name|GSC_RDY_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|GSC_IRQ_FLAG
value|0x01
end_define

begin_comment
comment|/*  * control register (w)  */
end_comment

begin_comment
comment|/* power on */
end_comment

begin_define
define|#
directive|define
name|GSC_POWER_ON
value|0x01
end_define

begin_comment
comment|/* pixel per line count */
end_comment

begin_define
define|#
directive|define
name|GSC_CNT_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|GSC_CNT_3648
value|0x30
end_define

begin_define
define|#
directive|define
name|GSC_CNT_2544
value|0x90
end_define

begin_define
define|#
directive|define
name|GSC_CNT_1696
value|0xb0
end_define

begin_define
define|#
directive|define
name|GSC_CNT_1648
value|0xe0
end_define

begin_define
define|#
directive|define
name|GSC_CNT_1264
value|0x80
end_define

begin_define
define|#
directive|define
name|GSC_CNT_840
value|0xa0
end_define

begin_define
define|#
directive|define
name|GSC_CNT_424
value|0xf0
end_define

begin_comment
comment|/*  * port addresses  */
end_comment

begin_define
define|#
directive|define
name|GSC_DATA
parameter_list|(
name|iob
parameter_list|)
value|(iob + (iob == 0x270 ? 0x02 : 0x01))
end_define

begin_define
define|#
directive|define
name|GSC_STAT
parameter_list|(
name|iob
parameter_list|)
value|(iob + (iob == 0x270 ? 0x03 : 0x02))
end_define

begin_define
define|#
directive|define
name|GSC_CTRL
parameter_list|(
name|iob
parameter_list|)
value|(iob + (iob == 0x270 ? 0x0a : 0x03))
end_define

begin_define
define|#
directive|define
name|GSC_CLRP
parameter_list|(
name|iob
parameter_list|)
value|(iob + (iob == 0x270 ? 0x0b : 0x04))
end_define

end_unit

