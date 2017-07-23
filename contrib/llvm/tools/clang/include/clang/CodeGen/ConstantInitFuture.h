begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ConstantInitFuture.h - "Future" constant initializers ----*- C++ -*-===//
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
comment|// This class defines the ConstantInitFuture class.  This is split out
end_comment

begin_comment
comment|// from ConstantInitBuilder.h in order to allow APIs to work with it
end_comment

begin_comment
comment|// without having to include that entire header.  This is particularly
end_comment

begin_comment
comment|// important because it is often useful to be able to default-construct
end_comment

begin_comment
comment|// a future in, say, a default argument.
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
name|LLVM_CLANG_CODEGEN_CONSTANTINITFUTURE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_CONSTANTINITFUTURE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constant.h"
end_include

begin_comment
comment|// Forward-declare ConstantInitBuilderBase and give it a
end_comment

begin_comment
comment|// PointerLikeTypeTraits specialization so that we can safely use it
end_comment

begin_comment
comment|// in a PointerUnion below.
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|ConstantInitBuilderBase
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
operator|::
name|clang
operator|::
name|CodeGen
operator|::
name|ConstantInitBuilderBase
operator|*
operator|>
block|{
name|public
operator|:
name|using
name|T
operator|=
operator|::
name|clang
operator|::
name|CodeGen
operator|::
name|ConstantInitBuilderBase
operator|*
block|;
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|T p
argument_list|)
block|{
return|return
name|p
return|;
block|}
specifier|static
specifier|inline
name|T
name|getFromVoidPointer
argument_list|(
argument|void *p
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|>
operator|(
name|p
operator|)
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// A "future" for a completed constant initializer, which can be passed
comment|/// around independently of any sub-builders (but not the original parent).
name|class
name|ConstantInitFuture
block|{
name|using
name|PairTy
init|=
name|llvm
operator|::
name|PointerUnion
operator|<
name|ConstantInitBuilderBase
operator|*
decl_stmt|,
name|llvm
decl|::
name|Constant
modifier|*
decl|>
decl_stmt|;
name|PairTy
name|Data
decl_stmt|;
name|friend
name|class
name|ConstantInitBuilderBase
decl_stmt|;
name|explicit
name|ConstantInitFuture
parameter_list|(
name|ConstantInitBuilderBase
modifier|*
name|builder
parameter_list|)
function_decl|;
name|public
label|:
name|ConstantInitFuture
argument_list|()
block|{}
comment|/// A future can be explicitly created from a fixed initializer.
name|explicit
name|ConstantInitFuture
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|initializer
argument_list|)
range|:
name|Data
argument_list|(
argument|initializer
argument_list|)
block|{
name|assert
argument_list|(
name|initializer
operator|&&
literal|"creating null future"
argument_list|)
block|;   }
comment|/// Is this future non-null?
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|bool
argument_list|(
name|Data
argument_list|)
return|;
block|}
comment|/// Return the type of the initializer.
name|llvm
operator|::
name|Type
operator|*
name|getType
argument_list|()
specifier|const
expr_stmt|;
comment|/// Abandon this initializer.
name|void
name|abandon
parameter_list|()
function_decl|;
comment|/// Install the initializer into a global variable.  This cannot
comment|/// be called multiple times.
name|void
name|installInGlobal
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|global
argument_list|)
decl_stmt|;
name|void
operator|*
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
name|ConstantInitFuture
name|getFromOpaqueValue
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
block|{
name|ConstantInitFuture
name|result
decl_stmt|;
name|result
operator|.
name|Data
operator|=
name|PairTy
operator|::
name|getFromOpaqueValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
enum|enum
block|{
name|NumLowBitsAvailable
init|=
name|llvm
operator|::
name|PointerLikeTypeTraits
operator|<
name|PairTy
operator|>
operator|::
name|NumLowBitsAvailable
block|}
enum|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
operator|::
name|clang
operator|::
name|CodeGen
operator|::
name|ConstantInitFuture
operator|>
block|{
name|public
operator|:
name|using
name|T
operator|=
operator|::
name|clang
operator|::
name|CodeGen
operator|::
name|ConstantInitFuture
block|;
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|T future
argument_list|)
block|{
return|return
name|future
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|T
name|getFromVoidPointer
argument_list|(
argument|void *p
argument_list|)
block|{
return|return
name|T
operator|::
name|getFromOpaqueValue
argument_list|(
name|p
argument_list|)
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
name|T
operator|::
name|NumLowBitsAvailable
block|}
block|; }
expr_stmt|;
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

