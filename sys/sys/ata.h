begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 - 2006 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/* ATA/ATAPI device parameters */
end_comment

begin_struct
struct|struct
name|ata_params
block|{
comment|/*000*/
name|u_int16_t
name|config
decl_stmt|;
comment|/* configuration info */
define|#
directive|define
name|ATA_PROTO_MASK
value|0x8003
define|#
directive|define
name|ATA_PROTO_ATAPI
value|0x8000
define|#
directive|define
name|ATA_PROTO_ATAPI_12
value|0x8000
define|#
directive|define
name|ATA_PROTO_ATAPI_16
value|0x8001
define|#
directive|define
name|ATA_ATAPI_TYPE_MASK
value|0x1f00
define|#
directive|define
name|ATA_ATAPI_TYPE_DIRECT
value|0x0000
comment|/* disk/floppy */
define|#
directive|define
name|ATA_ATAPI_TYPE_TAPE
value|0x0100
comment|/* streaming tape */
define|#
directive|define
name|ATA_ATAPI_TYPE_CDROM
value|0x0500
comment|/* CD-ROM device */
define|#
directive|define
name|ATA_ATAPI_TYPE_OPTICAL
value|0x0700
comment|/* optical disk */
define|#
directive|define
name|ATA_DRQ_MASK
value|0x0060
define|#
directive|define
name|ATA_DRQ_SLOW
value|0x0000
comment|/* cpu 3 ms delay */
define|#
directive|define
name|ATA_DRQ_INTR
value|0x0020
comment|/* interrupt 10 ms delay */
define|#
directive|define
name|ATA_DRQ_FAST
value|0x0040
comment|/* accel 50 us delay */
comment|/*001*/
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* # of cylinders */
name|u_int16_t
name|reserved2
decl_stmt|;
comment|/*003*/
name|u_int16_t
name|heads
decl_stmt|;
comment|/* # heads */
name|u_int16_t
name|obsolete4
decl_stmt|;
name|u_int16_t
name|obsolete5
decl_stmt|;
comment|/*006*/
name|u_int16_t
name|sectors
decl_stmt|;
comment|/* # sectors/track */
comment|/*007*/
name|u_int16_t
name|vendor7
index|[
literal|3
index|]
decl_stmt|;
comment|/*010*/
name|u_int8_t
name|serial
index|[
literal|20
index|]
decl_stmt|;
comment|/* serial number */
comment|/*020*/
name|u_int16_t
name|retired20
decl_stmt|;
name|u_int16_t
name|retired21
decl_stmt|;
name|u_int16_t
name|obsolete22
decl_stmt|;
comment|/*023*/
name|u_int8_t
name|revision
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware revision */
comment|/*027*/
name|u_int8_t
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* model name */
comment|/*047*/
name|u_int16_t
name|sectors_intr
decl_stmt|;
comment|/* sectors per interrupt */
comment|/*048*/
name|u_int16_t
name|usedmovsd
decl_stmt|;
comment|/* double word read/write? */
comment|/*049*/
name|u_int16_t
name|capabilities1
decl_stmt|;
define|#
directive|define
name|ATA_SUPPORT_DMA
value|0x0100
define|#
directive|define
name|ATA_SUPPORT_LBA
value|0x0200
define|#
directive|define
name|ATA_SUPPORT_OVERLAP
value|0x4000
comment|/*050*/
name|u_int16_t
name|capabilities2
decl_stmt|;
comment|/*051*/
name|u_int16_t
name|retired_piomode
decl_stmt|;
comment|/* PIO modes 0-2 */
define|#
directive|define
name|ATA_RETIRED_PIO_MASK
value|0x0300
comment|/*052*/
name|u_int16_t
name|retired_dmamode
decl_stmt|;
comment|/* DMA modes */
define|#
directive|define
name|ATA_RETIRED_DMA_MASK
value|0x0003
comment|/*053*/
name|u_int16_t
name|atavalid
decl_stmt|;
comment|/* fields valid */
define|#
directive|define
name|ATA_FLAG_54_58
value|0x0001
comment|/* words 54-58 valid */
define|#
directive|define
name|ATA_FLAG_64_70
value|0x0002
comment|/* words 64-70 valid */
define|#
directive|define
name|ATA_FLAG_88
value|0x0004
comment|/* word 88 valid */
comment|/*054*/
name|u_int16_t
name|current_cylinders
decl_stmt|;
comment|/*055*/
name|u_int16_t
name|current_heads
decl_stmt|;
comment|/*056*/
name|u_int16_t
name|current_sectors
decl_stmt|;
comment|/*057*/
name|u_int16_t
name|current_size_1
decl_stmt|;
comment|/*058*/
name|u_int16_t
name|current_size_2
decl_stmt|;
comment|/*059*/
name|u_int16_t
name|multi
decl_stmt|;
define|#
directive|define
name|ATA_MULTI_VALID
value|0x0100
comment|/*060*/
name|u_int16_t
name|lba_size_1
decl_stmt|;
name|u_int16_t
name|lba_size_2
decl_stmt|;
name|u_int16_t
name|obsolete62
decl_stmt|;
comment|/*063*/
name|u_int16_t
name|mwdmamodes
decl_stmt|;
comment|/* multiword DMA modes */
comment|/*064*/
name|u_int16_t
name|apiomodes
decl_stmt|;
comment|/* advanced PIO modes */
comment|/*065*/
name|u_int16_t
name|mwdmamin
decl_stmt|;
comment|/* min. M/W DMA time/word ns */
comment|/*066*/
name|u_int16_t
name|mwdmarec
decl_stmt|;
comment|/* rec. M/W DMA time ns */
comment|/*067*/
name|u_int16_t
name|pioblind
decl_stmt|;
comment|/* min. PIO cycle w/o flow */
comment|/*068*/
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
comment|/*071*/
name|u_int16_t
name|rlsovlap
decl_stmt|;
comment|/* rel time (us) for overlap */
comment|/*072*/
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
comment|/*075*/
name|u_int16_t
name|queue
decl_stmt|;
define|#
directive|define
name|ATA_QUEUE_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x001f)
name|u_int16_t
name|satacapabilities
decl_stmt|;
define|#
directive|define
name|ATA_SATA_GEN1
value|0x0002
define|#
directive|define
name|ATA_SATA_GEN2
value|0x0004
define|#
directive|define
name|ATA_SUPPORT_NCQ
value|0x0100
define|#
directive|define
name|ATA_SUPPORT_IFPWRMNGTRCV
value|0x0200
name|u_int16_t
name|reserved77
decl_stmt|;
name|u_int16_t
name|satasupport
decl_stmt|;
define|#
directive|define
name|ATA_SUPPORT_NONZERO
value|0x0002
define|#
directive|define
name|ATA_SUPPORT_AUTOACTIVATE
value|0x0004
define|#
directive|define
name|ATA_SUPPORT_IFPWRMNGT
value|0x0008
define|#
directive|define
name|ATA_SUPPORT_INORDERDATA
value|0x0010
name|u_int16_t
name|sataenabled
decl_stmt|;
comment|/*080*/
name|u_int16_t
name|version_major
decl_stmt|;
comment|/*081*/
name|u_int16_t
name|version_minor
decl_stmt|;
struct|struct
block|{
comment|/*082/085*/
name|u_int16_t
name|command1
decl_stmt|;
define|#
directive|define
name|ATA_SUPPORT_SMART
value|0x0001
define|#
directive|define
name|ATA_SUPPORT_SECURITY
value|0x0002
define|#
directive|define
name|ATA_SUPPORT_REMOVABLE
value|0x0004
define|#
directive|define
name|ATA_SUPPORT_POWERMGT
value|0x0008
define|#
directive|define
name|ATA_SUPPORT_PACKET
value|0x0010
define|#
directive|define
name|ATA_SUPPORT_WRITECACHE
value|0x0020
define|#
directive|define
name|ATA_SUPPORT_LOOKAHEAD
value|0x0040
define|#
directive|define
name|ATA_SUPPORT_RELEASEIRQ
value|0x0080
define|#
directive|define
name|ATA_SUPPORT_SERVICEIRQ
value|0x0100
define|#
directive|define
name|ATA_SUPPORT_RESET
value|0x0200
define|#
directive|define
name|ATA_SUPPORT_PROTECTED
value|0x0400
define|#
directive|define
name|ATA_SUPPORT_WRITEBUFFER
value|0x1000
define|#
directive|define
name|ATA_SUPPORT_READBUFFER
value|0x2000
define|#
directive|define
name|ATA_SUPPORT_NOP
value|0x4000
comment|/*083/086*/
name|u_int16_t
name|command2
decl_stmt|;
define|#
directive|define
name|ATA_SUPPORT_MICROCODE
value|0x0001
define|#
directive|define
name|ATA_SUPPORT_QUEUED
value|0x0002
define|#
directive|define
name|ATA_SUPPORT_CFA
value|0x0004
define|#
directive|define
name|ATA_SUPPORT_APM
value|0x0008
define|#
directive|define
name|ATA_SUPPORT_NOTIFY
value|0x0010
define|#
directive|define
name|ATA_SUPPORT_STANDBY
value|0x0020
define|#
directive|define
name|ATA_SUPPORT_SPINUP
value|0x0040
define|#
directive|define
name|ATA_SUPPORT_MAXSECURITY
value|0x0100
define|#
directive|define
name|ATA_SUPPORT_AUTOACOUSTIC
value|0x0200
define|#
directive|define
name|ATA_SUPPORT_ADDRESS48
value|0x0400
define|#
directive|define
name|ATA_SUPPORT_OVERLAY
value|0x0800
define|#
directive|define
name|ATA_SUPPORT_FLUSHCACHE
value|0x1000
define|#
directive|define
name|ATA_SUPPORT_FLUSHCACHE48
value|0x2000
comment|/*084/087*/
name|u_int16_t
name|extension
decl_stmt|;
block|}
name|__packed
name|support
struct|,
name|enabled
struct|;
comment|/*088*/
name|u_int16_t
name|udmamodes
decl_stmt|;
comment|/* UltraDMA modes */
comment|/*089*/
name|u_int16_t
name|erase_time
decl_stmt|;
comment|/*090*/
name|u_int16_t
name|enhanced_erase_time
decl_stmt|;
comment|/*091*/
name|u_int16_t
name|apm_value
decl_stmt|;
comment|/*092*/
name|u_int16_t
name|master_passwd_revision
decl_stmt|;
comment|/*093*/
name|u_int16_t
name|hwres
decl_stmt|;
define|#
directive|define
name|ATA_CABLE_ID
value|0x2000
comment|/*094*/
name|u_int16_t
name|acoustic
decl_stmt|;
define|#
directive|define
name|ATA_ACOUSTIC_CURRENT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00ff)
define|#
directive|define
name|ATA_ACOUSTIC_VENDOR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff00)>> 8)
comment|/*095*/
name|u_int16_t
name|stream_min_req_size
decl_stmt|;
comment|/*096*/
name|u_int16_t
name|stream_transfer_time
decl_stmt|;
comment|/*097*/
name|u_int16_t
name|stream_access_latency
decl_stmt|;
comment|/*098*/
name|u_int32_t
name|stream_granularity
decl_stmt|;
comment|/*100*/
name|u_int16_t
name|lba_size48_1
decl_stmt|;
name|u_int16_t
name|lba_size48_2
decl_stmt|;
name|u_int16_t
name|lba_size48_3
decl_stmt|;
name|u_int16_t
name|lba_size48_4
decl_stmt|;
name|u_int16_t
name|reserved104
index|[
literal|23
index|]
decl_stmt|;
comment|/*127*/
name|u_int16_t
name|removable_status
decl_stmt|;
comment|/*128*/
name|u_int16_t
name|security_status
decl_stmt|;
name|u_int16_t
name|reserved129
index|[
literal|31
index|]
decl_stmt|;
comment|/*160*/
name|u_int16_t
name|cfa_powermode1
decl_stmt|;
name|u_int16_t
name|reserved161
index|[
literal|15
index|]
decl_stmt|;
comment|/*176*/
name|u_int16_t
name|media_serial
index|[
literal|30
index|]
decl_stmt|;
name|u_int16_t
name|reserved206
index|[
literal|49
index|]
decl_stmt|;
comment|/*255*/
name|u_int16_t
name|integrity
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* ATA transfer modes */
end_comment

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
name|ATA_PIO_MAX
value|0x0f
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
name|ATA_WDMA0
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_WDMA1
value|0x21
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
name|ATA_UDMA0
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_UDMA1
value|0x41
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

