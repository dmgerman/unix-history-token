begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pcp.h -- Describes the format of a precompiled file    Copyright (C) 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Structure allocated for every string in a precompiled file */
end_comment

begin_typedef
typedef|typedef
name|struct
name|stringdef
name|STRINGDEF
typedef|;
end_typedef

begin_struct
struct|struct
name|stringdef
block|{
name|U_CHAR
modifier|*
name|contents
decl_stmt|;
comment|/* String to include */
name|int
name|len
decl_stmt|;
comment|/* Its length */
name|int
name|writeflag
decl_stmt|;
comment|/* Whether we write this */
name|int
name|lineno
decl_stmt|;
comment|/* Linenumber of source file */
name|U_CHAR
modifier|*
name|filename
decl_stmt|;
comment|/* Name of source file */
name|STRINGDEF
modifier|*
name|chain
decl_stmt|;
comment|/* Global list of strings in natural order */
name|int
name|output_mark
decl_stmt|;
comment|/* Where in the output this goes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keydef
name|KEYDEF
typedef|;
end_typedef

begin_struct
struct|struct
name|keydef
block|{
name|STRINGDEF
modifier|*
name|str
decl_stmt|;
name|KEYDEF
modifier|*
name|chain
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Format: */
end_comment

begin_comment
comment|/* A precompiled file starts with a series of #define and #undef  statements:     #define MAC DEF     ---   Indicates MAC must be defined with defn DEF     #define MAC         ---   Indicates MAC must be defined with any defn     #undef MAC          ---   Indicates MAC cannot be defined  These preconditions must be true for a precompiled file to be used.   The preconditions section is null terminated. */
end_comment

begin_comment
comment|/* Then, there is a four byte number (in network byte order) which */
end_comment

begin_comment
comment|/* indicates the number of strings the file contains. */
end_comment

begin_comment
comment|/* Each string contains a STRINGDEF structure.  The only component of */
end_comment

begin_comment
comment|/* the STRINGDEF structure which is used is the lineno field, which */
end_comment

begin_comment
comment|/* should hold the line number in the original header file.  */
end_comment

begin_comment
comment|/* Then follows the string, followed by a null.  Then comes a four */
end_comment

begin_comment
comment|/* byte number (again, in network byte order) indicating the number */
end_comment

begin_comment
comment|/* of keys for this string.  Each key is a KEYDEF structure, with */
end_comment

begin_comment
comment|/* irrelevant contents, followed by the null-terminated string. */
end_comment

begin_comment
comment|/* If the number of keys is 0, then there are no keys for the string, */
end_comment

begin_comment
comment|/* in other words, the string will never be included.  If the number */
end_comment

begin_comment
comment|/* of keys is -1, this is a special flag indicating there are no keys */
end_comment

begin_comment
comment|/* in the file, and the string is mandatory (that is, it must be */
end_comment

begin_comment
comment|/* included regardless in the included output).  */
end_comment

begin_comment
comment|/* A file, then, looks like this:    Precondition 1   Precondition 2   .    .   .<NUL>   Number of strings     STRINGDEF     String . . .<NUL>     Number of keys       KEYDEF       Key . . .<NUL>       KEYDEF        Key . . .<NUL>       .       .       .     STRINGDEF     String . . .<NUL>     Number of keys       KEYDEF       Key . . .<NUL>       .       .       .     .     .     .  */
end_comment

end_unit

