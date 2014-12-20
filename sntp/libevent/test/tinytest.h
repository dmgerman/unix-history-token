begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tinytest.h -- Copyright 2009-2012 Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TINYTEST_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|TINYTEST_H_INCLUDED_
end_define

begin_comment
comment|/** Flag for a test that needs to run in a subprocess. */
end_comment

begin_define
define|#
directive|define
name|TT_FORK
value|(1<<0)
end_define

begin_comment
comment|/** Runtime flag for a test we've decided to skip. */
end_comment

begin_define
define|#
directive|define
name|TT_SKIP
value|(1<<1)
end_define

begin_comment
comment|/** Internal runtime flag for a test we've decided to run. */
end_comment

begin_define
define|#
directive|define
name|TT_ENABLED_
value|(1<<2)
end_define

begin_comment
comment|/** Flag for a test that's off by default. */
end_comment

begin_define
define|#
directive|define
name|TT_OFF_BY_DEFAULT
value|(1<<3)
end_define

begin_comment
comment|/** If you add your own flags, make them start at this point. */
end_comment

begin_define
define|#
directive|define
name|TT_FIRST_USER_FLAG
value|(1<<4)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|testcase_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|testcase_t
struct_decl|;
end_struct_decl

begin_comment
comment|/** Functions to initialize/teardown a structure for a testcase. */
end_comment

begin_struct
struct|struct
name|testcase_setup_t
block|{
comment|/** Return a new structure for use by a given testcase. */
name|void
modifier|*
function_decl|(
modifier|*
name|setup_fn
function_decl|)
parameter_list|(
specifier|const
name|struct
name|testcase_t
modifier|*
parameter_list|)
function_decl|;
comment|/** Clean/free a structure from setup_fn. Return 1 if ok, 0 on err. */
name|int
function_decl|(
modifier|*
name|cleanup_fn
function_decl|)
parameter_list|(
specifier|const
name|struct
name|testcase_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/** A single test-case that you can run. */
end_comment

begin_struct
struct|struct
name|testcase_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< An identifier for this case. */
name|testcase_fn
name|fn
decl_stmt|;
comment|/**< The function to run to implement this case. */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/**< Bitfield of TT_* flags. */
specifier|const
name|struct
name|testcase_setup_t
modifier|*
name|setup
decl_stmt|;
comment|/**< Optional setup/cleanup fns*/
name|void
modifier|*
name|setup_data
decl_stmt|;
comment|/**< Extra data usable by setup function */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|END_OF_TESTCASES
value|{ NULL, NULL, 0, NULL, NULL }
end_define

begin_comment
comment|/** A group of tests that are selectable together. */
end_comment

begin_struct
struct|struct
name|testgroup_t
block|{
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/**< Prefix to prepend to testnames. */
name|struct
name|testcase_t
modifier|*
name|cases
decl_stmt|;
comment|/** Array, ending with END_OF_TESTCASES */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|END_OF_GROUPS
value|{ NULL, NULL}
end_define

begin_struct
struct|struct
name|testlist_alias_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|tests
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|END_OF_ALIASES
value|{ NULL, NULL }
end_define

begin_comment
comment|/** Implementation: called from a test to indicate failure, before logging. */
end_comment

begin_function_decl
name|void
name|tinytest_set_test_failed_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Implementation: called from a test to indicate that we're skipping. */
end_comment

begin_function_decl
name|void
name|tinytest_set_test_skipped_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Implementation: return 0 for quiet, 1 for normal, 2 for loud. */
end_comment

begin_function_decl
name|int
name|tinytest_get_verbosity_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Implementation: Set a flag on tests matching a name; returns number  * of tests that matched. */
end_comment

begin_function_decl
name|int
name|tinytest_set_flag_
parameter_list|(
name|struct
name|testgroup_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
name|set
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Set all tests in 'groups' matching the name 'named' to be skipped. */
end_comment

begin_define
define|#
directive|define
name|tinytest_skip
parameter_list|(
name|groups
parameter_list|,
name|named
parameter_list|)
define|\
value|tinytest_set_flag_(groups, named, 1, TT_SKIP)
end_define

begin_comment
comment|/** Run a single testcase in a single group. */
end_comment

begin_function_decl
name|int
name|testcase_run_one
parameter_list|(
specifier|const
name|struct
name|testgroup_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|testcase_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tinytest_set_aliases
parameter_list|(
specifier|const
name|struct
name|testlist_alias_t
modifier|*
name|aliases
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Run a set of testcases from an END_OF_GROUPS-terminated array of groups,     as selected from the command line. */
end_comment

begin_function_decl
name|int
name|tinytest_main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|struct
name|testgroup_t
modifier|*
name|groups
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

