begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
end_comment

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
literal|"@(#)line.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_extern
extern|extern vti;
end_extern

begin_extern
extern|extern xnow
operator|,
extern|ynow;
end_extern

begin_macro
name|line
argument_list|(
argument|x0
argument_list|,
argument|y0
argument_list|,
argument|x1
argument_list|,
argument|y1
argument_list|)
end_macro

begin_block
block|{
struct|struct
block|{
name|char
name|x
decl_stmt|,
name|c
decl_stmt|;
name|int
name|x0
decl_stmt|,
name|y0
decl_stmt|,
name|x1
decl_stmt|,
name|y1
decl_stmt|;
block|}
name|p
struct|;
name|p
operator|.
name|c
operator|=
literal|3
expr_stmt|;
name|p
operator|.
name|x0
operator|=
name|xsc
argument_list|(
name|x0
argument_list|)
expr_stmt|;
name|p
operator|.
name|y0
operator|=
name|ysc
argument_list|(
name|y0
argument_list|)
expr_stmt|;
name|p
operator|.
name|x1
operator|=
name|xnow
operator|=
name|xsc
argument_list|(
name|x1
argument_list|)
expr_stmt|;
name|p
operator|.
name|y1
operator|=
name|ynow
operator|=
name|ysc
argument_list|(
name|y1
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|p
operator|.
name|c
argument_list|,
literal|9
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cont
argument_list|(
argument|x0
argument_list|,
argument|y0
argument_list|)
end_macro

begin_block
block|{
name|line
argument_list|(
name|xnow
argument_list|,
name|ynow
argument_list|,
name|xsc
argument_list|(
name|x0
argument_list|)
argument_list|,
name|ysc
argument_list|(
name|y0
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

