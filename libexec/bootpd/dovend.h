begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dovend.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|dovend_rfc1497
name|P
argument_list|(
operator|(
expr|struct
name|host
operator|*
name|hp
operator|,
name|u_char
operator|*
name|buf
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insert_ip
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in_addr_list
operator|*
operator|,
name|u_char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insert_u_long
name|P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|P
end_undef

end_unit

