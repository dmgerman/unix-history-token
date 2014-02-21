begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function declarations for libiberty.     Copyright 2001, 2002, 2005 Free Software Foundation, Inc.        Note - certain prototypes declared in this header file are for    functions whoes implementation copyright does not belong to the    FSF.  Those prototypes are present in this file for reference    purposes only and their presence in this file should not construed    as an indication of ownership by the FSF of the implementation of    those functions in any way or form whatsoever.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.        Written by Cygnus Support, 1994.     The libiberty library provides a number of functions which are    missing on some operating systems.  We do not declare those here,    to avoid conflicts with the system header files on operating    systems that do support those functions.  In this file we only    declare those functions which are specific to libiberty.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|"ansidecl.h"
comment|/* Get a definition for size_t.  */
include|#
directive|include
file|<stddef.h>
comment|/* Get a definition for va_list.  */
include|#
directive|include
file|<stdarg.h>
include|#
directive|include
file|<stdio.h>
comment|/* If the OS supports it, ensure that the supplied stream is setup to    avoid any multi-threaded locking.  Otherwise leave the FILE pointer    unchanged.  If the stream is NULL do nothing.  */
specifier|extern
name|void
name|unlock_stream
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
comment|/* If the OS supports it, ensure that the standard I/O streams, stdin,    stdout and stderr are setup to avoid any multi-threaded locking.    Otherwise do nothing.  */
specifier|extern
name|void
name|unlock_std_streams
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Open and return a FILE pointer.  If the OS supports it, ensure that    the stream is setup to avoid any multi-threaded locking.  Otherwise    return the FILE pointer unchanged.  */
specifier|extern
name|FILE
modifier|*
name|fopen_unlocked
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|FILE
modifier|*
name|fdopen_unlocked
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|FILE
modifier|*
name|freopen_unlocked
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
comment|/* Build an argument vector from a string.  Allocates memory using    malloc.  Use freeargv to free the vector.  */
specifier|extern
name|char
modifier|*
modifier|*
name|buildargv
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Free a vector returned by buildargv.  */
specifier|extern
name|void
name|freeargv
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* Duplicate an argument vector. Allocates memory using malloc.  Use    freeargv to free the vector.  */
specifier|extern
name|char
modifier|*
modifier|*
name|dupargv
argument_list|(
name|char
operator|*
operator|*
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Expand "@file" arguments in argv.  */
specifier|extern
name|void
name|expandargv
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the last component of a path name.  Note that we can't use a    prototype here because the parameter is declared inconsistently    across different systems, sometimes as "char *" and sometimes as    "const char *" */
comment|/* HAVE_DECL_* is a three-state macro: undefined, 0 or 1.  If it is    undefined, we haven't run the autoconf check so provide the    declaration without arguments.  If it is 0, we checked and failed    to find the declaration so provide a fully prototyped one.  If it    is 1, we found it so don't provide any declaration at all.  */
if|#
directive|if
operator|!
name|HAVE_DECL_BASENAME
if|#
directive|if
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_DECL_BASENAME
argument_list|)
specifier|extern
name|char
modifier|*
name|basename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
comment|/* Do not allow basename to be used if there is no prototype seen.  We    either need to use the above prototype or have one from    autoconf which would result in HAVE_DECL_BASENAME being set.  */
define|#
directive|define
name|basename
value|basename_cannot_be_used_without_a_prototype
endif|#
directive|endif
endif|#
directive|endif
comment|/* A well-defined basename () that is always compiled in.  */
specifier|extern
specifier|const
name|char
modifier|*
name|lbasename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* A well-defined realpath () that is always compiled in.  */
specifier|extern
name|char
modifier|*
name|lrealpath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Concatenate an arbitrary number of strings.  You must pass NULL as    the last argument of this function, to terminate the list of    strings.  Allocates memory using xmalloc.  */
specifier|extern
name|char
modifier|*
name|concat
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_MALLOC
name|ATTRIBUTE_SENTINEL
decl_stmt|;
comment|/* Concatenate an arbitrary number of strings.  You must pass NULL as    the last argument of this function, to terminate the list of    strings.  Allocates memory using xmalloc.  The first argument is    not one of the strings to be concatenated, but if not NULL is a    pointer to be freed after the new string is created, similar to the    way xrealloc works.  */
specifier|extern
name|char
modifier|*
name|reconcat
argument_list|(
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_MALLOC
name|ATTRIBUTE_SENTINEL
decl_stmt|;
comment|/* Determine the length of concatenating an arbitrary number of    strings.  You must pass NULL as the last argument of this function,    to terminate the list of strings.  */
specifier|extern
name|unsigned
name|long
name|concat_length
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_SENTINEL
decl_stmt|;
comment|/* Concatenate an arbitrary number of strings into a SUPPLIED area of    memory.  You must pass NULL as the last argument of this function,    to terminate the list of strings.  The supplied memory is assumed    to be large enough.  */
specifier|extern
name|char
modifier|*
name|concat_copy
argument_list|(
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_SENTINEL
decl_stmt|;
comment|/* Concatenate an arbitrary number of strings into a GLOBAL area of    memory.  You must pass NULL as the last argument of this function,    to terminate the list of strings.  The supplied memory is assumed    to be large enough.  */
specifier|extern
name|char
modifier|*
name|concat_copy2
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_SENTINEL
decl_stmt|;
comment|/* This is the global area used by concat_copy2.  */
specifier|extern
name|char
modifier|*
name|libiberty_concat_ptr
decl_stmt|;
comment|/* Concatenate an arbitrary number of strings.  You must pass NULL as    the last argument of this function, to terminate the list of    strings.  Allocates memory using alloca.  The arguments are    evaluated twice!  */
define|#
directive|define
name|ACONCAT
parameter_list|(
name|ACONCAT_PARAMS
parameter_list|)
define|\
value|(libiberty_concat_ptr = (char *) alloca (concat_length ACONCAT_PARAMS + 1), \    concat_copy2 ACONCAT_PARAMS)
comment|/* Check whether two file descriptors refer to the same file.  */
specifier|extern
name|int
name|fdmatch
parameter_list|(
name|int
name|fd1
parameter_list|,
name|int
name|fd2
parameter_list|)
function_decl|;
comment|/* Return the position of the first bit set in the argument.  */
comment|/* Prototypes vary from system to system, so we only provide a    prototype on systems where we know that we need it.  */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FFS
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FFS
specifier|extern
name|int
name|ffs
parameter_list|(
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* Get the working directory.  The result is cached, so don't call    chdir() between calls to getpwd().  */
specifier|extern
name|char
modifier|*
name|getpwd
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Get the current time.  */
comment|/* Prototypes vary from system to system, so we only provide a    prototype on systems where we know that we need it.  */
ifdef|#
directive|ifdef
name|__MINGW32__
comment|/* Forward declaration to avoid #include<sys/time.h>.   */
struct_decl|struct
name|timeval
struct_decl|;
specifier|extern
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* Get the amount of time the process has run, in microseconds.  */
specifier|extern
name|long
name|get_run_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Generate a relocated path to some installation directory.  Allocates    return value using malloc.  */
specifier|extern
name|char
modifier|*
name|make_relative_prefix
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Choose a temporary directory to use for scratch files.  */
specifier|extern
name|char
modifier|*
name|choose_temp_base
argument_list|(
name|void
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Return a temporary file name or NULL if unable to create one.  */
specifier|extern
name|char
modifier|*
name|make_temp_file
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Remove a link to a file unless it is special. */
specifier|extern
name|int
name|unlink_if_ordinary
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Allocate memory filled with spaces.  Allocates using malloc.  */
specifier|extern
specifier|const
name|char
modifier|*
name|spaces
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
comment|/* Return the maximum error number for which strerror will return a    string.  */
specifier|extern
name|int
name|errno_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return the name of an errno value (e.g., strerrno (EINVAL) returns    "EINVAL").  */
specifier|extern
specifier|const
name|char
modifier|*
name|strerrno
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Given the name of an errno value, return the value.  */
specifier|extern
name|int
name|strtoerrno
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* ANSI's strerror(), but more robust.  */
specifier|extern
name|char
modifier|*
name|xstrerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Return the maximum signal number for which strsignal will return a    string.  */
specifier|extern
name|int
name|signo_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return a signal message string for a signal number    (e.g., strsignal (SIGHUP) returns something like "Hangup").  */
comment|/* This is commented out as it can conflict with one in system headers.    We still document its existence though.  */
comment|/*extern const char *strsignal (int);*/
comment|/* Return the name of a signal number (e.g., strsigno (SIGHUP) returns    "SIGHUP").  */
specifier|extern
specifier|const
name|char
modifier|*
name|strsigno
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Given the name of a signal, return its number.  */
specifier|extern
name|int
name|strtosigno
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Register a function to be run by xexit.  Returns 0 on success.  */
specifier|extern
name|int
name|xatexit
parameter_list|(
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
comment|/* Exit, calling all the functions registered with xatexit.  */
specifier|extern
name|void
name|xexit
argument_list|(
name|int
name|status
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
comment|/* Set the program name used by xmalloc.  */
specifier|extern
name|void
name|xmalloc_set_program_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Report an allocation failure.  */
specifier|extern
name|void
name|xmalloc_failed
argument_list|(
name|size_t
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
comment|/* Allocate memory without fail.  If malloc fails, this will print a    message to stderr (using the name set by xmalloc_set_program_name,    if any) and then call xexit.  */
specifier|extern
name|void
modifier|*
name|xmalloc
argument_list|(
name|size_t
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Reallocate memory without fail.  This works like xmalloc.  Note,    realloc type functions are not suitable for attribute malloc since    they may return the same address across multiple calls. */
specifier|extern
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Allocate memory without fail and set it to zero.  This works like    xmalloc.  */
specifier|extern
name|void
modifier|*
name|xcalloc
argument_list|(
name|size_t
argument_list|,
name|size_t
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Copy a string into a memory buffer without fail.  */
specifier|extern
name|char
modifier|*
name|xstrdup
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Copy at most N characters from string into a buffer without fail.  */
specifier|extern
name|char
modifier|*
name|xstrndup
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* Copy an existing memory buffer to a new memory buffer without fail.  */
specifier|extern
name|void
modifier|*
name|xmemdup
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
name|size_t
argument_list|,
name|size_t
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
comment|/* APPLE LOCAL begin retune gc params 6124839 */
specifier|extern
name|unsigned
name|int
name|ncpu_available
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* APPLE LOCAL end retune gc params 6124839 */
comment|/* Physical memory routines.  Return values are in BYTES.  */
specifier|extern
name|double
name|physmem_total
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|double
name|physmem_available
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* These macros provide a K&R/C89/C++-friendly way of allocating structures    with nice encapsulation.  The XDELETE*() macros are technically    superfluous, but provided here for symmetry.  Using them consistently    makes it easier to update client code to use different allocators such    as new/delete and new[]/delete[].  */
comment|/* Scalar allocators.  */
define|#
directive|define
name|XNEW
parameter_list|(
name|T
parameter_list|)
value|((T *) xmalloc (sizeof (T)))
define|#
directive|define
name|XCNEW
parameter_list|(
name|T
parameter_list|)
value|((T *) xcalloc (1, sizeof (T)))
define|#
directive|define
name|XDELETE
parameter_list|(
name|P
parameter_list|)
value|free ((void*) (P))
comment|/* Array allocators.  */
define|#
directive|define
name|XNEWVEC
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
value|((T *) xmalloc (sizeof (T) * (N)))
define|#
directive|define
name|XCNEWVEC
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
value|((T *) xcalloc ((N), sizeof (T)))
define|#
directive|define
name|XRESIZEVEC
parameter_list|(
name|T
parameter_list|,
name|P
parameter_list|,
name|N
parameter_list|)
value|((T *) xrealloc ((void *) (P), sizeof (T) * (N)))
define|#
directive|define
name|XDELETEVEC
parameter_list|(
name|P
parameter_list|)
value|free ((void*) (P))
comment|/* Allocators for variable-sized structures and raw buffers.  */
define|#
directive|define
name|XNEWVAR
parameter_list|(
name|T
parameter_list|,
name|S
parameter_list|)
value|((T *) xmalloc ((S)))
define|#
directive|define
name|XCNEWVAR
parameter_list|(
name|T
parameter_list|,
name|S
parameter_list|)
value|((T *) xcalloc (1, (S)))
define|#
directive|define
name|XRESIZEVAR
parameter_list|(
name|T
parameter_list|,
name|P
parameter_list|,
name|S
parameter_list|)
value|((T *) xrealloc ((P), (S)))
comment|/* Type-safe obstack allocator.  */
define|#
directive|define
name|XOBNEW
parameter_list|(
name|O
parameter_list|,
name|T
parameter_list|)
value|((T *) obstack_alloc ((O), sizeof (T)))
define|#
directive|define
name|XOBFINISH
parameter_list|(
name|O
parameter_list|,
name|T
parameter_list|)
value|((T) obstack_finish ((O)))
comment|/* hex character manipulation routines */
define|#
directive|define
name|_hex_array_size
value|256
define|#
directive|define
name|_hex_bad
value|99
specifier|extern
specifier|const
name|unsigned
name|char
name|_hex_value
index|[
name|_hex_array_size
index|]
decl_stmt|;
specifier|extern
name|void
name|hex_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
define|#
directive|define
name|hex_p
parameter_list|(
name|c
parameter_list|)
value|(hex_value (c) != _hex_bad)
comment|/* If you change this, note well: Some code relies on side effects in    the argument being performed exactly once.  */
define|#
directive|define
name|hex_value
parameter_list|(
name|c
parameter_list|)
value|((unsigned int) _hex_value[(unsigned char) (c)])
comment|/* Flags for pex_init.  These are bits to be or'ed together.  */
comment|/* Record subprocess times, if possible.  */
define|#
directive|define
name|PEX_RECORD_TIMES
value|0x1
comment|/* Use pipes for communication between processes, if possible.  */
define|#
directive|define
name|PEX_USE_PIPES
value|0x2
comment|/* Save files used for communication between processes.  */
define|#
directive|define
name|PEX_SAVE_TEMPS
value|0x4
comment|/* Prepare to execute one or more programs, with standard output of    each program fed to standard input of the next.    FLAGS	As above.    PNAME	The name of the program to report in error messages.    TEMPBASE	A base name to use for temporary files; may be NULL to    		use a random name.    Returns NULL on error.  */
specifier|extern
name|struct
name|pex_obj
modifier|*
name|pex_init
parameter_list|(
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|pname
parameter_list|,
specifier|const
name|char
modifier|*
name|tempbase
parameter_list|)
function_decl|;
comment|/* Flags for pex_run.  These are bits to be or'ed together.  */
comment|/* Last program in pipeline.  Standard output of program goes to    OUTNAME, or, if OUTNAME is NULL, to standard output of caller.  Do    not set this if you want to call pex_read_output.  After this is    set, pex_run may no longer be called with the same struct    pex_obj.  */
define|#
directive|define
name|PEX_LAST
value|0x1
comment|/* Search for program in executable search path.  */
define|#
directive|define
name|PEX_SEARCH
value|0x2
comment|/* OUTNAME is a suffix.  */
define|#
directive|define
name|PEX_SUFFIX
value|0x4
comment|/* Send program's standard error to standard output.  */
define|#
directive|define
name|PEX_STDERR_TO_STDOUT
value|0x8
comment|/* Input file should be opened in binary mode.  This flag is ignored    on Unix.  */
define|#
directive|define
name|PEX_BINARY_INPUT
value|0x10
comment|/* Output file should be opened in binary mode.  This flag is ignored    on Unix.  For proper behaviour PEX_BINARY_INPUT and    PEX_BINARY_OUTPUT have to match appropriately--i.e., a call using    PEX_BINARY_OUTPUT should be followed by a call using    PEX_BINARY_INPUT.  */
define|#
directive|define
name|PEX_BINARY_OUTPUT
value|0x20
comment|/* Execute one program.  Returns NULL on success.  On error returns an    error string (typically just the name of a system call); the error    string is statically allocated.     OBJ		Returned by pex_init.     FLAGS	As above.     EXECUTABLE	The program to execute.     ARGV		NULL terminated array of arguments to pass to the program.     OUTNAME	Sets the output file name as follows:  		PEX_SUFFIX set (OUTNAME may not be NULL): 		  TEMPBASE parameter to pex_init not NULL: 		    Output file name is the concatenation of TEMPBASE 		    and OUTNAME. 		  TEMPBASE is NULL: 		    Output file name is a random file name ending in 		    OUTNAME. 		PEX_SUFFIX not set: 		  OUTNAME not NULL: 		    Output file name is OUTNAME. 		  OUTNAME NULL, TEMPBASE not NULL: 		    Output file name is randomly chosen using 		    TEMPBASE. 		  OUTNAME NULL, TEMPBASE NULL: 		    Output file name is randomly chosen.  		If PEX_LAST is not set, the output file name is the    		name to use for a temporary file holding stdout, if    		any (there will not be a file if PEX_USE_PIPES is set    		and the system supports pipes).  If a file is used, it    		will be removed when no longer needed unless    		PEX_SAVE_TEMPS is set.  		If PEX_LAST is set, and OUTNAME is not NULL, standard    		output is written to the output file name.  The file    		will not be removed.  If PEX_LAST and PEX_SUFFIX are    		both set, TEMPBASE may not be NULL.     ERRNAME	If not NULL, this is the name of a file to which 		standard error is written.  If NULL, standard error of 		the program is standard error of the caller.     ERR		On an error return, *ERR is set to an errno value, or    		to 0 if there is no relevant errno. */
specifier|extern
specifier|const
name|char
modifier|*
name|pex_run
parameter_list|(
name|struct
name|pex_obj
modifier|*
name|obj
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|executable
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|outname
parameter_list|,
specifier|const
name|char
modifier|*
name|errname
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/* As for pex_run (), but takes an extra parameter to enable the    environment for the child process to be specified.     ENV		The environment for the child process, specified as 		an array of character pointers.  Each element of the 		array should point to a string of the form VAR=VALUE,                 with the exception of the last element which must be                 a null pointer. */
specifier|extern
specifier|const
name|char
modifier|*
name|pex_run_in_environment
parameter_list|(
name|struct
name|pex_obj
modifier|*
name|obj
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|executable
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|env
parameter_list|,
specifier|const
name|char
modifier|*
name|outname
parameter_list|,
specifier|const
name|char
modifier|*
name|errname
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/* Return a stream for a temporary file to pass to the first program    in the pipeline as input.  The file name is chosen as for pex_run.    pex_run closes the file automatically; don't close it yourself.  */
specifier|extern
name|FILE
modifier|*
name|pex_input_file
parameter_list|(
name|struct
name|pex_obj
modifier|*
name|obj
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|in_name
parameter_list|)
function_decl|;
comment|/* Return a stream for a pipe connected to the standard input of the    first program in the pipeline.  You must have passed    `PEX_USE_PIPES' to `pex_init'.  Close the returned stream    yourself.  */
specifier|extern
name|FILE
modifier|*
name|pex_input_pipe
parameter_list|(
name|struct
name|pex_obj
modifier|*
name|obj
parameter_list|,
name|int
name|binary
parameter_list|)
function_decl|;
comment|/* Read the standard output of the last program to be executed.    pex_run can not be called after this.  BINARY should be non-zero if    the file should be opened in binary mode; this is ignored on Unix.    Returns NULL on error.  Don't call fclose on the returned FILE; it    will be closed by pex_free.  */
specifier|extern
name|FILE
modifier|*
name|pex_read_output
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
name|binary
parameter_list|)
function_decl|;
comment|/* Return exit status of all programs in VECTOR.  COUNT indicates the    size of VECTOR.  The status codes in the vector are in the order of    the calls to pex_run.  Returns 0 on error, 1 on success.  */
specifier|extern
name|int
name|pex_get_status
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
name|count
parameter_list|,
name|int
modifier|*
name|vector
parameter_list|)
function_decl|;
comment|/* Return times of all programs in VECTOR.  COUNT indicates the size    of VECTOR.  struct pex_time is really just struct timeval, but that    is not portable to all systems.  Returns 0 on error, 1 on    success.  */
struct|struct
name|pex_time
block|{
name|unsigned
name|long
name|user_seconds
decl_stmt|;
name|unsigned
name|long
name|user_microseconds
decl_stmt|;
name|unsigned
name|long
name|system_seconds
decl_stmt|;
name|unsigned
name|long
name|system_microseconds
decl_stmt|;
block|}
struct|;
specifier|extern
name|int
name|pex_get_times
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
name|count
parameter_list|,
name|struct
name|pex_time
modifier|*
name|vector
parameter_list|)
function_decl|;
comment|/* Clean up a pex_obj.  */
specifier|extern
name|void
name|pex_free
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|)
function_decl|;
comment|/* Just execute one program.  Return value is as for pex_run.    FLAGS	Combination of PEX_SEARCH and PEX_STDERR_TO_STDOUT.    EXECUTABLE	As for pex_run.    ARGV		As for pex_run.    PNAME	As for pex_init.    OUTNAME	As for pex_run when PEX_LAST is set.    ERRNAME	As for pex_run.    STATUS	Set to exit status on success.    ERR		As for pex_run. */
specifier|extern
specifier|const
name|char
modifier|*
name|pex_one
parameter_list|(
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|executable
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|pname
parameter_list|,
specifier|const
name|char
modifier|*
name|outname
parameter_list|,
specifier|const
name|char
modifier|*
name|errname
parameter_list|,
name|int
modifier|*
name|status
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/* pexecute and pwait are the old pexecute interface, still here for    backward compatibility.  Don't use these for new code.  Instead,    use pex_init/pex_run/pex_get_status/pex_free, or pex_one.  */
comment|/* Definitions used by the pexecute routine.  */
define|#
directive|define
name|PEXECUTE_FIRST
value|1
define|#
directive|define
name|PEXECUTE_LAST
value|2
define|#
directive|define
name|PEXECUTE_ONE
value|(PEXECUTE_FIRST + PEXECUTE_LAST)
define|#
directive|define
name|PEXECUTE_SEARCH
value|4
define|#
directive|define
name|PEXECUTE_VERBOSE
value|8
comment|/* Execute a program.  */
specifier|extern
name|int
name|pexecute
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Wait for pexecute to finish.  */
specifier|extern
name|int
name|pwait
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|HAVE_DECL_ASPRINTF
comment|/* Like sprintf but provides a pointer to malloc'd storage, which must    be freed by the caller.  */
specifier|extern
name|int
name|asprintf
argument_list|(
name|char
operator|*
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_VASPRINTF
comment|/* Like vsprintf but provides a pointer to malloc'd storage, which    must be freed by the caller.  */
specifier|extern
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|ATTRIBUTE_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|0
block|)
empty_stmt|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_SNPRINTF
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_SNPRINTF
end_if

begin_comment
comment|/* Like sprintf but prints at most N characters.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|snprintf
argument_list|(
name|char
operator|*
argument_list|,
name|size_t
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_3
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_VSNPRINTF
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_VSNPRINTF
end_if

begin_comment
comment|/* Like vsprintf but prints at most N characters.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|ATTRIBUTE_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_STRVERSCMP
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_STRVERSCMP
end_if

begin_comment
comment|/* Compare version strings.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|strverscmp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof (a) / sizeof ((a)[0]))
end_define

begin_comment
comment|/* Drastically simplified alloca configurator.  If we're using GCC,    we use __builtin_alloca; otherwise we use the C alloca.  The C    alloca is always available.  You can override GCC by defining    USE_C_ALLOCA yourself.  The canonical autoconf macro C_ALLOCA is    also set/unset as it is often used to indicate whether code needs    to call alloca(0).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|C_alloca
argument_list|(
name|size_t
argument_list|)
name|ATTRIBUTE_MALLOC
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|2000
operator|&&
operator|!
name|defined
name|USE_C_ALLOCA
end_if

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|x
parameter_list|)
value|__builtin_alloca(x)
end_define

begin_undef
undef|#
directive|undef
name|C_ALLOCA
end_undef

begin_define
define|#
directive|define
name|ASTRDUP
parameter_list|(
name|X
parameter_list|)
define|\
value|(__extension__ ({ const char *const libiberty_optr = (X); \    const unsigned long libiberty_len = strlen (libiberty_optr) + 1; \    char *const libiberty_nptr = (char *const) alloca (libiberty_len); \    (char *) memcpy (libiberty_nptr, libiberty_optr, libiberty_len); }))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|x
parameter_list|)
value|C_alloca(x)
end_define

begin_undef
undef|#
directive|undef
name|USE_C_ALLOCA
end_undef

begin_define
define|#
directive|define
name|USE_C_ALLOCA
value|1
end_define

begin_undef
undef|#
directive|undef
name|C_ALLOCA
end_undef

begin_define
define|#
directive|define
name|C_ALLOCA
value|1
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|libiberty_optr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|libiberty_nptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|libiberty_len
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ASTRDUP
parameter_list|(
name|X
parameter_list|)
define|\
value|(libiberty_optr = (X), \    libiberty_len = strlen (libiberty_optr) + 1, \    libiberty_nptr = (char *) alloca (libiberty_len), \    (char *) memcpy (libiberty_nptr, libiberty_optr, libiberty_len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (LIBIBERTY_H) */
end_comment

end_unit

