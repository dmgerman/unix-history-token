begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoverageMappingWriter.h - Code coverage mapping writer ---*- C++ -*-===//
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
comment|// This file contains support for writing coverage mapping data for
end_comment

begin_comment
comment|// instrumentation based coverage.
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
name|LLVM_PROFILEDATA_COVERAGE_COVERAGEMAPPINGWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_COVERAGE_COVERAGEMAPPINGWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ProfileData/Coverage/CoverageMapping.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|coverage
block|{
comment|/// \brief Writer of the filenames section for the instrumentation
comment|/// based code coverage.
name|class
name|CoverageFilenamesSectionWriter
block|{
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Filenames
expr_stmt|;
name|public
label|:
name|CoverageFilenamesSectionWriter
argument_list|(
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Filenames
argument_list|)
operator|:
name|Filenames
argument_list|(
argument|Filenames
argument_list|)
block|{}
comment|/// \brief Write encoded filenames to the given output stream.
name|void
name|write
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Writer for instrumentation based coverage mapping data.
name|class
name|CoverageMappingWriter
block|{
name|ArrayRef
operator|<
name|unsigned
operator|>
name|VirtualFileMapping
expr_stmt|;
name|ArrayRef
operator|<
name|CounterExpression
operator|>
name|Expressions
expr_stmt|;
name|MutableArrayRef
operator|<
name|CounterMappingRegion
operator|>
name|MappingRegions
expr_stmt|;
name|public
label|:
name|CoverageMappingWriter
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|VirtualFileMapping
argument_list|,
name|ArrayRef
operator|<
name|CounterExpression
operator|>
name|Expressions
argument_list|,
name|MutableArrayRef
operator|<
name|CounterMappingRegion
operator|>
name|MappingRegions
argument_list|)
operator|:
name|VirtualFileMapping
argument_list|(
name|VirtualFileMapping
argument_list|)
operator|,
name|Expressions
argument_list|(
name|Expressions
argument_list|)
operator|,
name|MappingRegions
argument_list|(
argument|MappingRegions
argument_list|)
block|{}
comment|/// \brief Write encoded coverage mapping data to the given output stream.
name|void
name|write
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace coverage
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_PROFILEDATA_COVERAGE_COVERAGEMAPPINGWRITER_H
end_comment

end_unit

