begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)declare.h	4.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Declarations of routines from the controller.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|AddHost
argument_list|()
decl_stmt|,
name|DoReadModified
argument_list|()
decl_stmt|,
name|DoReadBuffer
argument_list|()
decl_stmt|,
name|OptInit
argument_list|()
decl_stmt|,
name|SendToIBM
argument_list|()
decl_stmt|,
name|SendTransparent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DataFrom3270
argument_list|()
decl_stmt|,
name|DataFromNetwork
argument_list|()
decl_stmt|,
name|OptOrder
argument_list|()
decl_stmt|,
name|OutputClock
decl_stmt|,
name|TransparentClock
decl_stmt|;
end_decl_stmt

end_unit

