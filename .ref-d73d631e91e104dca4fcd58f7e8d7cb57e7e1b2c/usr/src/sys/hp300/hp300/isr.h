begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)isr.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|isr
block|{
name|struct
name|isr
modifier|*
name|isr_forw
decl_stmt|;
name|struct
name|isr
modifier|*
name|isr_back
decl_stmt|;
name|int
function_decl|(
modifier|*
name|isr_intr
function_decl|)
parameter_list|()
function_decl|;
name|int
name|isr_arg
decl_stmt|;
name|int
name|isr_ipl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NISR
value|3
end_define

begin_define
define|#
directive|define
name|ISRIPL
parameter_list|(
name|x
parameter_list|)
value|((x) - 3)
end_define

end_unit

