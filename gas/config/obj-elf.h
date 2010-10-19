begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF object file format.    Copyright 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001,    2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* HP PA-RISC support was contributed by the Center for Software Science    at the University of Utah.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OBJ_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|_OBJ_ELF_H
end_define

begin_define
define|#
directive|define
name|OBJ_ELF
value|1
end_define

begin_comment
comment|/* Note that all macros in this file should be wrapped in #ifndef, for    sake of obj-multi.h which includes this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OUTPUT_FLAVOR
end_ifndef

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_elf_flavour
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_comment
comment|/* for now */
end_comment

begin_include
include|#
directive|include
file|"bfd/elf-bfd.h"
end_include

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TC_ALPHA
end_ifdef

begin_define
define|#
directive|define
name|ECOFF_DEBUGGING
value|(alpha_flag_mdebug> 0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|alpha_flag_mdebug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For now, always set ECOFF_DEBUGGING for a MIPS target.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_MIPS
end_ifdef

begin_define
define|#
directive|define
name|ECOFF_DEBUGGING
value|mips_flag_mdebug
end_define

begin_decl_stmt
specifier|extern
name|int
name|mips_flag_mdebug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_MIPS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_MAYBE_ECOFF
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_DEBUGGING
end_ifndef

begin_define
define|#
directive|define
name|ECOFF_DEBUGGING
value|1
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
comment|/* Additional information we keep for each symbol.  */
end_comment

begin_struct
struct|struct
name|elf_obj_sy
block|{
comment|/* Whether the symbol has been marked as local.  */
name|int
name|local
decl_stmt|;
comment|/* Use this to keep track of .size expressions that involve      differences that we can't compute yet.  */
name|expressionS
modifier|*
name|size
decl_stmt|;
comment|/* The name specified by the .symver directive.  */
name|char
modifier|*
name|versioned_name
decl_stmt|;
ifdef|#
directive|ifdef
name|ECOFF_DEBUGGING
comment|/* If we are generating ECOFF debugging information, we need some      additional fields for each symbol.  */
name|struct
name|efdr
modifier|*
name|ecoff_file
decl_stmt|;
name|struct
name|localsym
modifier|*
name|ecoff_symbol
decl_stmt|;
name|valueT
name|ecoff_extern_size
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|struct elf_obj_sy
end_define

begin_comment
comment|/* Symbol fields used by the ELF back end.  */
end_comment

begin_define
define|#
directive|define
name|ELF_TARGET_SYMBOL_FIELDS
value|int local:1;
end_define

begin_comment
comment|/* Don't change this; change ELF_TARGET_SYMBOL_FIELDS instead.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SYMBOL_FIELDS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SYMBOL_FIELDS
value|ELF_TARGET_SYMBOL_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include "targ-cpu.h" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|!FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|obj_begin
end_ifndef

begin_define
define|#
directive|define
name|obj_begin
parameter_list|()
value|elf_begin ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|elf_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* should be conditional on address size! */
end_comment

begin_define
define|#
directive|define
name|elf_symbol
parameter_list|(
name|asymbol
parameter_list|)
value|((elf_symbol_type *) (&(asymbol)->the_bfd))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|S_GET_SIZE
end_ifndef

begin_define
define|#
directive|define
name|S_GET_SIZE
parameter_list|(
name|S
parameter_list|)
define|\
value|(elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_SET_SIZE
end_ifndef

begin_define
define|#
directive|define
name|S_SET_SIZE
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|)
define|\
value|(elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_size = (V))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_GET_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|S_GET_ALIGN
parameter_list|(
name|S
parameter_list|)
define|\
value|(elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_value)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_SET_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|S_SET_ALIGN
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|)
define|\
value|(elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_value = (V))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|elf_s_get_other
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|S_GET_OTHER
end_ifndef

begin_define
define|#
directive|define
name|S_GET_OTHER
parameter_list|(
name|S
parameter_list|)
value|(elf_s_get_other (S))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_SET_OTHER
end_ifndef

begin_define
define|#
directive|define
name|S_SET_OTHER
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|)
define|\
value|(elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_other = (V))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|gdb_section
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|obj_sec_set_private_data
end_ifndef

begin_define
define|#
directive|define
name|obj_sec_set_private_data
parameter_list|(
name|B
parameter_list|,
name|S
parameter_list|)
define|\
value|if (! BFD_SEND ((B), _new_section_hook, ((B), (S)))) \     as_fatal (_("can't allocate ELF private section data: %s"),	\ 	      bfd_errmsg (bfd_get_error ()))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|obj_frob_file
end_ifndef

begin_define
define|#
directive|define
name|obj_frob_file
value|elf_frob_file
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|elf_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_frob_file_before_adjust
end_ifndef

begin_define
define|#
directive|define
name|obj_frob_file_before_adjust
value|elf_frob_file_before_adjust
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|elf_frob_file_before_adjust
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_frob_file_after_relocs
end_ifndef

begin_define
define|#
directive|define
name|obj_frob_file_after_relocs
value|elf_frob_file_after_relocs
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|elf_frob_file_after_relocs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If the target doesn't have special processing for labels, take care of    dwarf2 output at the object file level.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tc_frob_label
end_ifndef

