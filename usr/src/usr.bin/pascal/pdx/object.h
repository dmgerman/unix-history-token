begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)object.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Object module definitions.  *  * The object module is the interface to the object file; in particular  * it contains the routines that read symbol and line number information.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|objname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of object file */
end_comment

begin_decl_stmt
name|int
name|objsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of object code */
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|int
name|stringsize
decl_stmt|;
comment|/* size of the dumped string table */
name|unsigned
name|int
name|nsyms
decl_stmt|;
comment|/* number of symbols */
name|unsigned
name|int
name|nfiles
decl_stmt|;
comment|/* number of files */
name|unsigned
name|int
name|nlines
decl_stmt|;
comment|/* number of lines */
block|}
name|nlhdr
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|stringtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dotpfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of compiled file */
end_comment

begin_function_decl
name|int
name|readobj
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read in the object file */
end_comment

begin_function_decl
name|int
name|objfree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* release storage for object file information */
end_comment

end_unit

