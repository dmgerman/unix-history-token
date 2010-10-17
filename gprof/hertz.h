begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|hertz_h
end_ifndef

begin_define
define|#
directive|define
name|hertz_h
end_define

begin_define
define|#
directive|define
name|HZ_WRONG
value|0
end_define

begin_comment
comment|/* impossible clock frequency */
end_comment

begin_comment
comment|/*  * Discover the tick frequency of the machine if something goes wrong,  * we return HZ_WRONG, an impossible sampling frequency.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hertz
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hertz_h */
end_comment

end_unit

