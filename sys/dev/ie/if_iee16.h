begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995  *	Rodney W. Grimes, Milwaukie, Oregon  97222.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Rodney W. Grimes.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RODNEY W. GRIMES ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL RODNEY W. GRIMES BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for EtherExpress 16  */
end_comment

begin_define
define|#
directive|define
name|IEE16_ATTN
value|0x06
end_define

begin_comment
comment|/* channel attention control */
end_comment

begin_define
define|#
directive|define
name|IEE16_IRQ
value|0x07
end_define

begin_comment
comment|/* IRQ configuration */
end_comment

begin_define
define|#
directive|define
name|IEE16_IRQ_ENABLE
value|0x08
end_define

begin_comment
comment|/* enable board interrupts */
end_comment

begin_define
define|#
directive|define
name|IEE16_MEMDEC
value|0x0a
end_define

begin_comment
comment|/* memory decode */
end_comment

begin_define
define|#
directive|define
name|IEE16_MCTRL
value|0x0b
end_define

begin_comment
comment|/* memory control */
end_comment

begin_define
define|#
directive|define
name|IEE16_MCTRL_FMCS16
value|0x10
end_define

begin_comment
comment|/* MEMCS16- for F000 */
end_comment

begin_define
define|#
directive|define
name|IEE16_MPCTRL
value|0x0c
end_define

begin_comment
comment|/* memory page control */
end_comment

begin_define
define|#
directive|define
name|IEE16_CONFIG
value|0x0d
end_define

begin_comment
comment|/* config register */
end_comment

begin_define
define|#
directive|define
name|IEE16_BART_LOOPBACK
value|0x02
end_define

begin_comment
comment|/* loopback, 0=none, 1=loopback */
end_comment

begin_define
define|#
directive|define
name|IEE16_BART_IOCHRDY_LATE
value|0x10
end_define

begin_comment
comment|/* iochrdy late control bit */
end_comment

begin_define
define|#
directive|define
name|IEE16_BART_IO_TEST_EN
value|0x20
end_define

begin_comment
comment|/* enable iochrdy timing test */
end_comment

begin_define
define|#
directive|define
name|IEE16_BART_IO_RESULT
value|0x40
end_define

begin_comment
comment|/* result of the iochrdy test */
end_comment

begin_define
define|#
directive|define
name|IEE16_BART_MCS16_TEST
value|0x80
end_define

begin_comment
comment|/* enable memcs16 select test */
end_comment

begin_define
define|#
directive|define
name|IEE16_ECTRL
value|0x0e
end_define

begin_comment
comment|/* eeprom control */
end_comment

begin_define
define|#
directive|define
name|IEE16_ECTRL_EESK
value|0x01
end_define

begin_comment
comment|/* EEPROM clock bit */
end_comment

begin_define
define|#
directive|define
name|IEE16_ECTRL_EECS
value|0x02
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|IEE16_ECTRL_EEDI
value|0x04
end_define

begin_comment
comment|/* EEPROM data in bit */
end_comment

begin_define
define|#
directive|define
name|IEE16_ECTRL_EEDO
value|0x08
end_define

begin_comment
comment|/* EEPROM data out bit */
end_comment

begin_define
define|#
directive|define
name|IEE16_RESET_ASIC
value|0x40
end_define

begin_comment
comment|/* reset ASIC (bart) pin */
end_comment

begin_define
define|#
directive|define
name|IEE16_RESET_586
value|0x80
end_define

begin_comment
comment|/* reset 82586 pin */
end_comment

begin_define
define|#
directive|define
name|IEE16_ECTRL_MASK
value|0xb2
end_define

begin_comment
comment|/* and'ed with ECTRL to enable read  */
end_comment

begin_define
define|#
directive|define
name|IEE16_MECTRL
value|0x0f
end_define

begin_comment
comment|/* memory control, 0xe000 seg 'W' */
end_comment

begin_define
define|#
directive|define
name|IEE16_ID_PORT
value|0x0f
end_define

begin_comment
comment|/* auto-id port 'R' */
end_comment

begin_define
define|#
directive|define
name|IEE16_ID
value|0xbaba
end_define

begin_comment
comment|/* known id of EE16 */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_READ
value|0x06
end_define

begin_comment
comment|/* EEPROM read opcode */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_OPSIZE1
value|0x03
end_define

begin_comment
comment|/* size of EEPROM opcodes */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_ADDR_SIZE
value|0x06
end_define

begin_comment
comment|/* size of EEPROM address */
end_comment

begin_comment
comment|/* Locations in the EEPROM */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_CONFIG1
value|0x00
end_define

begin_comment
comment|/* Configuration register 1 */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_IRQ
value|0xE000
end_define

begin_comment
comment|/* Encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_IRQ_SHIFT
value|13
end_define

begin_comment
comment|/* To shift IRQ to lower bits */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_LOCK_ADDR
value|0x01
end_define

begin_comment
comment|/* contains the lock bit */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_LOCKED
value|0x01
end_define

begin_comment
comment|/* means that it is locked */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_ENET_LOW
value|0x02
end_define

begin_comment
comment|/* Ethernet address, low word */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_ENET_MID
value|0x03
end_define

begin_comment
comment|/* Ethernet address, middle word */
end_comment

begin_define
define|#
directive|define
name|IEE16_EEPROM_ENET_HIGH
value|0x04
end_define

begin_comment
comment|/* Ethernet address, high word */
end_comment

end_unit

