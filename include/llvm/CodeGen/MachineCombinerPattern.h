begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineCombinerPattern.h - Instruction pattern supported by
end_comment

begin_comment
comment|// combiner  ------*- C++ -*-===//
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
comment|// This file defines instruction pattern supported by combiner
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
name|LLVM_CODEGEN_MACHINECOMBINERPATTERN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINECOMBINERPATTERN_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Enumeration of instruction pattern supported by machine combiner
comment|///
comment|///
name|namespace
name|MachineCombinerPattern
block|{
comment|// Forward declaration
enum_decl|enum
name|MC_PATTERN
enum_decl|:
name|int
enum_decl|;
block|}
comment|// end namespace MachineCombinerPattern
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

