begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATA device parameter information */
end_comment

begin_struct
struct|struct
name|ata_params
block|{
name|int16_t
name|config
decl_stmt|;
comment|/* general configuration bits */
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* number of cylinders */
name|int16_t
name|reserved2
decl_stmt|;
name|u_int16_t
name|heads
decl_stmt|;
comment|/* # heads */
name|int16_t
name|unfbytespertrk
decl_stmt|;
comment|/* # unformatted bytes/track */
name|int16_t
name|unfbytes
decl_stmt|;
comment|/* # unformatted bytes/sector */
name|u_int16_t
name|sectors
decl_stmt|;
comment|/* # sectors/track */
name|int16_t
name|vendorunique0
index|[
literal|3
index|]
decl_stmt|;
name|int8_t
name|serial
index|[
literal|20
index|]
decl_stmt|;
comment|/* serial number */
name|int16_t
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
name|int16_t
name|buffersize
decl_stmt|;
comment|/* buf size, 512-byte units */
name|int16_t
name|necc
decl_stmt|;
comment|/* ecc bytes appended */
name|int8_t
name|revision
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware revision */
name|int8_t
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* model name */
name|int8_t
name|nsecperint
decl_stmt|;
comment|/* sectors per interrupt */
name|int8_t
name|vendorunique1
decl_stmt|;
name|int16_t
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
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|standby
range|:
literal|1
decl_stmt|;
comment|/* standby timer supported */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|int16_t
name|capvalidate
decl_stmt|;
comment|/* validation for above */
name|int8_t
name|vendorunique3
decl_stmt|;
name|int8_t
name|opiomode
decl_stmt|;
comment|/* PIO modes 0-2 */
name|int8_t
name|vendorunique4
decl_stmt|;
name|int8_t
name|odmamode
decl_stmt|;
comment|/* old DMA modes, not ATA-3 */
name|int16_t
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
name|int16_t
name|currcyls
decl_stmt|;
name|int16_t
name|currheads
decl_stmt|;
name|int16_t
name|currsectors
decl_stmt|;
name|int16_t
name|currsize0
decl_stmt|;
name|int16_t
name|currsize1
decl_stmt|;
name|int8_t
name|currmultsect
decl_stmt|;
name|int8_t
name|multsectvalid
decl_stmt|;
name|int32_t
name|lbasize
decl_stmt|;
name|int16_t
name|sdmamodes
decl_stmt|;
comment|/* singleword DMA modes */
name|int16_t
name|wdmamodes
decl_stmt|;
comment|/* multiword DMA modes */
name|int16_t
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
name|int16_t
name|reserved69
decl_stmt|;
name|int16_t
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
name|int16_t
name|reserved73
decl_stmt|;
name|int16_t
name|reserved74
decl_stmt|;
name|int16_t
name|queuelen
decl_stmt|;
name|int16_t
name|reserved76
decl_stmt|;
name|int16_t
name|reserved77
decl_stmt|;
name|int16_t
name|reserved78
decl_stmt|;
name|int16_t
name|reserved79
decl_stmt|;
name|int16_t
name|versmajor
decl_stmt|;
name|int16_t
name|versminor
decl_stmt|;
name|int16_t
name|featsupp1
decl_stmt|;
name|int16_t
name|featsupp2
decl_stmt|;
name|int16_t
name|featsupp3
decl_stmt|;
name|int16_t
name|featenab1
decl_stmt|;
name|int16_t
name|featenab2
decl_stmt|;
name|int16_t
name|featenab3
decl_stmt|;
name|int16_t
name|udmamodes
decl_stmt|;
comment|/* UltraDMA modes */
name|int16_t
name|erasetime
decl_stmt|;
name|int16_t
name|enherasetime
decl_stmt|;
name|int16_t
name|apmlevel
decl_stmt|;
name|int16_t
name|reserved92
index|[
literal|34
index|]
decl_stmt|;
name|int16_t
name|rmvcap
decl_stmt|;
name|int16_t
name|securelevel
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing an ATA disk */
end_comment

begin_struct
struct|struct
name|ad_softc
block|{
name|struct
name|ata_softc
modifier|*
name|controller
decl_stmt|;
comment|/* ptr to parent ctrl */
name|struct
name|ata_params
modifier|*
name|ata_parm
decl_stmt|;
comment|/* ata device params */
name|int32_t
name|unit
decl_stmt|;
comment|/* ATA_MASTER or ATA_SLAVE */
name|int32_t
name|lun
decl_stmt|;
comment|/* logical unit number */
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* disk geometry (probed) */
name|u_int8_t
name|heads
decl_stmt|;
name|u_int8_t
name|sectors
decl_stmt|;
name|u_int32_t
name|total_secs
decl_stmt|;
comment|/* total # of sectors (LBA) */
name|u_int32_t
name|transfersize
decl_stmt|;
comment|/* size of each transfer */
name|u_int32_t
name|num_tags
decl_stmt|;
comment|/* number of tags supported */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* drive flags */
define|#
directive|define
name|AD_F_LABELLING
value|0x0001
define|#
directive|define
name|AD_F_LBA_ENABLED
value|0x0002
define|#
directive|define
name|AD_F_32B_ENABLED
value|0x0004
define|#
directive|define
name|AD_F_DMA_ENABLED
value|0x0008
define|#
directive|define
name|AD_F_TAG_ENABLED
value|0x0010
name|struct
name|buf_queue_head
name|queue
decl_stmt|;
comment|/* head of request queue */
name|struct
name|devstat
name|stats
decl_stmt|;
comment|/* devstat entry */
name|struct
name|disk
name|disk
decl_stmt|;
comment|/* disklabel/slice stuff */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ad_request
block|{
name|struct
name|ad_softc
modifier|*
name|device
decl_stmt|;
comment|/* ptr to parent device */
name|u_int32_t
name|blockaddr
decl_stmt|;
comment|/* block number */
name|u_int32_t
name|bytecount
decl_stmt|;
comment|/* bytes to transfer */
name|u_int32_t
name|donecount
decl_stmt|;
comment|/* bytes transferred */
name|u_int32_t
name|currentsize
decl_stmt|;
comment|/* size of current transfer */
name|u_int32_t
name|result
decl_stmt|;
comment|/* result code */
name|int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|AR_F_READ
value|0x0001
define|#
directive|define
name|AR_F_ERROR
value|0x0002
define|#
directive|define
name|AR_F_DMA_USED
value|0x0004
name|int8_t
modifier|*
name|data
decl_stmt|;
comment|/* pointer to data buf */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* associated buf ptr */
name|u_int8_t
name|tag
decl_stmt|;
comment|/* tag ID of this request */
name|TAILQ_ENTRY
argument_list|(
argument|ad_request
argument_list|)
name|chain
expr_stmt|;
comment|/* list management */
block|}
struct|;
end_struct

end_unit

