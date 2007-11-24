begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by J.T. Conklin<jtc@NetBSD.org>.  * Public domain.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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

begin_endif
unit|__RCSID("$NetBSD: l64a.c,v 1.13 2003/07/26 19:24:54 salo Exp $");
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|ADOT
value|46
end_define

begin_comment
comment|/* ASCII '.' */
end_comment

begin_define
define|#
directive|define
name|ASLASH
value|ADOT + 1
end_define

begin_comment
comment|/* ASCII '/' */
end_comment

begin_define
define|#
directive|define
name|A0
value|48
end_define

begin_comment
comment|/* ASCII '0' */
end_comment

begin_define
define|#
directive|define
name|AA
value|65
end_define

begin_comment
comment|/* ASCII 'A' */
end_comment

begin_define
define|#
directive|define
name|Aa
value|97
end_define

begin_comment
comment|/* ASCII 'a' */
end_comment

begin_function
name|char
modifier|*
name|l64a
parameter_list|(
name|long
name|value
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|8
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|l64a_r
argument_list|(
name|value
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

begin_function
name|int
name|l64a_r
parameter_list|(
name|long
name|value
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|buflen
parameter_list|)
block|{
name|long
name|v
decl_stmt|;
name|int
name|digit
decl_stmt|;
name|v
operator|=
name|value
operator|&
operator|(
name|long
operator|)
literal|0xffffffff
expr_stmt|;
for|for
control|(
init|;
name|v
operator|!=
literal|0
operator|&&
name|buflen
operator|>
literal|1
condition|;
name|buffer
operator|++
operator|,
name|buflen
operator|--
control|)
block|{
name|digit
operator|=
name|v
operator|&
literal|0x3f
expr_stmt|;
if|if
condition|(
name|digit
operator|<
literal|2
condition|)
operator|*
name|buffer
operator|=
name|digit
operator|+
name|ADOT
expr_stmt|;
elseif|else
if|if
condition|(
name|digit
operator|<
literal|12
condition|)
operator|*
name|buffer
operator|=
name|digit
operator|+
name|A0
operator|-
literal|2
expr_stmt|;
elseif|else
if|if
condition|(
name|digit
operator|<
literal|38
condition|)
operator|*
name|buffer
operator|=
name|digit
operator|+
name|AA
operator|-
literal|12
expr_stmt|;
else|else
operator|*
name|buffer
operator|=
name|digit
operator|+
name|Aa
operator|-
literal|38
expr_stmt|;
name|v
operator|>>=
literal|6
expr_stmt|;
block|}
return|return
operator|(
name|v
operator|==
literal|0
condition|?
literal|0
else|:
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

