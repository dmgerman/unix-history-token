begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 David E. O'Brien  * Copyright (c) 1996-1997 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
value|1
end_define

begin_comment
comment|/*  * EABI ELF definitions for the PowerPC architecture.  * See "PowerPC Embedded Application Binary Interface, 32-Bit Impliementation"  * [ppc-eabi-1995-01.pdf] for details.  */
end_comment

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_comment
comment|/* Definitions common to all 32 bit architectures. */
end_comment

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|32
end_define

begin_comment
comment|/* Used by<sys/elf_generic.h> */
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
value|EM_PPC
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == EM_PPC)
end_define

begin_comment
comment|/*  * Auxiliary vector entries for passing information to the interpreter.  *  * The PowerPC supplement to the SVR4 ABI specification names this "auxv_t",  * but POSIX lays claim to all symbols ending with "_t".  */
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
name|Elf32_Auxinfo
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
comment|/* Flags (unused for PowerPC). */
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
name|AT_DCACHEBSIZE
value|10
end_define

begin_comment
comment|/* Data cache block size for the processor. */
end_comment

begin_define
define|#
directive|define
name|AT_ICACHEBSIZE
value|11
end_define

begin_comment
comment|/* Instruction cache block size for the uP. */
end_comment

begin_define
define|#
directive|define
name|AT_UCACHEBSIZE
value|12
end_define

begin_comment
comment|/* Cache block size, or `0' if cache not unified. */
end_comment

begin_define
define|#
directive|define
name|AT_COUNT
value|13
end_define

begin_comment
comment|/* Count of defined aux entry types. */
end_comment

begin_comment
comment|/* Used in John Polstra's testbed stuff. */
end_comment

begin_define
define|#
directive|define
name|AT_DEBUG
value|14
end_define

begin_comment
comment|/* Debugging level. */
end_comment

begin_comment
comment|/*  * Relocation types.  */
end_comment

begin_define
define|#
directive|define
name|R_PPC_NONE
value|0
end_define

begin_comment
comment|/* No relocation. */
end_comment

begin_define
define|#
directive|define
name|R_PPC_ADDR32
value|1
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR24
value|2
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR16
value|3
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR16_LO
value|4
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR16_HI
value|5
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR16_HA
value|6
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR14
value|7
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR14_BRTAKEN
value|8
end_define

begin_define
define|#
directive|define
name|R_PPC_ADDR14_BRNTAKEN
value|9
end_define

begin_define
define|#
directive|define
name|R_PPC_REL24
value|10
end_define

begin_define
define|#
directive|define
name|R_PPC_REL14
value|11
end_define

begin_define
define|#
directive|define
name|R_PPC_REL14_BRTAKEN
value|12
end_define

begin_define
define|#
directive|define
name|R_PPC_REL14_BRNTAKEN
value|13
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT16
value|14
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT16_LO
value|15
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT16_HI
value|16
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT16_HA
value|17
end_define

begin_define
define|#
directive|define
name|R_PPC_PLTREL24
value|18
end_define

begin_define
define|#
directive|define
name|R_PPC_COPY
value|19
end_define

begin_define
define|#
directive|define
name|R_PPC_GLOB_DAT
value|20
end_define

begin_define
define|#
directive|define
name|R_PPC_JMP_SLOT
value|21
end_define

begin_define
define|#
directive|define
name|R_PPC_RELATIVE
value|22
end_define

begin_define
define|#
directive|define
name|R_PPC_LOCAL24PC
value|23
end_define

begin_define
define|#
directive|define
name|R_PPC_UADDR32
value|24
end_define

begin_define
define|#
directive|define
name|R_PPC_UADDR16
value|25
end_define

begin_define
define|#
directive|define
name|R_PPC_REL32
value|26
end_define

begin_define
define|#
directive|define
name|R_PPC_PLT32
value|27
end_define

begin_define
define|#
directive|define
name|R_PPC_PLTREL32
value|28
end_define

