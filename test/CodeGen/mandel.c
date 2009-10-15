begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o %t
end_comment

begin_comment
comment|/* Sparc is not C99-compliant */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
end_if

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sparc */
end_comment

begin_define
define|#
directive|define
name|ESCAPE
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_WIDTH
value|150
end_define

begin_define
define|#
directive|define
name|IMAGE_HEIGHT
value|50
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|IMAGE_SIZE
value|60
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IMAGE_SIZE
value|5000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|START_X
value|-2.1
end_define

begin_define
define|#
directive|define
name|END_X
value|1.0
end_define

begin_define
define|#
directive|define
name|START_Y
value|-1.25
end_define

begin_define
define|#
directive|define
name|MAX_ITER
value|100
end_define

begin_define
define|#
directive|define
name|step_X
value|((END_X - START_X)/IMAGE_WIDTH)
end_define

begin_define
define|#
directive|define
name|step_Y
value|((-START_Y - START_Y)/IMAGE_HEIGHT)
end_define

begin_define
define|#
directive|define
name|I
value|1.0iF
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|volatile
name|double
name|__complex__
name|accum
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|mandel
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|n
decl_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|IMAGE_HEIGHT
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
name|IMAGE_WIDTH
condition|;
operator|++
name|x
control|)
block|{
name|double
name|__complex__
name|c
init|=
operator|(
name|START_X
operator|+
name|x
operator|*
name|step_X
operator|)
operator|+
operator|(
name|START_Y
operator|+
name|y
operator|*
name|step_Y
operator|)
operator|*
name|I
decl_stmt|;
name|double
name|__complex__
name|z
init|=
literal|0.0
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|MAX_ITER
condition|;
operator|++
name|n
control|)
block|{
name|z
operator|=
name|z
operator|*
name|z
operator|+
name|c
expr_stmt|;
if|if
condition|(
name|hypot
argument_list|(
argument|__real__ z
argument_list|,
argument|__imag__ z
argument_list|)
operator|>=
name|ESCAPE
condition|)
break|break;
block|}
if|if
condition|(
name|n
operator|==
name|MAX_ITER
condition|)
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|>
literal|6
condition|)
name|putchar
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|>
literal|3
condition|)
name|putchar
argument_list|(
literal|'+'
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|>
literal|2
condition|)
name|putchar
argument_list|(
literal|'x'
argument_list|)
expr_stmt|;
else|else
name|putchar
argument_list|(
literal|'*'
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|mandel
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

end_unit

