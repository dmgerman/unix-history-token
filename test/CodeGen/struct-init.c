begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm-only
end_comment

begin_typedef
typedef|typedef
name|struct
name|_zend_ini_entry
name|zend_ini_entry
typedef|;
end_typedef

begin_struct
struct|struct
name|_zend_ini_entry
block|{
name|void
modifier|*
name|mh_arg1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|zend_ini_entry
name|ini_entries
index|[]
init|=
block|{
block|{
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
operator|(
name|zend_ini_entry
operator|*
operator|)
literal|0
operator|)
operator|->
name|mh_arg1
operator|-
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR7564
end_comment

begin_struct
struct|struct
name|GLGENH
block|{
name|int
label|:
literal|27
expr_stmt|;
name|int
name|EMHJAA
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|GLGENH
name|ABHFBF
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|unsigned
name|int
name|uint2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( __vector_size__(
literal|8
argument|) )
argument_list|)
name|unsigned
name|int
name|__neon_uint32x2_t
typedef|;
end_typedef

begin_comment
comment|// rdar://8183908
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__simd64_uint32_t
block|{
name|__neon_uint32x2_t
name|val
decl_stmt|;
block|}
name|uint32x2_t
typedef|;
end_typedef

begin_function
name|void
name|foo
parameter_list|()
block|{
specifier|const
name|uint32x2_t
name|signBit
init|=
block|{
operator|(
name|uint2
operator|)
literal|0x80000000
block|}
decl_stmt|;
block|}
end_function

end_unit

