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
name|__alpha
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uint32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|MD5Context
block|{
name|uint32
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|uint32
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
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
parameter_list|,
name|unsigned
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Transform
parameter_list|(
name|uint32
name|buf
index|[
literal|4
index|]
parameter_list|,
name|uint32
specifier|const
name|in
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i64c
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|crypt_md5
parameter_list|(
specifier|const
name|char
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|salt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * This is needed to make RSAREF happy on some MS-DOS compilers. */
end_comment

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
comment|/* MD5_H */
end_comment

end_unit

