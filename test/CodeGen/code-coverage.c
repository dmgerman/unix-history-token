begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -disable-red-zone -femit-coverage-data %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -disable-red-zone -femit-coverage-data -coverage-no-function-names-in-data %s -o - | FileCheck %s --check-prefix WITHOUTNAMES
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -disable-red-zone -femit-coverage-data -coverage-notes-file=aaa.gcno -coverage-data-file=bbb.gcda -dwarf-column-info -debug-info-kind=limited -dwarf-version=4 %s -o - | FileCheck %s --check-prefix GCOV_FILE_INFO
end_comment

begin_comment
comment|//<rdar://problem/12843084>
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
switch|switch
condition|(
name|a
operator|%
literal|2
condition|)
block|{
case|case
literal|0
case|:
operator|++
name|a
expr_stmt|;
case|case
literal|1
case|:
name|a
operator|/=
literal|2
expr_stmt|;
block|}
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// Check that the noredzone flag is set on the generated functions.
end_comment

begin_comment
comment|// CHECK: void @__llvm_gcov_indirect_counter_increment(i32* %{{.*}}, i64** %{{.*}}) unnamed_addr [[NRZ:#[0-9]+]]
end_comment

begin_comment
comment|// Inside llvm_gcov_writeout, check that -coverage-no-function-names-in-data
end_comment

begin_comment
comment|// passes null as the function name.
end_comment

begin_comment
comment|// CHECK: void @__llvm_gcov_writeout() unnamed_addr [[NRZ]]
end_comment

begin_comment
comment|// CHECK: call void @llvm_gcda_emit_function({{.*}}, i8* getelementptr {{.*}}, {{.*}})
end_comment

begin_comment
comment|// WITHOUTNAMES: void @__llvm_gcov_writeout() unnamed_addr
end_comment

begin_comment
comment|// WITHOUTNAMES: call void @llvm_gcda_emit_function({{.*}}, i8* null, {{.*}})
end_comment

begin_comment
comment|// CHECK: void @__llvm_gcov_flush() unnamed_addr [[NRZ]]
end_comment

begin_comment
comment|// CHECK: void @__llvm_gcov_init() unnamed_addr [[NRZ]]
end_comment

begin_comment
comment|// CHECK: attributes [[NRZ]] = { {{.*}}noredzone{{.*}} }
end_comment

begin_comment
comment|// GCOV_FILE_INFO: !llvm.gcov = !{![[GCOV:[0-9]+]]}
end_comment

begin_comment
comment|// GCOV_FILE_INFO: ![[GCOV]] = !{!"aaa.gcno", !"bbb.gcda", !{{[0-9]+}}}
end_comment

end_unit

