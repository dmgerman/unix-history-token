begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- llvm/GlobalAlias.h - GlobalAlias class ------------*- C++ -*-===//
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
comment|// This file contains the declaration of the GlobalAlias class, which
end_comment

begin_comment
comment|// represents a single function or variable alias in the IR.
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
name|LLVM_IR_GLOBALALIAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GLOBALALIAS_H
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
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
name|class
name|GlobalAlias
range|:
name|public
name|GlobalIndirectSymbol
decl_stmt|,
name|public
name|ilist_node
decl|<
name|GlobalAlias
decl|>
block|{
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|GlobalAlias
operator|>
expr_stmt|;
name|GlobalAlias
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Constant *Aliasee
argument_list|,
argument|Module *Parent
argument_list|)
empty_stmt|;
name|public
label|:
name|GlobalAlias
argument_list|(
specifier|const
name|GlobalAlias
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|GlobalAlias
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GlobalAlias
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// If a parent module is specified, the alias is automatically inserted into
comment|/// the end of the specified module's alias list.
specifier|static
name|GlobalAlias
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
name|Aliasee
parameter_list|,
name|Module
modifier|*
name|Parent
parameter_list|)
function_decl|;
comment|// Without the Aliasee.
specifier|static
name|GlobalAlias
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
name|Module
modifier|*
name|Parent
parameter_list|)
function_decl|;
comment|// The module is taken from the Aliasee.
specifier|static
name|GlobalAlias
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
name|GlobalValue
modifier|*
name|Aliasee
parameter_list|)
function_decl|;
comment|// Type, Parent and AddressSpace taken from the Aliasee.
specifier|static
name|GlobalAlias
modifier|*
name|create
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|GlobalValue
modifier|*
name|Aliasee
parameter_list|)
function_decl|;
comment|// Linkage, Type, Parent and AddressSpace taken from the Aliasee.
specifier|static
name|GlobalAlias
modifier|*
name|create
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|GlobalValue
modifier|*
name|Aliasee
parameter_list|)
function_decl|;
name|void
name|copyAttributesFrom
parameter_list|(
specifier|const
name|GlobalValue
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
comment|/// removeFromParent - This method unlinks 'this' from the containing module,
comment|/// but does not delete it.
comment|///
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing module
comment|/// and deletes it.
comment|///
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// These methods retrieve and set alias target.
name|void
name|setAliasee
parameter_list|(
name|Constant
modifier|*
name|Aliasee
parameter_list|)
function_decl|;
specifier|const
name|Constant
operator|*
name|getAliasee
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
name|getAliasee
parameter_list|()
block|{
return|return
name|getIndirectSymbol
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isValidLinkage
parameter_list|(
name|LinkageTypes
name|L
parameter_list|)
block|{
return|return
name|isExternalLinkage
argument_list|(
name|L
argument_list|)
operator|||
name|isLocalLinkage
argument_list|(
name|L
argument_list|)
operator|||
name|isWeakLinkage
argument_list|(
name|L
argument_list|)
operator|||
name|isLinkOnceLinkage
argument_list|(
name|L
argument_list|)
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
name|GlobalAliasVal
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
comment|// LLVM_IR_GLOBALALIAS_H
end_comment

end_unit

