begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i386.h -- Header file for tc-i386.c    Copyright (C) 1989, 92, 93, 94, 95, 96, 1997 Free Software Foundation.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
name|TC_RELOC
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|(((X) != BFD_RELOC_386_PLT32&& \ 	   (X) != BFD_RELOC_386_GOTOFF&& \ 	   (X) != BFD_RELOC_386_GOT32&& \ 	   (X) != BFD_RELOC_386_GOTPC) ? Y : X)
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

begin_comment
comment|/* This is the relocation type for direct references to GLOBAL_OFFSET_TABLE.  * It comes up in complicated expressions such as   * _GLOBAL_OFFSET_TABLE_+[.-.L284], which cannot be expressed normally with  * the regular expressions.  The fixup specified here when used at runtime   * implies that we should add the address of the GOT to the specified location,  * and as a result we have simplified the expression into something we can use.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_GLOBAL_OFFSET_TABLE
value|BFD_RELOC_386_GOTPC
end_define

begin_comment
comment|/* This expression evaluates to false if the relocation is for a local object    for which we still want to do the relocation at runtime.  True if we    are willing to perform this relocation while building the .o file.    This is only used for pcrel relocations, so GOTOFF does not need to be    checked here.  I am not sure if some of the others are ever used with    pcrel, but it is easier to be safe than sorry. */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_386_PLT32 \&& (FIX)->fx_r_type != BFD_RELOC_386_GOT32 \&& (FIX)->fx_r_type != BFD_RELOC_386_GOTPC)
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_i386
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TE_NetBSD
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
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
name|TARGET_FORMAT
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
name|TARGET_FORMAT
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
name|TARGET_FORMAT
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
name|TARGET_FORMAT
value|"a.out-i386-dynix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-i386"
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
comment|/* OBJ_AOUT */
end_comment

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
name|OBJ_MAYBE_ELF
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_MAYBE_COFF
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

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
name|TC_FORCE_RELOCATION
parameter_list|(
name|x
parameter_list|)
value|((x)->fx_r_type==7)
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
value|tc_coff_sizemachdep(frag)
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

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|)
value|2
end_define

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
name|MAX_PREFIXES
value|5
end_define

begin_comment
comment|/* max prefixes per opcode */
end_comment

begin_define
define|#
directive|define
name|MAX_IMMEDIATE_OPERANDS
value|2
end_define

begin_comment
comment|/* max immediates per insn */
end_comment

begin_define
define|#
directive|define
name|MAX_MEMORY_OPERANDS
value|2
end_define

begin_comment
comment|/* max memory ref per insn (lcall uses 2) */
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
name|PREFIX_SEPERATOR
value|'/'
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

begin_comment
comment|/* these are the att as opcode suffixes, making movl --> mov, for example */
end_comment

begin_define
define|#
directive|define
name|DWORD_OPCODE_SUFFIX
value|'l'
end_define

begin_define
define|#
directive|define
name|WORD_OPCODE_SUFFIX
value|'w'
end_define

begin_define
define|#
directive|define
name|BYTE_OPCODE_SUFFIX
value|'b'
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
comment|/*   When an operand is read in it is classified by its type.  This type includes   all the possible ways an operand can be used.  Thus, '%eax' is both 'register   # 0' and 'The Accumulator'.  In our language this is expressed by OR'ing   'Reg32' (any 32 bit register) and 'Acc' (the accumulator).   Operands are classified so that we can match given operand types with   the opcode table in i386-opcode.h.   */
end_comment

begin_define
define|#
directive|define
name|Unknown
value|0x0
end_define

begin_comment
comment|/* register */
end_comment

begin_define
define|#
directive|define
name|Reg8
value|0x1
end_define

begin_comment
comment|/* 8 bit reg */
end_comment

begin_define
define|#
directive|define
name|Reg16
value|0x2
end_define

begin_comment
comment|/* 16 bit reg */
end_comment

begin_define
define|#
directive|define
name|Reg32
value|0x4
end_define

begin_comment
comment|/* 32 bit reg */
end_comment

begin_define
define|#
directive|define
name|Reg
value|(Reg8|Reg16|Reg32)
end_define

begin_comment
comment|/* gen'l register */
end_comment

begin_define
define|#
directive|define
name|WordReg
value|(Reg16|Reg32)
end_define

begin_comment
comment|/* for push/pop operands */
end_comment

begin_comment
comment|/* immediate */
end_comment

begin_define
define|#
directive|define
name|Imm8
value|0x8
end_define

begin_comment
comment|/* 8 bit immediate */
end_comment

begin_define
define|#
directive|define
name|Imm8S
value|0x10
end_define

begin_comment
comment|/* 8 bit immediate sign extended */
end_comment

begin_define
define|#
directive|define
name|Imm16
value|0x20
end_define

begin_comment
comment|/* 16 bit immediate */
end_comment

begin_define
define|#
directive|define
name|Imm32
value|0x40
end_define

begin_comment
comment|/* 32 bit immediate */
end_comment

