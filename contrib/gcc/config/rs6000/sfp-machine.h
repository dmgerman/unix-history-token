begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|_FP_W_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|_FP_W_TYPE
value|unsigned long
end_define

begin_define
define|#
directive|define
name|_FP_WS_TYPE
value|signed long
end_define

begin_define
define|#
directive|define
name|_FP_I_TYPE
value|long
end_define

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|_FP_MUL_MEAT_1_wide(_FP_WFRACBITS_S,R,X,Y,umul_ppmm)
end_define

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|_FP_MUL_MEAT_2_wide(_FP_WFRACBITS_D,R,X,Y,umul_ppmm)
end_define

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|_FP_MUL_MEAT_4_wide(_FP_WFRACBITS_Q,R,X,Y,umul_ppmm)
end_define

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV_MEAT_1_loop(S,R,X,Y)
end_define

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV_MEAT_2_udiv(D,R,X,Y)
end_define

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV_MEAT_4_udiv(Q,R,X,Y)
end_define

begin_define
define|#
directive|define
name|_FP_NANFRAC_S
value|((_FP_QNANBIT_S<< 1) - 1)
end_define

begin_define
define|#
directive|define
name|_FP_NANFRAC_D
value|((_FP_QNANBIT_D<< 1) - 1), -1
end_define

begin_define
define|#
directive|define
name|_FP_NANFRAC_Q
value|((_FP_QNANBIT_Q<< 1) - 1), -1, -1, -1
end_define

begin_define
define|#
directive|define
name|_FP_NANSIGN_S
value|0
end_define

begin_define
define|#
directive|define
name|_FP_NANSIGN_D
value|0
end_define

begin_define
define|#
directive|define
name|_FP_NANSIGN_Q
value|0
end_define

begin_define
define|#
directive|define
name|_FP_KEEPNANFRACP
value|1
end_define

begin_comment
comment|/* Someone please check this.  */
end_comment

begin_define
define|#
directive|define
name|_FP_CHOOSENAN
parameter_list|(
name|fs
parameter_list|,
name|wc
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|OP
parameter_list|)
define|\
value|do {								\     if ((_FP_FRAC_HIGH_RAW_##fs(X)& _FP_QNANBIT_##fs)		\&& !(_FP_FRAC_HIGH_RAW_##fs(Y)& _FP_QNANBIT_##fs))	\       {								\ 	R##_s = Y##_s;						\ 	_FP_FRAC_COPY_##wc(R,Y);				\       }								\     else							\       {								\ 	R##_s = X##_s;						\ 	_FP_FRAC_COPY_##wc(R,X);				\       }								\     R##_c = FP_CLS_NAN;						\   } while (0)
end_define

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|4321
end_define

begin_if
if|#
directive|if
name|defined
name|__BIG_ENDIAN__
operator|||
name|defined
name|_BIG_ENDIAN
end_if

begin_if
if|#
directive|if
name|defined
name|__LITTLE_ENDIAN__
operator|||
name|defined
name|_LITTLE_ENDIAN
end_if

begin_error
error|#
directive|error
literal|"Both BIG_ENDIAN and LITTLE_ENDIAN defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|__LITTLE_ENDIAN__
operator|||
name|defined
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Cannot determine current byte order"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define ALIASNAME as a strong alias for NAME.  */
end_comment

begin_define
define|#
directive|define
name|strong_alias
parameter_list|(
name|name
parameter_list|,
name|aliasname
parameter_list|)
value|_strong_alias(name, aliasname)
end_define

begin_define
define|#
directive|define
name|_strong_alias
parameter_list|(
name|name
parameter_list|,
name|aliasname
parameter_list|)
define|\
value|extern __typeof (name) aliasname __attribute__ ((alias (#name)));
end_define

end_unit

