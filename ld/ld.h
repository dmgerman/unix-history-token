begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ld.h -- general linker header file    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|C_ALLOCA
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|C_ALLOCA
argument_list|)
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_comment
comment|/* predefined by HP cc +Olibcalls */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__, __hpux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* alloca */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ENABLE_NLS
end_ifndef

begin_comment
comment|/* The Solaris version of locale.h always includes libintl.h.  If we have       been configured with --disable-nls then ENABLE_NLS will not be defined       and the dummy definitions of bindtextdomain (et al) below will conflict       with the defintions in libintl.h.  So we define these values to prevent       the bogus inclusion of libintl.h.  */
end_comment

begin_define
define|#
directive|define
name|_LIBINTL_H
end_define

begin_define
define|#
directive|define
name|_LIBGETTEXT_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gettext_noop
end_ifdef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|gettext_noop (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|,
name|Category
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bin-bugs.h"
end_include

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
comment|/* A file name list */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|name_list
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|name_list
modifier|*
name|next
decl_stmt|;
block|}
name|name_list
typedef|;
end_typedef

begin_comment
comment|/* A wildcard specification.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|none
block|,
name|by_name
block|,
name|by_alignment
block|,
name|by_name_alignment
block|,
name|by_alignment_name
block|}
name|sort_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|sort_type
name|sort_section
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|wildcard_spec
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|name_list
modifier|*
name|exclude_name_list
decl_stmt|;
name|sort_type
name|sorted
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wildcard_list
block|{
name|struct
name|wildcard_list
modifier|*
name|next
decl_stmt|;
name|struct
name|wildcard_spec
name|spec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|map_symbol_def
block|{
name|struct
name|bfd_link_hash_entry
modifier|*
name|entry
decl_stmt|;
name|struct
name|map_symbol_def
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The initial part of fat_user_section_struct has to be idential with    lean_user_section_struct.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fat_user_section_struct
block|{
comment|/* For input sections, when writing a map file: head / tail of a linked      list of hash table entries for symbols defined in this section.  */
name|struct
name|map_symbol_def
modifier|*
name|map_symbol_def_head
decl_stmt|;
name|struct
name|map_symbol_def
modifier|*
modifier|*
name|map_symbol_def_tail
decl_stmt|;
block|}
name|fat_section_userdata_type
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

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 1 => assign space to common symbols even if `relocatable_output'.  */
name|bfd_boolean
name|force_common_definition
decl_stmt|;
comment|/* 1 => do not assign addresses to common symbols.  */
name|bfd_boolean
name|inhibit_common_definition
decl_stmt|;
name|bfd_boolean
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
comment|/* If TRUE, build MIPS embedded PIC relocation tables in the output      file.  */
name|bfd_boolean
name|embedded_relocs
decl_stmt|;
comment|/* If TRUE, force generation of a file with a .exe file.  */
name|bfd_boolean
name|force_exe_suffix
decl_stmt|;
comment|/* If TRUE, generate a cross reference report.  */
name|bfd_boolean
name|cref
decl_stmt|;
comment|/* If TRUE (which is the default), warn about mismatched input      files.  */
name|bfd_boolean
name|warn_mismatch
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
comment|/* A version symbol to be applied to the symbol names found in the      .exports sections.  */
name|char
modifier|*
name|version_exports_section
decl_stmt|;
comment|/* If TRUE (the default) check section addresses, once compute,      fpor overlaps.  */
name|bfd_boolean
name|check_section_addresses
decl_stmt|;
comment|/* If TRUE allow the linking of input files in an unknown architecture      assuming that the user knows what they are doing.  This was the old      behaviour of the linker.  The new default behaviour is to reject such      input files.  */
name|bfd_boolean
name|accept_unknown_input_arch
decl_stmt|;
comment|/* If TRUE reduce memory overheads, at the expense of speed.      This will cause map file generation to use an O(N^2) algorithm.  */
name|bfd_boolean
name|reduce_memory_overheads
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
name|bfd_boolean
name|magic_demand_paged
decl_stmt|;
name|bfd_boolean
name|make_executable
decl_stmt|;
comment|/* If TRUE, doing a dynamic link.  */
name|bfd_boolean
name|dynamic_link
decl_stmt|;
comment|/* If TRUE, -shared is supported.  */
comment|/* ??? A better way to do this is perhaps to define this in the      ld_emulation_xfer_struct since this is really a target dependent      parameter.  */
name|bfd_boolean
name|has_shared
decl_stmt|;
comment|/* If TRUE, build constructors.  */
name|bfd_boolean
name|build_constructors
decl_stmt|;
comment|/* If TRUE, warn about any constructors.  */
name|bfd_boolean
name|warn_constructors
decl_stmt|;
comment|/* If TRUE, warn about merging common symbols with others.  */
name|bfd_boolean
name|warn_common
decl_stmt|;
comment|/* If TRUE, only warn once about a particular undefined symbol.  */
name|bfd_boolean
name|warn_once
decl_stmt|;
comment|/* If TRUE, warn if multiple global-pointers are needed (Alpha      only).  */
name|bfd_boolean
name|warn_multiple_gp
decl_stmt|;
comment|/* If TRUE, warn if the starting address of an output section      changes due to the alignment of an input section.  */
name|bfd_boolean
name|warn_section_align
decl_stmt|;
comment|/* If TRUE, warning messages are fatal */
name|bfd_boolean
name|fatal_warnings
decl_stmt|;
name|bfd_boolean
name|sort_common
decl_stmt|;
name|bfd_boolean
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
name|bfd_boolean
name|stats
decl_stmt|;
comment|/* If set, orphan input sections will be mapped to separate output      sections.  */
name|bfd_boolean
name|unique_orphan_sections
decl_stmt|;
name|unsigned
name|int
name|split_by_reloc
decl_stmt|;
name|bfd_size_type
name|split_by_file
decl_stmt|;
comment|/* If set, only search library directories explicitly selected      on the command line.  */
name|bfd_boolean
name|only_cmd_line_lib_dirs
decl_stmt|;
comment|/* The size of the hash table to use.  */
name|bfd_size_type
name|hash_table_size
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

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|saved_script_handle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
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

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_cref
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|handle_asneeded_cref
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|enum
name|notice_asneeded_action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_cref
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_nocrossrefs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|ld_abort
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If gcc>= 2.6, we can give a function name, too.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|6
operator|)
end_if

begin_define
define|#
directive|define
name|__PRETTY_FUNCTION__
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|ld_abort (__FILE__, __LINE__, __PRETTY_FUNCTION__)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

