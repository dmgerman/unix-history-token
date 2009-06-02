begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - %s | grep {18}
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|a
decl_stmt|;
block|}
name|foo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|major
decl_stmt|;
name|uint8_t
name|minor
decl_stmt|;
name|uint16_t
name|build
decl_stmt|;
block|}
name|VERSION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|a
index|[
literal|5
index|]
decl_stmt|;
name|VERSION
name|version
decl_stmt|;
name|uint8_t
name|b
decl_stmt|;
name|foo
name|d
decl_stmt|;
name|uint32_t
name|guard
decl_stmt|;
block|}
name|bar
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_function
name|unsigned
name|barsize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|bar
argument_list|)
return|;
block|}
end_function

end_unit

