begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function declarations for libiberty.    Written by Cygnus Support, 1994.     The libiberty library provides a number of functions which are    missing on some operating systems.  We do not declare those here,    to avoid conflicts with the system header files on operating    systems that do support those functions.  In this file we only    declare those functions which are specific to libiberty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBIBERTY_H
end_ifndef

begin_define
define|#
directive|define
name|LIBIBERTY_H
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* Build an argument vector from a string.  Allocates memory using    malloc.  Use freeargv to free the vector.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|buildargv
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a vector returned by buildargv.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|freeargv
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the last component of a path name.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|basename
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate an arbitrary number of strings, up to (char *) NULL.    Allocates memory using xmalloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|concat
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check whether two file descriptors refer to the same file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fdmatch
name|PARAMS
argument_list|(
operator|(
name|int
name|fd1
operator|,
name|int
name|fd2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the amount of time the process has run, in microseconds.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|get_run_time
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate memory filled with spaces.  Allocates using malloc.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|spaces
name|PARAMS
argument_list|(
operator|(
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the maximum error number for which strerror will return a    string.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno_max
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the name of an errno value (e.g., strerrno (EINVAL) returns    "EINVAL").  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|strerrno
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given the name of an errno value, return the value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strtoerrno
name|PARAMS
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
comment|/* Return the maximum signal number for which strsignal will return a    string.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|signo_max
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the name of a signal number (e.g., strsigno (SIGHUP) returns    "SIGHUP").  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|strsigno
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given the name of a signal, return its number.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strtosigno
name|PARAMS
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
comment|/* Register a function to be run by xexit.  Returns 0 on success.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xatexit
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exit, calling all the functions registered with xatexit.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|xexit
name|PARAMS
argument_list|(
operator|(
name|int
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
name|libiberty_voidfn
name|PARAMS
typedef|((
name|int
name|status
typedef|));
end_typedef

begin_decl_stmt
specifier|__volatile__
name|libiberty_voidfn
name|xexit
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the program name used by xmalloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|xmalloc_set_program_name
name|PARAMS
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
comment|/* Allocate memory without fail.  If malloc fails, this will print a    message to stderr (using the name set by xmalloc_set_program_name,    if any) and then call xexit.     FIXME: We do not declare the parameter type (size_t) in order to    avoid conflicts with other declarations of xmalloc that exist in    programs which use libiberty.  */
end_comment

begin_function_decl
specifier|extern
name|PTR
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Reallocate memory without fail.  This works like xmalloc.     FIXME: We do not declare the parameter types for the same reason as    xmalloc.  */
end_comment

begin_function_decl
specifier|extern
name|PTR
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (LIBIBERTY_H) */
end_comment

end_unit

