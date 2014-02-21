begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005, M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Dlink chipset used on some Netgear and Dlink PCMCIA cards */
end_comment

begin_define
define|#
directive|define
name|ED_DL100XX_MIIBUS
value|0x0c
end_define

begin_comment
comment|/* MII bus register on ASIC */
end_comment

begin_define
define|#
directive|define
name|ED_DL10022_DIAG
value|0x0d
end_define

begin_define
define|#
directive|define
name|ED_DL10022_COLLISON_DIS
value|4
end_define

begin_comment
comment|/* Disable collision detection */
end_comment

begin_define
define|#
directive|define
name|ED_DL10022_MII_RESET1
value|0x04
end_define

begin_define
define|#
directive|define
name|ED_DL10022_MII_RESET2
value|0x08
end_define

begin_define
define|#
directive|define
name|ED_DL100XX_MII_DATAIN
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_DL10022_MII_DIROUT
value|0x20
end_define

begin_define
define|#
directive|define
name|ED_DL10019_MII_DIROUT
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_DL100XX_MII_DIROUT
value|(ED_DL10022_MII_DIROUT | ED_DL10019_MII_DIROUT)
end_define

begin_define
define|#
directive|define
name|ED_DL100XX_MII_DATAOUT
value|0x40
end_define

begin_define
define|#
directive|define
name|ED_DL100XX_MII_CLK
value|0x80
end_define

end_unit

