begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_ecreg.h	7.4 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * 3Com Ethernet controller registers.  */
end_comment

begin_struct
struct|struct
name|ecdevice
block|{
name|short
name|ec_rcr
decl_stmt|;
comment|/* Receive Control Register */
name|short
name|ec_xcr
decl_stmt|;
comment|/* Transmit Control Register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control and status bits -- rcr  */
end_comment

begin_define
define|#
directive|define
name|EC_SPIE
value|0x8000
end_define

begin_comment
comment|/* set parity interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EC_ASTEP
value|0x4000
end_define

begin_comment
comment|/* increment address counter */
end_comment

begin_define
define|#
directive|define
name|EC_AROM
value|0x2000
end_define

begin_comment
comment|/* 1: Use address ROM, 0: use RAM */
end_comment

begin_define
define|#
directive|define
name|EC_PE
value|0x2000
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|EC_AWCLK
value|0x1000
end_define

begin_comment
comment|/* address write clock bit */
end_comment

begin_define
define|#
directive|define
name|EC_PIE
value|0x1000
end_define

begin_comment
comment|/* Parity interrupt enable (read) */
end_comment

begin_define
define|#
directive|define
name|EC_ADATA
value|0x0f00
end_define

begin_comment
comment|/* address/filtering */
end_comment

begin_define
define|#
directive|define
name|EC_RDONE
value|0x0080
end_define

begin_comment
comment|/* receive done */
end_comment

begin_define
define|#
directive|define
name|EC_MDISAB
value|0x0080
end_define

begin_comment
comment|/* memory disable */
end_comment

begin_define
define|#
directive|define
name|EC_RINTEN
value|0x0040
end_define

begin_comment
comment|/* receive interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EC_RCLR
value|0x0020
end_define

begin_comment
comment|/* clear RDONE bit */
end_comment

begin_define
define|#
directive|define
name|EC_RWBN
value|0x0010
end_define

begin_comment
comment|/* submit buffer for receive */
end_comment

begin_define
define|#
directive|define
name|EC_RBN
value|0x000f
end_define

begin_comment
comment|/* buffer number */
end_comment

begin_define
define|#
directive|define
name|EC_RBITS
value|"\10\16PE\15PIE\10RDONE\7RINTEN"
end_define

begin_comment
comment|/*  * Control and status bits -- xcr  */
end_comment

begin_define
define|#
directive|define
name|EC_JAM
value|0x8000
end_define

begin_comment
comment|/* collision dectected */
end_comment

begin_define
define|#
directive|define
name|EC_JINTEN
value|0x4000
end_define

begin_comment
comment|/* collision interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EC_JCLR
value|0x2000
end_define

begin_comment
comment|/* clear collision detect */
end_comment

begin_define
define|#
directive|define
name|EC_UECLR
value|0x0100
end_define

begin_comment
comment|/* reset controller */
end_comment

begin_define
define|#
directive|define
name|EC_XDONE
value|0x0080
end_define

begin_comment
comment|/* transmit done */
end_comment

begin_define
define|#
directive|define
name|EC_XINTEN
value|0x0040
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EC_XCLR
value|0x0020
end_define

begin_comment
comment|/* clear XDONE bit */
end_comment

begin_define
define|#
directive|define
name|EC_XWBN
value|0x0010
end_define

begin_comment
comment|/* submit buffer for transmit */
end_comment

begin_define
define|#
directive|define
name|EC_XBN
value|0x000f
end_define

begin_comment
comment|/* buffer number */
end_comment

begin_define
define|#
directive|define
name|EC_XBITS
value|"\10\20JAM\17JINTEN\10XDONE\7XINTEN"
end_define

begin_comment
comment|/*  * Useful combinations  */
end_comment

begin_define
define|#
directive|define
name|EC_READ
value|(0x600|EC_RINTEN|EC_RWBN)
end_define

begin_define
define|#
directive|define
name|EC_MULTI
value|(0x700|EC_RINTEN|EC_RWBN)
end_define

begin_define
define|#
directive|define
name|EC_PROMISC
value|(0x000|EC_RINTEN|EC_RWBN)
end_define

begin_define
define|#
directive|define
name|EC_WRITE
value|(EC_JINTEN|EC_XINTEN|EC_XWBN)
end_define

begin_define
define|#
directive|define
name|EC_CLEAR
value|(EC_JINTEN|EC_XINTEN|EC_JCLR)
end_define

begin_comment
comment|/*  * Buffer number definitions  */
end_comment

begin_define
define|#
directive|define
name|ECTBF
value|0
end_define

begin_comment
comment|/* Buffer for transmit */
end_comment

begin_define
define|#
directive|define
name|ECRLBF
value|1
end_define

begin_comment
comment|/* First buffer for receive */
end_comment

begin_define
define|#
directive|define
name|ECRHBF
value|15
end_define

begin_comment
comment|/* Last buffer for receive */
end_comment

begin_define
define|#
directive|define
name|ECRDOFF
value|528
end_define

begin_comment
comment|/* Packet offset in read buffer */
end_comment

end_unit

