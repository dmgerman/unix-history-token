begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** **  Radix-32 strings divide a number into five-bit nibbles and use the **  alphabet 0..9a..v to represent 0..32. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_decl_stmt
specifier|static
name|char
name|ALPHABET
index|[]
init|=
literal|"0123456789abcdefghijklmnopqrstuv"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Turn a number into a Radix-32 string.  Assume the number fits into **  32 bits. */
end_comment

begin_function
name|void
name|Radix32
parameter_list|(
name|l
parameter_list|,
name|buff
parameter_list|)
specifier|register
name|unsigned
name|long
name|l
decl_stmt|;
specifier|register
name|char
modifier|*
name|buff
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|char
name|temp
index|[
literal|10
index|]
decl_stmt|;
comment|/* Simple sanity checks. */
if|if
condition|(
operator|(
name|l
operator|&=
literal|0xFFFFFFFFL
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|buff
operator|++
operator|=
name|ALPHABET
index|[
literal|0
index|]
expr_stmt|;
operator|*
name|buff
operator|=
literal|'\0'
expr_stmt|;
return|return;
block|}
comment|/* Format the string, in reverse. */
for|for
control|(
name|p
operator|=
name|temp
init|;
name|l
condition|;
name|l
operator|>>=
literal|5
control|)
operator|*
name|p
operator|++
operator|=
name|ALPHABET
index|[
call|(
name|int
call|)
argument_list|(
name|l
operator|&
literal|037
argument_list|)
index|]
expr_stmt|;
comment|/* Reverse it. */
for|for
control|(
name|i
operator|=
name|p
operator|-
name|temp
init|;
operator|--
name|i
operator|>=
literal|0
condition|;
control|)
operator|*
name|buff
operator|++
operator|=
operator|*
operator|--
name|p
expr_stmt|;
operator|*
name|buff
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* **  Return a Radix-32 string as a number, or ~0 on error. */
end_comment

begin_endif
unit|unsigned long Decode32(p)     register char		*p; {     register unsigned long	l;     register char		*cp;      for (l = 0; *p; p++) { 	if ((cp = strchr(ALPHABET, *p)) == NULL) 	    return ~0; 	l = (l<< 6) + cp - ALPHABET;     }     return l; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

end_unit

