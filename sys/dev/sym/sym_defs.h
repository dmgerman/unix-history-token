begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Device driver optimized for the Symbios/LSI 53C896/53C895A/53C1010   *  PCI-SCSI controllers.  *  *  Copyright (C) 1999-2001  Gerard Roudier<groudier@free.fr>  *  *  This driver also supports the following Symbios/LSI PCI-SCSI chips:  *	53C810A, 53C825A, 53C860, 53C875, 53C876, 53C885, 53C895,  *	53C810,  53C815,  53C825 and the 53C1510D is 53C8XX mode.  *  *    *  This driver for FreeBSD-CAM is derived from the Linux sym53c8xx driver.  *  Copyright (C) 1998-1999  Gerard Roudier  *  *  The sym53c8xx driver is derived from the ncr53c8xx driver that had been   *  a port of the FreeBSD ncr driver to Linux-1.2.13.  *  *  The original ncr driver has been written for 386bsd and FreeBSD by  *          Wolfgang Stanglmeier<wolf@cologne.de>  *          Stefan Esser<se@mi.Uni-Koeln.de>  *  Copyright (C) 1994  Wolfgang Stanglmeier  *  *  The initialisation code, and part of the code that addresses   *  FreeBSD-CAM services is based on the aic7xxx driver for FreeBSD-CAM   *  written by Justin T. Gibbs.  *  *  Other major contributions:  *  *  NVRAM detection and reading.  *  Copyright (C) 1997 Richard Waltham<dormouse@farsrobt.demon.co.uk>  *  *-----------------------------------------------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SYM_DEFS_H
end_define

begin_comment
comment|/*  *  Vendor.  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_NCR
value|0x1000
end_define

begin_comment
comment|/*  *  PCI device identifier of SYMBIOS chips.  */
end_comment

begin_define
define|#
directive|define
name|PCI_ID_SYM53C810
value|1
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C810AP
value|5
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C815
value|4
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C820
value|2
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C825
value|3
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C860
value|6
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C875
value|0xf
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C875_2
value|0x8f
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C885
value|0xd
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C895
value|0xc
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C896
value|0xb
end_define

begin_define
define|#
directive|define
name|PCI_ID_SYM53C895A
value|0x12
end_define

begin_define
define|#
directive|define
name|PCI_ID_LSI53C1010
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_ID_LSI53C1010_2
value|0x21
end_define

begin_define
define|#
directive|define
name|PCI_ID_LSI53C1510D
value|0xa
end_define

begin_comment
comment|/*  *	SYM53C8XX device features descriptor.  */
end_comment

