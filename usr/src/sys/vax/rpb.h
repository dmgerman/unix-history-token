begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)rpb.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * The restart parameter block, which is a page in (very) low  * core which runs after a crash.  Currently, the restart  * procedure takes a dump.  */
end_comment

begin_struct
struct|struct
name|rpb
block|{
name|struct
name|rpb
modifier|*
name|rp_selfref
decl_stmt|;
comment|/* self-reference */
name|int
function_decl|(
modifier|*
name|rp_dumprout
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to be called */
name|long
name|rp_checksum
decl_stmt|;
comment|/* checksum of 31 words of dumprout */
name|long
name|rp_flag
decl_stmt|;
comment|/* set to 1 when dumprout runs */
comment|/* the dump stack grows from the end of the rpb page not to reach here */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|rpb
name|rpb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

