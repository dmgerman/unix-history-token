begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- htmintrin.h - Standard header for PowerPC HTM ---------------===*\  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  * \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HTMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__HTMINTRIN_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__HTM__
end_ifndef

begin_error
error|#
directive|error
literal|"HTM instruction set not enabled"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc__
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_typedef
typedef|typedef
name|uint64_t
name|texasr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|texasru_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|texasrl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uintptr_t
name|tfiar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uintptr_t
name|tfhar_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_HTM_STATE
parameter_list|(
name|CR0
parameter_list|)
value|((CR0>> 1)& 0x3)
end_define

begin_define
define|#
directive|define
name|_HTM_NONTRANSACTIONAL
value|0x0
end_define

begin_define
define|#
directive|define
name|_HTM_SUSPENDED
value|0x1
end_define

begin_define
define|#
directive|define
name|_HTM_TRANSACTIONAL
value|0x2
end_define

begin_define
define|#
directive|define
name|_TEXASR_EXTRACT_BITS
parameter_list|(
name|TEXASR
parameter_list|,
name|BITNUM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|(((TEXASR)>> (63-(BITNUM)))& ((1<<(SIZE))-1))
end_define

begin_define
define|#
directive|define
name|_TEXASRU_EXTRACT_BITS
parameter_list|(
name|TEXASR
parameter_list|,
name|BITNUM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|(((TEXASR)>> (31-(BITNUM)))& ((1<<(SIZE))-1))
end_define

begin_define
define|#
directive|define
name|_TEXASR_FAILURE_CODE
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 7, 8)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_FAILURE_CODE
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 7, 8)
end_define

begin_define
define|#
directive|define
name|_TEXASR_FAILURE_PERSISTENT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 7, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_FAILURE_PERSISTENT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 7, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_DISALLOWED
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 8, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_DISALLOWED
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 8, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_NESTING_OVERFLOW
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 9, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_NESTING_OVERFLOW
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 9, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_FOOTPRINT_OVERFLOW
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 10, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_FOOTPRINT_OVERFLOW
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 10, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_SELF_INDUCED_CONFLICT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 11, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_SELF_INDUCED_CONFLICT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 11, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_NON_TRANSACTIONAL_CONFLICT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 12, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_NON_TRANSACTIONAL_CONFLICT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 12, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_TRANSACTION_CONFLICT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 13, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_TRANSACTION_CONFLICT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 13, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_TRANSLATION_INVALIDATION_CONFLICT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 14, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_TRANSLATION_INVALIDATION_CONFLICT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 14, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_IMPLEMENTAION_SPECIFIC
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 15, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_IMPLEMENTAION_SPECIFIC
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 15, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_INSTRUCTION_FETCH_CONFLICT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 16, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_INSTRUCTION_FETCH_CONFLICT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 16, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_ABORT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 31, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASRU_ABORT
parameter_list|(
name|TEXASRU
parameter_list|)
define|\
value|_TEXASRU_EXTRACT_BITS(TEXASRU, 31, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_SUSPENDED
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 32, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_PRIVILEGE
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 35, 2)
end_define

begin_define
define|#
directive|define
name|_TEXASR_FAILURE_SUMMARY
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 36, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_TFIAR_EXACT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 37, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_ROT
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 38, 1)
end_define

