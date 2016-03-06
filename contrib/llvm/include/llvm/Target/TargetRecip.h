begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- llvm/Target/TargetRecip.h ------------*- C++ -*-===//
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
comment|// This class is used to customize machine-specific reciprocal estimate code
end_comment

begin_comment
comment|// generation in a target-independent way.
end_comment

begin_comment
comment|// If a target does not support operations in this specification, then code
end_comment

begin_comment
comment|// generation will default to using supported operations.
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
name|LLVM_TARGET_TARGETRECIP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETRECIP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|TargetRecip
block|{
name|public
label|:
name|TargetRecip
argument_list|()
expr_stmt|;
comment|/// Initialize all or part of the operations from command-line options or
comment|/// a front end.
name|TargetRecip
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Args
argument_list|)
expr_stmt|;
comment|/// Set whether a particular reciprocal operation is enabled and how many
comment|/// refinement steps are needed when using it. Use "all" to set enablement
comment|/// and refinement steps for all operations.
name|void
name|setDefaults
parameter_list|(
name|StringRef
name|Key
parameter_list|,
name|bool
name|Enable
parameter_list|,
name|unsigned
name|RefSteps
parameter_list|)
function_decl|;
comment|/// Return true if the reciprocal operation has been enabled by default or
comment|/// from the command-line. Return false if the operation has been disabled
comment|/// by default or from the command-line.
name|bool
name|isEnabled
argument_list|(
name|StringRef
name|Key
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the number of iterations necessary to refine the
comment|/// the result of a machine instruction for the given reciprocal operation.
name|unsigned
name|getRefinementSteps
argument_list|(
name|StringRef
name|Key
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TargetRecip
operator|&
name|Other
operator|)
specifier|const
expr_stmt|;
name|private
label|:
enum|enum
block|{
name|Uninitialized
init|=
operator|-
literal|1
block|}
enum|;
struct|struct
name|RecipParams
block|{
name|int8_t
name|Enabled
decl_stmt|;
name|int8_t
name|RefinementSteps
decl_stmt|;
name|RecipParams
argument_list|()
operator|:
name|Enabled
argument_list|(
name|Uninitialized
argument_list|)
operator|,
name|RefinementSteps
argument_list|(
argument|Uninitialized
argument_list|)
block|{}
block|}
struct|;
name|std
operator|::
name|map
operator|<
name|StringRef
operator|,
name|RecipParams
operator|>
name|RecipMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|StringRef
operator|,
name|RecipParams
operator|>
operator|::
name|iterator
name|RecipIter
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|StringRef
operator|,
name|RecipParams
operator|>
operator|::
name|const_iterator
name|ConstRecipIter
expr_stmt|;
name|bool
name|parseGlobalParams
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Arg
argument_list|)
decl_stmt|;
name|void
name|parseIndividualParams
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Args
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

