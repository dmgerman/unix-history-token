begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** This file is in the public domain, so clarified as of ** June 5, 1996 by Arthur David Olson (arthur_david_olson@nih.gov). ** ** $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOID
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|elsieid
index|[]
init|=
literal|"@(#)difftime.c	7.7"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_comment
comment|/* ** Algorithm courtesy Paul Eggert (eggert@twinsun.com). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LONG_DOUBLE
end_ifdef

begin_define
define|#
directive|define
name|long_double
value|long double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined HAVE_LONG_DOUBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LONG_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|long_double
value|double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HAVE_LONG_DOUBLE */
end_comment

begin_function
name|double
name|difftime
parameter_list|(
name|time1
parameter_list|,
name|time0
parameter_list|)
specifier|const
name|time_t
name|time1
decl_stmt|;
specifier|const
name|time_t
name|time0
decl_stmt|;
block|{
name|time_t
name|delta
decl_stmt|;
name|time_t
name|hibit
decl_stmt|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|time_t
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|double
argument_list|)
condition|)
return|return
operator|(
name|double
operator|)
name|time1
operator|-
operator|(
name|double
operator|)
name|time0
return|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|time_t
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|long_double
argument_list|)
condition|)
return|return
operator|(
name|long_double
operator|)
name|time1
operator|-
operator|(
name|long_double
operator|)
name|time0
return|;
if|if
condition|(
name|time1
operator|<
name|time0
condition|)
return|return
operator|-
name|difftime
argument_list|(
name|time0
argument_list|,
name|time1
argument_list|)
return|;
comment|/* 	** As much as possible, avoid loss of precision 	** by computing the difference before converting to double. 	*/
name|delta
operator|=
name|time1
operator|-
name|time0
expr_stmt|;
if|if
condition|(
name|delta
operator|>=
literal|0
condition|)
return|return
name|delta
return|;
comment|/* 	** Repair delta overflow. 	*/
name|hibit
operator|=
operator|(
operator|~
operator|(
name|time_t
operator|)
literal|0
operator|)
operator|<<
operator|(
name|TYPE_BIT
argument_list|(
name|time_t
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* 	** The following expression rounds twice, which means 	** the result may not be the closest to the true answer. 	** For example, suppose time_t is 64-bit signed int, 	** long_double is IEEE 754 double with default rounding, 	** time1 = 9223372036854775807 and time0 = -1536. 	** Then the true difference is 9223372036854777343, 	** which rounds to 9223372036854777856 	** with a total error of 513. 	** But delta overflows to -9223372036854774273, 	** which rounds to -9223372036854774784, and correcting 	** this by subtracting 2 * (long_double) hibit 	** (i.e. by adding 2**64 = 18446744073709551616) 	** yields 9223372036854776832, which 	** rounds to 9223372036854775808 	** with a total error of 1535 instead. 	** This problem occurs only with very large differences. 	** It's too painful to fix this portably. 	** We are not alone in this problem; 	** some C compilers round twice when converting 	** large unsigned types to small floating types, 	** so if time_t is unsigned the "return delta" above 	** has the same double-rounding problem with those compilers. 	*/
return|return
name|delta
operator|-
literal|2
operator|*
operator|(
name|long_double
operator|)
name|hibit
return|;
block|}
end_function

end_unit