begin_define
define|#
directive|define
name|R_PPC_PLT16_LO
value|29
end_define

begin_define
define|#
directive|define
name|R_PPC_PLT16_HI
value|30
end_define

begin_define
define|#
directive|define
name|R_PPC_PLT16_HA
value|31
end_define

begin_define
define|#
directive|define
name|R_PPC_SDAREL16
value|32
end_define

begin_define
define|#
directive|define
name|R_PPC_SECTOFF
value|33
end_define

begin_define
define|#
directive|define
name|R_PPC_SECTOFF_LO
value|34
end_define

begin_define
define|#
directive|define
name|R_PPC_SECTOFF_HI
value|35
end_define

begin_define
define|#
directive|define
name|R_PPC_SECTOFF_HA
value|36
end_define

begin_define
define|#
directive|define
name|R_PPC_COUNT
value|37
end_define

begin_comment
comment|/* Count of defined relocation types. */
end_comment

begin_comment
comment|/*  * TLS relocations  */
end_comment

begin_define
define|#
directive|define
name|R_PPC_TLS
value|67
end_define

begin_define
define|#
directive|define
name|R_PPC_DTPMOD32
value|68
end_define

begin_define
define|#
directive|define
name|R_PPC_TPREL16
value|69
end_define

begin_define
define|#
directive|define
name|R_PPC_TPREL16_LO
value|70
end_define

begin_define
define|#
directive|define
name|R_PPC_TPREL16_HI
value|71
end_define

begin_define
define|#
directive|define
name|R_PPC_TPREL16_HA
value|72
end_define

begin_define
define|#
directive|define
name|R_PPC_TPREL32
value|73
end_define

begin_define
define|#
directive|define
name|R_PPC_DTPREL16
value|74
end_define

begin_define
define|#
directive|define
name|R_PPC_DTPREL16_LO
value|75
end_define

begin_define
define|#
directive|define
name|R_PPC_DTPREL16_HI
value|76
end_define

begin_define
define|#
directive|define
name|R_PPC_DTPREL16_HA
value|77
end_define

begin_define
define|#
directive|define
name|R_PPC_DTPREL32
value|78
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSGD16
value|79
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSGD16_LO
value|80
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSGD16_HI
value|81
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSGD16_HA
value|82
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSLD16
value|83
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSLD16_LO
value|84
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSLD16_HI
value|85
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TLSLD16_HA
value|86
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TPREL16
value|87
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TPREL16_LO
value|88
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TPREL16_HI
value|89
end_define

begin_define
define|#
directive|define
name|R_PPC_GOT_TPREL16_HA
value|90
end_define

begin_comment
comment|/*  * The remaining relocs are from the Embedded ELF ABI, and are not in the  *  SVR4 ELF ABI.  */
end_comment

begin_define
define|#
directive|define
name|R_PPC_EMB_NADDR32
value|101
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_NADDR16
value|102
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_NADDR16_LO
value|103
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_NADDR16_HI
value|104
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_NADDR16_HA
value|105
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_SDAI16
value|106
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_SDA2I16
value|107
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_SDA2REL
value|108
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_SDA21
value|109
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_MRKREF
value|110
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_RELSEC16
value|111
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_RELST_LO
value|112
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_RELST_HI
value|113
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_RELST_HA
value|114
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_BIT_FLD
value|115
end_define

begin_define
define|#
directive|define
name|R_PPC_EMB_RELSDA
value|116
end_define

begin_comment
comment|/* Count of defined relocation types. */
end_comment

begin_define
define|#
directive|define
name|R_PPC_EMB_COUNT
value|(R_PPC_EMB_RELSDA - R_PPC_EMB_NADDR32 + 1)
end_define

begin_comment
comment|/* Define "machine" characteristics */
end_comment

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS32
end_define

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2MSB
end_define

begin_define
define|#
directive|define
name|ELF_TARG_MACH
value|EM_PPC
end_define

begin_define
define|#
directive|define
name|ELF_TARG_VER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ELF_H_ */
end_comment

end_unit

