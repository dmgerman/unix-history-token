begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2011 Robert N. M. Watson  * Copyright (c) 2011 Jonathan Anderson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAP_TEST_H
end_ifndef

begin_define
define|#
directive|define
name|CAP_TEST_H
end_define

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_comment
comment|/*  * Define a file required by a test. The test can't complete without the file,  * so if we don't have it, just die.  */
end_comment

begin_define
define|#
directive|define
name|REQUIRE
parameter_list|(
name|fd
parameter_list|)
value|do {						\ 	if ((fd)< 0)							\ 		err(-1, "%s:%d: Missing required file '%s'",		\ 			__FILE__, __LINE__, #fd);			\ } while (0)
end_define

begin_comment
comment|/* Whether a test passed or failed. */
end_comment

begin_define
define|#
directive|define
name|PASSED
value|0
end_define

begin_define
define|#
directive|define
name|FAILED
value|1
end_define

begin_comment
comment|/* A test has failed; print a message and clear the 'success' flag. */
end_comment

begin_define
define|#
directive|define
name|FAIL
parameter_list|(
modifier|...
parameter_list|)
value|do {						\ 	warn(__VA_ARGS__);						\ 	success = FAILED;						\ } while (0)
end_define

begin_comment
comment|/* As above, but do not print the errno message. */
end_comment

begin_define
define|#
directive|define
name|FAILX
parameter_list|(
modifier|...
parameter_list|)
value|do {						\ 	warnx(__VA_ARGS__);						\ 	success = FAILED;						\ } while (0)
end_define

begin_comment
comment|/* Like an assertion, but don't kill the test, just fail and keep going. */
end_comment

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|condition
parameter_list|)
value|do {						\ 	if (!(condition))						\ 		FAILX("%s:%d: Assertion '%s' failed",			\ 		    __func__, __LINE__, #condition);			\ } while (0)
end_define

begin_comment
comment|/* Make sure that a system call's return value is>= 0. */
end_comment

begin_define
define|#
directive|define
name|CHECK_SYSCALL_SUCCEEDS
parameter_list|(
name|syscall
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (syscall(__VA_ARGS__)< 0)					\ 		FAIL("%s() at line %d: %s failed",			\ 		    __func__, __LINE__, #syscall);			\ } while (0)
end_define

begin_comment
comment|/* Make sure that a system call fails with the correct errno. */
end_comment

begin_define
define|#
directive|define
name|CHECK_SYSCALL_FAILS
parameter_list|(
name|expected_errno
parameter_list|,
name|syscall
parameter_list|,
modifier|...
parameter_list|)
value|do {	\ 	if (syscall(__VA_ARGS__)< 0) {					\ 		if (errno != expected_errno)				\ 			FAIL("%s() at line %d: %s",			\ 			    __func__, __LINE__, #syscall);		\ 	} else {							\ 		FAILX("%s() at line %d: %s succeeded; it should've failed", \ 		    __func__, __LINE__, #syscall);			\ 	}								\ } while (0)
end_define

begin_comment
comment|/* Make sure that a system call fails, but not with a particular errno. */
end_comment

begin_define
define|#
directive|define
name|CHECK_SYSCALL_FAILS_BUT_NOT_WITH
parameter_list|(
name|bad_errno
parameter_list|,
name|syscall
parameter_list|,
modifier|...
parameter_list|)
value|do { \ 	if (syscall(__VA_ARGS__)< 0) {					\ 		if (errno == bad_errno)					\ 			FAIL("%s() at line %d: %s",			\ 			    __func__, __LINE__, #syscall);		\ 	} else {							\ 		FAILX("%s() at line %d: %s succeeded; it should've failed", \ 		    __func__, __LINE__, #syscall);			\ 	}								\ } while (0)
end_define

begin_comment
comment|/* A system call should fail with ECAPMODE. */
end_comment

begin_define
define|#
directive|define
name|CHECK_CAPMODE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|CHECK_SYSCALL_FAILS(ECAPMODE, __VA_ARGS__)
end_define

begin_comment
comment|/* A system call should fail, but not with ECAPMODE. */
end_comment

begin_define
define|#
directive|define
name|CHECK_NOT_CAPMODE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|CHECK_SYSCALL_FAILS_BUT_NOT_WITH(ECAPMODE, __VA_ARGS__)
end_define

begin_comment
comment|/* A system call should fail with ENOTCAPABLE. */
end_comment

begin_define
define|#
directive|define
name|CHECK_NOTCAPABLE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|CHECK_SYSCALL_FAILS(ENOTCAPABLE, __VA_ARGS__)
end_define

begin_comment
comment|/* Ensure that 'rights' are a subset of 'max'. */
end_comment

begin_define
define|#
directive|define
name|CHECK_RIGHTS
parameter_list|(
name|rights
parameter_list|,
name|max
parameter_list|)
value|do {				\ 	if ((success == PASSED)&& (rights != max))			\ 		FAILX("Rights of opened file (%jx)> maximum (%jx)",	\ 		    (cap_rights_t) rights, (cap_rights_t) max);		\ } while (0)
end_define

begin_comment
comment|/* Create a capability from a file descriptor, make sure it succeeds. */
end_comment

begin_define
define|#
directive|define
name|MAKE_CAPABILITY
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|rights
parameter_list|)
value|do {			\ 	cap_rights_t _rights;						\ 	REQUIRE(to = cap_new(from, rights));				\ 	CHECK_SYSCALL_SUCCEEDS(cap_getrights, to,&_rights);		\ 	if ((success == PASSED)&& (_rights != (rights)))		\ 		FAILX("New capability's rights (%jx) != %jx",		\ 		    _rights, (cap_rights_t) (rights));			\ } while (0)
end_define

begin_comment
comment|/*  * A top-level test should take no arguments and return an integer value,  * either PASSED or FAILED.  *  * Errors such as SIGSEGV will be caught and interpreted as FAILED.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|test_function
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Information about a test. */
end_comment

begin_struct
struct|struct
name|test
block|{
name|char
modifier|*
name|t_name
decl_stmt|;
name|test_function
name|t_run
decl_stmt|;
name|int
name|t_result
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Run a test in a child process so that cap_enter(2) doesn't mess up  * subsequent tests.  */
end_comment

begin_function_decl
name|int
name|execute
parameter_list|(
name|int
name|id
parameter_list|,
name|struct
name|test
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_capmode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_capabilities
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_fcntl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_pdfork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_pdkill
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_pdwait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_relative
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_sysctl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAP_TEST_H */
end_comment

end_unit

