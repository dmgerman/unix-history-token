begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NONSTD_H
end_ifndef

begin_define
define|#
directive|define
name|NONSTD_H
end_define

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
name|nonstdhid
index|[]
init|=
literal|"@(#)nonstd.h	4.2"
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
name|s
parameter_list|)
value|s
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_comment
comment|/* ** Cover for stupid Turbo C */
end_comment

begin_define
define|#
directive|define
name|genericptr_t
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined __TURBOC__ */
end_comment

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
comment|/* !defined __TURBOC__ */
end_comment

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
name|fread_size_t
value|size_t
end_define

begin_define
define|#
directive|define
name|fwrite_size_t
value|size_t
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined __STDC__ */
end_comment

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
name|s
parameter_list|)
value|(/ASTERISK s ASTERISK/)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|genericptr_t
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
comment|/* !defined genericptr_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|alloc_size_t
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|alloc_size_t
typedef|;
end_typedef

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

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_typedef
typedef|typedef
name|int
name|qsort_size_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined BSD */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|qsort_size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined BSD */
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
name|fread_size_t
end_ifndef

begin_typedef
typedef|typedef
name|int
name|fread_size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined fread_size_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fwrite_size_t
end_ifndef

begin_typedef
typedef|typedef
name|int
name|fwrite_size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined fwrite_size_t */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
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
comment|/* !defined NONSTD_H */
end_comment

begin_comment
comment|/* ** UNIX is a registered trademark of AT&T. */
end_comment

end_unit

