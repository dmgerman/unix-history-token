begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD COFF object file private structure.    Copyright (C) 1990-1991 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Object file tdata; access macros */
end_comment

begin_define
define|#
directive|define
name|coff_data
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.coff_obj_data)
end_define

begin_define
define|#
directive|define
name|exec_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->hdr)
end_define

begin_define
define|#
directive|define
name|obj_symbols
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->symbols)
end_define

begin_define
define|#
directive|define
name|obj_sym_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->sym_filepos)
end_define

begin_define
define|#
directive|define
name|obj_relocbase
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->relocbase)
end_define

begin_define
define|#
directive|define
name|obj_raw_syments
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->raw_syments)
end_define

begin_define
define|#
directive|define
name|obj_convert
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->conversion_table)
end_define

begin_define
define|#
directive|define
name|obj_conv_table_size
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->conv_table_size)
end_define

begin_if
if|#
directive|if
name|CFILE_STUFF
end_if

begin_define
define|#
directive|define
name|obj_symbol_slew
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data(bfd)->symbol_index_slew)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|obj_symbol_slew
parameter_list|(
name|bfd
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* `Tdata' information kept for COFF files.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coff_tdata
block|{
name|struct
name|coff_symbol_struct
modifier|*
name|symbols
decl_stmt|;
comment|/* symtab for input bfd */
name|unsigned
name|int
modifier|*
name|conversion_table
decl_stmt|;
name|int
name|conv_table_size
decl_stmt|;
name|file_ptr
name|sym_filepos
decl_stmt|;
name|long
name|symbol_index_slew
decl_stmt|;
comment|/* used during read to mark whether a 				   C_FILE symbol as been added. */
name|struct
name|coff_ptr_struct
modifier|*
name|raw_syments
decl_stmt|;
name|struct
name|lineno
modifier|*
name|raw_linenos
decl_stmt|;
name|unsigned
name|int
name|raw_syment_count
decl_stmt|;
name|unsigned
name|short
name|flags
decl_stmt|;
comment|/* These are only valid once writing has begun */
name|long
name|int
name|relocbase
decl_stmt|;
comment|/* These members communicate important constants about the symbol table      to GDB's symbol-reading code.  These `constants' unfortunately vary      from coff implementation to implementation...  */
name|unsigned
name|local_n_btmask
decl_stmt|;
name|unsigned
name|local_n_btshft
decl_stmt|;
name|unsigned
name|local_n_tmask
decl_stmt|;
name|unsigned
name|local_n_tshift
decl_stmt|;
name|unsigned
name|local_symesz
decl_stmt|;
name|unsigned
name|local_auxesz
decl_stmt|;
name|unsigned
name|local_linesz
decl_stmt|;
block|}
name|coff_data_type
typedef|;
end_typedef

begin_comment
comment|/* We take the address of the first element of a asymbol to ensure that the  * macro is only ever applied to an asymbol.  */
end_comment

begin_define
define|#
directive|define
name|coffsymbol
parameter_list|(
name|asymbol
parameter_list|)
value|((coff_symbol_type *)(&((asymbol)->the_bfd)))
end_define

begin_comment
comment|/* And more taken from the source .. */
end_comment

end_unit

