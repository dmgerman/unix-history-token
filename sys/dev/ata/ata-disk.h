begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: ata-disk.h,v 1.5 1999/03/01 12:11:01 sos Exp $  */
end_comment

begin_comment
comment|/*  * Structure describing an ATA disk  */
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
name|struct
name|diskslices
modifier|*
name|slices
decl_stmt|;
name|int32_t
name|unit
decl_stmt|;
comment|/* ATA_MASTER or ATA_SLAVE */
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
name|currentsize
decl_stmt|;
comment|/* size of current transfer */
name|struct
name|buf_queue_head
name|queue
decl_stmt|;
comment|/* head of request queue */
name|u_int32_t
name|bytecount
decl_stmt|;
comment|/* bytes to transfer */
name|u_int32_t
name|donecount
decl_stmt|;
comment|/* bytes transferred */
name|u_int32_t
name|active
decl_stmt|;
comment|/* active processing request */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* drive flags */
define|#
directive|define
name|AD_F_LABELLING
value|0x0001
name|struct
name|devstat
name|stats
decl_stmt|;
comment|/* devstat entry */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ad_transfer
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ad_interrupt
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

