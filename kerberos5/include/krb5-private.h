begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is a generated file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__krb5_private_h__
end_ifndef

begin_define
define|#
directive|define
name|__krb5_private_h__
end_define

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
name|void
name|_krb5_crc_init_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|_krb5_crc_update
parameter_list|(
specifier|const
name|char
modifier|*
comment|/*p*/
parameter_list|,
name|size_t
comment|/*len*/
parameter_list|,
name|u_int32_t
comment|/*res*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_krb5_extract_ticket
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|krb5_kdc_rep
modifier|*
comment|/*rep*/
parameter_list|,
name|krb5_creds
modifier|*
comment|/*creds*/
parameter_list|,
name|krb5_keyblock
modifier|*
comment|/*key*/
parameter_list|,
name|krb5_const_pointer
comment|/*keyseed*/
parameter_list|,
name|krb5_key_usage
comment|/*key_usage*/
parameter_list|,
name|krb5_addresses
modifier|*
comment|/*addrs*/
parameter_list|,
name|unsigned
comment|/*nonce*/
parameter_list|,
name|krb5_boolean
comment|/*allow_server_mismatch*/
parameter_list|,
name|krb5_boolean
comment|/*ignore_cname*/
parameter_list|,
name|krb5_decrypt_proc
comment|/*decrypt_proc*/
parameter_list|,
name|krb5_const_pointer
comment|/*decryptarg*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_ssize_t
name|_krb5_get_int
parameter_list|(
name|void
modifier|*
comment|/*buffer*/
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/*value*/
parameter_list|,
name|size_t
comment|/*size*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_krb5_n_fold
parameter_list|(
specifier|const
name|void
modifier|*
comment|/*str*/
parameter_list|,
name|size_t
comment|/*len*/
parameter_list|,
name|void
modifier|*
comment|/*key*/
parameter_list|,
name|size_t
comment|/*size*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_ssize_t
name|_krb5_put_int
parameter_list|(
name|void
modifier|*
comment|/*buffer*/
parameter_list|,
name|unsigned
name|long
comment|/*value*/
parameter_list|,
name|size_t
comment|/*size*/
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __krb5_private_h__ */
end_comment

end_unit

