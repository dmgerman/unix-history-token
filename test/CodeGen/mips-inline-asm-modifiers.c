begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -S -o - -emit-llvm %s \
end_comment

begin_comment
comment|// RUN: | FileCheck %s
end_comment

begin_comment
comment|// This checks that the frontend will accept inline asm operand modifiers
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|v4i32
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_comment
comment|// CHECK: %{{[0-9]+}} = call i32 asm ".set noreorder;\0Alw    $0,$1;\0A.set reorder;\0A", "=r,*m,~{$1}"(i32* getelementptr inbounds ([8 x i32]* @b, i32 {{[0-9]+}}, i32 {{[0-9]+}})) #2,
end_comment

begin_comment
comment|// CHECK: %{{[0-9]+}} = call i32 asm "lw    $0,${1:D};\0A", "=r,*m,~{$1}"(i32* getelementptr inbounds ([8 x i32]* @b, i32 {{[0-9]+}}, i32 {{[0-9]+}})) #2,
end_comment

begin_comment
comment|// CHECK: %{{[0-9]+}} = call<4 x i32> asm "ldi.w ${0:w},1", "=f,~{$1}"
end_comment

begin_decl_stmt
name|int
name|b
index|[
literal|8
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|v4i32
name|v4i32_r
decl_stmt|;
comment|// The first word. Notice, no 'D'
block|{
asm|asm (   ".set noreorder;\n"   "lw    %0,%1;\n"   ".set reorder;\n"   : "=r" (i)   : "m" (*(b+4)));
block|}
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// The second word
block|{
asm|asm (   "lw    %0,%D1;\n"   : "=r" (i)   : "m" (*(b+4))   );
block|}
comment|// MSA registers
block|{
asm|asm ("ldi.w %w0,1" : "=f" (v4i32_r));
block|}
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

