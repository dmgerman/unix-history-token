begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bootptest.h */
end_comment

begin_comment
comment|/*  * Hacks for sharing print-bootp.c between tcpdump and bootptest.  */
end_comment

begin_define
define|#
directive|define
name|ESRC
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_define
define|#
directive|define
name|EDST
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USE_BFUNCS
end_ifndef

begin_comment
comment|/* Use mem/str functions */
end_comment

begin_comment
comment|/* There are no overlapped copies, so memcpy is OK. */
end_comment

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy(b,a,c)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|memset(p,0,l)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbose flag */
end_comment

begin_comment
comment|/* global pointers to beginning and end of current packet (during printing) */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|packetp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|snapend
decl_stmt|;
end_decl_stmt

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
name|char
modifier|*
name|ipaddr_string
name|P
argument_list|(
operator|(
expr|struct
name|in_addr
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

