begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)rdwr.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These routines are used to access the debuggee process from  * outside the "process" module.  *  * They invoke "pio" which eventually leads to a call to "ptrace".  * The system generates an I/O error when a ptrace fails, we catch  * that here and assume its due to a misguided address.  */
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

begin_if
if|#
directive|if
operator|(
name|isvaxpx
operator|)
end_if

begin_include
include|#
directive|include
file|"pxinfo.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|LOCAL
name|rwerr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read from the process' instruction area.  For px, this is actually  * the data area.  */
end_comment

begin_macro
name|iread
argument_list|(
argument|buff
argument_list|,
argument|addr
argument_list|,
argument|nbytes
argument_list|)
end_macro

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
operator|&
name|rwerr
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|isvaxpx
operator|)
name|badaddr
operator|=
name|addr
operator|+
name|ENDOFF
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|PREAD
argument_list|,
name|DATASEG
argument_list|,
name|buff
argument_list|,
name|addr
operator|+
name|ENDOFF
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
else|#
directive|else
name|badaddr
operator|=
name|addr
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|PREAD
argument_list|,
name|TEXTSEG
argument_list|,
name|buff
argument_list|,
name|addr
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
comment|/*   * Write to the process' instruction area, usually in order to set  * or unset a breakpoint.  */
end_comment

begin_macro
name|iwrite
argument_list|(
argument|buff
argument_list|,
argument|addr
argument_list|,
argument|nbytes
argument_list|)
end_macro

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
operator|&
name|rwerr
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|isvaxpx
operator|)
name|badaddr
operator|=
name|addr
operator|+
name|ENDOFF
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|PWRITE
argument_list|,
name|DATASEG
argument_list|,
name|buff
argument_list|,
name|addr
operator|+
name|ENDOFF
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
else|#
directive|else
name|badaddr
operator|=
name|addr
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|PWRITE
argument_list|,
name|TEXTSEG
argument_list|,
name|buff
argument_list|,
name|addr
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
comment|/*  * Read for the process' data area.  */
end_comment

begin_macro
name|dread
argument_list|(
argument|buff
argument_list|,
argument|addr
argument_list|,
argument|nbytes
argument_list|)
end_macro

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
operator|&
name|rwerr
argument_list|)
expr_stmt|;
name|badaddr
operator|=
name|addr
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|PREAD
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
comment|/*  * Write to the process' data area.  */
end_comment

begin_macro
name|dwrite
argument_list|(
argument|buff
argument_list|,
argument|addr
argument_list|,
argument|nbytes
argument_list|)
end_macro

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
operator|&
name|rwerr
argument_list|)
expr_stmt|;
name|badaddr
operator|=
name|addr
expr_stmt|;
name|pio
argument_list|(
name|process
argument_list|,
name|PWRITE
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
literal|"bad read/write process address 0x%x"
argument_list|,
name|badaddr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

