begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)domain.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structure per communications domain.  */
end_comment

begin_comment
comment|/*  * Forward structure declarations for function prototypes [sic].  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

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
name|void
argument_list|(
argument|*dom_init
argument_list|)
comment|/* initialize domain data structures */
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*dom_externalize
argument_list|)
comment|/* externalize access rights */
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*dom_dispose
argument_list|)
comment|/* dispose of internalized rights */
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|int
argument_list|(
argument|*dom_rtattach
argument_list|)
comment|/* initialize routing table */
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
name|dom_rtoffset
decl_stmt|;
comment|/* an arg to rtattach, in bits */
name|int
name|dom_maxrtkey
decl_stmt|;
comment|/* for routing layer */
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

