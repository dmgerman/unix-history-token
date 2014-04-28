begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EHScopeStack.h - Stack for cleanup IR generation --------*- C++ -*-===//
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
comment|// These classes should be the minimum interface required for other parts of
end_comment

begin_comment
comment|// CodeGen to emit cleanups.  The implementation is in CGCleanup.cpp and other
end_comment

begin_comment
comment|// implemenentation details that are not widely needed are in CGCleanup.h.
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
name|CLANG_CODEGEN_EHSCOPESTACK_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_EHSCOPESTACK_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
comment|/// A branch fixup.  These are required when emitting a goto to a
comment|/// label which hasn't been emitted yet.  The goto is optimistically
comment|/// emitted as a branch to the basic block for the label, and (if it
comment|/// occurs in a scope with non-trivial cleanups) a fixup is added to
comment|/// the innermost cleanup.  When a (normal) cleanup is popped, any
comment|/// unresolved fixups in that scope are threaded through the cleanup.
struct|struct
name|BranchFixup
block|{
comment|/// The block containing the terminator which needs to be modified
comment|/// into a switch if this fixup is resolved into the current scope.
comment|/// If null, LatestBranch points directly to the destination.
name|llvm
operator|::
name|BasicBlock
operator|*
name|OptimisticBranchBlock
expr_stmt|;
comment|/// The ultimate destination of the branch.
comment|///
comment|/// This can be set to null to indicate that this fixup was
comment|/// successfully resolved.
name|llvm
operator|::
name|BasicBlock
operator|*
name|Destination
expr_stmt|;
comment|/// The destination index value.
name|unsigned
name|DestinationIndex
decl_stmt|;
comment|/// The initial branch of the fixup.
name|llvm
operator|::
name|BranchInst
operator|*
name|InitialBranch
expr_stmt|;
block|}
struct|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|InvariantValue
block|{
typedef|typedef
name|T
name|type
typedef|;
typedef|typedef
name|T
name|saved_type
typedef|;
specifier|static
name|bool
name|needsSaving
parameter_list|(
name|type
name|value
parameter_list|)
block|{
return|return
name|false
return|;
block|}
specifier|static
name|saved_type
name|save
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|type
name|value
parameter_list|)
block|{
return|return
name|value
return|;
block|}
specifier|static
name|type
name|restore
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|saved_type
name|value
parameter_list|)
block|{
return|return
name|value
return|;
block|}
block|}
empty_stmt|;
comment|/// A metaprogramming class for ensuring that a value will dominate an
comment|/// arbitrary position in a function.
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|DominatingValue
operator|:
name|InvariantValue
operator|<
name|T
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|,
name|bool
name|mightBeInstruction
operator|=
name|llvm
operator|::
name|is_base_of
operator|<
name|llvm
operator|::
name|Value
operator|,
name|T
operator|>
operator|::
name|value
operator|&&
operator|!
name|llvm
operator|::
name|is_base_of
operator|<
name|llvm
operator|::
name|Constant
operator|,
name|T
operator|>
operator|::
name|value
operator|&&
operator|!
name|llvm
operator|::
name|is_base_of
operator|<
name|llvm
operator|::
name|BasicBlock
operator|,
name|T
operator|>
operator|::
name|value
operator|>
expr|struct
name|DominatingPointer
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|DominatingPointer
operator|<
name|T
operator|,
name|false
operator|>
operator|:
name|InvariantValue
operator|<
name|T
operator|*
operator|>
block|{}
expr_stmt|;
comment|// template<class T> struct DominatingPointer<T,true> at end of file
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|DominatingValue
operator|<
name|T
operator|*
operator|>
operator|:
name|DominatingPointer
operator|<
name|T
operator|>
block|{}
expr_stmt|;
enum|enum
name|CleanupKind
block|{
name|EHCleanup
init|=
literal|0x1
block|,
name|NormalCleanup
init|=
literal|0x2
block|,
name|NormalAndEHCleanup
init|=
name|EHCleanup
operator||
name|NormalCleanup
block|,
name|InactiveCleanup
init|=
literal|0x4
block|,
name|InactiveEHCleanup
init|=
name|EHCleanup
operator||
name|InactiveCleanup
block|,
name|InactiveNormalCleanup
init|=
name|NormalCleanup
operator||
name|InactiveCleanup
block|,
name|InactiveNormalAndEHCleanup
init|=
name|NormalAndEHCleanup
operator||
name|InactiveCleanup
block|}
enum|;
comment|/// A stack of scopes which respond to exceptions, including cleanups
comment|/// and catch blocks.
name|class
name|EHScopeStack
block|{
name|public
label|:
comment|/// A saved depth on the scope stack.  This is necessary because
comment|/// pushing scopes onto the stack invalidates iterators.
name|class
name|stable_iterator
block|{
name|friend
name|class
name|EHScopeStack
decl_stmt|;
comment|/// Offset from StartOfData to EndOfBuffer.
name|ptrdiff_t
name|Size
decl_stmt|;
name|stable_iterator
argument_list|(
argument|ptrdiff_t Size
argument_list|)
block|:
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
name|public
label|:
specifier|static
name|stable_iterator
name|invalid
parameter_list|()
block|{
return|return
name|stable_iterator
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
name|stable_iterator
argument_list|()
operator|:
name|Size
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Size
operator|>=
literal|0
return|;
block|}
comment|/// Returns true if this scope encloses I.
comment|/// Returns false if I is invalid.
comment|/// This scope must be valid.
name|bool
name|encloses
argument_list|(
name|stable_iterator
name|I
argument_list|)
decl|const
block|{
return|return
name|Size
operator|<=
name|I
operator|.
name|Size
return|;
block|}
comment|/// Returns true if this scope strictly encloses I: that is,
comment|/// if it encloses I and is not I.
comment|/// Returns false is I is invalid.
comment|/// This scope must be valid.
name|bool
name|strictlyEncloses
argument_list|(
name|stable_iterator
name|I
argument_list|)
decl|const
block|{
return|return
name|Size
operator|<
name|I
operator|.
name|Size
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|stable_iterator
name|A
operator|,
name|stable_iterator
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Size
operator|==
name|B
operator|.
name|Size
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|stable_iterator
name|A
operator|,
name|stable_iterator
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Size
operator|!=
name|B
operator|.
name|Size
return|;
block|}
block|}
empty_stmt|;
comment|/// Information for lazily generating a cleanup.  Subclasses must be
comment|/// POD-like: cleanups will not be destructed, and they will be
comment|/// allocated on the cleanup stack and freely copied and moved
comment|/// around.
comment|///
comment|/// Cleanup implementations should generally be declared in an
comment|/// anonymous namespace.
name|class
name|Cleanup
block|{
comment|// Anchor the construction vtable.
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
comment|/// Generation flags.
name|class
name|Flags
block|{
enum|enum
block|{
name|F_IsForEH
init|=
literal|0x1
block|,
name|F_IsNormalCleanupKind
init|=
literal|0x2
block|,
name|F_IsEHCleanupKind
init|=
literal|0x4
block|}
enum|;
name|unsigned
name|flags
decl_stmt|;
name|public
label|:
name|Flags
argument_list|()
operator|:
name|flags
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// isForEH - true if the current emission is for an EH cleanup.
name|bool
name|isForEHCleanup
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|F_IsForEH
return|;
block|}
name|bool
name|isForNormalCleanup
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isForEHCleanup
argument_list|()
return|;
block|}
name|void
name|setIsForEHCleanup
parameter_list|()
block|{
name|flags
operator||=
name|F_IsForEH
expr_stmt|;
block|}
name|bool
name|isNormalCleanupKind
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|F_IsNormalCleanupKind
return|;
block|}
name|void
name|setIsNormalCleanupKind
parameter_list|()
block|{
name|flags
operator||=
name|F_IsNormalCleanupKind
expr_stmt|;
block|}
comment|/// isEHCleanupKind - true if the cleanup was pushed as an EH
comment|/// cleanup.
name|bool
name|isEHCleanupKind
argument_list|()
specifier|const
block|{
return|return
name|flags
operator|&
name|F_IsEHCleanupKind
return|;
block|}
name|void
name|setIsEHCleanupKind
parameter_list|()
block|{
name|flags
operator||=
name|F_IsEHCleanupKind
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|// Provide a virtual destructor to suppress a very common warning
comment|// that unfortunately cannot be suppressed without this.  Cleanups
comment|// should not rely on this destructor ever being called.
name|virtual
operator|~
name|Cleanup
argument_list|()
block|{}
comment|/// Emit the cleanup.  For normal cleanups, this is run in the
comment|/// same EH context as when the cleanup was pushed, i.e. the
comment|/// immediately-enclosing context of the cleanup scope.  For
comment|/// EH cleanups, this is run in a terminate context.
comment|///
comment|// \param flags cleanup kind.
name|virtual
name|void
name|Emit
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Flags flags
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// ConditionalCleanupN stores the saved form of its N parameters,
comment|/// then restores them and performs the cleanup.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|>
name|class
name|ConditionalCleanup1
operator|:
name|public
name|Cleanup
block|{
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|A0_saved
expr_stmt|;
name|A0_saved
name|a0_saved
expr_stmt|;
name|void
name|Emit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|Flags
name|flags
parameter_list|)
block|{
name|A0
name|a0
init|=
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a0_saved
argument_list|)
decl_stmt|;
name|T
argument_list|(
name|a0
argument_list|)
operator|.
name|Emit
argument_list|(
name|CGF
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|ConditionalCleanup1
argument_list|(
argument|A0_saved a0
argument_list|)
block|:
name|a0_saved
argument_list|(
argument|a0
argument_list|)
block|{}
block|}
empty_stmt|;
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|>
name|class
name|ConditionalCleanup2
operator|:
name|public
name|Cleanup
block|{
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|A0_saved
expr_stmt|;
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|A1_saved
expr_stmt|;
name|A0_saved
name|a0_saved
decl_stmt|;
name|A1_saved
name|a1_saved
decl_stmt|;
name|void
name|Emit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|Flags
name|flags
parameter_list|)
block|{
name|A0
name|a0
init|=
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a0_saved
argument_list|)
decl_stmt|;
name|A1
name|a1
init|=
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a1_saved
argument_list|)
decl_stmt|;
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|)
operator|.
name|Emit
argument_list|(
name|CGF
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|ConditionalCleanup2
argument_list|(
argument|A0_saved a0
argument_list|,
argument|A1_saved a1
argument_list|)
block|:
name|a0_saved
argument_list|(
name|a0
argument_list|)
operator|,
name|a1_saved
argument_list|(
argument|a1
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|>
name|class
name|ConditionalCleanup3
operator|:
name|public
name|Cleanup
block|{
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|A0_saved
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|A1_saved
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A2
operator|>
operator|::
name|saved_type
name|A2_saved
expr_stmt|;
end_typedef

begin_decl_stmt
name|A0_saved
name|a0_saved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|A1_saved
name|a1_saved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|A2_saved
name|a2_saved
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|Emit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|Flags
name|flags
parameter_list|)
block|{
name|A0
name|a0
init|=
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a0_saved
argument_list|)
decl_stmt|;
name|A1
name|a1
init|=
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a1_saved
argument_list|)
decl_stmt|;
name|A2
name|a2
init|=
name|DominatingValue
operator|<
name|A2
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a2_saved
argument_list|)
decl_stmt|;
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|)
operator|.
name|Emit
argument_list|(
name|CGF
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_macro
name|ConditionalCleanup3
argument_list|(
argument|A0_saved a0
argument_list|,
argument|A1_saved a1
argument_list|,
argument|A2_saved a2
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|a0_saved
argument_list|(
name|a0
argument_list|)
operator|,
name|a1_saved
argument_list|(
name|a1
argument_list|)
operator|,
name|a2_saved
argument_list|(
argument|a2
argument_list|)
block|{}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|,
name|class
name|A3
operator|>
name|class
name|ConditionalCleanup4
operator|:
name|public
name|Cleanup
block|{
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|A0_saved
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|A1_saved
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A2
operator|>
operator|::
name|saved_type
name|A2_saved
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|DominatingValue
operator|<
name|A3
operator|>
operator|::
name|saved_type
name|A3_saved
expr_stmt|;
end_typedef

begin_decl_stmt
name|A0_saved
name|a0_saved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|A1_saved
name|a1_saved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|A2_saved
name|a2_saved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|A3_saved
name|a3_saved
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|Emit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|Flags
name|flags
parameter_list|)
block|{
name|A0
name|a0
init|=
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a0_saved
argument_list|)
decl_stmt|;
name|A1
name|a1
init|=
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a1_saved
argument_list|)
decl_stmt|;
name|A2
name|a2
init|=
name|DominatingValue
operator|<
name|A2
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a2_saved
argument_list|)
decl_stmt|;
name|A3
name|a3
init|=
name|DominatingValue
operator|<
name|A3
operator|>
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|a3_saved
argument_list|)
decl_stmt|;
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
operator|.
name|Emit
argument_list|(
name|CGF
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_macro
name|ConditionalCleanup4
argument_list|(
argument|A0_saved a0
argument_list|,
argument|A1_saved a1
argument_list|,
argument|A2_saved a2
argument_list|,
argument|A3_saved a3
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|a0_saved
argument_list|(
name|a0
argument_list|)
operator|,
name|a1_saved
argument_list|(
name|a1
argument_list|)
operator|,
name|a2_saved
argument_list|(
name|a2
argument_list|)
operator|,
name|a3_saved
argument_list|(
argument|a3
argument_list|)
block|{}
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_comment
comment|// The implementation for this class is in CGException.h and
end_comment

begin_comment
comment|// CGException.cpp; the definition is here because it's used as a
end_comment

begin_comment
comment|// member of CodeGenFunction.
end_comment

begin_comment
comment|/// The start of the scope-stack buffer, i.e. the allocated pointer
end_comment

begin_comment
comment|/// for the buffer.  All of these pointers are either simultaneously
end_comment

begin_comment
comment|/// null or simultaneously valid.
end_comment

begin_decl_stmt
name|char
modifier|*
name|StartOfBuffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The end of the buffer.
end_comment

begin_decl_stmt
name|char
modifier|*
name|EndOfBuffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The first valid entry in the buffer.
end_comment

begin_decl_stmt
name|char
modifier|*
name|StartOfData
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The innermost normal cleanup on the stack.
end_comment

begin_decl_stmt
name|stable_iterator
name|InnermostNormalCleanup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The innermost EH scope on the stack.
end_comment

begin_decl_stmt
name|stable_iterator
name|InnermostEHScope
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The current set of branch fixups.  A branch fixup is a jump to
end_comment

begin_comment
comment|/// an as-yet unemitted label, i.e. a label for which we don't yet
end_comment

begin_comment
comment|/// know the EH stack depth.  Whenever we pop a cleanup, we have
end_comment

begin_comment
comment|/// to thread all the current branch fixups through it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fixups are recorded as the Use of the respective branch or
end_comment

begin_comment
comment|/// switch statement.  The use points to the final destination.
end_comment

begin_comment
comment|/// When popping out of a cleanup, these uses are threaded through
end_comment

begin_comment
comment|/// the cleanup and adjusted to point to the new cleanup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that branches are allowed to jump into protected scopes
end_comment

begin_comment
comment|/// in certain situations;  e.g. the following code is legal:
end_comment

begin_comment
comment|///     struct A { ~A(); }; // trivial ctor, non-trivial dtor
end_comment

begin_comment
comment|///     goto foo;
end_comment

begin_comment
comment|///     A a;
end_comment

begin_comment
comment|///    foo:
end_comment

begin_comment
comment|///     bar();
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|BranchFixup
operator|,
literal|8
operator|>
name|BranchFixups
expr_stmt|;
end_expr_stmt

begin_function_decl
name|char
modifier|*
name|allocate
parameter_list|(
name|size_t
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pushCleanup
parameter_list|(
name|CleanupKind
name|K
parameter_list|,
name|size_t
name|DataSize
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|EHScopeStack
argument_list|()
operator|:
name|StartOfBuffer
argument_list|(
literal|0
argument_list|)
operator|,
name|EndOfBuffer
argument_list|(
literal|0
argument_list|)
operator|,
name|StartOfData
argument_list|(
literal|0
argument_list|)
operator|,
name|InnermostNormalCleanup
argument_list|(
name|stable_end
argument_list|()
argument_list|)
operator|,
name|InnermostEHScope
argument_list|(
argument|stable_end()
argument_list|)
block|{}
operator|~
name|EHScopeStack
argument_list|()
block|{
name|delete
index|[]
name|StartOfBuffer
block|; }
comment|// Variadic templates would make this not terrible.
comment|/// Push a lazily-created cleanup on the stack.
name|template
operator|<
name|class
name|T
operator|>
name|void
name|pushCleanup
argument_list|(
argument|CleanupKind Kind
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|Cleanup
operator|*
name|Obj
operator|=
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|()
block|;
operator|(
name|void
operator|)
name|Obj
block|;   }
comment|/// Push a lazily-created cleanup on the stack.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|>
name|void
name|pushCleanup
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|A0 a0
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|Cleanup
operator|*
name|Obj
operator|=
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|(
name|a0
argument_list|)
block|;
operator|(
name|void
operator|)
name|Obj
block|;   }
comment|/// Push a lazily-created cleanup on the stack.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|>
name|void
name|pushCleanup
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|Cleanup
operator|*
name|Obj
operator|=
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|)
block|;
operator|(
name|void
operator|)
name|Obj
block|;   }
comment|/// Push a lazily-created cleanup on the stack.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|>
name|void
name|pushCleanup
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|Cleanup
operator|*
name|Obj
operator|=
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|)
block|;
operator|(
name|void
operator|)
name|Obj
block|;   }
comment|/// Push a lazily-created cleanup on the stack.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|,
name|class
name|A3
operator|>
name|void
name|pushCleanup
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|,
argument|A3 a3
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|Cleanup
operator|*
name|Obj
operator|=
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
block|;
operator|(
name|void
operator|)
name|Obj
block|;   }
comment|/// Push a lazily-created cleanup on the stack.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|,
name|class
name|A3
operator|,
name|class
name|A4
operator|>
name|void
name|pushCleanup
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|,
argument|A3 a3
argument_list|,
argument|A4 a4
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|Cleanup
operator|*
name|Obj
operator|=
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|)
block|;
operator|(
name|void
operator|)
name|Obj
block|;   }
comment|// Feel free to add more variants of the following:
comment|/// Push a cleanup with non-constant storage requirements on the
comment|/// stack.  The cleanup type must provide an additional static method:
comment|///   static size_t getExtraSize(size_t);
comment|/// The argument to this method will be the value N, which will also
comment|/// be passed as the first argument to the constructor.
comment|///
comment|/// The data stored in the extra storage must obey the same
comment|/// restrictions as normal cleanup member data.
comment|///
comment|/// The pointer returned from this method is valid until the cleanup
comment|/// stack is modified.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|>
name|T
operator|*
name|pushCleanupWithExtra
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|size_t N
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|)
block|{
name|void
operator|*
name|Buffer
operator|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|+
name|T
operator|::
name|getExtraSize
argument_list|(
name|N
argument_list|)
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|Buffer
argument_list|)
name|T
argument_list|(
name|N
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|pushCopyOfCleanup
parameter_list|(
name|CleanupKind
name|Kind
parameter_list|,
specifier|const
name|void
modifier|*
name|Cleanup
parameter_list|,
name|size_t
name|Size
parameter_list|)
block|{
name|void
modifier|*
name|Buffer
init|=
name|pushCleanup
argument_list|(
name|Kind
argument_list|,
name|Size
argument_list|)
decl_stmt|;
name|std
operator|::
name|memcpy
argument_list|(
name|Buffer
argument_list|,
name|Cleanup
argument_list|,
name|Size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Pops a cleanup scope off the stack.  This is private to CGCleanup.cpp.
end_comment

begin_function_decl
name|void
name|popCleanup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Push a set of catch handlers on the stack.  The catch is
end_comment

begin_comment
comment|/// uninitialized and will need to have the given number of handlers
end_comment

begin_comment
comment|/// set on it.
end_comment

begin_function_decl
name|class
name|EHCatchScope
modifier|*
name|pushCatch
parameter_list|(
name|unsigned
name|NumHandlers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Pops a catch scope off the stack.  This is private to CGException.cpp.
end_comment

begin_function_decl
name|void
name|popCatch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Push an exceptions filter on the stack.
end_comment

begin_function_decl
name|class
name|EHFilterScope
modifier|*
name|pushFilter
parameter_list|(
name|unsigned
name|NumFilters
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Pops an exceptions filter off the stack.
end_comment

begin_function_decl
name|void
name|popFilter
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Push a terminate handler on the stack.
end_comment

begin_function_decl
name|void
name|pushTerminate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Pops a terminate handler off the stack.
end_comment

begin_function_decl
name|void
name|popTerminate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Determines whether the exception-scopes stack is empty.
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|StartOfData
operator|==
name|EndOfBuffer
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|requiresLandingPad
argument_list|()
specifier|const
block|{
return|return
name|InnermostEHScope
operator|!=
name|stable_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Determines whether there are any normal cleanups on the stack.
end_comment

begin_expr_stmt
name|bool
name|hasNormalCleanups
argument_list|()
specifier|const
block|{
return|return
name|InnermostNormalCleanup
operator|!=
name|stable_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the innermost normal cleanup on the stack, or
end_comment

begin_comment
comment|/// stable_end() if there are no normal cleanups.
end_comment

begin_expr_stmt
name|stable_iterator
name|getInnermostNormalCleanup
argument_list|()
specifier|const
block|{
return|return
name|InnermostNormalCleanup
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|stable_iterator
name|getInnermostActiveNormalCleanup
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stable_iterator
name|getInnermostEHScope
argument_list|()
specifier|const
block|{
return|return
name|InnermostEHScope
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|stable_iterator
name|getInnermostActiveEHScope
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// An unstable reference to a scope-stack depth.  Invalidated by
end_comment

begin_comment
comment|/// pushes but not pops.
end_comment

begin_decl_stmt
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns an iterator pointing to the innermost EH scope.
end_comment

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns an iterator pointing to the outermost EH scope.
end_comment

begin_expr_stmt
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create a stable reference to the top of the EH stack.  The
end_comment

begin_comment
comment|/// returned reference is valid until that scope is popped off the
end_comment

begin_comment
comment|/// stack.
end_comment

begin_expr_stmt
name|stable_iterator
name|stable_begin
argument_list|()
specifier|const
block|{
return|return
name|stable_iterator
argument_list|(
name|EndOfBuffer
operator|-
name|StartOfData
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Create a stable reference to the bottom of the EH stack.
end_comment

begin_function
specifier|static
name|stable_iterator
name|stable_end
parameter_list|()
block|{
return|return
name|stable_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Translates an iterator into a stable_iterator.
end_comment

begin_decl_stmt
name|stable_iterator
name|stabilize
argument_list|(
name|iterator
name|it
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Turn a stable reference to a scope depth into a unstable pointer
end_comment

begin_comment
comment|/// to the EH stack.
end_comment

begin_decl_stmt
name|iterator
name|find
argument_list|(
name|stable_iterator
name|save
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Removes the cleanup pointed to by the given stable_iterator.
end_comment

begin_function_decl
name|void
name|removeCleanup
parameter_list|(
name|stable_iterator
name|save
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Add a branch fixup to the current cleanup scope.
end_comment

begin_function
name|BranchFixup
modifier|&
name|addBranchFixup
parameter_list|()
block|{
name|assert
argument_list|(
name|hasNormalCleanups
argument_list|()
operator|&&
literal|"adding fixup in scope without cleanups"
argument_list|)
expr_stmt|;
name|BranchFixups
operator|.
name|push_back
argument_list|(
name|BranchFixup
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|BranchFixups
operator|.
name|back
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getNumBranchFixups
argument_list|()
specifier|const
block|{
return|return
name|BranchFixups
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|BranchFixup
modifier|&
name|getBranchFixup
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumBranchFixups
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|BranchFixups
index|[
name|I
index|]
return|;
block|}
end_function

begin_comment
comment|/// Pops lazily-removed fixups from the end of the list.  This
end_comment

begin_comment
comment|/// should only be called by procedures which have just popped a
end_comment

begin_comment
comment|/// cleanup or resolved one or more fixups.
end_comment

begin_function_decl
name|void
name|popNullFixups
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Clears the branch-fixups list.  This should only be called by
end_comment

begin_comment
comment|/// ResolveAllBranchFixups.
end_comment

begin_function
name|void
name|clearFixups
parameter_list|()
block|{
name|BranchFixups
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
unit|};  }
comment|// namespace CodeGen
end_comment

begin_comment
unit|}
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

