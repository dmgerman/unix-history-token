begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NON_UNIX_STDIO
end_ifndef

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_include
include|#
directive|include
file|"sys/stat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_include
include|#
directive|include
file|"fmt.h"
end_include

begin_comment
comment|/* for struct syl */
end_comment

begin_include
include|#
directive|include
file|"rawio.h"
end_include

begin_comment
comment|/* for fcntl.h, fdopen */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NON_UNIX_STDIO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_include
include|#
directive|include
file|"stdlib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*global definitions*/
end_comment

begin_decl_stmt
name|unit
name|f__units
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
name|f__init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*0 on entry, 1 after initializations*/
end_comment

begin_decl_stmt
name|cilist
modifier|*
name|f__elist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*active external io list*/
end_comment

begin_decl_stmt
name|icilist
modifier|*
name|f__svic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*active internal io list*/
end_comment

begin_decl_stmt
name|flag
name|f__reading
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if reading, 0 if writing*/
end_comment

begin_decl_stmt
name|flag
name|f__cplus
decl_stmt|,
name|f__cblank
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f__fmtbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|flag
name|f__external
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if external io, 0 if internal */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|int
argument_list|(
operator|*
name|f__doed
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|f__doned
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
argument_list|(
operator|*
name|f__doend
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|f__donewrec
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|f__dorevert
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
argument_list|(
operator|*
name|f__getn
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|f__putn
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*for formatted io*/
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
argument_list|(
operator|*
name|f__getn
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|f__putn
argument_list|)
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*for formatted io*/
end_comment

begin_decl_stmt
name|int
argument_list|(
operator|*
name|f__doed
argument_list|)
argument_list|(
expr|struct
name|syl
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|ftnlen
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|f__doned
argument_list|)
argument_list|(
expr|struct
name|syl
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
argument_list|(
operator|*
name|f__dorevert
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|f__donewrec
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|f__doend
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|flag
name|f__sequential
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if sequential io, 0 if direct*/
end_comment

begin_decl_stmt
name|flag
name|f__formatted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1 if formatted io, 0 if unformatted*/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|f__cf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current file*/
end_comment

begin_decl_stmt
name|unit
modifier|*
name|f__curunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current unit*/
end_comment

begin_decl_stmt
name|int
name|f__recpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*place in current record*/
end_comment

begin_decl_stmt
name|int
name|f__cursor
decl_stmt|,
name|f__hiwater
decl_stmt|,
name|f__scale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f__icptr
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
comment|/* 100 */
literal|"illegal unit number"
block|,
comment|/* 101 */
literal|"formatted io not allowed"
block|,
comment|/* 102 */
literal|"unformatted io not allowed"
block|,
comment|/* 103 */
literal|"direct io not allowed"
block|,
comment|/* 104 */
literal|"sequential io not allowed"
block|,
comment|/* 105 */
literal|"can't backspace file"
block|,
comment|/* 106 */
literal|"null file name"
block|,
comment|/* 107 */
literal|"can't stat file"
block|,
comment|/* 108 */
literal|"unit not connected"
block|,
comment|/* 109 */
literal|"off end of record"
block|,
comment|/* 110 */
literal|"truncation failed in endfile"
block|,
comment|/* 111 */
literal|"incomprehensible list input"
block|,
comment|/* 112 */
literal|"out of free space"
block|,
comment|/* 113 */
literal|"unit not connected"
block|,
comment|/* 114 */
literal|"read unexpected character"
block|,
comment|/* 115 */
literal|"bad logical input field"
block|,
comment|/* 116 */
literal|"bad variable type"
block|,
comment|/* 117 */
literal|"bad namelist name"
block|,
comment|/* 118 */
literal|"variable not in namelist"
block|,
comment|/* 119 */
literal|"no end record"
block|,
comment|/* 120 */
literal|"variable count incorrect"
block|,
comment|/* 121 */
literal|"subscript for scalar variable"
block|,
comment|/* 122 */
literal|"invalid array section"
block|,
comment|/* 123 */
literal|"substring out of bounds"
block|,
comment|/* 124 */
literal|"subscript out of bounds"
block|,
comment|/* 125 */
literal|"can't read file"
block|,
comment|/* 126 */
literal|"can't write file"
block|,
comment|/* 127 */
literal|"'new' file exists"
block|,
comment|/* 128 */
literal|"can't append to file"
block|,
comment|/* 129 */
literal|"non-positive record number"
comment|/* 130 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXERR
value|(sizeof(F_err)/sizeof(char *)+100)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_macro
name|f__canseek
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

begin_else
else|#
directive|else
end_else

begin_macro
name|f__canseek
argument_list|(
argument|FILE *f
argument_list|)
end_macro

begin_comment
comment|/*SYSDEP*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
ifdef|#
directive|ifdef
name|NON_UNIX_STDIO
return|return
operator|!
name|isatty
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|)
return|;
else|#
directive|else
name|struct
name|stat
name|x
decl_stmt|;
if|if
condition|(
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
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|S_IFMT
switch|switch
condition|(
name|x
operator|.
name|st_mode
operator|&
name|S_IFMT
condition|)
block|{
case|case
name|S_IFDIR
case|:
case|case
name|S_IFREG
case|:
if|if
condition|(
name|x
operator|.
name|st_nlink
operator|>
literal|0
condition|)
comment|/* !pipe */
return|return
operator|(
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|S_IFCHR
case|:
if|if
condition|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|S_IFBLK
case|case
name|S_IFBLK
case|:
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
else|#
directive|else
ifdef|#
directive|ifdef
name|S_ISDIR
comment|/* POSIX version */
if|if
condition|(
name|S_ISREG
argument_list|(
name|x
operator|.
name|st_mode
argument_list|)
operator|||
name|S_ISDIR
argument_list|(
name|x
operator|.
name|st_mode
argument_list|)
condition|)
block|{
if|if
condition|(
name|x
operator|.
name|st_nlink
operator|>
literal|0
condition|)
comment|/* !pipe */
return|return
operator|(
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|S_ISCHR
argument_list|(
name|x
operator|.
name|st_mode
argument_list|)
condition|)
block|{
if|if
condition|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|S_ISBLK
argument_list|(
name|x
operator|.
name|st_mode
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
else|#
directive|else
name|Help
operator|!
name|How
name|does
name|fstat
name|work
name|on
name|this
name|system
condition|?
endif|#
directive|endif
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
comment|/* who knows what it is? */
endif|#
directive|endif
block|}
end_block

begin_function
name|void
ifdef|#
directive|ifdef
name|KR_headers
name|f__fatal
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
else|#
directive|else
function|f__fatal
parameter_list|(
name|int
name|n
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
endif|#
directive|endif
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
operator|||
name|n
operator|<
operator|-
literal|1
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
operator|==
operator|-
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: end of file\n"
argument_list|,
name|s
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
if|if
condition|(
name|f__curunit
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"apparent state: unit %d "
argument_list|,
name|f__curunit
operator|-
name|f__units
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|f__curunit
operator|->
name|ufnm
condition|?
literal|"named %s\n"
else|:
literal|"(unnamed)\n"
argument_list|,
name|f__curunit
operator|->
name|ufnm
argument_list|)
expr_stmt|;
block|}
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"apparent state: internal I/O\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|f__fmtbuf
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"last format: %s\n"
argument_list|,
name|f__fmtbuf
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"lately %s %s %s %s"
argument_list|,
name|f__reading
condition|?
literal|"reading"
else|:
literal|"writing"
argument_list|,
name|f__sequential
condition|?
literal|"sequential"
else|:
literal|"direct"
argument_list|,
name|f__formatted
condition|?
literal|"formatted"
else|:
literal|"unformatted"
argument_list|,
name|f__external
condition|?
literal|"external"
else|:
literal|"internal"
argument_list|)
expr_stmt|;
name|sig_die
argument_list|(
literal|" IO"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*initialization routine*/
end_comment

begin_function
name|VOID
name|f_init
parameter_list|(
name|Void
parameter_list|)
block|{
name|unit
modifier|*
name|p
decl_stmt|;
name|f__init
operator|=
literal|1
expr_stmt|;
name|p
operator|=
operator|&
name|f__units
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
name|f__canseek
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NON_UNIX_STDIO
name|setbuf
argument_list|(
name|stderr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|BUFSIZ
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|stderr
operator|->
name|_flag
operator|&=
operator|~
name|_IONBF
expr_stmt|;
endif|#
directive|endif
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
name|f__units
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
name|f__canseek
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
name|f__units
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
name|f__canseek
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
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_macro
name|f__nowreading
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

begin_else
else|#
directive|else
end_else

begin_macro
name|f__nowreading
argument_list|(
argument|unit *x
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|long
name|loc
decl_stmt|;
name|int
name|ufmt
decl_stmt|;
specifier|extern
name|char
modifier|*
name|f__r_mode
index|[]
decl_stmt|;
if|if
condition|(
operator|!
name|x
operator|->
name|ufnm
condition|)
goto|goto
name|cantread
goto|;
name|ufmt
operator|=
name|x
operator|->
name|ufmt
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
if|if
condition|(
name|freopen
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
name|f__r_mode
index|[
name|ufmt
index|]
argument_list|,
name|x
operator|->
name|ufd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|cantread
label|:
name|errno
operator|=
literal|126
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|x
operator|->
name|uwrt
operator|=
literal|0
expr_stmt|;
operator|(
name|void
operator|)
name|fseek
argument_list|(
name|x
operator|->
name|ufd
argument_list|,
name|loc
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_macro
name|f__nowwriting
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

begin_else
else|#
directive|else
end_else

begin_macro
name|f__nowwriting
argument_list|(
argument|unit *x
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|long
name|loc
decl_stmt|;
name|int
name|ufmt
decl_stmt|;
specifier|extern
name|char
modifier|*
name|f__w_mode
index|[]
decl_stmt|;
ifndef|#
directive|ifndef
name|NON_UNIX_STDIO
name|int
name|k
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|x
operator|->
name|ufnm
condition|)
goto|goto
name|cantwrite
goto|;
name|ufmt
operator|=
name|x
operator|->
name|ufmt
expr_stmt|;
ifdef|#
directive|ifdef
name|NON_UNIX_STDIO
name|ufmt
operator||=
literal|2
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|x
operator|->
name|uwrt
operator|==
literal|3
condition|)
block|{
comment|/* just did write, rewind */
ifdef|#
directive|ifdef
name|NON_UNIX_STDIO
if|if
condition|(
operator|!
operator|(
name|f__cf
operator|=
name|x
operator|->
name|ufd
operator|=
name|freopen
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
name|f__w_mode
index|[
name|ufmt
index|]
argument_list|,
name|x
operator|->
name|ufd
argument_list|)
operator|)
condition|)
else|#
directive|else
if|if
condition|(
name|close
argument_list|(
name|creat
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
literal|0666
argument_list|)
argument_list|)
condition|)
endif|#
directive|endif
goto|goto
name|cantwrite
goto|;
block|}
else|else
block|{
name|loc
operator|=
name|ftell
argument_list|(
name|x
operator|->
name|ufd
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NON_UNIX_STDIO
if|if
condition|(
operator|!
operator|(
name|f__cf
operator|=
name|x
operator|->
name|ufd
operator|=
name|freopen
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
name|f__w_mode
index|[
name|ufmt
index|]
argument_list|,
name|x
operator|->
name|ufd
argument_list|)
operator|)
condition|)
else|#
directive|else
if|if
condition|(
name|fclose
argument_list|(
name|x
operator|->
name|ufd
argument_list|)
operator|<
literal|0
operator|||
operator|(
name|k
operator|=
name|x
operator|->
name|uwrt
operator|==
literal|2
condition|?
name|creat
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
literal|0666
argument_list|)
else|:
name|open
argument_list|(
name|x
operator|->
name|ufnm
argument_list|,
name|O_WRONLY
argument_list|)
operator|)
operator|<
literal|0
operator|||
operator|(
name|f__cf
operator|=
name|x
operator|->
name|ufd
operator|=
name|fdopen
argument_list|(
name|k
argument_list|,
name|f__w_mode
index|[
name|ufmt
index|]
argument_list|)
operator|)
operator|==
name|NULL
condition|)
endif|#
directive|endif
block|{
name|x
operator|->
name|ufd
operator|=
name|NULL
expr_stmt|;
name|cantwrite
label|:
name|errno
operator|=
literal|127
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
operator|(
name|void
operator|)
name|fseek
argument_list|(
name|x
operator|->
name|ufd
argument_list|,
name|loc
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
block|}
name|x
operator|->
name|uwrt
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|int
ifdef|#
directive|ifdef
name|KR_headers
name|err__fl
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
name|int
name|f
decl_stmt|,
name|m
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
else|#
directive|else
function|err__fl
parameter_list|(
name|int
name|f
parameter_list|,
name|int
name|m
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
endif|#
directive|endif
block|{
if|if
condition|(
operator|!
name|f
condition|)
name|f__fatal
argument_list|(
name|m
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|f__doend
condition|)
call|(
modifier|*
name|f__doend
call|)
argument_list|()
expr_stmt|;
return|return
name|errno
operator|=
name|m
return|;
block|}
end_function

end_unit