begin_define
define|#
directive|define
name|ATA_UDMA5
value|0x45
end_define

begin_define
define|#
directive|define
name|ATA_UDMA6
value|0x46
end_define

begin_define
define|#
directive|define
name|ATA_SA150
value|0x47
end_define

begin_define
define|#
directive|define
name|ATA_SA300
value|0x48
end_define

begin_define
define|#
directive|define
name|ATA_DMA_MAX
value|0x4f
end_define

begin_define
define|#
directive|define
name|ATA_USB
value|0x80
end_define

begin_define
define|#
directive|define
name|ATA_USB1
value|0x81
end_define

begin_define
define|#
directive|define
name|ATA_USB2
value|0x82
end_define

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
comment|/* NOP */
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
name|ATA_DEVICE_RESET
value|0x08
end_define

begin_comment
comment|/* reset device */
end_comment

begin_define
define|#
directive|define
name|ATA_READ
value|0x20
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ATA_READ48
value|0x24
end_define

begin_comment
comment|/* read 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA48
value|0x25
end_define

begin_comment
comment|/* read DMA 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA_QUEUED48
value|0x26
end_define

begin_comment
comment|/* read DMA QUEUED 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_NATIVE_MAX_ADDDRESS48
value|0x27
end_define

begin_comment
comment|/* read native max addr 48bit */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_MUL48
value|0x29
end_define

