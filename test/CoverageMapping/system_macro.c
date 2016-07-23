begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name system_macro.c -o - %s | FileCheck %s
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

begin_define
define|#
directive|define
name|Func
parameter_list|(
name|x
parameter_list|)
value|if (x) {}
end_define

begin_define
define|#
directive|define
name|SomeType
value|int
end_define

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

begin_comment
comment|// CHECK-LABEL: doSomething:
end_comment

begin_function
name|void
name|doSomething
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: File 0, [[@LINE]]:25 -> {{[0-9:]+}} = #0
name|Func
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return;
name|SomeType
modifier|*
name|f
decl_stmt|;
comment|// CHECK: File 0, [[@LINE]]:11 -> {{[0-9:]+}} = 0
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

