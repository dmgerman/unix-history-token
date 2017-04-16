begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test core -print-source-symbols -- %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch %s -o %t.pch
end_comment

begin_comment
comment|// RUN: c-index-test core -print-source-symbols -module-file %t.pch | FileCheck %s
end_comment

begin_comment
comment|// CHECK: [[@LINE+1]]:6 | function/C | test1 | [[TEST1_USR:.*]] | [[TEST1_CG:.*]] | Decl | rel: 0
end_comment

begin_function_decl
name|void
name|test1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: [[@LINE+1]]:20 | function/C | test2 | [[TEST2_USR:.*]] | {{.*}} | Def | rel: 0
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|test2
parameter_list|()
block|{
comment|// CHECK: [[@LINE+2]]:3 | function/C | test1 | [[TEST1_USR]] | [[TEST1_CG]] | Ref,Call,RelCall,RelCont | rel: 1
comment|// CHECK-NEXT: RelCall,RelCont | test2 | [[TEST2_USR]]
name|test1
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

