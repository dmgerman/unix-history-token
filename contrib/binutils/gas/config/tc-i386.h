begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i386.h -- Header file for tc-i386.c    Copyright 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004, 2005, 2006, 2007    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I386
end_ifndef

begin_define
define|#
directive|define
name|TC_I386
value|1
end_define

begin_include
include|#
directive|include
file|"opcodes/i386-opc.h"
end_include

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|TARGET_MACH
value|(i386_mach ())
end_define

begin_function_decl
specifier|extern
name|unsigned
name|long
name|i386_mach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TE_FreeBSD
end_ifdef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-i386-freebsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_NetBSD
end_ifdef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-i386-netbsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_386BSD
end_ifdef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-i386-bsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LINUX
end_ifdef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-i386-linux"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_Mach
end_ifdef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-mach3"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_DYNIX
end_ifdef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-i386-dynix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AOUT_TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|AOUT_TARGET_FORMAT
value|"a.out-i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_FreeBSD
end_ifdef

begin_define
define|#
directive|define
name|ELF_TARGET_FORMAT
value|"elf32-i386-freebsd"
end_define

begin_define
define|#
directive|define
name|ELF_TARGET_FORMAT64
value|"elf64-x86-64-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TE_VXWORKS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ELF_TARGET_FORMAT
value|"elf32-i386-vxworks"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|ELF_TARGET_FORMAT
value|"elf32-i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_TARGET_FORMAT64
end_ifndef

begin_define
define|#
directive|define
name|ELF_TARGET_FORMAT64
value|"elf64-x86-64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|OBJ_MAYBE_COFF
argument_list|)
operator|&&
name|defined
argument_list|(
name|OBJ_MAYBE_AOUT
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_MAYBE_ELF
argument_list|)
operator|)
end_if

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|i386_target_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|i386_target_format ()
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|ELF_TARGET_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|AOUT_TARGET_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|OBJ_MAYBE_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|md_end
value|i386_elf_emit_arch_note
end_define

begin_function_decl
specifier|extern
name|void
name|i386_elf_emit_arch_note
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|,
name|FRCHAIN
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|extra_symbol_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_symbol_chars
value|extra_symbol_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|i386_comment_chars
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_comment_chars
value|i386_comment_chars
end_define

begin_comment
comment|/* Prefixes will be emitted in the order defined below.    WAIT_PREFIX must be the first prefix since FWAIT is really is an    instruction, and so must come before any prefixes.    The preferred prefix order is SEG_PREFIX, ADDR_PREFIX, DATA_PREFIX,    LOCKREP_PREFIX.  */
end_comment

begin_define
define|#
directive|define
name|WAIT_PREFIX
value|0
end_define

begin_define
define|#
directive|define
name|SEG_PREFIX
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_PREFIX
value|2
end_define

begin_define
define|#
directive|define
name|DATA_PREFIX
value|3
end_define

begin_define
define|#
directive|define
name|LOCKREP_PREFIX
value|4
end_define

begin_define
define|#
directive|define
name|REX_PREFIX
value|5
end_define

begin_comment
comment|/* must come last.  */
end_comment

begin_define
define|#
directive|define
name|MAX_PREFIXES
value|6
end_define

begin_comment
comment|/* max prefixes per opcode */
end_comment

begin_comment
comment|/* we define the syntax here (modulo base,index,scale syntax) */
end_comment

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|'%'
end_define

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|'$'
end_define

begin_define
define|#
directive|define
name|ABSOLUTE_PREFIX
value|'*'
end_define

begin_comment
comment|/* these are the instruction mnemonic suffixes.  */
end_comment

begin_define
define|#
directive|define
name|WORD_MNEM_SUFFIX
value|'w'
end_define

begin_define
define|#
directive|define
name|BYTE_MNEM_SUFFIX
value|'b'
end_define

begin_define
define|#
directive|define
name|SHORT_MNEM_SUFFIX
value|'s'
end_define

begin_define
define|#
directive|define
name|LONG_MNEM_SUFFIX
value|'l'
end_define

