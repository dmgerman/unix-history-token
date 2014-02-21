begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** This file is in the public domain, so clarified as of ** 1996-06-05 by Arthur David Olson. */
end_comment

begin_comment
comment|/* ** Avoid the temptation to punt entirely to strftime; ** the output of strftime is supposed to be locale specific ** whereas the output of asctime is supposed to be constant. */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOID
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|elsieid
index|[]
name|__unused
init|=
literal|"@(#)asctime.c	8.5"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"tzfile.h"
end_include

begin_comment
comment|/* ** Some systems only handle "%.2d"; others only handle "%02d"; ** "%02.2d" makes (most) everybody happy. ** At least some versions of gcc warn about the %02.2d; ** we conditionalize below to avoid the warning. */
end_comment

begin_comment
comment|/* ** All years associated with 32-bit time_t values are exactly four digits long; ** some years associated with 64-bit time_t values are not. ** Vintage programs are coded for years that are always four digits long ** and may assume that the newline always lands in the same place. ** For years that are less than four digits, we pad the output with ** leading zeroes to get the newline in the traditional place. ** The -4 ensures that we get four characters of output even if ** we call a strftime variant that produces fewer characters for some years. ** The ISO C 1999 and POSIX 1003.1-2004 standards prohibit padding the year, ** but many implementations pad anyway; most likely the standards are buggy. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ASCTIME_FMT
value|"%.3s %.3s%3d %2.2d:%2.2d:%2.2d %-4s\n"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|ASCTIME_FMT
value|"%.3s %.3s%3d %02.2d:%02.2d:%02.2d %-4s\n"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __GNUC__ */
end_comment

begin_comment
comment|/* ** For years that are more than four digits we put extra spaces before the year ** so that code trying to overwrite the newline won't end up overwriting ** a digit within a year and truncating the year (operating on the assumption ** that no output is better than wrong output). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ASCTIME_FMT_B
value|"%.3s %.3s%3d %2.2d:%2.2d:%2.2d     %s\n"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|ASCTIME_FMT_B
value|"%.3s %.3s%3d %02.2d:%02.2d:%02.2d     %s\n"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|STD_ASCTIME_BUF_SIZE
value|26
end_define

begin_comment
comment|/* ** Big enough for something such as ** ??? ???-2147483648 -2147483648:-2147483648:-2147483648     -2147483648\n ** (two three-character abbreviations, five strings denoting integers, ** seven explicit spaces, two explicit colons, a newline, ** and a trailing ASCII nul). ** The values above are for systems where an int is 32 bits and are provided ** as an example; the define below calculates the maximum for the system at ** hand. */
end_comment

begin_define
define|#
directive|define
name|MAX_ASCTIME_BUF_SIZE
value|(2*3+5*INT_STRLEN_MAXIMUM(int)+7+2+1+1)
end_define

