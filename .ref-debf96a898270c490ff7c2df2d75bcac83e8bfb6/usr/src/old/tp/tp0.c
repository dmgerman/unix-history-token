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
literal|"@(#)tp0.c	4.2 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tp.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_decl_stmt
name|char
name|mt
index|[]
init|=
name|_PATH_MT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tc
index|[]
init|=
name|_PATH_TAPX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flags
init|=
name|flu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mheader
index|[]
init|=
name|_PATH_MBOOT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|theader
index|[]
init|=
name|_PATH_TBOOT
decl_stmt|;
end_decl_stmt

end_unit

