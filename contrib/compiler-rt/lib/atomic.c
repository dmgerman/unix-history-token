begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- atomic.c - Implement support functions for atomic operations.------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===  *  *  atomic.c defines a set of functions for performing atomic accesses on  *  arbitrary-sized memory locations.  This design uses locks that should  *  be fast in the uncontended case, for two reasons:  *   *  1) This code must work with C programs that do not link to anything  *     (including pthreads) and so it should not depend on any pthread  *     functions.  *  2) Atomic operations, rather than explicit mutexes, are most commonly used  *     on code where contended operations are rate.  *   *  To avoid needing a per-object lock, this code allocates an array of  *  locks and hashes the object pointers to find the one that it should use.  *  For operations that must be atomic on two locations, the lower lock is  *  always acquired first, to avoid deadlock.  *  *===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|// Clang objects if you redefine a builtin.  This little hack allows us to
end_comment

begin_comment
comment|// define a function with the same name as an intrinsic.
end_comment

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__atomic_load_c
name|__atomic_load
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__atomic_store_c
name|__atomic_store
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__atomic_exchange_c
name|__atomic_exchange
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__atomic_compare_exchange_c
name|__atomic_compare_exchange
end_pragma

begin_comment
comment|/// Number of locks.  This allocates one page on 32-bit platforms, two on
end_comment

begin_comment
comment|/// 64-bit.  This can be specified externally if a different trade between
end_comment

begin_comment
comment|/// memory usage and contention probability is required for a given platform.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPINLOCK_COUNT
end_ifndef

begin_define
define|#
directive|define
name|SPINLOCK_COUNT
value|(1<<10)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|long
name|SPINLOCK_MASK
init|=
name|SPINLOCK_COUNT
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Platform-specific lock implementation.  Falls back to spinlocks if none is
end_comment

begin_comment
comment|// defined.  Each platform should define the Lock type, and corresponding
end_comment

begin_comment
comment|// lock() and unlock() functions.
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<sys/umtx.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|_usem
name|Lock
typedef|;
end_typedef

