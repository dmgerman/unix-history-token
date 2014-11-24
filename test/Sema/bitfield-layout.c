begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -triple=i686-apple-darwin9
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_define
define|#
directive|define
name|CHECK_SIZE
parameter_list|(
name|kind
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
value|extern int name##1[sizeof(kind name) == size ? 1 : -1];
end_define

begin_define
define|#
directive|define
name|CHECK_ALIGN
parameter_list|(
name|kind
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
value|extern int name##2[__alignof(kind name) == size ? 1 : -1];
end_define

begin_comment
comment|// Zero-width bit-fields
end_comment

begin_struct
struct|struct
name|a
block|{
name|char
name|x
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|a
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|a
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|// Zero-width bit-fields with packed
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|a2
block|{
name|short
name|x
range|:
literal|9
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|int
name|y
range|:
literal|17
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|a2
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|a2
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|// Zero-width bit-fields at the end of packed struct
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|a3
block|{
name|short
name|x
range|:
literal|9
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|a3
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|a3
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|// For comparison, non-zero-width bit-fields at the end of packed struct
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|a4
block|{
name|short
name|x
range|:
literal|9
decl_stmt|;
name|int
label|:
literal|1
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|a4
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|a4
argument_list|,
literal|1
argument_list|)
end_macro

begin_union
union|union
name|b
block|{
name|char
name|x
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|y
decl_stmt|;
block|}
union|;
end_union

begin_macro
name|CHECK_SIZE
argument_list|(
argument|union
argument_list|,
argument|b
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|union
argument_list|,
argument|b
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|// Unnamed bit-field align
end_comment

begin_struct
struct|struct
name|c
block|{
name|char
name|x
decl_stmt|;
name|int
label|:
literal|20
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|c
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|c
argument_list|,
literal|1
argument_list|)
end_macro

begin_union
union|union
name|d
block|{
name|char
name|x
decl_stmt|;
name|int
label|:
literal|20
expr_stmt|;
block|}
union|;
end_union

begin_macro
name|CHECK_SIZE
argument_list|(
argument|union
argument_list|,
argument|d
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|union
argument_list|,
argument|d
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|// Bit-field packing
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|e
block|{
name|int
name|x
range|:
literal|4
decl_stmt|,
name|y
range|:
literal|30
decl_stmt|,
name|z
range|:
literal|30
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|e
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|e
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|// Alignment on bit-fields
end_comment

begin_struct
struct|struct
name|f
block|{
name|__attribute
argument_list|(
argument|(aligned(
literal|8
argument|))
argument_list|)
name|int
name|x
range|:
literal|30
decl_stmt|,
name|y
range|:
literal|30
decl_stmt|,
name|z
range|:
literal|30
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|f
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|f
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|// Large structure (overflows i32, in bits).
end_comment

begin_struct
struct|struct
name|s0
block|{
name|char
name|a
index|[
literal|0x32100000
index|]
decl_stmt|;
name|int
name|x
range|:
literal|30
decl_stmt|,
name|y
range|:
literal|30
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|CHECK_SIZE
argument_list|(
argument|struct
argument_list|,
argument|s0
argument_list|,
literal|0x32100008
argument_list|)
end_macro

begin_macro
name|CHECK_ALIGN
argument_list|(
argument|struct
argument_list|,
argument|s0
argument_list|,
literal|4
argument_list|)
end_macro

end_unit

