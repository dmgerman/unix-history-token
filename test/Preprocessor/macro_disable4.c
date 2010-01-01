begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -P -E %s | grep 'int f(void)'
end_comment

begin_comment
comment|// PR1820
end_comment

begin_define
define|#
directive|define
name|f
parameter_list|(
name|x
parameter_list|)
value|h(x
end_define

begin_define
define|#
directive|define
name|h
parameter_list|(
name|x
parameter_list|)
value|x(void)
end_define

begin_function
specifier|extern
name|int
name|f
parameter_list|(
name|f
parameter_list|)
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

end_unit

