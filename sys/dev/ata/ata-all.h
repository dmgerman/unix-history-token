begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999,2000,2001 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATA register defines */
end_comment

begin_define
define|#
directive|define
name|ATA_DATA
value|0x00
end_define

begin_comment
comment|/* data register */
end_comment

begin_define
define|#
directive|define
name|ATA_ERROR
value|0x01
end_define

begin_comment
comment|/* (R) error register */
end_comment

begin_define
define|#
directive|define
name|ATA_E_NM
value|0x02
end_define

begin_comment
comment|/* no media */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ABORT
value|0x04
end_define

begin_comment
comment|/* command aborted */
end_comment

begin_define
define|#
directive|define
name|ATA_E_MCR
value|0x08
end_define

begin_comment
comment|/* media change request */
end_comment

begin_define
define|#
directive|define
name|ATA_E_IDNF
value|0x10
end_define

begin_comment
comment|/* ID not found */
end_comment

begin_define
define|#
directive|define
name|ATA_E_MC
value|0x20
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|ATA_E_UNC
value|0x40
end_define

begin_comment
comment|/* uncorrectable data */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ICRC
value|0x80
end_define

begin_comment
comment|/* UDMA crc error */
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE
value|0x01
end_define

begin_comment
comment|/* (W) feature register */
end_comment

begin_define
define|#
directive|define
name|ATA_F_DMA
value|0x01
end_define

begin_comment
comment|/* enable DMA */
end_comment

begin_define
define|#
directive|define
name|ATA_F_OVL
value|0x02
end_define

begin_comment
comment|/* enable overlap */
end_comment

begin_define
define|#
directive|define
name|ATA_COUNT
value|0x02
end_define

begin_comment
comment|/* (W) sector count */
end_comment

begin_define
define|#
directive|define
name|ATA_IREASON
value|0x02
end_define

begin_comment
comment|/* (R) interrupt reason */
end_comment

begin_define
define|#
directive|define
name|ATA_I_CMD
value|0x01
end_define

begin_comment
comment|/* cmd (1) | data (0) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_IN
value|0x02
end_define

begin_comment
comment|/* read (1) | write (0) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_RELEASE
value|0x04
end_define

begin_comment
comment|/* released bus (1) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_TAGMASK
value|0xf8
end_define

begin_comment
comment|/* tag mask */
end_comment

begin_define
define|#
directive|define
name|ATA_SECTOR
value|0x03
end_define

begin_comment
comment|/* sector # */
end_comment

begin_define
define|#
directive|define
name|ATA_CYL_LSB
value|0x04
end_define

begin_comment
comment|/* cylinder# LSB */
end_comment

begin_define
define|#
directive|define
name|ATA_CYL_MSB
value|0x05
end_define

begin_comment
comment|/* cylinder# MSB */
end_comment

begin_define
define|#
directive|define
name|ATA_DRIVE
value|0x06
end_define

begin_comment
comment|/* Sector/Drive/Head register */
end_comment

begin_define
define|#
directive|define
name|ATA_D_LBA
value|0x40
end_define

begin_comment
comment|/* use LBA adressing */
end_comment

begin_define
define|#
directive|define
name|ATA_D_IBM
value|0xa0
end_define

begin_comment
comment|/* 512 byte sectors, ECC */
end_comment

begin_define
define|#
directive|define
name|ATA_CMD
value|0x07
end_define

begin_comment
comment|/* command register */
end_comment

begin_define
define|#
directive|define
name|ATA_C_NOP
value|0x00
end_define

begin_comment
comment|/* NOP command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_FLUSHQUEUE
value|0x00
end_define

begin_comment
comment|/* flush queued cmd's */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_AUTOPOLL
value|0x01
end_define

begin_comment
comment|/* start autopoll function */
end_comment

begin_define
define|#
directive|define
name|ATA_C_ATAPI_RESET
value|0x08
end_define

begin_comment
comment|/* reset ATAPI device */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ
value|0x20
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE
value|0x30
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_PACKET_CMD
value|0xa0
end_define

begin_comment
comment|/* packet command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_ATAPI_IDENTIFY
value|0xa1
end_define

begin_comment
comment|/* get ATAPI params*/
end_comment

begin_define
define|#
directive|define
name|ATA_C_SERVICE
value|0xa2
end_define

begin_comment
comment|/* service command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ_MUL
value|0xc4
end_define

begin_comment
comment|/* read multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_MUL
value|0xc5
end_define

begin_comment
comment|/* write multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_SET_MULTI
value|0xc6
end_define

begin_comment
comment|/* set multi size command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ_DMA_QUEUED
value|0xc7
end_define

begin_comment
comment|/* read w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ_DMA
value|0xc8
end_define

begin_comment
comment|/* read w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_DMA
value|0xca
end_define

begin_comment
comment|/* write w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_DMA_QUEUED
value|0xcc
end_define

begin_comment
comment|/* write w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_FLUSHCACHE
value|0xe7
end_define

begin_comment
comment|/* flush cache to disk */
end_comment

