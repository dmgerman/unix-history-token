begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Version.h - Clang Version Number -------------------------*- C++ -*-===//
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
comment|/// for Clang.
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
name|LLVM_CLANG_BASIC_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_VERSION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Version.inc"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|/// \brief Helper macro for CLANG_VERSION_STRING.
end_comment

begin_define
define|#
directive|define
name|CLANG_MAKE_VERSION_STRING2
parameter_list|(
name|X
parameter_list|)
value|#X
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CLANG_VERSION_PATCHLEVEL
end_ifdef

begin_comment
comment|/// \brief Helper macro for CLANG_VERSION_STRING.
end_comment

begin_define
define|#
directive|define
name|CLANG_MAKE_VERSION_STRING
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
value|CLANG_MAKE_VERSION_STRING2(X.Y.Z)
end_define

begin_comment
comment|/// \brief A string that describes the Clang version number, e.g., "1.0".
end_comment

begin_define
define|#
directive|define
name|CLANG_VERSION_STRING
define|\
value|CLANG_MAKE_VERSION_STRING(CLANG_VERSION_MAJOR,CLANG_VERSION_MINOR, \                             CLANG_VERSION_PATCHLEVEL)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/// \brief Helper macro for CLANG_VERSION_STRING.
end_comment

begin_define
define|#
directive|define
name|CLANG_MAKE_VERSION_STRING
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|CLANG_MAKE_VERSION_STRING2(X.Y)
end_define

begin_comment
comment|/// \brief A string that describes the Clang version number, e.g., "1.0".
end_comment

begin_define
define|#
directive|define
name|CLANG_VERSION_STRING
define|\
value|CLANG_MAKE_VERSION_STRING(CLANG_VERSION_MAJOR,CLANG_VERSION_MINOR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Retrieves the repository path (e.g., Subversion path) that
comment|/// identifies the particular Clang branch, tag, or trunk from which this
comment|/// Clang was built.
name|std
operator|::
name|string
name|getClangRepositoryPath
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves the repository path from which LLVM was built.
comment|///
comment|/// This supports LLVM residing in a separate repository from clang.
name|std
operator|::
name|string
name|getLLVMRepositoryPath
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves the repository revision number (or identifer) from which
comment|/// this Clang was built.
name|std
operator|::
name|string
name|getClangRevision
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves the repository revision number (or identifer) from which
comment|/// LLVM was built.
comment|///
comment|/// If Clang and LLVM are in the same repository, this returns the same
comment|/// string as getClangRevision.
name|std
operator|::
name|string
name|getLLVMRevision
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves the full repository version that is an amalgamation of
comment|/// the information in getClangRepositoryPath() and getClangRevision().
name|std
operator|::
name|string
name|getClangFullRepositoryVersion
argument_list|()
expr_stmt|;
comment|/// \brief Retrieves a string representing the complete clang version,
comment|/// which includes the clang version number, the repository version,
comment|/// and the vendor tag.
name|std
operator|::
name|string
name|getClangFullVersion
argument_list|()
expr_stmt|;
comment|/// \brief Like getClangFullVersion(), but with a custom tool name.
name|std
operator|::
name|string
name|getClangToolFullVersion
argument_list|(
argument|llvm::StringRef ToolName
argument_list|)
expr_stmt|;
comment|/// \brief Retrieves a string representing the complete clang version suitable
comment|/// for use in the CPP __VERSION__ macro, which includes the clang version
comment|/// number, the repository version, and the vendor tag.
name|std
operator|::
name|string
name|getClangFullCPPVersion
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_VERSION_H
end_comment

end_unit

