begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ECOFF object file format header file.    Copyright 1993, 1994, 1995, 1996, 1997, 1999    Free Software Foundation, Inc.    Contributed by Cygnus Support.    Written by Ian Lance Taylor<ian@cygnus.com>.     This file is part of GAS.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_ECOFF
value|1
end_define

begin_comment
comment|/* Use the generic ECOFF debugging code.  */
end_comment

begin_define
define|#
directive|define
name|ECOFF_DEBUGGING
value|1
end_define

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_ecoff_flavour
end_define

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_include
include|#
directive|include
file|"ecoff.h"
end_include

begin_comment
comment|/* For each gas symbol we keep track of which file it came from, of    whether we have generated an ECOFF symbol for it, and whether the    symbols is undefined (this last is needed to distinguish a .extern    symbols from a .comm symbol).  */
end_comment

begin_struct
struct|struct
name|ecoff_sy_obj
block|{
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|struct ecoff_sy_obj
end_define

begin_comment
comment|/* Modify the ECOFF symbol.  */
end_comment

begin_define
define|#
directive|define
name|obj_frob_symbol
parameter_list|(
name|symp
parameter_list|,
name|punt
parameter_list|)
value|ecoff_frob_symbol (symp)
end_define

begin_comment
comment|/* This is used to write the symbolic data in the format that BFD    expects it.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_frob_file
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
name|obj_frob_file
parameter_list|()
value|ecoff_frob_file ()
end_define

begin_comment
comment|/* We use the ECOFF functions as our hooks.  */
end_comment

begin_define
define|#
directive|define
name|obj_read_begin_hook
value|ecoff_read_begin_hook
end_define

begin_define
define|#
directive|define
name|obj_symbol_new_hook
value|ecoff_symbol_new_hook
end_define

begin_comment
comment|/* Record file switches in the ECOFF symbol table.  */
end_comment

begin_define
define|#
directive|define
name|obj_app_file
parameter_list|(
name|name
parameter_list|)
value|ecoff_new_file (name)
end_define

begin_comment
comment|/* At the moment we don't want to do any stabs processing in read.c.  */
end_comment

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
name|EMIT_SECTION_SYMBOLS
value|0
end_define

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
parameter_list|(
name|SEC
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|obj_ecoff_set_ext
value|ecoff_set_ext
end_define

begin_decl_stmt
specifier|extern
name|void
name|obj_ecoff_set_ext
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|EXTR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

