begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999,2000,2001,2002 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* structure describing an ATA disk request */
end_comment

begin_struct
struct|struct
name|ad_request
block|{
name|struct
name|ad_softc
modifier|*
name|softc
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
name|struct
name|callout_handle
name|timeout_handle
decl_stmt|;
comment|/* handle for untimeout */
name|int
name|retries
decl_stmt|;
comment|/* retry count */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ADR_F_READ
value|0x0001
define|#
directive|define
name|ADR_F_ERROR
value|0x0002
define|#
directive|define
name|ADR_F_DMA_USED
value|0x0004
define|#
directive|define
name|ADR_F_QUEUED
value|0x0008
define|#
directive|define
name|ADR_F_FORCE_PIO
value|0x0010
name|caddr_t
name|data
decl_stmt|;
comment|/* pointer to data buf */
name|struct
name|bio
modifier|*
name|bp
decl_stmt|;
comment|/* associated bio ptr */
name|u_int8_t
name|tag
decl_stmt|;
comment|/* tag ID of this request */
name|int
name|serv
decl_stmt|;
comment|/* request had service */
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

begin_comment
comment|/* structure describing an ATA disk */
end_comment

begin_struct
struct|struct
name|ad_softc
block|{
name|struct
name|ata_device
modifier|*
name|device
decl_stmt|;
comment|/* ptr to device softc */
name|int
name|lun
decl_stmt|;
comment|/* logical unit number */
name|u_int64_t
name|total_secs
decl_stmt|;
comment|/* total # of sectors (LBA) */
name|u_int8_t
name|heads
decl_stmt|;
name|u_int8_t
name|sectors
decl_stmt|;
name|u_int32_t
name|transfersize
decl_stmt|;
comment|/* size of each transfer */
name|int
name|num_tags
decl_stmt|;
comment|/* number of tags supported */
name|int
name|flags
decl_stmt|;
comment|/* drive flags */
define|#
directive|define
name|AD_F_LABELLING
value|0x0001
define|#
directive|define
name|AD_F_CHS_USED
value|0x0002
define|#
directive|define
name|AD_F_32B_ENABLED
value|0x0004
define|#
directive|define
name|AD_F_TAG_ENABLED
value|0x0008
define|#
directive|define
name|AD_F_RAID_SUBDISK
value|0x0010
name|struct
name|ad_request
modifier|*
name|tags
index|[
literal|32
index|]
decl_stmt|;
comment|/* tag array of requests */
name|int
name|outstanding
decl_stmt|;
comment|/* tags not serviced yet */
name|struct
name|bio_queue_head
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
name|dev_t
name|dev
decl_stmt|;
comment|/* device place holder */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ad_attach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ad_detach
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
name|void
name|ad_reinit
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ad_start
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ad_transfer
parameter_list|(
name|struct
name|ad_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ad_interrupt
parameter_list|(
name|struct
name|ad_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ad_service
parameter_list|(
name|struct
name|ad_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ad_print
parameter_list|(
name|struct
name|ad_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

