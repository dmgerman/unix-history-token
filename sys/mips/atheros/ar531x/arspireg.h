begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: arspireg.h,v 1.1 2006/10/14 15:33:23 gdamore Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 Urbana-Champaign Independent Media Center.  * Copyright (c) 2006 Garrett D'Amore.  * All rights reserved.  *  * Portions of this code were written by Garrett D'Amore for the  * Champaign-Urbana Community Wireless Network Project.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgements:  *      This product includes software developed by the Urbana-Champaign  *      Independent Media Center.  *	This product includes software developed by Garrett D'Amore.  * 4. Urbana-Champaign Independent Media Center's name and Garrett  *    D'Amore's name may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE URBANA-CHAMPAIGN INDEPENDENT  * MEDIA CENTER AND GARRETT D'AMORE ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE URBANA-CHAMPAIGN INDEPENDENT  * MEDIA CENTER OR GARRETT D'AMORE BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_ATHEROS_DEV_ARSPIREG_H
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_ATHEROS_DEV_ARSPIREG_H
end_define

begin_define
define|#
directive|define
name|ARSPI_REG_CTL
value|0x00
end_define

begin_define
define|#
directive|define
name|ARSPI_REG_OPCODE
value|0x04
end_define

begin_define
define|#
directive|define
name|ARSPI_REG_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_START
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_BUSY
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_TXCNT_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_TXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_RXCNT_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_RXCNT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_SIZE_MASK
value|0x00060000
end_define

begin_define
define|#
directive|define
name|ARSPI_CTL_CLKSEL_MASK
value|0x03000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_ATHEROS_DEV_ARSPIREG_H */
end_comment

end_unit

