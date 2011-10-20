begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o /dev/null
end_comment

begin_comment
comment|// This is a testcase for PR461
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|min_align
range|:
literal|1
decl_stmt|;
name|unsigned
label|:
literal|1
expr_stmt|;
block|}
name|addr_diff_vec_flags
typedef|;
end_typedef

begin_decl_stmt
name|addr_diff_vec_flags
name|X
decl_stmt|;
end_decl_stmt

end_unit

