begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rijndael.h,v 1.6 2003/08/28 08:36:32 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/**  * rijndael-alg-fst.h  *  * @version 3.0 (December 2000)  *  * Optimised ANSI C code for the Rijndael cipher (now AES)  *  * @author Vincent Rijmen<vincent.rijmen@esat.kuleuven.ac.be>  * @author Antoon Bosselaers<antoon.bosselaers@esat.kuleuven.ac.be>  * @author Paulo Barreto<paulo.barreto@terra.com.br>  *  * This code is hereby placed in the public domain.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RIJNDAEL_H
end_ifndef

begin_define
define|#
directive|define
name|__RIJNDAEL_H
end_define

begin_define
define|#
directive|define
name|RIJNDAEL_MAXKC
value|(256/32)
end_define

begin_define
define|#
directive|define
name|RIJNDAEL_MAXKB
value|(256/8)
end_define

begin_define
define|#
directive|define
name|RIJNDAEL_MAXNR
value|14
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|decrypt
decl_stmt|;
name|int
name|Nr
decl_stmt|;
comment|/* key-length-dependent number of rounds */
name|uint32_t
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
comment|/* encrypt key schedule */
name|uint32_t
name|dk
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
comment|/* decrypt key schedule */
block|}
name|rijndael_ctx
typedef|;
end_typedef

begin_function_decl
name|void
name|rijndael_set_key
parameter_list|(
name|rijndael_ctx
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rijndael_decrypt
parameter_list|(
specifier|const
name|rijndael_ctx
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rijndael_encrypt
parameter_list|(
specifier|const
name|rijndael_ctx
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndaelKeySetupEnc
parameter_list|(
name|u_int32_t
index|[
comment|/*4*(Nr+1)*/
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndaelKeySetupDec
parameter_list|(
name|u_int32_t
index|[
comment|/*4*(Nr+1)*/
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rijndaelEncrypt
parameter_list|(
specifier|const
name|u_int32_t
index|[
comment|/*4*(Nr+1)*/
index|]
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_int8_t
index|[
literal|16
index|]
parameter_list|,
name|u_int8_t
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rijndaelDecrypt
parameter_list|(
specifier|const
name|u_int32_t
index|[
comment|/*4*(Nr+1)*/
index|]
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_int8_t
index|[
literal|16
index|]
parameter_list|,
name|u_int8_t
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RIJNDAEL_H */
end_comment

end_unit

