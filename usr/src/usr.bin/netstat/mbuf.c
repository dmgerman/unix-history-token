begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)mbuf.c	4.1 82/08/25"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_decl_stmt
name|struct
name|mbstat
name|mbstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print mbuf statistics.  */
end_comment

begin_macro
name|mbpr
argument_list|(
argument|mbaddr
argument_list|)
end_macro

begin_decl_stmt
name|off_t
name|mbaddr
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|mbaddr
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"mbstat: symbol not in namelist\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|printf
argument_list|(
literal|"mbufs:"
argument_list|)
expr_stmt|;
name|klseek
argument_list|(
name|kmem
argument_list|,
name|mbaddr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
name|kmem
argument_list|,
operator|&
name|mbstat
argument_list|,
sizeof|sizeof
argument_list|(
name|mbstat
argument_list|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|mbstat
argument_list|)
condition|)
name|printf
argument_list|(
literal|" mbufs %d mbfree %d clusters %d clfree %d drops %d\n"
argument_list|,
name|mbstat
operator|.
name|m_mbufs
argument_list|,
name|mbstat
operator|.
name|m_mbfree
argument_list|,
name|mbstat
operator|.
name|m_clusters
argument_list|,
name|mbstat
operator|.
name|m_clfree
argument_list|,
name|mbstat
operator|.
name|m_drops
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

