begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: artio.h,v 4.3 85/05/01 11:35:43 lwall Exp $  *  * $Log:	artio.h,v $  * Revision 4.3  85/05/01  11:35:43  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_decl_stmt
name|EXT
name|ART_POS
name|artpos
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* byte position in article file */
end_comment

begin_decl_stmt
name|EXT
name|ART_LINE
name|artline
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line number in article file */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|artfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* current article file pointer */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|openart
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what is the currently open article number? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LINKART
end_ifdef

begin_function_decl
name|EXT
name|char
modifier|*
name|linkartname
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* real name of article for Eunice */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|artio_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|artopen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* open an article unless already opened */
end_comment

end_unit

