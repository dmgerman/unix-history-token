begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|R_PAREN
value|)
end_define

begin_define
define|#
directive|define
name|FUNC
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_decl_stmt
specifier|static
name|int
name|glob
init|=
operator|(
literal|1
operator|+
name|FUNC
argument_list|(
literal|1
name|R_PAREN
argument_list|)
expr|;
end_decl_stmt

begin_comment
comment|// CHECK: static int glob = (1 + 1 );
end_comment

end_unit

