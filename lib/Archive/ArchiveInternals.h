begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/Archive/ArchiveInternals.h -------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Internal implementation header for LLVM Archive files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_ARCHIVE_ARCHIVEINTERNALS_H
end_ifndef

begin_define
define|#
directive|define
name|LIB_ARCHIVE_ARCHIVEINTERNALS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/Archive.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_define
define|#
directive|define
name|ARFILE_MAGIC
value|"!<arch>\n"
end_define

begin_comment
comment|///< magic string
end_comment

begin_define
define|#
directive|define
name|ARFILE_MAGIC_LEN
value|(sizeof(ARFILE_MAGIC)-1)
end_define

begin_comment
comment|///< length of magic string
end_comment

begin_define
define|#
directive|define
name|ARFILE_SVR4_SYMTAB_NAME
value|"/               "
end_define

begin_comment
comment|///< SVR4 symtab entry name
end_comment

begin_define
define|#
directive|define
name|ARFILE_LLVM_SYMTAB_NAME
value|"#_LLVM_SYM_TAB_#"
end_define

begin_comment
comment|///< LLVM symtab entry name
end_comment

begin_define
define|#
directive|define
name|ARFILE_BSD4_SYMTAB_NAME
value|"__.SYMDEF SORTED"
end_define

begin_comment
comment|///< BSD4 symtab entry name
end_comment

begin_define
define|#
directive|define
name|ARFILE_STRTAB_NAME
value|"//              "
end_define

begin_comment
comment|///< Name of string table
end_comment

begin_define
define|#
directive|define
name|ARFILE_PAD
value|"\n"
end_define

begin_comment
comment|///< inter-file align padding
end_comment

begin_define
define|#
directive|define
name|ARFILE_MEMBER_MAGIC
value|"`\n"
end_define

begin_comment
comment|///< fmag field magic #
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
comment|/// The ArchiveMemberHeader structure is used internally for bitcode
comment|/// archives.
comment|/// The header precedes each file member in the archive. This structure is
comment|/// defined using character arrays for direct and correct interpretation
comment|/// regardless of the endianess of the machine that produced it.
comment|/// @brief Archive File Member Header
name|class
name|ArchiveMemberHeader
block|{
comment|/// @name Data
comment|/// @{
name|public
label|:
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|///< Name of the file member.
name|char
name|date
index|[
literal|12
index|]
decl_stmt|;
comment|///< File date, decimal seconds since Epoch
name|char
name|uid
index|[
literal|6
index|]
decl_stmt|;
comment|///< user id in ASCII decimal
name|char
name|gid
index|[
literal|6
index|]
decl_stmt|;
comment|///< group id in ASCII decimal
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
comment|///< file mode in ASCII octal
name|char
name|size
index|[
literal|10
index|]
decl_stmt|;
comment|///< file size in ASCII decimal
name|char
name|fmag
index|[
literal|2
index|]
decl_stmt|;
comment|///< Always contains ARFILE_MAGIC_TERMINATOR
comment|/// @}
comment|/// @name Methods
comment|/// @{
name|public
label|:
name|void
name|init
parameter_list|()
block|{
name|memset
argument_list|(
name|name
argument_list|,
literal|' '
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|date
argument_list|,
literal|' '
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|uid
argument_list|,
literal|' '
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|gid
argument_list|,
literal|' '
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|mode
argument_list|,
literal|' '
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|size
argument_list|,
literal|' '
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|fmag
index|[
literal|0
index|]
operator|=
literal|'`'
expr_stmt|;
name|fmag
index|[
literal|1
index|]
operator|=
literal|'\n'
expr_stmt|;
block|}
name|bool
name|checkSignature
argument_list|()
specifier|const
block|{
return|return
literal|0
operator|==
name|memcmp
argument_list|(
name|fmag
argument_list|,
name|ARFILE_MEMBER_MAGIC
argument_list|,
literal|2
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|// Get just the externally visible defined symbols from the bitcode
name|bool
name|GetBitcodeSymbols
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|fName
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|symbols
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
decl_stmt|;
name|Module
modifier|*
name|GetBitcodeSymbols
argument_list|(
specifier|const
name|char
operator|*
name|Buffer
argument_list|,
name|unsigned
name|Length
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ModuleID
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|symbols
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// vim: sw=2 ai
end_comment

end_unit

