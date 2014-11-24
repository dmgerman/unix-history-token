begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|FOO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|BAR
parameter_list|(
name|x
parameter_list|)
value|x x
end_define

begin_define
define|#
directive|define
name|BAZ
parameter_list|(
name|x
parameter_list|)
value|[x] [ x] [x ]
end_define

begin_expr_stmt
index|[
name|FOO
argument_list|()
index|]
index|[
name|FOO
argument_list|()
index|]
index|[
name|FOO
argument_list|()
index|]
index|[
name|BAR
argument_list|()
index|]
index|[
name|BAR
argument_list|()
index|]
index|[
name|BAR
argument_list|()
index|]
name|BAZ
argument_list|()
end_expr_stmt

begin_comment
comment|// CHECK: [] [ ] [ ] [ ] [ ] [ ] [] [ ] [ ]
end_comment

end_unit

