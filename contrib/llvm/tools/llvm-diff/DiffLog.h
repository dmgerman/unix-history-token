begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DiffLog.h - Difference Log Builder and accessories ------*- C++ -*-===//
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
comment|// This header defines the interface to the LLVM difference log builder.
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
name|LLVM_TOOLS_LLVM_DIFF_DIFFLOG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_DIFF_DIFFLOG_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Consumer
decl_stmt|;
comment|/// Trichotomy assumption
enum|enum
name|DiffChange
block|{
name|DC_match
block|,
name|DC_left
block|,
name|DC_right
block|}
enum|;
comment|/// A temporary-object class for building up log messages.
name|class
name|LogBuilder
block|{
name|Consumer
modifier|&
name|consumer
decl_stmt|;
comment|/// The use of a stored StringRef here is okay because
comment|/// LogBuilder should be used only as a temporary, and as a
comment|/// temporary it will be destructed before whatever temporary
comment|/// might be initializing this format.
name|StringRef
name|Format
decl_stmt|;
name|SmallVector
operator|<
name|Value
operator|*
operator|,
literal|4
operator|>
name|Arguments
expr_stmt|;
name|public
label|:
name|LogBuilder
argument_list|(
argument|Consumer&c
argument_list|,
argument|StringRef Format
argument_list|)
block|:
name|consumer
argument_list|(
name|c
argument_list|)
operator|,
name|Format
argument_list|(
argument|Format
argument_list|)
block|{}
name|LogBuilder
operator|&
name|operator
operator|<<
operator|(
name|Value
operator|*
name|V
operator|)
block|{
name|Arguments
operator|.
name|push_back
argument_list|(
name|V
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|LogBuilder
argument_list|()
expr_stmt|;
name|StringRef
name|getFormat
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getNumArguments
argument_list|()
specifier|const
expr_stmt|;
name|Value
modifier|*
name|getArgument
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// A temporary-object class for building up diff messages.
name|class
name|DiffLogBuilder
block|{
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Instruction
operator|*
operator|,
name|Instruction
operator|*
operator|>
name|DiffRecord
expr_stmt|;
name|SmallVector
operator|<
name|DiffRecord
operator|,
literal|20
operator|>
name|Diff
expr_stmt|;
name|Consumer
modifier|&
name|consumer
decl_stmt|;
name|public
label|:
name|DiffLogBuilder
argument_list|(
name|Consumer
operator|&
name|c
argument_list|)
operator|:
name|consumer
argument_list|(
argument|c
argument_list|)
block|{}
operator|~
name|DiffLogBuilder
argument_list|()
expr_stmt|;
name|void
name|addMatch
parameter_list|(
name|Instruction
modifier|*
name|L
parameter_list|,
name|Instruction
modifier|*
name|R
parameter_list|)
function_decl|;
comment|// HACK: VS 2010 has a bug in the stdlib that requires this.
name|void
name|addLeft
parameter_list|(
name|Instruction
modifier|*
name|L
parameter_list|)
function_decl|;
name|void
name|addRight
parameter_list|(
name|Instruction
modifier|*
name|R
parameter_list|)
function_decl|;
name|unsigned
name|getNumLines
argument_list|()
specifier|const
expr_stmt|;
name|DiffChange
name|getLineKind
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
decl_stmt|;
name|Instruction
modifier|*
name|getLeft
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
decl_stmt|;
name|Instruction
modifier|*
name|getRight
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

