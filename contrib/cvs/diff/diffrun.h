begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface header file for GNU DIFF library.    Copyright (C) 1998 Free Software Foundation, Inc.  This file is part of GNU DIFF.  GNU DIFF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU DIFF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIFFRUN_H
end_ifndef

begin_define
define|#
directive|define
name|DIFFRUN_H
end_define

begin_comment
comment|/* This header file defines the interfaces used by the diff library.    It should be included by programs which use the diff library.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|&&
name|__STDC__
end_if

begin_define
define|#
directive|define
name|DIFFPARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIFFPARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The diff_callbacks structure is used to handle callbacks from the    diff library.  All output goes through these callbacks.  When a    pointer to this structure is passed in, it may be NULL.  Also, any    of the individual callbacks may be NULL.  This means that the    default action should be taken.  */
end_comment

begin_struct
struct|struct
name|diff_callbacks
block|{
comment|/* Write output.  This function just writes a string of a given      length to the output file.  The default is to fwrite to OUTFILE.      If this callback is defined, flush_output must also be defined.      If the length is zero, output zero bytes.  */
name|void
argument_list|(
argument|*write_output
argument_list|)
name|DIFFPARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Flush output.  The default is to fflush OUTFILE.  If this      callback is defined, write_output must also be defined.  */
name|void
argument_list|(
argument|*flush_output
argument_list|)
name|DIFFPARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Write a '\0'-terminated string to stdout.      This is called for version and help messages.  */
name|void
argument_list|(
argument|*write_stdout
argument_list|)
name|DIFFPARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Print an error message.  The first argument is a printf format,      and the next two are parameters.  The default is to print a      message on stderr.  */
name|void
argument_list|(
argument|*error
argument_list|)
name|DIFFPARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Run a diff.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|diff_run
name|DIFFPARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
specifier|const
expr|struct
name|diff_callbacks
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run a diff3.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|diff3_run
name|DIFFPARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
specifier|const
expr|struct
name|diff_callbacks
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DIFFPARAMS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIFFRUN_H */
end_comment

end_unit

