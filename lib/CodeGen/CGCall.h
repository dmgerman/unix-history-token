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
file|<llvm/ADT/FoldingSet.h>
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"CGValue.h"
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
struct_decl|struct
name|AttributeWithIndex
struct_decl|;
name|class
name|Function
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
operator|>
name|class
name|SmallVector
expr_stmt|;
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
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|AttributeWithIndex
operator|,
literal|8
operator|>
name|AttributeListType
expr_stmt|;
comment|/// CallArgList - Type for representing both the value and type of
comment|/// arguments in a call.
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|RValue
operator|,
name|QualType
operator|>
operator|,
literal|16
operator|>
name|CallArgList
expr_stmt|;
comment|/// FunctionArgList - Type for representing both the decl and type
comment|/// of parameters to a function. The decl must be either a
comment|/// ParmVarDecl or ImplicitParamDecl.
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|QualType
operator|>
operator|,
literal|16
operator|>
name|FunctionArgList
expr_stmt|;
comment|/// CGFunctionInfo - Class to encapsulate the information about a
comment|/// function definition.
name|class
name|CGFunctionInfo
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{     struct
name|ArgInfo
block|{
name|QualType
name|type
block|;
name|ABIArgInfo
name|info
block|;     }
block|;
comment|/// The LLVM::CallingConv to use for this function (as specified by the
comment|/// user).
name|unsigned
name|CallingConvention
block|;
comment|/// The LLVM::CallingConv to actually use for this function, which may
comment|/// depend on the ABI.
name|unsigned
name|EffectiveCallingConvention
block|;
name|unsigned
name|NumArgs
block|;
name|ArgInfo
operator|*
name|Args
block|;
name|public
operator|:
typedef|typedef
specifier|const
name|ArgInfo
modifier|*
name|const_arg_iterator
typedef|;
typedef|typedef
name|ArgInfo
modifier|*
name|arg_iterator
typedef|;
name|CGFunctionInfo
argument_list|(
argument|unsigned CallingConvention
argument_list|,
argument|QualType ResTy
argument_list|,
argument|const llvm::SmallVector<QualType
argument_list|,
literal|16
argument|>&ArgTys
argument_list|)
empty_stmt|;
operator|~
name|CGFunctionInfo
argument_list|()
block|{
name|delete
index|[]
name|Args
block|; }
name|const_arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|+
literal|1
return|;
block|}
name|const_arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|+
literal|1
operator|+
name|NumArgs
return|;
block|}
name|arg_iterator
name|arg_begin
parameter_list|()
block|{
return|return
name|Args
operator|+
literal|1
return|;
block|}
name|arg_iterator
name|arg_end
parameter_list|()
block|{
return|return
name|Args
operator|+
literal|1
operator|+
name|NumArgs
return|;
block|}
name|unsigned
name|arg_size
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
comment|/// getCallingConvention - Return the user specified calling
comment|/// convention.
name|unsigned
name|getCallingConvention
argument_list|()
specifier|const
block|{
return|return
name|CallingConvention
return|;
block|}
comment|/// getEffectiveCallingConvention - Return the actual calling convention to
comment|/// use, which may depend on the ABI.
name|unsigned
name|getEffectiveCallingConvention
argument_list|()
specifier|const
block|{
return|return
name|EffectiveCallingConvention
return|;
block|}
name|void
name|setEffectiveCallingConvention
parameter_list|(
name|unsigned
name|Value
parameter_list|)
block|{
name|EffectiveCallingConvention
operator|=
name|Value
expr_stmt|;
block|}
name|QualType
name|getReturnType
argument_list|()
specifier|const
block|{
return|return
name|Args
index|[
literal|0
index|]
operator|.
name|type
return|;
block|}
name|ABIArgInfo
modifier|&
name|getReturnInfo
parameter_list|()
block|{
return|return
name|Args
index|[
literal|0
index|]
operator|.
name|info
return|;
block|}
specifier|const
name|ABIArgInfo
operator|&
name|getReturnInfo
argument_list|()
specifier|const
block|{
return|return
name|Args
index|[
literal|0
index|]
operator|.
name|info
return|;
block|}
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|getCallingConvention
argument_list|()
argument_list|)
expr_stmt|;
name|getReturnType
argument_list|()
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
for|for
control|(
name|arg_iterator
name|it
init|=
name|arg_begin
argument_list|()
init|,
name|ie
init|=
name|arg_end
argument_list|()
init|;
name|it
operator|!=
name|ie
condition|;
operator|++
name|it
control|)
name|it
operator|->
name|type
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|class
name|Iterator
operator|>
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|unsigned CallingConvention
argument_list|,
argument|QualType ResTy
argument_list|,
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|CallingConvention
argument_list|)
block|;
name|ResTy
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;
for|for
control|(
init|;
name|begin
operator|!=
name|end
condition|;
operator|++
name|begin
control|)
name|begin
operator|->
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
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

