begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999,2000,2001,2002 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ATA_C_READ48
value|0x24
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ_DMA48
value|0x25
end_define

begin_comment
comment|/* read w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ_DMA_QUEUED48
value|0x26
end_define

begin_comment
comment|/* read w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_READ_MUL48
value|0x29
end_define

begin_comment
comment|/* read multi command */
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
name|ATA_C_WRITE48
value|0x34
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_DMA48
value|0x35
end_define

begin_comment
comment|/* write w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_DMA_QUEUED48
value|0x36
end_define

begin_comment
comment|/* write w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_MUL48
value|0x39
end_define

begin_comment
comment|/* write multi command */
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
name|ATA_C_SLEEP
value|0xe6
end_define

begin_comment
comment|/* sleep command */
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
name|ATA_C_FLUSHCACHE48
value|0xea
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
name|ATA_ALTSTAT
value|0x00
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
name|ATA_IOSIZE
value|0x08
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
value|2
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
name|ATA_BMDEVSPEC_0
value|0x01
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
name|ATA_BMDEVSPEC_1
value|0x03
end_define

begin_define
define|#
directive|define
name|ATA_BMDTP_PORT
value|0x04
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

begin_struct
struct|struct
name|ata_dmastate
block|{
name|bus_dma_tag_t
name|ddmatag
decl_stmt|;
comment|/* data DMA tag */
name|bus_dmamap_t
name|ddmamap
decl_stmt|;
comment|/* data DMA map */
name|bus_dma_tag_t
name|cdmatag
decl_stmt|;
comment|/* control DMA tag */
name|bus_dmamap_t
name|cdmamap
decl_stmt|;
comment|/* control DMA map */
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
name|int
name|flags
decl_stmt|;
comment|/* debugging */
define|#
directive|define
name|ATA_DS_ACTIVE
value|0x01
comment|/* debugging */
define|#
directive|define
name|ATA_DS_READ
value|0x02
comment|/* transaction is a read */
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
name|driver
decl_stmt|;
comment|/* ptr to driver for device */
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
name|int
name|mode
decl_stmt|;
comment|/* transfermode */
name|int
name|cmd
decl_stmt|;
comment|/* last cmd executed */
name|void
modifier|*
name|result
decl_stmt|;
comment|/* misc data */
name|struct
name|ata_dmastate
name|dmastate
decl_stmt|;
comment|/* dma state */
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
name|bus_dma_tag_t
name|dmatag
decl_stmt|;
comment|/* parent dma tag */
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
name|int
function_decl|(
modifier|*
name|intr_func
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
comment|/* interrupt function */
name|u_int32_t
name|chiptype
decl_stmt|;
comment|/* pciid of controller chip */
name|u_int32_t
name|alignment
decl_stmt|;
comment|/* dma engine min alignment */
name|int
name|flags
decl_stmt|;
comment|/* controller flags */
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
name|ATA_ATAPI_DMA_RO
value|0x04
define|#
directive|define
name|ATA_QUEUED
value|0x08
define|#
directive|define
name|ATA_DMA_ACTIVE
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
value|0x0000
define|#
directive|define
name|ATA_IMMEDIATE
value|0x0001
define|#
directive|define
name|ATA_WAIT_INTR
value|0x0002
define|#
directive|define
name|ATA_WAIT_READY
value|0x0004
define|#
directive|define
name|ATA_WAIT_MASK
value|0x0007
define|#
directive|define
name|ATA_ACTIVE
value|0x0010
define|#
directive|define
name|ATA_ACTIVE_ATA
value|0x0020
define|#
directive|define
name|ATA_ACTIVE_ATAPI
value|0x0040
define|#
directive|define
name|ATA_CONTROL
value|0x0080
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
comment|/* disk bay/drawer related */
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
name|int
name|ata_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_resume
parameter_list|(
name|device_t
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_reset
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_reinit
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_wait
parameter_list|(
name|struct
name|ata_device
modifier|*
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
name|ata_device
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_drawerleds
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|,
name|u_int8_t
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
name|ata_prtdev
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
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
parameter_list|)
function_decl|;
end_function_decl

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
name|int
name|ata_test_lun
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
name|int
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

begin_function_decl
name|int
name|ata_dmaalloc
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_dmafree
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_dmafreetags
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_dmainit
parameter_list|(
name|struct
name|ata_device
modifier|*
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
name|ata_device
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_dmastart
parameter_list|(
name|struct
name|ata_device
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
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_dmadone
parameter_list|(
name|struct
name|ata_device
modifier|*
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
value|atomic_cmpset_int(&(ch)->active, ATA_IDLE, (value))
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
value|while (!atomic_cmpset_int(&(ch)->active, ATA_IDLE, (value)))\ 	    tsleep((caddr_t)&(ch), PRIBIO, "atalck", 1);
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
define|\
value|(ch)->active = value;
end_define

begin_define
define|#
directive|define
name|ATA_UNLOCK_CH
parameter_list|(
name|ch
parameter_list|)
define|\
value|(ch)->active = ATA_IDLE
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
value|bus_space_read_multi_stream_2(rman_get_bustag((res)), \ 			 	      rman_get_bushandle((res)), \ 				      (offset), (addr), (count))
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
value|bus_space_read_multi_stream_4(rman_get_bustag((res)), \ 			 	      rman_get_bushandle((res)), \ 				      (offset), (addr), (count))
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
value|bus_space_write_multi_stream_2(rman_get_bustag((res)), \ 			 	       rman_get_bushandle((res)), \ 				       (offset), (addr), (count))
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
value|bus_space_write_multi_stream_4(rman_get_bustag((res)), \ 			 	       rman_get_bushandle((res)), \ 				       (offset), (addr), (count))
end_define

end_unit

