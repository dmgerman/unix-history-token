begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
file|"elfhdr.h"
end_include

begin_define
define|#
directive|define
name|KGZ_FIX_NSIZE
value|0
end_define

begin_comment
comment|/* Run-time fixup */
end_comment

begin_comment
comment|/*  * Relocatable header template.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|kgz_elfhdr
name|elfhdr
init|=
block|{
comment|/* ELF header */
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
literal|0
block|,
comment|/* e_entry */
literal|0
block|,
comment|/* e_phoff */
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|kgz_elfhdr
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
name|Elf32_Ehdr
argument_list|)
argument_list|)
block|,
comment|/* e_ehsize */
literal|0
block|,
comment|/* e_phentsize */
literal|0
block|,
comment|/* e_phnum */
name|htole16
argument_list|(
sizeof|sizeof
argument_list|(
name|Elf32_Shdr
argument_list|)
argument_list|)
block|,
comment|/* e_shentsize */
name|htole16
argument_list|(
name|KGZ_SHNUM
argument_list|)
block|,
comment|/* e_shnum */
name|htole16
argument_list|(
argument|KGZ_SH_SHSTRTAB
argument_list|)
comment|/* e_shstrndx */
block|}
block|,
comment|/* Section header */
block|{
block|{
literal|0
block|,
comment|/* sh_name */
name|htole32
argument_list|(
name|SHT_NULL
argument_list|)
block|,
comment|/* sh_type */
literal|0
block|,
comment|/* sh_flags */
literal|0
block|,
comment|/* sh_addr */
literal|0
block|,
comment|/* sh_offset */
literal|0
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
literal|0
block|,
comment|/* sh_addralign */
literal|0
comment|/* sh_entsize */
block|}
block|,
block|{
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|kgz_shstrtab
argument_list|,
name|symtab
argument_list|)
argument_list|)
block|,
comment|/* sh_name */
name|htole32
argument_list|(
name|SHT_SYMTAB
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
name|kgz_elfhdr
argument_list|,
name|st
argument_list|)
argument_list|)
block|,
comment|/* sh_offset */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
name|Elf32_Sym
argument_list|)
operator|*
name|KGZ_STNUM
argument_list|)
block|,
comment|/* sh_size */
name|htole32
argument_list|(
name|KGZ_SH_STRTAB
argument_list|)
block|,
comment|/* sh_link */
name|htole32
argument_list|(
literal|1
argument_list|)
block|,
comment|/* sh_info */
name|htole32
argument_list|(
literal|4
argument_list|)
block|,
comment|/* sh_addralign */
name|htole32
argument_list|(
argument|sizeof(Elf32_Sym)
argument_list|)
comment|/* sh_entsize */
block|}
block|,
block|{
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|kgz_shstrtab
argument_list|,
name|shstrtab
argument_list|)
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
name|kgz_elfhdr
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
expr|struct
name|kgz_shstrtab
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
name|offsetof
argument_list|(
expr|struct
name|kgz_shstrtab
argument_list|,
name|strtab
argument_list|)
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
name|kgz_elfhdr
argument_list|,
name|strtab
argument_list|)
argument_list|)
block|,
comment|/* sh_offset */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|kgz_strtab
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
name|offsetof
argument_list|(
expr|struct
name|kgz_shstrtab
argument_list|,
name|data
argument_list|)
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
literal|0
block|,
comment|/* sh_addr */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|kgz_elfhdr
argument_list|)
argument_list|)
block|,
comment|/* sh_offset */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|kgz_hdr
argument_list|)
operator|+
name|KGZ_FIX_NSIZE
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
comment|/* Symbol table */
block|{
block|{
literal|0
block|,
comment|/* st_name */
literal|0
block|,
comment|/* st_value */
literal|0
block|,
comment|/* st_size */
literal|0
block|,
comment|/* st_info */
literal|0
block|,
comment|/* st_other */
name|htole16
argument_list|(
argument|SHN_UNDEF
argument_list|)
comment|/* st_shndx */
block|}
block|,
block|{
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|kgz_strtab
argument_list|,
name|kgz
argument_list|)
argument_list|)
block|,
comment|/* st_name */
literal|0
block|,
comment|/* st_value */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|kgz_hdr
argument_list|)
argument_list|)
block|,
comment|/* st_size */
name|ELF32_ST_INFO
argument_list|(
name|STB_GLOBAL
argument_list|,
name|STT_OBJECT
argument_list|)
block|,
comment|/* st_info */
literal|0
block|,
comment|/* st_other */
name|htole16
argument_list|(
argument|KGZ_SH_DATA
argument_list|)
comment|/* st_shndx */
block|}
block|,
block|{
name|htole32
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|kgz_strtab
argument_list|,
name|kgz_ndata
argument_list|)
argument_list|)
block|,
comment|/* st_name */
name|htole32
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|kgz_hdr
argument_list|)
argument_list|)
block|,
comment|/* st_value */
name|htole32
argument_list|(
name|KGZ_FIX_NSIZE
argument_list|)
block|,
comment|/* st_size */
name|ELF32_ST_INFO
argument_list|(
name|STB_GLOBAL
argument_list|,
name|STT_OBJECT
argument_list|)
block|,
comment|/* st_info */
literal|0
block|,
comment|/* st_other */
name|htole16
argument_list|(
argument|KGZ_SH_DATA
argument_list|)
comment|/* st_shndx */
block|}
block|}
block|,
comment|/* Section header string table */
block|{
name|KGZ_SHSTR_ZERO
block|,
comment|/* zero */
name|KGZ_SHSTR_SYMTAB
block|,
comment|/* symtab */
name|KGZ_SHSTR_SHSTRTAB
block|,
comment|/* shstrtab */
name|KGZ_SHSTR_STRTAB
block|,
comment|/* strtab */
name|KGZ_SHSTR_DATA
comment|/* data */
block|}
block|,
comment|/* String table */
block|{
name|KGZ_STR_ZERO
block|,
comment|/* zero */
name|KGZ_STR_KGZ
block|,
comment|/* kgz */
name|KGZ_STR_KGZ_NDATA
comment|/* kgz_ndata */
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

