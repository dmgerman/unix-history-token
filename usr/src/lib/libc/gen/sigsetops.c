begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)sigsetops.c	5.2 (Berkeley) %G%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)sigsetops.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_undef
undef|#
directive|undef
name|sigemptyset
end_undef

begin_undef
undef|#
directive|undef
name|sigfillset
end_undef

begin_undef
undef|#
directive|undef
name|sigaddset
end_undef

begin_undef
undef|#
directive|undef
name|sigdelset
end_undef

begin_undef
undef|#
directive|undef
name|sigismember
end_undef

begin_macro
name|sigemptyset
argument_list|(
argument|set
argument_list|)
end_macro

begin_decl_stmt
name|sigset_t
modifier|*
name|set
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|set
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|sigfillset
argument_list|(
argument|set
argument_list|)
end_macro

begin_decl_stmt
name|sigset_t
modifier|*
name|set
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|set
operator|=
operator|~
operator|(
name|sigset_t
operator|)
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|sigaddset
argument_list|(
argument|set
argument_list|,
argument|signo
argument_list|)
end_macro

begin_decl_stmt
name|sigset_t
modifier|*
name|set
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|signo
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|set
operator||=
name|sigmask
argument_list|(
name|signo
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|sigdelset
argument_list|(
argument|set
argument_list|,
argument|signo
argument_list|)
end_macro

begin_decl_stmt
name|sigset_t
modifier|*
name|set
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|signo
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|set
operator|&=
operator|~
name|sigmask
argument_list|(
name|signo
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|sigismember
argument_list|(
argument|set
argument_list|,
argument|signo
argument_list|)
end_macro

begin_decl_stmt
name|sigset_t
modifier|*
name|set
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|signo
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
operator|*
name|set
operator|&
operator|~
name|sigmask
argument_list|(
name|signo
argument_list|)
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_block

end_unit

