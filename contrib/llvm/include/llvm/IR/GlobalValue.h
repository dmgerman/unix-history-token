begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/GlobalValue.h - Class to represent a global value --*- C++ -*-===//
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
comment|// This file is a common base class of all globally definable objects.  As such,
end_comment

begin_comment
comment|// it is subclassed by GlobalVariable, GlobalAlias and by Function.  This is
end_comment

begin_comment
comment|// used because you can do certain things with these global objects that you
end_comment

begin_comment
comment|// can't do to anything else.  For example, use the address of one as a
end_comment

begin_comment
comment|// constant.
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
name|LLVM_IR_GLOBALVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GLOBALVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PointerType
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GlobalValue
range|:
name|public
name|Constant
block|{
name|GlobalValue
argument_list|(
argument|const GlobalValue&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// @brief An enumeration for the kinds of linkage for global values.
expr|enum
name|LinkageTypes
block|{
name|ExternalLinkage
operator|=
literal|0
block|,
comment|///< Externally visible function
name|AvailableExternallyLinkage
block|,
comment|///< Available for inspection, not emission.
name|LinkOnceAnyLinkage
block|,
comment|///< Keep one copy of function when linking (inline)
name|LinkOnceODRLinkage
block|,
comment|///< Same, but only replaced by something equivalent.
name|WeakAnyLinkage
block|,
comment|///< Keep one copy of named function when linking (weak)
name|WeakODRLinkage
block|,
comment|///< Same, but only replaced by something equivalent.
name|AppendingLinkage
block|,
comment|///< Special purpose, only applies to global arrays
name|InternalLinkage
block|,
comment|///< Rename collisions when linking (static functions).
name|PrivateLinkage
block|,
comment|///< Like Internal, but omit from symbol table.
name|LinkerPrivateLinkage
block|,
comment|///< Like Private, but linker removes.
name|LinkerPrivateWeakLinkage
block|,
comment|///< Like LinkerPrivate, but weak.
name|DLLImportLinkage
block|,
comment|///< Function to be imported from DLL
name|DLLExportLinkage
block|,
comment|///< Function to be accessible from DLL.
name|ExternalWeakLinkage
block|,
comment|///< ExternalWeak linkage description.
name|CommonLinkage
comment|///< Tentative definitions.
block|}
block|;
comment|/// @brief An enumeration for the kinds of visibility of global values.
block|enum
name|VisibilityTypes
block|{
name|DefaultVisibility
operator|=
literal|0
block|,
comment|///< The GV is visible
name|HiddenVisibility
block|,
comment|///< The GV is hidden
name|ProtectedVisibility
comment|///< The GV is protected
block|}
block|;
name|protected
operator|:
name|GlobalValue
argument_list|(
argument|Type *ty
argument_list|,
argument|ValueTy vty
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|LinkageTypes linkage
argument_list|,
argument|const Twine&Name
argument_list|)
operator|:
name|Constant
argument_list|(
name|ty
argument_list|,
name|vty
argument_list|,
name|Ops
argument_list|,
name|NumOps
argument_list|)
block|,
name|Linkage
argument_list|(
name|linkage
argument_list|)
block|,
name|Visibility
argument_list|(
name|DefaultVisibility
argument_list|)
block|,
name|Alignment
argument_list|(
literal|0
argument_list|)
block|,
name|UnnamedAddr
argument_list|(
literal|0
argument_list|)
block|,
name|Parent
argument_list|(
literal|0
argument_list|)
block|{
name|setName
argument_list|(
name|Name
argument_list|)
block|;   }
comment|// Note: VC++ treats enums as signed, so an extra bit is required to prevent
comment|// Linkage and Visibility from turning into negative values.
name|LinkageTypes
name|Linkage
operator|:
literal|5
block|;
comment|// The linkage of this global
name|unsigned
name|Visibility
operator|:
literal|2
block|;
comment|// The visibility style of this global
name|unsigned
name|Alignment
operator|:
literal|16
block|;
comment|// Alignment of this symbol, must be power of two
name|unsigned
name|UnnamedAddr
operator|:
literal|1
block|;
comment|// This value's address is not significant
name|Module
operator|*
name|Parent
block|;
comment|// The containing module.
name|std
operator|::
name|string
name|Section
block|;
comment|// Section to emit this into, empty mean default
name|public
operator|:
operator|~
name|GlobalValue
argument_list|()
block|{
name|removeDeadConstantUsers
argument_list|()
block|;
comment|// remove any dead constants using this.
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1u
operator|<<
name|Alignment
operator|)
operator|>>
literal|1
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Align
argument_list|)
block|;
name|bool
name|hasUnnamedAddr
argument_list|()
specifier|const
block|{
return|return
name|UnnamedAddr
return|;
block|}
name|void
name|setUnnamedAddr
argument_list|(
argument|bool Val
argument_list|)
block|{
name|UnnamedAddr
operator|=
name|Val
block|; }
name|VisibilityTypes
name|getVisibility
argument_list|()
specifier|const
block|{
return|return
name|VisibilityTypes
argument_list|(
name|Visibility
argument_list|)
return|;
block|}
name|bool
name|hasDefaultVisibility
argument_list|()
specifier|const
block|{
return|return
name|Visibility
operator|==
name|DefaultVisibility
return|;
block|}
name|bool
name|hasHiddenVisibility
argument_list|()
specifier|const
block|{
return|return
name|Visibility
operator|==
name|HiddenVisibility
return|;
block|}
name|bool
name|hasProtectedVisibility
argument_list|()
specifier|const
block|{
return|return
name|Visibility
operator|==
name|ProtectedVisibility
return|;
block|}
name|void
name|setVisibility
argument_list|(
argument|VisibilityTypes V
argument_list|)
block|{
name|Visibility
operator|=
name|V
block|; }
name|bool
name|hasSection
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Section
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getSection
argument_list|()
specifier|const
block|{
return|return
name|Section
return|;
block|}
name|void
name|setSection
argument_list|(
argument|StringRef S
argument_list|)
block|{
name|Section
operator|=
name|S
block|; }
comment|/// If the usage is empty (except transitively dead constants), then this
comment|/// global value can be safely deleted since the destructor will
comment|/// delete the dead constants as well.
comment|/// @brief Determine if the usage of this global value is empty except
comment|/// for transitively dead constants.
name|bool
name|use_empty_except_constants
argument_list|()
block|;
comment|/// getType - Global values are always pointers.
specifier|inline
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|User
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
specifier|static
name|LinkageTypes
name|getLinkOnceLinkage
argument_list|(
argument|bool ODR
argument_list|)
block|{
return|return
name|ODR
operator|?
name|LinkOnceODRLinkage
operator|:
name|LinkOnceAnyLinkage
return|;
block|}
specifier|static
name|LinkageTypes
name|getWeakLinkage
argument_list|(
argument|bool ODR
argument_list|)
block|{
return|return
name|ODR
condition|?
name|WeakODRLinkage
else|:
name|WeakAnyLinkage
return|;
block|}
specifier|static
name|bool
name|isExternalLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|ExternalLinkage
return|;
block|}
specifier|static
name|bool
name|isAvailableExternallyLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|AvailableExternallyLinkage
return|;
block|}
specifier|static
name|bool
name|isLinkOnceLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|LinkOnceAnyLinkage
operator|||
name|Linkage
operator|==
name|LinkOnceODRLinkage
return|;
block|}
specifier|static
name|bool
name|isWeakLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|WeakAnyLinkage
operator|||
name|Linkage
operator|==
name|WeakODRLinkage
return|;
block|}
specifier|static
name|bool
name|isAppendingLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|AppendingLinkage
return|;
block|}
specifier|static
name|bool
name|isInternalLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|InternalLinkage
return|;
block|}
specifier|static
name|bool
name|isPrivateLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|PrivateLinkage
return|;
block|}
specifier|static
name|bool
name|isLinkerPrivateLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|LinkerPrivateLinkage
return|;
block|}
specifier|static
name|bool
name|isLinkerPrivateWeakLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|LinkerPrivateWeakLinkage
return|;
block|}
specifier|static
name|bool
name|isLocalLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|isInternalLinkage
argument_list|(
name|Linkage
argument_list|)
operator|||
name|isPrivateLinkage
argument_list|(
name|Linkage
argument_list|)
operator|||
name|isLinkerPrivateLinkage
argument_list|(
name|Linkage
argument_list|)
operator|||
name|isLinkerPrivateWeakLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isDLLImportLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|DLLImportLinkage
return|;
block|}
specifier|static
name|bool
name|isDLLExportLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|DLLExportLinkage
return|;
block|}
specifier|static
name|bool
name|isExternalWeakLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|ExternalWeakLinkage
return|;
block|}
specifier|static
name|bool
name|isCommonLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|CommonLinkage
return|;
block|}
comment|/// isDiscardableIfUnused - Whether the definition of this global may be
comment|/// discarded if it is not used in its compilation unit.
specifier|static
name|bool
name|isDiscardableIfUnused
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|isLinkOnceLinkage
argument_list|(
name|Linkage
argument_list|)
operator|||
name|isLocalLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
comment|/// mayBeOverridden - Whether the definition of this global may be replaced
comment|/// by something non-equivalent at link time.  For example, if a function has
comment|/// weak linkage then the code defining it may be replaced by different code.
specifier|static
name|bool
name|mayBeOverridden
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|WeakAnyLinkage
operator|||
name|Linkage
operator|==
name|LinkOnceAnyLinkage
operator|||
name|Linkage
operator|==
name|CommonLinkage
operator|||
name|Linkage
operator|==
name|ExternalWeakLinkage
operator|||
name|Linkage
operator|==
name|LinkerPrivateWeakLinkage
return|;
block|}
comment|/// isWeakForLinker - Whether the definition of this global may be replaced at
comment|/// link time.  NB: Using this method outside of the code generators is almost
comment|/// always a mistake: when working at the IR level use mayBeOverridden instead
comment|/// as it knows about ODR semantics.
specifier|static
name|bool
name|isWeakForLinker
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|AvailableExternallyLinkage
operator|||
name|Linkage
operator|==
name|WeakAnyLinkage
operator|||
name|Linkage
operator|==
name|WeakODRLinkage
operator|||
name|Linkage
operator|==
name|LinkOnceAnyLinkage
operator|||
name|Linkage
operator|==
name|LinkOnceODRLinkage
operator|||
name|Linkage
operator|==
name|CommonLinkage
operator|||
name|Linkage
operator|==
name|ExternalWeakLinkage
operator|||
name|Linkage
operator|==
name|LinkerPrivateWeakLinkage
return|;
block|}
name|bool
name|hasExternalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isExternalLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasAvailableExternallyLinkage
argument_list|()
specifier|const
block|{
return|return
name|isAvailableExternallyLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasLinkOnceLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLinkOnceLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasWeakLinkage
argument_list|()
specifier|const
block|{
return|return
name|isWeakLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasAppendingLinkage
argument_list|()
specifier|const
block|{
return|return
name|isAppendingLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasInternalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isInternalLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasPrivateLinkage
argument_list|()
specifier|const
block|{
return|return
name|isPrivateLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasLinkerPrivateLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLinkerPrivateLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasLinkerPrivateWeakLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLinkerPrivateWeakLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasLocalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLocalLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasDLLImportLinkage
argument_list|()
specifier|const
block|{
return|return
name|isDLLImportLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasDLLExportLinkage
argument_list|()
specifier|const
block|{
return|return
name|isDLLExportLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasExternalWeakLinkage
argument_list|()
specifier|const
block|{
return|return
name|isExternalWeakLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasCommonLinkage
argument_list|()
specifier|const
block|{
return|return
name|isCommonLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|void
name|setLinkage
argument_list|(
argument|LinkageTypes LT
argument_list|)
block|{
name|Linkage
operator|=
name|LT
block|; }
name|LinkageTypes
name|getLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
return|;
block|}
name|bool
name|isDiscardableIfUnused
argument_list|()
specifier|const
block|{
return|return
name|isDiscardableIfUnused
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|mayBeOverridden
argument_list|()
specifier|const
block|{
return|return
name|mayBeOverridden
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|isWeakForLinker
argument_list|()
specifier|const
block|{
return|return
name|isWeakForLinker
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
comment|/// copyAttributesFrom - copy all additional attributes (those not needed to
comment|/// create a GlobalValue) from the GlobalValue Src to this one.
name|virtual
name|void
name|copyAttributesFrom
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|Src
argument_list|)
block|;
comment|/// getRealLinkageName - If special LLVM prefix that is used to inform the asm
comment|/// printer to not emit usual symbol prefix before the symbol name is used
comment|/// then return linkage name after skipping this special LLVM prefix.
specifier|static
name|StringRef
name|getRealLinkageName
argument_list|(
argument|StringRef Name
argument_list|)
block|{
if|if
condition|(
operator|!
name|Name
operator|.
name|empty
argument_list|()
operator|&&
name|Name
index|[
literal|0
index|]
operator|==
literal|'\1'
condition|)
return|return
name|Name
operator|.
name|substr
argument_list|(
literal|1
argument_list|)
return|;
return|return
name|Name
return|;
block|}
comment|/// @name Materialization
comment|/// Materialization is used to construct functions only as they're needed. This
comment|/// is useful to reduce memory usage in LLVM or parsing work done by the
comment|/// BitcodeReader to load the Module.
comment|/// @{
comment|/// isMaterializable - If this function's Module is being lazily streamed in
comment|/// functions from disk or some other source, this method can be used to check
comment|/// to see if the function has been read in yet or not.
name|bool
name|isMaterializable
argument_list|()
specifier|const
expr_stmt|;
comment|/// isDematerializable - Returns true if this function was loaded from a
comment|/// GVMaterializer that's still attached to its Module and that knows how to
comment|/// dematerialize the function.
name|bool
name|isDematerializable
argument_list|()
specifier|const
expr_stmt|;
comment|/// Materialize - make sure this GlobalValue is fully read.  If the module is
comment|/// corrupt, this returns true and fills in the optional string with
comment|/// information about the problem.  If successful, this returns false.
name|bool
name|Materialize
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrInfo
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Dematerialize - If this GlobalValue is read in, and if the GVMaterializer
comment|/// supports it, release the memory for the function, and set it up to be
comment|/// materialized lazily.  If !isDematerializable(), this method is a noop.
name|void
name|Dematerialize
parameter_list|()
function_decl|;
comment|/// @}
comment|/// Override from Constant class.
name|virtual
name|void
name|destroyConstant
parameter_list|()
function_decl|;
comment|/// isDeclaration - Return true if the primary definition of this global
comment|/// value is outside of the current translation unit.
name|bool
name|isDeclaration
argument_list|()
specifier|const
expr_stmt|;
comment|/// removeFromParent - This method unlinks 'this' from the containing module,
comment|/// but does not delete it.
name|virtual
name|void
name|removeFromParent
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing module
comment|/// and deletes it.
name|virtual
name|void
name|eraseFromParent
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// getParent - Get the module that this global value is contained inside
comment|/// of...
specifier|inline
name|Module
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|Parent
return|;
block|}
specifier|inline
specifier|const
name|Module
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
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
name|FunctionVal
operator|||
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalVariableVal
operator|||
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

