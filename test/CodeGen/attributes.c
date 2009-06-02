begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep 't1.*noreturn' %t&&
end_comment

begin_comment
comment|// RUN: grep 't2.*nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'weak.*t3' %t&&
end_comment

begin_comment
comment|// RUN: grep 'hidden.*t4' %t&&
end_comment

begin_comment
comment|// RUN: grep 't5.*weak' %t&&
end_comment

begin_comment
comment|// RUN: grep 't6.*protected' %t&&
end_comment

begin_comment
comment|// RUN: grep 't7.*noreturn' %t&&
end_comment

begin_comment
comment|// RUN: grep 't7.*nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 't9.*alias.*weak.*t8' %t&&
end_comment

begin_comment
comment|// RUN: grep '@t10().*section "SECT"' %t&&
end_comment

begin_comment
comment|// RUN: grep '@t11().*section "SECT"' %t&&
end_comment

begin_comment
comment|// RUN: grep '@t12 =.*section "SECT"' %t&&
end_comment

begin_comment
comment|// RUN: grep '@t13 =.*section "SECT"' %t&&
end_comment

begin_comment
comment|// RUN: grep '@t14.x =.*section "SECT"' %t
end_comment

begin_comment
comment|// RUN: grep 'declare extern_weak i32 @t15()' %t&&
end_comment

begin_comment
comment|// RUN: grep '@t16 = extern_weak global i32' %t
end_comment

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t1
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|t2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nothrow
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t2
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|t3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t3
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|t4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"hidden"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t4
parameter_list|()
block|{}
end_function

begin_decl_stmt
name|int
name|t5
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t6
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"protected"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|t7
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
operator|,
function_decl|nothrow
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t7
parameter_list|()
block|{}
end_function

begin_function
name|void
name|__t8
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|t9
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"__t8"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|t10
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|"SECT"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t10
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
name|t11
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_decl_stmt
name|int
name|t12
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s0
name|t13
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|t14
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
name|t15
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|t16
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|t17
parameter_list|()
block|{
return|return
name|t15
argument_list|()
operator|+
name|t16
return|;
block|}
end_function

end_unit

