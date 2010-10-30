begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-xtensa.h -- Header file for tc-xtensa.c.    Copyright (C) 2003, 2004, 2005, 2007 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_XTENSA
end_ifndef

begin_define
define|#
directive|define
name|TC_XTENSA
value|1
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_ELF
end_ifndef

begin_error
error|#
directive|error
error|Xtensa support requires ELF object format
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xtensa-isa.h"
end_include

begin_include
include|#
directive|include
file|"xtensa-config.h"
end_include

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|XCHAL_HAVE_BE
end_define

begin_comment
comment|/* Maximum number of opcode slots in a VLIW instruction.  */
end_comment

begin_define
define|#
directive|define
name|MAX_SLOTS
value|15
end_define

begin_comment
comment|/* For all xtensa relax states except RELAX_DESIRE_ALIGN and    RELAX_DESIRE_ALIGN_IF_TARGET, the amount a frag might grow is stored    in the fr_var field.  For the two exceptions, fr_var is a float value    that records the frequency with which the following instruction is    executed as a branch target.  The aligner uses this information to    tell which targets are most important to be aligned.  */
end_comment

begin_enum
enum|enum
name|xtensa_relax_statesE
block|{
name|RELAX_ALIGN_NEXT_OPCODE
block|,
comment|/* Use the first opcode of the next fragment to determine the      alignment requirements.  This is ONLY used for LOOPs currently.  */
name|RELAX_CHECK_ALIGN_NEXT_OPCODE
block|,
comment|/* The next non-empty frag contains a loop instruction.  Check to see      if it is correctly aligned, but do not align it.  */
name|RELAX_DESIRE_ALIGN_IF_TARGET
block|,
comment|/* These are placed in front of labels and converted to either      RELAX_DESIRE_ALIGN / RELAX_LOOP_END or rs_fill of 0 before      relaxation begins.  */
name|RELAX_ADD_NOP_IF_A0_B_RETW
block|,
comment|/* These are placed in front of conditional branches.  Before      relaxation begins, they are turned into either NOPs for branches      immediately followed by RETW or RETW.N or rs_fills of 0.  This is      used to avoid a hardware bug in some early versions of the      processor.  */
name|RELAX_ADD_NOP_IF_PRE_LOOP_END
block|,
comment|/* These are placed after JX instructions.  Before relaxation begins,      they are turned into either NOPs, if the JX is one instruction      before a loop end label, or rs_fills of 0.  This is used to avoid a      hardware interlock issue prior to Xtensa version T1040.  */
name|RELAX_ADD_NOP_IF_SHORT_LOOP
block|,
comment|/* These are placed after LOOP instructions and turned into NOPs when:      (1) there are less than 3 instructions in the loop; we place 2 of      these in a row to add up to 2 NOPS in short loops; or (2) the      instructions in the loop do not include a branch or jump.      Otherwise they are turned into rs_fills of 0 before relaxation      begins.  This is used to avoid hardware bug PR3830.  */
name|RELAX_ADD_NOP_IF_CLOSE_LOOP_END
block|,
comment|/* These are placed after LOOP instructions and turned into NOPs if      there are less than 12 bytes to the end of some other loop's end.      Otherwise they are turned into rs_fills of 0 before relaxation      begins.  This is used to avoid hardware bug PR3830.  */
name|RELAX_DESIRE_ALIGN
block|,
comment|/* The next fragment would like its first instruction to NOT cross an      instruction fetch boundary.  */
name|RELAX_MAYBE_DESIRE_ALIGN
block|,
comment|/* The next fragment might like its first instruction to NOT cross an      instruction fetch boundary.  These are placed after a branch that      might be relaxed.  If the branch is relaxed, then this frag will be      a branch target and this frag will be changed to RELAX_DESIRE_ALIGN      frag.  */
name|RELAX_LOOP_END
block|,
comment|/* This will be turned into a NOP or NOP.N if the previous instruction      is expanded to negate a loop.  */
name|RELAX_LOOP_END_ADD_NOP
block|,
comment|/* When the code density option is available, this will generate a      NOP.N marked RELAX_NARROW.  Otherwise, it will create an rs_fill      fragment with a NOP in it.  */
name|RELAX_LITERAL
block|,
comment|/* Another fragment could generate an expansion here but has not yet.  */
name|RELAX_LITERAL_NR
block|,
comment|/* Expansion has been generated by an instruction that generates a      literal.  However, the stretch has NOT been reported yet in this      fragment.  */
name|RELAX_LITERAL_FINAL
block|,
comment|/* Expansion has been generated by an instruction that generates a      literal.  */
name|RELAX_LITERAL_POOL_BEGIN
block|,
name|RELAX_LITERAL_POOL_END
block|,
comment|/* Technically these are not relaxations at all but mark a location      to store literals later.  Note that fr_var stores the frchain for      BEGIN frags and fr_var stores now_seg for END frags.  */
name|RELAX_NARROW
block|,
comment|/* The last instruction in this fragment (at->fr_opcode) can be      freely replaced with a single wider instruction if a future      alignment desires or needs it.  */
name|RELAX_IMMED
block|,
comment|/* The last instruction in this fragment (at->fr_opcode) contains      an immediate or symbol.  If the value does not fit, relax the      opcode using expansions from the relax table.  */
name|RELAX_IMMED_STEP1
block|,
comment|/* The last instruction in this fragment (at->fr_opcode) contains a      literal.  It has already been expanded 1 step.  */
name|RELAX_IMMED_STEP2
block|,
comment|/* The last instruction in this fragment (at->fr_opcode) contains a      literal.  It has already been expanded 2 steps.  */
name|RELAX_IMMED_STEP3
block|,
comment|/* The last instruction in this fragment (at->fr_opcode) contains a      literal.  It has already been expanded 3 steps.  */
name|RELAX_SLOTS
block|,
comment|/* There are instructions within the last VLIW instruction that need      relaxation.  Find the relaxation based on the slot info in      xtensa_frag_type.  Relaxations that deal with particular opcodes      are slot-based (e.g., converting a MOVI to an L32R).  Relaxations      that deal with entire instructions, such as alignment, are not      slot-based.  */
name|RELAX_FILL_NOP
block|,
comment|/* This marks the location of a pipeline stall.  We can fill these guys      in for alignment of any size.  */
name|RELAX_UNREACHABLE
block|,
comment|/* This marks the location as unreachable.  The assembler may widen or      narrow this area to meet alignment requirements of nearby      instructions.  */
name|RELAX_MAYBE_UNREACHABLE
block|,
comment|/* This marks the location as possibly unreachable.  These are placed      after a branch that may be relaxed into a branch and jump. If the      branch is relaxed, then this frag will be converted to a      RELAX_UNREACHABLE frag.  */
name|RELAX_ORG
block|,
comment|/* This marks the location as having previously been an rs_org frag.        rs_org frags are converted to fill-zero frags immediately after      relaxation.  However, we need to remember where they were so we can      prevent the linker from changing the size of any frag between the      section start and the org frag.  */
name|RELAX_NONE
block|}
enum|;
end_enum

