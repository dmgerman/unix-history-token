begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000  *	Paul Richards.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name Paul Richards may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PAUL RICHARDS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PAUL RICHARDS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|"lnc.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/lnc/if_lncvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/lnc/if_lncreg.h>
end_include

begin_decl_stmt
name|int
name|pcnet_probe
name|__P
argument_list|(
operator|(
name|lnc_softc_t
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|cnet98s_probe
name|__P
argument_list|(
operator|(
name|lnc_softc_t
operator|*
name|sc
operator|,
name|unsigned
name|iobase
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C-NET(98)S port addresses */
end_comment

begin_define
define|#
directive|define
name|CNET98S_RDP
value|0x400
end_define

begin_comment
comment|/* Register Data Port */
end_comment

begin_define
define|#
directive|define
name|CNET98S_RAP
value|0x402
end_define

begin_comment
comment|/* Register Address Port */
end_comment

begin_define
define|#
directive|define
name|CNET98S_RESET
value|0x404
end_define

begin_define
define|#
directive|define
name|CNET98S_IDP
value|0x406
end_define

begin_define
define|#
directive|define
name|CNET98S_EEPROM
value|0x40e
end_define

begin_comment
comment|/*  * XXX - The I/O address range is fragmented in the C-NET(98)S.  *       This is the number of regs at iobase.  */
end_comment

begin_define
define|#
directive|define
name|CNET98S_IOSIZE
value|16
end_define

begin_comment
comment|/* # of i/o addresses used. */
end_comment

begin_comment
comment|/* ISA Bus Configuration Registers */
end_comment

begin_comment
comment|/* XXX - Should be in ic/Am7990.h */
end_comment

begin_define
define|#
directive|define
name|MSRDA
value|0x0000
end_define

begin_comment
comment|/* ISACSR0: Master Mode Read Activity */
end_comment

begin_define
define|#
directive|define
name|MSWRA
value|0x0001
end_define

begin_comment
comment|/* ISACSR1: Master Mode Write Activity */
end_comment

begin_define
define|#
directive|define
name|MC
value|0x0002
end_define

begin_comment
comment|/* ISACSR2: Miscellaneous Configuration */
end_comment

begin_define
define|#
directive|define
name|LED1
value|0x0005
end_define

begin_comment
comment|/* ISACSR5: LED1 Status */
end_comment

begin_define
define|#
directive|define
name|LED2
value|0x0006
end_define

begin_comment
comment|/* ISACSR6: LED2 Status */
end_comment

begin_define
define|#
directive|define
name|LED3
value|0x0007
end_define

begin_comment
comment|/* ISACSR7: LED3 Status */
end_comment

begin_define
define|#
directive|define
name|LED_PSE
value|0x0080
end_define

begin_comment
comment|/* Pulse Stretcher */
end_comment

begin_define
define|#
directive|define
name|LED_XMTE
value|0x0010
end_define

begin_comment
comment|/* Transmit Status */
end_comment

begin_define
define|#
directive|define
name|LED_RVPOLE
value|0x0008
end_define

begin_comment
comment|/* Receive Polarity */
end_comment

begin_define
define|#
directive|define
name|LED_RCVE
value|0x0004
end_define

begin_comment
comment|/* Receive Status */
end_comment

begin_define
define|#
directive|define
name|LED_JABE
value|0x0002
end_define

begin_comment
comment|/* Jabber */
end_comment

begin_define
define|#
directive|define
name|LED_COLE
value|0x0001
end_define

begin_comment
comment|/* Collision */
end_comment

begin_function
specifier|static
name|int
name|cnet98s_probe
parameter_list|(
name|lnc_softc_t
modifier|*
name|sc
parameter_list|,
name|unsigned
name|iobase
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|ushort
name|tmp
decl_stmt|;
name|sc
operator|->
name|rap
operator|=
name|iobase
operator|+
name|CNET98S_RAP
expr_stmt|;
name|sc
operator|->
name|rdp
operator|=
name|iobase
operator|+
name|CNET98S_RDP
expr_stmt|;
comment|/* Reset */
name|tmp
operator|=
name|inw
argument_list|(
name|iobase
operator|+
name|CNET98S_RESET
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|iobase
operator|+
name|CNET98S_RESET
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|sc
operator|->
name|nic
operator|.
name|ic
operator|=
name|pcnet_probe
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|sc
operator|->
name|nic
operator|.
name|ic
operator|==
name|UNKNOWN
operator|)
operator|||
operator|(
name|sc
operator|->
name|nic
operator|.
name|ic
operator|>
name|PCnet_32
operator|)
condition|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|sc
operator|->
name|nic
operator|.
name|ident
operator|=
name|CNET98S
expr_stmt|;
name|sc
operator|->
name|nic
operator|.
name|mem_mode
operator|=
name|DMA_FIXED
expr_stmt|;
comment|/* XXX - For now just use the defines */
name|sc
operator|->
name|nrdre
operator|=
name|NRDRE
expr_stmt|;
name|sc
operator|->
name|ntdre
operator|=
name|NTDRE
expr_stmt|;
comment|/* Extract MAC address from PROM */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ETHER_ADDR_LEN
condition|;
name|i
operator|++
control|)
block|{
name|sc
operator|->
name|arpcom
operator|.
name|ac_enaddr
index|[
name|i
index|]
operator|=
name|inb
argument_list|(
name|iobase
operator|+
operator|(
name|i
operator|*
literal|2
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * ISA Configuration 	 * 	 * XXX - Following parameters are Contec C-NET(98)S only. 	 *       So, check the Ethernet address here. 	 * 	 *       Contec uses 00 80 4c ?? ?? ?? 	 */
if|if
condition|(
name|sc
operator|->
name|arpcom
operator|.
name|ac_enaddr
index|[
literal|0
index|]
operator|==
operator|(
name|u_char
operator|)
literal|0x00
operator|&&
name|sc
operator|->
name|arpcom
operator|.
name|ac_enaddr
index|[
literal|1
index|]
operator|==
operator|(
name|u_char
operator|)
literal|0x80
operator|&&
name|sc
operator|->
name|arpcom
operator|.
name|ac_enaddr
index|[
literal|2
index|]
operator|==
operator|(
name|u_char
operator|)
literal|0x4c
condition|)
block|{
name|outw
argument_list|(
name|sc
operator|->
name|rap
argument_list|,
name|MSRDA
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|iobase
operator|+
name|CNET98S_IDP
argument_list|,
literal|0x0006
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|sc
operator|->
name|rap
argument_list|,
name|MSWRA
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|iobase
operator|+
name|CNET98S_IDP
argument_list|,
literal|0x0006
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|outw
argument_list|(
name|sc
operator|->
name|rap
argument_list|,
name|MC
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ISACSR2 = %x\n"
argument_list|,
name|inw
argument_list|(
name|iobase
operator|+
name|CNET98S_IDP
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|outw
argument_list|(
name|sc
operator|->
name|rap
argument_list|,
name|LED1
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|iobase
operator|+
name|CNET98S_IDP
argument_list|,
name|LED_PSE
operator||
name|LED_XMTE
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|sc
operator|->
name|rap
argument_list|,
name|LED2
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|iobase
operator|+
name|CNET98S_IDP
argument_list|,
name|LED_PSE
operator||
name|LED_RCVE
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|sc
operator|->
name|rap
argument_list|,
name|LED3
argument_list|)
expr_stmt|;
name|outw
argument_list|(
name|iobase
operator|+
name|CNET98S_IDP
argument_list|,
name|LED_PSE
operator||
name|LED_COLE
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|CNET98S_IOSIZE
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

