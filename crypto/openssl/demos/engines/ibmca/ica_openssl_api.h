begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__ICA_OPENSSL_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__ICA_OPENSSL_API_H__
end_define

begin_comment
comment|/**  ** abstract data types for API  **/
end_comment

begin_define
define|#
directive|define
name|ICA_ADAPTER_HANDLE
value|int
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|ICA_CALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|ICA_CALL
value|__stdcall
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------------------------------------------*  | RSA defines and typedefs                       |  *------------------------------------------------*/
end_comment

begin_comment
comment|/*  * All data elements of the RSA key are in big-endian format  * Modulus-Exponent form of key  *  */
end_comment

begin_define
define|#
directive|define
name|MAX_EXP_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|MAX_MODULUS_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|MAX_MODEXP_SIZE
value|(MAX_EXP_SIZE + MAX_MODULUS_SIZE)
end_define

begin_define
define|#
directive|define
name|MAX_OPERAND_SIZE
value|MAX_EXP_SIZE
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ICA_KEY_RSA_MODEXPO_REC
index|[
name|MAX_MODEXP_SIZE
index|]
typedef|;
end_typedef

begin_comment
comment|/*  * All data elements of the RSA key are in big-endian format  * Chinese Remainder Thereom(CRT) form of key  * Used only for Decrypt, the encrypt form is typically Modulus-Exponent  *  */
end_comment

begin_define
define|#
directive|define
name|MAX_BP_SIZE
value|136
end_define

begin_define
define|#
directive|define
name|MAX_BQ_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|MAX_NP_SIZE
value|136
end_define

begin_define
define|#
directive|define
name|MAX_NQ_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|MAX_QINV_SIZE
value|136
end_define

begin_define
define|#
directive|define
name|MAX_RSACRT_SIZE
value|(MAX_BP_SIZE+MAX_BQ_SIZE+MAX_NP_SIZE+MAX_NQ_SIZE+MAX_QINV_SIZE)
end_define

begin_define
define|#
directive|define
name|RSA_GEN_OPERAND_MAX
value|256
end_define

begin_comment
comment|/* bytes */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ICA_KEY_RSA_CRT_REC
index|[
name|MAX_RSACRT_SIZE
index|]
typedef|;
end_typedef

begin_comment
comment|/*------------------------------------------------*  | RSA key token types                            |  *------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|RSA_PUBLIC_MODULUS_EXPONENT
value|3
end_define

begin_define
define|#
directive|define
name|RSA_PKCS_PRIVATE_CHINESE_REMAINDER
value|6
end_define

begin_define
define|#
directive|define
name|KEYTYPE_MODEXPO
value|1
end_define

begin_define
define|#
directive|define
name|KEYTYPE_PKCSCRT
value|2
end_define

begin_comment
comment|/*------------------------------------------------*  | RSA Key Token format                           |  *------------------------------------------------*/
end_comment

begin_comment
comment|/*  * NOTE:  All the fields in the ICA_KEY_RSA_MODEXPO structure  *        (lengths, offsets, exponents, modulus, etc.) are  *        stored in big-endian format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ICA_KEY_RSA_MODEXPO
block|{
name|unsigned
name|int
name|keyType
decl_stmt|;
comment|/* RSA key type.               */
name|unsigned
name|int
name|keyLength
decl_stmt|;
comment|/* Total length of the token.  */
name|unsigned
name|int
name|modulusBitLength
decl_stmt|;
comment|/* Modulus n bit length.       */
comment|/* -- Start of the data length.*/
name|unsigned
name|int
name|nLength
decl_stmt|;
comment|/* Modulus n = p * q           */
name|unsigned
name|int
name|expLength
decl_stmt|;
comment|/* exponent (public or private)*/
comment|/*   e = 1/d * mod(p-1)(q-1)   */
comment|/* -- Start of the data offsets*/
name|unsigned
name|int
name|nOffset
decl_stmt|;
comment|/* Modulus n .                 */
name|unsigned
name|int
name|expOffset
decl_stmt|;
comment|/* exponent (public or private)*/
name|unsigned
name|char
name|reserved
index|[
literal|112
index|]
decl_stmt|;
comment|/* reserved area               */
comment|/* -- Start of the variable -- */
comment|/* -- length token data.    -- */
name|ICA_KEY_RSA_MODEXPO_REC
name|keyRecord
decl_stmt|;
block|}
name|ICA_KEY_RSA_MODEXPO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SZ_HEADER_MODEXPO
value|(sizeof(ICA_KEY_RSA_MODEXPO) - sizeof(ICA_KEY_RSA_MODEXPO_REC))
end_define

