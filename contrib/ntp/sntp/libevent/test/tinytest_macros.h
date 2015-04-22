begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tinytest_macros.h -- Copyright 2009-2012 Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TINYTEST_MACROS_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|TINYTEST_MACROS_H_INCLUDED_
end_define

begin_comment
comment|/* Helpers for defining statement-like macros */
end_comment

begin_define
define|#
directive|define
name|TT_STMT_BEGIN
value|do {
end_define

begin_define
define|#
directive|define
name|TT_STMT_END
value|} while (0)
end_define

begin_comment
comment|/* Redefine this if your test functions want to abort with something besides  * "goto end;" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TT_EXIT_TEST_FUNCTION
end_ifndef

begin_define
define|#
directive|define
name|TT_EXIT_TEST_FUNCTION
value|TT_STMT_BEGIN goto end; TT_STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Redefine this if you want to note success/failure in some different way. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TT_DECLARE
end_ifndef

begin_define
define|#
directive|define
name|TT_DECLARE
parameter_list|(
name|prefix
parameter_list|,
name|args
parameter_list|)
define|\
value|TT_STMT_BEGIN						\ 	printf("\n  %s %s:%d: ",prefix,__FILE__,__LINE__);	\ 	printf args ;						\ 	TT_STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Announce a failure. Args are parenthesized printf args. */
end_comment

begin_define
define|#
directive|define
name|TT_GRIPE
parameter_list|(
name|args
parameter_list|)
value|TT_DECLARE("FAIL", args)
end_define

begin_comment
comment|/* Announce a non-failure if we're verbose. */
end_comment

begin_define
define|#
directive|define
name|TT_BLATHER
parameter_list|(
name|args
parameter_list|)
define|\
value|TT_STMT_BEGIN							\ 	if (tinytest_get_verbosity_()>1) TT_DECLARE("  OK", args);	\ 	TT_STMT_END
end_define

begin_define
define|#
directive|define
name|TT_DIE
parameter_list|(
name|args
parameter_list|)
define|\
value|TT_STMT_BEGIN						\ 	tinytest_set_test_failed_();				\ 	TT_GRIPE(args);						\ 	TT_EXIT_TEST_FUNCTION;					\ 	TT_STMT_END
end_define

begin_define
define|#
directive|define
name|TT_FAIL
parameter_list|(
name|args
parameter_list|)
define|\
value|TT_STMT_BEGIN						\ 	tinytest_set_test_failed_();				\ 	TT_GRIPE(args);						\ 	TT_STMT_END
end_define

begin_comment
comment|/* Fail and abort the current test for the reason in msg */
end_comment

begin_define
define|#
directive|define
name|tt_abort_printf
parameter_list|(
name|msg
parameter_list|)
value|TT_DIE(msg)
end_define

begin_define
define|#
directive|define
name|tt_abort_perror
parameter_list|(
name|op
parameter_list|)
value|TT_DIE(("%s: %s [%d]",(op),strerror(errno), errno))
end_define

begin_define
define|#
directive|define
name|tt_abort_msg
parameter_list|(
name|msg
parameter_list|)
value|TT_DIE(("%s", msg))
end_define

begin_define
define|#
directive|define
name|tt_abort
parameter_list|()
value|TT_DIE(("%s", "(Failed.)"))
end_define

begin_comment
comment|/* Fail but do not abort the current test for the reason in msg. */
end_comment

begin_define
define|#
directive|define
name|tt_failprint_f
parameter_list|(
name|msg
parameter_list|)
value|TT_FAIL(msg)
end_define

begin_define
define|#
directive|define
name|tt_fail_perror
parameter_list|(
name|op
parameter_list|)
value|TT_FAIL(("%s: %s [%d]",(op),strerror(errno), errno))
end_define

begin_define
define|#
directive|define
name|tt_fail_msg
parameter_list|(
name|msg
parameter_list|)
value|TT_FAIL(("%s", msg))
end_define

begin_define
define|#
directive|define
name|tt_fail
parameter_list|()
value|TT_FAIL(("%s", "(Failed.)"))
end_define

begin_comment
comment|/* End the current test, and indicate we are skipping it. */
end_comment

begin_define
define|#
directive|define
name|tt_skip
parameter_list|()
define|\
value|TT_STMT_BEGIN						\ 	tinytest_set_test_skipped_();				\ 	TT_EXIT_TEST_FUNCTION;					\ 	TT_STMT_END
end_define

begin_define
define|#
directive|define
name|tt_want_
parameter_list|(
name|b
parameter_list|,
name|msg
parameter_list|,
name|fail
parameter_list|)
define|\
value|TT_STMT_BEGIN					\ 	if (!(b)) {					\ 		tinytest_set_test_failed_();		\ 		TT_GRIPE(("%s",msg));			\ 		fail;					\ 	} else {					\ 		TT_BLATHER(("%s",msg));			\ 	}						\ 	TT_STMT_END
end_define

