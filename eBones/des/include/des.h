begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* des.h */
end_comment

begin_comment
comment|/* Copyright (C) 1993 Eric Young - see README for more details */
end_comment

begin_comment
comment|/*-  *	$Id: des.h,v 1.2 1994/07/19 19:22:17 g89r4222 Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_DEFS
end_ifndef

begin_define
define|#
directive|define
name|DES_DEFS
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|des_cblock
index|[
literal|8
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|des_ks_struct
block|{
union|union
block|{
name|des_cblock
name|_
decl_stmt|;
comment|/* make sure things are correct size on machines with 		 * 8 byte longs */
name|unsigned
name|long
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ks
union|;
define|#
directive|define
name|_
value|ks._
block|}
name|des_key_schedule
index|[
literal|16
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DES_KEY_SZ
value|(sizeof(des_cblock))
end_define

begin_define
define|#
directive|define
name|DES_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|DES_DECRYPT
value|0
end_define

begin_define
define|#
directive|define
name|DES_CBC_MODE
value|0
end_define

begin_define
define|#
directive|define
name|DES_PCBC_MODE
value|1
end_define

begin_define
define|#
directive|define
name|C_Block
value|des_cblock
end_define

begin_define
define|#
directive|define
name|Key_schedule
value|des_key_schedule
end_define

begin_define
define|#
directive|define
name|ENCRYPT
value|DES_ENCRYPT
end_define

begin_define
define|#
directive|define
name|DECRYPT
value|DES_DECRYPT
end_define

begin_define
define|#
directive|define
name|KEY_SZ
value|DES_KEY_SZ
end_define

begin_define
define|#
directive|define
name|string_to_key
value|des_string_to_key
end_define

begin_define
define|#
directive|define
name|read_pw_string
value|des_read_pw_string
end_define

begin_define
define|#
directive|define
name|random_key
value|des_random_key
end_define

begin_define
define|#
directive|define
name|pcbc_encrypt
value|des_pcbc_encrypt
end_define

begin_define
define|#
directive|define
name|set_key
value|des_set__key
end_define

begin_define
define|#
directive|define
name|key_sched
value|des_key_sched
end_define

begin_define
define|#
directive|define
name|ecb_encrypt
value|des_ecb_encrypt
end_define

begin_define
define|#
directive|define
name|cbc_encrypt
value|des_cbc_encrypt
end_define

begin_define
define|#
directive|define
name|cbc_cksum
value|des_cbc_cksum
end_define

begin_define
define|#
directive|define
name|quad_cksum
value|des_quad_cksum
end_define

begin_comment
comment|/* For compatibility with the MIT lib - eay 20/05/92 */
end_comment

begin_typedef
typedef|typedef
name|struct
name|des_ks_struct
name|bit_64
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|des_check_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defaults to false */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|des_rw_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defaults to DES_PCBC_MODE */
end_comment

begin_comment
comment|/* The next line is used to disable full ANSI prototypes, if your  * compiler has problems with the prototypes, make sure this line always  * evaluates to true :-) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS
end_ifndef

begin_function_decl
name|int
name|des_3ecb_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_cbc_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_3cbc_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_cfb_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ecb_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_enc_read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_enc_write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ofb_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_pcbc_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_random_key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_read_password
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_read_2passwords
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_read_pw_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_is_weak_key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_set__key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_key_sched
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_string_to_key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_string_to_2keys
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|des_cbc_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|des_quad_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|des_cbc_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|des_set_odd_parity
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PROTO */
end_comment

begin_function_decl
name|int
name|des_3ecb_encrypt
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,\
name|des_key_schedule
name|ks1
parameter_list|,
name|des_key_schedule
name|ks2
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|des_cbc_cksum
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,\
name|long
name|length
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_cbc_encrypt
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,
name|long
name|length
parameter_list|,\
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_3cbc_encrypt
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,
name|long
name|length
parameter_list|,\
name|des_key_schedule
name|sk1
parameter_list|,
name|des_key_schedule
name|sk2
parameter_list|,\
name|des_cblock
modifier|*
name|ivec1
parameter_list|,
name|des_cblock
modifier|*
name|ivec2
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_cfb_encrypt
parameter_list|(
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|int
name|numbits
parameter_list|,\
name|long
name|length
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ecb_encrypt
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,\
name|des_key_schedule
name|ks
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_encrypt
parameter_list|(
name|unsigned
name|long
modifier|*
name|input
parameter_list|,
name|unsigned
name|long
modifier|*
name|output
parameter_list|,
name|des_key_schedule
name|ks
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_enc_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|des_key_schedule
name|sched
parameter_list|,\
name|des_cblock
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_enc_write
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|des_key_schedule
name|sched
parameter_list|,\
name|des_cblock
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|salt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ofb_encrypt
parameter_list|(
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,\
name|int
name|numbits
parameter_list|,
name|long
name|length
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_pcbc_encrypt
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,
name|long
name|length
parameter_list|,\
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|des_quad_cksum
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,\
name|long
name|length
parameter_list|,
name|int
name|out_count
parameter_list|,
name|des_cblock
modifier|*
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_random_key
parameter_list|(
name|des_cblock
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_read_password
parameter_list|(
name|des_cblock
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|verify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_read_2passwords
parameter_list|(
name|des_cblock
modifier|*
name|key1
parameter_list|,
name|des_cblock
modifier|*
name|key2
parameter_list|, \
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|verify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_read_pw_string
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|length
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|verify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|des_set_odd_parity
parameter_list|(
name|des_cblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_is_weak_key
parameter_list|(
name|des_cblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_set__key
parameter_list|(
name|des_cblock
modifier|*
name|key
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_key_sched
parameter_list|(
name|des_cblock
modifier|*
name|key
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_string_to_key
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|des_cblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_string_to_2keys
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|des_cblock
modifier|*
name|key1
parameter_list|,
name|des_cblock
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

