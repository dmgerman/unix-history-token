begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flex - tool to generate fast lexical analyzers */
end_comment

begin_comment
comment|/*  Copyright (c) 1990 The Regents of the University of California. */
end_comment

begin_comment
comment|/*  All rights reserved. */
end_comment

begin_comment
comment|/*  This code is derived from software contributed to Berkeley by */
end_comment

begin_comment
comment|/*  Vern Paxson. */
end_comment

begin_comment
comment|/*  The United States Government has rights in this work pursuant */
end_comment

begin_comment
comment|/*  to contract no. DE-AC03-76SF00098 between the United States */
end_comment

begin_comment
comment|/*  Department of Energy and the University of California. */
end_comment

begin_comment
comment|/*  This file is part of flex. */
end_comment

begin_comment
comment|/*  Redistribution and use in source and binary forms, with or without */
end_comment

begin_comment
comment|/*  modification, are permitted provided that the following conditions */
end_comment

begin_comment
comment|/*  are met: */
end_comment

begin_comment
comment|/*  1. Redistributions of source code must retain the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer. */
end_comment

begin_comment
comment|/*  2. Redistributions in binary form must reproduce the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer in the */
end_comment

begin_comment
comment|/*     documentation and/or other materials provided with the distribution. */
end_comment

begin_comment
comment|/*  Neither the name of the University nor the names of its contributors */
end_comment

begin_comment
comment|/*  may be used to endorse or promote products derived from this software */
end_comment

begin_comment
comment|/*  without specific prior written permission. */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
end_comment

begin_comment
comment|/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
end_comment

begin_comment
comment|/*  PURPOSE. */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SCANOPT_H
end_ifndef

begin_define
define|#
directive|define
name|SCANOPT_H
end_define

begin_include
include|#
directive|include
file|"flexdef.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SCANOPT_USAGE
end_ifndef

begin_comment
comment|/* Used by scanopt_usage for pretty-printing. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES_H
end_ifdef

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
ifndef|#
directive|ifndef
name|PROTO
define|#
directive|define
name|PROTO
parameter_list|(
name|args
parameter_list|)
value|args
endif|#
directive|endif
comment|/* Error codes. */
enum|enum
name|scanopt_err_t
block|{
name|SCANOPT_ERR_OPT_UNRECOGNIZED
init|=
operator|-
literal|1
block|,
comment|/* Unrecognized option. */
name|SCANOPT_ERR_OPT_AMBIGUOUS
init|=
operator|-
literal|2
block|,
comment|/* It matched more than one option name. */
name|SCANOPT_ERR_ARG_NOT_FOUND
init|=
operator|-
literal|3
block|,
comment|/* The required arg was not found. */
name|SCANOPT_ERR_ARG_NOT_ALLOWED
init|=
operator|-
literal|4
comment|/* Option does not take an argument. */
block|}
enum|;
comment|/* flags passed to scanopt_init */
enum|enum
name|scanopt_flag_t
block|{
name|SCANOPT_NO_ERR_MSG
init|=
literal|0x01
comment|/* Suppress printing to stderr. */
block|}
enum|;
comment|/* Specification for a single option. */
struct|struct
name|optspec_t
block|{
specifier|const
name|char
modifier|*
name|opt_fmt
decl_stmt|;
comment|/* e.g., "--foo=FILE", "-f FILE", "-n [NUM]" */
name|int
name|r_val
decl_stmt|;
comment|/* Value to be returned by scanopt_ex(). */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* Brief description of this option, or NULL. */
block|}
struct|;
typedef|typedef
name|struct
name|optspec_t
name|optspec_t
typedef|;
comment|/* Used internally by scanopt() to maintain state. */
comment|/* Never modify these value directly. */
typedef|typedef
name|void
modifier|*
name|scanopt_t
typedef|;
comment|/* Initializes scanner and checks option list for errors.  * Parameters:  *   options - Array of options.  *   argc    - Same as passed to main().  *   argv    - Same as passed to main(). First element is skipped.  *   flags   - Control behavior.  * Return:  A malloc'd pointer .  */
name|scanopt_t
modifier|*
name|scanopt_init
name|PROTO
argument_list|(
operator|(
specifier|const
name|optspec_t
operator|*
name|options
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
comment|/* Frees memory used by scanner.  * Always returns 0. */
name|int
name|scanopt_destroy
name|PROTO
argument_list|(
operator|(
name|scanopt_t
operator|*
name|scanner
operator|)
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_SCANOPT_USAGE
comment|/* Prints a usage message based on contents of optlist.  * Parameters:  *   scanner  - The scanner, already initialized with scanopt_init().  *   fp       - The file stream to write to.  *   usage    - Text to be prepended to option list. May be NULL.  * Return:  Always returns 0 (zero).  */
name|int
name|scanopt_usage
name|PROTO
argument_list|(
operator|(
name|scanopt_t
operator|*
name|scanner
operator|,
name|FILE
operator|*
name|fp
operator|,
specifier|const
name|char
operator|*
name|usage
operator|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* Scans command-line options in argv[].  * Parameters:  *   scanner  - The scanner, already initialized with scanopt_init().  *   optarg   - Return argument, may be NULL.  *              On success, it points to start of an argument.  *   optindex - Return argument, may be NULL.  *              On success or failure, it is the index of this option.  *              If return is zero, then optindex is the NEXT valid option index.  *  * Return:> 0 on success. Return value is from optspec_t->rval.  *         == 0 if at end of options.  *< 0 on error (return value is an error code).  *  */
name|int
name|scanopt
name|PROTO
argument_list|(
operator|(
name|scanopt_t
operator|*
name|scanner
operator|,
name|char
operator|*
operator|*
name|optarg
operator|,
name|int
operator|*
name|optindex
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vim:set tabstop=8 softtabstop=4 shiftwidth=4: */
end_comment

end_unit

