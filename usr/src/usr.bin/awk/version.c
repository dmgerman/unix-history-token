begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** version.c copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	version.c,v $  * Revision 5.3  92/03/03  16:42:23  brennan  * patch 1  *   * Revision 5.2  92/01/22  05:34:10  brennan  * version 1.1  *   * Revision 5.1  91/12/05  07:56:33  brennan  * 1.1 pre-release  *  */
end_comment

begin_include
include|#
directive|include
file|"mawk.h"
end_include

begin_include
include|#
directive|include
file|"patchlev.h"
end_include

begin_define
define|#
directive|define
name|VERSION_STRING
define|\
value|"mawk 1.1%s%s Feb 1992, Copyright (C) Michael D. Brennan\n\n"
end_define

begin_define
define|#
directive|define
name|DOS_STRING
value|""
end_define

begin_comment
comment|/* If use different command line syntax for MSDOS    mark that in VERSION  */
end_comment

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_undef
undef|#
directive|undef
name|DOS_STRING
end_undef

begin_if
if|#
directive|if
name|SM_DOS
end_if

begin_if
if|#
directive|if
name|HAVE_REARGV
end_if

begin_define
define|#
directive|define
name|DOS_STRING
value|"SM"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DOS_STRING
value|"SMDOS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LM_DOS  */
end_comment

begin_if
if|#
directive|if
name|HAVE_REARGV
end_if

begin_define
define|#
directive|define
name|DOS_STRING
value|"LM"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DOS_STRING
value|"LMDOS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|THINK_C
end_ifdef

begin_undef
undef|#
directive|undef
name|DOS_STRING
end_undef

begin_define
define|#
directive|define
name|DOS_STRING
value|":Mac"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* print VERSION and exit */
end_comment

begin_function
name|void
name|print_version
parameter_list|()
block|{
specifier|static
name|char
name|fmt
index|[]
init|=
literal|"%-14s%10u\n"
decl_stmt|;
name|printf
argument_list|(
name|VERSION_STRING
argument_list|,
name|PATCH_STRING
argument_list|,
name|DOS_STRING
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"compiled limits:\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
literal|"largest field"
argument_list|,
name|MAX_FIELD
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
literal|"sprintf buffer"
argument_list|,
name|SPRINTF_SZ
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

