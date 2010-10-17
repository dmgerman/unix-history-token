begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Testcase to make sure that if we externally reference a versioned symbol  * that we always get the right one.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|int
name|foo_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|foo_2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|foo_3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|foo_4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Expect 4,    get %d\n"
argument_list|,
name|foo_1
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Expect 13,   get %d\n"
argument_list|,
name|foo_2
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Expect 103,  get %d\n"
argument_list|,
name|foo_3
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Expect 1003, get %d\n"
argument_list|,
name|foo_4
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_asm
asm|__asm__(".symver foo_1,show_foo@");
end_asm

begin_asm
asm|__asm__(".symver foo_2,show_foo@VERS_1.1");
end_asm

begin_asm
asm|__asm__(".symver foo_3,show_foo@VERS_1.2");
end_asm

begin_asm
asm|__asm__(".symver foo_4,show_foo@VERS_2.0");
end_asm

end_unit

