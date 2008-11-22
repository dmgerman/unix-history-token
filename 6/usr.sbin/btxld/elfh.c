begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"elfh.h"
end_include

begin_define
define|#
directive|define
name|SET_ME
value|0xeeeeeeee
end_define

begin_comment
comment|/* filled in by btxld */
end_comment

begin_comment
comment|/*  * ELF header template.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|elfh
name|elfhdr
init|=
block|{
block|{
block|{
name|ELFMAG0
block|,
name|ELFMAG1
block|,
name|ELFMAG2
block|,
name|ELFMAG3
block|,
comment|/* e_ident */
name|ELFCLASS32
block|,
name|ELFDATA2LSB
block|,
name|EV_CURRENT
block|,
literal|0
block|,
literal|'F'
block|,
literal|'r'
block|,
literal|'e'
block|,
literal|'e'
block|,
literal|'B'
block|,
literal|'S'
block|,
literal|'D'
block|,
literal|0
block|}
block|,
name|htole16
argument_list|(
name|ET_EXEC
argument_list|)
block|,
comment|/* e_type */
name|htole16
argument_list|(
name|EM_386
argument_list|)
block|,
comment|/* e_machine */
name|htole32
argument_list|(
name|EV_CURRENT
argument_list|)
block|,
comment|/* e_version */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* e_entry */
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|elfh
argument_list|,
name|p
argument_list|)
argument_list|)
block|,
comment|/* e_phoff */
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|elfh
argument_list|,
name|sh
argument_list|)
argument_list|)
block|,
comment|/* e_shoff */
literal|0
block|,
comment|/* e_flags */
name|htole16
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|e
argument_list|)
argument_list|)
block|,
comment|/* e_ehsize */
name|htole16
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|p
index|[
literal|0
index|]
argument_list|)
argument_list|)
block|,
comment|/* e_phentsize */
name|htole16
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|p
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|p
index|[
literal|0
index|]
argument_list|)
argument_list|)
block|,
comment|/* e_phnum */
name|htole16
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|sh
index|[
literal|0
index|]
argument_list|)
argument_list|)
block|,
comment|/* e_shentsize */
name|htole16
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|sh
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|sh
index|[
literal|0
index|]
argument_list|)
argument_list|)
block|,
comment|/* e_shnum */
name|htole16
argument_list|(
literal|1
argument_list|)
comment|/* e_shstrndx */
block|}
block|,
block|{
block|{
name|htole32
argument_list|(
name|PT_LOAD
argument_list|)
block|,
comment|/* p_type */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
argument_list|)
argument_list|)
block|,
comment|/* p_offset */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_vaddr */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_paddr */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_filesz */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_memsz */
name|htole32
argument_list|(
name|PF_R
operator||
name|PF_X
argument_list|)
block|,
comment|/* p_flags */
name|htole32
argument_list|(
literal|0x1000
argument_list|)
comment|/* p_align */
block|}
block|,
block|{
name|htole32
argument_list|(
name|PT_LOAD
argument_list|)
block|,
comment|/* p_type */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_offset */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_vaddr */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_paddr */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_filesz */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* p_memsz */
name|htole32
argument_list|(
name|PF_R
operator||
name|PF_W
argument_list|)
block|,
comment|/* p_flags */
name|htole32
argument_list|(
literal|0x1000
argument_list|)
comment|/* p_align */
block|}
block|}
block|,
block|{
block|{
literal|0
block|,
name|htole32
argument_list|(
name|SHT_NULL
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|htole32
argument_list|(
name|SHN_UNDEF
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|htole32
argument_list|(
literal|1
argument_list|)
block|,
comment|/* sh_name */
name|htole32
argument_list|(
name|SHT_STRTAB
argument_list|)
block|,
comment|/* sh_type */
literal|0
block|,
comment|/* sh_flags */
literal|0
block|,
comment|/* sh_addr */
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|elfh
argument_list|,
name|shstrtab
argument_list|)
argument_list|)
block|,
comment|/* sh_offset */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
name|elfhdr
operator|.
name|shstrtab
argument_list|)
argument_list|)
block|,
comment|/* sh_size */
name|htole32
argument_list|(
name|SHN_UNDEF
argument_list|)
block|,
comment|/* sh_link */
literal|0
block|,
comment|/* sh_info */
name|htole32
argument_list|(
literal|1
argument_list|)
block|,
comment|/* sh_addralign */
literal|0
comment|/* sh_entsize */
block|}
block|,
block|{
name|htole32
argument_list|(
literal|0xb
argument_list|)
block|,
comment|/* sh_name */
name|htole32
argument_list|(
name|SHT_PROGBITS
argument_list|)
block|,
comment|/* sh_type */
name|htole32
argument_list|(
name|SHF_EXECINSTR
operator||
name|SHF_ALLOC
argument_list|)
block|,
comment|/* sh_flags */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* sh_addr */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* sh_offset */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* sh_size */
name|htole32
argument_list|(
name|SHN_UNDEF
argument_list|)
block|,
comment|/* sh_link */
literal|0
block|,
comment|/* sh_info */
name|htole32
argument_list|(
literal|4
argument_list|)
block|,
comment|/* sh_addralign */
literal|0
comment|/* sh_entsize */
block|}
block|,
block|{
name|htole32
argument_list|(
literal|0x11
argument_list|)
block|,
comment|/* sh_name */
name|htole32
argument_list|(
name|SHT_PROGBITS
argument_list|)
block|,
comment|/* sh_type */
name|htole32
argument_list|(
name|SHF_ALLOC
operator||
name|SHF_WRITE
argument_list|)
block|,
comment|/* sh_flags */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* sh_addr */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* sh_offset */
name|htole32
argument_list|(
name|SET_ME
argument_list|)
block|,
comment|/* sh_size */
name|htole32
argument_list|(
name|SHN_UNDEF
argument_list|)
block|,
comment|/* sh_link */
literal|0
block|,
comment|/* sh_info */
name|htole32
argument_list|(
literal|4
argument_list|)
block|,
comment|/* sh_addralign */
literal|0
comment|/* sh_entsize */
block|}
block|}
block|,
literal|"\0.shstrtab\0.text\0.data"
comment|/* shstrtab */
block|}
decl_stmt|;
end_decl_stmt

end_unit

