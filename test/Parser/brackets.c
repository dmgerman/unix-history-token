begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fixit %t -x c -DFIXIT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %t -x c -DFIXIT
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s -strict-whitespace
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|int
name|a
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
name|int
index|[]
name|b
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|4
block|,
literal|9
block|,
literal|16
block|}
decl_stmt|;
comment|// expected-error@-1{{brackets go after the identifier}}
comment|// CHECK: {{^}}  int []b = {0,1,4,9,16};
comment|// CHECK: {{^}}      ~~ ^
comment|// CHECK: {{^}}         []
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-5]]:7-[[@LINE-5]]:9}:""
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-6]]:10-[[@LINE-6]]:10}:"[]"
name|int
name|c
init|=
name|a
index|[
literal|0
index|]
decl_stmt|;
name|int
name|d
init|=
name|b
index|[
literal|0
index|]
decl_stmt|;
comment|// No undeclared identifer error here.
name|int
modifier|*
name|e
init|=
name|a
decl_stmt|;
name|int
modifier|*
name|f
init|=
name|b
decl_stmt|;
comment|// No undeclared identifer error here.
block|}
end_function

begin_struct
struct|struct
name|S
block|{
name|int
index|[
literal|1
index|]
index|[
literal|1
index|]
name|x
decl_stmt|;
comment|// expected-error@-1{{brackets go after the identifier}}
comment|// CHECK: {{^}}  int [1][1]x;
comment|// CHECK: {{^}}      ~~~~~~ ^
comment|// CHECK: {{^}}             [1][1]
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-5]]:7-[[@LINE-5]]:13}:""
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-6]]:14-[[@LINE-6]]:14}:"[1][1]"
block|}
name|s
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|FIXIT
end_ifndef

begin_function
name|void
name|test2
parameter_list|()
block|{
name|int
index|[]
index|[]
index|[]
expr_stmt|;
comment|// expected-error@-1{{expected identifier or '('}}
comment|// CHECK: {{^}}  int [][][];
comment|// CHECK: {{^}}      ^
comment|// CHECK-NOT: fix-it
struct|struct
name|T
block|{
name|int
index|[]
expr_stmt|;
comment|// expected-error@-1{{expected member name or ';' after declaration specifiers}}
comment|// CHECK: {{^}}    int [];
comment|// CHECK: {{^}}    ~~~ ^
comment|// CHECK-NOT: fix-it
block|}
struct|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
name|int
index|[
literal|5
index|]
modifier|*
decl_stmt|;
comment|// expected-error@-1{{expected identifier or '('}}
comment|// CHECK: {{^}}  int [5] *;
comment|// CHECK: {{^}}           ^
comment|// CHECK-NOT: fix-it
comment|// expected-error@-5{{brackets go after the identifier}}
comment|// CHECK: {{^}}  int [5] *;
comment|// CHECK: {{^}}      ~~~~ ^
comment|// CHECK: {{^}}          ()[5]
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-9]]:7-[[@LINE-9]]:11}:""
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-10]]:11-[[@LINE-10]]:11}:"("
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-11]]:12-[[@LINE-11]]:12}:")[5]"
name|int
index|[
literal|5
index|]
modifier|*
name|a
decl_stmt|;
comment|// expected-error@-1{{brackets go after the identifier}}
comment|// CHECK: {{^}}  int [5] * a;
comment|// CHECK: {{^}}      ~~~~   ^
comment|// CHECK: {{^}}          (  )[5]
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-5]]:7-[[@LINE-5]]:11}:""
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-6]]:11-[[@LINE-6]]:11}:"("
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-7]]:14-[[@LINE-7]]:14}:")[5]"
name|int
modifier|*
name|b
index|[
literal|5
index|]
init|=
name|a
decl_stmt|;
comment|// expected-error{{}} a should not be corrected to type b
name|int
argument_list|(
operator|*
name|c
argument_list|)
index|[
literal|5
index|]
operator|=
name|a
expr_stmt|;
comment|// a should be the same type as c
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: 8 errors generated.
end_comment

end_unit

