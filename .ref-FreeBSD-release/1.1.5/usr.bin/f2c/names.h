begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|CONST_IDENT_MAX
value|30
end_define

begin_define
define|#
directive|define
name|IO_IDENT_MAX
value|30
end_define

begin_define
define|#
directive|define
name|ARGUMENT_MAX
value|30
end_define

begin_define
define|#
directive|define
name|USER_LABEL_MAX
value|30
end_define

begin_define
define|#
directive|define
name|EQUIV_INIT_NAME
value|"equiv"
end_define

begin_define
define|#
directive|define
name|write_nv_ident
parameter_list|(
name|fp
parameter_list|,
name|a
parameter_list|)
value|wr_nv_ident_help ((fp), (struct Addrblock *) (a))
end_define

begin_define
define|#
directive|define
name|nv_type
parameter_list|(
name|x
parameter_list|)
value|nv_type_help ((struct Addrblock *) x)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|c_keywords
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|new_io_ident
parameter_list|(
comment|/* char * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|new_func_length
parameter_list|(
comment|/* char * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|new_arg_length
parameter_list|(
comment|/* Namep */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|declare_new_addr
parameter_list|(
comment|/* struct Addrblock * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nv_ident_help
parameter_list|(
comment|/* struct Addrblock * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nv_type_help
parameter_list|(
comment|/* struct Addrblock */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|user_label
parameter_list|(
comment|/* int */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|temp_name
parameter_list|(
comment|/* int, char */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|c_type_decl
parameter_list|(
comment|/* int, int */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|equiv_name
parameter_list|(
comment|/* int, char * */
parameter_list|)
function_decl|;
end_function_decl

end_unit

