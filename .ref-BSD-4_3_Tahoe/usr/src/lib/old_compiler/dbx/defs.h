begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)defs.h	5.2 (Berkeley) 1/12/88  */
end_comment

begin_comment
comment|/*  * Public definitions, common to all.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_define
define|#
directive|define
name|double
value|long float
end_define

begin_define
define|#
directive|define
name|atof
value|_latof
end_define

begin_define
define|#
directive|define
name|IRIS
end_define

begin_define
define|#
directive|define
name|mc68000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|new
parameter_list|(
name|type
parameter_list|)
value|((type) malloc(sizeof(struct type)))
end_define

begin_define
define|#
directive|define
name|newarr
parameter_list|(
name|type
parameter_list|,
name|n
parameter_list|)
value|((type *) malloc((unsigned) (n) * sizeof(type)))
end_define

begin_define
define|#
directive|define
name|dispose
parameter_list|(
name|ptr
parameter_list|)
value|{ free((char *) ptr); ptr = 0; }
end_define

begin_define
define|#
directive|define
name|public
end_define

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_define
define|#
directive|define
name|ord
parameter_list|(
name|enumcon
parameter_list|)
value|((unsigned int) enumcon)
end_define

begin_define
define|#
directive|define
name|nil
value|0
end_define

begin_define
define|#
directive|define
name|and
value|&&
end_define

begin_define
define|#
directive|define
name|or
value|||
end_define

begin_define
define|#
directive|define
name|not
value|!
end_define

begin_define
define|#
directive|define
name|div
value|/
end_define

begin_define
define|#
directive|define
name|mod
value|%
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|b
parameter_list|)
value|{ \     if (not(b)) { \ 	panic("assertion failed at line %d in file %s", __LINE__, __FILE__); \     } \ }
end_define

begin_define
define|#
directive|define
name|badcaseval
parameter_list|(
name|v
parameter_list|)
value|{ \     panic("unexpected value %d at line %d in file %s", v, __LINE__, __FILE__); \ }
end_define

begin_define
define|#
directive|define
name|checkref
parameter_list|(
name|p
parameter_list|)
value|{ \     if (p == nil) { \ 	panic("reference through nil pointer at line %d in file %s", \ 	    __LINE__, __FILE__); \     } \ }
end_define

begin_typedef
typedef|typedef
name|int
name|Integer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|integer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|Char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|Real
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|real
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
block|,
name|true
block|}
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
name|boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|String
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|FILE
modifier|*
name|File
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Fileid
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|String
name|Filename
typedef|;
end_typedef

begin_define
define|#
directive|define
name|get
parameter_list|(
name|f
parameter_list|,
name|var
parameter_list|)
value|fread((char *)&(var), sizeof(var), 1, f)
end_define

begin_define
define|#
directive|define
name|put
parameter_list|(
name|f
parameter_list|,
name|var
parameter_list|)
value|fwrite((char *)&(var), sizeof(var), 1, f)
end_define

begin_undef
undef|#
directive|undef
name|FILE
end_undef

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|String
name|strcpy
argument_list|()
decl_stmt|,
name|index
argument_list|()
decl_stmt|,
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|String
name|cmdname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|String
name|errfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|errlineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug_flag
index|[]
decl_stmt|;
end_decl_stmt

end_unit

