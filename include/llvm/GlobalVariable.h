begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/GlobalVariable.h - GlobalVariable class ------------*- C++ -*-===//
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
comment|// This file contains the declaration of the GlobalVariable class, which
end_comment

begin_comment
comment|// represents a single global variable (or constant) in the VM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Global variables are constant pointers that refer to hunks of space that are
end_comment

begin_comment
comment|// allocated by either the VM, or by the linker in a static compiler.  A global
end_comment

begin_comment
comment|// variable may have an intial value, which is copied into the executables .data
end_comment

begin_comment
comment|// area.  Global Constants are required to have initializers.
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
name|LLVM_GLOBAL_VARIABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_GLOBAL_VARIABLE_H
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
name|GlobalVariable
range|:
name|public
name|GlobalValue
decl_stmt|,
name|public
name|ilist_node
decl|<
name|GlobalVariable
decl|>
block|{
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|GlobalVariable
operator|,
name|Module
operator|>
expr_stmt|;
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
comment|// Do not implement
name|void
name|operator
init|=
operator|(
specifier|const
name|GlobalVariable
operator|&
operator|)
decl_stmt|;
comment|// Do not implement
name|GlobalVariable
argument_list|(
specifier|const
name|GlobalVariable
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
name|bool
name|isConstantGlobal
range|:
literal|1
decl_stmt|;
comment|// Is this a global constant?
name|bool
name|isThreadLocalSymbol
range|:
literal|1
decl_stmt|;
comment|// Is this symbol "Thread Local"?
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
comment|/// GlobalVariable ctor - If a parent module is specified, the global is
comment|/// automatically inserted into the end of the specified modules global list.
name|GlobalVariable
argument_list|(
argument|const Type *Ty
argument_list|,
argument|bool isConstant
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|Constant *Initializer =
literal|0
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|bool ThreadLocal = false
argument_list|,
argument|unsigned AddressSpace =
literal|0
argument_list|)
empty_stmt|;
comment|/// GlobalVariable ctor - This creates a global and inserts it before the
comment|/// specified other global.
name|GlobalVariable
argument_list|(
argument|Module&M
argument_list|,
argument|const Type *Ty
argument_list|,
argument|bool isConstant
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|Constant *Initializer
argument_list|,
argument|const Twine&Name
argument_list|,
argument|GlobalVariable *InsertBefore =
literal|0
argument_list|,
argument|bool ThreadLocal = false
argument_list|,
argument|unsigned AddressSpace =
literal|0
argument_list|)
empty_stmt|;
operator|~
name|GlobalVariable
argument_list|()
block|{
name|NumOperands
operator|=
literal|1
block|;
comment|// FIXME: needed by operator delete
block|}
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
block|{
return|return
name|getNumOperands
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// hasInitializer - Unless a global variable isExternal(), it has an
comment|/// initializer.  The initializer for the global variable/constant is held by
comment|/// Initializer if an initializer is specified.
comment|///
specifier|inline
name|bool
name|hasInitializer
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDeclaration
argument_list|()
return|;
block|}
comment|/// hasDefinitiveInitializer - Whether the global variable has an initializer,
comment|/// and this is the initializer that will be used in the final executable.
specifier|inline
name|bool
name|hasDefinitiveInitializer
argument_list|()
specifier|const
block|{
return|return
name|hasInitializer
argument_list|()
operator|&&
comment|// The initializer of a global variable with weak linkage may change at
comment|// link time.
operator|!
name|mayBeOverridden
argument_list|()
return|;
block|}
comment|/// getInitializer - Return the initializer for this global variable.  It is
comment|/// illegal to call this method if the global is external, because we cannot
comment|/// tell what the value is initialized to!
comment|///
specifier|inline
comment|/*const FIXME*/
name|Constant
operator|*
name|getInitializer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasInitializer
argument_list|()
operator|&&
literal|"GV doesn't have initializer!"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Constant
operator|*
operator|>
operator|(
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|.
name|get
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|Constant
modifier|*
name|getInitializer
parameter_list|()
block|{
name|assert
argument_list|(
name|hasInitializer
argument_list|()
operator|&&
literal|"GV doesn't have initializer!"
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|Constant
operator|*
operator|>
operator|(
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|.
name|get
argument_list|()
operator|)
return|;
block|}
comment|/// setInitializer - Sets the initializer for this global variable, removing
comment|/// any existing initializer if InitVal==NULL.  If this GV has type T*, the
comment|/// initializer must have type T.
name|void
name|setInitializer
parameter_list|(
name|Constant
modifier|*
name|InitVal
parameter_list|)
function_decl|;
comment|/// If the value is a global constant, its value is immutable throughout the
comment|/// runtime execution of the program.  Assigning a value into the constant
comment|/// leads to undefined behavior.
comment|///
name|bool
name|isConstant
argument_list|()
specifier|const
block|{
return|return
name|isConstantGlobal
return|;
block|}
name|void
name|setConstant
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|isConstantGlobal
operator|=
name|Val
expr_stmt|;
block|}
comment|/// If the value is "Thread Local", its value isn't shared by the threads.
name|bool
name|isThreadLocal
argument_list|()
specifier|const
block|{
return|return
name|isThreadLocalSymbol
return|;
block|}
name|void
name|setThreadLocal
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|isThreadLocalSymbol
operator|=
name|Val
expr_stmt|;
block|}
comment|/// copyAttributesFrom - copy all additional attributes (those not needed to
comment|/// create a GlobalVariable) from the GlobalVariable Src to this one.
name|void
name|copyAttributesFrom
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|Src
parameter_list|)
function_decl|;
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
comment|/// Override Constant's implementation of this method so we can
comment|/// replace constant initializers.
name|virtual
name|void
name|replaceUsesOfWithOnConstant
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|,
name|Use
modifier|*
name|U
parameter_list|)
function_decl|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|GlobalVariable
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
name|GlobalVariableVal
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
name|GlobalVariable
operator|>
operator|:
name|public
name|OptionalOperandTraits
operator|<
operator|>
block|{ }
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|GlobalVariable
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

