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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|_krb5_crc_init_table
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|_krb5_crc_update
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|p
operator|,
name|size_t
name|len
operator|,
name|u_int32_t
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_krb5_extract_ticket
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|krb5_kdc_rep
operator|*
name|rep
operator|,
name|krb5_creds
operator|*
name|creds
operator|,
name|krb5_keyblock
operator|*
name|key
operator|,
name|krb5_const_pointer
name|keyseed
operator|,
name|krb5_key_usage
name|key_usage
operator|,
name|krb5_addresses
operator|*
name|addrs
operator|,
name|unsigned
name|nonce
operator|,
name|krb5_boolean
name|allow_server_mismatch
operator|,
name|krb5_boolean
name|ignore_cname
operator|,
name|krb5_decrypt_proc
name|decrypt_proc
operator|,
name|krb5_const_pointer
name|decryptarg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|_krb5_get_int
name|__P
argument_list|(
operator|(
name|void
operator|*
name|buffer
operator|,
name|unsigned
name|long
operator|*
name|value
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_krb5_n_fold
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|str
operator|,
name|size_t
name|len
operator|,
name|void
operator|*
name|key
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|_krb5_put_int
name|__P
argument_list|(
operator|(
name|void
operator|*
name|buffer
operator|,
name|unsigned
name|long
name|value
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __krb5_private_h__ */
end_comment

end_unit

