begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-ia64.h -- Header file for tc-ia64.c.    Copyright 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by David Mosberger-Tang<davidm@hpl.hp.com>     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<opcode/ia64.h>
end_include

begin_include
include|#
directive|include
file|<elf/ia64.h>
end_include

begin_define
define|#
directive|define
name|TC_IA64
end_define

begin_comment
comment|/* Linux is little endian by default.  HPUX is big endian by default.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TE_HPUX
end_ifdef

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_bigendian
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|MD_FLAGS_DEFAULT
value|EF_IA_64_BE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|MD_FLAGS_DEFAULT
value|EF_IA_64_ABI64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TE_HPUX */
end_comment

begin_comment
comment|/* We need to set the default object file format in ia64_init and not in    md_begin.  This is because parse_args is called before md_begin, and we    do not want md_begin to wipe out the flag settings set by options parsed in    md_parse_args.  */
end_comment

begin_define
define|#
directive|define
name|HOST_SPECIAL_INIT
value|ia64_init
end_define

begin_decl_stmt
specifier|extern
name|void
name|ia64_init
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|ia64_target_format()
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ia64_target_format
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
name|TARGET_ARCH
value|bfd_arch_ia64
end_define

begin_define
define|#
directive|define
name|DOUBLESLASH_LINE_COMMENTS
end_define

begin_comment
comment|/* allow //-style comments */
end_comment

begin_define
define|#
directive|define
name|NEED_LITERAL_POOL
end_define

begin_comment
comment|/* need gp literal pool */
end_comment

begin_define
define|#
directive|define
name|RELOC_REQUIRES_SYMBOL
end_define

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
name|NEED_INDEX_OPERATOR
end_define

begin_comment
comment|/* [ ] is index operator */
end_comment

begin_define
define|#
directive|define
name|QUOTES_IN_INSN
end_define

begin_comment
comment|/* allow `string "foo;bar"' */
end_comment

begin_define
define|#
directive|define
name|LEX_AT
value|LEX_NAME
end_define

begin_comment
comment|/* allow `@' inside name */
end_comment

begin_define
define|#
directive|define
name|LEX_QM
value|LEX_NAME
end_define

begin_comment
comment|/* allow `?' inside name */
end_comment

begin_define
define|#
directive|define
name|LEX_HASH
value|LEX_END_NAME
end_define

begin_comment
comment|/* allow `#' ending a name */
end_comment

begin_struct
struct|struct
name|ia64_fix
block|{
name|int
name|bigendian
decl_stmt|;
comment|/* byte order at fix location */
name|enum
name|ia64_opnd
name|opnd
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|ia64_do_align
name|PARAMS
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_end_of_source
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_start_line
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_unrecognized_line
name|PARAMS
argument_list|(
operator|(
name|int
name|ch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_frob_label
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
name|sym
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_flush_pending_output
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|ia64_parse_name
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|expressionS
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|ia64_optimize_expr
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
name|l
operator|,
name|operatorT
name|op
operator|,
name|expressionS
operator|*
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_cons_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_flush_insns
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_fix_adjustable
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
name|fix
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_force_relocation
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

begin_decl_stmt
specifier|extern
name|void
name|ia64_cons_fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|f
operator|,
name|int
name|where
operator|,
name|int
name|nbytes
operator|,
name|expressionS
operator|*
name|exp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_validate_fix
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
name|fix
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ia64_canonicalize_symbol_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_elf_section_letter
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flagword
name|ia64_elf_section_flags
name|PARAMS
argument_list|(
operator|(
name|flagword
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_elf_section_type
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ia64_pcrel_from_section
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
name|fix
operator|,
name|segT
name|sec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_md_do_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_handle_align
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|f
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ia64_after_parse_args
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
name|md_end
parameter_list|()
value|ia64_end_of_source ()
end_define

begin_define
define|#
directive|define
name|md_start_line_hook
parameter_list|()
value|ia64_start_line ()
end_define

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|ch
parameter_list|)
value|ia64_unrecognized_line (ch)
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|s
parameter_list|)
value|ia64_frob_label (s)
end_define

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|ia64_flush_pending_output ()
end_define

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|,
name|c
parameter_list|)
value|ia64_parse_name (s, e)
end_define

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|s
parameter_list|)
value|ia64_canonicalize_symbol_name (s)
end_define

begin_define
define|#
directive|define
name|md_optimize_expr
parameter_list|(
name|l
parameter_list|,
name|o
parameter_list|,
name|r
parameter_list|)
value|ia64_optimize_expr (l, o, r)
end_define

begin_define
define|#
directive|define
name|md_cons_align
parameter_list|(
name|n
parameter_list|)
value|ia64_cons_align (n)
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|f
parameter_list|)
value|ia64_force_relocation (f)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|f
parameter_list|)
value|ia64_fix_adjustable (f)
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|as_fatal ("ia64_convert_frag")
end_define

