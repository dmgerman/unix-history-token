begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hostctlr.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_HOST3270
end_define

begin_comment
comment|/* define orders given to 3270's */
end_comment

begin_define
define|#
directive|define
name|ORDER_SF
value|0x1d
end_define

begin_comment
comment|/* Start Field */
end_comment

begin_define
define|#
directive|define
name|ORDER_SFE
value|0x29
end_define

begin_comment
comment|/* Start Field Extended */
end_comment

begin_define
define|#
directive|define
name|ORDER_SBA
value|0x11
end_define

begin_comment
comment|/* Set Buffer Address (for output) */
end_comment

begin_define
define|#
directive|define
name|ORDER_SA
value|0x28
end_define

begin_comment
comment|/* Set Attribute */
end_comment

begin_define
define|#
directive|define
name|ORDER_MF
value|0x2c
end_define

begin_comment
comment|/* Modify field */
end_comment

begin_define
define|#
directive|define
name|ORDER_IC
value|0x13
end_define

begin_comment
comment|/* Insert Cursor (at buffer address) */
end_comment

begin_define
define|#
directive|define
name|ORDER_PT
value|0x05
end_define

begin_comment
comment|/* Program Tab (absurdly complicated) */
end_comment

begin_define
define|#
directive|define
name|ORDER_RA
value|0x3c
end_define

begin_comment
comment|/* Repeat next character to some addr */
end_comment

begin_define
define|#
directive|define
name|ORDER_EUA
value|0x12
end_define

begin_comment
comment|/* Null out every unprotected field 					 * to some address. 					 */
end_comment

begin_define
define|#
directive|define
name|ORDER_GE
value|0x08
end_define

begin_comment
comment|/* Graphics Escape */
end_comment

begin_define
define|#
directive|define
name|ORDER_YALE
value|0x2b
end_define

begin_comment
comment|/* This is a special YALE order, which 					 * introduces YALE extended orders 					 * (like setting tabs, etc.). 					 */
end_comment

begin_comment
comment|/* The following is defined for initialization and error messages. */
end_comment

