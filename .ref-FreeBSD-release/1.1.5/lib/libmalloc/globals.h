begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: globals.h,v 1.6 1993/05/23 05:10:52 moraes Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLOBALS_H__
end_ifndef

begin_define
define|#
directive|define
name|__GLOBALS_H__
end_define

begin_comment
comment|/*  *  Remember to initialize the variable in globals.c if you want, and  *  provide an alternative short name in globrename.h  */
end_comment

begin_include
include|#
directive|include
file|"globrename.h"
end_include

begin_decl_stmt
specifier|extern
name|size_t
name|_malloc_minchunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Word
modifier|*
name|_malloc_rover
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Word
modifier|*
name|_malloc_hiword
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Word
modifier|*
name|_malloc_loword
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|_malloc_sbrkunits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|_malloc_totalavail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Word
modifier|*
name|_malloc_mem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_malloc_tracing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No tracing */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|_malloc_statsfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|_malloc_statsbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_malloc_leaktrace
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PROFILESIZES
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|_malloc_scount
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILESIZES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  *  0 or 1 means checking all pointers before using them. Reasonably  *  thorough.  2 means check the entire heap on every call to  *  malloc/free/realloc/memalign. (the rest call these)  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_malloc_debugging
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_extern
extern|extern univptr_t (* _malloc_memfunc
end_extern

begin_expr_stmt
unit|)
name|proto
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLOBALS_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

