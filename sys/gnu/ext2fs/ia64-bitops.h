begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_EXT2FS_BITOPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_GNU_EXT2FS_BITOPS_H_
end_define

begin_define
define|#
directive|define
name|find_first_zero_bit
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
value|find_next_zero_bit(addr,size,0)
end_define

begin_function
specifier|static
name|__inline
name|int
name|clear_bit
parameter_list|(
name|int
name|no
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|panic
argument_list|(
literal|"ext2fs: clear_bit() unimplemented"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|set_bit
parameter_list|(
name|int
name|no
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|panic
argument_list|(
literal|"ext2fs: set_bit() unimplemented"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|test_bit
parameter_list|(
name|int
name|no
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|panic
argument_list|(
literal|"ext2fs: clear_bit() unimplemented"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|size_t
name|find_next_zero_bit
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|ofs
parameter_list|)
block|{
name|panic
argument_list|(
literal|"ext2fs: find_next_zero_bit() unimplemented"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|memscan
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|sz
parameter_list|)
block|{
name|panic
argument_list|(
literal|"ext2fs: memscan() unimplemented"
argument_list|)
expr_stmt|;
return|return
operator|(
name|addr
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GNU_EXT2FS_BITOPS_H_ */
end_comment

end_unit

