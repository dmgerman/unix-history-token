begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return the basename of a pathname.    This file is in the public domain. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* basename (const char *@var{name})  Returns a pointer to the last component of pathname @var{name}. Behavior is undefined if the pathname ends in a directory separator.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|"safe-ctype.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DJGPP__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__OS2__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_DOS_BASED_FILE_SYSTEM
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR_2
end_ifndef

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'\\'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define IS_DIR_SEPARATOR.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR_2
end_ifndef

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|ch
parameter_list|)
value|((ch) == DIR_SEPARATOR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DIR_SEPARATOR_2 */
end_comment

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|ch
parameter_list|)
define|\
value|(((ch) == DIR_SEPARATOR) || ((ch) == DIR_SEPARATOR_2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIR_SEPARATOR_2 */
end_comment

begin_function
name|char
modifier|*
name|basename
parameter_list|(
name|name
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DOS_BASED_FILE_SYSTEM
argument_list|)
comment|/* Skip over the disk name in MSDOS pathnames. */
if|if
condition|(
name|ISALPHA
argument_list|(
name|name
index|[
literal|0
index|]
argument_list|)
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|':'
condition|)
name|name
operator|+=
literal|2
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|base
operator|=
name|name
init|;
operator|*
name|name
condition|;
name|name
operator|++
control|)
block|{
if|if
condition|(
name|IS_DIR_SEPARATOR
argument_list|(
operator|*
name|name
argument_list|)
condition|)
block|{
name|base
operator|=
name|name
operator|+
literal|1
expr_stmt|;
block|}
block|}
return|return
operator|(
name|char
operator|*
operator|)
name|base
return|;
block|}
end_function

end_unit

