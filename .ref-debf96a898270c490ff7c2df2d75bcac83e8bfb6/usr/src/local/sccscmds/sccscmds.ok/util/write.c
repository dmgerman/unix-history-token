begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"../hdr/macros.h"
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_define
define|#
directive|define
name|syswrite
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|syscall(SYS_write,a,b,c)
end_define

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|write
literal|2.1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	Interface to write(II) (called syswrite) which handles 	all error conditions. 	Returns number of bytes written on success, 	returns fatal(<mesg>) on failure. */
end_comment

begin_macro
name|write
argument_list|(
argument|fildes
argument_list|,
argument|buffer
argument_list|,
argument|nbytes
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buffer
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|n
decl_stmt|;
if|if
condition|(
name|nbytes
operator|>
literal|0
operator|&&
operator|(
name|n
operator|=
name|syswrite
argument_list|(
name|fildes
argument_list|,
name|buffer
argument_list|,
name|nbytes
argument_list|)
operator|)
operator|!=
name|nbytes
condition|)
name|n
operator|=
name|xmsg
argument_list|(
literal|""
argument_list|,
literal|"write"
argument_list|)
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

end_unit

