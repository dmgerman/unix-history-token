begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Some general definitions.  */
end_comment

begin_define
define|#
directive|define
name|numberof
parameter_list|(
name|x
parameter_list|)
value|(sizeof x/sizeof x[0])
end_define

begin_define
define|#
directive|define
name|highestof
parameter_list|(
name|x
parameter_list|)
value|(numberof(x)-1)
end_define

begin_define
define|#
directive|define
name|ClearStructure
parameter_list|(
name|x
parameter_list|)
value|bzero((char *)&x, sizeof x)
end_define

begin_define
define|#
directive|define
name|ClearArray
parameter_list|(
name|x
parameter_list|)
value|bzero((char *)x, sizeof x)
end_define

end_unit

