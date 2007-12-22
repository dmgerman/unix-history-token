begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2007 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* structure describing an ATA disk */
end_comment

begin_struct
struct|struct
name|ad_softc
block|{
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
name|disk
modifier|*
name|disk
decl_stmt|;
comment|/* disklabel/slice stuff */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|ad_devclass
decl_stmt|;
end_decl_stmt

end_unit

