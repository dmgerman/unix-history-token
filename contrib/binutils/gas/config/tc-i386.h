begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i386.h -- Header file for tc-i386.c    Copyright 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LYNX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-i386-lynx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_comment
comment|/* This is used to determine relocation types in tc-i386.c.  The first    parameter is the current relocation type, the second one is the desired    type.  The idea is that if the original type is already some kind of PIC    relocation, we leave it alone, otherwise we give it the desired type */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|X
parameter_list|)
value|tc_i386_fix_adjustable(X)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_i386_fix_adjustable
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
operator|||
name|defined
argument_list|(
name|OBJ_MAYBE_COFF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_COFF
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TE_PE
argument_list|)
end_if

begin_comment
comment|/* This arranges for gas/write.c to not apply a relocation if    tc_fix_adjustable() says it is not adjustable.    The "! symbol_used_in_reloc_p" test is there specifically to cover    the case of non-global symbols in linkonce sections.  It's the    generally correct thing to do though;  If a reloc is going to be    emitted against a symbol then we don't want to adjust the fixup by    applying the reloc during assembly.  The reloc will be applied by    the linker during final link.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_ADJUSTABLE
parameter_list|(
name|fixP
parameter_list|)
define|\
value|(! symbol_used_in_reloc_p ((fixP)->fx_addsy)&& tc_fix_adjustable (fixP))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This expression evaluates to false if the relocation is for a local object    for which we still want to do the relocation at runtime.  True if we    are willing to perform this relocation while building the .o file.    This is only used for pcrel relocations, so GOTOFF does not need to be    checked here.  I am not sure if some of the others are ever used with    pcrel, but it is easier to be safe than sorry.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_386_PLT32			\&& (FIX)->fx_r_type != BFD_RELOC_386_GOT32			\&& (FIX)->fx_r_type != BFD_RELOC_386_GOTPC			\&& ((FIX)->fx_addsy == NULL					\        || (! S_IS_EXTERNAL ((FIX)->fx_addsy)			\&& ! S_IS_WEAK ((FIX)->fx_addsy)			\&& S_IS_DEFINED ((FIX)->fx_addsy)			\&& ! S_IS_COMMON ((FIX)->fx_addsy))))
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

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|i386_mach
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|i386_target_format
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|"elf32-i386"
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

begin_decl_stmt
specifier|extern
name|void
name|i386_elf_emit_arch_note
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_comment
comment|/* COFF STUFF */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC
value|I386MAGIC
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|COFF_FLAGS
value|F_AR32WR
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|((x)->fx_addsy || (x)->fx_r_type==7)
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixP
parameter_list|)
value|tc_coff_fix2rtype(fixP)
end_define

begin_decl_stmt
specifier|extern
name|short
name|tc_coff_fix2rtype
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep (frag)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_coff_sizemachdep
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|frag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TE_GO32
end_ifdef

begin_comment
comment|/* DJGPP now expects some sections to be 2**4 aligned.  */
end_comment

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|)
define|\
value|((strcmp (obj_segment_name (SEG), ".text") == 0			\     || strcmp (obj_segment_name (SEG), ".data") == 0			\     || strcmp (obj_segment_name (SEG), ".bss") == 0			\     || strncmp (obj_segment_name (SEG), ".gnu.linkonce.t", 15) == 0	\     || strncmp (obj_segment_name (SEG), ".gnu.linkonce.d", 15) == 0	\     || strncmp (obj_segment_name (SEG), ".gnu.linkonce.r", 15) == 0)	\    ? 4									\    : 2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|)
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TC_RVA_RELOC
value|7
end_define

begin_comment
comment|/* Need this for PIC relocations */
end_comment

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_386BSD
end_ifdef

begin_comment
comment|/* The BSDI linker apparently rejects objects with a machine type of    M_386 (100).  */
end_comment

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|REVERSE_SORT_RELOCS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LEX_AT
end_ifndef

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

begin_decl_stmt
specifier|extern
name|void
name|x86_cons
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|x86_cons_fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fixp
parameter_list|)
value|tc_i386_force_relocation(fixp)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_i386_force_relocation
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|NO_RELOC
value|BFD_RELOC_NONE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_RELOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_AOUT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|TE_PE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|TE_GO32
end_ifndef

