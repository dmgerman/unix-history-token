begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985 Xerox Corp.  *  * common definitons  */
end_comment

begin_define
define|#
directive|define
name|MICAS_PER_INCH
value|2540
end_define

begin_define
define|#
directive|define
name|POINTS_PER_INCH
value|72
end_define

begin_comment
comment|/* these are fat points */
end_comment

begin_function_decl
name|unsigned
name|char
modifier|*
name|GetStringProp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|GetIntegerProp
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Make16BitChar
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a<< 8) | b)
end_define

end_unit

