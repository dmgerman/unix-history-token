begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|"IIglobals.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIgetc.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIGETC.C -- File input routines ** **	Defines: **		IIfopen() **		IIgetc() **		IIclose() ** **	Requires: **		read() **		open() ** **	Required By: **		IIp_err() -- to get text from error files **		IIgetpath(); **		USER -- as Input routines ** **	History: **		11/21/78 -- (marc) written to free IIp_err() [IIp_err.c] from **			depending on a single I/O package */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  IIFOPEN -- Buffered input file open ** **	Entirely analogous to fopen(III). ** **	Parameters: **		file - file name to open for READ only **		iobuf - iob struct to use for this file ** **	Returns: **		0  success **		-1 failure (errno set by open(II) call) ** **	Side Effects: **		file activity **		sets up iobuf ** **	Requires: **		open() ** **	Called By: **		IIp_err() [IIp_err.c] **		USER ** **	History: **		11/21/78 -- (marc) written */
end_comment

begin_macro
name|IIfopen
argument_list|(
argument|file
argument_list|,
argument|iobuf
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iob
modifier|*
name|iobuf
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|iob
modifier|*
name|b
decl_stmt|;
name|b
operator|=
name|iobuf
expr_stmt|;
if|if
condition|(
operator|(
name|b
operator|->
name|fildes
operator|=
name|open
argument_list|(
name|file
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|b
operator|->
name|nleft
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  IIGETC -- Get a character from a file using buffered input ** **	Entirely analogous to getc(III). ** **	Parameters: **		iobuf -- iob struct for the file from which the character **			is to be taken ** **	Returns: **		next character from file (16-bit no sign extension) **		-1 -- EOF or error (errno set by read) ** **	Side Effects: **		file activity - may do a read () **		fuddles iobuf to reflect number of characters left after call ** **	Requires: **		read() **		an fopen(III) or IIfopen() [IIgetc.c] call on iobuf before **			being called. (It is unwise to call fopen(), the  **			IIgetc(), because fopen() and getc(III) are both  **			in /usr/source/s4/getc.c so the code will be  **			duplicated). ** **	Called By: **		IIp_err() [IIp_err.c] **		USER ** **	History: **		11/21/78 -- (marc) written */
end_comment

begin_macro
name|IIgetc
argument_list|(
argument|iobuf
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|iobuf
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|iob
modifier|*
name|b
decl_stmt|;
specifier|register
name|i
expr_stmt|;
specifier|register
name|c
expr_stmt|;
name|b
operator|=
name|iobuf
expr_stmt|;
if|if
condition|(
operator|--
name|b
operator|->
name|nleft
operator|>=
literal|0
condition|)
block|{
name|c
operator|=
operator|*
name|b
operator|->
name|nextp
operator|++
operator|&
literal|0377
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
comment|/* else fill the buffer */
name|i
operator|=
name|read
argument_list|(
name|b
operator|->
name|fildes
argument_list|,
name|b
operator|->
name|buff
argument_list|,
sizeof|sizeof
name|b
operator|->
name|buff
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
block|{
name|b
operator|->
name|nextp
operator|=
name|b
operator|->
name|buff
expr_stmt|;
name|b
operator|->
name|nleft
operator|=
operator|--
name|i
expr_stmt|;
name|c
operator|=
operator|*
name|b
operator|->
name|nextp
operator|++
operator|&
literal|0377
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
comment|/* EOF or error */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  IICLOSE -- Close a file opened with IIfopen ** **	Parameters: **		buf -- io buffer ** **	Returns: **< 0 one error (errno set) ** **	Side Effects: **		closes file ** **	Requires: **		close(II) ** **	Called By: **		USER */
end_comment

begin_macro
name|IIclose
argument_list|(
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|close
argument_list|(
name|buf
operator|->
name|fildes
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

