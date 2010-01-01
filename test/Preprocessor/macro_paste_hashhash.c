begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^"x ## y";$'
end_comment

begin_define
define|#
directive|define
name|hash_hash
value|# ## #
end_define

begin_define
define|#
directive|define
name|mkstr
parameter_list|(
name|a
parameter_list|)
value|# a
end_define

begin_define
define|#
directive|define
name|in_between
parameter_list|(
name|a
parameter_list|)
value|mkstr(a)
end_define

begin_define
define|#
directive|define
name|join
parameter_list|(
name|c
parameter_list|,
name|d
parameter_list|)
value|in_between(c hash_hash d)
end_define

begin_expr_stmt
name|join
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

