begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-frv.h -- Header file for tc-frv.c.    Copyright 2002, 2004, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA. */
end_comment

begin_define
define|#
directive|define
name|TC_FRV
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"FRV GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_frv
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(frv_md_fdpic_enabled () \ 		       ? "elf32-frvfdpic" : "elf32-frv")
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|frv_md_fdpic_enabled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* .-foo gets turned into PC relative relocs */
end_comment

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

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

begin_decl_stmt
specifier|extern
name|void
name|frv_tomcat_workaround
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
name|md_cleanup
value|frv_tomcat_workaround
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|frv_md_number_to_chars
end_define

begin_decl_stmt
specifier|extern
name|long
name|frv_relax_frag
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|frv_relax_frag(fragP, stretch)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|frv_fix_adjustable (FIX)
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|frv_fix_adjustable
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
comment|/* When relaxing, we need to emit various relocs we otherwise wouldn't.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fix
parameter_list|)
value|frv_force_relocation (fix)
end_define

begin_decl_stmt
specifier|extern
name|int
name|frv_force_relocation
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
comment|/* If we simplify subtractions that aren't SUB_SAME or SUB_ABS, we end    up with PCrel fixups, but since we don't have any PCrel relocs, we    crash.  Preventing simplification gets us a good, early error.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_LOCAL
parameter_list|(
name|fixP
parameter_list|)
value|1
end_define

begin_undef
undef|#
directive|undef
name|GAS_CGEN_MAX_FIXUPS
end_undef

begin_define
define|#
directive|define
name|GAS_CGEN_MAX_FIXUPS
value|1
end_define

begin_decl_stmt
name|void
name|frv_frob_label
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|frv_frob_label(sym)
end_define

begin_define
define|#
directive|define
name|tc_gen_reloc
value|gas_cgen_tc_gen_reloc
end_define

begin_define
define|#
directive|define
name|md_cgen_record_fixup_exp
value|frv_cgen_record_fixup_exp
end_define

begin_comment
comment|/* Call md_pcrel_from_section(), not md_pcrel_from().  */
end_comment

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section (FIX, SEC)
end_define

begin_decl_stmt
specifier|extern
name|long
name|md_pcrel_from_section
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After all of the symbols have been adjusted, go over the file looking    for any relocations that pic won't support.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_file
parameter_list|()
value|frv_frob_file ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|frv_frob_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We don't want 0x00 for code alignment because this generates `add.p    gr0, gr0, gr0' patterns.  Although it's fine as a nop instruction,    it has the VLIW packing bit set, which means if you have a bunch of    them in a row and attempt to execute them, you'll exceed the VLIW    capacity and fail.  This also gets GDB confused sometimes, because    it won't set breakpoints in instructions other than the first of a    VLIW pack, so you used to be unable to set a breakpoint in the    initial instruction of a function that followed such    alignment-introduced instructions.     We could have arranged to emit `nop' instructions (0x80880000),    maybe even VLIW-pack sequences of nop instructions as much as    possible for the selected machine type, just in case the alignment    code actually happens to run, but this is probably too much effort    for little gain.  This code is not meant to be run anyway, so just    emit nops.  */
end_comment

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(3 + 4)
end_define

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|FRAGP
parameter_list|)
value|do						\   if ((FRAGP)->fr_type == rs_align_code) 				\     {									\       valueT count = ((FRAGP)->fr_next->fr_address			\ 		      - ((FRAGP)->fr_address + (FRAGP)->fr_fix));	\       char *dest = (FRAGP)->fr_literal + (FRAGP)->fr_fix;		\       if ((count& 3) != 0)						\ 	{								\ 	  memset (dest, 0, (count& 3));				\ 	  (FRAGP)->fr_fix += (count& 3);				\ 	  dest += (count& 3);						\ 	  count -= (count& 3);						\ 	}								\       if (count)							\ 	{								\ 	  (FRAGP)->fr_var = 4;						\ 	  *dest++ = 0x80;						\ 	  *dest++ = 0x88;						\ 	  *dest++ = 0x00;						\ 	  *dest++ = 0x00;						\ 	}								\     }									\  while (0)
end_define

end_unit

