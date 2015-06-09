begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -ffreestanding -triple=i686-apple-darwin9 | FileCheck %s
end_comment

begin_comment
comment|// Also test serialization of atomic operations here, to avoid duplicating the
end_comment

begin_comment
comment|// test.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t -ffreestanding -triple=i686-apple-darwin9
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t -ffreestanding -triple=i686-apple-darwin9 -emit-llvm -o - | FileCheck %s
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

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_comment
comment|// Basic IRGen tests for __c11_atomic_* and GNU __atomic_*
end_comment

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
comment|// CHECK-LABEL: @fi1
comment|// CHECK: load atomic i32, i32* {{.*}} seq_cst
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
comment|// CHECK-LABEL: @fi1a
comment|// CHECK: load atomic i32, i32* {{.*}} seq_cst
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
comment|// CHECK-LABEL: @fi1b
comment|// CHECK: load atomic i32, i32* {{.*}} seq_cst
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
name|int
name|fi1c
parameter_list|(
name|atomic_int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK-LABEL: @fi1c
comment|// CHECK: load atomic i32, i32* {{.*}} seq_cst
return|return
name|atomic_load
argument_list|(
name|i
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
comment|// CHECK-LABEL: @fi2
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
comment|// CHECK-LABEL: @fi2a
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
comment|// CHECK-LABEL: @fi2b
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
name|void
name|fi2c
parameter_list|(
name|atomic_int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK-LABEL: @fi2c
comment|// CHECK: store atomic i32 {{.*}} seq_cst
name|atomic_store
argument_list|(
name|i
argument_list|,
literal|1
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
comment|// CHECK-LABEL: @fi3
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
comment|// CHECK-LABEL: @fi3a
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
comment|// CHECK-LABEL: @fi3b
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
comment|// CHECK-LABEL: @fi3c
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
comment|// CHECK-LABEL: @fi3d
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
name|int
name|fi3e
parameter_list|(
name|atomic_int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK-LABEL: @fi3e
comment|// CHECK: atomicrmw or
comment|// CHECK-NOT: {{ or }}
return|return
name|atomic_fetch_or
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|fi3f
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK-LABEL: @fi3f
comment|// CHECK-NOT: store volatile
comment|// CHECK: atomicrmw or
comment|// CHECK-NOT: {{ or }}
return|return
name|__atomic_fetch_or
argument_list|(
name|i
argument_list|,
operator|(
name|short
operator|)
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
comment|// CHECK-LABEL: @fi4(
comment|// CHECK: [[PAIR:%[.0-9A-Z_a-z]+]] = cmpxchg i32* [[PTR:%[.0-9A-Z_a-z]+]], i32 [[EXPECTED:%[.0-9A-Z_a-z]+]], i32 [[DESIRED:%[.0-9A-Z_a-z]+]]
comment|// CHECK: [[OLD:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 0
comment|// CHECK: [[CMP:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 1
comment|// CHECK: br i1 [[CMP]], label %[[STORE_EXPECTED:[.0-9A-Z_a-z]+]], label %[[CONTINUE:[.0-9A-Z_a-z]+]]
comment|// CHECK: store i32 [[OLD]]
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
comment|// CHECK-LABEL: @fi4a
comment|// CHECK: [[PAIR:%[.0-9A-Z_a-z]+]] = cmpxchg i32* [[PTR:%[.0-9A-Z_a-z]+]], i32 [[EXPECTED:%[.0-9A-Z_a-z]+]], i32 [[DESIRED:%[.0-9A-Z_a-z]+]]
comment|// CHECK: [[OLD:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 0
comment|// CHECK: [[CMP:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 1
comment|// CHECK: br i1 [[CMP]], label %[[STORE_EXPECTED:[.0-9A-Z_a-z]+]], label %[[CONTINUE:[.0-9A-Z_a-z]+]]
comment|// CHECK: store i32 [[OLD]]
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
comment|// CHECK-LABEL: @fi4b(
comment|// CHECK: [[PAIR:%[.0-9A-Z_a-z]+]] = cmpxchg weak i32* [[PTR:%[.0-9A-Z_a-z]+]], i32 [[EXPECTED:%[.0-9A-Z_a-z]+]], i32 [[DESIRED:%[.0-9A-Z_a-z]+]]
comment|// CHECK: [[OLD:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 0
comment|// CHECK: [[CMP:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 1
comment|// CHECK: br i1 [[CMP]], label %[[STORE_EXPECTED:[.0-9A-Z_a-z]+]], label %[[CONTINUE:[.0-9A-Z_a-z]+]]
comment|// CHECK: store i32 [[OLD]]
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
name|_Bool
name|fi4c
parameter_list|(
name|atomic_int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK-LABEL: @fi4c
comment|// CHECK: cmpxchg i32*
name|int
name|cmp
init|=
literal|0
decl_stmt|;
return|return
name|atomic_compare_exchange_strong
argument_list|(
name|i
argument_list|,
operator|&
name|cmp
argument_list|,
literal|1
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
comment|// CHECK-LABEL: @ff1
comment|// CHECK: load atomic i32, i32* {{.*}} monotonic
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
comment|// CHECK-LABEL: @ff2
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

begin_struct
struct|struct
name|S
block|{
name|double
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|S
name|fd1
parameter_list|(
name|struct
name|S
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @fd1
comment|// CHECK: [[RETVAL:%.*]] = alloca %struct.S, align 4
comment|// CHECK: [[RET:%.*]]    = alloca %struct.S, align 4
comment|// CHECK: [[CALL:%.*]]   = call i64 @__atomic_load_8(
comment|// CHECK: [[CAST:%.*]]   = bitcast %struct.S* [[RET]] to i64*
comment|// CHECK: store i64 [[CALL]], i64* [[CAST]], align 4
name|struct
name|S
name|ret
decl_stmt|;
name|__atomic_load
argument_list|(
name|a
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
name|void
name|fd2
parameter_list|(
name|struct
name|S
modifier|*
name|a
parameter_list|,
name|struct
name|S
modifier|*
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @fd2
comment|// CHECK:      [[A_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: [[B_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: store %struct.S* %a, %struct.S** [[A_ADDR]], align 4
comment|// CHECK-NEXT: store %struct.S* %b, %struct.S** [[B_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_A_PTR:%.*]] = load %struct.S*, %struct.S** [[A_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_B_PTR:%.*]] = load %struct.S*, %struct.S** [[B_ADDR]], align 4
comment|// CHECK-NEXT: [[COERCED_A:%.*]] = bitcast %struct.S* [[LOAD_A_PTR]] to i8*
comment|// CHECK-NEXT: [[COERCED_B:%.*]] = bitcast %struct.S* [[LOAD_B_PTR]] to i64*
comment|// CHECK-NEXT: [[LOAD_B:%.*]] = load i64, i64* [[COERCED_B]], align 4
comment|// CHECK-NEXT: call void @__atomic_store_8(i8* [[COERCED_A]], i64 [[LOAD_B]],
comment|// CHECK-NEXT: ret void
name|__atomic_store
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fd3
parameter_list|(
name|struct
name|S
modifier|*
name|a
parameter_list|,
name|struct
name|S
modifier|*
name|b
parameter_list|,
name|struct
name|S
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: @fd3
comment|// CHECK:      [[A_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: [[B_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: [[C_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: store %struct.S* %a, %struct.S** [[A_ADDR]], align 4
comment|// CHECK-NEXT: store %struct.S* %b, %struct.S** [[B_ADDR]], align 4
comment|// CHECK-NEXT: store %struct.S* %c, %struct.S** [[C_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_A_PTR:%.*]] = load %struct.S*, %struct.S** [[A_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_B_PTR:%.*]] = load %struct.S*, %struct.S** [[B_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_C_PTR:%.*]] = load %struct.S*, %struct.S** [[C_ADDR]], align 4
comment|// CHECK-NEXT: [[COERCED_A:%.*]] = bitcast %struct.S* [[LOAD_A_PTR]] to i8*
comment|// CHECK-NEXT: [[COERCED_B:%.*]] = bitcast %struct.S* [[LOAD_B_PTR]] to i64*
comment|// CHECK-NEXT: [[LOAD_B:%.*]] = load i64, i64* [[COERCED_B]], align 4
comment|// CHECK-NEXT: [[CALL:%.*]] = call i64 @__atomic_exchange_8(i8* [[COERCED_A]], i64 [[LOAD_B]],
comment|// CHECK-NEXT: [[COERCED_C:%.*]] = bitcast %struct.S* [[LOAD_C_PTR]] to i64*
comment|// CHECK-NEXT: store i64 [[CALL]], i64* [[COERCED_C]], align 4
name|__atomic_exchange
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|_Bool
name|fd4
parameter_list|(
name|struct
name|S
modifier|*
name|a
parameter_list|,
name|struct
name|S
modifier|*
name|b
parameter_list|,
name|struct
name|S
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: @fd4
comment|// CHECK:      [[A_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: [[B_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK-NEXT: [[C_ADDR:%.*]] = alloca %struct.S*, align 4
comment|// CHECK:      store %struct.S* %a, %struct.S** [[A_ADDR]], align 4
comment|// CHECK-NEXT: store %struct.S* %b, %struct.S** [[B_ADDR]], align 4
comment|// CHECK-NEXT: store %struct.S* %c, %struct.S** [[C_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_A_PTR:%.*]] = load %struct.S*, %struct.S** [[A_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_B_PTR:%.*]] = load %struct.S*, %struct.S** [[B_ADDR]], align 4
comment|// CHECK-NEXT: [[LOAD_C_PTR:%.*]] = load %struct.S*, %struct.S** [[C_ADDR]], align 4
comment|// CHECK-NEXT: [[COERCED_A:%.*]] = bitcast %struct.S* [[LOAD_A_PTR]] to i8*
comment|// CHECK-NEXT: [[COERCED_B:%.*]] = bitcast %struct.S* [[LOAD_B_PTR]] to i8*
comment|// CHECK-NEXT: [[COERCED_C:%.*]] = bitcast %struct.S* [[LOAD_C_PTR]] to i64*
comment|// CHECK-NEXT: [[LOAD_C:%.*]] = load i64, i64* [[COERCED_C]], align 4
comment|// CHECK-NEXT: [[CALL:%.*]] = call zeroext i1 @__atomic_compare_exchange_8(i8* [[COERCED_A]], i8* [[COERCED_B]], i64 [[LOAD_C]]
comment|// CHECK-NEXT: ret i1 [[CALL]]
return|return
name|__atomic_compare_exchange
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
literal|5
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
comment|// CHECK-LABEL: @fp1
comment|// CHECK: load atomic i32, i32* {{.*}} seq_cst
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
comment|// CHECK-LABEL: @fp2
comment|// CHECK: store i32 4
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
comment|// CHECK-LABEL: @fp2a
comment|// CHECK: store i32 4
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
comment|// CHECK-LABEL: @fc
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
comment|// CHECK-LABEL: @fs
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
comment|// CHECK-LABEL: @fsa
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
comment|// CHECK-LABEL: @fsb
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
comment|// CHECK-LABEL: @lock_free
comment|// CHECK: call i32 @__atomic_is_lock_free(i32 3, i8* null)
name|__c11_atomic_is_lock_free
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i32 16, i8* {{.*}}@sixteen{{.*}})
name|__atomic_is_lock_free
argument_list|(
literal|16
argument_list|,
operator|&
name|sixteen
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i32 17, i8* {{.*}}@seventeen{{.*}})
name|__atomic_is_lock_free
argument_list|(
literal|17
argument_list|,
operator|&
name|seventeen
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @__atomic_is_lock_free(i32 4, {{.*}})
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
comment|// CHECK: call i32 @__atomic_is_lock_free(i32 4, {{.*}})
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
comment|// CHECK-LABEL: @structAtomicStore
name|struct
name|foo
name|f
init|=
block|{
literal|0
block|}
decl_stmt|;
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
comment|// CHECK: call void @__atomic_store(i32 3, i8* {{.*}} @smallThing
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
comment|// CHECK: call void @__atomic_store(i32 512, i8* {{.*}} @bigThing
block|}
end_function

begin_function
name|void
name|structAtomicLoad
parameter_list|()
block|{
comment|// CHECK-LABEL: @structAtomicLoad
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
comment|// CHECK: call void @__atomic_load(i32 3, i8* {{.*}} @smallThing
name|struct
name|foo
name|f
init|=
block|{
literal|0
block|}
decl_stmt|;
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
comment|// CHECK: call void @__atomic_load(i32 512, i8* {{.*}} @bigThing
block|}
end_function

begin_function
name|struct
name|foo
name|structAtomicExchange
parameter_list|()
block|{
comment|// CHECK-LABEL: @structAtomicExchange
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
comment|// CHECK: call void @__atomic_exchange(i32 512, {{.*}}, i8* bitcast ({{.*}} @bigThing to i8*),
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
comment|// CHECK: call void @__atomic_exchange(i32 512, i8* bitcast ({{.*}} @bigAtomic to i8*),
block|}
end_function

begin_function
name|int
name|structAtomicCmpExchange
parameter_list|()
block|{
comment|// CHECK-LABEL: @structAtomicCmpExchange
comment|// CHECK: %[[x_mem:.*]] = alloca i8
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
comment|// CHECK: %[[call1:.*]] = call zeroext i1 @__atomic_compare_exchange(i32 3, {{.*}} @smallThing{{.*}} @thing1{{.*}} @thing2
comment|// CHECK: %[[zext1:.*]] = zext i1 %[[call1]] to i8
comment|// CHECK: store i8 %[[zext1]], i8* %[[x_mem]], align 1
comment|// CHECK: %[[x:.*]] = load i8, i8* %[[x_mem]]
comment|// CHECK: %[[x_bool:.*]] = trunc i8 %[[x]] to i1
comment|// CHECK: %[[conv1:.*]] = zext i1 %[[x_bool]] to i32
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
comment|// CHECK: %[[call2:.*]] = call zeroext i1 @__atomic_compare_exchange(i32 512, i8* bitcast ({{.*}} @bigAtomic to i8*),
comment|// CHECK: %[[conv2:.*]] = zext i1 %[[call2]] to i32
comment|// CHECK: %[[and:.*]] = and i32 %[[conv1]], %[[conv2]]
comment|// CHECK: ret i32 %[[and]]
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
comment|// CHECK-LABEL: @atomic_init_foo
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

begin_comment
comment|// CHECK-LABEL: @failureOrder
end_comment

begin_function
name|void
name|failureOrder
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|ptr2
parameter_list|)
block|{
name|__c11_atomic_compare_exchange_strong
argument_list|(
name|ptr
argument_list|,
name|ptr2
argument_list|,
literal|43
argument_list|,
name|memory_order_acquire
argument_list|,
name|memory_order_relaxed
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg i32* {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z_.]+}} acquire monotonic
name|__c11_atomic_compare_exchange_weak
argument_list|(
name|ptr
argument_list|,
name|ptr2
argument_list|,
literal|43
argument_list|,
name|memory_order_seq_cst
argument_list|,
name|memory_order_acquire
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg weak i32* {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z_.]+}} seq_cst acquire
comment|// Unknown ordering: conservatively pick strongest valid option (for now!).
name|__atomic_compare_exchange
argument_list|(
name|ptr2
argument_list|,
name|ptr2
argument_list|,
name|ptr2
argument_list|,
literal|0
argument_list|,
name|memory_order_acq_rel
argument_list|,
operator|*
name|ptr2
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg i32* {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z_.]+}} acq_rel acquire
comment|// Undefined behaviour: don't really care what that last ordering is so leave
comment|// it out:
name|__atomic_compare_exchange_n
argument_list|(
name|ptr2
argument_list|,
name|ptr2
argument_list|,
literal|43
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg weak i32* {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z_.]+}} seq_cst
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @generalFailureOrder
end_comment

begin_function
name|void
name|generalFailureOrder
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|ptr2
parameter_list|,
name|int
name|success
parameter_list|,
name|int
name|fail
parameter_list|)
block|{
name|__c11_atomic_compare_exchange_strong
argument_list|(
name|ptr
argument_list|,
name|ptr2
argument_list|,
literal|42
argument_list|,
name|success
argument_list|,
name|fail
argument_list|)
expr_stmt|;
comment|// CHECK: switch i32 {{.*}}, label %[[MONOTONIC:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: i32 1, label %[[ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 2, label %[[ACQUIRE]]
comment|// CHECK-NEXT: i32 3, label %[[RELEASE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 4, label %[[ACQREL:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 5, label %[[SEQCST:[0-9a-zA-Z._]+]]
comment|// CHECK: [[MONOTONIC]]
comment|// CHECK: switch {{.*}}, label %[[MONOTONIC_MONOTONIC:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: ]
comment|// CHECK: [[ACQUIRE]]
comment|// CHECK: switch {{.*}}, label %[[ACQUIRE_MONOTONIC:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: i32 1, label %[[ACQUIRE_ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 2, label %[[ACQUIRE_ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: ]
comment|// CHECK: [[RELEASE]]
comment|// CHECK: switch {{.*}}, label %[[RELEASE_MONOTONIC:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: ]
comment|// CHECK: [[ACQREL]]
comment|// CHECK: switch {{.*}}, label %[[ACQREL_MONOTONIC:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: i32 1, label %[[ACQREL_ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 2, label %[[ACQREL_ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: ]
comment|// CHECK: [[SEQCST]]
comment|// CHECK: switch {{.*}}, label %[[SEQCST_MONOTONIC:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: i32 1, label %[[SEQCST_ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 2, label %[[SEQCST_ACQUIRE:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: i32 5, label %[[SEQCST_SEQCST:[0-9a-zA-Z._]+]]
comment|// CHECK-NEXT: ]
comment|// CHECK: [[MONOTONIC_MONOTONIC]]
comment|// CHECK: cmpxchg {{.*}} monotonic monotonic
comment|// CHECK: br
comment|// CHECK: [[ACQUIRE_MONOTONIC]]
comment|// CHECK: cmpxchg {{.*}} acquire monotonic
comment|// CHECK: br
comment|// CHECK: [[ACQUIRE_ACQUIRE]]
comment|// CHECK: cmpxchg {{.*}} acquire acquire
comment|// CHECK: br
comment|// CHECK: [[ACQREL_MONOTONIC]]
comment|// CHECK: cmpxchg {{.*}} acq_rel monotonic
comment|// CHECK: br
comment|// CHECK: [[ACQREL_ACQUIRE]]
comment|// CHECK: cmpxchg {{.*}} acq_rel acquire
comment|// CHECK: br
comment|// CHECK: [[SEQCST_MONOTONIC]]
comment|// CHECK: cmpxchg {{.*}} seq_cst monotonic
comment|// CHECK: br
comment|// CHECK: [[SEQCST_ACQUIRE]]
comment|// CHECK: cmpxchg {{.*}} seq_cst acquire
comment|// CHECK: br
comment|// CHECK: [[SEQCST_SEQCST]]
comment|// CHECK: cmpxchg {{.*}} seq_cst seq_cst
comment|// CHECK: br
block|}
end_function

begin_function
name|void
name|generalWeakness
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|ptr2
parameter_list|,
name|_Bool
name|weak
parameter_list|)
block|{
name|__atomic_compare_exchange_n
argument_list|(
name|ptr
argument_list|,
name|ptr2
argument_list|,
literal|42
argument_list|,
name|weak
argument_list|,
name|memory_order_seq_cst
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: switch i1 {{.*}}, label %[[WEAK:[0-9a-zA-Z._]+]] [
comment|// CHECK-NEXT: i1 false, label %[[STRONG:[0-9a-zA-Z._]+]]
comment|// CHECK: [[STRONG]]
comment|// CHECK-NOT: br
comment|// CHECK: cmpxchg {{.*}} seq_cst seq_cst
comment|// CHECK: br
comment|// CHECK: [[WEAK]]
comment|// CHECK-NOT: br
comment|// CHECK: cmpxchg weak {{.*}} seq_cst seq_cst
comment|// CHECK: br
block|}
end_function

begin_comment
comment|// Having checked the flow in the previous two cases, we'll trust clang to
end_comment

begin_comment
comment|// combine them sanely.
end_comment

begin_function
name|void
name|EMIT_ALL_THE_THINGS
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|ptr2
parameter_list|,
name|int
name|new
parameter_list|,
name|_Bool
name|weak
parameter_list|,
name|int
name|success
parameter_list|,
name|int
name|fail
parameter_list|)
block|{
name|__atomic_compare_exchange
argument_list|(
name|ptr
argument_list|,
name|ptr2
argument_list|,
operator|&
name|new
argument_list|,
name|weak
argument_list|,
name|success
argument_list|,
name|fail
argument_list|)
expr_stmt|;
comment|// CHECK: = cmpxchg {{.*}} monotonic monotonic
comment|// CHECK: = cmpxchg weak {{.*}} monotonic monotonic
comment|// CHECK: = cmpxchg {{.*}} acquire monotonic
comment|// CHECK: = cmpxchg {{.*}} acquire acquire
comment|// CHECK: = cmpxchg weak {{.*}} acquire monotonic
comment|// CHECK: = cmpxchg weak {{.*}} acquire acquire
comment|// CHECK: = cmpxchg {{.*}} release monotonic
comment|// CHECK: = cmpxchg weak {{.*}} release monotonic
comment|// CHECK: = cmpxchg {{.*}} acq_rel monotonic
comment|// CHECK: = cmpxchg {{.*}} acq_rel acquire
comment|// CHECK: = cmpxchg weak {{.*}} acq_rel monotonic
comment|// CHECK: = cmpxchg weak {{.*}} acq_rel acquire
comment|// CHECK: = cmpxchg {{.*}} seq_cst monotonic
comment|// CHECK: = cmpxchg {{.*}} seq_cst acquire
comment|// CHECK: = cmpxchg {{.*}} seq_cst seq_cst
comment|// CHECK: = cmpxchg weak {{.*}} seq_cst monotonic
comment|// CHECK: = cmpxchg weak {{.*}} seq_cst acquire
comment|// CHECK: = cmpxchg weak {{.*}} seq_cst seq_cst
block|}
end_function

begin_function
name|int
name|PR21643
parameter_list|()
block|{
return|return
name|__atomic_or_fetch
argument_list|(
operator|(
name|int
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|257
argument_list|)
operator|)
argument_list|)
operator|*
operator|)
literal|0x308
argument_list|,
literal|1
argument_list|,
name|__ATOMIC_RELAXED
argument_list|)
return|;
comment|// CHECK: %[[atomictmp:.*]] = alloca i32, align 4
comment|// CHECK: %[[atomicdst:.*]] = alloca i32, align 4
comment|// CHECK: store i32 1, i32* %[[atomictmp]]
comment|// CHECK: %[[one:.*]] = load i32, i32* %[[atomictmp]], align 4
comment|// CHECK: %[[old:.*]] = atomicrmw or i32 addrspace(257)* inttoptr (i32 776 to i32 addrspace(257)*), i32 %[[one]] monotonic
comment|// CHECK: %[[new:.*]] = or i32 %[[old]], %[[one]]
comment|// CHECK: store i32 %[[new]], i32* %[[atomicdst]], align 4
comment|// CHECK: %[[ret:.*]] = load i32, i32* %[[atomicdst]], align 4
comment|// CHECK: ret i32 %[[ret]]
block|}
end_function

begin_function
name|int
name|PR17306_1
parameter_list|(
specifier|volatile
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK-LABEL: @PR17306_1
comment|// CHECK:      %[[i_addr:.*]] = alloca i32
comment|// CHECK-NEXT: %[[atomicdst:.*]] = alloca i32
comment|// CHECK-NEXT: store i32* %i, i32** %[[i_addr]]
comment|// CHECK-NEXT: %[[addr:.*]] = load i32*, i32** %[[i_addr]]
comment|// CHECK-NEXT: %[[res:.*]] = load atomic volatile i32, i32* %[[addr]] seq_cst
comment|// CHECK-NEXT: store i32 %[[res]], i32* %[[atomicdst]]
comment|// CHECK-NEXT: %[[retval:.*]] = load i32, i32* %[[atomicdst]]
comment|// CHECK-NEXT: ret i32 %[[retval]]
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
name|PR17306_2
parameter_list|(
specifier|volatile
name|int
modifier|*
name|i
parameter_list|,
name|int
name|value
parameter_list|)
block|{
comment|// CHECK-LABEL: @PR17306_2
comment|// CHECK:      %[[i_addr:.*]] = alloca i32*
comment|// CHECK-NEXT: %[[value_addr:.*]] = alloca i32
comment|// CHECK-NEXT: %[[atomictmp:.*]] = alloca i32
comment|// CHECK-NEXT: %[[atomicdst:.*]] = alloca i32
comment|// CHECK-NEXT: store i32* %i, i32** %[[i_addr]]
comment|// CHECK-NEXT: store i32 %value, i32* %[[value_addr]]
comment|// CHECK-NEXT: %[[i_lval:.*]] = load i32*, i32** %[[i_addr]]
comment|// CHECK-NEXT: %[[value:.*]] = load i32, i32* %[[value_addr]]
comment|// CHECK-NEXT: store i32 %[[value]], i32* %[[atomictmp]]
comment|// CHECK-NEXT: %[[value_lval:.*]] = load i32, i32* %[[atomictmp]]
comment|// CHECK-NEXT: %[[old_val:.*]] = atomicrmw volatile add i32* %[[i_lval]], i32 %[[value_lval]] seq_cst
comment|// CHECK-NEXT: %[[new_val:.*]] = add i32 %[[old_val]], %[[value_lval]]
comment|// CHECK-NEXT: store i32 %[[new_val]], i32* %[[atomicdst]]
comment|// CHECK-NEXT: %[[retval:.*]] = load i32, i32* %[[atomicdst]]
comment|// CHECK-NEXT: ret i32 %[[retval]]
return|return
name|__atomic_add_fetch
argument_list|(
name|i
argument_list|,
name|value
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

