begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	PCMCIA card structures and defines.  *	These defines relate to the user level  *	structures and card information, not  *	driver/process communication.  *-------------------------------------------------------------------------  *  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  *	Card Information Structure tuples definitions  *	The structure of a tuple is basically:  *  *		Tuple_code  *		Tuple_data_length  *		Tuple_data ...  *  *	Tuples are contiguous in attribute memory, and  *	are terminated with a 0xFF for the tuple code or  *	the tuple length.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_CIS_H
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_CIS_H
end_define

begin_define
define|#
directive|define
name|CIS_NULL
value|0
end_define

begin_comment
comment|/* Empty tuple */
end_comment

begin_define
define|#
directive|define
name|CIS_MEM_COMMON
value|0x01
end_define

begin_comment
comment|/* Device descriptor, common memory */
end_comment

begin_define
define|#
directive|define
name|CIS_LONGLINK_CB
value|0x02
end_define

begin_comment
comment|/* Long link to next chain for CardBus */
end_comment

begin_define
define|#
directive|define
name|CIS_INDIRECT
value|0x03
end_define

begin_comment
comment|/* Indirect access */
end_comment

begin_define
define|#
directive|define
name|CIS_CONF_MAP_CB
value|0x04
end_define

begin_comment
comment|/* Card Configuration map for CardBus */
end_comment

begin_define
define|#
directive|define
name|CIS_CONFIG_CB
value|0x05
end_define

begin_comment
comment|/* Card Configuration entry for CardBus */
end_comment

begin_define
define|#
directive|define
name|CIS_LONGLINK_MFC
value|0x06
end_define

begin_comment
comment|/* Long link to next chain for Multi function card */
end_comment

begin_define
define|#
directive|define
name|CIS_BAR
value|0x07
end_define

begin_comment
comment|/* Base address register for CardBus */
end_comment

begin_define
define|#
directive|define
name|CIS_CHECKSUM
value|0x10
end_define

begin_comment
comment|/* Checksum */
end_comment

begin_define
define|#
directive|define
name|CIS_LONGLINK_A
value|0x11
end_define

begin_comment
comment|/* Link to Attribute memory */
end_comment

begin_define
define|#
directive|define
name|CIS_LONGLINK_C
value|0x12
end_define

begin_comment
comment|/* Link to Common memory */
end_comment

begin_define
define|#
directive|define
name|CIS_LINKTARGET
value|0x13
end_define

begin_comment
comment|/* Linked tuple must start with this. */
end_comment

begin_define
define|#
directive|define
name|CIS_NOLINK
value|0x14
end_define

begin_comment
comment|/* Assume no common memory link tuple. */
end_comment

begin_define
define|#
directive|define
name|CIS_INFO_V1
value|0x15
end_define

begin_comment
comment|/* Card info data, version 1 */
end_comment

begin_define
define|#
directive|define
name|CIS_ALTSTR
value|0x16
end_define

begin_comment
comment|/* Alternate language string tuple. */
end_comment

begin_define
define|#
directive|define
name|CIS_MEM_ATTR
value|0x17
end_define

begin_comment
comment|/* Device descriptor, Attribute memory */
end_comment

begin_define
define|#
directive|define
name|CIS_JEDEC_C
value|0x18
end_define

begin_comment
comment|/* JEDEC descr for common memory */
end_comment

begin_define
define|#
directive|define
name|CIS_JEDEC_A
value|0x19
end_define

begin_comment
comment|/* JEDEC descr for Attribute memory */
end_comment

begin_define
define|#
directive|define
name|CIS_CONF_MAP
value|0x1A
end_define

begin_comment
comment|/* Card Configuration map */
end_comment

begin_define
define|#
directive|define
name|CIS_CONFIG
value|0x1B
end_define

begin_comment
comment|/* Card Configuration entry */
end_comment

begin_define
define|#
directive|define
name|CIS_DEVICE_OC
value|0x1C
end_define

