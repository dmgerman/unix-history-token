begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_assert.h - design by contract stuff  *  * example:  *  * int foo(char *a) {  *	int result;  *	int value;  *  *	REQUIRE(a != NULL);  *	...  *	bar(&value);  *	INSIST(value> 2);  *	...  *  *	ENSURE(result != 12);  *	return result;  * }  *  * open question: when would we use INVARIANT()?  *  * For cases where the overhead for non-debug builds is deemed too high,  * use DEBUG_REQUIRE(), DEBUG_INSIST(), DEBUG_ENSURE(), and/or  * DEBUG_INVARIANT().  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_ASSERT_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_ASSERT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CALYSTO
end_ifdef

begin_comment
comment|/* see: http://www.domagoj-babic.com/index.php/ResearchProjects/Calysto */
end_comment

begin_function_decl
specifier|extern
name|void
name|calysto_assume
parameter_list|(
name|unsigned
name|char
name|cnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* assume this always holds */
end_comment

begin_function_decl
specifier|extern
name|void
name|calysto_assert
parameter_list|(
name|unsigned
name|char
name|cnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check whether this holds */
end_comment

begin_define
define|#
directive|define
name|ALWAYS_REQUIRE
parameter_list|(
name|x
parameter_list|)
value|calysto_assert(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_INSIST
parameter_list|(
name|x
parameter_list|)
value|calysto_assume(x)
end_define

begin_comment
comment|/* DLH calysto_assert()? */
end_comment

begin_define
define|#
directive|define
name|ALWAYS_INVARIANT
parameter_list|(
name|x
parameter_list|)
value|calysto_assume(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_ENSURE
parameter_list|(
name|x
parameter_list|)
value|calysto_assert(x)
end_define

begin_comment
comment|/* # elif defined(__COVERITY__) */
end_comment

begin_comment
comment|/*  * DH: try letting coverity scan our actual assertion macros, now that  * isc_assertioncallback_t is marked __attribute__ __noreturn__.  */
end_comment

begin_comment
comment|/*  * Coverity has special knowledge that assert(x) terminates the process  * if x is not true.  Rather than teach it about our assertion macros,  * just use the one it knows about for Coverity Prevent scans.  This  * means our assertion code (and ISC's) escapes Coverity analysis, but  * that seems to be a reasonable trade-off.  */
end_comment

begin_comment
comment|/* #define ALWAYS_REQUIRE(x)	assert(x) #define ALWAYS_INSIST(x)	assert(x) #define ALWAYS_INVARIANT(x)	assert(x) #define ALWAYS_ENSURE(x)	assert(x) */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FLEXELINT__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|ALWAYS_REQUIRE
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_INSIST
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_INVARIANT
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_ENSURE
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* neither Calysto, Coverity or FlexeLint */
end_comment

begin_include
include|#
directive|include
file|"isc/assertions.h"
end_include

begin_define
define|#
directive|define
name|ALWAYS_REQUIRE
parameter_list|(
name|x
parameter_list|)
value|ISC_REQUIRE(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_INSIST
parameter_list|(
name|x
parameter_list|)
value|ISC_INSIST(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_INVARIANT
parameter_list|(
name|x
parameter_list|)
value|ISC_INVARIANT(x)
end_define

begin_define
define|#
directive|define
name|ALWAYS_ENSURE
parameter_list|(
name|x
parameter_list|)
value|ISC_ENSURE(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* neither Coverity nor Calysto */
end_comment

begin_define
define|#
directive|define
name|REQUIRE
parameter_list|(
name|x
parameter_list|)
value|ALWAYS_REQUIRE(x)
end_define

begin_define
define|#
directive|define
name|INSIST
parameter_list|(
name|x
parameter_list|)
value|ALWAYS_INSIST(x)
end_define

begin_define
define|#
directive|define
name|INVARIANT
parameter_list|(
name|x
parameter_list|)
value|ALWAYS_INVARIANT(x)
end_define

begin_define
define|#
directive|define
name|ENSURE
parameter_list|(
name|x
parameter_list|)
value|ALWAYS_ENSURE(x)
end_define

begin_comment
comment|/*  * We initially used NTP_REQUIRE() instead of REQUIRE() etc, but that  * is unneccesarily verbose, as libisc use of REQUIRE() etc shows.  */
end_comment

begin_define
define|#
directive|define
name|NTP_REQUIRE
parameter_list|(
name|x
parameter_list|)
value|REQUIRE(x)
end_define

begin_define
define|#
directive|define
name|NTP_INSIST
parameter_list|(
name|x
parameter_list|)
value|INSIST(x)
end_define

begin_define
define|#
directive|define
name|NTP_INVARIANT
parameter_list|(
name|x
parameter_list|)
value|INVARIANT(x)
end_define

begin_define
define|#
directive|define
name|NTP_ENSURE
parameter_list|(
name|x
parameter_list|)
value|ENSURE(x)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_REQUIRE
parameter_list|(
name|x
parameter_list|)
value|REQUIRE(x)
end_define

begin_define
define|#
directive|define
name|DEBUG_INSIST
parameter_list|(
name|x
parameter_list|)
value|INSIST(x)
end_define

begin_define
define|#
directive|define
name|DEBUG_INVARIANT
parameter_list|(
name|x
parameter_list|)
value|INVARIANT(x)
end_define

begin_define
define|#
directive|define
name|DEBUG_ENSURE
parameter_list|(
name|x
parameter_list|)
value|ENSURE(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG_REQUIRE
parameter_list|(
name|x
parameter_list|)
value|do {} while (FALSE)
end_define

begin_define
define|#
directive|define
name|DEBUG_INSIST
parameter_list|(
name|x
parameter_list|)
value|do {} while (FALSE)
end_define

begin_define
define|#
directive|define
name|DEBUG_INVARIANT
parameter_list|(
name|x
parameter_list|)
value|do {} while (FALSE)
end_define

begin_define
define|#
directive|define
name|DEBUG_ENSURE
parameter_list|(
name|x
parameter_list|)
value|do {} while (FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_ASSERT_H */
end_comment

end_unit

