begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ranlib.h -- archive library index member definition for GNU.    Copyright 1990, 1991 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The Symdef member of an archive contains two things:    a table that maps symbol-string offsets to file offsets,    and a symbol-string table.  All the symbol names are    run together (each with trailing null) in the symbol-string    table.  There is a single longword bytecount on the front    of each of these tables.  Thus if we have two symbols,    "foo" and "_bar", that are in archive members at offsets    200 and 900, it would look like this:         16		; byte count of index table   	0		; offset of "foo" in string table   	200		; offset of foo-module in file   	4		; offset of "bar" in string table   	900		; offset of bar-module in file   	9		; byte count of string table   	"foo\0_bar\0"	; string table  */
end_comment

begin_define
define|#
directive|define
name|RANLIBMAG
value|"__.SYMDEF"
end_define

begin_comment
comment|/* Archive file name containing index */
end_comment

begin_define
define|#
directive|define
name|RANLIBSKEW
value|3
end_define

begin_comment
comment|/* Creation time offset */
end_comment

begin_comment
comment|/* Format of __.SYMDEF:    First, a longword containing the size of the 'symdef' data that follows.    Second, zero or more 'symdef' structures.    Third, a longword containing the length of symbol name strings.    Fourth, zero or more symbol name strings (each followed by a null).  */
end_comment

begin_struct
struct|struct
name|symdef
block|{
union|union
block|{
name|unsigned
name|long
name|string_offset
decl_stmt|;
comment|/* In the file */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* In memory, sometimes */
block|}
name|s
union|;
comment|/* this points to the front of the file header (AKA member header --        a struct ar_hdr), not to the front of the file or into the file).        in other words it only tells you which file to read */
name|unsigned
name|long
name|file_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Compatability with BSD code */
end_comment

begin_define
define|#
directive|define
name|ranlib
value|symdef
end_define

begin_define
define|#
directive|define
name|ran_un
value|s
end_define

begin_define
define|#
directive|define
name|ran_strx
value|string_offset
end_define

begin_define
define|#
directive|define
name|ran_name
value|name
end_define

begin_define
define|#
directive|define
name|ran_off
value|file_offset
end_define

end_unit

