begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stdlib.h	5.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDLIB_H_
end_define

begin_include
include|#
directive|include
file|<machine/machtypes.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WCHAR_T_
end_ifdef

begin_typedef
typedef|typedef
name|_WCHAR_T_
name|wchar_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|quot
decl_stmt|;
comment|/* quotient */
name|int
name|rem
decl_stmt|;
comment|/* remainder */
block|}
name|div_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|quot
decl_stmt|;
comment|/* quotient */
name|long
name|rem
decl_stmt|;
comment|/* remainder */
block|}
name|ldiv_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|RAND_MAX
value|0x7ffffffff
end_define

begin_define
define|#
directive|define
name|MB_CUR_MAX
value|1
end_define

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|abs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
name|_func
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atof
parameter_list|(
specifier|const
name|char
modifier|*
name|_nptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
name|_nptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|atol
parameter_list|(
specifier|const
name|char
modifier|*
name|_nptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bsearch
parameter_list|(
specifier|const
name|void
modifier|*
name|_key
parameter_list|,
specifier|const
name|void
modifier|*
name|_base
parameter_list|,
name|size_t
name|_nmemb
parameter_list|,
name|size_t
name|_size
parameter_list|,
name|int
function_decl|(
modifier|*
name|_compar
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
name|_nmemb
parameter_list|,
name|size_t
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|div_t
name|div
parameter_list|(
name|int
name|_numer
parameter_list|,
name|int
name|_denom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exit
parameter_list|(
name|int
name|_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
name|_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|labs
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ldiv_t
name|ldiv
parameter_list|(
name|long
name|_numer
parameter_list|,
name|long
name|_denom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsort
parameter_list|(
name|void
modifier|*
name|_base
parameter_list|,
name|size_t
name|_nmemb
parameter_list|,
name|size_t
name|_size
parameter_list|,
name|int
function_decl|(
modifier|*
name|_compar
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rand
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
name|_ptr
parameter_list|,
name|size_t
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srand
parameter_list|(
name|unsigned
name|_seed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|_nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|_endptr
parameter_list|,
name|int
name|_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|_nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|_endptr
parameter_list|,
name|int
name|_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|system
parameter_list|(
specifier|const
name|char
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_function_decl
name|void
name|cfree
parameter_list|(
name|void
modifier|*
name|_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putenv
parameter_list|(
specifier|const
name|char
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|_string
parameter_list|,
specifier|const
name|char
modifier|*
name|_value
parameter_list|,
name|int
name|_overwrite
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_YET_IMPLEMENTED
end_ifdef

begin_function_decl
name|int
name|mblen
parameter_list|(
specifier|const
name|char
modifier|*
name|_s
parameter_list|,
name|size_t
name|_n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbstowcs
parameter_list|(
name|wchar_t
modifier|*
name|_pwcs
parameter_list|,
specifier|const
name|char
modifier|*
name|_s
parameter_list|,
name|size_t
name|_n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wctomb
parameter_list|(
name|char
modifier|*
name|_s
parameter_list|,
name|wchar_t
name|_wchar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mbtowc
parameter_list|(
name|wchar_t
modifier|*
name|_pwc
parameter_list|,
specifier|const
name|char
modifier|*
name|_s
parameter_list|,
name|size_t
name|_n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|strtod
parameter_list|(
specifier|const
name|char
modifier|*
name|_nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|_endptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcstombs
parameter_list|(
name|char
modifier|*
name|_s
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|_pwcs
parameter_list|,
name|size_t
name|_n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__STDC__ */
end_comment

begin_function_decl
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|abs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atoi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bsearch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|div_t
name|div
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|labs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ldiv_t
name|ldiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|strtol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|strtoul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|system
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_function_decl
name|void
name|cfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_YET_IMPLEMENTED
end_ifdef

begin_function_decl
name|int
name|mblen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbstowcs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wctomb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mbtowc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|strtod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcstombs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDLIB_H_ */
end_comment

end_unit

