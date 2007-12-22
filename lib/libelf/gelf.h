begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_GELF_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_typedef
typedef|typedef
name|Elf64_Addr
name|GElf_Addr
typedef|;
end_typedef

begin_comment
comment|/* Addresses */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Half
name|GElf_Half
typedef|;
end_typedef

begin_comment
comment|/* Half words (16 bit) */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Off
name|GElf_Off
typedef|;
end_typedef

begin_comment
comment|/* Offsets */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Sword
name|GElf_Sword
typedef|;
end_typedef

begin_comment
comment|/* Signed words (32 bit) */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Sxword
name|GElf_Sxword
typedef|;
end_typedef

begin_comment
comment|/* Signed long words (64 bit) */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Word
name|GElf_Word
typedef|;
end_typedef

begin_comment
comment|/* Unsigned words (32 bit) */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Xword
name|GElf_Xword
typedef|;
end_typedef

begin_comment
comment|/* Unsigned long words (64 bit) */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Dyn
name|GElf_Dyn
typedef|;
end_typedef

begin_comment
comment|/* ".dynamic" section entries */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Ehdr
name|GElf_Ehdr
typedef|;
end_typedef

begin_comment
comment|/* ELF header */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Phdr
name|GElf_Phdr
typedef|;
end_typedef

begin_comment
comment|/* Program header */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Shdr
name|GElf_Shdr
typedef|;
end_typedef

begin_comment
comment|/* Section header */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Sym
name|GElf_Sym
typedef|;
end_typedef

begin_comment
comment|/* Symbol table entries */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Rel
name|GElf_Rel
typedef|;
end_typedef

begin_comment
comment|/* Relocation entries */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Rela
name|GElf_Rela
typedef|;
end_typedef

begin_comment
comment|/* Relocation entries with addend */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700025
end_if

begin_typedef
typedef|typedef
name|Elf64_Cap
name|GElf_Cap
typedef|;
end_typedef

begin_comment
comment|/* SW/HW capabilities */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Move
name|GElf_Move
typedef|;
end_typedef

begin_comment
comment|/* Move entries */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Syminfo
name|GElf_Syminfo
typedef|;
end_typedef

begin_comment
comment|/* Symbol information */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GELF_M_INFO
value|ELF64_M_INFO
end_define

begin_define
define|#
directive|define
name|GELF_M_SIZE
value|ELF64_M_SIZE
end_define

begin_define
define|#
directive|define
name|GELF_M_SYM
value|ELF64_M_SYM
end_define

begin_define
define|#
directive|define
name|GELF_R_INFO
value|ELF64_R_INFO
end_define

begin_define
define|#
directive|define
name|GELF_R_SYM
value|ELF64_R_SYM
end_define

begin_define
define|#
directive|define
name|GELF_R_TYPE
value|ELF64_R_TYPE
end_define

begin_define
define|#
directive|define
name|GELF_R_TYPE_DATA
value|ELF64_R_TYPE_DATA
end_define

begin_define
define|#
directive|define
name|GELF_R_TYPE_ID
value|ELF64_R_TYPE_ID
end_define

begin_define
define|#
directive|define
name|GELF_R_TYPE_INFO
value|ELF64_R_TYPE_INFO
end_define

begin_define
define|#
directive|define
name|GELF_ST_BIND
value|ELF64_ST_BIND
end_define

begin_define
define|#
directive|define
name|GELF_ST_INFO
value|ELF64_ST_INFO
end_define

begin_define
define|#
directive|define
name|GELF_ST_TYPE
value|ELF64_ST_TYPE
end_define

begin_define
define|#
directive|define
name|GELF_ST_VISIBILITY
value|ELF64_ST_VISIBILITY
end_define

begin_function_decl
name|__BEGIN_DECLS
name|long
name|gelf_checksum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|gelf_fsize
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Type
name|_type
parameter_list|,
name|size_t
name|_count
parameter_list|,
name|unsigned
name|int
name|_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_getclass
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Dyn
modifier|*
name|gelf_getdyn
parameter_list|(
name|Elf_Data
modifier|*
name|_data
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Dyn
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Ehdr
modifier|*
name|gelf_getehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|GElf_Ehdr
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Phdr
modifier|*
name|gelf_getphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Phdr
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Rel
modifier|*
name|gelf_getrel
parameter_list|(
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Rel
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Rela
modifier|*
name|gelf_getrela
parameter_list|(
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Rela
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Shdr
modifier|*
name|gelf_getshdr
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|,
name|GElf_Shdr
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Sym
modifier|*
name|gelf_getsym
parameter_list|(
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Sym
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Sym
modifier|*
name|gelf_getsymshndx
parameter_list|(
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|Elf_Data
modifier|*
name|_shindexsrc
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Sym
modifier|*
name|_dst
parameter_list|,
name|Elf32_Word
modifier|*
name|_shindexdst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|gelf_newehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|int
name|_class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|gelf_newphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
name|_phnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_dyn
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Dyn
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_ehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|GElf_Ehdr
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_phdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Phdr
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_rel
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Rel
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_rela
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Rela
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_shdr
parameter_list|(
name|Elf_Scn
modifier|*
name|_dst
parameter_list|,
name|GElf_Shdr
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_sym
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Sym
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_symshndx
parameter_list|(
name|Elf_Data
modifier|*
name|_symdst
parameter_list|,
name|Elf_Data
modifier|*
name|_shindexdst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Sym
modifier|*
name|_symsrc
parameter_list|,
name|Elf32_Word
name|_shindexsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|gelf_xlatetof
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|unsigned
name|int
name|_encode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|gelf_xlatetom
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|unsigned
name|int
name|_encode
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700025
end_if

begin_function_decl
name|GElf_Cap
modifier|*
name|gelf_getcap
parameter_list|(
name|Elf_Data
modifier|*
name|_data
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Cap
modifier|*
name|_cap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Move
modifier|*
name|gelf_getmove
parameter_list|(
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Move
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GElf_Syminfo
modifier|*
name|gelf_getsyminfo
parameter_list|(
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Syminfo
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_cap
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Cap
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_move
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Move
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gelf_update_syminfo
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
name|int
name|_index
parameter_list|,
name|GElf_Syminfo
modifier|*
name|_src
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GELF_H_ */
end_comment

end_unit

