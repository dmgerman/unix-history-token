begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FUNCTION<<memchr>>---find character in memory  INDEX 	memchr  ANSI_SYNOPSIS 	#include<string.h> 	void *memchr(const void *<[src]>, int<[c]>, size_t<[length]>);  TRAD_SYNOPSIS 	#include<string.h> 	void *memchr(<[src]>,<[c]>,<[length]>) 	void *<[src]>; 	void *<[c]>; 	size_t<[length]>;  DESCRIPTION 	This function searches memory starting at<<*<[src]>>> for the 	character<[c]>.  The search only ends with the first 	occurrence of<[c]>, or after<[length]> characters; in 	particular,<<NUL>> does not terminate the search.  RETURNS 	If the character<[c]> is found within<[length]> characters 	of<<*<[src]>>>, a pointer to the character is returned. If<[c]> is not found, then<<NULL>> is returned.  PORTABILITY<<memchr>> is ANSI C.<<memchr>> requires no supporting OS subroutines.  QUICKREF 	memchr ansi pure */
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
comment|/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
end_comment

begin_define
define|#
directive|define
name|UNALIGNED
parameter_list|(
name|X
parameter_list|)
value|((long)X& (sizeof (long) - 1))
end_define

begin_comment
comment|/* How many bytes are loaded each iteration of the word copy loop.  */
end_comment

begin_define
define|#
directive|define
name|LBLOCKSIZE
value|(sizeof (long))
end_define

begin_comment
comment|/* Threshhold for punting to the bytewise iterator.  */
end_comment

begin_define
define|#
directive|define
name|TOO_SMALL
parameter_list|(
name|LEN
parameter_list|)
value|((LEN)< LBLOCKSIZE)
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

begin_comment
comment|/* DETECTCHAR returns nonzero if (long)X contains the byte used    to fill (long)MASK. */
end_comment

begin_define
define|#
directive|define
name|DETECTCHAR
parameter_list|(
name|X
parameter_list|,
name|MASK
parameter_list|)
value|(DETECTNULL(X ^ MASK))
end_define

begin_decl_stmt
name|_PTR
name|_DEFUN
argument_list|(
name|memchr
argument_list|,
operator|(
name|src_void
operator|,
name|c
operator|,
name|length
operator|)
argument_list|,
name|_CONST
name|_PTR
name|src_void
name|_AND
name|int
name|c
name|_AND
name|size_t
name|length
argument_list|)
block|{
name|_CONST
name|unsigned
name|char
modifier|*
name|src
init|=
operator|(
name|_CONST
name|unsigned
name|char
operator|*
operator|)
name|src_void
decl_stmt|;
name|unsigned
name|char
name|d
init|=
name|c
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
name|asrc
decl_stmt|;
name|unsigned
name|long
name|mask
decl_stmt|;
name|int
name|i
decl_stmt|;
while|while
condition|(
name|UNALIGNED
argument_list|(
name|src
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|length
operator|--
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|*
name|src
operator|==
name|d
condition|)
return|return
operator|(
name|void
operator|*
operator|)
name|src
return|;
name|src
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|TOO_SMALL
argument_list|(
name|length
argument_list|)
condition|)
block|{
comment|/* If we get this far, we know that length is large and src is          word-aligned. */
comment|/* The fast code reads the source one word at a time and only          performs the bytewise search on word-sized segments if they          contain the search character, which is detected by XORing          the word-sized segment with a word-sized block of the search          character and then detecting for the presence of NUL in the          result.  */
name|asrc
operator|=
operator|(
name|unsigned
name|long
operator|*
operator|)
name|src
expr_stmt|;
name|mask
operator|=
name|d
operator|<<
literal|8
operator||
name|d
expr_stmt|;
name|mask
operator|=
name|mask
operator|<<
literal|16
operator||
name|mask
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|32
init|;
name|i
operator|<
name|LBLOCKSIZE
operator|*
literal|8
condition|;
name|i
operator|<<=
literal|1
control|)
name|mask
operator|=
operator|(
name|mask
operator|<<
name|i
operator|)
operator||
name|mask
expr_stmt|;
while|while
condition|(
name|length
operator|>=
name|LBLOCKSIZE
condition|)
block|{
if|if
condition|(
name|DETECTCHAR
argument_list|(
operator|*
name|asrc
argument_list|,
name|mask
argument_list|)
condition|)
break|break;
name|length
operator|-=
name|LBLOCKSIZE
expr_stmt|;
name|asrc
operator|++
expr_stmt|;
block|}
comment|/* If there are fewer than LBLOCKSIZE characters left,          then we resort to the bytewise loop.  */
name|src
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|asrc
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* not PREFER_SIZE_OVER_SPEED */
while|while
condition|(
name|length
operator|--
condition|)
block|{
if|if
condition|(
operator|*
name|src
operator|==
name|d
condition|)
return|return
operator|(
name|void
operator|*
operator|)
name|src
return|;
name|src
operator|++
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_decl_stmt

end_unit

