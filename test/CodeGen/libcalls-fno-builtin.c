begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -O3 -fno-builtin -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar://10551066
end_comment

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_function_decl
name|double
name|ceil
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|copysign
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cos
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fabs
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|floor
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strrchr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stpcpy
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strpbrk
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|strspn
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|strtod
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|strtof
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|strtold
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|int
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|int
name|strtoll
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|long
name|int
name|strtoull
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|t1
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|ceil
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t1
end_comment

begin_comment
comment|// CHECK: ceil
end_comment

begin_function
name|double
name|t2
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
return|return
name|copysign
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t2
end_comment

begin_comment
comment|// CHECK: copysign
end_comment

begin_function
name|double
name|t3
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|cos
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t3
end_comment

begin_comment
comment|// CHECK: cos
end_comment

begin_function
name|double
name|t4
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|fabs
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t4
end_comment

begin_comment
comment|// CHECK: fabs
end_comment

begin_function
name|double
name|t5
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|floor
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t5
end_comment

begin_comment
comment|// CHECK: floor
end_comment

begin_function
name|char
modifier|*
name|t6
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strcat
argument_list|(
name|x
argument_list|,
literal|""
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t6
end_comment

begin_comment
comment|// CHECK: strcat
end_comment

begin_function
name|char
modifier|*
name|t7
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strncat
argument_list|(
name|x
argument_list|,
literal|""
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t7
end_comment

begin_comment
comment|// CHECK: strncat
end_comment

begin_function
name|char
modifier|*
name|t8
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|strchr
argument_list|(
literal|"hello, world"
argument_list|,
literal|'w'
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t8
end_comment

begin_comment
comment|// CHECK: strchr
end_comment

begin_function
name|char
modifier|*
name|t9
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|strrchr
argument_list|(
literal|"hello, world"
argument_list|,
literal|'w'
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t9
end_comment

begin_comment
comment|// CHECK: strrchr
end_comment

begin_function
name|int
name|t10
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|strcmp
argument_list|(
literal|"foo"
argument_list|,
literal|"bar"
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t10
end_comment

begin_comment
comment|// CHECK: strcmp
end_comment

begin_function
name|int
name|t11
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|strncmp
argument_list|(
literal|"foo"
argument_list|,
literal|"bar"
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t11
end_comment

begin_comment
comment|// CHECK: strncmp
end_comment

begin_function
name|char
modifier|*
name|t12
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strcpy
argument_list|(
name|x
argument_list|,
literal|"foo"
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t12
end_comment

begin_comment
comment|// CHECK: strcpy
end_comment

begin_function
name|char
modifier|*
name|t13
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|stpcpy
argument_list|(
name|x
argument_list|,
literal|"foo"
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t13
end_comment

begin_comment
comment|// CHECK: stpcpy
end_comment

begin_function
name|char
modifier|*
name|t14
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strncpy
argument_list|(
name|x
argument_list|,
literal|"foo"
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t14
end_comment

begin_comment
comment|// CHECK: strncpy
end_comment

begin_function
name|size_t
name|t15
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|strlen
argument_list|(
literal|"foo"
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t15
end_comment

begin_comment
comment|// CHECK: strlen
end_comment

begin_function
name|char
modifier|*
name|t16
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strpbrk
argument_list|(
name|x
argument_list|,
literal|""
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t16
end_comment

begin_comment
comment|// CHECK: strpbrk
end_comment

begin_function
name|size_t
name|t17
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strspn
argument_list|(
name|x
argument_list|,
literal|""
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t17
end_comment

begin_comment
comment|// CHECK: strspn
end_comment

begin_function
name|double
name|t18
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtod
argument_list|(
literal|"123.4"
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t18
end_comment

begin_comment
comment|// CHECK: strtod
end_comment

begin_function
name|float
name|t19
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtof
argument_list|(
literal|"123.4"
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t19
end_comment

begin_comment
comment|// CHECK: strtof
end_comment

begin_function
name|long
name|double
name|t20
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtold
argument_list|(
literal|"123.4"
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t20
end_comment

begin_comment
comment|// CHECK: strtold
end_comment

begin_function
name|long
name|int
name|t21
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtol
argument_list|(
literal|"1234"
argument_list|,
name|x
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t21
end_comment

begin_comment
comment|// CHECK: strtol
end_comment

begin_function
name|long
name|int
name|t22
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtoll
argument_list|(
literal|"1234"
argument_list|,
name|x
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t22
end_comment

begin_comment
comment|// CHECK: strtoll
end_comment

begin_function
name|long
name|int
name|t23
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtoul
argument_list|(
literal|"1234"
argument_list|,
name|x
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t23
end_comment

begin_comment
comment|// CHECK: strtoul
end_comment

begin_function
name|long
name|int
name|t24
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
return|return
name|strtoull
argument_list|(
literal|"1234"
argument_list|,
name|x
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t24
end_comment

begin_comment
comment|// CHECK: strtoull
end_comment

end_unit