begin_define
define|#
directive|define
name|Imm1
value|0x80
end_define

begin_comment
comment|/* 1 bit immediate */
end_comment

begin_define
define|#
directive|define
name|ImmUnknown
value|Imm32
end_define

begin_comment
comment|/* for unknown expressions */
end_comment

begin_define
define|#
directive|define
name|Imm
value|(Imm8|Imm8S|Imm16|Imm32)
end_define

begin_comment
comment|/* gen'l immediate */
end_comment

begin_comment
comment|/* memory */
end_comment

begin_define
define|#
directive|define
name|Disp8
value|0x200
end_define

begin_comment
comment|/* 8 bit displacement (for jumps) */
end_comment

begin_define
define|#
directive|define
name|Disp16
value|0x400
end_define

begin_comment
comment|/* 16 bit displacement */
end_comment

begin_define
define|#
directive|define
name|Disp32
value|0x800
end_define

begin_comment
comment|/* 32 bit displacement */
end_comment

begin_define
define|#
directive|define
name|Disp
value|(Disp8|Disp16|Disp32)
end_define

begin_comment
comment|/* General displacement */
end_comment

begin_define
define|#
directive|define
name|DispUnknown
value|Disp32
end_define

begin_comment
comment|/* for unknown size displacements */
end_comment

begin_define
define|#
directive|define
name|Mem8
value|0x1000
end_define

begin_define
define|#
directive|define
name|Mem16
value|0x2000
end_define

begin_define
define|#
directive|define
name|Mem32
value|0x4000
end_define

begin_define
define|#
directive|define
name|BaseIndex
value|0x8000
end_define

begin_define
define|#
directive|define
name|Mem
value|(Disp|Mem8|Mem16|Mem32|BaseIndex)
end_define

begin_comment
comment|/* General memory */
end_comment

begin_define
define|#
directive|define
name|WordMem
value|(Mem16|Mem32|Disp|BaseIndex)
end_define

begin_define
define|#
directive|define
name|ByteMem
value|(Mem8|Disp|BaseIndex)
end_define

begin_comment
comment|/* specials */
end_comment

begin_define
define|#
directive|define
name|InOutPortReg
value|0x10000
end_define

begin_comment
comment|/* register to hold in/out port addr = dx */
end_comment

begin_define
define|#
directive|define
name|ShiftCount
value|0x20000
end_define

begin_comment
comment|/* register to hold shift cound = cl */
end_comment

begin_define
define|#
directive|define
name|Control
value|0x40000
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|Debug
value|0x80000
end_define

begin_comment
comment|/* Debug register */
end_comment

begin_define
define|#
directive|define
name|Test
value|0x100000
end_define

begin_comment
comment|/* Test register */
end_comment

begin_define
define|#
directive|define
name|FloatReg
value|0x200000
end_define

begin_comment
comment|/* Float register */
end_comment

begin_define
define|#
directive|define
name|FloatAcc
value|0x400000
end_define

begin_comment
comment|/* Float stack top %st(0) */
end_comment

begin_define
define|#
directive|define
name|SReg2
value|0x800000
end_define

begin_comment
comment|/* 2 bit segment register */
end_comment

begin_define
define|#
directive|define
name|SReg3
value|0x1000000
end_define

begin_comment
comment|/* 3 bit segment register */
end_comment

begin_define
define|#
directive|define
name|Acc
value|0x2000000
end_define

begin_comment
comment|/* Accumulator %al or %ax or %eax */
end_comment

begin_define
define|#
directive|define
name|ImplicitRegister
value|(InOutPortReg|ShiftCount|Acc|FloatAcc)
end_define

begin_define
define|#
directive|define
name|JumpAbsolute
value|0x4000000
end_define

begin_define
define|#
directive|define
name|Abs8
value|0x08000000
end_define

begin_define
define|#
directive|define
name|Abs16
value|0x10000000
end_define

begin_define
define|#
directive|define
name|Abs32
value|0x20000000
end_define

begin_define
define|#
directive|define
name|Abs
value|(Abs8|Abs16|Abs32)
end_define

begin_define
define|#
directive|define
name|RegMMX
value|0x40000000
end_define

begin_comment
comment|/* MMX register */
end_comment

begin_define
define|#
directive|define
name|Byte
value|(Reg8|Imm8|Imm8S)
end_define

begin_define
define|#
directive|define
name|Word
value|(Reg16|Imm16)
end_define

begin_define
define|#
directive|define
name|DWord
value|(Reg32|Imm32)
end_define

