begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)extr.h	5.2 (Berkeley) 6/1/90  */
end_comment

begin_decl_stmt
specifier|extern
name|ndptr
name|hashtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table for macros etc.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* push-back buffer	       */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first available character   */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endpbb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of push-back buffer     */
end_comment

begin_decl_stmt
specifier|extern
name|stae
name|mstack
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack of m4 machine         */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first free char in strspace */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space	       */
end_comment

begin_decl_stmt
name|int
name|sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current m4  stack pointer   */
end_comment

begin_decl_stmt
name|int
name|fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4 call frame pointer       */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack (0=stdin)  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outfile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion array(0=bitbucket)*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active output file pointer  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename for diversions     */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ilevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack pointer    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|oindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion index..	       */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as it says.. just a null..  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4wraps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4wrap string default..     */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* left quote character  (`)   */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* right quote character (')   */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|scommt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start character for comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ecommt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end character for comment   */
end_comment

end_unit

