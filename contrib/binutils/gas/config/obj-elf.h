begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF object file format.    Copyright (C) 1992, 93, 94, 95, 96, 1997 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_elf_flavour
end_define

begin_include
include|#
directive|include
file|<bfd.h>
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

begin_comment
comment|/* Additional information we keep for each symbol.  */
end_comment

begin_comment
comment|/* FIXME: For some reason, this structure is needed both here and in    obj-multi.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_SYMFIELD_TYPE
end_ifndef

begin_struct
struct|struct
name|elf_obj_sy
block|{
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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|TARGET_SYMBOL_FIELDS
value|ELF_TARGET_SYMBOL_FIELDS
end_define

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

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

begin_define
define|#
directive|define
name|obj_begin
parameter_list|()
value|elf_begin ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|elf_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|((elf_symbol_type *)(&(asymbol)->the_bfd))
end_define

begin_define
define|#
directive|define
name|S_GET_SIZE
parameter_list|(
name|S
parameter_list|)
value|(elf_symbol ((S)->bsym)->internal_elf_sym.st_size)
end_define

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
value|(elf_symbol((S)->bsym)->internal_elf_sym.st_size = (V))
end_define

begin_define
define|#
directive|define
name|S_GET_ALIGN
parameter_list|(
name|S
parameter_list|)
value|(elf_symbol ((S)->bsym)->internal_elf_sym.st_value)
end_define

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
value|(elf_symbol ((S)->bsym)->internal_elf_sym.st_value = (V))
end_define

begin_define
define|#
directive|define
name|S_GET_OTHER
parameter_list|(
name|S
parameter_list|)
value|(elf_symbol ((S)->bsym)->internal_elf_sym.st_other)
end_define

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
value|(elf_symbol ((S)->bsym)->internal_elf_sym.st_other = (V))
end_define

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|gdb_section
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_frob_file
value|elf_frob_file
end_define

begin_decl_stmt
specifier|extern
name|void
name|elf_frob_file
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
name|obj_frob_file_after_relocs
value|elf_frob_file_after_relocs
end_define

begin_decl_stmt
specifier|extern
name|void
name|elf_frob_file_after_relocs
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
name|obj_app_file
value|elf_file_symbol
end_define

begin_decl_stmt
specifier|extern
name|void
name|elf_file_symbol
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|obj_elf_section_change_hook
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
name|obj_elf_section
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|obj_elf_previous
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|obj_elf_version
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BFD wants to write the udata field, which is a no-no for the    globally defined sections.  */
end_comment

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
parameter_list|(
name|SEC
parameter_list|)
value|((SEC)->owner != 0)
end_define

begin_comment
comment|/* When setting one symbol equal to another, by default we probably    want them to have the same "size", whatever it means in the current    context.  */
end_comment

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
value|do							\   {							\     S_SET_SIZE ((DEST), S_GET_SIZE (SRC));		\     S_SET_OTHER ((DEST), S_GET_OTHER (SRC));		\   }							\ while (0)
end_define

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

begin_decl_stmt
specifier|extern
name|void
name|obj_elf_init_stab_section
name|PARAMS
argument_list|(
operator|(
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_STAB_SECTION
parameter_list|(
name|seg
parameter_list|)
value|obj_elf_init_stab_section (seg)
end_define

begin_comment
comment|/* For now, always set ECOFF_DEBUGGING for an Alpha target.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_ALPHA
end_ifdef

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
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ECOFF_DEBUGGING
end_if

begin_comment
comment|/* If we are generating ECOFF debugging information, we need some    additional fields for each symbol.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SYMBOL_FIELDS
end_undef

begin_define
define|#
directive|define
name|TARGET_SYMBOL_FIELDS
define|\
value|ELF_TARGET_SYMBOL_FIELDS \   struct efdr *ecoff_file; \   struct localsym *ecoff_symbol; \   valueT ecoff_extern_size;
end_define

begin_comment
comment|/* We smuggle stabs in ECOFF rather than using a separate section.    The Irix linker can not handle a separate stabs section.  */
end_comment

begin_undef
undef|#
directive|undef
name|SEPARATE_STAB_SECTIONS
end_undef

begin_undef
undef|#
directive|undef
name|INIT_STAB_SECTION
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
value|ecoff_stab ((seg), (what), (string), (type), (other), (desc))
end_define

begin_define
define|#
directive|define
name|OBJ_GENERATE_ASM_LINENO
parameter_list|(
name|filename
parameter_list|,
name|lineno
parameter_list|)
define|\
value|ecoff_generate_asm_lineno ((filename), (lineno))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECOFF_DEBUGGING */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|elf_frob_symbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|elf_pop_insert
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
name|obj_pop_insert
parameter_list|()
value|elf_pop_insert()
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|ecoff_extr
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|elf_ecoff_set_ext
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
expr|struct
name|ecoff_extr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OBJ_ELF_H */
end_comment

end_unit

