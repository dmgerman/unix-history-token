begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005, M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Tamarack TC5299J */
end_comment

begin_define
define|#
directive|define
name|ED_TC5299J_CRA
value|0x0a
end_define

begin_comment
comment|/* Config Register A */
end_comment

begin_define
define|#
directive|define
name|ED_TC5299J_CRB
value|0x0b
end_define

begin_comment
comment|/* Config Register B */
end_comment

begin_define
define|#
directive|define
name|ED_TC5299J_MIIBUS
value|0x03
end_define

begin_comment
comment|/* MII bus register on in bank 3 */
end_comment

begin_define
define|#
directive|define
name|ED_TC5299J_MII_CLK
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_TC5299J_MII_DATAOUT
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_TC5299J_MII_DIROUT
value|0x04
end_define

begin_define
define|#
directive|define
name|ED_TC5299J_MII_DATAIN
value|0x08
end_define

end_unit

