begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|x
parameter_list|)
value|(x==NULL?"":x)
end_define

begin_comment
comment|/*global definitions*/
end_comment

begin_decl_stmt
name|unit
name|units
index|[
name|MXUNIT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*unit table*/
end_comment

begin_decl_stmt
name|flag
name|init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*0 on entry, 1 after initializations*/
end_comment

begin_decl_stmt
name|cilist
modifier|*
name|elist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*active external io list*/
end_comment

begin_decl_stmt
name|flag
name|reading
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if reading, 0 if writing*/
end_comment

begin_decl_stmt
name|flag
name|cplus
decl_stmt|,
name|cblank
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmtbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|flag
name|external
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if external io, 0 if internal */
end_comment

begin_decl_stmt
name|int
argument_list|(
operator|*
name|doed
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|doned
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
argument_list|(
operator|*
name|doend
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|donewrec
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|dorevert
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|flag
name|sequential
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if sequential io, 0 if direct*/
end_comment

begin_decl_stmt
name|flag
name|formatted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if formatted io, 0 if unformatted*/
end_comment

begin_decl_stmt
name|int
argument_list|(
operator|*
name|getn
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|putn
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*for formatted io*/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|cf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current file*/
end_comment

begin_decl_stmt
name|unit
modifier|*
name|curunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current unit*/
end_comment

begin_decl_stmt
name|int
name|recpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*place in current record*/
end_comment

begin_decl_stmt
name|int
name|cursor
decl_stmt|,
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*error messages*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|F_err
index|[]
init|=
block|{
literal|"error in format"
block|,
literal|"illegal unit number"
block|,
literal|"formatted io not allowed"
block|,
literal|"unformatted io not allowed"
block|,
literal|"direct io not allowed"
block|,
literal|"sequential io not allowed"
block|,
literal|"can't backspace file"
block|,
literal|"null file name"
block|,
literal|"can't stat file"
block|,
literal|"unit not connected"
block|,
literal|"off end of record"
block|,
literal|"truncation failed in endfile"
block|,
literal|"incomprehensible list input"
block|,
literal|"out of free space"
block|,
literal|"unit not connected"
block|,
literal|"read unexpected character"
block|,
literal|"blank logical input field"
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXERR
value|(sizeof(F_err)/sizeof(char *)+100)
end_define

begin_macro
name|fatal
argument_list|(
argument|n
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|n
operator|<
literal|100
operator|&&
name|n
operator|>=
literal|0
condition|)
name|perror
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/*SYSDEP*/
elseif|else
if|if
condition|(
name|n
operator|>=
operator|(
name|int
operator|)
name|MAXERR
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: illegal error number %d\n"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|n
operator|<
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: end of file %d\n"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|s
argument_list|,
name|F_err
index|[
name|n
operator|-
literal|100
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"apparent state: unit %d named %s\n"
argument_list|,
name|curunit
operator|-
name|units
argument_list|,
name|STR
argument_list|(
name|curunit
operator|->
name|ufnm
argument_list|)
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"last format: %s\n"
argument_list|,
name|STR
argument_list|(
name|fmtbuf
argument_list|)
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"lately %s %s %s %s IO\n"
argument_list|,
name|reading
condition|?
literal|"reading"
else|:
literal|"writing"
argument_list|,
name|sequential
condition|?
literal|"sequential"
else|:
literal|"direct"
argument_list|,
name|formatted
condition|?
literal|"formatted"
else|:
literal|"unformatted"
argument_list|,
name|external
condition|?
literal|"external"
else|:
literal|"internal"
argument_list|)
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*initialization routine*/
end_comment

begin_macro
name|f_init
argument_list|()
end_macro

begin_block
block|{
name|unit
modifier|*
name|p
decl_stmt|;
name|init
operator|=
literal|1
expr_stmt|;
name|p
operator|=
operator|&
name|units
index|[
literal|0
index|]
expr_stmt|;
name|p
operator|->
name|ufd
operator|=
name|stderr
expr_stmt|;
name|p
operator|->
name|useek
operator|=
name|canseek
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|p
operator|->
name|ufmt
operator|=
literal|1
expr_stmt|;
name|p
operator|->
name|uwrt
operator|=
literal|1
expr_stmt|;
name|p
operator|=
operator|&
name|units
index|[
literal|5
index|]
expr_stmt|;
name|p
operator|->
name|ufd
operator|=
name|stdin
expr_stmt|;
name|p
operator|->
name|useek
operator|=
name|canseek
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
name|p
operator|->
name|ufmt
operator|=
literal|1
expr_stmt|;
name|p
operator|->
name|uwrt
operator|=
literal|0
expr_stmt|;
name|p
operator|=
operator|&
name|units
index|[
literal|6
index|]
expr_stmt|;
name|p
operator|->
name|ufd
operator|=
name|stdout
expr_stmt|;
name|p
operator|->
name|useek
operator|=
name|canseek
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|p
operator|->
name|ufmt
operator|=
literal|1
expr_stmt|;
name|p
operator|->
name|uwrt
operator|=
literal|1
expr_stmt|;
block|}
end_block

begin_macro
name|canseek
argument_list|(
argument|f
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*SYSDEP*/
end_comment

begin_block
block|{
name|struct
name|stat
name|x
decl_stmt|;
name|fstat
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|.
name|st_nlink
operator|>
literal|0
comment|/*pipe*/
operator|&&
operator|!
name|isatty
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|)
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|nowreading
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|unit
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|loc
decl_stmt|;
name|x
operator|->
name|uwrt
operator|=
literal|0
expr_stmt|;
name|loc
operator|=
name|ftell
argument_list|(
name|x
operator|->
name|ufd
argument_list|)
expr_stmt|;
name|freopen
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
literal|"r"
argument_list|,
name|x
operator|->
name|ufd
argument_list|)
expr_stmt|;
name|fseek
argument_list|(
name|x
operator|->
name|ufd
argument_list|,
name|loc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|nowwriting
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|unit
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|loc
decl_stmt|;
name|loc
operator|=
name|ftell
argument_list|(
name|x
operator|->
name|ufd
argument_list|)
expr_stmt|;
name|x
operator|->
name|uwrt
operator|=
literal|1
expr_stmt|;
name|freopen
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
literal|"a"
argument_list|,
name|x
operator|->
name|ufd
argument_list|)
expr_stmt|;
name|fseek
argument_list|(
name|x
operator|->
name|ufd
argument_list|,
name|loc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

