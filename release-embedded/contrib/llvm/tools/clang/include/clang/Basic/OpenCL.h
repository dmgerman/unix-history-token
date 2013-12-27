begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OpenCL.h - OpenCL enums --------------------------------*- C++ -*-===//
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
comment|/// \brief Defines some OpenCL-specific enums.
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
name|LLVM_CLANG_BASIC_OPENCL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_OPENCL_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Names for the OpenCL image access qualifiers (OpenCL 1.1 6.6).
enum|enum
name|OpenCLImageAccess
block|{
name|CLIA_read_only
init|=
literal|1
block|,
name|CLIA_write_only
init|=
literal|2
block|,
name|CLIA_read_write
init|=
literal|3
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

