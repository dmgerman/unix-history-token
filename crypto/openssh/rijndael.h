begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: rijndael.h,v 1.12 2001/12/19 07:18:56 deraadt Exp $ */
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
name|MAXKC
value|(256/32)
end_define

begin_define
define|#
directive|define
name|MAXKB
value|(256/8)
end_define

begin_define
define|#
directive|define
name|MAXNR
value|14
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
end_typedef

begin_comment
comment|/*  The structure for key information */
end_comment

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
name|u32
name|ek
index|[
literal|4
operator|*
operator|(
name|MAXNR
operator|+
literal|1
operator|)
index|]
decl_stmt|;
comment|/* encrypt key schedule */
name|u32
name|dk
index|[
literal|4
operator|*
operator|(
name|MAXNR
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
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rijndael_decrypt
parameter_list|(
name|rijndael_ctx
modifier|*
parameter_list|,
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
name|rijndael_ctx
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
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

