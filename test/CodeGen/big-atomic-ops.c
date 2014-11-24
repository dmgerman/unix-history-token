begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=x86_64-apple-macosx10.9.0 | FileCheck %s
end_comment

begin_comment
comment|// Also test serialization of atomic operations here, to avoid duplicating the
end_comment

begin_comment
comment|// test.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t -triple=x86_64-apple-macosx10.9.0
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t -triple=x86_64-apple-macosx10.9.0 -emit-llvm -o - | FileCheck %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALREADY_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ALREADY_INCLUDED
end_define

begin_comment
comment|// Basic IRGen tests for __c11_atomic_* and GNU __atomic_*
end_comment

begin_typedef
typedef|typedef
enum|enum
name|memory_order
block|{
name|memory_order_relaxed
block|,
name|memory_order_consume
block|,
name|memory_order_acquire
block|,
name|memory_order_release
block|,
name|memory_order_acq_rel
block|,
name|memory_order_seq_cst
block|}
name|memory_order
typedef|;
end_typedef

begin_function
name|int
name|fi1
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi1
comment|// CHECK: load atomic i32* {{.*}} seq_cst
return|return
name|__c11_atomic_load
argument_list|(
name|i
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|fi1a
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi1a
comment|// CHECK: load atomic i32* {{.*}} seq_cst
name|int
name|v
decl_stmt|;
name|__atomic_load
argument_list|(
name|i
argument_list|,
operator|&
name|v
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_function
name|int
name|fi1b
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi1b
comment|// CHECK: load atomic i32* {{.*}} seq_cst
return|return
name|__atomic_load_n
argument_list|(
name|i
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|fi2
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi2
comment|// CHECK: store atomic i32 {{.*}} seq_cst
name|__c11_atomic_store
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fi2a
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi2a
comment|// CHECK: store atomic i32 {{.*}} seq_cst
name|int
name|v
init|=
literal|1
decl_stmt|;
name|__atomic_store
argument_list|(
name|i
argument_list|,
operator|&
name|v
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fi2b
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi2b
comment|// CHECK: store atomic i32 {{.*}} seq_cst
name|__atomic_store_n
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|fi3
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi3
comment|// CHECK: atomicrmw and
comment|// CHECK-NOT: and
return|return
name|__c11_atomic_fetch_and
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|fi3a
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi3a
comment|// CHECK: atomicrmw xor
comment|// CHECK-NOT: xor
return|return
name|__atomic_fetch_xor
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|fi3b
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi3b
comment|// CHECK: atomicrmw add
comment|// CHECK: add
return|return
name|__atomic_add_fetch
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|fi3c
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi3c
comment|// CHECK: atomicrmw nand
comment|// CHECK-NOT: and
return|return
name|__atomic_fetch_nand
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|fi3d
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi3d
comment|// CHECK: atomicrmw nand
comment|// CHECK: and
comment|// CHECK: xor
return|return
name|__atomic_nand_fetch
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|_Bool
name|fi4
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi4
comment|// CHECK: cmpxchg i32*
name|int
name|cmp
init|=
literal|0
decl_stmt|;
return|return
name|__c11_atomic_compare_exchange_strong
argument_list|(
name|i
argument_list|,
operator|&
name|cmp
argument_list|,
literal|1
argument_list|,
name|memory_order_acquire
argument_list|,
name|memory_order_acquire
argument_list|)
return|;
block|}
end_function

begin_function
name|_Bool
name|fi4a
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi4
comment|// CHECK: cmpxchg i32*
name|int
name|cmp
init|=
literal|0
decl_stmt|;
name|int
name|desired
init|=
literal|1
decl_stmt|;
return|return
name|__atomic_compare_exchange
argument_list|(
name|i
argument_list|,
operator|&
name|cmp
argument_list|,
operator|&
name|desired
argument_list|,
literal|0
argument_list|,
name|memory_order_acquire
argument_list|,
name|memory_order_acquire
argument_list|)
return|;
block|}
end_function

begin_function
name|_Bool
name|fi4b
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi4
comment|// CHECK: cmpxchg weak i32*
name|int
name|cmp
init|=
literal|0
decl_stmt|;
return|return
name|__atomic_compare_exchange_n
argument_list|(
name|i
argument_list|,
operator|&
name|cmp
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|memory_order_acquire
argument_list|,
name|memory_order_acquire
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|ff1
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|d
parameter_list|)
block|{
comment|// CHECK: @ff1
comment|// CHECK: load atomic i32* {{.*}} monotonic
return|return
name|__c11_atomic_load
argument_list|(
name|d
argument_list|,
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|ff2
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|d
parameter_list|)
block|{
comment|// CHECK: @ff2
comment|// CHECK: store atomic i32 {{.*}} release
name|__c11_atomic_store
argument_list|(
name|d
argument_list|,
literal|1
argument_list|,
name|memory_order_release
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|float
name|ff3
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|d
parameter_list|)
block|{
return|return
name|__c11_atomic_exchange
argument_list|(
name|d
argument_list|,
literal|2
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|fp1
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
operator|*
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: @fp1
comment|// CHECK: load atomic i64* {{.*}} seq_cst
return|return
name|__c11_atomic_load
argument_list|(
name|p
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|fp2
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
operator|*
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: @fp2
comment|// CHECK: store i64 4
comment|// CHECK: atomicrmw add {{.*}} monotonic
return|return
name|__c11_atomic_fetch_add
argument_list|(
name|p
argument_list|,
literal|1
argument_list|,
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|fp2a
parameter_list|(
name|int
modifier|*
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: @fp2a
comment|// CHECK: store i64 4
comment|// CHECK: atomicrmw sub {{.*}} monotonic
comment|// Note, the GNU builtins do not multiply by sizeof(T)!
return|return
name|__atomic_fetch_sub
argument_list|(
name|p
argument_list|,
literal|4
argument_list|,
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_function

begin_function
specifier|_Complex
name|float
name|fc
parameter_list|(
atomic|_Atomic
argument_list|(
specifier|_Complex
name|float
argument_list|)
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK: @fc
comment|// CHECK: atomicrmw xchg i64*
return|return
name|__c11_atomic_exchange
argument_list|(
name|c
argument_list|,
literal|2
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|;
block|}
name|X
typedef|;
end_typedef

begin_function
name|X
name|fs
parameter_list|(
atomic|_Atomic
argument_list|(
name|X
argument_list|)
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK: @fs
comment|// CHECK: atomicrmw xchg i32*
return|return
name|__c11_atomic_exchange
argument_list|(
name|c
argument_list|,
operator|(
name|X
operator|)
block|{
literal|2
block|}
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|X
name|fsa
parameter_list|(
name|X
modifier|*
name|c
parameter_list|,
name|X
modifier|*
name|d
parameter_list|)
block|{
comment|// CHECK: @fsa
comment|// CHECK: atomicrmw xchg i32*
name|X
name|ret
decl_stmt|;
name|__atomic_exchange
argument_list|(
name|c
argument_list|,
name|d
argument_list|,
operator|&
name|ret
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|_Bool
name|fsb
parameter_list|(
name|_Bool
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK: @fsb
comment|// CHECK: atomicrmw xchg i8*
return|return
name|__atomic_exchange_n
argument_list|(
name|c
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|char
name|flag1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|char
name|flag2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_and_set
parameter_list|()
block|{
comment|// CHECK: atomicrmw xchg i8* @flag1, i8 1 seq_cst
name|__atomic_test_and_set
argument_list|(
operator|&
name|flag1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw volatile xchg i8* @flag2, i8 1 acquire
name|__atomic_test_and_set
argument_list|(
operator|&
name|flag2
argument_list|,
name|memory_order_acquire
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic volatile i8 0, i8* @flag2 release
name|__atomic_clear
argument_list|(
operator|&
name|flag2
argument_list|,
name|memory_order_release
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic i8 0, i8* @flag1 seq_cst
name|__atomic_clear
argument_list|(
operator|&
name|flag1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|Sixteen
block|{
name|char
name|c
index|[
literal|16
index|]
decl_stmt|;
block|}
name|sixteen
struct|;
end_struct

begin_struct
struct|struct
name|Seventeen
block|{
name|char
name|c
index|[
literal|17
index|]
decl_stmt|;
block|}
name|seventeen
struct|;
end_struct

begin_function
name|int
name|lock_free
parameter_list|(
name|struct
name|Incomplete
modifier|*
name|incomplete
parameter_list|)
block|{
comment|// CHECK: @lock_free
comment|// CHECK: call i32 @__atomic_is_lock_free(i64 3, i8* null)
name|__c11_atomic_is_lock_free
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i64 16, i8* {{.*}}@sixteen{{.*}})
name|__atomic_is_lock_free
argument_list|(
literal|16
argument_list|,
operator|&
name|sixteen
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i64 17, i8* {{.*}}@seventeen{{.*}})
name|__atomic_is_lock_free
argument_list|(
literal|17
argument_list|,
operator|&
name|seventeen
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i64 4, {{.*}})
name|__atomic_is_lock_free
argument_list|(
literal|4
argument_list|,
name|incomplete
argument_list|)
expr_stmt|;
name|char
name|cs
index|[
literal|20
index|]
decl_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i64 4, {{.*}})
name|__atomic_is_lock_free
argument_list|(
literal|4
argument_list|,
name|cs
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: call
name|__atomic_always_lock_free
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|__atomic_always_lock_free
argument_list|(
literal|16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|__atomic_always_lock_free
argument_list|(
literal|17
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|__atomic_always_lock_free
argument_list|(
literal|16
argument_list|,
operator|&
name|sixteen
argument_list|)
expr_stmt|;
name|__atomic_always_lock_free
argument_list|(
literal|17
argument_list|,
operator|&
name|seventeen
argument_list|)
expr_stmt|;
name|int
name|n
decl_stmt|;
name|__atomic_is_lock_free
argument_list|(
literal|4
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
comment|// CHECK: ret i32 1
return|return
name|__c11_atomic_is_lock_free
argument_list|(
sizeof|sizeof
argument_list|(
expr|_Atomic
operator|(
name|int
operator|)
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Tests for atomic operations on big values.  These should call the functions
end_comment

begin_comment
comment|// defined here:
end_comment

begin_comment
comment|// http://gcc.gnu.org/wiki/Atomic/GCCMM/LIbrary#The_Library_interface
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|big
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bar
block|{
name|char
name|c
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|bar
name|smallThing
decl_stmt|,
name|thing1
decl_stmt|,
name|thing2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|foo
name|bigThing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
expr|struct
name|foo
argument_list|)
name|bigAtomic
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|structAtomicStore
parameter_list|()
block|{
comment|// CHECK: @structAtomicStore
name|struct
name|foo
name|f
init|=
block|{
literal|0
block|}
decl_stmt|;
name|__c11_atomic_store
argument_list|(
operator|&
name|bigAtomic
argument_list|,
name|f
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @__atomic_store(i64 512, i8* bitcast ({{.*}} @bigAtomic to i8*),
name|struct
name|bar
name|b
init|=
block|{
literal|0
block|}
decl_stmt|;
name|__atomic_store
argument_list|(
operator|&
name|smallThing
argument_list|,
operator|&
name|b
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @__atomic_store(i64 3, i8* {{.*}} @smallThing
name|__atomic_store
argument_list|(
operator|&
name|bigThing
argument_list|,
operator|&
name|f
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @__atomic_store(i64 512, i8* {{.*}} @bigThing
block|}
end_function

begin_function
name|void
name|structAtomicLoad
parameter_list|()
block|{
comment|// CHECK: @structAtomicLoad
name|struct
name|foo
name|f
init|=
name|__c11_atomic_load
argument_list|(
operator|&
name|bigAtomic
argument_list|,
literal|5
argument_list|)
decl_stmt|;
comment|// CHECK: call void @__atomic_load(i64 512, i8* bitcast ({{.*}} @bigAtomic to i8*),
name|struct
name|bar
name|b
decl_stmt|;
name|__atomic_load
argument_list|(
operator|&
name|smallThing
argument_list|,
operator|&
name|b
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @__atomic_load(i64 3, i8* {{.*}} @smallThing
name|__atomic_load
argument_list|(
operator|&
name|bigThing
argument_list|,
operator|&
name|f
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @__atomic_load(i64 512, i8* {{.*}} @bigThing
block|}
end_function

begin_function
name|struct
name|foo
name|structAtomicExchange
parameter_list|()
block|{
comment|// CHECK: @structAtomicExchange
name|struct
name|foo
name|f
init|=
block|{
literal|0
block|}
decl_stmt|;
name|struct
name|foo
name|old
decl_stmt|;
name|__atomic_exchange
argument_list|(
operator|&
name|f
argument_list|,
operator|&
name|bigThing
argument_list|,
operator|&
name|old
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @__atomic_exchange(i64 512, {{.*}}, i8* bitcast ({{.*}} @bigThing to i8*),
return|return
name|__c11_atomic_exchange
argument_list|(
operator|&
name|bigAtomic
argument_list|,
name|f
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: call void @__atomic_exchange(i64 512, i8* bitcast ({{.*}} @bigAtomic to i8*),
block|}
end_function

begin_function
name|int
name|structAtomicCmpExchange
parameter_list|()
block|{
comment|// CHECK: @structAtomicCmpExchange
name|_Bool
name|x
init|=
name|__atomic_compare_exchange
argument_list|(
operator|&
name|smallThing
argument_list|,
operator|&
name|thing1
argument_list|,
operator|&
name|thing2
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
decl_stmt|;
comment|// CHECK: call zeroext i1 @__atomic_compare_exchange(i64 3, {{.*}} @smallThing{{.*}} @thing1{{.*}} @thing2
name|struct
name|foo
name|f
init|=
block|{
literal|0
block|}
decl_stmt|;
name|struct
name|foo
name|g
init|=
block|{
literal|0
block|}
decl_stmt|;
name|g
operator|.
name|big
index|[
literal|12
index|]
operator|=
literal|12
expr_stmt|;
return|return
name|x
operator|&
name|__c11_atomic_compare_exchange_strong
argument_list|(
operator|&
name|bigAtomic
argument_list|,
operator|&
name|f
argument_list|,
name|g
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: call zeroext i1 @__atomic_compare_exchange(i64 512, i8* bitcast ({{.*}} @bigAtomic to i8*),
block|}
end_function

begin_comment
comment|// Check that no atomic operations are used in any initialisation of _Atomic
end_comment

begin_comment
comment|// types.
end_comment

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|atomic_init_i
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @atomic_init_foo
end_comment

begin_function
name|void
name|atomic_init_foo
parameter_list|()
block|{
comment|// CHECK-NOT: }
comment|// CHECK-NOT: atomic
comment|// CHECK: store
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|j
init|=
literal|12
decl_stmt|;
comment|// CHECK-NOT: }
comment|// CHECK-NOT: atomic
comment|// CHECK: store
name|__c11_atomic_init
argument_list|(
operator|&
name|j
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: atomic
comment|// CHECK: }
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