begin_define
define|#
directive|define
name|SMALLEST_DISP_TYPE
parameter_list|(
name|num
parameter_list|)
define|\
value|fits_in_signed_byte(num) ? (Disp8|Disp32|Abs8|Abs32) : (Disp32|Abs32)
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
comment|/* base_opcode is the fundamental opcode byte with a optional prefix(es). */
name|unsigned
name|int
name|base_opcode
decl_stmt|;
comment|/* extension_opcode is the 3 bit extension for group<n> insns.      If this template has no extension opcode (the usual case) use None */
name|unsigned
name|char
name|extension_opcode
decl_stmt|;
define|#
directive|define
name|None
value|0xff
comment|/* If no extension_opcode is possible. */
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
comment|/* set if operands are words or dwords */
define|#
directive|define
name|D
value|0x2
comment|/* D = 0 if Reg --> Regmem; D = 1 if Regmem --> Reg */
comment|/* direction flag for floating insns:  MUST BE 0x400 */
define|#
directive|define
name|FloatD
value|0x400
comment|/* shorthand */
define|#
directive|define
name|DW
value|(D|W)
define|#
directive|define
name|ShortForm
value|0x10
comment|/* register is in low 3 bits of opcode */
define|#
directive|define
name|ShortFormW
value|0x20
comment|/* ShortForm and W bit is 0x8 */
define|#
directive|define
name|Seg2ShortForm
value|0x40
comment|/* encoding of load segment reg insns */
define|#
directive|define
name|Seg3ShortForm
value|0x80
comment|/* fs/gs segment register insns. */
define|#
directive|define
name|Jump
value|0x100
comment|/* special case for jump insns. */
define|#
directive|define
name|JumpInterSegment
value|0x200
comment|/* special case for intersegment leaps/calls */
comment|/* 0x400 CANNOT BE USED since it's already used by FloatD above */
define|#
directive|define
name|DONT_USE
value|0x400
define|#
directive|define
name|NoModrm
value|0x800
define|#
directive|define
name|Modrm
value|0x1000
define|#
directive|define
name|imulKludge
value|0x2000
define|#
directive|define
name|JumpByte
value|0x4000
define|#
directive|define
name|JumpDword
value|0x8000
define|#
directive|define
name|ReverseRegRegmem
value|0x10000
define|#
directive|define
name|Data16
value|0x20000
comment|/* needs data prefix if in 32-bit mode */
define|#
directive|define
name|Data32
value|0x40000
comment|/* needs data prefix if in 16-bit mode */
define|#
directive|define
name|iclrKludge
value|0x80000
comment|/* used to convert clr to xor */
comment|/* (opcode_modifier& COMES_IN_ALL_SIZES) is true if the      instuction comes in byte, word, and dword sizes and is encoded into      machine code in the canonical way. */
define|#
directive|define
name|COMES_IN_ALL_SIZES
value|(W)
comment|/* (opcode_modifier& COMES_IN_BOTH_DIRECTIONS) indicates that the      source and destination operands can be reversed by setting either      the D (for integer insns) or the FloatD (for floating insns) bit      in base_opcode. */
define|#
directive|define
name|COMES_IN_BOTH_DIRECTIONS
value|(D|FloatD)
comment|/* operand_types[i] describes the type of operand i.  This is made      by OR'ing together all of the possible type masks.  (e.g.      'operand_types[i] = Reg|Imm' specifies that operand i can be      either a register or an immediate operand */
name|unsigned
name|int
name|operand_types
index|[
literal|3
index|]
decl_stmt|;
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
name|template
modifier|*
name|start
decl_stmt|;
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
comment|/* these are for prefix name --> prefix code hash lookup */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|prefix_name
decl_stmt|;
name|unsigned
name|char
name|prefix_code
decl_stmt|;
block|}
name|prefix_entry
typedef|;
end_typedef

begin_comment
comment|/* 386 operand encoding bytes:  see 386 book for details of this. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|regmem
range|:
literal|3
decl_stmt|;
comment|/* codes register or memory operand */
name|unsigned
name|reg
range|:
literal|3
decl_stmt|;
comment|/* codes register operand (or extended opcode) */
name|unsigned
name|mode
range|:
literal|2
decl_stmt|;
comment|/* how to interpret regmem& reg */
block|}
name|modrm_byte
typedef|;
end_typedef

begin_comment
comment|/* 386 opcode byte to code indirect addressing. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|base
range|:
literal|3
decl_stmt|;
name|unsigned
name|index
range|:
literal|3
decl_stmt|;
name|unsigned
name|scale
range|:
literal|2
decl_stmt|;
block|}
name|base_index_byte
typedef|;
end_typedef

begin_comment
comment|/* The name of the global offset table generated by the compiler. Allow    this to be overridden if need be. */
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

begin_decl_stmt
specifier|extern
name|int
name|flag_16bit_code
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
value|if ((n)&& !need_pass_2							\&& (!(fill) || ((char)*(fill) == (char)0x90&& (len) == 1))		\&& now_seg != data_section&& now_seg != bss_section)		\   {									\     char *p;								\     p = frag_var (rs_align_code, 15, 1, (relax_substateT) max,		\ 		  (symbolS *) 0, (offsetT) (n), (char *) 0);		\     *p = 0x90;								\     goto around;							\   }
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

begin_comment
comment|/* call md_apply_fix3 with segment instead of md_apply_fix */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_FIX3
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

begin_comment
comment|/* end of tc-i386.h */
end_comment

end_unit

