begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: getdtablesize.c,v 1.5 1997/07/21 14:06:26 jtc Exp	*/
end_comment

begin_comment
comment|/*  * Written by J.T. Conklin<jtc@netbsd.org>.  * Public domain.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id$"
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
file|<unistd.h>
end_include

begin_function
name|int
name|getdtablesize
parameter_list|()
block|{
return|return
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
return|;
block|}
end_function

end_unit

