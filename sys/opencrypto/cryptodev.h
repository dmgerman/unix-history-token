begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: cryptodev.h,v 1.31 2002/06/11 11:14:29 beck Exp $	*/
end_comment

begin_comment
comment|/*-  * The author of this code is Angelos D. Keromytis (angelos@cis.upenn.edu)  * Copyright (c) 2002-2006 Sam Leffler, Errno Consulting  *  * This code was written by Angelos D. Keromytis in Athens, Greece, in  * February 2000. Network Security Technologies Inc. (NSTI) kindly  * supported the development of this code.  *  * Copyright (c) 2000 Angelos D. Keromytis  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all source code copies of any software which is or includes a copy or  * modification of this software.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  *  * Copyright (c) 2001 Theo de Raadt  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in the  *   documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *   derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRYPTO_CRYPTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRYPTO_CRYPTO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Some initial values */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_DRIVERS_INITIAL
value|4
end_define

begin_define
define|#
directive|define
name|CRYPTO_SW_SESSIONS
value|32
end_define

begin_comment
comment|/* Hash values */
end_comment

begin_define
define|#
directive|define
name|NULL_HASH_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MD5_HASH_LEN
value|16
end_define

begin_define
define|#
directive|define
name|SHA1_HASH_LEN
value|20
end_define

begin_define
define|#
directive|define
name|RIPEMD160_HASH_LEN
value|20
end_define

begin_define
define|#
directive|define
name|SHA2_256_HASH_LEN
value|32
end_define

begin_define
define|#
directive|define
name|SHA2_384_HASH_LEN
value|48
end_define

begin_define
define|#
directive|define
name|SHA2_512_HASH_LEN
value|64
end_define

begin_define
define|#
directive|define
name|MD5_KPDK_HASH_LEN
value|16
end_define

begin_define
define|#
directive|define
name|SHA1_KPDK_HASH_LEN
value|20
end_define

begin_comment
comment|/* Maximum hash algorithm result length */
end_comment

begin_define
define|#
directive|define
name|HASH_MAX_LEN
value|SHA2_512_HASH_LEN
end_define

begin_comment
comment|/* Keep this updated */
end_comment

begin_comment
comment|/* HMAC values */
end_comment

begin_define
define|#
directive|define
name|NULL_HMAC_BLOCK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|MD5_HMAC_BLOCK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|SHA1_HMAC_BLOCK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|RIPEMD160_HMAC_BLOCK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|SHA2_256_HMAC_BLOCK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|SHA2_384_HMAC_BLOCK_LEN
value|128
end_define

begin_define
define|#
directive|define
name|SHA2_512_HMAC_BLOCK_LEN
value|128
end_define

begin_comment
comment|/* Maximum HMAC block length */
end_comment

begin_define
define|#
directive|define
name|HMAC_MAX_BLOCK_LEN
value|SHA2_512_HMAC_BLOCK_LEN
end_define

begin_comment
comment|/* Keep this updated */
end_comment

begin_define
define|#
directive|define
name|HMAC_IPAD_VAL
value|0x36
end_define

begin_define
define|#
directive|define
name|HMAC_OPAD_VAL
value|0x5C
end_define

begin_comment
comment|/* Encryption algorithm block sizes */
end_comment

begin_define
define|#
directive|define
name|NULL_BLOCK_LEN
value|4
end_define

begin_define
define|#
directive|define
name|DES_BLOCK_LEN
value|8
end_define

begin_define
define|#
directive|define
name|DES3_BLOCK_LEN
value|8
end_define

begin_define
define|#
directive|define
name|BLOWFISH_BLOCK_LEN
value|8
end_define

begin_define
define|#
directive|define
name|SKIPJACK_BLOCK_LEN
value|8
end_define

begin_define
define|#
directive|define
name|CAST128_BLOCK_LEN
value|8
end_define

begin_define
define|#
directive|define
name|RIJNDAEL128_BLOCK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|AES_BLOCK_LEN
value|RIJNDAEL128_BLOCK_LEN
end_define

begin_define
define|#
directive|define
name|EALG_MAX_BLOCK_LEN
value|AES_BLOCK_LEN
end_define

begin_comment
comment|/* Keep this updated */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ALGORITHM_MIN
value|1
end_define

begin_define
define|#
directive|define
name|CRYPTO_DES_CBC
value|1
end_define

begin_define
define|#
directive|define
name|CRYPTO_3DES_CBC
value|2
end_define

