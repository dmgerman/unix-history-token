begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Print the version number.  */
end_comment

begin_comment
comment|/* $Id: version.c,v 1.5 1997/05/21 18:29:20 eggert Exp $ */
end_comment

begin_define
define|#
directive|define
name|XTERN
value|extern
end_define

begin_include
include|#
directive|include
file|<common.h>
end_include

begin_undef
undef|#
directive|undef
name|XTERN
end_undef

begin_define
define|#
directive|define
name|XTERN
end_define

begin_include
include|#
directive|include
file|<patchlevel.h>
end_include

begin_include
include|#
directive|include
file|<version.h>
end_include

begin_decl_stmt
specifier|static
name|char
specifier|const
name|copyright_string
index|[]
init|=
literal|"\ Copyright 1988 Larry Wall\n\ Copyright 1997 Free Software Foundation, Inc."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
name|free_software_msgid
index|[]
init|=
literal|"\ This program comes with NO WARRANTY, to the extent permitted by law.\n\ You may redistribute copies of this program\n\ under the terms of the GNU General Public License.\n\ For more information about these matters, see the file named COPYING."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
name|authorship_msgid
index|[]
init|=
literal|"\ written by Larry Wall with lots o' patches by Paul Eggert"
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|version
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s %s\n%s\n\n%s\n\n%s\n"
argument_list|,
name|program_name
argument_list|,
name|PATCH_VERSION
argument_list|,
name|copyright_string
argument_list|,
name|free_software_msgid
argument_list|,
name|authorship_msgid
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

