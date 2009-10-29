begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMILIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMILIB_H_
end_define

begin_include
include|#
directive|include
file|<dev/rmi/sec/desc.h>
end_include

begin_include
include|#
directive|include
file|<mips/xlr/iomap.h>
end_include

begin_comment
comment|/*#define XLR_SEC_CMD_DEBUG*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XLR_SEC_CMD_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINT
value|printf
end_define

begin_define
define|#
directive|define
name|XLR_SEC_CMD_DIAG
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|{ \                 DPRINT(fmt, ##args); \         }
end_define

begin_define
define|#
directive|define
name|XLR_SEC_CMD_DIAG_SYM_DESC
parameter_list|(
name|desc
parameter_list|,
name|vec
parameter_list|)
value|{ \                 decode_symkey_desc ((desc), (vec)); \         }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_CMD_DIAG
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_CMD_DIAG_SYM_DESC
parameter_list|(
name|desc
parameter_list|,
name|vec
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #include<mips/include/pmap.h>  #define OS_ALLOC_KERNEL(size) kmalloc((size), GFP_KERNEL) #define virt_to_phys(x)  vtophys((vm_offset_t)(x)) */
end_comment

begin_comment
comment|/*  * Cryptographic parameter definitions  */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_DES_KEY_LENGTH
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_3DES_KEY_LENGTH
value|24
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES128_KEY_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES192_KEY_LENGTH
value|24
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES256_KEY_LENGTH
value|32
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES128F8_KEY_LENGTH
value|32
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES192F8_KEY_LENGTH
value|48
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES256F8_KEY_LENGTH
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_KASUMI_F8_KEY_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_MAX_CRYPT_KEY_LENGTH
value|XLR_SEC_AES256F8_KEY_LENGTH
end_define

begin_define
define|#
directive|define
name|XLR_SEC_DES_IV_LENGTH
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES_IV_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_ARC4_IV_LENGTH
value|0
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_KASUMI_F8_IV_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_MAX_IV_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_IV_LENGTH_BYTES
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_AES_BLOCK_SIZE
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_DES_BLOCK_SIZE
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_3DES_BLOCK_SIZE
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_MD5_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA1_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA256_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA384_BLOCK_SIZE
value|128
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA512_BLOCK_SIZE
value|128
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_GCM_BLOCK_SIZE
value|16
end_define

begin_comment
comment|/* XXX: Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_KASUMI_F9_BLOCK_SIZE
value|16
end_define

begin_comment
comment|/* XXX: Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_MAX_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Max of MD5/SHA */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_MD5_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA1_LENGTH
value|20
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA256_LENGTH
value|32
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA384_LENGTH
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SHA512_LENGTH
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_GCM_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_KASUMI_F9_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_KASUMI_F9_RESULT_LENGTH
value|4
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_HMAC_LENGTH
value|64
end_define

begin_comment
comment|/* Max of MD5/SHA/SHA256 */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_MAX_AUTH_KEY_LENGTH
value|XLR_SEC_SHA512_BLOCK_SIZE
end_define

begin_define
define|#
directive|define
name|XLR_SEC_MAX_RC4_STATE_SIZE
value|264
end_define

begin_comment
comment|/* char s[256], int i, int j */
end_comment

begin_comment
comment|/* Status code is used by the SRL to indicate status */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|xlr_sec_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * Status codes  */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_NO_DEVICE
value|-1
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_TIMEOUT
value|-2
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_INVALID_PARAMETER
value|-3
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_DEVICE_FAILED
value|-4
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_DEVICE_BUSY
value|-5
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_NO_RESOURCE
value|-6
end_define

begin_define
define|#
directive|define
name|XLR_SEC_STATUS_CANCELLED
value|-7
end_define

begin_comment
comment|/*  * Flags  */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_FLAGS_HIGH_PRIORITY
value|1
end_define

begin_comment
comment|/* Error code is used to indicate any errors */
end_comment

begin_typedef
typedef|typedef
name|int
name|xlr_sec_error_t
typedef|;
end_typedef

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_ERR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CIPHER_OP
value|-1
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CIPHER_TYPE
value|-2
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CIPHER_MODE
value|-3
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CIPHER_INIT
value|-4
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_DIGEST_TYPE
value|-5
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_DIGEST_INIT
value|-6
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_DIGEST_SRC
value|-7
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CKSUM_TYPE
value|-8
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CKSUM_SRC
value|-9
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_ALLOC
value|-10
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_CONTROL_VECTOR
value|-11
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_LOADHMACKEY_MODE
value|-12
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_PADHASH_MODE
value|-13
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_HASHBYTES_MODE
value|-14
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_NEXT_MODE
value|-15
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_PKT_IV_MODE
value|-16
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_LASTWORD_MODE
value|-17
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_PUBKEY_OP
value|-18
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_SYMKEY_MSGSND
value|-19
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_PUBKEY_MSGSND
value|-20
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_SYMKEY_GETSEM
value|-21
end_define

