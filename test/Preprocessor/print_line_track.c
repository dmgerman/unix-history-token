begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -E %s | grep 'a 3'  * RUN: %clang_cc1 -E %s | grep 'b 16'  * RUN: %clang_cc1 -E -P %s | grep 'a 3'  * RUN: %clang_cc1 -E -P %s | grep 'b 16'  * RUN: %clang_cc1 -E %s | not grep '# 0 '  * PR1848  * PR3437 */
end_comment

begin_define
define|#
directive|define
name|t
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_macro
name|t
argument_list|(
argument|a
literal|3
argument_list|)
end_macro

begin_macro
name|t
argument_list|(
argument|b __LINE__
argument_list|)
end_macro

end_unit

