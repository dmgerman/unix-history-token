begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)wwprintf.c	3.1 83/08/11"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_comment
comment|/*VARARGS2*/
end_comment

begin_macro
name|wwprintf
argument_list|(
argument|w
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|ww
modifier|*
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|_iobuf
name|_wwbuf
decl_stmt|;
specifier|static
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
comment|/* 	 * A danger is that when buf overflows, _flsbuf() will be 	 * called automatically.  It doesn't check for _IOSTR. 	 * We set the file descriptor to -1 so no actual io will be done. 	 */
name|_wwbuf
operator|.
name|_flag
operator|=
name|_IOWRT
operator|+
name|_IOSTRG
expr_stmt|;
name|_wwbuf
operator|.
name|_base
operator|=
name|_wwbuf
operator|.
name|_ptr
operator|=
name|buf
expr_stmt|;
name|_wwbuf
operator|.
name|_cnt
operator|=
sizeof|sizeof
name|buf
expr_stmt|;
name|_wwbuf
operator|.
name|_file
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* safe */
name|_doprnt
argument_list|(
name|fmt
argument_list|,
operator|&
name|args
argument_list|,
operator|&
name|_wwbuf
argument_list|)
expr_stmt|;
return|return
name|wwwrite
argument_list|(
name|w
argument_list|,
name|buf
argument_list|,
name|_wwbuf
operator|.
name|_ptr
operator|-
name|buf
argument_list|)
return|;
block|}
end_block

end_unit

