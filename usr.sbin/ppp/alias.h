begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*     Alias.h defines the outside world interfaces for the packet     aliasing software.      This software is placed into the public domain with no restrictions     on its distribution.      Initial version:  August, 1996  (cjm) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_H_
end_define

begin_decl_stmt
specifier|extern
name|void
name|PacketAliasIn
name|__P
argument_list|(
operator|(
expr|struct
name|ip
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|PacketAliasOut
name|__P
argument_list|(
operator|(
expr|struct
name|ip
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|SetAliasAddress
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|InitAlias
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|InitAliasLog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

