begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ATA_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ATA_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* ATA/ATAPI device parameter information */
end_comment

begin_struct
struct|struct
name|ata_params
block|{
name|u_int8_t
name|cmdsize
range|:
literal|2
decl_stmt|;
comment|/* packet command size */
define|#
directive|define
name|ATAPI_PSIZE_12
value|0
comment|/* 12 bytes */
define|#
directive|define
name|ATAPI_PSIZE_16
value|1
comment|/* 16 bytes */
name|u_int8_t
label|:
literal|3
expr_stmt|;
name|u_int8_t
name|drqtype
range|:
literal|2
decl_stmt|;
comment|/* DRQ type */
define|#
directive|define
name|ATAPI_DRQT_MPROC
value|0
comment|/* cpu	  3 ms delay */
define|#
directive|define
name|ATAPI_DRQT_INTR
value|1
comment|/* intr	 10 ms delay */
define|#
directive|define
name|ATAPI_DRQT_ACCEL
value|2
comment|/* accel 50 us delay */
name|u_int8_t
name|removable
range|:
literal|1
decl_stmt|;
comment|/* device is removable */
name|u_int8_t
name|device_type
range|:
literal|5
decl_stmt|;
comment|/* device type */
define|#
directive|define
name|ATAPI_TYPE_DIRECT
value|0
comment|/* disk/floppy */
define|#
directive|define
name|ATAPI_TYPE_TAPE
value|1
comment|/* streaming tape */
define|#
directive|define
name|ATAPI_TYPE_CDROM
value|5
comment|/* CD-ROM device */
define|#
directive|define
name|ATAPI_TYPE_OPTICAL
value|7
comment|/* optical disk */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|proto
range|:
literal|2
decl_stmt|;
comment|/* command protocol */
define|#
directive|define
name|ATAPI_PROTO_ATAPI
value|2
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* number of cylinders */
name|u_int16_t
name|reserved2
decl_stmt|;
name|u_int16_t
name|heads
decl_stmt|;
comment|/* # heads */
name|u_int16_t
name|unfbytespertrk
decl_stmt|;
comment|/* # unformatted bytes/track */
name|u_int16_t
name|unfbytes
decl_stmt|;
comment|/* # unformatted bytes/sector */
name|u_int16_t
name|sectors
decl_stmt|;
comment|/* # sectors/track */
name|u_int16_t
name|vendorunique0
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|serial
index|[
literal|20
index|]
decl_stmt|;
comment|/* serial number */
name|u_int16_t
name|buffertype
decl_stmt|;
comment|/* buffer type */
define|#
directive|define
name|ATA_BT_SINGLEPORTSECTOR
value|1
comment|/* 1 port, 1 sector buffer */
define|#
directive|define
name|ATA_BT_DUALPORTMULTI
value|2
comment|/* 2 port, mult sector buffer */
define|#
directive|define
name|ATA_BT_DUALPORTMULTICACHE
value|3
comment|/* above plus track cache */
name|u_int16_t
name|buffersize
decl_stmt|;
comment|/* buf size, 512-byte units */
name|u_int16_t
name|necc
decl_stmt|;
comment|/* ecc bytes appended */
name|u_int8_t
name|revision
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware revision */
name|u_int8_t
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* model name */
name|u_int8_t
name|nsecperint
decl_stmt|;
comment|/* sectors per interrupt */
name|u_int8_t
name|vendorunique1
decl_stmt|;
name|u_int16_t
name|usedmovsd
decl_stmt|;
comment|/* double word read/write? */
name|u_int8_t
name|vendorcap
decl_stmt|;
comment|/* vendor capabilities */
name|u_int8_t
name|dmaflag
range|:
literal|1
decl_stmt|;
comment|/* DMA supported - always 1 */
name|u_int8_t
name|lbaflag
range|:
literal|1
decl_stmt|;
comment|/* LBA supported - always 1 */
name|u_int8_t
name|iordydis
range|:
literal|1
decl_stmt|;
comment|/* IORDY may be disabled */
name|u_int8_t
name|iordyflag
range|:
literal|1
decl_stmt|;
comment|/* IORDY supported */
name|u_int8_t
name|softreset
range|:
literal|1
decl_stmt|;
comment|/* needs softreset when busy */
name|u_int8_t
name|stdby_ovlap
range|:
literal|1
decl_stmt|;
comment|/* standby/overlap supported */
name|u_int8_t
name|queueing
range|:
literal|1
decl_stmt|;
comment|/* supports queuing overlap */
name|u_int8_t
name|idmaflag
range|:
literal|1
decl_stmt|;
comment|/* interleaved DMA supported */
name|u_int16_t
name|capvalidate
decl_stmt|;
comment|/* validation for above */
name|u_int8_t
name|vendorunique3
decl_stmt|;
name|u_int8_t
name|opiomode
decl_stmt|;
comment|/* PIO modes 0-2 */
name|u_int8_t
name|vendorunique4
decl_stmt|;
name|u_int8_t
name|odmamode
decl_stmt|;
comment|/* old DMA modes, not ATA-3 */
name|u_int16_t
name|atavalid
decl_stmt|;
comment|/* fields valid */
define|#
directive|define
name|ATA_FLAG_54_58
value|1
comment|/* words 54-58 valid */
define|#
directive|define
name|ATA_FLAG_64_70
value|2
comment|/* words 64-70 valid */
define|#
directive|define
name|ATA_FLAG_88
value|4
comment|/* word 88 valid */
name|u_int16_t
name|currcyls
decl_stmt|;
name|u_int16_t
name|currheads
decl_stmt|;
name|u_int16_t
name|currsectors
decl_stmt|;
name|u_int16_t
name|currsize0
decl_stmt|;
name|u_int16_t
name|currsize1
decl_stmt|;
name|u_int8_t
name|currmultsect
decl_stmt|;
name|u_int8_t
name|multsectvalid
decl_stmt|;
name|u_int32_t
name|lbasize
decl_stmt|;
name|u_int16_t
name|sdmamodes
decl_stmt|;
comment|/* singleword DMA modes */
name|u_int16_t
name|wdmamodes
decl_stmt|;
comment|/* multiword DMA modes */
name|u_int16_t
name|apiomodes
decl_stmt|;
comment|/* advanced PIO modes */
name|u_int16_t
name|mwdmamin
decl_stmt|;
comment|/* min. M/W DMA time/word ns */
name|u_int16_t
name|mwdmarec
decl_stmt|;
comment|/* rec. M/W DMA time ns */
name|u_int16_t
name|pioblind
decl_stmt|;
comment|/* min. PIO cycle w/o flow */
name|u_int16_t
name|pioiordy
decl_stmt|;
comment|/* min. PIO cycle IORDY flow */
name|u_int16_t
name|reserved69
decl_stmt|;
name|u_int16_t
name|reserved70
decl_stmt|;
name|u_int16_t
name|rlsovlap
decl_stmt|;
comment|/* rel time (us) for overlap */
name|u_int16_t
name|rlsservice
decl_stmt|;
comment|/* rel time (us) for service */
name|u_int16_t
name|reserved73
decl_stmt|;
name|u_int16_t
name|reserved74
decl_stmt|;
name|u_int16_t
name|queuelen
range|:
literal|5
decl_stmt|;
name|u_int16_t
label|:
literal|11
expr_stmt|;
name|u_int16_t
name|reserved76
decl_stmt|;
name|u_int16_t
name|reserved77
decl_stmt|;
name|u_int16_t
name|reserved78
decl_stmt|;
name|u_int16_t
name|reserved79
decl_stmt|;
name|u_int16_t
name|versmajor
decl_stmt|;
name|u_int16_t
name|versminor
decl_stmt|;
name|u_int16_t
name|featsupp1
decl_stmt|;
comment|/* 82 */
name|u_int16_t
name|supmicrocode
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|supqueued
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|supcfa
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|supapm
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|suprmsn
range|:
literal|1
decl_stmt|;
name|u_int16_t
label|:
literal|11
expr_stmt|;
name|u_int16_t
name|featsupp3
decl_stmt|;
comment|/* 84 */
name|u_int16_t
name|featenab1
decl_stmt|;
comment|/* 85 */
name|u_int16_t
name|enabmicrocode
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|enabqueued
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|enabcfa
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|enabapm
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|enabrmsn
range|:
literal|1
decl_stmt|;
name|u_int16_t
label|:
literal|11
expr_stmt|;
name|u_int16_t
name|featenab3
decl_stmt|;
comment|/* 87 */
name|u_int16_t
name|udmamodes
decl_stmt|;
comment|/* UltraDMA modes */
name|u_int16_t
name|erasetime
decl_stmt|;
name|u_int16_t
name|enherasetime
decl_stmt|;
name|u_int16_t
name|apmlevel
decl_stmt|;
name|u_int16_t
name|masterpasswdrev
decl_stmt|;
name|u_int16_t
name|masterhwres
range|:
literal|8
decl_stmt|;
name|u_int16_t
name|slavehwres
range|:
literal|5
decl_stmt|;
name|u_int16_t
name|cblid
range|:
literal|1
decl_stmt|;
name|u_int16_t
name|reserved93_1415
range|:
literal|2
decl_stmt|;
name|u_int16_t
name|reserved94
index|[
literal|32
index|]
decl_stmt|;
name|u_int16_t
name|rmvstat
decl_stmt|;
name|u_int16_t
name|securstat
decl_stmt|;
name|u_int16_t
name|reserved129
index|[
literal|30
index|]
decl_stmt|;
name|u_int16_t
name|cfapwrmode
decl_stmt|;
name|u_int16_t
name|reserved160
index|[
literal|85
index|]
decl_stmt|;
name|u_int16_t
name|integrity
decl_stmt|;
name|u_int16_t
name|reserved246
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATA_MODE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATA_DMA_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|ATA_PIO
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_PIO0
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_PIO1
value|0x09
end_define

begin_define
define|#
directive|define
name|ATA_PIO2
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATA_PIO3
value|0x0b
end_define

begin_define
define|#
directive|define
name|ATA_PIO4
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATA_DMA
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_WDMA
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_WDMA2
value|0x22
end_define

begin_define
define|#
directive|define
name|ATA_UDMA
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_UDMA2
value|0x42
end_define

begin_define
define|#
directive|define
name|ATA_UDMA4
value|0x44
end_define

begin_define
define|#
directive|define
name|ATA_UDMA5
value|0x45
end_define

begin_struct
struct|struct
name|ata_cmd
block|{
name|int
name|channel
decl_stmt|;
name|int
name|device
decl_stmt|;
name|int
name|cmd
decl_stmt|;
define|#
directive|define
name|ATAGPARM
value|1
define|#
directive|define
name|ATAGMODE
value|2
define|#
directive|define
name|ATASMODE
value|3
define|#
directive|define
name|ATAREINIT
value|4
define|#
directive|define
name|ATAATTACH
value|5
define|#
directive|define
name|ATADETACH
value|6
define|#
directive|define
name|ATAPICMD
value|7
union|union
block|{
struct|struct
block|{
name|int
name|mode
index|[
literal|2
index|]
decl_stmt|;
block|}
name|mode
struct|;
struct|struct
block|{
name|int
name|type
index|[
literal|2
index|]
decl_stmt|;
name|char
name|name
index|[
literal|2
index|]
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|ata_params
name|params
index|[
literal|2
index|]
decl_stmt|;
block|}
name|param
struct|;
struct|struct
block|{
name|char
name|ccb
index|[
literal|16
index|]
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATAPI_CMD_CTRL
value|0x00
define|#
directive|define
name|ATAPI_CMD_READ
value|0x01
define|#
directive|define
name|ATAPI_CMD_WRITE
value|0x02
name|int
name|timeout
decl_stmt|;
name|int
name|error
decl_stmt|;
name|char
name|sense_data
index|[
literal|18
index|]
decl_stmt|;
block|}
name|atapi
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCATA
value|_IOWR('a',  1, struct ata_cmd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ATA_H_ */
end_comment

end_unit

