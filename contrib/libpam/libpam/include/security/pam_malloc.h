begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: pam_malloc.h,v 1.1 1996/11/10 21:23:14 morgan Exp $  * $FreeBSD$  *  * $Log: pam_malloc.h,v $  * Revision 1.1  1996/11/10 21:23:14  morgan  * Initial revision  *  */
end_comment

begin_comment
comment|/*  * This file (via the use of macros) defines a wrapper for the malloc  * family of calls. It logs where the memory was requested and also  * where it was free()'d and keeps a list of currently requested memory.  *  * It is hoped that it will provide some help in locating memory leaks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_MALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|PAM_MALLOC_H
end_define

begin_comment
comment|/* these are the macro definitions for the stdlib.h memory functions */
end_comment

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|s
parameter_list|)
value|pam_malloc(s,__FILE__,__FUNCTION__,__LINE__)
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|pam_calloc(n,s,__FILE__,__FUNCTION__,__LINE__)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|x
parameter_list|)
value|pam_free(x,__FILE__,__FUNCTION__,__LINE__)
end_define

begin_comment
comment|/* #define memalign(a,s)  pam_memalign(a,s,__FILE__,__FUNCTION__,__LINE__) */
end_comment

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|pam_realloc(x,s,__FILE__,__FUNCTION__,__LINE__)
end_define

begin_comment
comment|/* #define valloc(s)      pam_valloc(s,__FILE__,__FUNCTION__,__LINE__) */
end_comment

begin_comment
comment|/* #define alloca(s)      pam_alloca(s,__FILE__,__FUNCTION__,__LINE__) */
end_comment

begin_define
define|#
directive|define
name|exit
parameter_list|(
name|i
parameter_list|)
value|pam_exit(i,__FILE__,__FUNCTION__,__LINE__)
end_define

begin_comment
comment|/* these are the prototypes for the wrapper functions */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
specifier|extern
name|void
modifier|*
name|pam_malloc
parameter_list|(
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|pam_calloc
parameter_list|(
name|size_t
name|n
parameter_list|,
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pam_free
parameter_list|(
name|void
modifier|*
name|x
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|pam_memalign
parameter_list|(
name|size_t
name|a
parameter_list|,
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|pam_realloc
parameter_list|(
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|pam_valloc
parameter_list|(
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|pam_alloca
parameter_list|(
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pam_exit
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* these are the flags used to turn on and off diagnostics */
end_comment

begin_define
define|#
directive|define
name|PAM_MALLOC_LEAKED
value|01
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_REQUEST
value|02
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_FREE
value|04
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_EXCH
value|(PAM_MALLOC_FREED|PAM_MALLOC_EXCH)
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_RESIZE
value|010
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_FAIL
value|020
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_NULL
value|040
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_VERIFY
value|0100
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_FUNC
value|0200
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_PAUSE
value|0400
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_STOP
value|01000
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_ALL
value|0777
end_define

begin_define
define|#
directive|define
name|PAM_MALLOC_DEFAULT
define|\
value|(PAM_MALLOC_LEAKED|PAM_MALLOC_PAUSE|PAM_MALLOC_FAIL)
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|pam_malloc_outfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defaults to stdout */
end_comment

begin_comment
comment|/* how much output do you want? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pam_malloc_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pam_malloc_delay_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how long to pause on errors */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_MALLOC_H */
end_comment

end_unit