begin_define
define|#
directive|define
name|CRYPTO_BLF_CBC
value|3
end_define

begin_define
define|#
directive|define
name|CRYPTO_CAST_CBC
value|4
end_define

begin_define
define|#
directive|define
name|CRYPTO_SKIPJACK_CBC
value|5
end_define

begin_define
define|#
directive|define
name|CRYPTO_MD5_HMAC
value|6
end_define

begin_define
define|#
directive|define
name|CRYPTO_SHA1_HMAC
value|7
end_define

begin_define
define|#
directive|define
name|CRYPTO_RIPEMD160_HMAC
value|8
end_define

begin_define
define|#
directive|define
name|CRYPTO_MD5_KPDK
value|9
end_define

begin_define
define|#
directive|define
name|CRYPTO_SHA1_KPDK
value|10
end_define

begin_define
define|#
directive|define
name|CRYPTO_RIJNDAEL128_CBC
value|11
end_define

begin_comment
comment|/* 128 bit blocksize */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_AES_CBC
value|11
end_define

begin_comment
comment|/* 128 bit blocksize -- the same as above */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ARC4
value|12
end_define

begin_define
define|#
directive|define
name|CRYPTO_MD5
value|13
end_define

begin_define
define|#
directive|define
name|CRYPTO_SHA1
value|14
end_define

begin_define
define|#
directive|define
name|CRYPTO_NULL_HMAC
value|15
end_define

begin_define
define|#
directive|define
name|CRYPTO_NULL_CBC
value|16
end_define

begin_define
define|#
directive|define
name|CRYPTO_DEFLATE_COMP
value|17
end_define

begin_comment
comment|/* Deflate compression algorithm */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_SHA2_256_HMAC
value|18
end_define

begin_define
define|#
directive|define
name|CRYPTO_SHA2_384_HMAC
value|19
end_define

begin_define
define|#
directive|define
name|CRYPTO_SHA2_512_HMAC
value|20
end_define

begin_define
define|#
directive|define
name|CRYPTO_ALGORITHM_MAX
value|20
end_define

begin_comment
comment|/* Keep updated - see below */
end_comment

begin_comment
comment|/* Algorithm flags */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ALG_FLAG_SUPPORTED
value|0x01
end_define

begin_comment
comment|/* Algorithm is supported */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ALG_FLAG_RNG_ENABLE
value|0x02
end_define

begin_comment
comment|/* Has HW RNG for DH/DSA */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ALG_FLAG_DSA_SHA
value|0x04
end_define

begin_comment
comment|/* Can do SHA on msg */
end_comment

begin_comment
comment|/*  * Crypto driver/device flags.  They can set in the crid  * parameter when creating a session or submitting a key  * op to affect the device/driver assigned.  If neither  * of these are specified then the crid is assumed to hold  * the driver id of an existing (and suitable) device that  * must be used to satisfy the request.  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_HARDWARE
value|0x01000000
end_define

begin_comment
comment|/* hardware accelerated */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_SOFTWARE
value|0x02000000
end_define

begin_comment
comment|/* software implementation */
end_comment

begin_comment
comment|/* NB: deprecated */
end_comment

