begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ka820.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Definitions specific to the ka820 cpu.  */
end_comment

begin_if
if|#
directive|if
name|VAX8200
end_if

begin_comment
comment|/*  * Device addresses.  */
end_comment

begin_define
define|#
directive|define
name|KA820_PORTADDR
value|0x20088000
end_define

begin_comment
comment|/* port controller */
end_comment

begin_define
define|#
directive|define
name|KA820_BRAMADDR
value|0x20090000
end_define

begin_comment
comment|/* boot ram */
end_comment

begin_define
define|#
directive|define
name|KA820_EEPROMADDR
value|0x20098000
end_define

begin_comment
comment|/* eeprom */
end_comment

begin_define
define|#
directive|define
name|KA820_RX50ADDR
value|0x200b0000
end_define

begin_comment
comment|/* rcx50 */
end_comment

begin_define
define|#
directive|define
name|KA820_CLOCKADDR
value|0x200b8000
end_define

begin_comment
comment|/* watch chip */
end_comment

begin_comment
comment|/*  * Sizes.  The port controller, RCX50, and watch chip are all one page.  */
end_comment

begin_define
define|#
directive|define
name|KA820_BRPAGES
value|16
end_define

begin_comment
comment|/* 8K */
end_comment

begin_define
define|#
directive|define
name|KA820_EEPAGES
value|64
end_define

begin_comment
comment|/* 32K */
end_comment

begin_comment
comment|/* port controller CSR bit values */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_RSTHALT
value|0x80000000
end_define

begin_comment
comment|/* restart halt */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_LCONS
value|0x40000000
end_define

begin_comment
comment|/* logical console */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_LCONSEN
value|0x20000000
end_define

begin_comment
comment|/* logical console enable */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_BIRESET
value|0x10000000
end_define

begin_comment
comment|/* BI reset */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_BISTF
value|0x08000000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_ENBAPT
value|0x04000000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_STPASS
value|0x02000000
end_define

begin_comment
comment|/* self test pass */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_RUN
value|0x01000000
end_define

begin_comment
comment|/* run */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_WWPE
value|0x00800000
end_define

begin_comment
comment|/* ??? parity even? */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_EVLCK
value|0x00400000
end_define

begin_comment
comment|/* event lock */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_WMEM
value|0x00200000
end_define

begin_comment
comment|/* write mem */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_EV4
value|0x00100000
end_define

begin_comment
comment|/* event 4 */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_EV3
value|0x00080000
end_define

begin_comment
comment|/* event 3 */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_EV2
value|0x00040000
end_define

begin_comment
comment|/* event 2 */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_EV1
value|0x00020000
end_define

begin_comment
comment|/* event 1 */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_EV0
value|0x00010000
end_define

begin_comment
comment|/* event 0 */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_WWPO
value|0x00008000
end_define

begin_comment
comment|/* ??? parity odd? */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_PERH
value|0x00004000
end_define

begin_comment
comment|/* parity error H */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_ENBPIPE
value|0x00002000
end_define

begin_comment
comment|/* enable? pipe */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_TIMEOUT
value|0x00001000
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_RSVD
value|0x00000800
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_CONSEN
value|0x00000400
end_define

begin_comment
comment|/* console interrupt enable */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_CONSCLR
value|0x00000200
end_define

begin_comment
comment|/* clear console interrupt */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_CONSINTR
value|0x00000100
end_define

begin_comment
comment|/* console interrupt req */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_RXIE
value|0x00000080
end_define

begin_comment
comment|/* RX50 interrupt enable */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_RXCLR
value|0x00000040
end_define

begin_comment
comment|/* clear RX50 interrupt */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_RXIRQ
value|0x00000020
end_define

begin_comment
comment|/* RX50 interrupt request */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_IPCLR
value|0x00000010
end_define

begin_comment
comment|/* clear IP interrupt */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_IPINTR
value|0x00000008
end_define

begin_comment
comment|/* IP interrupt request */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_CRDEN
value|0x00000004
end_define

begin_comment
comment|/* enable CRD interrupts */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_CRDCLR
value|0x00000002
end_define

begin_comment
comment|/* clear CRD interrupt */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_CRDINTR
value|0x00000001
end_define

begin_comment
comment|/* CRD interrupt request */
end_comment

begin_comment
comment|/* what the heck */
end_comment

begin_define
define|#
directive|define
name|KA820PORT_BITS
define|\
value|"\20\40RSTHALT\37LCONS\36LCONSEN\35BIRESET\34BISTF\33ENBAPT\32STPASS\31RUN\ \30WWPE\27EVLCK\26WMEM\25EV4\24EV3\23EV2\22EV1\21EV\20WWPO\17PERH\16ENBPIPE\ \15TIMEOUT\13CONSEN\12CONSCLR\11CONSINTR\10RXIE\7RXCLR\6RXIRQ\5IPCLR\4IPINTR\ \3CRDEN\2CLRCLR\1CRDINTR"
end_define

begin_comment
comment|/* clock CSR bit values, per csr */
end_comment

begin_define
define|#
directive|define
name|KA820CLK_0_BUSY
value|0x01
end_define

begin_comment
comment|/* busy (time changing) */
end_comment

begin_define
define|#
directive|define
name|KA820CLK_1_GO
value|0x0c
end_define

begin_comment
comment|/* run */
end_comment

begin_define
define|#
directive|define
name|KA820CLK_1_SET
value|0x0d
end_define

begin_comment
comment|/* set the time */
end_comment

begin_define
define|#
directive|define
name|KA820CLK_3_VALID
value|0x01
end_define

begin_comment
comment|/* clock is valid */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|ka820port
block|{
name|u_long
name|csr
decl_stmt|;
comment|/* that seems to be all.... */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ka820clock
block|{
name|u_char
name|sec
decl_stmt|;
name|u_char
name|pad0
decl_stmt|;
name|u_char
name|secalrm
decl_stmt|;
name|u_char
name|pad1
decl_stmt|;
name|u_char
name|min
decl_stmt|;
name|u_char
name|pad2
decl_stmt|;
name|u_char
name|minalrm
decl_stmt|;
name|u_char
name|pad3
decl_stmt|;
name|u_char
name|hr
decl_stmt|;
name|u_char
name|pad4
decl_stmt|;
name|u_char
name|hralrm
decl_stmt|;
name|u_char
name|pad5
decl_stmt|;
name|u_char
name|dayofwk
decl_stmt|;
name|u_char
name|pad6
decl_stmt|;
name|u_char
name|day
decl_stmt|;
name|u_char
name|pad7
decl_stmt|;
name|u_char
name|mon
decl_stmt|;
name|u_char
name|pad8
decl_stmt|;
name|u_char
name|yr
decl_stmt|;
name|u_char
name|pad9
decl_stmt|;
name|u_short
name|csr0
decl_stmt|;
name|u_short
name|csr1
decl_stmt|;
name|u_short
name|csr2
decl_stmt|;
name|u_short
name|csr3
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

