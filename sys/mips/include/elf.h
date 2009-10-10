begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: elf_abi.h,v 1.1 1998/01/28 11:14:41 pefo Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 Per Fogelstrom  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed under OpenBSD by  *	Per Fogelstrom.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	JNPR: elf.h,v 1.4 2006/12/02 09:53:40 katta  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ELF_H_
end_define

begin_comment
comment|/* Information taken from MIPS ABI supplemental */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ELF_WORD_SIZE
end_ifndef

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|32
end_define

begin_comment
comment|/* Used by<sys/elf_generic.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_comment
comment|/* Definitions common to all 32 bit architectures. */
end_comment

begin_include
include|#
directive|include
file|<sys/elf64.h>
end_include

begin_comment
comment|/* Definitions common to all 64 bit architectures. */
end_comment

begin_include
include|#
directive|include
file|<sys/elf_generic.h>
end_include

begin_define
define|#
directive|define
name|ELF_ARCH
value|EM_MIPS
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == EM_MIPS || (x) == EM_MIPS_RS4_BE)
end_define

begin_comment
comment|/* Architecture dependent Segment types - p_type */
end_comment

begin_define
define|#
directive|define
name|PT_MIPS_REGINFO
value|0x70000000
end_define

begin_comment
comment|/* Register usage information */
end_comment

begin_comment
comment|/* Architecture dependent d_tag field for Elf32_Dyn.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_RLD_VERSION
value|0x70000001
end_define

begin_comment
comment|/* Runtime Linker Interface ID */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_TIME_STAMP
value|0x70000002
end_define

begin_comment
comment|/* Timestamp */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_ICHECKSUM
value|0x70000003
end_define

begin_comment
comment|/* Cksum of ext str and com sizes */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_IVERSION
value|0x70000004
end_define

begin_comment
comment|/* Version string (string tbl index) */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_FLAGS
value|0x70000005
end_define

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_BASE_ADDRESS
value|0x70000006
end_define

begin_comment
comment|/* Segment base address */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_CONFLICT
value|0x70000008
end_define

begin_comment
comment|/* Adr of .conflict section */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LIBLIST
value|0x70000009
end_define

begin_comment
comment|/* Address of .liblist section */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LOCAL_GOTNO
value|0x7000000a
end_define

begin_comment
comment|/* Number of local .GOT entries */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_CONFLICTNO
value|0x7000000b
end_define

begin_comment
comment|/* Number of .conflict entries */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LIBLISTNO
value|0x70000010
end_define

begin_comment
comment|/* Number of .liblist entries */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_SYMTABNO
value|0x70000011
end_define

begin_comment
comment|/* Number of .dynsym entries */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_UNREFEXTNO
value|0x70000012
end_define

begin_comment
comment|/* First external DYNSYM */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_GOTSYM
value|0x70000013
end_define

begin_comment
comment|/* First GOT entry in .dynsym */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_HIPAGENO
value|0x70000014
end_define

begin_comment
comment|/* Number of GOT page table entries */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_RLD_MAP
value|0x70000016
end_define

begin_comment
comment|/* Address of debug map pointer */
end_comment

begin_define
define|#
directive|define
name|DT_PROCNUM
value|(DT_MIPS_RLD_MAP - DT_LOPROC + 1)
end_define

begin_comment
comment|/*  * Legal values for e_flags field of Elf32_Ehdr.  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_NOREORDER
value|1
end_define

begin_comment
comment|/* .noreorder was used */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_PIC
value|2
end_define

begin_comment
comment|/* Contains PIC code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_CPIC
value|4
end_define

begin_comment
comment|/* Uses PIC calling sequence */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH
value|0xf0000000
end_define

begin_comment
comment|/* MIPS architecture level */
end_comment

begin_comment
comment|/*  * Mips special sections.  */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_ACOMMON
value|0xff00
end_define

begin_comment
comment|/* Allocated common symbols */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_SCOMMON
value|0xff03
end_define

begin_comment
comment|/* Small common symbols */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_SUNDEFINED
value|0xff04
end_define

begin_comment
comment|/* Small undefined symbols */
end_comment

begin_comment
comment|/*  * Legal values for sh_type field of Elf32_Shdr.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_LIBLIST
value|0x70000000
end_define

begin_comment
comment|/* Shared objects used in link */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_CONFLICT
value|0x70000002
end_define

begin_comment
comment|/* Conflicting symbols */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_GPTAB
value|0x70000003
end_define

begin_comment
comment|/* Global data area sizes */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_UCODE
value|0x70000004
end_define

begin_comment
comment|/* Reserved for SGI/MIPS compilers */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DEBUG
value|0x70000005
end_define

begin_comment
comment|/* MIPS ECOFF debugging information */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_REGINFO
value|0x70000006
end_define

begin_comment
comment|/* Register usage information */
end_comment

