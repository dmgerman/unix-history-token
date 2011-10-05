begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|LTM1
argument_list|)
operator|&&
name|defined
argument_list|(
name|LTM2
argument_list|)
operator|&&
name|defined
argument_list|(
name|LTM3
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LTM2
argument_list|)
end_if

begin_define
define|#
directive|define
name|LTM3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LTM1
argument_list|)
end_if

begin_define
define|#
directive|define
name|LTM2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LTM1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LTM_ALL
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_ERROR_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_MP_INVMOD_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_MP_MONTGOMERY_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_S_MP_MUL_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_S_MP_MUL_HIGH_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_S_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_2EXPT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ABS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADDMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_AND_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CNT_LSB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_3_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DR_IS_MODULUS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DR_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DR_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPT_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPTMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPTMOD_FAST_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXTEUCLID_C
end_define

begin_define
define|#
directive|define
name|BN_MP_FREAD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_FWRITE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GCD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GET_INT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SET_INT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INVMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INVMOD_SLOW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_IS_SQUARE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_JACOBI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_KARATSUBA_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_KARATSUBA_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LCM_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MONTGOMERY_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MONTGOMERY_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MULMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_N_ROOT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_NEG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_OR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_FERMAT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_IS_DIVISIBLE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_IS_PRIME_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_MILLER_RABIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_NEXT_PRIME_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_RABIN_MILLER_TRIALS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_RANDOM_EX_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RADIX_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RADIX_SMAP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RAND_C
end_define

begin_define
define|#
directive|define
name|BN_MP_READ_RADIX_C
end_define

begin_define
define|#
directive|define
name|BN_MP_READ_SIGNED_BIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_READ_UNSIGNED_BIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_L_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_SETUP_L_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_IS_2K_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_IS_2K_L_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_INT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SHRINK_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SIGNED_BIN_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQRMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQRT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUBMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TO_SIGNED_BIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TO_SIGNED_BIN_N_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TO_UNSIGNED_BIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TO_UNSIGNED_BIN_N_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TOOM_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TOOM_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TORADIX_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TORADIX_N_C
end_define

begin_define
define|#
directive|define
name|BN_MP_UNSIGNED_BIN_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_XOR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_PRIME_TAB_C
end_define

