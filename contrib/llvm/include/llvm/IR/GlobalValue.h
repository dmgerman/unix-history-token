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

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Comdat
decl_stmt|;
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
comment|/// @brief Storage classes of global values for PE targets.
block|enum
name|DLLStorageClassTypes
block|{
name|DefaultStorageClass
operator|=
literal|0
block|,
name|DLLImportStorageClass
operator|=
literal|1
block|,
comment|///< Function to be imported from DLL
name|DLLExportStorageClass
operator|=
literal|2
comment|///< Function to be accessible from DLL.
block|}
block|;
name|protected
operator|:
name|GlobalValue
argument_list|(
argument|Type *Ty
argument_list|,
argument|ValueTy VTy
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|const Twine&Name
argument_list|)
operator|:
name|Constant
argument_list|(
name|Ty
argument_list|,
name|VTy
argument_list|,
name|Ops
argument_list|,
name|NumOps
argument_list|)
block|,
name|Linkage
argument_list|(
name|Linkage
argument_list|)
block|,
name|Visibility
argument_list|(
name|DefaultVisibility
argument_list|)
block|,
name|UnnamedAddr
argument_list|(
literal|0
argument_list|)
block|,
name|DllStorageClass
argument_list|(
name|DefaultStorageClass
argument_list|)
block|,
name|ThreadLocal
argument_list|(
name|NotThreadLocal
argument_list|)
block|,
name|Parent
argument_list|(
argument|nullptr
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
name|UnnamedAddr
operator|:
literal|1
block|;
comment|// This value's address is not significant
name|unsigned
name|DllStorageClass
operator|:
literal|2
block|;
comment|// DLL storage class
name|unsigned
name|ThreadLocal
operator|:
literal|3
block|;
comment|// Is this symbol "Thread Local", if so, what is
comment|// the desired model?
name|private
operator|:
comment|// Give subclasses access to what otherwise would be wasted padding.
comment|// (19 + 3 + 2 + 1 + 2 + 5) == 32.
name|unsigned
name|SubClassData
operator|:
literal|19
block|;
name|protected
operator|:
specifier|static
specifier|const
name|unsigned
name|GlobalValueSubClassDataBits
operator|=
literal|19
block|;
name|unsigned
name|getGlobalValueSubClassData
argument_list|()
specifier|const
block|{
return|return
name|SubClassData
return|;
block|}
name|void
name|setGlobalValueSubClassData
argument_list|(
argument|unsigned V
argument_list|)
block|{
name|assert
argument_list|(
name|V
operator|<
operator|(
literal|1
operator|<<
literal|19
operator|)
operator|&&
literal|"It will not fit"
argument_list|)
block|;
name|SubClassData
operator|=
name|V
block|;   }
name|Module
operator|*
name|Parent
block|;
comment|// The containing module.
name|public
operator|:
expr|enum
name|ThreadLocalMode
block|{
name|NotThreadLocal
operator|=
literal|0
block|,
name|GeneralDynamicTLSModel
block|,
name|LocalDynamicTLSModel
block|,
name|InitialExecTLSModel
block|,
name|LocalExecTLSModel
block|}
block|;
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
name|bool
name|hasComdat
argument_list|()
specifier|const
block|{
return|return
name|getComdat
argument_list|()
operator|!=
name|nullptr
return|;
block|}
name|Comdat
operator|*
name|getComdat
argument_list|()
block|;
specifier|const
name|Comdat
operator|*
name|getComdat
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|GlobalValue
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getComdat
argument_list|()
return|;
block|}
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
name|assert
argument_list|(
operator|(
operator|!
name|hasLocalLinkage
argument_list|()
operator|||
name|V
operator|==
name|DefaultVisibility
operator|)
operator|&&
literal|"local linkage requires default visibility"
argument_list|)
block|;
name|Visibility
operator|=
name|V
block|;   }
comment|/// If the value is "Thread Local", its value isn't shared by the threads.
name|bool
name|isThreadLocal
argument_list|()
specifier|const
block|{
return|return
name|getThreadLocalMode
argument_list|()
operator|!=
name|NotThreadLocal
return|;
block|}
name|void
name|setThreadLocal
argument_list|(
argument|bool Val
argument_list|)
block|{
name|setThreadLocalMode
argument_list|(
name|Val
operator|?
name|GeneralDynamicTLSModel
operator|:
name|NotThreadLocal
argument_list|)
block|;   }
name|void
name|setThreadLocalMode
argument_list|(
argument|ThreadLocalMode Val
argument_list|)
block|{
name|assert
argument_list|(
name|Val
operator|==
name|NotThreadLocal
operator|||
name|getValueID
argument_list|()
operator|!=
name|Value
operator|::
name|FunctionVal
argument_list|)
block|;
name|ThreadLocal
operator|=
name|Val
block|;   }
name|ThreadLocalMode
name|getThreadLocalMode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ThreadLocalMode
operator|>
operator|(
name|ThreadLocal
operator|)
return|;
block|}
name|DLLStorageClassTypes
name|getDLLStorageClass
argument_list|()
specifier|const
block|{
return|return
name|DLLStorageClassTypes
argument_list|(
name|DllStorageClass
argument_list|)
return|;
block|}
name|bool
name|hasDLLImportStorageClass
argument_list|()
specifier|const
block|{
return|return
name|DllStorageClass
operator|==
name|DLLImportStorageClass
return|;
block|}
name|bool
name|hasDLLExportStorageClass
argument_list|()
specifier|const
block|{
return|return
name|DllStorageClass
operator|==
name|DLLExportStorageClass
return|;
block|}
name|void
name|setDLLStorageClass
argument_list|(
argument|DLLStorageClassTypes C
argument_list|)
block|{
name|DllStorageClass
operator|=
name|C
block|; }
name|bool
name|hasSection
argument_list|()
specifier|const
block|{
return|return
operator|!
name|StringRef
argument_list|(
name|getSection
argument_list|()
argument_list|)
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// It is unfortunate that we have to use "char *" in here since this is
comment|// always non NULL, but:
comment|// * The C API expects a null terminated string, so we cannot use StringRef.
comment|// * The C API expects us to own it, so we cannot use a std:string.
comment|// * For GlobalAliases we can fail to find the section and we have to
comment|//   return "", so we cannot use a "const std::string&".
specifier|const
name|char
operator|*
name|getSection
argument_list|()
specifier|const
block|;
comment|/// Global values are always pointers.
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
condition|?
name|LinkOnceODRLinkage
else|:
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
name|isLinkOnceODRLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|LinkOnceODRLinkage
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
name|isWeakAnyLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|WeakAnyLinkage
return|;
block|}
specifier|static
name|bool
name|isWeakODRLinkage
argument_list|(
argument|LinkageTypes Linkage
argument_list|)
block|{
return|return
name|Linkage
operator|==
name|WeakODRLinkage
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
name|isWeakAnyLinkage
argument_list|(
name|Linkage
argument_list|)
operator|||
name|isWeakODRLinkage
argument_list|(
name|Linkage
argument_list|)
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
comment|/// Whether the definition of this global may be discarded if it is not used
comment|/// in its compilation unit.
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
comment|/// Whether the definition of this global may be replaced by something
comment|/// non-equivalent at link time. For example, if a function has weak linkage
comment|/// then the code defining it may be replaced by different code.
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
return|;
block|}
comment|/// Whether the definition of this global may be replaced at link time.  NB:
comment|/// Using this method outside of the code generators is almost always a
comment|/// mistake: when working at the IR level use mayBeOverridden instead as it
comment|/// knows about ODR semantics.
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
name|hasLinkOnceODRLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLinkOnceODRLinkage
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
name|hasWeakAnyLinkage
argument_list|()
specifier|const
block|{
return|return
name|isWeakAnyLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
name|bool
name|hasWeakODRLinkage
argument_list|()
specifier|const
block|{
return|return
name|isWeakODRLinkage
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
if|if
condition|(
name|isLocalLinkage
argument_list|(
name|LT
argument_list|)
condition|)
name|Visibility
operator|=
name|DefaultVisibility
expr_stmt|;
name|Linkage
operator|=
name|LT
block|;   }
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
comment|/// Copy all additional attributes (those not needed to create a GlobalValue)
comment|/// from the GlobalValue Src to this one.
name|virtual
name|void
name|copyAttributesFrom
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|Src
parameter_list|)
function_decl|;
comment|/// If special LLVM prefix that is used to inform the asm printer to not emit
comment|/// usual symbol prefix before the symbol name is used then return linkage
comment|/// name after skipping this special LLVM prefix.
specifier|static
name|StringRef
name|getRealLinkageName
parameter_list|(
name|StringRef
name|Name
parameter_list|)
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
comment|/// If this function's Module is being lazily streamed in functions from disk
comment|/// or some other source, this method can be used to check to see if the
comment|/// function has been read in yet or not.
name|bool
name|isMaterializable
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if this function was loaded from a GVMaterializer that's
comment|/// still attached to its Module and that knows how to dematerialize the
comment|/// function.
name|bool
name|isDematerializable
argument_list|()
specifier|const
expr_stmt|;
comment|/// Make sure this GlobalValue is fully read. If the module is corrupt, this
comment|/// returns true and fills in the optional string with information about the
comment|/// problem.  If successful, this returns false.
name|std
operator|::
name|error_code
name|materialize
argument_list|()
expr_stmt|;
comment|/// If this GlobalValue is read in, and if the GVMaterializer supports it,
comment|/// release the memory for the function, and set it up to be materialized
comment|/// lazily. If !isDematerializable(), this method is a noop.
name|void
name|Dematerialize
parameter_list|()
function_decl|;
comment|/// @}
comment|/// Override from Constant class.
name|void
name|destroyConstant
argument_list|()
name|override
expr_stmt|;
comment|/// Return true if the primary definition of this global value is outside of
comment|/// the current translation unit.
name|bool
name|isDeclaration
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDeclarationForLinker
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasAvailableExternallyLinkage
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|isDeclaration
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// This method unlinks 'this' from the containing module, but does not delete
end_comment

begin_comment
comment|/// it.
end_comment

begin_function_decl
name|virtual
name|void
name|removeFromParent
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// This method unlinks 'this' from the containing module and deletes it.
end_comment

begin_function_decl
name|virtual
name|void
name|eraseFromParent
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// Get the module that this global value is contained inside of...
end_comment

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
end_comment

begin_function
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
end_function

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

