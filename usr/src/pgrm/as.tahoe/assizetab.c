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
literal|"@(#)assizetab.c 4.4 11/11/82"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AS
end_ifdef

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

begin_include
include|#
directive|include
file|"assyms.h"
end_include

begin_comment
comment|/*  *	Convert loader reference types (plus PCREL) to bytes and lg bytes  */
end_comment

begin_decl_stmt
name|int
name|reflen
index|[]
init|=
block|{
comment|/* {LEN*+PCREL} ==> number of bytes */
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
comment|/* LEN1,	LEN1 + PCREL */
literal|2
block|,
literal|2
block|,
comment|/* LEN2,	LEN2 + PCREL */
literal|4
block|,
literal|4
block|,
comment|/* LEN4,	LEN2 + PCREL */
literal|8
block|,
literal|8
comment|/* LEN8,	LEN2 + PCREL */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lgreflen
index|[]
init|=
block|{
comment|/* {LEN*+PCREL} ==> number of bytes */
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
comment|/* LEN1,	LEN1 + PCREL */
literal|1
block|,
literal|1
block|,
comment|/* LEN2,	LEN2 + PCREL */
literal|2
block|,
literal|2
block|,
comment|/* LEN4,	LEN2 + PCREL */
literal|3
block|,
literal|3
comment|/* LEN8,	LEN2 + PCREL */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Convert sizes to loader reference types and type flags  */
end_comment

begin_comment
comment|/*0	1	2	3	4	5	6	7	8*/
end_comment

begin_comment
comment|/*  *	Convert {1,2,4,8} into {LEN1, LEN2, LEN4, LEN8}  */
end_comment

begin_decl_stmt
name|int
name|len124
index|[]
init|=
block|{
literal|0
block|,
name|LEN1
block|,
comment|/* 0 */
name|LEN2
block|,
literal|0
block|,
comment|/* 2 */
name|LEN4
block|,
literal|0
block|,
comment|/* 4 */
literal|0
block|,
literal|0
block|,
comment|/* 6 */
name|LEN8
block|,
literal|0
comment|/* 8 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Convert {1,2,4,8} into {bits to construct operands}  */
end_comment

begin_decl_stmt
name|char
name|mod124
index|[]
init|=
block|{
literal|0
block|,
literal|0x00
block|,
comment|/* 0 */
literal|0x20
block|,
literal|0
block|,
comment|/* 2 */
literal|0x40
block|,
literal|0
block|,
comment|/* 4 */
literal|0
block|,
literal|0
block|,
comment|/* 6 */
literal|0
block|,
literal|0
comment|/* 8 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	{1,2,4,8} into {TYPB, TYPW, TYPL, TYPQ}  */
end_comment

begin_decl_stmt
name|int
name|type_124
index|[]
init|=
block|{
literal|0
block|,
name|TYPB
block|,
comment|/* 0 */
name|TYPW
block|,
literal|0
block|,
comment|/* 2 */
name|TYPL
block|,
literal|0
block|,
comment|/* 4 */
literal|0
block|,
literal|0
block|,
comment|/* 6 */
name|TYPQ
block|,
literal|0
comment|/* 8 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|AS
end_endif

begin_comment
comment|/*  *	Convert TYP[BWLQOFDGH] into {1 if relocation not OK}  */
end_comment

begin_decl_stmt
name|int
name|ty_NORELOC
index|[]
init|=
block|{
literal|0
block|,
comment|/* TYPB */
literal|0
block|,
comment|/* TYPW */
literal|0
block|,
comment|/* TYPL */
literal|1
block|,
comment|/* TYPQ */
literal|1
block|,
comment|/* TYPF */
literal|1
block|,
comment|/* TYPD */
literal|1
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ADB
end_ifndef

begin_comment
comment|/*  *	Convert TYP[BWLQOFDGH] into {1 if a floating point number}  */
end_comment

begin_decl_stmt
name|int
name|ty_float
index|[]
init|=
block|{
literal|0
block|,
comment|/* TYPB */
literal|0
block|,
comment|/* TYPW */
literal|0
block|,
comment|/* TYPL */
literal|0
block|,
comment|/* TYPQ */
literal|1
block|,
comment|/* TYPF */
literal|1
block|,
comment|/* TYPD */
literal|0
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AS
end_ifdef

begin_comment
comment|/*  *	Convert TYP[BWLQOFDGH] into {LEN1 ... LEN16}  */
end_comment

begin_decl_stmt
name|int
name|ty_LEN
index|[]
init|=
block|{
name|LEN1
block|,
comment|/* TYPB */
name|LEN2
block|,
comment|/* TYPW */
name|LEN4
block|,
comment|/* TYPL */
name|LEN8
block|,
comment|/* TYPQ */
name|LEN4
block|,
comment|/* TYPF */
name|LEN8
block|,
comment|/* TYPD */
literal|0
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|AS
end_endif

begin_comment
comment|/*  *	Convert TYP[BWLQFD] into {1 ... 8}  */
end_comment

begin_decl_stmt
name|int
name|ty_nbyte
index|[]
init|=
block|{
literal|1
block|,
comment|/* TYPB */
literal|2
block|,
comment|/* TYPW */
literal|4
block|,
comment|/* TYPL */
literal|8
block|,
comment|/* TYPQ */
literal|4
block|,
comment|/* TYPF */
literal|8
block|,
comment|/* TYPD */
literal|0
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ADB
end_ifndef

begin_comment
comment|/*  *	Convert TYP[BWLQFD] into lg{1 ... 8}  */
end_comment

begin_decl_stmt
name|int
name|ty_nlg
index|[]
init|=
block|{
literal|0
block|,
comment|/* TYPB */
literal|1
block|,
comment|/* TYPW */
literal|2
block|,
comment|/* TYPL */
literal|3
block|,
comment|/* TYPQ */
literal|2
block|,
comment|/* TYPF */
literal|3
block|,
comment|/* TYPD */
operator|-
literal|1
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Convert TYP[BWLQFD] into strings  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ty_string
index|[]
init|=
block|{
literal|"byte"
block|,
comment|/* TYPB */
literal|"word"
block|,
comment|/* TYPW */
literal|"long"
block|,
comment|/* TYPL */
literal|"quad"
block|,
comment|/* TYPQ */
literal|"f_float"
block|,
comment|/* TYPF */
literal|"d_float"
block|,
comment|/* TYPD */
literal|"??snark??"
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

