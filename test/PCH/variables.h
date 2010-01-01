begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o variables.h.pch variables.h
end_comment

begin_comment
comment|// Do not mess with the whitespace in this file. It's important.
end_comment

begin_decl_stmt
specifier|extern
name|float
name|y
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|ip
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|z
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|z2
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAKE_HAPPY
parameter_list|(
name|X
parameter_list|)
value|X##Happy
end_define

begin_function_decl
name|int
name|MAKE_HAPPY
parameter_list|(
name|Very
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_MACRO_IN_THE_PCH
value|492
end_define

begin_define
define|#
directive|define
name|FUNCLIKE_MACRO
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|X ## Y
end_define

begin_define
define|#
directive|define
name|PASTE2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x##y
end_define

begin_define
define|#
directive|define
name|PASTE1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|PASTE2(x,y)
end_define

begin_define
define|#
directive|define
name|UNIQUE
parameter_list|(
name|x
parameter_list|)
value|PASTE1(x,__COUNTER__)
end_define

begin_function_decl
name|int
name|UNIQUE
parameter_list|(
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a0
end_comment

begin_function_decl
name|int
name|UNIQUE
parameter_list|(
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a1
end_comment

end_unit

