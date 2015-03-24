begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Config/Version.h - LLD Version Number ----------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines version macros and version-related utility functions
end_comment

begin_comment
comment|/// for lld.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_VERSION_H
end_define

begin_include
include|#
directive|include
file|"lld/Config/Version.inc"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|/// \brief Helper macro for LLD_VERSION_STRING.
end_comment

begin_define
define|#
directive|define
name|LLD_MAKE_VERSION_STRING2
parameter_list|(
name|X
parameter_list|)
value|#X
end_define

begin_comment
comment|/// \brief Helper macro for LLD_VERSION_STRING.
end_comment

begin_define
define|#
directive|define
name|LLD_MAKE_VERSION_STRING
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|LLD_MAKE_VERSION_STRING2(X.Y)
end_define

begin_comment
comment|/// \brief A string that describes the lld version number, e.g., "1.0".
end_comment

begin_define
define|#
directive|define
name|LLD_VERSION_STRING
define|\
value|LLD_MAKE_VERSION_STRING(LLD_VERSION_MAJOR, LLD_VERSION_MINOR)
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
comment|/// \brief Retrieves the repository path (e.g., Subversion path) that
comment|/// identifies the particular lld branch, tag, or trunk from which this
comment|/// lld was built.
name|llvm
operator|::
name|StringRef
name|getLLDRepositoryPath
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves the repository revision number (or identifer) from which
comment|/// this lld was built.
name|llvm
operator|::
name|StringRef
name|getLLDRevision
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves the full repository version that is an amalgamation of
comment|/// the information in getLLDRepositoryPath() and getLLDRevision().
name|std
operator|::
name|string
name|getLLDRepositoryVersion
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves a string representing the complete lld version.
name|llvm
operator|::
name|StringRef
name|getLLDVersion
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_VERSION_H
end_comment

end_unit