begin_define
define|#
directive|define
name|ATA_C_ATA_IDENTIFY
value|0xec
end_define

begin_comment
comment|/* get ATA params */
end_comment

begin_define
define|#
directive|define
name|ATA_C_SETFEATURES
value|0xef
end_define

begin_comment
comment|/* features command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_SETXFER
value|0x03
end_define

begin_comment
comment|/* set transfer mode */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_ENAB_WCACHE
value|0x02
end_define

begin_comment
comment|/* enable write cache */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_DIS_WCACHE
value|0x82
end_define

begin_comment
comment|/* disable write cache */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_ENAB_RCACHE
value|0xaa
end_define

begin_comment
comment|/* enable readahead cache */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_DIS_RCACHE
value|0x55
end_define

begin_comment
comment|/* disable readahead cache */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_ENAB_RELIRQ
value|0x5d
end_define

begin_comment
comment|/* enable release interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_DIS_RELIRQ
value|0xdd
end_define

begin_comment
comment|/* disable release interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_ENAB_SRVIRQ
value|0x5e
end_define

begin_comment
comment|/* enable service interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_C_F_DIS_SRVIRQ
value|0xde
end_define

begin_comment
comment|/* disable service interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_STATUS
value|0x07
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|ATA_S_ERROR
value|0x01
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|ATA_S_INDEX
value|0x02
end_define

begin_comment
comment|/* index */
end_comment

begin_define
define|#
directive|define
name|ATA_S_CORR
value|0x04
end_define

begin_comment
comment|/* data corrected */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DRQ
value|0x08
end_define

begin_comment
comment|/* data request */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DSC
value|0x10
end_define

begin_comment
comment|/* drive seek completed */
end_comment

begin_define
define|#
directive|define
name|ATA_S_SERVICE
value|0x10
end_define

begin_comment
comment|/* drive needs service */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DWF
value|0x20
end_define

begin_comment
comment|/* drive write fault */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DMA
value|0x20
end_define

begin_comment
comment|/* DMA ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_READY
value|0x40
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_BUSY
value|0x80
end_define

begin_comment
comment|/* busy */
end_comment

begin_define
define|#
directive|define
name|ATA_ALTOFFSET
value|0x206
end_define

begin_comment
comment|/* alternate registers offset */
end_comment

begin_define
define|#
directive|define
name|ATA_PCCARD_ALTOFFSET
value|0x0e
end_define

begin_comment
comment|/* do for PCCARD devices */
end_comment

begin_define
define|#
directive|define
name|ATA_ALTIOSIZE
value|0x01
end_define

begin_comment
comment|/* alternate registers size */
end_comment

begin_define
define|#
directive|define
name|ATA_A_IDS
value|0x02
end_define

begin_comment
comment|/* disable interrupts */
end_comment

begin_define
define|#
directive|define
name|ATA_A_RESET
value|0x04
end_define

begin_comment
comment|/* RESET controller */
end_comment

begin_define
define|#
directive|define
name|ATA_A_4BIT
value|0x08
end_define

begin_comment
comment|/* 4 head bits */
end_comment

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|ATA_MASTER
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_SLAVE
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_IOSIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_OP_FINISHED
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_OP_CONTINUES
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_DEV
parameter_list|(
name|device
parameter_list|)
value|((device == ATA_MASTER) ? 0 : 1)
end_define

begin_define
define|#
directive|define
name|ATA_PARAM
parameter_list|(
name|scp
parameter_list|,
name|device
parameter_list|)
value|(scp->dev_param[ATA_DEV(device)])
end_define

begin_comment
comment|/* busmaster DMA related defines */
end_comment

begin_define
define|#
directive|define
name|ATA_BM_OFFSET1
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_DMA_ENTRIES
value|256
end_define

begin_define
define|#
directive|define
name|ATA_DMA_EOT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATA_BMCMD_PORT
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_BMCMD_START_STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_BMCMD_WRITE_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_PORT
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_INTERRUPT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_DMA_MASTER
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_DMA_SLAVE
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_DMA_SIMPLEX
value|0x80
end_define

begin_define
define|#
directive|define
name|ATA_BMDTP_PORT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_BMIOSIZE
value|0x20
end_define

begin_comment
comment|/* structure for holding DMA address data */
end_comment

