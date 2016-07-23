begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -emit-llvm -main-file-name unused_names.c -o - %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=SYSHEADER -input-file %t %s
end_comment

begin_comment
comment|// Since foo is never emitted, there should not be a profile name for it.
end_comment

begin_comment
comment|// CHECK-DAG: @__profn_bar = {{.*}} [3 x i8] c"bar"
end_comment

begin_comment
comment|// CHECK-DAG: @__profn_baz = {{.*}} [3 x i8] c"baz"
end_comment

begin_comment
comment|// CHECK-DAG: @__profn_unused_names.c_qux = {{.*}} [18 x i8] c"unused_names.c:qux"
end_comment

begin_comment
comment|// CHECK-DAG: @__llvm_prf_nm = private constant {{.*}}, section "{{.*}}__llvm_prf_names"
end_comment

begin_comment
comment|// SYSHEADER-NOT: @__profn_foo =
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IS_SYSHEADER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_function
specifier|inline
name|int
name|foo
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_SYSHEADER
end_define

begin_include
include|#
directive|include
include|__FILE__
end_include

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|int
name|baz
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|qux
parameter_list|()
block|{
return|return
literal|42
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

