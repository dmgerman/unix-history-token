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

begin_decl_stmt
name|char
modifier|*
name|c_type_decl
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|declare_new_addr
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|new_arg_length
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|new_func_length
name|Argdcl
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nv_type_help
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|temp_name
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|user_label
name|Argdcl
argument_list|(
operator|(
name|long
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

