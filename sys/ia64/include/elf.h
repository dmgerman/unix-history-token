begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996-1997 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * ELF definitions for the IA-64 architecture.  */
end_comment

begin_include
include|#
directive|include
file|<sys/elf64.h>
end_include

begin_comment
comment|/* Definitions common to all 64 bit architectures. */
end_comment

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|64
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
value|EM_IA_64
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == EM_IA_64)
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
comment|/*  * Types of dynamic symbol hash table bucket and chain elements.  *  * This is inconsistent among 64 bit architectures, so a machine dependent  * typedef is required.  */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Half
name|Elf64_Hashelt
typedef|;
end_typedef

begin_expr_stmt
name|__ElfType
argument_list|(
name|Hashelt
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

begin_comment
comment|/*  * The following non-standard values are used for passing information  * from John Polstra's testbed program to the dynamic linker.  These  * are expected to go away soon.  *  * Unfortunately, these overlap the Linux non-standard values, so they  * must not be used in the same context.  */
end_comment

begin_define
define|#
directive|define
name|AT_BRK
value|10
end_define

begin_comment
comment|/* Starting point for sbrk and brk. */
end_comment

begin_define
define|#
directive|define
name|AT_DEBUG
value|11
end_define

begin_comment
comment|/* Debugging level. */
end_comment

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
name|AT_COUNT
value|15
end_define

begin_comment
comment|/* Count of defined aux entry types. */
end_comment

begin_comment
comment|/*  * Values for e_flags.  */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_MASKOS
value|0x00ff000f
end_define

begin_define
define|#
directive|define
name|EF_IA_64_ABI64
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EF_IA_64_REDUCEDFP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EF_IA_64_CONS_GP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EF_IA_64_NOFUNCDESC_CONS_GP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EF_IA_64_ABSOLUTE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EF_IA_64_ARCH
value|0xff000000
end_define

begin_comment
comment|/*  * Segment types.  */
end_comment

begin_define
define|#
directive|define
name|PT_IA_64_ARCHEXT
value|0x70000000
end_define

begin_define
define|#
directive|define
name|PT_IA_64_UNWIND
value|0x70000001
end_define

begin_comment
comment|/*  * Segment attributes.  */
end_comment

begin_define
define|#
directive|define
name|PF_IA_64_NORECOV
value|0x80000000
end_define

begin_comment
comment|/*  * Section types.  */
end_comment

begin_define
define|#
directive|define
name|SHT_IA_64_EXT
value|0x70000000
end_define

begin_define
define|#
directive|define
name|SHT_IA_64_UNWIND
value|0x70000001
end_define

begin_define
define|#
directive|define
name|SHT_IA_64_LOPSREG
value|0x78000000
end_define

begin_define
define|#
directive|define
name|SHT_IA_64_HIPSREG
value|0x7fffffff
end_define

begin_comment
comment|/*  * Section attribute flags.  */
end_comment

begin_define
define|#
directive|define
name|SHF_IA_64_SHORT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SHF_IA_64_NORECOV
value|0x20000000
end_define

begin_comment
comment|/*  * Relocation types.  */
end_comment

begin_comment
comment|/*	Name			Value	   Field	Calculation */
end_comment

begin_define
define|#
directive|define
name|R_IA64_NONE
value|0
end_define

begin_comment
comment|/* None */
end_comment

begin_define
define|#
directive|define
name|R_IA64_IMM14
value|0x21
end_define

begin_comment
comment|/* immediate14	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_IMM22
value|0x22
end_define

begin_comment
comment|/* immediate22	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_IMM64
value|0x23
end_define

begin_comment
comment|/* immediate64	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_DIR32MSB
value|0x24
end_define

begin_comment
comment|/* word32 MSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_DIR32LSB
value|0x25
end_define

begin_comment
comment|/* word32 LSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_DIR64MSB
value|0x26
end_define

begin_comment
comment|/* word64 MSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_DIR64LSB
value|0x27
end_define

begin_comment
comment|/* word64 LSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_GPREL22
value|0x2a
end_define

begin_comment
comment|/* immediate22	@gprel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_GPREL64I
value|0x2b
end_define

begin_comment
comment|/* immediate64	@gprel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_GPREL64MSB
value|0x2e
end_define

begin_comment
comment|/* word64 MSB	@gprel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_GPREL64LSB
value|0x2f
end_define

begin_comment
comment|/* word64 LSB	@gprel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF22
value|0x32
end_define

begin_comment
comment|/* immediate22	@ltoff(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF64I
value|0x33
end_define

begin_comment
comment|/* immediate64	@ltoff(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PLTOFF22
value|0x3a
end_define

begin_comment
comment|/* immediate22	@pltoff(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PLTOFF64I
value|0x3b
end_define

begin_comment
comment|/* immediate64	@pltoff(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PLTOFF64MSB
value|0x3e
end_define

begin_comment
comment|/* word64 MSB	@pltoff(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PLTOFF64LSB
value|0x3f
end_define

begin_comment
comment|/* word64 LSB	@pltoff(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_FPTR64I
value|0x43
end_define

begin_comment
comment|/* immediate64	@fptr(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_FPTR32MSB
value|0x44
end_define

begin_comment
comment|/* word32 MSB	@fptr(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_FPTR32LSB
value|0x45
end_define

begin_comment
comment|/* word32 LSB	@fptr(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_FPTR64MSB
value|0x46
end_define

begin_comment
comment|/* word64 MSB	@fptr(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_FPTR64LSB
value|0x47
end_define

begin_comment
comment|/* word64 LSB	@fptr(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL21B
value|0x49
end_define

begin_comment
comment|/* immediate21 form1 S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL21M
value|0x4a
end_define

begin_comment
comment|/* immediate21 form2 S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL21F
value|0x4b
end_define

begin_comment
comment|/* immediate21 form3 S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL32MSB
value|0x4c
end_define

begin_comment
comment|/* word32 MSB	S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL32LSB
value|0x4d
end_define

begin_comment
comment|/* word32 LSB	S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL64MSB
value|0x4e
end_define

begin_comment
comment|/* word64 MSB	S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_PCREL64LSB
value|0x4f
end_define

begin_comment
comment|/* word64 LSB	S + A - P */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF_FPTR22
value|0x52
end_define

begin_comment
comment|/* immediate22	@ltoff(@fptr(S + A)) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF_FPTR64I
value|0x53
end_define

begin_comment
comment|/* immediate64	@ltoff(@fptr(S + A)) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF_FPTR32MSB
value|0x54
end_define

begin_comment
comment|/* word32 MSB	@ltoff(@fptr(S + A)) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF_FPTR32LSB
value|0x55
end_define

begin_comment
comment|/* word32 LSB	@ltoff(@fptr(S + A)) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF_FPTR64MSB
value|0x56
end_define

begin_comment
comment|/* word64 MSB	@ltoff(@fptr(S + A)) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF_FPTR64LSB
value|0x57
end_define

begin_comment
comment|/* word64 LSB	@ltoff(@fptr(S + A)) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SEGREL32MSB
value|0x5c
end_define

begin_comment
comment|/* word32 MSB	@segrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SEGREL32LSB
value|0x5d
end_define

begin_comment
comment|/* word32 LSB	@segrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SEGREL64MSB
value|0x5e
end_define

begin_comment
comment|/* word64 MSB	@segrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SEGREL64LSB
value|0x5f
end_define

begin_comment
comment|/* word64 LSB	@segrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SECREL32MSB
value|0x64
end_define

begin_comment
comment|/* word32 MSB	@secrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SECREL32LSB
value|0x65
end_define

begin_comment
comment|/* word32 LSB	@secrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SECREL64MSB
value|0x66
end_define

begin_comment
comment|/* word64 MSB	@secrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SECREL64LSB
value|0x67
end_define

begin_comment
comment|/* word64 LSB	@secrel(S + A) */
end_comment

begin_define
define|#
directive|define
name|R_IA64_REL32MSB
value|0x6c
end_define

begin_comment
comment|/* word32 MSB	BD + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_REL32LSB
value|0x6d
end_define

begin_comment
comment|/* word32 LSB	BD + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_REL64MSB
value|0x6e
end_define

begin_comment
comment|/* word64 MSB	BD + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_REL64LSB
value|0x6f
end_define

begin_comment
comment|/* word64 LSB	BD + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTV32MSB
value|0x74
end_define

begin_comment
comment|/* word32 MSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTV32LSB
value|0x75
end_define

begin_comment
comment|/* word32 LSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTV64MSB
value|0x76
end_define

begin_comment
comment|/* word64 MSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTV64LSB
value|0x77
end_define

begin_comment
comment|/* word64 LSB	S + A */
end_comment

begin_define
define|#
directive|define
name|R_IA64_IPLTMSB
value|0x80
end_define

begin_comment
comment|/* function descriptor MSB special */
end_comment

begin_define
define|#
directive|define
name|R_IA64_IPLTLSB
value|0x81
end_define

begin_comment
comment|/* function descriptor LSB speciaal */
end_comment

begin_define
define|#
directive|define
name|R_IA64_SUB
value|0x85
end_define

begin_comment
comment|/* immediate64	A - S */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LTOFF22X
value|0x86
end_define

begin_comment
comment|/* immediate22	special */
end_comment

begin_define
define|#
directive|define
name|R_IA64_LDXMOV
value|0x87
end_define

begin_comment
comment|/* immediate22	special */
end_comment

begin_comment
comment|/* Define "machine" characteristics */
end_comment

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS64
end_define

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|ELF_TARG_MACH
value|EM_IA_64
end_define

begin_define
define|#
directive|define
name|ELF_TARG_VER
value|1
end_define

begin_comment
comment|/* Processor specific dynmamic section tags. */
end_comment

begin_define
define|#
directive|define
name|DT_IA64_PLT_RESERVE
value|0x70000000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * On the ia64 we load the dynamic linker where a userland call  * to mmap(0, ...) would put it.  The rationale behind this  * calculation is that it leaves room for the heap to grow to  * its maximum allowed size.  */
end_comment

begin_define
define|#
directive|define
name|ELF_RTLD_ADDR
parameter_list|(
name|vmspace
parameter_list|)
define|\
value|(round_page((vm_offset_t)(vmspace)->vm_daddr + maxdsiz))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ELF_H_ */
end_comment

end_unit

