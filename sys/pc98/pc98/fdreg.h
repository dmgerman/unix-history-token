begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)fdreg.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT floppy controller registers and bitfields  */
end_comment

begin_comment
comment|/* uses NEC765 controller */
end_comment

begin_include
include|#
directive|include
file|<dev/ic/nec765.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* registers */
end_comment

begin_define
define|#
directive|define
name|FDSTS
value|0
end_define

begin_comment
comment|/* NEC 765 Main Status Register (R) */
end_comment

begin_define
define|#
directive|define
name|FDDATA
value|1
end_define

begin_comment
comment|/* NEC 765 Data Register (R/W) */
end_comment

begin_define
define|#
directive|define
name|FDCTL
value|2
end_define

begin_comment
comment|/* FD Control Register */
end_comment

begin_define
define|#
directive|define
name|FDC_RST
value|0x80
end_define

begin_comment
comment|/*  FDC RESET */
end_comment

begin_define
define|#
directive|define
name|FDC_RDY
value|0x40
end_define

begin_comment
comment|/*  force READY */
end_comment

begin_define
define|#
directive|define
name|FDC_DD
value|0x20
end_define

begin_comment
comment|/*  FDD Mode Exchange 0:1M 1:640K */
end_comment

begin_define
define|#
directive|define
name|FDC_DMAE
value|0x10
end_define

begin_comment
comment|/*  enable floppy DMA */
end_comment

begin_define
define|#
directive|define
name|FDC_MTON
value|0x08
end_define

begin_comment
comment|/*  MOTOR ON (when EMTON=1)*/
end_comment

begin_define
define|#
directive|define
name|FDC_TMSK
value|0x04
end_define

begin_comment
comment|/*  TIMER MASK */
end_comment

begin_define
define|#
directive|define
name|FDC_TTRG
value|0x01
end_define

begin_comment
comment|/*  TIMER TRIGER */
end_comment

begin_define
define|#
directive|define
name|FDP_EMTON
value|0x04
end_define

begin_comment
comment|/*  enable MTON */
end_comment

begin_define
define|#
directive|define
name|FDP_FDDEXC
value|0x02
end_define

begin_comment
comment|/*  FDD Mode Exchange 1:1M 0:640K */
end_comment

begin_define
define|#
directive|define
name|FDP_PORTEXC
value|0x01
end_define

begin_comment
comment|/*  PORT Exchane 1:1M 0:640K */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* registers */
end_comment

begin_define
define|#
directive|define
name|FDOUT
value|2
end_define

begin_comment
comment|/* Digital Output Register (W) */
end_comment

begin_define
define|#
directive|define
name|FDO_FDSEL
value|0x03
end_define

begin_comment
comment|/*  floppy device select */
end_comment

begin_define
define|#
directive|define
name|FDO_FRST
value|0x04
end_define

begin_comment
comment|/*  floppy controller reset */
end_comment

begin_define
define|#
directive|define
name|FDO_FDMAEN
value|0x08
end_define

begin_comment
comment|/*  enable floppy DMA and Interrupt */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN0
value|0x10
end_define

begin_comment
comment|/*  motor enable drive 0 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN1
value|0x20
end_define

begin_comment
comment|/*  motor enable drive 1 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN2
value|0x40
end_define

begin_comment
comment|/*  motor enable drive 2 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN3
value|0x80
end_define

begin_comment
comment|/*  motor enable drive 3 */
end_comment

begin_define
define|#
directive|define
name|FDSTS
value|4
end_define

begin_comment
comment|/* NEC 765 Main Status Register (R) */
end_comment

begin_define
define|#
directive|define
name|FDDATA
value|5
end_define

begin_comment
comment|/* NEC 765 Data Register (R/W) */
end_comment

begin_define
define|#
directive|define
name|FDCTL
value|7
end_define

begin_comment
comment|/* Control Register (W) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FDC_500KBPS
end_ifndef

begin_define
define|#
directive|define
name|FDC_500KBPS
value|0x00
end_define

begin_comment
comment|/* 500KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_300KBPS
value|0x01
end_define

begin_comment
comment|/* 300KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_250KBPS
value|0x02
end_define

begin_comment
comment|/* 250KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_125KBPS
value|0x03
end_define

begin_comment
comment|/* 125KBPS FM drive transfer rate */
end_comment

begin_comment
comment|/* for some controllers 1MPBS instead */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FDC_500KBPS */
end_comment

begin_comment
comment|/*  * this is the secret PIO data port (offset from base)  */
end_comment

begin_define
define|#
directive|define
name|FDC_YE_DATAPORT
value|6
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_define
define|#
directive|define
name|FDIN
value|7
end_define

begin_comment
comment|/* Digital Input Register (R) */
end_comment

begin_define
define|#
directive|define
name|FDI_DCHG
value|0x80
end_define

begin_comment
comment|/* diskette has been changed */
end_comment

begin_comment
comment|/* requires drive and motor being selected */
end_comment

begin_comment
comment|/* is cleared by any step pulse to drive */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

