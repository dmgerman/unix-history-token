begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2003 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ATA_E_ILI
value|0x01
end_define

begin_comment
comment|/* illegal length */
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
name|ATA_E_MASK
value|0x0f
end_define

begin_comment
comment|/* error mask */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_MASK
value|0xf0
end_define

begin_comment
comment|/* sense key mask */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_NO_SENSE
value|0x00
end_define

begin_comment
comment|/* no specific sense key info */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_RECOVERED_ERROR
value|0x10
end_define

begin_comment
comment|/* command OK, data recovered */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_NOT_READY
value|0x20
end_define

begin_comment
comment|/* no access to drive */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_MEDIUM_ERROR
value|0x30
end_define

begin_comment
comment|/* non-recovered data error */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_HARDWARE_ERROR
value|0x40
end_define

begin_comment
comment|/* non-recoverable HW failure */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_ILLEGAL_REQUEST
value|0x50
end_define

begin_comment
comment|/* invalid command param(s) */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_UNIT_ATTENTION
value|0x60
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_DATA_PROTECT
value|0x70
end_define

begin_comment
comment|/* write protect */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_BLANK_CHECK
value|0x80
end_define

begin_comment
comment|/* blank check */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_VENDOR_SPECIFIC
value|0x90
end_define

begin_comment
comment|/* vendor specific skey */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_COPY_ABORTED
value|0xa0
end_define

begin_comment
comment|/* copy aborted */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_ABORTED_COMMAND
value|0xb0
end_define

begin_comment
comment|/* command aborted, try again */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_EQUAL
value|0xc0
end_define

begin_comment
comment|/* equal */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_VOLUME_OVERFLOW
value|0xd0
end_define

begin_comment
comment|/* volume overflow */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_MISCOMPARE
value|0xe0
end_define

begin_comment
comment|/* data dont match the medium */
end_comment

begin_define
define|#
directive|define
name|ATA_SK_RESERVED
value|0xf0
end_define

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
comment|/* use LBA addressing */
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
name|ATA_ALTSTAT
value|0x08
end_define

begin_comment
comment|/* alternate status register */
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
name|ATA_PC98_ALTOFFSET
value|0x10c
end_define

begin_comment
comment|/* do for PC98 devices */
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
comment|/* ATAPI misc defines */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MAGIC_LSB
value|0x14
end_define

begin_define
define|#
directive|define
name|ATAPI_MAGIC_MSB
value|0xeb
end_define

