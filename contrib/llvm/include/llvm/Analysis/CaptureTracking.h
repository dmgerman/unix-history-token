begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- llvm/Analysis/CaptureTracking.h - Pointer capture ----*- C++ -*-===//
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
comment|// This file contains routines that help determine which pointers are captured.
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
name|LLVM_ANALYSIS_CAPTURETRACKING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CAPTURETRACKING_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Use
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
comment|/// PointerMayBeCaptured - Return true if this pointer value may be captured
comment|/// by the enclosing function (which is required to exist).  This routine can
comment|/// be expensive, so consider caching the results.  The boolean ReturnCaptures
comment|/// specifies whether returning the value (or part of it) from the function
comment|/// counts as capturing it or not.  The boolean StoreCaptures specified
comment|/// whether storing the value (or part of it) into memory anywhere
comment|/// automatically counts as capturing it or not.
name|bool
name|PointerMayBeCaptured
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|bool
name|ReturnCaptures
parameter_list|,
name|bool
name|StoreCaptures
parameter_list|)
function_decl|;
comment|/// PointerMayBeCapturedBefore - Return true if this pointer value may be
comment|/// captured by the enclosing function (which is required to exist). If a
comment|/// DominatorTree is provided, only captures which happen before the given
comment|/// instruction are considered. This routine can be expensive, so consider
comment|/// caching the results.  The boolean ReturnCaptures specifies whether
comment|/// returning the value (or part of it) from the function counts as capturing
comment|/// it or not.  The boolean StoreCaptures specified whether storing the value
comment|/// (or part of it) into memory anywhere automatically counts as capturing it
comment|/// or not. Captures by the provided instruction are considered if the
comment|/// final parameter is true.
name|bool
name|PointerMayBeCapturedBefore
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|bool
name|ReturnCaptures
parameter_list|,
name|bool
name|StoreCaptures
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|bool
name|IncludeI
init|=
name|false
parameter_list|)
function_decl|;
comment|/// This callback is used in conjunction with PointerMayBeCaptured. In
comment|/// addition to the interface here, you'll need to provide your own getters
comment|/// to see whether anything was captured.
struct|struct
name|CaptureTracker
block|{
name|virtual
operator|~
name|CaptureTracker
argument_list|()
expr_stmt|;
comment|/// tooManyUses - The depth of traversal has breached a limit. There may be
comment|/// capturing instructions that will not be passed into captured().
name|virtual
name|void
name|tooManyUses
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// shouldExplore - This is the use of a value derived from the pointer.
comment|/// To prune the search (ie., assume that none of its users could possibly
comment|/// capture) return false. To search it, return true.
comment|///
comment|/// U->getUser() is always an Instruction.
name|virtual
name|bool
name|shouldExplore
parameter_list|(
specifier|const
name|Use
modifier|*
name|U
parameter_list|)
function_decl|;
comment|/// captured - Information about the pointer was captured by the user of
comment|/// use U. Return true to stop the traversal or false to continue looking
comment|/// for more capturing instructions.
name|virtual
name|bool
name|captured
parameter_list|(
specifier|const
name|Use
modifier|*
name|U
parameter_list|)
init|=
literal|0
function_decl|;
block|}
struct|;
comment|/// PointerMayBeCaptured - Visit the value and the values derived from it and
comment|/// find values which appear to be capturing the pointer value. This feeds
comment|/// results into and is controlled by the CaptureTracker object.
name|void
name|PointerMayBeCaptured
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|CaptureTracker
modifier|*
name|Tracker
parameter_list|)
function_decl|;
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

