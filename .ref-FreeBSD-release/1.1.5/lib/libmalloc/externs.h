begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|EXTERNS_H__
end_ifndef

begin_define
define|#
directive|define
name|EXTERNS_H__
end_define

begin_comment
comment|/* Lots of ugliness as we cope with non-standardness */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDHEADERS
end_ifdef

begin_comment
comment|/* if we have properly prototyped standard headers, use them */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! STDHEADERS */
end_comment

begin_comment
comment|/* # include<sys/types.h> */
end_comment

begin_define
define|#
directive|define
name|caddr_t
value|char *
end_define

begin_comment
comment|/*   *  Malloc definitions from General Utilities<stdlib.h>. Note that we  *  disagree with Berkeley Unix on the return type of free/cfree.  */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|malloc
name|proto
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
name|proto
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
name|proto
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
name|void
name|free
name|proto
argument_list|(
operator|(
name|univptr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General Utilities<stdlib.h> */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|abort
name|proto
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
name|exit
name|proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  Input/Output<stdio.h> Note we disagree with Berkeley Unix on  *  sprintf().  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* can't win with this one */
end_comment

begin_endif
unit|extern int sprintf proto((char *, const char *, ...));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|fputs
name|proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fflush
name|proto
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
name|int
name|setvbuf
name|proto
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|memsize_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character Handling:<string.h> */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|memset
name|proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|int
operator|,
name|memsize_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* clash with builtin, garn */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|memcpy
name|proto
argument_list|(
operator|(
name|univptr_t
operator|,
specifier|const
name|univptr_t
operator|,
name|memsize_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|memsize_t
name|strlen
name|proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UNIX -- unistd.h */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write
name|proto
argument_list|(
operator|(
name|int
comment|/*fd*/
operator|,
specifier|const
name|char
operator|*
comment|/*buf*/
operator|,
name|int
comment|/*nbytes*/
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|open
name|proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
comment|/*path*/
operator|,
name|int
comment|/*flags*/
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDHEADERS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_PAGESIZE
end_ifdef

begin_comment
comment|/* Solaris 2.x, SVR4? */
end_comment

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf(_SC_PAGESIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _SC_PAGESIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_PAGE_SIZE
end_ifdef

begin_comment
comment|/* HP, IBM */
end_comment

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf(_SC_PAGE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _SC_PAGE_SIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|getpagesize
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|getpagesize
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* getpagesize */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SC_PAGE_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SC_PAGESIZE */
end_comment

begin_decl_stmt
specifier|extern
name|caddr_t
name|sbrk
name|proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backwards compatibility with BSD/Sun -- these are going to vanish one day */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|valloc
name|proto
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
name|proto
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
name|void
name|cfree
name|proto
argument_list|(
operator|(
name|univptr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Malloc definitions - my additions.  Yuk, should use malloc.h properly!!  */
end_comment

begin_decl_stmt
specifier|extern
name|univptr_t
name|emalloc
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|mal_debug
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mal_sbrkset
name|proto
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
name|proto
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
name|proto
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
name|mal_setstatsfile
name|proto
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
name|proto
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
name|proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal definitions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__nothing
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|univptr_t
name|_mal_sbrk
name|proto
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
name|_mal_mmap
name|proto
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MMAP
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|madvise
name|proto
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_decl_stmt
specifier|extern
name|caddr_t
name|mmap
name|proto
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MMAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXTERNS_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