begin_comment
comment|/* Other conditions info - common memory */
end_comment

begin_define
define|#
directive|define
name|CIS_DEVICE_OA
value|0x1D
end_define

begin_comment
comment|/* Other conditions info - attribute memory */
end_comment

begin_define
define|#
directive|define
name|CIS_DEVICEGEO
value|0x1E
end_define

begin_comment
comment|/* Geometry info for common memory */
end_comment

begin_define
define|#
directive|define
name|CIS_DEVICEGEO_A
value|0x1F
end_define

begin_comment
comment|/* Geometry info for attribute memory */
end_comment

begin_define
define|#
directive|define
name|CIS_MANUF_ID
value|0x20
end_define

begin_comment
comment|/* Card manufacturer's ID */
end_comment

begin_define
define|#
directive|define
name|CIS_FUNC_ID
value|0x21
end_define

begin_comment
comment|/* Function of card */
end_comment

begin_define
define|#
directive|define
name|CIS_FUNC_EXT
value|0x22
end_define

begin_comment
comment|/* Functional extension */
end_comment

begin_comment
comment|/*  *	Data recording format tuples.  */
end_comment

begin_define
define|#
directive|define
name|CIS_SW_INTERLV
value|0x23
end_define

begin_comment
comment|/* Software interleave */
end_comment

begin_define
define|#
directive|define
name|CIS_VERS_2
value|0x40
end_define

begin_comment
comment|/* Card info data, version 2 */
end_comment

begin_define
define|#
directive|define
name|CIS_FORMAT
value|0x41
end_define

begin_comment
comment|/* Memory card format */
end_comment

begin_define
define|#
directive|define
name|CIS_GEOMETRY
value|0x42
end_define

begin_comment
comment|/* Disk sector layout */
end_comment

begin_define
define|#
directive|define
name|CIS_BYTEORDER
value|0x43
end_define

begin_comment
comment|/* Byte order of memory data */
end_comment

begin_define
define|#
directive|define
name|CIS_DATE
value|0x44
end_define

begin_comment
comment|/* Format data/time */
end_comment

begin_define
define|#
directive|define
name|CIS_BATTERY
value|0x45
end_define

begin_comment
comment|/* Battery replacement date */
end_comment

begin_define
define|#
directive|define
name|CIS_ORG
value|0x46
end_define

begin_comment
comment|/* Organization of data on card */
end_comment

begin_define
define|#
directive|define
name|CIS_END
value|0xFF
end_define

begin_comment
comment|/* Termination code */
end_comment

begin_comment
comment|/*  *	Internal tuple definitions.  *  *	Device descriptor for memory (CIS_MEM_ATTR, CIS_MEM_COMMON)  *  *	Byte 1:  *		0xF0 - Device type  *		0x08 - Write protect switch  *		0x07 - Speed index (7 = extended speed)  *	Byte 2: Extended speed (bit 7 = another follows)  *	Byte 3: (ignored if 0xFF)  *		0xF8 - Addressable units (0's numbered)  *		0x07 - Unit size  *	The three byte sequence is repeated until byte 1 == 0xFF  */
end_comment

begin_comment
comment|/*  *	CIS_INFO_V1 - Version one card information.  *  *	Byte 1:   Major version number (should be 4)  *	Byte 2:   Minor version number (should be 1)  *	Byte 3-x: Null terminated Manufacturer name  *	Byte x-x: Null terminated product name  *	Byte x-x: Null terminated additional info 1  *	Byte x-x: Null terminated additional info 2  *	Byte x:   final byte must be 0xFF  */
end_comment

begin_define
define|#
directive|define
name|CIS_MAJOR_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|CIS_MINOR_VERSION
value|1
end_define

begin_comment
comment|/*  *	CIS_CONF_MAP - Provides an address map for the card  *			configuration register(s), and a max value  *			identifying the last configuration tuple.  *  *	Byte 1:  *		0x3C - Register mask size (0's numbered)  *		0x03 - Register address size (0's numbered)  *	Byte 2:  *		0x3F - ID of last configuration.  *	Byte 3-n: Card register address (size is determined by  *			the value in byte 1).  *	Byte x-x: Card register masks (size determined by the  *			value in byte 1)  */
end_comment

