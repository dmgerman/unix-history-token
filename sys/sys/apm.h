begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_APM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_APM_H_
end_define

begin_comment
comment|/* Driver Descriptor Record. */
end_comment

begin_struct
struct|struct
name|apm_ddr
block|{
name|uint16_t
name|ddr_sig
decl_stmt|;
define|#
directive|define
name|APM_DDR_SIG
value|0x4552
name|uint16_t
name|ddr_blksize
decl_stmt|;
name|uint32_t
name|ddr_blkcount
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Partition Map Entry Record. */
end_comment

begin_struct
struct|struct
name|apm_ent
block|{
name|uint16_t
name|ent_sig
decl_stmt|;
define|#
directive|define
name|APM_ENT_SIG
value|0x504d
name|uint16_t
name|_pad_
decl_stmt|;
name|uint32_t
name|ent_pmblkcnt
decl_stmt|;
name|uint32_t
name|ent_start
decl_stmt|;
name|uint32_t
name|ent_size
decl_stmt|;
name|char
name|ent_name
index|[
literal|32
index|]
decl_stmt|;
name|char
name|ent_type
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|APM_ENT_TYPE_SELF
value|"Apple_partition_map"
end_define

begin_define
define|#
directive|define
name|APM_ENT_TYPE_UNUSED
value|"Apple_Free"
end_define

begin_define
define|#
directive|define
name|APM_ENT_TYPE_FREEBSD
value|"FreeBSD"
end_define

begin_define
define|#
directive|define
name|APM_ENT_TYPE_FREEBSD_SWAP
value|"FreeBSD-swap"
end_define

begin_define
define|#
directive|define
name|APM_ENT_TYPE_FREEBSD_UFS
value|"FreeBSD-UFS"
end_define

begin_define
define|#
directive|define
name|APM_ENT_TYPE_FREEBSD_VINUM
value|"FreeBSD-Vinum"
end_define

begin_define
define|#
directive|define
name|APM_ENT_TYPE_APPLE_HFS
value|"Apple_HFS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_APM_H_ */
end_comment

end_unit

