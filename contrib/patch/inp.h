begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inputting files to be patched */
end_comment

begin_comment
comment|/* $Id: inp.h,v 1.4 1997/04/07 01:07:00 eggert Exp $ */
end_comment

begin_decl_stmt
name|XTERN
name|LINENUM
name|input_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how long is input file in lines */
end_comment

begin_decl_stmt
name|char
specifier|const
modifier|*
name|ifetch
name|PARAMS
argument_list|(
operator|(
name|LINENUM
operator|,
name|int
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_input_file
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|re_input
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scan_input
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

