begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "System header" for testing GNU libc keyword conflict workarounds */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|union
name|w
modifier|*
name|__uptr
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|MS
argument_list|)
operator|&&
name|defined
argument_list|(
name|NOT_SYSTEM
argument_list|)
comment|// expected-warning@-2 {{keyword '__uptr' will be made available as an identifier here}}
endif|#
directive|endif
name|int
modifier|*
name|__iptr
decl_stmt|;
block|}
name|WS
name|__attribute__
typedef|((
name|__transparent_union__
typedef|));
end_typedef

end_unit

