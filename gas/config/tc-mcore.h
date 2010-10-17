begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-mcore.h     Copyright 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_MCORE
end_ifndef

begin_define
define|#
directive|define
name|TC_MCORE
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|MCORE support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_mcore
end_define

begin_comment
comment|/* Used to initialise target_big_endian.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Don't write out relocs for pcrel stuff.  */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(((x)->fx_addsy || (x)->fx_subsy)&& \ 			   (x)->fx_r_type< BFD_RELOC_MCORE_PCREL_IMM8BY4)
end_define

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|TC_RELOC_MANGLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tc_reloc_mangle (a, b, c)
end_define

begin_comment
comment|/* Some pseudo-op semantic extensions.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_LCOMM_OPTIONAL_ALIGN
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"M.CORE GAS Version 2.9.4"
end_define

begin_define
define|#
directive|define
name|LISTING_LHS_CONT_LINES
value|4
end_define

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|COFF_FLAGS
value|1
end_define

begin_comment
comment|/* We want local label support.  */
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
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep (frag)
end_define

begin_decl_stmt
name|int
name|tc_coff_sizemachdep
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
name|md_end
value|md_mcore_end
end_define

begin_comment
comment|/* Want the section information too...  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "pe-mcore-big" : "pe-mcore-little")
end_define

begin_struct
struct|struct
name|mcore_tc_sy
block|{
name|int
name|sy_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|struct mcore_tc_sy
end_define

begin_if
if|#
directive|if
name|defined
name|TE_PE
end_if

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)->fx_r_type == BFD_RELOC_RVA || generic_force_reloc (x))
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
comment|/* OBJ_COFF */
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
value|(target_big_endian ? "elf32-mcore-big" : "elf32-mcore-little")
end_define

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

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
value|mcore_force_relocation (fix)
end_define

begin_decl_stmt
specifier|extern
name|int
name|mcore_force_relocation
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
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|mcore_fix_adjustable (FIX)
end_define

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|mcore_fix_adjustable
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_ELF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_error
error|#
directive|error
error|No target format specified.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"write.h"
end_include

begin_comment
comment|/* For definition of fixS */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|md_mcore_end
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
name|long
name|md_pcrel_from_section
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|arelent
modifier|*
name|tc_gen_reloc
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|fixS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_MCORE */
end_comment

end_unit

