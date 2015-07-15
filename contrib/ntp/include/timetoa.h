begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * timetoa.h -- time_t related string formatting  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  *  * Printing a 'time_t' has some portability pitfalls, due to it's opaque  * base type. The only requirement imposed by the standard is that it  * must be a numeric type. For all practical purposes it's a signed int,  * and 32 bits are common.  *  * Since the UN*X time epoch will cause a signed integer overflow for  * 32-bit signed int values in the year 2038, implementations slowly  * move to 64bit base types for time_t, even in 32-bit environments. In  * such an environment sizeof(time_t) could be bigger than sizeof(long)  * and the commonly used idiom of casting to long leads to truncation.  *  * As the printf() family has no standardised type specifier for time_t,  * guessing the right output format specifier is a bit troublesome and  * best done with the help of the preprocessor and "config.h".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMETOA_H
end_ifndef

begin_define
define|#
directive|define
name|TIMETOA_H
end_define

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_comment
comment|/*  * Given the size of time_t, guess what can be used as an unsigned value  * to hold a time_t and the printf() format specifcation.  *  * These should be used with the string constant concatenation feature  * of the compiler like this:  *  * printf("a time stamp: %" TIME_FORMAT " and more\n", a_time_t_value);  *  * It's not exactly nice, but there's not much leeway once we want to  * use the printf() family on time_t values.  */
end_comment

begin_if
if|#
directive|if
name|SIZEOF_TIME_T
operator|<=
name|SIZEOF_INT
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_time
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TIME_FORMAT
value|"d"
end_define

begin_define
define|#
directive|define
name|UTIME_FORMAT
value|"u"
end_define

begin_elif
elif|#
directive|elif
name|SIZEOF_TIME_T
operator|<=
name|SIZEOF_LONG
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_time
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TIME_FORMAT
value|"ld"
end_define

begin_define
define|#
directive|define
name|UTIME_FORMAT
value|"lu"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SIZEOF_LONG_LONG
argument_list|)
operator|&&
name|SIZEOF_TIME_T
operator|<=
name|SIZEOF_LONG_LONG
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_time
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TIME_FORMAT
value|"lld"
end_define

begin_define
define|#
directive|define
name|UTIME_FORMAT
value|"llu"
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"GRONK: what size has a time_t here?"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * general fractional time stamp formatting.  *  * secs - integral seconds of time stamp  * frac - fractional units  * prec - log10 of units per second (3=milliseconds, 6=microseconds,..)  *	  or in other words: the count of decimal digits required.  *	  If prec is< 0, abs(prec) is taken for the precision and secs  *	  is treated as an unsigned value.  *  * The function will eventually normalise the fraction and adjust the  * seconds accordingly.  *  * This function uses the string buffer library for the return value,  * so do not keep the resulting pointers around.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|format_time_fraction
parameter_list|(
name|time_t
name|secs
parameter_list|,
name|long
name|frac
parameter_list|,
name|int
name|prec
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(TIMETOA_H) */
end_comment

end_unit

