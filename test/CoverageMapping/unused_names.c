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
comment|// CHECK-DAG: @__profc_bar
end_comment

begin_comment
comment|// CHECK-DAG: @__llvm_prf_nm = private constant {{.*}}, section "{{.*__llvm_prf_names|.*lprfn}}"
end_comment

begin_comment
comment|// These are never instantiated, so we shouldn't get counters for them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NOT: @__profc_baz
end_comment

begin_comment
comment|// CHECK-NOT: @__profc_unused_names.c_qux
end_comment

begin_comment
comment|// SYSHEADER-NOT: @__profc_foo =
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

