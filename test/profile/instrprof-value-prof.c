begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -mllvm -vp-static-alloc=false  -O2 -o %t %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.profraw %run %t
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t-2.profraw %run %t DO_NOT_INSTRUMENT
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-2.profdata %t-2.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-merged.profdata %t.profraw %t-2.profdata
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-2.profdata | FileCheck  %s -check-prefix=NO-VALUE
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t.profdata | FileCheck  %s
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-merged.profdata | FileCheck  %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t-3.profraw LLVM_VP_BUFFER_SIZE=1 %run %t
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t-4.profraw LLVM_VP_BUFFER_SIZE=8 %run %t
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t-5.profraw LLVM_VP_BUFFER_SIZE=128 %run %t
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t-6.profraw LLVM_VP_BUFFER_SIZE=1024 %run %t
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t-7.profraw LLVM_VP_BUFFER_SIZE=102400 %run %t
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-3.profdata %t-3.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-4.profdata %t-4.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-5.profdata %t-5.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-6.profdata %t-6.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t-7.profdata %t-7.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-3.profdata | FileCheck  %s
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-4.profdata | FileCheck  %s
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-5.profdata | FileCheck  %s
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-6.profdata | FileCheck  %s
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t-7.profdata | FileCheck  %s
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

begin_define
define|#
directive|define
name|DEF_FUNC
parameter_list|(
name|x
parameter_list|)
define|\
value|void x() {}
end_define

