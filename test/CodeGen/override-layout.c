begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -fdump-record-layouts %s> %t.layouts
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -fdump-record-layouts-simple %s> %t.before
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -DPACKED= -DALIGNED16= -fdump-record-layouts-simple -foverride-record-layout=%t.layouts %s> %t.after
end_comment

begin_comment
comment|// RUN: diff %t.before %t.after
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.after
end_comment

begin_comment
comment|// If not explicitly disabled, set PACKED to the packed attribute.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PACKED
end_ifndef

begin_define
define|#
directive|define
name|PACKED
value|__attribute__((packed))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// If not explicitly disabled, set ALIGNED16 to 16-byte alignment.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGNED16
end_ifndef

begin_define
define|#
directive|define
name|ALIGNED16
value|__attribute__((aligned(16)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: Type: struct X0
end_comment

begin_struct
struct|struct
name|X0
block|{
name|int
name|x
index|[
literal|6
index|]
name|PACKED
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|use_X0
parameter_list|()
block|{
name|struct
name|X0
name|x0
decl_stmt|;
name|x0
operator|.
name|x
index|[
literal|5
index|]
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X0
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: Type: struct X1
end_comment

begin_struct
struct|struct
name|X1
block|{
name|char
name|x
index|[
literal|13
index|]
decl_stmt|;
name|struct
name|X0
name|y
decl_stmt|;
block|}
name|PACKED
struct|;
end_struct

begin_function
name|void
name|use_X1
parameter_list|()
block|{
name|struct
name|X1
name|x1
decl_stmt|;
name|x1
operator|.
name|x
index|[
literal|5
index|]
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X1
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: Type: struct X2
end_comment

begin_struct
struct|struct
name|PACKED
name|X2
block|{
name|short
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|use_X2
parameter_list|()
block|{
name|struct
name|X2
name|x2
decl_stmt|;
name|x2
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X2
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: Type: struct X3
end_comment

begin_struct
struct|struct
name|X3
block|{
name|short
name|x
name|PACKED
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|use_X3
parameter_list|()
block|{
name|struct
name|X3
name|x3
decl_stmt|;
name|x3
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X3
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_comment
comment|// CHECK: Type: struct X4
end_comment

begin_struct
struct|struct
name|X4
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_function
name|void
name|use_X4
parameter_list|()
block|{
name|struct
name|X4
name|x4
decl_stmt|;
name|x4
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X4
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: Type: struct X5
end_comment

begin_struct
struct|struct
name|PACKED
name|X5
block|{
name|double
name|a
index|[
literal|19
index|]
decl_stmt|;
name|signed
name|char
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|use_X5
parameter_list|()
block|{
name|struct
name|X5
name|x5
decl_stmt|;
name|x5
operator|.
name|b
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X5
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: Type: struct X6
end_comment

begin_struct
struct|struct
name|PACKED
name|X6
block|{
name|long
name|double
name|a
decl_stmt|;
name|char
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|use_X6
parameter_list|()
block|{
name|struct
name|X6
name|x6
decl_stmt|;
name|x6
operator|.
name|b
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X6
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: Type: struct X7
end_comment

begin_struct
struct|struct
name|X7
block|{
name|unsigned
name|x
decl_stmt|;
name|unsigned
name|char
name|y
decl_stmt|;
block|}
name|PACKED
struct|;
end_struct

begin_function
name|void
name|use_X7
parameter_list|()
block|{
name|struct
name|X7
name|x7
decl_stmt|;
name|x7
operator|.
name|y
operator|=
name|x7
operator|.
name|x
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: Type: union X8
end_comment

begin_union
union|union
name|X8
block|{
name|struct
name|X7
name|x
decl_stmt|;
name|unsigned
name|y
decl_stmt|;
block|}
name|PACKED
union|;
end_union

begin_comment
comment|// CHECK: Type: struct X9
end_comment

begin_struct
struct|struct
name|X9
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
name|PACKED
decl_stmt|;
name|unsigned
name|int
name|y
decl_stmt|;
name|unsigned
name|int
name|z
name|PACKED
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: Type: struct X10
end_comment

begin_struct
struct|struct
name|X10
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
name|PACKED
decl_stmt|;
name|unsigned
name|int
name|y
name|PACKED
decl_stmt|;
name|unsigned
name|int
name|z
name|PACKED
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: Type: struct X11
end_comment

begin_struct
struct|struct
name|PACKED
name|X11
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|y
decl_stmt|;
name|unsigned
name|int
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: Type: struct X12
end_comment

begin_struct
struct|struct
name|PACKED
name|X12
block|{
name|int
name|x
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: Type: struct X13
end_comment

begin_struct
struct|struct
name|PACKED
name|X13
block|{
name|signed
name|x
range|:
literal|10
decl_stmt|;
name|signed
name|y
range|:
literal|10
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: Type: union X14
end_comment

begin_union
union|union
name|PACKED
name|X14
block|{
name|unsigned
name|long
name|long
name|x
range|:
literal|3
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|// CHECK: Type: struct X15
end_comment

begin_struct
struct|struct
name|X15
block|{
name|unsigned
name|x
range|:
literal|16
decl_stmt|;
name|unsigned
name|y
range|:
literal|28
name|PACKED
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: Type: struct X16
end_comment

begin_struct
struct|struct
name|ALIGNED16
name|X16
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|int
name|x
range|:
literal|5
decl_stmt|;
name|int
name|y
range|:
literal|29
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|use_structs
parameter_list|()
block|{
name|union
name|X8
name|x8
decl_stmt|;
typedef|typedef
name|int
name|X8array
index|[
sizeof|sizeof
argument_list|(
expr|union
name|X8
argument_list|)
index|]
expr_stmt|;
name|x8
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|union
name|X8
argument_list|)
expr_stmt|;
name|x8
operator|.
name|x
operator|.
name|x
operator|=
name|x8
operator|.
name|y
expr_stmt|;
name|struct
name|X9
name|x9
decl_stmt|;
typedef|typedef
name|int
name|X9array
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|X9
argument_list|)
index|]
typedef|;
name|x9
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X9
argument_list|)
expr_stmt|;
name|struct
name|X10
name|x10
decl_stmt|;
typedef|typedef
name|int
name|X10array
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|X10
argument_list|)
index|]
typedef|;
name|x10
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X10
argument_list|)
expr_stmt|;
name|struct
name|X11
name|x11
decl_stmt|;
typedef|typedef
name|int
name|X11array
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|X11
argument_list|)
index|]
typedef|;
name|x11
operator|.
name|y
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X11
argument_list|)
expr_stmt|;
name|struct
name|X12
name|x12
decl_stmt|;
name|x12
operator|.
name|x
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X12
argument_list|)
expr_stmt|;
name|struct
name|X13
name|x13
decl_stmt|;
name|x13
operator|.
name|x
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X13
argument_list|)
expr_stmt|;
name|union
name|X14
name|x14
decl_stmt|;
name|x14
operator|.
name|x
operator|=
sizeof|sizeof
argument_list|(
expr|union
name|X14
argument_list|)
expr_stmt|;
name|struct
name|X15
name|x15
decl_stmt|;
name|x15
operator|.
name|x
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X15
argument_list|)
expr_stmt|;
name|struct
name|X16
name|x16
decl_stmt|;
name|x16
operator|.
name|x
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|X16
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

