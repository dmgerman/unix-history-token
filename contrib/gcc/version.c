begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/* This is the trailing component of the string reported as the    version number by all components of the compiler.  For an official    FSF release, it is empty.  If you distribute a modified version of    GCC, please change this string to indicate that.  The suggested    format is a leading space, followed by your organization's name    in parentheses.  You may also wish to include a number indicating    the revision of your modified compiler.  */
end_comment

begin_define
define|#
directive|define
name|VERSUFFIX
value|" [FreeBSD]"
end_define

begin_comment
comment|/* This is the location of the online document giving instructions for    reporting bugs.  If you distribute a modified version of GCC,    please change this to refer to a document giving instructions for    reporting bugs to you, not us.  (You are of course welcome to    forward us bugs reported to you, if you determine that they are    not bugs in your modifications.)  */
end_comment

begin_decl_stmt
specifier|const
name|char
name|bug_report_url
index|[]
init|=
literal|"<URL:http://www.freebsd.org/support.html>"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The complete version string, assembled from several pieces.    BASEVER, DATESTAMP, and DEVPHASE are defined by the Makefile.  */
end_comment

begin_decl_stmt
specifier|const
name|char
name|version_string
index|[]
init|=
name|BASEVER
name|DATESTAMP
name|DEVPHASE
name|VERSUFFIX
decl_stmt|;
end_decl_stmt

end_unit

