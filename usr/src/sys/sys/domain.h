begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	domain.h	5.1	5.1	*/
end_comment

begin_comment
comment|/*  * Structure for a communications domain.  * Each communications domain supports a set or protocols,  * which are contained in a protocol table located through  * this structure.  */
end_comment

begin_struct
struct|struct
name|domain
block|{
name|char
modifier|*
name|dom_name
decl_stmt|;
name|struct
name|protosw
modifier|*
name|dom_proto
decl_stmt|;
name|int
name|dom_nproto
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
name|domain
modifier|*
name|domains
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

