begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	map.h	4.4	81/02/27	*/
end_comment

begin_comment
comment|/*  * Resource Allocation Maps  */
end_comment

begin_struct
struct|struct
name|map
block|{
name|int
name|m_size
decl_stmt|;
name|int
name|m_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|map
modifier|*
name|swapmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nswapmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
modifier|*
name|argmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
modifier|*
name|kernelmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

