begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
specifier|_Complex
name|cd
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: code-complete-errors.c:1:1: warning: plain '_Complex' requires a type specifier; assuming '_Complex double'
end_comment

begin_comment
comment|// CHECK: FIX-IT: Insert " double" at 1:9
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
empty_stmt|;
comment|// CHECK: code-complete-errors.c:4:12: warning: extra ';' inside a struct or union
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: FIX-IT: Remove [4:12 - 4:13]
end_comment

begin_decl_stmt
name|struct
name|s
name|s0
init|=
block|{
name|y
operator|:
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: code-complete-errors.c:7:20: warning: use of GNU old-style field designator extension
end_comment

begin_comment
comment|// CHECK: FIX-IT: Replace [7:17 - 7:19] with ".y = "
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
modifier|*
name|ptr1
parameter_list|,
name|float
modifier|*
name|ptr2
parameter_list|)
block|{
return|return
name|ptr1
operator|!=
name|ptr2
return|;
comment|// CHECK: code-complete-errors.c:10:15:{10:10-10:14}{10:18-10:22}: warning: comparison of distinct pointer types ('int *' and 'float *')
block|}
end_function

begin_function
name|void
name|g
parameter_list|()
block|{  }
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:13:12 -pedantic %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK %s< %t
end_comment

end_unit

