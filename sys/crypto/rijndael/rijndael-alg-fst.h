begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: rijndael-alg-fst.h,v 1.4 2000/10/02 17:14:26 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * rijndael-alg-fst.h   v2.3   April '2000  *  * Optimised ANSI C code  *  * #define INTERMEDIATE_VALUE_KAT to generate the Intermediate Value Known Answer Test.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RIJNDAEL_ALG_FST_H
end_ifndef

begin_define
define|#
directive|define
name|__RIJNDAEL_ALG_FST_H
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
name|RIJNDAEL_MAXROUNDS
value|14
end_define

begin_function_decl
name|int
name|rijndaelKeySched
parameter_list|(
name|u_int8_t
name|k
index|[
name|RIJNDAEL_MAXKC
index|]
index|[
literal|4
index|]
parameter_list|,
name|u_int8_t
name|rk
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
parameter_list|,
name|int
name|ROUNDS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndaelKeyEncToDec
parameter_list|(
name|u_int8_t
name|W
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
parameter_list|,
name|int
name|ROUNDS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rijndaelEncrypt
parameter_list|(
name|u_int8_t
name|a
index|[
literal|16
index|]
parameter_list|,
name|u_int8_t
name|b
index|[
literal|16
index|]
parameter_list|,
name|u_int8_t
name|rk
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
parameter_list|,
name|int
name|ROUNDS
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
name|rijndaelEncryptRound
parameter_list|(
name|u_int8_t
name|a
index|[
literal|4
index|]
index|[
literal|4
index|]
parameter_list|,
name|u_int8_t
name|rk
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
parameter_list|,
name|int
name|ROUNDS
parameter_list|,
name|int
name|rounds
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

begin_function_decl
name|int
name|rijndaelDecrypt
parameter_list|(
name|u_int8_t
name|a
index|[
literal|16
index|]
parameter_list|,
name|u_int8_t
name|b
index|[
literal|16
index|]
parameter_list|,
name|u_int8_t
name|rk
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
parameter_list|,
name|int
name|ROUNDS
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
name|rijndaelDecryptRound
parameter_list|(
name|u_int8_t
name|a
index|[
literal|4
index|]
index|[
literal|4
index|]
parameter_list|,
name|u_int8_t
name|rk
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
parameter_list|,
name|int
name|ROUNDS
parameter_list|,
name|int
name|rounds
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
comment|/* __RIJNDAEL_ALG_FST_H */
end_comment

end_unit