begin_struct
struct|struct
name|session_op
block|{
name|u_int32_t
name|cipher
decl_stmt|;
comment|/* ie. CRYPTO_DES_CBC */
name|u_int32_t
name|mac
decl_stmt|;
comment|/* ie. CRYPTO_MD5_HMAC */
name|u_int32_t
name|keylen
decl_stmt|;
comment|/* cipher key */
name|caddr_t
name|key
decl_stmt|;
name|int
name|mackeylen
decl_stmt|;
comment|/* mac key */
name|caddr_t
name|mackey
decl_stmt|;
name|u_int32_t
name|ses
decl_stmt|;
comment|/* returns: session # */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|session2_op
block|{
name|u_int32_t
name|cipher
decl_stmt|;
comment|/* ie. CRYPTO_DES_CBC */
name|u_int32_t
name|mac
decl_stmt|;
comment|/* ie. CRYPTO_MD5_HMAC */
name|u_int32_t
name|keylen
decl_stmt|;
comment|/* cipher key */
name|caddr_t
name|key
decl_stmt|;
name|int
name|mackeylen
decl_stmt|;
comment|/* mac key */
name|caddr_t
name|mackey
decl_stmt|;
name|u_int32_t
name|ses
decl_stmt|;
comment|/* returns: session # */
name|int
name|crid
decl_stmt|;
comment|/* driver id + flags (rw) */
name|int
name|pad
index|[
literal|4
index|]
decl_stmt|;
comment|/* for future expansion */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|crypt_op
block|{
name|u_int32_t
name|ses
decl_stmt|;
name|u_int16_t
name|op
decl_stmt|;
comment|/* i.e. COP_ENCRYPT */
define|#
directive|define
name|COP_ENCRYPT
value|1
define|#
directive|define
name|COP_DECRYPT
value|2
name|u_int16_t
name|flags
decl_stmt|;
define|#
directive|define
name|COP_F_BATCH
value|0x0008
comment|/* Batch op if possible */
name|u_int
name|len
decl_stmt|;
name|caddr_t
name|src
decl_stmt|,
name|dst
decl_stmt|;
comment|/* become iov[] inside kernel */
name|caddr_t
name|mac
decl_stmt|;
comment|/* must be big enough for chosen MAC */
name|caddr_t
name|iv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parameters for looking up a crypto driver/device by  * device name or by id.  The latter are returned for  * created sessions (crid) and completed key operations.  */
end_comment

begin_struct
struct|struct
name|crypt_find_op
block|{
name|int
name|crid
decl_stmt|;
comment|/* driver id + flags */
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* device/driver name */
block|}
struct|;
end_struct

begin_comment
comment|/* bignum parameter, in packed bytes, ... */
end_comment

begin_struct
struct|struct
name|crparam
block|{
name|caddr_t
name|crp_p
decl_stmt|;
name|u_int
name|crp_nbits
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CRK_MAXPARAM
value|8
end_define

begin_struct
struct|struct
name|crypt_kop
block|{
name|u_int
name|crk_op
decl_stmt|;
comment|/* ie. CRK_MOD_EXP or other */
name|u_int
name|crk_status
decl_stmt|;
comment|/* return status */
name|u_short
name|crk_iparams
decl_stmt|;
comment|/* # of input parameters */
name|u_short
name|crk_oparams
decl_stmt|;
comment|/* # of output parameters */
name|u_int
name|crk_crid
decl_stmt|;
comment|/* NB: only used by CIOCKEY2 (rw) */
name|struct
name|crparam
name|crk_param
index|[
name|CRK_MAXPARAM
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CRK_ALGORITM_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CRK_MOD_EXP
value|0
end_define

begin_define
define|#
directive|define
name|CRK_MOD_EXP_CRT
value|1
end_define

begin_define
define|#
directive|define
name|CRK_DSA_SIGN
value|2
end_define

begin_define
define|#
directive|define
name|CRK_DSA_VERIFY
value|3
end_define

begin_define
define|#
directive|define
name|CRK_DH_COMPUTE_KEY
value|4
end_define

begin_define
define|#
directive|define
name|CRK_ALGORITHM_MAX
value|4
end_define

begin_comment
comment|/* Keep updated - see below */
end_comment

begin_define
define|#
directive|define
name|CRF_MOD_EXP
value|(1<< CRK_MOD_EXP)
end_define

begin_define
define|#
directive|define
name|CRF_MOD_EXP_CRT
value|(1<< CRK_MOD_EXP_CRT)
end_define

begin_define
define|#
directive|define
name|CRF_DSA_SIGN
value|(1<< CRK_DSA_SIGN)
end_define

begin_define
define|#
directive|define
name|CRF_DSA_VERIFY
value|(1<< CRK_DSA_VERIFY)
end_define

begin_define
define|#
directive|define
name|CRF_DH_COMPUTE_KEY
value|(1<< CRK_DH_COMPUTE_KEY)
end_define

begin_comment
comment|/*  * done against open of /dev/crypto, to get a cloned descriptor.  * Please use F_SETFD against the cloned descriptor.  */
end_comment

begin_define
define|#
directive|define
name|CRIOGET
value|_IOWR('c', 100, u_int32_t)
end_define

begin_define
define|#
directive|define
name|CRIOASYMFEAT
value|CIOCASYMFEAT
end_define

begin_define
define|#
directive|define
name|CRIOFINDDEV
value|CIOCFINDDEV
end_define

begin_comment
comment|/* the following are done against the cloned descriptor */
end_comment

begin_define
define|#
directive|define
name|CIOCGSESSION
value|_IOWR('c', 101, struct session_op)
end_define

begin_define
define|#
directive|define
name|CIOCFSESSION
value|_IOW('c', 102, u_int32_t)
end_define

begin_define
define|#
directive|define
name|CIOCCRYPT
value|_IOWR('c', 103, struct crypt_op)
end_define

begin_define
define|#
directive|define
name|CIOCKEY
value|_IOWR('c', 104, struct crypt_kop)
end_define

begin_define
define|#
directive|define
name|CIOCASYMFEAT
value|_IOR('c', 105, u_int32_t)
end_define

begin_define
define|#
directive|define
name|CIOCGSESSION2
value|_IOWR('c', 106, struct session2_op)
end_define

begin_define
define|#
directive|define
name|CIOCKEY2
value|_IOWR('c', 107, struct crypt_kop)
end_define

begin_define
define|#
directive|define
name|CIOCFINDDEV
value|_IOWR('c', 108, struct crypt_find_op)
end_define

begin_struct
struct|struct
name|cryptotstat
block|{
name|struct
name|timespec
name|acc
decl_stmt|;
comment|/* total accumulated time */
name|struct
name|timespec
name|min
decl_stmt|;
comment|/* min time */
name|struct
name|timespec
name|max
decl_stmt|;
comment|/* max time */
name|u_int32_t
name|count
decl_stmt|;
comment|/* number of observations */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cryptostats
block|{
name|u_int32_t
name|cs_ops
decl_stmt|;
comment|/* symmetric crypto ops submitted */
name|u_int32_t
name|cs_errs
decl_stmt|;
comment|/* symmetric crypto ops that failed */
name|u_int32_t
name|cs_kops
decl_stmt|;
comment|/* asymetric/key ops submitted */
name|u_int32_t
name|cs_kerrs
decl_stmt|;
comment|/* asymetric/key ops that failed */
name|u_int32_t
name|cs_intrs
decl_stmt|;
comment|/* crypto swi thread activations */
name|u_int32_t
name|cs_rets
decl_stmt|;
comment|/* crypto return thread activations */
name|u_int32_t
name|cs_blocks
decl_stmt|;
comment|/* symmetric op driver block */
name|u_int32_t
name|cs_kblocks
decl_stmt|;
comment|/* symmetric op driver block */
comment|/* 	 * When CRYPTO_TIMING is defined at compile time and the 	 * sysctl debug.crypto is set to 1, the crypto system will 	 * accumulate statistics about how long it takes to process 	 * crypto requests at various points during processing. 	 */
name|struct
name|cryptotstat
name|cs_invoke
decl_stmt|;
comment|/* crypto_dipsatch -> crypto_invoke */
name|struct
name|cryptotstat
name|cs_done
decl_stmt|;
comment|/* crypto_invoke -> crypto_done */
name|struct
name|cryptotstat
name|cs_cb
decl_stmt|;
comment|/* crypto_done -> callback */
name|struct
name|cryptotstat
name|cs_finis
decl_stmt|;
comment|/* callback -> callback return */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Standard initialization structure beginning */
end_comment

begin_struct
struct|struct
name|cryptoini
block|{
name|int
name|cri_alg
decl_stmt|;
comment|/* Algorithm to use */
name|int
name|cri_klen
decl_stmt|;
comment|/* Key length, in bits */
name|int
name|cri_mlen
decl_stmt|;
comment|/* Number of bytes we want from the 					   entire hash. 0 means all. */
name|caddr_t
name|cri_key
decl_stmt|;
comment|/* key to use */
name|u_int8_t
name|cri_iv
index|[
name|EALG_MAX_BLOCK_LEN
index|]
decl_stmt|;
comment|/* IV to use */
name|struct
name|cryptoini
modifier|*
name|cri_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Describe boundaries of a single crypto operation */
end_comment

begin_struct
struct|struct
name|cryptodesc
block|{
name|int
name|crd_skip
decl_stmt|;
comment|/* How many bytes to ignore from start */
name|int
name|crd_len
decl_stmt|;
comment|/* How many bytes to process */
name|int
name|crd_inject
decl_stmt|;
comment|/* Where to inject results, if applicable */
name|int
name|crd_flags
decl_stmt|;
define|#
directive|define
name|CRD_F_ENCRYPT
value|0x01
comment|/* Set when doing encryption */
define|#
directive|define
name|CRD_F_IV_PRESENT
value|0x02
comment|/* When encrypting, IV is already in 					   place, so don't copy. */
define|#
directive|define
name|CRD_F_IV_EXPLICIT
value|0x04
comment|/* IV explicitly provided */
define|#
directive|define
name|CRD_F_DSA_SHA_NEEDED
value|0x08
comment|/* Compute SHA-1 of buffer for DSA */
define|#
directive|define
name|CRD_F_KEY_EXPLICIT
value|0x10
comment|/* Key explicitly provided */
define|#
directive|define
name|CRD_F_COMP
value|0x0f
comment|/* Set when doing compression */
name|struct
name|cryptoini
name|CRD_INI
decl_stmt|;
comment|/* Initialization/context data */
define|#
directive|define
name|crd_iv
value|CRD_INI.cri_iv
define|#
directive|define
name|crd_key
value|CRD_INI.cri_key
define|#
directive|define
name|crd_alg
value|CRD_INI.cri_alg
define|#
directive|define
name|crd_klen
value|CRD_INI.cri_klen
name|struct
name|cryptodesc
modifier|*
name|crd_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing complete operation */
end_comment

begin_struct
struct|struct
name|cryptop
block|{
name|TAILQ_ENTRY
argument_list|(
argument|cryptop
argument_list|)
name|crp_next
expr_stmt|;
name|u_int64_t
name|crp_sid
decl_stmt|;
comment|/* Session ID */
name|int
name|crp_ilen
decl_stmt|;
comment|/* Input data total length */
name|int
name|crp_olen
decl_stmt|;
comment|/* Result total length */
name|int
name|crp_etype
decl_stmt|;
comment|/* 					 * Error type (zero means no error). 					 * All error codes except EAGAIN 					 * indicate possible data corruption (as in, 					 * the data have been touched). On all 					 * errors, the crp_sid may have changed 					 * (reset to a new one), so the caller 					 * should always check and use the new 					 * value on future requests. 					 */
name|int
name|crp_flags
decl_stmt|;
define|#
directive|define
name|CRYPTO_F_IMBUF
value|0x0001
comment|/* Input/output are mbuf chains */
define|#
directive|define
name|CRYPTO_F_IOV
value|0x0002
comment|/* Input/output are uio */
define|#
directive|define
name|CRYPTO_F_REL
value|0x0004
comment|/* Must return data in same place */
define|#
directive|define
name|CRYPTO_F_BATCH
value|0x0008
comment|/* Batch op if possible */
define|#
directive|define
name|CRYPTO_F_CBIMM
value|0x0010
comment|/* Do callback immediately */
define|#
directive|define
name|CRYPTO_F_DONE
value|0x0020
comment|/* Operation completed */
define|#
directive|define
name|CRYPTO_F_CBIFSYNC
value|0x0040
comment|/* Do CBIMM if op is synchronous */
name|caddr_t
name|crp_buf
decl_stmt|;
comment|/* Data to be processed */
name|caddr_t
name|crp_opaque
decl_stmt|;
comment|/* Opaque pointer, passed along */
name|struct
name|cryptodesc
modifier|*
name|crp_desc
decl_stmt|;
comment|/* Linked list of processing descriptors */
name|int
function_decl|(
modifier|*
name|crp_callback
function_decl|)
parameter_list|(
name|struct
name|cryptop
modifier|*
parameter_list|)
function_decl|;
comment|/* Callback function */
name|struct
name|bintime
name|crp_tstamp
decl_stmt|;
comment|/* performance time stamp */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CRYPTO_BUF_CONTIG
value|0x0
end_define

begin_define
define|#
directive|define
name|CRYPTO_BUF_IOV
value|0x1
end_define

begin_define
define|#
directive|define
name|CRYPTO_BUF_MBUF
value|0x2
end_define

begin_define
define|#
directive|define
name|CRYPTO_OP_DECRYPT
value|0x0
end_define

begin_define
define|#
directive|define
name|CRYPTO_OP_ENCRYPT
value|0x1
end_define

begin_comment
comment|/*  * Hints passed to process methods.  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_HINT_MORE
value|0x1
end_define

begin_comment
comment|/* more ops coming shortly */
end_comment

begin_struct
struct|struct
name|cryptkop
block|{
name|TAILQ_ENTRY
argument_list|(
argument|cryptkop
argument_list|)
name|krp_next
expr_stmt|;
name|u_int
name|krp_op
decl_stmt|;
comment|/* ie. CRK_MOD_EXP or other */
name|u_int
name|krp_status
decl_stmt|;
comment|/* return status */
name|u_short
name|krp_iparams
decl_stmt|;
comment|/* # of input parameters */
name|u_short
name|krp_oparams
decl_stmt|;
comment|/* # of output parameters */
name|u_int
name|krp_crid
decl_stmt|;
comment|/* desired device, etc. */
name|u_int32_t
name|krp_hid
decl_stmt|;
name|struct
name|crparam
name|krp_param
index|[
name|CRK_MAXPARAM
index|]
decl_stmt|;
comment|/* kvm */
name|int
function_decl|(
modifier|*
name|krp_callback
function_decl|)
parameter_list|(
name|struct
name|cryptkop
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Session ids are 64 bits.  The lower 32 bits contain a "local id" which  * is a driver-private session identifier.  The upper 32 bits contain a  * "hardware id" used by the core crypto code to identify the driver and  * a copy of the driver's capabilities that can be used by client code to  * optimize operation.  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_SESID2HID
parameter_list|(
name|_sid
parameter_list|)
value|(((_sid)>> 32)& 0x00ffffff)
end_define

begin_define
define|#
directive|define
name|CRYPTO_SESID2CAPS
parameter_list|(
name|_sid
parameter_list|)
value|(((_sid)>> 32)& 0xff000000)
end_define

begin_define
define|#
directive|define
name|CRYPTO_SESID2LID
parameter_list|(
name|_sid
parameter_list|)
value|(((u_int32_t) (_sid))& 0xffffffff)
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CRYPTO_DATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|int
name|crypto_newsession
parameter_list|(
name|u_int64_t
modifier|*
name|sid
parameter_list|,
name|struct
name|cryptoini
modifier|*
name|cri
parameter_list|,
name|int
name|hard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_freesession
parameter_list|(
name|u_int64_t
name|sid
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CRYPTOCAP_F_HARDWARE
value|CRYPTO_FLAG_HARDWARE
end_define

begin_define
define|#
directive|define
name|CRYPTOCAP_F_SOFTWARE
value|CRYPTO_FLAG_SOFTWARE
end_define

begin_define
define|#
directive|define
name|CRYPTOCAP_F_SYNC
value|0x04000000
end_define

begin_comment
comment|/* operates synchronously */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|crypto_get_driverid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_find_driver
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|device_t
name|crypto_find_device_byhid
parameter_list|(
name|int
name|hid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_getcaps
parameter_list|(
name|int
name|hid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_register
parameter_list|(
name|u_int32_t
name|driverid
parameter_list|,
name|int
name|alg
parameter_list|,
name|u_int16_t
name|maxoplen
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_kregister
parameter_list|(
name|u_int32_t
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_unregister
parameter_list|(
name|u_int32_t
name|driverid
parameter_list|,
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_unregister_all
parameter_list|(
name|u_int32_t
name|driverid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_dispatch
parameter_list|(
name|struct
name|cryptop
modifier|*
name|crp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_kdispatch
parameter_list|(
name|struct
name|cryptkop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CRYPTO_SYMQ
value|0x1
end_define

begin_define
define|#
directive|define
name|CRYPTO_ASYMQ
value|0x2
end_define

begin_function_decl
specifier|extern
name|int
name|crypto_unblock
parameter_list|(
name|u_int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_done
parameter_list|(
name|struct
name|cryptop
modifier|*
name|crp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_kdone
parameter_list|(
name|struct
name|cryptkop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_getfeat
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_freereq
parameter_list|(
name|struct
name|cryptop
modifier|*
name|crp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cryptop
modifier|*
name|crypto_getreq
parameter_list|(
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|crypto_usercrypto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* userland may do crypto requests */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|crypto_userasymcrypto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* userland may do asym crypto reqs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|crypto_devallowsoft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only use hardware crypto */
end_comment

begin_comment
comment|/*  * Crypto-related utility routines used mainly by drivers.  *  * XXX these don't really belong here; but for now they're  *     kept apart from the rest of the system.  */
end_comment

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|cuio_copydata
parameter_list|(
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|len
parameter_list|,
name|caddr_t
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cuio_copyback
parameter_list|(
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|len
parameter_list|,
name|caddr_t
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|iovec
modifier|*
name|cuio_getptr
parameter_list|(
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|loc
parameter_list|,
name|int
modifier|*
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cuio_apply
parameter_list|(
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|len
parameter_list|,
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_copyback
parameter_list|(
name|int
name|flags
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|size
parameter_list|,
name|caddr_t
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_copydata
parameter_list|(
name|int
name|flags
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|size
parameter_list|,
name|caddr_t
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_apply
parameter_list|(
name|int
name|flags
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|len
parameter_list|,
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRYPTO_CRYPTO_H_ */
end_comment

end_unit

