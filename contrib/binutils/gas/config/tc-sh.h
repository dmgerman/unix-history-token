begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-sh.h    Copyright (C) 1993, 94, 95, 96, 1997 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_SH
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
value|bfd_arch_sh
end_define

begin_comment
comment|/* Whether in little endian mode.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|shl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether -relax was used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sh_relax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't try to break words.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* When relaxing, we need to generate relocations for alignment    directives.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|frag
parameter_list|)
value|sh_handle_align (frag)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sh_handle_align
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We need to force out some relocations when relaxing.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fix
parameter_list|)
value|sh_force_relocation (fix)
end_define

begin_function_decl
specifier|extern
name|int
name|sh_force_relocation
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|(shl ? "Hitachi Super-H GAS Little Endian" : "Hitachi Super-H GAS Big Endian")
end_define

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

begin_comment
comment|/* We use a special alignment function to insert the correct nop    pattern.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sh_do_align
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
name|l
parameter_list|)
value|if (sh_do_align (n,fill,len,max)) goto l
end_define

begin_comment
comment|/* We record, for each section, whether we have most recently output a    CODE reloc or a DATA reloc.  */
end_comment

begin_struct
struct|struct
name|sh_segment_info_type
block|{
name|int
name|in_code
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|struct sh_segment_info_type
end_define

begin_comment
comment|/* We call a routine to emit a reloc for a label, so that the linker    can align loads and stores without crossing a label.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sh_frob_label
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
value|sh_frob_label ()
end_define

begin_comment
comment|/* We call a routine to flush pending output in order to output a DATA    reloc when required.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sh_flush_pending_output
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
name|md_flush_pending_output
parameter_list|()
value|sh_flush_pending_output ()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|tc_frob_file_before_adjust
value|sh_frob_file
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tc_frob_file
value|sh_frob_file
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|sh_frob_file
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
name|OBJ_COFF
end_ifdef

begin_comment
comment|/* COFF specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_comment
comment|/* This macro translates between an internal fix and an coff reloc type */
end_comment

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fix
parameter_list|)
value|((fix)->fx_r_type)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|TARGET_ARCH
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|(shl ? SH_ARCH_MAGIC_LITTLE : SH_ARCH_MAGIC_BIG)
end_define

begin_comment
comment|/* We need to write out relocs which have not been completed.  */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|fix
parameter_list|)
value|((fix)->fx_addsy != NULL)
end_define

begin_define
define|#
directive|define
name|TC_RELOC_MANGLE
parameter_list|(
name|seg
parameter_list|,
name|fix
parameter_list|,
name|int
parameter_list|,
name|paddr
parameter_list|)
define|\
value|sh_coff_reloc_mangle ((seg), (fix), (int), (paddr))
end_define

begin_function_decl
specifier|extern
name|void
name|sh_coff_reloc_mangle
parameter_list|()
function_decl|;
end_function_decl

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

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|TC_KEEP_FX_OFFSET
value|1
end_define

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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We align most sections to a 16 byte boundary.  */
end_comment

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|)
define|\
value|(strncmp (obj_segment_name (SEG), ".stabstr", 8) == 0		\    ? 0								\    : ((strncmp (obj_segment_name (SEG), ".stab", 5) == 0	\        || strcmp (obj_segment_name (SEG), ".ctors") == 0	\        || strcmp (obj_segment_name (SEG), ".dtors") == 0)	\       ? 2							\       : 4))
end_define

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

begin_comment
comment|/* ELF specific definitions.  */
end_comment

begin_comment
comment|/* Whether or not the target is big endian */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(shl ? "elf32-shl" : "elf32-sh")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_ELF */
end_comment

begin_comment
comment|/* end of tc-sh.h */
end_comment

end_unit