begin_define
define|#
directive|define
name|md_create_long_jump
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|,
name|fr
parameter_list|,
name|s
parameter_list|)
value|as_fatal ("ia64_create_long_jump")
end_define

begin_define
define|#
directive|define
name|md_create_short_jump
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|,
name|fr
parameter_list|,
name|s
parameter_list|)
define|\
value|as_fatal ("ia64_create_short_jump")
end_define

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(as_fatal ("ia64_estimate_size_before_relax"), 1)
end_define

begin_define
define|#
directive|define
name|md_elf_section_letter
value|ia64_elf_section_letter
end_define

begin_define
define|#
directive|define
name|md_elf_section_flags
value|ia64_elf_section_flags
end_define

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|struct ia64_fix
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|f
parameter_list|)
value|{ f->tc_fix_data.opnd = 0; }
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|e
parameter_list|)
value|ia64_cons_fix_new (f, o, l, e)
end_define

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX
parameter_list|(
name|fix
parameter_list|,
name|seg
parameter_list|,
name|skip
parameter_list|)
value|ia64_validate_fix (fix)
end_define

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|fix
parameter_list|,
name|sec
parameter_list|)
value|ia64_pcrel_from_section (fix, sec)
end_define

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|,
name|m
parameter_list|,
name|j
parameter_list|)
value|ia64_md_do_align (n,f,l,m)
end_define

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|f
parameter_list|)
value|ia64_handle_align (f)
end_define

begin_define
define|#
directive|define
name|md_elf_section_type
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
value|ia64_elf_section_type (str, len)
end_define

begin_define
define|#
directive|define
name|md_after_parse_args
parameter_list|()
value|ia64_after_parse_args ()
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(15 + 16)
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* don't do broken word processing for now */
end_comment

begin_define
define|#
directive|define
name|ELF_TC_SPECIAL_SECTIONS
define|\
value|{ ".sbss",	SHT_NOBITS,	SHF_ALLOC + SHF_WRITE + SHF_IA_64_SHORT }, \ { ".sdata",	SHT_PROGBITS,	SHF_ALLOC + SHF_WRITE + SHF_IA_64_SHORT },
end_define

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|1
end_define

begin_comment
comment|/* so slot-multipliers can be 1 */
end_comment

begin_comment
comment|/* This is the information required for unwind records in an ia64    object file. This is required by GAS and the compiler runtime.  */
end_comment

begin_comment
comment|/* These are the starting point masks for the various types of    unwind records. To create a record of type R3 for instance, one    starts by using the value UNW_R3 and or-ing in any other required values.    These values are also unique (in context), so they can be used to identify    the various record types as well. UNW_Bx and some UNW_Px do have the    same value, but Px can only occur in a prologue context, and Bx in    a body context.  */
end_comment

begin_define
define|#
directive|define
name|UNW_R1
value|0x00
end_define

begin_define
define|#
directive|define
name|UNW_R2
value|0x40
end_define