begin_define
define|#
directive|define
name|XLR_SEC_ERR_PUBKEY_GETSEM
value|-22
end_define

begin_comment
comment|/*  * Descriptor Vector quantities  *  (helps to identify descriptor type per operation)  */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_DES
value|0x0001
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_3DES
value|0x0002
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_AES128
value|0x0004
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_AES192
value|0x0008
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_AES256
value|0x0010
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4
value|0x0020
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_AES
value|(XLR_SEC_VECTOR_CIPHER_AES128 | \                                            XLR_SEC_VECTOR_CIPHER_AES192 | \                                            XLR_SEC_VECTOR_CIPHER_AES256)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER
value|(XLR_SEC_VECTOR_CIPHER_DES | \                                            XLR_SEC_VECTOR_CIPHER_3DES | \                                            XLR_SEC_VECTOR_CIPHER_AES128 | \                                            XLR_SEC_VECTOR_CIPHER_AES192 | \                                            XLR_SEC_VECTOR_CIPHER_AES256 | \                                            XLR_SEC_VECTOR_CIPHER_ARC4)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_HMAC
value|0x0040
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_MAC
value|0x0080
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_MODE_CTR_CFB
value|0x0100
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_MODE_ECB_CBC_OFB
value|0x0200
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_MODE_ECB_CBC
value|0x0400
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_STATE
value|0x0800
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_KASUMI_F8
value|0x01000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_HMAC2
value|0x02000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_GCM
value|0x04000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_F9
value|0x08000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_MODE_F8
value|0x10000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__HMAC
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_HMAC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__STATE
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_STATE)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__HMAC__STATE
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_STATE)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_DES__HMAC__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_DES | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_DES__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_DES | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_3DES__HMAC__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_3DES | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_3DES__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_3DES | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__HMAC__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__HMAC__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__HMAC__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__HMAC__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__HMAC__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__HMAC__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__HMAC__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__HMAC__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__HMAC__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_HMAC | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_KASUMI_F8__F9
define|\
value|(XLR_SEC_VECTOR_CIPHER_KASUMI_F8 | XLR_SEC_VECTOR_F9)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_KASUMI_F8__HMAC
define|\
value|(XLR_SEC_VECTOR_CIPHER_KASUMI_F8 | XLR_SEC_VECTOR_HMAC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_KASUMI_F8__HMAC2
define|\
value|(XLR_SEC_VECTOR_CIPHER_KASUMI_F8 | XLR_SEC_VECTOR_HMAC2)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_KASUMI_F8__GCM
define|\
value|(XLR_SEC_VECTOR_CIPHER_KASUMI_F8 | XLR_SEC_VECTOR_GCM)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__HMAC2
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_HMAC2)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__HMAC2__STATE
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_STATE)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_DES__HMAC2__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_DES | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_3DES__HMAC2__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_3DES | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__HMAC2__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__HMAC2__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__HMAC2__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__HMAC2__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__HMAC2__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__HMAC2__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__HMAC2__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__HMAC2__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__HMAC2__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_HMAC2 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__GCM
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_GCM)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__GCM__STATE
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_STATE)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_DES__GCM__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_DES | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_3DES__GCM__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_3DES | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__GCM__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__GCM__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__GCM__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__GCM__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__GCM__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__GCM__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__GCM__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__GCM__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__GCM__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_GCM | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__F9
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_F9)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR_CIPHER_ARC4__F9__STATE
define|\
value|(XLR_SEC_VECTOR_CIPHER_ARC4 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_STATE)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_DES__F9__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_DES | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_3DES__F9__MODE_ECB_CBC
define|\
value|(XLR_SEC_VECTOR_CIPHER_3DES | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_ECB_CBC)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__F9__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__F9__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__F9__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__F9__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__F9__MODE_CTR_CFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_CTR_CFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__F9__MODE_ECB_CBC_OFB
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_ECB_CBC_OFB)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES128__F9__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES128 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES192__F9__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES192 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_VECTOR__CIPHER_AES256__F9__MODE_F8
define|\
value|(XLR_SEC_VECTOR_CIPHER_AES256 | XLR_SEC_VECTOR_F9 | XLR_SEC_VECTOR_MODE_F8)
end_define

