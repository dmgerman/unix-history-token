begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_comment
comment|// PR 1861
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__u32
name|__le32
typedef|;
end_typedef

begin_struct
struct|struct
name|bcm43xx_plcp_hdr6
block|{
union|union
block|{
name|__le32
name|data
decl_stmt|;
name|__u8
name|raw
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bcm43xx_txhdr
block|{
union|union
block|{
struct|struct
block|{
name|struct
name|bcm43xx_plcp_hdr6
name|plcp
decl_stmt|;
block|}
struct|;
block|}
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_function
specifier|static
name|void
name|bcm43xx_generate_rts
parameter_list|(
name|struct
name|bcm43xx_txhdr
modifier|*
name|txhdr
parameter_list|)
block|{ }
end_function

end_unit

