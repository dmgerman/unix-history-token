begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** This file is in the public domain, so clarified as of ** 1996-06-05 by Arthur David Olson. */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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
name|__unused
init|=
literal|"@(#)difftime.c	8.1"
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

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_comment
comment|/* for time_t, TYPE_INTEGRAL, and TYPE_SIGNED */
end_comment

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

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
comment|/* 	** If (sizeof (double)> sizeof (time_t)) simply convert and subtract 	** (assuming that the larger type has more precision). 	** This is the common real-world case circa 2004. 	*/
if|if
condition|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|time_t
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
operator|!
name|TYPE_INTEGRAL
argument_list|(
name|time_t
argument_list|)
condition|)
block|{
comment|/* 		** time_t is floating. 		*/
return|return
name|time1
operator|-
name|time0
return|;
block|}
if|if
condition|(
operator|!
name|TYPE_SIGNED
argument_list|(
name|time_t
argument_list|)
condition|)
block|{
comment|/* 		** time_t is integral and unsigned. 		** The difference of two unsigned values can't overflow 		** if the minuend is greater than or equal to the subtrahend. 		*/
if|if
condition|(
name|time1
operator|>=
name|time0
condition|)
return|return
name|time1
operator|-
name|time0
return|;
else|else
return|return
operator|-
operator|(
call|(
name|double
call|)
argument_list|(
name|time0
operator|-
name|time1
argument_list|)
operator|)
return|;
block|}
comment|/* 	** time_t is integral and signed. 	** Handle cases where both time1 and time0 have the same sign 	** (meaning that their difference cannot overflow). 	*/
if|if
condition|(
operator|(
name|time1
operator|<
literal|0
operator|)
operator|==
operator|(
name|time0
operator|<
literal|0
operator|)
condition|)
return|return
name|time1
operator|-
name|time0
return|;
comment|/* 	** time1 and time0 have opposite signs. 	** Punt if unsigned long is too narrow. 	*/
if|if
condition|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|<
sizeof|sizeof
argument_list|(
name|time_t
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
comment|/* 	** Stay calm...decent optimizers will eliminate the complexity below. 	*/
if|if
condition|(
name|time1
operator|>=
literal|0
comment|/*&& time0< 0 */
condition|)
return|return
operator|(
name|unsigned
name|long
operator|)
name|time1
operator|+
call|(
name|unsigned
name|long
call|)
argument_list|(
operator|-
operator|(
name|time0
operator|+
literal|1
operator|)
argument_list|)
operator|+
literal|1
return|;
return|return
operator|-
call|(
name|double
call|)
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|time0
operator|+
call|(
name|unsigned
name|long
call|)
argument_list|(
operator|-
operator|(
name|time1
operator|+
literal|1
operator|)
argument_list|)
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

