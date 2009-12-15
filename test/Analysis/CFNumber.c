begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic -analyzer-constraints=basic -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic -analyzer-constraints=range -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=region -analyzer-constraints=basic -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=region -analyzer-constraints=range -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_typedef
typedef|typedef
name|signed
name|long
name|CFIndex
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFAllocator
modifier|*
name|CFAllocatorRef
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|kCFNumberSInt8Type
init|=
literal|1
block|,
name|kCFNumberSInt16Type
init|=
literal|2
block|,
name|kCFNumberSInt32Type
init|=
literal|3
block|,
name|kCFNumberSInt64Type
init|=
literal|4
block|,
name|kCFNumberFloat32Type
init|=
literal|5
block|,
name|kCFNumberFloat64Type
init|=
literal|6
block|,
name|kCFNumberCharType
init|=
literal|7
block|,
name|kCFNumberShortType
init|=
literal|8
block|,
name|kCFNumberIntType
init|=
literal|9
block|,
name|kCFNumberLongType
init|=
literal|10
block|,
name|kCFNumberLongLongType
init|=
literal|11
block|,
name|kCFNumberFloatType
init|=
literal|12
block|,
name|kCFNumberDoubleType
init|=
literal|13
block|,
name|kCFNumberCFIndexType
init|=
literal|14
block|,
name|kCFNumberNSIntegerType
init|=
literal|15
block|,
name|kCFNumberCGFloatType
init|=
literal|16
block|,
name|kCFNumberMaxType
init|=
literal|16
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|CFIndex
name|CFNumberType
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFNumber
modifier|*
name|CFNumberRef
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|CFNumberRef
name|CFNumberCreate
parameter_list|(
name|CFAllocatorRef
name|allocator
parameter_list|,
name|CFNumberType
name|theType
parameter_list|,
specifier|const
name|void
modifier|*
name|valuePtr
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|CFNumberRef
name|f1
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{
return|return
name|CFNumberCreate
argument_list|(
literal|0
argument_list|,
name|kCFNumberSInt16Type
argument_list|,
operator|&
name|x
argument_list|)
return|;
comment|// expected-warning{{An 8 bit integer is used to initialize a CFNumber object that represents a 16 bit integer. 8 bits of the CFNumber value will be garbage.}}
block|}
end_function

begin_function
name|CFNumberRef
name|f2
parameter_list|(
name|unsigned
name|short
name|x
parameter_list|)
block|{
return|return
name|CFNumberCreate
argument_list|(
literal|0
argument_list|,
name|kCFNumberSInt8Type
argument_list|,
operator|&
name|x
argument_list|)
return|;
comment|// expected-warning{{A 16 bit integer is used to initialize a CFNumber object that represents an 8 bit integer. 8 bits of the input integer will be lost.}}
block|}
end_function

begin_function
name|CFNumberRef
name|f3
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
name|CFNumberCreate
argument_list|(
literal|0
argument_list|,
name|kCFNumberLongType
argument_list|,
operator|&
name|i
argument_list|)
return|;
comment|// expected-warning{{A 32 bit integer is used to initialize a CFNumber object that represents a 64 bit integer.}}
block|}
end_function

end_unit

