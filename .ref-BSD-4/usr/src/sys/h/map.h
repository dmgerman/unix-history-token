begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	map.h	4.1	11/9/80	*/
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
name|swapmap
index|[
name|SMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space for swap allocation */
end_comment

begin_define
define|#
directive|define
name|AMAPSIZ
value|25
end_define

begin_decl_stmt
name|struct
name|map
name|argmap
index|[
name|AMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|map
name|kernelmap
index|[
name|NPROC
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space for kernel map for user page tables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

