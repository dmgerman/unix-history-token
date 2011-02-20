begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeGenFunction.h - Per-Function state for LLVM CodeGen -*- C++ -*-===//
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
comment|// This is the internal per-function state used for llvm translation.
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
name|CLANG_CODEGEN_CODEGENFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CODEGENFUNCTION_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenModule.h"
end_include

begin_include
include|#
directive|include
file|"CGBuilder.h"
end_include

begin_include
include|#
directive|include
file|"CGCall.h"
end_include

begin_include
include|#
directive|include
file|"CGValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|SwitchInst
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|APValue
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXTryStmt
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|LabelDecl
decl_stmt|;
name|class
name|EnumConstantDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|FunctionProtoType
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCPropertyImplDecl
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|TargetCodeGenInfo
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|ObjCForCollectionStmt
decl_stmt|;
name|class
name|ObjCAtTryStmt
decl_stmt|;
name|class
name|ObjCAtThrowStmt
decl_stmt|;
name|class
name|ObjCAtSynchronizedStmt
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenTypes
decl_stmt|;
name|class
name|CGDebugInfo
decl_stmt|;
name|class
name|CGFunctionInfo
decl_stmt|;
name|class
name|CGRecordLayout
decl_stmt|;
name|class
name|CGBlockInfo
decl_stmt|;
name|class
name|CGCXXABI
decl_stmt|;
name|class
name|BlockFlags
decl_stmt|;
name|class
name|BlockFieldFlags
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
name|public
label|:
comment|// Anchor the construction vtable.  We use the destructor because
comment|// gcc gives an obnoxious warning if there are virtual methods
comment|// with an accessible non-virtual destructor.  Unfortunately,
comment|// declaring this destructor makes it non-trivial, but there
comment|// doesn't seem to be any other way around this warning.
comment|//
comment|// This destructor will never be called.
name|virtual
operator|~
name|Cleanup
argument_list|()
expr_stmt|;
comment|/// Emit the cleanup.  For normal cleanups, this is run in the
comment|/// same EH context as when the cleanup was pushed, i.e. the
comment|/// immediately-enclosing context of the cleanup scope.  For
comment|/// EH cleanups, this is run in a terminate context.
comment|///
comment|// \param IsForEHCleanup true if this is for an EH cleanup, false
comment|///  if for a normal cleanup.
name|virtual
name|void
name|Emit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|bool
name|IsForEHCleanup
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// UnconditionalCleanupN stores its N parameters and just passes
comment|/// them to the real cleanup function.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|>
name|class
name|UnconditionalCleanup1
operator|:
name|public
name|Cleanup
block|{
name|A0
name|a0
block|;
name|public
operator|:
name|UnconditionalCleanup1
argument_list|(
argument|A0 a0
argument_list|)
operator|:
name|a0
argument_list|(
argument|a0
argument_list|)
block|{}
name|void
name|Emit
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|bool IsForEHCleanup
argument_list|)
block|{
name|T
operator|::
name|Emit
argument_list|(
name|CGF
argument_list|,
name|IsForEHCleanup
argument_list|,
name|a0
argument_list|)
block|;     }
block|}
expr_stmt|;
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
name|UnconditionalCleanup2
operator|:
name|public
name|Cleanup
block|{
name|A0
name|a0
block|;
name|A1
name|a1
block|;
name|public
operator|:
name|UnconditionalCleanup2
argument_list|(
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|)
operator|:
name|a0
argument_list|(
name|a0
argument_list|)
block|,
name|a1
argument_list|(
argument|a1
argument_list|)
block|{}
name|void
name|Emit
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|bool IsForEHCleanup
argument_list|)
block|{
name|T
operator|::
name|Emit
argument_list|(
name|CGF
argument_list|,
name|IsForEHCleanup
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|)
block|;     }
block|}
expr_stmt|;
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
name|bool
name|IsForEHCleanup
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
operator|::
name|Emit
argument_list|(
name|CGF
argument_list|,
name|IsForEHCleanup
argument_list|,
name|a0
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
name|bool
name|IsForEHCleanup
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
operator|::
name|Emit
argument_list|(
name|CGF
argument_list|,
name|IsForEHCleanup
argument_list|,
name|a0
argument_list|,
name|a1
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

begin_label
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
comment|/// The innermost EH cleanup on the stack.
end_comment

begin_decl_stmt
name|stable_iterator
name|InnermostEHCleanup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The number of catches on the stack.
end_comment

begin_decl_stmt
name|unsigned
name|CatchDepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The current EH destination index.  Reset to FirstCatchIndex
end_comment

begin_comment
comment|/// whenever the last EH cleanup is popped.
end_comment

begin_decl_stmt
name|unsigned
name|NextEHDestIndex
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|FirstEHDestIndex
init|=
literal|1
block|}
enum|;
end_enum

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
name|llvm
operator|::
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
name|InnermostEHCleanup
argument_list|(
name|stable_end
argument_list|()
argument_list|)
operator|,
name|CatchDepth
argument_list|(
literal|0
argument_list|)
operator|,
name|NextEHDestIndex
argument_list|(
argument|FirstEHDestIndex
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

begin_comment
comment|/// Pops a cleanup scope off the stack.  This should only be called
end_comment

begin_comment
comment|/// by CodeGenFunction::PopCleanupBlock.
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
comment|/// Pops a catch scope off the stack.
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
operator|(
name|CatchDepth
operator|||
name|hasEHCleanups
argument_list|()
operator|)
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

begin_comment
comment|// CGException.h
end_comment

begin_comment
comment|/// Determines whether there are any EH cleanups on the stack.
end_comment

begin_expr_stmt
name|bool
name|hasEHCleanups
argument_list|()
specifier|const
block|{
return|return
name|InnermostEHCleanup
operator|!=
name|stable_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the innermost EH cleanup on the stack, or stable_end()
end_comment

begin_comment
comment|/// if there are no EH cleanups.
end_comment

begin_expr_stmt
name|stable_iterator
name|getInnermostEHCleanup
argument_list|()
specifier|const
block|{
return|return
name|InnermostEHCleanup
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|stable_iterator
name|getInnermostActiveEHCleanup
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CGException.h
end_comment

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
comment|/// Finds the nearest cleanup enclosing the given iterator.
end_comment

begin_comment
comment|/// Returns stable_iterator::invalid() if there are no such cleanups.
end_comment

begin_decl_stmt
name|stable_iterator
name|getEnclosingEHCleanup
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
comment|/// Gets the next EH destination index.
end_comment

begin_function
name|unsigned
name|getNextEHDestIndex
parameter_list|()
block|{
return|return
name|NextEHDestIndex
operator|++
return|;
block|}
end_function

begin_comment
unit|};
comment|/// CodeGenFunction - This class organizes the per-function state that is used
end_comment

begin_comment
comment|/// while generating LLVM code.
end_comment

begin_decl_stmt
name|class
name|CodeGenFunction
range|:
name|public
name|CodeGenTypeCache
block|{
name|CodeGenFunction
argument_list|(
specifier|const
name|CodeGenFunction
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenFunction
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|CGCXXABI
block|;
name|public
operator|:
comment|/// A jump destination is an abstract label, branching to which may
comment|/// require a jump out through normal cleanups.
expr|struct
name|JumpDest
block|{
name|JumpDest
argument_list|()
operator|:
name|Block
argument_list|(
literal|0
argument_list|)
block|,
name|ScopeDepth
argument_list|()
block|,
name|Index
argument_list|(
literal|0
argument_list|)
block|{}
name|JumpDest
argument_list|(
argument|llvm::BasicBlock *Block
argument_list|,
argument|EHScopeStack::stable_iterator Depth
argument_list|,
argument|unsigned Index
argument_list|)
operator|:
name|Block
argument_list|(
name|Block
argument_list|)
block|,
name|ScopeDepth
argument_list|(
name|Depth
argument_list|)
block|,
name|Index
argument_list|(
argument|Index
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Block
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|BasicBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|Block
return|;
block|}
name|EHScopeStack
operator|::
name|stable_iterator
name|getScopeDepth
argument_list|()
specifier|const
block|{
return|return
name|ScopeDepth
return|;
block|}
name|unsigned
name|getDestIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
name|private
operator|:
name|llvm
operator|::
name|BasicBlock
operator|*
name|Block
block|;
name|EHScopeStack
operator|::
name|stable_iterator
name|ScopeDepth
block|;
name|unsigned
name|Index
block|;   }
block|;
comment|/// An unwind destination is an abstract label, branching to which
comment|/// may require a jump out through EH cleanups.
block|struct
name|UnwindDest
block|{
name|UnwindDest
argument_list|()
operator|:
name|Block
argument_list|(
literal|0
argument_list|)
block|,
name|ScopeDepth
argument_list|()
block|,
name|Index
argument_list|(
literal|0
argument_list|)
block|{}
name|UnwindDest
argument_list|(
argument|llvm::BasicBlock *Block
argument_list|,
argument|EHScopeStack::stable_iterator Depth
argument_list|,
argument|unsigned Index
argument_list|)
operator|:
name|Block
argument_list|(
name|Block
argument_list|)
block|,
name|ScopeDepth
argument_list|(
name|Depth
argument_list|)
block|,
name|Index
argument_list|(
argument|Index
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Block
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|BasicBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|Block
return|;
block|}
name|EHScopeStack
operator|::
name|stable_iterator
name|getScopeDepth
argument_list|()
specifier|const
block|{
return|return
name|ScopeDepth
return|;
block|}
name|unsigned
name|getDestIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
name|private
operator|:
name|llvm
operator|::
name|BasicBlock
operator|*
name|Block
block|;
name|EHScopeStack
operator|::
name|stable_iterator
name|ScopeDepth
block|;
name|unsigned
name|Index
block|;   }
block|;
name|CodeGenModule
operator|&
name|CGM
block|;
comment|// Per-module state.
specifier|const
name|TargetInfo
operator|&
name|Target
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|ComplexPairTy
expr_stmt|;
name|CGBuilderTy
name|Builder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CurFuncDecl - Holds the Decl for the current function or ObjC method.
end_comment

begin_comment
comment|/// This excludes BlockDecls.
end_comment

begin_decl_stmt
specifier|const
name|Decl
modifier|*
name|CurFuncDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CurCodeDecl - This is the inner-most code context, which includes blocks.
end_comment

begin_decl_stmt
specifier|const
name|Decl
modifier|*
name|CurCodeDecl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CGFunctionInfo
modifier|*
name|CurFnInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|QualType
name|FnRetTy
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|CurFn
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CurGD - The GlobalDecl for the current function being compiled.
end_comment

begin_decl_stmt
name|GlobalDecl
name|CurGD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ReturnBlock - Unified return block.
end_comment

begin_decl_stmt
name|JumpDest
name|ReturnBlock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ReturnValue - The temporary alloca to hold the return value. This is null
end_comment

begin_comment
comment|/// iff the function has no return value.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|ReturnValue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// RethrowBlock - Unified rethrow block.
end_comment

begin_decl_stmt
name|UnwindDest
name|RethrowBlock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AllocaInsertPoint - This is an instruction in the entry block before which
end_comment

begin_comment
comment|/// we prefer to insert allocas.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AssertingVH
operator|<
name|llvm
operator|::
name|Instruction
operator|>
name|AllocaInsertPt
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|CatchUndefined
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|CodeGen
operator|::
name|CGBlockInfo
operator|*
name|BlockInfo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BlockPointer
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A mapping from NRVO variables to the flags used to indicate
end_comment

begin_comment
comment|/// when the NRVO has been applied to this variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|NRVOFlags
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|EHScopeStack
name|EHStack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// i32s containing the indexes of the cleanup destinations.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|NormalCleanupDest
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|EHCleanupDest
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NextCleanupDestIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The exception slot.  All landing pads write the current
end_comment

begin_comment
comment|/// exception pointer into this alloca.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|ExceptionSlot
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emits a landing pad for the current EH stack.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|EmitLandingPad
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getInvokeDestImpl
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Set up the last cleaup that was pushed as a conditional
end_comment

begin_comment
comment|/// full-expression cleanup.
end_comment

begin_function_decl
name|void
name|initFullExprCleanup
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|typename
name|DominatingValue
operator|<
name|T
operator|>
operator|::
name|saved_type
name|saveValueInCond
argument_list|(
argument|T value
argument_list|)
block|{
return|return
name|DominatingValue
operator|<
name|T
operator|>
operator|::
name|save
argument_list|(
operator|*
name|this
argument_list|,
name|value
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// ObjCEHValueStack - Stack of Objective-C exception values, used for
end_comment

begin_comment
comment|/// rethrows.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|8
operator|>
name|ObjCEHValueStack
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A struct holding information about a finally block's IR
end_comment

begin_comment
comment|// generation.  For now, doesn't actually hold anything.
end_comment

begin_struct
struct|struct
name|FinallyInfo
block|{   }
struct|;
end_struct

begin_decl_stmt
name|FinallyInfo
name|EnterFinallyBlock
argument_list|(
specifier|const
name|Stmt
operator|*
name|Stmt
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|BeginCatchFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|EndCatchFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|RethrowFn
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ExitFinallyBlock
parameter_list|(
name|FinallyInfo
modifier|&
name|FinallyInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// pushFullExprCleanup - Push a cleanup to be run at the end of the
end_comment

begin_comment
comment|/// current full-expression.  Safe against the possibility that
end_comment

begin_comment
comment|/// we're currently inside a conditionally-evaluated expression.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|>
name|void
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|A0 a0
argument_list|)
block|{
comment|// If we're not in a conditional branch, or if none of the
comment|// arguments requires saving, then use the unconditional cleanup.
if|if
condition|(
operator|!
name|isInConditionalBranch
argument_list|()
condition|)
block|{
typedef|typedef
name|EHScopeStack
operator|::
name|UnconditionalCleanup1
operator|<
name|T
operator|,
name|A0
operator|>
name|CleanupType
expr_stmt|;
return|return
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0
operator|)
return|;
block|}
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|a0_saved
operator|=
name|saveValueInCond
argument_list|(
name|a0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup1
operator|<
name|T
operator|,
name|A0
operator|>
name|CleanupType
expr_stmt|;
end_typedef

begin_expr_stmt
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0_saved
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|initFullExprCleanup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// pushFullExprCleanup - Push a cleanup to be run at the end of the
end_comment

begin_comment
comment|/// current full-expression.  Safe against the possibility that
end_comment

begin_comment
comment|/// we're currently inside a conditionally-evaluated expression.
end_comment

begin_expr_stmt
unit|template
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
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|)
block|{
comment|// If we're not in a conditional branch, or if none of the
comment|// arguments requires saving, then use the unconditional cleanup.
if|if
condition|(
operator|!
name|isInConditionalBranch
argument_list|()
condition|)
block|{
typedef|typedef
name|EHScopeStack
operator|::
name|UnconditionalCleanup2
operator|<
name|T
operator|,
name|A0
operator|,
name|A1
operator|>
name|CleanupType
expr_stmt|;
return|return
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0
operator|,
name|a1
operator|)
return|;
block|}
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|a0_saved
operator|=
name|saveValueInCond
argument_list|(
name|a0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|a1_saved
operator|=
name|saveValueInCond
argument_list|(
name|a1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup2
operator|<
name|T
operator|,
name|A0
operator|,
name|A1
operator|>
name|CleanupType
expr_stmt|;
end_typedef

begin_expr_stmt
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0_saved
operator|,
name|a1_saved
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|initFullExprCleanup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// PushDestructorCleanup - Push a cleanup to call the
end_comment

begin_comment
comment|/// complete-object destructor of an object of the given type at the
end_comment

begin_comment
comment|/// given address.  Does nothing if T is not a C++ class type with a
end_comment

begin_comment
comment|/// non-trivial destructor.
end_comment

begin_macro
unit|void
name|PushDestructorCleanup
argument_list|(
argument|QualType T
argument_list|,
argument|llvm::Value *Addr
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// PushDestructorCleanup - Push a cleanup to call the
end_comment

begin_comment
comment|/// complete-object variant of the given destructor on the object at
end_comment

begin_comment
comment|/// the given address.
end_comment

begin_decl_stmt
name|void
name|PushDestructorCleanup
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|Dtor
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// PopCleanupBlock - Will pop the cleanup entry on the stack and
end_comment

begin_comment
comment|/// process all branch fixups.
end_comment

begin_function_decl
name|void
name|PopCleanupBlock
parameter_list|(
name|bool
name|FallThroughIsBranchThrough
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DeactivateCleanupBlock - Deactivates the given cleanup block.
end_comment

begin_comment
comment|/// The block cannot be reactivated.  Pops it if it's the top of the
end_comment

begin_comment
comment|/// stack.
end_comment

begin_decl_stmt
name|void
name|DeactivateCleanupBlock
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|Cleanup
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ActivateCleanupBlock - Activates an initially-inactive cleanup.
end_comment

begin_comment
comment|/// Cannot be used to resurrect a deactivated cleanup.
end_comment

begin_decl_stmt
name|void
name|ActivateCleanupBlock
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|Cleanup
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Enters a new scope for capturing cleanups, all of which
end_comment

begin_comment
comment|/// will be executed once the scope is exited.
end_comment

begin_decl_stmt
name|class
name|RunCleanupsScope
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|EHScopeStack
operator|::
name|stable_iterator
name|CleanupStackDepth
expr_stmt|;
name|bool
name|OldDidCallStackSave
decl_stmt|;
name|bool
name|PerformCleanup
decl_stmt|;
name|RunCleanupsScope
argument_list|(
specifier|const
name|RunCleanupsScope
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|RunCleanupsScope
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RunCleanupsScope
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
comment|/// \brief Enter a new cleanup scope.
name|explicit
name|RunCleanupsScope
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|PerformCleanup
argument_list|(
argument|true
argument_list|)
block|{
name|CleanupStackDepth
operator|=
name|CGF
operator|.
name|EHStack
operator|.
name|stable_begin
argument_list|()
block|;
name|OldDidCallStackSave
operator|=
name|CGF
operator|.
name|DidCallStackSave
block|;
name|CGF
operator|.
name|DidCallStackSave
operator|=
name|false
block|;     }
comment|/// \brief Exit this cleanup scope, emitting any accumulated
comment|/// cleanups.
operator|~
name|RunCleanupsScope
argument_list|()
block|{
if|if
condition|(
name|PerformCleanup
condition|)
block|{
name|CGF
operator|.
name|DidCallStackSave
operator|=
name|OldDidCallStackSave
expr_stmt|;
name|CGF
operator|.
name|PopCleanupBlocks
argument_list|(
name|CleanupStackDepth
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// \brief Determine whether this scope requires any cleanups.
name|bool
name|requiresCleanups
argument_list|()
specifier|const
block|{
return|return
name|CGF
operator|.
name|EHStack
operator|.
name|stable_begin
argument_list|()
operator|!=
name|CleanupStackDepth
return|;
block|}
comment|/// \brief Force the emission of cleanups now, instead of waiting
comment|/// until this object is destroyed.
name|void
name|ForceCleanup
parameter_list|()
block|{
name|assert
argument_list|(
name|PerformCleanup
operator|&&
literal|"Already forced cleanup"
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|DidCallStackSave
operator|=
name|OldDidCallStackSave
expr_stmt|;
name|CGF
operator|.
name|PopCleanupBlocks
argument_list|(
name|CleanupStackDepth
argument_list|)
expr_stmt|;
name|PerformCleanup
operator|=
name|false
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// PopCleanupBlocks - Takes the old cleanup stack size and emits
end_comment

begin_comment
comment|/// the cleanup blocks that have been added.
end_comment

begin_decl_stmt
name|void
name|PopCleanupBlocks
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|OldCleanupStackSize
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ResolveBranchFixups
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Target
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The given basic block lies in the current EH scope, but may be a
end_comment

begin_comment
comment|/// target of a potentially scope-crossing jump; get a stable handle
end_comment

begin_comment
comment|/// to which we can perform this jump later.
end_comment

begin_decl_stmt
name|JumpDest
name|getJumpDestInCurrentScope
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Target
argument_list|)
block|{
return|return
name|JumpDest
argument_list|(
name|Target
argument_list|,
name|EHStack
operator|.
name|getInnermostNormalCleanup
argument_list|()
argument_list|,
name|NextCleanupDestIndex
operator|++
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// The given basic block lies in the current EH scope, but may be a
end_comment

begin_comment
comment|/// target of a potentially scope-crossing jump; get a stable handle
end_comment

begin_comment
comment|/// to which we can perform this jump later.
end_comment

begin_decl_stmt
name|JumpDest
name|getJumpDestInCurrentScope
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
operator|=
name|llvm
operator|::
name|StringRef
argument_list|()
argument_list|)
block|{
return|return
name|getJumpDestInCurrentScope
argument_list|(
name|createBasicBlock
argument_list|(
name|Name
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// EmitBranchThroughCleanup - Emit a branch from the current insert
end_comment

begin_comment
comment|/// block through the normal cleanup handling code (if any) and then
end_comment

begin_comment
comment|/// on to \arg Dest.
end_comment

begin_function_decl
name|void
name|EmitBranchThroughCleanup
parameter_list|(
name|JumpDest
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitBranchThroughEHCleanup - Emit a branch from the current
end_comment

begin_comment
comment|/// insert block through the EH cleanup handling code (if any) and
end_comment

begin_comment
comment|/// then on to \arg Dest.
end_comment

begin_function_decl
name|void
name|EmitBranchThroughEHCleanup
parameter_list|(
name|UnwindDest
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getRethrowDest - Returns the unified outermost-scope rethrow
end_comment

begin_comment
comment|/// destination.
end_comment

begin_function_decl
name|UnwindDest
name|getRethrowDest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// An object to manage conditionally-evaluated expressions.
end_comment

begin_decl_stmt
name|class
name|ConditionalEvaluation
block|{
name|llvm
operator|::
name|BasicBlock
operator|*
name|StartBB
expr_stmt|;
name|public
label|:
name|ConditionalEvaluation
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|StartBB
argument_list|(
argument|CGF.Builder.GetInsertBlock()
argument_list|)
block|{}
name|void
name|begin
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
name|assert
argument_list|(
name|CGF
operator|.
name|OutermostConditional
operator|!=
name|this
argument_list|)
block|;
if|if
condition|(
operator|!
name|CGF
operator|.
name|OutermostConditional
condition|)
name|CGF
operator|.
name|OutermostConditional
operator|=
name|this
expr_stmt|;
block|}
name|void
name|end
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
name|assert
argument_list|(
name|CGF
operator|.
name|OutermostConditional
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|CGF
operator|.
name|OutermostConditional
operator|==
name|this
condition|)
name|CGF
operator|.
name|OutermostConditional
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Returns a block which will be executed prior to each
comment|/// evaluation of the conditional code.
name|llvm
operator|::
name|BasicBlock
operator|*
name|getStartingBlock
argument_list|()
specifier|const
block|{
return|return
name|StartBB
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// isInConditionalBranch - Return true if we're currently emitting
end_comment

begin_comment
comment|/// one branch or the other of a conditional expression.
end_comment

begin_expr_stmt
name|bool
name|isInConditionalBranch
argument_list|()
specifier|const
block|{
return|return
name|OutermostConditional
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// An RAII object to record that we're evaluating a statement
end_comment

begin_comment
comment|/// expression.
end_comment

begin_decl_stmt
name|class
name|StmtExprEvaluation
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
comment|/// We have to save the outermost conditional: cleanups in a
comment|/// statement expression aren't conditional just because the
comment|/// StmtExpr is.
name|ConditionalEvaluation
modifier|*
name|SavedOutermostConditional
decl_stmt|;
name|public
label|:
name|StmtExprEvaluation
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|SavedOutermostConditional
argument_list|(
argument|CGF.OutermostConditional
argument_list|)
block|{
name|CGF
operator|.
name|OutermostConditional
operator|=
literal|0
block|;     }
operator|~
name|StmtExprEvaluation
argument_list|()
block|{
name|CGF
operator|.
name|OutermostConditional
operator|=
name|SavedOutermostConditional
block|;
name|CGF
operator|.
name|EnsureInsertPoint
argument_list|()
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An object which temporarily prevents a value from being
end_comment

begin_comment
comment|/// destroyed by aggressive peephole optimizations that assume that
end_comment

begin_comment
comment|/// all uses of a value have been realized in the IR.
end_comment

begin_decl_stmt
name|class
name|PeepholeProtection
block|{
name|llvm
operator|::
name|Instruction
operator|*
name|Inst
expr_stmt|;
name|friend
name|class
name|CodeGenFunction
decl_stmt|;
name|public
label|:
name|PeepholeProtection
argument_list|()
operator|:
name|Inst
argument_list|(
literal|0
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An RAII object to set (and then clear) a mapping for an OpaqueValueExpr.
end_comment

begin_decl_stmt
name|class
name|OpaqueValueMapping
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
specifier|const
name|OpaqueValueExpr
modifier|*
name|OpaqueValue
decl_stmt|;
name|bool
name|BoundLValue
decl_stmt|;
name|CodeGenFunction
operator|::
name|PeepholeProtection
name|Protection
expr_stmt|;
name|public
label|:
specifier|static
name|bool
name|shouldBindAsLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|expr
parameter_list|)
block|{
return|return
name|expr
operator|->
name|isGLValue
argument_list|()
operator|||
name|expr
operator|->
name|getType
argument_list|()
operator|->
name|isRecordType
argument_list|()
return|;
block|}
comment|/// Build the opaque value mapping for the given conditional
comment|/// operator if it's the GNU ?: extension.  This is a common
comment|/// enough pattern that the convenience operator is really
comment|/// helpful.
comment|///
name|OpaqueValueMapping
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|AbstractConditionalOperator
operator|*
name|op
argument_list|)
operator|:
name|CGF
argument_list|(
argument|CGF
argument_list|)
block|{
if|if
condition|(
name|isa
operator|<
name|ConditionalOperator
operator|>
operator|(
name|op
operator|)
condition|)
block|{
name|OpaqueValue
operator|=
literal|0
expr_stmt|;
name|BoundLValue
operator|=
name|false
expr_stmt|;
return|return;
block|}
specifier|const
name|BinaryConditionalOperator
modifier|*
name|e
init|=
name|cast
operator|<
name|BinaryConditionalOperator
operator|>
operator|(
name|op
operator|)
decl_stmt|;
name|init
argument_list|(
name|e
operator|->
name|getOpaqueValue
argument_list|()
argument_list|,
name|e
operator|->
name|getCommon
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_macro
name|OpaqueValueMapping
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const OpaqueValueExpr *opaqueValue
argument_list|,
argument|LValue lvalue
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|OpaqueValue
argument_list|(
name|opaqueValue
argument_list|)
operator|,
name|BoundLValue
argument_list|(
argument|true
argument_list|)
block|{
name|assert
argument_list|(
name|opaqueValue
operator|&&
literal|"no opaque value expression!"
argument_list|)
block|;
name|assert
argument_list|(
name|shouldBindAsLValue
argument_list|(
name|opaqueValue
argument_list|)
argument_list|)
block|;
name|initLValue
argument_list|(
name|lvalue
argument_list|)
block|;     }
name|OpaqueValueMapping
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const OpaqueValueExpr *opaqueValue
argument_list|,
argument|RValue rvalue
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|OpaqueValue
argument_list|(
name|opaqueValue
argument_list|)
operator|,
name|BoundLValue
argument_list|(
argument|false
argument_list|)
block|{
name|assert
argument_list|(
name|opaqueValue
operator|&&
literal|"no opaque value expression!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|shouldBindAsLValue
argument_list|(
name|opaqueValue
argument_list|)
argument_list|)
block|;
name|initRValue
argument_list|(
name|rvalue
argument_list|)
block|;     }
name|void
name|pop
argument_list|()
block|{
name|assert
argument_list|(
name|OpaqueValue
operator|&&
literal|"mapping already popped!"
argument_list|)
block|;
name|popImpl
argument_list|()
block|;
name|OpaqueValue
operator|=
literal|0
block|;     }
operator|~
name|OpaqueValueMapping
argument_list|()
block|{
if|if
condition|(
name|OpaqueValue
condition|)
name|popImpl
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function
name|void
name|popImpl
parameter_list|()
block|{
if|if
condition|(
name|BoundLValue
condition|)
name|CGF
operator|.
name|OpaqueLValues
operator|.
name|erase
argument_list|(
name|OpaqueValue
argument_list|)
expr_stmt|;
else|else
block|{
name|CGF
operator|.
name|OpaqueRValues
operator|.
name|erase
argument_list|(
name|OpaqueValue
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|unprotectFromPeepholes
argument_list|(
name|Protection
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|init
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|ov
parameter_list|,
specifier|const
name|Expr
modifier|*
name|e
parameter_list|)
block|{
name|OpaqueValue
operator|=
name|ov
expr_stmt|;
name|BoundLValue
operator|=
name|shouldBindAsLValue
argument_list|(
name|ov
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|BoundLValue
operator|==
name|shouldBindAsLValue
argument_list|(
name|e
argument_list|)
operator|&&
literal|"inconsistent expression value kinds!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|BoundLValue
condition|)
name|initLValue
argument_list|(
name|CGF
operator|.
name|EmitLValue
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|initRValue
argument_list|(
name|CGF
operator|.
name|EmitAnyExpr
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|initLValue
parameter_list|(
specifier|const
name|LValue
modifier|&
name|lv
parameter_list|)
block|{
name|CGF
operator|.
name|OpaqueLValues
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|OpaqueValue
argument_list|,
name|lv
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|initRValue
parameter_list|(
specifier|const
name|RValue
modifier|&
name|rv
parameter_list|)
block|{
comment|// Work around an extremely aggressive peephole optimization in
comment|// EmitScalarConversion which assumes that all other uses of a
comment|// value are extant.
name|Protection
operator|=
name|CGF
operator|.
name|protectFromPeepholes
argument_list|(
name|rv
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|OpaqueRValues
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|OpaqueValue
argument_list|,
name|rv
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/// getByrefValueFieldNumber - Given a declaration, returns the LLVM field
end_comment

begin_comment
comment|/// number that holds the value.
end_comment

begin_decl_stmt
name|unsigned
name|getByRefValueLLVMField
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|VD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// BuildBlockByrefAddress - Computes address location of the
end_comment

begin_comment
comment|/// variable which is declared as __block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildBlockByrefAddress
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|BaseAddr
argument_list|,
specifier|const
name|VarDecl
operator|*
name|V
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|CGDebugInfo
modifier|*
name|DebugInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// IndirectBranch - The first time an indirect goto is seen we create a block
end_comment

begin_comment
comment|/// with an indirect branch.  Every time we see the address of a label taken,
end_comment

begin_comment
comment|/// we add the label to the indirect goto.  Every subsequent indirect goto is
end_comment

begin_comment
comment|/// codegen'd as a jump to the IndirectBranch's basic block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|IndirectBrInst
operator|*
name|IndirectBranch
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// LocalDeclMap - This keeps track of the LLVM allocas or globals for local C
end_comment

begin_comment
comment|/// decls.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|DeclMapTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|DeclMapTy
name|LocalDeclMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LabelMap - This keeps track of the LLVM basic block for each C label.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|LabelDecl
operator|*
operator|,
name|JumpDest
operator|>
name|LabelMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|// BreakContinueStack - This keeps track of where break and continue
end_comment

begin_comment
comment|// statements should jump to.
end_comment

begin_struct
struct|struct
name|BreakContinue
block|{
name|BreakContinue
argument_list|(
argument|JumpDest Break
argument_list|,
argument|JumpDest Continue
argument_list|)
block|:
name|BreakBlock
argument_list|(
name|Break
argument_list|)
operator|,
name|ContinueBlock
argument_list|(
argument|Continue
argument_list|)
block|{}
name|JumpDest
name|BreakBlock
expr_stmt|;
name|JumpDest
name|ContinueBlock
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|BreakContinue
operator|,
literal|8
operator|>
name|BreakContinueStack
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SwitchInsn - This is nearest current switch instruction. It is null if if
end_comment

begin_comment
comment|/// current context is not in a switch.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SwitchInst
operator|*
name|SwitchInsn
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CaseRangeBlock - This block holds if condition check for last case
end_comment

begin_comment
comment|/// statement range in current switch instruction.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|CaseRangeBlock
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// OpaqueLValues - Keeps track of the current set of opaque value
end_comment

begin_comment
comment|/// expressions.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|LValue
operator|>
name|OpaqueLValues
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|RValue
operator|>
name|OpaqueRValues
expr_stmt|;
end_expr_stmt

begin_comment
comment|// VLASizeMap - This keeps track of the associated size for each VLA type.
end_comment

begin_comment
comment|// We track this by the size expression rather than the type itself because
end_comment

begin_comment
comment|// in certain situations, like a const qualifier applied to an VLA typedef,
end_comment

begin_comment
comment|// multiple VLA types can share the same size expression.
end_comment

begin_comment
comment|// FIXME: Maybe this could be a stack of maps that is pushed/popped as we
end_comment

begin_comment
comment|// enter/leave scopes.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Expr
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|VLASizeMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// DidCallStackSave - Whether llvm.stacksave has been called. Used to avoid
end_comment

begin_comment
comment|/// calling llvm.stacksave for multiple VLAs in the same scope.
end_comment

begin_decl_stmt
name|bool
name|DidCallStackSave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A block containing a single 'unreachable' instruction.  Created
end_comment

begin_comment
comment|/// lazily by getUnreachableBlock().
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|UnreachableBlock
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CXXThisDecl - When generating code for a C++ member function,
end_comment

begin_comment
comment|/// this will hold the implicit 'this' declaration.
end_comment

begin_decl_stmt
name|ImplicitParamDecl
modifier|*
name|CXXThisDecl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|CXXThisValue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CXXVTTDecl - When generating code for a base object constructor or
end_comment

begin_comment
comment|/// base object destructor with virtual bases, this will hold the implicit
end_comment

begin_comment
comment|/// VTT parameter.
end_comment

begin_decl_stmt
name|ImplicitParamDecl
modifier|*
name|CXXVTTDecl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|CXXVTTValue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// OutermostConditional - Points to the outermost active
end_comment

begin_comment
comment|/// conditional control.  This is used so that we know if a
end_comment

begin_comment
comment|/// temporary should be destroyed conditionally.
end_comment

begin_decl_stmt
name|ConditionalEvaluation
modifier|*
name|OutermostConditional
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ByrefValueInfoMap - For each __block variable, contains a pair of the LLVM
end_comment

begin_comment
comment|/// type as well as the field number that contains the actual data.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ValueDecl
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
specifier|const
name|llvm
operator|::
name|Type
operator|*
operator|,
name|unsigned
operator|>
expr|>
name|ByRefValueInfo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|TerminateLandingPad
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|TerminateHandler
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|TrapBB
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|CodeGenFunction
argument_list|(
name|CodeGenModule
operator|&
name|cgm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CodeGenTypes
operator|&
name|getTypes
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getTypes
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|CGDebugInfo
modifier|*
name|getDebugInfo
parameter_list|()
block|{
return|return
name|DebugInfo
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|LangOptions
operator|&
name|getLangOptions
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getLangOptions
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns a pointer to the function's exception object slot, which
end_comment

begin_comment
comment|/// is assigned in every landing pad.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getExceptionSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getNormalCleanupDestSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getEHCleanupDestSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getUnreachableBlock
argument_list|()
block|{
if|if
condition|(
operator|!
name|UnreachableBlock
condition|)
block|{
name|UnreachableBlock
operator|=
name|createBasicBlock
argument_list|(
literal|"unreachable"
argument_list|)
expr_stmt|;
name|new
name|llvm
operator|::
name|UnreachableInst
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
name|UnreachableBlock
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|UnreachableBlock
return|;
end_return

begin_expr_stmt
unit|}    llvm
operator|::
name|BasicBlock
operator|*
name|getInvokeDest
argument_list|()
block|{
if|if
condition|(
operator|!
name|EHStack
operator|.
name|requiresLandingPad
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getInvokeDestImpl
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    llvm
operator|::
name|LLVMContext
operator|&
name|getLLVMContext
argument_list|()
block|{
return|return
name|CGM
operator|.
name|getLLVMContext
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Objective-C
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_function_decl
name|void
name|GenerateObjCMethod
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|OMD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StartObjCMethod
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
specifier|const
name|ObjCContainerDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GenerateObjCGetter - Synthesize an Objective-C property getter function.
end_comment

begin_function_decl
name|void
name|GenerateObjCGetter
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|IMP
parameter_list|,
specifier|const
name|ObjCPropertyImplDecl
modifier|*
name|PID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GenerateObjCGetterBody
parameter_list|(
name|ObjCIvarDecl
modifier|*
name|Ivar
parameter_list|,
name|bool
name|IsAtomic
parameter_list|,
name|bool
name|IsStrong
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GenerateObjCAtomicSetterBody
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|OMD
parameter_list|,
name|ObjCIvarDecl
modifier|*
name|Ivar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GenerateObjCCtorDtorMethod
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|IMP
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
name|bool
name|ctor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GenerateObjCSetter - Synthesize an Objective-C property setter function
end_comment

begin_comment
comment|/// for the given property.
end_comment

begin_function_decl
name|void
name|GenerateObjCSetter
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|IMP
parameter_list|,
specifier|const
name|ObjCPropertyImplDecl
modifier|*
name|PID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IndirectObjCSetterArg
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IvarTypeWithAggrGCObjects
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Block Bits
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitBlockLiteral
argument_list|(
specifier|const
name|BlockExpr
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|BuildDescriptorBlockDecl
argument_list|(
specifier|const
name|BlockExpr
operator|*
argument_list|,
specifier|const
name|CGBlockInfo
operator|&
name|Info
argument_list|,
specifier|const
name|llvm
operator|::
name|StructType
operator|*
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|BlockVarLayout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateBlockFunction
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|const CGBlockInfo&Info
argument_list|,
argument|const Decl *OuterFuncDecl
argument_list|,
argument|const DeclMapTy&ldm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateCopyHelperFunction
argument_list|(
specifier|const
name|CGBlockInfo
operator|&
name|blockInfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateDestroyHelperFunction
argument_list|(
specifier|const
name|CGBlockInfo
operator|&
name|blockInfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GeneratebyrefCopyHelperFunction
argument_list|(
argument|const llvm::Type *
argument_list|,
argument|BlockFieldFlags flags
argument_list|,
argument|const VarDecl *BD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GeneratebyrefDestroyHelperFunction
argument_list|(
argument|const llvm::Type *T
argument_list|,
argument|BlockFieldFlags flags
argument_list|,
argument|const VarDecl *BD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|BuildBlockRelease
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DeclPtr
argument_list|,
name|BlockFieldFlags
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadBlockStruct
argument_list|()
block|{
name|assert
argument_list|(
name|BlockPointer
operator|&&
literal|"no block pointer set!"
argument_list|)
block|;
return|return
name|BlockPointer
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|AllocateBlockCXXThisPointer
parameter_list|(
specifier|const
name|CXXThisExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AllocateBlockDecl
parameter_list|(
specifier|const
name|BlockDeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfBlockDecl
argument_list|(
argument|const BlockDeclRefExpr *E
argument_list|)
block|{
return|return
name|GetAddrOfBlockDecl
argument_list|(
name|E
operator|->
name|getDecl
argument_list|()
argument_list|,
name|E
operator|->
name|isByRef
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfBlockDecl
argument_list|(
argument|const VarDecl *var
argument_list|,
argument|bool ByRef
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|BuildByRefType
argument_list|(
specifier|const
name|VarDecl
operator|*
name|var
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|GenerateCode
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|StartFunction
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|QualType
name|RetTy
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|FunctionArgList
operator|&
name|Args
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitConstructorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDestructorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitFunctionBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitReturnBlock - Emit the unified return block, trying to avoid its
end_comment

begin_comment
comment|/// emission when possible.
end_comment

begin_function_decl
name|void
name|EmitReturnBlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// FinishFunction - Complete IR generation of the current function. It is
end_comment

begin_comment
comment|/// legal to call this function even if there is no current insertion point.
end_comment

begin_function_decl
name|void
name|FinishFunction
parameter_list|(
name|SourceLocation
name|EndLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GenerateThunk - Generate a thunk for the given method.
end_comment

begin_decl_stmt
name|void
name|GenerateThunk
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|GlobalDecl
name|GD
argument_list|,
specifier|const
name|ThunkInfo
operator|&
name|Thunk
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitCtorPrologue
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|,
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// InitializeVTablePointer - Initialize the vtable pointer of the given
end_comment

begin_comment
comment|/// subobject.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|InitializeVTablePointer
argument_list|(
name|BaseSubobject
name|Base
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|NearestVBase
argument_list|,
name|uint64_t
name|OffsetFromNearestVBase
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|VTable
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|VTableClass
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|4
operator|>
name|VisitedVirtualBasesSetTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|void
name|InitializeVTablePointers
argument_list|(
name|BaseSubobject
name|Base
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|NearestVBase
argument_list|,
name|uint64_t
name|OffsetFromNearestVBase
argument_list|,
name|bool
name|BaseIsNonVirtualPrimaryBase
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|VTable
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|VTableClass
argument_list|,
name|VisitedVirtualBasesSetTy
operator|&
name|VBases
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|InitializeVTablePointers
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetVTablePtr - Return the Value of the vtable pointer member pointed
end_comment

begin_comment
comment|/// to by This.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetVTablePtr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EnterDtorCleanups - Enter the cleanups necessary to complete the
end_comment

begin_comment
comment|/// given phase of destruction for a destructor.  The end result
end_comment

begin_comment
comment|/// should call destructors on members and base classes in reverse
end_comment

begin_comment
comment|/// order of their construction.
end_comment

begin_function_decl
name|void
name|EnterDtorCleanups
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|Dtor
parameter_list|,
name|CXXDtorType
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ShouldInstrumentFunction - Return true if the current function should be
end_comment

begin_comment
comment|/// instrumented with __cyg_profile_func_* calls
end_comment

begin_function_decl
name|bool
name|ShouldInstrumentFunction
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitFunctionInstrumentation - Emit LLVM code to call the specified
end_comment

begin_comment
comment|/// instrumentation function with the current function and the call site, if
end_comment

begin_comment
comment|/// function instrumentation is enabled.
end_comment

begin_function_decl
name|void
name|EmitFunctionInstrumentation
parameter_list|(
specifier|const
name|char
modifier|*
name|Fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitMCountInstrumentation - Emit call to .mcount.
end_comment

begin_function_decl
name|void
name|EmitMCountInstrumentation
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitFunctionProlog - Emit the target specific LLVM code to load the
end_comment

begin_comment
comment|/// arguments for the given function. This is also responsible for naming the
end_comment

begin_comment
comment|/// LLVM function arguments.
end_comment

begin_decl_stmt
name|void
name|EmitFunctionProlog
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|FI
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|FunctionArgList
operator|&
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitFunctionEpilog - Emit the target specific LLVM code to return the
end_comment

begin_comment
comment|/// given temporary.
end_comment

begin_function_decl
name|void
name|EmitFunctionEpilog
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStartEHSpec - Emit the start of the exception spec.
end_comment

begin_function_decl
name|void
name|EmitStartEHSpec
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitEndEHSpec - Emit the end of the exception spec.
end_comment

begin_function_decl
name|void
name|EmitEndEHSpec
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getTerminateLandingPad - Return a landing pad that just calls terminate.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTerminateLandingPad
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getTerminateHandler - Return a handler (not a landing pad, just
end_comment

begin_comment
comment|/// a catch handler) that just calls terminate.  This is used when
end_comment

begin_comment
comment|/// a terminate scope encloses a try.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTerminateHandler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeForMem
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|const TypeDecl *T
argument_list|)
block|{
return|return
name|ConvertType
argument_list|(
name|getContext
argument_list|()
operator|.
name|getTypeDeclType
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// LoadObjCSelf - Load the value of self. This function is only valid while
end_comment

begin_comment
comment|/// generating code for an Objective-C method.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadObjCSelf
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// TypeOfSelfObject - Return type of object that this self represents.
end_comment

begin_function_decl
name|QualType
name|TypeOfSelfObject
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// hasAggregateLLVMType - Return true if the specified AST type will map into
end_comment

begin_comment
comment|/// an aggregate LLVM type or is void.
end_comment

begin_function_decl
specifier|static
name|bool
name|hasAggregateLLVMType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// createBasicBlock - Create an LLVM basic block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|createBasicBlock
argument_list|(
argument|llvm::StringRef name =
literal|""
argument_list|,
argument|llvm::Function *parent =
literal|0
argument_list|,
argument|llvm::BasicBlock *before =
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|NDEBUG
return|return
name|llvm
operator|::
name|BasicBlock
operator|::
name|Create
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
literal|""
argument_list|,
name|parent
argument_list|,
name|before
argument_list|)
return|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_return
return|return
name|llvm
operator|::
name|BasicBlock
operator|::
name|Create
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
name|name
argument_list|,
name|parent
argument_list|,
name|before
argument_list|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/// getBasicBlockForLabel - Return the LLVM basicblock that the specified
end_comment

begin_comment
comment|/// label maps to.
end_comment

begin_expr_stmt
unit|JumpDest
name|getJumpDestForLabel
argument_list|(
specifier|const
name|LabelDecl
operator|*
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SimplifyForwardingBlocks - If the given basic block is only a branch to
end_comment

begin_comment
comment|/// another basic block, simplify it. This assumes that no other code could
end_comment

begin_comment
comment|/// potentially reference the basic block.
end_comment

begin_decl_stmt
name|void
name|SimplifyForwardingBlocks
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitBlock - Emit the given block \arg BB and set it as the insert point,
end_comment

begin_comment
comment|/// adding a fall-through branch from the current insert block if
end_comment

begin_comment
comment|/// necessary. It is legal to call this function even if there is no current
end_comment

begin_comment
comment|/// insertion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IsFinished - If true, indicates that the caller has finished emitting
end_comment

begin_comment
comment|/// branches to the given block and does not expect to emit code into it. This
end_comment

begin_comment
comment|/// means the block can be ignored if it is unreachable.
end_comment

begin_decl_stmt
name|void
name|EmitBlock
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|,
name|bool
name|IsFinished
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitBranch - Emit a branch to the specified basic block from the current
end_comment

begin_comment
comment|/// insert block, taking care to avoid creation of branches from dummy
end_comment

begin_comment
comment|/// blocks. It is legal to call this function even if there is no current
end_comment

begin_comment
comment|/// insertion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function clears the current insertion point. The caller should follow
end_comment

begin_comment
comment|/// calls to this function with calls to Emit*Block prior to generation new
end_comment

begin_comment
comment|/// code.
end_comment

begin_decl_stmt
name|void
name|EmitBranch
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Block
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// HaveInsertPoint - True if an insertion point is defined. If not, this
end_comment

begin_comment
comment|/// indicates that the current code being emitted is unreachable.
end_comment

begin_expr_stmt
name|bool
name|HaveInsertPoint
argument_list|()
specifier|const
block|{
return|return
name|Builder
operator|.
name|GetInsertBlock
argument_list|()
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// EnsureInsertPoint - Ensure that an insertion point is defined so that
end_comment

begin_comment
comment|/// emitted IR has a place to go. Note that by definition, if this function
end_comment

begin_comment
comment|/// creates a block then that block is unreachable; callers may do better to
end_comment

begin_comment
comment|/// detect when no insertion point is defined and simply skip IR generation.
end_comment

begin_function
name|void
name|EnsureInsertPoint
parameter_list|()
block|{
if|if
condition|(
operator|!
name|HaveInsertPoint
argument_list|()
condition|)
name|EmitBlock
argument_list|(
name|createBasicBlock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
end_comment

begin_comment
comment|/// specified stmt yet.
end_comment

begin_function_decl
name|void
name|ErrorUnsupported
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
specifier|const
name|char
modifier|*
name|Type
parameter_list|,
name|bool
name|OmitOnError
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Helpers
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|LValue
name|MakeAddrLValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
name|QualType
name|T
argument_list|,
name|unsigned
name|Alignment
operator|=
literal|0
argument_list|)
block|{
return|return
name|LValue
operator|::
name|MakeAddr
argument_list|(
name|V
argument_list|,
name|T
argument_list|,
name|Alignment
argument_list|,
name|getContext
argument_list|()
argument_list|,
name|CGM
operator|.
name|getTBAAInfo
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// CreateTempAlloca - This creates a alloca and inserts it into the entry
end_comment

begin_comment
comment|/// block. The caller is responsible for setting an appropriate alignment on
end_comment

begin_comment
comment|/// the alloca.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateTempAlloca
argument_list|(
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|Name
operator|=
literal|"tmp"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// InitTempAlloca - Provide an initial value for the given alloca.
end_comment

begin_decl_stmt
name|void
name|InitTempAlloca
argument_list|(
name|llvm
operator|::
name|AllocaInst
operator|*
name|Alloca
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Value
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CreateIRTemp - Create a temporary IR object of the given type, with
end_comment

begin_comment
comment|/// appropriate alignment. This routine should only be used when an temporary
end_comment

begin_comment
comment|/// value needs to be stored into an alloca (for example, to avoid explicit
end_comment

begin_comment
comment|/// PHI construction), but the type is the IR type, not the type appropriate
end_comment

begin_comment
comment|/// for storing in memory.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateIRTemp
argument_list|(
argument|QualType T
argument_list|,
argument|const llvm::Twine&Name =
literal|"tmp"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CreateMemTemp - Create a temporary memory object of the given type, with
end_comment

begin_comment
comment|/// appropriate alignment.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateMemTemp
argument_list|(
argument|QualType T
argument_list|,
argument|const llvm::Twine&Name =
literal|"tmp"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CreateAggTemp - Create a temporary memory object for the given
end_comment

begin_comment
comment|/// aggregate type.
end_comment

begin_decl_stmt
name|AggValueSlot
name|CreateAggTemp
argument_list|(
name|QualType
name|T
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|Name
operator|=
literal|"tmp"
argument_list|)
block|{
return|return
name|AggValueSlot
operator|::
name|forAddr
argument_list|(
name|CreateMemTemp
argument_list|(
name|T
argument_list|,
name|Name
argument_list|)
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Emit a cast to void* in the appropriate address space.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCastToVoidPtr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EvaluateExprAsBool - Perform the usual unary conversions on the specified
end_comment

begin_comment
comment|/// expression and compare the result against zero, returning an Int1Ty value.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EvaluateExprAsBool
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitIgnoredExpr - Emit an expression in a context which ignores the result.
end_comment

begin_function_decl
name|void
name|EmitIgnoredExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAnyExpr - Emit code to compute the specified expression which can have
end_comment

begin_comment
comment|/// any type.  The result is returned as an RValue struct.  If this is an
end_comment

begin_comment
comment|/// aggregate expression, the aggloc/agglocvolatile arguments indicate where
end_comment

begin_comment
comment|/// the result should be returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IgnoreResult - True if the resulting value isn't used.
end_comment

begin_function_decl
name|RValue
name|EmitAnyExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|AggSlot
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|,
name|bool
name|IgnoreResult
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// EmitVAListRef - Emit a "reference" to a va_list; this is either the address
end_comment

begin_comment
comment|// or the value of the expression, depending on how va_list is defined.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVAListRef
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitAnyExprToTemp - Similary to EmitAnyExpr(), however, the result will
end_comment

begin_comment
comment|/// always be accessible even if no aggregate location is provided.
end_comment

begin_function_decl
name|RValue
name|EmitAnyExprToTemp
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitsAnyExprToMem - Emits the code necessary to evaluate an
end_comment

begin_comment
comment|/// arbitrary expression into the given memory location.
end_comment

begin_decl_stmt
name|void
name|EmitAnyExprToMem
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Location
argument_list|,
name|bool
name|IsLocationVolatile
argument_list|,
name|bool
name|IsInitializer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitAggregateCopy - Emit an aggrate copy.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param isVolatile - True iff either the source or the destination is
end_comment

begin_comment
comment|/// volatile.
end_comment

begin_decl_stmt
name|void
name|EmitAggregateCopy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcPtr
argument_list|,
name|QualType
name|EltTy
argument_list|,
name|bool
name|isVolatile
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// StartBlock - Start new block named N. If insert block is a dummy block
end_comment

begin_comment
comment|/// then reuse it.
end_comment

begin_function_decl
name|void
name|StartBlock
parameter_list|(
specifier|const
name|char
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetAddrOfStaticLocalVar - Return the address of a static local variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfStaticLocalVar
argument_list|(
argument|const VarDecl *BVD
argument_list|)
block|{
return|return
name|cast
operator|<
name|llvm
operator|::
name|Constant
operator|>
operator|(
name|GetAddrOfLocalVar
argument_list|(
name|BVD
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// GetAddrOfLocalVar - Return the address of a local variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfLocalVar
argument_list|(
argument|const VarDecl *VD
argument_list|)
block|{
name|llvm
operator|::
name|Value
operator|*
name|Res
operator|=
name|LocalDeclMap
index|[
name|VD
index|]
block|;
name|assert
argument_list|(
name|Res
operator|&&
literal|"Invalid argument to GetAddrOfLocalVar(), no decl!"
argument_list|)
block|;
return|return
name|Res
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOpaqueLValueMapping - Given an opaque value expression (which
end_comment

begin_comment
comment|/// must be mapped to an l-value), return its mapping.
end_comment

begin_function
specifier|const
name|LValue
modifier|&
name|getOpaqueLValueMapping
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
block|{
name|assert
argument_list|(
name|OpaqueValueMapping
operator|::
name|shouldBindAsLValue
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|LValue
operator|>
operator|::
name|iterator
name|it
operator|=
name|OpaqueLValues
operator|.
name|find
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|it
operator|!=
name|OpaqueLValues
operator|.
name|end
argument_list|()
operator|&&
literal|"no mapping for opaque value!"
argument_list|)
expr_stmt|;
return|return
name|it
operator|->
name|second
return|;
block|}
end_function

begin_comment
comment|/// getOpaqueRValueMapping - Given an opaque value expression (which
end_comment

begin_comment
comment|/// must be mapped to an r-value), return its mapping.
end_comment

begin_function
specifier|const
name|RValue
modifier|&
name|getOpaqueRValueMapping
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|OpaqueValueMapping
operator|::
name|shouldBindAsLValue
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|RValue
operator|>
operator|::
name|iterator
name|it
operator|=
name|OpaqueRValues
operator|.
name|find
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|it
operator|!=
name|OpaqueRValues
operator|.
name|end
argument_list|()
operator|&&
literal|"no mapping for opaque value!"
argument_list|)
expr_stmt|;
return|return
name|it
operator|->
name|second
return|;
block|}
end_function

begin_comment
comment|/// getAccessedFieldNo - Given an encoded value and a result number, return
end_comment

begin_comment
comment|/// the input field number being accessed.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|getAccessedFieldNo
argument_list|(
name|unsigned
name|Idx
argument_list|,
specifier|const
name|llvm
operator|::
name|Constant
operator|*
name|Elts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|BlockAddress
operator|*
name|GetAddrOfLabel
argument_list|(
specifier|const
name|LabelDecl
operator|*
name|L
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|GetIndirectGotoBlock
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitNullInitialization - Generate code to set a value of the given type to
end_comment

begin_comment
comment|/// null, If the type contains data member pointers, they will be initialized
end_comment

begin_comment
comment|/// to -1 in accordance with the Itanium C++ ABI.
end_comment

begin_decl_stmt
name|void
name|EmitNullInitialization
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// EmitVAArg - Generate code to get an argument from the passed in pointer
end_comment

begin_comment
comment|// and update it accordingly. The return value is a pointer to the argument.
end_comment

begin_comment
comment|// FIXME: We should be able to get rid of this method and use the va_arg
end_comment

begin_comment
comment|// instruction in LLVM instead once it works well enough.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVAArg
argument_list|(
argument|llvm::Value *VAListAddr
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitVLASize - Generate code for any VLA size expressions that might occur
end_comment

begin_comment
comment|/// in a variably modified type. If Ty is a VLA, will return the value that
end_comment

begin_comment
comment|/// corresponds to the size in bytes of the VLA type. Will return 0 otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVLASize
argument_list|(
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// GetVLASize - Returns an LLVM value that corresponds to the size in bytes
end_comment

begin_comment
comment|// of a variable length array type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetVLASize
argument_list|(
specifier|const
name|VariableArrayType
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// LoadCXXThis - Load the value of 'this'. This function is only valid while
end_comment

begin_comment
comment|/// generating code for an C++ member function.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadCXXThis
argument_list|()
block|{
name|assert
argument_list|(
name|CXXThisValue
operator|&&
literal|"no 'this' value for this function"
argument_list|)
block|;
return|return
name|CXXThisValue
return|;
block|}
end_expr_stmt

begin_comment
comment|/// LoadCXXVTT - Load the VTT parameter to base constructors/destructors have
end_comment

begin_comment
comment|/// virtual bases.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadCXXVTT
argument_list|()
block|{
name|assert
argument_list|(
name|CXXVTTValue
operator|&&
literal|"no VTT value for this function"
argument_list|)
block|;
return|return
name|CXXVTTValue
return|;
block|}
end_expr_stmt

begin_comment
comment|/// GetAddressOfBaseOfCompleteClass - Convert the given pointer to a
end_comment

begin_comment
comment|/// complete class to the given direct base.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddressOfDirectBaseInCompleteClass
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|const CXXRecordDecl *Derived
argument_list|,
argument|const CXXRecordDecl *Base
argument_list|,
argument|bool BaseIsVirtual
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddressOfBaseClass - This function will add the necessary delta to the
end_comment

begin_comment
comment|/// load of 'this' and returns address of the base class.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddressOfBaseClass
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|const CXXRecordDecl *Derived
argument_list|,
argument|CastExpr::path_const_iterator PathBegin
argument_list|,
argument|CastExpr::path_const_iterator PathEnd
argument_list|,
argument|bool NullCheckValue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddressOfDerivedClass
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|const CXXRecordDecl *Derived
argument_list|,
argument|CastExpr::path_const_iterator PathBegin
argument_list|,
argument|CastExpr::path_const_iterator PathEnd
argument_list|,
argument|bool NullCheckValue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetVirtualBaseClassOffset
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|ClassDecl
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EmitDelegateCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|Ctor
parameter_list|,
name|CXXCtorType
name|CtorType
parameter_list|,
specifier|const
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitCXXConstructorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
name|CXXCtorType
name|Type
argument_list|,
name|bool
name|ForVirtualBase
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitSynthesizedCXXCopyCtorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Src
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrConstructorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
specifier|const
name|ConstantArrayType
operator|*
name|ArrayTy
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ArrayPtr
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|,
name|bool
name|ZeroInitialization
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrConstructorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ArrayPtr
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|,
name|bool
name|ZeroInitialization
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
specifier|const
name|ArrayType
operator|*
name|Array
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateCXXAggrDestructorHelper
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
specifier|const
name|ArrayType
operator|*
name|Array
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitCXXDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
name|CXXDtorType
name|Type
argument_list|,
name|bool
name|ForVirtualBase
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitNewArrayInitializer
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NewPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXTemporary
argument_list|(
specifier|const
name|CXXTemporary
operator|*
name|Temporary
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCXXNewExpr
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EmitCXXDeleteExpr
parameter_list|(
specifier|const
name|CXXDeleteExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitDeleteCall
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|DeleteFD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|,
name|QualType
name|DeleteTy
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCXXTypeidExpr
argument_list|(
specifier|const
name|CXXTypeidExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitDynamicCast
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|CXXDynamicCastExpr
operator|*
name|DCE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitCheck
argument_list|(
name|llvm
operator|::
name|Value
operator|*
argument_list|,
name|unsigned
name|Size
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarPrePostIncDec
argument_list|(
argument|const UnaryOperator *E
argument_list|,
argument|LValue LV
argument_list|,
argument|bool isInc
argument_list|,
argument|bool isPre
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ComplexPairTy
name|EmitComplexPrePostIncDec
parameter_list|(
specifier|const
name|UnaryOperator
modifier|*
name|E
parameter_list|,
name|LValue
name|LV
parameter_list|,
name|bool
name|isInc
parameter_list|,
name|bool
name|isPre
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                            Declaration Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// EmitDecl - Emit a declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitDecl
parameter_list|(
specifier|const
name|Decl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitVarDecl - Emit a local variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
name|SpecialInitFn
argument_list|(
name|CodeGenFunction
operator|&
name|Init
argument_list|,
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Address
argument_list|)
typedef|;
end_typedef

begin_comment
comment|/// EmitAutoVarDecl - Emit an auto variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitAutoVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|,
name|SpecialInitFn
modifier|*
name|SpecialInit
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitStaticVarDecl
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|Linkage
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitParmDecl - Emit a ParmVarDecl or an ImplicitParamDecl.
end_comment

begin_decl_stmt
name|void
name|EmitParmDecl
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Arg
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// protectFromPeepholes - Protect a value that we're intending to
end_comment

begin_comment
comment|/// store to the side, but which will probably be used later, from
end_comment

begin_comment
comment|/// aggressive peepholing optimizations that might delete it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pass the result to unprotectFromPeepholes to declare that
end_comment

begin_comment
comment|/// protection is no longer required.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There's no particular reason why this shouldn't apply to
end_comment

begin_comment
comment|/// l-values, it's just that no existing peepholes work on pointers.
end_comment

begin_function_decl
name|PeepholeProtection
name|protectFromPeepholes
parameter_list|(
name|RValue
name|rvalue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unprotectFromPeepholes
parameter_list|(
name|PeepholeProtection
name|protection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                             Statement Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// EmitStopPoint - Emit a debug stoppoint if we are emitting debug info.
end_comment

begin_function_decl
name|void
name|EmitStopPoint
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStmt - Emit the code for the statement \arg S. It is legal to call
end_comment

begin_comment
comment|/// this function even if there is no current insertion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function may clear the current insertion point; callers should use
end_comment

begin_comment
comment|/// EnsureInsertPoint if they wish to subsequently generate code without first
end_comment

begin_comment
comment|/// calling EmitBlock, EmitBranch, or EmitStmt.
end_comment

begin_function_decl
name|void
name|EmitStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitSimpleStmt - Try to emit a "simple" statement which does not
end_comment

begin_comment
comment|/// necessarily require an insertion point or debug information; typically
end_comment

begin_comment
comment|/// because the statement amounts to a jump or a container of other
end_comment

begin_comment
comment|/// statements.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return True if the statement was handled.
end_comment

begin_function_decl
name|bool
name|EmitSimpleStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitCompoundStmt
parameter_list|(
specifier|const
name|CompoundStmt
modifier|&
name|S
parameter_list|,
name|bool
name|GetLast
init|=
name|false
parameter_list|,
name|AggValueSlot
name|AVS
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLabel - Emit the block for the given label. It is legal to call this
end_comment

begin_comment
comment|/// function even if there is no current insertion point.
end_comment

begin_function_decl
name|void
name|EmitLabel
parameter_list|(
specifier|const
name|LabelDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// helper for EmitLabelStmt.
end_comment

begin_function_decl
name|void
name|EmitLabelStmt
parameter_list|(
specifier|const
name|LabelStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitGotoStmt
parameter_list|(
specifier|const
name|GotoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitIndirectGotoStmt
parameter_list|(
specifier|const
name|IndirectGotoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitIfStmt
parameter_list|(
specifier|const
name|IfStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitWhileStmt
parameter_list|(
specifier|const
name|WhileStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDoStmt
parameter_list|(
specifier|const
name|DoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitForStmt
parameter_list|(
specifier|const
name|ForStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitReturnStmt
parameter_list|(
specifier|const
name|ReturnStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDeclStmt
parameter_list|(
specifier|const
name|DeclStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitBreakStmt
parameter_list|(
specifier|const
name|BreakStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitContinueStmt
parameter_list|(
specifier|const
name|ContinueStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitSwitchStmt
parameter_list|(
specifier|const
name|SwitchStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDefaultStmt
parameter_list|(
specifier|const
name|DefaultStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCaseStmt
parameter_list|(
specifier|const
name|CaseStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCaseStmtRange
parameter_list|(
specifier|const
name|CaseStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAsmStmt
parameter_list|(
specifier|const
name|AsmStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCForCollectionStmt
parameter_list|(
specifier|const
name|ObjCForCollectionStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAtTryStmt
parameter_list|(
specifier|const
name|ObjCAtTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAtThrowStmt
parameter_list|(
specifier|const
name|ObjCAtThrowStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAtSynchronizedStmt
parameter_list|(
specifier|const
name|ObjCAtSynchronizedStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getUnwindResumeOrRethrowFn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EnterCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|,
name|bool
name|IsFnTryBlock
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExitCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|,
name|bool
name|IsFnTryBlock
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         LValue Expression Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// GetUndefRValue - Get an appropriate 'undef' rvalue for the given type.
end_comment

begin_function_decl
name|RValue
name|GetUndefRValue
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitUnsupportedRValue - Emit a dummy r-value using the type of E
end_comment

begin_comment
comment|/// and issue an ErrorUnsupported style diagnostic (using the
end_comment

begin_comment
comment|/// provided Name).
end_comment

begin_function_decl
name|RValue
name|EmitUnsupportedRValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitUnsupportedLValue - Emit a dummy l-value using the type of E and issue
end_comment

begin_comment
comment|/// an ErrorUnsupported style diagnostic (using the provided Name).
end_comment

begin_function_decl
name|LValue
name|EmitUnsupportedLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLValue - Emit code to compute a designator that specifies the location
end_comment

begin_comment
comment|/// of the expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can return one of two things: a simple address or a bitfield
end_comment

begin_comment
comment|/// reference.  In either case, the LLVM Value* in the LValue structure is
end_comment

begin_comment
comment|/// guaranteed to be an LLVM pointer type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this returns a bitfield reference, nothing about the pointee type of
end_comment

begin_comment
comment|/// the LLVM value is known: For example, it may not be a pointer to an
end_comment

begin_comment
comment|/// integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this returns a normal address, and if the lvalue's C type is fixed
end_comment

begin_comment
comment|/// size, this method guarantees that the returned pointer type will point to
end_comment

begin_comment
comment|/// an LLVM type of the same size of the lvalue's type.  If the lvalue has a
end_comment

begin_comment
comment|/// variable length type, this is not possible.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|LValue
name|EmitLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCheckedLValue - Same as EmitLValue but additionally we generate
end_comment

begin_comment
comment|/// checking code to guard against undefined behavior.  This is only
end_comment

begin_comment
comment|/// suitable when we know that the address will be used to access the
end_comment

begin_comment
comment|/// object.
end_comment

begin_function_decl
name|LValue
name|EmitCheckedLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitToMemory - Change a scalar value from its value
end_comment

begin_comment
comment|/// representation to its in-memory representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitToMemory
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitFromMemory - Change a scalar value from its memory
end_comment

begin_comment
comment|/// representation to its value representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitFromMemory
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitLoadOfScalar - Load a scalar value from an address, taking
end_comment

begin_comment
comment|/// care to appropriately convert from the memory representation to
end_comment

begin_comment
comment|/// the LLVM value representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitLoadOfScalar
argument_list|(
argument|llvm::Value *Addr
argument_list|,
argument|bool Volatile
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|QualType Ty
argument_list|,
argument|llvm::MDNode *TBAAInfo =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitStoreOfScalar - Store a scalar value to an address, taking
end_comment

begin_comment
comment|/// care to appropriately convert from the memory representation to
end_comment

begin_comment
comment|/// the LLVM value representation.
end_comment

begin_decl_stmt
name|void
name|EmitStoreOfScalar
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Value
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Addr
argument_list|,
name|bool
name|Volatile
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|QualType
name|Ty
argument_list|,
name|llvm
operator|::
name|MDNode
operator|*
name|TBAAInfo
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitLoadOfLValue - Given an expression that represents a value lvalue,
end_comment

begin_comment
comment|/// this method emits the address of the lvalue, then loads the result as an
end_comment

begin_comment
comment|/// rvalue, returning the rvalue.
end_comment

begin_function_decl
name|RValue
name|EmitLoadOfLValue
parameter_list|(
name|LValue
name|V
parameter_list|,
name|QualType
name|LVType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfExtVectorElementLValue
parameter_list|(
name|LValue
name|V
parameter_list|,
name|QualType
name|LVType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfBitfieldLValue
parameter_list|(
name|LValue
name|LV
parameter_list|,
name|QualType
name|ExprType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfPropertyRefLValue
parameter_list|(
name|LValue
name|LV
parameter_list|,
name|ReturnValueSlot
name|Return
init|=
name|ReturnValueSlot
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStoreThroughLValue - Store the specified rvalue into the specified
end_comment

begin_comment
comment|/// lvalue, where both are guaranteed to the have the same type, and that type
end_comment

begin_comment
comment|/// is 'Ty'.
end_comment

begin_function_decl
name|void
name|EmitStoreThroughLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitStoreThroughExtVectorComponentLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitStoreThroughPropertyRefLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStoreThroughLValue - Store Src into Dst with same constraints as
end_comment

begin_comment
comment|/// EmitStoreThroughLValue.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Result [out] - If non-null, this will be set to a Value* for the
end_comment

begin_comment
comment|/// bit-field contents after the store, appropriate for use as the result of
end_comment

begin_comment
comment|/// an assignment to the bit-field.
end_comment

begin_decl_stmt
name|void
name|EmitStoreThroughBitfieldLValue
argument_list|(
name|RValue
name|Src
argument_list|,
name|LValue
name|Dst
argument_list|,
name|QualType
name|Ty
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|*
name|Result
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit an l-value for an assignment (simple or compound) of complex type.
end_comment

begin_function_decl
name|LValue
name|EmitComplexAssignmentLValue
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitComplexCompoundAssignmentLValue
parameter_list|(
specifier|const
name|CompoundAssignOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note: only availabe for agg return types
end_comment

begin_function_decl
name|LValue
name|EmitBinaryOperatorLValue
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCompoundAssignmentLValue
parameter_list|(
specifier|const
name|CompoundAssignOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note: only available for agg return types
end_comment

begin_function_decl
name|LValue
name|EmitCallExprLValue
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note: only available for agg return types
end_comment

begin_function_decl
name|LValue
name|EmitVAArgExprLValue
parameter_list|(
specifier|const
name|VAArgExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitDeclRefLValue
parameter_list|(
specifier|const
name|DeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitStringLiteralLValue
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCEncodeExprLValue
parameter_list|(
specifier|const
name|ObjCEncodeExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitPredefinedLValue
parameter_list|(
specifier|const
name|PredefinedExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitUnaryOpLValue
parameter_list|(
specifier|const
name|UnaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitArraySubscriptExpr
parameter_list|(
specifier|const
name|ArraySubscriptExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitExtVectorElementExpr
parameter_list|(
specifier|const
name|ExtVectorElementExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitMemberExpr
parameter_list|(
specifier|const
name|MemberExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCIsaExpr
parameter_list|(
specifier|const
name|ObjCIsaExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCompoundLiteralLValue
parameter_list|(
specifier|const
name|CompoundLiteralExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitConditionalOperatorLValue
parameter_list|(
specifier|const
name|AbstractConditionalOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCastLValue
parameter_list|(
specifier|const
name|CastExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitNullInitializationLValue
parameter_list|(
specifier|const
name|CXXScalarValueInitExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitOpaqueValueLValue
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitIvarOffset
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|Interface
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LValue
name|EmitLValueForAnonRecordField
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|IndirectFieldDecl
operator|*
name|Field
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LValue
name|EmitLValueForField
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitLValueForFieldInitialization - Like EmitLValueForField, except that
end_comment

begin_comment
comment|/// if the Field is a reference, this will return the address of the reference
end_comment

begin_comment
comment|/// and not the address of the value stored in the reference.
end_comment

begin_decl_stmt
name|LValue
name|EmitLValueForFieldInitialization
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LValue
name|EmitLValueForIvar
argument_list|(
name|QualType
name|ObjectTy
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LValue
name|EmitLValueForBitfield
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LValue
name|EmitBlockDeclRefLValue
parameter_list|(
specifier|const
name|BlockDeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCXXConstructLValue
parameter_list|(
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCXXBindTemporaryLValue
parameter_list|(
specifier|const
name|CXXBindTemporaryExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitExprWithCleanupsLValue
parameter_list|(
specifier|const
name|ExprWithCleanups
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCXXTypeidLValue
parameter_list|(
specifier|const
name|CXXTypeidExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCMessageExprLValue
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCIvarRefLValue
parameter_list|(
specifier|const
name|ObjCIvarRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCPropertyRefLValue
parameter_list|(
specifier|const
name|ObjCPropertyRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitStmtExprLValue
parameter_list|(
specifier|const
name|StmtExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitPointerToDataMemberBinaryExpr
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCSelectorLValue
parameter_list|(
specifier|const
name|ObjCSelectorExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitDeclRefExprDbgValue
argument_list|(
specifier|const
name|DeclRefExpr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Init
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         Scalar Expression Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// EmitCall - Generate a call of the given function, expecting the given
end_comment

begin_comment
comment|/// result type, and using the given argument list which specifies both the
end_comment

begin_comment
comment|/// LLVM arguments and the types they were derived from.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TargetDecl - If given, the decl of the function in a direct call;
end_comment

begin_comment
comment|/// used to set attributes on the call (noreturn, etc.).
end_comment

begin_decl_stmt
name|RValue
name|EmitCall
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
specifier|const
name|CallArgList
operator|&
name|Args
argument_list|,
specifier|const
name|Decl
operator|*
name|TargetDecl
operator|=
literal|0
argument_list|,
name|llvm
operator|::
name|Instruction
operator|*
operator|*
name|callOrInvoke
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RValue
name|EmitCall
argument_list|(
name|QualType
name|FnType
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|,
specifier|const
name|Decl
operator|*
name|TargetDecl
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RValue
name|EmitCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
init|=
name|ReturnValueSlot
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|CallSite
name|EmitCallOrInvoke
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|llvm
operator|::
name|Value
operator|*
specifier|const
operator|*
name|ArgBegin
argument_list|,
name|llvm
operator|::
name|Value
operator|*
specifier|const
operator|*
name|ArgEnd
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildVirtualCall
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildVirtualCall
argument_list|(
argument|const CXXDestructorDecl *DD
argument_list|,
argument|CXXDtorType Type
argument_list|,
argument|llvm::Value *This
argument_list|,
argument|const llvm::Type *Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildAppleKextVirtualCall
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|NestedNameSpecifier
operator|*
name|Qual
argument_list|,
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildAppleKextVirtualDestructorCall
argument_list|(
argument|const CXXDestructorDecl *DD
argument_list|,
argument|CXXDtorType Type
argument_list|,
argument|const CXXRecordDecl *RD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|RValue
name|EmitCXXMemberCall
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|VTT
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RValue
name|EmitCXXMemberCallExpr
parameter_list|(
specifier|const
name|CXXMemberCallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitCXXMemberPointerCallExpr
parameter_list|(
specifier|const
name|CXXMemberCallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitCXXOperatorMemberCallExpr
parameter_list|(
specifier|const
name|CXXOperatorCallExpr
modifier|*
name|E
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitBuiltinExpr
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|unsigned
name|BuiltinID
parameter_list|,
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitBlockCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitTargetBuiltinExpr - Emit the given builtin call. Returns 0 if the call
end_comment

begin_comment
comment|/// is unhandled by the current target.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitTargetBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARMBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonCall
argument_list|(
argument|llvm::Function *F
argument_list|,
argument|llvm::SmallVectorImpl<llvm::Value*>&O
argument_list|,
argument|const char *name
argument_list|,
argument|unsigned shift =
literal|0
argument_list|,
argument|bool rightshift = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonSplat
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonShiftVector
argument_list|(
argument|llvm::Value *V
argument_list|,
argument|const llvm::Type *Ty
argument_list|,
argument|bool negateForRightShift
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildVector
argument_list|(
specifier|const
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|Ops
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitX86BuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitPPCBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCProtocolExpr
argument_list|(
specifier|const
name|ObjCProtocolExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCStringLiteral
argument_list|(
specifier|const
name|ObjCStringLiteral
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCSelectorExpr
argument_list|(
specifier|const
name|ObjCSelectorExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|RValue
name|EmitObjCMessageExpr
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|Return
init|=
name|ReturnValueSlot
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitReferenceBindingToExpr - Emits a reference binding to the passed in
end_comment

begin_comment
comment|/// expression. Will emit a temporary variable if E is not an LValue.
end_comment

begin_function_decl
name|RValue
name|EmitReferenceBindingToExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|InitializedDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                           Expression Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Expressions are broken into three classes: scalar, complex, aggregate.
end_comment

begin_comment
comment|/// EmitScalarExpr - Emit the computation of the specified expression of LLVM
end_comment

begin_comment
comment|/// scalar type, returning the result.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarExpr
argument_list|(
argument|const Expr *E
argument_list|,
argument|bool IgnoreResultAssign = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitScalarConversion - Emit a conversion from the specified type to the
end_comment

begin_comment
comment|/// specified destination type, both of which are LLVM scalar types.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarConversion
argument_list|(
argument|llvm::Value *Src
argument_list|,
argument|QualType SrcTy
argument_list|,
argument|QualType DstTy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitComplexToScalarConversion - Emit a conversion from the specified
end_comment

begin_comment
comment|/// complex type to the specified destination type, where the destination type
end_comment

begin_comment
comment|/// is an LLVM scalar type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitComplexToScalarConversion
argument_list|(
argument|ComplexPairTy Src
argument_list|,
argument|QualType SrcTy
argument_list|,
argument|QualType DstTy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitAggExpr - Emit the computation of the specified expression
end_comment

begin_comment
comment|/// of aggregate type.  The result is computed into the given slot,
end_comment

begin_comment
comment|/// which may be null to indicate that the value is not needed.
end_comment

begin_function_decl
name|void
name|EmitAggExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|AS
parameter_list|,
name|bool
name|IgnoreResult
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAggExprToLValue - Emit the computation of the specified expression of
end_comment

begin_comment
comment|/// aggregate type into a temporary LValue.
end_comment

begin_function_decl
name|LValue
name|EmitAggExprToLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitGCMemmoveCollectable - Emit special API for structs with object
end_comment

begin_comment
comment|/// pointers.
end_comment

begin_decl_stmt
name|void
name|EmitGCMemmoveCollectable
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcPtr
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitComplexExpr - Emit the computation of the specified expression of
end_comment

begin_comment
comment|/// complex type, returning the result.
end_comment

begin_function_decl
name|ComplexPairTy
name|EmitComplexExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|bool
name|IgnoreReal
init|=
name|false
parameter_list|,
name|bool
name|IgnoreImag
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitComplexExprIntoAddr - Emit the computation of the specified expression
end_comment

begin_comment
comment|/// of complex type, storing into the specified Value*.
end_comment

begin_decl_stmt
name|void
name|EmitComplexExprIntoAddr
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|DestAddr
argument_list|,
name|bool
name|DestIsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// StoreComplexToAddr - Store a complex number into the specified address.
end_comment

begin_decl_stmt
name|void
name|StoreComplexToAddr
argument_list|(
name|ComplexPairTy
name|V
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|DestAddr
argument_list|,
name|bool
name|DestIsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LoadComplexFromAddr - Load a complex number from the specified address.
end_comment

begin_decl_stmt
name|ComplexPairTy
name|LoadComplexFromAddr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|SrcAddr
argument_list|,
name|bool
name|SrcIsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CreateStaticVarDecl - Create a zero-initialized LLVM global for
end_comment

begin_comment
comment|/// a static local variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|CreateStaticVarDecl
argument_list|(
argument|const VarDecl&D
argument_list|,
argument|const char *Separator
argument_list|,
argument|llvm::GlobalValue::LinkageTypes Linkage
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// AddInitializerToStaticVarDecl - Add the initializer for 'D' to the
end_comment

begin_comment
comment|/// global variable that has already been created for it.  If the initializer
end_comment

begin_comment
comment|/// has a different type than GV does, this may free GV and return a different
end_comment

begin_comment
comment|/// one.  Otherwise it just returns GV.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|AddInitializerToStaticVarDecl
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitCXXGlobalVarDeclInit - Create the initializer for a C++
end_comment

begin_comment
comment|/// variable with global storage.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGlobalVarDeclInit
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|DeclPtr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitCXXGlobalDtorRegistration - Emits a call to register the global ptr
end_comment

begin_comment
comment|/// with the C++ runtime so that its destructor will be called at exit.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGlobalDtorRegistration
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|DtorFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|DeclPtr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit code in this function to perform a guarded variable
end_comment

begin_comment
comment|/// initialization.  Guarded initializations are used when it's not
end_comment

begin_comment
comment|/// possible to prove that an initialization will be done exactly
end_comment

begin_comment
comment|/// once, e.g. with a static local variable or a static data member
end_comment

begin_comment
comment|/// of a class template.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGuardedInit
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|DeclPtr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GenerateCXXGlobalInitFunc - Generates code for initializing global
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|void
name|GenerateCXXGlobalInitFunc
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|*
name|Decls
argument_list|,
name|unsigned
name|NumDecls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GenerateCXXGlobalDtorFunc - Generates code for destroying global
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|void
name|GenerateCXXGlobalDtorFunc
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|WeakVH
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
expr|>
operator|&
name|DtorsAndObjects
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|GenerateCXXGlobalVarDeclInitFunc
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|Addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitCXXConstructExpr
parameter_list|(
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitSynthesizedCXXCopyCtor
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Dest
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Src
argument_list|,
specifier|const
name|Expr
operator|*
name|Exp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RValue
name|EmitExprWithCleanups
parameter_list|(
specifier|const
name|ExprWithCleanups
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|Slot
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXThrowExpr
parameter_list|(
specifier|const
name|CXXThrowExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                             Internal Helpers
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// ContainsLabel - Return true if the statement contains a label in it.  If
end_comment

begin_comment
comment|/// this statement is not executed normally, it not containing a label means
end_comment

begin_comment
comment|/// that we can just remove the code.
end_comment

begin_function_decl
specifier|static
name|bool
name|ContainsLabel
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|bool
name|IgnoreCaseStmts
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ConstantFoldsToSimpleInteger - If the specified expression does not fold
end_comment

begin_comment
comment|/// to a constant, or if it does but contains a label, return 0.  If it
end_comment

begin_comment
comment|/// constant folds to 'true' and does not contain a label, return 1, if it
end_comment

begin_comment
comment|/// constant folds to 'false' and does not contain a label, return -1.
end_comment

begin_function_decl
name|int
name|ConstantFoldsToSimpleInteger
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Cond
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitBranchOnBoolExpr - Emit a branch on a boolean condition (e.g. for an
end_comment

begin_comment
comment|/// if statement) to the specified blocks.  Based on the condition, this might
end_comment

begin_comment
comment|/// try to simplify the codegen of the conditional based on the branch.
end_comment

begin_decl_stmt
name|void
name|EmitBranchOnBoolExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|Cond
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|TrueBlock
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|FalseBlock
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getTrapBB - Create a basic block that will call the trap intrinsic.  We'll
end_comment

begin_comment
comment|/// generate a branch around the created basic block as necessary.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTrapBB
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitCallArg - Emit a single call argument.
end_comment

begin_function_decl
name|RValue
name|EmitCallArg
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|QualType
name|ArgType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitDelegateCallArg - We are performing a delegate call; that
end_comment

begin_comment
comment|/// is, the current function is delegating to another one.  Produce
end_comment

begin_comment
comment|/// a r-value suitable for passing the given parameter.
end_comment

begin_function_decl
name|RValue
name|EmitDelegateCallArg
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Param
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|EmitReturnOfRValue
parameter_list|(
name|RValue
name|RV
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ExpandTypeFromArgs - Reconstruct a structure of type \arg Ty
end_comment

begin_comment
comment|/// from function arguments into \arg Dst. See ABIArgInfo::Expand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AI - The first function argument of the expansion.
end_comment

begin_comment
comment|/// \return The argument following the last expanded function
end_comment

begin_comment
comment|/// argument.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|::
name|arg_iterator
name|ExpandTypeFromArgs
argument_list|(
argument|QualType Ty
argument_list|,
argument|LValue Dst
argument_list|,
argument|llvm::Function::arg_iterator AI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ExpandTypeToArgs - Expand an RValue \arg Src, with the LLVM type for \arg
end_comment

begin_comment
comment|/// Ty, into individual arguments on the provided vector \arg Args. See
end_comment

begin_comment
comment|/// ABIArgInfo::Expand.
end_comment

begin_decl_stmt
name|void
name|ExpandTypeToArgs
argument_list|(
name|QualType
name|Ty
argument_list|,
name|RValue
name|Src
argument_list|,
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|Value
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAsmInput
argument_list|(
specifier|const
name|AsmStmt
operator|&
name|S
argument_list|,
specifier|const
name|TargetInfo
operator|::
name|ConstraintInfo
operator|&
name|Info
argument_list|,
specifier|const
name|Expr
operator|*
name|InputExpr
argument_list|,
name|std
operator|::
name|string
operator|&
name|ConstraintStr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAsmInputLValue
argument_list|(
argument|const AsmStmt&S
argument_list|,
argument|const TargetInfo::ConstraintInfo&Info
argument_list|,
argument|LValue InputValue
argument_list|,
argument|QualType InputType
argument_list|,
argument|std::string&ConstraintStr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitCallArgs - Emit call arguments for a function.
end_comment

begin_comment
comment|/// The CallArgTypeInfo parameter is used for iterating over the known
end_comment

begin_comment
comment|/// argument types of the function being called.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|EmitCallArgs
argument_list|(
argument|CallArgList& Args
argument_list|,
argument|const T* CallArgTypeInfo
argument_list|,
argument|CallExpr::const_arg_iterator ArgBeg
argument_list|,
argument|CallExpr::const_arg_iterator ArgEnd
argument_list|)
block|{
name|CallExpr
operator|::
name|const_arg_iterator
name|Arg
operator|=
name|ArgBeg
block|;
comment|// First, use the argument types that the type info knows about
if|if
condition|(
name|CallArgTypeInfo
condition|)
block|{
for|for
control|(
name|typename
name|T
operator|::
name|arg_type_iterator
name|I
operator|=
name|CallArgTypeInfo
operator|->
name|arg_type_begin
argument_list|()
operator|,
name|E
operator|=
name|CallArgTypeInfo
operator|->
name|arg_type_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
operator|,
operator|++
name|Arg
control|)
block|{
name|assert
argument_list|(
name|Arg
operator|!=
name|ArgEnd
operator|&&
literal|"Running over edge of argument list!"
argument_list|)
expr_stmt|;
name|QualType
name|ArgType
init|=
operator|*
name|I
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|QualType
name|ActualArgType
init|=
name|Arg
operator|->
name|getType
argument_list|()
decl_stmt|;
if|if
condition|(
name|ArgType
operator|->
name|isPointerType
argument_list|()
operator|&&
name|ActualArgType
operator|->
name|isPointerType
argument_list|()
condition|)
block|{
name|QualType
name|ActualBaseType
init|=
name|ActualArgType
operator|->
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
operator|->
name|getPointeeType
argument_list|()
decl_stmt|;
name|QualType
name|ArgBaseType
init|=
name|ArgType
operator|->
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
operator|->
name|getPointeeType
argument_list|()
decl_stmt|;
if|if
condition|(
name|ArgBaseType
operator|->
name|isVariableArrayType
argument_list|()
condition|)
block|{
if|if
condition|(
specifier|const
name|VariableArrayType
modifier|*
name|VAT
init|=
name|getContext
argument_list|()
operator|.
name|getAsVariableArrayType
argument_list|(
name|ActualBaseType
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|VAT
operator|->
name|getSizeExpr
argument_list|()
condition|)
name|ActualArgType
operator|=
name|ArgType
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}         }
name|assert
argument_list|(
name|getContext
argument_list|()
operator|.
name|getCanonicalType
argument_list|(
name|ArgType
operator|.
name|getNonReferenceType
argument_list|()
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|==
name|getContext
argument_list|()
operator|.
name|getCanonicalType
argument_list|(
name|ActualArgType
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|&&
literal|"type mismatch in call argument!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|Args
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|EmitCallArg
argument_list|(
operator|*
name|Arg
argument_list|,
name|ArgType
argument_list|)
argument_list|,
name|ArgType
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Either we've emitted all the call args, or we have a call to a
end_comment

begin_comment
comment|// variadic function.
end_comment

begin_expr_stmt
unit|assert
operator|(
operator|(
name|Arg
operator|==
name|ArgEnd
operator|||
name|CallArgTypeInfo
operator|->
name|isVariadic
argument_list|()
operator|)
operator|&&
literal|"Extra arguments in non-variadic function!"
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// If we still have any arguments, emit them using the type of the argument.
end_comment

begin_expr_stmt
unit|for
operator|(
expr|;
name|Arg
operator|!=
name|ArgEnd
expr|;
operator|++
name|Arg
operator|)
block|{
name|QualType
name|ArgType
operator|=
name|Arg
operator|->
name|getType
argument_list|()
block|;
name|Args
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|EmitCallArg
argument_list|(
operator|*
name|Arg
argument_list|,
name|ArgType
argument_list|)
argument_list|,
name|ArgType
argument_list|)
argument_list|)
block|;     }
end_expr_stmt

begin_expr_stmt
unit|}    const
name|TargetCodeGenInfo
operator|&
name|getTargetHooks
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getTargetCodeGenInfo
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|EmitDeclMetadata
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// Helper class with most of the code for saving a value for a
end_comment

begin_comment
comment|/// conditional expression cleanup.
end_comment

begin_struct
struct|struct
name|DominatingLLVMValue
block|{
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|saved_type
expr_stmt|;
comment|/// Answer whether the given value needs extra work to be saved.
specifier|static
name|bool
name|needsSaving
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
block|{
comment|// If it's not an instruction, we don't need to save.
if|if
condition|(
operator|!
name|isa
operator|<
name|llvm
operator|::
name|Instruction
operator|>
operator|(
name|value
operator|)
condition|)
return|return
name|false
return|;
comment|// If it's an instruction in the entry block, we don't need to save.
name|llvm
operator|::
name|BasicBlock
operator|*
name|block
operator|=
name|cast
operator|<
name|llvm
operator|::
name|Instruction
operator|>
operator|(
name|value
operator|)
operator|->
name|getParent
argument_list|()
expr_stmt|;
return|return
operator|(
name|block
operator|!=
operator|&
name|block
operator|->
name|getParent
argument_list|()
operator|->
name|getEntryBlock
argument_list|()
operator|)
return|;
block|}
comment|/// Try to save the given value.
specifier|static
name|saved_type
name|save
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
block|{
if|if
condition|(
operator|!
name|needsSaving
argument_list|(
name|value
argument_list|)
condition|)
return|return
name|saved_type
argument_list|(
name|value
argument_list|,
name|false
argument_list|)
return|;
comment|// Otherwise we need an alloca.
name|llvm
operator|::
name|Value
operator|*
name|alloca
operator|=
name|CGF
operator|.
name|CreateTempAlloca
argument_list|(
name|value
operator|->
name|getType
argument_list|()
argument_list|,
literal|"cond-cleanup.save"
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|Builder
operator|.
name|CreateStore
argument_list|(
name|value
argument_list|,
name|alloca
argument_list|)
expr_stmt|;
return|return
name|saved_type
argument_list|(
name|alloca
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|llvm
operator|::
name|Value
operator|*
name|restore
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|saved_type value
argument_list|)
block|{
if|if
condition|(
operator|!
name|value
operator|.
name|getInt
argument_list|()
condition|)
return|return
name|value
operator|.
name|getPointer
argument_list|()
return|;
return|return
name|CGF
operator|.
name|Builder
operator|.
name|CreateLoad
argument_list|(
name|value
operator|.
name|getPointer
argument_list|()
argument_list|)
return|;
block|}
end_struct

begin_comment
unit|};
comment|/// A partial specialization of DominatingValue for llvm::Values that
end_comment

begin_comment
comment|/// might be llvm::Instructions.
end_comment

begin_expr_stmt
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
name|true
operator|>
operator|:
name|DominatingLLVMValue
block|{
typedef|typedef
name|T
modifier|*
name|type
typedef|;
specifier|static
name|type
name|restore
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|saved_type value
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|DominatingLLVMValue
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|value
argument_list|)
operator|)
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A specialization of DominatingValue for RValue.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DominatingValue
operator|<
name|RValue
operator|>
block|{
typedef|typedef
name|RValue
name|type
typedef|;
name|class
name|saved_type
block|{     enum
name|Kind
block|{
name|ScalarLiteral
block|,
name|ScalarAddress
block|,
name|AggregateLiteral
block|,
name|AggregateAddress
block|,
name|ComplexAddress
block|}
block|;
name|llvm
operator|::
name|Value
operator|*
name|Value
block|;
name|Kind
name|K
block|;
name|saved_type
argument_list|(
argument|llvm::Value *v
argument_list|,
argument|Kind k
argument_list|)
operator|:
name|Value
argument_list|(
name|v
argument_list|)
block|,
name|K
argument_list|(
argument|k
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|bool
name|needsSaving
argument_list|(
argument|RValue value
argument_list|)
block|;
specifier|static
name|saved_type
name|save
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|RValue value
argument_list|)
block|;
name|RValue
name|restore
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
block|;
comment|// implementations in CGExprCXX.cpp
block|}
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|bool
name|needsSaving
parameter_list|(
name|type
name|value
parameter_list|)
block|{
return|return
name|saved_type
operator|::
name|needsSaving
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function

begin_function
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
name|saved_type
operator|::
name|save
argument_list|(
name|CGF
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function

begin_function
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
operator|.
name|restore
argument_list|(
name|CGF
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace CodeGen
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