begin_decl_stmt
specifier|static
name|char
name|buf_asctime
index|[
name|MAX_ASCTIME_BUF_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ** A la ISO/IEC 9945-1, ANSI/IEEE Std 1003.1, 2004 Edition. */
end_comment

begin_function
name|char
modifier|*
name|asctime_r
parameter_list|(
name|timeptr
parameter_list|,
name|buf
parameter_list|)
specifier|const
name|struct
name|tm
modifier|*
name|timeptr
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|{
specifier|static
specifier|const
name|char
name|wday_name
index|[]
index|[
literal|3
index|]
init|=
block|{
literal|"Sun"
block|,
literal|"Mon"
block|,
literal|"Tue"
block|,
literal|"Wed"
block|,
literal|"Thu"
block|,
literal|"Fri"
block|,
literal|"Sat"
block|}
decl_stmt|;
specifier|static
specifier|const
name|char
name|mon_name
index|[]
index|[
literal|3
index|]
init|=
block|{
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|}
decl_stmt|;
specifier|const
name|char
modifier|*
name|wn
decl_stmt|;
specifier|const
name|char
modifier|*
name|mn
decl_stmt|;
name|char
name|year
index|[
name|INT_STRLEN_MAXIMUM
argument_list|(
name|int
argument_list|)
operator|+
literal|2
index|]
decl_stmt|;
name|char
name|result
index|[
name|MAX_ASCTIME_BUF_SIZE
index|]
decl_stmt|;
if|if
condition|(
name|timeptr
operator|==
name|NULL
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"??? ??? ?? ??:??:?? ????\n"
argument_list|)
return|;
block|}
if|if
condition|(
name|timeptr
operator|->
name|tm_wday
operator|<
literal|0
operator|||
name|timeptr
operator|->
name|tm_wday
operator|>=
name|DAYSPERWEEK
condition|)
name|wn
operator|=
literal|"???"
expr_stmt|;
else|else
name|wn
operator|=
name|wday_name
index|[
name|timeptr
operator|->
name|tm_wday
index|]
expr_stmt|;
if|if
condition|(
name|timeptr
operator|->
name|tm_mon
operator|<
literal|0
operator|||
name|timeptr
operator|->
name|tm_mon
operator|>=
name|MONSPERYEAR
condition|)
name|mn
operator|=
literal|"???"
expr_stmt|;
else|else
name|mn
operator|=
name|mon_name
index|[
name|timeptr
operator|->
name|tm_mon
index|]
expr_stmt|;
comment|/* 	** Use strftime's %Y to generate the year, to avoid overflow problems 	** when computing timeptr->tm_year + TM_YEAR_BASE. 	** Assume that strftime is unaffected by other out-of-range members 	** (e.g., timeptr->tm_mday) when processing "%Y". 	*/
operator|(
name|void
operator|)
name|strftime
argument_list|(
name|year
argument_list|,
sizeof|sizeof
name|year
argument_list|,
literal|"%Y"
argument_list|,
name|timeptr
argument_list|)
expr_stmt|;
comment|/* 	** We avoid using snprintf since it's not available on all systems. 	*/
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|result
argument_list|,
operator|(
operator|(
name|strlen
argument_list|(
name|year
argument_list|)
operator|<=
literal|4
operator|)
condition|?
name|ASCTIME_FMT
else|:
name|ASCTIME_FMT_B
operator|)
argument_list|,
name|wn
argument_list|,
name|mn
argument_list|,
name|timeptr
operator|->
name|tm_mday
argument_list|,
name|timeptr
operator|->
name|tm_hour
argument_list|,
name|timeptr
operator|->
name|tm_min
argument_list|,
name|timeptr
operator|->
name|tm_sec
argument_list|,
name|year
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|result
argument_list|)
operator|<
name|STD_ASCTIME_BUF_SIZE
operator|||
name|buf
operator|==
name|buf_asctime
condition|)
return|return
name|strcpy
argument_list|(
name|buf
argument_list|,
name|result
argument_list|)
return|;
else|else
block|{
ifdef|#
directive|ifdef
name|EOVERFLOW
name|errno
operator|=
name|EOVERFLOW
expr_stmt|;
else|#
directive|else
comment|/* !defined EOVERFLOW */
name|errno
operator|=
name|EINVAL
expr_stmt|;
endif|#
directive|endif
comment|/* !defined EOVERFLOW */
return|return
name|NULL
return|;
block|}
block|}
end_function

begin_comment
comment|/* ** A la ISO/IEC 9945-1, ANSI/IEEE Std 1003.1, 2004 Edition. */
end_comment

begin_function
name|char
modifier|*
name|asctime
parameter_list|(
name|timeptr
parameter_list|)
specifier|const
name|struct
name|tm
modifier|*
name|timeptr
decl_stmt|;
block|{
return|return
name|asctime_r
argument_list|(
name|timeptr
argument_list|,
name|buf_asctime
argument_list|)
return|;
block|}
end_function

end_unit

