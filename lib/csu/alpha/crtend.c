begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: crtend.c,v 1.2 1997/10/10 08:45:30 mrg Exp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_COMPAT
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*__CTOR_LIST__[
literal|1
argument|]
argument_list|)
name|__P
argument_list|(
argument|(void)
argument_list|)
name|__attribute__
argument_list|(
argument|(__unused__)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".ctors"
argument_list|)
operator|)
argument_list|)
operator|=
block|{
operator|(
name|void
operator|*
operator|)
literal|0
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*__DTOR_LIST__[
literal|1
argument|]
argument_list|)
name|__P
argument_list|(
argument|(void)
argument_list|)
name|__attribute__
argument_list|(
argument|(__unused__)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".dtors"
argument_list|)
operator|)
argument_list|)
operator|=
block|{
operator|(
name|void
operator|*
operator|)
literal|0
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ECOFF_COMPAT */
end_comment

end_unit

