begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1982 Regents of the University of California  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)aspseudo.c 4.5 6/30/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|name
parameter_list|,
name|opcode
parameter_list|,
name|nargs
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|{ \ 		name, opcode, nargs, arg1, arg2, arg3, arg4, arg5, arg6, \ 		(nargs == 0 ? INST0:INSTn) \ 	}
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|tag
parameter_list|)
define|\
value|{ \ 		name, type, 0,   0, 0, 0, 0, 0, 0, \ 		tag \ 	}
end_define

begin_decl_stmt
name|readonly
name|struct
name|Instab
name|instab
index|[]
init|=
block|{
include|#
directive|include
file|"instrs.as"
name|PSEUDO
argument_list|(
literal|"\0\0\0\0\0\0\0\0\0\0"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

end_unit

