begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2003 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATA commands */
end_comment

begin_define
define|#
directive|define
name|ATA_NOP
value|0x00
end_define

begin_comment
comment|/* NOP command */
end_comment

begin_define
define|#
directive|define
name|ATA_NF_FLUSHQUEUE
value|0x00
end_define

begin_comment
comment|/* flush queued cmd's */
end_comment

begin_define
define|#
directive|define
name|ATA_NF_AUTOPOLL
value|0x01
end_define

begin_comment
comment|/* start autopoll function */
end_comment

begin_define
define|#
directive|define
name|ATA_ATAPI_RESET
value|0x08
end_define

begin_comment
comment|/* reset ATAPI device */
end_comment

begin_define
define|#
directive|define
name|ATA_READ
value|0x20
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ48
value|0x24
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA48
value|0x25
end_define

begin_comment
comment|/* read w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA_QUEUED48
value|0x26
end_define

begin_comment
comment|/* read w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_MUL48
value|0x29
end_define

begin_comment
comment|/* read multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE
value|0x30
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE48
value|0x34
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA48
value|0x35
end_define

begin_comment
comment|/* write w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED48
value|0x36
end_define

begin_comment
comment|/* write w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_MUL48
value|0x39
end_define

begin_comment
comment|/* write multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_PACKET_CMD
value|0xa0
end_define

begin_comment
comment|/* packet command */
end_comment

begin_define
define|#
directive|define
name|ATA_ATAPI_IDENTIFY
value|0xa1
end_define

begin_comment
comment|/* get ATAPI params*/
end_comment

begin_define
define|#
directive|define
name|ATA_SERVICE
value|0xa2
end_define

begin_comment
comment|/* service command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_MUL
value|0xc4
end_define

begin_comment
comment|/* read multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_MUL
value|0xc5
end_define

begin_comment
comment|/* write multi command */
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MULTI
value|0xc6
end_define

begin_comment
comment|/* set multi size command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA_QUEUED
value|0xc7
end_define

begin_comment
comment|/* read w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA
value|0xc8
end_define

begin_comment
comment|/* read w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA
value|0xca
end_define

begin_comment
comment|/* write w/DMA command */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED
value|0xcc
end_define

begin_comment
comment|/* write w/DMA QUEUED command */
end_comment

begin_define
define|#
directive|define
name|ATA_SLEEP
value|0xe6
end_define

begin_comment
comment|/* sleep command */
end_comment

begin_define
define|#
directive|define
name|ATA_FLUSHCACHE
value|0xe7
end_define

begin_comment
comment|/* flush cache to disk */
end_comment

begin_define
define|#
directive|define
name|ATA_FLUSHCACHE48
value|0xea
end_define

begin_comment
comment|/* flush cache to disk */
end_comment

begin_define
define|#
directive|define
name|ATA_ATA_IDENTIFY
value|0xec
end_define

begin_comment
comment|/* get ATA params */
end_comment

begin_define
define|#
directive|define
name|ATA_SETFEATURES
value|0xef
end_define

begin_comment
comment|/* features command */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_SETXFER
value|0x03
end_define

begin_comment
comment|/* set transfer mode */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_ENAB_WCACHE
value|0x02
end_define

begin_comment
comment|/* enable write cache */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_DIS_WCACHE
value|0x82
end_define

begin_comment
comment|/* disable write cache */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_ENAB_RCACHE
value|0xaa
end_define

begin_comment
comment|/* enable readahead cache */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_DIS_RCACHE
value|0x55
end_define

begin_comment
comment|/* disable readahead cache */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_ENAB_RELIRQ
value|0x5d
end_define

begin_comment
comment|/* enable release interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_DIS_RELIRQ
value|0xdd
end_define

begin_comment
comment|/* disable release interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_ENAB_SRVIRQ
value|0x5e
end_define

begin_comment
comment|/* enable service interrupt */
end_comment

begin_define
define|#
directive|define
name|ATA_SF_DIS_SRVIRQ
value|0xde
end_define

begin_comment
comment|/* disable service interrupt */
end_comment

begin_comment
comment|/* ATAPI commands */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TEST_UNIT_READY
value|0x00
end_define

begin_comment
comment|/* check if device is ready */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REZERO
value|0x01
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REQUEST_SENSE
value|0x03
end_define

begin_comment
comment|/* get sense data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_FORMAT
value|0x04
end_define

begin_comment
comment|/* format unit */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ
value|0x08
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WRITE
value|0x0a
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WEOF
value|0x10
end_define

