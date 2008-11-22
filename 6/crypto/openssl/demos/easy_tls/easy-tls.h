begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- Mode: C; c-file-style: "bsd" -*- */
end_comment

begin_comment
comment|/*  * easy-tls.h -- generic TLS proxy.  * $Id: easy-tls.h,v 1.1 2001/09/17 19:06:59 bodo Exp $  */
end_comment

begin_comment
comment|/*  * (c) Copyright 1999 Bodo Moeller.  All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_TLS_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_TLS_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_SSL_H
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|ssl_ctx_st
name|SSL_CTX
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TLS_INFO_SIZE
value|512
end_define

begin_comment
comment|/* max. # of bytes written to infofd */
end_comment

begin_function_decl
name|void
name|tls_set_dhe1024
parameter_list|(
name|int
name|i
parameter_list|,
name|void
modifier|*
name|apparg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate DHE parameters:  * i>= 0 deterministic (i selects seed), i< 0 random (may take a while).  * tls_create_ctx calls this with random non-negative i if the application  * has never called it.*/
end_comment

begin_function_decl
name|void
name|tls_rand_seed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_rand_seed_from_file
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|size_t
name|n
parameter_list|,
name|void
modifier|*
name|apparg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tls_rand_seed_from_memory
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tls_create_ctx_args
block|{
name|int
name|client_p
decl_stmt|;
specifier|const
name|char
modifier|*
name|certificate_file
decl_stmt|;
specifier|const
name|char
modifier|*
name|key_file
decl_stmt|;
specifier|const
name|char
modifier|*
name|ca_file
decl_stmt|;
name|int
name|verify_depth
decl_stmt|;
name|int
name|fail_unless_verified
decl_stmt|;
name|int
name|export_p
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|tls_create_ctx_args
name|tls_create_ctx_defaultargs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* struct tls_create_ctx_args is similar to a conventional argument list,  * but it can provide default values and allows for future extension. */
end_comment

begin_function_decl
name|SSL_CTX
modifier|*
name|tls_create_ctx
parameter_list|(
name|struct
name|tls_create_ctx_args
parameter_list|,
name|void
modifier|*
name|apparg
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tls_start_proxy_args
block|{
name|int
name|fd
decl_stmt|;
name|int
name|client_p
decl_stmt|;
name|SSL_CTX
modifier|*
name|ctx
decl_stmt|;
name|pid_t
modifier|*
name|pid
decl_stmt|;
name|int
modifier|*
name|infofd
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|tls_start_proxy_args
name|tls_start_proxy_defaultargs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tls_start_proxy return value *MUST* be checked!  * 0 means ok, otherwise we've probably run out of some resources. */
end_comment

begin_function_decl
name|int
name|tls_start_proxy
parameter_list|(
name|struct
name|tls_start_proxy_args
parameter_list|,
name|void
modifier|*
name|apparg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

