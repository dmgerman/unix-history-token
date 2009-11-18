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
name|LLVM_GLOBALVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_GLOBALVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Constant.h"
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
specifier|const
name|GlobalValue
operator|&
argument_list|)
block|;
comment|// do not implement
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
name|DLLImportLinkage
block|,
comment|///< Function to be imported from DLL
name|DLLExportLinkage
block|,
comment|///< Function to be accessible from DLL.
name|ExternalWeakLinkage
block|,
comment|///< ExternalWeak linkage description.
name|GhostLinkage
block|,
comment|///< Stand-in functions for streaming fns from BC files.
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
argument|const Type *ty
argument_list|,
argument|ValueTy vty
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|LinkageTypes linkage
argument_list|,
argument|const Twine&Name =
literal|""
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
name|Parent
argument_list|(
literal|0
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
block|{
name|setName
argument_list|(
name|Name
argument_list|)
block|;   }
name|Module
operator|*
name|Parent
block|;
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
name|Alignment
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Align
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Align
operator|&
operator|(
name|Align
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|&&
literal|"Alignment is not a power of 2!"
argument_list|)
block|;
name|Alignment
operator|=
name|Align
block|;   }
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
comment|/// global value can can be safely deleted since the destructor will
comment|/// delete the dead constants as well.
comment|/// @brief Determine if the usage of this global value is empty except
comment|/// for transitively dead constants.
name|bool
name|use_empty_except_constants
argument_list|()
block|;
comment|/// getType - Global values are always pointers.
specifier|inline
specifier|const
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|PointerType
operator|*
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
name|bool
name|hasExternalLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|ExternalLinkage
return|;
block|}
name|bool
name|hasAvailableExternallyLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|AvailableExternallyLinkage
return|;
block|}
name|bool
name|hasLinkOnceLinkage
argument_list|()
specifier|const
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
name|bool
name|hasWeakLinkage
argument_list|()
specifier|const
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
name|bool
name|hasAppendingLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|AppendingLinkage
return|;
block|}
name|bool
name|hasInternalLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|InternalLinkage
return|;
block|}
name|bool
name|hasPrivateLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|PrivateLinkage
return|;
block|}
name|bool
name|hasLinkerPrivateLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|LinkerPrivateLinkage
return|;
block|}
name|bool
name|hasLocalLinkage
argument_list|()
specifier|const
block|{
return|return
name|hasInternalLinkage
argument_list|()
operator|||
name|hasPrivateLinkage
argument_list|()
operator|||
name|hasLinkerPrivateLinkage
argument_list|()
return|;
block|}
name|bool
name|hasDLLImportLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|DLLImportLinkage
return|;
block|}
name|bool
name|hasDLLExportLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|DLLExportLinkage
return|;
block|}
name|bool
name|hasExternalWeakLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|ExternalWeakLinkage
return|;
block|}
name|bool
name|hasGhostLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|GhostLinkage
return|;
block|}
name|bool
name|hasCommonLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|CommonLinkage
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
comment|/// mayBeOverridden - Whether the definition of this global may be replaced
comment|/// by something non-equivalent at link time.  For example, if a function has
comment|/// weak linkage then the code defining it may be replaced by different code.
name|bool
name|mayBeOverridden
argument_list|()
specifier|const
block|{
return|return
operator|(
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
operator|)
return|;
block|}
comment|/// isWeakForLinker - Whether the definition of this global may be replaced at
comment|/// link time.
name|bool
name|isWeakForLinker
argument_list|()
specifier|const
block|{
return|return
operator|(
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
operator|)
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
comment|/// hasNotBeenReadFromBitcode - If a module provider is being used to lazily
comment|/// stream in functions from disk, this method can be used to check to see if
comment|/// the function has been read in yet or not.  Unless you are working on the
comment|/// JIT or something else that streams stuff in lazily, you don't need to
comment|/// worry about this.
name|bool
name|hasNotBeenReadFromBitcode
argument_list|()
specifier|const
block|{
return|return
name|Linkage
operator|==
name|GhostLinkage
return|;
block|}
comment|/// Override from Constant class. No GlobalValue's are null values so this
comment|/// always returns false.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Override from Constant class.
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// isDeclaration - Return true if the primary definition of this global
comment|/// value is outside of the current translation unit...
name|virtual
name|bool
name|isDeclaration
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// removeFromParent - This method unlinks 'this' from the containing module,
comment|/// but does not delete it.
name|virtual
name|void
name|removeFromParent
argument_list|()
operator|=
literal|0
block|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing module
comment|/// and deletes it.
name|virtual
name|void
name|eraseFromParent
argument_list|()
operator|=
literal|0
block|;
comment|/// getParent - Get the module that this global value is contained inside
comment|/// of...
specifier|inline
name|Module
operator|*
name|getParent
argument_list|()
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
comment|/// removeDeadConstantUsers - If there are any dead constant users dangling
comment|/// off of this global value, remove them.  This method is useful for clients
comment|/// that want to check to see if a global is unused, but don't want to deal
comment|/// with potentially dead constants hanging off of the globals.
name|void
name|removeDeadConstantUsers
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const GlobalValue *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
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
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

