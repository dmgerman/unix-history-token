begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: rijndael-api-fst.h,v 1.6 2001/05/27 00:23:23 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * rijndael-api-fst.h   v2.3   April '2000  *  * Optimised ANSI C code  *  * #define INTERMEDIATE_VALUE_KAT to generate the Intermediate Value Known Answer Test.  */
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
comment|/*  Defines: 	Add any additional defines you need */
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
comment|/*  Error Codes - CHANGE POSSIBLE: inclusion of additional error codes  */
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
comment|/*  CHANGE POSSIBLE:  inclusion of algorithm specific defines  */
end_comment

begin_define
define|#
directive|define
name|MAX_KEY_SIZE
value|64
end_define

begin_comment
comment|/* # of ASCII char's needed to represent a key */
end_comment

begin_define
define|#
directive|define
name|MAX_IV_SIZE
value|16
end_define

begin_comment
comment|/* # bytes needed to represent an IV  */
end_comment

begin_comment
comment|/*  Typedefs:  	Typedef'ed data storage elements.  Add any algorithm specific  parameters at the bottom of the structs as appropriate. */
end_comment

begin_comment
comment|/*  The structure for key information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
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
name|MAX_KEY_SIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Raw key data in ASCII, e.g., user input or KAT values */
comment|/*  The following parameters are algorithm dependent, replace or add as necessary  */
name|int
name|ROUNDS
decl_stmt|;
comment|/* key-length-dependent number of rounds */
name|int
name|blockLen
decl_stmt|;
comment|/* block length */
union|union
block|{
name|u_int8_t
name|xkS8
index|[
name|RIJNDAEL_MAXROUNDS
operator|+
literal|1
index|]
index|[
literal|4
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* key schedule		*/
name|u_int32_t
name|xkS32
index|[
name|RIJNDAEL_MAXROUNDS
operator|+
literal|1
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* key schedule		*/
block|}
name|xKeySched
union|;
define|#
directive|define
name|keySched
value|xKeySched.xkS8
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
name|u_int8_t
name|mode
decl_stmt|;
comment|/* MODE_ECB, MODE_CBC, or MODE_CFB1 */
name|u_int8_t
name|IV
index|[
name|MAX_IV_SIZE
index|]
decl_stmt|;
comment|/* A possible Initialization Vector for ciphering */
comment|/*  Add any algorithm specific parameters needed here  */
name|int
name|blockLen
decl_stmt|;
comment|/* Sample: Handles non-128 bit block sizes (if available) */
block|}
name|cipherInstance
typedef|;
end_typedef

begin_comment
comment|/*  Function prototypes  */
end_comment

begin_comment
comment|/*  CHANGED: nothing 	TODO: implement the following extensions to setup 192-bit and 256-bit block lengths:         makeKeyEx():    parameter blockLen added                         -- this parameter is absolutely necessary if you want to                         setup the round keys in a variable block length setting  	    cipherInitEx(): parameter blockLen added (for obvious reasons)		  */
end_comment

begin_function_decl
name|int
name|rijndael_makeKey
parameter_list|(
name|keyInstance
modifier|*
name|key
parameter_list|,
name|u_int8_t
name|direction
parameter_list|,
name|int
name|keyLen
parameter_list|,
name|char
modifier|*
name|keyMaterial
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_cipherInit
parameter_list|(
name|cipherInstance
modifier|*
name|cipher
parameter_list|,
name|u_int8_t
name|mode
parameter_list|,
name|char
modifier|*
name|IV
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_blockEncrypt
parameter_list|(
name|cipherInstance
modifier|*
name|cipher
parameter_list|,
name|keyInstance
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|input
parameter_list|,
name|int
name|inputLen
parameter_list|,
name|u_int8_t
modifier|*
name|outBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_padEncrypt
parameter_list|(
name|cipherInstance
modifier|*
name|cipher
parameter_list|,
name|keyInstance
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|input
parameter_list|,
name|int
name|inputOctets
parameter_list|,
name|u_int8_t
modifier|*
name|outBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_blockDecrypt
parameter_list|(
name|cipherInstance
modifier|*
name|cipher
parameter_list|,
name|keyInstance
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|input
parameter_list|,
name|int
name|inputLen
parameter_list|,
name|u_int8_t
modifier|*
name|outBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndael_padDecrypt
parameter_list|(
name|cipherInstance
modifier|*
name|cipher
parameter_list|,
name|keyInstance
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|input
parameter_list|,
name|int
name|inputOctets
parameter_list|,
name|u_int8_t
modifier|*
name|outBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INTERMEDIATE_VALUE_KAT
end_ifdef

begin_function_decl
name|int
name|rijndael_cipherUpdateRounds
parameter_list|(
name|cipherInstance
modifier|*
name|cipher
parameter_list|,
name|keyInstance
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|input
parameter_list|,
name|int
name|inputLen
parameter_list|,
name|u_int8_t
modifier|*
name|outBuffer
parameter_list|,
name|int
name|Rounds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTERMEDIATE_VALUE_KAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __RIJNDAEL_API_FST_H */
end_comment

end_unit