begin_comment
comment|/* read multi 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE
value|0x30
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE48
value|0x34
end_define

begin_comment
comment|/* write 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA48
value|0x35
end_define

begin_comment
comment|/* write DMA 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED48
value|0x36
end_define

begin_comment
comment|/* write DMA QUEUED 48bit LBA*/
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MAX_ADDRESS48
value|0x37
end_define

begin_comment
comment|/* set max address 48bit */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_MUL48
value|0x39
end_define

begin_comment
comment|/* write multi 48bit LBA */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_FPDMA_QUEUED
value|0x60
end_define

begin_comment
comment|/* read DMA NCQ */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_FPDMA_QUEUED
value|0x61
end_define

begin_comment
comment|/* write DMA NCQ */
end_comment

begin_define
define|#
directive|define
name|ATA_SEEK
value|0x70
end_define

begin_comment
comment|/* seek */
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
name|ATA_SMART_CMD
value|0xb0
end_define

begin_comment
comment|/* SMART command */
end_comment

begin_define
define|#
directive|define
name|ATA_CFA_ERASE
value|0xc0
end_define

begin_comment
comment|/* CFA erase */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_MUL
value|0xc4
end_define

begin_comment
comment|/* read multi */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_MUL
value|0xc5
end_define

begin_comment
comment|/* write multi */
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MULTI
value|0xc6
end_define

