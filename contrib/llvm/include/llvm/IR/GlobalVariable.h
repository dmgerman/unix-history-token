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
comment|// variable may have an initial value, which is copied into the executables .data
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
name|LLVM_IR_GLOBALVARIABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GLOBALVARIABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalObject.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|Constant
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
name|DIGlobalVariable
decl_stmt|;
name|class
name|DIGlobalVariableExpression
decl_stmt|;
name|class
name|GlobalVariable
range|:
name|public
name|GlobalObject
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
operator|>
expr_stmt|;
name|AttributeSet
name|Attrs
decl_stmt|;
name|bool
name|isConstantGlobal
range|:
literal|1
decl_stmt|;
comment|// Is this a global constant?
name|bool
name|isExternallyInitializedConstant
range|:
literal|1
decl_stmt|;
comment|// Is this a global whose value
comment|// can change from its initial
comment|// value before global
comment|// initializers are run?
name|public
label|:
comment|/// GlobalVariable ctor - If a parent module is specified, the global is
comment|/// automatically inserted into the end of the specified modules global list.
name|GlobalVariable
argument_list|(
argument|Type *Ty
argument_list|,
argument|bool isConstant
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|Constant *Initializer = nullptr
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|ThreadLocalMode = NotThreadLocal
argument_list|,
argument|unsigned AddressSpace =
literal|0
argument_list|,
argument|bool isExternallyInitialized = false
argument_list|)
empty_stmt|;
comment|/// GlobalVariable ctor - This creates a global and inserts it before the
comment|/// specified other global.
name|GlobalVariable
argument_list|(
argument|Module&M
argument_list|,
argument|Type *Ty
argument_list|,
argument|bool isConstant
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|Constant *Initializer
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|GlobalVariable *InsertBefore = nullptr
argument_list|,
argument|ThreadLocalMode = NotThreadLocal
argument_list|,
argument|unsigned AddressSpace =
literal|0
argument_list|,
argument|bool isExternallyInitialized = false
argument_list|)
empty_stmt|;
name|GlobalVariable
argument_list|(
specifier|const
name|GlobalVariable
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|GlobalVariable
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GlobalVariable
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|GlobalVariable
argument_list|()
block|{
name|dropAllReferences
argument_list|()
block|;
comment|// FIXME: needed by operator delete
name|setGlobalVariableNumOperands
argument_list|(
literal|1
argument_list|)
block|;   }
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
name|Value
argument_list|)
expr_stmt|;
comment|/// Definitions have initializers, declarations don't.
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
comment|/// and any other instances of the global (this can happen due to weak
comment|/// linkage) are guaranteed to have the same initializer.
comment|///
comment|/// Note that if you want to transform a global, you must use
comment|/// hasUniqueInitializer() instead, because of the *_odr linkage type.
comment|///
comment|/// Example:
comment|///
comment|/// @a = global SomeType* null - Initializer is both definitive and unique.
comment|///
comment|/// @b = global weak SomeType* null - Initializer is neither definitive nor
comment|/// unique.
comment|///
comment|/// @c = global weak_odr SomeType* null - Initializer is definitive, but not
comment|/// unique.
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
comment|// The initializer of a global variable may change to something arbitrary
comment|// at link time.
operator|!
name|isInterposable
argument_list|()
operator|&&
comment|// The initializer of a global variable with the externally_initialized
comment|// marker may change at runtime before C++ initializers are evaluated.
operator|!
name|isExternallyInitialized
argument_list|()
return|;
block|}
comment|/// hasUniqueInitializer - Whether the global variable has an initializer, and
comment|/// any changes made to the initializer will turn up in the final executable.
specifier|inline
name|bool
name|hasUniqueInitializer
argument_list|()
specifier|const
block|{
return|return
comment|// We need to be sure this is the definition that will actually be used
name|isStrongDefinitionForLinker
argument_list|()
operator|&&
comment|// It is not safe to modify initializers of global variables with the
comment|// external_initializer marker since the value may be changed at runtime
comment|// before C++ initializers are evaluated.
operator|!
name|isExternallyInitialized
argument_list|()
return|;
block|}
comment|/// getInitializer - Return the initializer for this global variable.  It is
comment|/// illegal to call this method if the global is external, because we cannot
comment|/// tell what the value is initialized to!
comment|///
specifier|inline
specifier|const
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
name|bool
name|isExternallyInitialized
argument_list|()
specifier|const
block|{
return|return
name|isExternallyInitializedConstant
return|;
block|}
name|void
name|setExternallyInitialized
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|isExternallyInitializedConstant
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
name|GlobalVariable
modifier|*
name|Src
parameter_list|)
function_decl|;
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
comment|/// Drop all references in preparation to destroy the GlobalVariable. This
comment|/// drops not only the reference to the initializer but also to any metadata.
name|void
name|dropAllReferences
parameter_list|()
function_decl|;
comment|/// Attach a DIGlobalVariableExpression.
name|void
name|addDebugInfo
parameter_list|(
name|DIGlobalVariableExpression
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// Fill the vector with all debug info attachements.
name|void
name|getDebugInfo
argument_list|(
name|SmallVectorImpl
operator|<
name|DIGlobalVariableExpression
operator|*
operator|>
operator|&
name|GVs
argument_list|)
decl|const
decl_stmt|;
comment|/// Add attribute to this global.
name|void
name|addAttribute
argument_list|(
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
block|{
name|Attrs
operator|=
name|Attrs
operator|.
name|addAttribute
argument_list|(
name|getContext
argument_list|()
argument_list|,
name|Kind
argument_list|)
expr_stmt|;
block|}
comment|/// Add attribute to this global.
name|void
name|addAttribute
parameter_list|(
name|StringRef
name|Kind
parameter_list|,
name|StringRef
name|Val
init|=
name|StringRef
argument_list|()
parameter_list|)
block|{
name|Attrs
operator|=
name|Attrs
operator|.
name|addAttribute
argument_list|(
name|getContext
argument_list|()
argument_list|,
name|Kind
argument_list|,
name|Val
argument_list|)
expr_stmt|;
block|}
comment|/// Return true if the attribute exists.
name|bool
name|hasAttribute
argument_list|(
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
decl|const
block|{
return|return
name|Attrs
operator|.
name|hasAttribute
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Return true if the attribute exists.
name|bool
name|hasAttribute
argument_list|(
name|StringRef
name|Kind
argument_list|)
decl|const
block|{
return|return
name|Attrs
operator|.
name|hasAttribute
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Return true if any attributes exist.
name|bool
name|hasAttributes
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|hasAttributes
argument_list|()
return|;
block|}
comment|/// Return the attribute object.
name|Attribute
name|getAttribute
argument_list|(
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
decl|const
block|{
return|return
name|Attrs
operator|.
name|getAttribute
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Return the attribute object.
name|Attribute
name|getAttribute
argument_list|(
name|StringRef
name|Kind
argument_list|)
decl|const
block|{
return|return
name|Attrs
operator|.
name|getAttribute
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Return the attribute set for this global
name|AttributeSet
name|getAttributes
argument_list|()
specifier|const
block|{
return|return
name|Attrs
return|;
block|}
comment|/// Return attribute set as list with index.
comment|/// FIXME: This may not be required once ValueEnumerators
comment|/// in bitcode-writer can enumerate attribute-set.
name|AttributeList
name|getAttributesAsList
argument_list|(
name|unsigned
name|index
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|hasAttributes
argument_list|()
condition|)
return|return
name|AttributeList
argument_list|()
return|;
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|AttributeSet
operator|>
name|AS
index|[
literal|1
index|]
operator|=
block|{
block|{
name|index
block|,
name|Attrs
block|}
block|}
expr_stmt|;
return|return
name|AttributeList
operator|::
name|get
argument_list|(
name|getContext
argument_list|()
argument_list|,
name|AS
argument_list|)
return|;
block|}
comment|/// Set attribute list for this global
name|void
name|setAttributes
parameter_list|(
name|AttributeSet
name|A
parameter_list|)
block|{
name|Attrs
operator|=
name|A
expr_stmt|;
block|}
comment|/// Check if section name is present
name|bool
name|hasImplicitSection
argument_list|()
specifier|const
block|{
return|return
name|getAttributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
literal|"bss-section"
argument_list|)
operator|||
name|getAttributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
literal|"data-section"
argument_list|)
operator|||
name|getAttributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
literal|"rodata-section"
argument_list|)
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
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
name|GlobalVariable
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_GLOBALVARIABLE_H
end_comment

end_unit

