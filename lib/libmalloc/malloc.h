begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright University of Toronto 1988, 1989, 1993.  * Written by Mark Moraes  *  * Permission is granted to anyone to use this software for any purpose on  * any computer system, and to alter it and redistribute it freely, subject  * to the following restrictions:  *  * 1. The author and the University of Toronto are not responsible   *    for the consequences of use of this software, no matter how awful,   *    even if they arise from flaws in it.  *  * 2. The origin of this software must not be misrepresented, either by  *    explicit claim or by omission.  Since few users ever read sources,  *    credits must appear in the documentation.  *  * 3. Altered versions must be plainly marked as such, and must not be  *    misrepresented as being the original software.  Since few users  *    ever read sources, credits must appear in the documentation.  *  * 4. This notice may not be removed or altered.  *  * $Id: malloc.h,v 1.16 1993/05/23 03:38:27 moraes Exp $   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XMALLOC_H__
end_ifndef

begin_define
define|#
directive|define
name|__XMALLOC_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANSI_TYPES
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|univptr_t
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! ANSI_TYPES */
end_comment

begin_define
define|#
directive|define
name|univptr_t
value|char *
end_define

begin_define
define|#
directive|define
name|size_t
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI_TYPES */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANSI_TYPES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__proto
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__proto
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  defined so users of new features of this malloc can #ifdef  *  invocations of those features.  */
end_comment

begin_define
define|#
directive|define
name|CSRIMALLOC
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_TRACE
end_ifdef

begin_comment
comment|/* Tracing malloc definitions - helps find leaks */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|__malloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__calloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__realloc
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__valloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__memalign
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__emalloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__ecalloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|__erealloc
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__strdup
name|__proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__strsave
name|__proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__free
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__cfree
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|x
parameter_list|)
value|__malloc((x), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|__calloc((x), (n), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|__realloc((p), (x), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|memalign
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|__memalign((x), (n), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|valloc
parameter_list|(
name|x
parameter_list|)
value|__valloc((x), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|emalloc
parameter_list|(
name|x
parameter_list|)
value|__emalloc((x), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ecalloc
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|__ecalloc((x), (n), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|erealloc
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|__erealloc((p), (x), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|p
parameter_list|)
value|__strdup((p), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|strsave
parameter_list|(
name|p
parameter_list|)
value|__strsave((p), __FILE__, __LINE__)
end_define

begin_comment
comment|/* cfree and free are identical */
end_comment

begin_define
define|#
directive|define
name|cfree
parameter_list|(
name|p
parameter_list|)
value|__free((p), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|p
parameter_list|)
value|__free((p), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MALLOC_TRACE */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|malloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|calloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|realloc
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|valloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|memalign
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|emalloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|ecalloc
name|__proto
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|erealloc
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|__proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strsave
name|__proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cfree
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MALLOC_TRACE */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mal_debug
name|__proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_dumpleaktrace
name|__proto
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_heapdump
name|__proto
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_leaktrace
name|__proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_sbrkset
name|__proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_slopset
name|__proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_statsdump
name|__proto
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_setstatsfile
name|__proto
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_trace
name|__proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mal_verify
name|__proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_mmap
name|__proto
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  You may or may not want this - In gcc version 1.30, on Sun3s running  *  SunOS3.5, this works fine.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|n
parameter_list|)
value|__builtin_alloca(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|n
parameter_list|)
value|__builtin_alloca(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_TYPES
end_ifdef

begin_undef
undef|#
directive|undef
name|univptr_t
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! ANSI_TYPES */
end_comment

begin_undef
undef|#
directive|undef
name|univptr_t
end_undef

begin_undef
undef|#
directive|undef
name|size_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI_TYPES */
end_comment

begin_comment
comment|/* Just in case you want an ANSI malloc without an ANSI compiler */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANSI_TYPES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|size_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__proto
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XMALLOC_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

