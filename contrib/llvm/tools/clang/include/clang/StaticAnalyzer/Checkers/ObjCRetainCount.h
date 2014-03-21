begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- ObjCRetainCount.h - Retain count summaries for Cocoa -------*- C++ -*--//
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
comment|//  This file defines the core data structures for retain count "summaries"
end_comment

begin_comment
comment|//  for Objective-C and Core Foundation APIs.  These summaries are used
end_comment

begin_comment
comment|//  by the static analyzer to summarize the retain/release effects of
end_comment

begin_comment
comment|//  function and method calls.  This drives a path-sensitive typestate
end_comment

begin_comment
comment|//  analysis in the static analyzer, but can also potentially be used by
end_comment

begin_comment
comment|//  other clients.
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
name|LLVM_CLANG_OBJCRETAINCOUNT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_OBJCRETAINCOUNT_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|namespace
name|objc_retain
block|{
comment|/// An ArgEffect summarizes the retain count behavior on an argument or receiver
comment|/// to a function or method.
enum|enum
name|ArgEffect
block|{
comment|/// There is no effect.
name|DoNothing
block|,
comment|/// The argument is treated as if an -autorelease message had been sent to
comment|/// the referenced object.
name|Autorelease
block|,
comment|/// The argument is treated as if an -dealloc message had been sent to
comment|/// the referenced object.
name|Dealloc
block|,
comment|/// The argument has its reference count decreased by 1.  This is as
comment|/// if CFRelease has been called on the argument.
name|DecRef
block|,
comment|/// The argument has its reference count decreased by 1.  This is as
comment|/// if a -release message has been sent to the argument.  This differs
comment|/// in behavior from DecRef when GC is enabled.
name|DecRefMsg
block|,
comment|/// The argument has its reference count decreased by 1 to model
comment|/// a transferred bridge cast under ARC.
name|DecRefBridgedTransferred
block|,
comment|/// The argument has its reference count increased by 1.  This is as
comment|/// if a -retain message has been sent to the argument.  This differs
comment|/// in behavior from IncRef when GC is enabled.
name|IncRefMsg
block|,
comment|/// The argument has its reference count increased by 1.  This is as
comment|/// if CFRetain has been called on the argument.
name|IncRef
block|,
comment|/// The argument acts as if has been passed to CFMakeCollectable, which
comment|/// transfers the object to the Garbage Collector under GC.
name|MakeCollectable
block|,
comment|/// The argument is treated as potentially escaping, meaning that
comment|/// even when its reference count hits 0 it should be treated as still
comment|/// possibly being alive as someone else *may* be holding onto the object.
name|MayEscape
block|,
comment|/// All typestate tracking of the object ceases.  This is usually employed
comment|/// when the effect of the call is completely unknown.
name|StopTracking
block|,
comment|/// All typestate tracking of the object ceases.  Unlike StopTracking,
comment|/// this is also enforced when the method body is inlined.
comment|///
comment|/// In some cases, we obtain a better summary for this checker
comment|/// by looking at the call site than by inlining the function.
comment|/// Signifies that we should stop tracking the symbol even if
comment|/// the function is inlined.
name|StopTrackingHard
block|,
comment|/// Performs the combined functionality of DecRef and StopTrackingHard.
comment|///
comment|/// The models the effect that the called function decrements the reference
comment|/// count of the argument and all typestate tracking on that argument
comment|/// should cease.
name|DecRefAndStopTrackingHard
block|,
comment|/// Performs the combined functionality of DecRefMsg and StopTrackingHard.
comment|///
comment|/// The models the effect that the called function decrements the reference
comment|/// count of the argument and all typestate tracking on that argument
comment|/// should cease.
name|DecRefMsgAndStopTrackingHard
block|}
enum|;
comment|/// RetEffect summarizes a call's retain/release behavior with respect
comment|/// to its return value.
name|class
name|RetEffect
block|{
name|public
label|:
enum|enum
name|Kind
block|{
comment|/// Indicates that no retain count information is tracked for
comment|/// the return value.
name|NoRet
block|,
comment|/// Indicates that the returned value is an owned (+1) symbol.
name|OwnedSymbol
block|,
comment|/// Indicates that the returned value is an owned (+1) symbol and
comment|/// that it should be treated as freshly allocated.
name|OwnedAllocatedSymbol
block|,
comment|/// Indicates that the returned value is an object with retain count
comment|/// semantics but that it is not owned (+0).  This is the default
comment|/// for getters, etc.
name|NotOwnedSymbol
block|,
comment|/// Indicates that the object is not owned and controlled by the
comment|/// Garbage collector.
name|GCNotOwnedSymbol
block|,
comment|/// Indicates that the object is not owned and controlled by ARC.
name|ARCNotOwnedSymbol
block|,
comment|/// Indicates that the return value is an owned object when the
comment|/// receiver is also a tracked object.
name|OwnedWhenTrackedReceiver
block|,
comment|// Treat this function as returning a non-tracked symbol even if
comment|// the function has been inlined. This is used where the call
comment|// site summary is more presise than the summary indirectly produced
comment|// by inlining the function
name|NoRetHard
block|}
enum|;
comment|/// Determines the object kind of a tracked object.
enum|enum
name|ObjKind
block|{
comment|/// Indicates that the tracked object is a CF object.  This is
comment|/// important between GC and non-GC code.
name|CF
block|,
comment|/// Indicates that the tracked object is an Objective-C object.
name|ObjC
block|,
comment|/// Indicates that the tracked object could be a CF or Objective-C object.
name|AnyObj
block|}
enum|;
name|private
label|:
name|Kind
name|K
decl_stmt|;
name|ObjKind
name|O
decl_stmt|;
name|RetEffect
argument_list|(
argument|Kind k
argument_list|,
argument|ObjKind o = AnyObj
argument_list|)
block|:
name|K
argument_list|(
name|k
argument_list|)
operator|,
name|O
argument_list|(
argument|o
argument_list|)
block|{}
name|public
operator|:
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|K
return|;
block|}
name|ObjKind
name|getObjKind
argument_list|()
specifier|const
block|{
return|return
name|O
return|;
block|}
name|bool
name|isOwned
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|OwnedSymbol
operator|||
name|K
operator|==
name|OwnedAllocatedSymbol
operator|||
name|K
operator|==
name|OwnedWhenTrackedReceiver
return|;
block|}
name|bool
name|notOwned
argument_list|()
specifier|const
block|{
return|return
name|K
operator|==
name|NotOwnedSymbol
operator|||
name|K
operator|==
name|ARCNotOwnedSymbol
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RetEffect
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|K
operator|==
name|Other
operator|.
name|K
operator|&&
name|O
operator|==
name|Other
operator|.
name|O
return|;
block|}
specifier|static
name|RetEffect
name|MakeOwnedWhenTrackedReceiver
parameter_list|()
block|{
return|return
name|RetEffect
argument_list|(
name|OwnedWhenTrackedReceiver
argument_list|,
name|ObjC
argument_list|)
return|;
block|}
specifier|static
name|RetEffect
name|MakeOwned
parameter_list|(
name|ObjKind
name|o
parameter_list|,
name|bool
name|isAllocated
init|=
name|false
parameter_list|)
block|{
return|return
name|RetEffect
argument_list|(
name|isAllocated
condition|?
name|OwnedAllocatedSymbol
else|:
name|OwnedSymbol
argument_list|,
name|o
argument_list|)
return|;
block|}
specifier|static
name|RetEffect
name|MakeNotOwned
parameter_list|(
name|ObjKind
name|o
parameter_list|)
block|{
return|return
name|RetEffect
argument_list|(
name|NotOwnedSymbol
argument_list|,
name|o
argument_list|)
return|;
block|}
specifier|static
name|RetEffect
name|MakeGCNotOwned
parameter_list|()
block|{
return|return
name|RetEffect
argument_list|(
name|GCNotOwnedSymbol
argument_list|,
name|ObjC
argument_list|)
return|;
block|}
specifier|static
name|RetEffect
name|MakeARCNotOwned
parameter_list|()
block|{
return|return
name|RetEffect
argument_list|(
name|ARCNotOwnedSymbol
argument_list|,
name|ObjC
argument_list|)
return|;
block|}
specifier|static
name|RetEffect
name|MakeNoRet
parameter_list|()
block|{
return|return
name|RetEffect
argument_list|(
name|NoRet
argument_list|)
return|;
block|}
specifier|static
name|RetEffect
name|MakeNoRetHard
parameter_list|()
block|{
return|return
name|RetEffect
argument_list|(
name|NoRetHard
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Encapsulates the retain count semantics on the arguments, return value,
comment|/// and receiver (if any) of a function/method call.
comment|///
comment|/// Note that construction of these objects is not highly efficient.  That
comment|/// is okay for clients where creating these objects isn't really a bottleneck.
comment|/// The purpose of the API is to provide something simple.  The actual
comment|/// static analyzer checker that implements retain/release typestate
comment|/// tracking uses something more efficient.
name|class
name|CallEffects
block|{
name|llvm
operator|::
name|SmallVector
operator|<
name|ArgEffect
operator|,
literal|10
operator|>
name|Args
expr_stmt|;
name|RetEffect
name|Ret
decl_stmt|;
name|ArgEffect
name|Receiver
decl_stmt|;
name|CallEffects
argument_list|(
specifier|const
name|RetEffect
operator|&
name|R
argument_list|)
operator|:
name|Ret
argument_list|(
argument|R
argument_list|)
block|{}
name|public
operator|:
comment|/// Returns the argument effects for a call.
name|llvm
operator|::
name|ArrayRef
operator|<
name|ArgEffect
operator|>
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
comment|/// Returns the effects on the receiver.
name|ArgEffect
name|getReceiver
argument_list|()
specifier|const
block|{
return|return
name|Receiver
return|;
block|}
comment|/// Returns the effect on the return value.
name|RetEffect
name|getReturnValue
argument_list|()
specifier|const
block|{
return|return
name|Ret
return|;
block|}
comment|/// Return the CallEfect for a given Objective-C method.
specifier|static
name|CallEffects
name|getEffect
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
comment|/// Return the CallEfect for a given C/C++ function.
specifier|static
name|CallEffects
name|getEffect
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

