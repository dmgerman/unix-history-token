begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TEST_OUTPUT_TEST_H
end_ifndef

begin_define
define|#
directive|define
name|TEST_OUTPUT_TEST_H
end_define

begin_undef
undef|#
directive|undef
name|NDEBUG
end_undef

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"../src/re.h"
end_include

begin_include
include|#
directive|include
file|"benchmark/benchmark.h"
end_include

begin_define
define|#
directive|define
name|CONCAT2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x##y
end_define

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT2(x, y)
end_define

begin_define
define|#
directive|define
name|ADD_CASES
parameter_list|(
modifier|...
parameter_list|)
value|int CONCAT(dummy, __LINE__) = ::AddCases(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|SET_SUBSTITUTIONS
parameter_list|(
modifier|...
parameter_list|)
define|\
value|int CONCAT(dummy, __LINE__) = ::SetSubstitutions(__VA_ARGS__)
end_define

begin_enum
enum|enum
name|MatchRules
block|{
name|MR_Default
block|,
comment|// Skip non-matching lines until a match is found.
name|MR_Next
block|,
comment|// Match must occur on the next line.
name|MR_Not
comment|// No line between the current position and the next match matches
comment|// the regex
block|}
enum|;
end_enum

begin_struct
struct|struct
name|TestCase
block|{
name|TestCase
argument_list|(
argument|std::string re
argument_list|,
argument|int rule = MR_Default
argument_list|)
empty_stmt|;
name|std
operator|::
name|string
name|regex_str
expr_stmt|;
name|int
name|match_rule
decl_stmt|;
name|std
operator|::
name|string
name|substituted_regex
expr_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|benchmark
operator|::
name|Regex
operator|>
name|regex
expr_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|TestCaseID
block|{
name|TC_ConsoleOut
block|,
name|TC_ConsoleErr
block|,
name|TC_JSONOut
block|,
name|TC_JSONErr
block|,
name|TC_CSVOut
block|,
name|TC_CSVErr
block|,
name|TC_NumID
comment|// PRIVATE
block|}
enum|;
end_enum

begin_comment
comment|// Add a list of test cases to be run against the output specified by
end_comment

begin_comment
comment|// 'ID'
end_comment

begin_decl_stmt
name|int
name|AddCases
argument_list|(
name|TestCaseID
name|ID
argument_list|,
name|std
operator|::
name|initializer_list
operator|<
name|TestCase
operator|>
name|il
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Add or set a list of substitutions to be performed on constructed regex's
end_comment

begin_comment
comment|// See 'output_test_helper.cc' for a list of default substitutions.
end_comment

begin_decl_stmt
name|int
name|SetSubstitutions
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|std
operator|::
name|string
operator|>>
name|il
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Run all output tests.
end_comment

begin_function_decl
name|void
name|RunOutputTests
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ========================================================================= //
end_comment

begin_comment
comment|// --------------------------- Misc Utilities ------------------------------ //
end_comment

begin_comment
comment|// ========================================================================= //
end_comment

begin_macro
name|namespace
end_macro

begin_block
block|{
specifier|const
name|char
modifier|*
specifier|const
name|dec_re
init|=
literal|"[0-9]*[.]?[0-9]+([eE][-+][0-9]+)?"
decl_stmt|;
block|}
end_block

begin_comment
comment|//  end namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TEST_OUTPUT_TEST_H
end_comment

end_unit

