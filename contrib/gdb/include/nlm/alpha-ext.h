begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Alpha NLM (NetWare Loadable Module) support for BFD.    Copyright (C) 1993 Free Software Foundation, Inc.    By Ian Lance Taylor, Cygnus Support  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* An Alpha NLM starts with an instance of this structure.  */
end_comment

begin_struct
struct|struct
name|nlm32_alpha_external_prefix_header
block|{
comment|/* Magic number.  Must be NLM32_ALPHA_MAGIC.  */
name|unsigned
name|char
name|magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* Format descriptor.  Current value is 2.  */
name|unsigned
name|char
name|format
index|[
literal|4
index|]
decl_stmt|;
comment|/* Size of prefix header.  */
name|unsigned
name|char
name|size
index|[
literal|4
index|]
decl_stmt|;
comment|/* Padding.  */
name|unsigned
name|char
name|pad1
index|[
literal|4
index|]
decl_stmt|;
comment|/* More fields may be added later, supposedly.  */
block|}
struct|;
end_struct

begin_comment
comment|/* The external format of an Alpha NLM reloc.  This is the same as an    Alpha ECOFF reloc.  */
end_comment

begin_struct
struct|struct
name|nlm32_alpha_external_reloc
block|{
name|unsigned
name|char
name|r_vaddr
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|r_bits
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Constants to unpack the r_bits field of a reloc.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_BITS0_TYPE_LITTLE
value|0xff
end_define

begin_define
define|#
directive|define
name|RELOC_BITS0_TYPE_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_EXTERN_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_OFFSET_LITTLE
value|0x7e
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_OFFSET_SH_LITTLE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_RESERVED_LITTLE
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_RESERVED_SH_LITTLE
value|7
end_define

begin_define
define|#
directive|define
name|RELOC_BITS2_RESERVED_LITTLE
value|0xff
end_define

begin_define
define|#
directive|define
name|RELOC_BITS2_RESERVED_SH_LEFT_LITTLE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_RESERVED_LITTLE
value|0x03
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_RESERVED_SH_LEFT_LITTLE
value|9
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_SIZE_LITTLE
value|0xfc
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_SIZE_SH_LITTLE
value|2
end_define

begin_comment
comment|/* The external format of the fixed header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm32_alpha_external_fixed_header
block|{
comment|/* The signature field identifies the file as an NLM.  It must contain      the signature string, which depends upon the NLM target. */
name|unsigned
name|char
name|signature
index|[
literal|24
index|]
decl_stmt|;
comment|/* The version of the header.  At this time, the highest version number      is 4. */
name|unsigned
name|char
name|version
index|[
literal|4
index|]
decl_stmt|;
comment|/* The name of the module, which must be a DOS name (1-8 characters followed      by a period and a 1-3 character extension).  The first byte is the byte      length of the name and the last byte is a null terminator byte.  This      field is fixed length, and any unused bytes should be null bytes.  The      value is set by the OUTPUT keyword to NLMLINK. */
name|unsigned
name|char
name|moduleName
index|[
literal|14
index|]
decl_stmt|;
comment|/* Padding to make it come out correct. */
name|unsigned
name|char
name|pad1
index|[
literal|2
index|]
decl_stmt|;
comment|/* The byte offset of the code image from the start of the file. */
name|unsigned
name|char
name|codeImageOffset
index|[
literal|4
index|]
decl_stmt|;
comment|/* The size of the code image, in bytes. */
name|unsigned
name|char
name|codeImageSize
index|[
literal|4
index|]
decl_stmt|;
comment|/* The byte offset of the data image from the start of the file. */
name|unsigned
name|char
name|dataImageOffset
index|[
literal|4
index|]
decl_stmt|;
comment|/* The size of the data image, in bytes. */
name|unsigned
name|char
name|dataImageSize
index|[
literal|4
index|]
decl_stmt|;
comment|/* The size of the uninitialized data region that the loader is to be      allocated at load time.  Uninitialized data follows the initialized      data in the NLM address space. */
name|unsigned
name|char
name|uninitializedDataSize
index|[
literal|4
index|]
decl_stmt|;
comment|/* The byte offset of the custom data from the start of the file.  The      custom data is set by the CUSTOM keyword to NLMLINK.  It is possible      for this to be EOF if there is no custom data. */
name|unsigned
name|char
name|customDataOffset
index|[
literal|4
index|]
decl_stmt|;
comment|/* The size of the custom data, in bytes. */
name|unsigned
name|char
name|customDataSize
index|[
literal|4
index|]
decl_stmt|;
comment|/* The byte offset of the module dependencies from the start of the file.      The module dependencies are determined by the MODULE keyword in      NLMLINK. */
name|unsigned
name|char
name|moduleDependencyOffset
index|[
literal|4
index|]
decl_stmt|;
comment|/* The number of module dependencies at the moduleDependencyOffset. */
name|unsigned
name|char
name|numberOfModuleDependencies
index|[
literal|4
index|]
decl_stmt|;
comment|/* The byte offset of the relocation fixup data from the start of the file */
name|unsigned
name|char
name|relocationFixupOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|numberOfRelocationFixups
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|externalReferencesOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|numberOfExternalReferences
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|publicsOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|numberOfPublics
index|[
literal|4
index|]
decl_stmt|;
comment|/* The byte offset of the internal debug info from the start of the file.      It is possible for this to be EOF if there is no debug info. */
name|unsigned
name|char
name|debugInfoOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|numberOfDebugRecords
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|codeStartOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|exitProcedureOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|checkUnloadProcedureOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|moduleType
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|flags
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Nlm32_alpha_External_Fixed_Header
typedef|;
end_typedef

end_unit

