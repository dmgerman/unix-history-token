begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUNC_H
end_ifndef

begin_define
define|#
directive|define
name|FUNC_H
end_define

begin_include
include|#
directive|include
file|"calc.h"
end_include

begin_include
include|#
directive|include
file|"label.h"
end_include

begin_comment
comment|/*  * Structure of a function.  * The f_opcodes array is actually of variable size.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|func
name|FUNC
typedef|;
end_typedef

begin_struct
struct|struct
name|func
block|{
name|FUNC
modifier|*
name|f_next
decl_stmt|;
comment|/* next function in list */
name|unsigned
name|long
name|f_opcodecount
decl_stmt|;
comment|/* size of opcode array */
name|unsigned
name|int
name|f_localcount
decl_stmt|;
comment|/* number of local variables */
name|unsigned
name|int
name|f_paramcount
decl_stmt|;
comment|/* max number of parameters */
name|char
modifier|*
name|f_name
decl_stmt|;
comment|/* function name */
name|VALUE
name|f_savedvalue
decl_stmt|;
comment|/* saved value of last expression */
name|long
name|f_opcodes
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of opcodes (variable length) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Amount of space needed to allocate a function of n opcodes.  */
end_comment

begin_define
define|#
directive|define
name|funcsize
parameter_list|(
name|n
parameter_list|)
value|(sizeof(FUNC) + (n) * sizeof(long))
end_define

begin_comment
comment|/*  * Size of a character pointer rounded up to a number of opcodes.  */
end_comment

begin_define
define|#
directive|define
name|PTR_SIZE
value|((sizeof(char *) + sizeof(long) - 1) / sizeof(long))
end_define

begin_comment
comment|/*  * The current function being compiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|FUNC
modifier|*
name|curfunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Functions to handle functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|FUNC
modifier|*
name|findfunc
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|namefunc
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|evaluate
name|MATH_PROTO
argument_list|(
operator|(
name|BOOL
name|nestflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|adduserfunc
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|beginfunc
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|BOOL
name|newflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|builtinopcode
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|builtinname
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dumpop
name|MATH_PROTO
argument_list|(
operator|(
name|long
operator|*
name|pc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addop
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|endfunc
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addopone
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|op
operator|,
name|long
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addoptwo
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|op
operator|,
name|long
name|arg1
operator|,
name|long
name|arg2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addoplabel
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|op
operator|,
name|LABEL
operator|*
name|label
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addopptr
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|op
operator|,
name|char
operator|*
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|writeindexop
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|showbuiltins
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getbuiltinfunc
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|builtincheck
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addopfunction
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|op
operator|,
name|long
name|index
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|showfunctions
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initfunctions
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearopt
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|updateoldvalue
name|MATH_PROTO
argument_list|(
operator|(
name|FUNC
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|calculate
name|MATH_PROTO
argument_list|(
operator|(
name|FUNC
operator|*
name|fp
operator|,
name|int
name|argcount
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
name|builtinfunc
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|,
name|int
name|argcount
operator|,
name|VALUE
operator|*
name|stck
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

