begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* super class file for PK algos */
end_comment

begin_comment
comment|/* default ... include all MPI */
end_comment

begin_define
define|#
directive|define
name|LTM_ALL
end_define

begin_comment
comment|/* RSA only (does not support DH/DSA/ECC) */
end_comment

begin_comment
comment|/* #define SC_RSA_1 */
end_comment

begin_comment
comment|/* For reference.... On an Athlon64 optimizing for speed...     LTM's mpi.o with all functions [striped] is 142KiB in size.  */
end_comment

begin_comment
comment|/* Works for RSA only, mpi.o is 68KiB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SC_RSA_1
end_ifdef

begin_define
define|#
directive|define
name|BN_MP_SHRINK_C
end_define

begin_define
define|#
directive|define
name|BN_MP_LCM_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_RANDOM_EX_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INVMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_GCD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_MULMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_ADDMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_EXPTMOD_C
end_define

begin_define
define|#
directive|define
name|BN_MP_SET_INT_C
end_define

begin_define
define|#
directive|define
name|BN_MP_INIT_MULTI_C
end_define

begin_define
define|#
directive|define
name|BN_MP_CLEAR_MULTI_C
end_define

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

begin_define
define|#
directive|define
name|BN_MP_MOD_D_C
end_define

begin_define
define|#
directive|define
name|BN_MP_PRIME_RABIN_MILLER_TRIALS_C
end_define

begin_define
define|#
directive|define
name|BN_REVERSE_C
end_define

begin_define
define|#
directive|define
name|BN_PRIME_TAB_C
end_define

begin_comment
comment|/* other modifiers */
end_comment

begin_define
define|#
directive|define
name|BN_MP_DIV_SMALL
end_define

begin_comment
comment|/* Slower division, not critical */
end_comment

begin_comment
comment|/* here we are on the last pass so we turn things off.  The functions classes are still there     * but we remove them specifically from the build.  This also invokes tweaks in functions     * like removing support for even moduli, etc...     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LTM_LAST
end_ifdef

begin_undef
undef|#
directive|undef
name|BN_MP_TOOM_MUL_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_TOOM_SQR_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_KARATSUBA_MUL_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_KARATSUBA_SQR_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_REDUCE_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_REDUCE_SETUP_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_DR_IS_MODULUS_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_DR_SETUP_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_DR_REDUCE_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_REDUCE_IS_2K_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_REDUCE_2K_SETUP_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_REDUCE_2K_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_S_MP_EXPTMOD_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_DIV_3_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_S_MP_MUL_HIGH_DIGS_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_FAST_S_MP_MUL_HIGH_DIGS_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_FAST_MP_INVMOD_C
end_undef

begin_comment
comment|/* To safely undefine these you have to make sure your RSA key won't exceed the Comba threshold     * which is roughly 255 digits [7140 bits for 32-bit machines, 15300 bits for 64-bit machines]     * which means roughly speaking you can handle upto 2536-bit RSA keys with these defined without     * trouble.     */
end_comment

begin_undef
undef|#
directive|undef
name|BN_S_MP_MUL_DIGS_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_S_MP_SQR_C
end_undef

begin_undef
undef|#
directive|undef
name|BN_MP_MONTGOMERY_REDUCE_C
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/tommath_superclass.h,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.3 $ */
end_comment

begin_comment
comment|/* $Date: 2005/05/14 13:29:17 $ */
end_comment

end_unit

