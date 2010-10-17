begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Special version of<a.out.h> for use under hp-ux.    Copyright 1988, 1991 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* THIS FILE IS OBSOLETE.  It needs to be revised as a variant "external"    a.out format for use with BFD.  */
end_comment

begin_comment
comment|/* The `exec' structure and overall layout must be close to HP's when    we are running on an HP system, otherwise we will not be able to    execute the resulting file. */
end_comment

begin_comment
comment|/* Allow this file to be included twice. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_EXEC_MACROS__
end_ifndef

begin_struct
struct|struct
name|exec
block|{
name|unsigned
name|short
name|a_machtype
decl_stmt|;
comment|/* machine type */
name|unsigned
name|short
name|a_magic
decl_stmt|;
comment|/* magic number */
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
comment|/* length of text, in bytes */
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* length of data, in bytes */
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* length of uninitialized data area for file, in bytes */
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* length of relocation info for text, in bytes */
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* length of relocation info for data, in bytes */
name|unsigned
name|long
name|a_spare3
decl_stmt|;
comment|/* HP = pascal interface size */
name|unsigned
name|long
name|a_spare4
decl_stmt|;
comment|/* HP = symbol table size */
name|unsigned
name|long
name|a_spare5
decl_stmt|;
comment|/* HP = debug name table size */
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* start address */
name|unsigned
name|long
name|a_spare6
decl_stmt|;
comment|/* HP = source line table size */
name|unsigned
name|long
name|a_spare7
decl_stmt|;
comment|/* HP = value table size */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* length of symbol table data in file, in bytes */
name|unsigned
name|long
name|a_spare8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tell a.out.gnu.h not to define `struct exec'.  */
end_comment

begin_define
define|#
directive|define
name|__STRUCT_EXEC_OVERRIDE__
end_define

begin_include
include|#
directive|include
file|"../a.out.gnu.h"
end_include

begin_undef
undef|#
directive|undef
name|N_MAGIC
end_undef

begin_undef
undef|#
directive|undef
name|N_MACHTYPE
end_undef

begin_undef
undef|#
directive|undef
name|N_FLAGS
end_undef

begin_undef
undef|#
directive|undef
name|N_SET_INFO
end_undef

begin_undef
undef|#
directive|undef
name|N_SET_MAGIC
end_undef

begin_undef
undef|#
directive|undef
name|N_SET_MACHTYPE
end_undef

begin_undef
undef|#
directive|undef
name|N_SET_FLAGS
end_undef

begin_define
define|#
directive|define
name|N_MAGIC
parameter_list|(
name|exec
parameter_list|)
value|((exec) . a_magic)
end_define

begin_define
define|#
directive|define
name|N_MACHTYPE
parameter_list|(
name|exec
parameter_list|)
value|((exec) . a_machtype)
end_define

begin_define
define|#
directive|define
name|N_SET_MAGIC
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|)
value|(((exec) . a_magic) = (magic))
end_define

begin_define
define|#
directive|define
name|N_SET_MACHTYPE
parameter_list|(
name|exec
parameter_list|,
name|machtype
parameter_list|)
value|(((exec) . a_machtype) = (machtype))
end_define

begin_undef
undef|#
directive|undef
name|N_BADMAG
end_undef

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((_N_BADMAG (x)) || (_N_BADMACH (x)))
end_define

begin_define
define|#
directive|define
name|_N_BADMACH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((N_MACHTYPE (x)) != HP9000S200_ID)&&					\  ((N_MACHTYPE (x)) != HP98x6_ID))
end_define

begin_define
define|#
directive|define
name|HP98x6_ID
value|0x20A
end_define

begin_define
define|#
directive|define
name|HP9000S200_ID
value|0x20C
end_define

begin_undef
undef|#
directive|undef
name|_N_HDROFF
end_undef

begin_define
define|#
directive|define
name|_N_HDROFF
parameter_list|(
name|x
parameter_list|)
value|(SEGMENT_SIZE - (sizeof (struct exec)))
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_EXEC_MACROS__ */
end_comment

end_unit

