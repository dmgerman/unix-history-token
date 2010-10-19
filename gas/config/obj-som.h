begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SOM object file format.    Copyright 1993, 1994, 1995, 1998, 2000, 2004, 2005    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.     Written by the Center for Software Science at the University of Utah    and by Cygnus Support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OBJ_SOM_H
end_ifndef

begin_define
define|#
directive|define
name|_OBJ_SOM_H
end_define

begin_define
define|#
directive|define
name|OBJ_SOM
value|1
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"bfd/som.h"
end_include

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

begin_comment
comment|/* should be conditional on address size!  */
end_comment

begin_define
define|#
directive|define
name|som_symbol
parameter_list|(
name|asymbol
parameter_list|)
value|((som_symbol_type *) (&(asymbol)->the_bfd))
end_define

begin_function_decl
specifier|extern
name|void
name|som_file_symbol
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|som_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_som_version
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_som_init_stab_section
parameter_list|(
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_som_copyright
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_som_compiler
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|obj_symbol_new_hook
parameter_list|(
name|s
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* SOM has several attributes for spaces/subspaces which can not    be easily expressed in BFD.  We use these macros to trigger calls    into the SOM BFD backend to set these attributes.  */
end_comment

begin_define
define|#
directive|define
name|obj_set_section_attributes
value|bfd_som_set_section_attributes
end_define

begin_define
define|#
directive|define
name|obj_set_subsection_attributes
value|bfd_som_set_subsection_attributes
end_define

begin_comment
comment|/* Likewise for symbol types.  */
end_comment

begin_define
define|#
directive|define
name|obj_set_symbol_type
value|bfd_som_set_symbol_type
end_define

begin_comment
comment|/* Stabs go in a separate sections.  GDB expects to find them in sections    with the names $GDB_SYMBOLS$ and $GDB_STRINGS$ rather than .stab and    .stabstr.  */
end_comment

begin_define
define|#
directive|define
name|SEPARATE_STAB_SECTIONS
value|1
end_define

begin_define
define|#
directive|define
name|STAB_SECTION_NAME
value|"$GDB_SYMBOLS$"
end_define

begin_define
define|#
directive|define
name|STAB_STRING_SECTION_NAME
value|"$GDB_STRINGS$"
end_define

begin_comment
comment|/* We use INIT_STAB_SECTION to record the space/subspace relationships    for the various debugging sections.  */
end_comment

begin_define
define|#
directive|define
name|INIT_STAB_SECTION
parameter_list|(
name|seg
parameter_list|)
value|obj_som_init_stab_section (seg)
end_define

begin_comment
comment|/* We'll be updating the magic 1st stab entry once the entire assembly    fail has been processed.  */
end_comment

begin_define
define|#
directive|define
name|obj_frob_file
parameter_list|()
value|som_frob_file()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OBJ_SOM_H */
end_comment

end_unit

