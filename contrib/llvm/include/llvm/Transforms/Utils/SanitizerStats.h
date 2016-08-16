begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SanitizerStats.h - Sanitizer statistics gathering  -------*- C++ -*-===//
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
comment|// Declares functions and data structures for sanitizer statistics gathering.
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
name|LLVM_TRANSFORMS_UTILS_SANITIZERSTATS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SANITIZERSTATS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Number of bits in data that are used for the sanitizer kind. Needs to match
comment|// __sanitizer::kKindBits in compiler-rt/lib/stats/stats.h
enum|enum
block|{
name|kSanitizerStatKindBits
init|=
literal|3
block|}
enum|;
enum|enum
name|SanitizerStatKind
block|{
name|SanStat_CFI_VCall
block|,
name|SanStat_CFI_NVCall
block|,
name|SanStat_CFI_DerivedCast
block|,
name|SanStat_CFI_UnrelatedCast
block|,
name|SanStat_CFI_ICall
block|, }
enum|;
struct|struct
name|SanitizerStatReport
block|{
name|SanitizerStatReport
argument_list|(
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
comment|/// Generates code into B that increments a location-specific counter tagged
comment|/// with the given sanitizer kind SK.
name|void
name|create
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
name|SanitizerStatKind
name|SK
argument_list|)
decl_stmt|;
comment|/// Finalize module stats array and add global constructor to register it.
name|void
name|finish
parameter_list|()
function_decl|;
name|private
label|:
name|Module
modifier|*
name|M
decl_stmt|;
name|GlobalVariable
modifier|*
name|ModuleStatsGV
decl_stmt|;
name|ArrayType
modifier|*
name|StatTy
decl_stmt|;
name|StructType
modifier|*
name|EmptyModuleStatsTy
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
name|Inits
expr_stmt|;
name|ArrayType
modifier|*
name|makeModuleStatsArrayTy
parameter_list|()
function_decl|;
name|StructType
modifier|*
name|makeModuleStatsTy
parameter_list|()
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