begin_comment
comment|/*  * Legal values for sh_flags field of Elf32_Shdr.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_GPREL
value|0x10000000
end_define

begin_comment
comment|/* Must be part of global data area */
end_comment

begin_comment
comment|/*  * Entries found in sections of type SHT_MIPS_GPTAB.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Elf32_Word
name|gt_current_g_value
decl_stmt|;
comment|/* -G val used in compilation */
name|Elf32_Word
name|gt_unused
decl_stmt|;
comment|/* Not used */
block|}
name|gt_header
struct|;
comment|/* First entry in section */
struct|struct
block|{
name|Elf32_Word
name|gt_g_value
decl_stmt|;
comment|/* If this val were used for -G */
name|Elf32_Word
name|gt_bytes
decl_stmt|;
comment|/* This many bytes would be used */
block|}
name|gt_entry
struct|;
comment|/* Subsequent entries in section */
block|}
name|Elf32_gptab
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Elf64_Word
name|gt_current_g_value
decl_stmt|;
comment|/* -G val used in compilation */
name|Elf64_Word
name|gt_unused
decl_stmt|;
comment|/* Not used */
block|}
name|gt_header
struct|;
comment|/* First entry in section */
struct|struct
block|{
name|Elf64_Word
name|gt_g_value
decl_stmt|;
comment|/* If this val were used for -G */
name|Elf64_Word
name|gt_bytes
decl_stmt|;
comment|/* This many bytes would be used */
block|}
name|gt_entry
struct|;
comment|/* Subsequent entries in section */
block|}
name|Elf64_gptab
typedef|;
end_typedef

begin_comment
comment|/*  * Entry found in sections of type SHT_MIPS_REGINFO.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|ri_gprmask
decl_stmt|;
comment|/* General registers used */
name|Elf32_Word
name|ri_cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* Coprocessor registers used */
name|Elf32_Sword
name|ri_gp_value
decl_stmt|;
comment|/* $gp register value */
block|}
name|Elf32_RegInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|ri_gprmask
decl_stmt|;
comment|/* General registers used */
name|Elf64_Word
name|ri_cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* Coprocessor registers used */
name|Elf64_Sword
name|ri_gp_value
decl_stmt|;
comment|/* $gp register value */
block|}
name|Elf64_RegInfo
typedef|;
end_typedef

begin_comment
comment|/*  * Mips relocations.  */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_NONE
value|0
end_define

begin_comment
comment|/* No reloc */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_16
value|1
end_define

begin_comment
comment|/* Direct 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_32
value|2
end_define

begin_comment
comment|/* Direct 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_REL32
value|3
end_define

begin_comment
comment|/* PC relative 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_26
value|4
end_define

begin_comment
comment|/* Direct 26 bit shifted */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_HI16
value|5
end_define

begin_comment
comment|/* High 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_LO16
value|6
end_define

begin_comment
comment|/* Low 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GPREL16
value|7
end_define

begin_comment
comment|/* GP relative 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_LITERAL
value|8
end_define

begin_comment
comment|/* 16 bit literal entry */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GOT16
value|9
end_define

begin_comment
comment|/* 16 bit GOT entry */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_PC16
value|10
end_define

begin_comment
comment|/* PC relative 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_CALL16
value|11
end_define

begin_comment
comment|/* 16 bit GOT entry for function */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GPREL32
value|12
end_define

begin_comment
comment|/* GP relative 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GOTHI16
value|21
end_define

begin_comment
comment|/* GOT HI 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GOTLO16
value|22
end_define

begin_comment
comment|/* GOT LO 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_CALLHI16
value|30
end_define

begin_comment
comment|/* upper 16 bit GOT entry for function */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_CALLLO16
value|31
end_define

begin_comment
comment|/* lower 16 bit GOT entry for function */
end_comment

begin_comment
comment|/*  * These are from the 64-bit Irix ELF ABI  */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_SHIFT5
value|16
end_define

begin_define
define|#
directive|define
name|R_MIPS_SHIFT6
value|17
end_define

begin_define
define|#
directive|define
name|R_MIPS_64
value|18
end_define

begin_define
define|#
directive|define
name|R_MIPS_GOT_DISP
value|19
end_define

begin_define
define|#
directive|define
name|R_MIPS_GOT_PAGE
value|20
end_define

begin_define
define|#
directive|define
name|R_MIPS_GOT_OFST
value|21
end_define

begin_define
define|#
directive|define
name|R_MIPS_GOT_HI16
value|22
end_define

begin_define
define|#
directive|define
name|R_MIPS_GOT_LO16
value|23
end_define

begin_define
define|#
directive|define
name|R_MIPS_SUB
value|24
end_define

begin_define
define|#
directive|define
name|R_MIPS_INSERT_A
value|25
end_define

begin_define
define|#
directive|define
name|R_MIPS_INSERT_B
value|26
end_define

begin_define
define|#
directive|define
name|R_MIPS_DELETE
value|27
end_define

