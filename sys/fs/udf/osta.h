begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Prototypes for the OSTA functions  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXLEN
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********************************************************************  * The following two typedef's are to remove compiler dependancies.  * byte needs to be unsigned 8-bit, and unicode_t needs to be  * unsigned 16-bit.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|unicode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef

begin_function_decl
name|int
name|udf_UncompressUnicode
parameter_list|(
name|int
parameter_list|,
name|byte
modifier|*
parameter_list|,
name|unicode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udf_CompressUnicode
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|unicode_t
modifier|*
parameter_list|,
name|byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|udf_cksum
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|udf_unicode_cksum
parameter_list|(
name|unsigned
name|short
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|UDFTransName
parameter_list|(
name|unicode_t
modifier|*
parameter_list|,
name|unicode_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

