begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VTOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VTOC_H_
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_UNASSIGNED
value|0x00
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_BOOT
value|0x01
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_ROOT
value|0x02
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_SWAP
value|0x03
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_USR
value|0x04
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_BACKUP
value|0x05
end_define

begin_comment
comment|/* "c" partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_TAG_STAND
value|0x06
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_VAR
value|0x07
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_HOME
value|0x08
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_ALTSCTR
value|0x09
end_define

begin_comment
comment|/* alternate sector partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_TAG_CACHE
value|0x0a
end_define

begin_comment
comment|/* Solaris cachefs partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_TAG_VXVM_PUB
value|0x0e
end_define

begin_comment
comment|/* VxVM public region */
end_comment

begin_define
define|#
directive|define
name|VTOC_TAG_VXVM_PRIV
value|0x0f
end_define

begin_comment
comment|/* VxVM private region */
end_comment

begin_comment
comment|/* NetBSD/mips defines this */
end_comment

begin_define
define|#
directive|define
name|VTOC_TAG_NETBSD_FFS
value|0xff
end_define

begin_comment
comment|/* FreeBSD tags: the high byte equals ELFOSABI_FREEBSD */
end_comment

begin_define
define|#
directive|define
name|VTOC_TAG_FREEBSD_SWAP
value|0x0901
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_FREEBSD_UFS
value|0x0902
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_FREEBSD_VINUM
value|0x0903
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_FREEBSD_ZFS
value|0x0904
end_define

begin_define
define|#
directive|define
name|VTOC_TAG_FREEBSD_NANDFS
value|0x0905
end_define

begin_define
define|#
directive|define
name|VTOC_FLAG_UNMNT
value|0x01
end_define

begin_comment
comment|/* unmountable partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_FLAG_RDONLY
value|0x10
end_define

begin_comment
comment|/* partition is read/only */
end_comment

begin_define
define|#
directive|define
name|VTOC_ASCII_LEN
value|128
end_define

begin_define
define|#
directive|define
name|VTOC_BOOTSIZE
value|8192
end_define

begin_comment
comment|/* 16 sectors */
end_comment

begin_define
define|#
directive|define
name|VTOC_MAGIC
value|0xdabe
end_define

begin_define
define|#
directive|define
name|VTOC_RAW_PART
value|2
end_define

begin_define
define|#
directive|define
name|VTOC_SANITY
value|0x600ddeee
end_define

begin_define
define|#
directive|define
name|VTOC_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|VTOC_VOLUME_LEN
value|8
end_define

begin_define
define|#
directive|define
name|VTOC8_NPARTS
value|8
end_define

begin_struct
struct|struct
name|vtoc8
block|{
name|char
name|ascii
index|[
name|VTOC_ASCII_LEN
index|]
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|char
name|volume
index|[
name|VTOC_VOLUME_LEN
index|]
decl_stmt|;
name|uint16_t
name|nparts
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|tag
decl_stmt|;
name|uint16_t
name|flag
decl_stmt|;
block|}
name|part
index|[
name|VTOC8_NPARTS
index|]
name|__packed
struct|;
name|uint16_t
name|__alignment
decl_stmt|;
name|uint32_t
name|bootinfo
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|sanity
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|10
index|]
decl_stmt|;
name|uint32_t
name|timestamp
index|[
name|VTOC8_NPARTS
index|]
decl_stmt|;
name|uint16_t
name|wskip
decl_stmt|;
name|uint16_t
name|rskip
decl_stmt|;
name|char
name|padding
index|[
literal|152
index|]
decl_stmt|;
name|uint16_t
name|rpm
decl_stmt|;
name|uint16_t
name|physcyls
decl_stmt|;
name|uint16_t
name|sparesecs
decl_stmt|;
name|uint16_t
name|spare1
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|interleave
decl_stmt|;
name|uint16_t
name|ncyls
decl_stmt|;
name|uint16_t
name|altcyls
decl_stmt|;
name|uint16_t
name|nheads
decl_stmt|;
name|uint16_t
name|nsecs
decl_stmt|;
name|uint16_t
name|spare2
index|[
literal|2
index|]
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|cyl
decl_stmt|;
name|uint32_t
name|nblks
decl_stmt|;
block|}
name|map
index|[
name|VTOC8_NPARTS
index|]
struct|;
name|uint16_t
name|magic
decl_stmt|;
name|uint16_t
name|cksum
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vtoc8
argument_list|)
operator|==
literal|512
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_VTOC_H_ */
end_comment

end_unit

