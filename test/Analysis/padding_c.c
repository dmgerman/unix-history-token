begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=optin.performance -analyzer-config optin.performance.Padding:AllowedPad=2 -verify %s
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|stdalign
operator|.
name|h
operator|>
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdalign.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|stdalign
operator|.
name|h
operator|>
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|// expected-warning@+1{{Excessive padding in 'struct FieldAttrAlign' (6 padding}}
end_comment

begin_struct
struct|struct
name|FieldAttrAlign
block|{
name|char
name|c1
decl_stmt|;
name|alignas
argument_list|(
literal|4
argument_list|)
name|int
name|i
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning@+1{{Excessive padding in 'struct FieldAttrOverAlign' (10 padding}}
end_comment

begin_struct
struct|struct
name|FieldAttrOverAlign
block|{
name|char
name|c1
decl_stmt|;
name|alignas
argument_list|(
literal|8
argument_list|)
name|int
name|i
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __has_include(<stdalign.h>) || defined(__cplusplus)
end_comment

begin_comment
comment|// Re-ordering members of these structs won't reduce padding, so don't warn
end_comment

begin_struct
struct|struct
name|LeadingChar
block|{
comment|// no-warning
name|char
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|TrailingChar
block|{
comment|// no-warning
name|int
name|i
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Helpless
block|{
comment|// no-warning
name|struct
name|TrailingChar
name|i1
decl_stmt|;
name|struct
name|LeadingChar
name|i2
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|SquishedIntSandwich
block|{
comment|// no-warning
name|char
name|c1
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
name|c2
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

begin_comment
comment|// Re-ordering members of these structs will reduce padding, so warn
end_comment

begin_struct
struct|struct
name|IntSandwich
block|{
comment|// expected-warning{{Excessive padding in 'struct IntSandwich'}}
name|char
name|c1
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|TurDuckHen
block|{
comment|// expected-warning{{Excessive padding in 'struct TurDuckHen'}}
name|char
name|c1
decl_stmt|;
name|struct
name|IntSandwich
name|i
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|2
name|)
end_pragma

begin_struct
struct|struct
name|SmallIntSandwich
block|{
comment|// expected-warning{{Excessive padding in 'struct SmallIntSandwich'}}
name|char
name|c1
decl_stmt|;
name|int
name|i1
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|char
name|c3
decl_stmt|;
name|int
name|i3
decl_stmt|;
name|char
name|c4
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

begin_union
union|union
name|SomeUnion
block|{
comment|// no-warning
name|char
name|c
decl_stmt|;
name|short
name|s
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|HoldsAUnion
block|{
comment|// expected-warning{{Excessive padding in 'struct HoldsAUnion'}}
name|char
name|c1
decl_stmt|;
name|union
name|SomeUnion
name|u
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|BigCharArray
block|{
comment|// no-warning
name|char
name|c
index|[
literal|129
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|SmallCharArray
block|{
comment|// no-warning
name|char
name|c
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|MediumIntArray
block|{
comment|// no-warning
name|int
name|i
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LargeSizeToSmallSize
block|{
comment|// expected-warning{{Excessive padding in 'struct LargeSizeToSmallSize'}}
name|struct
name|BigCharArray
name|b
decl_stmt|;
name|struct
name|MediumIntArray
name|m
decl_stmt|;
name|struct
name|SmallCharArray
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LargeAlignToSmallAlign
block|{
comment|// no-warning
name|struct
name|MediumIntArray
name|m
decl_stmt|;
name|struct
name|BigCharArray
name|b
decl_stmt|;
name|struct
name|SmallCharArray
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Currently ignoring VLA padding problems.  Still need to make sure we don't
end_comment

begin_comment
comment|// choke on VLAs though
end_comment

begin_struct
struct|struct
name|HoldsVLA
block|{
comment|// no-warning
name|char
name|c1
decl_stmt|;
name|int
name|x
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|int
name|vla
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Currently ignoring bitfield padding problems.  Still need to make sure we
end_comment

begin_comment
comment|// don't choke on bitfields though
end_comment

begin_struct
struct|struct
name|HoldsBitfield
block|{
comment|// no-warning
name|char
name|c1
decl_stmt|;
name|int
name|x
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|unsigned
name|char
name|b1
range|:
literal|3
decl_stmt|;
name|unsigned
name|char
name|b2
range|:
literal|3
decl_stmt|;
name|unsigned
name|char
name|b3
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// expected-warning{{Excessive padding in 'TypedefSandwich'}}
name|char
name|c1
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|TypedefSandwich
typedef|;
end_typedef

begin_comment
comment|// expected-warning@+1{{Excessive padding in 'struct StructAttrAlign' (10 padding}}
end_comment

begin_struct
struct|struct
name|StructAttrAlign
block|{
name|char
name|c1
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|CorrectOverlyAlignedChar
block|{
comment|// no-warning
name|char
name|c
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4096
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|int
name|x1
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|int
name|x2
decl_stmt|;
name|char
name|c3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|OverlyAlignedChar
block|{
comment|// expected-warning{{Excessive padding in 'struct OverlyAlignedChar'}}
name|char
name|c1
decl_stmt|;
name|int
name|x
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|char
name|c
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4096
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|HoldsOverlyAlignedChar
block|{
comment|// expected-warning{{Excessive padding in 'struct HoldsOverlyAlignedChar'}}
name|char
name|c1
decl_stmt|;
name|struct
name|OverlyAlignedChar
name|o
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|internalStructFunc
parameter_list|()
block|{
struct|struct
name|X
block|{
comment|// expected-warning{{Excessive padding in 'struct X'}}
name|char
name|c1
decl_stmt|;
name|int
name|t
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
name|struct
name|X
name|obj
decl_stmt|;
block|}
end_function

begin_function
name|void
name|typedefStructFunc
parameter_list|()
block|{
typedef|typedef
struct|struct
block|{
comment|// expected-warning{{Excessive padding in 'S'}}
name|char
name|c1
decl_stmt|;
name|int
name|t
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|S
typedef|;
name|S
name|obj
decl_stmt|;
block|}
end_function

begin_function
name|void
name|anonStructFunc
parameter_list|()
block|{
struct|struct
block|{
comment|// expected-warning{{Excessive padding in 'struct (anonymous}}
name|char
name|c1
decl_stmt|;
name|int
name|t
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|obj
struct|;
block|}
end_function

begin_struct
struct|struct
name|CorrectDefaultAttrAlign
block|{
comment|// no-warning
name|long
name|long
name|i
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|TooSmallShortSandwich
block|{
comment|// no-warning
name|char
name|c1
decl_stmt|;
name|short
name|s
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning@+1{{Excessive padding in 'struct SmallArrayShortSandwich'}}
end_comment

begin_struct
struct|struct
name|SmallArrayShortSandwich
block|{
name|char
name|c1
decl_stmt|;
name|short
name|s
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|ShortArray
index|[
literal|20
index|]
struct|;
end_struct

begin_comment
comment|// expected-warning@+1{{Excessive padding in 'struct SmallArrayInFunc'}}
end_comment

begin_struct
struct|struct
name|SmallArrayInFunc
block|{
name|char
name|c1
decl_stmt|;
name|short
name|s
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|arrayHolder
parameter_list|()
block|{
name|struct
name|SmallArrayInFunc
name|Arr
index|[
literal|15
index|]
decl_stmt|;
block|}
end_function

begin_comment
comment|// xxxexpected-warning@+1{{Excessive padding in 'struct SmallArrayInStruct'}}
end_comment

begin_struct
struct|struct
name|SmallArrayInStruct
block|{
name|char
name|c1
decl_stmt|;
name|short
name|s
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|HoldsSmallArray
block|{
name|struct
name|SmallArrayInStruct
name|Field
index|[
literal|20
index|]
decl_stmt|;
block|}
name|HoldsSmallArrayElt
struct|;
end_struct

begin_function
name|void
name|nestedPadding
parameter_list|()
block|{
name|struct
name|HoldsSmallArray
name|Arr
index|[
literal|15
index|]
decl_stmt|;
block|}
end_function

end_unit