begin_comment
comment|/* Local labels starts with .L */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|(name[0] == '.' \&& (name[1] == 'L' || name[1] == 'X' || name[1] == '.'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

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

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|3
end_define

begin_comment
comment|/* max operands per insn */
end_comment

begin_define
define|#
directive|define
name|MAX_IMMEDIATE_OPERANDS
value|2
end_define

begin_comment
comment|/* max immediates per insn (lcall, ljmp) */
end_comment

begin_define
define|#
directive|define
name|MAX_MEMORY_OPERANDS
value|2
end_define

begin_comment
comment|/* max memory refs per insn (string ops) */
end_comment

begin_comment
comment|/* Prefixes will be emitted in the order defined below.    WAIT_PREFIX must be the first prefix since FWAIT is really is an    instruction, and so must come before any prefixes.  */
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
name|LOCKREP_PREFIX
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
name|SEG_PREFIX
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

begin_define
define|#
directive|define
name|TWO_BYTE_OPCODE_ESCAPE
value|0x0f
end_define

begin_define
define|#
directive|define
name|NOP_OPCODE
value|(char) 0x90
end_define

begin_comment
comment|/* register numbers */
end_comment

begin_define
define|#
directive|define
name|EBP_REG_NUM
value|5
end_define

begin_define
define|#
directive|define
name|ESP_REG_NUM
value|4
end_define

begin_comment
comment|/* modrm_byte.regmem for twobyte escape */
end_comment

begin_define
define|#
directive|define
name|ESCAPE_TO_TWO_BYTE_ADDRESSING
value|ESP_REG_NUM
end_define

begin_comment
comment|/* index_base_byte.index for no index register addressing */
end_comment

begin_define
define|#
directive|define
name|NO_INDEX_REGISTER
value|ESP_REG_NUM
end_define

begin_comment
comment|/* index_base_byte.base for no base register addressing */
end_comment

begin_define
define|#
directive|define
name|NO_BASE_REGISTER
value|EBP_REG_NUM
end_define

begin_define
define|#
directive|define
name|NO_BASE_REGISTER_16
value|6
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

begin_comment
comment|/* modrm.mode = REGMEM_FIELD_HAS_REG when a register is in there */
end_comment

begin_define
define|#
directive|define
name|REGMEM_FIELD_HAS_REG
value|0x3
end_define

begin_comment
comment|/* always = 0x3 */
end_comment

begin_define
define|#
directive|define
name|REGMEM_FIELD_HAS_MEM
value|(~REGMEM_FIELD_HAS_REG)
end_define

begin_define
define|#
directive|define
name|END_OF_INSN
value|'\0'
end_define

begin_comment
comment|/* Intel Syntax */
end_comment

begin_comment
comment|/* Values 0-4 map onto scale factor */
end_comment

begin_define
define|#
directive|define
name|BYTE_PTR
value|0
end_define

begin_define
define|#
directive|define
name|WORD_PTR
value|1
end_define

begin_define
define|#
directive|define
name|DWORD_PTR
value|2
end_define

begin_define
define|#
directive|define
name|QWORD_PTR
value|3
end_define

begin_define
define|#
directive|define
name|XWORD_PTR
value|4
end_define

begin_define
define|#
directive|define
name|SHORT
value|5
end_define

begin_define
define|#
directive|define
name|OFFSET_FLAT
value|6
end_define

begin_define
define|#
directive|define
name|FLAT
value|7
end_define

begin_define
define|#
directive|define
name|NONE_FOUND
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* instruction name sans width suffix ("mov" for movl insns) */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* how many operands */
name|unsigned
name|int
name|operands
decl_stmt|;
comment|/* base_opcode is the fundamental opcode byte without optional      prefix(es).  */
name|unsigned
name|int
name|base_opcode
decl_stmt|;
comment|/* extension_opcode is the 3 bit extension for group<n> insns.      This field is also used to store the 8-bit opcode suffix for the      AMD 3DNow! instructions.      If this template has no extension opcode (the usual case) use None */
name|unsigned
name|int
name|extension_opcode
decl_stmt|;
define|#
directive|define
name|None
value|0xffff
comment|/* If no extension_opcode is possible.  */
comment|/* cpu feature flags */
name|unsigned
name|int
name|cpu_flags
decl_stmt|;
define|#
directive|define
name|Cpu086
value|0x1
comment|/* Any old cpu will do, 0 does the same */
define|#
directive|define
name|Cpu186
value|0x2
comment|/* i186 or better required */
define|#
directive|define
name|Cpu286
value|0x4
comment|/* i286 or better required */
define|#
directive|define
name|Cpu386
value|0x8
comment|/* i386 or better required */
define|#
directive|define
name|Cpu486
value|0x10
comment|/* i486 or better required */
define|#
directive|define
name|Cpu586
value|0x20
comment|/* i585 or better required */
define|#
directive|define
name|Cpu686
value|0x40
comment|/* i686 or better required */
define|#
directive|define
name|CpuP4
value|0x80
comment|/* Pentium4 or better required */
define|#
directive|define
name|CpuK6
value|0x100
comment|/* AMD K6 or better required*/
define|#
directive|define
name|CpuAthlon
value|0x200
comment|/* AMD Athlon or better required*/
define|#
directive|define
name|CpuSledgehammer
value|0x400
comment|/* Sledgehammer or better required */
define|#
directive|define
name|CpuMMX
value|0x800
comment|/* MMX support required */
define|#
directive|define
name|CpuSSE
value|0x1000
comment|/* Streaming SIMD extensions required */
define|#
directive|define
name|CpuSSE2
value|0x2000
comment|/* Streaming SIMD extensions 2 required */
define|#
directive|define
name|Cpu3dnow
value|0x4000
comment|/* 3dnow! support required */
comment|/* These flags are set by gas depending on the flag_code.  */
define|#
directive|define
name|Cpu64
value|0x4000000
comment|/* 64bit support required  */
define|#
directive|define
name|CpuNo64
value|0x8000000
comment|/* Not supported in the 64bit mode  */
comment|/* The default value for unknown CPUs - enable all features to avoid problems.  */
define|#
directive|define
name|CpuUnknownFlags
value|(Cpu086|Cpu186|Cpu286|Cpu386|Cpu486|Cpu586|Cpu686|CpuP4|CpuSledgehammer|CpuMMX|CpuSSE|CpuSSE2|Cpu3dnow|CpuK6|CpuAthlon)
comment|/* the bits in opcode_modifier are used to generate the final opcode from      the base_opcode.  These bits also are used to detect alternate forms of      the same instruction */
name|unsigned
name|int
name|opcode_modifier
decl_stmt|;
comment|/* opcode_modifier bits: */
define|#
directive|define
name|W
value|0x1
comment|/* set if operands can be words or dwords 				   encoded the canonical way */
define|#
directive|define
name|D
value|0x2
comment|/* D = 0 if Reg --> Regmem; 				   D = 1 if Regmem --> Reg:    MUST BE 0x2 */
define|#
directive|define
name|Modrm
value|0x4
define|#
directive|define
name|FloatR
value|0x8
comment|/* src/dest swap for floats:   MUST BE 0x8 */
define|#
directive|define
name|ShortForm
value|0x10
comment|/* register is in low 3 bits of opcode */
define|#
directive|define
name|FloatMF
value|0x20
comment|/* FP insn memory format bit, sized by 0x4 */
define|#
directive|define
name|Jump
value|0x40
comment|/* special case for jump insns.  */
define|#
directive|define
name|JumpDword
value|0x80
comment|/* call and jump */
define|#
directive|define
name|JumpByte
value|0x100
comment|/* loop and jecxz */
define|#
directive|define
name|JumpInterSegment
value|0x200
comment|/* special case for intersegment leaps/calls */
define|#
directive|define
name|FloatD
value|0x400
comment|/* direction for float insns:  MUST BE 0x400 */
define|#
directive|define
name|Seg2ShortForm
value|0x800
comment|/* encoding of load segment reg insns */
define|#
directive|define
name|Seg3ShortForm
value|0x1000
comment|/* fs/gs segment register insns.  */
define|#
directive|define
name|Size16
value|0x2000
comment|/* needs size prefix if in 32-bit mode */
define|#
directive|define
name|Size32
value|0x4000
comment|/* needs size prefix if in 16-bit mode */
define|#
directive|define
name|Size64
value|0x8000
comment|/* needs size prefix if in 16-bit mode */
define|#
directive|define
name|IgnoreSize
value|0x10000
comment|/* instruction ignores operand size prefix */
define|#
directive|define
name|DefaultSize
value|0x20000
comment|/* default insn size depends on mode */
define|#
directive|define
name|No_bSuf
value|0x40000
comment|/* b suffix on instruction illegal */
define|#
directive|define
name|No_wSuf
value|0x80000
comment|/* w suffix on instruction illegal */
define|#
directive|define
name|No_lSuf
value|0x100000
comment|/* l suffix on instruction illegal */
define|#
directive|define
name|No_sSuf
value|0x200000
comment|/* s suffix on instruction illegal */
define|#
directive|define
name|No_qSuf
value|0x400000
comment|/* q suffix on instruction illegal */
define|#
directive|define
name|No_xSuf
value|0x800000
comment|/* x suffix on instruction illegal */
define|#
directive|define
name|FWait
value|0x1000000
comment|/* instruction needs FWAIT */
define|#
directive|define
name|IsString
value|0x2000000
comment|/* quick test for string instructions */
define|#
directive|define
name|regKludge
value|0x4000000
comment|/* fake an extra reg operand for clr, imul */
define|#
directive|define
name|IsPrefix
value|0x8000000
comment|/* opcode is a prefix */
define|#
directive|define
name|ImmExt
value|0x10000000
comment|/* instruction has extension in 8 bit imm */
define|#
directive|define
name|NoRex64
value|0x20000000
comment|/* instruction don't need Rex64 prefix.  */
define|#
directive|define
name|Rex64
value|0x40000000
comment|/* instruction require Rex64 prefix.  */
define|#
directive|define
name|Ugh
value|0x80000000
comment|/* deprecated fp insn, gets a warning */
comment|/* operand_types[i] describes the type of operand i.  This is made      by OR'ing together all of the possible type masks.  (e.g.      'operand_types[i] = Reg|Imm' specifies that operand i can be      either a register or an immediate operand.  */
name|unsigned
name|int
name|operand_types
index|[
literal|3
index|]
decl_stmt|;
comment|/* operand_types[i] bits */
comment|/* register */
define|#
directive|define
name|Reg8
value|0x1
comment|/* 8 bit reg */
define|#
directive|define
name|Reg16
value|0x2
comment|/* 16 bit reg */
define|#
directive|define
name|Reg32
value|0x4
comment|/* 32 bit reg */
define|#
directive|define
name|Reg64
value|0x8
comment|/* 64 bit reg */
comment|/* immediate */
define|#
directive|define
name|Imm8
value|0x10
comment|/* 8 bit immediate */
define|#
directive|define
name|Imm8S
value|0x20
comment|/* 8 bit immediate sign extended */
define|#
directive|define
name|Imm16
value|0x40
comment|/* 16 bit immediate */
define|#
directive|define
name|Imm32
value|0x80
comment|/* 32 bit immediate */
define|#
directive|define
name|Imm32S
value|0x100
comment|/* 32 bit immediate sign extended */
define|#
directive|define
name|Imm64
value|0x200
comment|/* 64 bit immediate */
define|#
directive|define
name|Imm1
value|0x400
comment|/* 1 bit immediate */
comment|/* memory */
define|#
directive|define
name|BaseIndex
value|0x800
comment|/* Disp8,16,32 are used in different ways, depending on the      instruction.  For jumps, they specify the size of the PC relative      displacement, for baseindex type instructions, they specify the      size of the offset relative to the base register, and for memory      offset instructions such as `mov 1234,%al' they specify the size of      the offset relative to the segment base.  */
define|#
directive|define
name|Disp8
value|0x1000
comment|/* 8 bit displacement */
define|#
directive|define
name|Disp16
value|0x2000
comment|/* 16 bit displacement */
define|#
directive|define
name|Disp32
value|0x4000
comment|/* 32 bit displacement */
define|#
directive|define
name|Disp32S
value|0x8000
comment|/* 32 bit signed displacement */
define|#
directive|define
name|Disp64
value|0x10000
comment|/* 64 bit displacement */
comment|/* specials */
define|#
directive|define
name|InOutPortReg
value|0x20000
comment|/* register to hold in/out port addr = dx */
define|#
directive|define
name|ShiftCount
value|0x40000
comment|/* register to hold shift cound = cl */
define|#
directive|define
name|Control
value|0x80000
comment|/* Control register */
define|#
directive|define
name|Debug
value|0x100000
comment|/* Debug register */
define|#
directive|define
name|Test
value|0x200000
comment|/* Test register */
define|#
directive|define
name|FloatReg
value|0x400000
comment|/* Float register */
define|#
directive|define
name|FloatAcc
value|0x800000
comment|/* Float stack top %st(0) */
define|#
directive|define
name|SReg2
value|0x1000000
comment|/* 2 bit segment register */
define|#
directive|define
name|SReg3
value|0x2000000
comment|/* 3 bit segment register */
define|#
directive|define
name|Acc
value|0x4000000
comment|/* Accumulator %al or %ax or %eax */
define|#
directive|define
name|JumpAbsolute
value|0x8000000
define|#
directive|define
name|RegMMX
value|0x10000000
comment|/* MMX register */
define|#
directive|define
name|RegXMM
value|0x20000000
comment|/* XMM registers in PIII */
define|#
directive|define
name|EsSeg
value|0x40000000
comment|/* String insn operand with fixed es segment */
comment|/* InvMem is for instructions with a modrm byte that only allow a      general register encoding in the i.tm.mode and i.tm.regmem fields,      eg. control reg moves.  They really ought to support a memory form,      but don't, so we add an InvMem flag to the register operand to      indicate that it should be encoded in the i.tm.regmem field.  */
define|#
directive|define
name|InvMem
value|0x80000000
define|#
directive|define
name|Reg
value|(Reg8|Reg16|Reg32|Reg64)
comment|/* gen'l register */
define|#
directive|define
name|WordReg
value|(Reg16|Reg32|Reg64)
define|#
directive|define
name|ImplicitRegister
value|(InOutPortReg|ShiftCount|Acc|FloatAcc)
define|#
directive|define
name|Imm
value|(Imm8|Imm8S|Imm16|Imm32S|Imm32|Imm64)
comment|/* gen'l immediate */
define|#
directive|define
name|EncImm
value|(Imm8|Imm16|Imm32|Imm32S)
comment|/* Encodable gen'l immediate */
define|#
directive|define
name|Disp
value|(Disp8|Disp16|Disp32|Disp32S|Disp64)
comment|/* General displacement */
define|#
directive|define
name|AnyMem
value|(Disp8|Disp16|Disp32|Disp32S|BaseIndex|InvMem)
comment|/* General memory */
comment|/* The following aliases are defined because the opcode table      carefully specifies the allowed memory types for each instruction.      At the moment we can only tell a memory reference size by the      instruction suffix, so there's not much point in defining Mem8,      Mem16, Mem32 and Mem64 opcode modifiers - We might as well just use      the suffix directly to check memory operands.  */
define|#
directive|define
name|LLongMem
value|AnyMem
comment|/* 64 bits (or more) */
define|#
directive|define
name|LongMem
value|AnyMem
comment|/* 32 bit memory ref */
define|#
directive|define
name|ShortMem
value|AnyMem
comment|/* 16 bit memory ref */
define|#
directive|define
name|WordMem
value|AnyMem
comment|/* 16 or 32 bit memory ref */
define|#
directive|define
name|ByteMem
value|AnyMem
comment|/* 8 bit memory ref */
block|}
name|template
typedef|;
end_typedef

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
comment|/* these are for register name --> number& type hash lookup */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|reg_name
decl_stmt|;
name|unsigned
name|int
name|reg_type
decl_stmt|;
name|unsigned
name|int
name|reg_flags
decl_stmt|;
define|#
directive|define
name|RegRex
value|0x1
comment|/* Extended register.  */
define|#
directive|define
name|RegRex64
value|0x2
comment|/* Extended 8 bit register.  */
name|unsigned
name|int
name|reg_num
decl_stmt|;
block|}
name|reg_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|seg_name
decl_stmt|;
name|unsigned
name|int
name|seg_prefix
decl_stmt|;
block|}
name|seg_entry
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

