begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995-1996 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: imgact_elf.h,v 1.1 1996/03/10 08:42:52 sos Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMGACT_ELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_IMGACT_ELF_H_
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|Elf32_Sword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|Elf32_Half
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|elf_trace
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EI_NINDENT
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NINDENT
index|]
decl_stmt|;
comment|/* file id */
name|Elf32_Half
name|e_type
decl_stmt|;
comment|/* type */
name|Elf32_Half
name|e_machine
decl_stmt|;
comment|/* machine type */
name|Elf32_Word
name|e_version
decl_stmt|;
comment|/* version number */
name|Elf32_Addr
name|e_entry
decl_stmt|;
comment|/* entry point */
name|Elf32_Off
name|e_phoff
decl_stmt|;
comment|/* program hdr offset */
name|Elf32_Off
name|e_shoff
decl_stmt|;
comment|/* section hdr offset */
name|Elf32_Word
name|e_flags
decl_stmt|;
comment|/* flags */
name|Elf32_Half
name|e_ehsize
decl_stmt|;
comment|/* sizeof ehdr */
name|Elf32_Half
name|e_phentsize
decl_stmt|;
comment|/* program header entry size */
name|Elf32_Half
name|e_phnum
decl_stmt|;
comment|/* number of program headers */
name|Elf32_Half
name|e_shentsize
decl_stmt|;
comment|/* section header entry size */
name|Elf32_Half
name|e_shnum
decl_stmt|;
comment|/* number of section headers */
name|Elf32_Half
name|e_shstrndx
decl_stmt|;
comment|/* string table index */
block|}
name|Elf32_Ehdr
typedef|;
end_typedef

begin_comment
comment|/*  * Values for e_indent entry in struct Elf32_Ehdr.  */
end_comment

begin_define
define|#
directive|define
name|EI_MAG0
value|0
end_define

begin_define
define|#
directive|define
name|EI_MAG1
value|1
end_define

begin_define
define|#
directive|define
name|EI_MAG2
value|2
end_define

begin_define
define|#
directive|define
name|EI_MAG3
value|3
end_define

begin_define
define|#
directive|define
name|EI_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|EI_DATA
value|5
end_define

begin_define
define|#
directive|define
name|EI_VERSION
value|6
end_define

begin_define
define|#
directive|define
name|EI_SPARE
value|8
end_define

begin_define
define|#
directive|define
name|EI_BRAND
value|8
end_define

begin_define
define|#
directive|define
name|ELFMAG0
value|'\177'
end_define

begin_define
define|#
directive|define
name|ELFMAG1
value|'E'
end_define

begin_define
define|#
directive|define
name|ELFMAG2
value|'L'
end_define

begin_define
define|#
directive|define
name|ELFMAG3
value|'F'
end_define

begin_define
define|#
directive|define
name|ELFCLASSNONE
value|0
end_define

begin_comment
comment|/* invalid class */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS32
value|1
end_define

begin_comment
comment|/* 32bit object class */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS64
value|2
end_define

begin_comment
comment|/* 64bit object class */
end_comment

begin_define
define|#
directive|define
name|ELFDATANONE
value|0
end_define

begin_comment
comment|/* invalid data encoding */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2LSB
value|1
end_define

begin_comment
comment|/* little endian */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2MSB
value|2
end_define

begin_comment
comment|/* big endian */
end_comment

begin_comment
comment|/*  * Values for e_version entry in struct Elf32_Ehdr.  */
end_comment

begin_define
define|#
directive|define
name|EV_NONE
value|0
end_define

begin_comment
comment|/* invalid version */
end_comment

begin_define
define|#
directive|define
name|EV_CURRENT
value|1
end_define

begin_comment
comment|/* current version */
end_comment

begin_comment
comment|/*  * Values for e_type entry in struct Elf32_Ehdr.  */
end_comment

begin_define
define|#
directive|define
name|ET_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ET_REL
value|1
end_define

begin_define
define|#
directive|define
name|ET_EXEC
value|2
end_define

begin_define
define|#
directive|define
name|ET_DYN
value|3
end_define

begin_define
define|#
directive|define
name|ET_CORE
value|4
end_define

begin_define
define|#
directive|define
name|ET_LOPROC
value|5
end_define

begin_define
define|#
directive|define
name|ET_HIPROC
value|6
end_define

begin_comment
comment|/*  * Values for e_machine entry in struct Elf32_Ehdr.  */
end_comment

begin_define
define|#
directive|define
name|EM_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EM_M32
value|1
end_define

begin_define
define|#
directive|define
name|EM_SPARC
value|2
end_define

begin_define
define|#
directive|define
name|EM_386
value|3
end_define

begin_define
define|#
directive|define
name|EM_68K
value|4
end_define

begin_define
define|#
directive|define
name|EM_88K
value|5
end_define

begin_define
define|#
directive|define
name|EM_486
value|6
end_define

begin_define
define|#
directive|define
name|EM_860
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|p_type
decl_stmt|;
comment|/* entry type */
name|Elf32_Off
name|p_offset
decl_stmt|;
comment|/* offset */
name|Elf32_Addr
name|p_vaddr
decl_stmt|;
comment|/* virtual address */
name|Elf32_Addr
name|p_paddr
decl_stmt|;
comment|/* physical address */
name|Elf32_Word
name|p_filesz
decl_stmt|;
comment|/* file size */
name|Elf32_Word
name|p_memsz
decl_stmt|;
comment|/* memory size */
name|Elf32_Word
name|p_flags
decl_stmt|;
comment|/* flags */
name|Elf32_Word
name|p_align
decl_stmt|;
comment|/* memory& file alignment */
block|}
name|Elf32_Phdr
typedef|;
end_typedef

begin_comment
comment|/*  * Values for p_type entry in struct Elf32_Phdr.  */
end_comment

