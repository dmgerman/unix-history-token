begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-alpha.h    Copyright (C) 1994, 1995, 1996, 1997 Free Software Foundation, Inc.    Written by Ken Raeburn<raeburn@cygnus.com>.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
name|TARGET_ARCH
value|bfd_arch_alpha
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(OUTPUT_FLAVOR == bfd_target_ecoff_flavour	\ 		       ? "ecoff-littlealpha"				\ 		       : OUTPUT_FLAVOR == bfd_target_elf_flavour	\ 		       ? "elf64-alpha"					\ 		       : OUTPUT_FLAVOR == bfd_target_evax_flavour	\ 		       ? "evax-alpha"					\ 		       : "unknown-format")
end_define

begin_define
define|#
directive|define
name|NEED_LITERAL_POOL
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_define
define|#
directive|define
name|REPEAT_CONS_EXPRESSIONS
end_define

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
name|FIXP
parameter_list|)
value|alpha_force_relocation (FIXP)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIXP
parameter_list|)
value|alpha_fix_adjustable (FIXP)
end_define

begin_define
define|#
directive|define
name|RELOC_REQUIRES_SYMBOL
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
value|as_fatal("alpha_create_long_jump")
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
value|as_fatal("alpha_create_short_jump")
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
value|(as_fatal("estimate_size_before_relax called"),1)
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
expr|struct
name|symbol
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

end_unit

