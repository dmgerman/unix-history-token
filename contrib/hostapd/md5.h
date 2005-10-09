begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|MD5_H
end_ifndef

begin_define
define|#
directive|define
name|MD5_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EAP_TLS_FUNCS
end_ifdef

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_define
define|#
directive|define
name|MD5Init
value|MD5_Init
end_define

begin_define
define|#
directive|define
name|MD5Update
value|MD5_Update
end_define

begin_define
define|#
directive|define
name|MD5Final
value|MD5_Final
end_define

begin_define
define|#
directive|define
name|MD5Transform
value|MD5_Transform
end_define

begin_define
define|#
directive|define
name|MD5_MAC_LEN
value|MD5_DIGEST_LENGTH
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* EAP_TLS_FUNCS */
end_comment

begin_define
define|#
directive|define
name|MD5_MAC_LEN
value|16
end_define

begin_struct
struct|struct
name|MD5Context
block|{
name|u32
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|u32
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|in
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|MD5Init
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Update
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|char
specifier|const
modifier|*
name|buf
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Final
parameter_list|(
name|unsigned
name|char
name|digest
index|[
literal|16
index|]
parameter_list|,
name|struct
name|MD5Context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Transform
parameter_list|(
name|u32
name|buf
index|[
literal|4
index|]
parameter_list|,
name|u32
specifier|const
name|in
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|MD5Context
name|MD5_CTX
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_TLS_FUNCS */
end_comment

begin_function_decl
name|void
name|md5_mac
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hmac_md5_vector
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hmac_md5
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MD5_H */
end_comment

end_unit

