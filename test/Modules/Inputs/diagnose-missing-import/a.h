begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|A_h
end_ifndef

begin_define
define|#
directive|define
name|A_h
end_define

begin_decl_stmt
unit|@
name|class
name|NSString
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|NSString
modifier|*
specifier|const
name|xyzRiskyCloseOpenParam
init|= @
literal|"riskyCloseParam"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
specifier|inline
name|void
name|XYZLogEvent
parameter_list|(
name|NSString
modifier|*
name|eventName
parameter_list|,
name|NSString
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

