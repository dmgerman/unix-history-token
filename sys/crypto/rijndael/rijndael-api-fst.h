begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NetBSD: rijndael-api-fst.h,v 1.5 2003/07/16 05:08:09 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$KAME: rijndael-api-fst.h,v 1.9 2003/07/16 05:09:38 itojun Exp $	*/
end_comment

begin_comment
comment|/**  * rijndael-api-fst.h  *  * @version 2.9 (December 2000)  *  * Optimised ANSI C code for the Rijndael cipher (now AES)  *  * @author Vincent Rijmen<vincent.rijmen@esat.kuleuven.ac.be>  * @author Antoon Bosselaers<antoon.bosselaers@esat.kuleuven.ac.be>  * @author Paulo Barreto<paulo.barreto@terra.com.br>  *  * This code is hereby placed in the public domain.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Acknowledgements:  *  * We are deeply indebted to the following people for their bug reports,  * fixes, and improvement suggestions to this implementation. Though we  * tried to list all contributions, we apologise in advance for any  * missing reference.  *  * Andrew Bales<Andrew.Bales@Honeywell.com>  * Markus Friedl<markus.friedl@informatik.uni-erlangen.de>  * John Skodon<skodonj@webquill.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RIJNDAEL_API_FST_H
end_ifndef

begin_define
define|#
directive|define
name|__RIJNDAEL_API_FST_H
end_define

begin_include
include|#
directive|include
file|<crypto/rijndael/rijndael-alg-fst.h>
end_include

begin_comment
comment|/*  Generic Defines  */
end_comment

begin_define
define|#
directive|define
name|DIR_ENCRYPT
value|0
end_define

begin_comment
comment|/*  Are we encrpyting?  */
end_comment

begin_define
define|#
directive|define
name|DIR_DECRYPT
value|1
end_define

begin_comment
comment|/*  Are we decrpyting?  */
end_comment

begin_define
define|#
directive|define
name|MODE_ECB
value|1
end_define

begin_comment
comment|/*  Are we ciphering in ECB mode?   */
end_comment

begin_define
define|#
directive|define
name|MODE_CBC
value|2
end_define

begin_comment
comment|/*  Are we ciphering in CBC mode?   */
end_comment

begin_define
define|#
directive|define
name|MODE_CFB1
value|3
end_define

begin_comment
comment|/*  Are we ciphering in 1-bit CFB mode? */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|BITSPERBLOCK
value|128
end_define

begin_comment
comment|/* Default number of bits in a cipher block */
end_comment

begin_comment
comment|/*  Error Codes  */
end_comment

begin_define
define|#
directive|define
name|BAD_KEY_DIR
value|-1
end_define

begin_comment
comment|/*  Key direction is invalid, e.g., unknown value */
end_comment

begin_define
define|#
directive|define
name|BAD_KEY_MAT
value|-2
end_define

begin_comment
comment|/*  Key material not of correct length */
end_comment

begin_define
define|#
directive|define
name|BAD_KEY_INSTANCE
value|-3
end_define

begin_comment
comment|/*  Key passed is not valid */
end_comment

begin_define
define|#
directive|define
name|BAD_CIPHER_MODE
value|-4
end_define

begin_comment
comment|/*  Params struct passed to cipherInit invalid */
end_comment

begin_define
define|#
directive|define
name|BAD_CIPHER_STATE
value|-5
end_define

begin_comment
comment|/*  Cipher in wrong state (e.g., not initialized) */
end_comment

begin_define
define|#
directive|define
name|BAD_BLOCK_LENGTH
value|-6
end_define

begin_define
define|#
directive|define
name|BAD_CIPHER_INSTANCE
value|-7
end_define

begin_define
define|#
directive|define
name|BAD_DATA
value|-8
end_define

begin_comment
comment|/*  Data contents are invalid, e.g., invalid padding */
end_comment

begin_define
define|#
directive|define
name|BAD_OTHER
value|-9
end_define

begin_comment
comment|/*  Unknown error */
end_comment

begin_comment
comment|/*  Algorithm-specific Defines  */
end_comment

begin_define
define|#
directive|define
name|RIJNDAEL_MAX_KEY_SIZE
value|64
end_define

begin_comment
comment|/* # of ASCII char's needed to represent a key */
end_comment

begin_define
define|#
directive|define
name|RIJNDAEL_MAX_IV_SIZE
value|16
end_define

begin_comment
comment|/* # bytes needed to represent an IV  */
end_comment

begin_comment
comment|/*  Typedefs  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_comment
comment|/*  The structure for key information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|direction
decl_stmt|;
comment|/* Key used for encrypting or decrypting? */
name|int
name|keyLen
decl_stmt|;
comment|/* Length of the key  */
name|char
name|keyMaterial
index|[
name|RIJNDAEL_MAX_KEY_SIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Raw key data in ASCII, e.g., user input or KAT values */
name|int
name|Nr
decl_stmt|;
comment|/* key-length-dependent number of rounds */
name|u_int32_t
name|rk
index|[
literal|4
operator|*
operator|(
name|RIJNDAEL_MAXNR
operator|+
literal|1
operator|)
index|]
decl_stmt|;
comment|/* key schedule */
name|u_int32_t
name|ek
index|[
literal|4
operator|*
operator|(
name|RIJNDAEL_MAXNR
operator|+
literal|1
operator|)
index|]
decl_stmt|;
comment|/* CFB1 key schedule (encryption only) */
block|}
name|keyInstance
typedef|;
end_typedef

begin_comment
comment|/*  The structure for cipher information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* changed order of the components */
name|BYTE
name|mode
decl_stmt|;
comment|/* MODE_ECB, MODE_CBC, or MODE_CFB1 */
name|BYTE
name|IV
index|[
name|RIJNDAEL_MAX_IV_SIZE
index|]
decl_stmt|;
comment|/* A possible Initialization Vector for ciphering */
block|}
name|cipherInstance
typedef|;
end_typedef

begin_comment
comment|/*  Function prototypes  */
end_comment

begin_function_decl
name|int
name|rijndael_makeKey
parameter_list|(
name|keyInstance
modifier|*
parameter_list|,
name|BYTE
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_cipherInit
parameter_list|(
name|cipherInstance
modifier|*
parameter_list|,
name|BYTE
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_blockEncrypt
parameter_list|(
name|cipherInstance
modifier|*
parameter_list|,
name|keyInstance
modifier|*
parameter_list|,
name|BYTE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BYTE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_padEncrypt
parameter_list|(
name|cipherInstance
modifier|*
parameter_list|,
name|keyInstance
modifier|*
parameter_list|,
name|BYTE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BYTE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_blockDecrypt
parameter_list|(
name|cipherInstance
modifier|*
parameter_list|,
name|keyInstance
modifier|*
parameter_list|,
name|BYTE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BYTE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_padDecrypt
parameter_list|(
name|cipherInstance
modifier|*
parameter_list|,
name|keyInstance
modifier|*
parameter_list|,
name|BYTE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BYTE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RIJNDAEL_API_FST_H */
end_comment

end_unit