begin_function
specifier|inline
specifier|static
name|void
name|unlock
parameter_list|(
name|Lock
modifier|*
name|l
parameter_list|)
block|{
name|__c11_atomic_store
argument_list|(
operator|(
expr|_Atomic
operator|(
name|uint32_t
operator|)
operator|*
operator|)
operator|&
name|l
operator|->
name|_count
argument_list|,
literal|1
argument_list|,
name|__ATOMIC_RELEASE
argument_list|)
expr_stmt|;
name|__c11_atomic_thread_fence
argument_list|(
name|__ATOMIC_SEQ_CST
argument_list|)
expr_stmt|;
if|if
condition|(
name|l
operator|->
name|_has_waiters
condition|)
name|_umtx_op
argument_list|(
name|l
argument_list|,
name|UMTX_OP_SEM_WAKE
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
specifier|static
name|void
name|lock
parameter_list|(
name|Lock
modifier|*
name|l
parameter_list|)
block|{
name|uint32_t
name|old
init|=
literal|1
decl_stmt|;
while|while
condition|(
operator|!
name|__c11_atomic_compare_exchange_weak
argument_list|(
operator|(
expr|_Atomic
operator|(
name|uint32_t
operator|)
operator|*
operator|)
operator|&
name|l
operator|->
name|_count
argument_list|,
operator|&
name|old
argument_list|,
literal|0
argument_list|,
name|__ATOMIC_ACQUIRE
argument_list|,
name|__ATOMIC_RELAXED
argument_list|)
condition|)
block|{
name|_umtx_op
argument_list|(
name|l
argument_list|,
name|UMTX_OP_SEM_WAIT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|old
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// locks for atomic operations
end_comment

begin_decl_stmt
specifier|static
name|Lock
name|locks
index|[
name|SPINLOCK_COUNT
index|]
init|=
block|{
index|[
literal|0
operator|...
name|SPINLOCK_COUNT
operator|-
literal|1
index|]
operator|=
block|{
literal|0
block|,
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|uintptr_t
argument_list|)
name|Lock
typedef|;
end_typedef

begin_comment
comment|/// Unlock a lock.  This is a release operation.
end_comment

begin_function
specifier|inline
specifier|static
name|void
name|unlock
parameter_list|(
name|Lock
modifier|*
name|l
parameter_list|)
block|{
name|__c11_atomic_store
argument_list|(
name|l
argument_list|,
literal|0
argument_list|,
name|__ATOMIC_RELEASE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Locks a lock.  In the current implementation, this is potentially
end_comment

begin_comment
comment|/// unbounded in the contended case.
end_comment

begin_function
specifier|inline
specifier|static
name|void
name|lock
parameter_list|(
name|Lock
modifier|*
name|l
parameter_list|)
block|{
name|uintptr_t
name|old
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|__c11_atomic_compare_exchange_weak
argument_list|(
name|l
argument_list|,
operator|&
name|old
argument_list|,
literal|1
argument_list|,
name|__ATOMIC_ACQUIRE
argument_list|,
name|__ATOMIC_RELAXED
argument_list|)
condition|)
name|old
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/// locks for atomic operations
end_comment

begin_decl_stmt
specifier|static
name|Lock
name|locks
index|[
name|SPINLOCK_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// Returns a lock to use for a given pointer.
end_comment

begin_function
specifier|static
specifier|inline
name|Lock
modifier|*
name|lock_for_pointer
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|intptr_t
name|hash
init|=
operator|(
name|intptr_t
operator|)
name|ptr
decl_stmt|;
comment|// Disregard the lowest 4 bits.  We want all values that may be part of the
comment|// same memory operation to hash to the same value and therefore use the same
comment|// lock.
name|hash
operator|>>=
literal|4
expr_stmt|;
comment|// Use the next bits as the basis for the hash
name|intptr_t
name|low
init|=
name|hash
operator|&
name|SPINLOCK_MASK
decl_stmt|;
comment|// Now use the high(er) set of bits to perturb the hash, so that we don't
comment|// get collisions from atomic fields in a single object
name|hash
operator|>>=
literal|16
expr_stmt|;
name|hash
operator|^=
name|low
expr_stmt|;
comment|// Return a pointer to the word to use
return|return
name|locks
operator|+
operator|(
name|hash
operator|&
name|SPINLOCK_MASK
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Macros for determining whether a size is lock free.  Clang can not yet
end_comment

begin_comment
comment|/// codegen __atomic_is_lock_free(16), so for now we assume 16-byte values are
end_comment

begin_comment
comment|/// not lock free.
end_comment

begin_define
define|#
directive|define
name|IS_LOCK_FREE_1
value|__c11_atomic_is_lock_free(1)
end_define

begin_define
define|#
directive|define
name|IS_LOCK_FREE_2
value|__c11_atomic_is_lock_free(2)
end_define

begin_define
define|#
directive|define
name|IS_LOCK_FREE_4
value|__c11_atomic_is_lock_free(4)
end_define

begin_define
define|#
directive|define
name|IS_LOCK_FREE_8
value|__c11_atomic_is_lock_free(8)
end_define

begin_define
define|#
directive|define
name|IS_LOCK_FREE_16
value|0
end_define

begin_comment
comment|/// Macro that calls the compiler-generated lock-free versions of functions
end_comment

begin_comment
comment|/// when they exist.
end_comment

begin_define
define|#
directive|define
name|LOCK_FREE_CASES
parameter_list|()
define|\
value|do {\   switch (size) {\     case 2:\       if (IS_LOCK_FREE_2) {\         LOCK_FREE_ACTION(uint16_t);\       }\     case 4:\       if (IS_LOCK_FREE_4) {\         LOCK_FREE_ACTION(uint32_t);\       }\     case 8:\       if (IS_LOCK_FREE_8) {\         LOCK_FREE_ACTION(uint64_t);\       }\     case 16:\       if (IS_LOCK_FREE_16) {\
comment|/* FIXME: __uint128_t isn't available on 32 bit platforms.         LOCK_FREE_ACTION(__uint128_t);*/
value|\       }\   }\   } while (0)
end_define

begin_comment
comment|/// An atomic load operation.  This is atomic with respect to the source
end_comment

begin_comment
comment|/// pointer only.
end_comment

begin_function
name|void
name|__atomic_load_c
parameter_list|(
name|int
name|size
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|int
name|model
parameter_list|)
block|{
define|#
directive|define
name|LOCK_FREE_ACTION
parameter_list|(
name|type
parameter_list|)
define|\
value|*((type*)dest) = __c11_atomic_load((_Atomic(type)*)src, model);\     return;
name|LOCK_FREE_CASES
argument_list|()
expr_stmt|;
undef|#
directive|undef
name|LOCK_FREE_ACTION
name|Lock
modifier|*
name|l
init|=
name|lock_for_pointer
argument_list|(
name|src
argument_list|)
decl_stmt|;
name|lock
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|unlock
argument_list|(
name|l
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// An atomic store operation.  This is atomic with respect to the destination
end_comment

begin_comment
comment|/// pointer only.
end_comment

begin_function
name|void
name|__atomic_store_c
parameter_list|(
name|int
name|size
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|int
name|model
parameter_list|)
block|{
define|#
directive|define
name|LOCK_FREE_ACTION
parameter_list|(
name|type
parameter_list|)
define|\
value|__c11_atomic_store((_Atomic(type)*)dest, *(type*)dest, model);\     return;
name|LOCK_FREE_CASES
argument_list|()
expr_stmt|;
undef|#
directive|undef
name|LOCK_FREE_ACTION
name|Lock
modifier|*
name|l
init|=
name|lock_for_pointer
argument_list|(
name|dest
argument_list|)
decl_stmt|;
name|lock
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|unlock
argument_list|(
name|l
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Atomic compare and exchange operation.  If the value at *ptr is identical
end_comment

begin_comment
comment|/// to the value at *expected, then this copies value at *desired to *ptr.  If
end_comment

begin_comment
comment|/// they  are not, then this stores the current value from *ptr in *expected.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function returns 1 if the exchange takes place or 0 if it fails.
end_comment

begin_function
name|int
name|__atomic_compare_exchange_c
parameter_list|(
name|int
name|size
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|expected
parameter_list|,
name|void
modifier|*
name|desired
parameter_list|,
name|int
name|success
parameter_list|,
name|int
name|failure
parameter_list|)
block|{
define|#
directive|define
name|LOCK_FREE_ACTION
parameter_list|(
name|type
parameter_list|)
define|\
value|return __c11_atomic_compare_exchange_strong((_Atomic(type)*)ptr, (type*)expected,\       *(type*)desired, success, failure)
name|LOCK_FREE_CASES
argument_list|()
expr_stmt|;
undef|#
directive|undef
name|LOCK_FREE_ACTION
name|Lock
modifier|*
name|l
init|=
name|lock_for_pointer
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
name|lock
argument_list|(
name|l
argument_list|)
expr_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|ptr
argument_list|,
name|expected
argument_list|,
name|size
argument_list|)
operator|==
literal|0
condition|)
block|{
name|memcpy
argument_list|(
name|ptr
argument_list|,
name|desired
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|unlock
argument_list|(
name|l
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|memcpy
argument_list|(
name|expected
argument_list|,
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|unlock
argument_list|(
name|l
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// Performs an atomic exchange operation between two pointers.  This is atomic
end_comment

begin_comment
comment|/// with respect to the target address.
end_comment

begin_function
name|void
name|__atomic_exchange_c
parameter_list|(
name|int
name|size
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|void
modifier|*
name|old
parameter_list|,
name|int
name|model
parameter_list|)
block|{
define|#
directive|define
name|LOCK_FREE_ACTION
parameter_list|(
name|type
parameter_list|)
define|\
value|*(type*)old = __c11_atomic_exchange((_Atomic(type)*)ptr, *(type*)val,\         model);\     return;
name|LOCK_FREE_CASES
argument_list|()
expr_stmt|;
undef|#
directive|undef
name|LOCK_FREE_ACTION
name|Lock
modifier|*
name|l
init|=
name|lock_for_pointer
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
name|lock
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|old
argument_list|,
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|unlock
argument_list|(
name|l
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Where the size is known at compile time, the compiler may emit calls to
end_comment

begin_comment
comment|// specialised versions of the above functions.
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|OPTIMISED_CASES
define|\
value|OPTIMISED_CASE(1, IS_LOCK_FREE_1, uint8_t)\   OPTIMISED_CASE(2, IS_LOCK_FREE_2, uint16_t)\   OPTIMISED_CASE(4, IS_LOCK_FREE_4, uint32_t)\   OPTIMISED_CASE(8, IS_LOCK_FREE_8, uint64_t)\
comment|/* FIXME: __uint128_t isn't available on 32 bit platforms.   OPTIMISED_CASE(16, IS_LOCK_FREE_16, __uint128_t)*/
value|\  #define OPTIMISED_CASE(n, lockfree, type)\ type __atomic_load_##n(type *src, int model) {\   if (lockfree)\     return __c11_atomic_load((_Atomic(type)*)src, model);\   Lock *l = lock_for_pointer(src);\   lock(l);\   type val = *src;\   unlock(l);\   return val;\ }
end_define

begin_expr_stmt
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
define|\
value|void  __atomic_store_##n(type *dest, type val, int model) {\   if (lockfree) {\     __c11_atomic_store((_Atomic(type)*)dest, val, model);\     return;\   }\   Lock *l = lock_for_pointer(dest);\   lock(l);\   *dest = val;\   unlock(l);\   return;\ }
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
define|\
value|type __atomic_exchange_##n(type *dest, type val, int model) {\   if (lockfree)\     return __c11_atomic_exchange((_Atomic(type)*)dest, val, model);\   Lock *l = lock_for_pointer(dest);\   lock(l);\   type tmp = *dest;\   *dest = val;\   unlock(l);\   return tmp;\ }
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
define|\
value|int __atomic_compare_exchange_##n(type *ptr, type *expected, type desired,\     int success, int failure) {\   if (lockfree)\     return __c11_atomic_compare_exchange_strong((_Atomic(type)*)ptr, expected, desired,\         success, failure);\   Lock *l = lock_for_pointer(ptr);\   lock(l);\   if (*ptr == *expected) {\     *ptr = desired;\     unlock(l);\     return 1;\   }\   *expected = *ptr;\   unlock(l);\   return 0;\ }
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
comment|////////////////////////////////////////////////////////////////////////////////
comment|// Atomic read-modify-write operations for integers of various sizes.
comment|////////////////////////////////////////////////////////////////////////////////
define|#
directive|define
name|ATOMIC_RMW
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|,
name|opname
parameter_list|,
name|op
parameter_list|)
define|\
value|type __atomic_fetch_##opname##_##n(type *ptr, type val, int model) {\   if (lockfree) \     return __c11_atomic_fetch_##opname((_Atomic(type)*)ptr, val, model);\   Lock *l = lock_for_pointer(ptr);\   lock(l);\   type tmp = *ptr;\   *ptr = tmp op val;\   unlock(l);\   return tmp;\ }
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
value|ATOMIC_RMW(n, lockfree, type, add, +)
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
value|ATOMIC_RMW(n, lockfree, type, sub, -)
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
value|ATOMIC_RMW(n, lockfree, type, and,&)
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
value|ATOMIC_RMW(n, lockfree, type, or, |)
name|OPTIMISED_CASES
undef|#
directive|undef
name|OPTIMISED_CASE
define|#
directive|define
name|OPTIMISED_CASE
parameter_list|(
name|n
parameter_list|,
name|lockfree
parameter_list|,
name|type
parameter_list|)
value|ATOMIC_RMW(n, lockfree, type, xor, ^)
name|OPTIMISED_CASES
end_expr_stmt

begin_undef
undef|#
directive|undef
name|OPTIMISED_CASE
end_undef

end_unit

