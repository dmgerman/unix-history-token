begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ATA_E_ABORT
value|0x04
end_define

begin_comment
comment|/* command aborted */
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
name|ATA_C_READ_MULTI
value|0xc4
end_define

begin_comment
comment|/* read multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_C_WRITE_MULTI
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
name|ATA_C_FEA_SETXFER
value|0x03
end_define

begin_comment
comment|/* set transfer mode */
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
name|ATA_ALTPORT
value|0x206
end_define

begin_comment
comment|/* alternate Status register */
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
comment|/* ATA device DMA access modes */
end_comment

begin_define
define|#
directive|define
name|ATA_WDMA2
value|0x22
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
name|ATA_UDMA3
value|0x43
end_define

begin_define
define|#
directive|define
name|ATA_UDMA4
value|0x44
end_define

begin_comment
comment|/* structure describing an ATA device */
end_comment

begin_struct
struct|struct
name|ata_softc
block|{
name|int32_t
name|unit
decl_stmt|;
comment|/* unit on this controller */
name|int32_t
name|lun
decl_stmt|;
comment|/* logical unit # */
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* device handle */
name|int32_t
name|ioaddr
decl_stmt|;
comment|/* port addr */
name|int32_t
name|altioaddr
decl_stmt|;
comment|/* alternate port addr */
name|int32_t
name|bmaddr
decl_stmt|;
comment|/* bus master DMA port */
name|void
modifier|*
name|dev_softc
index|[
literal|2
index|]
decl_stmt|;
comment|/* ptr to devices softc's */
name|struct
name|ata_dmaentry
modifier|*
name|dmatab
index|[
literal|2
index|]
decl_stmt|;
comment|/* DMA transfer tables */
name|int32_t
name|mode
index|[
literal|2
index|]
decl_stmt|;
comment|/* transfer mode for devices */
define|#
directive|define
name|ATA_MODE_PIO
value|0x00
define|#
directive|define
name|ATA_MODE_WDMA2
value|0x01
define|#
directive|define
name|ATA_MODE_UDMA2
value|0x02
define|#
directive|define
name|ATA_MODE_UDMA3
value|0x04
define|#
directive|define
name|ATA_MODE_UDMA4
value|0x08
name|int32_t
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
name|int32_t
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
name|int32_t
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
value|0x0
define|#
directive|define
name|ATA_WAIT_INTR
value|0x1
define|#
directive|define
name|ATA_WAIT_READY
value|0x2
define|#
directive|define
name|ATA_ACTIVE_ATA
value|0x3
define|#
directive|define
name|ATA_ACTIVE_ATAPI
value|0x4
define|#
directive|define
name|ATA_REINITING
value|0x5
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
if|#
directive|if
name|NAPM
operator|>
literal|0
name|struct
name|apmhook
name|resume_hook
decl_stmt|;
comment|/* hook for apm */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* array to hold all ata softc's */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ata_softc
modifier|*
name|atadevices
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXATA
value|16
end_define

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
name|int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_reinit
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_wait
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_command
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_dmainit
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_dmasetup
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int8_t
modifier|*
parameter_list|,
name|int32_t
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
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_dmastatus
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ata_dmadone
parameter_list|(
name|struct
name|ata_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int8_t
modifier|*
name|ata_mode2str
parameter_list|(
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bswap
parameter_list|(
name|int8_t
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|btrim
parameter_list|(
name|int8_t
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpack
parameter_list|(
name|int8_t
modifier|*
parameter_list|,
name|int8_t
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

