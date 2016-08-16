begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2000, 2001, 2002, 2003  * Broadcom Corporation. All rights reserved.  *  * This software is furnished under license and may be used and   * copied only in accordance with the following terms and   * conditions.  Subject to these conditions, you may download,   * copy, install, use, modify and distribute modified or unmodified   * copies of this software in source and/or binary form.  No title   * or ownership is transferred hereby.  *  * 1) Any source code used, modified or distributed must reproduce and  *    retain this copyright notice and list of conditions as they appear in  *    the source file.  *  * 2) No right is granted to use any trade name, trademark, or logo of  *    Broadcom Corporation.  The "Broadcom Corporation" name may not be  *    used to endorse or promote products derived from this software  *    without the prior written permission of Broadcom Corporation.  *  * 3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR IMPLIED  *    WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED WARRANTIES OF  *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR  *    NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM BE LIABLE  *    FOR ANY DAMAGES WHATSOEVER, AND IN PARTICULAR, BROADCOM SHALL NOT BE  *    LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  *    OR OTHERWISE), EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *********************************************************************     *  Broadcom Common Firmware Environment (CFE)     *       *  IOCTL definitions			File: cfe_ioctl.h     *       *  IOCTL function numbers and I/O data structures.     *       *  Author:  Mitch Lichtenberg     *       ********************************************************************* */
end_comment

begin_comment
comment|/*  *********************************************************************     *  NVFAM and FLASH stuff     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_NVRAM_GETINFO
value|1
end_define

begin_comment
comment|/* return nvram_info_t */
end_comment

begin_define
define|#
directive|define
name|IOCTL_NVRAM_ERASE
value|2
end_define

begin_comment
comment|/* erase sector containing nvram_info_t area */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_ERASE_SECTOR
value|3
end_define

begin_comment
comment|/* erase an arbitrary sector */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_ERASE_ALL
value|4
end_define

begin_comment
comment|/* Erase the entire flash */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_WRITE_ALL
value|5
end_define

begin_comment
comment|/* write entire flash */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_GETINFO
value|6
end_define

begin_comment
comment|/* get flash device info */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_GETSECTORS
value|7
end_define

begin_comment
comment|/* get sector information */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_ERASE_RANGE
value|8
end_define

begin_comment
comment|/* erase range of bytes */
end_comment

begin_define
define|#
directive|define
name|IOCTL_NVRAM_UNLOCK
value|9
end_define

begin_comment
comment|/* allow r/w beyond logical end of device */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_PROTECT_RANGE
value|10
end_define

begin_comment
comment|/* Protect a group of sectors */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_UNPROTECT_RANGE
value|11
end_define

begin_comment
comment|/* unprotect a group of sectors */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_DATA_WIDTH_MODE
value|12
end_define

begin_comment
comment|/* switch flash and gen bus to support 8 or 16-bit mode I/Os */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_BURST_MODE
value|13
end_define

begin_comment
comment|/* configure gen bus for burst mode */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|flash_range_s
block|{
name|unsigned
name|int
name|range_base
decl_stmt|;
name|unsigned
name|int
name|range_length
decl_stmt|;
block|}
name|flash_range_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|flash_info_s
block|{
name|unsigned
name|long
name|long
name|flash_base
decl_stmt|;
comment|/* flash physical base address */
name|unsigned
name|int
name|flash_size
decl_stmt|;
comment|/* available device size in bytes */
name|unsigned
name|int
name|flash_type
decl_stmt|;
comment|/* type, from FLASH_TYPE below */
name|unsigned
name|int
name|flash_flags
decl_stmt|;
comment|/* Various flags (FLASH_FLAG_xxx) */
block|}
name|flash_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|flash_sector_s
block|{
name|int
name|flash_sector_idx
decl_stmt|;
name|int
name|flash_sector_status
decl_stmt|;
name|unsigned
name|int
name|flash_sector_offset
decl_stmt|;
name|unsigned
name|int
name|flash_sector_size
decl_stmt|;
block|}
name|flash_sector_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FLASH_SECTOR_OK
value|0
end_define

begin_define
define|#
directive|define
name|FLASH_SECTOR_INVALID
value|-1
end_define

begin_define
define|#
directive|define
name|FLASH_TYPE_UNKNOWN
value|0
end_define

begin_comment
comment|/* not sure what kind of flash */
end_comment

begin_define
define|#
directive|define
name|FLASH_TYPE_SRAM
value|1
end_define

begin_comment
comment|/* not flash: it's SRAM */
end_comment

begin_define
define|#
directive|define
name|FLASH_TYPE_ROM
value|2
end_define

begin_comment
comment|/* not flash: it's ROM */
end_comment

begin_define
define|#
directive|define
name|FLASH_TYPE_FLASH
value|3
end_define

begin_comment
comment|/* it's flash memory of some sort */
end_comment

begin_define
define|#
directive|define
name|FLASH_FLAG_NOERASE
value|1
end_define

begin_comment
comment|/* Byte-range writes supported, 					   Erasing is not necessary */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvram_info_s
block|{
name|int
name|nvram_offset
decl_stmt|;
comment|/* offset of environment area */
name|int
name|nvram_size
decl_stmt|;
comment|/* size of environment area */
name|int
name|nvram_eraseflg
decl_stmt|;
comment|/* true if we need to erase first */
block|}
name|nvram_info_t
typedef|;
end_typedef