begin_comment
comment|/* Assert b, but do not stop the test if b fails.  Log msg on failure. */
end_comment

begin_define
define|#
directive|define
name|tt_want_msg
parameter_list|(
name|b
parameter_list|,
name|msg
parameter_list|)
define|\
value|tt_want_(b, msg, );
end_define

begin_comment
comment|/* Assert b and stop the test if b fails.  Log msg on failure. */
end_comment

begin_define
define|#
directive|define
name|tt_assert_msg
parameter_list|(
name|b
parameter_list|,
name|msg
parameter_list|)
define|\
value|tt_want_(b, msg, TT_EXIT_TEST_FUNCTION);
end_define

begin_comment
comment|/* Assert b, but do not stop the test if b fails. */
end_comment

begin_define
define|#
directive|define
name|tt_want
parameter_list|(
name|b
parameter_list|)
value|tt_want_msg( (b), "want("#b")")
end_define

begin_comment
comment|/* Assert b, and stop the test if b fails. */
end_comment

begin_define
define|#
directive|define
name|tt_assert
parameter_list|(
name|b
parameter_list|)
value|tt_assert_msg((b), "assert("#b")")
end_define

begin_define
define|#
directive|define
name|tt_assert_test_fmt_type
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|str_test
parameter_list|,
name|type
parameter_list|,
name|test
parameter_list|,
name|printf_type
parameter_list|,
name|printf_fmt
parameter_list|, \
name|setup_block
parameter_list|,
name|cleanup_block
parameter_list|,
name|die_on_fail
parameter_list|)
define|\
value|TT_STMT_BEGIN							\ 	type val1_ = (type)(a);						\ 	type val2_ = (type)(b);						\ 	int tt_status_ = (test);					\ 	if (!tt_status_ || tinytest_get_verbosity_()>1)	{		\ 		printf_type print_;					\ 		printf_type print1_;					\ 		printf_type print2_;					\ 		type value_ = val1_;					\ 		setup_block;						\ 		print1_ = print_;					\ 		value_ = val2_;						\ 		setup_block;						\ 		print2_ = print_;					\ 		TT_DECLARE(tt_status_?"	 OK":"FAIL",			\ 			   ("assert(%s): "printf_fmt" vs "printf_fmt,	\ 			    str_test, print1_, print2_));		\ 		print_ = print1_;					\ 		cleanup_block;						\ 		print_ = print2_;					\ 		cleanup_block;						\ 		if (!tt_status_) {					\ 			tinytest_set_test_failed_();			\ 			die_on_fail ;					\ 		}							\ 	}								\ 	TT_STMT_END
end_define

begin_define
define|#
directive|define
name|tt_assert_test_type
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|str_test
parameter_list|,
name|type
parameter_list|,
name|test
parameter_list|,
name|fmt
parameter_list|,
name|die_on_fail
parameter_list|)
define|\
value|tt_assert_test_fmt_type(a,b,str_test,type,test,type,fmt,	\ 	    {print_=value_;},{},die_on_fail)
end_define

begin_comment
comment|/* Helper: assert that a op b, when cast to type.  Format the values with  * printf format fmt on failure. */
end_comment

begin_define
define|#
directive|define
name|tt_assert_op_type
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|,
name|type
parameter_list|,
name|fmt
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,type,(val1_ op val2_),fmt, \ 	    TT_EXIT_TEST_FUNCTION)
end_define

begin_define
define|#
directive|define
name|tt_int_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,long,(val1_ op val2_), \ 	    "%ld",TT_EXIT_TEST_FUNCTION)
end_define

begin_define
define|#
directive|define
name|tt_uint_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,unsigned long,		\ 	    (val1_ op val2_),"%lu",TT_EXIT_TEST_FUNCTION)
end_define

begin_define
define|#
directive|define
name|tt_ptr_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,void*,			\ 	    (val1_ op val2_),"%p",TT_EXIT_TEST_FUNCTION)
end_define

begin_define
define|#
directive|define
name|tt_str_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,const char *,		\ 	    (strcmp(val1_,val2_) op 0),"<%s>",TT_EXIT_TEST_FUNCTION)
end_define

begin_define
define|#
directive|define
name|tt_want_int_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,long,(val1_ op val2_),"%ld",(void)0)
end_define

begin_define
define|#
directive|define
name|tt_want_uint_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,unsigned long,		\ 	    (val1_ op val2_),"%lu",(void)0)
end_define

begin_define
define|#
directive|define
name|tt_want_ptr_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,void*,			\ 	    (val1_ op val2_),"%p",(void)0)
end_define

begin_define
define|#
directive|define
name|tt_want_str_op
parameter_list|(
name|a
parameter_list|,
name|op
parameter_list|,
name|b
parameter_list|)
define|\
value|tt_assert_test_type(a,b,#a" "#op" "#b,const char *,		\ 	    (strcmp(val1_,val2_) op 0),"<%s>",(void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

