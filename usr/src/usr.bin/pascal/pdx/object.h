begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)object.h	5.3 (Berkeley) 4/16/91  */
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

