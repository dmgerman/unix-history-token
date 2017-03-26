begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bootptest.h */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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

begin_function_decl
name|void
name|bootp_print
parameter_list|(
name|struct
name|bootp
modifier|*
name|bp
parameter_list|,
name|int
name|length
parameter_list|,
name|u_short
name|sport
parameter_list|,
name|u_short
name|dport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ipaddr_string
parameter_list|(
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printfn
parameter_list|(
name|u_char
modifier|*
name|s
parameter_list|,
name|u_char
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

end_unit

