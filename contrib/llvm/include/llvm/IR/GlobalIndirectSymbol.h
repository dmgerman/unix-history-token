begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/GlobalIndirectSymbol.h - GlobalIndirectSymbol class -*- C++ -*-===//
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
comment|// This file contains the declaration of the GlobalIndirectSymbol class, which
end_comment

begin_comment
comment|// is a base class for GlobalAlias and GlobalIFunc. It contains all common code
end_comment

begin_comment
comment|// for aliases and ifuncs.
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
name|LLVM_IR_GLOBALINDIRECTSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GLOBALINDIRECTSYMBOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/GlobalObject.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalIndirectSymbol
range|:
name|public
name|GlobalValue
block|{
name|protected
operator|:
name|GlobalIndirectSymbol
argument_list|(
argument|Type *Ty
argument_list|,
argument|ValueTy VTy
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Constant *Symbol
argument_list|)
block|;
name|public
operator|:
name|GlobalIndirectSymbol
argument_list|(
specifier|const
name|GlobalIndirectSymbol
operator|&
argument_list|)
operator|=
name|delete
block|;
name|GlobalIndirectSymbol
operator|&
name|operator
operator|=
operator|(
specifier|const
name|GlobalIndirectSymbol
operator|&
operator|)
operator|=
name|delete
block|;
comment|// allocate space for exactly one operand
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|1
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Constant
argument_list|)
block|;
comment|/// These methods set and retrieve indirect symbol.
name|void
name|setIndirectSymbol
argument_list|(
argument|Constant *Symbol
argument_list|)
block|{
name|setOperand
argument_list|(
literal|0
argument_list|,
name|Symbol
argument_list|)
block|;   }
specifier|const
name|Constant
operator|*
name|getIndirectSymbol
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|Constant
operator|*
name|getIndirectSymbol
argument_list|()
block|{
return|return
name|const_cast
operator|<
name|Constant
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|GlobalIndirectSymbol
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getIndirectSymbol
argument_list|()
operator|)
return|;
block|}
specifier|const
name|GlobalObject
operator|*
name|getBaseObject
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast
operator|<
name|GlobalObject
operator|>
operator|(
name|getIndirectSymbol
argument_list|()
operator|->
name|stripInBoundsOffsets
argument_list|()
operator|)
return|;
block|}
name|GlobalObject
operator|*
name|getBaseObject
argument_list|()
block|{
return|return
name|const_cast
operator|<
name|GlobalObject
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|GlobalIndirectSymbol
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getBaseObject
argument_list|()
operator|)
return|;
block|}
specifier|const
name|GlobalObject
operator|*
name|getBaseObject
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|APInt&Offset
argument_list|)
specifier|const
block|{
return|return
name|dyn_cast
operator|<
name|GlobalObject
operator|>
operator|(
name|getIndirectSymbol
argument_list|()
operator|->
name|stripAndAccumulateInBoundsConstantOffsets
argument_list|(
name|DL
argument_list|,
name|Offset
argument_list|)
operator|)
return|;
block|}
name|GlobalObject
operator|*
name|getBaseObject
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|APInt&Offset
argument_list|)
block|{
return|return
name|const_cast
operator|<
name|GlobalObject
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|GlobalIndirectSymbol
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getBaseObject
argument_list|(
name|DL
argument_list|,
name|Offset
argument_list|)
operator|)
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalAliasVal
operator|||
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalIFuncVal
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|GlobalIndirectSymbol
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|GlobalIndirectSymbol
block|,
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|GlobalIndirectSymbol
argument_list|,
argument|Constant
argument_list|)
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
comment|// LLVM_IR_GLOBALINDIRECTSYMBOL_H
end_comment

end_unit

