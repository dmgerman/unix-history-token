begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GetOptWrapper.h -----------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_GetOptWrapper_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_GetOptWrapper_h_
end_define

begin_comment
comment|// from getopt.h
end_comment

begin_define
define|#
directive|define
name|no_argument
value|0
end_define

begin_define
define|#
directive|define
name|required_argument
value|1
end_define

begin_define
define|#
directive|define
name|optional_argument
value|2
end_define

begin_comment
comment|// defined int unistd.h
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optreset
decl_stmt|;
end_decl_stmt

begin_comment
comment|// from getopt.h
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|opterr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|// option structure
end_comment

begin_struct
struct|struct
name|option
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// has_arg can't be an enum because some compilers complain about
comment|// type mismatches in all the code that assumes it is an int.
name|int
name|has_arg
decl_stmt|;
name|int
modifier|*
name|flag
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//
end_comment

begin_function_decl
specifier|extern
name|int
name|getopt_long_only
parameter_list|(
name|int
name|___argc
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|___argv
parameter_list|,
specifier|const
name|char
modifier|*
name|__shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|__longopts
parameter_list|,
name|int
modifier|*
name|__longind
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_GetOptWrapper_h_
end_comment

end_unit