begin_comment
comment|/*  *	CIS_CONFIG - Card configuration entry. Multiple tuples may  *		exist of this type, each one describing a different  *		memory/I-O map that can be used to address this card.  *		The first one usually has extra config data about the  *		card features. The final configuration tuple number  *		is stored in the CIS_CONF_MAP tuple so that the complete  *		list can be scanned.  *  *	Byte 1:  *		0x3F - Configuration ID number.  *		0x40 - Indicates this is the default configuration  *		0x80 - Interface byte exists  *	Byte 2: (exists only if bit 0x80 set in byte 1)  *		0x0F - Interface type value  *		0x10 - Battery voltage detect  *		0x20 - Write protect active  *		0x40 - RdyBsy active bit  *		0x80 - Wait signal required  *	Byte 3: (features byte)  *		0x03 - Power sub-tuple(s) exists  *		0x04 - Timing sub-tuple exists  *		0x08 - I/O space sub-tuple exists  *		0x10 - IRQ sub-tuple exists  *		0x60 - Memory space sub-tuple(s) exists  *		0x80 - Miscellaneous sub-tuple exists  */
end_comment

begin_define
define|#
directive|define
name|CIS_FEAT_POWER
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3)
end_define

begin_define
define|#
directive|define
name|CIS_FEAT_TIMING
value|0x4
end_define

begin_define
define|#
directive|define
name|CIS_FEAT_I_O
value|0x8
end_define

begin_define
define|#
directive|define
name|CIS_FEAT_IRQ
value|0x10
end_define

begin_define
define|#
directive|define
name|CIS_FEAT_MEMORY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x3)
end_define

begin_define
define|#
directive|define
name|CIS_FEAT_MISC
value|0x80
end_define

begin_comment
comment|/*  *	Depending on whether the "features" byte has the corresponding  *	bit set, a number of sub-tuples follow. Some features have  *	more than one sub-tuple, depending on the count within the  *	features byte (e.g power feature bits allows up to 3 sub-tuples).  *  *	Power structure sub-tuple:  *	Byte 1: parameter exists - Each bit (starting from 0x01) indicates  *		that a parameter block exists - up to 8 parameter blocks  *		are therefore allowed).  *	Byte 2:  *		0x7F - Parameter data  *		0x80 - More bytes follow (0 = last byte)  *  *	Timing sub-tuple  *	Byte 1:  *		0x03 - Wait scale  *		0x1C - Ready scale  *		0xE0 - Reserved scale  *	Byte 2: extended wait scale if wait scale != 3  *	Byte 3: extended ready scale if ready scale != 7  *	Byte 4: extended reserved scale if reserved scale != 7  */
end_comment

begin_define
define|#
directive|define
name|CIS_WAIT_SCALE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3)
end_define

begin_define
define|#
directive|define
name|CIS_READY_SCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>>2)& 0x7)
end_define

begin_define
define|#
directive|define
name|CIS_RESERVED_SCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>>5)& 0x7)
end_define

begin_comment
comment|/*  *	I/O mapping sub-tuple:  *	Byte 1:  *		0x1F - I/O address lines  *		0x20 - 8 bit I/O  *		0x40 - 16 bit I/O  *		0x80 - I/O range??  *	Byte 2:  *		0x0F - 0's numbered count of I/O block subtuples following.  *		0x30 - Size of I/O address value within subtuple. Values  *			can be 1 (8 bits), 2 (16 bits) or 3 (32 bits).  *		0xC0 - Size of I/O port block size value within subtuple.  *	I/O block sub-tuples, count from previous block:  *		Byte 1-n: I/O start address  *		Byte x-x: Size of I/O port block.  */
end_comment

begin_define
define|#
directive|define
name|CIS_IO_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1F)
end_define