begin_comment
comment|/*  *********************************************************************     *  Ethernet stuff     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_GETHWADDR
value|1
end_define

begin_comment
comment|/* Get hardware address (6bytes) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_SETHWADDR
value|2
end_define

begin_comment
comment|/* Set hardware address (6bytes) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_GETSPEED
value|3
end_define

begin_comment
comment|/* Get Speed and Media (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_SETSPEED
value|4
end_define

begin_comment
comment|/* Set Speed and Media (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_GETLINK
value|5
end_define

begin_comment
comment|/* get link status (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_GETLOOPBACK
value|7
end_define

begin_comment
comment|/* get loopback state */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_SETLOOPBACK
value|8
end_define

begin_comment
comment|/* set loopback state */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_SETPACKETFIFO
value|9
end_define

begin_comment
comment|/* set packet fifo mode (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_SETSTROBESIG
value|10
end_define

begin_comment
comment|/* set strobe signal (int) */
end_comment

begin_define
define|#
directive|define
name|ETHER_LOOPBACK_OFF
value|0
end_define

begin_comment
comment|/* no loopback */
end_comment

begin_define
define|#
directive|define
name|ETHER_LOOPBACK_INT
value|1
end_define

begin_comment
comment|/* Internal loopback */
end_comment

begin_define
define|#
directive|define
name|ETHER_LOOPBACK_EXT
value|2
end_define

begin_comment
comment|/* External loopback (through PHY) */
end_comment

begin_define
define|#
directive|define
name|ETHER_SPEED_AUTO
value|0
end_define

begin_comment
comment|/* Auto detect */
end_comment

begin_define
define|#
directive|define
name|ETHER_SPEED_UNKNOWN
value|0
end_define

begin_comment
comment|/* Speed not known (on link status) */
end_comment

begin_define
define|#
directive|define
name|ETHER_SPEED_10HDX
value|1
end_define

begin_comment
comment|/* 10MB hdx and fdx */
end_comment

begin_define
define|#
directive|define
name|ETHER_SPEED_10FDX
value|2
end_define

begin_define
define|#
directive|define
name|ETHER_SPEED_100HDX
value|3
end_define

begin_comment
comment|/* 100MB hdx and fdx */
end_comment

begin_define
define|#
directive|define
name|ETHER_SPEED_100FDX
value|4
end_define

begin_define
define|#
directive|define
name|ETHER_SPEED_1000HDX
value|5
end_define

begin_comment
comment|/* 1000MB hdx and fdx */
end_comment

begin_define
define|#
directive|define
name|ETHER_SPEED_1000FDX
value|6
end_define

begin_define
define|#
directive|define
name|ETHER_FIFO_8
value|0
end_define

begin_comment
comment|/* 8-bit packet fifo mode */
end_comment

begin_define
define|#
directive|define
name|ETHER_FIFO_16
value|1
end_define

begin_comment
comment|/* 16-bit packet fifo mode */
end_comment

begin_define
define|#
directive|define
name|ETHER_ETHER
value|2
end_define

begin_comment
comment|/* Standard ethernet mode */
end_comment

begin_define
define|#
directive|define
name|ETHER_STROBE_GMII
value|0
end_define

begin_comment
comment|/* GMII style strobe signal */
end_comment

begin_define
define|#
directive|define
name|ETHER_STROBE_ENCODED
value|1
end_define

begin_comment
comment|/* Encoded */
end_comment

begin_define
define|#
directive|define
name|ETHER_STROBE_SOP
value|2
end_define

begin_comment
comment|/* SOP flagged. Only in 8-bit mode*/
end_comment

begin_define
define|#
directive|define
name|ETHER_STROBE_EOP
value|3
end_define

begin_comment
comment|/* EOP flagged. Only in 8-bit mode*/
end_comment

begin_comment
comment|/*  *********************************************************************     *  Serial Ports     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SERIAL_SETSPEED
value|1
end_define

begin_comment
comment|/* get baud rate (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SERIAL_GETSPEED
value|2
end_define

begin_comment
comment|/* set baud rate (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SERIAL_SETFLOW
value|3
end_define

begin_comment
comment|/* Set Flow Control */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SERIAL_GETFLOW
value|4
end_define

begin_comment
comment|/* Get Flow Control */
end_comment

begin_define
define|#
directive|define
name|SERIAL_FLOW_NONE
value|0
end_define

begin_comment
comment|/* no flow control */
end_comment

begin_define
define|#
directive|define
name|SERIAL_FLOW_SOFTWARE
value|1
end_define

begin_comment
comment|/* software flow control (not impl) */
end_comment

begin_define
define|#
directive|define
name|SERIAL_FLOW_HARDWARE
value|2
end_define

begin_comment
comment|/* hardware flow control */
end_comment

begin_comment
comment|/*  *********************************************************************     *  Block device stuff     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_BLOCK_GETBLOCKSIZE
value|1
end_define

begin_comment
comment|/* get block size (int) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_BLOCK_GETTOTALBLOCKS
value|2
end_define

begin_comment
comment|/* get total bocks (long long) */
end_comment

begin_define
define|#
directive|define
name|IOCTL_BLOCK_GETDEVTYPE
value|3
end_define

begin_comment
comment|/* get device type (struct) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|blockdev_info_s
block|{
name|unsigned
name|long
name|long
name|blkdev_totalblocks
decl_stmt|;
name|unsigned
name|int
name|blkdev_blocksize
decl_stmt|;
name|unsigned
name|int
name|blkdev_devtype
decl_stmt|;
block|}
name|blockdev_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BLOCK_DEVTYPE_DISK
value|0
end_define

begin_define
define|#
directive|define
name|BLOCK_DEVTYPE_CDROM
value|1
end_define

end_unit

