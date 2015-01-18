begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name builtinmacro.c %s | FileCheck %s
end_comment

begin_comment
comment|// Test the coverage mapping generation for built-in macroes.
end_comment

begin_comment
comment|// CHECK: filename
end_comment

begin_function
specifier|const
name|char
modifier|*
name|filename
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:41 -> [[@LINE+3]]:2 = #0 (HasCodeBefore = 0)
specifier|static
specifier|const
name|char
name|this_file
index|[]
init|=
name|__FILE__
decl_stmt|;
return|return
name|this_file
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-NEXT: main
name|filename
argument_list|(
name|__FILE__
literal|"test.c"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

