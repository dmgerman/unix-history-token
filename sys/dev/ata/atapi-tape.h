begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: atapi-tape.h,v 1.1 1999/03/01 21:19:18 sos Exp $  */
end_comment

begin_comment
comment|/* ATAPI tape commands not in std ATAPI command set */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TAPE_REWIND
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_READ_CMD
value|0x08
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_WRITE_CMD
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_WEOF
value|0x10
end_define

begin_define
define|#
directive|define
name|WEOF_WRITE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_SPACE_CMD
value|0x11
end_define

begin_define
define|#
directive|define
name|SP_FM
value|0x01
end_define

begin_define
define|#
directive|define
name|SP_EOD
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_ERASE
value|0x19
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_MODE_SENSE
value|0x1a
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_LOAD_UNLOAD
value|0x1b
end_define

begin_define
define|#
directive|define
name|LU_LOAD_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|LU_RETENSION_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|LU_EOT_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|DSC_POLL_INTERVAL
value|10
end_define

begin_comment
comment|/* MODE SENSE parameter header */
end_comment

begin_struct
struct|struct
name|ast_header
block|{
name|u_int8_t
name|data_length
decl_stmt|;
comment|/* total length of data */
name|u_int8_t
name|medium_type
decl_stmt|;
comment|/* medium type (if any) */
name|u_int8_t
name|dsp
decl_stmt|;
comment|/* device specific parameter */
name|u_int8_t
name|bdl
decl_stmt|;
comment|/* block Descriptor Length */
block|}
struct|;
end_struct

begin_comment
comment|/* ATAPI tape drive Capabilities and Mechanical Status Page */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TAPE_CAP_PAGE
value|0x2a
end_define

begin_struct
struct|struct
name|ast_cappage
block|{
name|u_int8_t
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* page code == 0x2a */
name|u_int8_t
name|reserved1_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|page_length
decl_stmt|;
comment|/* page Length == 0x12 */
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int8_t
name|readonly
range|:
literal|1
decl_stmt|;
comment|/* read Only Mode */
name|u_int8_t
name|reserved4_1234
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|reverse
range|:
literal|1
decl_stmt|;
comment|/* supports reverse direction */
name|u_int8_t
name|reserved4_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|reserved5_012
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|eformat
range|:
literal|1
decl_stmt|;
comment|/* supports ERASE formatting */
name|u_int8_t
name|reserved5_4
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|qfa
range|:
literal|1
decl_stmt|;
comment|/* supports QFA formats */
name|u_int8_t
name|reserved5_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|lock
range|:
literal|1
decl_stmt|;
comment|/* supports locking media */
name|u_int8_t
name|locked
range|:
literal|1
decl_stmt|;
comment|/* the media is locked */
name|u_int8_t
name|prevent
range|:
literal|1
decl_stmt|;
comment|/* defaults to prevent state */
name|u_int8_t
name|eject
range|:
literal|1
decl_stmt|;
comment|/* supports eject */
name|u_int8_t
name|disconnect
range|:
literal|1
decl_stmt|;
comment|/* can break request> ctl */
name|u_int8_t
name|reserved6_5
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ecc
range|:
literal|1
decl_stmt|;
comment|/* supports error correction */
name|u_int8_t
name|compress
range|:
literal|1
decl_stmt|;
comment|/* supports data compression */
name|u_int8_t
name|reserved7_0
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|blk512
range|:
literal|1
decl_stmt|;
comment|/* supports 512b block size */
name|u_int8_t
name|blk1024
range|:
literal|1
decl_stmt|;
comment|/* supports 1024b block size */
name|u_int8_t
name|reserved7_3456
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|slowb
range|:
literal|1
decl_stmt|;
comment|/* restricts byte count */
name|u_int16_t
name|max_speed
decl_stmt|;
comment|/* supported speed in KBps */
name|u_int16_t
name|max_defects
decl_stmt|;
comment|/* max stored defect entries */
name|u_int16_t
name|ctl
decl_stmt|;
comment|/* continuous transfer limit */
name|u_int16_t
name|speed
decl_stmt|;
comment|/* current Speed, in KBps */
name|u_int16_t
name|buffer_size
decl_stmt|;
comment|/* buffer Size, in 512 bytes */
name|u_int8_t
name|reserved18
decl_stmt|;
name|u_int8_t
name|reserved19
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* REQUEST SENSE structure */
end_comment

begin_struct
struct|struct
name|ast_reqsense
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
comment|/* follows QIC-157C */
name|u_int8_t
name|reserved1
decl_stmt|;
comment|/* Segment number - reserved */
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
name|u_int8_t
name|info
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/* cmd specific info */
name|u_int8_t
name|asl
decl_stmt|;
comment|/* additional sense length (n-7) */
name|u_int8_t
name|command_specific
decl_stmt|;
comment|/* additional cmd specific info */
name|u_int8_t
name|asc
decl_stmt|;
comment|/* additional sense code */
name|u_int8_t
name|ascq
decl_stmt|;
comment|/* additional sense code qualifier */
name|u_int8_t
name|replaceable_unit_code
decl_stmt|;
comment|/* field replaceable unit code */
name|u_int8_t
name|sk_specific1
range|:
literal|7
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sksv
range|:
literal|1
decl_stmt|;
comment|/* sense key specific info valid */
name|u_int8_t
name|sk_specific2
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sk_specific3
decl_stmt|;
comment|/* sense key Specific */
name|u_int8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* padding */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ast_softc
block|{
name|struct
name|atapi_softc
modifier|*
name|atp
decl_stmt|;
comment|/* controller structure */
name|int32_t
name|lun
decl_stmt|;
comment|/* logical device unit */
name|int32_t
name|flags
decl_stmt|;
comment|/* device state flags */
name|int32_t
name|blksize
decl_stmt|;
comment|/* block size (512 | 1024) */
name|struct
name|buf_queue_head
name|buf_queue
decl_stmt|;
comment|/* queue of i/o requests */
name|struct
name|atapi_params
modifier|*
name|param
decl_stmt|;
comment|/* drive parameters table */
name|struct
name|ast_header
name|header
decl_stmt|;
comment|/* MODE SENSE param header */
name|struct
name|ast_cappage
name|cap
decl_stmt|;
comment|/* capabilities page info */
name|struct
name|devstat
name|stats
decl_stmt|;
comment|/* devstat entry */
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|cdevs_token
decl_stmt|;
name|void
modifier|*
name|bdevs_token
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

