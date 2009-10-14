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
comment|//
end_comment

begin_comment
comment|// This header defines version macros and version-related utility functions
end_comment

begin_comment
comment|// for Clang.
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
name|LLVM_CLANG_BASIC_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_VERSION_H
end_define

begin_comment
comment|/// \brief Clang major version
end_comment

begin_define
define|#
directive|define
name|CLANG_VERSION_MAJOR
value|1
end_define

begin_comment
comment|// FIXME: Updates to this file must also update CMakeLists.txt and VER.
end_comment

begin_comment
comment|/// \brief Clang minor version
end_comment

begin_define
define|#
directive|define
name|CLANG_VERSION_MINOR
value|1
end_define

begin_comment
comment|/// \brief Clang patchlevel version
end_comment

begin_comment
comment|// #define CLANG_VERSION_PATCHLEVEL 1
end_comment

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
comment|/// \brief A string that describes the Clang version number, e.g.,
end_comment

begin_comment
comment|/// "1.0".
end_comment

begin_define
define|#
directive|define
name|CLANG_VERSION_STRING
define|\
value|CLANG_MAKE_VERSION_STRING(CLANG_VERSION_MAJOR,CLANG_VERSION_MINOR,CLANG_VERSION_PATCHLEVEL)
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
comment|/// \brief A string that describes the Clang version number, e.g.,
end_comment

begin_comment
comment|/// "1.0".
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
comment|/// \brief Retrieves the Subversion path that identifies the particular
comment|/// Clang branch, tag, or trunk from which this Clang was built.
specifier|const
name|char
modifier|*
name|getClangSubversionPath
parameter_list|()
function_decl|;
comment|/// \brief Retrieves the Subversion revision number from which this Clang
comment|/// was built.
name|unsigned
name|getClangSubversionRevision
parameter_list|()
function_decl|;
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

