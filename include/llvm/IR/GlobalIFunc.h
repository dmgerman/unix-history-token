begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- llvm/GlobalIFunc.h - GlobalIFunc class ------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \brief
end_comment

begin_comment
comment|/// This file contains the declaration of the GlobalIFunc class, which
end_comment

begin_comment
comment|/// represents a single indirect function in the IR. Indirect function uses
end_comment

begin_comment
comment|/// ELF symbol type extension to mark that the address of a declaration should
end_comment

begin_comment
comment|/// be resolved at runtime by calling a resolver function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_GLOBALIFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GLOBALIFUNC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalIndirectSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Twine
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|// Traits class for using GlobalIFunc in symbol table in Module.
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
name|class
name|GlobalIFunc
name|final
range|:
name|public
name|GlobalIndirectSymbol
decl_stmt|,
name|public
name|ilist_node
decl|<
name|GlobalIFunc
decl|>
block|{
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|GlobalIFunc
operator|>
expr_stmt|;
name|GlobalIFunc
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Constant *Resolver
argument_list|,
argument|Module *Parent
argument_list|)
empty_stmt|;
name|public
label|:
name|GlobalIFunc
argument_list|(
specifier|const
name|GlobalIFunc
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|GlobalIFunc
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GlobalIFunc
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// If a parent module is specified, the ifunc is automatically inserted into
comment|/// the end of the specified module's ifunc list.
specifier|static
name|GlobalIFunc
modifier|*
name|create
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|,
name|unsigned
name|AddressSpace
parameter_list|,
name|LinkageTypes
name|Linkage
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|Constant
modifier|*
name|Resolver
parameter_list|,
name|Module
modifier|*
name|Parent
parameter_list|)
function_decl|;
name|void
name|copyAttributesFrom
parameter_list|(
specifier|const
name|GlobalIFunc
modifier|*
name|Src
parameter_list|)
block|{
name|GlobalValue
operator|::
name|copyAttributesFrom
argument_list|(
name|Src
argument_list|)
expr_stmt|;
block|}
comment|/// This method unlinks 'this' from the containing module, but does not
comment|/// delete it.
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// This method unlinks 'this' from the containing module and deletes it.
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// These methods retrieve and set ifunc resolver function.
name|void
name|setResolver
parameter_list|(
name|Constant
modifier|*
name|Resolver
parameter_list|)
block|{
name|setIndirectSymbol
argument_list|(
name|Resolver
argument_list|)
expr_stmt|;
block|}
specifier|const
name|Constant
operator|*
name|getResolver
argument_list|()
specifier|const
block|{
return|return
name|getIndirectSymbol
argument_list|()
return|;
block|}
name|Constant
modifier|*
name|getResolver
parameter_list|()
block|{
return|return
name|getIndirectSymbol
argument_list|()
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
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
block|}
empty_stmt|;
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
comment|// LLVM_IR_GLOBALIFUNC_H
end_comment

end_unit

