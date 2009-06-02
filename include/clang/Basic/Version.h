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
comment|// This header defines version macros for Clang.
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
comment|/// \brief Clang minor version
end_comment

begin_define
define|#
directive|define
name|CLANG_VERSION_MINOR
value|0
end_define

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

begin_comment
comment|// LLVM_CLANG_BASIC_VERSION_H
end_comment

end_unit

