begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)c22.c 4.3 3/19/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"c2.h"
end_include

begin_define
define|#
directive|define
name|readonly
end_define

begin_decl_stmt
name|readonly
name|char
name|revbr
index|[]
init|=
block|{
name|JNE
block|,
name|JEQ
block|,
name|JGT
block|,
name|JLT
block|,
name|JGE
block|,
name|JLE
block|,
name|JNE
block|,
name|JEQ
block|,
name|JHI
block|,
name|JLO
block|,
name|JHIS
block|,
name|JLOS
block|,
name|JBS
block|,
name|JBC
block|,
name|JLBS
block|,
name|JLBC
block|,
name|JBSC
block|,
name|JBCC
block|,
name|JBSS
block|,
name|JBCS
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TYPB
value|BYTE
end_define

begin_define
define|#
directive|define
name|TYPW
value|WORD
end_define

begin_define
define|#
directive|define
name|TYPL
value|LONG
end_define

begin_define
define|#
directive|define
name|TYPQ
value|QUAD
end_define

begin_define
define|#
directive|define
name|TYPO
value|OCTA
end_define

begin_define
define|#
directive|define
name|TYPF
value|FFLOAT
end_define

begin_define
define|#
directive|define
name|TYPD
value|DFLOAT
end_define

begin_define
define|#
directive|define
name|TYPG
value|GFLOAT
end_define

begin_define
define|#
directive|define
name|TYPH
value|HFLOAT
end_define

begin_decl_stmt
name|readonly
name|struct
name|optab
name|optab
index|[]
init|=
block|{
include|#
directive|include
file|"./instrs.c2"
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