begin_define
define|#
directive|define
name|REX_OPCODE
value|0x40
end_define

begin_comment
comment|/* Indicates 64 bit operand size.  */
end_comment

begin_define
define|#
directive|define
name|REX_MODE64
value|8
end_define

begin_comment
comment|/* High extension to reg field of modrm byte.  */
end_comment

begin_define
define|#
directive|define
name|REX_EXTX
value|4
end_define

begin_comment
comment|/* High extension to SIB index field.  */
end_comment

begin_define
define|#
directive|define
name|REX_EXTY
value|2
end_define

begin_comment
comment|/* High extension to base field of modrm or SIB, or reg field of opcode.  */
end_comment

begin_define
define|#
directive|define
name|REX_EXTZ
value|1
end_define

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

begin_comment
comment|/* x86 arch names and features */
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

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
name|void
name|i386_validate_fix
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX
parameter_list|(
name|FIXP
parameter_list|,
name|SEGTYPE
parameter_list|,
name|SKIP
parameter_list|)
value|i386_validate_fix(FIXP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I386 */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
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
value|if ((n)&& !need_pass_2							\&& (!(fill) || ((char)*(fill) == (char)0x90&& (len) == 1))		\&& subseg_text_p (now_seg))						\   {									\     frag_align_code ((n), (max));					\     goto around;							\   }
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|15
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_align_code
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|i386_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|sco_id
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

end_unit

