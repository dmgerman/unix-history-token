begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HP PA-RISC SOM object file format:  definitions internal to BFD.    Copyright (C) 1990-1991 Free Software Foundation, Inc.     Contributed by the Center for Software Science at the    University of Utah (pa-gdb-bugs@cs.utah.edu).  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_struct_decl
struct_decl|struct
name|header
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|som_exec_auxhdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|subspace_dictionary
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|FILE_HDR_SIZE
value|sizeof(struct header)
end_define

begin_define
define|#
directive|define
name|AUX_HDR_SIZE
value|sizeof(struct som_exec_auxhdr)
end_define

begin_decl_stmt
name|int
name|millicode_start
decl_stmt|,
name|millicode_end
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|nlist
block|{
union|union
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
name|struct
name|nlist
modifier|*
name|n_next
decl_stmt|;
name|long
name|n_strx
decl_stmt|;
block|}
name|n_un
union|;
name|unsigned
name|char
name|n_type
decl_stmt|;
name|char
name|n_other
decl_stmt|;
name|short
name|n_desc
decl_stmt|;
name|unsigned
name|long
name|n_value
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|hppa_symbol
block|{
name|asymbol
name|symbol
decl_stmt|;
name|short
name|desc
decl_stmt|;
name|char
name|other
decl_stmt|;
name|unsigned
name|char
name|type
decl_stmt|;
block|}
name|hppa_symbol_type
typedef|;
end_typedef

begin_struct
struct|struct
name|hppadata
block|{
name|struct
name|header
modifier|*
name|file_hdr
decl_stmt|;
name|struct
name|som_exec_auxhdr
modifier|*
name|aux_hdr
decl_stmt|;
name|hppa_symbol_type
modifier|*
name|symbols
decl_stmt|;
comment|/* For ease, we do this */
name|asection
modifier|*
name|textsec
decl_stmt|;
name|asection
modifier|*
name|datasec
decl_stmt|;
name|asection
modifier|*
name|bsssec
decl_stmt|;
comment|/* We remember these offsets so that after check_file_format, we have      no dependencies on the particular format of the exec_hdr.  */
name|file_ptr
name|dbx_sym_filepos
decl_stmt|;
name|file_ptr
name|dbx_str_filepos
decl_stmt|;
name|file_ptr
name|hp_sym_filepos
decl_stmt|;
name|file_ptr
name|hp_str_filepos
decl_stmt|;
name|int
name|dbx_sym_count
decl_stmt|;
name|int
name|hp_sym_count
decl_stmt|;
name|unsigned
name|dbx_stringtab_size
decl_stmt|;
name|unsigned
name|hp_stringtab_size
decl_stmt|;
comment|/* Size of a symbol table entry in external form */
name|unsigned
name|dbx_symbol_entry_size
decl_stmt|;
name|unsigned
name|hp_symbol_entry_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hppa_data_struct
block|{
name|struct
name|hppadata
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|padata
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.hppa_data->a)
end_define

begin_define
define|#
directive|define
name|obj_file_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).file_hdr)
end_define

begin_define
define|#
directive|define
name|obj_aux_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).aux_hdr)
end_define

begin_define
define|#
directive|define
name|obj_pa_symbols
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).symbols)
end_define

begin_define
define|#
directive|define
name|obj_textsec
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).textsec)
end_define

begin_define
define|#
directive|define
name|obj_datasec
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).datasec)
end_define

begin_define
define|#
directive|define
name|obj_bsssec
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).bsssec)
end_define

begin_define
define|#
directive|define
name|obj_dbx_sym_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).dbx_sym_filepos)
end_define

begin_define
define|#
directive|define
name|obj_dbx_str_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).dbx_str_filepos)
end_define

begin_define
define|#
directive|define
name|obj_hp_sym_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).hp_sym_filepos)
end_define

begin_define
define|#
directive|define
name|obj_hp_str_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).hp_str_filepos)
end_define

begin_define
define|#
directive|define
name|obj_dbx_sym_count
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).dbx_sym_count)
end_define

begin_define
define|#
directive|define
name|obj_hp_sym_count
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).hp_sym_count)
end_define

begin_define
define|#
directive|define
name|obj_dbx_stringtab_size
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).dbx_stringtab_size)
end_define

begin_define
define|#
directive|define
name|obj_hp_stringtab_size
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).hp_stringtab_size)
end_define

begin_define
define|#
directive|define
name|obj_dbx_symbol_entry_size
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).dbx_symbol_entry_size)
end_define

begin_define
define|#
directive|define
name|obj_hp_symbol_entry_size
parameter_list|(
name|bfd
parameter_list|)
value|(padata(bfd).hp_symbol_entry_size)
end_define

begin_comment
comment|/* We take the address of the first element of an asymbol to ensure that the    macro is only ever applied to an asymbol */
end_comment

begin_define
define|#
directive|define
name|hppa_symbol
parameter_list|(
name|asymbol
parameter_list|)
value|((hppa_symbol_type *)(&(asymbol)->the_bfd))
end_define

begin_comment
comment|/* These are stored in the bfd's tdata */
end_comment

begin_struct
struct|struct
name|hppa_core_struct
block|{
name|struct
name|hpuxuser
modifier|*
name|upage
decl_stmt|;
name|asection
modifier|*
name|data_section
decl_stmt|;
name|asection
modifier|*
name|stack_section
decl_stmt|;
name|asection
modifier|*
name|reg_section
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|core_upage
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.hppa_core_data->upage)
end_define

begin_define
define|#
directive|define
name|core_datasec
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.hppa_core_data->data_section)
end_define

begin_define
define|#
directive|define
name|core_stacksec
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.hppa_core_data->stack_section)
end_define

begin_define
define|#
directive|define
name|core_regsec
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.hppa_core_data->reg_section)
end_define

end_unit

