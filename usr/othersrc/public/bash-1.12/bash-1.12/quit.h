begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* quit.h -- How to handle SIGINT gracefully. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QUIT__
end_ifndef

begin_define
define|#
directive|define
name|__QUIT__
end_define

begin_comment
comment|/* Non-zero means SIGINT has already ocurred. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interrupt_state
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|throw_to_top_level
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Macro to call a great deal.  SIGINT just sets above variable.  When    it is safe, put QUIT in the code, and the "interrupt" will take place. */
end_comment

begin_define
define|#
directive|define
name|QUIT
value|if (interrupt_state) throw_to_top_level ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __QUIT__ */
end_comment

end_unit

