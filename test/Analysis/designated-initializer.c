begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=debug.DumpCFG %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_struct
struct|struct
name|Q
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|UQ
block|{
name|struct
name|Q
name|q
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|UQ
name|getUQ
parameter_list|()
block|{
name|union
name|UQ
name|u
init|=
block|{
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
block|}
decl_stmt|;
return|return
name|u
return|;
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
struct|struct
name|LUQ
block|{
name|union
name|UQ
name|uq
decl_stmt|;
block|}
name|var
init|=
block|{
name|getUQ
argument_list|()
block|,
operator|.
name|uq
operator|.
name|q
operator|.
name|a
operator|=
literal|100
block|}
struct|;
name|struct
name|Q
name|s
index|[]
init|=
block|{
index|[
literal|0
index|]
operator|=
operator|(
expr|struct
name|Q
operator|)
block|{
literal|1
block|,
literal|2
block|}
block|,
index|[
literal|0
index|]
operator|.
name|c
operator|=
literal|3
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: void test()
end_comment

begin_comment
comment|// CHECK: [B1]
end_comment

begin_comment
comment|// CHECK:   1: getUQ
end_comment

begin_comment
comment|// CHECK:   2: [B1.1] (ImplicitCastExpr, FunctionToPointerDecay, union UQ (*)())
end_comment

begin_comment
comment|// CHECK:   3: [B1.2]()
end_comment

begin_comment
comment|// CHECK:   4: 100
end_comment

begin_comment
comment|// CHECK:   5: /*no init*/
end_comment

begin_comment
comment|// CHECK:   6: /*no init*/
end_comment

begin_comment
comment|// CHECK:   7: {[B1.4], [B1.5], [B1.6]}
end_comment

begin_comment
comment|// CHECK:   8: {[B1.7]}
end_comment

begin_comment
comment|// CHECK:   9: {/*base*/[B1.3], /*updater*/[B1.8]}
end_comment

begin_comment
comment|// CHECK:  10: {[B1.3], .uq.q.a = [B1.4]}
end_comment

begin_comment
comment|// CHECK:  11: struct LUQ var = {getUQ(), .uq.q.a = 100};
end_comment

begin_comment
comment|// CHECK:  12: 1
end_comment

begin_comment
comment|// CHECK:  13: 2
end_comment

begin_comment
comment|// CHECK:  14: /*implicit*/(int)0
end_comment

begin_comment
comment|// CHECK:  15: {[B1.12], [B1.13]}
end_comment

begin_comment
comment|// CHECK:  18: /*no init*/
end_comment

begin_comment
comment|// CHECK:  19: /*no init*/
end_comment

begin_comment
comment|// CHECK:  20: 3
end_comment

begin_comment
comment|// CHECK:  21: {[B1.18], [B1.19], [B1.20]}
end_comment

begin_comment
comment|// CHECK:  22: {/*base*/[B1.17], /*updater*/[B1.21]}
end_comment

begin_comment
comment|// CHECK:  24: struct Q s[] = {[0] = (struct Q){1, 2}, [0].c = 3};
end_comment

end_unit

