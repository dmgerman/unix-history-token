begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/* This is the string reported as the version number by all components    of the compiler.  If you distribute a modified version of GCC,    please modify this string to indicate that, e.g. by putting your    organization's name in parentheses at the end of the string.  */
end_comment

begin_decl_stmt
specifier|const
name|char
name|version_string
index|[]
init|=
literal|"3.3.1"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the location of the online document giving instructions for    reporting bugs.  If you distribute a modified version of GCC,    please change this to refer to a document giving instructions for    reporting bugs to you, not us.  (You are of course welcome to    forward us bugs reported to you, if you determine that they are    not bugs in your modifications.)  */
end_comment

begin_decl_stmt
specifier|const
name|char
name|bug_report_url
index|[]
init|=
literal|"<URL:http://gcc.gnu.org/bugs.html>"
decl_stmt|;
end_decl_stmt

end_unit

