begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: poly1305.h,v 1.2 2013/12/19 22:57:13 djm Exp $ */
end_comment

begin_comment
comment|/*   * Public Domain poly1305 from Andrew Moon  * poly1305-donna-unrolled.c from https://github.com/floodyberry/poly1305-donna  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POLY1305_H
end_ifndef

begin_define
define|#
directive|define
name|POLY1305_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|POLY1305_KEYLEN
value|32
end_define

begin_define
define|#
directive|define
name|POLY1305_TAGLEN
value|16
end_define

begin_function_decl
name|void
name|poly1305_auth
parameter_list|(
name|u_char
name|out
index|[
name|POLY1305_TAGLEN
index|]
parameter_list|,
specifier|const
name|u_char
modifier|*
name|m
parameter_list|,
name|size_t
name|inlen
parameter_list|,
specifier|const
name|u_char
name|key
index|[
name|POLY1305_KEYLEN
index|]
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|POLY1305_TAGLEN
end_function_decl

begin_macro
unit|)))
name|__attribute__
argument_list|(
argument|(__bounded__(__buffer__,
literal|2
argument|,
literal|3
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__minbytes__
argument_list|,
literal|4
argument_list|,
name|POLY1305_KEYLEN
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
comment|/* POLY1305_H */
end_comment

end_unit

