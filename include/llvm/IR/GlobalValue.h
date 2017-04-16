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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

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
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MD5.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Comdat
decl_stmt|;
name|class
name|ConstantRange
decl_stmt|;
name|class
name|Error
decl_stmt|;
name|class
name|GlobalObject
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|namespace
name|Intrinsic
block|{
enum_decl|enum
name|ID
enum_decl|:
name|unsigned
enum_decl|;
block|}
comment|// end namespace Intrinsic
name|class
name|GlobalValue
range|:
name|public
name|Constant
block|{
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
argument_list|,
argument|unsigned AddressSpace
argument_list|)
operator|:
name|Constant
argument_list|(
name|PointerType
operator|::
name|get
argument_list|(
name|Ty
argument_list|,
name|AddressSpace
argument_list|)
argument_list|,
name|VTy
argument_list|,
name|Ops
argument_list|,
name|NumOps
argument_list|)
block|,
name|ValueType
argument_list|(
name|Ty
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
name|UnnamedAddrVal
argument_list|(
name|unsigned
argument_list|(
name|UnnamedAddr
operator|::
name|None
argument_list|)
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
name|HasLLVMReservedName
argument_list|(
name|false
argument_list|)
block|,
name|IntID
argument_list|(
operator|(
name|Intrinsic
operator|::
name|ID
operator|)
literal|0U
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
name|Type
operator|*
name|ValueType
block|;
specifier|static
specifier|const
name|unsigned
name|GlobalValueSubClassDataBits
operator|=
literal|18
block|;
comment|// All bitfields use unsigned as the underlying type so that MSVC will pack
comment|// them.
name|unsigned
name|Linkage
operator|:
literal|4
block|;
comment|// The linkage of this global
name|unsigned
name|Visibility
operator|:
literal|2
block|;
comment|// The visibility style of this global
name|unsigned
name|UnnamedAddrVal
operator|:
literal|2
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
comment|/// True if the function's name starts with "llvm.".  This corresponds to the
comment|/// value of Function::isIntrinsic(), which may be true even if
comment|/// Function::intrinsicID() returns Intrinsic::not_intrinsic.
name|unsigned
name|HasLLVMReservedName
operator|:
literal|1
block|;
name|private
operator|:
name|friend
name|class
name|Constant
block|;
comment|// Give subclasses access to what otherwise would be wasted padding.
comment|// (18 + 4 + 2 + 2 + 2 + 3 + 1) == 32.
name|unsigned
name|SubClassData
operator|:
name|GlobalValueSubClassDataBits
block|;
name|void
name|destroyConstantImpl
argument_list|()
block|;
name|Value
operator|*
name|handleOperandChangeImpl
argument_list|(
name|Value
operator|*
name|From
argument_list|,
name|Value
operator|*
name|To
argument_list|)
block|;
comment|/// Returns true if the definition of this global may be replaced by a
comment|/// differently optimized variant of the same source level function at link
comment|/// time.
name|bool
name|mayBeDerefined
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getLinkage
argument_list|()
condition|)
block|{
case|case
name|WeakODRLinkage
case|:
case|case
name|LinkOnceODRLinkage
case|:
case|case
name|AvailableExternallyLinkage
case|:
return|return
name|true
return|;
case|case
name|WeakAnyLinkage
case|:
case|case
name|LinkOnceAnyLinkage
case|:
case|case
name|CommonLinkage
case|:
case|case
name|ExternalWeakLinkage
case|:
case|case
name|ExternalLinkage
case|:
case|case
name|AppendingLinkage
case|:
case|case
name|InternalLinkage
case|:
case|case
name|PrivateLinkage
case|:
return|return
name|isInterposable
argument_list|()
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Fully covered switch above!"
argument_list|)
expr_stmt|;
block|}
name|protected
operator|:
comment|/// \brief The intrinsic ID for this subclass (which must be a Function).
comment|///
comment|/// This member is defined by this class, but not used for anything.
comment|/// Subclasses can use it to store their intrinsic ID, if they have one.
comment|///
comment|/// This is stored here to save space in Function on 64-bit hosts.
name|Intrinsic
operator|::
name|ID
name|IntID
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
name|GlobalValueSubClassDataBits
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
comment|// Used by SymbolTableListTraits.
name|void
name|setParent
argument_list|(
argument|Module *parent
argument_list|)
block|{
name|Parent
operator|=
name|parent
block|;   }
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
name|GlobalValue
argument_list|(
specifier|const
name|GlobalValue
operator|&
argument_list|)
operator|=
name|delete
block|;
operator|~
name|GlobalValue
argument_list|()
name|override
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
block|;    enum
name|class
name|UnnamedAddr
block|{
name|None
block|,
name|Local
block|,
name|Global
block|,   }
block|;
name|bool
name|hasGlobalUnnamedAddr
argument_list|()
specifier|const
block|{
return|return
name|getUnnamedAddr
argument_list|()
operator|==
name|UnnamedAddr
operator|::
name|Global
return|;
block|}
comment|/// Returns true if this value's address is not significant in this module.
comment|/// This attribute is intended to be used only by the code generator and LTO
comment|/// to allow the linker to decide whether the global needs to be in the symbol
comment|/// table. It should probably not be used in optimizations, as the value may
comment|/// have uses outside the module; use hasGlobalUnnamedAddr() instead.
name|bool
name|hasAtLeastLocalUnnamedAddr
argument_list|()
specifier|const
block|{
return|return
name|getUnnamedAddr
argument_list|()
operator|!=
name|UnnamedAddr
operator|::
name|None
return|;
block|}
name|UnnamedAddr
name|getUnnamedAddr
argument_list|()
specifier|const
block|{
return|return
name|UnnamedAddr
argument_list|(
name|UnnamedAddrVal
argument_list|)
return|;
block|}
name|void
name|setUnnamedAddr
argument_list|(
argument|UnnamedAddr Val
argument_list|)
block|{
name|UnnamedAddrVal
operator|=
name|unsigned
argument_list|(
name|Val
argument_list|)
block|; }
specifier|static
name|UnnamedAddr
name|getMinUnnamedAddr
argument_list|(
argument|UnnamedAddr A
argument_list|,
argument|UnnamedAddr B
argument_list|)
block|{
if|if
condition|(
name|A
operator|==
name|UnnamedAddr
operator|::
name|None
operator|||
name|B
operator|==
name|UnnamedAddr
operator|::
name|None
condition|)
return|return
name|UnnamedAddr
operator|::
name|None
return|;
if|if
condition|(
name|A
operator|==
name|UnnamedAddr
operator|::
name|Local
operator|||
name|B
operator|==
name|UnnamedAddr
operator|::
name|Local
condition|)
return|return
name|UnnamedAddr
operator|::
name|Local
return|;
return|return
name|UnnamedAddr
operator|::
name|Global
return|;
block|}
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
specifier|const
name|Comdat
operator|*
name|getComdat
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|Comdat
modifier|*
name|getComdat
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Comdat
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getComdat
argument_list|()
operator|)
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setVisibility
parameter_list|(
name|VisibilityTypes
name|V
parameter_list|)
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
expr_stmt|;
name|Visibility
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// If the value is "Thread Local", its value isn't shared by the threads.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setThreadLocal
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|setThreadLocalMode
argument_list|(
name|Val
condition|?
name|GeneralDynamicTLSModel
else|:
name|NotThreadLocal
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setThreadLocalMode
parameter_list|(
name|ThreadLocalMode
name|Val
parameter_list|)
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
expr_stmt|;
name|ThreadLocal
operator|=
name|Val
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setDLLStorageClass
parameter_list|(
name|DLLStorageClassTypes
name|C
parameter_list|)
block|{
name|DllStorageClass
operator|=
name|C
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|hasSection
argument_list|()
specifier|const
block|{
return|return
operator|!
name|getSection
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|StringRef
name|getSection
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Global values are always pointers.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|Type
operator|*
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|ValueType
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|LinkageTypes
name|getLinkOnceLinkage
parameter_list|(
name|bool
name|ODR
parameter_list|)
block|{
return|return
name|ODR
condition|?
name|LinkOnceODRLinkage
else|:
name|LinkOnceAnyLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|LinkageTypes
name|getWeakLinkage
parameter_list|(
name|bool
name|ODR
parameter_list|)
block|{
return|return
name|ODR
condition|?
name|WeakODRLinkage
else|:
name|WeakAnyLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isExternalLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|ExternalLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isAvailableExternallyLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|AvailableExternallyLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isLinkOnceODRLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|LinkOnceODRLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isLinkOnceLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
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
end_function

begin_function
specifier|static
name|bool
name|isWeakAnyLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|WeakAnyLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isWeakODRLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|WeakODRLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isWeakLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
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
end_function

begin_function
specifier|static
name|bool
name|isAppendingLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|AppendingLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isInternalLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|InternalLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isPrivateLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|PrivateLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isLocalLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
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
end_function

begin_function
specifier|static
name|bool
name|isExternalWeakLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|ExternalWeakLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isCommonLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|Linkage
operator|==
name|CommonLinkage
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isValidDeclarationLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
name|isExternalWeakLinkage
argument_list|(
name|Linkage
argument_list|)
operator|||
name|isExternalLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Whether the definition of this global may be replaced by something
end_comment

begin_comment
comment|/// non-equivalent at link time. For example, if a function has weak linkage
end_comment

begin_comment
comment|/// then the code defining it may be replaced by different code.
end_comment

begin_function
specifier|static
name|bool
name|isInterposableLinkage
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
switch|switch
condition|(
name|Linkage
condition|)
block|{
case|case
name|WeakAnyLinkage
case|:
case|case
name|LinkOnceAnyLinkage
case|:
case|case
name|CommonLinkage
case|:
case|case
name|ExternalWeakLinkage
case|:
return|return
name|true
return|;
case|case
name|AvailableExternallyLinkage
case|:
case|case
name|LinkOnceODRLinkage
case|:
case|case
name|WeakODRLinkage
case|:
comment|// The above three cannot be overridden but can be de-refined.
case|case
name|ExternalLinkage
case|:
case|case
name|AppendingLinkage
case|:
case|case
name|InternalLinkage
case|:
case|case
name|PrivateLinkage
case|:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Fully covered switch above!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether the definition of this global may be discarded if it is not used
end_comment

begin_comment
comment|/// in its compilation unit.
end_comment

begin_function
specifier|static
name|bool
name|isDiscardableIfUnused
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
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
operator|||
name|isAvailableExternallyLinkage
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Whether the definition of this global may be replaced at link time.  NB:
end_comment

begin_comment
comment|/// Using this method outside of the code generators is almost always a
end_comment

begin_comment
comment|/// mistake: when working at the IR level use isInterposable instead as it
end_comment

begin_comment
comment|/// knows about ODR semantics.
end_comment

begin_function
specifier|static
name|bool
name|isWeakForLinker
parameter_list|(
name|LinkageTypes
name|Linkage
parameter_list|)
block|{
return|return
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
end_function

begin_comment
comment|/// Return true if the currently visible definition of this global (if any) is
end_comment

begin_comment
comment|/// exactly the definition we will see at runtime.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Non-exact linkage types inhibits most non-inlining IPO, since a
end_comment

begin_comment
comment|/// differently optimized variant of the same function can have different
end_comment

begin_comment
comment|/// observable or undefined behavior than in the variant currently visible.
end_comment

begin_comment
comment|/// For instance, we could have started with
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   void foo(int *v) {
end_comment

begin_comment
comment|///     int t = 5 / v[0];
end_comment

begin_comment
comment|///     (void) t;
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// and "refined" it to
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   void foo(int *v) { }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// However, we cannot infer readnone for `foo`, since that would justify
end_comment

begin_comment
comment|/// DSE'ing a store to `v[0]` across a call to `foo`, which can cause
end_comment

begin_comment
comment|/// undefined behavior if the linker replaces the actual call destination with
end_comment

begin_comment
comment|/// the unoptimized `foo`.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Inlining is okay across non-exact linkage types as long as they're not
end_comment

begin_comment
comment|/// interposable (see \c isInterposable), since in such cases the currently
end_comment

begin_comment
comment|/// visible variant is *a* correct implementation of the original source
end_comment

begin_comment
comment|/// function; it just isn't the *only* correct implementation.
end_comment

begin_expr_stmt
name|bool
name|isDefinitionExact
argument_list|()
specifier|const
block|{
return|return
operator|!
name|mayBeDerefined
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return true if this global has an exact defintion.
end_comment

begin_expr_stmt
name|bool
name|hasExactDefinition
argument_list|()
specifier|const
block|{
comment|// While this computes exactly the same thing as
comment|// isStrongDefinitionForLinker, the intended uses are different.  This
comment|// function is intended to help decide if specific inter-procedural
comment|// transforms are correct, while isStrongDefinitionForLinker's intended use
comment|// is in low level code generation.
return|return
operator|!
name|isDeclaration
argument_list|()
operator|&&
name|isDefinitionExact
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return true if this global's definition can be substituted with an
end_comment

begin_comment
comment|/// *arbitrary* definition at link time.  We cannot do any IPO or inlinining
end_comment

begin_comment
comment|/// across interposable call edges, since the callee can be replaced with
end_comment

begin_comment
comment|/// something arbitrary at link time.
end_comment

begin_expr_stmt
name|bool
name|isInterposable
argument_list|()
specifier|const
block|{
return|return
name|isInterposableLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasExternalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isExternalLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasAvailableExternallyLinkage
argument_list|()
specifier|const
block|{
return|return
name|isAvailableExternallyLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasLinkOnceLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLinkOnceLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasLinkOnceODRLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLinkOnceODRLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasWeakLinkage
argument_list|()
specifier|const
block|{
return|return
name|isWeakLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasWeakAnyLinkage
argument_list|()
specifier|const
block|{
return|return
name|isWeakAnyLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasWeakODRLinkage
argument_list|()
specifier|const
block|{
return|return
name|isWeakODRLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasAppendingLinkage
argument_list|()
specifier|const
block|{
return|return
name|isAppendingLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasInternalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isInternalLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasPrivateLinkage
argument_list|()
specifier|const
block|{
return|return
name|isPrivateLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasLocalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isLocalLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasExternalWeakLinkage
argument_list|()
specifier|const
block|{
return|return
name|isExternalWeakLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasCommonLinkage
argument_list|()
specifier|const
block|{
return|return
name|isCommonLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasValidDeclarationLinkage
argument_list|()
specifier|const
block|{
return|return
name|isValidDeclarationLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setLinkage
parameter_list|(
name|LinkageTypes
name|LT
parameter_list|)
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
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|LinkageTypes
name|getLinkage
argument_list|()
specifier|const
block|{
return|return
name|LinkageTypes
argument_list|(
name|Linkage
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isDiscardableIfUnused
argument_list|()
specifier|const
block|{
return|return
name|isDiscardableIfUnused
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isWeakForLinker
argument_list|()
specifier|const
block|{
return|return
name|isWeakForLinker
argument_list|(
name|getLinkage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Copy all additional attributes (those not needed to create a GlobalValue)
end_comment

begin_comment
comment|/// from the GlobalValue Src to this one.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// If special LLVM prefix that is used to inform the asm printer to not emit
end_comment

begin_comment
comment|/// usual symbol prefix before the symbol name is used then return linkage
end_comment

begin_comment
comment|/// name after skipping this special LLVM prefix.
end_comment

begin_function
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
end_function

begin_comment
comment|/// Return the modified name for a global value suitable to be
end_comment

begin_comment
comment|/// used as the key for a global lookup (e.g. profile or ThinLTO).
end_comment

begin_comment
comment|/// The value's original name is \c Name and has linkage of type
end_comment

begin_comment
comment|/// \c Linkage. The value is defined in module \c FileName.
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getGlobalIdentifier
argument_list|(
argument|StringRef Name
argument_list|,
argument|GlobalValue::LinkageTypes Linkage
argument_list|,
argument|StringRef FileName
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the modified name for this global value suitable to be
end_comment

begin_comment
comment|/// used as the key for a global lookup (e.g. profile or ThinLTO).
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getGlobalIdentifier
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Declare a type to represent a global unique identifier for a global value.
end_comment

begin_comment
comment|/// This is a 64 bits hash that is used by PGO and ThinLTO to have a compact
end_comment

begin_comment
comment|/// unique way to identify a symbol.
end_comment

begin_decl_stmt
name|using
name|GUID
init|=
name|uint64_t
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a 64-bit global unique ID constructed from global value name
end_comment

begin_comment
comment|/// (i.e. returned by getGlobalIdentifier()).
end_comment

begin_function
specifier|static
name|GUID
name|getGUID
parameter_list|(
name|StringRef
name|GlobalName
parameter_list|)
block|{
return|return
name|MD5Hash
argument_list|(
name|GlobalName
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return a 64-bit global unique ID constructed from global value name
end_comment

begin_comment
comment|/// (i.e. returned by getGlobalIdentifier()).
end_comment

begin_expr_stmt
name|GUID
name|getGUID
argument_list|()
specifier|const
block|{
return|return
name|getGUID
argument_list|(
name|getGlobalIdentifier
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @name Materialization
end_comment

begin_comment
comment|/// Materialization is used to construct functions only as they're needed.
end_comment

begin_comment
comment|/// This
end_comment

begin_comment
comment|/// is useful to reduce memory usage in LLVM or parsing work done by the
end_comment

begin_comment
comment|/// BitcodeReader to load the Module.
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// If this function's Module is being lazily streamed in functions from disk
end_comment

begin_comment
comment|/// or some other source, this method can be used to check to see if the
end_comment

begin_comment
comment|/// function has been read in yet or not.
end_comment

begin_expr_stmt
name|bool
name|isMaterializable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Make sure this GlobalValue is fully read.
end_comment

begin_function_decl
name|Error
name|materialize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// Return true if the primary definition of this global value is outside of
end_comment

begin_comment
comment|/// the current translation unit.
end_comment

begin_expr_stmt
name|bool
name|isDeclaration
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_return
return|return
name|isDeclaration
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Returns true if this global's definition will be the one chosen by the
end_comment

begin_comment
comment|/// linker.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NB! Ideally this should not be used at the IR level at all.  If you're
end_comment

begin_comment
comment|/// interested in optimization constraints implied by the linker's ability to
end_comment

begin_comment
comment|/// choose an implementation, prefer using \c hasExactDefinition.
end_comment

begin_macro
unit|bool
name|isStrongDefinitionForLinker
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
operator|!
operator|(
name|isDeclarationForLinker
argument_list|()
operator|||
name|isWeakForLinker
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns true if the alignment of the value can be unilaterally
end_comment

begin_comment
comment|// increased.
end_comment

begin_expr_stmt
name|bool
name|canIncreaseAlignment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|GlobalObject
operator|*
name|getBaseObject
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|GlobalObject
modifier|*
name|getBaseObject
parameter_list|()
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
name|GlobalValue
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
end_function

begin_comment
comment|/// Returns whether this is a reference to an absolute symbol.
end_comment

begin_expr_stmt
name|bool
name|isAbsoluteSymbolRef
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// If this is an absolute symbol reference, returns the range of the symbol,
end_comment

begin_comment
comment|/// otherwise returns None.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|ConstantRange
operator|>
name|getAbsoluteSymbolRange
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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

begin_comment
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
end_comment

begin_function
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
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_GLOBALVALUE_H
end_comment

end_unit

