begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* File names and variables for bison,    Copyright (C) 1984, 1989 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* These two should be pathnames for opening the sample parser files.    When bison is installed, they should be absolute pathnames.    XPFILE1 and XPFILE2 normally come from config.h.  */
end_comment

begin_define
define|#
directive|define
name|PFILE
value|XPFILE
end_define

begin_comment
comment|/* Simple parser */
end_comment

begin_define
define|#
directive|define
name|PFILE1
value|XPFILE1
end_define

begin_comment
comment|/* Semantic parser */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|finput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read grammar specifications */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|foutput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optionally output messages describing the actions taken */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fdefines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optionally output #define's for token numbers. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ftable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output the tables and the parser */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fattrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if semantic parser, output a .h file that defines YYSTYPE */
end_comment

begin_comment
comment|/* and also contains all the %{ ... %} definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fguard
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if semantic parser, output yyguard, containing all the guard code */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|faction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output all the action code; precise form depends on which parser */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fparser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read the parser to copy into ftable */
end_comment

begin_comment
comment|/* File name specified with -o for the output file, or 0 if no -o.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|spec_outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|spec_name_prefix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -a, from getargs.c */
end_comment

begin_comment
comment|/* File name pfx specified with -b, or 0 if no -b.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|spec_file_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|defsfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tabfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|attrsfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|guardfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|actfile
decl_stmt|;
end_decl_stmt

end_unit

