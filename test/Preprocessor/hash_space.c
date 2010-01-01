begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep " #"
end_comment

begin_comment
comment|// Should put a space before the # so that -fpreprocessed mode doesn't
end_comment

begin_comment
comment|// macro expand this again.
end_comment

begin_define
define|#
directive|define
name|HASH
value|#
end_define

begin_expr_stmt
name|HASH
name|define
name|foo
name|bar
end_expr_stmt

end_unit