begin_define
define|#
directive|define
name|QWORD_MNEM_SUFFIX
value|'q'
end_define

begin_comment
comment|/* Intel Syntax */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_MNEM_SUFFIX
value|'x'
end_define

begin_define
define|#
directive|define
name|END_OF_INSN
value|'\0'
end_define

begin_comment
comment|/*   'templates' is for grouping together 'template' structures for opcodes   of the same name.  This is only used for storing the insns in the grand   ole hash table of insns.   The templates themselves start at START and range up to (but not including)   END.   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|template
modifier|*
name|start
decl_stmt|;
specifier|const
name|template
modifier|*
name|end
decl_stmt|;
block|}
name|templates
typedef|;
end_typedef

begin_comment
comment|/* 386 operand encoding bytes:  see 386 book for details of this.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|regmem
decl_stmt|;
comment|/* codes register or memory operand */
name|unsigned
name|int
name|reg
decl_stmt|;
comment|/* codes register operand (or extended opcode) */
name|unsigned
name|int
name|mode
decl_stmt|;
comment|/* how to interpret regmem& reg */
block|}
name|modrm_byte
typedef|;
end_typedef

begin_comment
comment|/* x86-64 extension prefix.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|rex_byte
typedef|;
end_typedef

begin_comment
comment|/* 386 opcode byte to code indirect addressing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|base
decl_stmt|;
name|unsigned
name|index
decl_stmt|;
name|unsigned
name|scale
decl_stmt|;
block|}
name|sib_byte
typedef|;
end_typedef

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_UNKNOWN
block|,
name|PROCESSOR_I486
block|,
name|PROCESSOR_PENTIUM
block|,
name|PROCESSOR_PENTIUMPRO
block|,
name|PROCESSOR_PENTIUM4
block|,
name|PROCESSOR_NOCONA
block|,
name|PROCESSOR_CORE
block|,
name|PROCESSOR_CORE2
block|,
name|PROCESSOR_K6
block|,
name|PROCESSOR_ATHLON
block|,
name|PROCESSOR_K8
block|,
name|PROCESSOR_GENERIC32
block|,
name|PROCESSOR_GENERIC64
block|,
name|PROCESSOR_AMDFAM10
block|}
enum|;
end_enum

begin_comment
comment|/* x86 arch names, types and features */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* arch name */
name|enum
name|processor_type
name|type
decl_stmt|;
comment|/* arch type */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* cpu feature flags */
block|}
name|arch_entry
typedef|;
end_typedef

