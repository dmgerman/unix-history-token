begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDRIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CDRIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|cdr_track
block|{
name|int
name|datablock_type
decl_stmt|;
comment|/* data type code */
define|#
directive|define
name|CDR_DB_RAW
value|0x0
comment|/* 2352 bytes of raw data */
define|#
directive|define
name|CDR_DB_RAW_PQ
value|0x1
comment|/* 2368 bytes raw data + P/Q subchan */
define|#
directive|define
name|CDR_DB_RAW_PW
value|0x2
comment|/* 2448 bytes raw data + P-W subchan */
define|#
directive|define
name|CDR_DB_RAW_PW_R
value|0x3
comment|/* 2448 bytes raw data + P-W raw sub */
define|#
directive|define
name|CDR_DB_RES_4
value|0x4
comment|/* reserved */
define|#
directive|define
name|CDR_DB_RES_5
value|0x5
comment|/* reserved */
define|#
directive|define
name|CDR_DB_RES_6
value|0x6
comment|/* reserved */
define|#
directive|define
name|CDR_DB_VS_7
value|0x7
comment|/* vendor specific */
define|#
directive|define
name|CDR_DB_ROM_MODE1
value|0x8
comment|/* 2048 bytes Mode 1 (ISO/IEC 10149) */
define|#
directive|define
name|CDR_DB_ROM_MODE2
value|0x9
comment|/* 2336 bytes Mode 2 (ISO/IEC 10149) */
define|#
directive|define
name|CDR_DB_XA_MODE1
value|0xa
comment|/* 2048 bytes Mode 1 (CD-ROM XA 1) */
define|#
directive|define
name|CDR_DB_XA_MODE2_F1
value|0xb
comment|/* 2056 bytes Mode 2 (CD-ROM XA 1) */
define|#
directive|define
name|CDR_DB_XA_MODE2_F2
value|0xc
comment|/* 2324 bytes Mode 2 (CD-ROM XA 2) */
define|#
directive|define
name|CDR_DB_XA_MODE2_MIX
value|0xd
comment|/* 2332 bytes Mode 2 (CD-ROM XA 1/2) */
define|#
directive|define
name|CDR_DB_RES_14
value|0xe
comment|/* reserved */
define|#
directive|define
name|CDR_DB_VS_15
value|0xf
comment|/* vendor specific */
name|int
name|preemp
decl_stmt|;
comment|/* preemphasis if audio track*/
name|int
name|test_write
decl_stmt|;
comment|/* use test writes, laser turned off */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDRIOCBLANK
value|_IOW('c', 100, int)
end_define

begin_define
define|#
directive|define
name|CDR_B_ALL
value|0x0
end_define

begin_define
define|#
directive|define
name|CDR_B_MIN
value|0x1
end_define

begin_define
define|#
directive|define
name|CDR_B_SESSION
value|0x6
end_define

begin_define
define|#
directive|define
name|CDRIOCNEXTWRITEABLEADDR
value|_IOR('c', 101, int)
end_define

begin_define
define|#
directive|define
name|CDRIOCOPENDISK
value|_IO('c', 102)
end_define

begin_define
define|#
directive|define
name|CDRIOCCLOSEDISK
value|_IOW('c', 103, int)
end_define

begin_define
define|#
directive|define
name|CDRIOCOPENTRACK
value|_IOW('c', 104, struct cdr_track)
end_define

begin_define
define|#
directive|define
name|CDRIOCCLOSETRACK
value|_IO('c', 105)
end_define

begin_define
define|#
directive|define
name|CDRIOCWRITESPEED
value|_IOW('c', 106, int)
end_define

begin_define
define|#
directive|define
name|CDRIOCGETBLOCKSIZE
value|_IOR('c', 107, int)
end_define

begin_define
define|#
directive|define
name|CDRIOCSETBLOCKSIZE
value|_IOW('c', 108, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CDRIO_H_ */
end_comment

end_unit

