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
literal|"@(#)wwprintf.c	1.3 83/07/19"
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

begin_comment
comment|/* wwprintf(w, fmt, args) struct ww *w; char *fmt; { 	_doprnt(fmt,&args, w); 	return 0; }  _strout(count, string, adjust, file, fillch) register char *string; register count; int adjust; register struct ww *file; { 	while (adjust< 0) { 		if (*string=='-'&& fillch=='0') { 			wputc(*string++, file); 			count--; 		} 		wputc(fillch, file); 		adjust++; 	} 	while (--count>=0) 		wputc(*string++, file); 	while (adjust) { 		wputc(fillch, file); 		adjust--; 	} } */
end_comment

end_unit

