begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -O2 -o %t %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.profraw %run %t
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t.profdata> %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-1< %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-2< %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-3< %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-4< %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-5< %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-6< %t.out
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|__llvm_profile_data
name|__llvm_profile_data
typedef|;
end_typedef

begin_function_decl
specifier|const
name|__llvm_profile_data
modifier|*
name|__llvm_profile_begin_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|__llvm_profile_data
modifier|*
name|__llvm_profile_end_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__llvm_profile_set_num_value_sites
parameter_list|(
name|__llvm_profile_data
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|ValueKind
parameter_list|,
name|uint16_t
name|NumValueSites
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__llvm_profile_data
modifier|*
name|__llvm_profile_iterate_data
parameter_list|(
specifier|const
name|__llvm_profile_data
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|__llvm_get_function_addr
parameter_list|(
specifier|const
name|__llvm_profile_data
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__llvm_profile_instrument_target
parameter_list|(
name|uint64_t
name|TargetValue
parameter_list|,
name|void
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|CounterIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|callee1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee2
parameter_list|()
block|{}
end_function

begin_function
name|void
name|caller_without_value_site1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|caller_with_value_site_never_called1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|caller_with_vp1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|caller_with_value_site_never_called2
parameter_list|()
block|{}
end_function

begin_function
name|void
name|caller_without_value_site2
parameter_list|()
block|{}
end_function

begin_function
name|void
name|caller_with_vp2
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
function_decl|(
modifier|*
name|callee1Ptr
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|callee2Ptr
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|setFunctionPointers
argument_list|()
block|{
name|callee1Ptr
operator|=
name|callee1
expr_stmt|;
name|callee2Ptr
operator|=
name|callee2
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|unsigned
name|S
decl_stmt|,
name|NS
init|=
literal|10
decl_stmt|,
name|V
decl_stmt|;
specifier|const
name|__llvm_profile_data
modifier|*
name|Data
decl_stmt|,
modifier|*
name|DataEnd
decl_stmt|;
name|setFunctionPointers
argument_list|()
expr_stmt|;
name|Data
operator|=
name|__llvm_profile_begin_data
argument_list|()
expr_stmt|;
name|DataEnd
operator|=
name|__llvm_profile_end_data
argument_list|()
expr_stmt|;
for|for
control|(
init|;
name|Data
operator|<
name|DataEnd
condition|;
name|Data
operator|=
name|__llvm_profile_iterate_data
argument_list|(
name|Data
argument_list|)
control|)
block|{
name|void
modifier|*
name|func
init|=
name|__llvm_get_function_addr
argument_list|(
name|Data
argument_list|)
decl_stmt|;
if|if
condition|(
name|func
operator|==
name|caller_without_value_site1
operator|||
name|func
operator|==
name|caller_without_value_site2
operator|||
name|func
operator|==
name|callee1
operator|||
name|func
operator|==
name|callee2
operator|||
name|func
operator|==
expr|main
condition|)
continue|continue;
name|__llvm_profile_set_num_value_sites
argument_list|(
operator|(
name|__llvm_profile_data
operator|*
operator|)
name|Data
argument_list|,
literal|0
comment|/*IPVK_IndirectCallTarget */
argument_list|,
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
name|func
operator|==
name|caller_with_value_site_never_called1
operator|||
name|func
operator|==
name|caller_with_value_site_never_called2
condition|)
continue|continue;
for|for
control|(
name|S
operator|=
literal|0
init|;
name|S
operator|<
name|NS
condition|;
name|S
operator|++
control|)
block|{
name|unsigned
name|C
decl_stmt|;
for|for
control|(
name|C
operator|=
literal|0
init|;
name|C
operator|<
name|S
operator|+
literal|1
condition|;
name|C
operator|++
control|)
block|{
name|__llvm_profile_instrument_target
argument_list|(
operator|(
name|uint64_t
operator|)
name|callee1Ptr
argument_list|,
operator|(
name|void
operator|*
operator|)
name|Data
argument_list|,
name|S
argument_list|)
expr_stmt|;
if|if
condition|(
name|C
operator|%
literal|2
operator|==
literal|0
condition|)
name|__llvm_profile_instrument_target
argument_list|(
operator|(
name|uint64_t
operator|)
name|callee2Ptr
argument_list|,
operator|(
name|void
operator|*
operator|)
name|Data
argument_list|,
name|S
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|// CHECK-1-LABEL:   caller_with_value_site_never_called2:
end_comment

begin_comment
comment|// CHECK-1-NEXT:    Hash: 0x0000000000000000
end_comment

begin_comment
comment|// CHECK-1-NEXT:    Counters:
end_comment

begin_comment
comment|// CHECK-1-NEXT:    Function count
end_comment

begin_comment
comment|// CHECK-1-NEXT:    Indirect Call Site Count: 10
end_comment

begin_comment
comment|// CHECK-1-NEXT:    Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-2-LABEL:   caller_with_vp2:
end_comment

begin_comment
comment|// CHECK-2-NEXT:    Hash: 0x0000000000000000
end_comment

begin_comment
comment|// CHECK-2-NEXT:    Counters:
end_comment

begin_comment
comment|// CHECK-2-NEXT:    Function count:
end_comment

begin_comment
comment|// CHECK-2-NEXT:    Indirect Call Site Count: 10
end_comment

begin_comment
comment|// CHECK-2-NEXT:    Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 0, callee1, 1 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 0, callee2, 1 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 1, callee1, 2 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 1, callee2, 1 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 2, callee1, 3 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 2, callee2, 2 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 3, callee1, 4 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 3, callee2, 2 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 4, callee1, 5 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 4, callee2, 3 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 5, callee1, 6 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 5, callee2, 3 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 6, callee1, 7 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 6, callee2, 4 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 7, callee1, 8 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 7, callee2, 4 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 8, callee1, 9 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 8, callee2, 5 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 9, callee1, 10 ]
end_comment

begin_comment
comment|// CHECK-2-NEXT:	[ 9, callee2, 5 ]
end_comment

begin_comment
comment|// CHECK-3-LABEL:   caller_with_vp1:
end_comment

begin_comment
comment|// CHECK-3-NEXT:    Hash: 0x0000000000000000
end_comment

begin_comment
comment|// CHECK-3-NEXT:    Counters:
end_comment

begin_comment
comment|// CHECK-3-NEXT:    Function count
end_comment

begin_comment
comment|// CHECK-3-NEXT:    Indirect Call Site Count: 10
end_comment

begin_comment
comment|// CHECK-3-NEXT:    Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 0, callee1, 1 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 0, callee2, 1 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 1, callee1, 2 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 1, callee2, 1 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 2, callee1, 3 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 2, callee2, 2 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 3, callee1, 4 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 3, callee2, 2 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 4, callee1, 5 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 4, callee2, 3 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 5, callee1, 6 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 5, callee2, 3 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 6, callee1, 7 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 6, callee2, 4 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 7, callee1, 8 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 7, callee2, 4 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 8, callee1, 9 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 8, callee2, 5 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 9, callee1, 10 ]
end_comment

begin_comment
comment|// CHECK-3-NEXT:	[ 9, callee2, 5 ]
end_comment

begin_comment
comment|// CHECK-4-LABEL:   caller_with_value_site_never_called1:
end_comment

begin_comment
comment|// CHECK-4-NEXT:    Hash: 0x0000000000000000
end_comment

begin_comment
comment|// CHECK-4-NEXT:    Counters:
end_comment

begin_comment
comment|// CHECK-4-NEXT:    Function count:
end_comment

begin_comment
comment|// CHECK-4-NEXT:    Indirect Call Site Count: 10
end_comment

begin_comment
comment|// CHECK-4-NEXT:    Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-5-LABEL:   caller_without_value_site2:
end_comment

begin_comment
comment|// CHECK-5-NEXT:    Hash: 0x0000000000000000
end_comment

begin_comment
comment|// CHECK-5-NEXT:    Counters:
end_comment

begin_comment
comment|// CHECK-5-NEXT:    Function count:
end_comment

begin_comment
comment|// CHECK-5-NEXT:    Indirect Call Site Count: 0
end_comment

begin_comment
comment|// CHECK-5-NEXT:    Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-6-LABEL:   caller_without_value_site1:
end_comment

begin_comment
comment|// CHECK-6-NEXT:    Hash: 0x0000000000000000
end_comment

begin_comment
comment|// CHECK-6-NEXT:    Counters:
end_comment

begin_comment
comment|// CHECK-6-NEXT:    Function count:
end_comment

begin_comment
comment|// CHECK-6-NEXT:    Indirect Call Site Count: 0
end_comment

begin_comment
comment|// CHECK-6-NEXT:    Indirect Target Results:
end_comment

end_unit