begin_define
define|#
directive|define
name|UNW_R3
value|0x60
end_define

begin_define
define|#
directive|define
name|UNW_P1
value|0x80
end_define

begin_define
define|#
directive|define
name|UNW_P2
value|0xA0
end_define

begin_define
define|#
directive|define
name|UNW_P3
value|0xB0
end_define

begin_define
define|#
directive|define
name|UNW_P4
value|0xB8
end_define

begin_define
define|#
directive|define
name|UNW_P5
value|0xB9
end_define

begin_define
define|#
directive|define
name|UNW_P6
value|0xC0
end_define

begin_define
define|#
directive|define
name|UNW_P7
value|0xE0
end_define

begin_define
define|#
directive|define
name|UNW_P8
value|0xF0
end_define

begin_define
define|#
directive|define
name|UNW_P9
value|0xF1
end_define

begin_define
define|#
directive|define
name|UNW_P10
value|0xFF
end_define

begin_define
define|#
directive|define
name|UNW_X1
value|0xF9
end_define

begin_define
define|#
directive|define
name|UNW_X2
value|0xFA
end_define

begin_define
define|#
directive|define
name|UNW_X3
value|0xFB
end_define

begin_define
define|#
directive|define
name|UNW_X4
value|0xFC
end_define

begin_define
define|#
directive|define
name|UNW_B1
value|0x80
end_define

begin_define
define|#
directive|define
name|UNW_B2
value|0xC0
end_define

begin_define
define|#
directive|define
name|UNW_B3
value|0xE0
end_define

begin_define
define|#
directive|define
name|UNW_B4
value|0xF0
end_define

