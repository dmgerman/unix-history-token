begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)floatdidf.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_define
define|#
directive|define
name|HIGH_HALFWORD_COEFF
value|(((long long) 1)<< (BITS_PER_WORD / 2))
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((long long) 1)<< BITS_PER_WORD)
end_define

begin_function
name|double
name|__floatdidf
parameter_list|(
name|u
parameter_list|)
name|long
name|long
name|u
decl_stmt|;
block|{
name|double
name|d
decl_stmt|;
name|int
name|negate
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|u
operator|<
literal|0
condition|)
name|u
operator|=
operator|-
name|u
operator|,
name|negate
operator|=
literal|1
expr_stmt|;
name|d
operator|=
call|(
name|unsigned
name|int
call|)
argument_list|(
name|u
operator|>>
name|BITS_PER_WORD
argument_list|)
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|+=
call|(
name|unsigned
name|int
call|)
argument_list|(
name|u
operator|&
operator|(
name|HIGH_WORD_COEFF
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|negate
condition|?
operator|-
name|d
else|:
name|d
operator|)
return|;
block|}
end_function

end_unit

