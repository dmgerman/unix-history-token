begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ngdata.h,v 4.3 85/05/01 11:44:48 lwall Exp $  *  * $Log:	ngdata.h,v $  * Revision 4.3  85/05/01  11:44:48  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|actfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the active file */
end_comment

begin_function_decl
name|EXT
name|bool
name|writesoft
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rewrite the soft pointer file? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|softtries
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|softmisses
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CACHEFIRST
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|abs1st
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1st real article in newsgroup */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MININACT
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|abs1st
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ngdata_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ART_NUM
name|getngsize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ACT_POS
name|findact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ART_NUM
name|getabsfirst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ART_NUM
name|getngmin
parameter_list|()
function_decl|;
end_function_decl

end_unit

