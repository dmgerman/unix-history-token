begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: moduli.h,v 1.1 2003/07/28 09:49:56 djm Exp $ */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_comment
comment|/*  * Using virtual memory can cause thrashing.  This should be the largest  * number that is supported without a large amount of disk activity --  * that would increase the run time from hours to days or weeks!  */
end_comment

begin_define
define|#
directive|define
name|LARGE_MINIMUM
value|(8UL)
end_define

begin_comment
comment|/* megabytes */
end_comment

begin_comment
comment|/*  * Do not increase this number beyond the unsigned integer bit size.  * Due to a multiple of 4, it must be LESS than 128 (yielding 2**30 bits).  */
end_comment

begin_define
define|#
directive|define
name|LARGE_MAXIMUM
value|(127UL)
end_define

begin_comment
comment|/* megabytes */
end_comment

begin_comment
comment|/* Minimum number of primality tests to perform */
end_comment

begin_define
define|#
directive|define
name|TRIAL_MINIMUM
value|(4)
end_define

begin_function_decl
name|int
name|gen_candidates
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prime_test
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

