begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_define
define|#
directive|define
name|INTRCNT_COUNT
value|(1 + ICU_LEN + 2 * ICU_LEN)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|u_long
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts for for each device and stray */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|intrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table containing device names */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|eintrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrnames[] */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

