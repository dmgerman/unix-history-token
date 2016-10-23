begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AW_P2WI_H__
end_ifndef

begin_define
define|#
directive|define
name|__AW_P2WI_H__
end_define

begin_define
define|#
directive|define
name|P2WI_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|P2WI_CTRL_SOFT_RESET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|P2WI_CTRL_GLOBAL_INT_ENB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|P2WI_CTRL_ABORT_TRANS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|P2WI_CTRL_START_TRANS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|P2WI_CCR
value|0x04
end_define

begin_define
define|#
directive|define
name|P2WI_CCR_CLK_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|P2WI_CCR_CLK_DIV_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|P2WI_CCR_SDA_ODLY_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|P2WI_CCR_SDA_ODLY_MASK
value|0x700
end_define

begin_define
define|#
directive|define
name|P2WI_INTE
value|0x08
end_define

begin_define
define|#
directive|define
name|P2WI_INTE_TRANS_OVER_ENB
end_define

begin_define
define|#
directive|define
name|P2WI_INTE_TRANS_ERR_ENB
end_define

begin_define
define|#
directive|define
name|P2WI_INTE_LOAD_BSY_ENB
end_define

begin_define
define|#
directive|define
name|P2WI_STAT
value|0x0C
end_define

begin_define
define|#
directive|define
name|P2WI_STAT_TRANS_OVER
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|P2WI_STAT_TRANS_ERR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|P2WI_STAT_LOAD_BSY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|P2WI_STAT_TRANS_ERR_ID_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|P2WI_STAT_TRANS_ERR_ID_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|P2WI_DADDR0
value|0x10
end_define

begin_define
define|#
directive|define
name|P2WI_DADDR1
value|0x14
end_define

begin_define
define|#
directive|define
name|P2WI_DLEN
value|0x18
end_define

begin_define
define|#
directive|define
name|P2WI_DLEN_LEN
parameter_list|(
name|x
parameter_list|)
value|((x - 1)& 0x7)
end_define

begin_define
define|#
directive|define
name|P2WI_DLEN_READ
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|P2WI_DATA0
value|0x1C
end_define

begin_define
define|#
directive|define
name|P2WI_DATA1
value|0x20
end_define

begin_define
define|#
directive|define
name|P2WI_LCR
value|0x24
end_define

begin_define
define|#
directive|define
name|P2WI_LCR_SDA_CTL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|P2WI_LCR_SDA_CTL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|P2WI_LCR_SCL_CTL_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|P2WI_LCR_SCL_CTL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|P2WI_LCR_SDA_STATE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|P2WI_LCR_SCL_STATE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|P2WI_PMCR
value|0x28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AW_P2WI_H__ */
end_comment

end_unit

