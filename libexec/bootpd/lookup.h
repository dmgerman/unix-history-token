begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lookup.h */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_comment
comment|/* for int32, u_int32 */
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
name|u_char
modifier|*
name|lookup_hwa
name|P
argument_list|(
operator|(
name|char
operator|*
name|hostname
operator|,
name|int
name|htype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lookup_ipa
name|P
argument_list|(
operator|(
name|char
operator|*
name|hostname
operator|,
name|u_int32
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lookup_netmask
name|P
argument_list|(
operator|(
name|u_int32
name|addr
operator|,
name|u_int32
operator|*
name|mask
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