begin_comment
comment|/* This is used as a stopper to bound the number of steps that    can be taken.  */
end_comment

begin_define
define|#
directive|define
name|RELAX_IMMED_MAXSTEPS
value|(RELAX_IMMED_STEP3 - RELAX_IMMED)
end_define

begin_struct
struct|struct
name|xtensa_frag_type
block|{
comment|/* Info about the current state of assembly, e.g., transform,      absolute_literals, etc.  These need to be passed to the backend and      then to the object file.       When is_assembly_state_set is false, the frag inherits some of the      state settings from the previous frag in this segment.  Because it      is not possible to intercept all fragment closures (frag_more and      frag_append_1_char can close a frag), we use a pass after initial      assembly to fill in the assembly states.  */
name|unsigned
name|int
name|is_assembly_state_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_no_density
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_no_transform
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|use_longcalls
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|use_absolute_literals
range|:
literal|1
decl_stmt|;
comment|/* Inhibits relaxation of machine-dependent alignment frags the      first time through a relaxation....  */
name|unsigned
name|int
name|relax_seen
range|:
literal|1
decl_stmt|;
comment|/* Information that is needed in the object file and set when known.  */
name|unsigned
name|int
name|is_literal
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_loop_target
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_branch_target
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_insn
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_unreachable
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_specific_opcode
range|:
literal|1
decl_stmt|;
comment|/* also implies no_transform */
name|unsigned
name|int
name|is_align
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_text_align
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|alignment
range|:
literal|5
decl_stmt|;
comment|/* A frag with this bit set is the first in a loop that actually      contains an instruction.  */
name|unsigned
name|int
name|is_first_loop_insn
range|:
literal|1
decl_stmt|;
comment|/* A frag with this bit set is a branch that we are using to      align branch targets as if it were a normal narrow instruction.  */
name|unsigned
name|int
name|is_aligning_branch
range|:
literal|1
decl_stmt|;
comment|/* For text fragments that can generate literals at relax time, this      variable points to the frag where the literal will be stored.  For      literal frags, this variable points to the nearest literal pool      location frag.  This literal frag will be moved to after this      location.  For RELAX_LITERAL_POOL_BEGIN frags, this field points      to the frag immediately before the corresponding RELAX_LITERAL_POOL_END      frag, to make moving frags for this literal pool efficient.  */
name|fragS
modifier|*
name|literal_frag
decl_stmt|;
comment|/* The destination segment for literal frags.  (Note that this is only      valid after xtensa_move_literals.)  This field is also used for      LITERAL_POOL_END frags.  */
name|segT
name|lit_seg
decl_stmt|;
comment|/* Frag chain for LITERAL_POOL_BEGIN frags.  */
name|struct
name|frchain
modifier|*
name|lit_frchain
decl_stmt|;
comment|/* For the relaxation scheme, some literal fragments can have their      expansions modified by an instruction that relaxes.  */
name|int
name|text_expansion
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
name|int
name|literal_expansion
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
name|int
name|unreported_expansion
decl_stmt|;
comment|/* For text fragments that can generate literals at relax time:  */
name|fragS
modifier|*
name|literal_frags
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
name|enum
name|xtensa_relax_statesE
name|slot_subtypes
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
name|symbolS
modifier|*
name|slot_symbols
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
name|offsetT
name|slot_offsets
index|[
name|MAX_SLOTS
index|]
decl_stmt|;
comment|/* The global aligner needs to walk backward through the list of      frags.  This field is only valid after xtensa_end.  */
name|fragS
modifier|*
name|fr_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For VLIW support, we need to know what slot a fixup applies to.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xtensa_fix_data_struct
block|{
name|int
name|slot
decl_stmt|;
name|symbolS
modifier|*
name|X_add_symbol
decl_stmt|;
name|offsetT
name|X_add_number
decl_stmt|;
block|}
name|xtensa_fix_data
typedef|;
end_typedef

begin_comment
comment|/* Structure to record xtensa-specific symbol information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xtensa_symfield_type
block|{
name|unsigned
name|int
name|is_loop_target
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_branch_target
range|:
literal|1
decl_stmt|;
block|}
name|xtensa_symfield_type
typedef|;
end_typedef

begin_comment
comment|/* Structure for saving information about a block of property data    for frags that have the same flags.   The forward reference is    in this header file.  The actual definition is in tc-xtensa.c.  */
end_comment

begin_struct_decl
struct_decl|struct
name|xtensa_block_info_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|xtensa_block_info_struct
name|xtensa_block_info
typedef|;
end_typedef

begin_comment
comment|/* Property section types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|xt_literal_sec
block|,
name|xt_prop_sec
block|,
name|max_xt_sec
block|}
name|xt_section_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_segment_info_struct
block|{
name|fragS
modifier|*
name|literal_pool_loc
decl_stmt|;
name|xtensa_block_info
modifier|*
name|blocks
index|[
name|max_xt_sec
index|]
decl_stmt|;
block|}
name|xtensa_segment_info
typedef|;
end_typedef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|xtensa_target_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_init_fix_data
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_frag_init
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xtensa_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xtensa_validate_fix_sub
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_frob_label
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_post_relax_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_file_arch_init
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_flush_pending_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|xtensa_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_symbol_new_hook
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|xtensa_relax_frag
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_elf_section_change_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xtensa_unrecognized_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|xtensa_check_inside_bundle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xtensa_handle_align
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xtensa_section_rename
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|xtensa_target_format ()
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_xtensa
end_define

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|xtensa_segment_info
end_define

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|struct xtensa_symfield_type
end_define

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|xtensa_fix_data
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|x
parameter_list|)
value|xtensa_init_fix_data (x)
end_define

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|struct xtensa_frag_type
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|frag
parameter_list|)
value|xtensa_frag_init (frag)
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fix
parameter_list|)
value|xtensa_force_relocation (fix)
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_SAME
parameter_list|(
name|fix
parameter_list|,
name|seg
parameter_list|)
define|\
value|(! SEG_NORMAL (seg) || xtensa_force_relocation (fix))
end_define

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX_SUB
parameter_list|(
name|fix
parameter_list|)
value|xtensa_validate_fix_sub (fix)
end_define

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|xtensa_check_inside_bundle ()
end_define

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|s
parameter_list|)
value|xtensa_section_rename (s)
end_define

begin_define
define|#
directive|define
name|tc_canonicalize_section_name
parameter_list|(
name|s
parameter_list|)
value|xtensa_section_rename (s)
end_define

begin_define
define|#
directive|define
name|tc_init_after_args
parameter_list|()
value|xtensa_file_arch_init (stdoutput)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|fix
parameter_list|)
value|xtensa_fix_adjustable (fix)
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|xtensa_frob_label (sym)
end_define

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|ch
parameter_list|)
value|xtensa_unrecognized_line (ch)
end_define

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|xtensa_flush_pending_output ()
end_define

begin_define
define|#
directive|define
name|md_elf_section_change_hook
value|xtensa_elf_section_change_hook
end_define

begin_define
define|#
directive|define
name|md_end
value|xtensa_end
end_define

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|xtensa_flush_pending_output ()
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TEXT_SECTION_NAME
value|xtensa_section_rename (".text")
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_NAME
value|xtensa_section_rename (".data")
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_NAME
value|xtensa_section_rename (".bss")
end_define

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|fragP
parameter_list|)
value|xtensa_handle_align (fragP)
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|1
end_define

begin_comment
comment|/* The renumber_section function must be mapped over all the sections    after calling xtensa_post_relax_hook.  That function is static in    write.c so it cannot be called from xtensa_post_relax_hook itself.  */
end_comment

begin_define
define|#
directive|define
name|md_post_relax_hook
define|\
value|do \     { \       int i = 0; \       xtensa_post_relax_hook (); \       bfd_map_over_sections (stdoutput, renumber_sections,&i); \     } \   while (0)
end_define

begin_comment
comment|/* Because xtensa relaxation can insert a new literal into the middle of    fragment and thus require re-running the relaxation pass on the    section, we need an explicit flag here.  We explicitly use the name    "stretched" here to avoid changing the source code in write.c.  */
end_comment

begin_define
define|#
directive|define
name|md_relax_frag
parameter_list|(
name|segment
parameter_list|,
name|fragP
parameter_list|,
name|stretch
parameter_list|)
define|\
value|xtensa_relax_frag (fragP, stretch,&stretched)
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|DOUBLESLASH_LINE_COMMENTS
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_define
define|#
directive|define
name|TC_FINALIZE_SYMS_BEFORE_SIZE_SEG
value|0
end_define

begin_define
define|#
directive|define
name|TC_LINKRELAX_FIXUP
parameter_list|(
name|SEG
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

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

begin_comment
comment|/* Use line number format that is amenable to linker relaxation.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_USE_FIXED_ADVANCE_PC
value|(linkrelax != 0)
end_define

begin_comment
comment|/* Resource reservation info functions.  */
end_comment

begin_comment
comment|/* Returns the number of copies of a particular unit.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|unit_num_copies_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xtensa_funcUnit
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Returns the number of units the opcode uses.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|opcode_num_units_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Given an opcode and an index into the opcode's funcUnit list,    returns the unit used for the index.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|opcode_funcUnit_use_unit_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Given an opcode and an index into the opcode's funcUnit list,    returns the cycle during which the unit is used.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|opcode_funcUnit_use_stage_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The above typedefs parameterize the resource_table so that the    optional scheduler doesn't need its own resource reservation system.     For simple resource checking, which is all that happens normally,    the functions will be as follows (with some wrapping to make the    interface more convenient):     unit_num_copies_func = xtensa_funcUnit_num_copies    opcode_num_units_func = xtensa_opcode_num_funcUnit_uses    opcode_funcUnit_use_unit_func = xtensa_opcode_funcUnit_use->unit    opcode_funcUnit_use_stage_func = xtensa_opcode_funcUnit_use->stage     Of course the optional scheduler has its own reservation table    and functions.  */
end_comment

begin_function_decl
name|int
name|opcode_funcUnit_use_unit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|opcode_funcUnit_use_stage
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|cycles
decl_stmt|;
name|int
name|allocated_cycles
decl_stmt|;
name|int
name|num_units
decl_stmt|;
name|unit_num_copies_func
name|unit_num_copies
decl_stmt|;
name|opcode_num_units_func
name|opcode_num_units
decl_stmt|;
name|opcode_funcUnit_use_unit_func
name|opcode_unit_use
decl_stmt|;
name|opcode_funcUnit_use_stage_func
name|opcode_unit_stage
decl_stmt|;
name|unsigned
name|char
modifier|*
modifier|*
name|units
decl_stmt|;
block|}
name|resource_table
typedef|;
end_typedef

begin_function_decl
name|resource_table
modifier|*
name|new_resource_table
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unit_num_copies_func
parameter_list|,
name|opcode_num_units_func
parameter_list|,
name|opcode_funcUnit_use_unit_func
parameter_list|,
name|opcode_funcUnit_use_stage_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resize_resource_table
parameter_list|(
name|resource_table
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clear_resource_table
parameter_list|(
name|resource_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|resources_available
parameter_list|(
name|resource_table
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reserve_resources
parameter_list|(
name|resource_table
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|release_resources
parameter_list|(
name|resource_table
modifier|*
parameter_list|,
name|xtensa_opcode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_XTENSA */
end_comment

end_unit

