begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NOCW */
end_comment

begin_comment
comment|/*         Please read the README file for condition of use, before         using this software.          Maurice Gittens<mgittens@gits.nl>   January 1997  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOADKEYS_H_SEEN
end_ifndef

begin_define
define|#
directive|define
name|LOADKEYS_H_SEEN
end_define

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_function_decl
name|EVP_PKEY
modifier|*
name|ReadPublicKey
parameter_list|(
specifier|const
name|char
modifier|*
name|certfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EVP_PKEY
modifier|*
name|ReadPrivateKey
parameter_list|(
specifier|const
name|char
modifier|*
name|keyfile
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