begin_comment
comment|/*  * NOTE:  All the fields in the ICA_KEY_RSA_CRT structure  *        (lengths, offsets, exponents, modulus, etc.) are  *        stored in big-endian format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ICA_KEY_RSA_CRT
block|{
name|unsigned
name|int
name|keyType
decl_stmt|;
comment|/* RSA key type.               */
name|unsigned
name|int
name|keyLength
decl_stmt|;
comment|/* Total length of the token.  */
name|unsigned
name|int
name|modulusBitLength
decl_stmt|;
comment|/* Modulus n bit length.       */
comment|/* -- Start of the data length.*/
if|#
directive|if
name|_AIX
name|unsigned
name|int
name|nLength
decl_stmt|;
comment|/* Modulus n = p * q           */
endif|#
directive|endif
name|unsigned
name|int
name|pLength
decl_stmt|;
comment|/* Prime number p .            */
name|unsigned
name|int
name|qLength
decl_stmt|;
comment|/* Prime number q .            */
name|unsigned
name|int
name|dpLength
decl_stmt|;
comment|/* dp = d * mod(p-1) .         */
name|unsigned
name|int
name|dqLength
decl_stmt|;
comment|/* dq = d * mod(q-1) .         */
name|unsigned
name|int
name|qInvLength
decl_stmt|;
comment|/* PKCS: qInv = Ap/q           */
comment|/* -- Start of the data offsets*/
if|#
directive|if
name|_AIX
name|unsigned
name|int
name|nOffset
decl_stmt|;
comment|/* Modulus n .                 */
endif|#
directive|endif
name|unsigned
name|int
name|pOffset
decl_stmt|;
comment|/* Prime number p .            */
name|unsigned
name|int
name|qOffset
decl_stmt|;
comment|/* Prime number q .            */
name|unsigned
name|int
name|dpOffset
decl_stmt|;
comment|/* dp .                        */
name|unsigned
name|int
name|dqOffset
decl_stmt|;
comment|/* dq .                        */
name|unsigned
name|int
name|qInvOffset
decl_stmt|;
comment|/* qInv for PKCS               */
if|#
directive|if
name|_AIX
name|unsigned
name|char
name|reserved
index|[
literal|80
index|]
decl_stmt|;
comment|/* reserved area               */
else|#
directive|else
name|unsigned
name|char
name|reserved
index|[
literal|88
index|]
decl_stmt|;
comment|/* reserved area               */
endif|#
directive|endif
comment|/* -- Start of the variable -- */
comment|/* -- length token data.    -- */
name|ICA_KEY_RSA_CRT_REC
name|keyRecord
decl_stmt|;
block|}
name|ICA_KEY_RSA_CRT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SZ_HEADER_CRT
value|(sizeof(ICA_KEY_RSA_CRT) - sizeof(ICA_KEY_RSA_CRT_REC))
end_define

begin_function_decl
name|unsigned
name|int
name|icaOpenAdapter
parameter_list|(
name|unsigned
name|int
name|adapterId
parameter_list|,
name|ICA_ADAPTER_HANDLE
modifier|*
name|pAdapterHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|icaCloseAdapter
parameter_list|(
name|ICA_ADAPTER_HANDLE
name|adapterHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|icaRsaModExpo
parameter_list|(
name|ICA_ADAPTER_HANDLE
name|hAdapterHandle
parameter_list|,
name|unsigned
name|int
name|inputDataLength
parameter_list|,
name|unsigned
name|char
modifier|*
name|pInputData
parameter_list|,
name|ICA_KEY_RSA_MODEXPO
modifier|*
name|pKeyModExpo
parameter_list|,
name|unsigned
name|int
modifier|*
name|pOutputDataLength
parameter_list|,
name|unsigned
name|char
modifier|*
name|pOutputData
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|icaRsaCrt
parameter_list|(
name|ICA_ADAPTER_HANDLE
name|hAdapterHandle
parameter_list|,
name|unsigned
name|int
name|inputDataLength
parameter_list|,
name|unsigned
name|char
modifier|*
name|pInputData
parameter_list|,
name|ICA_KEY_RSA_CRT
modifier|*
name|pKeyCrt
parameter_list|,
name|unsigned
name|int
modifier|*
name|pOutputDataLength
parameter_list|,
name|unsigned
name|char
modifier|*
name|pOutputData
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|icaRandomNumberGenerate
parameter_list|(
name|ICA_ADAPTER_HANDLE
name|hAdapterHandle
parameter_list|,
name|unsigned
name|int
name|outputDataLength
parameter_list|,
name|unsigned
name|char
modifier|*
name|pOutputData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Specific macros and definitions to not have IFDEF;s all over the    main code */
end_comment

begin_if
if|#
directive|if
operator|(
name|_AIX
operator|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|IBMCA_LIBNAME
init|=
literal|"/lib/libica.a(shr.o)"
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
operator|(
name|WIN32
operator|)
end_elif

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|IBMCA_LIBNAME
init|=
literal|"cryptica"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|IBMCA_LIBNAME
init|=
literal|"ica"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|WIN32
operator|)
end_if

begin_comment
comment|/*  The ICA_KEY_RSA_MODEXPO& ICA_KEY_RSA_CRT lengths and  offsets must be in big-endian format.  */
end_comment

begin_define
define|#
directive|define
name|CORRECT_ENDIANNESS
parameter_list|(
name|b
parameter_list|)
value|(  \                              (((unsigned long) (b)& 0x000000ff)<< 24) |  \                              (((unsigned long) (b)& 0x0000ff00)<<  8) |  \                              (((unsigned long) (b)& 0x00ff0000)>>  8) |  \                              (((unsigned long) (b)& 0xff000000)>> 24)    \                              )
end_define

begin_define
define|#
directive|define
name|CRT_KEY_TYPE
value|RSA_PKCS_PRIVATE_CHINESE_REMAINDER
end_define

begin_define
define|#
directive|define
name|ME_KEY_TYPE
value|RSA_PUBLIC_MODULUS_EXPONENT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CORRECT_ENDIANNESS
parameter_list|(
name|b
parameter_list|)
value|(b)
end_define

begin_define
define|#
directive|define
name|CRT_KEY_TYPE
value|KEYTYPE_PKCSCRT
end_define

begin_define
define|#
directive|define
name|ME_KEY_TYPE
value|KEYTYPE_MODEXPO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ICA_OPENSSL_API_H__ */
end_comment

end_unit

