begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/include/RCS/des.h,v $  * $Author: kfall $  * $Header: /usr/src/kerberosIV/include/RCS/des.h,v 4.12 90/06/25 20:48:41 kfall Exp $   *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Include file for the Data Encryption Standard library.  */
end_comment

begin_comment
comment|/* only do the whole thing once	 */
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

begin_ifdef
ifdef|#
directive|ifdef
name|ATHENA
end_ifdef

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* crypto-block size */
end_comment

begin_comment
comment|/* Key schedule */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|des_ks_struct
block|{
name|des_cblock
name|_
decl_stmt|;
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

begin_ifndef
ifndef|#
directive|ifndef
name|NCOMPAT
end_ifndef

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
name|key_sched
value|des_key_sched
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
name|C_Block_print
value|des_cblock_print
end_define

begin_define
define|#
directive|define
name|quad_cksum
value|des_quad_cksum
end_define

begin_typedef
typedef|typedef
name|struct
name|des_ks_struct
name|bit_64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|des_cblock_print
parameter_list|(
name|x
parameter_list|)
value|des_cblock_print_file(x, stdout)
end_define

begin_endif
endif|#
directive|endif
endif|DES_DEFS
end_endif

end_unit

