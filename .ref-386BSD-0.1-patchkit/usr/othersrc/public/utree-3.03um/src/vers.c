begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      VERS.C  *      UTREE version and history.  *      1.00    klin, Jul 12 1988 -- Initial version  *      1.01    klin, Jul 17 1988 -- Remove filesystems completely  *      1.02    klin, Feb  5 1990 -- Ported to BSD  *                                   Filesystem independent directory handling  *                                   Screen handling extracted from screen lib  *      2.00    klin, Nov 10 1990 -- Changes and extensions  *      2.01    klin, Jan 26 1991 -- Some bug fixes  *      2.02    klin, Mar 23 1991 -- User defined commands  *                                   File type commands  *                                   Some minor changes and bug fixes  *                    Apr  7 1991 -- File pattern extended  *      3.00-um klin, Apr 20 1991 -- Bug fixes  *                    May  5 1991 -- Some more extensions  *      3.01-um klin, Jun  4 1991 -- File zooming added  *                    Oct  7 1991 -- File size patterns added  *                                   Bug in putchar() deleted  *                    Oct 15 1991 -- Handling of symlinks changed  *                                   Option -L added  *                    Oct 26 1991 -- Marking directories changed  *                                   Sorting and zooming filelists changed  *                                   Print tree list added  *                                   writedlist() changed  *                                   Copying and moving files changed  *                                   Select directory added  *      3.02-um klin, Nov  1 1991 -- Screen layout changed  *                                   Goto parent directory added  *                                   Marking files changed  *                                   Option -u changed to -n  *                                   Option -u (update tree) added  *              klin, Nov 10 1991 -- buildlist() changed  *                                   Function key handling changed  *              klin, Nov 24 1991 -- Some error fixes and extensions for XENIX  *                                   reported and done by Rolf Gebhardt (Nov 22 1991)  *                                   Video attributes changed  *                                   Cd to current directory before executing  *                                   some commands  *      3.03-um klin, Feb 11 1992 -- Shell screen put into module hist.[ch]  *                                   Shell command history added  *                                   Status screen put into module stat.c  *                                   Generic list type glist added  *                                   Line editor extended, getline() and  *                                   editline() changed  *                                   Handling of variables and filetype  *                                   commands changed  *                                   Minor changes in screen layout  *              klin, Feb 15 1992 -- Video handling changed, display attributes  *                                   and video mode flag added  *                                   Partitioning of directory and file window on  *                                   tree screen changed and option -p added  *              klin, Feb 22 1992 -- Many commands on tree screen changed  *              klin, Feb 23 1992 -- Key handling and key bindings changed  *                                   User customizable key bindings added  *                                   Variables added  *              klin, Mar  6 1992 -- Minor changes before distribution  *            a klin, Mar 15 1992 -- Bug fixes and minor changes  *            b klin, Mar 22 1992 -- Bug fixes and minor changes  *            c klin, Mar 30 1992 -- More bug fixes  *            d klin, Apr  2 1992 -- Time stamps for history added  *            e klin, Apr 11 1992 -- Use colors for video attributes  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#) utree 3.03-um (klin) Feb 15 1992 vers.c"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !lint */
end_comment

begin_decl_stmt
specifier|static
name|char
name|version
index|[]
init|=
literal|"@(#) UTREE 3.03e-um"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) (C) 1991/92 P. Klingebiel& UNIX Magazin"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|release
index|[]
init|=
literal|"@(#) Release: Apr 11 1992"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VERS
value|&version[5]
end_define

begin_define
define|#
directive|define
name|COPY
value|&copyright[5]
end_define

begin_define
define|#
directive|define
name|DATE
value|&release[5]
end_define

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* ---- Functions and procedures -------------------------------------- */
end_comment

begin_comment
comment|/* Write version string to echoline or helpline */
end_comment

begin_function
name|GLOBL
name|int
name|putversion
parameter_list|(
name|l
parameter_list|,
name|s
parameter_list|)
specifier|register
name|int
name|l
decl_stmt|;
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
block|{
if|if
condition|(
name|l
operator|==
name|helpline
condition|)
block|{
name|puthelp
argument_list|(
literal|" %s %s (%s)"
argument_list|,
name|VERS
argument_list|,
name|COPY
argument_list|,
name|DATE
argument_list|)
expr_stmt|;
return|return
operator|(
name|RV_OK
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|s
condition|)
block|{
name|puthelp
argument_list|(
literal|"%s %s"
argument_list|,
name|s
argument_list|,
name|hitkey
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putecho
argument_list|(
literal|"%s %s (%s)"
argument_list|,
name|VERS
argument_list|,
name|COPY
argument_list|,
name|DATE
argument_list|)
expr_stmt|;
return|return
operator|(
name|hitakey
argument_list|(
name|NULL
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* putversion() */
end_comment

begin_comment
comment|/* Print version string */
end_comment

begin_function
name|GLOBL
name|VOID
name|utreeversion
parameter_list|()
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s %s (%s)\n"
argument_list|,
name|VERS
argument_list|,
name|COPY
argument_list|,
name|DATE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* utreeversion() */
end_comment

begin_comment
comment|/* Return utree version */
end_comment

begin_function
name|GLOBL
name|char
modifier|*
name|getversion
parameter_list|()
block|{
return|return
operator|(
name|VERS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* getversion() */
end_comment

end_unit

