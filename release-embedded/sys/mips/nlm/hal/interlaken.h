begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_ILAKEN_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_ILAKEN_H__
end_define

begin_comment
comment|/** * @file_name interlaken.h * @author Netlogic Microsystems * @brief Basic definitions of XLP ILAKEN ports */
end_comment

begin_define
define|#
directive|define
name|ILK_TX_CONTROL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x00)
end_define

begin_define
define|#
directive|define
name|ILK_TX_RATE_LIMIT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ILK_TX_META_CTRL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x02)
end_define

begin_define
define|#
directive|define
name|ILK_RX_CTRL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x03)
end_define

begin_define
define|#
directive|define
name|ILK_RX_STATUS1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x04)
end_define

begin_define
define|#
directive|define
name|ILK_RX_STATUS2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x05)
end_define

begin_define
define|#
directive|define
name|ILK_GENERAL_CTRL1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x06)
end_define

begin_define
define|#
directive|define
name|ILK_STATUS3
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x07)
end_define

begin_define
define|#
directive|define
name|ILK_RX_FC_TMAP0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x08)
end_define

begin_define
define|#
directive|define
name|ILK_RX_FC_TMAP1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x09)
end_define

begin_define
define|#
directive|define
name|ILK_RX_FC_TMAP2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x0a)
end_define

begin_define
define|#
directive|define
name|ILK_RX_FC_TMAP3
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x0b)
end_define

begin_define
define|#
directive|define
name|ILK_RX_FC_TMAP4
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x0c)
end_define

begin_define
define|#
directive|define
name|ILK_RX_FC_TADDR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x0d)
end_define

begin_define
define|#
directive|define
name|ILK_GENERAL_CTRL2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x0e)
end_define

begin_define
define|#
directive|define
name|ILK_GENERAL_CTRL3
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x0f)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x10)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x11)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x12)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT3
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x13)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT4
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x14)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT5
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x15)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT6
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x16)
end_define

begin_define
define|#
directive|define
name|ILK_SMALL_COUNT7
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x17)
end_define

begin_define
define|#
directive|define
name|ILK_MID_COUNT0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x18)
end_define

begin_define
define|#
directive|define
name|ILK_MID_COUNT1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x19)
end_define

begin_define
define|#
directive|define
name|ILK_LARGE_COUNT0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x1a)
end_define

begin_define
define|#
directive|define
name|ILK_LARGE_COUNT1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x1b)
end_define

begin_define
define|#
directive|define
name|ILK_LARGE_COUNT_H0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x1c)
end_define

begin_define
define|#
directive|define
name|ILK_LARGE_COUNT_H1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 5, 0x1d)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