begin_comment
comment|/*  * Cipher Modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CIPHER_MODE_NONE
init|=
literal|0
block|,
name|XLR_SEC_CIPHER_MODE_PASS
init|=
literal|1
block|,
name|XLR_SEC_CIPHER_MODE_ECB
block|,
name|XLR_SEC_CIPHER_MODE_CBC
block|,
name|XLR_SEC_CIPHER_MODE_OFB
block|,
name|XLR_SEC_CIPHER_MODE_CTR
block|,
name|XLR_SEC_CIPHER_MODE_CFB
block|,
name|XLR_SEC_CIPHER_MODE_F8
block|}
name|XLR_SEC_CIPHER_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CIPHER_OP_NONE
init|=
literal|0
block|,
name|XLR_SEC_CIPHER_OP_ENCRYPT
init|=
literal|1
block|,
name|XLR_SEC_CIPHER_OP_DECRYPT
block|}
name|XLR_SEC_CIPHER_OP
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CIPHER_TYPE_UNSUPPORTED
init|=
operator|-
literal|1
block|,
name|XLR_SEC_CIPHER_TYPE_NONE
init|=
literal|0
block|,
name|XLR_SEC_CIPHER_TYPE_DES
block|,
name|XLR_SEC_CIPHER_TYPE_3DES
block|,
name|XLR_SEC_CIPHER_TYPE_AES128
block|,
name|XLR_SEC_CIPHER_TYPE_AES192
block|,
name|XLR_SEC_CIPHER_TYPE_AES256
block|,
name|XLR_SEC_CIPHER_TYPE_ARC4
block|,
name|XLR_SEC_CIPHER_TYPE_KASUMI_F8
block|}
name|XLR_SEC_CIPHER_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CIPHER_INIT_OK
init|=
literal|1
block|,
comment|/* Preserve old Keys */
name|XLR_SEC_CIPHER_INIT_NK
comment|/* Load new Keys */
block|}
name|XLR_SEC_CIPHER_INIT
typedef|;
end_typedef

begin_comment
comment|/*  *  Hash Modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_DIGEST_TYPE_UNSUPPORTED
init|=
operator|-
literal|1
block|,
name|XLR_SEC_DIGEST_TYPE_NONE
init|=
literal|0
block|,
name|XLR_SEC_DIGEST_TYPE_MD5
block|,
name|XLR_SEC_DIGEST_TYPE_SHA1
block|,
name|XLR_SEC_DIGEST_TYPE_SHA256
block|,
name|XLR_SEC_DIGEST_TYPE_SHA384
block|,
name|XLR_SEC_DIGEST_TYPE_SHA512
block|,
name|XLR_SEC_DIGEST_TYPE_GCM
block|,
name|XLR_SEC_DIGEST_TYPE_KASUMI_F9
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_MD5
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_SHA1
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_SHA256
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_SHA384
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_SHA512
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_AES_CBC
block|,
name|XLR_SEC_DIGEST_TYPE_HMAC_AES_XCBC
block|}
name|XLR_SEC_DIGEST_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_DIGEST_INIT_OLDKEY
init|=
literal|1
block|,
comment|/* Preserve old key HMAC key stored in 					 * ID registers (moot if HASH.HMAC == 					 * 0) */
name|XLR_SEC_DIGEST_INIT_NEWKEY
comment|/* Load new HMAC key from memory ctrl 					 * section to ID registers */
block|}
name|XLR_SEC_DIGEST_INIT
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_DIGEST_SRC_DMA
init|=
literal|1
block|,
comment|/* DMA channel */
name|XLR_SEC_DIGEST_SRC_CPHR
comment|/* Cipher if word count exceeded 				 * Cipher_Offset; else DMA */
block|}
name|XLR_SEC_DIGEST_SRC
typedef|;
end_typedef