begin_define
define|#
directive|define
name|BN_REVERSE_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_EXPTMOD_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_MUL_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_MUL_HIGH_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BNCORE_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_ERROR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ERROR_TO_STRING_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_FAST_MP_INVMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISEVEN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISODD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_FAST_MP_MONTGOMERY_REDUCE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_FAST_S_MP_MUL_DIGS_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_FAST_S_MP_MUL_HIGH_DIGS_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_FAST_S_MP_SQR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_2EXPT_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_ABS_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_ADD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_S_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_ADD_D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_ADDMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_AND_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CLAMP_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CLEAR_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CLEAR_MULTI_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CMP_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CMP_D_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CMP_MAG_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_CNT_LSB_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_COPY_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_COUNT_BITS_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DIV_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ABS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DIV_2_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DIV_2D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DIV_3_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DIV_D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_3_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DR_IS_MODULUS_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DR_REDUCE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_DR_SETUP_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_EXCH_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_EXPT_D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_EXPTMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INVMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ABS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_IS_2K_L_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_EXPTMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DR_IS_MODULUS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_IS_2K_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISODD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPTMOD_FAST_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_EXPTMOD_FAST_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MONTGOMERY_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_MP_MONTGOMERY_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MONTGOMERY_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DR_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DR_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MULMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_EXTEUCLID_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_NEG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_FREAD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_S_RMAP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_FWRITE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_RADIX_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TORADIX_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_GCD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ABS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CNT_LSB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_GET_INT_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_GROW_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INIT_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INIT_COPY_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INIT_MULTI_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ERR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INIT_SET_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INIT_SET_INT_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_INT_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INIT_SIZE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INVMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISODD_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_MP_INVMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INVMOD_SLOW_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_INVMOD_SLOW_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISEVEN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISODD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_IS_SQUARE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_MOD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SET_INT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GET_INT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQRT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_JACOBI_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CNT_LSB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_KARATSUBA_MUL_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_KARATSUBA_SQR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_LCM_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GCD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_LSHD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MOD_2D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MOD_D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_DIV_D_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_2EXPT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MONTGOMERY_REDUCE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_FAST_MP_MONTGOMERY_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MONTGOMERY_SETUP_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MUL_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_TOOM_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_KARATSUBA_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_S_MP_MUL_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_MUL_DIGS_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MUL_2_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MUL_2D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MUL_D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_MULMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_N_ROOT_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPT_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_NEG_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_OR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_FERMAT_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPTMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_IS_DIVISIBLE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_MOD_D_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_IS_PRIME_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_IS_DIVISIBLE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_MILLER_RABIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_MILLER_RABIN_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CNT_LSB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPTMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQRMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_NEXT_PRIME_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISEVEN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_MILLER_RABIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_RABIN_MILLER_TRIALS_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_PRIME_RANDOM_EX_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_READ_UNSIGNED_BIN_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_IS_PRIME_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_RADIX_SIZE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_RADIX_SMAP_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_S_RMAP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_RAND_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_READ_RADIX_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_S_RMAP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RADIX_SMAP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_READ_SIGNED_BIN_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_READ_UNSIGNED_BIN_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_READ_UNSIGNED_BIN_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_REDUCE_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_MUL_HIGH_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_S_MP_MUL_HIGH_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_2D_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_MUL_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_2K_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_2K_L_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_2K_SETUP_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_2EXPT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_2K_SETUP_L_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_2EXPT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_IS_2K_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_IS_2K_L_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_REDUCE_SETUP_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_2EXPT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_RSHD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SET_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SET_INT_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SHRINK_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SIGNED_BIN_SIZE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_UNSIGNED_BIN_SIZE_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SQR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_TOOM_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_KARATSUBA_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_FAST_S_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SQR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SQRMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SQRT_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_N_ROOT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SUB_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_S_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CMP_MAG_C
end_define

begin_define
define|#
directive|define
name|BN_S_MP_SUB_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SUB_D_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_SUBMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TO_SIGNED_BIN_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_TO_UNSIGNED_BIN_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TO_SIGNED_BIN_N_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_SIGNED_BIN_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TO_SIGNED_BIN_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TO_UNSIGNED_BIN_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TO_UNSIGNED_BIN_N_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_UNSIGNED_BIN_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_TO_UNSIGNED_BIN_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TOOM_MUL_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_3_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TOOM_SQR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_RSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SUB_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_2_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_2D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_3_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LSHD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TORADIX_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_S_RMAP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_TORADIX_N_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_ISZERO_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_DIV_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_S_RMAP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_UNSIGNED_BIN_SIZE_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_XOR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_MP_ZERO_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_PRIME_TAB_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_REVERSE_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_S_MP_ADD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_S_MP_EXPTMOD_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_COUNT_BITS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_SETUP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_SETUP_L_C
end_define

begin_define
define|#
directive|define
name|BN_MP_REDUCE_2K_L_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_COPY_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SQR_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MUL_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_S_MP_MUL_DIGS_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_FAST_S_MP_MUL_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_S_MP_MUL_HIGH_DIGS_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_FAST_S_MP_MUL_HIGH_DIGS_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_S_MP_SQR_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_INIT_SIZE_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXCH_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BN_S_MP_SUB_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|BN_MP_GROW_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLAMP_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BNCORE_C
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LTM3
end_ifdef

begin_define
define|#
directive|define
name|LTM_LAST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tommath_superclass.h>
end_include

begin_include
include|#
directive|include
file|<tommath_class.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LTM_LAST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/tommath_class.h,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.3 $ */
end_comment

begin_comment
comment|/* $Date: 2005/07/28 11:59:32 $ */
end_comment

end_unit