begin_comment
comment|/* write filemark */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WF_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_SPACE
value|0x11
end_define

begin_comment
comment|/* space command */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SP_FM
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_SP_EOD
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_MODE_SELECT
value|0x15
end_define

begin_comment
comment|/* mode select */
end_comment

begin_define
define|#
directive|define
name|ATAPI_ERASE
value|0x19
end_define

begin_comment
comment|/* erase */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE
value|0x1a
end_define

begin_comment
comment|/* mode sense */
end_comment

begin_define
define|#
directive|define
name|ATAPI_START_STOP
value|0x1b
end_define

begin_comment
comment|/* start/stop unit */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SS_LOAD
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_SS_RETENSION
value|0x02
end_define

begin_define
define|#
directive|define
name|ATAPI_SS_EJECT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATAPI_PREVENT_ALLOW
value|0x1e
end_define

begin_comment
comment|/* media removal */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_FORMAT_CAPACITIES
value|0x23
end_define

begin_comment
comment|/* get format capacities */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_CAPACITY
value|0x25
end_define

begin_comment
comment|/* get volume capacity */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_BIG
value|0x28
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WRITE_BIG
value|0x2a
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_LOCATE
value|0x2b
end_define

begin_comment
comment|/* locate to position */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_POSITION
value|0x34
end_define

begin_comment
comment|/* read position */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SYNCHRONIZE_CACHE
value|0x35
end_define

begin_comment
comment|/* flush buf, close channel */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WRITE_BUFFER
value|0x3b
end_define

begin_comment
comment|/* write device buffer */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_BUFFER
value|0x3c
end_define

begin_comment
comment|/* read device buffer */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_SUBCHANNEL
value|0x42
end_define

begin_comment
comment|/* get subchannel info */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_TOC
value|0x43
end_define

begin_comment
comment|/* get table of contents */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_10
value|0x45
end_define

begin_comment
comment|/* play by lba */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_MSF
value|0x47
end_define

begin_comment
comment|/* play by MSF address */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_TRACK
value|0x48
end_define

begin_comment
comment|/* play by track number */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PAUSE
value|0x4b
end_define

begin_comment
comment|/* pause audio operation */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_DISK_INFO
value|0x51
end_define

begin_comment
comment|/* get disk info structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_TRACK_INFO
value|0x52
end_define

begin_comment
comment|/* get track info structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_RESERVE_TRACK
value|0x53
end_define

begin_comment
comment|/* reserve track */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_OPC_INFO
value|0x54
end_define

begin_comment
comment|/* send OPC structurek */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SELECT_BIG
value|0x55
end_define

begin_comment
comment|/* set device parameters */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REPAIR_TRACK
value|0x58
end_define

begin_comment
comment|/* repair track */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_MASTER_CUE
value|0x59
end_define

begin_comment
comment|/* read master CUE info */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE_BIG
value|0x5a
end_define

begin_comment
comment|/* get device parameters */
end_comment

begin_define
define|#
directive|define
name|ATAPI_CLOSE_TRACK
value|0x5b
end_define

begin_comment
comment|/* close track/session */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_BUFFER_CAPACITY
value|0x5c
end_define

begin_comment
comment|/* get buffer capicity */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_CUE_SHEET
value|0x5d
end_define

begin_comment
comment|/* send CUE sheet */
end_comment

begin_define
define|#
directive|define
name|ATAPI_BLANK
value|0xa1
end_define

begin_comment
comment|/* blank the media */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_KEY
value|0xa3
end_define

begin_comment
comment|/* send DVD key structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REPORT_KEY
value|0xa4
end_define

begin_comment
comment|/* get DVD key structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_12
value|0xa5
end_define

begin_comment
comment|/* play by lba */
end_comment

begin_define
define|#
directive|define
name|ATAPI_LOAD_UNLOAD
value|0xa6
end_define

begin_comment
comment|/* changer control command */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_STRUCTURE
value|0xad
end_define

begin_comment
comment|/* get DVD structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_CD
value|0xb4
end_define

begin_comment
comment|/* universal play command */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SET_SPEED
value|0xbb
end_define

begin_comment
comment|/* set drive speed */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MECH_STATUS
value|0xbd
end_define

begin_comment
comment|/* get changer status */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_CD
value|0xbe
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_POLL_DSC
value|0xff
end_define

begin_comment
comment|/* poll DSC status bit */
end_comment

end_unit