begin_comment
comment|/*  *  Checksum Modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CKSUM_TYPE_NOP
init|=
literal|1
block|,
name|XLR_SEC_CKSUM_TYPE_IP
block|}
name|XLR_SEC_CKSUM_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CKSUM_SRC_DMA
init|=
literal|1
block|,
name|XLR_SEC_CKSUM_SRC_CIPHER
block|}
name|XLR_SEC_CKSUM_SRC
typedef|;
end_typedef

begin_comment
comment|/*  *  Packet Modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_LOADHMACKEY_MODE_OLD
init|=
literal|1
block|,
name|XLR_SEC_LOADHMACKEY_MODE_LOAD
block|}
name|XLR_SEC_LOADHMACKEY_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_PADHASH_PADDED
init|=
literal|1
block|,
name|XLR_SEC_PADHASH_PAD
block|}
name|XLR_SEC_PADHASH_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_HASHBYTES_ALL8
init|=
literal|1
block|,
name|XLR_SEC_HASHBYTES_MSB
block|,
name|XLR_SEC_HASHBYTES_MSW
block|}
name|XLR_SEC_HASHBYTES_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_NEXT_FINISH
init|=
literal|1
block|,
name|XLR_SEC_NEXT_DO
block|}
name|XLR_SEC_NEXT_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_PKT_IV_OLD
init|=
literal|1
block|,
name|XLR_SEC_PKT_IV_NEW
block|}
name|XLR_SEC_PKT_IV_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_LASTWORD_128
init|=
literal|1
block|,
name|XLR_SEC_LASTWORD_96MASK
block|,
name|XLR_SEC_LASTWORD_64MASK
block|,
name|XLR_SEC_LASTWORD_32MASK
block|}
name|XLR_SEC_LASTWORD_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XLR_SEC_CFB_MASK_REGULAR_CTR
init|=
literal|0
block|,
name|XLR_SEC_CFB_MASK_CCMP
block|,
name|XLR_SEC_CFB_MASK_GCM_WITH_SCI
block|,
name|XLR_SEC_CFB_MASK_GCM_WITHOUT_SCI
block|}
name|XLR_SEC_CFB_MASK_MODE
typedef|;
end_typedef

begin_comment
comment|/*  *  Public Key  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RMIPK_BLKWIDTH_512
init|=
literal|1
block|,
name|RMIPK_BLKWIDTH_1024
block|}
name|RMIPK_BLKWIDTH_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|RMIPK_LDCONST_OLD
init|=
literal|1
block|,
name|RMIPK_LDCONST_NEW
block|}
name|RMIPK_LDCONST_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xlr_sec_io_s
block|{
name|unsigned
name|int
name|command
decl_stmt|;
name|unsigned
name|int
name|result_status
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|unsigned
name|int
name|session_num
decl_stmt|;
name|unsigned
name|int
name|use_callback
decl_stmt|;
name|unsigned
name|int
name|time_us
decl_stmt|;
name|unsigned
name|int
name|user_context
index|[
literal|2
index|]
decl_stmt|;
comment|/* usable for anything by caller */
name|unsigned
name|int
name|command_context
decl_stmt|;
comment|/* Context (ID) of this command). */
name|unsigned
name|char
name|initial_vector
index|[
name|XLR_SEC_MAX_IV_LENGTH
index|]
decl_stmt|;
name|unsigned
name|char
name|crypt_key
index|[
name|XLR_SEC_MAX_CRYPT_KEY_LENGTH
index|]
decl_stmt|;
name|unsigned
name|char
name|mac_key
index|[
name|XLR_SEC_MAX_AUTH_KEY_LENGTH
index|]
decl_stmt|;
name|XLR_SEC_CIPHER_OP
name|cipher_op
decl_stmt|;
name|XLR_SEC_CIPHER_MODE
name|cipher_mode
decl_stmt|;
name|XLR_SEC_CIPHER_TYPE
name|cipher_type
decl_stmt|;
name|XLR_SEC_CIPHER_INIT
name|cipher_init
decl_stmt|;
name|unsigned
name|int
name|cipher_offset
decl_stmt|;
name|XLR_SEC_DIGEST_TYPE
name|digest_type
decl_stmt|;
name|XLR_SEC_DIGEST_INIT
name|digest_init
decl_stmt|;
name|XLR_SEC_DIGEST_SRC
name|digest_src
decl_stmt|;
name|unsigned
name|int
name|digest_offset
decl_stmt|;
name|XLR_SEC_CKSUM_TYPE
name|cksum_type
decl_stmt|;
name|XLR_SEC_CKSUM_SRC
name|cksum_src
decl_stmt|;
name|unsigned
name|int
name|cksum_offset
decl_stmt|;
name|XLR_SEC_LOADHMACKEY_MODE
name|pkt_hmac
decl_stmt|;
name|XLR_SEC_PADHASH_MODE
name|pkt_hash
decl_stmt|;
name|XLR_SEC_HASHBYTES_MODE
name|pkt_hashbytes
decl_stmt|;
name|XLR_SEC_NEXT_MODE
name|pkt_next
decl_stmt|;
name|XLR_SEC_PKT_IV_MODE
name|pkt_iv
decl_stmt|;
name|XLR_SEC_LASTWORD_MODE
name|pkt_lastword
decl_stmt|;
name|unsigned
name|int
name|nonce
decl_stmt|;
name|unsigned
name|int
name|cfb_mask
decl_stmt|;
name|unsigned
name|int
name|iv_offset
decl_stmt|;
name|unsigned
name|short
name|pad_type
decl_stmt|;
name|unsigned
name|short
name|rc4_key_len
decl_stmt|;
name|unsigned
name|int
name|num_packets
decl_stmt|;
name|unsigned
name|int
name|num_fragments
decl_stmt|;
name|uint64_t
name|source_buf
decl_stmt|;
name|unsigned
name|int
name|source_buf_size
decl_stmt|;
name|uint64_t
name|dest_buf
decl_stmt|;
name|unsigned
name|int
name|dest_buf_size
decl_stmt|;
name|uint64_t
name|auth_dest
decl_stmt|;
name|uint64_t
name|cksum_dest
decl_stmt|;
name|unsigned
name|short
name|rc4_loadstate
decl_stmt|;
name|unsigned
name|short
name|rc4_savestate
decl_stmt|;
name|uint64_t
name|rc4_state
decl_stmt|;
block|}
name|xlr_sec_io_t
operator|,
typedef|*
name|xlr_sec_io_pt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XLR_SEC_SESSION
parameter_list|(
name|sid
parameter_list|)
value|((sid)& 0x000007ff)
end_define

