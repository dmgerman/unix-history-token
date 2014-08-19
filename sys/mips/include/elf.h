begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 M. Warner Losh. All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * See below starting with the line with $NetBSD...$ for code this applies to.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MIPS_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|__MIPS_ELF_H
end_define

begin_comment
comment|/* FreeBSD specific bits - derived from FreeBSD specific files and changes to old elf.h */
end_comment

begin_comment
comment|/*  * Define __ELF_WORD_SIZE based on the ABI, if not defined yet. This sets  * the proper defaults when we're not trying to do 32-bit on 64-bit systems.  * We include both 32 and 64 bit versions so we can support multiple ABIs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ELF_WORD_SIZE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_include
include|#
directive|include
file|<sys/elf64.h>
end_include

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
name|ELF_ARCH32
value|EM_MIPS
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == ELF_ARCH)
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
name|AT_CANARY
value|16
end_define

begin_comment
comment|/* Canary for SSP */
end_comment

begin_define
define|#
directive|define
name|AT_CANARYLEN
value|17
end_define

begin_comment
comment|/* Length of the canary. */
end_comment

begin_define
define|#
directive|define
name|AT_OSRELDATE
value|18
end_define

begin_comment
comment|/* OSRELDATE. */
end_comment

begin_define
define|#
directive|define
name|AT_NCPUS
value|19
end_define

begin_comment
comment|/* Number of CPUs. */
end_comment

begin_define
define|#
directive|define
name|AT_PAGESIZES
value|20
end_define

begin_comment
comment|/* Pagesizes. */
end_comment

begin_define
define|#
directive|define
name|AT_PAGESIZESLEN
value|21
end_define

begin_comment
comment|/* Number of pagesizes. */
end_comment

begin_define
define|#
directive|define
name|AT_TIMEKEEP
value|22
end_define

begin_comment
comment|/* Pointer to timehands. */
end_comment

begin_define
define|#
directive|define
name|AT_STACKPROT
value|23
end_define

begin_comment
comment|/* Initial stack protection. */
end_comment

begin_define
define|#
directive|define
name|AT_COUNT
value|24
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

begin_comment
comment|/*  * Constant to mark start of symtab/strtab saved by trampoline  */
end_comment

begin_define
define|#
directive|define
name|SYMTAB_MAGIC
value|0x64656267
end_define

begin_comment
comment|/* from NetBSD's sys/mips/include/elf_machdep.h $NetBSD: elf_machdep.h,v 1.18 2013/05/23 21:39:49 christos Exp $ */
end_comment

begin_comment
comment|/* mips relocs. */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|R_MIPS_16
value|1
end_define

begin_define
define|#
directive|define
name|R_MIPS_32
value|2
end_define

begin_define
define|#
directive|define
name|R_MIPS_REL32
value|3
end_define

begin_define
define|#
directive|define
name|R_MIPS_REL
value|R_MIPS_REL32
end_define

begin_define
define|#
directive|define
name|R_MIPS_26
value|4
end_define

begin_define
define|#
directive|define
name|R_MIPS_HI16
value|5
end_define

begin_comment
comment|/* high 16 bits of symbol value */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_LO16
value|6
end_define

begin_comment
comment|/* low 16 bits of symbol value */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GPREL16
value|7
end_define

begin_comment
comment|/* GP-relative reference  */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_LITERAL
value|8
end_define

begin_comment
comment|/* Reference to literal section  */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GOT16
value|9
end_define

begin_comment
comment|/* Reference to global offset table */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_GOT
value|R_MIPS_GOT16
end_define

begin_define
define|#
directive|define
name|R_MIPS_PC16
value|10
end_define

begin_comment
comment|/* 16 bit PC relative reference */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_CALL16
value|11
end_define

begin_comment
comment|/* 16 bit call thru glbl offset tbl */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_CALL
value|R_MIPS_CALL16
end_define

begin_define
define|#
directive|define
name|R_MIPS_GPREL32
value|12
end_define

begin_comment
comment|/* 13, 14, 15 are not defined at this point. */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_UNUSED1
value|13
end_define

begin_define
define|#
directive|define
name|R_MIPS_UNUSED2
value|14
end_define

begin_define
define|#
directive|define
name|R_MIPS_UNUSED3
value|15
end_define

begin_comment
comment|/*  * The remaining relocs are apparently part of the 64-bit Irix ELF ABI.  */
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
name|R_MIPS_CALL_HI16
value|30
end_define

begin_define
define|#
directive|define
name|R_MIPS_CALL_LO16
value|31
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
name|R_MIPS_RELGOT
value|36
end_define

begin_define
define|#
directive|define
name|R_MIPS_JALR
value|37
end_define

begin_comment
comment|/* TLS relocations */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_DTPMOD32
value|38
end_define

begin_comment
comment|/* Module number 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_DTPREL32
value|39
end_define

begin_comment
comment|/* Module-relative offset 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_DTPMOD64
value|40
end_define

begin_comment
comment|/* Module number 64 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_DTPREL64
value|41
end_define

begin_comment
comment|/* Module-relative offset 64 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_GD
value|42
end_define

begin_comment
comment|/* 16 bit GOT offset for GD */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_LDM
value|43
end_define

begin_comment
comment|/* 16 bit GOT offset for LDM */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_DTPREL_HI16
value|44
end_define

begin_comment
comment|/* Module-relative offset, high 16 bits */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_DTPREL_LO16
value|45
end_define

