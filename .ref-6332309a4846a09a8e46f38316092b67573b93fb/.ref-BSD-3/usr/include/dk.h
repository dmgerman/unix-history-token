begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * switch commands  */
end_comment

begin_define
define|#
directive|define
name|RAM_ON
value|0226
end_define

begin_define
define|#
directive|define
name|ROM_ON
value|0322
end_define

begin_define
define|#
directive|define
name|R_CNTL
value|0264
end_define

begin_define
define|#
directive|define
name|W_CNTL
value|0170
end_define

begin_comment
comment|/*  * dk command channel mode  */
end_comment

begin_define
define|#
directive|define
name|DKCMD
value|04000
end_define

begin_comment
comment|/*  * library routine declarations  */
end_comment

begin_function_decl
specifier|extern
name|long
name|cmread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ocmread
parameter_list|()
function_decl|;
end_function_decl

end_unit