begin_comment
comment|/* These are all the various types of unwind records.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|prologue
block|,
name|prologue_gr
block|,
name|body
block|,
name|mem_stack_f
block|,
name|mem_stack_v
block|,
name|psp_gr
block|,
name|psp_sprel
block|,
name|rp_when
block|,
name|rp_gr
block|,
name|rp_br
block|,
name|rp_psprel
block|,
name|rp_sprel
block|,
name|pfs_when
block|,
name|pfs_gr
block|,
name|pfs_psprel
block|,
name|pfs_sprel
block|,
name|preds_when
block|,
name|preds_gr
block|,
name|preds_psprel
block|,
name|preds_sprel
block|,
name|fr_mem
block|,
name|frgr_mem
block|,
name|gr_gr
block|,
name|gr_mem
block|,
name|br_mem
block|,
name|br_gr
block|,
name|spill_base
block|,
name|spill_mask
block|,
name|unat_when
block|,
name|unat_gr
block|,
name|unat_psprel
block|,
name|unat_sprel
block|,
name|lc_when
block|,
name|lc_gr
block|,
name|lc_psprel
block|,
name|lc_sprel
block|,
name|fpsr_when
block|,
name|fpsr_gr
block|,
name|fpsr_psprel
block|,
name|fpsr_sprel
block|,
name|priunat_when_gr
block|,
name|priunat_when_mem
block|,
name|priunat_gr
block|,
name|priunat_psprel
block|,
name|priunat_sprel
block|,
name|bsp_when
block|,
name|bsp_gr
block|,
name|bsp_psprel
block|,
name|bsp_sprel
block|,
name|bspstore_when
block|,
name|bspstore_gr
block|,
name|bspstore_psprel
block|,
name|bspstore_sprel
block|,
name|rnat_when
block|,
name|rnat_gr
block|,
name|rnat_psprel
block|,
name|rnat_sprel
block|,
name|epilogue
block|,
name|label_state
block|,
name|copy_state
block|,
name|spill_psprel
block|,
name|spill_sprel
block|,
name|spill_reg
block|,
name|spill_psprel_p
block|,
name|spill_sprel_p
block|,
name|spill_reg_p
block|,
name|unwabi
block|}
name|unw_record_type
typedef|;
end_typedef

begin_comment
comment|/* These structures declare the fields that can be used in each of the    4 record formats, R, P, B and X.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|unw_r_record
block|{
name|unsigned
name|long
name|rlen
decl_stmt|;
name|unsigned
name|short
name|grmask
decl_stmt|;
name|unsigned
name|short
name|grsave
decl_stmt|;
comment|/* masks to represent the union of save.g, save.f, save.b, and      save.gf: */
name|unsigned
name|long
name|imask_size
decl_stmt|;
struct|struct
block|{
name|unsigned
name|char
modifier|*
name|i
decl_stmt|;
name|unsigned
name|long
name|fr_mem
decl_stmt|;
name|unsigned
name|char
name|gr_mem
decl_stmt|;
name|unsigned
name|char
name|br_mem
decl_stmt|;
block|}
name|mask
struct|;
block|}
name|unw_r_record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|unw_p_record
block|{
name|void
modifier|*
name|imask
decl_stmt|;
name|unsigned
name|long
name|t
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|unsigned
name|long
name|spoff
decl_stmt|;
name|unsigned
name|long
name|br
decl_stmt|;
name|unsigned
name|long
name|pspoff
decl_stmt|;
name|unsigned
name|short
name|gr
decl_stmt|;
name|unsigned
name|short
name|rmask
decl_stmt|;
name|unsigned
name|short
name|grmask
decl_stmt|;
name|unsigned
name|long
name|frmask
decl_stmt|;
name|unsigned
name|short
name|brmask
decl_stmt|;
name|unsigned
name|char
name|abi
decl_stmt|;
name|unsigned
name|char
name|context
decl_stmt|;
block|}
name|unw_p_record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|unw_b_record
block|{
name|unsigned
name|long
name|t
decl_stmt|;
name|unsigned
name|long
name|label
decl_stmt|;
name|unsigned
name|short
name|ecount
decl_stmt|;
block|}
name|unw_b_record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|unw_x_record
block|{
name|unsigned
name|long
name|t
decl_stmt|;
name|unsigned
name|long
name|spoff
decl_stmt|;
name|unsigned
name|long
name|pspoff
decl_stmt|;
name|unsigned
name|short
name|reg
decl_stmt|;
name|unsigned
name|short
name|treg
decl_stmt|;
name|unsigned
name|short
name|qp
decl_stmt|;
name|unsigned
name|short
name|ab
decl_stmt|;
comment|/* Value of the AB field..  */
name|unsigned
name|short
name|xy
decl_stmt|;
comment|/* Value of the XY field..  */
block|}
name|unw_x_record
typedef|;
end_typedef

begin_comment
comment|/* This structure is used to determine the specific record type and    its fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|unwind_record
block|{
name|unw_record_type
name|type
decl_stmt|;
union|union
block|{
name|unw_r_record
name|r
decl_stmt|;
name|unw_p_record
name|p
decl_stmt|;
name|unw_b_record
name|b
decl_stmt|;
name|unw_x_record
name|x
decl_stmt|;
block|}
name|record
union|;
block|}
name|unwind_record
typedef|;
end_typedef

begin_comment
comment|/* This expression evaluates to false if the relocation is for a local     object for which we still want to do the relocation at runtime.    True if we are willing to perform this relocation while building    the .o file.  This is only used for pcrel relocations.  */
end_comment

begin_comment
comment|/* If the reloc type is BFD_RELOC_UNUSED, then this is for a TAG13/TAG13b field    which has no external reloc, so we must resolve the value now.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_addsy == NULL					\    || (FIX)->fx_r_type == BFD_RELOC_UNUSED			\    || (! S_IS_EXTERNAL ((FIX)->fx_addsy)			\&& ! S_IS_WEAK ((FIX)->fx_addsy)				\&& S_IS_DEFINED ((FIX)->fx_addsy)			\&& ! S_IS_COMMON ((FIX)->fx_addsy)))
end_define

end_unit

