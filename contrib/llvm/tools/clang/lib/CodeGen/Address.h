begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Address.h - An aligned address -------------------------*- C++ -*-===//
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
comment|// This class provides a simple wrapper for a pair of a pointer and an
end_comment

begin_comment
comment|// alignment.
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
name|LLVM_CLANG_LIB_CODEGEN_ADDRESS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_ADDRESS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Constants.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// An aligned address.
name|class
name|Address
block|{
name|llvm
operator|::
name|Value
operator|*
name|Pointer
expr_stmt|;
name|CharUnits
name|Alignment
decl_stmt|;
name|public
label|:
name|Address
argument_list|(
argument|llvm::Value *pointer
argument_list|,
argument|CharUnits alignment
argument_list|)
block|:
name|Pointer
argument_list|(
name|pointer
argument_list|)
operator|,
name|Alignment
argument_list|(
argument|alignment
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|alignment
operator|.
name|isZero
argument_list|()
operator|||
name|pointer
operator|==
name|nullptr
operator|)
operator|&&
literal|"creating valid address with invalid alignment"
argument_list|)
block|;   }
specifier|static
name|Address
name|invalid
argument_list|()
block|{
return|return
name|Address
argument_list|(
name|nullptr
argument_list|,
name|CharUnits
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Pointer
operator|!=
name|nullptr
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
argument_list|)
block|;
return|return
name|Pointer
return|;
block|}
comment|/// Return the type of the pointer value.
name|llvm
operator|::
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|cast
operator|<
name|llvm
operator|::
name|PointerType
operator|>
operator|(
name|getPointer
argument_list|()
operator|->
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Return the type of the values stored in this address.
comment|///
comment|/// When IR pointer types lose their element type, we should simply
comment|/// store it in Address instead for the convenience of writing code.
name|llvm
operator|::
name|Type
operator|*
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getElementType
argument_list|()
return|;
block|}
comment|/// Return the address space that this address resides in.
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getAddressSpace
argument_list|()
return|;
block|}
comment|/// Return the IR name of the pointer value.
name|llvm
operator|::
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getPointer
argument_list|()
operator|->
name|getName
argument_list|()
return|;
block|}
comment|/// Return the alignment of this pointer.
name|CharUnits
name|getAlignment
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
argument_list|)
block|;
return|return
name|Alignment
return|;
block|}
block|}
empty_stmt|;
comment|/// A specialization of Address that requires the address to be an
comment|/// LLVM Constant.
name|class
name|ConstantAddress
range|:
name|public
name|Address
block|{
name|public
operator|:
name|ConstantAddress
argument_list|(
argument|llvm::Constant *pointer
argument_list|,
argument|CharUnits alignment
argument_list|)
operator|:
name|Address
argument_list|(
argument|pointer
argument_list|,
argument|alignment
argument_list|)
block|{}
specifier|static
name|ConstantAddress
name|invalid
argument_list|()
block|{
return|return
name|ConstantAddress
argument_list|(
name|nullptr
argument_list|,
name|CharUnits
argument_list|()
argument_list|)
return|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|cast
operator|<
name|llvm
operator|::
name|Constant
operator|>
operator|(
name|Address
operator|::
name|getPointer
argument_list|()
operator|)
return|;
block|}
name|ConstantAddress
name|getBitCast
argument_list|(
argument|llvm::Type *ty
argument_list|)
specifier|const
block|{
return|return
name|ConstantAddress
argument_list|(
name|llvm
operator|::
name|ConstantExpr
operator|::
name|getBitCast
argument_list|(
name|getPointer
argument_list|()
argument_list|,
name|ty
argument_list|)
argument_list|,
name|getAlignment
argument_list|()
argument_list|)
return|;
block|}
name|ConstantAddress
name|getElementBitCast
argument_list|(
argument|llvm::Type *ty
argument_list|)
specifier|const
block|{
return|return
name|getBitCast
argument_list|(
name|ty
operator|->
name|getPointerTo
argument_list|(
name|getAddressSpace
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isaImpl
argument_list|(
argument|Address addr
argument_list|)
block|{
return|return
name|llvm
operator|::
name|isa
operator|<
name|llvm
operator|::
name|Constant
operator|>
operator|(
name|addr
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
specifier|static
name|ConstantAddress
name|castImpl
argument_list|(
argument|Address addr
argument_list|)
block|{
return|return
name|ConstantAddress
argument_list|(
name|llvm
operator|::
name|cast
operator|<
name|llvm
operator|::
name|Constant
operator|>
operator|(
name|addr
operator|.
name|getPointer
argument_list|()
operator|)
argument_list|,
name|addr
operator|.
name|getAlignment
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;  }
comment|// Present a minimal LLVM-like casting interface.
name|template
operator|<
name|class
name|U
operator|>
specifier|inline
name|U
name|cast
argument_list|(
argument|CodeGen::Address addr
argument_list|)
block|{
return|return
name|U
operator|::
name|castImpl
argument_list|(
name|addr
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|U
operator|>
specifier|inline
name|bool
name|isa
argument_list|(
argument|CodeGen::Address addr
argument_list|)
block|{
return|return
name|U
operator|::
name|isaImpl
argument_list|(
name|addr
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

