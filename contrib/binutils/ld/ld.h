begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ld.h -- general linker header file    Copyright (C) 1991, 93, 94, 95, 96, 1997 Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LD_H
end_ifndef

begin_define
define|#
directive|define
name|LD_H
end_define

begin_comment
comment|/* Look in this environment name for the linker to pretend to be */
end_comment

begin_define
define|#
directive|define
name|EMULATION_ENVIRON
value|"LDEMULATION"
end_define

begin_comment
comment|/* If in there look for the strings: */
end_comment

begin_comment
comment|/* Look in this variable for a target format */
end_comment

begin_define
define|#
directive|define
name|TARGET_ENVIRON
value|"GNUTARGET"
end_define

begin_comment
comment|/* Input sections which are put in a section of this name are actually    discarded.  */
end_comment

begin_define
define|#
directive|define
name|DISCARD_SECTION_NAME
value|"/DISCARD/"
end_define

begin_comment
comment|/* Extra information we hold on sections */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|user_section_struct
block|{
comment|/* Pointer to the section where this data will go */
name|struct
name|lang_input_statement_struct
modifier|*
name|file
decl_stmt|;
block|}
name|section_userdata_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|get_userdata
parameter_list|(
name|x
parameter_list|)
value|((x)->userdata)
end_define

begin_define
define|#
directive|define
name|BYTE_SIZE
value|(1)
end_define

begin_define
define|#
directive|define
name|SHORT_SIZE
value|(2)
end_define

begin_define
define|#
directive|define
name|LONG_SIZE
value|(4)
end_define

begin_define
define|#
directive|define
name|QUAD_SIZE
value|(8)
end_define

begin_comment
comment|/* ALIGN macro changed to ALIGN_N to avoid	*/
end_comment

begin_comment
comment|/* conflict in /usr/include/machine/machparam.h */
end_comment

begin_comment
comment|/* WARNING: If THIS is a 64 bit address and BOUNDARY is a 32 bit int,    you must coerce boundary to the same type as THIS.    ??? Is there a portable way to avoid this.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_N
parameter_list|(
name|this
parameter_list|,
name|boundary
parameter_list|)
define|\
value|((( (this) + ((boundary) -1))& (~((boundary)-1))))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 1 => assign space to common symbols even if `relocatable_output'.  */
name|boolean
name|force_common_definition
decl_stmt|;
name|boolean
name|relax
decl_stmt|;
comment|/* Name of runtime interpreter to invoke.  */
name|char
modifier|*
name|interpreter
decl_stmt|;
comment|/* Name to give runtime libary from the -soname argument.  */
name|char
modifier|*
name|soname
decl_stmt|;
comment|/* Runtime library search path from the -rpath argument.  */
name|char
modifier|*
name|rpath
decl_stmt|;
comment|/* Link time runtime library search path from the -rpath-link      argument.  */
name|char
modifier|*
name|rpath_link
decl_stmt|;
comment|/* Big or little endian as set on command line.  */
enum|enum
block|{
name|ENDIAN_UNSET
init|=
literal|0
block|,
name|ENDIAN_BIG
block|,
name|ENDIAN_LITTLE
block|}
name|endian
enum|;
comment|/* If true, export all symbols in the dynamic symbol table of an ELF      executable.  */
name|boolean
name|export_dynamic
decl_stmt|;
comment|/* If true, build MIPS embedded PIC relocation tables in the output      file.  */
name|boolean
name|embedded_relocs
decl_stmt|;
comment|/* If true, force generation of a file with a .exe file. */
name|boolean
name|force_exe_suffix
decl_stmt|;
comment|/* If true, generate a cross reference report.  */
name|boolean
name|cref
decl_stmt|;
comment|/* Name of shared object whose symbol table should be filtered with      this shared object.  From the --filter option.  */
name|char
modifier|*
name|filter_shlib
decl_stmt|;
comment|/* Name of shared object for whose symbol table this shared object      is an auxiliary filter.  From the --auxiliary option.  */
name|char
modifier|*
modifier|*
name|auxiliary_filters
decl_stmt|;
block|}
name|args_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|args_type
name|command_line
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|token_code_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bfd_size_type
name|specified_data_size
decl_stmt|;
name|boolean
name|magic_demand_paged
decl_stmt|;
name|boolean
name|make_executable
decl_stmt|;
comment|/* If true, doing a dynamic link.  */
name|boolean
name|dynamic_link
decl_stmt|;
comment|/* If true, build constructors.  */
name|boolean
name|build_constructors
decl_stmt|;
comment|/* If true, warn about any constructors.  */
name|boolean
name|warn_constructors
decl_stmt|;
comment|/* If true, warn about merging common symbols with others.  */
name|boolean
name|warn_common
decl_stmt|;
comment|/* If true, only warn once about a particular undefined symbol.  */
name|boolean
name|warn_once
decl_stmt|;
comment|/* If true, warn if multiple global-pointers are needed (Alpha      only).  */
name|boolean
name|warn_multiple_gp
decl_stmt|;
comment|/* If true, warn if the starting address of an output section      changes due to the alignment of an input section.  */
name|boolean
name|warn_section_align
decl_stmt|;
name|boolean
name|sort_common
decl_stmt|;
name|boolean
name|text_read_only
decl_stmt|;
name|char
modifier|*
name|map_filename
decl_stmt|;
name|FILE
modifier|*
name|map_file
decl_stmt|;
name|boolean
name|stats
decl_stmt|;
name|int
name|split_by_reloc
decl_stmt|;
name|boolean
name|split_by_file
decl_stmt|;
block|}
name|ld_config_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ld_config_type
name|config
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|lang_first_phase_enum
block|,
name|lang_allocating_phase_enum
block|,
name|lang_final_phase_enum
block|}
name|lang_phase_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|boolean
name|had_script
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|force_make_executable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if we are processing a --defsym from the command line.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|parsing_defsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyparse
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
name|add_cref
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_cref
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_nocrossrefs
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

