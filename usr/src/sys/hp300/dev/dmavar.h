begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dmavar.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* dmago flags */
end_comment

begin_define
define|#
directive|define
name|DMAGO_BYTE
value|0x00
end_define

begin_define
define|#
directive|define
name|DMAGO_WORD
value|0x01
end_define

begin_define
define|#
directive|define
name|DMAGO_LWORD
value|0x02
end_define

begin_define
define|#
directive|define
name|DMAGO_PRI
value|0x04
end_define

begin_define
define|#
directive|define
name|DMAGO_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|DMAGO_NOINT
value|0x80
end_define

begin_comment
comment|/* dma "controllers" (channels) */
end_comment

begin_define
define|#
directive|define
name|DMA0
value|0x1
end_define

begin_define
define|#
directive|define
name|DMA1
value|0x2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dmago
argument_list|()
decl_stmt|,
name|dmafree
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|dmareq
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

