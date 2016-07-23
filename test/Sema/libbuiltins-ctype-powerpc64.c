begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm< %s | FileCheck %s
end_comment

begin_function_decl
name|int
name|isalnum
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isalpha
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isblank
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iscntrl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isdigit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isgraph
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|islower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isprint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ispunct
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isspace
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isxdigit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tolower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|toupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: call signext i32 @isalnum(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isalnum
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isalpha(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isalpha
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isblank(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isblank
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @iscntrl(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|iscntrl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isdigit(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isdigit
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isgraph(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isgraph
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @islower(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|islower
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isprint(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isprint
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @ispunct(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|ispunct
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isspace(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isspace
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isupper(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isupper
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @isxdigit(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|isxdigit
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @tolower(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|tolower
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call signext i32 @toupper(i32 signext {{%[0-9]+}}) [[NUW_RO_CALL:#[0-9]+]]
operator|(
name|void
operator|)
name|toupper
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare signext i32 @isalnum(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isalpha(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isblank(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @iscntrl(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isdigit(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isgraph(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @islower(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isprint(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @ispunct(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isspace(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isupper(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @isxdigit(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @tolower(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare signext i32 @toupper(i32 signext) [[NUW_RO:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: attributes [[NUW_RO]] = { nounwind readonly{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NUW_RO_CALL]] = { nounwind readonly }
end_comment

end_unit

