begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACHINE_ATAGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACHINE_ATAGS_H__
end_define

begin_comment
comment|/*  * Linux boot ABI compatable ATAG definitions.  All these structures  * assume tight packing, but since they are all uint32_t's, I've not  * bothered to do the usual alignment dance.  */
end_comment

begin_define
define|#
directive|define
name|LBABI_MAX_COMMAND_LINE
value|1024
end_define

begin_struct
struct|struct
name|arm_lbabi_header
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/* Size of this node, including header */
name|uint32_t
name|tag
decl_stmt|;
comment|/* Node type */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATAG_NONE
value|0x00000000
end_define

begin_comment
comment|/* End of atags list */
end_comment

begin_define
define|#
directive|define
name|ATAG_CORE
value|0x54410001
end_define

begin_comment
comment|/* List must start with ATAG_CORE */
end_comment

begin_define
define|#
directive|define
name|ATAG_MEM
value|0x54410002
end_define

begin_comment
comment|/* Multiple ATAG_MEM nodes possible */
end_comment

begin_define
define|#
directive|define
name|ATAG_VIDEOTEXT
value|0x54410003
end_define

begin_comment
comment|/* Video parameters */
end_comment

begin_define
define|#
directive|define
name|ATAG_RAMDISK
value|0x54410004
end_define

begin_comment
comment|/* Describes the ramdisk parameters */
end_comment

begin_define
define|#
directive|define
name|ATAG_INITRD
value|0x54410005
end_define

begin_comment
comment|/* Deprecated ramdisk -- used va not pa */
end_comment

begin_define
define|#
directive|define
name|ATAG_INITRD2
value|0x54420005
end_define

begin_comment
comment|/* compressed ramdisk image */
end_comment

begin_define
define|#
directive|define
name|ATAG_SERIAL
value|0x54410006
end_define

begin_comment
comment|/* 64-bits of serial number */
end_comment

begin_define
define|#
directive|define
name|ATAG_REVISION
value|0x54410007
end_define

begin_comment
comment|/* Board revision */
end_comment

begin_define
define|#
directive|define
name|ATAG_VIDEOLFB
value|0x54410008
end_define

begin_comment
comment|/* vesafb framebuffer */
end_comment

begin_define
define|#
directive|define
name|ATAG_CMDLINE
value|0x54410009
end_define

begin_comment
comment|/* Command line */
end_comment

begin_comment
comment|/*  * ATAG_CORE data  */
end_comment

begin_struct
struct|struct
name|arm_lbabi_core
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/* bit 0 == read-only */
name|uint32_t
name|pagesize
decl_stmt|;
name|uint32_t
name|rootdev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATAG_MEM data -- Can be more than one to describe different  * banks.  */
end_comment

begin_struct
struct|struct
name|arm_lbabi_mem32
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|start
decl_stmt|;
comment|/* start of physical memory */
block|}
struct|;
end_struct

begin_comment
comment|/*   * ATAG_INITRD2 - Compressed ramdisk image details  */
end_comment

begin_struct
struct|struct
name|arm_lbabi_initrd
block|{
name|uint32_t
name|start
decl_stmt|;
comment|/* pa of start */
name|uint32_t
name|size
decl_stmt|;
comment|/* How big the ram disk is */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATAG_SERIAL - serial number  */
end_comment

begin_struct
struct|struct
name|arm_lbabi_serial_number
block|{
name|uint32_t
name|low
decl_stmt|;
name|uint32_t
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATAG_REVISION - board revision  */
end_comment

begin_struct
struct|struct
name|arm_lbabi_revision
block|{
name|uint32_t
name|rev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATAG_CMDLINE - Command line from uboot  */
end_comment

begin_struct
struct|struct
name|arm_lbabi_command_line
block|{
name|char
name|command
index|[
literal|1
index|]
decl_stmt|;
comment|/* Minimum command length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arm_lbabi_tag
block|{
name|struct
name|arm_lbabi_header
name|tag_hdr
decl_stmt|;
union|union
block|{
name|struct
name|arm_lbabi_core
name|tag_core
decl_stmt|;
name|struct
name|arm_lbabi_mem32
name|tag_mem
decl_stmt|;
name|struct
name|arm_lbabi_initrd
name|tag_initrd
decl_stmt|;
name|struct
name|arm_lbabi_serial_number
name|tag_sn
decl_stmt|;
name|struct
name|arm_lbabi_revision
name|tag_rev
decl_stmt|;
name|struct
name|arm_lbabi_command_line
name|tag_cmd
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATAG_TAG
parameter_list|(
name|a
parameter_list|)
value|(a)->tag_hdr.tag
end_define

begin_define
define|#
directive|define
name|ATAG_SIZE
parameter_list|(
name|a
parameter_list|)
value|(a)->tag_hdr.size
end_define

begin_define
define|#
directive|define
name|ATAG_NEXT
parameter_list|(
name|a
parameter_list|)
value|(struct arm_lbabi_tag *)((char *)(a) + ATAG_SIZE(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACHINE_ATAGS_H__ */
end_comment

end_unit

