begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * Written by Corinne Dive-Reclus(cdive@baltimore.com) * * Copyright@2001 Baltimore Technologies Ltd. *																								*	 *		THIS FILE IS PROVIDED BY BALTIMORE TECHNOLOGIES ``AS IS'' AND																			* *		ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE					*  *		IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE				* *		ARE DISCLAIMED.  IN NO EVENT SHALL BALTIMORE TECHNOLOGIES BE LIABLE						* *		FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL				* *		DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS					* *		OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)					* *		HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT				* *		LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY				* *		OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF					* *		SUCH DAMAGE.																			* * *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|SW_EXPORT
value|__declspec ( dllexport )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SW_EXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *	List of exposed SureWare errors */
end_comment

begin_define
define|#
directive|define
name|SUREWAREHOOK_ERROR_FAILED
value|-1
end_define

begin_define
define|#
directive|define
name|SUREWAREHOOK_ERROR_FALLBACK
value|-2
end_define

begin_define
define|#
directive|define
name|SUREWAREHOOK_ERROR_UNIT_FAILURE
value|-3
end_define

begin_define
define|#
directive|define
name|SUREWAREHOOK_ERROR_DATA_SIZE
value|-4
end_define

begin_define
define|#
directive|define
name|SUREWAREHOOK_ERROR_INVALID_PAD
value|-5
end_define

begin_comment
comment|/* * -----------------WARNING----------------------------------- * In all the following functions: * msg is a string with at least 24 bytes free. * A 24 bytes string will be concatenated to the existing content of msg.  */
end_comment

begin_comment
comment|/* *	SureWare Initialisation function *	in param threadsafe, if !=0, thread safe enabled *	return SureWareHOOK_ERROR_UNIT_FAILURE if failure, 1 if success */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Init_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
name|int
name|threadsafe
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Init_t
name|SureWareHook_Init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare Finish function */
end_comment

begin_typedef
typedef|typedef
name|void
name|SureWareHook_Finish_t
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Finish_t
name|SureWareHook_Finish
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	 PRE_CONDITION: *		DO NOT CALL ANY OF THE FOLLOWING FUNCTIONS IN CASE OF INIT FAILURE */
end_comment

begin_comment
comment|/* *	SureWare RAND Bytes function *	In case of failure, the content of buf is unpredictable. *	return 1 if success *			SureWareHOOK_ERROR_FALLBACK if function not available in hardware *			SureWareHOOK_ERROR_FAILED if error while processing *			SureWareHOOK_ERROR_UNIT_FAILURE if hardware failure *			SUREWAREHOOK_ERROR_DATA_SIZE wrong size for buf * *	in/out param buf : a num bytes long buffer where random bytes will be put *	in param num : the number of bytes into buf */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Rand_Bytes_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Rand_Bytes_t
name|SureWareHook_Rand_Bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare RAND Seed function *	Adds some seed to the Hardware Random Number Generator *	return 1 if success *			SureWareHOOK_ERROR_FALLBACK if function not available in hardware *			SureWareHOOK_ERROR_FAILED if error while processing *			SureWareHOOK_ERROR_UNIT_FAILURE if hardware failure *			SUREWAREHOOK_ERROR_DATA_SIZE wrong size for buf * *	in param buf : the seed to add into the HRNG *	in param num : the number of bytes into buf */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Rand_Seed_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Rand_Seed_t
name|SureWareHook_Rand_Seed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare Load Private Key function *	return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *	No hardware is contact for this function. * *	in param key_id :the name of the private protected key file without the extension 						".sws" *	out param hptr : a pointer to a buffer allocated by SureWare_Hook *	out param num: the effective key length in bytes *	out param keytype: 1 if RSA 2 if DSA */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Load_Privkey_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|key_id
parameter_list|,
name|char
modifier|*
modifier|*
name|hptr
parameter_list|,
name|unsigned
name|long
modifier|*
name|num
parameter_list|,
name|char
modifier|*
name|keytype
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Load_Privkey_t
name|SureWareHook_Load_Privkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare Info Public Key function *	return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *	No hardware is contact for this function. * *	in param key_id :the name of the private protected key file without the extension 						".swp" *	out param hptr : a pointer to a buffer allocated by SureWare_Hook *	out param num: the effective key length in bytes *	out param keytype: 1 if RSA 2 if DSA */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Info_Pubkey_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|key_id
parameter_list|,
name|unsigned
name|long
modifier|*
name|num
parameter_list|,
name|char
modifier|*
name|keytype
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Info_Pubkey_t
name|SureWareHook_Info_Pubkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare Load Public Key function *	return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *	No hardware is contact for this function. * *	in param key_id :the name of the public protected key file without the extension 						".swp" *	in param num : the bytes size of n and e *	out param n: where to write modulus in bn format *	out param e: where to write exponent in bn format */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Load_Rsa_Pubkey_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|key_id
parameter_list|,
name|unsigned
name|long
name|num
parameter_list|,
name|unsigned
name|long
modifier|*
name|n
parameter_list|,
name|unsigned
name|long
modifier|*
name|e
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Load_Rsa_Pubkey_t
name|SureWareHook_Load_Rsa_Pubkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare Load DSA Public Key function *	return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *	No hardware is contact for this function. * *	in param key_id :the name of the public protected key file without the extension 						".swp" *	in param num : the bytes size of n and e *	out param pub: where to write pub key in bn format *	out param p: where to write prime in bn format *	out param q: where to write sunprime (length 20 bytes) in bn format *	out param g: where to write base in bn format */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Load_Dsa_Pubkey_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|key_id
parameter_list|,
name|unsigned
name|long
name|num
parameter_list|,
name|unsigned
name|long
modifier|*
name|pub
parameter_list|,
name|unsigned
name|long
modifier|*
name|p
parameter_list|,
name|unsigned
name|long
modifier|*
name|q
parameter_list|,
name|unsigned
name|long
modifier|*
name|g
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Load_Dsa_Pubkey_t
name|SureWareHook_Load_Dsa_Pubkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *	SureWare Free function *	Destroy the key into the hardware if destroy==1 */
end_comment

