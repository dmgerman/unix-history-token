begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|PRIVATE_H
end_define

begin_comment
comment|/* ** This header is for use ONLY with the time conversion code. ** There is no guarantee that it will remain unchanged, ** or that it will remain at all. ** Do NOT copy it to any system include directory. ** Thank you! */
end_comment

begin_comment
comment|/* ** ID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOID
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|privatehid
index|[]
init|=
literal|"@(#)private.h	7.5"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_comment
comment|/* ** const */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined const */
end_comment

begin_comment
comment|/* ** void */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|void
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|sun
end_ifndef

begin_define
define|#
directive|define
name|void
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined sun */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined vax */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined void */
end_comment

begin_comment
comment|/* ** P((args)) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|ASTERISK
value|*
end_define

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|( /ASTERISK x ASTERISK/ )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined P */
end_comment

begin_comment
comment|/* ** genericptr_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|genericptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_typedef
typedef|typedef
name|char
modifier|*
name|genericptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_comment
comment|/* for time_t */
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"ctype.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"string.h"
end_include

begin_include
include|#
directive|include
file|"limits.h"
end_include

begin_comment
comment|/* for CHAR_BIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_
end_ifndef

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined _TIME_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|remove
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|unlink
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|remove
value|unlink
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined remove */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILENAME_MAX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined unix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|FILENAME_MAX
value|MAXPATHLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined MAXPATHLEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|FILENAME_MAX
value|1024
end_define

begin_comment
comment|/* Pure guesswork */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined FILENAME_MAX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined EXIT_SUCCESS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined EXIT_FAILURE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|alloc_size_t
value|size_t
end_define

begin_define
define|#
directive|define
name|qsort_size_t
value|size_t
end_define

begin_define
define|#
directive|define
name|fwrite_size_t
value|size_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|alloc_size_t
end_ifndef

begin_define
define|#
directive|define
name|alloc_size_t
value|unsigned
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined alloc_size_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|qsort_size_t
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_define
define|#
directive|define
name|qsort_size_t
value|unsigned
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined USG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_define
define|#
directive|define
name|qsort_size_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined qsort_size_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fwrite_size_t
end_ifndef

begin_define
define|#
directive|define
name|fwrite_size_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined fwrite_size_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sprintf
name|P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
name|format
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
comment|/* !defined USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_comment
comment|/* ** Ensure that these are declared--redundantly declaring them shouldn't hurt. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|genericptr_t
name|malloc
name|P
argument_list|(
operator|(
name|alloc_size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|genericptr_t
name|calloc
name|P
argument_list|(
operator|(
name|alloc_size_t
name|nelem
operator|,
name|alloc_size_t
name|elsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|genericptr_t
name|realloc
name|P
argument_list|(
operator|(
name|genericptr_t
name|oldptr
operator|,
name|alloc_size_t
name|newsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|exit
name|P
argument_list|(
operator|(
name|int
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|qsort
name|P
argument_list|(
operator|(
name|genericptr_t
name|base
operator|,
name|qsort_size_t
name|nelem
operator|,
name|qsort_size_t
name|elsize
operator|,
name|int
argument_list|(
operator|*
name|comp
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|perror
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free
name|P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined USG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined FALSE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_STRLEN_MAXIMUM
end_ifndef

begin_comment
comment|/* ** 302 / 1000 is log10(2.0) rounded up. ** Subtract one for the sign bit; ** add one for integer division truncation; ** add one more for a minus sign. */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_MAXIMUM
parameter_list|(
name|type
parameter_list|)
define|\
value|((sizeof(type) * CHAR_BIT - 1) * 302 / 1000 + 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined INT_STRLEN_MAXIMUM */
end_comment

begin_comment
comment|/* ** UNIX is a registered trademark of AT&T. ** VAX is a trademark of Digital Equipment Corporation. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined PRIVATE_H */
end_comment

end_unit

