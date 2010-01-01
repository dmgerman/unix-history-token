begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep "movl %eax"
end_comment

begin_comment
comment|// PR4132
end_comment

begin_define
define|#
directive|define
name|R1E
value|%eax
end_define

begin_define
define|#
directive|define
name|epilogue
parameter_list|(
name|r1
parameter_list|)
value|movl r1 ## E;
end_define

begin_macro
name|epilogue
argument_list|(
argument|R1
argument_list|)
end_macro

end_unit

