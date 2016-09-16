begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FUNCTION<<strcpy>>---copy string  INDEX 	strcpy  ANSI_SYNOPSIS 	#include<string.h> 	char *strcpy(char *<[dst]>, const char *<[src]>);  TRAD_SYNOPSIS 	#include<string.h> 	char *strcpy(<[dst]>,<[src]>) 	char *<[dst]>; 	char *<[src]>;  DESCRIPTION<<strcpy>> copies the string pointed to by<[src]> 	(including the terminating null character) to the array 	pointed to by<[dst]>.  RETURNS 	This function returns the initial value of<[dst]>.  PORTABILITY<<strcpy>> is ANSI C.<<strcpy>> requires no supporting OS subroutines.  QUICKREF 	strcpy ansi pure */
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

begin_comment
comment|/*SUPPRESS 560*/
end_comment

begin_comment
comment|/*SUPPRESS 530*/
end_comment

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

begin_comment
comment|/* Nonzero if X (a long int) contains a NULL byte. */
end_comment

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
name|char
modifier|*
name|_DEFUN
argument_list|(
name|strcpy
argument_list|,
operator|(
name|dst0
operator|,
name|src0
operator|)
argument_list|,
name|char
operator|*
name|dst0
name|_AND
name|_CONST
name|char
operator|*
name|src0
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
name|char
modifier|*
name|s
init|=
name|dst0
decl_stmt|;
while|while
condition|(
operator|*
name|dst0
operator|++
operator|=
operator|*
name|src0
operator|++
condition|)
empty_stmt|;
return|return
name|s
return|;
else|#
directive|else
name|char
modifier|*
name|dst
init|=
name|dst0
decl_stmt|;
name|_CONST
name|char
modifier|*
name|src
init|=
name|src0
decl_stmt|;
name|long
modifier|*
name|aligned_dst
decl_stmt|;
name|_CONST
name|long
modifier|*
name|aligned_src
decl_stmt|;
comment|/* If SRC or DEST is unaligned, then copy bytes.  */
if|if
condition|(
operator|!
name|UNALIGNED
argument_list|(
name|src
argument_list|,
name|dst
argument_list|)
condition|)
block|{
name|aligned_dst
operator|=
operator|(
name|long
operator|*
operator|)
name|dst
expr_stmt|;
name|aligned_src
operator|=
operator|(
name|long
operator|*
operator|)
name|src
expr_stmt|;
comment|/* SRC and DEST are both "long int" aligned, try to do "long int"          sized copies.  */
while|while
condition|(
operator|!
name|DETECTNULL
argument_list|(
operator|*
name|aligned_src
argument_list|)
condition|)
block|{
operator|*
name|aligned_dst
operator|++
operator|=
operator|*
name|aligned_src
operator|++
expr_stmt|;
block|}
name|dst
operator|=
operator|(
name|char
operator|*
operator|)
name|aligned_dst
expr_stmt|;
name|src
operator|=
operator|(
name|char
operator|*
operator|)
name|aligned_src
expr_stmt|;
block|}
while|while
condition|(
operator|(
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
operator|)
condition|)
empty_stmt|;
return|return
name|dst0
return|;
endif|#
directive|endif
comment|/* not PREFER_SIZE_OVER_SPEED */
block|}
end_decl_stmt

end_unit

