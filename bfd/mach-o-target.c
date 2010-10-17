begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mach-O support for BFD.    Copyright 1999, 2000, 2001, 2002    Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software     Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_NAME
end_ifndef

begin_error
error|#
directive|error
error|TARGET_NAME must be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_NAME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_STRING
end_ifndef

begin_error
error|#
directive|error
error|TARGET_STRING must be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_STRING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BIG_ENDIAN
end_ifndef

begin_error
error|#
directive|error
error|TARGET_BIG_ENDIAN must be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_BIG_ENDIAN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARCHIVE
end_ifndef

begin_error
error|#
directive|error
error|TARGET_ARCHIVE must be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_ARCHIVE */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|TARGET_ARCHIVE
operator|)
operator|&&
operator|(
operator|!
name|TARGET_BIG_ENDIAN
operator|)
operator|)
end_if

begin_error
error|#
directive|error
error|Mach-O fat files must always be big-endian.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ((TARGET_ARCHIVE)&& (! TARGET_BIG_ENDIAN)) */
end_comment

begin_decl_stmt
specifier|const
name|bfd_target
name|TARGET_NAME
init|=
block|{
name|TARGET_STRING
block|,
comment|/* Name.  */
name|bfd_target_mach_o_flavour
block|,
if|#
directive|if
name|TARGET_BIG_ENDIAN
name|BFD_ENDIAN_BIG
block|,
comment|/* Target byte order.  */
name|BFD_ENDIAN_BIG
block|,
comment|/* Target headers byte order.  */
else|#
directive|else
name|BFD_ENDIAN_LITTLE
block|,
comment|/* Target byte order.  */
name|BFD_ENDIAN_LITTLE
block|,
comment|/* Target headers byte order.  */
endif|#
directive|endif
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
comment|/* Object flags.  */
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|DYNAMIC
operator||
name|WP_TEXT
operator||
name|D_PAGED
operator|)
block|,
operator|(
name|SEC_CODE
operator||
name|SEC_DATA
operator||
name|SEC_ROM
operator||
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
block|,
comment|/* Section flags.  */
literal|'_'
block|,
comment|/* symbol_leading_char.  */
literal|' '
block|,
comment|/* ar_pad_char.  */
literal|16
block|,
comment|/* ar_max_namelen.  */
if|#
directive|if
name|TARGET_BIG_ENDIAN
name|bfd_getb64
block|,
name|bfd_getb_signed_64
block|,
name|bfd_putb64
block|,
name|bfd_getb32
block|,
name|bfd_getb_signed_32
block|,
name|bfd_putb32
block|,
name|bfd_getb16
block|,
name|bfd_getb_signed_16
block|,
name|bfd_putb16
block|,
comment|/* Data.  */
name|bfd_getb64
block|,
name|bfd_getb_signed_64
block|,
name|bfd_putb64
block|,
name|bfd_getb32
block|,
name|bfd_getb_signed_32
block|,
name|bfd_putb32
block|,
name|bfd_getb16
block|,
name|bfd_getb_signed_16
block|,
name|bfd_putb16
block|,
comment|/* Hdrs.  */
else|#
directive|else
name|bfd_getl64
block|,
name|bfd_getl_signed_64
block|,
name|bfd_putl64
block|,
name|bfd_getl32
block|,
name|bfd_getl_signed_32
block|,
name|bfd_putl32
block|,
name|bfd_getl16
block|,
name|bfd_getl_signed_16
block|,
name|bfd_putl16
block|,
comment|/* data */
name|bfd_getl64
block|,
name|bfd_getl_signed_64
block|,
name|bfd_putl64
block|,
name|bfd_getl32
block|,
name|bfd_getl_signed_32
block|,
name|bfd_putl32
block|,
name|bfd_getl16
block|,
name|bfd_getl_signed_16
block|,
name|bfd_putl16
block|,
comment|/* hdrs */
endif|#
directive|endif
comment|/* TARGET_BIG_ENDIAN */
block|{
comment|/* bfd_check_format.  */
if|#
directive|if
name|TARGET_ARCHIVE
name|_bfd_dummy_target
block|,
name|_bfd_dummy_target
block|,
name|bfd_mach_o_archive_p
block|,
name|_bfd_dummy_target
block|,
else|#
directive|else
name|_bfd_dummy_target
block|,
name|bfd_mach_o_object_p
block|,
name|_bfd_dummy_target
block|,
name|bfd_mach_o_core_p
endif|#
directive|endif
block|}
block|,
block|{
comment|/* bfd_set_format.  */
name|bfd_false
block|,
name|bfd_mach_o_mkobject
block|,
name|bfd_false
block|,
name|bfd_mach_o_mkobject
block|,   }
block|,
block|{
comment|/* bfd_write_contents.  */
name|bfd_false
block|,
name|bfd_mach_o_write_contents
block|,
name|bfd_false
block|,
name|bfd_mach_o_write_contents
block|,   }
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|bfd_mach_o
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|_bfd_nodynamic
argument_list|)
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

