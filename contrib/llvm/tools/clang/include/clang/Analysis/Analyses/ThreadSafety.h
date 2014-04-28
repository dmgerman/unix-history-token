begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ThreadSafety.h ------------------------------------------*- C++ --*-===//
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
comment|//
end_comment

begin_comment
comment|// A intra-procedural analysis for thread safety (e.g. deadlocks and race
end_comment

begin_comment
comment|// conditions), based off of an annotation system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See http://clang.llvm.org/docs/LanguageExtensions.html#thread-safety-annotation-checking
end_comment

begin_comment
comment|// for more information.
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
name|LLVM_CLANG_THREADSAFETY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_THREADSAFETY_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|thread_safety
block|{
comment|/// This enum distinguishes between different kinds of operations that may
comment|/// need to be protected by locks. We use this enum in error handling.
enum|enum
name|ProtectedOperationKind
block|{
name|POK_VarDereference
block|,
comment|///< Dereferencing a variable (e.g. p in *p = 5;)
name|POK_VarAccess
block|,
comment|///< Reading or writing a variable (e.g. x in x = 5;)
name|POK_FunctionCall
comment|///< Making a function call (e.g. fool())
block|}
enum|;
comment|/// This enum distinguishes between different kinds of lock actions. For
comment|/// example, it is an error to write a variable protected by shared version of a
comment|/// mutex.
enum|enum
name|LockKind
block|{
name|LK_Shared
block|,
comment|///< Shared/reader lock of a mutex.
name|LK_Exclusive
comment|///< Exclusive/writer lock of a mutex.
block|}
enum|;
comment|/// This enum distinguishes between different ways to access (read or write) a
comment|/// variable.
enum|enum
name|AccessKind
block|{
name|AK_Read
block|,
comment|///< Reading a variable.
name|AK_Written
comment|///< Writing a variable.
block|}
enum|;
comment|/// This enum distinguishes between different situations where we warn due to
comment|/// inconsistent locking.
comment|/// \enum SK_LockedSomeLoopIterations -- a mutex is locked for some but not all
comment|/// loop iterations.
comment|/// \enum SK_LockedSomePredecessors -- a mutex is locked in some but not all
comment|/// predecessors of a CFGBlock.
comment|/// \enum SK_LockedAtEndOfFunction -- a mutex is still locked at the end of a
comment|/// function.
enum|enum
name|LockErrorKind
block|{
name|LEK_LockedSomeLoopIterations
block|,
name|LEK_LockedSomePredecessors
block|,
name|LEK_LockedAtEndOfFunction
block|,
name|LEK_NotLockedAtEndOfFunction
block|}
enum|;
comment|/// Handler class for thread safety warnings.
name|class
name|ThreadSafetyHandler
block|{
name|public
label|:
typedef|typedef
name|StringRef
name|Name
typedef|;
name|ThreadSafetyHandler
argument_list|()
operator|:
name|IssueBetaWarnings
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
operator|~
name|ThreadSafetyHandler
argument_list|()
expr_stmt|;
comment|/// Warn about lock expressions which fail to resolve to lockable objects.
comment|/// \param Loc -- the SourceLocation of the unresolved expression.
name|virtual
name|void
name|handleInvalidLockExp
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{}
comment|/// Warn about unlock function calls that do not have a prior matching lock
comment|/// expression.
comment|/// \param LockName -- A StringRef name for the lock expression, to be printed
comment|/// in the error message.
comment|/// \param Loc -- The SourceLocation of the Unlock
name|virtual
name|void
name|handleUnmatchedUnlock
parameter_list|(
name|Name
name|LockName
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{}
comment|/// Warn about lock function calls for locks which are already held.
comment|/// \param LockName -- A StringRef name for the lock expression, to be printed
comment|/// in the error message.
comment|/// \param Loc -- The location of the second lock expression.
name|virtual
name|void
name|handleDoubleLock
parameter_list|(
name|Name
name|LockName
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{}
comment|/// Warn about situations where a mutex is sometimes held and sometimes not.
comment|/// The three situations are:
comment|/// 1. a mutex is locked on an "if" branch but not the "else" branch,
comment|/// 2, or a mutex is only held at the start of some loop iterations,
comment|/// 3. or when a mutex is locked but not unlocked inside a function.
comment|/// \param LockName -- A StringRef name for the lock expression, to be printed
comment|/// in the error message.
comment|/// \param LocLocked -- The location of the lock expression where the mutex is
comment|///               locked
comment|/// \param LocEndOfScope -- The location of the end of the scope where the
comment|///               mutex is no longer held
comment|/// \param LEK -- which of the three above cases we should warn for
name|virtual
name|void
name|handleMutexHeldEndOfScope
parameter_list|(
name|Name
name|LockName
parameter_list|,
name|SourceLocation
name|LocLocked
parameter_list|,
name|SourceLocation
name|LocEndOfScope
parameter_list|,
name|LockErrorKind
name|LEK
parameter_list|)
block|{}
comment|/// Warn when a mutex is held exclusively and shared at the same point. For
comment|/// example, if a mutex is locked exclusively during an if branch and shared
comment|/// during the else branch.
comment|/// \param LockName -- A StringRef name for the lock expression, to be printed
comment|/// in the error message.
comment|/// \param Loc1 -- The location of the first lock expression.
comment|/// \param Loc2 -- The location of the second lock expression.
name|virtual
name|void
name|handleExclusiveAndShared
parameter_list|(
name|Name
name|LockName
parameter_list|,
name|SourceLocation
name|Loc1
parameter_list|,
name|SourceLocation
name|Loc2
parameter_list|)
block|{}
comment|/// Warn when a protected operation occurs while no locks are held.
comment|/// \param D -- The decl for the protected variable or function
comment|/// \param POK -- The kind of protected operation (e.g. variable access)
comment|/// \param AK -- The kind of access (i.e. read or write) that occurred
comment|/// \param Loc -- The location of the protected operation.
name|virtual
name|void
name|handleNoMutexHeld
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|ProtectedOperationKind
name|POK
parameter_list|,
name|AccessKind
name|AK
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{}
comment|/// Warn when a protected operation occurs while the specific mutex protecting
comment|/// the operation is not locked.
comment|/// \param D -- The decl for the protected variable or function
comment|/// \param POK -- The kind of protected operation (e.g. variable access)
comment|/// \param LockName -- A StringRef name for the lock expression, to be printed
comment|/// in the error message.
comment|/// \param LK -- The kind of access (i.e. read or write) that occurred
comment|/// \param Loc -- The location of the protected operation.
name|virtual
name|void
name|handleMutexNotHeld
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|ProtectedOperationKind
name|POK
parameter_list|,
name|Name
name|LockName
parameter_list|,
name|LockKind
name|LK
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Name
modifier|*
name|PossibleMatch
init|=
literal|0
parameter_list|)
block|{}
comment|/// Warn when a function is called while an excluded mutex is locked. For
comment|/// example, the mutex may be locked inside the function.
comment|/// \param FunName -- The name of the function
comment|/// \param LockName -- A StringRef name for the lock expression, to be printed
comment|/// in the error message.
comment|/// \param Loc -- The location of the function call.
name|virtual
name|void
name|handleFunExcludesLock
parameter_list|(
name|Name
name|FunName
parameter_list|,
name|Name
name|LockName
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{}
name|bool
name|issueBetaWarnings
parameter_list|()
block|{
return|return
name|IssueBetaWarnings
return|;
block|}
name|void
name|setIssueBetaWarnings
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|IssueBetaWarnings
operator|=
name|b
expr_stmt|;
block|}
name|private
label|:
name|bool
name|IssueBetaWarnings
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Check a function's CFG for thread-safety violations.
comment|///
comment|/// We traverse the blocks in the CFG, compute the set of mutexes that are held
comment|/// at the end of each block, and issue warnings for thread safety violations.
comment|/// Each block in the CFG is traversed exactly once.
name|void
name|runThreadSafetyAnalysis
parameter_list|(
name|AnalysisDeclContext
modifier|&
name|AC
parameter_list|,
name|ThreadSafetyHandler
modifier|&
name|Handler
parameter_list|)
function_decl|;
comment|/// \brief Helper function that returns a LockKind required for the given level
comment|/// of access.
name|LockKind
name|getLockKindFromAccessKind
parameter_list|(
name|AccessKind
name|AK
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::thread_safety
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

