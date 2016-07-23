begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Assorted macros to help test #include behavior across file boundaries.
end_comment

begin_define
define|#
directive|define
name|helper1
value|0
end_define

begin_function_decl
name|void
name|helper2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|M1
parameter_list|(
name|a
parameter_list|,
modifier|...
parameter_list|)
value|helper2(a, ##__VA_ARGS__);
end_define

begin_comment
comment|// Note: M2 stresses vararg macro functions with macro arguments. The spelling
end_comment

begin_comment
comment|// locations of the args used to be set to the expansion site, leading to
end_comment

begin_comment
comment|// crashes (region LineEnd< LineStart). The regression test requires M2's line
end_comment

begin_comment
comment|// number to be greater than the line number containing the expansion.
end_comment

begin_define
define|#
directive|define
name|M2
parameter_list|(
name|a
parameter_list|,
modifier|...
parameter_list|)
value|M1(a, helper1, ##__VA_ARGS__);
end_define

end_unit

