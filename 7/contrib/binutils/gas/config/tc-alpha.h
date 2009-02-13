begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-alpha.h    Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.    Written by Ken Raeburn<raeburn@cygnus.com>.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_ALPHA
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
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_alpha
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_FreeBSD
end_ifdef

begin_define
define|#
directive|define
name|ELF_TARGET_FORMAT
value|"elf64-alpha-freebsd"
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
value|"elf64-alpha"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(OUTPUT_FLAVOR == bfd_target_ecoff_flavour	\ 		       ? "ecoff-littlealpha"				\ 		       : OUTPUT_FLAVOR == bfd_target_elf_flavour	\ 		       ? ELF_TARGET_FORMAT				\ 		       : OUTPUT_FLAVOR == bfd_target_evax_flavour	\ 		       ? "vms-alpha"					\ 		       : "unknown-format")
end_define

begin_define
define|#
directive|define
name|NEED_LITERAL_POOL
end_define

begin_define
define|#
directive|define
name|REPEAT_CONS_EXPRESSIONS
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|alpha_reloc_tag
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|alpha_force_relocation
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
name|int
name|alpha_fix_adjustable
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
name|unsigned
name|long
name|alpha_gprmask
decl_stmt|,
name|alpha_fprmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|valueT
name|alpha_gp_value
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|alpha_force_relocation (FIX)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|alpha_fix_adjustable (FIX)
end_define

begin_define
define|#
directive|define
name|RELOC_REQUIRES_SYMBOL
end_define

begin_comment
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
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
value|as_fatal ("alpha convert_frag\n")
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
value|(as_fatal ("estimate_size_before_relax called"),1)
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_EVAX
end_ifdef

begin_comment
comment|/* This field keeps the symbols position in the link section.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|valueT
end_define

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
define|\
value|fix_new_exp (FRAG, OFF, (int)LEN, EXP, 0, \ 	LEN == 2 ? BFD_RELOC_16 \ 	: LEN == 4 ? BFD_RELOC_32 \ 	: LEN == 8 ? BFD_RELOC_64 \ 	: BFD_RELOC_ALPHA_LINKAGE);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|TC_IMPLICIT_LCOMM_ALIGNMENT
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
define|\
value|do							\     {							\       align = 0;					\       if (size> 1)					\ 	{						\ 	  addressT temp = 1;				\ 	  while ((size& temp) == 0)			\ 	    ++align, temp<<= 1;			\ 	}						\     }							\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_get_register
name|PARAMS
argument_list|(
operator|(
name|int
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|alpha_frob_ecoff_data
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
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|alpha_define_label (sym)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_define_label
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
name|md_cons_align
parameter_list|(
name|nbytes
parameter_list|)
value|alpha_cons_align (nbytes)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_cons_align
name|PARAMS
argument_list|(
operator|(
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
name|fragp
parameter_list|)
value|alpha_handle_align (fragp)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_handle_align
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(3 + 4 + 8)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ECOFF
end_ifdef

begin_define
define|#
directive|define
name|tc_frob_file_before_adjust
parameter_list|()
value|alpha_frob_file_before_adjust ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_frob_file_before_adjust
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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|md_elf_section_letter
value|alpha_elf_section_letter
end_define

begin_decl_stmt
specifier|extern
name|int
name|alpha_elf_section_letter
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
name|md_elf_section_flags
value|alpha_elf_section_flags
end_define

begin_decl_stmt
specifier|extern
name|flagword
name|alpha_elf_section_flags
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Whether to add support for explicit !relocation_op!sequence_number.  At the    moment, only do this for ELF, though ECOFF could use it as well.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|RELOC_OP_P
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Before the relocations are written, reorder them, so that user    supplied !lituse relocations follow the appropriate !literal    relocations.  Also convert the gas-internal relocations to the    appropriate linker relocations.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_file_before_fix
parameter_list|()
value|alpha_before_fix ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_before_fix
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
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|md_end
value|alpha_elf_md_end
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_elf_md_end
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
comment|/* New fields for supporting explicit relocations (such as !literal to mark    where a pointer is loaded from the global table, and !lituse_base to track    all of the normal uses of that pointer).  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|struct alpha_fix_tag
end_define

begin_struct
struct|struct
name|alpha_fix_tag
block|{
name|struct
name|fix
modifier|*
name|next_reloc
decl_stmt|;
comment|/* next !lituse or !gpdisp */
name|struct
name|alpha_reloc_tag
modifier|*
name|info
decl_stmt|;
comment|/* other members with same sequence */
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize the TC_FIX_TYPE field.  */
end_comment

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|FIX
parameter_list|)
define|\
value|do {									\   FIX->tc_fix_data.next_reloc = (struct fix *) 0;			\   FIX->tc_fix_data.info = (struct alpha_reloc_tag *) 0;			\ } while (0)
end_define

begin_comment
comment|/* Work with DEBUG5 to print fields in tc_fix_type.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_DATA_PRINT
parameter_list|(
name|STREAM
parameter_list|,
name|FIX
parameter_list|)
define|\
value|do {									\   if (FIX->tc_fix_data.info)						\     fprintf (STREAM, "\tinfo = 0x%lx, next_reloc = 0x%lx\n", \ 	     (long) FIX->tc_fix_data.info,				\ 	     (long) FIX->tc_fix_data.next_reloc);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_CFIPOP
value|1
end_define

begin_define
define|#
directive|define
name|tc_cfi_frame_initial_instructions
value|alpha_cfi_frame_initial_instructions
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_cfi_frame_initial_instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|26
end_define

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|-8
end_define

end_unit

