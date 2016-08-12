begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_libm.h,v 1.6 2014/03/25 17:30:14 joerg Exp $ */
end_comment

begin_comment
comment|/*  * Check result of fn(arg) is correct within the bounds.  * Should be ok to do the checks using 'double' for 'float' functions.  * On i386 float and double values are returned on the x87 stack and might  * be out of range for the function - so save and print as 'long double'.  * (otherwise you can get 'inf != inf' reported!)  */
end_comment

begin_define
define|#
directive|define
name|T_LIBM_CHECK
parameter_list|(
name|subtest
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|expect_
parameter_list|,
name|epsilon_
parameter_list|)
value|do { \ 	long double epsilon = epsilon_; \ 	long double expect = expect_; \ 	long double r = fn(arg); \ 	long double e = fabsl(r - expect); \ 	if (r != expect&& e> epsilon) \ 		atf_tc_fail_nonfatal( \ 		    "subtest %u: " #fn "(%g) is %Lg (%.14La) " \ 		    "not %Lg (%.13La), error %Lg (%.6La)> %Lg", \ 		    subtest, arg, r, r, expect, expect, e, e, epsilon); \     } while (0)
end_define

begin_comment
comment|/* Check that the result of fn(arg) is NaN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__vax__
end_ifndef

begin_define
define|#
directive|define
name|T_LIBM_CHECK_NAN
parameter_list|(
name|subtest
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
value|do { \ 	double r = fn(arg); \ 	if (!isnan(r)) \ 		atf_tc_fail_nonfatal("subtest %u: " #fn "(%g) is %g not NaN", \ 		    subtest, arg, r); \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* vax doesn't support NaN */
end_comment

begin_define
define|#
directive|define
name|T_LIBM_CHECK_NAN
parameter_list|(
name|subtest
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
value|(void)(arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Check that the result of fn(arg) is +0.0 */
end_comment

begin_define
define|#
directive|define
name|T_LIBM_CHECK_PLUS_ZERO
parameter_list|(
name|subtest
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
value|do { \ 	double r = fn(arg); \ 	if (fabs(r)> 0.0 || signbit(r) != 0) \ 		atf_tc_fail_nonfatal("subtest %u: " #fn "(%g) is %g not +0.0", \ 		    subtest, arg, r); \     } while (0)
end_define

begin_comment
comment|/* Check that the result of fn(arg) is -0.0 */
end_comment

begin_define
define|#
directive|define
name|T_LIBM_CHECK_MINUS_ZERO
parameter_list|(
name|subtest
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
value|do { \ 	double r = fn(arg); \ 	if (fabs(r)> 0.0 || signbit(r) == 0) \ 		atf_tc_fail_nonfatal("subtest %u: " #fn "(%g) is %g not -0.0", \ 		    subtest, arg, r); \     } while (0)
end_define

begin_comment
comment|/* Some useful constants (for test vectors) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__vax__
end_ifndef

begin_comment
comment|/* no NAN nor +/- INF on vax */
end_comment

begin_define
define|#
directive|define
name|T_LIBM_NAN
value|(0.0 / 0.0)
end_define

begin_define
define|#
directive|define
name|T_LIBM_PLUS_INF
value|(+1.0 / 0.0)
end_define

begin_define
define|#
directive|define
name|T_LIBM_MINUS_INF
value|(-1.0 / 0.0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* One line definition of a simple test */
end_comment

begin_define
define|#
directive|define
name|ATF_LIBM_TEST
parameter_list|(
name|name
parameter_list|,
name|description
parameter_list|)
define|\
value|ATF_TC(name); \ ATF_TC_HEAD(name, tc) { atf_tc_set_md_var(tc, "descr", description); } \ ATF_TC_BODY(name, tc)
end_define

end_unit

