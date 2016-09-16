begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Basic macros that newlib uses */
end_comment

begin_define
define|#
directive|define
name|_PTR
value|void *
end_define

begin_define
define|#
directive|define
name|_DEFUN
parameter_list|(
name|_name
parameter_list|,
name|_args
parameter_list|,
name|_def
parameter_list|)
value|_name (_def)
end_define

begin_define
define|#
directive|define
name|_CONST
value|const
end_define

begin_define
define|#
directive|define
name|_AND
value|,
end_define

end_unit