begin_define
define|#
directive|define
name|XLR_SEC_SID
parameter_list|(
name|crd
parameter_list|,
name|ses
parameter_list|)
value|(((crd)<< 28) | ((ses)& 0x7ff))
end_define

begin_comment
comment|/*  *  Length values for cryptography  */
end_comment

begin_comment
comment|/* #define XLR_SEC_DES_KEY_LENGTH     8 #define XLR_SEC_3DES_KEY_LENGTH        24 #define XLR_SEC_MAX_CRYPT_KEY_LENGTH   XLR_SEC_3DES_KEY_LENGTH #define XLR_SEC_IV_LENGTH          8 #define XLR_SEC_AES_IV_LENGTH      16 #define XLR_SEC_MAX_IV_LENGTH      XLR_SEC_AES_IV_LENGTH */
end_comment

begin_define
define|#
directive|define
name|SEC_MAX_FRAG_LEN
value|16000
end_define

begin_struct
struct|struct
name|xlr_sec_command
block|{
name|uint16_t
name|session_num
decl_stmt|;
name|struct
name|cryptop
modifier|*
name|crp
decl_stmt|;
name|struct
name|cryptodesc
modifier|*
name|enccrd
decl_stmt|,
modifier|*
name|maccrd
decl_stmt|;
name|xlr_sec_io_t
name|op
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlr_sec_session
block|{
name|uint32_t
name|sessionid
decl_stmt|;
name|int
name|hs_used
decl_stmt|;
name|int
name|hs_mlen
decl_stmt|;
name|struct
name|xlr_sec_command
name|cmd
decl_stmt|;
name|void
modifier|*
name|desc_ptr
decl_stmt|;
name|uint8_t
name|multi_frag_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Holds data specific to rmi security accelerators  */
end_comment

begin_struct
struct|struct
name|xlr_sec_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device backpointer */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* per-instance lock */
name|int32_t
name|sc_cid
decl_stmt|;
name|struct
name|xlr_sec_session
modifier|*
name|sc_sessions
decl_stmt|;
name|int
name|sc_nsessions
decl_stmt|;
name|xlr_reg_t
modifier|*
name|mmio
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  union xlr_sec_operand_t {         struct mbuf *m;         struct uio *io;         void *buf; }xlr_sec_operand; */
end_comment

begin_comment
comment|/* this is passed to packet setup to optimize */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_CIPHER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_HMAC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_CIPHER_HMAC
value|(XLR_SEC_SETUP_OP_CIPHER | XLR_SEC_SETUP_OP_HMAC)
end_define

begin_comment
comment|/* this is passed to control_setup to update w/preserving existing keys */
end_comment

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_PRESERVE_HMAC_KEY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_PRESERVE_CIPHER_KEY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_UPDATE_KEYS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XLR_SEC_SETUP_OP_FLIP_3DES_KEY
value|0x00000020
end_define

begin_comment
comment|/*  *   Message Ring Specifics  */
end_comment

begin_define
define|#
directive|define
name|SEC_MSGRING_WORDSIZE
value|2
end_define

begin_comment
comment|/*  *  *  * rwR      31  30 29     27 26    24 23      21 20     18  *         |  NA  | RSA0Out | Rsa0In | Pipe3Out | Pipe3In | ...  *  *          17       15 14     12 11      9 8       6 5        3 2       0  *         |  Pipe2Out | Pipe2In | Pipe1In | Pipe1In | Pipe0Out | Pipe0In |  *  * DMA CREDIT REG -  *   NUMBER OF CREDITS PER PIPE  */
end_comment

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_RSA0_OUT_FOUR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_RSA0_OUT_TWO
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_RSA0_OUT_ONE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_RSA0_IN_FOUR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_RSA0_IN_TWO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_RSA0_IN_ONE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE3_OUT_FOUR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE3_OUT_TWO
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE3_OUT_ONE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE3_IN_FOUR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE3_IN_TWO
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE3_IN_ONE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE2_OUT_FOUR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE2_OUT_TWO
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE2_OUT_ONE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE2_IN_FOUR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE2_IN_TWO
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE2_IN_ONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE1_OUT_FOUR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE1_OUT_TWO
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE1_OUT_ONE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE1_IN_FOUR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE1_IN_TWO
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE1_IN_ONE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE0_OUT_FOUR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE0_OUT_TWO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE0_OUT_ONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE0_IN_FOUR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE0_IN_TWO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_PIPE0_IN_ONE
value|0x00000001
end_define

begin_comment
comment|/*  *  Currently, FOUR credits per PIPE  *  0x24924924  */
end_comment

begin_define
define|#
directive|define
name|SEC_DMA_CREDIT_CONFIG
value|SEC_DMA_CREDIT_RSA0_OUT_FOUR | \                                        SEC_DMA_CREDIT_RSA0_IN_FOUR | \                                        SEC_DMA_CREDIT_PIPE3_OUT_FOUR | \                                        SEC_DMA_CREDIT_PIPE3_IN_FOUR | \                                        SEC_DMA_CREDIT_PIPE2_OUT_FOUR | \                                        SEC_DMA_CREDIT_PIPE2_IN_FOUR | \                                        SEC_DMA_CREDIT_PIPE1_OUT_FOUR | \                                        SEC_DMA_CREDIT_PIPE1_IN_FOUR | \                                        SEC_DMA_CREDIT_PIPE0_OUT_FOUR | \                                        SEC_DMA_CREDIT_PIPE0_IN_FOUR
end_define

begin_comment
comment|/*  * CONFIG2  *    31   5         4                   3  *   |  NA  | PIPE3_DEF_DBL_ISS | PIPE2_DEF_DBL_ISS | ...  *  *                 2                   1                   0  *   ... | PIPE1_DEF_DBL_ISS | PIPE0_DEF_DBL_ISS | ROUND_ROBIN_MODE |  *  *  DBL_ISS - mode for SECENG and DMA controller which slows down transfers  *             (to be conservativei; 0=Disable,1=Enable).  *  ROUND_ROBIN - mode where SECENG dispatches operations to PIPE0-PIPE3  *                and all messages are sent to PIPE0.  *  */
end_comment

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE3_DBL_ISS_ON
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE3_DBL_ISS_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE2_DBL_ISS_ON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE2_DBL_ISS_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE1_DBL_ISS_ON
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE1_DBL_ISS_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE0_DBL_ISS_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_PIPE0_DBL_ISS_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_ROUND_ROBIN_ON
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SEC_CFG2_ROUND_ROBIN_OFF
value|0x00000000
end_define

begin_enum
enum|enum
name|sec_pipe_config
block|{
name|SEC_PIPE_CIPHER_KEY0_L0
init|=
literal|0x00
block|,
name|SEC_PIPE_CIPHER_KEY0_HI
block|,
name|SEC_PIPE_CIPHER_KEY1_LO
block|,
name|SEC_PIPE_CIPHER_KEY1_HI
block|,
name|SEC_PIPE_CIPHER_KEY2_LO
block|,
name|SEC_PIPE_CIPHER_KEY2_HI
block|,
name|SEC_PIPE_CIPHER_KEY3_LO
block|,
name|SEC_PIPE_CIPHER_KEY3_HI
block|,
name|SEC_PIPE_HMAC_KEY0_LO
block|,
name|SEC_PIPE_HMAC_KEY0_HI
block|,
name|SEC_PIPE_HMAC_KEY1_LO
block|,
name|SEC_PIPE_HMAC_KEY1_HI
block|,
name|SEC_PIPE_HMAC_KEY2_LO
block|,
name|SEC_PIPE_HMAC_KEY2_HI
block|,
name|SEC_PIPE_HMAC_KEY3_LO
block|,
name|SEC_PIPE_HMAC_KEY3_HI
block|,
name|SEC_PIPE_HMAC_KEY4_LO
block|,
name|SEC_PIPE_HMAC_KEY4_HI
block|,
name|SEC_PIPE_HMAC_KEY5_LO
block|,
name|SEC_PIPE_HMAC_KEY5_HI
block|,
name|SEC_PIPE_HMAC_KEY6_LO
block|,
name|SEC_PIPE_HMAC_KEY6_HI
block|,
name|SEC_PIPE_HMAC_KEY7_LO
block|,
name|SEC_PIPE_HMAC_KEY7_HI
block|,
name|SEC_PIPE_NCFBM_LO
block|,
name|SEC_PIPE_NCFBM_HI
block|,
name|SEC_PIPE_INSTR_LO
block|,
name|SEC_PIPE_INSTR_HI
block|,
name|SEC_PIPE_RSVD0
block|,
name|SEC_PIPE_RSVD1
block|,
name|SEC_PIPE_RSVD2
block|,
name|SEC_PIPE_RSVD3
block|,
name|SEC_PIPE_DF_PTRS0
block|,
name|SEC_PIPE_DF_PTRS1
block|,
name|SEC_PIPE_DF_PTRS2
block|,
name|SEC_PIPE_DF_PTRS3
block|,
name|SEC_PIPE_DF_PTRS4
block|,
name|SEC_PIPE_DF_PTRS5
block|,
name|SEC_PIPE_DF_PTRS6
block|,
name|SEC_PIPE_DF_PTRS7
block|,
name|SEC_PIPE_DU_DATA_IN_LO
block|,
name|SEC_PIPE_DU_DATA_IN_HI
block|,
name|SEC_PIPE_DU_DATA_IN_CTRL
block|,
name|SEC_PIPE_DU_DATA_OUT_LO
block|,
name|SEC_PIPE_DU_DATA_OUT_HI
block|,
name|SEC_PIPE_DU_DATA_OUT_CTRL
block|,
name|SEC_PIPE_STATE0
block|,
name|SEC_PIPE_STATE1
block|,
name|SEC_PIPE_STATE2
block|,
name|SEC_PIPE_STATE3
block|,
name|SEC_PIPE_STATE4
block|,
name|SEC_PIPE_INCLUDE_MASK0
block|,
name|SEC_PIPE_INCLUDE_MASK1
block|,
name|SEC_PIPE_INCLUDE_MASK2
block|,
name|SEC_PIPE_INCLUDE_MASK3
block|,
name|SEC_PIPE_INCLUDE_MASK4
block|,
name|SEC_PIPE_EXCLUDE_MASK0
block|,
name|SEC_PIPE_EXCLUDE_MASK1
block|,
name|SEC_PIPE_EXCLUDE_MASK2
block|,
name|SEC_PIPE_EXCLUDE_MASK3
block|,
name|SEC_PIPE_EXCLUDE_MASK4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|sec_pipe_base_config
block|{
name|SEC_PIPE0_BASE
init|=
literal|0x00
block|,
name|SEC_PIPE1_BASE
init|=
literal|0x40
block|,
name|SEC_PIPE2_BASE
init|=
literal|0x80
block|,
name|SEC_PIPE3_BASE
init|=
literal|0xc0
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sec_rsa_config
block|{
name|SEC_RSA_PIPE0_DU_DATA_IN_LO
init|=
literal|0x100
block|,
name|SEC_RSA_PIPE0_DU_DATA_IN_HI
block|,
name|SEC_RSA_PIPE0_DU_DATA_IN_CTRL
block|,
name|SEC_RSA_PIPE0_DU_DATA_OUT_LO
block|,
name|SEC_RSA_PIPE0_DU_DATA_OUT_HI
block|,
name|SEC_RSA_PIPE0_DU_DATA_OUT_CTRL
block|,
name|SEC_RSA_RSVD0
block|,
name|SEC_RSA_RSVD1
block|,
name|SEC_RSA_PIPE0_STATE0
block|,
name|SEC_RSA_PIPE0_STATE1
block|,
name|SEC_RSA_PIPE0_STATE2
block|,
name|SEC_RSA_PIPE0_INCLUDE_MASK0
block|,
name|SEC_RSA_PIPE0_INCLUDE_MASK1
block|,
name|SEC_RSA_PIPE0_INCLUDE_MASK2
block|,
name|SEC_RSA_PIPE0_EXCLUDE_MASK0
block|,
name|SEC_RSA_PIPE0_EXCLUDE_MASK1
block|,
name|SEC_RSA_PIPE0_EXCLUDE_MASK2
block|,
name|SEC_RSA_PIPE0_EVENT_CTR
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sec_config
block|{
name|SEC_DMA_CREDIT
init|=
literal|0x140
block|,
name|SEC_CONFIG1
block|,
name|SEC_CONFIG2
block|,
name|SEC_CONFIG3
block|,  }
enum|;
end_enum

begin_enum
enum|enum
name|sec_debug_config
block|{
name|SEC_DW0_DESCRIPTOR0_LO
init|=
literal|0x180
block|,
name|SEC_DW0_DESCRIPTOR0_HI
block|,
name|SEC_DW0_DESCRIPTOR1_LO
block|,
name|SEC_DW0_DESCRIPTOR1_HI
block|,
name|SEC_DW1_DESCRIPTOR0_LO
block|,
name|SEC_DW1_DESCRIPTOR0_HI
block|,
name|SEC_DW1_DESCRIPTOR1_LO
block|,
name|SEC_DW1_DESCRIPTOR1_HI
block|,
name|SEC_DW2_DESCRIPTOR0_LO
block|,
name|SEC_DW2_DESCRIPTOR0_HI
block|,
name|SEC_DW2_DESCRIPTOR1_LO
block|,
name|SEC_DW2_DESCRIPTOR1_HI
block|,
name|SEC_DW3_DESCRIPTOR0_LO
block|,
name|SEC_DW3_DESCRIPTOR0_HI
block|,
name|SEC_DW3_DESCRIPTOR1_LO
block|,
name|SEC_DW3_DESCRIPTOR1_HI
block|,
name|SEC_STATE0
block|,
name|SEC_STATE1
block|,
name|SEC_STATE2
block|,
name|SEC_INCLUDE_MASK0
block|,
name|SEC_INCLUDE_MASK1
block|,
name|SEC_INCLUDE_MASK2
block|,
name|SEC_EXCLUDE_MASK0
block|,
name|SEC_EXCLUDE_MASK1
block|,
name|SEC_EXCLUDE_MASK2
block|,
name|SEC_EVENT_CTR
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sec_msgring_bucket_config
block|{
name|SEC_BIU_CREDITS
init|=
literal|0x308
block|,
name|SEC_MSG_BUCKET0_SIZE
init|=
literal|0x320
block|,
name|SEC_MSG_BUCKET1_SIZE
block|,
name|SEC_MSG_BUCKET2_SIZE
block|,
name|SEC_MSG_BUCKET3_SIZE
block|,
name|SEC_MSG_BUCKET4_SIZE
block|,
name|SEC_MSG_BUCKET5_SIZE
block|,
name|SEC_MSG_BUCKET6_SIZE
block|,
name|SEC_MSG_BUCKET7_SIZE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|sec_msgring_credit_config
block|{
name|SEC_CC_CPU0_0
init|=
literal|0x380
block|,
name|SEC_CC_CPU1_0
init|=
literal|0x388
block|,
name|SEC_CC_CPU2_0
init|=
literal|0x390
block|,
name|SEC_CC_CPU3_0
init|=
literal|0x398
block|,
name|SEC_CC_CPU4_0
init|=
literal|0x3a0
block|,
name|SEC_CC_CPU5_0
init|=
literal|0x3a8
block|,
name|SEC_CC_CPU6_0
init|=
literal|0x3b0
block|,
name|SEC_CC_CPU7_0
init|=
literal|0x3b8
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sec_engine_id
block|{
name|SEC_PIPE0
block|,
name|SEC_PIPE1
block|,
name|SEC_PIPE2
block|,
name|SEC_PIPE3
block|,
name|SEC_RSA
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sec_cipher
block|{
name|SEC_AES256_MODE_HMAC
block|,
name|SEC_AES256_MODE
block|,
name|SEC_AES256_HMAC
block|,
name|SEC_AES256
block|,
name|SEC_AES192_MODE_HMAC
block|,
name|SEC_AES192_MODE
block|,
name|SEC_AES192_HMAC
block|,
name|SEC_AES192
block|,
name|SEC_AES128_MODE_HMAC
block|,
name|SEC_AES128_MODE
block|,
name|SEC_AES128_HMAC
block|,
name|SEC_AES128
block|,
name|SEC_DES_HMAC
block|,
name|SEC_DES
block|,
name|SEC_3DES
block|,
name|SEC_3DES_HMAC
block|,
name|SEC_HMAC
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sec_msgrng_msg_ctrl_config
block|{
name|SEC_EOP
init|=
literal|5
block|,
name|SEC_SOP
init|=
literal|6
block|, }
enum|;
end_enum

begin_function_decl
name|void
name|xlr_sec_init
parameter_list|(
name|struct
name|xlr_sec_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xlr_sec_setup
parameter_list|(
name|struct
name|xlr_sec_session
modifier|*
name|ses
parameter_list|,
name|struct
name|xlr_sec_command
modifier|*
name|cmd
parameter_list|,
name|symkey_desc_pt
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symkey_desc_pt
name|xlr_sec_allocate_desc
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