begin_struct
struct|struct
name|orders_def
block|{
name|int
name|code
decl_stmt|;
comment|/* As in 3270 data stream */
name|char
modifier|*
name|short_name
decl_stmt|,
comment|/* Short name */
modifier|*
name|long_name
decl_stmt|;
comment|/* Long name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ORDERS_DEF
value|{ \ 			    ORDER_SF, "SF", "Start Field", \ 			    ORDER_SFE, "SFE", "Start Field Extended", \ 			    ORDER_SBA, "SBA", "Set Buffer Address", \ 			    ORDER_SA, "SA", "Set Attribute", \ 			    ORDER_MF, "MF", "Modify Field", \ 			    ORDER_IC, "IC", "Insert Cursor", \ 			    ORDER_PT, "PT", "Program Tab", \ 			    ORDER_RA, "RA", "Repeat to Address", \ 			    ORDER_EUA, "EUA", "Erase Unprotected to Address", \ 			    ORDER_GE, "GE", "Graphics Escape", \ 			    ORDER_YALE, "YALE", "Yale Order" \ 			}
end_define

begin_define
define|#
directive|define
name|ATTR_RESET
value|0x00
end_define

begin_comment
comment|/* SA only - reset to default */
end_comment

begin_define
define|#
directive|define
name|ATTR_DEFAULT
value|0x00
end_define

begin_comment
comment|/* reset to default */
end_comment

begin_comment
comment|/* Also for 0x41-43 below */
end_comment

begin_define
define|#
directive|define
name|ATTR_FIELD
value|0xC0
end_define

begin_comment
comment|/* Field attributes */
end_comment

begin_define
define|#
directive|define
name|ATTR_MASK
value|0xc0
end_define

begin_comment
comment|/* control bits */
end_comment

begin_define
define|#
directive|define
name|ATTR_PROT
value|0x20
end_define

begin_comment
comment|/* protected bit */
end_comment

begin_define
define|#
directive|define
name|ATTR_NUMERIC
value|0x10
end_define

begin_comment
comment|/* numeric field */
end_comment

begin_define
define|#
directive|define
name|ATTR_AUTO_SKIP_MASK
value|0x30
end_define

begin_comment
comment|/* mask to check auto skip */
end_comment

begin_define
define|#
directive|define
name|ATTR_AUTO_SKIP_VALUE
value|0x30
end_define

begin_comment
comment|/* value to have auto skip */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_MASK
value|0x0c
end_define

begin_comment
comment|/* highlighting, etc. */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_DNSPD
value|0x00
end_define

begin_comment
comment|/* display, no select */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_DSPD
value|0x04
end_define

begin_comment
comment|/* display, select */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_HIGH
value|0x08
end_define

begin_comment
comment|/* highlighted, select */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_NONDISPLAY
value|0x0c
end_define

begin_comment
comment|/* non-display, no select */
end_comment

begin_define
define|#
directive|define
name|ATTR_MDT
value|0x01
end_define

begin_comment
comment|/* modified data tag */
end_comment

begin_define
define|#
directive|define
name|ATTR_EXTENDED_HIGHLIGHT
value|0x41
end_define

begin_comment
comment|/* Extended highlighting */
end_comment

begin_define
define|#
directive|define
name|ATTR_BLINK
value|0xf1
end_define

begin_comment
comment|/* Blinking */
end_comment

begin_define
define|#
directive|define
name|ATTR_REVERSE_VIDEO
value|0xf2
end_define

begin_comment
comment|/* Reverse video */
end_comment

begin_define
define|#
directive|define
name|ATTR_UNDERSCORE
value|0xf3
end_define

begin_comment
comment|/* Underline */
end_comment

begin_define
define|#
directive|define
name|ATTR_COLOR
value|0x42
end_define

begin_comment
comment|/* Color */
end_comment

begin_define
define|#
directive|define
name|ATTR_BLUE
value|0xf1
end_define

begin_define
define|#
directive|define
name|ATTR_RED
value|0xf2
end_define

begin_define
define|#
directive|define
name|ATTR_PINK
value|0xf3
end_define

begin_define
define|#
directive|define
name|ATTR_GREEN
value|0xf4
end_define

begin_define
define|#
directive|define
name|ATTR_TURQUOISE
value|0xf5
end_define

begin_define
define|#
directive|define
name|ATTR_YELLOW
value|0xf6
end_define

begin_define
define|#
directive|define
name|ATTR_WHITE
value|0xf7
end_define

begin_comment
comment|/* for 3279; black for 3287; */
end_comment

begin_comment
comment|/* multicolor for triple */
end_comment

begin_comment
comment|/* plane symbol */
end_comment

begin_define
define|#
directive|define
name|ATTR_PROGRAMMED_SYMBOLS
value|0x43
end_define

begin_comment
comment|/* Programmed Symbols */
end_comment

begin_define
define|#
directive|define
name|ATTR_SYMBOL_SET_LOW
value|0x40
end_define

begin_comment
comment|/* Lowest loadable set ID */
end_comment

begin_define
define|#
directive|define
name|ATTR_SYMBOL_SET_HIGH
value|0xef
end_define

begin_comment
comment|/* Highest loadable set ID */
end_comment

begin_define
define|#
directive|define
name|ATTR_SYMBOL_SET_APLTEXT
value|0xf1
end_define

begin_comment
comment|/* Non-SNA control unit commands */
end_comment

begin_define
define|#
directive|define
name|CMD_ERASE_ALL_UNPROTECTED
value|0x0f
end_define

begin_define
define|#
directive|define
name|CMD_ERASE_WRITE
value|0x05
end_define

begin_define
define|#
directive|define
name|CMD_ERASE_WRITE_ALTERNATE
value|0x0d
end_define

begin_define
define|#
directive|define
name|CMD_READ_BUFFER
value|0x02
end_define

begin_define
define|#
directive|define
name|CMD_READ_MODIFIED
value|0x06
end_define

begin_define
define|#
directive|define
name|CMD_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_STRUCTURED_FIELD
value|0x11
end_define

begin_comment
comment|/* SNA control unit commands */
end_comment

begin_define
define|#
directive|define
name|CMD_SNA_COPY
value|0xf7
end_define

begin_define
define|#
directive|define
name|CMD_SNA_ERASE_ALL_UNPROTECTED
value|0x6f
end_define

begin_define
define|#
directive|define
name|CMD_SNA_ERASE_WRITE
value|0xf5
end_define

begin_define
define|#
directive|define
name|CMD_SNA_ERASE_WRITE_ALTERNATE
value|0x7e
end_define

begin_define
define|#
directive|define
name|CMD_SNA_READ_BUFFER
value|0xf2
end_define

begin_define
define|#
directive|define
name|CMD_SNA_READ_MODIFIED
value|0xf6
end_define

begin_define
define|#
directive|define
name|CMD_SNA_READ_MODIFIED_ALL
value|0x6e
end_define

begin_define
define|#
directive|define
name|CMD_SNA_WRITE
value|0xf1
end_define

begin_define
define|#
directive|define
name|CMD_SNA_WRITE_STRUCTURED_FIELD
value|0xf3
end_define

begin_define
define|#
directive|define
name|WCC_RESET
value|0x40
end_define

begin_define
define|#
directive|define
name|WCC_ALARM
value|0x04
end_define

begin_define
define|#
directive|define
name|WCC_RESTORE
value|0x02
end_define

begin_define
define|#
directive|define
name|WCC_RESET_MDT
value|0x01
end_define

begin_comment
comment|/* Special EBCDIC characters unique to a 3270 */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_BLANK
value|0x40
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_CENTSIGN
value|0x4a
end_define

begin_comment
comment|/* Cent sign */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_DUP
value|0x1c
end_define

begin_comment
comment|/* DUP character */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_FM
value|0x1e
end_define

begin_comment
comment|/* Field mark character */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_PERCENT
value|0x6c
end_define

begin_comment
comment|/* Percent sign */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_SLASH
value|0x61
end_define

begin_comment
comment|/* Slash */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_SOH
value|0x01
end_define

begin_comment
comment|/* Start of Heading */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_STX
value|0x02
end_define

begin_comment
comment|/* Start of Text */
end_comment

begin_comment
comment|/* Structured field types */
end_comment

begin_define
define|#
directive|define
name|SF_3270DS
value|0x40
end_define

begin_comment
comment|/* For write operations */
end_comment

begin_define
define|#
directive|define
name|SF_LPS
value|0x06
end_define

begin_comment
comment|/* Load Programmed Symbols */
end_comment

begin_define
define|#
directive|define
name|SF_SRM
value|0x09
end_define

begin_comment
comment|/* Set Reply Mode */
end_comment

begin_define
define|#
directive|define
name|SF_SWO
value|0x0b
end_define

begin_comment
comment|/* Set Window Origin */
end_comment

begin_define
define|#
directive|define
name|SF_READ_PARTITION
value|0x01
end_define

begin_comment
comment|/* Read Partition (Query) */
end_comment

begin_define
define|#
directive|define
name|SF_ERASE_RESET
value|0x03
end_define

begin_comment
comment|/* Erase (and/or Reset) */
end_comment

begin_define
define|#
directive|define
name|SF_SCS_DATA
value|0x41
end_define

begin_comment
comment|/* SCS Data */
end_comment

begin_define
define|#
directive|define
name|SF_CREATE_PARTITION
value|0x0c
end_define

begin_comment
comment|/* Create a partition */
end_comment

begin_escape
end_escape

begin_comment
comment|/* AID characters sent to host.  *  * Note that this file (the following entries) are scanned by mkhit.c,  * and that the format must remain more-or-less consistent  * (#define\tAID_name\t[\t]*TOKEN)  */
end_comment

begin_define
define|#
directive|define
name|AID_NONE
value|0x60
end_define

begin_comment
comment|/* No AID (display) */
end_comment

begin_define
define|#
directive|define
name|AID_NONE_PRINTER
value|0xe8
end_define

begin_comment
comment|/* No AID (printer) */
end_comment

begin_define
define|#
directive|define
name|AID_PA1
value|0x6c
end_define

begin_define
define|#
directive|define
name|AID_PA2
value|0x6e
end_define

begin_define
define|#
directive|define
name|AID_PA3
value|0x6b
end_define

begin_define
define|#
directive|define
name|AID_CLEAR
value|0x6d
end_define

begin_define
define|#
directive|define
name|AID_TREQ
value|0xf0
end_define

begin_define
define|#
directive|define
name|AID_ENTER
value|0x7d
end_define

begin_define
define|#
directive|define
name|AID_SELPEN
value|0x7e
end_define

begin_comment
comment|/* 					 * Really, only SELPEN with DESIGNATOR 					 * = space or null 					 */
end_comment

begin_define
define|#
directive|define
name|AID_PF1
value|0xf1
end_define

begin_define
define|#
directive|define
name|AID_PF2
value|0xf2
end_define

begin_define
define|#
directive|define
name|AID_PF3
value|0xf3
end_define

begin_define
define|#
directive|define
name|AID_PF4
value|0xf4
end_define

begin_define
define|#
directive|define
name|AID_PF5
value|0xf5
end_define

begin_define
define|#
directive|define
name|AID_PF6
value|0xf6
end_define

begin_define
define|#
directive|define
name|AID_PF7
value|0xf7
end_define

begin_define
define|#
directive|define
name|AID_PF8
value|0xf8
end_define

begin_define
define|#
directive|define
name|AID_PF9
value|0xf9
end_define

begin_define
define|#
directive|define
name|AID_PF10
value|0x7a
end_define

begin_define
define|#
directive|define
name|AID_PF11
value|0x7b
end_define

begin_define
define|#
directive|define
name|AID_PF12
value|0x7c
end_define

begin_define
define|#
directive|define
name|AID_PF13
value|0xc1
end_define

begin_define
define|#
directive|define
name|AID_PF14
value|0xc2
end_define

begin_define
define|#
directive|define
name|AID_PF15
value|0xc3
end_define

begin_define
define|#
directive|define
name|AID_PF16
value|0xc4
end_define

begin_define
define|#
directive|define
name|AID_PF17
value|0xc5
end_define

begin_define
define|#
directive|define
name|AID_PF18
value|0xc6
end_define

begin_define
define|#
directive|define
name|AID_PF19
value|0xc7
end_define

begin_define
define|#
directive|define
name|AID_PF20
value|0xc8
end_define

begin_define
define|#
directive|define
name|AID_PF21
value|0xc9
end_define

begin_define
define|#
directive|define
name|AID_PF22
value|0x4a
end_define

begin_define
define|#
directive|define
name|AID_PF23
value|0x4b
end_define

begin_define
define|#
directive|define
name|AID_PF24
value|0x4c
end_define

begin_define
define|#
directive|define
name|AID_PF25
value|0xd1
end_define

begin_define
define|#
directive|define
name|AID_PF26
value|0xd2
end_define

begin_define
define|#
directive|define
name|AID_PF27
value|0xd3
end_define

begin_define
define|#
directive|define
name|AID_PF28
value|0xd4
end_define

begin_define
define|#
directive|define
name|AID_PF29
value|0xd5
end_define

begin_define
define|#
directive|define
name|AID_PF30
value|0xd6
end_define

begin_define
define|#
directive|define
name|AID_PF31
value|0xd7
end_define

begin_define
define|#
directive|define
name|AID_PF32
value|0xd8
end_define

begin_define
define|#
directive|define
name|AID_PF33
value|0xd9
end_define

begin_define
define|#
directive|define
name|AID_PF34
value|0x5a
end_define

begin_define
define|#
directive|define
name|AID_PF35
value|0x5b
end_define

begin_define
define|#
directive|define
name|AID_PF36
value|0x5c
end_define

end_unit

