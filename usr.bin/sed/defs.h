begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Diomidis Spinellis.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Diomidis Spinellis of Imperial College, University of London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Types of address specifications  */
end_comment

begin_enum
enum|enum
name|e_atype
block|{
name|AT_RE
block|,
comment|/* Line that match RE */
name|AT_LINE
block|,
comment|/* Specific line */
name|AT_LAST
block|,
comment|/* Last line */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Format of an address  */
end_comment

begin_struct
struct|struct
name|s_addr
block|{
name|enum
name|e_atype
name|type
decl_stmt|;
comment|/* Address type */
union|union
block|{
name|u_long
name|l
decl_stmt|;
comment|/* Line number */
name|regex_t
modifier|*
name|r
decl_stmt|;
comment|/* Regular expression */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Substitution command  */
end_comment

begin_struct
struct|struct
name|s_subst
block|{
name|int
name|n
decl_stmt|;
comment|/* Occurrence to subst. */
name|int
name|p
decl_stmt|;
comment|/* True if p flag */
name|char
modifier|*
name|wfile
decl_stmt|;
comment|/* NULL if no wfile */
name|int
name|wfd
decl_stmt|;
comment|/* Cached file descriptor */
name|regex_t
modifier|*
name|re
decl_stmt|;
comment|/* Regular expression */
name|int
name|maxbref
decl_stmt|;
comment|/* Largest backreference. */
name|u_long
name|linenum
decl_stmt|;
comment|/* Line number. */
name|char
modifier|*
name|new
decl_stmt|;
comment|/* Replacement text */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An internally compiled command.  * Initialy, label references are stored in t, on a second pass they  * are updated to pointers.  */
end_comment

begin_struct
struct|struct
name|s_command
block|{
name|struct
name|s_command
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to next command */
name|struct
name|s_addr
modifier|*
name|a1
decl_stmt|,
modifier|*
name|a2
decl_stmt|;
comment|/* Start and end address */
name|char
modifier|*
name|t
decl_stmt|;
comment|/* Text for : a c i r w */
union|union
block|{
name|struct
name|s_command
modifier|*
name|c
decl_stmt|;
comment|/* Command(s) for b t { */
name|struct
name|s_subst
modifier|*
name|s
decl_stmt|;
comment|/* Substitute command */
name|u_char
modifier|*
name|y
decl_stmt|;
comment|/* Replace command array */
name|int
name|fd
decl_stmt|;
comment|/* File descriptor for w */
block|}
name|u
union|;
name|char
name|code
decl_stmt|;
comment|/* Command code */
name|u_int
name|nonsel
range|:
literal|1
decl_stmt|;
comment|/* True if ! */
name|u_int
name|inrange
range|:
literal|1
decl_stmt|;
comment|/* True if in range */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types of command arguments recognised by the parser  */
end_comment

begin_enum
enum|enum
name|e_args
block|{
name|EMPTY
block|,
comment|/* d D g G h H l n N p P q x = \0 */
name|TEXT
block|,
comment|/* a c i */
name|NONSEL
block|,
comment|/* ! */
name|GROUP
block|,
comment|/* { */
name|ENDGROUP
block|,
comment|/* } */
name|COMMENT
block|,
comment|/* # */
name|BRANCH
block|,
comment|/* b t */
name|LABEL
block|,
comment|/* : */
name|RFILE
block|,
comment|/* r */
name|WFILE
block|,
comment|/* w */
name|SUBST
block|,
comment|/* s */
name|TR
comment|/* y */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Structure containing things to append before a line is read  */
end_comment

begin_struct
struct|struct
name|s_appends
block|{
enum|enum
block|{
name|AP_STRING
block|,
name|AP_FILE
block|}
name|type
enum|;
name|char
modifier|*
name|s
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|e_spflag
block|{
name|APPEND
block|,
comment|/* Append to the contents. */
name|REPLACE
block|,
comment|/* Replace the contents. */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Structure for a space (process, hold, otherwise).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|space
decl_stmt|;
comment|/* Current space pointer. */
name|size_t
name|len
decl_stmt|;
comment|/* Current length. */
name|int
name|deleted
decl_stmt|;
comment|/* If deleted. */
name|char
modifier|*
name|back
decl_stmt|;
comment|/* Backing memory. */
name|size_t
name|blen
decl_stmt|;
comment|/* Backing memory length. */
block|}
name|SPACE
typedef|;
end_typedef

end_unit