begin_comment
comment|/* Module-relative offset, low 16 bits */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_GOTTPREL
value|46
end_define

begin_comment
comment|/* 16 bit GOT offset for IE */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_TPREL32
value|47
end_define

begin_comment
comment|/* TP-relative offset, 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_TPREL64
value|48
end_define

begin_comment
comment|/* TP-relative offset, 64 bit */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_TPREL_HI16
value|49
end_define

begin_comment
comment|/* TP-relative offset, high 16 bits */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_TLS_TPREL_LO16
value|50
end_define

begin_comment
comment|/* TP-relative offset, low 16 bits */
end_comment

begin_define
define|#
directive|define
name|R_MIPS_max
value|51
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

begin_define
define|#
directive|define
name|R_MIPS16_min
value|100
end_define

begin_define
define|#
directive|define
name|R_MIPS16_26
value|100
end_define

begin_define
define|#
directive|define
name|R_MIPS16_GPREL
value|101
end_define

begin_define
define|#
directive|define
name|R_MIPS16_GOT16
value|102
end_define

begin_define
define|#
directive|define
name|R_MIPS16_CALL16
value|103
end_define

begin_define
define|#
directive|define
name|R_MIPS16_HI16
value|104
end_define

begin_define
define|#
directive|define
name|R_MIPS16_LO16
value|105
end_define

begin_define
define|#
directive|define
name|R_MIPS16_max
value|106
end_define

begin_define
define|#
directive|define
name|R_MIPS_COPY
value|126
end_define

begin_define
define|#
directive|define
name|R_MIPS_JUMP_SLOT
value|127
end_define

begin_comment
comment|/* mips dynamic tags */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_RLD_VERSION
value|0x70000001
end_define

begin_define
define|#
directive|define
name|DT_MIPS_TIME_STAMP
value|0x70000002
end_define

begin_define
define|#
directive|define
name|DT_MIPS_ICHECKSUM
value|0x70000003
end_define

begin_define
define|#
directive|define
name|DT_MIPS_IVERSION
value|0x70000004
end_define

begin_define
define|#
directive|define
name|DT_MIPS_FLAGS
value|0x70000005
end_define

begin_define
define|#
directive|define
name|DT_MIPS_BASE_ADDRESS
value|0x70000006
end_define

begin_define
define|#
directive|define
name|DT_MIPS_CONFLICT
value|0x70000008
end_define

begin_define
define|#
directive|define
name|DT_MIPS_LIBLIST
value|0x70000009
end_define

begin_define
define|#
directive|define
name|DT_MIPS_CONFLICTNO
value|0x7000000b
end_define

begin_define
define|#
directive|define
name|DT_MIPS_LOCAL_GOTNO
value|0x7000000a
end_define

begin_comment
comment|/* number of local got ents */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LIBLISTNO
value|0x70000010
end_define

begin_define
define|#
directive|define
name|DT_MIPS_SYMTABNO
value|0x70000011
end_define

begin_comment
comment|/* number of .dynsym entries */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_UNREFEXTNO
value|0x70000012
end_define

begin_define
define|#
directive|define
name|DT_MIPS_GOTSYM
value|0x70000013
end_define

begin_comment
comment|/* first dynamic sym in got */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_HIPAGENO
value|0x70000014
end_define

begin_define
define|#
directive|define
name|DT_MIPS_RLD_MAP
value|0x70000016
end_define

begin_comment
comment|/* address of loader map */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_PLTGOT
value|0x70000032
end_define

begin_define
define|#
directive|define
name|DT_MIPS_RWPLT
value|0x70000034
end_define

begin_comment
comment|/*  * ELF Flags  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_PIC
value|0x00000002
end_define

begin_comment
comment|/* Contains PIC code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_CPIC
value|0x00000004
end_define

begin_comment
comment|/* STD PIC calling sequence */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ABI2
value|0x00000020
end_define

begin_comment
comment|/* N32 */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_ASE
value|0x0f000000
end_define

begin_comment
comment|/* Architectural extensions */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_MDMX
value|0x08000000
end_define

begin_comment
comment|/* MDMX multimedia extension */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_M16
value|0x04000000
end_define

begin_comment
comment|/* MIPS-16 ISA extensions */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH
value|0xf0000000
end_define

begin_comment
comment|/* Architecture field */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_1
value|0x00000000
end_define

begin_comment
comment|/* -mips1 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_2
value|0x10000000
end_define

begin_comment
comment|/* -mips2 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_3
value|0x20000000
end_define

begin_comment
comment|/* -mips3 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_4
value|0x30000000
end_define

begin_comment
comment|/* -mips4 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_5
value|0x40000000
end_define

begin_comment
comment|/* -mips5 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_32
value|0x50000000
end_define

begin_comment
comment|/* -mips32 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_64
value|0x60000000
end_define

begin_comment
comment|/* -mips64 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_32R2
value|0x70000000
end_define

begin_comment
comment|/* -mips32r2 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_64R2
value|0x80000000
end_define

begin_comment
comment|/* -mips64r2 code */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ABI
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|EF_MIPS_ABI_O32
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EF_MIPS_ABI_O64
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EF_MIPS_ABI_EABI32
value|0x00003000
end_define

begin_define
define|#
directive|define
name|EF_MIPS_ABI_EABI64
value|0x00004000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MIPS_ELF_H */
end_comment

end_unit

