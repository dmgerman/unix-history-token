begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NLM (NetWare Loadable Module) support for BFD.    Copyright (C) 1993 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is part of NLM support for BFD, and contains the portions    that describe how NLM is represented internally in the BFD library.    I.E. it describes the in-memory representation of NLM.  It requires    the nlm/common.h file which contains the portions that are common to    both the internal and external representations. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Types used by various structures, functions, etc. */
end_comment

begin_comment
unit|typedef unsigned long	Nlm32_Addr;
comment|/* Unsigned program address */
end_comment

begin_comment
unit|typedef unsigned long	Nlm32_Off;
comment|/* Unsigned file offset */
end_comment

begin_comment
unit|typedef 	 long	Nlm32_Sword;
comment|/* Signed large integer */
end_comment

begin_comment
unit|typedef unsigned long	Nlm32_Word;
comment|/* Unsigned large integer */
end_comment

begin_comment
unit|typedef unsigned short	Nlm32_Half;
comment|/* Unsigned medium integer */
end_comment

begin_comment
unit|typedef unsigned char	Nlm32_Char;
comment|/* Unsigned tiny integer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HOST_64_BIT
end_ifdef

begin_endif
unit|typedef unsigned BFD_HOST_64_BIT	Nlm64_Addr; typedef unsigned BFD_HOST_64_BIT	Nlm64_Off; typedef          BFD_HOST_64_BIT	Nlm64_Sxword; typedef unsigned BFD_HOST_64_BIT	Nlm64_Xword;
endif|#
directive|endif
end_endif

begin_endif
unit|typedef          long		Nlm64_Sword; typedef unsigned long		Nlm64_Word; typedef unsigned short		Nlm64_Half;
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* This structure contains the internal form of the portion of the NLM    header that is fixed length. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_fixed_header
block|{
comment|/* The signature field identifies the file as an NLM.  It must contain      the signature string, which depends upon the NLM target. */
name|char
name|signature
index|[
name|NLM_SIGNATURE_SIZE
index|]
decl_stmt|;
comment|/* The version of the header.  At this time, the highest version number      is 4. */
name|long
name|version
decl_stmt|;
comment|/* The name of the module, which must be a DOS name (1-8 characters followed      by a period and a 1-3 character extension.  The first byte is the byte      length of the name and the last byte is a null terminator byte.  This      field is fixed length, and any unused bytes should be null bytes.  The      value is set by the OUTPUT keyword to NLMLINK. */
name|char
name|moduleName
index|[
name|NLM_MODULE_NAME_SIZE
index|]
decl_stmt|;
comment|/* The byte offset of the code image from the start of the file. */
name|file_ptr
name|codeImageOffset
decl_stmt|;
comment|/* The size of the code image, in bytes. */
name|bfd_size_type
name|codeImageSize
decl_stmt|;
comment|/* The byte offset of the data image from the start of the file. */
name|file_ptr
name|dataImageOffset
decl_stmt|;
comment|/* The size of the data image, in bytes. */
name|bfd_size_type
name|dataImageSize
decl_stmt|;
comment|/* The size of the uninitialized data region that the loader is to be      allocated at load time.  Uninitialized data follows the initialized      data in the NLM address space. */
name|bfd_size_type
name|uninitializedDataSize
decl_stmt|;
comment|/* The byte offset of the custom data from the start of the file.  The      custom data is set by the CUSTOM keyword to NLMLINK. */
name|file_ptr
name|customDataOffset
decl_stmt|;
comment|/* The size of the custom data, in bytes. */
name|bfd_size_type
name|customDataSize
decl_stmt|;
comment|/* The byte offset of the module dependencies from the start of the file.      The module dependencies are determined by the MODULE keyword in      NLMLINK. */
name|file_ptr
name|moduleDependencyOffset
decl_stmt|;
comment|/* The number of module dependencies at the moduleDependencyOffset. */
name|long
name|numberOfModuleDependencies
decl_stmt|;
comment|/* The byte offset of the relocation fixup data from the start of the file */
name|file_ptr
name|relocationFixupOffset
decl_stmt|;
name|long
name|numberOfRelocationFixups
decl_stmt|;
name|file_ptr
name|externalReferencesOffset
decl_stmt|;
name|long
name|numberOfExternalReferences
decl_stmt|;
name|file_ptr
name|publicsOffset
decl_stmt|;
name|long
name|numberOfPublics
decl_stmt|;
name|file_ptr
name|debugInfoOffset
decl_stmt|;
name|long
name|numberOfDebugRecords
decl_stmt|;
name|file_ptr
name|codeStartOffset
decl_stmt|;
name|file_ptr
name|exitProcedureOffset
decl_stmt|;
name|file_ptr
name|checkUnloadProcedureOffset
decl_stmt|;
name|long
name|moduleType
decl_stmt|;
name|long
name|flags
decl_stmt|;
block|}
name|Nlm_Internal_Fixed_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_fixed_header
value|nlm_internal_fixed_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Fixed_Header
value|Nlm_Internal_Fixed_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_fixed_header
value|nlm_internal_fixed_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Fixed_Header
value|Nlm_Internal_Fixed_Header
end_define

