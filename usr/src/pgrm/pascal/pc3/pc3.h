begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pc3.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_comment
comment|/*	static	char sccsid[] = "@(#)pc3.h 5.1 6/5/85"; */
end_comment

begin_comment
comment|/*      *	a symbol table entry.      */
end_comment

begin_struct
struct|struct
name|symbol
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* pointer to string table */
name|short
name|desc
decl_stmt|;
comment|/* symbol description */
name|int
name|lookup
decl_stmt|;
comment|/* whether new or old */
name|struct
name|symbol
modifier|*
name|fromp
decl_stmt|;
comment|/* its defining .p file */
union|union
block|{
comment|/* either */
struct|struct
block|{
comment|/*   for a symbol, */
name|struct
name|symbol
modifier|*
name|fromi
decl_stmt|;
comment|/*     its defining .i file */
name|long
name|iline
decl_stmt|;
comment|/*     the .i file line */
name|struct
name|symbol
modifier|*
name|rfilep
decl_stmt|;
comment|/*     its resolving file */
name|long
name|rline
decl_stmt|;
comment|/*     resolving file line */
block|}
name|sym_str
struct|;
name|long
name|checksum
decl_stmt|;
comment|/*   for a file, its checksum */
block|}
name|sym_un
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	struct for an argument .o file.      */
end_comment

begin_struct
struct|struct
name|fileinfo
block|{
name|FILE
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|off_t
name|nextoffset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	old archive magic for error detection.      */
end_comment

begin_define
define|#
directive|define
name|OARMAG
value|0177545
end_define

begin_comment
comment|/*      *	this is used to trim pointers into the range of a mod of a prime.      */
end_comment

begin_define
define|#
directive|define
name|SHORT_ABS
parameter_list|(
name|n
parameter_list|)
value|( n& 077777 )
end_define

begin_comment
comment|/*      *	a prime number which gets sizeof( struct symboltableinfo )      *	up to a multiple of BUFSIZ.      */
end_comment

begin_define
define|#
directive|define
name|SYMBOLPRIME
value|1021
end_define

begin_comment
comment|/*      *	number of entries used in this symbol table,      *	a chain to the next symbol table,      *	and the entries. (pointers to struct symbols.)      */
end_comment

begin_struct
struct|struct
name|symboltableinfo
block|{
name|long
name|used
decl_stmt|;
name|struct
name|symboltableinfo
modifier|*
name|chain
decl_stmt|;
name|struct
name|symbol
modifier|*
name|entry
index|[
name|SYMBOLPRIME
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	if new struct symbols are needed,      *	allocate this much space and hack it up into struct symbols.      */
end_comment

begin_define
define|#
directive|define
name|SYMBOLALLOC
value|BUFSIZ
end_define

begin_comment
comment|/*      *	a prime number which gets sizeof( struct stringtableinfo )      *	up to a multiple of BUFSIZ.      */
end_comment

begin_define
define|#
directive|define
name|STRINGPRIME
value|1021
end_define

begin_comment
comment|/*      *	number of entries used in this string table,      *	a chain to the next string table,      *	and the entries. (pointers to the character table.)      */
end_comment

begin_struct
struct|struct
name|stringtableinfo
block|{
name|long
name|used
decl_stmt|;
name|struct
name|stringtableinfo
modifier|*
name|chain
decl_stmt|;
name|char
modifier|*
name|entry
index|[
name|STRINGPRIME
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	if more character table space is needed,      *	allocate this much and hack it up into strings.      */
end_comment

begin_define
define|#
directive|define
name|CHARALLOC
value|BUFSIZ
end_define

begin_comment
comment|/*      *	uninitialized pointer      */
end_comment

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_comment
comment|/*      *	an enumeration for error types      */
end_comment

begin_define
define|#
directive|define
name|NONE
value|0
end_define

begin_define
define|#
directive|define
name|WARNING
value|1
end_define

begin_define
define|#
directive|define
name|ERROR
value|2
end_define

begin_define
define|#
directive|define
name|FATAL
value|3
end_define

begin_comment
comment|/*      *	an enumeration for lookups      */
end_comment

begin_define
define|#
directive|define
name|NEW
value|0
end_define

begin_define
define|#
directive|define
name|OLD
value|1
end_define

begin_comment
comment|/*      *	booleans      */
end_comment

begin_define
define|#
directive|define
name|BOOL
value|int
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*      *	function types.      */
end_comment

begin_function_decl
name|struct
name|symbol
modifier|*
name|entersymbol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|symbol
modifier|*
name|symbolalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|stringhash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|enterstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|charalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|BOOL
name|nextelement
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|mtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|classify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|article
parameter_list|()
function_decl|;
end_function_decl

end_unit

