begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: if_snreg.h,v 1.3 1999/01/24 01:39:52 kmatsuda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Kouichi Matsuda.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Kouichi Matsuda for  *      NetBSD/pc98.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Modified for NetBSD/pc98 1.2.1 from NetBSD/mac68k 1.2D by Kouichi Matsuda.  * Make adapted for NEC PC-9801-83, 84, PC-9801-103, 104, PC-9801N-25 and  * PC-9801N-J02R, which uses National Semiconductor DP83934AVQB as  * Ethernet Controller and National Semiconductor NS46C46 as (64 * 16 bits)  * Microwire Serial EEPROM.  */
end_comment

begin_comment
comment|/*  * XXX: Should not be HERE. (Should be shared with...)  */
end_comment

begin_comment
comment|/*  * NEC/SONIC port mappings, offset from iobase.  */
end_comment

begin_define
define|#
directive|define
name|SNEC_CTRL
value|0
end_define

begin_comment
comment|/* SONIC control port (word) */
end_comment

begin_define
define|#
directive|define
name|SNEC_CTRLB
value|1
end_define

begin_comment
comment|/* NEC/SONIC control port (byte) */
end_comment

begin_define
define|#
directive|define
name|SNEC_RSVD0
value|2
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|SNEC_ADDR
value|3
end_define

begin_comment
comment|/* SONIC, NEC/SONIC register address set port */
end_comment

begin_define
define|#
directive|define
name|SNEC_RSVD1
value|4
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|SNEC_RSVD2
value|5
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|SNEC_NREGS
value|6
end_define

begin_comment
comment|/* bank memory size */
end_comment

begin_define
define|#
directive|define
name|SNEC_NMEMS
value|(NBPG * 2)
end_define

begin_comment
comment|/* how many bank */
end_comment

begin_define
define|#
directive|define
name|SNEC_NBANK
value|0x10
end_define

begin_comment
comment|/* internal buffer size */
end_comment

begin_define
define|#
directive|define
name|SNEC_NBUF
value|(SNEC_NMEMS * SNEC_NBANK)
end_define

begin_comment
comment|/*  * NEC/SONIC specific internal registers.  */
end_comment

begin_comment
comment|/*  *	Memory Bank Select Register (MEMBS)  */
end_comment

begin_define
define|#
directive|define
name|SNECR_MEMBS
value|0x80
end_define

begin_define
define|#
directive|define
name|SNECR_MEMBS_BSEN
value|0x01
end_define

begin_comment
comment|/* enable memory bank select */
end_comment

begin_define
define|#
directive|define
name|SNECR_MEMBS_EBNMSK
value|0x1c
end_define

begin_comment
comment|/* encoded bank select number */
end_comment

begin_comment
comment|/* Translate bank number to encoded bank select number. */
end_comment

begin_define
define|#
directive|define
name|SNECR_MEMBS_B2EB
parameter_list|(
name|bank
parameter_list|)
value|(bank<< 2)
end_define

begin_define
define|#
directive|define
name|SNECR_MEMBS_PCMCIABUS
value|0x80
end_define

begin_comment
comment|/* bus type identification */
end_comment

begin_comment
comment|/*  *	Memory Base Address Select Register (MEMSEL)  */
end_comment

begin_define
define|#
directive|define
name|SNECR_MEMSEL
value|0x82
end_define

begin_comment
comment|/* Translate base phys address to encoded select number. */
end_comment

begin_define
define|#
directive|define
name|SNECR_MEMSEL_PHYS2EN
parameter_list|(
name|maddr
parameter_list|)
value|((maddr>> 13)& 0x0f)
end_define

begin_comment
comment|/*  *	Encoded Irq Select Register (IRQSEL)  */
end_comment

begin_define
define|#
directive|define
name|SNECR_IRQSEL
value|0x84
end_define

begin_comment
comment|/*  *	EEPROM Access Register (EEP)  */
end_comment

begin_define
define|#
directive|define
name|SNECR_EEP
value|0x86
end_define

begin_define
define|#
directive|define
name|SNECR_EEP_DI
value|0x10
end_define

begin_comment
comment|/* EEPROM Serial Data Input (high) */
end_comment

begin_define
define|#
directive|define
name|SNECR_EEP_CS
value|0x20
end_define

begin_comment
comment|/* EEPROM Chip Select (high) */
end_comment

begin_define
define|#
directive|define
name|SNECR_EEP_SK
value|0x40
end_define

begin_comment
comment|/* EEPROM Serial Data Clock (high) */
end_comment

begin_define
define|#
directive|define
name|SNECR_EEP_DO
value|0x80
end_define

begin_comment
comment|/* EEPROM Serial Data Output (high) */
end_comment

begin_comment
comment|/* EEPROM data locations */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_KEY0
value|6
end_define

begin_comment
comment|/* Station Address Check Sum Key #1 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_KEY1
value|7
end_define

begin_comment
comment|/* Station Address Check Sum Key #2 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SA0
value|8
end_define

begin_comment
comment|/* Station Address #1 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SA1
value|9
end_define

begin_comment
comment|/* Station Address #2 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SA2
value|10
end_define

begin_comment
comment|/* Station Address #3 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SA3
value|11
end_define

begin_comment
comment|/* Station Address #4 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SA4
value|12
end_define

begin_comment
comment|/* Station Address #5 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SA5
value|13
end_define

begin_comment
comment|/* Station Address #6 */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_CKSUM
value|14
end_define

begin_comment
comment|/* Station Address Check Sum */
end_comment

begin_define
define|#
directive|define
name|SNEC_EEPROM_SIZE
value|32
end_define

begin_comment
comment|/* valid EEPROM data (max 128 bytes) */
end_comment

begin_comment
comment|/*  *	Bus and Mode Identification Register (IDENT)  */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT
value|0x88
end_define

begin_comment
comment|/* Bit 0: Bus Identification. */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT_CBUS
value|0x01
end_define

begin_comment
comment|/* on PC-98 C-Bus */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT_PCMCIABUS
value|0x00
end_define

begin_comment
comment|/* on PCMCIA Bus */
end_comment

begin_comment
comment|/* Bit 2: always 1 */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT_MAGIC
value|0x04
end_define

begin_comment
comment|/* Bit 4: Bus Configuration Mode Identification. */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT_PNP
value|0x10
end_define

begin_comment
comment|/* Plug and Play (C-Bus and PCMCIA) */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT_LEGACY
value|0x00
end_define

begin_comment
comment|/* Legacy C-Bus */
end_comment

begin_define
define|#
directive|define
name|SNECR_IDENT_LEGACY_CBUS
define|\
value|(SNECR_IDENT_LEGACY | SNECR_IDENT_MAGIC | SNECR_IDENT_CBUS)
end_define

begin_define
define|#
directive|define
name|SNECR_IDENT_PNP_CBUS
define|\
value|(SNECR_IDENT_PNP | SNECR_IDENT_MAGIC | SNECR_IDENT_CBUS)
end_define

begin_define
define|#
directive|define
name|SNECR_IDENT_PNP_PCMCIABUS
define|\
value|(SNECR_IDENT_PNP | SNECR_IDENT_MAGIC | SNECR_IDENT_PCMCIABUS)
end_define

begin_comment
comment|/*  * XXX: parent bus type aliases  */
end_comment

begin_define
define|#
directive|define
name|SNEC_TYPE_LEGACY
value|0
end_define

begin_define
define|#
directive|define
name|SNEC_TYPE_PNP
value|1
end_define

end_unit

