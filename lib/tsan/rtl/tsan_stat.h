begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_stat.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
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
name|TSAN_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_STAT_H
end_define

begin_decl_stmt
name|namespace
name|__tsan
block|{
enum|enum
name|StatType
block|{
comment|// Memory access processing related stuff.
name|StatMop
block|,
name|StatMopRead
block|,
name|StatMopWrite
block|,
name|StatMop1
block|,
comment|// These must be consequtive.
name|StatMop2
block|,
name|StatMop4
block|,
name|StatMop8
block|,
name|StatMopSame
block|,
name|StatMopIgnored
block|,
name|StatMopRange
block|,
name|StatMopRodata
block|,
name|StatMopRangeRodata
block|,
name|StatShadowProcessed
block|,
name|StatShadowZero
block|,
name|StatShadowNonZero
block|,
comment|// Derived.
name|StatShadowSameSize
block|,
name|StatShadowIntersect
block|,
name|StatShadowNotIntersect
block|,
name|StatShadowSameThread
block|,
name|StatShadowAnotherThread
block|,
name|StatShadowReplace
block|,
comment|// Func processing.
name|StatFuncEnter
block|,
name|StatFuncExit
block|,
comment|// Trace processing.
name|StatEvents
block|,
comment|// Threads.
name|StatThreadCreate
block|,
name|StatThreadFinish
block|,
name|StatThreadReuse
block|,
name|StatThreadMaxTid
block|,
name|StatThreadMaxAlive
block|,
comment|// Mutexes.
name|StatMutexCreate
block|,
name|StatMutexDestroy
block|,
name|StatMutexLock
block|,
name|StatMutexUnlock
block|,
name|StatMutexRecLock
block|,
name|StatMutexRecUnlock
block|,
name|StatMutexReadLock
block|,
name|StatMutexReadUnlock
block|,
comment|// Synchronization.
name|StatSyncCreated
block|,
name|StatSyncDestroyed
block|,
name|StatSyncAcquire
block|,
name|StatSyncRelease
block|,
comment|// Clocks - acquire.
name|StatClockAcquire
block|,
name|StatClockAcquireEmpty
block|,
name|StatClockAcquireFastRelease
block|,
name|StatClockAcquireLarge
block|,
name|StatClockAcquireRepeat
block|,
name|StatClockAcquireFull
block|,
name|StatClockAcquiredSomething
block|,
comment|// Clocks - release.
name|StatClockRelease
block|,
name|StatClockReleaseResize
block|,
name|StatClockReleaseFast1
block|,
name|StatClockReleaseFast2
block|,
name|StatClockReleaseSlow
block|,
name|StatClockReleaseFull
block|,
name|StatClockReleaseAcquired
block|,
name|StatClockReleaseClearTail
block|,
comment|// Clocks - release store.
name|StatClockStore
block|,
name|StatClockStoreResize
block|,
name|StatClockStoreFast
block|,
name|StatClockStoreFull
block|,
name|StatClockStoreTail
block|,
comment|// Clocks - acquire-release.
name|StatClockAcquireRelease
block|,
comment|// Atomics.
name|StatAtomic
block|,
name|StatAtomicLoad
block|,
name|StatAtomicStore
block|,
name|StatAtomicExchange
block|,
name|StatAtomicFetchAdd
block|,
name|StatAtomicFetchSub
block|,
name|StatAtomicFetchAnd
block|,
name|StatAtomicFetchOr
block|,
name|StatAtomicFetchXor
block|,
name|StatAtomicFetchNand
block|,
name|StatAtomicCAS
block|,
name|StatAtomicFence
block|,
name|StatAtomicRelaxed
block|,
name|StatAtomicConsume
block|,
name|StatAtomicAcquire
block|,
name|StatAtomicRelease
block|,
name|StatAtomicAcq_Rel
block|,
name|StatAtomicSeq_Cst
block|,
name|StatAtomic1
block|,
name|StatAtomic2
block|,
name|StatAtomic4
block|,
name|StatAtomic8
block|,
name|StatAtomic16
block|,
comment|// Dynamic annotations.
name|StatAnnotation
block|,
name|StatAnnotateHappensBefore
block|,
name|StatAnnotateHappensAfter
block|,
name|StatAnnotateCondVarSignal
block|,
name|StatAnnotateCondVarSignalAll
block|,
name|StatAnnotateMutexIsNotPHB
block|,
name|StatAnnotateCondVarWait
block|,
name|StatAnnotateRWLockCreate
block|,
name|StatAnnotateRWLockCreateStatic
block|,
name|StatAnnotateRWLockDestroy
block|,
name|StatAnnotateRWLockAcquired
block|,
name|StatAnnotateRWLockReleased
block|,
name|StatAnnotateTraceMemory
block|,
name|StatAnnotateFlushState
block|,
name|StatAnnotateNewMemory
block|,
name|StatAnnotateNoOp
block|,
name|StatAnnotateFlushExpectedRaces
block|,
name|StatAnnotateEnableRaceDetection
block|,
name|StatAnnotateMutexIsUsedAsCondVar
block|,
name|StatAnnotatePCQGet
block|,
name|StatAnnotatePCQPut
block|,
name|StatAnnotatePCQDestroy
block|,
name|StatAnnotatePCQCreate
block|,
name|StatAnnotateExpectRace
block|,
name|StatAnnotateBenignRaceSized
block|,
name|StatAnnotateBenignRace
block|,
name|StatAnnotateIgnoreReadsBegin
block|,
name|StatAnnotateIgnoreReadsEnd
block|,
name|StatAnnotateIgnoreWritesBegin
block|,
name|StatAnnotateIgnoreWritesEnd
block|,
name|StatAnnotateIgnoreSyncBegin
block|,
name|StatAnnotateIgnoreSyncEnd
block|,
name|StatAnnotatePublishMemoryRange
block|,
name|StatAnnotateUnpublishMemoryRange
block|,
name|StatAnnotateThreadName
block|,
name|Stat__tsan_mutex_create
block|,
name|Stat__tsan_mutex_destroy
block|,
name|Stat__tsan_mutex_pre_lock
block|,
name|Stat__tsan_mutex_post_lock
block|,
name|Stat__tsan_mutex_pre_unlock
block|,
name|Stat__tsan_mutex_post_unlock
block|,
name|Stat__tsan_mutex_pre_signal
block|,
name|Stat__tsan_mutex_post_signal
block|,
name|Stat__tsan_mutex_pre_divert
block|,
name|Stat__tsan_mutex_post_divert
block|,
comment|// Internal mutex contentionz.
name|StatMtxTotal
block|,
name|StatMtxTrace
block|,
name|StatMtxThreads
block|,
name|StatMtxReport
block|,
name|StatMtxSyncVar
block|,
name|StatMtxSyncTab
block|,
name|StatMtxSlab
block|,
name|StatMtxAnnotations
block|,
name|StatMtxAtExit
block|,
name|StatMtxMBlock
block|,
name|StatMtxDeadlockDetector
block|,
name|StatMtxFired
block|,
name|StatMtxRacy
block|,
name|StatMtxFD
block|,
name|StatMtxGlobalProc
block|,
comment|// This must be the last.
name|StatCnt
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_STAT_H
end_comment

end_unit

