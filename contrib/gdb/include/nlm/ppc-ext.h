begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC NLM (NetWare Loadable Module) support for BFD.    Copyright (C) 1994 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OLDFORMAT
end_ifdef

begin_comment
comment|/* The format of a PowerPC NLM changed.  These structures are only    used in the old format.  */
end_comment

begin_comment
comment|/* A PowerPC NLM starts with an instance of this structure.  */
end_comment

begin_struct
struct|struct
name|nlm32_powerpc_external_prefix_header
block|{
comment|/* Signature.  Must be "AppleNLM".  */
name|char
name|signature
index|[
literal|8
index|]
decl_stmt|;
comment|/* Version number.  Current value is 1.  */
name|unsigned
name|char
name|headerVersion
index|[
literal|4
index|]
decl_stmt|;
comment|/* ??.  Should be set to 0.  */
name|unsigned
name|char
name|origins
index|[
literal|4
index|]
decl_stmt|;
comment|/* File creation date in standard Unix time format (seconds since      1/1/70).  */
name|unsigned
name|char
name|date
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NLM32_POWERPC_SIGNATURE
value|"AppleNLM"
end_define

begin_define
define|#
directive|define
name|NLM32_POWERPC_HEADER_VERSION
value|1
end_define

begin_comment
comment|/* The external format of a PowerPC NLM reloc.  This is the same as an    XCOFF dynamic reloc.  */
end_comment

begin_struct
struct|struct
name|nlm32_powerpc_external_reloc
block|{
comment|/* Address.  */
name|unsigned
name|char
name|l_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* Symbol table index.  This is 0 for .text and 1 for .data.  2      means .bss, but I don't know if it is used.  In XCOFF, larger      numbers are indices into the dynamic symbol table, but they are      presumably not used in an NLM.  */
name|unsigned
name|char
name|l_symndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* Relocation type.  */
name|unsigned
name|char
name|l_rtype
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section number being relocated.  */
name|unsigned
name|char
name|l_rsecnm
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLDFORMAT */
end_comment

begin_comment
comment|/* The external format of the fixed header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm32_powerpc_external_fixed_header
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
name|Nlm32_powerpc_External_Fixed_Header
typedef|;
end_typedef

end_unit