begin_define
define|#
directive|define
name|ATAPI_P_READ
value|(ATA_S_DRQ | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_WRITE
value|(ATA_S_DRQ)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_CMDOUT
value|(ATA_S_DRQ | ATA_I_CMD)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONEDRQ
value|(ATA_S_DRQ | ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONE
value|(ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_ABORT
value|0
end_define

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|ATA_PRIMARY
value|0x1f0
end_define

begin_define
define|#
directive|define
name|ATA_SECONDARY
value|0x170
end_define

begin_define
define|#
directive|define
name|ATA_PC98_BANK
value|0x432
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
name|ATA_PC98_IOSIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_ALTIOSIZE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_BMIOSIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_PC98_BANKIOSIZE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_IOADDR_RID
value|0
end_define

begin_define
define|#
directive|define
name|ATA_ALTADDR_RID
value|1
end_define

begin_define
define|#
directive|define
name|ATA_BMADDR_RID
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_PC98_ALTADDR_RID
value|8
end_define

begin_define
define|#
directive|define
name|ATA_PC98_BANKADDR_RID
value|9
end_define

begin_define
define|#
directive|define
name|ATA_IRQ_RID
value|0
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

begin_comment
comment|/* busmaster DMA related defines */
end_comment

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
value|0x09
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
name|ATA_BMCTL_PORT
value|0x09
end_define

begin_define
define|#
directive|define
name|ATA_BMDEVSPEC_0
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_PORT
value|0x0b
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
name|ATA_BMDEVSPEC_1
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATA_BMDTP_PORT
value|0x0d
end_define

begin_define
define|#
directive|define
name|ATA_IDX_ADDR
value|0x0e
end_define

begin_define
define|#
directive|define
name|ATA_IDX_DATA
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATA_MAX_RES
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_INTR_FLAGS
value|(INTR_MPSAFE|INTR_TYPE_BIO|INTR_ENTROPY)
end_define

begin_define
define|#
directive|define
name|ATA_OP_CONTINUES
value|0
end_define

begin_define
define|#
directive|define
name|ATA_OP_FINISHED
value|1
end_define

begin_struct
struct|struct
name|ata_request
block|{
name|struct
name|ata_device
modifier|*
name|device
decl_stmt|;
comment|/* ptr to device softc */
name|void
modifier|*
name|driver
decl_stmt|;
comment|/* driver specific */
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
comment|/* command reg */
name|u_int8_t
name|feature
decl_stmt|;
comment|/* feature reg */
name|u_int64_t
name|lba
decl_stmt|;
comment|/* lba reg */
name|u_int16_t
name|count
decl_stmt|;
comment|/* count reg */
block|}
name|ata
struct|;
struct|struct
block|{
name|u_int8_t
name|ccb
index|[
literal|16
index|]
decl_stmt|;
comment|/* ATAPI command block */
block|}
name|atapi
struct|;
block|}
name|u
union|;
name|u_int8_t
name|status
decl_stmt|;
comment|/* ATA status */
name|u_int8_t
name|error
decl_stmt|;
comment|/* ATA error */
name|u_int8_t
name|dmastat
decl_stmt|;
comment|/* DMA status */
name|u_int32_t
name|bytecount
decl_stmt|;
comment|/* bytes to transfer */
name|u_int32_t
name|transfersize
decl_stmt|;
comment|/* bytes pr transfer */
name|u_int32_t
name|donecount
decl_stmt|;
comment|/* bytes transferred */
name|caddr_t
name|data
decl_stmt|;
comment|/* pointer to data buf */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATA_R_DONE
value|0x0001
define|#
directive|define
name|ATA_R_CONTROL
value|0x0002
define|#
directive|define
name|ATA_R_READ
value|0x0004
define|#
directive|define
name|ATA_R_WRITE
value|0x0008
define|#
directive|define
name|ATA_R_ATAPI
value|0x0010
define|#
directive|define
name|ATA_R_QUIET
value|0x0020
define|#
directive|define
name|ATA_R_DMA
value|0x0040
define|#
directive|define
name|ATA_R_ORDERED
value|0x0100
define|#
directive|define
name|ATA_R_AT_HEAD
value|0x0200
define|#
directive|define
name|ATA_R_REQUEUE
value|0x0400
define|#
directive|define
name|ATA_R_SKIPSTART
value|0x0800
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
name|int
name|retries
decl_stmt|;
comment|/* retry count */
name|int
name|timeout
decl_stmt|;
comment|/* timeout for this cmd */
name|struct
name|callout_handle
name|timeout_handle
decl_stmt|;
comment|/* handle for untimeout */
name|int
name|result
decl_stmt|;
comment|/* result error code */
name|struct
name|task
name|task
decl_stmt|;
comment|/* task management */
name|TAILQ_ENTRY
argument_list|(
argument|ata_request
argument_list|)
name|sequence
expr_stmt|;
comment|/* sequence management */
name|TAILQ_ENTRY
argument_list|(
argument|ata_request
argument_list|)
name|chain
expr_stmt|;
comment|/* list management */
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing an ATA/ATAPI device */
end_comment

begin_struct
struct|struct
name|ata_device
block|{
name|struct
name|ata_channel
modifier|*
name|channel
decl_stmt|;
name|int
name|unit
decl_stmt|;
comment|/* unit number */
define|#
directive|define
name|ATA_MASTER
value|0x00
define|#
directive|define
name|ATA_SLAVE
value|0x10
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device name */
name|struct
name|ata_params
modifier|*
name|param
decl_stmt|;
comment|/* ata param structure */
name|void
modifier|*
name|softc
decl_stmt|;
comment|/* ptr to softc for device */
name|void
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATA_D_USE_CHS
value|0x0001
define|#
directive|define
name|ATA_D_DETACHING
value|0x0002
define|#
directive|define
name|ATA_D_MEDIA_CHANGED
value|0x0004
define|#
directive|define
name|ATA_D_ENC_PRESENT
value|0x0008
name|int
name|cmd
decl_stmt|;
comment|/* last cmd executed */
name|int
name|mode
decl_stmt|;
comment|/* transfermode */
name|void
function_decl|(
modifier|*
name|setmode
function_decl|)
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

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
comment|/* structure holding DMA related information */
end_comment

begin_struct
struct|struct
name|ata_dma
block|{
name|bus_dma_tag_t
name|dmatag
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|cdmatag
decl_stmt|;
comment|/* control DMA tag */
name|bus_dmamap_t
name|cdmamap
decl_stmt|;
comment|/* control DMA map */
name|bus_dma_tag_t
name|ddmatag
decl_stmt|;
comment|/* data DMA tag */
name|bus_dmamap_t
name|ddmamap
decl_stmt|;
comment|/* data DMA map */
name|struct
name|ata_dmaentry
modifier|*
name|dmatab
decl_stmt|;
comment|/* DMA transfer table */
name|bus_addr_t
name|mdmatab
decl_stmt|;
comment|/* bus address of dmatab */
name|u_int32_t
name|alignment
decl_stmt|;
comment|/* DMA engine alignment */
name|u_int32_t
name|max_iosize
decl_stmt|;
comment|/* DMA engine max IO size */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATA_DMA_ACTIVE
value|0x01
comment|/* DMA transfer in progress */
define|#
directive|define
name|ATA_DMA_READ
value|0x02
comment|/* transaction is a read */
name|int
function_decl|(
modifier|*
name|alloc
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|free
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setup
function_decl|)
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int32_t
name|count
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int32_t
name|count
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|stop
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure holding lowlevel functions */
end_comment

begin_struct
struct|struct
name|ata_lowlevel
block|{
name|void
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|transaction
function_decl|)
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|interrupt
function_decl|)
parameter_list|(
name|void
modifier|*
name|channel
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure holding resources for an ATA channel */
end_comment

begin_struct
struct|struct
name|ata_resource
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing an ATA channel */
end_comment

begin_struct
struct|struct
name|ata_channel
block|{
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* device handle */
name|int
name|unit
decl_stmt|;
comment|/* channel number */
name|struct
name|ata_resource
name|r_io
index|[
name|ATA_MAX_RES
index|]
decl_stmt|;
comment|/* I/O resources */
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
name|struct
name|ata_lowlevel
name|hw
decl_stmt|;
comment|/* lowlevel HW functions */
name|struct
name|ata_dma
modifier|*
name|dma
decl_stmt|;
comment|/* DMA data / functions */
name|int
name|flags
decl_stmt|;
comment|/* channel flags */
define|#
directive|define
name|ATA_NO_SLAVE
value|0x01
define|#
directive|define
name|ATA_USE_16BIT
value|0x02
define|#
directive|define
name|ATA_USE_PC98GEOM
value|0x04
define|#
directive|define
name|ATA_ATAPI_DMA_RO
value|0x08
define|#
directive|define
name|ATA_48BIT_ACTIVE
value|0x10
name|struct
name|ata_device
name|device
index|[
literal|2
index|]
decl_stmt|;
comment|/* devices on this channel */
define|#
directive|define
name|MASTER
value|0x00
define|#
directive|define
name|SLAVE
value|0x01
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
name|int
name|state
decl_stmt|;
comment|/* ATA channel state control */
define|#
directive|define
name|ATA_IDLE
value|0x0000
define|#
directive|define
name|ATA_ACTIVE
value|0x0001
define|#
directive|define
name|ATA_CONTROL
value|0x0002
name|void
function_decl|(
modifier|*
name|locking
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
define|#
directive|define
name|ATA_LF_LOCK
value|0x0001
define|#
directive|define
name|ATA_LF_UNLOCK
value|0x0002
name|struct
name|mtx
name|queue_mtx
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ata_request
argument_list|)
name|ata_queue
expr_stmt|;
comment|/* head of ATA queue */
name|void
modifier|*
name|running
decl_stmt|;
comment|/* currently running request */
block|}
struct|;
end_struct

begin_comment
comment|/* ATAPI request sense structure */
end_comment

begin_struct
struct|struct
name|atapi_sense
block|{
name|u_int8_t
name|error_code
range|:
literal|7
decl_stmt|;
comment|/* current or deferred errors */
name|u_int8_t
name|valid
range|:
literal|1
decl_stmt|;
comment|/* follows ATAPI spec */
name|u_int8_t
name|segment
decl_stmt|;
comment|/* Segment number */
name|u_int8_t
name|sense_key
range|:
literal|4
decl_stmt|;
comment|/* sense key */
name|u_int8_t
name|reserved2_4
range|:
literal|1
decl_stmt|;
comment|/* reserved */
name|u_int8_t
name|ili
range|:
literal|1
decl_stmt|;
comment|/* incorrect length indicator */
name|u_int8_t
name|eom
range|:
literal|1
decl_stmt|;
comment|/* end of medium */
name|u_int8_t
name|filemark
range|:
literal|1
decl_stmt|;
comment|/* filemark */
name|u_int32_t
name|cmd_info
name|__packed
decl_stmt|;
comment|/* cmd information */
name|u_int8_t
name|sense_length
decl_stmt|;
comment|/* additional sense len (n-7) */
name|u_int32_t
name|cmd_specific_info
name|__packed
decl_stmt|;
comment|/* additional cmd spec info */
name|u_int8_t
name|asc
decl_stmt|;
comment|/* additional sense code */
name|u_int8_t
name|ascq
decl_stmt|;
comment|/* additional sense code qual */
name|u_int8_t
name|replaceable_unit_code
decl_stmt|;
comment|/* replaceable unit code */
name|u_int8_t
name|sk_specific
range|:
literal|7
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sksv
range|:
literal|1
decl_stmt|;
comment|/* sense key specific info OK */
name|u_int8_t
name|sk_specific1
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sk_specific2
decl_stmt|;
comment|/* sense key specific */
block|}
struct|;
end_struct

begin_comment
comment|/* disk bay/enclosure related */
end_comment

begin_define
define|#
directive|define
name|ATA_LED_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_LED_RED
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_LED_GREEN
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_LED_ORANGE
value|0x03
end_define

begin_define
define|#
directive|define
name|ATA_LED_MASK
value|0x03
end_define

begin_comment
comment|/* externs */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|ata_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intr_config_hook
modifier|*
name|ata_delayed_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ata_dma
decl_stmt|,
name|ata_wc
decl_stmt|,
name|atapi_dma
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* public prototypes */
end_comment

begin_comment
comment|/* ata-all.c: */
end_comment

begin_function_decl
name|int
name|ata_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_printf
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|,
name|int
name|device
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
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
name|ata_prtdev
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ata_set_name
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_free_name
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_get_lun
parameter_list|(
name|u_int32_t
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_test_lun
parameter_list|(
name|u_int32_t
modifier|*
name|map
parameter_list|,
name|int
name|lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_free_lun
parameter_list|(
name|u_int32_t
modifier|*
name|map
parameter_list|,
name|int
name|lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ata_mode2str
parameter_list|(
name|int
name|mode
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
name|ap
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
name|ap
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
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_limit_mode
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|maxmode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ata-queue.c: */
end_comment

begin_function_decl
name|int
name|ata_reinit
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_start
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ata_request
modifier|*
name|ata_alloc_request
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_free_request
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_controlcmd
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
name|u_int8_t
name|command
parameter_list|,
name|u_int16_t
name|feature
parameter_list|,
name|u_int64_t
name|lba
parameter_list|,
name|u_int16_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_atapicmd
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|,
name|u_int8_t
modifier|*
name|ccb
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_queue_request
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_finish
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ata_cmd2str
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ata-lowlevel.c: */
end_comment

begin_function_decl
name|void
name|ata_generic_hw
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* subdrivers */
end_comment

begin_function_decl
name|void
name|ad_attach
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acd_attach
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afd_attach
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ast_attach
parameter_list|(
name|struct
name|ata_device
modifier|*
name|atadev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_cam_attach_bus
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_cam_detach_bus
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_cam_reinit_bus
parameter_list|(
name|struct
name|ata_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* macros for locking a channel */
end_comment

begin_define
define|#
directive|define
name|ATA_LOCK_CH
parameter_list|(
name|ch
parameter_list|,
name|value
parameter_list|)
define|\
value|atomic_cmpset_acq_int(&(ch)->state, ATA_IDLE, (value))
end_define

begin_define
define|#
directive|define
name|ATA_SLEEPLOCK_CH
parameter_list|(
name|ch
parameter_list|,
name|value
parameter_list|)
define|\
value|while (!atomic_cmpset_acq_int(&(ch)->state, ATA_IDLE, (value))) \ 	    tsleep((caddr_t)&(ch), PRIBIO, "atalck", 1);
end_define

begin_define
define|#
directive|define
name|ATA_FORCELOCK_CH
parameter_list|(
name|ch
parameter_list|,
name|value
parameter_list|)
value|atomic_store_rel_int(&(ch)->state, (value))
end_define

begin_define
define|#
directive|define
name|ATA_UNLOCK_CH
parameter_list|(
name|ch
parameter_list|)
value|atomic_store_rel_int(&(ch)->state, ATA_IDLE)
end_define

begin_comment
comment|/* macros to hide busspace uglyness */
end_comment

begin_define
define|#
directive|define
name|ATA_INB
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_1(rman_get_bustag((res)), \ 			 rman_get_bushandle((res)), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_2(rman_get_bustag((res)), \ 			 rman_get_bushandle((res)), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4(rman_get_bustag((res)), \ 			 rman_get_bushandle((res)), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INSW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_2(rman_get_bustag((res)), \ 			       rman_get_bushandle((res)), \ 			       (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSW_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_stream_2(rman_get_bustag((res)), \ 				      rman_get_bushandle((res)), \ 				      (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_4(rman_get_bustag((res)), \ 			       rman_get_bushandle((res)), \ 			       (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSL_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_stream_4(rman_get_bustag((res)), \ 				      rman_get_bushandle((res)), \ 				      (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTB
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1(rman_get_bustag((res)), \ 			  rman_get_bushandle((res)), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2(rman_get_bustag((res)), \ 			  rman_get_bushandle((res)), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4(rman_get_bustag((res)), \ 			  rman_get_bushandle((res)), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_2(rman_get_bustag((res)), \ 				rman_get_bushandle((res)), \ 				(offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSW_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_stream_2(rman_get_bustag((res)), \ 				       rman_get_bushandle((res)), \ 				       (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_4(rman_get_bustag((res)), \ 				rman_get_bushandle((res)), \ 				(offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSL_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_stream_4(rman_get_bustag((res)), \ 				       rman_get_bushandle((res)), \ 				       (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_SET
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|ATA_OUTB(ch->r_io[ATA_IDX_ADDR].res, ch->r_io[ATA_IDX_ADDR].offset, \ 		 ch->r_io[idx].offset)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INB
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INB(ch->r_io[idx].res, ch->r_io[idx].offset) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INB(ch->r_io[ATA_IDX_DATA].res, ch->r_io[ATA_IDX_DATA].offset)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INW(ch->r_io[idx].res, ch->r_io[idx].offset) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INW(ch->r_io[ATA_IDX_DATA].res, ch->r_io[ATA_IDX_DATA].offset)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INL(ch->r_io[idx].res, ch->r_io[idx].offset) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INL(ch->r_io[ATA_IDX_DATA].res, ch->r_io[ATA_IDX_DATA].offset)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INSW(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INSW(ch->r_io[ATA_IDX_DATA].res, \ 		    ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSW_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INSW_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INSW_STRM(ch->r_io[ATA_IDX_DATA].res, \ 			 ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INSL(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INSL(ch->r_io[ATA_IDX_DATA].res, \ 		    ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSL_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_INSL_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_INSL_STRM(ch->r_io[ATA_IDX_DATA].res, \ 			 ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTB
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTB(ch->r_io[idx].res, ch->r_io[idx].offset, value) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTB(ch->r_io[ATA_IDX_DATA].res, \ 		    ch->r_io[ATA_IDX_DATA].offset, value)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTW(ch->r_io[idx].res, ch->r_io[idx].offset, value) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTW(ch->r_io[ATA_IDX_DATA].res, \ 		    ch->r_io[ATA_IDX_DATA].offset, value)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTL(ch->r_io[idx].res, ch->r_io[idx].offset, value) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTL(ch->r_io[ATA_IDX_DATA].res, \ 		    ch->r_io[ATA_IDX_DATA].offset, value)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTSW(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTSW(ch->r_io[ATA_IDX_DATA].res, \ 		     ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSW_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTSW_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTSW_STRM(ch->r_io[ATA_IDX_DATA].res, \ 			  ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTSL(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTSL(ch->r_io[ATA_IDX_DATA].res, \ 		     ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSL_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|((ch->r_io[idx].res) \ 	? ATA_OUTSL_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count) \ 	: (ATA_IDX_SET(ch, idx), \ 	   ATA_OUTSL_STRM(ch->r_io[ATA_IDX_DATA].res, \ 			  ch->r_io[ATA_IDX_DATA].offset, addr, count)))
end_define

end_unit

