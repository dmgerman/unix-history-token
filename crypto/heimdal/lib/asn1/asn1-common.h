begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__asn1_common_definitions__
end_ifndef

begin_define
define|#
directive|define
name|__asn1_common_definitions__
end_define

begin_typedef
typedef|typedef
struct|struct
name|heim_integer
block|{
name|size_t
name|length
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|negative
decl_stmt|;
block|}
name|heim_integer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|heim_octet_string
block|{
name|size_t
name|length
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|heim_octet_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|heim_general_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|heim_utf8_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_octet_string
name|heim_printable_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_octet_string
name|heim_ia5_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|heim_bmp_string
block|{
name|size_t
name|length
decl_stmt|;
name|uint16_t
modifier|*
name|data
decl_stmt|;
block|}
name|heim_bmp_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|heim_universal_string
block|{
name|size_t
name|length
decl_stmt|;
name|uint32_t
modifier|*
name|data
decl_stmt|;
block|}
name|heim_universal_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|heim_visible_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|heim_oid
block|{
name|size_t
name|length
decl_stmt|;
name|unsigned
modifier|*
name|components
decl_stmt|;
block|}
name|heim_oid
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|heim_bit_string
block|{
name|size_t
name|length
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|heim_bit_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_octet_string
name|heim_any
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_octet_string
name|heim_any_set
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ASN1_MALLOC_ENCODE
parameter_list|(
name|T
parameter_list|,
name|B
parameter_list|,
name|BL
parameter_list|,
name|S
parameter_list|,
name|L
parameter_list|,
name|R
parameter_list|)
define|\
value|do {                                                         \     (BL) = length_##T((S));                                    \     (B) = malloc((BL));                                        \     if((B) == NULL) {                                          \       (R) = ENOMEM;                                            \     } else {                                                   \       (R) = encode_##T(((unsigned char*)(B)) + (BL) - 1, (BL), \                        (S), (L));                              \       if((R) != 0) {                                           \         free((B));                                             \         (B) = NULL;                                            \       }                                                        \     }                                                          \   } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ASN1_LIB
end_ifndef

begin_define
define|#
directive|define
name|ASN1EXP
value|__declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASN1EXP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASN1CALL
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASN1EXP
end_define

begin_define
define|#
directive|define
name|ASN1CALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

