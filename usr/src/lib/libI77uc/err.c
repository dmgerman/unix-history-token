begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file i/o error and initialization routines  */
end_comment

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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"fiodefs.h"
end_include

begin_comment
comment|/*  * global definitions  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tmplate
init|=
literal|"tmp.FXXXXXX"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scratch file template */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fortfile
init|=
literal|"fort.%d"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default file template */
end_comment

begin_decl_stmt
name|unit
name|units
index|[
name|MXUNIT
index|]
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*unit table*/
end_comment

begin_decl_stmt
name|flag
name|reading
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if reading,		0 if writing*/
end_comment

begin_decl_stmt
name|flag
name|external
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if external io,	0 if internal */
end_comment

begin_decl_stmt
name|flag
name|sequential
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if sequential io,	0 if direct*/
end_comment

begin_decl_stmt
name|flag
name|formatted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if formatted io,	0 if unformatted, -1 if list*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|fmtbuf
decl_stmt|,
modifier|*
name|icptr
decl_stmt|,
modifier|*
name|icend
decl_stmt|,
modifier|*
name|fmtptr
decl_stmt|;
end_decl_stmt

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
decl_stmt|,
argument_list|(
operator|*
name|dotab
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|lioproc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

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
decl_stmt|,
argument_list|(
operator|*
name|ungetn
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*for formatted io*/
end_comment

begin_decl_stmt
name|icilist
modifier|*
name|svic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active internal io list */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|cf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current file structure*/
end_comment

begin_decl_stmt
name|unit
modifier|*
name|curunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current unit structure*/
end_comment

begin_decl_stmt
name|int
name|lunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current logical unit*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|lfname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current filename*/
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
name|ftnint
name|recnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current record number */
end_comment

begin_decl_stmt
name|int
name|reclen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current record length */
end_comment

begin_decl_stmt
name|int
name|cursor
decl_stmt|,
name|scale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|radix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ioflag
name|signit
decl_stmt|,
name|tab
decl_stmt|,
name|cplus
decl_stmt|,
name|cblank
decl_stmt|,
name|elist
decl_stmt|,
name|errflag
decl_stmt|,
name|endflag
decl_stmt|,
name|lquit
decl_stmt|,
name|l_first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|flag
name|leof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lcount
decl_stmt|,
name|line_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*error messages*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|F_err
index|[]
init|=
block|{
comment|/* 100 */
literal|"error in format"
block|,
comment|/* 101 */
literal|"illegal unit number"
block|,
comment|/* 102 */
literal|"formatted io not allowed"
block|,
comment|/* 103 */
literal|"unformatted io not allowed"
block|,
comment|/* 104 */
literal|"direct io not allowed"
block|,
comment|/* 105 */
literal|"sequential io not allowed"
block|,
comment|/* 106 */
literal|"can't backspace file"
block|,
comment|/* 107 */
literal|"off beginning of record"
block|,
comment|/* 108 */
literal|"can't stat file"
block|,
comment|/* 109 */
literal|"no * after repeat count"
block|,
comment|/* 110 */
literal|"off end of record"
block|,
comment|/* 111 */
literal|"truncation failed"
block|,
comment|/* 112 */
literal|"incomprehensible list input"
block|,
comment|/* 113 */
literal|"out of free space"
block|,
comment|/* 114 */
literal|"unit not connected"
block|,
comment|/* 115 */
literal|"read unexpected character"
block|,
comment|/* 116 */
literal|"blank logical input field"
block|,
comment|/* 117 */
literal|"'new' file exists"
block|,
comment|/* 118 */
literal|"can't find 'old' file"
block|,
comment|/* 119 */
literal|"unknown system error"
block|,
comment|/* 120 */
literal|"requires seek ability"
block|,
comment|/* 121 */
literal|"illegal argument"
block|,
comment|/* 122 */
literal|"negative repeat count"
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
name|ftnint
name|lu
decl_stmt|;
for|for
control|(
name|lu
operator|=
literal|1
init|;
name|lu
operator|<
name|MXUNIT
condition|;
name|lu
operator|++
control|)
name|flush_
argument_list|(
operator|&
name|lu
argument_list|)
expr_stmt|;
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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: [%d] %s\n"
argument_list|,
name|s
argument_list|,
name|n
argument_list|,
name|sys_errlist
index|[
name|n
index|]
argument_list|)
expr_stmt|;
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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: [%d] illegal error number\n"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
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
literal|"%s: [%d] end of file\n"
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
literal|"%s: [%d] %s\n"
argument_list|,
name|s
argument_list|,
name|n
argument_list|,
name|F_err
index|[
name|n
operator|-
literal|100
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|external
condition|)
block|{
if|if
condition|(
operator|!
name|lfname
condition|)
switch|switch
condition|(
name|lunit
condition|)
block|{
case|case
name|STDERR
case|:
name|lfname
operator|=
literal|"stderr"
expr_stmt|;
break|break;
case|case
name|STDIN
case|:
name|lfname
operator|=
literal|"stdin"
expr_stmt|;
break|break;
case|case
name|STDOUT
case|:
name|lfname
operator|=
literal|"stdout"
expr_stmt|;
break|break;
default|default:
name|lfname
operator|=
literal|""
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"logical unit %d, named '%s'\n"
argument_list|,
name|lunit
argument_list|,
name|lfname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|elist
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"lately: %s %s %s %s IO\n"
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
operator|>
literal|0
condition|?
literal|"formatted"
else|:
operator|(
name|formatted
operator|<
literal|0
condition|?
literal|"list"
else|:
literal|"unformatted"
operator|)
argument_list|,
name|external
condition|?
literal|"external"
else|:
literal|"internal"
argument_list|)
expr_stmt|;
if|if
condition|(
name|formatted
condition|)
block|{
if|if
condition|(
name|fmtbuf
condition|)
name|prnt_fmt
argument_list|(
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|external
condition|)
block|{
if|if
condition|(
name|reading
operator|&&
name|curunit
operator|->
name|useek
condition|)
name|prnt_ext
argument_list|()
expr_stmt|;
comment|/* print external data */
block|}
else|else
name|prnt_int
argument_list|()
expr_stmt|;
comment|/* print internal array */
block|}
block|}
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|prnt_ext
argument_list|()
end_macro

begin_block
block|{
name|int
name|ch
decl_stmt|;
name|int
name|i
init|=
literal|1
decl_stmt|;
name|long
name|loc
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"part of last data: "
argument_list|)
expr_stmt|;
name|loc
operator|=
name|ftell
argument_list|(
name|curunit
operator|->
name|ufd
argument_list|)
expr_stmt|;
if|if
condition|(
name|loc
condition|)
block|{
if|if
condition|(
name|loc
operator|==
literal|1L
condition|)
name|rewind
argument_list|(
name|curunit
operator|->
name|ufd
argument_list|)
expr_stmt|;
else|else
for|for
control|(
init|;
name|i
operator|<
literal|12
operator|&&
name|last_char
argument_list|(
name|curunit
operator|->
name|ufd
argument_list|)
operator|!=
literal|'\n'
condition|;
name|i
operator|++
control|)
empty_stmt|;
while|while
condition|(
name|i
operator|--
condition|)
name|fputc
argument_list|(
name|fgetc
argument_list|(
name|curunit
operator|->
name|ufd
argument_list|)
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|fputc
argument_list|(
literal|'|'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|5
operator|&&
operator|(
name|ch
operator|=
name|fgetc
argument_list|(
name|curunit
operator|->
name|ufd
argument_list|)
operator|!=
name|EOF
operator|)
condition|;
name|i
operator|++
control|)
name|fputc
argument_list|(
name|ch
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|prnt_int
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|ep
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"part of last string: "
argument_list|)
expr_stmt|;
name|ep
operator|=
name|icptr
operator|-
operator|(
name|recpos
operator|<
literal|12
condition|?
name|recpos
else|:
literal|12
operator|)
expr_stmt|;
while|while
condition|(
name|ep
operator|<
name|icptr
condition|)
name|fputc
argument_list|(
operator|*
name|ep
operator|++
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'|'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
while|while
condition|(
name|ep
operator|<
operator|(
name|icptr
operator|+
literal|5
operator|)
operator|&&
name|ep
operator|<
name|icend
condition|)
name|fputc
argument_list|(
operator|*
name|ep
operator|++
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|prnt_fmt
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|ep
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"part of last format: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|100
condition|)
block|{
name|i
operator|=
name|fmtptr
operator|-
name|fmtbuf
expr_stmt|;
name|ep
operator|=
name|fmtptr
operator|-
operator|(
name|i
operator|<
literal|20
condition|?
name|i
else|:
literal|20
operator|)
expr_stmt|;
name|i
operator|=
name|i
operator|+
literal|5
expr_stmt|;
block|}
else|else
block|{
name|ep
operator|=
name|fmtbuf
expr_stmt|;
name|i
operator|=
literal|25
expr_stmt|;
name|fmtptr
operator|=
name|fmtbuf
operator|-
literal|1
expr_stmt|;
block|}
while|while
condition|(
name|i
operator|&&
operator|*
name|ep
condition|)
block|{
name|fputc
argument_list|(
operator|(
operator|*
name|ep
operator|==
name|GLITCH
operator|)
condition|?
literal|'"'
else|:
operator|*
name|ep
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
if|if
condition|(
name|ep
operator|==
name|fmtptr
condition|)
name|fputc
argument_list|(
literal|'|'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|ep
operator|++
expr_stmt|;
name|i
operator|--
expr_stmt|;
block|}
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
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
name|ini_std
argument_list|(
name|STDERR
argument_list|,
name|stderr
argument_list|,
name|WRITE
argument_list|)
expr_stmt|;
name|ini_std
argument_list|(
name|STDIN
argument_list|,
name|stdin
argument_list|,
name|READ
argument_list|)
expr_stmt|;
name|ini_std
argument_list|(
name|STDOUT
argument_list|,
name|stdout
argument_list|,
name|WRITE
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

