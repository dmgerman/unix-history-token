begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	domain.h	5.2	82/08/01	*/
end_comment

begin_comment
comment|/*  * Structure per communications domain.  */
end_comment

begin_struct
struct|struct
name|domain
block|{
name|int
name|dom_family
decl_stmt|;
comment|/* AF_xxx */
name|char
modifier|*
name|dom_name
decl_stmt|;
name|struct
name|protosw
modifier|*
name|dom_protosw
decl_stmt|,
modifier|*
name|dom_protoswNPROTOSW
decl_stmt|;
name|struct
name|domain
modifier|*
name|dom_next
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

