begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -O0 -debug-info-kind=limited %s -o - | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefixes CHECK %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple hexagon-unknown--elf -emit-llvm -O0 -debug-info-kind=limited %s -o - | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefixes CHECK,CHECK-LDsm %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm -O0 -debug-info-kind=limited %s -o - | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefixes CHECK,CHECK-LDlg %s
end_comment

begin_comment
comment|// Per PR26619, check that for referenced static const of floating-point type,
end_comment

begin_comment
comment|// we emit its constant value in debug info.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE that __fp16 is assumed to be 16 bits, float is assumed to be
end_comment

begin_comment
comment|// 32 bits, and double is assumed to be 64 bits.  Size of long double
end_comment

begin_comment
comment|// is not known (for example, it is 64 bits for hexagon-unknown--elf,
end_comment

begin_comment
comment|// but 128 bits for x86_64-unknown-linux-gnu).  Therefore, we specify
end_comment

begin_comment
comment|// target triples where it has a known size, and check accordingly:
end_comment

begin_comment
comment|// for the absence of a constant (CHECK-LDlg) when the size exceeds 64
end_comment

begin_comment
comment|// bits, and for the presence of a constant (CHECK-LDsm) but not its
end_comment

begin_comment
comment|// value when the size does not exceed 64 bits.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE that PR26619 is not yet fixed for types greater than 64 bits.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|__fp16
name|hVal
init|=
literal|29
operator|/
literal|13.0f
decl_stmt|;
end_decl_stmt

begin_comment
comment|//    2.2307692307692307692     (2.23046875)
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|fVal
init|=
operator|-
literal|147
operator|/
literal|17.0f
decl_stmt|;
end_decl_stmt

begin_comment
comment|//   -8.6470588235294117647     (-8.64705849)
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|dVal
init|=
literal|19637
operator|/
literal|7.0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 2805.2857142857142857        (2805.2857142857142)
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|long
name|double
name|ldVal
init|=
literal|3
operator|/
literal|1234567.0L
decl_stmt|;
end_decl_stmt

begin_comment
comment|//    2.4300017739012949479e-06 (<depends on size of long double>)
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|hVal
operator|+
name|fVal
operator|+
name|dVal
operator|+
name|ldVal
return|;
block|}
end_function

begin_comment
comment|// CHECK: !DIGlobalVariableExpression(var: [[HVAL:.*]], expr: [[HEXPR:.*]])
end_comment

begin_comment
comment|// CHECK: [[HVAL]] = distinct !DIGlobalVariable(name: "hVal",
end_comment

begin_comment
comment|// CHECK-SAME:                                  isLocal: true, isDefinition: true
end_comment

begin_comment
comment|// CHECK: [[HEXPR]] = !DIExpression(DW_OP_constu, 16502, DW_OP_stack_value)
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariableExpression(var: [[FVAL:.*]], expr: [[FEXPR:.*]])
end_comment

begin_comment
comment|// CHECK: [[FVAL]] = distinct !DIGlobalVariable(name: "fVal",
end_comment

begin_comment
comment|// CHECK-SAME:                                  isLocal: true, isDefinition: true
end_comment

begin_comment
comment|// CHECK: [[FEXPR]] = !DIExpression(DW_OP_constu, 3238681178, DW_OP_stack_value)
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariableExpression(var: [[DVAL:.*]], expr: [[DEXPR:.*]])
end_comment

begin_comment
comment|// CHECK: [[DVAL]] = distinct !DIGlobalVariable(name: "dVal",
end_comment

begin_comment
comment|// CHECK-SAME:                                  isLocal: true, isDefinition: true
end_comment

begin_comment
comment|// CHECK: [[DEXPR]] = !DIExpression(DW_OP_constu, 4658387303597904457, DW_OP_stack_value)
end_comment

begin_comment
comment|// CHECK-LDlg-DAG: [[LDVAL:.*]] = distinct !DIGlobalVariable(name: "ldVal", {{.*}}, isLocal: true, isDefinition: true)
end_comment

begin_comment
comment|// CHECK-LDlg-DAG: !DIGlobalVariableExpression(var: [[LDVAL]])
end_comment

begin_comment
comment|// CHECK-LDsm-DAG: [[LDVAL:.*]] = distinct !DIGlobalVariable(name: "ldVal", {{.*}}, isLocal: true, isDefinition: true)
end_comment

begin_comment
comment|// CHECK-LDsm-DAG: !DIGlobalVariableExpression(var: [[LDVAL]], expr:
end_comment

end_unit

