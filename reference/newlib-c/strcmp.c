begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FUNCTION<<strcmp>>---character string compare 	 INDEX 	strcmp  ANSI_SYNOPSIS 	#include<string.h> 	int strcmp(const char *<[a]>, const char *<[b]>);  TRAD_SYNOPSIS 	#include<string.h> 	int strcmp(<[a]>,<[b]>) 	char *<[a]>; 	char *<[b]>;  DESCRIPTION<<strcmp>> compares the string at<[a]> to 	the string at<[b]>.  RETURNS 	If<<*<[a]>>> sorts lexicographically after<<*<[b]>>>,<<strcmp>> returns a number greater than zero.  If the two 	strings match,<<strcmp>> returns zero.  If<<*<[a]>>> 	sorts lexicographically before<<*<[b]>>>,<<strcmp>> returns a 	number less than zero.  PORTABILITY<<strcmp>> is ANSI C.<<strcmp>> requires no supporting OS subroutines.  QUICKREF 	strcmp ansi pure */
end_comment

begin_include
include|#
directive|include
file|"shim.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_undef
undef|#
directive|undef
name|strcmp
end_undef

begin_comment
comment|/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
end_comment

begin_define
define|#
directive|define
name|UNALIGNED
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(((long)X& (sizeof (long) - 1)) | ((long)Y& (sizeof (long) - 1)))
end_define

begin_comment
comment|/* DETECTNULL returns nonzero if (long)X contains a NULL byte. */
end_comment

begin_if
if|#
directive|if
name|LONG_MAX
operator|==
literal|2147483647L
end_if

begin_define
define|#
directive|define
name|DETECTNULL
parameter_list|(
name|X
parameter_list|)
value|(((X) - 0x01010101)& ~(X)& 0x80808080)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONG_MAX
operator|==
literal|9223372036854775807L
end_if

begin_define
define|#
directive|define
name|DETECTNULL
parameter_list|(
name|X
parameter_list|)
value|(((X) - 0x0101010101010101)& ~(X)& 0x8080808080808080)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|long int is not a 32bit or 64bit type.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DETECTNULL
end_ifndef

begin_error
error|#
directive|error
error|long int is not a 32bit or 64bit byte
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|_DEFUN
argument_list|(
name|strcmp
argument_list|,
operator|(
name|s1
operator|,
name|s2
operator|)
argument_list|,
name|_CONST
name|char
operator|*
name|s1
name|_AND
name|_CONST
name|char
operator|*
name|s2
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|PREFER_SIZE_OVER_SPEED
argument_list|)
operator|||
name|defined
argument_list|(
name|__OPTIMIZE_SIZE__
argument_list|)
while|while
condition|(
operator|*
name|s1
operator|!=
literal|'\0'
operator|&&
operator|*
name|s1
operator|==
operator|*
name|s2
condition|)
block|{
name|s1
operator|++
expr_stmt|;
name|s2
operator|++
expr_stmt|;
block|}
return|return
operator|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s1
operator|)
operator|-
operator|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s2
operator|)
return|;
else|#
directive|else
name|unsigned
name|long
modifier|*
name|a1
decl_stmt|;
name|unsigned
name|long
modifier|*
name|a2
decl_stmt|;
comment|/* If s1 or s2 are unaligned, then compare bytes. */
if|if
condition|(
operator|!
name|UNALIGNED
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
condition|)
block|{
comment|/* If s1 and s2 are word-aligned, compare them a word at a time. */
name|a1
operator|=
operator|(
name|unsigned
name|long
operator|*
operator|)
name|s1
expr_stmt|;
name|a2
operator|=
operator|(
name|unsigned
name|long
operator|*
operator|)
name|s2
expr_stmt|;
while|while
condition|(
operator|*
name|a1
operator|==
operator|*
name|a2
condition|)
block|{
comment|/* To get here, *a1 == *a2, thus if we find a null in *a1, 	     then the strings must be equal, so return zero.  */
if|if
condition|(
name|DETECTNULL
argument_list|(
operator|*
name|a1
argument_list|)
condition|)
return|return
literal|0
return|;
name|a1
operator|++
expr_stmt|;
name|a2
operator|++
expr_stmt|;
block|}
comment|/* A difference was detected in last few bytes of s1, so search bytewise */
name|s1
operator|=
operator|(
name|char
operator|*
operator|)
name|a1
expr_stmt|;
name|s2
operator|=
operator|(
name|char
operator|*
operator|)
name|a2
expr_stmt|;
block|}
while|while
condition|(
operator|*
name|s1
operator|!=
literal|'\0'
operator|&&
operator|*
name|s1
operator|==
operator|*
name|s2
condition|)
block|{
name|s1
operator|++
expr_stmt|;
name|s2
operator|++
expr_stmt|;
block|}
return|return
operator|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s1
operator|)
operator|-
operator|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s2
operator|)
return|;
endif|#
directive|endif
comment|/* not PREFER_SIZE_OVER_SPEED */
block|}
end_decl_stmt

end_unit

