begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|CRYPTO_H
end_define

begin_function_decl
name|void
name|md4_vector
parameter_list|(
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
name|md4
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|size_t
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
name|des_encrypt
parameter_list|(
specifier|const
name|u8
modifier|*
name|clear
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|u8
modifier|*
name|cypher
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRYPTO_H */
end_comment

end_unit

