begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is obj-hp300.h    Copyright 1993, 2000 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|__STRUCT_EXEC_OVERRIDE__
end_define

begin_struct
struct|struct
name|exec_bytes
block|{
name|unsigned
name|char
name|a_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* a_machtype/a_magic */
name|unsigned
name|char
name|a_spare1
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_spare2
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_text
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of text, in bytes */
name|unsigned
name|char
name|a_data
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of data, in bytes */
name|unsigned
name|char
name|a_bss
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of uninitialized data area for file, in bytes */
name|unsigned
name|char
name|a_trsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of relocation info for text, in bytes */
name|unsigned
name|char
name|a_drsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of relocation info for data, in bytes */
name|unsigned
name|char
name|a_spare3
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = pascal interface size */
name|unsigned
name|char
name|a_spare4
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = symbol table size */
name|unsigned
name|char
name|a_spare5
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = debug name table size */
name|unsigned
name|char
name|a_entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* start address */
name|unsigned
name|char
name|a_spare6
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = source line table size */
name|unsigned
name|char
name|a_spare7
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = value table size */
name|unsigned
name|char
name|a_syms
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of symbol table data in file, in bytes */
name|unsigned
name|char
name|a_spare8
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How big the "struct exec" is on disk */
end_comment

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|(16 * 4)
end_define

begin_struct
struct|struct
name|exec
block|{
name|unsigned
name|long
name|a_info
decl_stmt|;
name|unsigned
name|long
name|a_spare1
decl_stmt|;
name|unsigned
name|long
name|a_spare2
decl_stmt|;
name|unsigned
name|long
name|a_text
decl_stmt|;
name|unsigned
name|long
name|a_data
decl_stmt|;
name|unsigned
name|long
name|a_bss
decl_stmt|;
name|unsigned
name|long
name|a_trsize
decl_stmt|;
name|unsigned
name|long
name|a_drsize
decl_stmt|;
name|unsigned
name|long
name|a_spare3
decl_stmt|;
name|unsigned
name|long
name|a_spare4
decl_stmt|;
name|unsigned
name|long
name|a_spare5
decl_stmt|;
name|unsigned
name|long
name|a_entry
decl_stmt|;
name|unsigned
name|long
name|a_spare6
decl_stmt|;
name|unsigned
name|long
name|a_spare7
decl_stmt|;
name|unsigned
name|long
name|a_syms
decl_stmt|;
name|unsigned
name|long
name|a_spare8
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|(OMAGIC)
end_define

begin_define
define|#
directive|define
name|AOUT_VERSION
value|0x02
end_define

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|0x0c
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|0x106
end_define

begin_define
define|#
directive|define
name|obj_header_append
value|hp300_header_append
end_define

begin_include
include|#
directive|include
file|"config/obj-aout.h"
end_include

end_unit