begin_define
define|#
directive|define
name|_TEXASR_TRANSACTION_LEVEL
parameter_list|(
name|TEXASR
parameter_list|)
define|\
value|_TEXASR_EXTRACT_BITS(TEXASR, 63, 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __powerpc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__s390__
end_ifdef

begin_comment
comment|/* Condition codes generated by tbegin  */
end_comment

begin_define
define|#
directive|define
name|_HTM_TBEGIN_STARTED
value|0
end_define

begin_define
define|#
directive|define
name|_HTM_TBEGIN_INDETERMINATE
value|1
end_define

begin_define
define|#
directive|define
name|_HTM_TBEGIN_TRANSIENT
value|2
end_define

begin_define
define|#
directive|define
name|_HTM_TBEGIN_PERSISTENT
value|3
end_define

begin_comment
comment|/* The abort codes below this threshold are reserved for machine use.  */
end_comment

begin_define
define|#
directive|define
name|_HTM_FIRST_USER_ABORT_CODE
value|256
end_define

begin_comment
comment|/* The transaction diagnostic block is it is defined in the Principles    of Operation chapter 5-91.  */
end_comment

begin_struct
struct|struct
name|__htm_tdb
block|{
name|unsigned
name|char
name|format
decl_stmt|;
comment|/*   0 */
name|unsigned
name|char
name|flags
decl_stmt|;
name|unsigned
name|char
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|nesting_depth
decl_stmt|;
name|unsigned
name|long
name|long
name|abort_code
decl_stmt|;
comment|/*   8 */
name|unsigned
name|long
name|long
name|conflict_token
decl_stmt|;
comment|/*  16 */
name|unsigned
name|long
name|long
name|atia
decl_stmt|;
comment|/*  24 */
name|unsigned
name|char
name|eaid
decl_stmt|;
comment|/*  32 */
name|unsigned
name|char
name|dxc
decl_stmt|;
name|unsigned
name|char
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|program_int_id
decl_stmt|;
name|unsigned
name|long
name|long
name|exception_id
decl_stmt|;
comment|/*  40 */
name|unsigned
name|long
name|long
name|bea
decl_stmt|;
comment|/*  48 */
name|unsigned
name|char
name|reserved3
index|[
literal|72
index|]
decl_stmt|;
comment|/*  56 */
name|unsigned
name|long
name|long
name|gprs
index|[
literal|16
index|]
decl_stmt|;
comment|/* 128 */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__aligned__
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Helper intrinsics to retry tbegin in case of transient failure.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__builtin_tbegin_retry_null
argument_list|(
name|int
name|__retry
argument_list|)
block|{
name|int
name|cc
decl_stmt|,
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|cc
operator|=
name|__builtin_tbegin
argument_list|(
literal|0
argument_list|)
operator|)
operator|==
name|_HTM_TBEGIN_TRANSIENT
operator|&&
name|i
operator|++
operator|<
name|__retry
condition|)
name|__builtin_tx_assist
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|cc
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__builtin_tbegin_retry_tdb
argument_list|(
name|void
operator|*
name|__tdb
argument_list|,
name|int
name|__retry
argument_list|)
block|{
name|int
name|cc
decl_stmt|,
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|cc
operator|=
name|__builtin_tbegin
argument_list|(
name|__tdb
argument_list|)
operator|)
operator|==
name|_HTM_TBEGIN_TRANSIENT
operator|&&
name|i
operator|++
operator|<
name|__retry
condition|)
name|__builtin_tx_assist
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|cc
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|__builtin_tbegin_retry
parameter_list|(
name|tdb
parameter_list|,
name|retry
parameter_list|)
define|\
value|(__builtin_constant_p(tdb == 0)&& tdb == 0 ? \    __builtin_tbegin_retry_null(retry) : \    __builtin_tbegin_retry_tdb(tdb, retry))
end_define

begin_decl_stmt
specifier|static
name|__inline
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__builtin_tbegin_retry_nofloat_null
argument_list|(
name|int
name|__retry
argument_list|)
block|{
name|int
name|cc
decl_stmt|,
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|cc
operator|=
name|__builtin_tbegin_nofloat
argument_list|(
literal|0
argument_list|)
operator|)
operator|==
name|_HTM_TBEGIN_TRANSIENT
operator|&&
name|i
operator|++
operator|<
name|__retry
condition|)
name|__builtin_tx_assist
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|cc
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__builtin_tbegin_retry_nofloat_tdb
argument_list|(
name|void
operator|*
name|__tdb
argument_list|,
name|int
name|__retry
argument_list|)
block|{
name|int
name|cc
decl_stmt|,
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|cc
operator|=
name|__builtin_tbegin_nofloat
argument_list|(
name|__tdb
argument_list|)
operator|)
operator|==
name|_HTM_TBEGIN_TRANSIENT
operator|&&
name|i
operator|++
operator|<
name|__retry
condition|)
name|__builtin_tx_assist
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|cc
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|__builtin_tbegin_retry_nofloat
parameter_list|(
name|tdb
parameter_list|,
name|retry
parameter_list|)
define|\
value|(__builtin_constant_p(tdb == 0)&& tdb == 0 ? \    __builtin_tbegin_retry_nofloat_null(retry) : \    __builtin_tbegin_retry_nofloat_tdb(tdb, retry))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __s390__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HTMINTRIN_H */
end_comment

end_unit

