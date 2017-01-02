begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_COMMANDLINEFLAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_COMMANDLINEFLAGS_H_
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Macro for referencing flags.
end_comment

begin_define
define|#
directive|define
name|FLAG
parameter_list|(
name|name
parameter_list|)
value|FLAGS_##name
end_define

begin_comment
comment|// Macros for declaring flags.
end_comment

begin_define
define|#
directive|define
name|DECLARE_bool
parameter_list|(
name|name
parameter_list|)
value|extern bool FLAG(name)
end_define

begin_define
define|#
directive|define
name|DECLARE_int32
parameter_list|(
name|name
parameter_list|)
value|extern int32_t FLAG(name)
end_define

begin_define
define|#
directive|define
name|DECLARE_int64
parameter_list|(
name|name
parameter_list|)
value|extern int64_t FLAG(name)
end_define

begin_define
define|#
directive|define
name|DECLARE_double
parameter_list|(
name|name
parameter_list|)
value|extern double FLAG(name)
end_define

begin_define
define|#
directive|define
name|DECLARE_string
parameter_list|(
name|name
parameter_list|)
value|extern std::string FLAG(name)
end_define

begin_comment
comment|// Macros for defining flags.
end_comment

begin_define
define|#
directive|define
name|DEFINE_bool
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
value|bool FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|DEFINE_int32
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
value|int32_t FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|DEFINE_int64
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
value|int64_t FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|DEFINE_double
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
value|double FLAG(name) = (default_val)
end_define

begin_define
define|#
directive|define
name|DEFINE_string
parameter_list|(
name|name
parameter_list|,
name|default_val
parameter_list|,
name|doc
parameter_list|)
define|\
value|std::string FLAG(name) = (default_val)
end_define

begin_decl_stmt
name|namespace
name|benchmark
block|{
comment|// Parses 'str' for a 32-bit signed integer.  If successful, writes the result
comment|// to *value and returns true; otherwise leaves *value unchanged and returns
comment|// false.
name|bool
name|ParseInt32
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|src_text
argument_list|,
specifier|const
name|char
operator|*
name|str
argument_list|,
name|int32_t
operator|*
name|value
argument_list|)
decl_stmt|;
comment|// Parses a bool/Int32/string from the environment variable
comment|// corresponding to the given Google Test flag.
name|bool
name|BoolFromEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|bool
name|default_val
parameter_list|)
function_decl|;
name|int32_t
name|Int32FromEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|int32_t
name|default_val
parameter_list|)
function_decl|;
name|double
name|DoubleFromEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|double
name|default_val
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|StringFromEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|default_val
parameter_list|)
function_decl|;
comment|// Parses a string for a bool flag, in the form of either
comment|// "--flag=value" or "--flag".
comment|//
comment|// In the former case, the value is taken as true if it passes IsTruthyValue().
comment|//
comment|// In the latter case, the value is taken as true.
comment|//
comment|// On success, stores the value of the flag in *value, and returns
comment|// true.  On failure, returns false without changing *value.
name|bool
name|ParseBoolFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|bool
modifier|*
name|value
parameter_list|)
function_decl|;
comment|// Parses a string for an Int32 flag, in the form of
comment|// "--flag=value".
comment|//
comment|// On success, stores the value of the flag in *value, and returns
comment|// true.  On failure, returns false without changing *value.
name|bool
name|ParseInt32Flag
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|int32_t
modifier|*
name|value
parameter_list|)
function_decl|;
comment|// Parses a string for a Double flag, in the form of
comment|// "--flag=value".
comment|//
comment|// On success, stores the value of the flag in *value, and returns
comment|// true.  On failure, returns false without changing *value.
name|bool
name|ParseDoubleFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|double
modifier|*
name|value
parameter_list|)
function_decl|;
comment|// Parses a string for a string flag, in the form of
comment|// "--flag=value".
comment|//
comment|// On success, stores the value of the flag in *value, and returns
comment|// true.  On failure, returns false without changing *value.
name|bool
name|ParseStringFlag
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
specifier|const
name|char
operator|*
name|flag
argument_list|,
name|std
operator|::
name|string
operator|*
name|value
argument_list|)
decl_stmt|;
comment|// Returns true if the string matches the flag.
name|bool
name|IsFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|flag
parameter_list|)
function_decl|;
comment|// Returns true unless value starts with one of: '0', 'f', 'F', 'n' or 'N', or
comment|// some non-alphanumeric character. As a special case, also returns true if
comment|// value is the empty string.
name|bool
name|IsTruthyFlagValue
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|value
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_COMMANDLINEFLAGS_H_
end_comment

end_unit

