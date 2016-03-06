begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|REPLACE_GETOPT
end_define

begin_define
define|#
directive|define
name|REPLACE_GETOPT_LONG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|REPLACE_GETOPT_LONG_ONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REPLACE_GETOPT
argument_list|)
end_if

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

begin_function_decl
name|int
name|getopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|optstring
parameter_list|)
function_decl|;
end_function_decl

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
comment|// defined in unistd.h
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optreset
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REPLACE_GETOPT_LONG
argument_list|)
end_if

begin_function_decl
name|int
name|getopt_long
parameter_list|(
name|int
name|argc
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
name|optstring
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|longopts
parameter_list|,
name|int
modifier|*
name|longindex
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REPLACE_GETOPT_LONG_ONLY
argument_list|)
end_if

begin_function_decl
name|int
name|getopt_long_only
parameter_list|(
name|int
name|argc
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
name|optstring
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|longopts
parameter_list|,
name|int
modifier|*
name|longindex
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

