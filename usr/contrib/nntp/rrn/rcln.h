begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: rcln.h,v 4.3 85/05/01 11:45:52 lwall Exp $  *  * $Log:	rcln.h,v $  * Revision 4.3  85/05/01  11:45:52  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|ngmax
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|rcln_init
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CATCHUP
end_ifdef

begin_function_decl
name|void
name|catch_up
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|addartnum
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MCHASE
end_ifdef

begin_function_decl
name|void
name|subartnum
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|prange
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_toread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkexpired
parameter_list|()
function_decl|;
end_function_decl

end_unit