begin_struct
struct|struct
name|ata_dmaentry
block|{
name|u_int32_t
name|base
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* cpu    3 ms delay */
define|#
directive|define
name|ATAPI_DRQT_INTR
value|1
comment|/* intr  10 ms delay */
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
name|reserved161
index|[
literal|84
index|]
decl_stmt|;
name|u_int16_t
name|integrity
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing an ATA device */
end_comment

begin_struct
struct|struct
name|ata_softc
block|{
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* device handle */
name|int
name|channel
decl_stmt|;
comment|/* channel on this controller */
name|struct
name|resource
modifier|*
name|r_io
decl_stmt|;
comment|/* io addr resource handle */
name|struct
name|resource
modifier|*
name|r_altio
decl_stmt|;
comment|/* altio addr resource handle */
name|struct
name|resource
modifier|*
name|r_bmio
decl_stmt|;
comment|/* bmio addr resource handle */
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
comment|/* interrupt of this channel */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handle */
name|u_int32_t
name|ioaddr
decl_stmt|;
comment|/* physical port addr */
name|u_int32_t
name|altioaddr
decl_stmt|;
comment|/* physical alt port addr */
name|u_int32_t
name|bmaddr
decl_stmt|;
comment|/* physical bus master port */
name|u_int32_t
name|chiptype
decl_stmt|;
comment|/* pciid of controller chip */
name|u_int32_t
name|alignment
decl_stmt|;
comment|/* dma engine min alignment */
name|struct
name|ata_params
modifier|*
name|dev_param
index|[
literal|2
index|]
decl_stmt|;
comment|/* ptr to devices params */
name|void
modifier|*
name|dev_softc
index|[
literal|2
index|]
decl_stmt|;
comment|/* ptr to devices softc's */
name|int
name|mode
index|[
literal|2
index|]
decl_stmt|;
comment|/* transfer mode for devices */
define|#
directive|define
name|ATA_PIO
value|0x00
define|#
directive|define
name|ATA_PIO0
value|0x08
define|#
directive|define
name|ATA_PIO1
value|0x09
define|#
directive|define
name|ATA_PIO2
value|0x0a
define|#
directive|define
name|ATA_PIO3
value|0x0b
define|#
directive|define
name|ATA_PIO4
value|0x0c
define|#
directive|define
name|ATA_DMA
value|0x10
define|#
directive|define
name|ATA_WDMA2
value|0x22
define|#
directive|define
name|ATA_UDMA2
value|0x42
define|#
directive|define
name|ATA_UDMA4
value|0x44
define|#
directive|define
name|ATA_UDMA5
value|0x45
name|int
name|flags
decl_stmt|;
comment|/* controller flags */
define|#
directive|define
name|ATA_DMA_ACTIVE
value|0x01
define|#
directive|define
name|ATA_ATAPI_DMA_RO
value|0x02
define|#
directive|define
name|ATA_USE_16BIT
value|0x04
define|#
directive|define
name|ATA_NO_SLAVE
value|0x08
define|#
directive|define
name|ATA_ATTACHED
value|0x10
define|#
directive|define
name|ATA_QUEUED
value|0x20
name|int
name|devices
decl_stmt|;
comment|/* what is present */
define|#
directive|define
name|ATA_ATA_MASTER
value|0x01
define|#
directive|define
name|ATA_ATA_SLAVE
value|0x02
define|#
directive|define
name|ATA_ATAPI_MASTER
value|0x04
define|#
directive|define
name|ATA_ATAPI_SLAVE
value|0x08
name|u_int8_t
name|status
decl_stmt|;
comment|/* last controller status */
name|u_int8_t
name|error
decl_stmt|;
comment|/* last controller error */
name|int
name|active
decl_stmt|;
comment|/* active processing request */
define|#
directive|define
name|ATA_IDLE
value|0x0
define|#
directive|define
name|ATA_IMMEDIATE
value|0x1
define|#
directive|define
name|ATA_WAIT_INTR
value|0x2
define|#
directive|define
name|ATA_WAIT_READY
value|0x3
define|#
directive|define
name|ATA_ACTIVE
value|0x4
define|#
directive|define
name|ATA_ACTIVE_ATA
value|0x5
define|#
directive|define
name|ATA_ACTIVE_ATAPI
value|0x6
define|#
directive|define
name|ATA_REINITING
value|0x7
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ad_request
argument_list|)
name|ata_queue
expr_stmt|;
comment|/* head of ATA queue */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|atapi_request
argument_list|)
name|atapi_queue
expr_stmt|;
comment|/* head of ATAPI queue */
name|void
modifier|*
name|running
decl_stmt|;
comment|/* currently running request */
block|}
struct|;
end_struct

begin_comment
comment|/* externs */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|ata_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* public prototypes */
end_comment

begin_function_decl
name|void
name|ata_start
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_reset
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_reinit
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_wait
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_command
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_printf
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|ata_get_lun
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_free_lun
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ata_mode2str
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pio2mode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pmode
parameter_list|(
name|struct
name|ata_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_wmode
parameter_list|(
name|struct
name|ata_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_umode
parameter_list|(
name|struct
name|ata_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|NPCI
operator|>
literal|0
end_if

begin_function_decl
name|int
name|ata_find_dev
parameter_list|(
name|device_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|ata_dmaalloc
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_dmainit
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_dmasetup
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ata_dmaentry
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_dmastart
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ata_dmaentry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_dmastatus
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_dmadone
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