begin_comment
comment|/* This structure contains the portions of the NLM header that are either    variable in size in the external representation, or else are not at a    fixed offset relative to the start of the NLM header due to preceding    variable sized fields.     Note that all the fields must exist in the external header, and in    the order used here (the same order is used in the internal form    for consistency, not out of necessity). */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_variable_header
block|{
comment|/* The descriptionLength field contains the length of the text in      descriptionText, excluding the null terminator.  The descriptionText      field contains the NLM description obtained from the DESCRIPTION      keyword in NLMLINK plus the null byte terminator.  The descriptionText      can be up to NLM_MAX_DESCRIPTION_LENGTH characters. */
name|unsigned
name|char
name|descriptionLength
decl_stmt|;
name|char
name|descriptionText
index|[
name|NLM_MAX_DESCRIPTION_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* The stackSize field contains the size of the stack in bytes, as      specified by the STACK or STACKSIZE keyword in NLMLINK.  If no size      is specified, the default is NLM_DEFAULT_STACKSIZE. */
name|long
name|stackSize
decl_stmt|;
comment|/* The reserved field is included only for completeness.  It should contain      zero. */
name|long
name|reserved
decl_stmt|;
comment|/* This field is fixed length, should contain " LONG" (note leading      space), and is unused. */
name|char
name|oldThreadName
index|[
name|NLM_OLD_THREAD_NAME_LENGTH
index|]
decl_stmt|;
comment|/* The screenNameLength field contains the length of the actual text stored      in the screenName field, excluding the null byte terminator.  The      screenName field contains the screen name as specified by the SCREENNAME      keyword in NLMLINK, and can be up to NLM_MAX_SCREEN_NAME_LENGTH      characters. */
name|unsigned
name|char
name|screenNameLength
decl_stmt|;
name|char
name|screenName
index|[
name|NLM_MAX_SCREEN_NAME_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* The threadNameLength field contains the length of the actual text stored      in the threadName field, excluding the null byte terminator.  The      threadName field contains the thread name as specified by the THREADNAME      keyword in NLMLINK, and can be up to NLM_MAX_THREAD_NAME_LENGTH      characters. */
name|unsigned
name|char
name|threadNameLength
decl_stmt|;
name|char
name|threadName
index|[
name|NLM_MAX_THREAD_NAME_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|Nlm_Internal_Variable_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_variable_header
value|nlm_internal_variable_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Variable_Header
value|Nlm_Internal_Variable_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_variable_header
value|nlm_internal_variable_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Variable_Header
value|Nlm_Internal_Variable_Header
end_define

begin_comment
comment|/* The version header is one of the optional auxiliary headers and    follows the fixed length and variable length NLM headers. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_version_header
block|{
comment|/* The header is recognized by "VeRsIoN#" in the stamp field. */
name|char
name|stamp
index|[
literal|8
index|]
decl_stmt|;
name|long
name|majorVersion
decl_stmt|;
name|long
name|minorVersion
decl_stmt|;
name|long
name|revision
decl_stmt|;
name|long
name|year
decl_stmt|;
name|long
name|month
decl_stmt|;
name|long
name|day
decl_stmt|;
block|}
name|Nlm_Internal_Version_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_version_header
value|nlm_internal_version_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Version_Header
value|Nlm_Internal_Version_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_version_header
value|nlm_internal_version_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Version_Header
value|Nlm_Internal_Version_Header
end_define

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_copyright_header
block|{
comment|/* The header is recognized by "CoPyRiGhT=" in the stamp field. */
name|char
name|stamp
index|[
literal|10
index|]
decl_stmt|;
name|unsigned
name|char
name|copyrightMessageLength
decl_stmt|;
name|char
name|copyrightMessage
index|[
name|NLM_MAX_COPYRIGHT_MESSAGE_LENGTH
index|]
decl_stmt|;
block|}
name|Nlm_Internal_Copyright_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_copyright_header
value|nlm_internal_copyright_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Copyright_Header
value|Nlm_Internal_Copyright_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_copyright_header
value|nlm_internal_copyright_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Copyright_Header
value|Nlm_Internal_Copyright_Header
end_define

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_extended_header
block|{
comment|/* The header is recognized by "MeSsAgEs" in the stamp field. */
name|char
name|stamp
index|[
literal|8
index|]
decl_stmt|;
name|long
name|languageID
decl_stmt|;
name|file_ptr
name|messageFileOffset
decl_stmt|;
name|bfd_size_type
name|messageFileLength
decl_stmt|;
name|long
name|messageCount
decl_stmt|;
name|file_ptr
name|helpFileOffset
decl_stmt|;
name|bfd_size_type
name|helpFileLength
decl_stmt|;
name|file_ptr
name|RPCDataOffset
decl_stmt|;
name|bfd_size_type
name|RPCDataLength
decl_stmt|;
name|file_ptr
name|sharedCodeOffset
decl_stmt|;
name|bfd_size_type
name|sharedCodeLength
decl_stmt|;
name|file_ptr
name|sharedDataOffset
decl_stmt|;
name|bfd_size_type
name|sharedDataLength
decl_stmt|;
name|file_ptr
name|sharedRelocationFixupOffset
decl_stmt|;
name|long
name|sharedRelocationFixupCount
decl_stmt|;
name|file_ptr
name|sharedExternalReferenceOffset
decl_stmt|;
name|long
name|sharedExternalReferenceCount
decl_stmt|;
name|file_ptr
name|sharedPublicsOffset
decl_stmt|;
name|long
name|sharedPublicsCount
decl_stmt|;
name|file_ptr
name|sharedDebugRecordOffset
decl_stmt|;
name|long
name|sharedDebugRecordCount
decl_stmt|;
name|bfd_vma
name|SharedInitializationOffset
decl_stmt|;
name|bfd_vma
name|SharedExitProcedureOffset
decl_stmt|;
name|long
name|productID
decl_stmt|;
name|long
name|reserved0
decl_stmt|;
name|long
name|reserved1
decl_stmt|;
name|long
name|reserved2
decl_stmt|;
name|long
name|reserved3
decl_stmt|;
name|long
name|reserved4
decl_stmt|;
name|long
name|reserved5
decl_stmt|;
block|}
name|Nlm_Internal_Extended_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_extended_header
value|nlm_internal_extended_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Extended_Header
value|Nlm_Internal_Extended_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_extended_header
value|nlm_internal_extended_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Extended_Header
value|Nlm_Internal_Extended_Header
end_define

begin_comment
comment|/* The format of a custom header as stored internally is different    from the external format.  This is how we store a custom header    which we do not recognize.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_custom_header
block|{
comment|/* The header is recognized by "CuStHeAd" in the stamp field. */
name|char
name|stamp
index|[
literal|8
index|]
decl_stmt|;
name|bfd_size_type
name|hdrLength
decl_stmt|;
name|file_ptr
name|dataOffset
decl_stmt|;
name|bfd_size_type
name|dataLength
decl_stmt|;
name|char
name|dataStamp
index|[
literal|8
index|]
decl_stmt|;
name|PTR
name|hdr
decl_stmt|;
block|}
name|Nlm_Internal_Custom_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_custom_header
value|nlm_internal_custom_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Custom_Header
value|Nlm_Internal_Custom_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_custom_header
value|nlm_internal_custom_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Custom_Header
value|Nlm_Internal_Custom_Header
end_define

begin_comment
comment|/* The internal Cygnus header is written out externally as a custom    header.  We don't try to replicate that structure here.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nlm_internal_cygnus_ext_header
block|{
comment|/* The header is recognized by "CyGnUsEx" in the stamp field. */
name|char
name|stamp
index|[
literal|8
index|]
decl_stmt|;
comment|/* File location of debugging information.  */
name|file_ptr
name|offset
decl_stmt|;
comment|/* Length of debugging information.  */
name|bfd_size_type
name|length
decl_stmt|;
block|}
name|Nlm_Internal_Cygnus_Ext_Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nlm32_internal_cygnus_ext_header
value|nlm_internal_cygnus_ext_header
end_define

begin_define
define|#
directive|define
name|Nlm32_Internal_Cygnus_Ext_Header
value|Nlm_Internal_Cygnus_Ext_Header
end_define

begin_define
define|#
directive|define
name|nlm64_internal_cygnus_ext_header
value|nlm_internal_cygnus_ext_header
end_define

begin_define
define|#
directive|define
name|Nlm64_Internal_Cygnus_Ext_Header
value|Nlm_Internal_Cygnus_Ext_Header
end_define

end_unit

