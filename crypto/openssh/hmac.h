begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HMAC_H
end_ifndef

begin_define
define|#
directive|define
name|HMAC_H
end_define

begin_function_decl
name|unsigned
name|char
modifier|*
name|hmac
parameter_list|(
name|EVP_MD
modifier|*
name|evp_md
parameter_list|,
name|unsigned
name|int
name|seqno
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|datalen
parameter_list|,
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

