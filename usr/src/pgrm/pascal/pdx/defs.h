begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)defs.h	5.3 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Global debugger defines.  *  * All files include this header.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Since C does not allow forward referencing of types,  * all the global types are declared here.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_typedef
typedef|typedef
name|int
name|BOOLEAN
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ADDRESS
typedef|;
end_typedef

begin_comment
comment|/* object code addresses */
end_comment

begin_typedef
typedef|typedef
name|short
name|LINENO
typedef|;
end_typedef

begin_comment
comment|/* source file line numbers */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sym
name|SYM
typedef|;
end_typedef

begin_comment
comment|/* symbol information structure */
end_comment

begin_typedef
typedef|typedef
name|struct
name|symtab
name|SYMTAB
typedef|;
end_typedef

begin_comment
comment|/* symbol table */
end_comment

begin_typedef
typedef|typedef
name|struct
name|node
name|NODE
typedef|;
end_typedef

begin_comment
comment|/* expression tree node */
end_comment

begin_typedef
typedef|typedef
name|short
name|OP
typedef|;
end_typedef

begin_comment
comment|/* tree operator */
end_comment

begin_typedef
typedef|typedef
name|struct
name|opinfo
name|OPINFO
typedef|;
end_typedef

begin_comment
comment|/* tree operator information table */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|WORD
typedef|;
end_typedef

begin_comment
comment|/* machine word */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_comment
comment|/* machine byte */
end_comment

begin_typedef
typedef|typedef
name|struct
name|frame
name|FRAME
typedef|;
end_typedef

begin_comment
comment|/* runtime activation record */
end_comment

begin_comment
comment|/*  * Definitions of standard C library routines that aren't in the  * standard I/O library, but which are generally useful.  */
end_comment

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ascii to long */
end_comment

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ascii to floating point */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* make a temporary file name */
end_comment

begin_comment
comment|/*  * Definitions of library routines.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmdname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of command for error messages */
end_comment

begin_decl_stmt
name|char
modifier|*
name|errfilename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file associated with error */
end_comment

begin_decl_stmt
name|short
name|errlineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number associated with error */
end_comment

begin_function_decl
name|int
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print an error message */
end_comment

begin_function_decl
name|int
name|panic
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print error message and exit */
end_comment

begin_function_decl
name|short
name|numerrors
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return number of errors since last call */
end_comment

begin_comment
comment|/*  * defintions for doing memory allocation  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|alloc
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|)
value|((type *) malloc((unsigned) (n) * sizeof(type)))
end_define

begin_define
define|#
directive|define
name|dispose
parameter_list|(
name|p
parameter_list|)
value|{ free((char *) p); p = NIL; }
end_define

begin_comment
comment|/*  * macro for doing freads  */
end_comment

begin_define
define|#
directive|define
name|get
parameter_list|(
name|fp
parameter_list|,
name|var
parameter_list|)
value|fread((char *)&(var), sizeof(var), 1, fp)
end_define

begin_comment
comment|/*  * string definitions  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|s
parameter_list|)
value|strcpy(malloc((unsigned) strlen(s) + 1), s)
end_define

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1, s2) == 0)
end_define

end_unit

