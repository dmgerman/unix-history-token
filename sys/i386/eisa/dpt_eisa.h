begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  *       Copyright (c) 1997 by Matthew N. Dodd<winter@jurai.net>  *       All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Credits:  Based on and part of the DPT driver for FreeBSD written and  *           maintained by Simon Shapiro<shimon@simon-shapiro.org>  */
end_comment

begin_comment
comment|/*  * $Id: dpt_eisa.h,v 1.1 1998/03/10 21:31:06 ShimonR Exp ShimonR $  */
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_SLOT_OFFSET
value|0xc88
end_define

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_IOSIZE
value|sizeof(eata_reg_t)
end_define

begin_define
define|#
directive|define
name|ISA_PRIMARY_WD_ADDRESS
value|0x1f8
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPT2402
value|0x12142402
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA401
value|0x1214A401
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA402
value|0x1214A402
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA410
value|0x1214A410
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA411
value|0x1214A411
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA412
value|0x1214A412
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA420
value|0x1214A420
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA501
value|0x1214A501
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA502
value|0x1214A502
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTA701
value|0x1214A701
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPTBC01
value|0x1214BC01
end_define

begin_define
define|#
directive|define
name|DPT_EISA_NEC8200
value|0x12148200
end_define

begin_define
define|#
directive|define
name|DPT_EISA_ATT2408
value|0x12142408
end_define

end_unit

