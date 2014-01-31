begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: chacha.h,v 1.1 2013/11/21 00:45:44 djm Exp $ */
end_comment

begin_comment
comment|/* chacha-merged.c version 20080118 D. J. Bernstein Public domain. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHACHA_H
end_ifndef

begin_define
define|#
directive|define
name|CHACHA_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|chacha_ctx
block|{
name|u_int
name|input
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHACHA_MINKEYLEN
value|16
end_define

begin_define
define|#
directive|define
name|CHACHA_NONCELEN
value|8
end_define

begin_define
define|#
directive|define
name|CHACHA_CTRLEN
value|8
end_define

begin_define
define|#
directive|define
name|CHACHA_STATELEN
value|(CHACHA_NONCELEN+CHACHA_CTRLEN)
end_define

begin_define
define|#
directive|define
name|CHACHA_BLOCKLEN
value|64
end_define

begin_function_decl
name|void
name|chacha_keysetup
parameter_list|(
name|struct
name|chacha_ctx
modifier|*
name|x
parameter_list|,
specifier|const
name|u_char
modifier|*
name|k
parameter_list|,
name|u_int
name|kbits
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|CHACHA_MINKEYLEN
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|chacha_ivsetup
parameter_list|(
name|struct
name|chacha_ctx
modifier|*
name|x
parameter_list|,
specifier|const
name|u_char
modifier|*
name|iv
parameter_list|,
specifier|const
name|u_char
modifier|*
name|ctr
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|CHACHA_NONCELEN
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__minbytes__
argument_list|,
literal|3
argument_list|,
name|CHACHA_CTRLEN
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|chacha_encrypt_bytes
parameter_list|(
name|struct
name|chacha_ctx
modifier|*
name|x
parameter_list|,
specifier|const
name|u_char
modifier|*
name|m
parameter_list|,
name|u_char
modifier|*
name|c
parameter_list|,
name|u_int
name|bytes
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__buffer__
parameter_list|,
function_decl|2
operator|,
function_decl|4
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__buffer__
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHACHA_H */
end_comment

end_unit

