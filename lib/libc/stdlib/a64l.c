begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Written by J.T. Conklin<jtc@netbsd.org>.  * Public domain.  */
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
unit|__RCSID("$NetBSD: a64l.c,v 1.8 2000/01/22 22:19:19 mycroft Exp $");
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

begin_include
include|#
directive|include
file|<inttypes.h>
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
name|long
name|a64l
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|long
name|shift
decl_stmt|;
name|int
name|digit
decl_stmt|,
name|i
decl_stmt|,
name|value
decl_stmt|;
name|value
operator|=
literal|0
expr_stmt|;
name|shift
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|*
name|s
operator|!=
literal|'\0'
operator|&&
name|i
operator|<
literal|6
condition|;
name|i
operator|++
operator|,
name|s
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|s
operator|<=
name|ASLASH
condition|)
name|digit
operator|=
operator|*
name|s
operator|-
name|ASLASH
operator|+
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|s
operator|<=
name|A0
operator|+
literal|9
condition|)
name|digit
operator|=
operator|*
name|s
operator|-
name|A0
operator|+
literal|2
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|s
operator|<=
name|AA
operator|+
literal|25
condition|)
name|digit
operator|=
operator|*
name|s
operator|-
name|AA
operator|+
literal|12
expr_stmt|;
else|else
name|digit
operator|=
operator|*
name|s
operator|-
name|Aa
operator|+
literal|38
expr_stmt|;
name|value
operator||=
name|digit
operator|<<
name|shift
expr_stmt|;
name|shift
operator|+=
literal|6
expr_stmt|;
block|}
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

end_unit

