begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGCall.h - Encapsulate calling convention details ----*- C++ -*-===//
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
comment|// These classes wrap the information about a call or function
end_comment

begin_comment
comment|// definition used to handle ABI compliancy.
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
name|CLANG_CODEGEN_CGCALL_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGCALL_H
end_define

begin_include
include|#
directive|include
file|"CGValue.h"
end_include

begin_include
include|#
directive|include
file|"EHScopeStack.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_comment
comment|// FIXME: Restructure so we don't have to expose so much stuff.
end_comment

begin_include
include|#
directive|include
file|"ABIInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AttributeSet
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
typedef|typedef
name|SmallVector
operator|<
name|llvm
operator|::
name|AttributeSet
operator|,
literal|8
operator|>
name|AttributeListType
expr_stmt|;
struct|struct
name|CallArg
block|{
name|RValue
name|RV
decl_stmt|;
name|QualType
name|Ty
decl_stmt|;
name|bool
name|NeedsCopy
decl_stmt|;
name|CallArg
argument_list|(
argument|RValue rv
argument_list|,
argument|QualType ty
argument_list|,
argument|bool needscopy
argument_list|)
block|:
name|RV
argument_list|(
name|rv
argument_list|)
operator|,
name|Ty
argument_list|(
name|ty
argument_list|)
operator|,
name|NeedsCopy
argument_list|(
argument|needscopy
argument_list|)
block|{ }
block|}
struct|;
comment|/// CallArgList - Type for representing both the value and type of
comment|/// arguments in a call.
name|class
name|CallArgList
range|:
name|public
name|SmallVector
operator|<
name|CallArg
decl_stmt|, 16>
block|{
name|public
label|:
struct|struct
name|Writeback
block|{
comment|/// The original argument.  Note that the argument l-value
comment|/// is potentially null.
name|LValue
name|Source
decl_stmt|;
comment|/// The temporary alloca.
name|llvm
operator|::
name|Value
operator|*
name|Temporary
expr_stmt|;
comment|/// A value to "use" after the writeback, or null.
name|llvm
operator|::
name|Value
operator|*
name|ToUse
expr_stmt|;
block|}
struct|;
struct|struct
name|CallArgCleanup
block|{
name|EHScopeStack
operator|::
name|stable_iterator
name|Cleanup
expr_stmt|;
comment|/// The "is active" insertion point.  This instruction is temporary and
comment|/// will be removed after insertion.
name|llvm
operator|::
name|Instruction
operator|*
name|IsActiveIP
expr_stmt|;
block|}
struct|;
name|void
name|add
parameter_list|(
name|RValue
name|rvalue
parameter_list|,
name|QualType
name|type
parameter_list|,
name|bool
name|needscopy
init|=
name|false
parameter_list|)
block|{
name|push_back
argument_list|(
name|CallArg
argument_list|(
name|rvalue
argument_list|,
name|type
argument_list|,
name|needscopy
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|addFrom
parameter_list|(
specifier|const
name|CallArgList
modifier|&
name|other
parameter_list|)
block|{
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|other
operator|.
name|begin
argument_list|()
argument_list|,
name|other
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|Writebacks
operator|.
name|insert
argument_list|(
name|Writebacks
operator|.
name|end
argument_list|()
argument_list|,
name|other
operator|.
name|Writebacks
operator|.
name|begin
argument_list|()
argument_list|,
name|other
operator|.
name|Writebacks
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|addWriteback
argument_list|(
name|LValue
name|srcLV
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|temporary
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|toUse
argument_list|)
block|{
name|Writeback
name|writeback
decl_stmt|;
name|writeback
operator|.
name|Source
operator|=
name|srcLV
expr_stmt|;
name|writeback
operator|.
name|Temporary
operator|=
name|temporary
expr_stmt|;
name|writeback
operator|.
name|ToUse
operator|=
name|toUse
expr_stmt|;
name|Writebacks
operator|.
name|push_back
argument_list|(
name|writeback
argument_list|)
expr_stmt|;
block|}
name|bool
name|hasWritebacks
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Writebacks
operator|.
name|empty
argument_list|()
return|;
block|}
typedef|typedef
name|SmallVectorImpl
operator|<
name|Writeback
operator|>
operator|::
name|const_iterator
name|writeback_iterator
expr_stmt|;
name|writeback_iterator
name|writeback_begin
argument_list|()
specifier|const
block|{
return|return
name|Writebacks
operator|.
name|begin
argument_list|()
return|;
block|}
name|writeback_iterator
name|writeback_end
argument_list|()
specifier|const
block|{
return|return
name|Writebacks
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|addArgCleanupDeactivation
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|Cleanup
argument_list|,
name|llvm
operator|::
name|Instruction
operator|*
name|IsActiveIP
argument_list|)
block|{
name|CallArgCleanup
name|ArgCleanup
decl_stmt|;
name|ArgCleanup
operator|.
name|Cleanup
operator|=
name|Cleanup
expr_stmt|;
name|ArgCleanup
operator|.
name|IsActiveIP
operator|=
name|IsActiveIP
expr_stmt|;
name|CleanupsToDeactivate
operator|.
name|push_back
argument_list|(
name|ArgCleanup
argument_list|)
expr_stmt|;
block|}
name|ArrayRef
operator|<
name|CallArgCleanup
operator|>
name|getCleanupsToDeactivate
argument_list|()
specifier|const
block|{
return|return
name|CleanupsToDeactivate
return|;
block|}
name|private
label|:
name|SmallVector
operator|<
name|Writeback
operator|,
literal|1
operator|>
name|Writebacks
expr_stmt|;
comment|/// Deactivate these cleanups immediately before making the call.  This
comment|/// is used to cleanup objects that are owned by the callee once the call
comment|/// occurs.
name|SmallVector
operator|<
name|CallArgCleanup
operator|,
literal|1
operator|>
name|CleanupsToDeactivate
expr_stmt|;
block|}
empty_stmt|;
comment|/// FunctionArgList - Type for representing both the decl and type
comment|/// of parameters to a function. The decl must be either a
comment|/// ParmVarDecl or ImplicitParamDecl.
name|class
name|FunctionArgList
range|:
name|public
name|SmallVector
operator|<
specifier|const
name|VarDecl
operator|*
decl_stmt|, 16>
block|{   }
empty_stmt|;
comment|/// ReturnValueSlot - Contains the address where the return value of a
comment|/// function can be stored, and whether the address is volatile or not.
name|class
name|ReturnValueSlot
block|{
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
name|Value
expr_stmt|;
name|public
label|:
name|ReturnValueSlot
argument_list|()
block|{}
name|ReturnValueSlot
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|bool IsVolatile
argument_list|)
block|:
name|Value
argument_list|(
argument|Value
argument_list|,
argument|IsVolatile
argument_list|)
block|{}
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|!
name|getValue
argument_list|()
return|;
block|}
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

