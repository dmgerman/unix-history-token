begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for code generation pass of GNU compiler.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_LIBFUNCS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_LIBFUNCS_H
end_define

begin_comment
comment|/* Enumeration of indexes into libfunc_table.  */
end_comment

begin_enum
enum|enum
name|libfunc_index
block|{
name|LTI_extendsfdf2
block|,
name|LTI_extendsfxf2
block|,
name|LTI_extendsftf2
block|,
name|LTI_extenddfxf2
block|,
name|LTI_extenddftf2
block|,
name|LTI_truncdfsf2
block|,
name|LTI_truncxfsf2
block|,
name|LTI_trunctfsf2
block|,
name|LTI_truncxfdf2
block|,
name|LTI_trunctfdf2
block|,
name|LTI_memcpy
block|,
name|LTI_memmove
block|,
name|LTI_bcopy
block|,
name|LTI_memcmp
block|,
name|LTI_bcmp
block|,
name|LTI_memset
block|,
name|LTI_bzero
block|,
name|LTI_unwind_resume
block|,
name|LTI_eh_personality
block|,
name|LTI_setjmp
block|,
name|LTI_longjmp
block|,
name|LTI_unwind_sjlj_register
block|,
name|LTI_unwind_sjlj_unregister
block|,
name|LTI_eqhf2
block|,
name|LTI_nehf2
block|,
name|LTI_gthf2
block|,
name|LTI_gehf2
block|,
name|LTI_lthf2
block|,
name|LTI_lehf2
block|,
name|LTI_unordhf2
block|,
name|LTI_eqsf2
block|,
name|LTI_nesf2
block|,
name|LTI_gtsf2
block|,
name|LTI_gesf2
block|,
name|LTI_ltsf2
block|,
name|LTI_lesf2
block|,
name|LTI_unordsf2
block|,
name|LTI_eqdf2
block|,
name|LTI_nedf2
block|,
name|LTI_gtdf2
block|,
name|LTI_gedf2
block|,
name|LTI_ltdf2
block|,
name|LTI_ledf2
block|,
name|LTI_unorddf2
block|,
name|LTI_eqxf2
block|,
name|LTI_nexf2
block|,
name|LTI_gtxf2
block|,
name|LTI_gexf2
block|,
name|LTI_ltxf2
block|,
name|LTI_lexf2
block|,
name|LTI_unordxf2
block|,
name|LTI_eqtf2
block|,
name|LTI_netf2
block|,
name|LTI_gttf2
block|,
name|LTI_getf2
block|,
name|LTI_lttf2
block|,
name|LTI_letf2
block|,
name|LTI_unordtf2
block|,
name|LTI_floatsisf
block|,
name|LTI_floatdisf
block|,
name|LTI_floattisf
block|,
name|LTI_floatsidf
block|,
name|LTI_floatdidf
block|,
name|LTI_floattidf
block|,
name|LTI_floatsixf
block|,
name|LTI_floatdixf
block|,
name|LTI_floattixf
block|,
name|LTI_floatsitf
block|,
name|LTI_floatditf
block|,
name|LTI_floattitf
block|,
name|LTI_fixsfsi
block|,
name|LTI_fixsfdi
block|,
name|LTI_fixsfti
block|,
name|LTI_fixdfsi
block|,
name|LTI_fixdfdi
block|,
name|LTI_fixdfti
block|,
name|LTI_fixxfsi
block|,
name|LTI_fixxfdi
block|,
name|LTI_fixxfti
block|,
name|LTI_fixtfsi
block|,
name|LTI_fixtfdi
block|,
name|LTI_fixtfti
block|,
name|LTI_fixunssfsi
block|,
name|LTI_fixunssfdi
block|,
name|LTI_fixunssfti
block|,
name|LTI_fixunsdfsi
block|,
name|LTI_fixunsdfdi
block|,
name|LTI_fixunsdfti
block|,
name|LTI_fixunsxfsi
block|,
name|LTI_fixunsxfdi
block|,
name|LTI_fixunsxfti
block|,
name|LTI_fixunstfsi
block|,
name|LTI_fixunstfdi
block|,
name|LTI_fixunstfti
block|,
name|LTI_profile_function_entry
block|,
name|LTI_profile_function_exit
block|,
name|LTI_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* SYMBOL_REF rtx's for the library functions that are called    implicitly and not via optabs.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|libfunc_table
index|[
name|LTI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accessor macros for libfunc_table.  */
end_comment

begin_define
define|#
directive|define
name|extendsfdf2_libfunc
value|(libfunc_table[LTI_extendsfdf2])
end_define

begin_define
define|#
directive|define
name|extendsfxf2_libfunc
value|(libfunc_table[LTI_extendsfxf2])
end_define

begin_define
define|#
directive|define
name|extendsftf2_libfunc
value|(libfunc_table[LTI_extendsftf2])
end_define

begin_define
define|#
directive|define
name|extenddfxf2_libfunc
value|(libfunc_table[LTI_extenddfxf2])
end_define

begin_define
define|#
directive|define
name|extenddftf2_libfunc
value|(libfunc_table[LTI_extenddftf2])
end_define

begin_define
define|#
directive|define
name|truncdfsf2_libfunc
value|(libfunc_table[LTI_truncdfsf2])
end_define

begin_define
define|#
directive|define
name|truncxfsf2_libfunc
value|(libfunc_table[LTI_truncxfsf2])
end_define

begin_define
define|#
directive|define
name|trunctfsf2_libfunc
value|(libfunc_table[LTI_trunctfsf2])
end_define

begin_define
define|#
directive|define
name|truncxfdf2_libfunc
value|(libfunc_table[LTI_truncxfdf2])
end_define

begin_define
define|#
directive|define
name|trunctfdf2_libfunc
value|(libfunc_table[LTI_trunctfdf2])
end_define

begin_define
define|#
directive|define
name|memcpy_libfunc
value|(libfunc_table[LTI_memcpy])
end_define

begin_define
define|#
directive|define
name|memmove_libfunc
value|(libfunc_table[LTI_memmove])
end_define

begin_define
define|#
directive|define
name|bcopy_libfunc
value|(libfunc_table[LTI_bcopy])
end_define

begin_define
define|#
directive|define
name|memcmp_libfunc
value|(libfunc_table[LTI_memcmp])
end_define

begin_define
define|#
directive|define
name|bcmp_libfunc
value|(libfunc_table[LTI_bcmp])
end_define

begin_define
define|#
directive|define
name|memset_libfunc
value|(libfunc_table[LTI_memset])
end_define

begin_define
define|#
directive|define
name|bzero_libfunc
value|(libfunc_table[LTI_bzero])
end_define

begin_define
define|#
directive|define
name|unwind_resume_libfunc
value|(libfunc_table[LTI_unwind_resume])
end_define

begin_define
define|#
directive|define
name|eh_personality_libfunc
value|(libfunc_table[LTI_eh_personality])
end_define

begin_define
define|#
directive|define
name|setjmp_libfunc
value|(libfunc_table[LTI_setjmp])
end_define

begin_define
define|#
directive|define
name|longjmp_libfunc
value|(libfunc_table[LTI_longjmp])
end_define

begin_define
define|#
directive|define
name|unwind_sjlj_register_libfunc
value|(libfunc_table[LTI_unwind_sjlj_register])
end_define

begin_define
define|#
directive|define
name|unwind_sjlj_unregister_libfunc
define|\
value|(libfunc_table[LTI_unwind_sjlj_unregister])
end_define

begin_define
define|#
directive|define
name|eqhf2_libfunc
value|(libfunc_table[LTI_eqhf2])
end_define

begin_define
define|#
directive|define
name|nehf2_libfunc
value|(libfunc_table[LTI_nehf2])
end_define

begin_define
define|#
directive|define
name|gthf2_libfunc
value|(libfunc_table[LTI_gthf2])
end_define

begin_define
define|#
directive|define
name|gehf2_libfunc
value|(libfunc_table[LTI_gehf2])
end_define

begin_define
define|#
directive|define
name|lthf2_libfunc
value|(libfunc_table[LTI_lthf2])
end_define

begin_define
define|#
directive|define
name|lehf2_libfunc
value|(libfunc_table[LTI_lehf2])
end_define

begin_define
define|#
directive|define
name|unordhf2_libfunc
value|(libfunc_table[LTI_unordhf2])
end_define

begin_define
define|#
directive|define
name|eqsf2_libfunc
value|(libfunc_table[LTI_eqsf2])
end_define

begin_define
define|#
directive|define
name|nesf2_libfunc
value|(libfunc_table[LTI_nesf2])
end_define

begin_define
define|#
directive|define
name|gtsf2_libfunc
value|(libfunc_table[LTI_gtsf2])
end_define

begin_define
define|#
directive|define
name|gesf2_libfunc
value|(libfunc_table[LTI_gesf2])
end_define

begin_define
define|#
directive|define
name|ltsf2_libfunc
value|(libfunc_table[LTI_ltsf2])
end_define

begin_define
define|#
directive|define
name|lesf2_libfunc
value|(libfunc_table[LTI_lesf2])
end_define

begin_define
define|#
directive|define
name|unordsf2_libfunc
value|(libfunc_table[LTI_unordsf2])
end_define

begin_define
define|#
directive|define
name|eqdf2_libfunc
value|(libfunc_table[LTI_eqdf2])
end_define

begin_define
define|#
directive|define
name|nedf2_libfunc
value|(libfunc_table[LTI_nedf2])
end_define

begin_define
define|#
directive|define
name|gtdf2_libfunc
value|(libfunc_table[LTI_gtdf2])
end_define

begin_define
define|#
directive|define
name|gedf2_libfunc
value|(libfunc_table[LTI_gedf2])
end_define

begin_define
define|#
directive|define
name|ltdf2_libfunc
value|(libfunc_table[LTI_ltdf2])
end_define

begin_define
define|#
directive|define
name|ledf2_libfunc
value|(libfunc_table[LTI_ledf2])
end_define

begin_define
define|#
directive|define
name|unorddf2_libfunc
value|(libfunc_table[LTI_unorddf2])
end_define

begin_define
define|#
directive|define
name|eqxf2_libfunc
value|(libfunc_table[LTI_eqxf2])
end_define

begin_define
define|#
directive|define
name|nexf2_libfunc
value|(libfunc_table[LTI_nexf2])
end_define

begin_define
define|#
directive|define
name|gtxf2_libfunc
value|(libfunc_table[LTI_gtxf2])
end_define

begin_define
define|#
directive|define
name|gexf2_libfunc
value|(libfunc_table[LTI_gexf2])
end_define

begin_define
define|#
directive|define
name|ltxf2_libfunc
value|(libfunc_table[LTI_ltxf2])
end_define

begin_define
define|#
directive|define
name|lexf2_libfunc
value|(libfunc_table[LTI_lexf2])
end_define

begin_define
define|#
directive|define
name|unordxf2_libfunc
value|(libfunc_table[LTI_unordxf2])
end_define

begin_define
define|#
directive|define
name|eqtf2_libfunc
value|(libfunc_table[LTI_eqtf2])
end_define

begin_define
define|#
directive|define
name|netf2_libfunc
value|(libfunc_table[LTI_netf2])
end_define

begin_define
define|#
directive|define
name|gttf2_libfunc
value|(libfunc_table[LTI_gttf2])
end_define

begin_define
define|#
directive|define
name|getf2_libfunc
value|(libfunc_table[LTI_getf2])
end_define

begin_define
define|#
directive|define
name|lttf2_libfunc
value|(libfunc_table[LTI_lttf2])
end_define

begin_define
define|#
directive|define
name|letf2_libfunc
value|(libfunc_table[LTI_letf2])
end_define

begin_define
define|#
directive|define
name|unordtf2_libfunc
value|(libfunc_table[LTI_unordtf2])
end_define

begin_define
define|#
directive|define
name|floatsisf_libfunc
value|(libfunc_table[LTI_floatsisf])
end_define

begin_define
define|#
directive|define
name|floatdisf_libfunc
value|(libfunc_table[LTI_floatdisf])
end_define

begin_define
define|#
directive|define
name|floattisf_libfunc
value|(libfunc_table[LTI_floattisf])
end_define

begin_define
define|#
directive|define
name|floatsidf_libfunc
value|(libfunc_table[LTI_floatsidf])
end_define

begin_define
define|#
directive|define
name|floatdidf_libfunc
value|(libfunc_table[LTI_floatdidf])
end_define

begin_define
define|#
directive|define
name|floattidf_libfunc
value|(libfunc_table[LTI_floattidf])
end_define

begin_define
define|#
directive|define
name|floatsixf_libfunc
value|(libfunc_table[LTI_floatsixf])
end_define

begin_define
define|#
directive|define
name|floatdixf_libfunc
value|(libfunc_table[LTI_floatdixf])
end_define

begin_define
define|#
directive|define
name|floattixf_libfunc
value|(libfunc_table[LTI_floattixf])
end_define

begin_define
define|#
directive|define
name|floatsitf_libfunc
value|(libfunc_table[LTI_floatsitf])
end_define

begin_define
define|#
directive|define
name|floatditf_libfunc
value|(libfunc_table[LTI_floatditf])
end_define

begin_define
define|#
directive|define
name|floattitf_libfunc
value|(libfunc_table[LTI_floattitf])
end_define

begin_define
define|#
directive|define
name|fixsfsi_libfunc
value|(libfunc_table[LTI_fixsfsi])
end_define

begin_define
define|#
directive|define
name|fixsfdi_libfunc
value|(libfunc_table[LTI_fixsfdi])
end_define

begin_define
define|#
directive|define
name|fixsfti_libfunc
value|(libfunc_table[LTI_fixsfti])
end_define

begin_define
define|#
directive|define
name|fixdfsi_libfunc
value|(libfunc_table[LTI_fixdfsi])
end_define

begin_define
define|#
directive|define
name|fixdfdi_libfunc
value|(libfunc_table[LTI_fixdfdi])
end_define

begin_define
define|#
directive|define
name|fixdfti_libfunc
value|(libfunc_table[LTI_fixdfti])
end_define

begin_define
define|#
directive|define
name|fixxfsi_libfunc
value|(libfunc_table[LTI_fixxfsi])
end_define

begin_define
define|#
directive|define
name|fixxfdi_libfunc
value|(libfunc_table[LTI_fixxfdi])
end_define

begin_define
define|#
directive|define
name|fixxfti_libfunc
value|(libfunc_table[LTI_fixxfti])
end_define

begin_define
define|#
directive|define
name|fixtfsi_libfunc
value|(libfunc_table[LTI_fixtfsi])
end_define

begin_define
define|#
directive|define
name|fixtfdi_libfunc
value|(libfunc_table[LTI_fixtfdi])
end_define

begin_define
define|#
directive|define
name|fixtfti_libfunc
value|(libfunc_table[LTI_fixtfti])
end_define

begin_define
define|#
directive|define
name|fixunssfsi_libfunc
value|(libfunc_table[LTI_fixunssfsi])
end_define

begin_define
define|#
directive|define
name|fixunssfdi_libfunc
value|(libfunc_table[LTI_fixunssfdi])
end_define

begin_define
define|#
directive|define
name|fixunssfti_libfunc
value|(libfunc_table[LTI_fixunssfti])
end_define

begin_define
define|#
directive|define
name|fixunsdfsi_libfunc
value|(libfunc_table[LTI_fixunsdfsi])
end_define

begin_define
define|#
directive|define
name|fixunsdfdi_libfunc
value|(libfunc_table[LTI_fixunsdfdi])
end_define

begin_define
define|#
directive|define
name|fixunsdfti_libfunc
value|(libfunc_table[LTI_fixunsdfti])
end_define

begin_define
define|#
directive|define
name|fixunsxfsi_libfunc
value|(libfunc_table[LTI_fixunsxfsi])
end_define

begin_define
define|#
directive|define
name|fixunsxfdi_libfunc
value|(libfunc_table[LTI_fixunsxfdi])
end_define

begin_define
define|#
directive|define
name|fixunsxfti_libfunc
value|(libfunc_table[LTI_fixunsxfti])
end_define

begin_define
define|#
directive|define
name|fixunstfsi_libfunc
value|(libfunc_table[LTI_fixunstfsi])
end_define

begin_define
define|#
directive|define
name|fixunstfdi_libfunc
value|(libfunc_table[LTI_fixunstfdi])
end_define

begin_define
define|#
directive|define
name|fixunstfti_libfunc
value|(libfunc_table[LTI_fixunstfti])
end_define

begin_define
define|#
directive|define
name|profile_function_entry_libfunc
value|(libfunc_table[LTI_profile_function_entry])
end_define

begin_define
define|#
directive|define
name|profile_function_exit_libfunc
value|(libfunc_table[LTI_profile_function_exit])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_LIBFUNCS_H */
end_comment

end_unit

