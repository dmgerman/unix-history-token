begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|// RUN: %clang --target=mips64-unknown-linux -S -mmadd4    %s -o -| FileCheck %s -check-prefix=MADD4
end_comment

begin_comment
comment|// RUN: %clang --target=mips64-unknown-linux -S -mno-madd4 %s -o -| FileCheck %s -check-prefix=NOMADD4
end_comment

begin_comment
comment|// RUN: %clang --target=mips64-unknown-linux -S -mmadd4    -fno-honor-nans %s -o -| FileCheck %s -check-prefix=MADD4-NONAN
end_comment

begin_comment
comment|// RUN: %clang --target=mips64-unknown-linux -S -mno-madd4 -fno-honor-nans %s -o -| FileCheck %s -check-prefix=NOMADD4-NONAN
end_comment

begin_function
name|float
name|madd_s
parameter_list|(
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|h
parameter_list|)
block|{
return|return
operator|(
name|f
operator|*
name|g
operator|)
operator|+
name|h
return|;
block|}
end_function

begin_comment
comment|// MADD4:   madd.s
end_comment

begin_comment
comment|// NOMADD4: mul.s
end_comment

begin_comment
comment|// NOMADD4: add.s
end_comment

begin_function
name|float
name|msub_s
parameter_list|(
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|h
parameter_list|)
block|{
return|return
operator|(
name|f
operator|*
name|g
operator|)
operator|-
name|h
return|;
block|}
end_function

begin_comment
comment|// MADD4:   msub.s
end_comment

begin_comment
comment|// NOMADD4: mul.s
end_comment

begin_comment
comment|// NOMADD4: sub.s
end_comment

begin_function
name|double
name|madd_d
parameter_list|(
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|)
block|{
return|return
operator|(
name|f
operator|*
name|g
operator|)
operator|+
name|h
return|;
block|}
end_function

begin_comment
comment|// MADD4:   madd.d
end_comment

begin_comment
comment|// NOMADD4: mul.d
end_comment

begin_comment
comment|// NOMADD4: add.d
end_comment

begin_function
name|double
name|msub_d
parameter_list|(
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|)
block|{
return|return
operator|(
name|f
operator|*
name|g
operator|)
operator|-
name|h
return|;
block|}
end_function

begin_comment
comment|// MADD4:   msub.d
end_comment

begin_comment
comment|// NOMADD4: mul.d
end_comment

begin_comment
comment|// NOMADD4: sub.d
end_comment

begin_function
name|float
name|nmadd_s
parameter_list|(
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|h
parameter_list|)
block|{
comment|// FIXME: Zero has been explicitly placed to force generation of a positive
comment|// zero in IR until pattern used to match this instruction is changed to
comment|// comply with negative zero as well.
return|return
literal|0
operator|-
operator|(
operator|(
name|f
operator|*
name|g
operator|)
operator|+
name|h
operator|)
return|;
block|}
end_function

begin_comment
comment|// MADD4-NONAN:   nmadd.s
end_comment

begin_comment
comment|// NOMADD4-NONAN: mul.s
end_comment

begin_comment
comment|// NOMADD4-NONAN: add.s
end_comment

begin_comment
comment|// NOMADD4-NONAN: sub.s
end_comment

begin_function
name|float
name|nmsub_s
parameter_list|(
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|h
parameter_list|)
block|{
comment|// FIXME: Zero has been explicitly placed to force generation of a positive
comment|// zero in IR until pattern used to match this instruction is changed to
comment|// comply with negative zero as well.
return|return
literal|0
operator|-
operator|(
operator|(
name|f
operator|*
name|g
operator|)
operator|-
name|h
operator|)
return|;
block|}
end_function

begin_comment
comment|// MADD4-NONAN:   nmsub.s
end_comment

begin_comment
comment|// NOMADD4-NONAN: mul.s
end_comment

begin_comment
comment|// NOMADD4-NONAN: sub.s
end_comment

begin_comment
comment|// NOMADD4-NONAN: sub.s
end_comment

begin_function
name|double
name|nmadd_d
parameter_list|(
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|)
block|{
comment|// FIXME: Zero has been explicitly placed to force generation of a positive
comment|// zero in IR until pattern used to match this instruction is changed to
comment|// comply with negative zero as well.
return|return
literal|0
operator|-
operator|(
operator|(
name|f
operator|*
name|g
operator|)
operator|+
name|h
operator|)
return|;
block|}
end_function

begin_comment
comment|// MADD4-NONAN:   nmadd.d
end_comment

begin_comment
comment|// NOMADD4-NONAN: mul.d
end_comment

begin_comment
comment|// NOMADD4-NONAN: add.d
end_comment

begin_comment
comment|// NOMADD4-NONAN: sub.d
end_comment

begin_function
name|double
name|nmsub_d
parameter_list|(
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|)
block|{
comment|// FIXME: Zero has been explicitly placed to force generation of a positive
comment|// zero in IR until pattern used to match this instruction is changed to
comment|// comply with negative zero as well.
return|return
literal|0
operator|-
operator|(
operator|(
name|f
operator|*
name|g
operator|)
operator|-
name|h
operator|)
return|;
block|}
end_function

begin_comment
comment|// MADD4-NONAN:   nmsub.d
end_comment

begin_comment
comment|// NOMADD4-NONAN: mul.d
end_comment

begin_comment
comment|// NOMADD4-NONAN: sub.d
end_comment

begin_comment
comment|// NOMADD4-NONAN: sub.d
end_comment

end_unit

