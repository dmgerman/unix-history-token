begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This pounds on macro expansion for performance reasons.  This is currently
end_comment

begin_comment
comment|// heavily constrained by darwin's malloc.
end_comment

begin_comment
comment|// Function-like macros.
end_comment

begin_define
define|#
directive|define
name|A0
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A B
end_define

begin_define
define|#
directive|define
name|A1
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A0(A,B) A0(A,B) A0(A,B) A0(A,B) A0(A,B) A0(A,B)
end_define

begin_define
define|#
directive|define
name|A2
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A1(A,B) A1(A,B) A1(A,B) A1(A,B) A1(A,B) A1(A,B)
end_define

begin_define
define|#
directive|define
name|A3
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A2(A,B) A2(A,B) A2(A,B) A2(A,B) A2(A,B) A2(A,B)
end_define

begin_define
define|#
directive|define
name|A4
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A3(A,B) A3(A,B) A3(A,B) A3(A,B) A3(A,B) A3(A,B)
end_define

begin_define
define|#
directive|define
name|A5
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A4(A,B) A4(A,B) A4(A,B) A4(A,B) A4(A,B) A4(A,B)
end_define

begin_define
define|#
directive|define
name|A6
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A5(A,B) A5(A,B) A5(A,B) A5(A,B) A5(A,B) A5(A,B)
end_define

begin_define
define|#
directive|define
name|A7
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A6(A,B) A6(A,B) A6(A,B) A6(A,B) A6(A,B) A6(A,B)
end_define

begin_define
define|#
directive|define
name|A8
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A7(A,B) A7(A,B) A7(A,B) A7(A,B) A7(A,B) A7(A,B)
end_define

begin_macro
name|A8
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

end_unit

