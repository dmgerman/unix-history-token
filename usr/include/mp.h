begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mp.h	5.1 (Berkeley) 5/30/85  */
end_comment

begin_define
define|#
directive|define
name|MINT
value|struct mint
end_define

begin_macro
name|MINT
end_macro

begin_block
block|{
name|int
name|len
decl_stmt|;
name|short
modifier|*
name|val
decl_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|x
parameter_list|)
value|{if(x.len!=0) {free((char *)x.val); x.len=0;}}
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DBG
end_ifndef

begin_define
define|#
directive|define
name|shfree
parameter_list|(
name|u
parameter_list|)
value|free((char *)u)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|shfree
parameter_list|(
name|u
parameter_list|)
value|{ if(dbg) fprintf(stderr, "free %o\n", u); free((char *)u);}
end_define

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

begin_struct
struct|struct
name|half
block|{
name|short
name|high
decl_stmt|;
name|short
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|half
block|{
name|short
name|low
decl_stmt|;
name|short
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|MINT
modifier|*
name|itom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
modifier|*
name|xalloc
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_extern
extern|extern xv_oid;
end_extern

begin_define
define|#
directive|define
name|VOID
value|xv_oid =
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

