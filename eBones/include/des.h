begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* des.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995 Eric Young (eay@mincom.oz.au).  * All rights reserved.  * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * See the COPYRIGHT file in the libdes distribution for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_DES_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_DES_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
undef|#
directive|undef
name|_
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
name|DES_SCHEDULE_SZ
value|(sizeof(des_key_schedule))
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
value|des_set_key
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
name|ncbc_encrypt
value|des_ncbc_encrypt
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
name|des_key_schedule
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
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|PROTO
end_undef

begin_define
define|#
directive|define
name|PROTO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* markm - dirty hack */
end_comment

begin_define
define|#
directive|define
name|PROTO
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PROTO
end_ifdef

begin_function_decl
name|int
name|des_2ecb_encrypt
parameter_list|(
name|des_cblock
modifier|*
name|input
parameter_list|,
name|des_cblock
modifier|*
name|output
parameter_list|,
name|des_key_schedule
name|ks1
parameter_list|,
name|des_key_schedule
name|ks2
parameter_list|,
name|int
name|enc
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|des_key_schedule
name|ks1
parameter_list|,
name|des_key_schedule
name|ks2
parameter_list|,
name|des_key_schedule
name|ks3
parameter_list|,
name|int
name|enc
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
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ncbc_encrypt
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
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|enc
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
parameter_list|,
name|des_key_schedule
name|sk1
parameter_list|,
name|des_key_schedule
name|sk2
parameter_list|,
name|des_cblock
modifier|*
name|ivec1
parameter_list|,
name|des_cblock
modifier|*
name|ivec2
parameter_list|,
name|int
name|enc
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
parameter_list|,
name|int
name|enc
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
parameter_list|,
name|des_key_schedule
name|ks
parameter_list|,
name|int
name|enc
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
name|enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_encrypt2
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
name|enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ede3_cbc_encrypt
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
parameter_list|,
name|des_key_schedule
name|ks1
parameter_list|,
name|des_key_schedule
name|ks2
parameter_list|,
name|des_key_schedule
name|ks3
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ede2_cbc_encrypt
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
parameter_list|,
name|des_key_schedule
name|ks1
parameter_list|,
name|des_key_schedule
name|ks2
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|enc
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
parameter_list|,
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
parameter_list|,
name|des_cblock
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|PERL5
end_ifdef

begin_else
unit|char *des_crypt(const char *buf,const char *salt);
else|#
directive|else
end_else

begin_comment
comment|/* some stupid compilers complain because I have declared char instead  * of const char */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HEADER_DES_LOCL_H
end_ifdef

begin_else
unit|char *crypt(const char *buf,const char *salt);
else|#
directive|else
end_else

begin_endif
unit|char *crypt();
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_DES_LOCL_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

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
parameter_list|,
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
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|ivec
parameter_list|,
name|int
name|enc
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
parameter_list|,
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
name|void
name|des_random_seed
parameter_list|(
name|des_cblock
name|key
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
name|des_set_key
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

begin_function_decl
name|int
name|des_cfb64_encrypt
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
modifier|*
name|num
parameter_list|,
name|int
name|enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ofb64_encrypt
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
modifier|*
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|des_cblock_print_file
parameter_list|(
name|des_cblock
modifier|*
name|cb
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|des_2ecb_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_3ecb_encrypt
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
name|int
name|des_cbc_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ncbc_encrypt
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
name|des_encrypt2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ede3_cbc_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ede2_cbc_encrypt
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

begin_ifdef
ifdef|#
directive|ifdef
name|PERL5
end_ifdef

begin_function_decl
name|char
modifier|*
name|des_crypt
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|unsigned
name|long
name|des_quad_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|des_random_seed
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
name|void
name|des_set_odd_parity
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
name|des_set_key
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

begin_function_decl
name|int
name|des_cfb64_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_ofb64_encrypt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|des_cblock_print_file
parameter_list|()
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

