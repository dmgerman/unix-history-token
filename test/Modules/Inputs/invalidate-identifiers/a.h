begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Ensure that loading 'i' introduces enough identifiers to cause the
end_comment

begin_comment
comment|// identifier table to be reallocated.
end_comment

begin_define
define|#
directive|define
name|TYPEDEFS
parameter_list|(
name|x
parameter_list|)
value|typedef x##0 x; typedef x##1 x;
end_define

begin_define
define|#
directive|define
name|DEPTH_0
parameter_list|(
name|x
parameter_list|)
value|DEPTH_1(x##0) DEPTH_1(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_1
parameter_list|(
name|x
parameter_list|)
value|DEPTH_2(x##0) DEPTH_2(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_2
parameter_list|(
name|x
parameter_list|)
value|DEPTH_3(x##0) DEPTH_3(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_3
parameter_list|(
name|x
parameter_list|)
value|DEPTH_4(x##0) DEPTH_4(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_4
parameter_list|(
name|x
parameter_list|)
value|DEPTH_5(x##0) DEPTH_5(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_5
parameter_list|(
name|x
parameter_list|)
value|DEPTH_6(x##0) DEPTH_6(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_6
parameter_list|(
name|x
parameter_list|)
value|DEPTH_7(x##0) DEPTH_7(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_7
parameter_list|(
name|x
parameter_list|)
value|DEPTH_8(x##0) DEPTH_8(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_8
parameter_list|(
name|x
parameter_list|)
value|DEPTH_9(x##0) DEPTH_9(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_9
parameter_list|(
name|x
parameter_list|)
value|DEPTH_A(x##0) DEPTH_A(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_A
parameter_list|(
name|x
parameter_list|)
value|DEPTH_B(x##0) DEPTH_B(x##1) TYPEDEFS(x)
end_define

begin_define
define|#
directive|define
name|DEPTH_B
parameter_list|(
name|x
parameter_list|)
value|typedef int x;
end_define

begin_macro
name|DEPTH_0
argument_list|(
argument|i
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|i
name|v
decl_stmt|;
end_decl_stmt

end_unit