begin_comment
comment|/* The name of the global offset table generated by the compiler. Allow    this to be overridden if need be.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GLOBAL_OFFSET_TABLE_NAME
end_ifndef

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"_GLOBAL_OFFSET_TABLE_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_MAYBE_ELF
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|LEX_AT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TC_PARSE_CONS_EXPRESSION
parameter_list|(
name|EXP
parameter_list|,
name|NBYTES
parameter_list|)
value|x86_cons (EXP, NBYTES)
end_define

begin_function_decl
specifier|extern
name|void
name|x86_cons
parameter_list|(
name|expressionS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|OFF
parameter_list|,
name|LEN
parameter_list|,
name|EXP
parameter_list|)
value|x86_cons_fix_new(FRAG, OFF, LEN, EXP)
end_define

begin_function_decl
specifier|extern
name|void
name|x86_cons_fix_new
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

begin_define
define|#
directive|define
name|NO_RELOC
value|BFD_RELOC_NONE
end_define

begin_function_decl
name|void
name|i386_validate_fix
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX
parameter_list|(
name|FIX
parameter_list|,
name|SEGTYPE
parameter_list|,
name|SKIP
parameter_list|)
value|i386_validate_fix(FIX)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|X
parameter_list|)
value|tc_i386_fix_adjustable(X)
end_define

begin_function_decl
specifier|extern
name|int
name|tc_i386_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Values passed to md_apply_fix don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_comment
comment|/* ELF wants external syms kept, as does PE COFF.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TE_PE
argument_list|)
operator|&&
name|defined
argument_list|(
name|STRICT_PE_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
define|\
value|(OUTPUT_FLAVOR == bfd_target_elf_flavour		\    || OUTPUT_FLAVOR == bfd_target_coff_flavour)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
define|\
value|(OUTPUT_FLAVOR == bfd_target_elf_flavour)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This expression evaluates to true if the relocation is for a local    object for which we still want to do the relocation at runtime.    False if we are willing to perform this relocation while building    the .o file.  GOTOFF does not need to be checked here because it is    not pcrel.  I am not sure if some of the others are ever used with    pcrel, but it is easier to be safe than sorry.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel					\    || (FIX)->fx_r_type == BFD_RELOC_386_PLT32		\    || (FIX)->fx_r_type == BFD_RELOC_386_GOT32		\    || (FIX)->fx_r_type == BFD_RELOC_386_GOTPC		\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_parse_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|expressionS
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
value|i386_parse_name (s, e, c)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_decl_stmt
specifier|extern
name|int
name|optimize_align_code
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|n
parameter_list|,
name|fill
parameter_list|,
name|len
parameter_list|,
name|max
parameter_list|,
name|around
parameter_list|)
define|\
value|if ((n)									\&& !need_pass_2							\&& optimize_align_code						\&& (!(fill)								\ 	|| ((char)*(fill) == (char)0x90&& (len) == 1))			\&& subseg_text_p (now_seg))						\   {									\     frag_align_code ((n), (max));					\     goto around;							\   }
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|15
end_define

begin_function_decl
specifier|extern
name|void
name|i386_align_code
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|fragP
parameter_list|)
define|\
value|if (fragP->fr_type == rs_align_code) 					\   i386_align_code (fragP, (fragP->fr_next->fr_address			\ 			   - fragP->fr_address				\ 			   - fragP->fr_fix));
end_define

begin_function_decl
name|void
name|i386_print_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_print_statistics
value|i386_print_statistics
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SCO_ELF
end_ifdef

begin_define
define|#
directive|define
name|tc_init_after_args
parameter_list|()
value|sco_id ()
end_define

begin_function_decl
specifier|extern
name|void
name|sco_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
value|1
end_define

begin_comment
comment|/* We want .cfi_* pseudo-ops for generating unwind info.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_USE_CFIPOP
value|1
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|x86_dwarf2_return_column
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|x86_dwarf2_return_column
end_define

begin_decl_stmt
specifier|extern
name|int
name|x86_cie_data_alignment
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|x86_cie_data_alignment
end_define

begin_define
define|#
directive|define
name|tc_regname_to_dw2regnum
value|tc_x86_regname_to_dw2regnum
end_define

begin_function_decl
specifier|extern
name|int
name|tc_x86_regname_to_dw2regnum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_cfi_frame_initial_instructions
value|tc_x86_frame_initial_instructions
end_define

begin_function_decl
specifier|extern
name|void
name|tc_x86_frame_initial_instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_elf_section_type
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
value|i386_elf_section_type (str, len)
end_define

begin_function_decl
specifier|extern
name|int
name|i386_elf_section_type
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Support for SHF_X86_64_LARGE */
end_comment

begin_function_decl
specifier|extern
name|int
name|x86_64_section_word
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|x86_64_section_letter
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_elf_section_letter
parameter_list|(
name|LETTER
parameter_list|,
name|PTR_MSG
parameter_list|)
value|x86_64_section_letter (LETTER, PTR_MSG)
end_define

begin_define
define|#
directive|define
name|md_elf_section_word
parameter_list|(
name|STR
parameter_list|,
name|LEN
parameter_list|)
value|x86_64_section_word (STR, LEN)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_define
define|#
directive|define
name|O_secrel
value|O_md1
end_define

begin_define
define|#
directive|define
name|TC_DWARF2_EMIT_OFFSET
value|tc_pe_dwarf2_emit_offset
end_define

begin_function_decl
name|void
name|tc_pe_dwarf2_emit_offset
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TE_PE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I386 */
end_comment

end_unit

