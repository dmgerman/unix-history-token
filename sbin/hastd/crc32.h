begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  COPYRIGHT (C) 1986 Gary S. Brown.  You may use this program, or  *  code or tables extracted from it, as desired without restriction.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRC32_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRC32_H_
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/* uint32_t */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|crc32_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|uint32_t
name|crc32
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
specifier|const
name|uint8_t
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|uint32_t
name|crc
decl_stmt|;
name|crc
operator|=
operator|~
literal|0U
expr_stmt|;
while|while
condition|(
name|size
operator|--
condition|)
name|crc
operator|=
name|crc32_tab
index|[
operator|(
name|crc
operator|^
operator|*
name|p
operator|++
operator|)
operator|&
literal|0xFF
index|]
operator|^
operator|(
name|crc
operator|>>
literal|8
operator|)
expr_stmt|;
return|return
operator|(
name|crc
operator|^
operator|~
literal|0U
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CRC32_H_ */
end_comment

end_unit