begin_include
include|#
directive|include
file|"dwarf2dbg.h"
end_include

begin_define
define|#
directive|define
name|obj_frob_label
value|dwarf2_emit_label
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|obj_app_file
end_ifndef

begin_define
define|#
directive|define
name|obj_app_file
value|elf_file_symbol
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|elf_file_symbol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_section_change_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_section
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_previous
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_version
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_common
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_data
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_text
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_elf_change_section
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|fix
modifier|*
name|obj_elf_vtable_inherit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|fix
modifier|*
name|obj_elf_vtable_entry
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BFD wants to write the udata field, which is a no-no for the    predefined section symbols in bfd/section.c.  They are read-only.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|obj_sec_sym_ok_for_reloc
end_ifndef

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
parameter_list|(
name|SEC
parameter_list|)
value|((SEC)->owner != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|elf_obj_read_begin_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_read_begin_hook
end_ifndef

begin_define
define|#
directive|define
name|obj_read_begin_hook
value|elf_obj_read_begin_hook
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|elf_obj_symbol_new_hook
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_symbol_new_hook
end_ifndef

begin_define
define|#
directive|define
name|obj_symbol_new_hook
value|elf_obj_symbol_new_hook
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|elf_copy_symbol_attributes
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_COPY_SYMBOL_ATTRIBUTES
end_ifndef

begin_define
define|#
directive|define
name|OBJ_COPY_SYMBOL_ATTRIBUTES
parameter_list|(
name|DEST
parameter_list|,
name|SRC
parameter_list|)
define|\
value|(elf_copy_symbol_attributes (DEST, SRC))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEPARATE_STAB_SECTIONS
end_ifndef

begin_comment
comment|/* Avoid ifndef each separate macro setting by wrapping the whole of the    stab group on the assumption that whoever sets SEPARATE_STAB_SECTIONS    caters to ECOFF_DEBUGGING and the right setting of INIT_STAB_SECTIONS    and OBJ_PROCESS_STAB too, without needing the tweaks below.  */
end_comment

begin_comment
comment|/* Stabs go in a separate section.  */
end_comment

begin_define
define|#
directive|define
name|SEPARATE_STAB_SECTIONS
value|1
end_define

begin_comment
comment|/* We need 12 bytes at the start of the section to hold some initial    information.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|obj_elf_init_stab_section
parameter_list|(
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INIT_STAB_SECTION
parameter_list|(
name|seg
parameter_list|)
value|obj_elf_init_stab_section (seg)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ECOFF_DEBUGGING
end_ifdef

begin_comment
comment|/* We smuggle stabs in ECOFF rather than using a separate section.    The Irix linker can not handle a separate stabs section.  */
end_comment

begin_undef
undef|#
directive|undef
name|SEPARATE_STAB_SECTIONS
end_undef

begin_define
define|#
directive|define
name|SEPARATE_STAB_SECTIONS
value|(!ECOFF_DEBUGGING)
end_define

begin_undef
undef|#
directive|undef
name|INIT_STAB_SECTION
end_undef

begin_define
define|#
directive|define
name|INIT_STAB_SECTION
parameter_list|(
name|seg
parameter_list|)
define|\
value|((void) (ECOFF_DEBUGGING ? 0 : (obj_elf_init_stab_section (seg), 0)))
end_define

begin_undef
undef|#
directive|undef
name|OBJ_PROCESS_STAB
end_undef

begin_define
define|#
directive|define
name|OBJ_PROCESS_STAB
parameter_list|(
name|seg
parameter_list|,
name|what
parameter_list|,
name|string
parameter_list|,
name|type
parameter_list|,
name|other
parameter_list|,
name|desc
parameter_list|)
define|\
value|if (ECOFF_DEBUGGING)							\     ecoff_stab ((seg), (what), (string), (type), (other), (desc))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECOFF_DEBUGGING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SEPARATE_STAB_SECTIONS not defined.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|elf_frob_symbol
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_frob_symbol
end_ifndef

begin_define
define|#
directive|define
name|obj_frob_symbol
parameter_list|(
name|symp
parameter_list|,
name|punt
parameter_list|)
value|elf_frob_symbol (symp,&punt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|elf_pop_insert
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_pop_insert
end_ifndef

begin_define
define|#
directive|define
name|obj_pop_insert
parameter_list|()
value|elf_pop_insert()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_MAYBE_ELF
end_ifndef

begin_define
define|#
directive|define
name|obj_ecoff_set_ext
value|elf_ecoff_set_ext
end_define

begin_struct_decl
struct_decl|struct
name|ecoff_extr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|elf_ecoff_set_ext
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|struct
name|ecoff_extr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|elf_com_section_ptr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|elf_common_parse
parameter_list|(
name|int
name|ignore
name|ATTRIBUTE_UNUSED
parameter_list|,
name|symbolS
modifier|*
name|symbolP
parameter_list|,
name|addressT
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OBJ_ELF_H */
end_comment

end_unit