begin_comment
comment|/* set multi size */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA_QUEUED
value|0xc7
end_define

begin_comment
comment|/* read DMA QUEUED */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_DMA
value|0xc8
end_define

begin_comment
comment|/* read DMA */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA
value|0xca
end_define

begin_comment
comment|/* write DMA */
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED
value|0xcc
end_define

begin_comment
comment|/* write DMA QUEUED */
end_comment

begin_define
define|#
directive|define
name|ATA_STANDBY_IMMEDIATE
value|0xe0
end_define

begin_comment
comment|/* standby immediate */
end_comment

begin_define
define|#
directive|define
name|ATA_IDLE_IMMEDIATE
value|0xe1
end_define

begin_comment
comment|/* idle immediate */
end_comment

begin_define
define|#
directive|define
name|ATA_STANDBY_CMD
value|0xe2
end_define

begin_comment
comment|/* standby */
end_comment

begin_define
define|#
directive|define
name|ATA_IDLE_CMD
value|0xe3
end_define

begin_comment
comment|/* idle */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_BUFFER
value|0xe4
end_define

begin_comment
comment|/* read buffer */
end_comment

begin_define
define|#
directive|define
name|ATA_SLEEP
value|0xe6
end_define

begin_comment
comment|/* sleep */
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

begin_define
define|#
directive|define
name|ATA_SECURITY_FREEE_LOCK
value|0xf5
end_define

