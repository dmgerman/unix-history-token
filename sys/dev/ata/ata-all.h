begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: ata-all.h,v 1.2 1999/03/03 21:10:29 sos Exp $  */
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
name|ATA_PRECOMP
value|0x01
end_define

begin_comment
comment|/* (W) precompensation */
end_comment

begin_define
define|#
directive|define
name|ATA_COUNT
value|0x02
end_define

begin_comment
comment|/* sector count */
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
name|ATA_C_ATA_IDENTIFY
value|0xec
end_define

begin_comment
comment|/* get ATA params */
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
name|ATA_C_PACKET_CMD
value|0xa0
end_define

begin_comment
comment|/* set multi size command */
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
comment|/* drive Seek Completed */
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
name|ATA_S_DRDY
value|0x40
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_BSY
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
comment|/* Misc defines */
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

begin_comment
comment|/* Devices types */
end_comment

begin_define
define|#
directive|define
name|ATA_ATA_MASTER
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_ATA_SLAVE
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_ATAPI_MASTER
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_ATAPI_SLAVE
value|0x08
end_define

begin_comment
comment|/* Structure describing an ATA device */
end_comment

begin_struct
struct|struct
name|ata_softc
block|{
name|u_int32_t
name|unit
decl_stmt|;
comment|/* this instance's number */
name|u_int32_t
name|ioaddr
decl_stmt|;
comment|/* port addr */
name|u_int32_t
name|altioaddr
decl_stmt|;
comment|/* alternate port addr */
name|void
modifier|*
name|dmacookie
decl_stmt|;
comment|/* handle for DMA services */
name|int32_t
name|flags
decl_stmt|;
comment|/* controller flags */
define|#
directive|define
name|ATA_F_SLAVE_ONLY
value|0x0001
name|int32_t
name|devices
decl_stmt|;
comment|/* what is present */
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
name|ATA_IGNORE_INTR
value|0x2
define|#
directive|define
name|ATA_ACTIVE_ATA
value|0x3
define|#
directive|define
name|ATA_ACTIVE_ATAPI
value|0x4
name|struct
name|buf_queue_head
name|ata_queue
decl_stmt|;
comment|/* head of ATA queue */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|atapi_request
argument_list|)
name|atapi_queue
expr_stmt|;
comment|/* head of ATAPI queue */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXATA
value|8
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ata_softc
modifier|*
name|atadevices
index|[]
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
name|int32_t
name|ata_wait
parameter_list|(
name|struct
name|ata_softc
modifier|*
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

