begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|DEF_C_LINE_LENGTH
value|77
end_define

begin_comment
comment|/* actual max will be 79 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|c_output_line_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # chars per line in C source 					   code */
end_comment

begin_decl_stmt
name|chainp
name|data_value
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|long
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_init_data
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|list_init_data
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|*
operator|,
name|char
operator|*
operator|,
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wr_ardecls
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
expr|struct
name|Dimblock
operator|*
operator|,
name|long
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_one_init
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|char
operator|*
operator|,
name|chainp
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_output_values
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|Namep
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

