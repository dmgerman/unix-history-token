begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjCARCInstKind.h - ARC instruction equivalence classes --*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_OBJCARCINSTKIND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_OBJCARCINSTKIND_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|objcarc
block|{
comment|/// \enum ARCInstKind
comment|///
comment|/// \brief Equivalence classes of instructions in the ARC Model.
comment|///
comment|/// Since we do not have "instructions" to represent ARC concepts in LLVM IR,
comment|/// we instead operate on equivalence classes of instructions.
comment|///
comment|/// TODO: This should be split into two enums: a runtime entry point enum
comment|/// (possibly united with the ARCRuntimeEntrypoint class) and an enum that deals
comment|/// with effects of instructions in the ARC model (which would handle the notion
comment|/// of a User or CallOrUser).
name|enum
name|class
name|ARCInstKind
block|{
name|Retain
operator|,
comment|///< objc_retain
name|RetainRV
operator|,
comment|///< objc_retainAutoreleasedReturnValue
name|ClaimRV
operator|,
comment|///< objc_unsafeClaimAutoreleasedReturnValue
name|RetainBlock
operator|,
comment|///< objc_retainBlock
name|Release
operator|,
comment|///< objc_release
name|Autorelease
operator|,
comment|///< objc_autorelease
name|AutoreleaseRV
operator|,
comment|///< objc_autoreleaseReturnValue
name|AutoreleasepoolPush
operator|,
comment|///< objc_autoreleasePoolPush
name|AutoreleasepoolPop
operator|,
comment|///< objc_autoreleasePoolPop
name|NoopCast
operator|,
comment|///< objc_retainedObject, etc.
name|FusedRetainAutorelease
operator|,
comment|///< objc_retainAutorelease
name|FusedRetainAutoreleaseRV
operator|,
comment|///< objc_retainAutoreleaseReturnValue
name|LoadWeakRetained
operator|,
comment|///< objc_loadWeakRetained (primitive)
name|StoreWeak
operator|,
comment|///< objc_storeWeak (primitive)
name|InitWeak
operator|,
comment|///< objc_initWeak (derived)
name|LoadWeak
operator|,
comment|///< objc_loadWeak (derived)
name|MoveWeak
operator|,
comment|///< objc_moveWeak (derived)
name|CopyWeak
operator|,
comment|///< objc_copyWeak (derived)
name|DestroyWeak
operator|,
comment|///< objc_destroyWeak (derived)
name|StoreStrong
operator|,
comment|///< objc_storeStrong (derived)
name|IntrinsicUser
operator|,
comment|///< clang.arc.use
name|CallOrUser
operator|,
comment|///< could call objc_release and/or "use" pointers
name|Call
operator|,
comment|///< could call objc_release
name|User
operator|,
comment|///< could "use" a pointer
name|None
comment|///< anything that is inert from an ARC perspective.
block|}
empty_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|ARCInstKind
name|Class
operator|)
expr_stmt|;
comment|/// \brief Test if the given class is a kind of user.
name|bool
name|IsUser
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class is objc_retain or equivalent.
name|bool
name|IsRetain
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class is objc_autorelease or equivalent.
name|bool
name|IsAutorelease
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class represents instructions which return their
comment|/// argument verbatim.
name|bool
name|IsForwarding
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class represents instructions which do nothing if
comment|/// passed a null pointer.
name|bool
name|IsNoopOnNull
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class represents instructions which are always safe
comment|/// to mark with the "tail" keyword.
name|bool
name|IsAlwaysTail
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class represents instructions which are never safe
comment|/// to mark with the "tail" keyword.
name|bool
name|IsNeverTail
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Test if the given class represents instructions which are always safe
comment|/// to mark with the nounwind attribute.
name|bool
name|IsNoThrow
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// Test whether the given instruction can autorelease any pointer or cause an
comment|/// autoreleasepool pop.
name|bool
name|CanInterruptRV
parameter_list|(
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// \brief Determine if F is one of the special known Functions.  If it isn't,
comment|/// return ARCInstKind::CallOrUser.
name|ARCInstKind
name|GetFunctionClass
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Determine which objc runtime call instruction class V belongs to.
comment|///
comment|/// This is similar to GetARCInstKind except that it only detects objc
comment|/// runtime calls. This allows it to be faster.
comment|///
specifier|inline
name|ARCInstKind
name|GetBasicARCInstKind
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
if|if
condition|(
specifier|const
name|CallInst
modifier|*
name|CI
init|=
name|dyn_cast
operator|<
name|CallInst
operator|>
operator|(
name|V
operator|)
condition|)
block|{
if|if
condition|(
specifier|const
name|Function
modifier|*
name|F
init|=
name|CI
operator|->
name|getCalledFunction
argument_list|()
condition|)
return|return
name|GetFunctionClass
argument_list|(
name|F
argument_list|)
return|;
comment|// Otherwise, be conservative.
return|return
name|ARCInstKind
operator|::
name|CallOrUser
return|;
block|}
comment|// Otherwise, be conservative.
return|return
name|isa
operator|<
name|InvokeInst
operator|>
operator|(
name|V
operator|)
condition|?
name|ARCInstKind
operator|::
name|CallOrUser
else|:
name|ARCInstKind
operator|::
name|User
return|;
block|}
comment|/// Map V to its ARCInstKind equivalence class.
name|ARCInstKind
name|GetARCInstKind
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Returns false if conservatively we can prove that any instruction mapped to
comment|/// this kind can not decrement ref counts. Returns true otherwise.
name|bool
name|CanDecrementRefCount
parameter_list|(
name|ARCInstKind
name|Kind
parameter_list|)
function_decl|;
block|}
comment|// end namespace objcarc
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