begin_define
define|#
directive|define
name|DEF_2_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_FUNC(x##_1) DEF_FUNC(x##_2)
end_define

begin_define
define|#
directive|define
name|DEF_4_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_2_FUNCS(x##_1) DEF_2_FUNCS(x##_2)
end_define

begin_define
define|#
directive|define
name|DEF_8_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_4_FUNCS(x##_1) DEF_4_FUNCS(x##_2)
end_define

begin_define
define|#
directive|define
name|DEF_16_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_8_FUNCS(x##_1) DEF_8_FUNCS(x##_2)
end_define

begin_define
define|#
directive|define
name|DEF_32_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_16_FUNCS(x##_1) DEF_16_FUNCS(x##_2)
end_define

begin_define
define|#
directive|define
name|DEF_64_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_32_FUNCS(x##_1) DEF_32_FUNCS(x##_2)
end_define

begin_define
define|#
directive|define
name|DEF_128_FUNCS
parameter_list|(
name|x
parameter_list|)
value|DEF_64_FUNCS(x##_1) DEF_64_FUNCS(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_ADDR
parameter_list|(
name|x
parameter_list|)
value|&x,
end_define

begin_define
define|#
directive|define
name|FUNC_2_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_ADDR(x##_1) FUNC_ADDR(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_4_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_2_ADDRS(x##_1) FUNC_2_ADDRS(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_8_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_4_ADDRS(x##_1) FUNC_4_ADDRS(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_16_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_8_ADDRS(x##_1) FUNC_8_ADDRS(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_32_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_16_ADDRS(x##_1) FUNC_16_ADDRS(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_64_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_32_ADDRS(x##_1) FUNC_32_ADDRS(x##_2)
end_define

begin_define
define|#
directive|define
name|FUNC_128_ADDRS
parameter_list|(
name|x
parameter_list|)
value|FUNC_64_ADDRS(x##_1) FUNC_64_ADDRS(x##_2)
end_define

begin_macro
name|DEF_8_FUNCS
argument_list|(
argument|callee
argument_list|)
end_macro

begin_macro
name|DEF_128_FUNCS
argument_list|(
argument|caller
argument_list|)
end_macro

begin_decl_stmt
name|void
modifier|*
name|CallerAddrs
index|[]
init|=
block|{
name|FUNC_128_ADDRS
argument_list|(
argument|caller
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|CalleeAddrs
index|[]
init|=
block|{
name|FUNC_8_ADDRS
argument_list|(
argument|callee
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|CallerInfo
block|{
name|void
modifier|*
name|CallerAddr
decl_stmt|;
name|uint32_t
name|NS
decl_stmt|;
comment|/* Number value sites. */
block|}
name|CallerInfo
typedef|;
end_typedef

begin_decl_stmt
name|CallerInfo
name|CallerInfos
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|cmpaddr
parameter_list|(
specifier|const
name|void
modifier|*
name|p1
parameter_list|,
specifier|const
name|void
modifier|*
name|p2
parameter_list|)
block|{
name|CallerInfo
modifier|*
name|addr1
init|=
operator|(
name|CallerInfo
operator|*
operator|)
name|p1
decl_stmt|;
name|CallerInfo
modifier|*
name|addr2
init|=
operator|(
name|CallerInfo
operator|*
operator|)
name|p2
decl_stmt|;
return|return
operator|(
name|intptr_t
operator|)
name|addr2
operator|->
name|CallerAddr
operator|-
operator|(
name|intptr_t
operator|)
name|addr1
operator|->
name|CallerAddr
return|;
block|}
end_function

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
literal|0
decl_stmt|,
name|I
decl_stmt|,
name|V
decl_stmt|,
name|doInstrument
init|=
literal|1
decl_stmt|;
specifier|const
name|__llvm_profile_data
modifier|*
name|Data
decl_stmt|,
modifier|*
name|DataEnd
decl_stmt|;
if|if
condition|(
name|argc
operator|>=
literal|2
operator|&&
operator|!
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"DO_NOT_INSTRUMENT"
argument_list|)
condition|)
name|doInstrument
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|128
condition|;
name|I
operator|++
control|)
block|{
name|CallerInfos
index|[
name|I
index|]
operator|.
name|CallerAddr
operator|=
name|CallerAddrs
index|[
name|I
index|]
expr_stmt|;
name|CallerInfos
index|[
name|I
index|]
operator|.
name|NS
operator|=
name|I
expr_stmt|;
block|}
name|qsort
argument_list|(
name|CallerInfos
argument_list|,
sizeof|sizeof
argument_list|(
name|CallerInfos
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|CallerInfo
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|CallerInfo
argument_list|)
argument_list|,
name|cmpaddr
argument_list|)
expr_stmt|;
comment|/* We will synthesis value profile data for 128 callers functions declared.    * The number of value sites for each caller function is recorded in    * the NS field of the CallerInfo object. For each value site, the number of    * callee values is determined by the site index (modulo 8). The frequency    * of each callee target synthesized is equal to V + 1, in which V is the    * index of the target value for the callsite. */
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
name|CallerInfo
name|Key
decl_stmt|,
modifier|*
name|Res
decl_stmt|;
name|Key
operator|.
name|CallerAddr
operator|=
name|func
expr_stmt|;
name|Res
operator|=
operator|(
name|CallerInfo
operator|*
operator|)
name|bsearch
argument_list|(
operator|&
name|Key
argument_list|,
name|CallerInfos
argument_list|,
sizeof|sizeof
argument_list|(
name|CallerInfos
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|CallerInfo
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|CallerInfo
argument_list|)
argument_list|,
name|cmpaddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|Res
condition|)
block|{
name|NS
operator|=
name|Res
operator|->
name|NS
expr_stmt|;
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
name|NS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|doInstrument
condition|)
block|{
continue|continue;
block|}
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
for|for
control|(
name|V
operator|=
literal|0
init|;
name|V
operator|<
name|S
operator|%
literal|8
condition|;
name|V
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
name|V
operator|+
literal|1
condition|;
name|C
operator|++
control|)
name|__llvm_profile_instrument_target
argument_list|(
operator|(
name|uint64_t
operator|)
name|CalleeAddrs
index|[
name|V
index|]
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
block|}
end_function

begin_comment
comment|// NO-VALUE: Indirect Call Site Count: 127
end_comment

begin_comment
comment|// NO-VALUE-NEXT: Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-LABEL: caller_1_1_1_1_2_2_1:
end_comment

begin_comment
comment|// CHECK: Indirect Call Site Count: 6
end_comment

begin_comment
comment|// CHECK-NEXT: Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-NEXT: [ 1, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 2, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 2, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 3, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 3, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 3, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 4, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 4, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 4, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 4, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 5, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 5, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 5, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 5, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT: [ 5, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-LABEL: caller_2_2_2_2_2_2_2:
end_comment

begin_comment
comment|// CHECK: Indirect Call Site Count: 127
end_comment

begin_comment
comment|// CHECK-NEXT: Indirect Target Results:
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 1, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 2, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 2, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 3, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 3, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 3, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 4, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 4, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 4, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 4, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 5, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 5, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 5, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 5, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 5, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 6, callee_2_1_2, 6 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 6, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 6, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 6, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 6, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 6, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_2_2_1, 7 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_2_1_2, 6 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 7, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 9, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 10, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 10, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 11, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 11, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 11, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 12, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 12, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 12, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 12, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 13, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 13, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 13, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 13, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 13, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 14, callee_2_1_2, 6 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 14, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 14, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 14, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 14, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 14, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_2_2_1, 7 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_2_1_2, 6 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 15, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 17, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 18, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 18, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 19, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 19, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 19, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 20, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 20, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 20, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 20, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 21, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 21, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 21, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 21, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 21, callee_1_1_1, 1 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 22, callee_2_1_2, 6 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 22, callee_2_1_1, 5 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 22, callee_1_2_2, 4 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 22, callee_1_2_1, 3 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 22, callee_1_1_2, 2 ]
end_comment

begin_comment
comment|// CHECK-NEXT:  [ 22, callee_1_1_1, 1 ]
end_comment

end_unit

