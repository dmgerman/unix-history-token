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
name|LLVM_GLOBAL_ALIAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_GLOBAL_ALIAS_H
end_define

begin_include
include|#
directive|include
file|"llvm/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|template
operator|<
name|typename
name|ValueSubClass
operator|,
name|typename
name|ItemParentClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
name|class
name|GlobalAlias
range|:
name|public
name|GlobalValue
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
operator|,
name|Module
operator|>
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|GlobalAlias
operator|&
operator|)
decl_stmt|;
comment|// Do not implement
name|GlobalAlias
argument_list|(
specifier|const
name|GlobalAlias
operator|&
argument_list|)
expr_stmt|;
comment|// Do not implement
name|void
name|setParent
parameter_list|(
name|Module
modifier|*
name|parent
parameter_list|)
function_decl|;
name|public
label|:
comment|// allocate space for exactly one operand
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|s
parameter_list|)
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
comment|/// GlobalAlias ctor - If a parent module is specified, the alias is
comment|/// automatically inserted into the end of the specified module's alias list.
name|GlobalAlias
argument_list|(
argument|const Type *Ty
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Constant* Aliasee =
literal|0
argument_list|,
argument|Module *Parent =
literal|0
argument_list|)
empty_stmt|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
expr_stmt|;
comment|/// isDeclaration - Is this global variable lacking an initializer?  If so,
comment|/// the global variable is defined in some other translation unit, and is thus
comment|/// only a declaration here.
name|virtual
name|bool
name|isDeclaration
argument_list|()
specifier|const
expr_stmt|;
comment|/// removeFromParent - This method unlinks 'this' from the containing module,
comment|/// but does not delete it.
comment|///
name|virtual
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing module
comment|/// and deletes it.
comment|///
name|virtual
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// set/getAliasee - These methods retrive and set alias target.
name|void
name|setAliasee
parameter_list|(
name|Constant
modifier|*
name|GV
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
name|cast_or_null
operator|<
name|Constant
operator|>
operator|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|)
return|;
block|}
name|Constant
modifier|*
name|getAliasee
parameter_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Constant
operator|>
operator|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|)
return|;
block|}
comment|/// getAliasedGlobal() - Aliasee can be either global or bitcast of
comment|/// global. This method retrives the global for both aliasee flavours.
specifier|const
name|GlobalValue
operator|*
name|getAliasedGlobal
argument_list|()
specifier|const
expr_stmt|;
comment|/// resolveAliasedGlobal() - This method tries to ultimately resolve the alias
comment|/// by going through the aliasing chain and trying to find the very last
comment|/// global. Returns NULL if a cycle was found. If stopOnWeak is false, then
comment|/// the whole chain aliasing chain is traversed, otherwise - only strong
comment|/// aliases.
specifier|const
name|GlobalValue
modifier|*
name|resolveAliasedGlobal
argument_list|(
name|bool
name|stopOnWeak
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|GlobalAlias
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
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
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|GlobalAlias
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
literal|1
operator|>
block|{ }
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|GlobalAlias
argument_list|,
argument|Value
argument_list|)
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

