begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)rdwr.c	5.3 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * This routine is used to access the debuggee process from  * outside the "process" module.  *  * They invoke "pio" which eventually leads to a call to "ptrace".  * The system generates an I/O error when a ptrace fails, we catch  * that here and assume its due to a misguided address.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"process.rep"
end_include

begin_include
include|#
directive|include
file|"pxinfo.h"
end_include

begin_typedef
typedef|typedef
name|int
name|INTFUNC
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|INTFUNC
modifier|*
name|onsyserr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|LOCAL
name|badaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|PIO_OP
name|rwflg
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LOCAL
name|rwerr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read/Write to the process' data area.  */
end_comment

begin_macro
name|drdwr
argument_list|(
argument|rw
argument_list|,
argument|buff
argument_list|,
argument|addr
argument_list|,
argument|nbytes
argument_list|)
end_macro

begin_decl_stmt
name|PIO_OP
name|rw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbytes
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|INTFUNC
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|onsyserr
argument_list|(
name|EIO
argument_list|,
name|rwerr
argument_list|)
expr_stmt|;
name|badaddr
operator|=
name|addr
expr_stmt|;
name|rwflg
operator|=
name|rw
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|rw
argument_list|,
name|DATASEG
argument_list|,
name|buff
argument_list|,
name|addr
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
name|onsyserr
argument_list|(
name|EIO
argument_list|,
name|f
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Error handler.  */
end_comment

begin_function
name|LOCAL
name|rwerr
parameter_list|()
block|{
name|error
argument_list|(
literal|"bad %s process address 0x%x"
argument_list|,
name|rwflg
operator|==
name|PREAD
condition|?
literal|"read"
else|:
literal|"write"
argument_list|,
name|badaddr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

