begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getif.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|ifreq
modifier|*
name|getif
parameter_list|(
name|int
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|struct
name|ifreq
modifier|*
name|getif
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