begin_struct
struct|struct
name|sym_pci_chip
block|{
name|u_short
name|device_id
decl_stmt|;
name|unsigned
name|short
name|revision_id
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|u_char
name|burst_max
decl_stmt|;
comment|/* log-base-2 of max burst */
name|u_char
name|offset_max
decl_stmt|;
name|u_char
name|nr_divisor
decl_stmt|;
name|u_char
name|lp_probe_bit
decl_stmt|;
name|u_int
name|features
decl_stmt|;
define|#
directive|define
name|FE_LED0
value|(1<<0)
define|#
directive|define
name|FE_WIDE
value|(1<<1)
comment|/* Wide data transfers */
define|#
directive|define
name|FE_ULTRA
value|(1<<2)
comment|/* Ultra speed 20Mtrans/sec */
define|#
directive|define
name|FE_ULTRA2
value|(1<<3)
comment|/* Ultra 2 - 40 Mtrans/sec */
define|#
directive|define
name|FE_DBLR
value|(1<<4)
comment|/* Clock doubler present */
define|#
directive|define
name|FE_QUAD
value|(1<<5)
comment|/* Clock quadrupler present */
define|#
directive|define
name|FE_ERL
value|(1<<6)
comment|/* Enable read line */
define|#
directive|define
name|FE_CLSE
value|(1<<7)
comment|/* Cache line size enable */
define|#
directive|define
name|FE_WRIE
value|(1<<8)
comment|/* Write& Invalidate enable */
define|#
directive|define
name|FE_ERMP
value|(1<<9)
comment|/* Enable read multiple */
define|#
directive|define
name|FE_BOF
value|(1<<10)
comment|/* Burst opcode fetch */
define|#
directive|define
name|FE_DFS
value|(1<<11)
comment|/* DMA fifo size */
define|#
directive|define
name|FE_PFEN
value|(1<<12)
comment|/* Prefetch enable */
define|#
directive|define
name|FE_LDSTR
value|(1<<13)
comment|/* Load/Store supported */
define|#
directive|define
name|FE_RAM
value|(1<<14)
comment|/* On chip RAM present */
define|#
directive|define
name|FE_CLK80
value|(1<<15)
comment|/* Board clock is 80 MHz */
define|#
directive|define
name|FE_RAM8K
value|(1<<16)
comment|/* On chip RAM sized 8Kb */
define|#
directive|define
name|FE_64BIT
value|(1<<17)
comment|/* 64-bit PCI BUS interface */
define|#
directive|define
name|FE_IO256
value|(1<<18)
comment|/* Requires full 256 bytes in PCI space */
define|#
directive|define
name|FE_NOPM
value|(1<<19)
comment|/* Scripts handles phase mismatch */
define|#
directive|define
name|FE_LEDC
value|(1<<20)
comment|/* Hardware control of LED */
define|#
directive|define
name|FE_ULTRA3
value|(1<<21)
comment|/* Ultra 3 - 80 Mtrans/sec DT */
define|#
directive|define
name|FE_66MHZ
value|(1<<22)
comment|/* 66MHz PCI support */
define|#
directive|define
name|FE_CRC
value|(1<<23)
comment|/* CRC support */
define|#
directive|define
name|FE_DIFF
value|(1<<24)
comment|/* SCSI HVD support */
define|#
directive|define
name|FE_DFBC
value|(1<<25)
comment|/* Have DFBC register */
define|#
directive|define
name|FE_LCKFRQ
value|(1<<26)
comment|/* Have LCKFRQ */
define|#
directive|define
name|FE_C10
value|(1<<27)
comment|/* Various C10 core (mis)features */
define|#
directive|define
name|FE_U3EN
value|(1<<28)
comment|/* U3EN bit usable */
define|#
directive|define
name|FE_DAC
value|(1<<29)
comment|/* Support PCI DAC (64 bit addressing) */
define|#
directive|define
name|FE_CACHE_SET
value|(FE_ERL|FE_CLSE|FE_WRIE|FE_ERMP)
define|#
directive|define
name|FE_CACHE0_SET
value|(FE_CACHE_SET& ~FE_ERL)
define|#
directive|define
name|FE_SPECIAL_SET
value|(FE_CACHE_SET|FE_BOF|FE_DFS|FE_LDSTR|FE_PFEN|FE_RAM)
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Symbios NVRAM data format  */
end_comment

begin_define
define|#
directive|define
name|SYMBIOS_NVRAM_SIZE
value|368
end_define

begin_define
define|#
directive|define
name|SYMBIOS_NVRAM_ADDRESS
value|0x100
end_define

begin_struct
struct|struct
name|Symbios_nvram
block|{
comment|/* Header 6 bytes */
name|u_short
name|type
decl_stmt|;
comment|/* 0x0000 */
name|u_short
name|byte_count
decl_stmt|;
comment|/* excluding header/trailer */
name|u_short
name|checksum
decl_stmt|;
comment|/* Controller set up 20 bytes */
name|u_char
name|v_major
decl_stmt|;
comment|/* 0x00 */
name|u_char
name|v_minor
decl_stmt|;
comment|/* 0x30 */
name|u32
name|boot_crc
decl_stmt|;
name|u_short
name|flags
decl_stmt|;
define|#
directive|define
name|SYMBIOS_SCAM_ENABLE
value|(1)
define|#
directive|define
name|SYMBIOS_PARITY_ENABLE
value|(1<<1)
define|#
directive|define
name|SYMBIOS_VERBOSE_MSGS
value|(1<<2)
define|#
directive|define
name|SYMBIOS_CHS_MAPPING
value|(1<<3)
define|#
directive|define
name|SYMBIOS_NO_NVRAM
value|(1<<3)
comment|/* ??? */
name|u_short
name|flags1
decl_stmt|;
define|#
directive|define
name|SYMBIOS_SCAN_HI_LO
value|(1)
name|u_short
name|term_state
decl_stmt|;
define|#
directive|define
name|SYMBIOS_TERM_CANT_PROGRAM
value|(0)
define|#
directive|define
name|SYMBIOS_TERM_ENABLED
value|(1)
define|#
directive|define
name|SYMBIOS_TERM_DISABLED
value|(2)
name|u_short
name|rmvbl_flags
decl_stmt|;
define|#
directive|define
name|SYMBIOS_RMVBL_NO_SUPPORT
value|(0)
define|#
directive|define
name|SYMBIOS_RMVBL_BOOT_DEVICE
value|(1)
define|#
directive|define
name|SYMBIOS_RMVBL_MEDIA_INSTALLED
value|(2)
name|u_char
name|host_id
decl_stmt|;
name|u_char
name|num_hba
decl_stmt|;
comment|/* 0x04 */
name|u_char
name|num_devices
decl_stmt|;
comment|/* 0x10 */
name|u_char
name|max_scam_devices
decl_stmt|;
comment|/* 0x04 */
name|u_char
name|num_valid_scam_devices
decl_stmt|;
comment|/* 0x00 */
name|u_char
name|flags2
decl_stmt|;
define|#
directive|define
name|SYMBIOS_AVOID_BUS_RESET
value|(1<<2)
comment|/* Boot order 14 bytes * 4 */
struct|struct
name|Symbios_host
block|{
name|u_short
name|type
decl_stmt|;
comment|/* 4:8xx / 0:nok */
name|u_short
name|device_id
decl_stmt|;
comment|/* PCI device id */
name|u_short
name|vendor_id
decl_stmt|;
comment|/* PCI vendor id */
name|u_char
name|bus_nr
decl_stmt|;
comment|/* PCI bus number */
name|u_char
name|device_fn
decl_stmt|;
comment|/* PCI device/function number<< 3*/
name|u_short
name|word8
decl_stmt|;
name|u_short
name|flags
decl_stmt|;
define|#
directive|define
name|SYMBIOS_INIT_SCAN_AT_BOOT
value|(1)
name|u_short
name|io_port
decl_stmt|;
comment|/* PCI io_port address */
block|}
name|host
index|[
literal|4
index|]
struct|;
comment|/* Targets 8 bytes * 16 */
struct|struct
name|Symbios_target
block|{
name|u_char
name|flags
decl_stmt|;
define|#
directive|define
name|SYMBIOS_DISCONNECT_ENABLE
value|(1)
define|#
directive|define
name|SYMBIOS_SCAN_AT_BOOT_TIME
value|(1<<1)
define|#
directive|define
name|SYMBIOS_SCAN_LUNS
value|(1<<2)
define|#
directive|define
name|SYMBIOS_QUEUE_TAGS_ENABLED
value|(1<<3)
name|u_char
name|rsvd
decl_stmt|;
name|u_char
name|bus_width
decl_stmt|;
comment|/* 0x08/0x10 */
name|u_char
name|sync_offset
decl_stmt|;
name|u_short
name|sync_period
decl_stmt|;
comment|/* 4*period factor */
name|u_short
name|timeout
decl_stmt|;
block|}
name|target
index|[
literal|16
index|]
struct|;
comment|/* Scam table 8 bytes * 4 */
struct|struct
name|Symbios_scam
block|{
name|u_short
name|id
decl_stmt|;
name|u_short
name|method
decl_stmt|;
define|#
directive|define
name|SYMBIOS_SCAM_DEFAULT_METHOD
value|(0)
define|#
directive|define
name|SYMBIOS_SCAM_DONT_ASSIGN
value|(1)
define|#
directive|define
name|SYMBIOS_SCAM_SET_SPECIFIC_ID
value|(2)
define|#
directive|define
name|SYMBIOS_SCAM_USE_ORDER_GIVEN
value|(3)
name|u_short
name|status
decl_stmt|;
define|#
directive|define
name|SYMBIOS_SCAM_UNKNOWN
value|(0)
define|#
directive|define
name|SYMBIOS_SCAM_DEVICE_NOT_FOUND
value|(1)
define|#
directive|define
name|SYMBIOS_SCAM_ID_NOT_SET
value|(2)
define|#
directive|define
name|SYMBIOS_SCAM_ID_VALID
value|(3)
name|u_char
name|target_id
decl_stmt|;
name|u_char
name|rsvd
decl_stmt|;
block|}
name|scam
index|[
literal|4
index|]
struct|;
name|u_char
name|spare_devices
index|[
literal|15
operator|*
literal|8
index|]
decl_stmt|;
name|u_char
name|trailer
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0xfe 0xfe 0x00 0x00 0x00 0x00 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Symbios_nvram
name|Symbios_nvram
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Symbios_host
name|Symbios_host
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Symbios_target
name|Symbios_target
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Symbios_scam
name|Symbios_scam
typedef|;
end_typedef

begin_comment
comment|/*  *	Tekram NvRAM data format.  */
end_comment

begin_define
define|#
directive|define
name|TEKRAM_NVRAM_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|TEKRAM_93C46_NVRAM_ADDRESS
value|0
end_define

begin_define
define|#
directive|define
name|TEKRAM_24C16_NVRAM_ADDRESS
value|0x40
end_define

begin_struct
struct|struct
name|Tekram_nvram
block|{
struct|struct
name|Tekram_target
block|{
name|u_char
name|flags
decl_stmt|;
define|#
directive|define
name|TEKRAM_PARITY_CHECK
value|(1)
define|#
directive|define
name|TEKRAM_SYNC_NEGO
value|(1<<1)
define|#
directive|define
name|TEKRAM_DISCONNECT_ENABLE
value|(1<<2)
define|#
directive|define
name|TEKRAM_START_CMD
value|(1<<3)
define|#
directive|define
name|TEKRAM_TAGGED_COMMANDS
value|(1<<4)
define|#
directive|define
name|TEKRAM_WIDE_NEGO
value|(1<<5)
name|u_char
name|sync_index
decl_stmt|;
name|u_short
name|word2
decl_stmt|;
block|}
name|target
index|[
literal|16
index|]
struct|;
name|u_char
name|host_id
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
define|#
directive|define
name|TEKRAM_MORE_THAN_2_DRIVES
value|(1)
define|#
directive|define
name|TEKRAM_DRIVES_SUP_1GB
value|(1<<1)
define|#
directive|define
name|TEKRAM_RESET_ON_POWER_ON
value|(1<<2)
define|#
directive|define
name|TEKRAM_ACTIVE_NEGATION
value|(1<<3)
define|#
directive|define
name|TEKRAM_IMMEDIATE_SEEK
value|(1<<4)
define|#
directive|define
name|TEKRAM_SCAN_LUNS
value|(1<<5)
define|#
directive|define
name|TEKRAM_REMOVABLE_FLAGS
value|(3<<6)
comment|/* 0: disable; 1: boot device; 2:all */
name|u_char
name|boot_delay_index
decl_stmt|;
name|u_char
name|max_tags_index
decl_stmt|;
name|u_short
name|flags1
decl_stmt|;
define|#
directive|define
name|TEKRAM_F2_F6_ENABLED
value|(1)
name|u_short
name|spare
index|[
literal|29
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Tekram_nvram
name|Tekram_nvram
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Tekram_target
name|Tekram_target
typedef|;
end_typedef

begin_comment
comment|/*  *	SYM53C8XX IO register data structure.  */
end_comment

begin_struct
struct|struct
name|sym_reg
block|{
comment|/*00*/
name|u8
name|nc_scntl0
decl_stmt|;
comment|/* full arb., ena parity, par->ATN  */
comment|/*01*/
name|u8
name|nc_scntl1
decl_stmt|;
comment|/* no reset                         */
define|#
directive|define
name|ISCON
value|0x10
comment|/* connected to scsi		    */
define|#
directive|define
name|CRST
value|0x08
comment|/* force reset                      */
define|#
directive|define
name|IARB
value|0x02
comment|/* immediate arbitration            */
comment|/*02*/
name|u8
name|nc_scntl2
decl_stmt|;
comment|/* no disconnect expected           */
define|#
directive|define
name|SDU
value|0x80
comment|/* cmd: disconnect will raise error */
define|#
directive|define
name|CHM
value|0x40
comment|/* sta: chained mode                */
define|#
directive|define
name|WSS
value|0x08
comment|/* sta: wide scsi send           [W]*/
define|#
directive|define
name|WSR
value|0x01
comment|/* sta: wide scsi received       [W]*/
comment|/*03*/
name|u8
name|nc_scntl3
decl_stmt|;
comment|/* cnf system clock dependent       */
define|#
directive|define
name|EWS
value|0x08
comment|/* cmd: enable wide scsi         [W]*/
define|#
directive|define
name|ULTRA
value|0x80
comment|/* cmd: ULTRA enable                */
comment|/* bits 0-2, 7 rsvd for C1010       */
comment|/*04*/
name|u8
name|nc_scid
decl_stmt|;
comment|/* cnf host adapter scsi address    */
define|#
directive|define
name|RRE
value|0x40
comment|/* r/w:e enable response to resel.  */
define|#
directive|define
name|SRE
value|0x20
comment|/* r/w:e enable response to select  */
comment|/*05*/
name|u8
name|nc_sxfer
decl_stmt|;
comment|/* ### Sync speed and count         */
comment|/* bits 6-7 rsvd for C1010          */
comment|/*06*/
name|u8
name|nc_sdid
decl_stmt|;
comment|/* ### Destination-ID               */
comment|/*07*/
name|u8
name|nc_gpreg
decl_stmt|;
comment|/* ??? IO-Pins                      */
comment|/*08*/
name|u8
name|nc_sfbr
decl_stmt|;
comment|/* ### First byte received          */
comment|/*09*/
name|u8
name|nc_socl
decl_stmt|;
define|#
directive|define
name|CREQ
value|0x80
comment|/* r/w: SCSI-REQ                    */
define|#
directive|define
name|CACK
value|0x40
comment|/* r/w: SCSI-ACK                    */
define|#
directive|define
name|CBSY
value|0x20
comment|/* r/w: SCSI-BSY                    */
define|#
directive|define
name|CSEL
value|0x10
comment|/* r/w: SCSI-SEL                    */
define|#
directive|define
name|CATN
value|0x08
comment|/* r/w: SCSI-ATN                    */
define|#
directive|define
name|CMSG
value|0x04
comment|/* r/w: SCSI-MSG                    */
define|#
directive|define
name|CC_D
value|0x02
comment|/* r/w: SCSI-C_D                    */
define|#
directive|define
name|CI_O
value|0x01
comment|/* r/w: SCSI-I_O                    */
comment|/*0a*/
name|u8
name|nc_ssid
decl_stmt|;
comment|/*0b*/
name|u8
name|nc_sbcl
decl_stmt|;
comment|/*0c*/
name|u8
name|nc_dstat
decl_stmt|;
define|#
directive|define
name|DFE
value|0x80
comment|/* sta: dma fifo empty              */
define|#
directive|define
name|MDPE
value|0x40
comment|/* int: master data parity error    */
define|#
directive|define
name|BF
value|0x20
comment|/* int: script: bus fault           */
define|#
directive|define
name|ABRT
value|0x10
comment|/* int: script: command aborted     */
define|#
directive|define
name|SSI
value|0x08
comment|/* int: script: single step         */
define|#
directive|define
name|SIR
value|0x04
comment|/* int: script: interrupt instruct. */
define|#
directive|define
name|IID
value|0x01
comment|/* int: script: illegal instruct.   */
comment|/*0d*/
name|u8
name|nc_sstat0
decl_stmt|;
define|#
directive|define
name|ILF
value|0x80
comment|/* sta: data in SIDL register lsb   */
define|#
directive|define
name|ORF
value|0x40
comment|/* sta: data in SODR register lsb   */
define|#
directive|define
name|OLF
value|0x20
comment|/* sta: data in SODL register lsb   */
define|#
directive|define
name|AIP
value|0x10
comment|/* sta: arbitration in progress     */
define|#
directive|define
name|LOA
value|0x08
comment|/* sta: arbitration lost            */
define|#
directive|define
name|WOA
value|0x04
comment|/* sta: arbitration won             */
define|#
directive|define
name|IRST
value|0x02
comment|/* sta: scsi reset signal           */
define|#
directive|define
name|SDP
value|0x01
comment|/* sta: scsi parity signal          */
comment|/*0e*/
name|u8
name|nc_sstat1
decl_stmt|;
define|#
directive|define
name|FF3210
value|0xf0
comment|/* sta: bytes in the scsi fifo      */
comment|/*0f*/
name|u8
name|nc_sstat2
decl_stmt|;
define|#
directive|define
name|ILF1
value|0x80
comment|/* sta: data in SIDL register msb[W]*/
define|#
directive|define
name|ORF1
value|0x40
comment|/* sta: data in SODR register msb[W]*/
define|#
directive|define
name|OLF1
value|0x20
comment|/* sta: data in SODL register msb[W]*/
define|#
directive|define
name|DM
value|0x04
comment|/* sta: DIFFSENS mismatch (895/6 only) */
define|#
directive|define
name|LDSC
value|0x02
comment|/* sta: disconnect& reconnect      */
comment|/*10*/
name|u8
name|nc_dsa
decl_stmt|;
comment|/* --> Base page                    */
comment|/*11*/
name|u8
name|nc_dsa1
decl_stmt|;
comment|/*12*/
name|u8
name|nc_dsa2
decl_stmt|;
comment|/*13*/
name|u8
name|nc_dsa3
decl_stmt|;
comment|/*14*/
name|u8
name|nc_istat
decl_stmt|;
comment|/* --> Main Command and status      */
define|#
directive|define
name|CABRT
value|0x80
comment|/* cmd: abort current operation     */
define|#
directive|define
name|SRST
value|0x40
comment|/* mod: reset chip                  */
define|#
directive|define
name|SIGP
value|0x20
comment|/* r/w: message from host to script */
define|#
directive|define
name|SEM
value|0x10
comment|/* r/w: message between host + script  */
define|#
directive|define
name|CON
value|0x08
comment|/* sta: connected to scsi           */
define|#
directive|define
name|INTF
value|0x04
comment|/* sta: int on the fly (reset by wr)*/
define|#
directive|define
name|SIP
value|0x02
comment|/* sta: scsi-interrupt              */
define|#
directive|define
name|DIP
value|0x01
comment|/* sta: host/script interrupt       */
comment|/*15*/
name|u8
name|nc_istat1
decl_stmt|;
comment|/* 896 only */
comment|/*16*/
name|u8
name|nc_mbox0
decl_stmt|;
comment|/* 896 only */
comment|/*17*/
name|u8
name|nc_mbox1
decl_stmt|;
comment|/* 896 only */
comment|/*18*/
name|u8
name|nc_ctest0
decl_stmt|;
comment|/*19*/
name|u8
name|nc_ctest1
decl_stmt|;
comment|/*1a*/
name|u8
name|nc_ctest2
decl_stmt|;
define|#
directive|define
name|CSIGP
value|0x40
comment|/* bits 0-2,7 rsvd for C1010        */
comment|/*1b*/
name|u8
name|nc_ctest3
decl_stmt|;
define|#
directive|define
name|FLF
value|0x08
comment|/* cmd: flush dma fifo              */
define|#
directive|define
name|CLF
value|0x04
comment|/* cmd: clear dma fifo		    */
define|#
directive|define
name|FM
value|0x02
comment|/* mod: fetch pin mode              */
define|#
directive|define
name|WRIE
value|0x01
comment|/* mod: write and invalidate enable */
comment|/* bits 4-7 rsvd for C1010          */
comment|/*1c*/
name|u32
name|nc_temp
decl_stmt|;
comment|/* ### Temporary stack              */
comment|/*20*/
name|u8
name|nc_dfifo
decl_stmt|;
comment|/*21*/
name|u8
name|nc_ctest4
decl_stmt|;
define|#
directive|define
name|BDIS
value|0x80
comment|/* mod: burst disable               */
define|#
directive|define
name|MPEE
value|0x08
comment|/* mod: master parity error enable  */
comment|/*22*/
name|u8
name|nc_ctest5
decl_stmt|;
define|#
directive|define
name|DFS
value|0x20
comment|/* mod: dma fifo size               */
comment|/* bits 0-1, 3-7 rsvd for C1010     */
comment|/*23*/
name|u8
name|nc_ctest6
decl_stmt|;
comment|/*24*/
name|u32
name|nc_dbc
decl_stmt|;
comment|/* ### Byte count and command       */
comment|/*28*/
name|u32
name|nc_dnad
decl_stmt|;
comment|/* ### Next command register        */
comment|/*2c*/
name|u32
name|nc_dsp
decl_stmt|;
comment|/* --> Script Pointer               */
comment|/*30*/
name|u32
name|nc_dsps
decl_stmt|;
comment|/* --> Script pointer save/opcode#2 */
comment|/*34*/
name|u8
name|nc_scratcha
decl_stmt|;
comment|/* Temporary register a            */
comment|/*35*/
name|u8
name|nc_scratcha1
decl_stmt|;
comment|/*36*/
name|u8
name|nc_scratcha2
decl_stmt|;
comment|/*37*/
name|u8
name|nc_scratcha3
decl_stmt|;
comment|/*38*/
name|u8
name|nc_dmode
decl_stmt|;
define|#
directive|define
name|BL_2
value|0x80
comment|/* mod: burst length shift value +2 */
define|#
directive|define
name|BL_1
value|0x40
comment|/* mod: burst length shift value +1 */
define|#
directive|define
name|ERL
value|0x08
comment|/* mod: enable read line            */
define|#
directive|define
name|ERMP
value|0x04
comment|/* mod: enable read multiple        */
define|#
directive|define
name|BOF
value|0x02
comment|/* mod: burst op code fetch         */
comment|/*39*/
name|u8
name|nc_dien
decl_stmt|;
comment|/*3a*/
name|u8
name|nc_sbr
decl_stmt|;
comment|/*3b*/
name|u8
name|nc_dcntl
decl_stmt|;
comment|/* --> Script execution control     */
define|#
directive|define
name|CLSE
value|0x80
comment|/* mod: cache line size enable      */
define|#
directive|define
name|PFF
value|0x40
comment|/* cmd: pre-fetch flush             */
define|#
directive|define
name|PFEN
value|0x20
comment|/* mod: pre-fetch enable            */
define|#
directive|define
name|SSM
value|0x10
comment|/* mod: single step mode            */
define|#
directive|define
name|IRQM
value|0x08
comment|/* mod: irq mode (1 = totem pole !) */
define|#
directive|define
name|STD
value|0x04
comment|/* cmd: start dma mode              */
define|#
directive|define
name|IRQD
value|0x02
comment|/* mod: irq disable                 */
define|#
directive|define
name|NOCOM
value|0x01
comment|/* cmd: protect sfbr while reselect */
comment|/* bits 0-1 rsvd for C1010          */
comment|/*3c*/
name|u32
name|nc_adder
decl_stmt|;
comment|/*40*/
name|u16
name|nc_sien
decl_stmt|;
comment|/* -->: interrupt enable            */
comment|/*42*/
name|u16
name|nc_sist
decl_stmt|;
comment|/*<--: interrupt status            */
define|#
directive|define
name|SBMC
value|0x1000
comment|/* sta: SCSI Bus Mode Change (895/6 only) */
define|#
directive|define
name|STO
value|0x0400
comment|/* sta: timeout (select)            */
define|#
directive|define
name|GEN
value|0x0200
comment|/* sta: timeout (general)           */
define|#
directive|define
name|HTH
value|0x0100
comment|/* sta: timeout (handshake)         */
define|#
directive|define
name|MA
value|0x80
comment|/* sta: phase mismatch              */
define|#
directive|define
name|CMP
value|0x40
comment|/* sta: arbitration complete        */
define|#
directive|define
name|SEL
value|0x20
comment|/* sta: selected by another device  */
define|#
directive|define
name|RSL
value|0x10
comment|/* sta: reselected by another device*/
define|#
directive|define
name|SGE
value|0x08
comment|/* sta: gross error (over/underflow)*/
define|#
directive|define
name|UDC
value|0x04
comment|/* sta: unexpected disconnect       */
define|#
directive|define
name|RST
value|0x02
comment|/* sta: scsi bus reset detected     */
define|#
directive|define
name|PAR
value|0x01
comment|/* sta: scsi parity error           */
comment|/*44*/
name|u8
name|nc_slpar
decl_stmt|;
comment|/*45*/
name|u8
name|nc_swide
decl_stmt|;
comment|/*46*/
name|u8
name|nc_macntl
decl_stmt|;
comment|/*47*/
name|u8
name|nc_gpcntl
decl_stmt|;
comment|/*48*/
name|u8
name|nc_stime0
decl_stmt|;
comment|/* cmd: timeout for select&handshake*/
comment|/*49*/
name|u8
name|nc_stime1
decl_stmt|;
comment|/* cmd: timeout user defined        */
comment|/*4a*/
name|u16
name|nc_respid
decl_stmt|;
comment|/* sta: Reselect-IDs                */
comment|/*4c*/
name|u8
name|nc_stest0
decl_stmt|;
comment|/*4d*/
name|u8
name|nc_stest1
decl_stmt|;
define|#
directive|define
name|SCLK
value|0x80
comment|/* Use the PCI clock as SCSI clock	*/
define|#
directive|define
name|DBLEN
value|0x08
comment|/* clock doubler running		*/
define|#
directive|define
name|DBLSEL
value|0x04
comment|/* clock doubler selected		*/
comment|/*4e*/
name|u8
name|nc_stest2
decl_stmt|;
define|#
directive|define
name|ROF
value|0x40
comment|/* reset scsi offset (after gross error!) */
define|#
directive|define
name|EXT
value|0x02
comment|/* extended filtering                     */
comment|/*4f*/
name|u8
name|nc_stest3
decl_stmt|;
define|#
directive|define
name|TE
value|0x80
comment|/* c: tolerAnt enable */
define|#
directive|define
name|HSC
value|0x20
comment|/* c: Halt SCSI Clock */
define|#
directive|define
name|CSF
value|0x02
comment|/* c: clear scsi fifo */
comment|/*50*/
name|u16
name|nc_sidl
decl_stmt|;
comment|/* Lowlevel: latched from scsi data */
comment|/*52*/
name|u8
name|nc_stest4
decl_stmt|;
define|#
directive|define
name|SMODE
value|0xc0
comment|/* SCSI bus mode      (895/6 only) */
define|#
directive|define
name|SMODE_HVD
value|0x40
comment|/* High Voltage Differential       */
define|#
directive|define
name|SMODE_SE
value|0x80
comment|/* Single Ended                    */
define|#
directive|define
name|SMODE_LVD
value|0xc0
comment|/* Low Voltage Differential        */
define|#
directive|define
name|LCKFRQ
value|0x20
comment|/* Frequency Lock (895/6 only)     */
comment|/* bits 0-5 rsvd for C1010         */
comment|/*53*/
name|u8
name|nc_53_
decl_stmt|;
comment|/*54*/
name|u16
name|nc_sodl
decl_stmt|;
comment|/* Lowlevel: data out to scsi data  */
comment|/*56*/
name|u8
name|nc_ccntl0
decl_stmt|;
comment|/* Chip Control 0 (896)             */
define|#
directive|define
name|ENPMJ
value|0x80
comment|/* Enable Phase Mismatch Jump       */
define|#
directive|define
name|PMJCTL
value|0x40
comment|/* Phase Mismatch Jump Control      */
define|#
directive|define
name|ENNDJ
value|0x20
comment|/* Enable Non Data PM Jump          */
define|#
directive|define
name|DISFC
value|0x10
comment|/* Disable Auto FIFO Clear          */
define|#
directive|define
name|DILS
value|0x02
comment|/* Disable Internal Load/Store      */
define|#
directive|define
name|DPR
value|0x01
comment|/* Disable Pipe Req                 */
comment|/*57*/
name|u8
name|nc_ccntl1
decl_stmt|;
comment|/* Chip Control 1 (896)             */
define|#
directive|define
name|ZMOD
value|0x80
comment|/* High Impedance Mode              */
define|#
directive|define
name|DDAC
value|0x08
comment|/* Disable Dual Address Cycle       */
define|#
directive|define
name|XTIMOD
value|0x04
comment|/* 64-bit Table Ind. Indexing Mode  */
define|#
directive|define
name|EXTIBMV
value|0x02
comment|/* Enable 64-bit Table Ind. BMOV    */
define|#
directive|define
name|EXDBMV
value|0x01
comment|/* Enable 64-bit Direct BMOV        */
comment|/*58*/
name|u16
name|nc_sbdl
decl_stmt|;
comment|/* Lowlevel: data from scsi data    */
comment|/*5a*/
name|u16
name|nc_5a_
decl_stmt|;
comment|/*5c*/
name|u8
name|nc_scr0
decl_stmt|;
comment|/* Working register B               */
comment|/*5d*/
name|u8
name|nc_scr1
decl_stmt|;
comment|/*5e*/
name|u8
name|nc_scr2
decl_stmt|;
comment|/*5f*/
name|u8
name|nc_scr3
decl_stmt|;
comment|/*60*/
name|u8
name|nc_scrx
index|[
literal|64
index|]
decl_stmt|;
comment|/* Working register C-R             */
comment|/*a0*/
name|u32
name|nc_mmrs
decl_stmt|;
comment|/* Memory Move Read Selector        */
comment|/*a4*/
name|u32
name|nc_mmws
decl_stmt|;
comment|/* Memory Move Write Selector       */
comment|/*a8*/
name|u32
name|nc_sfs
decl_stmt|;
comment|/* Script Fetch Selector            */
comment|/*ac*/
name|u32
name|nc_drs
decl_stmt|;
comment|/* DSA Relative Selector            */
comment|/*b0*/
name|u32
name|nc_sbms
decl_stmt|;
comment|/* Static Block Move Selector       */
comment|/*b4*/
name|u32
name|nc_dbms
decl_stmt|;
comment|/* Dynamic Block Move Selector      */
comment|/*b8*/
name|u32
name|nc_dnad64
decl_stmt|;
comment|/* DMA Next Address 64              */
comment|/*bc*/
name|u16
name|nc_scntl4
decl_stmt|;
comment|/* C1010 only                       */
define|#
directive|define
name|U3EN
value|0x80
comment|/* Enable Ultra 3                   */
define|#
directive|define
name|AIPCKEN
value|0x40
comment|/* AIP checking enable              */
comment|/* Also enable AIP generation on C10-33*/
define|#
directive|define
name|XCLKH_DT
value|0x08
comment|/* Extra clock of data hold on DT edge */
define|#
directive|define
name|XCLKH_ST
value|0x04
comment|/* Extra clock of data hold on ST edge */
define|#
directive|define
name|XCLKS_DT
value|0x02
comment|/* Extra clock of data set  on DT edge */
define|#
directive|define
name|XCLKS_ST
value|0x01
comment|/* Extra clock of data set  on ST edge */
comment|/*be*/
name|u8
name|nc_aipcntl0
decl_stmt|;
comment|/* AIP Control 0 C1010 only         */
comment|/*bf*/
name|u8
name|nc_aipcntl1
decl_stmt|;
comment|/* AIP Control 1 C1010 only         */
define|#
directive|define
name|DISAIP
value|0x08
comment|/* Disable AIP generation C10-66 only  */
comment|/*c0*/
name|u32
name|nc_pmjad1
decl_stmt|;
comment|/* Phase Mismatch Jump Address 1    */
comment|/*c4*/
name|u32
name|nc_pmjad2
decl_stmt|;
comment|/* Phase Mismatch Jump Address 2    */
comment|/*c8*/
name|u8
name|nc_rbc
decl_stmt|;
comment|/* Remaining Byte Count             */
comment|/*c9*/
name|u8
name|nc_rbc1
decl_stmt|;
comment|/*ca*/
name|u8
name|nc_rbc2
decl_stmt|;
comment|/*cb*/
name|u8
name|nc_rbc3
decl_stmt|;
comment|/*cc*/
name|u8
name|nc_ua
decl_stmt|;
comment|/* Updated Address                  */
comment|/*cd*/
name|u8
name|nc_ua1
decl_stmt|;
comment|/*ce*/
name|u8
name|nc_ua2
decl_stmt|;
comment|/*cf*/
name|u8
name|nc_ua3
decl_stmt|;
comment|/*d0*/
name|u32
name|nc_esa
decl_stmt|;
comment|/* Entry Storage Address            */
comment|/*d4*/
name|u8
name|nc_ia
decl_stmt|;
comment|/* Instruction Address              */
comment|/*d5*/
name|u8
name|nc_ia1
decl_stmt|;
comment|/*d6*/
name|u8
name|nc_ia2
decl_stmt|;
comment|/*d7*/
name|u8
name|nc_ia3
decl_stmt|;
comment|/*d8*/
name|u32
name|nc_sbc
decl_stmt|;
comment|/* SCSI Byte Count (3 bytes only)   */
comment|/*dc*/
name|u32
name|nc_csbc
decl_stmt|;
comment|/* Cumulative SCSI Byte Count       */
comment|/* Following for C1010 only         */
comment|/*e0*/
name|u16
name|nc_crcpad
decl_stmt|;
comment|/* CRC Value                        */
comment|/*e2*/
name|u8
name|nc_crccntl0
decl_stmt|;
comment|/* CRC control register             */
define|#
directive|define
name|SNDCRC
value|0x10
comment|/* Send CRC Request                 */
comment|/*e3*/
name|u8
name|nc_crccntl1
decl_stmt|;
comment|/* CRC control register             */
comment|/*e4*/
name|u32
name|nc_crcdata
decl_stmt|;
comment|/* CRC data register                */
comment|/*e8*/
name|u32
name|nc_e8_
decl_stmt|;
comment|/*ec*/
name|u32
name|nc_ec_
decl_stmt|;
comment|/*f0*/
name|u16
name|nc_dfbc
decl_stmt|;
comment|/* DMA FIFO byte count              */
block|}
struct|;
end_struct

begin_comment
comment|/*-----------------------------------------------------------  *  *	Utility macros for the script.  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|REGJ
parameter_list|(
name|p
parameter_list|,
name|r
parameter_list|)
value|(offsetof(struct sym_reg, p ## r))
end_define

begin_define
define|#
directive|define
name|REG
parameter_list|(
name|r
parameter_list|)
value|REGJ (nc_, r)
end_define

begin_typedef
typedef|typedef
name|u32
name|symcmd
typedef|;
end_typedef

begin_comment
comment|/*-----------------------------------------------------------  *  *	SCSI phases  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_DATA_OUT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCR_DATA_IN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCR_COMMAND
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCR_STATUS
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SCR_DT_DATA_OUT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_DT_DATA_IN
value|0x05000000
end_define

begin_define
define|#
directive|define
name|SCR_MSG_OUT
value|0x06000000
end_define

begin_define
define|#
directive|define
name|SCR_MSG_IN
value|0x07000000
end_define

begin_comment
comment|/* DT phases are illegal for non Ultra3 mode */
end_comment

begin_define
define|#
directive|define
name|SCR_ILG_OUT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_ILG_IN
value|0x05000000
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	Data transfer via SCSI.  *  *-----------------------------------------------------------  *  *	MOVE_ABS (LEN)  *<<start address>>  *  *	MOVE_IND (LEN)  *<<dnad_offset>>  *  *	MOVE_TBL  *<<dnad_offset>>  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|OPC_MOVE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SCR_MOVE_ABS
parameter_list|(
name|l
parameter_list|)
value|((0x00000000 | OPC_MOVE) | (l))
end_define

begin_define
define|#
directive|define
name|SCR_MOVE_IND
parameter_list|(
name|l
parameter_list|)
value|((0x20000000 | OPC_MOVE) | (l))
end_define

begin_define
define|#
directive|define
name|SCR_MOVE_TBL
value|(0x10000000 | OPC_MOVE)
end_define

begin_define
define|#
directive|define
name|SCR_CHMOV_ABS
parameter_list|(
name|l
parameter_list|)
value|((0x00000000) | (l))
end_define

begin_define
define|#
directive|define
name|SCR_CHMOV_IND
parameter_list|(
name|l
parameter_list|)
value|((0x20000000) | (l))
end_define

begin_define
define|#
directive|define
name|SCR_CHMOV_TBL
value|(0x10000000)
end_define

begin_struct
struct|struct
name|sym_tblmove
block|{
name|u32
name|size
decl_stmt|;
name|u32
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*-----------------------------------------------------------  *  *	Selection  *  *-----------------------------------------------------------  *  *	SEL_ABS | SCR_ID (0..15)    [ | REL_JMP]  *<<alternate_address>>  *  *	SEL_TBL |<< dnad_offset>>  [ | REL_JMP]  *<<alternate_address>>  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_SEL_ABS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SCR_SEL_ABS_ATN
value|0x41000000
end_define

begin_define
define|#
directive|define
name|SCR_SEL_TBL
value|0x42000000
end_define

begin_define
define|#
directive|define
name|SCR_SEL_TBL_ATN
value|0x43000000
end_define

begin_struct
struct|struct
name|sym_tblsel
block|{
name|u_char
name|sel_scntl4
decl_stmt|;
comment|/* C1010 only */
name|u_char
name|sel_sxfer
decl_stmt|;
name|u_char
name|sel_id
decl_stmt|;
name|u_char
name|sel_scntl3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCR_JMP_REL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_ID
parameter_list|(
name|id
parameter_list|)
value|(((u32)(id))<< 16)
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	Waiting for Disconnect or Reselect  *  *-----------------------------------------------------------  *  *	WAIT_DISC  *	dummy:<<alternate_address>>  *  *	WAIT_RESEL  *<<alternate_address>>  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_WAIT_DISC
value|0x48000000
end_define

begin_define
define|#
directive|define
name|SCR_WAIT_RESEL
value|0x50000000
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	Bit Set / Reset  *  *-----------------------------------------------------------  *  *	SET (flags {|.. })  *  *	CLR (flags {|.. })  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_SET
parameter_list|(
name|f
parameter_list|)
value|(0x58000000 | (f))
end_define

begin_define
define|#
directive|define
name|SCR_CLR
parameter_list|(
name|f
parameter_list|)
value|(0x60000000 | (f))
end_define

begin_define
define|#
directive|define
name|SCR_CARRY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCR_TRG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCR_ACK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SCR_ATN
value|0x00000008
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	Memory to memory move  *  *-----------------------------------------------------------  *  *	COPY (bytecount)  *<< source_address>>  *<< destination_address>>  *  *	SCR_COPY   sets the NO FLUSH option by default.  *	SCR_COPY_F does not set this option.  *  *	For chips which do not support this option,  *	sym_copy_and_bind() will remove this bit.  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_NO_FLUSH
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCR_COPY
parameter_list|(
name|n
parameter_list|)
value|(0xc0000000 | SCR_NO_FLUSH | (n))
end_define

begin_define
define|#
directive|define
name|SCR_COPY_F
parameter_list|(
name|n
parameter_list|)
value|(0xc0000000 | (n))
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	Register move and binary operations  *  *-----------------------------------------------------------  *  *	SFBR_REG (reg, op, data)        reg  = SFBR op data  *<< 0>>  *  *	REG_SFBR (reg, op, data)        SFBR = reg op data  *<< 0>>  *  *	REG_REG  (reg, op, data)        reg  = reg op data  *<< 0>>  *  *-----------------------------------------------------------  *  *	On 825A, 875, 895 and 896 chips the content   *	of SFBR register can be used as data (SCR_SFBR_DATA).  *	The 896 has additionnal IO registers starting at   *	offset 0x80. Bit 7 of register offset is stored in   *	bit 7 of the SCRIPTS instruction first DWORD.  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_REG_OFS
parameter_list|(
name|ofs
parameter_list|)
value|((((ofs)& 0x7f)<< 16ul) + ((ofs)& 0x80))
end_define

begin_define
define|#
directive|define
name|SCR_SFBR_REG
parameter_list|(
name|reg
parameter_list|,
name|op
parameter_list|,
name|data
parameter_list|)
define|\
value|(0x68000000 | (SCR_REG_OFS(REG(reg))) | (op) | (((data)&0xff)<<8ul))
end_define

begin_define
define|#
directive|define
name|SCR_REG_SFBR
parameter_list|(
name|reg
parameter_list|,
name|op
parameter_list|,
name|data
parameter_list|)
define|\
value|(0x70000000 | (SCR_REG_OFS(REG(reg))) | (op) | (((data)&0xff)<<8ul))
end_define

begin_define
define|#
directive|define
name|SCR_REG_REG
parameter_list|(
name|reg
parameter_list|,
name|op
parameter_list|,
name|data
parameter_list|)
define|\
value|(0x78000000 | (SCR_REG_OFS(REG(reg))) | (op) | (((data)&0xff)<<8ul))
end_define

begin_define
define|#
directive|define
name|SCR_LOAD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCR_SHL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCR_OR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCR_XOR
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SCR_AND
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_SHR
value|0x05000000
end_define

begin_define
define|#
directive|define
name|SCR_ADD
value|0x06000000
end_define

begin_define
define|#
directive|define
name|SCR_ADDC
value|0x07000000
end_define

begin_define
define|#
directive|define
name|SCR_SFBR_DATA
value|(0x00800000>>8ul)
end_define

begin_comment
comment|/* Use SFBR as data */
end_comment

begin_comment
comment|/*-----------------------------------------------------------  *  *	FROM_REG (reg)		  SFBR = reg  *<< 0>>  *  *	TO_REG	 (reg)		  reg  = SFBR  *<< 0>>  *  *	LOAD_REG (reg, data)	  reg  =<data>  *<< 0>>  *  *	LOAD_SFBR(data) 	  SFBR =<data>  *<< 0>>  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_FROM_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|SCR_REG_SFBR(reg,SCR_OR,0)
end_define

begin_define
define|#
directive|define
name|SCR_TO_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|SCR_SFBR_REG(reg,SCR_OR,0)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_REG
parameter_list|(
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|SCR_REG_REG(reg,SCR_LOAD,data)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_SFBR
parameter_list|(
name|data
parameter_list|)
define|\
value|(SCR_REG_SFBR (gpreg, SCR_LOAD, data))
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	LOAD  from memory   to register.  *	STORE from register to memory.  *  *	Only supported by 810A, 860, 825A, 875, 895 and 896.  *  *-----------------------------------------------------------  *  *	LOAD_ABS (LEN)  *<<start address>>  *  *	LOAD_REL (LEN)        (DSA relative)  *<<dsa_offset>>  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_REG_OFS2
parameter_list|(
name|ofs
parameter_list|)
value|(((ofs)& 0xff)<< 16ul)
end_define

begin_define
define|#
directive|define
name|SCR_NO_FLUSH2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCR_DSA_REL2
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_R
parameter_list|(
name|reg
parameter_list|,
name|how
parameter_list|,
name|n
parameter_list|)
define|\
value|(0xe1000000 | how | (SCR_REG_OFS2(REG(reg))) | (n))
end_define

begin_define
define|#
directive|define
name|SCR_STORE_R
parameter_list|(
name|reg
parameter_list|,
name|how
parameter_list|,
name|n
parameter_list|)
define|\
value|(0xe0000000 | how | (SCR_REG_OFS2(REG(reg))) | (n))
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_ABS
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_LOAD_R(reg, SCR_NO_FLUSH2, n)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_REL
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_LOAD_R(reg, SCR_NO_FLUSH2|SCR_DSA_REL2, n)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_ABS_F
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_LOAD_R(reg, 0, n)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_REL_F
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_LOAD_R(reg, SCR_DSA_REL2, n)
end_define

begin_define
define|#
directive|define
name|SCR_STORE_ABS
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_STORE_R(reg, SCR_NO_FLUSH2, n)
end_define

begin_define
define|#
directive|define
name|SCR_STORE_REL
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_STORE_R(reg, SCR_NO_FLUSH2|SCR_DSA_REL2,n)
end_define

begin_define
define|#
directive|define
name|SCR_STORE_ABS_F
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_STORE_R(reg, 0, n)
end_define

begin_define
define|#
directive|define
name|SCR_STORE_REL_F
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|SCR_STORE_R(reg, SCR_DSA_REL2, n)
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	Waiting for Disconnect or Reselect  *  *-----------------------------------------------------------  *  *	JUMP            [ | IFTRUE/IFFALSE ( ... ) ]  *<<address>>  *  *	JUMPR           [ | IFTRUE/IFFALSE ( ... ) ]  *<<distance>>  *  *	CALL            [ | IFTRUE/IFFALSE ( ... ) ]  *<<address>>  *  *	CALLR           [ | IFTRUE/IFFALSE ( ... ) ]  *<<distance>>  *  *	RETURN          [ | IFTRUE/IFFALSE ( ... ) ]  *<<dummy>>  *  *	INT             [ | IFTRUE/IFFALSE ( ... ) ]  *<<ident>>  *  *	INT_FLY         [ | IFTRUE/IFFALSE ( ... ) ]  *<<ident>>  *  *	Conditions:  *	     WHEN (phase)  *	     IF   (phase)  *	     CARRYSET  *	     DATA (data, mask)  *  *-----------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|SCR_NO_OP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SCR_JUMP
value|0x80080000
end_define

begin_define
define|#
directive|define
name|SCR_JUMP64
value|0x80480000
end_define

begin_define
define|#
directive|define
name|SCR_JUMPR
value|0x80880000
end_define

begin_define
define|#
directive|define
name|SCR_CALL
value|0x88080000
end_define

begin_define
define|#
directive|define
name|SCR_CALLR
value|0x88880000
end_define

begin_define
define|#
directive|define
name|SCR_RETURN
value|0x90080000
end_define

begin_define
define|#
directive|define
name|SCR_INT
value|0x98080000
end_define

begin_define
define|#
directive|define
name|SCR_INT_FLY
value|0x98180000
end_define

begin_define
define|#
directive|define
name|IFFALSE
parameter_list|(
name|arg
parameter_list|)
value|(0x00080000 | (arg))
end_define

begin_define
define|#
directive|define
name|IFTRUE
parameter_list|(
name|arg
parameter_list|)
value|(0x00000000 | (arg))
end_define

begin_define
define|#
directive|define
name|WHEN
parameter_list|(
name|phase
parameter_list|)
value|(0x00030000 | (phase))
end_define

begin_define
define|#
directive|define
name|IF
parameter_list|(
name|phase
parameter_list|)
value|(0x00020000 | (phase))
end_define

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|D
parameter_list|)
value|(0x00040000 | ((D)& 0xff))
end_define

begin_define
define|#
directive|define
name|MASK
parameter_list|(
name|D
parameter_list|,
name|M
parameter_list|)
value|(0x00040000 | (((M ^ 0xff)& 0xff)<< 8ul)|((D)& 0xff))
end_define

begin_define
define|#
directive|define
name|CARRYSET
value|(0x00200000)
end_define

begin_comment
comment|/*-----------------------------------------------------------  *  *	SCSI  constants.  *  *-----------------------------------------------------------  */
end_comment

begin_comment
comment|/*  *	Messages  */
end_comment

begin_define
define|#
directive|define
name|M_COMPLETE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|M_EXTENDED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|M_SAVE_DP
value|(0x02)
end_define

begin_define
define|#
directive|define
name|M_RESTORE_DP
value|(0x03)
end_define

begin_define
define|#
directive|define
name|M_DISCONNECT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|M_ID_ERROR
value|(0x05)
end_define

begin_define
define|#
directive|define
name|M_ABORT
value|(0x06)
end_define

begin_define
define|#
directive|define
name|M_REJECT
value|(0x07)
end_define

begin_define
define|#
directive|define
name|M_NOOP
value|(0x08)
end_define

begin_define
define|#
directive|define
name|M_PARITY
value|(0x09)
end_define

begin_define
define|#
directive|define
name|M_LCOMPLETE
value|(0x0a)
end_define

begin_define
define|#
directive|define
name|M_FCOMPLETE
value|(0x0b)
end_define

begin_define
define|#
directive|define
name|M_RESET
value|(0x0c)
end_define

begin_define
define|#
directive|define
name|M_ABORT_TAG
value|(0x0d)
end_define

begin_define
define|#
directive|define
name|M_CLEAR_QUEUE
value|(0x0e)
end_define

begin_define
define|#
directive|define
name|M_INIT_REC
value|(0x0f)
end_define

begin_define
define|#
directive|define
name|M_REL_REC
value|(0x10)
end_define

begin_define
define|#
directive|define
name|M_TERMINATE
value|(0x11)
end_define

begin_define
define|#
directive|define
name|M_SIMPLE_TAG
value|(0x20)
end_define

begin_define
define|#
directive|define
name|M_HEAD_TAG
value|(0x21)
end_define

begin_define
define|#
directive|define
name|M_ORDERED_TAG
value|(0x22)
end_define

begin_define
define|#
directive|define
name|M_IGN_RESIDUE
value|(0x23)
end_define

begin_define
define|#
directive|define
name|M_IDENTIFY
value|(0x80)
end_define

begin_define
define|#
directive|define
name|M_X_MODIFY_DP
value|(0x00)
end_define

begin_define
define|#
directive|define
name|M_X_SYNC_REQ
value|(0x01)
end_define

begin_define
define|#
directive|define
name|M_X_WIDE_REQ
value|(0x03)
end_define

begin_define
define|#
directive|define
name|M_X_PPR_REQ
value|(0x04)
end_define

begin_comment
comment|/*  *	PPR protocol options  */
end_comment

begin_define
define|#
directive|define
name|PPR_OPT_IU
value|(0x01)
end_define

begin_define
define|#
directive|define
name|PPR_OPT_DT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|PPR_OPT_QAS
value|(0x04)
end_define

begin_define
define|#
directive|define
name|PPR_OPT_MASK
value|(0x07)
end_define

begin_comment
comment|/*  *	Status  */
end_comment

begin_define
define|#
directive|define
name|S_GOOD
value|(0x00)
end_define

begin_define
define|#
directive|define
name|S_CHECK_COND
value|(0x02)
end_define

begin_define
define|#
directive|define
name|S_COND_MET
value|(0x04)
end_define

begin_define
define|#
directive|define
name|S_BUSY
value|(0x08)
end_define

begin_define
define|#
directive|define
name|S_INT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|S_INT_COND_MET
value|(0x14)
end_define

begin_define
define|#
directive|define
name|S_CONFLICT
value|(0x18)
end_define

begin_define
define|#
directive|define
name|S_TERMINATED
value|(0x20)
end_define

begin_define
define|#
directive|define
name|S_QUEUE_FULL
value|(0x28)
end_define

begin_define
define|#
directive|define
name|S_ILLEGAL
value|(0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SYM_DEFS_H */
end_comment

end_unit

