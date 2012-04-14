begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -detailed-preprocessing-record %s
end_comment

begin_comment
comment|// http://llvm.org/PR11120
end_comment

begin_define
define|#
directive|define
name|STRINGIZE
parameter_list|(
name|text
parameter_list|)
value|STRINGIZE_I(text)
end_define

begin_define
define|#
directive|define
name|STRINGIZE_I
parameter_list|(
name|text
parameter_list|)
value|#text
end_define

begin_define
define|#
directive|define
name|INC
value|pp-record.h
end_define

begin_include
include|#
directive|include
include|STRINGIZE(INC)
end_include

begin_expr_stmt
name|CAKE
expr_stmt|;
end_expr_stmt

end_unit

