begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2007 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATAPI tape drive Capabilities and Mechanical Status Page */
end_comment

begin_struct
struct|struct
name|ast_cappage
block|{
comment|/* mode page data header */
name|u_int8_t
name|data_length
decl_stmt|;
comment|/* total length of data */
name|u_int8_t
name|medium_type
decl_stmt|;
comment|/* medium type (if any) */
name|u_int8_t
name|reserved
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|mode
range|:
literal|3
decl_stmt|;
comment|/* buffering mode */
name|u_int8_t
name|write_protect
range|:
literal|1
decl_stmt|;
comment|/* media is writeprotected */
name|u_int8_t
name|blk_desc_len
decl_stmt|;
comment|/* block Descriptor Length */
comment|/* capabilities page */
name|u_int8_t
name|page_code
range|:
literal|6
decl_stmt|;
define|#
directive|define
name|ATAPI_TAPE_CAP_PAGE
value|0x2a
name|u_int8_t
name|reserved0_6
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ps
range|:
literal|1
decl_stmt|;
comment|/* parameters saveable */
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
name|blk32k
range|:
literal|1
decl_stmt|;
comment|/* supports 32kb block size */
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
comment|/* ATAPI OnStream ADR data transfer mode page (ADR unique) */
end_comment

begin_struct
struct|struct
name|ast_transferpage
block|{
comment|/* mode page data header */
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
name|blk_desc_len
decl_stmt|;
comment|/* block Descriptor Length */
comment|/* data transfer page */
name|u_int8_t
name|page_code
range|:
literal|6
decl_stmt|;
define|#
directive|define
name|ATAPI_TAPE_TRANSFER_PAGE
value|0x30
name|u_int8_t
name|reserved0_6
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ps
range|:
literal|1
decl_stmt|;
comment|/* parameters saveable */
name|u_int8_t
name|page_length
decl_stmt|;
comment|/* page Length == 0x02 */
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int8_t
name|read32k
range|:
literal|1
decl_stmt|;
comment|/* 32k blk size (data only) */
name|u_int8_t
name|read32k5
range|:
literal|1
decl_stmt|;
comment|/* 32.5k blk size (data&AUX) */
name|u_int8_t
name|reserved3_23
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|write32k
range|:
literal|1
decl_stmt|;
comment|/* 32k blk size (data only) */
name|u_int8_t
name|write32k5
range|:
literal|1
decl_stmt|;
comment|/* 32.5k blk size (data&AUX) */
name|u_int8_t
name|reserved3_6
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|streaming
range|:
literal|1
decl_stmt|;
comment|/* streaming mode enable */
block|}
struct|;
end_struct

begin_comment
comment|/* ATAPI OnStream ADR vendor identification mode page (ADR unique) */
end_comment

begin_struct
struct|struct
name|ast_identifypage
block|{
comment|/* mode page data header */
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
name|blk_desc_len
decl_stmt|;
comment|/* block Descriptor Length */
comment|/* data transfer page */
name|u_int8_t
name|page_code
range|:
literal|6
decl_stmt|;
define|#
directive|define
name|ATAPI_TAPE_IDENTIFY_PAGE
value|0x36
name|u_int8_t
name|reserved0_6
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ps
range|:
literal|1
decl_stmt|;
comment|/* parameters saveable */
name|u_int8_t
name|page_length
decl_stmt|;
comment|/* page Length == 0x06 */
name|u_int8_t
name|ident
index|[
literal|4
index|]
decl_stmt|;
comment|/* host id string */
name|u_int8_t
name|reserved6
decl_stmt|;
name|u_int8_t
name|reserved7
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ATAPI read position structure */
end_comment

begin_struct
struct|struct
name|ast_readposition
block|{
name|u_int8_t
name|reserved0_05
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|eop
range|:
literal|1
decl_stmt|;
comment|/* end of partition */
name|u_int8_t
name|bop
range|:
literal|1
decl_stmt|;
comment|/* beginning of partition */
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int32_t
name|host
decl_stmt|;
comment|/* frame address in buffer */
name|u_int32_t
name|tape
decl_stmt|;
comment|/* frame address on tape */
name|u_int8_t
name|reserved12
decl_stmt|;
name|u_int8_t
name|reserved13
decl_stmt|;
name|u_int8_t
name|reserved14
decl_stmt|;
name|u_int8_t
name|blks_in_buf
decl_stmt|;
comment|/* blocks in buffer */
name|u_int8_t
name|reserved16
decl_stmt|;
name|u_int8_t
name|reserved17
decl_stmt|;
name|u_int8_t
name|reserved18
decl_stmt|;
name|u_int8_t
name|reserved19
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ast_softc
block|{
name|int
name|flags
decl_stmt|;
comment|/* device state flags */
define|#
directive|define
name|F_CTL_WARN
value|0x0001
comment|/* warned about CTL wrong? */
define|#
directive|define
name|F_WRITEPROTECT
value|0x0002
comment|/* media is writeprotected */
define|#
directive|define
name|F_DATA_WRITTEN
value|0x0004
comment|/* data has been written */
define|#
directive|define
name|F_FM_WRITTEN
value|0x0008
comment|/* filemark has been written */
define|#
directive|define
name|F_ONSTREAM
value|0x0100
comment|/* OnStream ADR device */
name|int
name|blksize
decl_stmt|;
comment|/* block size (512 | 1024) */
name|struct
name|atapi_params
modifier|*
name|param
decl_stmt|;
comment|/* drive parameters table */
name|struct
name|ast_cappage
name|cap
decl_stmt|;
comment|/* capabilities page info */
name|struct
name|devstat
modifier|*
name|stats
decl_stmt|;
comment|/* devstat entry */
name|struct
name|cdev
modifier|*
name|dev1
decl_stmt|,
modifier|*
name|dev2
decl_stmt|;
comment|/* device place holders */
block|}
struct|;
end_struct

end_unit

