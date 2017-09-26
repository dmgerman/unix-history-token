begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AddressSpaces.h - Language-specific address spaces -----*- C++ -*-===//
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
comment|/// \brief Provides definitions for the various language-specific address
end_comment

begin_comment
comment|/// spaces.
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
name|LLVM_CLANG_BASIC_ADDRESSSPACES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_ADDRESSSPACES_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|LangAS
block|{
comment|/// \brief Defines the address space values used by the address space qualifier
comment|/// of QualType.
comment|///
enum|enum
name|ID
block|{
comment|// The default value 0 is the value used in QualType for the the situation
comment|// where there is no address space qualifier. For most languages, this also
comment|// corresponds to the situation where there is no address space qualifier in
comment|// the source code, except for OpenCL, where the address space value 0 in
comment|// QualType represents private address space in OpenCL source code.
name|Default
init|=
literal|0
block|,
comment|// OpenCL specific address spaces.
name|opencl_global
block|,
name|opencl_local
block|,
name|opencl_constant
block|,
name|opencl_generic
block|,
comment|// CUDA specific address spaces.
name|cuda_device
block|,
name|cuda_constant
block|,
name|cuda_shared
block|,
comment|// This denotes the count of language-specific address spaces and also
comment|// the offset added to the target-specific address spaces, which are usually
comment|// specified by address space attributes __attribute__(address_space(n))).
name|FirstTargetAddressSpace
block|}
enum|;
comment|/// The type of a lookup table which maps from language-specific address spaces
comment|/// to target-specific ones.
typedef|typedef
name|unsigned
name|Map
index|[
name|FirstTargetAddressSpace
index|]
typedef|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

