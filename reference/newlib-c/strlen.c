begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FUNCTION<<strlen>>---character string length  INDEX 	strlen  ANSI_SYNOPSIS 	#include<string.h> 	size_t strlen(const char *<[str]>);  TRAD_SYNOPSIS 	#include<string.h> 	size_t strlen(<[str]>) 	char *<[src]>;  DESCRIPTION 	The<<strlen>> function works out the length of the string 	starting at<<*<[str]>>> by counting chararacters until it 	reaches a<<NULL>> character.  RETURNS<<strlen>> returns the character count.  PORTABILITY<<strlen>> is ANSI C.<<strlen>> requires no supporting OS subroutines.  QUICKREF 	strlen ansi pure */
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

begin_define
define|#
directive|define
name|LBLOCKSIZE
value|(sizeof (long))
end_define

begin_define
define|#
directive|define
name|UNALIGNED
parameter_list|(
name|X
parameter_list|)
value|((long)X& (LBLOCKSIZE - 1))
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
name|size_t
name|_DEFUN
argument_list|(
name|strlen
argument_list|,
operator|(
name|str
operator|)
argument_list|,
name|_CONST
name|char
operator|*
name|str
argument_list|)
block|{
name|_CONST
name|char
modifier|*
name|start
init|=
name|str
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PREFER_SIZE_OVER_SPEED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__OPTIMIZE_SIZE__
argument_list|)
name|unsigned
name|long
modifier|*
name|aligned_addr
decl_stmt|;
comment|/* Align the pointer, so we can search a word at a time.  */
while|while
condition|(
name|UNALIGNED
argument_list|(
name|str
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
operator|*
name|str
condition|)
return|return
name|str
operator|-
name|start
return|;
name|str
operator|++
expr_stmt|;
block|}
comment|/* If the string is word-aligned, we can check for the presence of      a null in each word-sized block.  */
name|aligned_addr
operator|=
operator|(
name|unsigned
name|long
operator|*
operator|)
name|str
expr_stmt|;
while|while
condition|(
operator|!
name|DETECTNULL
argument_list|(
operator|*
name|aligned_addr
argument_list|)
condition|)
name|aligned_addr
operator|++
expr_stmt|;
comment|/* Once a null is detected, we check each byte in that block for a      precise position of the null.  */
name|str
operator|=
operator|(
name|char
operator|*
operator|)
name|aligned_addr
expr_stmt|;
endif|#
directive|endif
comment|/* not PREFER_SIZE_OVER_SPEED */
while|while
condition|(
operator|*
name|str
condition|)
name|str
operator|++
expr_stmt|;
return|return
name|str
operator|-
name|start
return|;
block|}
end_decl_stmt

end_unit