begin_define
define|#
directive|define
name|CIS_IO_8BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|CIS_IO_16BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|CIS_IO_RANGE
value|0x80
end_define

begin_define
define|#
directive|define
name|CIS_IO_BLKS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xF)
end_define

begin_define
define|#
directive|define
name|CIS_IO_ADSZ
parameter_list|(
name|x
parameter_list|)
value|(((x)>>4)& 3)
end_define

begin_define
define|#
directive|define
name|CIS_IO_BLKSZ
parameter_list|(
name|x
parameter_list|)
value|(((x)>>6)& 3)
end_define

begin_comment
comment|/*  *	IRQ sub-tuple.  *	Byte 1:  *		0x0F - Irq number or mask bits  *		0x10 - IRQ mask values exist  *		0x20 - Level triggered interrupts  *		0x40 - Pulse triggered requests  *		0x80 - Interrupt sharing.  *	Byte 2-3: Interrupt req mask (if 0x10 of byte 1 set).  */
end_comment

begin_define
define|#
directive|define
name|CIS_IRQ_IRQN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xF)
end_define

begin_define
define|#
directive|define
name|CIS_IRQ_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|CIS_IRQ_LEVEL
value|0x20
end_define

begin_define
define|#
directive|define
name|CIS_IRQ_PULSE
value|0x40
end_define

begin_define
define|#
directive|define
name|CIS_IRQ_SHARING
value|0x80
end_define

begin_comment
comment|/*  *	Memory block subtuple. Depending on the features bits, the  *	following subtuples are used:  *	mem features == 1  *		Byte 1-2: upper 16 bits of 24 bit memory length.  *	mem features == 2  *		Byte 1-2: upper 16 bits of 24 bit memory length.  *		Byte 3-4: upper 16 bits of 24 bit memory address.  *	mem_features == 3  *		Byte 1:  *			0x07 - 0's numbered count of memory sub-tuples  *			0x18 - Memory length size (1's numbered)  *			0x60 - Memory address size (1's numbered)  *			0x80 - Host address value exists  *		Memory sub-tuples follow:  *			Byte 1-n: Memory length value (<< 8)  *			Byte n-n: Memory card address value (<< 8)  *			Byte n-n: Memory host address value (<< 8)  */
end_comment

begin_define
define|#
directive|define
name|CIS_FEAT_MEM_NONE
value|0
end_define

begin_comment
comment|/* No memory config */
end_comment

begin_define
define|#
directive|define
name|CIS_FEAT_MEM_LEN
value|1
end_define

begin_comment
comment|/* Just length */
end_comment

begin_define
define|#
directive|define
name|CIS_FEAT_MEM_ADDR
value|2
end_define

begin_comment
comment|/* Card address& length */
end_comment

begin_define
define|#
directive|define
name|CIS_FEAT_MEM_WIN
value|3
end_define

begin_comment
comment|/* Multiple windows */
end_comment

begin_define
define|#
directive|define
name|CIS_MEM_WINS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)+1)
end_define

begin_define
define|#
directive|define
name|CIS_MEM_LENSZ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x3)
end_define

begin_define
define|#
directive|define
name|CIS_MEM_ADDRSZ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x3)
end_define

begin_define
define|#
directive|define
name|CIS_MEM_HOST
value|0x80
end_define

begin_comment
comment|/*  *	Misc sub-tuple.  *	Byte 1:  *	Byte 2:  *		0x0c - DMA Request Signal  *                      00 - not support DMA  *                      01 - use SPKR# line  *                      10 - use IOIS16# line  *                      11 - use INPACK# line  *		0x10 - DMA Width  *                      0 - 8 bit DMA  *                      1 - 16 bit DMA  */
end_comment

begin_define
define|#
directive|define
name|CIS_MISC_DMA_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x10)>> 4)
end_define

begin_define
define|#
directive|define
name|CIS_MISC_DMA_REQ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCCARD_CIS_H */
end_comment

end_unit