begin_define
define|#
directive|define
name|R_MIPS_HIGHER
value|28
end_define

begin_define
define|#
directive|define
name|R_MIPS_HIGHEST
value|29
end_define

begin_define
define|#
directive|define
name|R_MIPS_SCN_DISP
value|32
end_define

begin_define
define|#
directive|define
name|R_MIPS_REL16
value|33
end_define

begin_define
define|#
directive|define
name|R_MIPS_ADD_IMMEDIATE
value|34
end_define

begin_define
define|#
directive|define
name|R_MIPS_PJUMP
value|35
end_define

begin_define
define|#
directive|define
name|R_MIPS_ERLGOT
value|36
end_define

begin_define
define|#
directive|define
name|R_MIPS_max
value|37
end_define

begin_define
define|#
directive|define
name|R_TYPE
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(R_MIPS_,name)
end_define

begin_comment
comment|/* Define "machine" characteristics */
end_comment

begin_if
if|#
directive|if
name|__ELF_WORD_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__MIPSEB__
end_ifdef

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2MSB
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2LSB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ELF_TARG_MACH
value|EM_MIPS
end_define

begin_define
define|#
directive|define
name|ELF_TARG_VER
value|1
end_define

begin_comment
comment|/*  * Auxiliary vector entries for passing information to the interpreter.  *  * The i386 supplement to the SVR4 ABI specification names this "auxv_t",  * but POSIX lays claim to all symbols ending with "_t".  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Auxiliary vector entry on initial stack */
name|int
name|a_type
decl_stmt|;
comment|/* Entry type. */
union|union
block|{
name|int
name|a_val
decl_stmt|;
comment|/* Integer value. */
name|void
modifier|*
name|a_ptr
decl_stmt|;
comment|/* Address. */
name|void
function_decl|(
modifier|*
name|a_fcn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Function pointer (not used). */
block|}
name|a_un
union|;
block|}
name|Elf32_Auxinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Auxiliary vector entry on initial stack */
name|long
name|a_type
decl_stmt|;
comment|/* Entry type. */
union|union
block|{
name|long
name|a_val
decl_stmt|;
comment|/* Integer value. */
name|void
modifier|*
name|a_ptr
decl_stmt|;
comment|/* Address. */
name|void
function_decl|(
modifier|*
name|a_fcn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Function pointer (not used). */
block|}
name|a_un
union|;
block|}
name|Elf64_Auxinfo
typedef|;
end_typedef

begin_expr_stmt
name|__ElfType
argument_list|(
name|Auxinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Values for a_type. */
end_comment

begin_define
define|#
directive|define
name|AT_NULL
value|0
end_define

begin_comment
comment|/* Terminates the vector. */
end_comment

begin_define
define|#
directive|define
name|AT_IGNORE
value|1
end_define

begin_comment
comment|/* Ignored entry. */
end_comment

begin_define
define|#
directive|define
name|AT_EXECFD
value|2
end_define

begin_comment
comment|/* File descriptor of program to load. */
end_comment

begin_define
define|#
directive|define
name|AT_PHDR
value|3
end_define

begin_comment
comment|/* Program header of program already loaded. */
end_comment

begin_define
define|#
directive|define
name|AT_PHENT
value|4
end_define

begin_comment
comment|/* Size of each program header entry. */
end_comment

begin_define
define|#
directive|define
name|AT_PHNUM
value|5
end_define

begin_comment
comment|/* Number of program header entries. */
end_comment

begin_define
define|#
directive|define
name|AT_PAGESZ
value|6
end_define

begin_comment
comment|/* Page size in bytes. */
end_comment

begin_define
define|#
directive|define
name|AT_BASE
value|7
end_define

begin_comment
comment|/* Interpreter's base address. */
end_comment

begin_define
define|#
directive|define
name|AT_FLAGS
value|8
end_define

begin_comment
comment|/* Flags (unused for i386). */
end_comment

begin_define
define|#
directive|define
name|AT_ENTRY
value|9
end_define

begin_comment
comment|/* Where interpreter should transfer control. */
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
comment|/* Real uid. */
end_comment

begin_define
define|#
directive|define
name|AT_EUID
value|12
end_define

begin_comment
comment|/* Effective uid. */
end_comment

begin_define
define|#
directive|define
name|AT_GID
value|13
end_define

begin_comment
comment|/* Real gid. */
end_comment

begin_define
define|#
directive|define
name|AT_EGID
value|14
end_define

begin_comment
comment|/* Effective gid. */
end_comment

begin_define
define|#
directive|define
name|AT_EXECPATH
value|15
end_define

begin_comment
comment|/* Path to the executable. */
end_comment

begin_define
define|#
directive|define
name|AT_COUNT
value|16
end_define

begin_comment
comment|/* Count of defined aux entry types. */
end_comment

begin_define
define|#
directive|define
name|ET_DYN_LOAD_ADDR
value|0x0120000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ELF_H_ */
end_comment

end_unit

