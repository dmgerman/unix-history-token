begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FUNCTION<<memchr>>---find character in memory  INDEX 	memchr  ANSI_SYNOPSIS 	#include<string.h> 	void *memchr(const void *<[src]>, int<[c]>, size_t<[length]>);  TRAD_SYNOPSIS 	#include<string.h> 	void *memchr(<[src]>,<[c]>,<[length]>) 	void *<[src]>; 	void *<[c]>; 	size_t<[length]>;  DESCRIPTION 	This function searches memory starting at<<*<[src]>>> for the 	character<[c]>.  The search only ends with the first 	occurrence of<[c]>, or after<[length]> characters; in 	particular,<<NULL>> does not terminate the search.  RETURNS 	If the character<[c]> is found within<[length]> characters 	of<<*<[src]>>>, a pointer to the character is returned. If<[c]> is not found, then<<NULL>> is returned. 	  PORTABILITY<<memchr>>  requires no supporting OS subroutines.  QUICKREF 	memchr ansi pure  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|PTR
name|memchr
parameter_list|(
name|src_void
parameter_list|,
name|c
parameter_list|,
name|length
parameter_list|)
specifier|register
name|CONST
name|PTR
name|src_void
decl_stmt|;
name|int
name|c
decl_stmt|;
name|size_t
name|length
decl_stmt|;
block|{
name|CONST
name|unsigned
name|char
modifier|*
name|src
init|=
operator|(
name|CONST
name|unsigned
name|char
operator|*
operator|)
name|src_void
decl_stmt|;
while|while
condition|(
operator|--
name|length
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|src
operator|==
name|c
condition|)
return|return
operator|(
name|PTR
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
end_function

end_unit

