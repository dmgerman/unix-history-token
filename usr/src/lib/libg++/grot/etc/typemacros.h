begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|_T
parameter_list|(
name|type
parameter_list|)
value|typeof(type)
end_define

begin_define
define|#
directive|define
name|pointer_to
parameter_list|(
name|type
parameter_list|)
value|_T(_T(type)*)
end_define

begin_define
define|#
directive|define
name|member_of
parameter_list|(
name|cls
parameter_list|,
name|type
parameter_list|)
value|_T(_T(type) cls::)
end_define

begin_define
define|#
directive|define
name|function
parameter_list|(
name|res
parameter_list|,
name|args
parameter_list|)
value|_T(_T(res) args)
end_define

begin_define
define|#
directive|define
name|_xq_yq
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## _ ## y
end_define

begin_define
define|#
directive|define
name|_x_y
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|_xq_yq(x,y)
end_define

begin_define
define|#
directive|define
name|_gensym
parameter_list|(
name|stem
parameter_list|)
value|_x_y(stem, __LINE__)
end_define

end_unit

