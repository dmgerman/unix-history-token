begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjCARC.h - ObjC ARC Optimization --------------*- C++ -*-----------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file defines common definitions/declarations used by the ObjC ARC
end_comment

begin_comment
comment|/// Optimizer. ARC stands for Automatic Reference Counting and is a system for
end_comment

begin_comment
comment|/// managing reference counts for objects in Objective C.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about certain library functions. It recognizes them
end_comment

begin_comment
comment|/// by name, and hardwires knowledge of their semantics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about how certain Objective-C library functions are
end_comment

begin_comment
comment|/// used. Naive LLVM IR transformations which would otherwise be
end_comment

begin_comment
comment|/// behavior-preserving may break these assumptions.
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
name|LLVM_TRANSFORMS_SCALAR_OBJCARC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_OBJCARC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ValueTracking.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/InstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/ObjCARC.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/Local.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|objcarc
block|{
comment|/// \brief A handy option to enable/disable all ARC Optimizations.
specifier|extern
name|bool
name|EnableARCOpts
decl_stmt|;
comment|/// \brief Test if the given module looks interesting to run ARC optimization
comment|/// on.
specifier|static
specifier|inline
name|bool
name|ModuleHasARC
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
block|{
return|return
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_retain"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_release"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_autorelease"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_retainAutoreleasedReturnValue"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_retainBlock"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_autoreleaseReturnValue"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_autoreleasePoolPush"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_loadWeakRetained"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_loadWeak"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_destroyWeak"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_storeWeak"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_initWeak"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_moveWeak"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_copyWeak"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_retainedObject"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_unretainedObject"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"objc_unretainedPointer"
argument_list|)
operator|||
name|M
operator|.
name|getNamedValue
argument_list|(
literal|"clang.arc.use"
argument_list|)
return|;
block|}
comment|/// \enum InstructionClass
comment|/// \brief A simple classification for instructions.
enum|enum
name|InstructionClass
block|{
name|IC_Retain
block|,
comment|///< objc_retain
name|IC_RetainRV
block|,
comment|///< objc_retainAutoreleasedReturnValue
name|IC_RetainBlock
block|,
comment|///< objc_retainBlock
name|IC_Release
block|,
comment|///< objc_release
name|IC_Autorelease
block|,
comment|///< objc_autorelease
name|IC_AutoreleaseRV
block|,
comment|///< objc_autoreleaseReturnValue
name|IC_AutoreleasepoolPush
block|,
comment|///< objc_autoreleasePoolPush
name|IC_AutoreleasepoolPop
block|,
comment|///< objc_autoreleasePoolPop
name|IC_NoopCast
block|,
comment|///< objc_retainedObject, etc.
name|IC_FusedRetainAutorelease
block|,
comment|///< objc_retainAutorelease
name|IC_FusedRetainAutoreleaseRV
block|,
comment|///< objc_retainAutoreleaseReturnValue
name|IC_LoadWeakRetained
block|,
comment|///< objc_loadWeakRetained (primitive)
name|IC_StoreWeak
block|,
comment|///< objc_storeWeak (primitive)
name|IC_InitWeak
block|,
comment|///< objc_initWeak (derived)
name|IC_LoadWeak
block|,
comment|///< objc_loadWeak (derived)
name|IC_MoveWeak
block|,
comment|///< objc_moveWeak (derived)
name|IC_CopyWeak
block|,
comment|///< objc_copyWeak (derived)
name|IC_DestroyWeak
block|,
comment|///< objc_destroyWeak (derived)
name|IC_StoreStrong
block|,
comment|///< objc_storeStrong (derived)
name|IC_IntrinsicUser
block|,
comment|///< clang.arc.use
name|IC_CallOrUser
block|,
comment|///< could call objc_release and/or "use" pointers
name|IC_Call
block|,
comment|///< could call objc_release
name|IC_User
block|,
comment|///< could "use" a pointer
name|IC_None
comment|///< anything else
block|}
enum|;
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
name|InstructionClass
name|Class
operator|)
expr_stmt|;
comment|/// \brief Test if the given class is a kind of user.
specifier|inline
specifier|static
name|bool
name|IsUser
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
return|return
name|Class
operator|==
name|IC_User
operator|||
name|Class
operator|==
name|IC_CallOrUser
operator|||
name|Class
operator|==
name|IC_IntrinsicUser
return|;
block|}
comment|/// \brief Test if the given class is objc_retain or equivalent.
specifier|static
specifier|inline
name|bool
name|IsRetain
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
return|return
name|Class
operator|==
name|IC_Retain
operator|||
name|Class
operator|==
name|IC_RetainRV
return|;
block|}
comment|/// \brief Test if the given class is objc_autorelease or equivalent.
specifier|static
specifier|inline
name|bool
name|IsAutorelease
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
return|return
name|Class
operator|==
name|IC_Autorelease
operator|||
name|Class
operator|==
name|IC_AutoreleaseRV
return|;
block|}
comment|/// \brief Test if the given class represents instructions which return their
comment|/// argument verbatim.
specifier|static
specifier|inline
name|bool
name|IsForwarding
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
return|return
name|Class
operator|==
name|IC_Retain
operator|||
name|Class
operator|==
name|IC_RetainRV
operator|||
name|Class
operator|==
name|IC_Autorelease
operator|||
name|Class
operator|==
name|IC_AutoreleaseRV
operator|||
name|Class
operator|==
name|IC_NoopCast
return|;
block|}
comment|/// \brief Test if the given class represents instructions which do nothing if
comment|/// passed a null pointer.
specifier|static
specifier|inline
name|bool
name|IsNoopOnNull
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
return|return
name|Class
operator|==
name|IC_Retain
operator|||
name|Class
operator|==
name|IC_RetainRV
operator|||
name|Class
operator|==
name|IC_Release
operator|||
name|Class
operator|==
name|IC_Autorelease
operator|||
name|Class
operator|==
name|IC_AutoreleaseRV
operator|||
name|Class
operator|==
name|IC_RetainBlock
return|;
block|}
comment|/// \brief Test if the given class represents instructions which are always safe
comment|/// to mark with the "tail" keyword.
specifier|static
specifier|inline
name|bool
name|IsAlwaysTail
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
comment|// IC_RetainBlock may be given a stack argument.
return|return
name|Class
operator|==
name|IC_Retain
operator|||
name|Class
operator|==
name|IC_RetainRV
operator|||
name|Class
operator|==
name|IC_AutoreleaseRV
return|;
block|}
comment|/// \brief Test if the given class represents instructions which are never safe
comment|/// to mark with the "tail" keyword.
specifier|static
specifier|inline
name|bool
name|IsNeverTail
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
comment|/// It is never safe to tail call objc_autorelease since by tail calling
comment|/// objc_autorelease, we also tail call -[NSObject autorelease] which supports
comment|/// fast autoreleasing causing our object to be potentially reclaimed from the
comment|/// autorelease pool which violates the semantics of __autoreleasing types in
comment|/// ARC.
return|return
name|Class
operator|==
name|IC_Autorelease
return|;
block|}
comment|/// \brief Test if the given class represents instructions which are always safe
comment|/// to mark with the nounwind attribute.
specifier|static
specifier|inline
name|bool
name|IsNoThrow
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
comment|// objc_retainBlock is not nounwind because it calls user copy constructors
comment|// which could theoretically throw.
return|return
name|Class
operator|==
name|IC_Retain
operator|||
name|Class
operator|==
name|IC_RetainRV
operator|||
name|Class
operator|==
name|IC_Release
operator|||
name|Class
operator|==
name|IC_Autorelease
operator|||
name|Class
operator|==
name|IC_AutoreleaseRV
operator|||
name|Class
operator|==
name|IC_AutoreleasepoolPush
operator|||
name|Class
operator|==
name|IC_AutoreleasepoolPop
return|;
block|}
comment|/// Test whether the given instruction can autorelease any pointer or cause an
comment|/// autoreleasepool pop.
specifier|static
specifier|inline
name|bool
name|CanInterruptRV
parameter_list|(
name|InstructionClass
name|Class
parameter_list|)
block|{
switch|switch
condition|(
name|Class
condition|)
block|{
case|case
name|IC_AutoreleasepoolPop
case|:
case|case
name|IC_CallOrUser
case|:
case|case
name|IC_Call
case|:
case|case
name|IC_Autorelease
case|:
case|case
name|IC_AutoreleaseRV
case|:
case|case
name|IC_FusedRetainAutorelease
case|:
case|case
name|IC_FusedRetainAutoreleaseRV
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
comment|/// \brief Determine if F is one of the special known Functions.  If it isn't,
comment|/// return IC_CallOrUser.
name|InstructionClass
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
comment|/// This is similar to GetInstructionClass except that it only detects objc
comment|/// runtime calls. This allows it to be faster.
comment|///
specifier|static
specifier|inline
name|InstructionClass
name|GetBasicInstructionClass
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
name|IC_CallOrUser
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
name|IC_CallOrUser
else|:
name|IC_User
return|;
block|}
comment|/// \brief Determine what kind of construct V is.
name|InstructionClass
name|GetInstructionClass
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// \brief This is a wrapper around getUnderlyingObject which also knows how to
comment|/// look through objc_retain and objc_autorelease calls, which we know to return
comment|/// their argument verbatim.
specifier|static
specifier|inline
specifier|const
name|Value
modifier|*
name|GetUnderlyingObjCPtr
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|V
operator|=
name|GetUnderlyingObject
argument_list|(
name|V
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|IsForwarding
argument_list|(
name|GetBasicInstructionClass
argument_list|(
name|V
argument_list|)
argument_list|)
condition|)
break|break;
name|V
operator|=
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|V
operator|)
operator|->
name|getArgOperand
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|V
return|;
block|}
comment|/// \brief This is a wrapper around Value::stripPointerCasts which also knows
comment|/// how to look through objc_retain and objc_autorelease calls, which we know to
comment|/// return their argument verbatim.
specifier|static
specifier|inline
specifier|const
name|Value
modifier|*
name|StripPointerCastsAndObjCCalls
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|V
operator|=
name|V
operator|->
name|stripPointerCasts
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|IsForwarding
argument_list|(
name|GetBasicInstructionClass
argument_list|(
name|V
argument_list|)
argument_list|)
condition|)
break|break;
name|V
operator|=
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|V
operator|)
operator|->
name|getArgOperand
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|V
return|;
block|}
comment|/// \brief This is a wrapper around Value::stripPointerCasts which also knows
comment|/// how to look through objc_retain and objc_autorelease calls, which we know to
comment|/// return their argument verbatim.
specifier|static
specifier|inline
name|Value
modifier|*
name|StripPointerCastsAndObjCCalls
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|V
operator|=
name|V
operator|->
name|stripPointerCasts
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|IsForwarding
argument_list|(
name|GetBasicInstructionClass
argument_list|(
name|V
argument_list|)
argument_list|)
condition|)
break|break;
name|V
operator|=
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|V
operator|)
operator|->
name|getArgOperand
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|V
return|;
block|}
comment|/// \brief Assuming the given instruction is one of the special calls such as
comment|/// objc_retain or objc_release, return the argument value, stripped of no-op
comment|/// casts and forwarding calls.
specifier|static
specifier|inline
name|Value
modifier|*
name|GetObjCArg
parameter_list|(
name|Value
modifier|*
name|Inst
parameter_list|)
block|{
return|return
name|StripPointerCastsAndObjCCalls
argument_list|(
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|Inst
operator|)
operator|->
name|getArgOperand
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|IsNullOrUndef
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|isa
operator|<
name|ConstantPointerNull
operator|>
operator|(
name|V
operator|)
operator|||
name|isa
operator|<
name|UndefValue
operator|>
operator|(
name|V
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|IsNoopInstruction
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
return|return
name|isa
operator|<
name|BitCastInst
operator|>
operator|(
name|I
operator|)
operator|||
operator|(
name|isa
operator|<
name|GetElementPtrInst
operator|>
operator|(
name|I
operator|)
operator|&&
name|cast
operator|<
name|GetElementPtrInst
operator|>
operator|(
name|I
operator|)
operator|->
name|hasAllZeroIndices
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Erase the given instruction.
comment|///
comment|/// Many ObjC calls return their argument verbatim,
comment|/// so if it's such a call and the return value has users, replace them with the
comment|/// argument value.
comment|///
specifier|static
specifier|inline
name|void
name|EraseInstruction
parameter_list|(
name|Instruction
modifier|*
name|CI
parameter_list|)
block|{
name|Value
modifier|*
name|OldArg
init|=
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|CI
operator|)
operator|->
name|getArgOperand
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|bool
name|Unused
init|=
name|CI
operator|->
name|use_empty
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|Unused
condition|)
block|{
comment|// Replace the return value with the argument.
name|assert
argument_list|(
operator|(
name|IsForwarding
argument_list|(
name|GetBasicInstructionClass
argument_list|(
name|CI
argument_list|)
argument_list|)
operator|||
operator|(
name|IsNoopOnNull
argument_list|(
name|GetBasicInstructionClass
argument_list|(
name|CI
argument_list|)
argument_list|)
operator|&&
name|isa
operator|<
name|ConstantPointerNull
operator|>
operator|(
name|OldArg
operator|)
operator|)
operator|)
operator|&&
literal|"Can't delete non-forwarding instruction with users!"
argument_list|)
expr_stmt|;
name|CI
operator|->
name|replaceAllUsesWith
argument_list|(
name|OldArg
argument_list|)
expr_stmt|;
block|}
name|CI
operator|->
name|eraseFromParent
argument_list|()
expr_stmt|;
if|if
condition|(
name|Unused
condition|)
name|RecursivelyDeleteTriviallyDeadInstructions
argument_list|(
name|OldArg
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Test whether the given value is possible a retainable object pointer.
specifier|static
specifier|inline
name|bool
name|IsPotentialRetainableObjPtr
parameter_list|(
specifier|const
name|Value
modifier|*
name|Op
parameter_list|)
block|{
comment|// Pointers to static or stack storage are not valid retainable object
comment|// pointers.
if|if
condition|(
name|isa
operator|<
name|Constant
operator|>
operator|(
name|Op
operator|)
operator|||
name|isa
operator|<
name|AllocaInst
operator|>
operator|(
name|Op
operator|)
condition|)
return|return
name|false
return|;
comment|// Special arguments can not be a valid retainable object pointer.
if|if
condition|(
specifier|const
name|Argument
modifier|*
name|Arg
init|=
name|dyn_cast
operator|<
name|Argument
operator|>
operator|(
name|Op
operator|)
condition|)
if|if
condition|(
name|Arg
operator|->
name|hasByValAttr
argument_list|()
operator|||
name|Arg
operator|->
name|hasNestAttr
argument_list|()
operator|||
name|Arg
operator|->
name|hasStructRetAttr
argument_list|()
condition|)
return|return
name|false
return|;
comment|// Only consider values with pointer types.
comment|//
comment|// It seemes intuitive to exclude function pointer types as well, since
comment|// functions are never retainable object pointers, however clang occasionally
comment|// bitcasts retainable object pointers to function-pointer type temporarily.
name|PointerType
modifier|*
name|Ty
init|=
name|dyn_cast
operator|<
name|PointerType
operator|>
operator|(
name|Op
operator|->
name|getType
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|Ty
condition|)
return|return
name|false
return|;
comment|// Conservatively assume anything else is a potential retainable object
comment|// pointer.
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|IsPotentialRetainableObjPtr
parameter_list|(
specifier|const
name|Value
modifier|*
name|Op
parameter_list|,
name|AliasAnalysis
modifier|&
name|AA
parameter_list|)
block|{
comment|// First make the rudimentary check.
if|if
condition|(
operator|!
name|IsPotentialRetainableObjPtr
argument_list|(
name|Op
argument_list|)
condition|)
return|return
name|false
return|;
comment|// Objects in constant memory are not reference-counted.
if|if
condition|(
name|AA
operator|.
name|pointsToConstantMemory
argument_list|(
name|Op
argument_list|)
condition|)
return|return
name|false
return|;
comment|// Pointers in constant memory are not pointing to reference-counted objects.
if|if
condition|(
specifier|const
name|LoadInst
modifier|*
name|LI
init|=
name|dyn_cast
operator|<
name|LoadInst
operator|>
operator|(
name|Op
operator|)
condition|)
if|if
condition|(
name|AA
operator|.
name|pointsToConstantMemory
argument_list|(
name|LI
operator|->
name|getPointerOperand
argument_list|()
argument_list|)
condition|)
return|return
name|false
return|;
comment|// Otherwise assume the worst.
return|return
name|true
return|;
block|}
comment|/// \brief Helper for GetInstructionClass. Determines what kind of construct CS
comment|/// is.
specifier|static
specifier|inline
name|InstructionClass
name|GetCallSiteClass
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|)
block|{
for|for
control|(
name|ImmutableCallSite
operator|::
name|arg_iterator
name|I
operator|=
name|CS
operator|.
name|arg_begin
argument_list|()
operator|,
name|E
operator|=
name|CS
operator|.
name|arg_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|IsPotentialRetainableObjPtr
argument_list|(
operator|*
name|I
argument_list|)
condition|)
return|return
name|CS
operator|.
name|onlyReadsMemory
argument_list|()
condition|?
name|IC_User
else|:
name|IC_CallOrUser
return|;
return|return
name|CS
operator|.
name|onlyReadsMemory
argument_list|()
condition|?
name|IC_None
else|:
name|IC_Call
return|;
block|}
comment|/// \brief Return true if this value refers to a distinct and identifiable
comment|/// object.
comment|///
comment|/// This is similar to AliasAnalysis's isIdentifiedObject, except that it uses
comment|/// special knowledge of ObjC conventions.
specifier|static
specifier|inline
name|bool
name|IsObjCIdentifiedObject
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
comment|// Assume that call results and arguments have their own "provenance".
comment|// Constants (including GlobalVariables) and Allocas are never
comment|// reference-counted.
if|if
condition|(
name|isa
operator|<
name|CallInst
operator|>
operator|(
name|V
operator|)
operator|||
name|isa
operator|<
name|InvokeInst
operator|>
operator|(
name|V
operator|)
operator|||
name|isa
operator|<
name|Argument
operator|>
operator|(
name|V
operator|)
operator|||
name|isa
operator|<
name|Constant
operator|>
operator|(
name|V
operator|)
operator|||
name|isa
operator|<
name|AllocaInst
operator|>
operator|(
name|V
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
specifier|const
name|LoadInst
modifier|*
name|LI
init|=
name|dyn_cast
operator|<
name|LoadInst
operator|>
operator|(
name|V
operator|)
condition|)
block|{
specifier|const
name|Value
modifier|*
name|Pointer
init|=
name|StripPointerCastsAndObjCCalls
argument_list|(
name|LI
operator|->
name|getPointerOperand
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
init|=
name|dyn_cast
operator|<
name|GlobalVariable
operator|>
operator|(
name|Pointer
operator|)
condition|)
block|{
comment|// A constant pointer can't be pointing to an object on the heap. It may
comment|// be reference-counted, but it won't be deleted.
if|if
condition|(
name|GV
operator|->
name|isConstant
argument_list|()
condition|)
return|return
name|true
return|;
name|StringRef
name|Name
init|=
name|GV
operator|->
name|getName
argument_list|()
decl_stmt|;
comment|// These special variables are known to hold values which are not
comment|// reference-counted pointers.
if|if
condition|(
name|Name
operator|.
name|startswith
argument_list|(
literal|"\01L_OBJC_SELECTOR_REFERENCES_"
argument_list|)
operator|||
name|Name
operator|.
name|startswith
argument_list|(
literal|"\01L_OBJC_CLASSLIST_REFERENCES_"
argument_list|)
operator|||
name|Name
operator|.
name|startswith
argument_list|(
literal|"\01L_OBJC_CLASSLIST_SUP_REFS_$_"
argument_list|)
operator|||
name|Name
operator|.
name|startswith
argument_list|(
literal|"\01L_OBJC_METH_VAR_NAME_"
argument_list|)
operator|||
name|Name
operator|.
name|startswith
argument_list|(
literal|"\01l_objc_msgSend_fixup_"
argument_list|)
condition|)
return|return
name|true
return|;
block|}
block|}
return|return
name|false
return|;
block|}
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

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_OBJCARC_H
end_comment

end_unit