begin_define
define|#
directive|define
name|PT_NULL
value|0
end_define

begin_define
define|#
directive|define
name|PT_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|PT_DYNAMIC
value|2
end_define

begin_define
define|#
directive|define
name|PT_INTERP
value|3
end_define

begin_define
define|#
directive|define
name|PT_NOTE
value|4
end_define

begin_define
define|#
directive|define
name|PT_SHLIB
value|5
end_define

begin_define
define|#
directive|define
name|PT_PHDR
value|6
end_define

begin_define
define|#
directive|define
name|PT_LOPROC
value|0x70000000
end_define

begin_define
define|#
directive|define
name|PT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/*  * Values for p_flags entry in struct Elf32_Phdr.  */
end_comment

begin_define
define|#
directive|define
name|PF_X
value|0x1
end_define

begin_define
define|#
directive|define
name|PF_W
value|0x2
end_define

begin_define
define|#
directive|define
name|PF_R
value|0x4
end_define

begin_define
define|#
directive|define
name|PF_MASKPROC
value|0xf0000000
end_define

begin_comment
comment|/*  * Auxiliary vector entry on initial stack.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Sword
name|a_type
decl_stmt|;
name|Elf32_Word
name|a_val
decl_stmt|;
block|}
name|Elf32_Auxinfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AUXARGS_ENTRY
parameter_list|(
name|pos
parameter_list|,
name|id
parameter_list|,
name|val
parameter_list|)
value|{suword(pos++, id); suword(pos++, val);}
end_define

begin_comment
comment|/*   * Values for a_type in struct Elf32_Auxinfo.  */
end_comment

begin_define
define|#
directive|define
name|AT_NULL
value|0
end_define

begin_comment
comment|/* Terminates the vector */
end_comment

begin_define
define|#
directive|define
name|AT_IGNORE
value|1
end_define

begin_comment
comment|/* Ignored */
end_comment

begin_define
define|#
directive|define
name|AT_EXECFD
value|2
end_define

begin_comment
comment|/* File descriptor of program to load */
end_comment

begin_define
define|#
directive|define
name|AT_PHDR
value|3
end_define

begin_comment
comment|/* Program header of program already loaded */
end_comment

begin_define
define|#
directive|define
name|AT_PHENT
value|4
end_define

begin_comment
comment|/* Size of each program header entry */
end_comment

begin_define
define|#
directive|define
name|AT_PHNUM
value|5
end_define

begin_comment
comment|/* Number of program header entries */
end_comment

begin_define
define|#
directive|define
name|AT_PAGESZ
value|6
end_define

begin_comment
comment|/* Page size in bytes */
end_comment

begin_define
define|#
directive|define
name|AT_BASE
value|7
end_define

begin_comment
comment|/* Interpreter's base address */
end_comment

begin_define
define|#
directive|define
name|AT_FLAGS
value|8
end_define

begin_comment
comment|/* Flags (unused for i386) */
end_comment

begin_define
define|#
directive|define
name|AT_ENTRY
value|9
end_define

begin_comment
comment|/* Where interpreter should transfer control */
end_comment

begin_comment
comment|/*  * The following non-standard values are used for passing information  * to the (FreeBSD ELF) dynamic linker. Will probably go away soon....  */
end_comment

begin_define
define|#
directive|define
name|AT_BRK
value|10
end_define

begin_comment
comment|/* Starting point for sbrk and brk */
end_comment

begin_define
define|#
directive|define
name|AT_DEBUG
value|11
end_define

begin_comment
comment|/* Debugging level */
end_comment

begin_define
define|#
directive|define
name|AT_COUNT
value|15
end_define

begin_comment
comment|/*  * The following non-standard values are used in Linux ELF binaries.  */
end_comment

begin_define
define|#
directive|define
name|AT_NOTELF
value|10
end_define

begin_comment
comment|/* Program is not ELF ?? */
end_comment

begin_define
define|#
directive|define
name|AT_UID
value|11
end_define

begin_comment
comment|/* Real uid */
end_comment

begin_define
define|#
directive|define
name|AT_EUID
value|12
end_define

begin_comment
comment|/* Effective uid */
end_comment

begin_define
define|#
directive|define
name|AT_GID
value|13
end_define

begin_comment
comment|/* Real gid */
end_comment

begin_define
define|#
directive|define
name|AT_EGID
value|14
end_define

begin_comment
comment|/* Effective gid */
end_comment

begin_comment
comment|/*  * Structure used to pass infomation from the loader to the  * stack fixup routine.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Sword
name|execfd
decl_stmt|;
name|Elf32_Word
name|phdr
decl_stmt|;
name|Elf32_Word
name|phent
decl_stmt|;
name|Elf32_Word
name|phnum
decl_stmt|;
name|Elf32_Word
name|pagesz
decl_stmt|;
name|Elf32_Word
name|base
decl_stmt|;
name|Elf32_Word
name|flags
decl_stmt|;
name|Elf32_Word
name|entry
decl_stmt|;
name|Elf32_Word
name|trace
decl_stmt|;
block|}
name|Elf32_Auxargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|brand
decl_stmt|;
name|char
modifier|*
name|emul_path
decl_stmt|;
name|char
modifier|*
name|interp_path
decl_stmt|;
name|struct
name|sysentvec
modifier|*
name|sysvec
decl_stmt|;
block|}
name|Elf32_Brandinfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_BRANDS
value|8
end_define

begin_decl_stmt
name|int
name|elf_insert_brand_entry
name|__P
argument_list|(
operator|(
name|Elf32_Brandinfo
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|elf_remove_brand_entry
name|__P
argument_list|(
operator|(
name|Elf32_Brandinfo
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IMGACT_ELF_H_ */
end_comment

end_unit