begin_typedef
typedef|typedef
name|void
name|SureWareHook_Free_t
parameter_list|(
name|char
modifier|*
name|p
parameter_list|,
name|int
name|destroy
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Free_t
name|SureWareHook_Free
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SUREWARE_PKCS1_PAD
value|1
end_define

begin_define
define|#
directive|define
name|SUREWARE_ISO9796_PAD
value|2
end_define

begin_define
define|#
directive|define
name|SUREWARE_NO_PAD
value|0
end_define

begin_comment
comment|/* * SureWare RSA Private Decryption * return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *			SureWareHOOK_ERROR_UNIT_FAILURE if hardware failure *			SUREWAREHOOK_ERROR_DATA_SIZE wrong size for buf * *	in param flen : byte size of from and to *	in param from : encrypted data buffer, should be a not-null valid pointer *	out param tlen: byte size of decrypted data, if error, unexpected value *	out param to : decrypted data buffer, should be a not-null valid pointer *   in param prsa: a protected key pointer, should be a not-null valid pointer *   int padding: padding id as follow *					SUREWARE_PKCS1_PAD *					SUREWARE_NO_PAD * */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Rsa_Priv_Dec_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
name|int
name|flen
parameter_list|,
name|unsigned
name|char
modifier|*
name|from
parameter_list|,
name|int
modifier|*
name|tlen
parameter_list|,
name|unsigned
name|char
modifier|*
name|to
parameter_list|,
name|char
modifier|*
name|prsa
parameter_list|,
name|int
name|padding
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Rsa_Priv_Dec_t
name|SureWareHook_Rsa_Priv_Dec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * SureWare RSA Signature * return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *			SureWareHOOK_ERROR_UNIT_FAILURE if hardware failure *			SUREWAREHOOK_ERROR_DATA_SIZE wrong size for buf * *	in param flen : byte size of from and to *	in param from : encrypted data buffer, should be a not-null valid pointer *	out param tlen: byte size of decrypted data, if error, unexpected value *	out param to : decrypted data buffer, should be a not-null valid pointer *   in param prsa: a protected key pointer, should be a not-null valid pointer *   int padding: padding id as follow *					SUREWARE_PKCS1_PAD *					SUREWARE_ISO9796_PAD * */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Rsa_Sign_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
name|int
name|flen
parameter_list|,
name|unsigned
name|char
modifier|*
name|from
parameter_list|,
name|int
modifier|*
name|tlen
parameter_list|,
name|unsigned
name|char
modifier|*
name|to
parameter_list|,
name|char
modifier|*
name|prsa
parameter_list|,
name|int
name|padding
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Rsa_Sign_t
name|SureWareHook_Rsa_Sign
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * SureWare DSA Signature * return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *			SureWareHOOK_ERROR_UNIT_FAILURE if hardware failure *			SUREWAREHOOK_ERROR_DATA_SIZE wrong size for buf * *	in param flen : byte size of from and to *	in param from : encrypted data buffer, should be a not-null valid pointer *	out param to : decrypted data buffer, should be a 40bytes valid pointer *   in param pdsa: a protected key pointer, should be a not-null valid pointer * */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Dsa_Sign_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
name|int
name|flen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|from
parameter_list|,
name|unsigned
name|long
modifier|*
name|r
parameter_list|,
name|unsigned
name|long
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|pdsa
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Dsa_Sign_t
name|SureWareHook_Dsa_Sign
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * SureWare Mod Exp * return 1 if success *			SureWareHOOK_ERROR_FAILED if error while processing *			SureWareHOOK_ERROR_UNIT_FAILURE if hardware failure *			SUREWAREHOOK_ERROR_DATA_SIZE wrong size for buf * *	mod and res are mlen bytes long. *	exp is elen bytes long *	data is dlen bytes long *	mlen,elen and dlen are all multiple of sizeof(unsigned long) */
end_comment

begin_typedef
typedef|typedef
name|int
name|SureWareHook_Mod_Exp_t
parameter_list|(
name|char
modifier|*
specifier|const
name|msg
parameter_list|,
name|int
name|mlen
parameter_list|,
specifier|const
name|unsigned
name|long
modifier|*
name|mod
parameter_list|,
name|int
name|elen
parameter_list|,
specifier|const
name|unsigned
name|long
modifier|*
name|exp
parameter_list|,
name|int
name|dlen
parameter_list|,
name|unsigned
name|long
modifier|*
name|data
parameter_list|,
name|unsigned
name|long
modifier|*
name|res
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|SW_EXPORT
name|SureWareHook_Mod_Exp_t
name|SureWareHook_Mod_Exp
decl_stmt|;
end_decl_stmt

end_unit