begin_comment
comment|/* freeze security config */
end_comment

begin_define
define|#
directive|define
name|ATA_READ_NATIVE_MAX_ADDDRESS
value|0xf8
end_define

begin_comment
comment|/* read native max address */
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MAX_ADDRESS
value|0xf9
end_define

begin_comment
comment|/* set max address */
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
name|ATAPI_INQUIRY
value|0x12
end_define

begin_comment
comment|/* get inquiry data */
end_comment

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
name|ATAPI_SERVICE_ACTION_IN
value|0x96
end_define

begin_comment
comment|/* get service data */
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

begin_struct
struct|struct
name|ata_ioc_devices
block|{
name|int
name|channel
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
struct|;
end_struct

begin_comment
comment|/* pr channel ATA ioctl calls */
end_comment

begin_define
define|#
directive|define
name|IOCATAGMAXCHANNEL
value|_IOR('a',  1, int)
end_define

begin_define
define|#
directive|define
name|IOCATAREINIT
value|_IOW('a',  2, int)
end_define

begin_define
define|#
directive|define
name|IOCATAATTACH
value|_IOW('a',  3, int)
end_define

begin_define
define|#
directive|define
name|IOCATADETACH
value|_IOW('a',  4, int)
end_define

begin_define
define|#
directive|define
name|IOCATADEVICES
value|_IOWR('a',  5, struct ata_ioc_devices)
end_define

begin_comment
comment|/* ATAPI request sense structure */
end_comment

begin_struct
struct|struct
name|atapi_sense
block|{
name|u_int8_t
name|error
decl_stmt|;
comment|/* current or deferred errors */
define|#
directive|define
name|ATA_SENSE_VALID
value|0x80
name|u_int8_t
name|segment
decl_stmt|;
comment|/* segment number */
name|u_int8_t
name|key
decl_stmt|;
comment|/* sense key */
define|#
directive|define
name|ATA_SENSE_KEY_MASK
value|0x0f
comment|/* sense key mask */
define|#
directive|define
name|ATA_SENSE_NO_SENSE
value|0x00
comment|/* no specific sense key info */
define|#
directive|define
name|ATA_SENSE_RECOVERED_ERROR
value|0x01
comment|/* command OK, data recovered */
define|#
directive|define
name|ATA_SENSE_NOT_READY
value|0x02
comment|/* no access to drive */
define|#
directive|define
name|ATA_SENSE_MEDIUM_ERROR
value|0x03
comment|/* non-recovered data error */
define|#
directive|define
name|ATA_SENSE_HARDWARE_ERROR
value|0x04
comment|/* non-recoverable HW failure */
define|#
directive|define
name|ATA_SENSE_ILLEGAL_REQUEST
value|0x05
comment|/* invalid command param(s) */
define|#
directive|define
name|ATA_SENSE_UNIT_ATTENTION
value|0x06
comment|/* media changed */
define|#
directive|define
name|ATA_SENSE_DATA_PROTECT
value|0x07
comment|/* write protect */
define|#
directive|define
name|ATA_SENSE_BLANK_CHECK
value|0x08
comment|/* blank check */
define|#
directive|define
name|ATA_SENSE_VENDOR_SPECIFIC
value|0x09
comment|/* vendor specific skey */
define|#
directive|define
name|ATA_SENSE_COPY_ABORTED
value|0x0a
comment|/* copy aborted */
define|#
directive|define
name|ATA_SENSE_ABORTED_COMMAND
value|0x0b
comment|/* command aborted, try again */
define|#
directive|define
name|ATA_SENSE_EQUAL
value|0x0c
comment|/* equal */
define|#
directive|define
name|ATA_SENSE_VOLUME_OVERFLOW
value|0x0d
comment|/* volume overflow */
define|#
directive|define
name|ATA_SENSE_MISCOMPARE
value|0x0e
comment|/* data dont match the medium */
define|#
directive|define
name|ATA_SENSE_RESERVED
value|0x0f
define|#
directive|define
name|ATA_SENSE_ILI
value|0x20;
define|#
directive|define
name|ATA_SENSE_EOM
value|0x40;
define|#
directive|define
name|ATA_SENSE_FILEMARK
value|0x80;
name|u_int32_t
name|cmd_info
decl_stmt|;
comment|/* cmd information */
name|u_int8_t
name|sense_length
decl_stmt|;
comment|/* additional sense len (n-7) */
name|u_int32_t
name|cmd_specific_info
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
name|specific
decl_stmt|;
comment|/* sense key specific */
define|#
directive|define
name|ATA_SENSE_SPEC_VALID
value|0x80
define|#
directive|define
name|ATA_SENSE_SPEC_MASK
value|0x7f
name|u_int8_t
name|specific1
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|specific2
decl_stmt|;
comment|/* sense key specific */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ata_ioc_request
block|{
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|feature
decl_stmt|;
name|u_int64_t
name|lba
decl_stmt|;
name|u_int16_t
name|count
decl_stmt|;
block|}
name|ata
struct|;
struct|struct
block|{
name|char
name|ccb
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|atapi_sense
name|sense
decl_stmt|;
block|}
name|atapi
struct|;
block|}
name|u
union|;
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
name|ATA_CMD_CONTROL
value|0x01
define|#
directive|define
name|ATA_CMD_READ
value|0x02
define|#
directive|define
name|ATA_CMD_WRITE
value|0x04
define|#
directive|define
name|ATA_CMD_ATAPI
value|0x08
name|int
name|timeout
decl_stmt|;
name|int
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* pr device ATA ioctl calls */
end_comment

begin_define
define|#
directive|define
name|IOCATAREQUEST
value|_IOWR('a', 100, struct ata_ioc_request)
end_define

begin_define
define|#
directive|define
name|IOCATAGPARM
value|_IOR('a', 101, struct ata_params)
end_define

begin_define
define|#
directive|define
name|IOCATAGMODE
value|_IOR('a', 102, int)
end_define

begin_define
define|#
directive|define
name|IOCATASMODE
value|_IOW('a', 103, int)
end_define

begin_struct
struct|struct
name|ata_ioc_raid_config
block|{
name|int
name|lun
decl_stmt|;
name|int
name|type
decl_stmt|;
define|#
directive|define
name|AR_JBOD
value|0x0001
define|#
directive|define
name|AR_SPAN
value|0x0002
define|#
directive|define
name|AR_RAID0
value|0x0004
define|#
directive|define
name|AR_RAID1
value|0x0008
define|#
directive|define
name|AR_RAID01
value|0x0010
define|#
directive|define
name|AR_RAID3
value|0x0020
define|#
directive|define
name|AR_RAID4
value|0x0040
define|#
directive|define
name|AR_RAID5
value|0x0080
name|int
name|interleave
decl_stmt|;
name|int
name|status
decl_stmt|;
define|#
directive|define
name|AR_READY
value|1
define|#
directive|define
name|AR_DEGRADED
value|2
define|#
directive|define
name|AR_REBUILDING
value|4
name|int
name|progress
decl_stmt|;
name|int
name|total_disks
decl_stmt|;
name|int
name|disks
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ATA RAID ioctl calls */
end_comment

begin_define
define|#
directive|define
name|IOCATARAIDCREATE
value|_IOWR('a', 200, struct ata_ioc_raid_config)
end_define

begin_define
define|#
directive|define
name|IOCATARAIDDELETE
value|_IOW('a', 201, int)
end_define

begin_define
define|#
directive|define
name|IOCATARAIDSTATUS
value|_IOWR('a', 202, struct ata_ioc_raid_config)
end_define

begin_define
define|#
directive|define
name|IOCATARAIDADDSPARE
value|_IOW('a', 203, struct ata_ioc_raid_config)
end_define

begin_define
define|#
directive|define
name|IOCATARAIDREBUILD
value|_IOW('a', 204, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ATA_H_ */
end_comment

end_unit

